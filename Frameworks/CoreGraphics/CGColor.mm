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

#import <StubReturn.h>
#import <Starboard.h>
#import <CoreGraphics/CGColor.h>

#import "UIColorInternal.h"

const CFStringRef kCGColorBlack = CFSTR("BLACK");
const CFStringRef kCGColorWhite = CFSTR("WHITE");
const CFStringRef kCGColorClear = CFSTR("CLEAR");

static IWLazyClassLookup __LazyUIColor("UIColor");

/**
 @Status Caveat
 @Notes Limited constants supported
*/
CGColorRef CGColorGetConstantColor(CFStringRef name) {
    CGColorRef ret = nullptr;
    woc::StrongCF<CGColorSpaceRef> colorspace;
    if (CFEqual(kCGColorBlack, name)) {
        ret = static_cast<CGColorRef>([[__LazyUIColor blackColor] CGColor]);
        colorspace = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceGray());
    } else if (CFEqual(kCGColorWhite, name)) {
        ret = static_cast<CGColorRef>([[__LazyUIColor whiteColor] CGColor]);
        colorspace = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceGray());
    } else if (CFEqual(kCGColorClear, name)) {
        ret = static_cast<CGColorRef>([[__LazyUIColor clearColor] CGColor]);
        colorspace = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceGray());
    } else {
        UNIMPLEMENTED_WITH_MSG("CGColorGetConstantColor does not support color %s", CFStringGetCStringPtr(name, kCFStringEncodingUTF8));
    }

    if (ret) {
        [static_cast<UIColor*>(ret) setColorSpace:colorspace];
    }

    return ret;
}

/**
 @Status Interoperable
*/
void CGColorRelease(CGColorRef color) {
    RETURN_IF(!color);
    CFRelease(color);
}

/**
 @Status Interoperable
*/
CGColorRef CGColorRetain(CGColorRef color) {
    CFRetain((id)color);

    return color;
}

/**
 @Status Caveat
 @Notes only supports RGB
*/
CGColorRef CGColorCreate(CGColorSpaceRef colorSpace, const CGFloat* components) {
    RETURN_NULL_IF(!colorSpace);
    RETURN_NULL_IF(!components);
    CGColorRef ret = static_cast<CGColorRef>(
        [[__LazyUIColor colorWithRed:components[0] green:components[1] blue:components[2] alpha:components[3]] retain]);
    [static_cast<UIColor*>(ret) setColorSpace:colorSpace];
    return ret;
}

/**
 @Status Interoperable
*/
CGColorRef CGColorCreateCopy(CGColorRef color) {
    return CGColorRetain(color);
}

/**
 @Status Interoperable
*/
CGColorRef CGColorCreateCopyWithAlpha(CGColorRef color, float alpha) {
    RETURN_NULL_IF(!color);
    static __CGColorQuad defaultColor{ 0.0f, 0.0f, 0.0f, 0.0f };
    const __CGColorQuad* curColor = [(UIColor*)color _getColors];
    if (!curColor) {
        curColor = &defaultColor;
    }

    CGColorRef ret =
        static_cast<CGColorRef>([[__LazyUIColor colorWithRed:curColor->r green:curColor->g blue:curColor->b alpha:alpha] retain]);
    [static_cast<UIColor*>(ret) setColorSpace:CGColorGetColorSpace(color)];
    return ret;
}

/**
 @Status Caveat
 @Notes components are not supported
*/
CGColorRef CGColorCreateWithPattern(CGColorSpaceRef colorSpace, CGPatternRef pattern, const CGFloat* components) {
    RETURN_NULL_IF(!colorSpace);
    RETURN_NULL_IF(!pattern);
    CGColorRef ret = static_cast<CGColorRef>([[__LazyUIColor _colorWithCGPattern:(CGPatternRef)pattern] retain]);
    [static_cast<UIColor*>(ret) setColorSpace:colorSpace];
    return ret;
}

/**
 @Status Interoperable
*/
bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2) {
    if (color1 == color2) {
        return true;
    }
    if (!color1 || !color2) {
        return false;
    }
    const __CGColorQuad* components1 = [(UIColor*)color1 _getColors];
    const __CGColorQuad* components2 = [(UIColor*)color2 _getColors];

    return ((components1->r == components2->r) && (components1->g == components2->g) && (components1->b == components2->b) &&
            (components1->a == components2->a)) &&
           (CGColorSpaceGetModel(CGColorGetColorSpace(color1)) == CGColorSpaceGetModel(CGColorGetColorSpace(color2)));
}

/**
 @Status Interoperable
*/
CGFloat CGColorGetAlpha(CGColorRef color) {
    RETURN_RESULT_IF(!color, 0.0f);
    const __CGColorQuad* curColor = [(UIColor*)color _getColors];
    return curColor->a;
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorGetColorSpace(CGColorRef color) {
    RETURN_NULL_IF(!color);
    return [static_cast<UIColor*>(color) colorSpace];
}

/**
 @Status Caveat
 @Notes Works as expected for RGBA only.
*/
const CGFloat* CGColorGetComponents(CGColorRef color) {
    return (const CGFloat*)[(UIColor*)color _getColors];
}

/**
 @Status Caveat
 @Notes Not all colors have 4 components, but all of the ones we currently support do!
*/
size_t CGColorGetNumberOfComponents(CGColorRef color) {
    return 4;
}

/**
 @Status Stub
 @Notes
*/
CGPatternRef CGColorGetPattern(CGColorRef color) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGColorGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
