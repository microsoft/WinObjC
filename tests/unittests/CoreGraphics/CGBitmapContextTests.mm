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

#import "CGContextInternal.h"
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGImage.h>
#import <CoreGraphics/CGBitmapContext.h>
#import <CoreText/CTFont.h>
#import <CoreText/CTFrame.h>
#import <CoreText/CTFrameSetter.h>
#import <CoreText/CTStringAttributes.h>
#import <Foundation/Foundation.h>
#import <Starboard.h>
#import <TestFramework.h>

DISABLED_TEST(CGBitmapContext, BitmapInfoAPIs_CMYK) {
    CGColorSpaceRef cmykColorSpace = CGColorSpaceCreateDeviceCMYK();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, cmykColorSpace, 0);

    EXPECT_EQ(CGBitmapContextGetBitmapInfo(context), 0);

    // The following tests may fail since CMYK color spaces are not supported
    // and so cmykColorSpace will be NULL.  If a NULL colorspace is passed
    // to CGBitmapContextCreate, a RGB colorspace will be assumed and calls to
    // CGBitmapContextGetBitsPerComponent and CGBitmapContextGetBitsPerPixel will
    // return the values for a context created with an RGB colorspace instead of a
    // CMYK one.
    // TODO:: GitHub Issue: https://github.com/Microsoft/WinObjC/issues/594
    // TODO:: Re-add these tests when CMYK colorspaces are supported

    // EXPECT_EQ(CGBitmapContextGetBitsPerComponent(context), 8);
    // EXPECT_EQ(CGBitmapContextGetBitsPerPixel(context), 32);

    CGColorSpaceRelease(cmykColorSpace);
    CGContextRelease(context);
}

void _DrawText(CGContextRef context, NSString* text, const CGRect bounds) {
    // Aligns origin for our frame
    CGContextTranslateCTM(context, 0.0f, bounds.size.height);

    // Flips y-axis for our frame
    CGContextScaleCTM(context, 1.0f, -1.0f);

    // Creates path with current rectangle
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathAddRect(path, NULL, bounds);

    CTFontRef myCFFont = CTFontCreateWithName((__bridge CFStringRef) @"Arial", 10, NULL);
    CFAutorelease(myCFFont);

    // Make dictionary for attributed string with font, color, and alignment
    NSDictionary* attributesDict = [NSDictionary dictionaryWithObjectsAndKeys:(__bridge id)myCFFont,
                                                                              (id)kCTFontAttributeName,
                                                                              kCFBooleanTrue,
                                                                              (id)kCTForegroundColorFromContextAttributeName,
                                                                              nil];

    CFAttributedStringRef attrString =
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)text, (__bridge CFDictionaryRef)attributesDict);
    CFAutorelease(attrString);

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
    CFAutorelease(framesetter);

    // Creates frame for framesetter with current attributed string
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    CFAutorelease(frame);

    // Draws the text in the frame
    CTFrameDraw(frame, context);
    CGPathRelease(path);
}

// we will create a 10x10 bitmap context and :
// 1. Fill context with R=0.0, G=0.0, B=0.5, A=1.
// data buffer in little endian format: R = 0, G=0, B > 0, A = FF
// 2. Set R=1, G=0.5, B=0, A=1.0
// Draw "||" into the buffer
// The data buffer should contain R > G > B.
// Due to text aliasing, we won't get the actual values we specify hence this

// The test will break under two circumstances:
// 1. pixel format breaks due to CG drawing code change (for as long as we use cairo)
// 2. pixel format breaks due to changes in render target pixel format for bitmap context.

void _TestPixelFormat(const CGRect bounds, const CGBitmapInfo info, DWORD expectedBG, DWORD expectedFG1, DWORD expectedFG2) {
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();

    const size_t width = bounds.size.width;
    const size_t height = bounds.size.height;
    const size_t bytesPerPixel = 4;
    const size_t bitsPerChannel = 8;
    const CGFloat color[] = { 1.0, 0.5, 0.0, 1.0 };
    const CGFloat bgColor[] = { 0.0, 0.0, 0.5, 1.0 };

    std::unique_ptr<uint8_t[]> data(new uint8_t[width * height * 4]);
    CGContextRef context = CGBitmapContextCreate(data.get(),
                                                 width,
                                                 height,
                                                 bitsPerChannel,
                                                 width * 4, // bytes per row
                                                 colorSpace,
                                                 info);

    CGContextSetFillColor(context, bgColor);
    CGContextFillRect(context, bounds);

    DWORD* pixel = (DWORD*)data.get();
    EXPECT_EQ(*pixel, expectedBG);

    CGContextSetFillColor(context, color);
    _DrawText(context, @"||", bounds);

    EXPECT_EQ(*pixel, expectedFG1);
    pixel++;
    EXPECT_EQ(*pixel, expectedFG2);

    CGColorSpaceRelease(colorSpace);
    CGContextRelease(context);
}

DISABLED_TEST(CGBitmapContext, VerifyPixelFormatRGBA) {
    _TestPixelFormat(CGRect{ 0, 0, 10, 10 },
                     kCGBitmapByteOrder32Big | kCGImageAlphaPremultipliedLast,
                     0xff800000, // expectedbg
                     0xff631d3a, // expectedfg1
                     0xff2759b1 // expectedfg2
                     );
}

