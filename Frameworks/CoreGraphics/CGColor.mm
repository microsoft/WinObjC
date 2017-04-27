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

#include <StubReturn.h>
#include <Starboard.h>
#include <CoreGraphics/CGColor.h>
#include <CFCppBase.h>
#include "CGColorInternal.h"

const CFStringRef kCGColorBlack = CFSTR("BLACK");
const CFStringRef kCGColorWhite = CFSTR("WHITE");
const CFStringRef kCGColorClear = CFSTR("CLEAR");

static const wchar_t* TAG = L"CGColor";

struct __CGColor : CoreFoundation::CppBase<__CGColor> {
    // Override to add Equals method
    static CFTypeID GetTypeID() {
        static __CFRuntimeClass _cls{
            0, // Version
            typeid(__CGColor).name(), // Class Name
            nullptr, // Init
            nullptr, // Copy (ill-defined for CF)
            &_CFFinalize, // Finalize
            &__CFEquals, // Equals
            nullptr, // Hash
            nullptr, // Copy Description
            nullptr, // Copy Debug Description
        };
        static CFTypeID _id = _CFRuntimeRegisterClass(&_cls);
        return _id;
    }

    __CGColor(CGColorSpaceRef colorspace, CGFloat r, CGFloat g, CGFloat b, CGFloat alpha)
        : _colorSpace(colorspace), _pattern(nullptr), _components{ r, g, b, alpha } {
    }

    __CGColor(CGColorSpaceRef colorSpace, CGPatternRef pattern) : _colorSpace(colorSpace), _pattern(pattern) {
        // TODO #2581: CGColorCreateWithPattern should support components
        _components.Clear();
    }

    // CreateCopyWithAlpha
    __CGColor(const __CGColor& color, float alpha) : _colorSpace(color._colorSpace), _pattern(color._pattern) {
        if (color.IsPatternColor()) {
            _components.Clear();
            _components.a = alpha;
        } else {
            _components.SetColorComponents(color._components.r, color._components.g, color._components.b, alpha);
        }
    }

    bool operator==(const __CGColor& other) const {
        return (CGColorSpaceGetModel(_colorSpace) == CGColorSpaceGetModel(other._colorSpace)) && (_pattern == other._pattern) &&
               (_components == other._components);
    }

    inline CGFloat Alpha() const {
        return _components.a;
    }

    inline CGColorSpaceRef ColorSpace() const {
        return _colorSpace;
    }

    inline const __CGColorQuad& ColorComponents() const {
        return _components;
    }

    inline CGPatternRef Pattern() const {
        return _pattern;
    }

private:
    __CGColorQuad _components;
    woc::StrongCF<CGColorSpaceRef> _colorSpace;
    woc::StrongCF<CGPatternRef> _pattern;

    static Boolean __CFEquals(CFTypeRef color1, CFTypeRef color2) {
        return *((__CGColor*)color1) == *((__CGColor*)color2);
    }

    inline bool IsPatternColor() const {
        return _pattern != nullptr;
    }
};

/**
 @Status Caveat
 @Notes components are not supported
*/
CGColorRef CGColorCreateWithPattern(CGColorSpaceRef colorSpace, CGPatternRef pattern, const CGFloat* components) {
    RETURN_NULL_IF(!colorSpace);
    RETURN_NULL_IF(!pattern);
    return __CGColor::CreateInstance(kCFAllocatorDefault, colorSpace, pattern);
}

/**
 @Status Interoperable
*/
CGColorRef CGColorGetConstantColor(CFStringRef name) {
    if (CFEqual(kCGColorBlack, name)) {
        static woc::StrongCF<CGColorRef> s_black{ woc::TakeOwnership, CGColorCreateGenericGray(0.0f, 1.0f) };
        return s_black;
    } else if (CFEqual(kCGColorWhite, name)) {
        static woc::StrongCF<CGColorRef> s_white{ woc::TakeOwnership, CGColorCreateGenericGray(1.0f, 1.0f) };
        return s_white;
    } else if (CFEqual(kCGColorClear, name)) {
        static woc::StrongCF<CGColorRef> s_clear{ woc::TakeOwnership, CGColorCreateGenericGray(0.0f, 0.0f) };
        return s_clear;
    }

    TraceError(TAG, L"Unknown constant color name: %s", CFStringGetCStringPtr(name, kCFStringEncodingUTF8));
    return nullptr;
}

