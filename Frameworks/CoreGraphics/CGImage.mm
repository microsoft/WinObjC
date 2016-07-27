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
#import <math.h>
#import <vector>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/NSData.h>
#import <UIKit/UIImage.h>
#import "CGColorSpaceInternal.h"
#import "CGImageInternal.h"
#import "_CGLifetimeBridgingType.h"
#import "CGSurfaceInfoInternal.h"

extern "C" {
#import <png.h>
};

// This is the format libpng expects.
struct _RGBA_swizzle {
    BYTE r, g, b, a;
};

// This is what comes out of pixman.
struct _BGRA_swizzle {
    BYTE b, g, r, a;
};

#include "LoggingNative.h"

static const wchar_t* TAG = L"CGImage";

@interface CGNSImage : _CGLifetimeBridgingType
@end
@implementation CGNSImage
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (void)dealloc {
#pragma diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
    // __CGImage is a C++ class massaged into an objc object.
    delete (__CGImage*)self;
#pragma diagnostic pop
}
@end

static IWLazyClassLookup _LazyUIImage("UIImage");

int numCGImages = 0;

__CGImage::__CGImage() {
    numCGImages++;

    _has32BitAlpha = true;

#ifdef DEBUG_IMG_COUNT
    TraceVerbose(TAG, L"Number of CGImages: %d created=%x", numCGImages, this);
#endif

    object_setClass((id)this, [CGNSImage class]);
}

static std::vector<CGImageDestructionListener> _imageDestructionListeners;
COREGRAPHICS_EXPORT void CGImageAddDestructionListener(CGImageDestructionListener listener) {
    _imageDestructionListeners.push_back(listener);
}

__CGImage::~__CGImage() {
    numCGImages--;
#ifdef DEBUG_IMG_COUNT
    TraceVerbose(TAG, L"destroyed=%x from=%x", this, _ReturnAddress());
#endif
    for (CGImageDestructionListener& curListener : _imageDestructionListeners) {
        curListener(this);
    }

    if (_img) {
        delete _img;
    }
    _provider = nil;
}

CGImageBacking* __CGImage::DetachBacking(CGImageRef newParent) {
    CGImageBacking* ret = _img;

    _img->_parent = newParent;
    _img = NULL;

    return ret;
}

//  Default implementation does a deep copy
CGImageRef CGImageBacking::CopyOnWrite() {
    CGImageRef ret;

    ret = new CGBitmapImage(_parent);

    return ret;
}

/**
 @Status Caveat
 @Notes decode parameter not supported and must be nullptr.
*/
CGImageRef CGImageCreateWithJPEGDataProvider(CGDataProviderRef source,
                                             const CGFloat decode[],
                                             bool shouldInterpolate,
                                             CGColorRenderingIntent intent) {
    FAIL_FAST_IF_FALSE(decode == nullptr);
    FAIL_FAST_HR_IF_FALSE_MSG(E_INVALIDARG,
                              ((source == nullptr) || [(NSObject*)source isKindOfClass:[NSData class]]),
                              "CGDataProviderRef does not derive from NSData!");

    id img = [[_LazyUIImage alloc] initWithData:(NSData*)source];
    return (CGImageRef)[img CGImage];
}

/**
 @Status Caveat
 @Notes decode parameter not supported and must be nullptr.
*/
CGImageRef CGImageCreateWithPNGDataProvider(CGDataProviderRef source,
                                            const CGFloat decode[],
                                            bool shouldInterpolate,
                                            CGColorRenderingIntent intent) {
    FAIL_FAST_IF_FALSE(decode == nullptr);
    FAIL_FAST_HR_IF_FALSE_MSG(E_INVALIDARG,
                              ((source == nullptr) || [(NSObject*)source isKindOfClass:[NSData class]]),
                              "CGDataProviderRef does not derive from NSData!");

    id img = [[_LazyUIImage alloc] initWithData:(NSData*)source];

    return (CGImageRef)[img CGImage];
}