DISABLED_TEST(CGBitmapContext, VerifyPixelFormatBGRA) {
    _TestPixelFormat(CGRect{ 0, 0, 10, 10 },
                     kCGBitmapByteOrder32Big | kCGImageAlphaPremultipliedFirst,
                     0xff000080, // expectedbg
                     0xff3a1d63, // expectedfg1
                     0xffb15927 // expectedfg2
                     );
}

#define EXPECT_ARRAY_EQ(expected, actual, size)                       \
    for (int i = 0; i < (size); ++i) {                                \
        EXPECT_EQ((expected)[i], (actual)[i]) << i << " of " << size; \
    }

TEST(CGBitmapContext, BitmapInfoAPIs_Gray) {
    CGColorSpaceRef grayColorSpace = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, grayColorSpace, 0);
    EXPECT_EQ(context, nullptr);

    context = CGBitmapContextCreate(nullptr, 120, 20, 8, 120, grayColorSpace, 0);
    EXPECT_NE(context, nullptr);
}

TEST(CGBitmapContext, BitmapInfoAPIs_RGB) {
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();

    CGContextRef context =
        CGBitmapContextCreate(nullptr, 120, 20, 8, 480, rgbColorSpace, kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);

    EXPECT_EQ(CGBitmapContextGetBitsPerComponent(context), 8);
    EXPECT_EQ(CGBitmapContextGetBitsPerPixel(context), 32);
    EXPECT_EQ(CGBitmapContextGetWidth(context), 120);
    EXPECT_EQ(CGBitmapContextGetHeight(context), 20);

    EXPECT_EQ(CGBitmapContextGetBytesPerRow(context), 480);
    EXPECT_NE(CGBitmapContextGetData(context), nullptr);

    CGColorSpaceRelease(rgbColorSpace);
    CGContextRelease(context);
}

TEST(CGBitmapContext, Rendering) {
    woc::unique_cf<CGColorSpaceRef> rgbColorSpace(CGColorSpaceCreateDeviceRGB());

    //                 R     G  B  A
    BYTE result[4] = { 0xff, 0, 0, 0xff };
    woc::unique_cf<CGContextRef> context(
        CGBitmapContextCreate(nullptr, 1, 1, 8, 4, rgbColorSpace.get(), kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big));

    EXPECT_EQ(CGBitmapContextGetBitsPerComponent(context.get()), 8);
    EXPECT_EQ(CGBitmapContextGetBitsPerPixel(context.get()), 32);
    EXPECT_EQ(CGBitmapContextGetWidth(context.get()), 1);
    EXPECT_EQ(CGBitmapContextGetHeight(context.get()), 1);

    EXPECT_EQ(CGBitmapContextGetBytesPerRow(context.get()), 4);
    EXPECT_NE(CGBitmapContextGetData(context.get()), nullptr);

    // Draw a rectangle into it.
    CGRect rectangle = CGRectMake(0, 0, 2, 2);
    CGContextSetRGBFillColor(context.get(), 1.0, 0.0, 0.0, 1.0);
    CGContextSetRGBStrokeColor(context.get(), 1.0, 0.0, 0.0, 1.0);
    CGContextFillRect(context.get(), rectangle);

    // verify the rect was drawn
    BYTE* data = static_cast<BYTE*>(CGBitmapContextGetData(context.get()));
    ASSERT_NE(data, nullptr);

    EXPECT_ARRAY_EQ(result, data, 4);

    // Create the image out of the bitmap context
    woc::unique_cf<CGImageRef> image(CGBitmapContextCreateImage(context.get()));
    ASSERT_NE(image, nullptr);

    woc::unique_cf<CFDataRef> rawData(CGDataProviderCopyData(CGImageGetDataProvider(image.get())));
    ASSERT_NE(rawData, nullptr);

    const BYTE* rData = static_cast<const BYTE*>(CFDataGetBytePtr(rawData.get()));
    EXPECT_ARRAY_EQ(result, rData, 4);
}

struct BitmapFormatTestCase {
    CGBitmapInfo bitmapInfo;
    uint32_t nComponents;
    uint32_t bitsPerPixel;
    std::vector<uint8_t> mask;
    std::vector<uint8_t> expectedPixelValues;
};

class BitmapFormats : public ::testing::TestWithParam<BitmapFormatTestCase> {};

