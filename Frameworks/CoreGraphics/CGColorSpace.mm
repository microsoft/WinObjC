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

#include "Starboard.h"

#include "CGContextInternal.h"
#include "CGColorSpaceInternal.h"

static IWLazyClassLookup _LazyUIColor("UIColor"); 

@interface CGNSColorSpace : NSObject {
}
@end

@implementation CGNSColorSpace
    -(void) dealloc {
        delete (__CGColorSpace *) self;
    }

    -(id) retain {
        CFRetain(self);

        return self;
    }

    -(void) release {
        CFRelease(self);
    }
@end

__CGColorSpace::__CGColorSpace(surfaceFormat fmt)
{
    isa = NULL;
    object_setClass((id) this, [CGNSColorSpace class]);

    colorSpace = fmt;
    palette = NULL;
    lastColor = 0;
}

__CGColorSpace::~__CGColorSpace()
{
    if ( palette ) {
        delete palette;
        palette = NULL;
    }
}

CGColorSpaceRef CGColorSpaceCreateCalibratedRGB()
{
    EbrDebugLog("CGColorSpaceCreateCalibratedRGB not supported\n");
    return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
}

CGColorSpaceRef CGColorSpaceCreateIndexed(id baseSpace, int lastIndex, void *colorTable)
{
    __CGColorSpace *ret = new __CGColorSpace(_ColorIndexed);

    ret->palette = (char *) malloc(3 * (lastIndex + 1));
    memcpy(ret->palette, colorTable, 3 * (lastIndex + 1));
    ret->lastColor = lastIndex;
    return (CGColorSpaceRef) ret;
}

CGColorSpaceRef CGColorSpaceCreateDeviceRGB()
{
    return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
}

CGColorSpaceRef CGColorSpaceCreatePattern(CGColorSpaceRef source)
{
    return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
}

CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef colorSpace)
{
    EbrDebugLog("CGColorSpaceGetModel not implemented\n");
    return kCGColorSpaceModelRGB;
}

size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef pSpace)
{
    switch ( ((__CGColorSpace *) pSpace)->colorSpace ) {
        case _ColorRGBA:
        case _ColorARGB:
            return 3;

        case _ColorGrayscale:
            return 1;

        default:
            assert(0);
            return 0;
    }
}

CGColorSpaceRef CGColorSpaceCreateDeviceGray()
{
    return (CGColorSpaceRef) new __CGColorSpace(_ColorGrayscale);
}

CGColorSpaceRef CGColorSpaceCreateWithName(id name)
{
    char *strName = (char *) [name UTF8String];

    if ( strcmp(strName, "kCGColorSpaceGenericRGB") == 0 ) {
        return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
    } else if ( strcmp(strName, "kCGColorSpaceGenericRGBLinear") == 0 ) {
        return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
    } else {
        assert(0);
    }

    return NULL;
}

void CGColorSpaceRelease(CGColorSpaceRef colorSpace)
{
    CFRelease((id) colorSpace);
}

CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef colorSpace)
{
    CFRetain((id) colorSpace);

    return colorSpace;
}

void CGColorRelease(CGColorRef color)
{
    CFRelease(color);
}

CGColorRef CGColorRetain(CGColorRef color)
{
    CFRetain((id)color);

    return color;
}

CGColorRef CGColorCreateCopy(CGColorRef color)
{
    // Revisit?
    return CGColorRetain(color);
}

CGColorRef CGColorCreate(CGColorSpaceRef colorSpace, const float *components)
{
    CGColorRef ret = (CGColorRef) [[_LazyUIColor colorWithRed:components[0] green:components[1] blue:components[2] alpha:components[3]] retain];

    return ret;
}

CGColorRef CGColorCreateCopyWithAlpha(CGColorRef color, float alpha)
{
    float curColor[4];

    [(UIColor*) color getColors:curColor];

    id ret = [[_LazyUIColor colorWithRed:curColor[0] green:curColor[1] blue:curColor[2] alpha:alpha] retain];

    return (CGColorRef) ret;
}
CGColorRef CGColorCreateWithPattern(CGColorSpaceRef colorSpace, id pattern, float components[])
{
    CGColorRef ret = (CGColorRef) [[_LazyUIColor colorWithCGPattern:pattern] retain];
    
    return ret;
}

CGColorRef CGColorCreateGenericRGB(float r, float g, float b, float a)
{
    CGColorRef ret = (CGColorRef) [[_LazyUIColor colorWithRed:r green:g blue:b alpha:a] retain];

    return ret;
}

bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2)
{
    float components1[4] = { 0.0f };
    float components2[4] = { 0.0f };

    [(UIColor*) color1 getColors:components1];
    [(UIColor*) color2 getColors:components2];

    for ( int i = 0; i < 4; i ++ ) {
        if ( components1[i] != components2[i] ) return FALSE;
    }

    return TRUE;
}

CGColorRef CGColorGetConstantColor(CFStringRef name)
{
    UIColor* ret;

    char *pName = (char *) [name UTF8String];
    if ( strcmp(pName, "BLACK") == 0 ) {
        ret = [_LazyUIColor blackColor];
    } else {
        assert(0);
    }

    return (CGColorRef) [ret retain];
}

size_t CGColorGetNumberOfComponents(CGColorRef color)
{
    /* [BUG: Not all colors have 4 components, but all of the ones we currently support do!] */
    return 4;
}

CGFloat CGColorGetAlpha(CGColorRef color)
{
    float components[4];

    [(UIColor*) color getColors:components];

    return (CGFloat)components[3];
}

CGColorSpaceRef CGColorGetColorSpace(CGColorRef color)
{
    return CGColorSpaceCreateDeviceRGB();
}

;
;
;
;
;
;
;
    
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