/**
 @Status Caveat
 @Notes Doesn't support copy-on-write semantics - returns an unlinked copy of the source
        image cropped to the specified rectangle.
*/
CGImageRef CGImageCreateWithImageInRect(CGImageRef ref, CGRect rect) {
    if (ref == NULL) {
        TraceWarning(TAG, L"CGImageCreateWithImageInRect: ref = NULL!");
        return 0;
    }

    rect = CGRectIntegral(rect);

    CGRect imgRefSize;
    imgRefSize.origin.x = 0;
    imgRefSize.origin.y = 0;
    imgRefSize.size.width = (float)ref->Backing()->Width();
    imgRefSize.size.height = (float)ref->Backing()->Height();

    rect = CGRectIntersection(rect, imgRefSize);

    __CGSurfaceInfo surfaceInfo;
    ref->Backing()->GetSurfaceInfoWithoutPixelPtr(&surfaceInfo);

    // Override width and height with the rect
    surfaceInfo.width = rect.size.width;
    surfaceInfo.height = rect.size.height;

    assert(surfaceInfo.surfaceData == NULL);

    CGImageRef newImage = new CGBitmapImage(surfaceInfo);

    int startX = (int)rect.origin.x;
    int startY = (int)rect.origin.y;
    int sizeX = (int)rect.size.width;
    int sizeY = (int)rect.size.height;

    BYTE* srcIn =
        ((BYTE*)ref->Backing()->LockImageData()) + startY * ref->Backing()->BytesPerRow() + startX * ref->Backing()->BytesPerPixel();
    BYTE* destOut = (BYTE*)newImage->Backing()->LockImageData();

    for (int curY = 0; curY < sizeY; curY++) {
        memmove(destOut, srcIn, newImage->Backing()->BytesPerRow());

        srcIn += ref->Backing()->BytesPerRow();
        destOut += newImage->Backing()->BytesPerRow();
    }

    ref->Backing()->ReleaseImageData();
    newImage->Backing()->ReleaseImageData();

    return (CGImageRef)newImage;
}

/**
 @Status Interoperable
 @Notes Doesn't support copy-on-write semantics - returns an unlinked copy of the source
        image.
*/
CGImageRef CGImageCreateCopy(CGImageRef ref) {
    if (!ref)
        return nullptr;

    __CGSurfaceInfo surfaceInfo;
    ref->Backing()->GetSurfaceInfoWithoutPixelPtr(&surfaceInfo);

    assert(surfaceInfo.surfaceData == NULL);

    CGImageRef newImage = new CGBitmapImage(surfaceInfo);

    int startX = 0;
    int startY = 0;
    int sizeX = ref->Backing()->Width();
    int sizeY = ref->Backing()->Height();

    if (startY < 0) {
        startY = 0;
    }

    BYTE* srcIn =
        ((BYTE*)ref->Backing()->LockImageData()) + startY * ref->Backing()->BytesPerRow() + startX * ref->Backing()->BytesPerPixel();
    BYTE* destOut = (BYTE*)newImage->Backing()->LockImageData();

    for (int curY = 0; curY < sizeY; curY++) {
        memcpy(destOut, srcIn, newImage->Backing()->BytesPerRow());

        srcIn += ref->Backing()->BytesPerRow();
        destOut += newImage->Backing()->BytesPerRow();
    }

    ref->Backing()->ReleaseImageData();
    newImage->Backing()->ReleaseImageData();

    return (CGImageRef)newImage;
}