TEST_P(BitmapFormats, BufferCompare) {
    const BitmapFormatTestCase& testInfo = GetParam();
    const size_t width = 4;
    const size_t height = 1;
    size_t bytesPerPixel = testInfo.bitsPerPixel >> 3;
    size_t stride = width * bytesPerPixel;
    std::vector<uint8_t> data(stride * height, 0);
    woc::unique_cf<CGColorSpaceRef> colorSpace;
    if (bytesPerPixel == 1) {
        colorSpace.reset(CGColorSpaceCreateDeviceGray());
    } else {
        colorSpace.reset(CGColorSpaceCreateDeviceRGB());
    }
    woc::unique_cf<CGContextRef> context{ CGBitmapContextCreateWithData(data.data(),
                                                                        width,
                                                                        height,
                                                                        testInfo.bitsPerPixel / testInfo.nComponents,
                                                                        stride,
                                                                        colorSpace.get(),
                                                                        testInfo.bitmapInfo,
                                                                        nullptr,
                                                                        nullptr) };
    ASSERT_NE(nullptr, context);

    // Pixel values: 0x20 0x40 0x00 0x80
    // Premultiplied: 0x10 0x20 0x00 0x80
    CGContextSetRGBFillColor(context.get(), 32. / 255., 64. / 255., 0.0, 128. / 255.);
    CGContextFillRect(context.get(), { CGPointZero, { width, height } });

    size_t maskLength = testInfo.mask.size();
    size_t compareBufferLength = testInfo.expectedPixelValues.size();
    for (size_t i = 0; i < data.size(); ++i) {
        uint8_t maskedValue = data[i] & testInfo.mask[i % maskLength];
        EXPECT_EQ(testInfo.expectedPixelValues[i % compareBufferLength], maskedValue) << i;
    }
}

// clang-format off
static BitmapFormatTestCase bitmapFormatTestCases[]{
    // CGBitmapInfo (pixel format, order)                         | #channels| bpp| pixel mask                | expected pixel values      |
    // Alpha only (8bpp format)
    { kCGImageAlphaOnly,                                            1,           8, { 0xFF }                  , { 0x80 }                   },

    // RGBX (32bpp)
    { kCGImageAlphaNoneSkipLast       | kCGBitmapByteOrder32Big,    4,          32, { 0xFF, 0xFF, 0xFF, 0x00 }, { 0x10, 0x20, 0x00, 0x00 } },

    // RGBA (32bpp premultiplied)
    { kCGImageAlphaPremultipliedLast  | kCGBitmapByteOrder32Big,    4,          32, { 0xFF, 0xFF, 0xFF, 0xFF }, { 0x10, 0x20, 0x00, 0x80 } },

    // BGRX (32bpp) (XRGB but in LE)
    { kCGImageAlphaNoneSkipFirst      | kCGBitmapByteOrder32Little, 4,          32, { 0xFF, 0xFF, 0xFF, 0x00 }, { 0x00, 0x20, 0x10, 0x00 } },

    // BGRA (32bpp premultiplied) (ARGB but in LE)
    { kCGImageAlphaPremultipliedFirst | kCGBitmapByteOrder32Little, 4,          32, { 0xFF, 0xFF, 0xFF, 0xFF }, { 0x00, 0x20, 0x10, 0x80 } },
};
// clang-format on

INSTANTIATE_TEST_CASE_P(CGBitmapContextFormat, BitmapFormats, ::testing::ValuesIn(bitmapFormatTestCases));

TEST(CGBitmapContext, BadStrides) {
    uint32_t data = 0;
    auto colorSpace = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceRGB());

    {
        auto context = woc::MakeStrongCF<CGContextRef>(
            CGBitmapContextCreateWithData(&data, 1, 1, 8, 0, colorSpace, kCGImageAlphaLast, nullptr, nullptr));
        ASSERT_EQ(nullptr, context);
    }

    {
        auto context = woc::MakeStrongCF<CGContextRef>(
            CGBitmapContextCreateWithData(&data, 1, 1, 8, 1, colorSpace, kCGImageAlphaLast, nullptr, nullptr));
        ASSERT_EQ(nullptr, context);
    }
}

TEST(CGBitmapContext, MismatchedConfigurationValues) {
    auto colorSpace = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceRGB());

    {
        // Provided 1 byte per row, but using 3-component + alpha = 32bpp (4 byte/pixel)
        auto context = woc::MakeStrongCF<CGContextRef>(
            CGBitmapContextCreateWithData(nullptr, 1, 1, 8, 1, colorSpace, kCGImageAlphaLast, nullptr, nullptr));
        ASSERT_EQ(nullptr, context);
    }

    {
        // Provided 2 bytes per row, requested 32bpp, but using 3-component no alpha = 24bpp (3 byte/pixel)
        // Context imputes format to be 32, but provided values should not match.
        auto context = woc::MakeStrongCF<CGContextRef>(
            CGBitmapContextCreateWithData(nullptr, 1, 1, 8, 2, colorSpace, kCGImageAlphaNone | kCGBitmapByteOrder32Big, nullptr, nullptr));
        ASSERT_EQ(nullptr, context);
    }
}

TEST(CGBitmapContext, ImputeStrideRGBA) {
    auto colorSpace = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceRGB());
    auto context = woc::MakeStrongCF<CGContextRef>(
        CGBitmapContextCreateWithData(nullptr, 1, 1, 8, 0, colorSpace, kCGImageAlphaPremultipliedLast, nullptr, nullptr));
    ASSERT_NE(nullptr, context);
    EXPECT_EQ(32, CGBitmapContextGetBitsPerPixel(context));
    EXPECT_LE(4, CGBitmapContextGetBytesPerRow(context)); // 4 <= stride
}