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

#import "CGContextInternal.h"
#import "CGColorSpaceInternal.h"
#import "_CGLifetimeBridgingType.h"

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
- (void)dealloc {
    delete (__CGColorSpace*)self;
}
@end

__CGColorSpace::__CGColorSpace(surfaceFormat fmt) {
    object_setClass((id) this, [CGNSColorSpace class]);

    colorSpace = fmt;
    palette = NULL;
    lastColor = 0;
}

__CGColorSpace::~__CGColorSpace() {
    if (palette) {
        delete palette;
        palette = NULL;
    }
}

CGColorSpaceRef CGColorSpaceCreateCalibratedRGB() {
    EbrDebugLog("CGColorSpaceCreateCalibratedRGB not supported\n");
    return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
}

CGColorSpaceRef CGColorSpaceCreateIndexed(id baseSpace, int lastIndex, void* colorTable) {
    __CGColorSpace* ret = new __CGColorSpace(_ColorIndexed);

    ret->palette = (char*)malloc(3 * (lastIndex + 1));
    memcpy(ret->palette, colorTable, 3 * (lastIndex + 1));
    ret->lastColor = lastIndex;
    return (CGColorSpaceRef)ret;
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreateDeviceRGB() {
    return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
}

/**
 @Status Stub
 @Notes Always returns RGBA colorspace
*/
CGColorSpaceRef CGColorSpaceCreatePattern(CGColorSpaceRef source) {
    UNIMPLEMENTED();
    return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
}

/**
 @Status Stub
 @Notes Always returns RGB colorspace
*/
CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef colorSpace) {
    UNIMPLEMENTED();
    EbrDebugLog("CGColorSpaceGetModel not implemented\n");
    return kCGColorSpaceModelRGB;
}

/**
 @Status Caveat
 @Notes Doesn't support all bitmap formats
*/
size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef pSpace) {
    switch (((__CGColorSpace*)pSpace)->colorSpace) {
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

/**
 @Status Interoperable
*/
CGColorSpaceRef CGColorSpaceCreateDeviceGray() {
    return (CGColorSpaceRef) new __CGColorSpace(_ColorGrayscale);
}

CGColorSpaceRef CGColorSpaceCreateWithName(id name) {
    char* strName = (char*)[name UTF8String];

    if (strcmp(strName, "kCGColorSpaceGenericRGB") == 0) {
        return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
    } else if (strcmp(strName, "kCGColorSpaceGenericRGBLinear") == 0) {
        return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
    } else {
        assert(0);
    }

    return NULL;
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

    char* pName = (char*)[name UTF8String];
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