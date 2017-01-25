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

#pragma once

#include <CoreGraphics/CGImage.h>
#include <Starboard/SmartTypes.h>

enum class ImageComparisonResult : unsigned int { Unknown = 0, Incomparable, Different, Same };

struct rgbaPixel {
    uint8_t r, g, b, a;
};

template <size_t FailureThreshold = 1>
struct PixelComparisonModeExact {
    static constexpr size_t Threshold = FailureThreshold;
    template <typename LP, typename RP>
    rgbaPixel ComparePixels(const LP& background, const LP& bp, const RP& cp, size_t& npxchg);
};

template <size_t FailureThreshold = 1>
struct PixelComparisonModeMask {
    static constexpr size_t Threshold = FailureThreshold;
    template <typename LP, typename RP>
    rgbaPixel ComparePixels(const LP& background, const LP& bp, const RP& cp, size_t& npxchg);
};

struct ImageDelta {
    ImageComparisonResult result;
    size_t differences;
    woc::unique_cf<CGImageRef> deltaImage;

    ImageDelta(ImageComparisonResult result) : result(result), differences(0), deltaImage(nullptr) {
    }

    ImageDelta(ImageComparisonResult result, size_t differences, CGImageRef deltaImage)
        : result(result), differences(differences), deltaImage(CGImageRetain(deltaImage)) {
    }

    ImageDelta(ImageDelta&& other) : result(other.result), differences(other.differences), deltaImage(other.deltaImage.release()) {}
};

class ImageComparator {
public:
    virtual ImageDelta CompareImages(CGImageRef left, CGImageRef right) = 0;
};

template <typename PixelComparisonMode = PixelComparisonModeExact<1>>
class PixelByPixelImageComparator : public ImageComparator {
public:
    ImageDelta CompareImages(CGImageRef left, CGImageRef right) override;
};
