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
    float curColor[4];

    [(UIColor*)color getColors:curColor];

    id ret = [[_LazyUIColor colorWithRed:curColor[0] green:curColor[1] blue:curColor[2] alpha:alpha] retain];

    return (CGColorRef)ret;
}

/**
 @Status Interoperable
*/
CGColorRef CGColorCreateWithPattern(CGColorSpaceRef colorSpace, id pattern, float components[]) {
    CGColorRef ret = (CGColorRef)[[_LazyUIColor colorWithCGPattern:(CGPatternRef)pattern] retain];

    return ret;
}

/**
 @Status Interoperable
*/
bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2) {
    float components1[4] = { 0.0f };
    float components2[4] = { 0.0f };

    [(UIColor*)color1 getColors:components1];
    [(UIColor*)color2 getColors:components2];

    for (int i = 0; i < 4; i++) {
        if (components1[i] != components2[i]) {
            return FALSE;
        }
    }

    return TRUE;
}

/**
 @Status Interoperable
*/
CGFloat CGColorGetAlpha(CGColorRef color) {
    float components[4];

    [(UIColor*)color getColors:components];

    return (CGFloat)components[3];
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
    [(UIColor*)color getColors:ret];
    return ret;
}

/**
 @Status Stub
*/
size_t CGColorGetNumberOfComponents(CGColorRef color) {
    UNIMPLEMENTED();
    /* [BUG: Not all colors have 4 components, but all of the ones we currently
    * support do!] */
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
