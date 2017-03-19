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
#import <vector>
#import <CFCppBase.h>

#import "CGContextInternal.h"
#import "CGColorSpaceInternal.h"
#import "_CGLifetimeBridgingType.h"
#import "LoggingNative.h"

static const wchar_t* TAG = L"CGColorSpace";

const CFStringRef kCGColorSpaceGenericGray = static_cast<CFStringRef>(@"kCGColorSpaceGenericGray");
const CFStringRef kCGColorSpaceGenericRGB = static_cast<CFStringRef>(@"kCGColorSpaceGenericRGB");
const CFStringRef kCGColorSpaceGenericCMYK = static_cast<CFStringRef>(@"kCGColorSpaceGenericCMYK");
const CFStringRef kCGColorSpaceGenericRGBLinear = static_cast<CFStringRef>(@"kCGColorSpaceGenericRGBLinear");
const CFStringRef kCGColorSpaceAdobeRGB1998 = static_cast<CFStringRef>(@"kCGColorSpaceAdobeRGB1998");
const CFStringRef kCGColorSpaceSRGB = static_cast<CFStringRef>(@"kCGColorSpaceSRGB");
const CFStringRef kCGColorSpaceGenericGrayGamma2_2 = static_cast<CFStringRef>(@"kCGColorSpaceGenericGrayGamma2_2");
const CFStringRef kCGColorSpaceGenericXYZ = static_cast<CFStringRef>(@"kCGColorSpaceGenericXYZ");
const CFStringRef kCGColorSpaceACESCGLinear = static_cast<CFStringRef>(@"kCGColorSpaceACESCGLinear");
const CFStringRef kCGColorSpaceITUR_709 = static_cast<CFStringRef>(@"kCGColorSpaceITUR_709");
const CFStringRef kCGColorSpaceITUR_2020 = static_cast<CFStringRef>(@"kCGColorSpaceITUR_2020");
const CFStringRef kCGColorSpaceROMMRGB = static_cast<CFStringRef>(@"kCGColorSpaceROMMRGB");

struct __CGColorSpace : CoreFoundation::CppBase<__CGColorSpace> {
    __CGColorSpace(CGColorSpaceModel model, CGColorSpaceRef baseSpace = nullptr, size_t lastIndex = 0)
        : _colorSpaceModel(model), _baseColorSpace(baseSpace), _lastColorIndex(lastIndex) {
    }

    __CGColorSpace(CGColorSpaceModel model, CGColorSpaceRef baseSpace, size_t lastIndex, const unsigned char* colorTable)
        : _colorSpaceModel(model),
          _baseColorSpace(baseSpace),
          _lastColorIndex(lastIndex),
          _palette(colorTable, colorTable + CGColorSpaceGetNumberOfComponents(baseSpace) * (lastIndex + 1)) {
    }

    inline CGColorSpaceModel ColorSpaceModel() const {
        return _colorSpaceModel;
    }

    inline CGColorSpaceRef BaseColorSpace() const {
        return _baseColorSpace;
    }

    inline size_t LastColorIndex() const {
        return _lastColorIndex;
    }

private:
    CGColorSpaceModel _colorSpaceModel;
    woc::StrongCF<CGColorSpaceRef> _baseColorSpace;
    std::vector<char> _palette;
    size_t _lastColorIndex;
};