/**
 @Status Caveat
 @Notes No actual conversion between colorspaces, simply copies and reinterprets data in new colorspace
*/
CGImageRef CGImageCreateCopyWithColorSpace(CGImageRef ref, CGColorSpaceRef colorSpace) {
    __CGSurfaceInfo surfaceInfo;
    ref->Backing()->GetSurfaceInfoWithoutPixelPtr(&surfaceInfo);

    // Override colorSpaceModel
    surfaceInfo.colorSpaceModel = ((__CGColorSpace*)colorSpace)->colorSpaceModel;

    assert(surfaceInfo.surfaceData == NULL);

    CGImageRef newImage = new CGBitmapImage(surfaceInfo);

    int startX = 0;
    int startY = 0;
    int sizeX = ref->Backing()->Width();
    int sizeY = ref->Backing()->Height();

    if (startY < 0) {
        startY = 0;
    }

    BYTE* srcIn =
        ((BYTE*)ref->Backing()->LockImageData()) + startY * ref->Backing()->BytesPerRow() + startX * ref->Backing()->BytesPerPixel();
    BYTE* destOut = (BYTE*)newImage->Backing()->LockImageData();

    for (int curY = 0; curY < sizeY; curY++) {
        memcpy(destOut, srcIn, newImage->Backing()->BytesPerRow());

        srcIn += ref->Backing()->BytesPerRow();
        destOut += newImage->Backing()->BytesPerRow();
    }

    ref->Backing()->ReleaseImageData();
    newImage->Backing()->ReleaseImageData();

    return (CGImageRef)newImage;
}

/**
 @Status Caveat
 @Notes Source image must be RGBA32.
*/
CGImageRef CGImageCreateWithMask(CGImageRef image, CGImageRef mask) {
    CGImageRef newImage;

    {
        const DWORD bytesPerRow = image->Backing()->Width() * 4;
        DWORD* newImageData = (DWORD*)IwMalloc(bytesPerRow * image->Backing()->Height());
        DWORD* src = (DWORD*)image->Backing()->LockImageData();
        BYTE* maskData = (BYTE*)mask->Backing()->LockImageData();
        DWORD incX = ((mask->Backing()->Width()) << 16) / image->Backing()->Width();
        DWORD incY = ((mask->Backing()->Height()) << 16) / image->Backing()->Height();

        __CGSurfaceInfo surfaceInfo =
            _CGSurfaceInfoInit(image->Backing()->Width(), image->Backing()->Height(), _ColorABGR, newImageData, bytesPerRow);

        newImage = new CGBitmapImage(surfaceInfo);
        newImage->Backing()->SetFreeWhenDone(TRUE);

        int imgWidth = image->Backing()->Width();

        for (int i = 0; i < image->Backing()->Height(); i++) {
            BYTE* srcMask = ((BYTE*)maskData) + ((i * incY) >> 16) * mask->Backing()->BytesPerRow();
            DWORD* srcRow = (DWORD*)(((BYTE*)src) + (i * image->Backing()->BytesPerRow()));
            DWORD srcMaskX = 0;
            DWORD maskFmt = mask->Backing()->SurfaceFormat();

            for (int j = 0; j < imgWidth; j++) {
                DWORD srcPixel = *srcRow;
                DWORD r = srcPixel & 0xFF;
                DWORD g = (srcPixel >> 8) & 0xFF;
                DWORD b = (srcPixel >> 16) & 0xFF;
                DWORD a = (srcPixel >> 24) & 0xFF;
                DWORD maskRA = 255, maskGA = 255, maskBA = 255, maskAA = 255;

                switch (maskFmt) {
                    case _ColorA8:
                    case _ColorGrayscale:
                        maskAA = maskRA = maskGA = maskBA = srcMask[srcMaskX >> 16];
                        break;

                    case _ColorABGR:
                        maskRA = srcMask[(srcMaskX >> 16) * 4];
                        maskGA = srcMask[(srcMaskX >> 16) * 4 + 1];
                        maskBA = srcMask[(srcMaskX >> 16) * 4 + 2];
                        maskAA = (maskRA + maskGA + maskBA) / 3;
                        break;

                    case _ColorBGR:
                        maskRA = srcMask[(srcMaskX >> 16) * 3];
                        maskGA = srcMask[(srcMaskX >> 16) * 3 + 1];
                        maskBA = srcMask[(srcMaskX >> 16) * 3 + 2];
                        maskAA = (maskRA + maskGA + maskBA) / 3;
                        break;

                    case _ColorARGB:
                        maskBA = srcMask[(srcMaskX >> 16) * 4];
                        maskGA = srcMask[(srcMaskX >> 16) * 4 + 1];
                        maskRA = srcMask[(srcMaskX >> 16) * 4 + 2];
                        maskAA = (maskRA + maskGA + maskBA) / 3;
                        break;
                }

                r *= maskAA;
                r /= 255;
                g *= maskAA;
                g /= 255;
                b *= maskAA;
                b /= 255;
                a *= maskAA;
                a /= 255;

                *newImageData = r | (g << 8) | (b << 16) | (a << 24);

                newImageData++;
                srcRow++;
                srcMaskX += incX;
            }
        }

        image->Backing()->ReleaseImageData();
        mask->Backing()->ReleaseImageData();
    }

    return (CGImageRef)newImage;
}

