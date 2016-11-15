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
#import <CoreGraphics\CGBitmapContext.h>
#import <Foundation\Foundation.h>
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

    woc::unique_iw<uint8_t> data(static_cast<uint8_t*>(IwMalloc(width * height * 4)));
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

static void _expectArrayValues(BYTE* res, BYTE* source, int size) {
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(res[i], source[i]);
    }
}

TEST(CGBitmapContext, BitmapInfoAPIs_Gray) {
    CGColorSpaceRef grayColorSpace = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, grayColorSpace, 0);
    EXPECT_EQ(context, nullptr);

    context = CGBitmapContextCreate(nullptr, 120, 20, 8, 480, grayColorSpace, 0);
    EXPECT_EQ(context, nullptr);
}

TEST(CGBitmapContext, BitmapInfoAPIs_RGB) {
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();

    CGContextRef context = CGBitmapContextCreate(nullptr, 120, 20, 8, 480, rgbColorSpace, kCGImageAlphaPremultipliedFirst);

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

    BYTE result[4] = { 0xff, 0, 0, 0xff };
    woc::unique_cf<CGContextRef> context(CGBitmapContextCreate(nullptr, 1, 1, 8, 4, rgbColorSpace.get(), kCGImageAlphaPremultipliedFirst));

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

    _expectArrayValues(result, data, 4);

    // Create the image out of the bitmap context
    woc::unique_cf<CGImageRef> image(CGBitmapContextCreateImage(context.get()));
    ASSERT_NE(image, nullptr);

    NSData* dataProvider = static_cast<NSData*>(CGImageGetDataProvider(image.get()));
    ASSERT_NE(dataProvider, nullptr);

    NSData* ref = [[NSData dataWithBytesNoCopy:result length:4 freeWhenDone:NO] autorelease];
    ASSERT_OBJCEQ(dataProvider, ref);
}
