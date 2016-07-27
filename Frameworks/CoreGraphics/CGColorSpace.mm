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

#import "CGContextInternal.h"
#import "CGColorSpaceInternal.h"
#import "_CGLifetimeBridgingType.h"
#include "LoggingNative.h"

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

static IWLazyClassLookup _LazyUIColor2("UIColor");

@interface CGNSColorSpace : _CGLifetimeBridgingType
@end

@implementation CGNSColorSpace
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
- (void)dealloc {
    delete (__CGColorSpace*)self;
}
#pragma clang diagnostic pop
@end

__CGColorSpace::__CGColorSpace(CGColorSpaceModel model) {
    object_setClass((id)this, [CGNSColorSpace class]);

    colorSpaceModel = model;
    palette = NULL;
    lastColor = 0;
}

__CGColorSpace::~__CGColorSpace() {
    if (palette) {
        IwFree(palette);
        palette = NULL;
    }
}

/**
 @Status Stub
*/
CGColorSpaceRef CGColorSpaceCreateCalibratedRGB(const CGFloat whitePoint[3],
                                                const CGFloat blackPoint[3],
                                                const CGFloat gamma[3],
                                                const CGFloat matrix[9]) {
    UNIMPLEMENTED();
    TraceWarning(TAG, L"CGColorSpaceCreateCalibratedRGB not supported");
    return (CGColorSpaceRef) new __CGColorSpace(kCGColorSpaceModelRGB);
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreateIndexed(CGColorSpaceRef baseSpace, size_t lastIndex, const unsigned char* colorTable) {
    __CGColorSpace* ret = new __CGColorSpace(kCGColorSpaceModelIndexed);

    ret->palette = (char*)IwMalloc(3 * (lastIndex + 1));
    memcpy(ret->palette, colorTable, 3 * (lastIndex + 1));
    ret->lastColor = lastIndex;
    return (CGColorSpaceRef)ret;
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreateDeviceRGB() {
    return (CGColorSpaceRef) new __CGColorSpace(kCGColorSpaceModelRGB);
}

/**
 @Status Stub
 @Notes Always returns RGB colorspace
*/
CGColorSpaceRef CGColorSpaceCreatePattern(CGColorSpaceRef source) {
    UNIMPLEMENTED();
    return (CGColorSpaceRef) new __CGColorSpace(kCGColorSpaceModelRGB);
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreateDeviceGray() {
    return (CGColorSpaceRef) new __CGColorSpace(kCGColorSpaceModelMonochrome);
}

/**
 @Status Caveat
 @Notes Only GenericRGB, GenericRGBLinear and GenericGray supported
*/
CGColorSpaceRef CGColorSpaceCreateWithName(CFStringRef name) {
    const char* strName = static_cast<const char*>([(__bridge NSString*)name UTF8String]);

    if (strcmp(strName, "kCGColorSpaceGenericRGB") == 0) {
        return (CGColorSpaceRef) new __CGColorSpace(kCGColorSpaceModelRGB);
    } else if (strcmp(strName, "kCGColorSpaceGenericRGBLinear") == 0) {
        return (CGColorSpaceRef) new __CGColorSpace(kCGColorSpaceModelRGB);
    } else if (strcmp(strName, "kCGColorSpaceGenericGray") == 0) {
        return (CGColorSpaceRef) new __CGColorSpace(kCGColorSpaceModelMonochrome);
    } else {
        UNIMPLEMENTED_WITH_MSG("Colorspace Unsupported: %s", strName);
        return (CGColorSpaceRef) new __CGColorSpace(kCGColorSpaceModelRGB);
    }

    return NULL;
}

/**
@Status Interoperable
*/
CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef colorSpace) {
    if (colorSpace) {
        return ((__CGColorSpace*)colorSpace)->colorSpaceModel;
    } else {
        return kCGColorSpaceModelRGB;
    }
}

/**
@Status Caveat
@Notes Doesn't support all colorSpaces
*/
size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef pSpace) {
    const CGColorSpaceModel colorSpaceModel = ((__CGColorSpace*)pSpace)->colorSpaceModel;

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
    CFRelease((id)colorSpace);
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef colorSpace) {
    CFRetain((id)colorSpace);

    return colorSpace;
}

/**
 @Status Caveat
 @Notes Limited constants supported
*/
CGColorRef CGColorGetConstantColor(CFStringRef name) {
    UIColor* ret;

    char* pName = (char*)[(NSString*)name UTF8String];
    if (strcmp(pName, "BLACK") == 0) {
        ret = [_LazyUIColor2 blackColor];
    } else if (strcmp(pName, "WHITE") == 0) {
        ret = [_LazyUIColor2 whiteColor];
    } else {
        assert(0);
    }

    return (CGColorRef)[ret retain];
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
 @Status Stub
 @Notes
*/
CGColorSpaceRef CGColorSpaceGetBaseColorSpace(CGColorSpaceRef space) {
    UNIMPLEMENTED();
    return StubReturn();
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
CFTypeID CGColorSpaceGetTypeID() {
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