/**
 @Status Caveat
 @Notes Only 32bpp RGBA source format supported. Returns an 8bpp grayscale alpha mask one-time
        copy of source bitmap.
*/
CGImageRef CGImageMaskCreate(size_t width,
                             size_t height,
                             size_t bitsPerComponent,
                             size_t bitsPerPixel,
                             size_t bytesPerRow,
                             CGDataProviderRef provider,
                             const CGFloat* decode,
                             bool shouldInterpolate) {
    FAIL_FAST_HR_IF_FALSE(E_UNEXPECTED, ((bitsPerComponent == 8) && (bitsPerPixel == 32)));
    FAIL_FAST_HR_IF_FALSE_MSG(E_INVALIDARG,
                              ((provider == nullptr) || [(NSObject*)provider isKindOfClass:[NSData class]]),
                              "CGDataProviderRef does not derive from NSData!");

    NSData* dataProvider = (__bridge NSData*)provider;
    char* pData = (char*)[dataProvider bytes];
    size_t dataLen = (size_t)[dataProvider length];

    //  Create an 8-bit mask from the data
    __CGSurfaceInfo surfaceInfo = _CGSurfaceInfoInit(width, height, _ColorGrayscale);

    CGImageRef newImage = new CGBitmapImage(surfaceInfo);
    char* pNewImage = (char*)newImage->Backing()->LockImageData();

    int pixOut = 0;
    int outImageBytesPerRow = newImage->Backing()->BytesPerRow();

    for (unsigned y = 0; y < height; y++) {
        char* rowIn = &pData[y * bytesPerRow];
        char* rowOut = &pNewImage[pixOut];

        for (unsigned x = 0; x < width; x++) {
            BYTE r = *rowIn++;
            BYTE g = *rowIn++;
            BYTE b = *rowIn++;
            BYTE a = *rowIn++;

            BYTE alphaOut = (r + g + b) * a / 255 / 3;
            *rowOut++ = 255 - alphaOut;
        }

        pixOut += outImageBytesPerRow;
    }

    newImage->Backing()->ReleaseImageData();

    return (CGImageRef)newImage;
}

/**
 @Status Interoperable
*/
CGImageAlphaInfo CGImageGetAlphaInfo(CGImageRef img) {
    int32_t ret;

    if (img) {
        ret = img->Backing()->BitmapInfo() & kCGBitmapAlphaInfoMask;
    } else {
        TraceWarning(TAG, L"CGImageGetAlphaInfo: Null CGImageRef!");
        ret = 0;
    }

    return (CGImageAlphaInfo)ret;
}

@interface CGImageDataProvider : NSData {
@public
    CGImageRef _img;
}

- (instancetype)init;
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
- (const void*)bytes;
- (NSUInteger)length;

@end

// TODO: Task 7188763 This class makes no sense to be derived from NSData as it exposes a public _img field
// and apparently does all operations via that rather than actually acting like an NSData.
// To make it work, just add in the appropriate NSData methods using an inner NSData to hold anything
// with the assumption it is not used.
@implementation CGImageDataProvider {
@private
    StrongId<NSData> _data;
}
- (void)dealloc {
    _img->Backing()->ReleaseImageData();
    [super dealloc];
}

