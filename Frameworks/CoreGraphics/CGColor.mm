//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

static IWLazyClassLookup _LazyUIColor("UIColor");

/**
 @Status Interoperable
*/
void CGColorRelease(CGColorRef color) {
    if (color != nullptr) {
        CFRelease(color);
    }
}

/**
 @Status Interoperable
*/
CGColorRef CGColorRetain(CGColorRef color) {
    CFRetain((id)color);

    return color;
}

/**
 @Status Interoperable
*/
CGColorRef CGColorCreate(CGColorSpaceRef colorSpace, const float* components) {
    CGColorRef ret =
        (CGColorRef)[[_LazyUIColor colorWithRed:components[0] green:components[1] blue:components[2] alpha:components[3]] retain];

    return ret;
}

/**
 @Status Caveat
 @Notes TODO: need to revisit if retail is enough for CreateCopy
*/
CGColorRef CGColorCreateCopy(CGColorRef color) {
    return CGColorRetain(color);
}

/**
 @Status Interoperable
*/
CGColorRef CGColorCreateCopyWithAlpha(CGColorRef color, float alpha) {
    ColorQuad curColor;

    [(UIColor*)color getColors:&curColor];

    return static_cast<CGColorRef>([[_LazyUIColor colorWithRed:curColor.r green:curColor.g blue:curColor.b alpha:alpha] retain]);
}

/**
 @Status Interoperable
*/
CGColorRef CGColorCreateWithPattern(CGColorSpaceRef colorSpace, CGPatternRef pattern, const CGFloat* components) {
    CGColorRef ret = (CGColorRef)[[_LazyUIColor _colorWithCGPattern:(CGPatternRef)pattern] retain];

    return ret;
}

/**
 @Status Interoperable
*/
bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2) {
    ColorQuad components1{};
    ColorQuad components2{};

    [(UIColor*)color1 getColors:&components1];
    [(UIColor*)color2 getColors:&components2];

    return ((components1.r == components1.r) && (components1.g == components1.g) && (components1.b == components1.b) &&
            (components1.a == components1.a));
}

/**
 @Status Interoperable
*/
CGFloat CGColorGetAlpha(CGColorRef color) {
    ColorQuad components;

    [(UIColor*)color getColors:&components];

    return (CGFloat)components.a;
}

/**
 @Status Stub
 @Notes
*/
CGColorSpaceRef CGColorGetColorSpace(CGColorRef color) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Works as expected for RGBA only, but returns a client-freed buffer.
*/
const CGFloat* CGColorGetComponents(CGColorRef color) {
    float* ret = (float*)IwMalloc(sizeof(float) * 4);
    ColorQuad colorComponents;
    [(UIColor*)color getColors:&colorComponents];

    ColorQuadToFloatArray(colorComponents, ret);

    return ret;
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
