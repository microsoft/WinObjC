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
#include "CoreGraphics/CGContext.h"
#include "CGColorSpaceInternal.h"
#include "CGGradientInternal.h"

@interface CGNSGradient : NSObject {
}
@end

@implementation CGNSGradient
- (void)dealloc {
    delete (__CGGradient*)self;
}

- (id)retain {
    CGGradientRetain((CGGradientRef)self);

    return self;
}

- (void)release {
    CGGradientRelease((CGGradientRef)self);
}
@end

__CGGradient::__CGGradient() {
    isa = NULL;
    object_setClass((id) this, [CGNSGradient class]);
}

__CGGradient::~__CGGradient() {
    free(_components);
    free(_locations);
}

void __CGGradient::initWithColorComponents(const float* components, const float* locations, size_t count, CGColorSpaceRef colorspace) {
    DWORD componentCount = 0;
    __CGColorSpace* cs = (__CGColorSpace*)colorspace;
    _colorSpace = cs->colorSpace;

    switch (_colorSpace) {
        case _ColorRGB:
            componentCount = 3;
            break;

        case _ColorRGBA:
            componentCount = 4;
            break;

        case _ColorGrayscale:
            componentCount = 2;
            break;

        default:
            assert(0);
            break;
    }

    _components = (float*)malloc(sizeof(float) * count * componentCount);
    memcpy(_components, components, sizeof(float) * count * componentCount);

    _locations = (float*)malloc(sizeof(float) * count);

    if (locations) {
        memcpy(_locations, locations, sizeof(float) * count);
    } else {
        for (unsigned i = 0; i < count; i++) {
            _locations[i] = (float)i / (float)(count - 1);
        }
    }

    _count = count;
}

void __CGGradient::initWithColors(CFArrayRef componentsArr, const float* locations, CGColorSpaceRef colorspace) {
    NSArray* components = (NSArray*)componentsArr;
    size_t componentCount = 0;
    __CGColorSpace* cs = (__CGColorSpace*)colorspace;

    _colorSpace = _ColorRGBA;

    switch (_colorSpace) {
        case _ColorRGB:
            componentCount = 3;
            break;

        case _ColorRGBA:
            componentCount = 4;
            break;

        case _ColorGrayscale:
            componentCount = 2;
            break;

        default:
            assert(0);
            break;
    }

    int count = [components count];

    _components = (float*)malloc(sizeof(float) * count * componentCount);

    for (int i = 0; i < count; i++) {
        id curColor = [components objectAtIndex:i];

        float color[4];
        [curColor getColors:color];
        memcpy(&_components[i * componentCount], color, sizeof(float) * count * componentCount);
    }

    _locations = (float*)malloc(sizeof(float) * count);

    if (locations) {
        memcpy(_locations, locations, sizeof(float) * count);
    } else {
        for (int i = 0; i < count; i++) {
            _locations[i] = (float)i / (float)(count - 1);
        }
    }

    _count = count;
}

CGGradientRef CGGradientCreateWithColorComponents(CGColorSpaceRef colorSpace,
                                                  const float* components,
                                                  const float* locations,
                                                  size_t count) {
    CGGradientRef ret = new __CGGradient();
    ret->initWithColorComponents(components, locations, count, colorSpace);

    return ret;
}

CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef colorSpace, CFArrayRef colors, const float* locations) {
    CGGradientRef ret = new __CGGradient();
    ret->initWithColors(colors, locations, colorSpace);

    return ret;
}

void CGGradientRelease(CGGradientRef gradient) {
    CFRelease((id)gradient);
}

CGGradientRef CGGradientRetain(CGGradientRef gradient) {
    CFRetain((id)gradient);
    return gradient;
}