- (instancetype)init {
    return [self initWithBytes:"" length:0];
}

- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    if (self = [super init]) {
        _data.attach([[NSData alloc] initWithBytesNoCopy:bytes length:length freeWhenDone:freeWhenDone]);
    }
    return self;
}

- (const void*)bytes {
    return [_data bytes];
}

- (NSUInteger)length {
    return [_data length];
}

@end

/**
 @Status Interoperable
*/
CGDataProviderRef CGImageGetDataProvider(CGImageRef img) {
    char* pPtr = (char*)img->Backing()->LockImageData();
    CGImageDataProvider* ret = [[CGImageDataProvider alloc] initWithBytesNoCopy:pPtr
                                                                         length:img->Backing()->Height() * img->Backing()->BytesPerRow()
                                                                   freeWhenDone:FALSE];
    ret->_img = img;

    return ret;
}

void* _CGImageGetData(CGImageRef img) {
    return img->Backing()->StaticImageData();
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGImageGetColorSpace(CGImageRef img) {
    // TODO: Consider caching colorspaceRef in CGImageRef
    CGColorSpaceRef ret = (CGColorSpaceRef) new __CGColorSpace(img->Backing()->ColorSpaceModel());

    return ret;
}

/**
 @Status Interoperable
*/
size_t CGImageGetBitsPerPixel(CGImageRef img) {
    if (!img) {
        TraceWarning(TAG, L"CGImageGetBitsPerPixel: nil!");
        return 0;
    }

    return (img->Backing()->BytesPerPixel() << 3);
}

/**
 @Status Interoperable
*/
size_t CGImageGetBitsPerComponent(CGImageRef img) {
    if (!img) {
        TraceWarning(TAG, L"CGImageGetBitsPerComponent: nil!");
        return 0;
    }

    return (img->Backing()->BitsPerComponent());
}

/**
 @Status Interoperable
*/
size_t CGImageGetWidth(CGImageRef img) {
    if (!img)
        return 0;

    return img->Backing()->Width();
}

/**
 @Status Interoperable
*/
size_t CGImageGetHeight(CGImageRef img) {
    if (!img)
        return 0;

    return img->Backing()->Height();
}

/**
 @Status Interoperable
*/
void CGImageRelease(CGImageRef img) {
    CFRelease((id)img);
}

/**
 @Status Interoperable
*/
CGImageRef CGImageRetain(CGImageRef img) {
    CFRetain((id)img);
    return img;
}

/**
 @Status Interoperable
*/
CGBitmapInfo CGImageGetBitmapInfo(CGImageRef img) {
    int ret;

    if (img) {
        ret = img->Backing()->BitmapInfo();
    } else {
        TraceWarning(TAG, L"CGImageGetBitmapInfo: Null CGImageRef!");
        ret = 0;
    }

    return ret;
}

/**
 @Status Interoperable
*/
size_t CGImageGetBytesPerRow(CGImageRef img) {
    if (!img)
        return 0;

    DWORD ret = 0;

    switch (img->Backing()->SurfaceFormat()) {
        case _ColorARGB:
        case _ColorABGR:
        case _ColorBGRX:
            ret = img->Backing()->BytesPerRow();
            break;

        default:
            FAIL_FAST();
            break;
    }
    return ret;
}

/**
 @Status Caveat
 @Notes Limited bitmap formats available. Decode, shouldInterpolate, intent parameters
        and some byte orders ignored.
*/
CGImageRef CGImageCreate(size_t width,
                         size_t height,
                         size_t bitsPerComponent,
                         size_t bitsPerPixel,
                         size_t bytesPerRow,
                         CGColorSpaceRef colorSpace,
                         CGBitmapInfo bitmapInfo,
                         CGDataProviderRef provider,
                         const float* decode,
                         bool shouldInterpolate,
                         CGColorRenderingIntent intent) {
    CGBitmapImage* newImage;
    FAIL_FAST_HR_IF_FALSE_MSG(E_INVALIDARG,
                              ((provider == nullptr) || [(NSObject*)provider isKindOfClass:[NSData class]]),
                              "CGDataProviderRef does not derive from NSData!");
    NSData* dataProvider = (__bridge NSData*)provider;

    char* data = (char*)[dataProvider bytes];

    bool colorSpaceAllocated = false;

    if (colorSpace == NULL) {
        if (bytesPerRow >= (width * 3)) {
            TraceWarning(TAG, L"Warning: colorSpace = NULL, assuming RGB based on bytesPerRow.");
            colorSpace = CGColorSpaceCreateDeviceRGB();
        } else {
            TraceWarning(TAG, L"Warning: colorSpace = NULL, assuming Gray based on bytesPerRow.");
            colorSpace = CGColorSpaceCreateDeviceGray();
        }

        colorSpaceAllocated = true;
    }

    __CGSurfaceFormat format = _CGImageGetFormat(bitsPerComponent, bitsPerPixel, colorSpace, bitmapInfo);

    if (format != _ColorIndexed) {
        __CGSurfaceInfo surfaceInfo = __CGSurfaceInfo(((__CGColorSpace*)colorSpace)->colorSpaceModel,
                                                      bitmapInfo,
                                                      bitsPerComponent,
                                                      bitsPerPixel >> 3,
                                                      width,
                                                      height,
                                                      bytesPerRow,
                                                      data,
                                                      format);

        newImage = new CGBitmapImage(surfaceInfo);
    } else {
        __CGSurfaceInfo surfaceInfo = _CGSurfaceInfoInit(width, height, _ColorBGR);

        newImage = new CGBitmapImage(surfaceInfo);
        void* pData = newImage->Backing()->LockImageData();
        int stride = newImage->Backing()->BytesPerRow();

        char* curPosOut = (char*)pData;
        char* curPosIn = (char*)data;
        for (unsigned y = 0; y < height; y++) {
            char* curLineOut = curPosOut;
            char* curLineIn = curPosIn;
            for (unsigned x = 0; x < width; x++) {
                BYTE c = *curLineIn;

                if (c <= ((__CGColorSpace*)colorSpace)->lastColor) {
                    BYTE* palette = (BYTE*)&((__CGColorSpace*)colorSpace)->palette[c * 3];
                    *(curLineOut++) = *(palette++);
                    *(curLineOut++) = *(palette++);
                    *(curLineOut++) = *(palette++);
                } else {
                    *(curLineOut++) = 0;
                    *(curLineOut++) = 0;
                    *(curLineOut++) = 0;
                }
                curLineIn++;
            }

            curPosOut += stride;
            curPosIn += width;
        }

        newImage->Backing()->ReleaseImageData();
    }

    newImage->_provider = dataProvider;

    if (colorSpaceAllocated == true) {
        CGColorSpaceRelease(colorSpace);
    }

    return (CGImageRef)newImage;
}

static void PNGWriteFunc(png_structp png_ptr, png_bytep data, png_size_t length) {
    id dataOut = (id)png_get_io_ptr(png_ptr);

    [dataOut appendBytes:data length:length];
}

NSData* _CGImagePNGRepresentation(UIImage* img) {
    if (img == nil) {
        TraceWarning(TAG, L"UIImagePNGRepresentation: img = nil!");
        return nil;
    }

    CGImageRef pImage = (CGImageRef)[img CGImage];
    if (pImage == NULL) {
        TraceWarning(TAG, L"No image passed to UIImagePNGRepresentation");
        return nil;
    }
    NSMutableData* ret = [NSMutableData data];

    if (pImage == NULL || pImage->Backing()->Width() == 0 || pImage->Backing()->Height() == 0) {
        TraceVerbose(TAG, L"%x", pImage);
        FAIL_FAST_HR(E_UNEXPECTED);
    }

    png_structp png_ptr;
    png_infop info_ptr;

    // Initialize write structure
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    // Initialize info structure
    info_ptr = png_create_info_struct(png_ptr);

    if (setjmp(png_jmpbuf(png_ptr))) {
        TraceError(TAG, L"Error during png creation");
        return nil;
    }

    png_set_write_fn(png_ptr, (void*)ret, PNGWriteFunc, NULL);

    int width = pImage->Backing()->Width();
    int height = pImage->Backing()->Height();
    int xStrideImg = pImage->Backing()->BytesPerPixel();
    int yStrideImg = pImage->Backing()->BytesPerRow();
    BYTE* pImgData = (BYTE*)pImage->Backing()->LockImageData();

    int orientation = [img imageOrientation];
    switch (orientation) {
        case UIImageOrientationDown:
            pImgData += yStrideImg * (height - 1);
            yStrideImg = -yStrideImg;
            break;
        case UIImageOrientationRight: {
            pImgData += xStrideImg * (width - 1);

            int tmp = yStrideImg;
            yStrideImg = -xStrideImg;
            xStrideImg = tmp;

            tmp = width;
            width = height;
            height = tmp;
        } break;
        case UIImageOrientationLeft: {
            pImgData += yStrideImg * (height - 1);

            int tmp = yStrideImg;
            yStrideImg = xStrideImg;
            xStrideImg = -tmp;

            tmp = width;
            width = height;
            height = tmp;
        } break;

        case UIImageOrientationUp:
            break;

        default:
            TraceWarning(TAG, L"Unknown image orientation %d", orientation);
            break;
    }

    int xStrideOut;
    int yStrideOut;
    __CGSurfaceFormat backingFormat = pImage->Backing()->SurfaceFormat();

    // Write header (8 bit colour depth)
    switch (backingFormat) {
        case _Color565:
        case _ColorBGR:
            png_set_IHDR(png_ptr,
                         info_ptr,
                         width,
                         height,
                         8,
                         PNG_COLOR_TYPE_RGB,
                         PNG_INTERLACE_NONE,
                         PNG_COMPRESSION_TYPE_BASE,
                         PNG_FILTER_TYPE_BASE);
            xStrideOut = 3;
            break;

        case _ColorGrayscale:
        case _ColorA8:
            png_set_IHDR(png_ptr,
                         info_ptr,
                         width,
                         height,
                         8,
                         PNG_COLOR_TYPE_GRAY,
                         PNG_INTERLACE_NONE,
                         PNG_COMPRESSION_TYPE_BASE,
                         PNG_FILTER_TYPE_BASE);
            xStrideOut = 1;
            break;

        case _ColorARGB:
        case _ColorABGR:
        case _ColorBGRX:
        case _ColorXBGR:
            png_set_IHDR(png_ptr,
                         info_ptr,
                         width,
                         height,
                         8,
                         PNG_COLOR_TYPE_RGB_ALPHA,
                         PNG_INTERLACE_NONE,
                         PNG_COMPRESSION_TYPE_BASE,
                         PNG_FILTER_TYPE_BASE);
            xStrideOut = 4;
            break;

        default:
            // Any other backing formats are outside the scope of libpng, and extremely unlikely to be used.
            FAIL_FAST_HR_MSG(E_UNEXPECTED, "Unsupported backing format!");
            break;
    }

    yStrideOut = xStrideOut * width;

    png_write_info(png_ptr, info_ptr);

    int x, y;
    int bytesperpixel = pImage->Backing()->BytesPerPixel();
    BYTE* pRow = static_cast<BYTE*>(IwMalloc(yStrideOut));
    FAIL_FAST_HR_IF_NULL(E_OUTOFMEMORY, pRow);
    for (y = 0; y < height; y++) {
        BYTE* rowStart = pImgData;
        BYTE* rowOut = pRow;

        for (x = 0; x < width; x++) {
            BYTE* pixel = rowStart;
            _RGBA_swizzle* outSwizzle = reinterpret_cast<_RGBA_swizzle*>(rowOut);
            _BGRA_swizzle* pixelSwizzle = reinterpret_cast<_BGRA_swizzle*>(pixel);
            switch (backingFormat) {
                // PIXMAN_g8 | PIXMAN_a8
                case _ColorGrayscale:
                case _ColorA8:
                    *rowOut = *pixel;
                    break;

                // PIXMAN_b8g8r8
                case _ColorBGR: {
                    outSwizzle->r = pixelSwizzle->b;
                    outSwizzle->g = pixelSwizzle->g;
                    outSwizzle->b = pixelSwizzle->r;
                } break;

                // PIXMAN_r5g6b5
                case _Color565: {
                    unsigned short shortPixel = *reinterpret_cast<unsigned short*>(pixel);

                    // Mask out the RGB portions
                    outSwizzle->r = (BYTE)(shortPixel >> 11);
                    outSwizzle->g = (BYTE)((shortPixel >> 5) & 0x3F);
                    outSwizzle->b = (BYTE)(shortPixel & 0x1F);

                    // Scale component to BYTE with LSB extension. (00011b << 3 becomes 11111b, 00010b becomes 10000b)
                    outSwizzle->r = (outSwizzle->r << 3) | (((outSwizzle->r & 0x1) << 3) - (outSwizzle->r & 0x1));
                    outSwizzle->g = (outSwizzle->g << 2) | (((outSwizzle->g & 0x1) << 2) - (outSwizzle->g & 0x1));
                    outSwizzle->b = (outSwizzle->b << 3) | (((outSwizzle->b & 0x1) << 3) - (outSwizzle->b & 0x1));
                } break;

                // PIXMAN_a8r8g8b8
                case _ColorARGB: {
                    outSwizzle->r = pixelSwizzle->r;
                    outSwizzle->g = pixelSwizzle->g;
                    outSwizzle->b = pixelSwizzle->b;
                    outSwizzle->a = pixelSwizzle->a;
                } break;

                // PIXMAN_x8b8g8r8 | PIXMAN_a8b8g8r8
                case _ColorXBGR:
                case _ColorABGR: {
                    outSwizzle->r = pixelSwizzle->b;
                    outSwizzle->g = pixelSwizzle->g;
                    outSwizzle->b = pixelSwizzle->r;
                    outSwizzle->a = pixelSwizzle->a;
                } break;

                // PIXMAN_b8g8r8x8
                case _ColorBGRX: {
                    outSwizzle->r = pixelSwizzle->b;
                    outSwizzle->g = pixelSwizzle->g;
                    outSwizzle->b = pixelSwizzle->r;
                    outSwizzle->a = pixelSwizzle->a;
                } break;

                default:
                    // Impossible state, we should have failed higher up.
                    FAIL_FAST_HR(E_UNEXPECTED);
                    break;
            }
            rowOut += xStrideOut;
            rowStart += xStrideImg;
        }
        pImgData += yStrideImg;
        png_write_row(png_ptr, pRow);
    }
    IwFree(pRow);
    pImage->Backing()->ReleaseImageData();

    png_write_end(png_ptr, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);

    return ret;
}

@interface _UIImageWriterCallback : NSObject
- (void)image:(UIImage*)image didFinishSavingWithError:(NSError*)err contextInfo:(void*)contextInfo;
@end

/**
 @Status Stub
 @Notes
*/
const CGFloat* CGImageGetDecode(CGImageRef image) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGColorRenderingIntent CGImageGetRenderingIntent(CGImageRef image) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGImageGetShouldInterpolate(CGImageRef image) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGImageGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGImageIsMask(CGImageRef image) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGImageRef CGImageCreateWithMaskingColors(CGImageRef image, const CGFloat* components) {
    UNIMPLEMENTED();
    return StubReturn();
}