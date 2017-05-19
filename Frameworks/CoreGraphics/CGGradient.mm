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
#import <CoreGraphics/CGContext.h>
#import <CFCppBase.h>
#import <vector>
#import <algorithm>
#import <iterator>
#import <LoggingNative.h>
#import "CGColorSpaceInternal.h"
#import "CGGradientInternal.h"

static const wchar_t* TAG = L"CGGradient";

struct __CGGradient : CoreFoundation::CppBase<__CGGradient> {
    __CGGradient(CGColorSpaceRef colorSpace = nullptr) : _colorSpace(colorSpace) {
    }

    __CGGradient(CGColorSpaceRef colorSpace, const CGFloat* components, const CGFloat* locations, size_t count)
        : _colorSpace(colorSpace),
          _colorComponents(components, components + count * (CGColorSpaceGetNumberOfComponents(_colorSpace) + 1)),
          _stopLocations(CopyLocations(locations, count)) {
    }

    __CGGradient(CGColorSpaceRef colorSpace, CFArrayRef components, const CGFloat* locations)
        : _colorSpace(woc::TakeOwnership, colorSpace ? CGColorSpaceRetain(colorSpace) : CGColorSpaceCreateDeviceRGB()),
          _colorComponents(CopyColorComponents(_colorSpace, components)),
          _stopLocations(CopyLocations(locations, CFArrayGetCount(components))) {
    }

    inline CGColorSpaceRef GetColorSpace() const {
        return _colorSpace;
    }

    inline const std::vector<CGFloat>& GetColorComponents() const {
        return _colorComponents;
    }

    inline const std::vector<CGFloat>& GetStopLocations() const {
        return _stopLocations;
    }

    woc::StrongCF<CGColorSpaceRef> _colorSpace;
    std::vector<CGFloat> _colorComponents;
    std::vector<CGFloat> _stopLocations;

private:
    std::vector<CGFloat> CopyLocations(const CGFloat* locations, size_t count) {
        // locations can be null
        std::vector<CGFloat> result;
        RETURN_RESULT_IF(count == 0, result);

        if (locations) {
            result = std::vector<CGFloat>(locations, locations + count);
        } else {
            result.reserve(count);

            for (size_t i = 0; i < count; i++) {
                result.push_back((CGFloat)i / (CGFloat)(count));
            }
        }

        return result;
    }

    std::vector<CGFloat> CopyColorComponents(CGColorSpaceRef colorspace, CFArrayRef components) {
        std::vector<CGFloat> result;
        size_t componentCount = CGColorSpaceGetNumberOfComponents(colorspace) + 1;
        CFIndex count = CFArrayGetCount(components);
        result.reserve(count * componentCount);
        static const CGFloat defaultColor[4] = { 0, 0, 0, 0 };

        for (CFIndex i = 0; i < count; i++) {
            CGColorRef curColor = (CGColorRef)CFArrayGetValueAtIndex(components, i);
            const CGFloat* color = curColor ? CGColorGetComponents(curColor) : defaultColor;
            result.insert(_colorComponents.begin() + i * componentCount, color, color + componentCount);
        }

        return result;
    }
};

/**
 @Status Interoperable
*/
CFTypeID CGGradientGetTypeID() {
    return __CGGradient::GetTypeID();
}

/**
 @Status Interoperable
*/
void CGGradientRelease(CGGradientRef gradient) {
    RETURN_IF(!gradient);
    CFRelease(static_cast<CFTypeRef>(gradient));
}

/**
 @Status Interoperable
*/
CGGradientRef CGGradientRetain(CGGradientRef gradient) {
    RETURN_NULL_IF(!gradient);
    CFRetain(static_cast<CFTypeRef>(gradient));
    return gradient;
}

static inline bool __isValidGradientColorspaceModel(CGColorSpaceRef colorspace) {
    // Note: null colorspace is valid
    // The colorspace cannot be kCGColorSpaceModelPattern || kCGColorSpaceModelIndexed
    CGColorSpaceModel colorSpaceModel = CGColorSpaceGetModel(colorspace);
    if ((colorSpaceModel == kCGColorSpaceModelPattern) || (colorSpaceModel == kCGColorSpaceModelIndexed)) {
        TraceError(TAG, L"Invalid colorspace %ld for gradient", colorSpaceModel);
        return false;
    }

    return true;
}

/**
 @Status Interoperable
*/
CGGradientRef CGGradientCreateWithColorComponents(CGColorSpaceRef colorSpace,
                                                  const CGFloat* components,
                                                  const CGFloat* locations,
                                                  size_t count) {
    RETURN_NULL_IF(!colorSpace);
    RETURN_NULL_IF(!components);
    RETURN_NULL_IF(count == 0);
    RETURN_NULL_IF(!__isValidGradientColorspaceModel(colorSpace));
    // location can be null
    return __CGGradient::CreateInstance(kCFAllocatorDefault, colorSpace, components, locations, count);
}

/**
 @Status Caveat
 @Notes Only RGB colorspace is supported, but individual colors can be of different colorspace
*/
CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef colorSpace, CFArrayRef colors, const CGFloat* locations) {
    RETURN_NULL_IF(!colors);
    RETURN_NULL_IF(!__isValidGradientColorspaceModel(colorSpace));
    // location can be null
    return __CGGradient::CreateInstance(kCFAllocatorDefault, colorSpace, colors, locations);
}

const std::vector<CGFloat>& _CGGradientGetStopLocations(CGGradientRef gradient) {
    return gradient->GetStopLocations();
}

const std::vector<CGFloat>& _CGGradientGetColorComponents(CGGradientRef gradient) {
    return gradient->GetColorComponents();
}

size_t _CGGradientGetCount(CGGradientRef gradient) {
    RETURN_RESULT_IF_NULL(gradient, 0);
    return gradient->GetStopLocations().size();
}

CGColorSpaceRef _CGGradientGetColorSpace(CGGradientRef gradient) {
    RETURN_NULL_IF(!gradient);
    return gradient->GetColorSpace();
}