/**
 @Status Interoperable
*/
CFTypeID CGColorSpaceGetTypeID() {
    return __CGColorSpace::GetTypeID();
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreateDeviceRGB() {
    static const woc::StrongCF<CGColorSpaceRef> sc_rgbColorSpace{ __CGColorSpace::CreateInstance(kCFAllocatorDefault,
                                                                                                 kCGColorSpaceModelRGB) };

    return CGColorSpaceRetain(sc_rgbColorSpace);
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreateDeviceGray() {
    static const woc::StrongCF<CGColorSpaceRef> sc_grayColorSpace{ __CGColorSpace::CreateInstance(kCFAllocatorDefault,
                                                                                                  kCGColorSpaceModelMonochrome) };

    return CGColorSpaceRetain(sc_grayColorSpace);
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreatePattern(CGColorSpaceRef baseSpace) {
    // base space can be null
    RETURN_NULL_IF(baseSpace && CGColorSpaceGetModel(baseSpace) == kCGColorSpaceModelPattern);
    return __CGColorSpace::CreateInstance(kCFAllocatorDefault, kCGColorSpaceModelPattern, baseSpace);
}

CGColorSpaceRef _CGColorSpaceCreate(CGColorSpaceModel model) {
    return __CGColorSpace::CreateInstance(kCFAllocatorDefault, model);
}

/**
 @Status Stub
*/
CGColorSpaceRef CGColorSpaceCreateCalibratedRGB(const CGFloat whitePoint[3],
                                                const CGFloat blackPoint[3],
                                                const CGFloat gamma[3],
                                                const CGFloat matrix[9]) {
    UNIMPLEMENTED_WITH_MSG("CGColorSpaceCreateCalibratedRGB not supported");
    return __CGColorSpace::CreateInstance(kCFAllocatorDefault, kCGColorSpaceModelRGB);
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreateIndexed(CGColorSpaceRef baseSpace, size_t lastIndex, const unsigned char* colorTable) {
    RETURN_NULL_IF(!baseSpace);
    RETURN_NULL_IF(lastIndex > 255);
    RETURN_NULL_IF(!colorTable);
    return __CGColorSpace::CreateInstance(kCFAllocatorDefault, kCGColorSpaceModelIndexed, baseSpace, lastIndex, colorTable);
}

/**
 @Status Caveat
 @Notes Only GenericRGB, GenericRGBLinear and GenericGray supported
*/
CGColorSpaceRef CGColorSpaceCreateWithName(CFStringRef name) {
    RETURN_NULL_IF(!name);
    if (CFEqual(kCGColorSpaceGenericRGB, name) || CFEqual(kCGColorSpaceGenericRGBLinear, name)) {
        return CGColorSpaceCreateDeviceRGB();
    } else if (CFEqual(kCGColorSpaceGenericGray, name)) {
        return CGColorSpaceCreateDeviceGray();
    } else {
        UNIMPLEMENTED_WITH_MSG("Colorspace Unsupported: %s", CFStringGetCStringPtr(name, kCFStringEncodingUTF8));
        return CGColorSpaceCreateDeviceRGB();
    }

    return nullptr;
}

/**
@Status Interoperable
*/
CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef colorSpace) {
    RETURN_RESULT_IF_NULL(colorSpace, kCGColorSpaceModelRGB);
    return colorSpace->ColorSpaceModel();
}

/**
@Status Caveat
@Notes Doesn't support all colorSpaces
*/
size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef pSpace) {
    RETURN_RESULT_IF_NULL(pSpace, 0);
    CGColorSpaceModel colorSpaceModel = CGColorSpaceGetModel(colorSpace);

    switch (colorSpaceModel) {
        case kCGColorSpaceModelRGB:
            return 3;
        case kCGColorSpaceModelPattern:
        case kCGColorSpaceModelMonochrome:
            return 1;
        case kCGColorSpaceModelCMYK:
            return 4;
        default:
            UNIMPLEMENTED_WITH_MSG("Colorspace Unsupported. Model: %d", colorSpaceModel);
            return 0;
    }
}

/**
 @Status Interoperable
*/
void CGColorSpaceRelease(CGColorSpaceRef colorSpace) {
    RETURN_IF(!colorSpace);
    CFRelease(static_cast<CFTypeRef>(colorSpace));
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef colorSpace) {
    RETURN_NULL_IF(!colorSpace);
    CFRetain(static_cast<CFTypeRef>(colorSpace));
    return colorSpace;
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CGColorSpaceCopyICCProfile(CGColorSpaceRef space) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGColorSpaceRef CGColorSpaceCreateCalibratedGray(const CGFloat whitePoint[3], const CGFloat blackPoint[3], CGFloat gamma) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGColorSpaceRef CGColorSpaceCreateDeviceCMYK() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGColorSpaceRef CGColorSpaceCreateICCBased(size_t nComponents, const CGFloat* range, CGDataProviderRef profile, CGColorSpaceRef alternate) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGColorSpaceRef CGColorSpaceCreateLab(const CGFloat whitePoint[3], const CGFloat blackPoint[3], const CGFloat range[4]) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGColorSpaceRef CGColorSpaceCreateWithICCProfile(CFDataRef data) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGColorSpaceRef CGColorSpaceCreateWithPlatformColorSpace(const void* ref) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceGetBaseColorSpace(CGColorSpaceRef space) {
    RETURN_NULL_IF(!space);
    return space->BaseColorSpace();
}

/**
 @Status Stub
 @Notes
*/
size_t CGColorSpaceGetColorTableCount(CGColorSpaceRef space) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGColorSpaceGetColorTable(CGColorSpaceRef space, uint8_t* table) {
    UNIMPLEMENTED();
}
