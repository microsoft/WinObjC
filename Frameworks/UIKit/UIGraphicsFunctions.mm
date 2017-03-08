//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import <StubReturn.h>
#import <Starboard.h>
#import <UIKit/UIKit.h>
#import <LoggingNative.h>
#import <CoreGraphics/CGContext.h>

#import "StarboardXaml/DisplayProperties.h"
#import "CGContextInternal.h" // for shadow projection

#import <stack>
#import <mutex>

static const wchar_t* TAG = L"UIGraphicsFunctions";

namespace {
typedef NS_ENUM(NSUInteger, _UIGraphicsContextType) {
    _UIGraphicsContextTypeUnknown = 0,
    _UIGraphicsContextTypeUser,
    _UIGraphicsContextTypeImage,
    _UIGraphicsContextTypePDF,
};

struct _UIGraphicsContextRecord {
    woc::unique_cf<CGContextRef> context;
    _UIGraphicsContextType type;
    CGSize size;
    CGFloat scale;

    _UIGraphicsContextRecord(CGContextRef context, _UIGraphicsContextType type, CGSize size = CGSizeZero, CGFloat scale = 1.0f)
        : context(CGContextRetain(context)), type(type), size(size), scale(scale) {
    }
};
}

static std::mutex s_contextStackMutex;
static std::stack<_UIGraphicsContextRecord> s_contextStack;

/**
 @Status Interoperable
*/
void UIGraphicsPushContext(CGContextRef context) {
    std::lock_guard<std::mutex> lock(s_contextStackMutex);

    s_contextStack.emplace(context, _UIGraphicsContextTypeUser);
}

/**
 @Status Interoperable
*/
void UIGraphicsPopContext() {
    std::lock_guard<std::mutex> lock(s_contextStackMutex);
    if (s_contextStack.empty()) {
        TraceError(TAG, L"UIGraphicsPopContext(): the context stack was empty.");
        return;
    }
    s_contextStack.pop();
}

/**
 @Status Interoperable
*/
CGContextRef UIGraphicsGetCurrentContext() {
    std::lock_guard<std::mutex> lock(s_contextStackMutex);
    return s_contextStack.top().context.get();
}

/**
 @Status Interoperable
*/
void UIGraphicsBeginImageContextWithOptions(CGSize size, BOOL opaque, float scale) {
    // Locking occurs in UIGraphicsPushContext.
    if (scale == 0.0f) {
        scale = DisplayProperties::ScreenScale();
    }

    CGSize scaledSize{
        size.width * scale, size.height * scale,
    };
    woc::unique_cf<CGColorSpaceRef> rgbColorSpace(CGColorSpaceCreateDeviceRGB());
    woc::unique_cf<CGContextRef> context{ CGBitmapContextCreate(nullptr,
                                                                scaledSize.width,
                                                                scaledSize.height,
                                                                8, // 32bpp (8 bits per component)
                                                                scaledSize.width * 4, // Stride for RGBA/RGBX
                                                                rgbColorSpace.get(),
                                                                (opaque ? kCGImageAlphaNoneSkipLast : kCGImageAlphaPremultipliedLast) |
                                                                    kCGBitmapByteOrder32Big) };

    // Apply the UIKit ULO transform (and shadow projection transform)
    CGContextTranslateCTM(context.get(), 0.0f, size.height * scale);
    CGContextScaleCTM(context.get(), scale, -scale);
    _CGContextSetShadowProjectionTransform(context.get(), CGAffineTransformMakeScale(1.0, -1.0));

    {
        std::lock_guard<std::mutex> lock(s_contextStackMutex);

        s_contextStack.emplace(context.get(), _UIGraphicsContextTypeImage, size, scale);
    }
}

/**
 @Status Interoperable
*/
void UIGraphicsBeginImageContext(CGSize size) {
    UIGraphicsBeginImageContextWithOptions(size, FALSE, 1.0f);
}

