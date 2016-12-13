//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include "ImageComparison.h"
#include "ImageHelpers.h"

#include <CoreGraphics/CGGeometry.h>

struct bgraPixel {
    uint8_t b, g, r, a;
};

struct rgbaPixel {
    uint8_t r, g, b, a;
};

template <typename T, typename U>
bool operator==(const T& t, const U& u) {
    return t.r == u.r && t.g == u.g && t.b == u.b && t.a == u.a;
}

ImageDelta PixelByPixelImageComparator::CompareImages(CGImageRef left, CGImageRef right) {
    if (!left || !right) {
        return { ImageComparisonResult::Incomparable };
    }

    CGSize leftSize{
        (CGFloat)CGImageGetWidth(left), (CGFloat)CGImageGetHeight(left),
    };

    CGSize rightSize{
        (CGFloat)CGImageGetWidth(right), (CGFloat)CGImageGetHeight(right),
    };

    size_t leftPixelCount = leftSize.width * leftSize.height;
    size_t rightPixelCount = rightSize.width * rightSize.height;

    if (leftPixelCount != rightPixelCount) {
        return { ImageComparisonResult::Incomparable };
    }

    woc::unique_cf<CFDataRef> leftData{ _CFDataCreateFromCGImage(left) };
    woc::unique_cf<CFDataRef> rightData{ _CFDataCreateFromCGImage(right) };

    CFIndex leftLength = CFDataGetLength(leftData.get());
    if (leftLength != CFDataGetLength(rightData.get())) {
        return { ImageComparisonResult::Incomparable };
    }

    woc::unique_iw<uint8_t> deltaBuffer{ static_cast<uint8_t*>(IwCalloc(leftLength, 1)) };

    const rgbaPixel* leftPixels{ reinterpret_cast<const rgbaPixel*>(CFDataGetBytePtr(leftData.get())) };
    const rgbaPixel* rightPixels{ reinterpret_cast<const rgbaPixel*>(CFDataGetBytePtr(rightData.get())) };
    rgbaPixel* deltaPixels{ reinterpret_cast<rgbaPixel*>(deltaBuffer.get()) };

    // ASSUMPTION: The context draw did not cover the top left pixel;
    // We can use it as the background to detect accidental background deletion and miscomposition.
    auto background = leftPixels[0];

    size_t npxchg = 0;
    for (off_t i = 0; i < leftLength / sizeof(rgbaPixel); ++i) {
        auto& bp = leftPixels[i];
        auto& cp = rightPixels[i];
        auto& gp = deltaPixels[i];
        if (!(bp == cp)) {
            ++npxchg;
            if (cp == background) {
                // Pixel is in EXPECTED but not ACTUAL
                gp.r = gp.a = 255;
            } else if (bp == background) {
                // Pixel is in ACTUAL but not EXPECTED
                gp.g = gp.a = 255;
            } else {
                // Pixel is in BOTH but DIFFERENT
                gp.r = gp.g = gp.a = 255;
            }
        } else {
            gp.r = gp.g = gp.b = 0;
            gp.a = 255;
        }
    }

    woc::unique_cf<CFDataRef> deltaData{ CFDataCreateWithBytesNoCopy(nullptr, deltaBuffer.release(), leftLength, kCFAllocatorDefault) };
    woc::unique_cf<CGDataProviderRef> deltaProvider{ CGDataProviderCreateWithCFData(deltaData.get()) };

    woc::unique_cf<CGImageRef> deltaImage{ CGImageCreate(leftSize.width,
                                                         leftSize.height,
                                                         8,
                                                         32,
                                                         leftSize.width * 4,
                                                         CGImageGetColorSpace(left),
                                                         CGImageGetBitmapInfo(left),
                                                         deltaProvider.get(),
                                                         nullptr,
                                                         FALSE,
                                                         kCGRenderingIntentDefault) };

    return {
        (npxchg == 0 ? ImageComparisonResult::Same : ImageComparisonResult::Different), npxchg, deltaImage.get(),
    };
}