/**
 @Status Interoperable
*/
void CGColorRelease(CGColorRef color) {
    RETURN_IF(!color);
    CFRelease(static_cast<CFTypeRef>(color));
}

/**
 @Status Interoperable
*/
CGColorRef CGColorRetain(CGColorRef color) {
    RETURN_NULL_IF(!color);
    CFRetain(static_cast<CFTypeRef>(color));
    return color;
}

/**
 @Status Caveat
 @Notes only supports RGB & Monochrome
*/
CGColorRef CGColorCreate(CGColorSpaceRef colorSpace, const CGFloat* components) {
    RETURN_NULL_IF(!colorSpace);
    RETURN_NULL_IF(!components);
    CGColorSpaceModel model = CGColorSpaceGetModel(colorSpace);
    switch (model) {
        case kCGColorSpaceModelRGB:
            return __CGColor::CreateInstance(kCFAllocatorDefault, colorSpace, components[0], components[1], components[2], components[3]);
        case kCGColorSpaceModelMonochrome:
            return __CGColor::CreateInstance(kCFAllocatorDefault, colorSpace, components[0], components[0], components[0], components[1]);
        default:
            UNIMPLEMENTED_WITH_MSG("Colorspace Unsupported. Model: %d", model);
    }

    return nullptr;
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
CGColorRef CGColorCreateCopyWithAlpha(CGColorRef color, CGFloat alpha) {
    RETURN_NULL_IF(!color);
    return __CGColor::CreateInstance(kCFAllocatorDefault, *color, alpha);
}

/**
 @Status Interoperable
*/
bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2) {
    RETURN_RESULT_IF(color1 == color2, true);
    RETURN_FALSE_IF(!color1 || !color2);
    return CFEqual(color1, color2);
}

/**
 @Status Interoperable
*/
CGFloat CGColorGetAlpha(CGColorRef color) {
    RETURN_RESULT_IF(!color, 0.0f);
    return color->Alpha();
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorGetColorSpace(CGColorRef color) {
    RETURN_NULL_IF(!color);
    return color->ColorSpace();
}

/**
 @Status Caveat
 @Notes Works as expected for RGBA only.
*/
const CGFloat* CGColorGetComponents(CGColorRef color) {
    RETURN_NULL_IF(!color);
    return reinterpret_cast<const CGFloat*>(&color->ColorComponents());
}

/**
 @Status Caveat
 @Notes Limited support for colorspace
*/
size_t CGColorGetNumberOfComponents(CGColorRef color) {
    RETURN_RESULT_IF_NULL(color, 0);
    return CGColorSpaceGetNumberOfComponents(color->ColorSpace()) + 1;
}

/**
 @Status Interoperable
*/
CGPatternRef CGColorGetPattern(CGColorRef color) {
    RETURN_NULL_IF(!color);
    return color->Pattern();
}

/**
 @Status Interoperable
*/
CFTypeID CGColorGetTypeID() {
    return __CGColor::GetTypeID();
}

/**
 @Status Interoperable
*/
CGColorRef CGColorCreateGenericRGB(CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha) {
    static const auto colorspace_rgb = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceRGB());
    return __CGColor::CreateInstance(kCFAllocatorDefault, colorspace_rgb, red, green, blue, alpha);
}

/**
 @Status Interoperable
*/
CGColorRef CGColorCreateGenericGray(CGFloat gray, CGFloat alpha) {
    static const auto colorspace_grayscale = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceGray());
    return __CGColor::CreateInstance(kCFAllocatorDefault, colorspace_grayscale, gray, gray, gray, alpha);
}

/**
 @Status Stub
*/
CGColorRef CGColorCreateGenericCMYK(CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CGColorRef CGColorCreateCopyByMatchingToColorSpace(CGColorSpaceRef,
                                                   CGColorRenderingIntent intent,
                                                   CGColorRef color,
                                                   CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}