/**
 @Status Interoperable
*/
UIImage* UIGraphicsGetImageFromCurrentImageContext() {
    std::lock_guard<std::mutex> lock(s_contextStackMutex);
    if (s_contextStack.empty()) {
        TraceError(TAG, L"UIGraphicsGetImageFromCurrentImageContext(): the context stack was empty.");
        return nil;
    }

    _UIGraphicsContextRecord& topRecord = s_contextStack.top();
    if (topRecord.type != _UIGraphicsContextTypeImage) {
        TraceError(TAG, L"UIGraphicsGetImageFromCurrentImageContext(): the top context is not an image context.");
        return nil;
    }

    CGContextRef context = topRecord.context.get();
    return [UIImage imageWithCGImage:_CGBitmapContextGetImage(context) scale:topRecord.scale orientation:UIImageOrientationUp];
}

/**
 @Status Interoperable
*/
void UIGraphicsEndImageContext() {
    std::lock_guard<std::mutex> lock(s_contextStackMutex);
    if (s_contextStack.empty()) {
        TraceError(TAG, L"UIGraphicsEndImageContext(): the context stack was empty.");
        return;
    }

    if (s_contextStack.top().type == _UIGraphicsContextTypeImage) {
        s_contextStack.pop(); // Releases record's CGContext.
    }
}

/**
 @Status Interoperable
*/
void UIRectFill(CGRect rect) {
    UIRectFillUsingBlendMode(rect, kCGBlendModeCopy);
}

/**
 @Status Interoperable
*/
void UIRectFillUsingBlendMode(CGRect rect, CGBlendMode blendMode) {
    CGContextRef context = UIGraphicsGetCurrentContext();

    CGContextSaveGState(context);
    CGContextSetBlendMode(context, blendMode);
    CGContextFillRect(context, rect);
    CGContextRestoreGState(context);
}

/**
 @Status Interoperable
*/
void UIRectFrame(CGRect rect) {
    UIRectFrameUsingBlendMode(rect, kCGBlendModeCopy);
}

/**
 @Status Interoperable
*/
void UIRectFrameUsingBlendMode(CGRect rect, CGBlendMode blendMode) {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSaveGState(context);
    CGContextSetLineWidth(context, 1.0);
    CGContextSetBlendMode(context, kCGBlendModeCopy);

    // Rect is inset because the API is specified as stroking a 1.0pt wide line *inside* the provided rectangle.
    CGContextStrokeRect(context, CGRectInset(rect, 0.5, 0.5));

    CGContextRestoreGState(context);
}

/**
 @Status Interoperable
*/
void UIRectClip(CGRect clip) {
    CGContextRef ctx = UIGraphicsGetCurrentContext();

    CGContextClipToRect(ctx, clip);
}

/**
 @Status Stub
 @Notes
*/
void UIImageWriteToSavedPhotosAlbum(UIImage* image, id completionTarget, SEL completionSelector, void* contextInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void UISaveVideoAtPathToSavedPhotosAlbum(NSString* videoPath, id completionTarget, SEL completionSelector, void* contextInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIVideoAtPathIsCompatibleWithSavedPhotosAlbum(NSString* videoPath) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
NSString* NSStringFromCGPoint(CGPoint p) {
    return [NSString stringWithFormat:@"{%f,%f}", p.x, p.y];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromCGSize(CGSize s) {
    return [NSString stringWithFormat:@"{%f,%f}", s.width, s.height];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromCGRect(CGRect r) {
    return [NSString stringWithFormat:@"{{%f, %f}, {%f, %f}}", r.origin.x, r.origin.y, r.size.width, r.size.height];
}

/**
 @Status Interoperable
*/
CGPoint CGPointFromString(NSString* strPt) {
    if (!strPt) {
        return { 0, 0 };
    }

    CGPoint ret;

    const char* str = [strPt UTF8String];
    sscanf_s(str, "{%f, %f}", &ret.x, &ret.y);
    return ret;
}

/**
 @Status Interoperable
*/
CGRect CGRectFromString(NSString* string) {
    if (!string) {
        return { { 0, 0 }, 0, 0 };
    }

    CGRect ret;

    const char* str = [string UTF8String];
    sscanf_s(str, "{{%f, %f}, {%f, %f}}", &ret.origin.x, &ret.origin.y, &ret.size.width, &ret.size.height);
    return ret;
}

/**
 @Status Interoperable
*/
CGSize CGSizeFromString(NSString* strSize) {
    if (!strSize) {
        return { 0, 0 };
    }

    CGSize ret;

    const char* str = [strSize UTF8String];
    sscanf_s(str, "{%f, %f}", &ret.width, &ret.height);
    return ret;
}
