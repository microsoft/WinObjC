//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

TEST(CGBitmapContext, BitmapInfoAPIs_CMYK) {
    CGColorSpaceRef cmykColorSpace = CGColorSpaceCreateDeviceCMYK();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, cmykColorSpace, 0);

    // The following causes a crash since CGImage only supports RGB right now
    // IF the quick return is removed, these tests should be reinstated
    // TODO:: GitHub Issue: https://github.com/Microsoft/WinObjC/issues/594
    // EXPECT_EQ(CGBitmapContextGetBitmapInfo(context), 0);
    EXPECT_EQ(CGBitmapContextGetBitsPerComponent(context), 8);
    EXPECT_EQ(CGBitmapContextGetBitsPerPixel(context), 8);

    CGColorSpaceRelease(cmykColorSpace);
    CGContextRelease(context);
}

TEST(CGBitmapContext, BitmapInfoAPIs_RGB) {
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, rgbColorSpace, 0);

    EXPECT_EQ(CGBitmapContextGetBitmapInfo(context), 0);
    EXPECT_EQ(CGBitmapContextGetBitsPerComponent(context), 8);
    EXPECT_EQ(CGBitmapContextGetBitsPerPixel(context), 24);

    CGColorSpaceRelease(rgbColorSpace);
    CGContextRelease(context);
}

TEST(CGBitmapContext, BitmapInfoAPIs_Gray) {
    CGColorSpaceRef grayColorSpace = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, grayColorSpace, 0);

    // The following causes a crash since CGImage only supports RGB right now
    // IF the quick return is removed, these tests should be reinstated
    // TODO:: GitHub Issue: https://github.com/Microsoft/WinObjC/issues/594
    // EXPECT_EQ(CGBitmapContextGetBitmapInfo(context), 0);
    EXPECT_EQ(CGBitmapContextGetBitsPerComponent(context), 8);
    EXPECT_EQ(CGBitmapContextGetBitsPerPixel(context), 8);

    CGColorSpaceRelease(grayColorSpace);
    CGContextRelease(context);
}