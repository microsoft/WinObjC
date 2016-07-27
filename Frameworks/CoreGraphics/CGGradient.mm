//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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
#import <CoreGraphics/CGContext.h>
#import "CGColorSpaceInternal.h"
#import "CGGradientInternal.h"
#import "UIColorInternal.h"
#import "_CGLifetimeBridgingType.h"

@interface CGNSGradient : _CGLifetimeBridgingType
@end

@implementation CGNSGradient
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
- (void)dealloc {
    delete (__CGGradient*)self;
}
#pragma clang diagnostic pop
@end

__CGGradient::__CGGradient() : _components(NULL), _locations(NULL) {
    object_setClass((id) this, [CGNSGradient class]);
}

__CGGradient::~__CGGradient() {
    if (_components) {
        delete[] _components;
        _components = NULL;
    }
    if (_locations) {
        delete[] _locations;
        _locations = NULL;
    }
}

void __CGGradient::initWithColorComponents(const float* components, const float* locations, size_t count, CGColorSpaceRef colorspace) {
    __CGColorSpace* cs = (__CGColorSpace*)colorspace;
    DWORD componentCount = 0;

    _colorSpaceModel = cs->colorSpaceModel;

    switch (_colorSpaceModel) {
        case kCGColorSpaceModelRGB:
            componentCount = 4;
            _format = _ColorABGR;
            break;
        case kCGColorSpaceModelMonochrome:
            componentCount = 2;
            _format = _ColorGrayscale;
            break;
        default:
            UNIMPLEMENTED_WITH_MSG("Unsupported colorspace used to create gradiant.");
            break;
    }

    _components = new float[count * componentCount];
    memcpy(_components, components, sizeof(float) * count * componentCount);

    _locations = new float[count];

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

    _colorSpaceModel = cs->colorSpaceModel;

    switch (_colorSpaceModel) {
        case kCGColorSpaceModelRGB:
            componentCount = 4;
            _format = _ColorABGR;
            break;
        case kCGColorSpaceModelMonochrome:
            componentCount = 2;
            _format = _ColorGrayscale;
            break;
        default:
            UNIMPLEMENTED_WITH_MSG("Unsupported colorspace used to create gradiant.");
            break;
    }

    int count = [components count];

    _components = new CGFloat[count * componentCount];

    for (int i = 0; i < count; i++) {
        UIColor* curColor = [components objectAtIndex:i];

        if (curColor) {
            const __CGColorQuad* color = [curColor _getColors];
            memcpy(&_components[i * componentCount], color, sizeof(CGFloat) * componentCount);
        } else {
            memset(&_components[i * componentCount], 0, sizeof(CGFloat) * componentCount);
        }
    }

    _locations = new float[count];

    if (locations) {
        memcpy(_locations, locations, sizeof(float) * count);
    } else {
        for (int i = 0; i < count; i++) {
            _locations[i] = (float)i / (float)(count - 1);
        }
    }

    _count = count;
}

/**
 @Status Interoperable
*/
CGGradientRef CGGradientCreateWithColorComponents(CGColorSpaceRef colorSpace,
                                                  const float* components,
                                                  const float* locations,
                                                  size_t count) {
    CGGradientRef ret = new __CGGradient();
    ret->initWithColorComponents(components, locations, count, colorSpace);

    return ret;
}

/**
 @Status Interoperable
*/
CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef colorSpace, CFArrayRef colors, const float* locations) {
    CGGradientRef ret = new __CGGradient();
    ret->initWithColors(colors, locations, colorSpace);

    return ret;
}

/**
 @Status Interoperable
*/
void CGGradientRelease(CGGradientRef gradient) {
    CFRelease((id)gradient);
}

/**
 @Status Interoperable
*/
CGGradientRef CGGradientRetain(CGGradientRef gradient) {
    CFRetain((id)gradient);
    return gradient;
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGGradientGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
