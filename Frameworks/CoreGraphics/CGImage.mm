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

#include "CGColorSpaceInternal.h"
#include "CGImageInternal.h"
#include "CoreGraphics/CGContext.h"
#include "CoreGraphics/CGGeometry.h"
#include "UIKit/UIImage.h"
#include "Foundation/NSData.h"

#include <math.h>
#include <vector>

extern "C" {
#include <png.h>
};

@interface CGNSImage : NSObject {
@public
}
@end

static IWLazyClassLookup _LazyUIImage("UIImage");

//#define DEBUG_IMG_COUNT

@implementation CGNSImage : NSObject
- (instancetype)copyWithZone:(NSZone*)zone {
    CFRetain(self);

    return self;
}

- (instancetype)retain {
    CFRetain(self);

    return self;
}

- (instancetype)release {
    CFRelease(self);

    return self;
}

- (void)dealloc {
    delete (__CGImage*)self;
}

@end

int numCGImages = 0;

__CGImage::__CGImage() {
    numCGImages++;

    _has32BitAlpha = true;

#ifdef DEBUG_IMG_COUNT
    EbrDebugLog("Number of CGImages: %d created=%x\n", numCGImages, this);
#endif

    isa = NULL;
    object_setClass((id) this, [CGNSImage class]);
}

static std::vector<CGImageDestructionListener> _imageDestructionListeners;
COREGRAPHICS_EXPORT void CGImageAddDestructionListener(CGImageDestructionListener listener) {
    _imageDestructionListeners.push_back(listener);
}

__CGImage::~__CGImage() {
    numCGImages--;
#ifdef DEBUG_IMG_COUNT
    EbrDebugLog("destroyed=%x from=%x\n", this, _ReturnAddress());
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
 @Status Stub
*/
const CGFloat* CGColorGetComponents(CGColorRef color) {
    UNIMPLEMENTED();
    float* ret = (float*)malloc(sizeof(float) * 4);

    [color getColors:ret];

    return ret;
}

/**
 @Status Stub
 @Notes Calls CGImageCreateWithPNGDataProvider
*/
CGImageRef CGImageCreateWithJPEGDataProvider(CGDataProviderRef source,
                                             const CGFloat decode[],
                                             bool shouldInterpolate,
                                             CGColorRenderingIntent intent) {
    UNIMPLEMENTED();
    assert(decode == NULL);

    id img = [[_LazyUIImage alloc] initWithData:(NSData*)source];
    return (CGImageRef)[img CGImage];
}

/**
 @Status Interoperable
*/
CGImageRef CGImageCreateWithPNGDataProvider(CGDataProviderRef source,
                                            const CGFloat decode[],
                                            bool shouldInterpolate,
                                            CGColorRenderingIntent intent) {
    assert(decode == NULL);

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
        EbrDebugLog("CGImageCreateWithImageInRect: ref = NULL!\n");
        return 0;
    }

    rect = CGRectIntegral(rect);

    CGRect imgRefSize;
    imgRefSize.origin.x = 0;
    imgRefSize.origin.y = 0;
    imgRefSize.size.width = (float)ref->Backing()->Width();
    imgRefSize.size.height = (float)ref->Backing()->Height();

    rect = CGRectIntersection(rect, imgRefSize);

    CGImageRef newImage = new CGBitmapImage((DWORD)rect.size.width, (DWORD)rect.size.height, ref->Backing()->SurfaceFormat());

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

    CGImageRef newImage = new CGBitmapImage(ref->Backing()->Width(), ref->Backing()->Height(), ref->Backing()->SurfaceFormat());

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
 @Notes colorSpace parameter ignored
*/
CGImageRef CGImageCreateCopyWithColorSpace(CGImageRef ref, CGColorSpaceRef colorSpace) {
    CGImageRef newImage = new CGBitmapImage(ref->Backing()->Width(), ref->Backing()->Height(), ref->Backing()->SurfaceFormat());

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
        TimingFunction f("CGImageCreateWithMask");
        DWORD* newImageData = (DWORD*)EbrMalloc(image->Backing()->Width() * image->Backing()->Height() * 4);
        DWORD* src = (DWORD*)image->Backing()->LockImageData();
        BYTE* maskData = (BYTE*)mask->Backing()->LockImageData();
        DWORD incX = ((mask->Backing()->Width()) << 16) / image->Backing()->Width();
        DWORD incY = ((mask->Backing()->Height()) << 16) / image->Backing()->Height();

        newImage = new CGBitmapImage(image->Backing()->Width(), image->Backing()->Height(), _ColorRGBA, newImageData);
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

                    case _ColorRGBA:
                        maskRA = srcMask[(srcMaskX >> 16) * 4];
                        maskGA = srcMask[(srcMaskX >> 16) * 4 + 1];
                        maskBA = srcMask[(srcMaskX >> 16) * 4 + 2];
                        maskAA = (maskRA + maskGA + maskBA) / 3;
                        break;

                    case _ColorRGB:
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
    assert(bitsPerComponent == 8 && bitsPerPixel == 32);

    char* pData = (char*)[provider bytes];
    size_t dataLen = (size_t)[provider length];

    //  Create an 8-bit mask from the data
    CGImageRef newImage = new CGBitmapImage(width, height, _ColorGrayscale, NULL);
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
 @Status Caveat
 @Notes Only returns kCGImageAlphaFirst or kCGImageAlphaLast
*/
CGImageAlphaInfo CGImageGetAlphaInfo(CGImageRef img) {
    if (!img) {
        EbrDebugLog("CGImageGetAlphaInfo: nil!\n");
        return (CGImageAlphaInfo)0;
    }

    uint32_t ret = 0;

    switch (img->Backing()->SurfaceFormat()) {
        case _ColorARGB:
            ret |= kCGImageAlphaLast;
            break;

        case _ColorRGBA:
            ret |= kCGImageAlphaFirst;
            break;
    }

    return (CGImageAlphaInfo)ret;
}

@interface CGImageDataProvider : NSData {
@public
    CGImageRef _img;
}
@end

@implementation CGImageDataProvider : NSData
- (void)dealloc {
    _img->Backing()->ReleaseImageData();
    [super dealloc];
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

/**
 @Status Interoperable
*/
CGColorSpaceRef CGImageGetColorSpace(CGImageRef img) {
    CGColorSpaceRef ret = (CGColorSpaceRef) new __CGColorSpace(img->Backing()->SurfaceFormat());

    return ret;
}

/**
 @Status Interoperable
*/
size_t CGImageGetBitsPerPixel(CGImageRef img) {
    if (!img) {
        EbrDebugLog("CGImageGetBitsPerPixel: nil!\n");
        return 0;
    }

    DWORD ret = 0;

    switch (img->Backing()->SurfaceFormat()) {
        case _ColorARGB:
            ret = 32;
            break;

        case _ColorRGBA:
        case _ColorRGB32:
            ret = 32;
            break;

        default:
            assert(0);
    }

    return ret;
}

/**
 @Status Interoperable
*/
size_t CGImageGetBitsPerComponent(CGImageRef img) {
    if (!img) {
        EbrDebugLog("CGImageGetBitsPerComponent: nil!\n");
        return 0;
    }

    DWORD ret = 0;

    switch (img->Backing()->SurfaceFormat()) {
        case _ColorARGB:
        case _ColorRGB32:
            ret = 8;
            break;

        case _ColorRGBA:
        case _ColorRGB:
            ret = 8;
            break;

        case _ColorGrayscale:
            ret = 8;
            break;

        default:
            assert(0);
    }

    return ret;
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
    // EbrDebugLog("Releasing %x\n", img);
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
 @Status Caveat
 @Notes Only returns kCGImageAlpha information
*/
CGBitmapInfo CGImageGetBitmapInfo(CGImageRef img) {
    if (!img)
        return (CGBitmapInfo)0;

    uint32_t ret = 0;

    switch (img->Backing()->SurfaceFormat()) {
        case _ColorARGB:
            ret = kCGImageAlphaLast;
            break;

        case _ColorRGBA:
            ret = kCGImageAlphaFirst;
            break;

        case _ColorRGB32:
            ret = kCGImageAlphaNoneSkipFirst;
            break;

        case _ColorRGB:
            ret = kCGImageAlphaNone;
            break;

        default:
            assert(0);
            break;
    }
    return (CGBitmapInfo)ret;
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
        case _ColorRGBA:
        case _ColorRGB32:
            ret = img->Backing()->BytesPerRow();
            break;

        default:
            assert(0);
            break;
    }
    return ret;
}

/**
 @Status Caveat
 @Notes Limited bitmap formats available. decode, shouldInterpolate and intent parameters
        ignored.
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
    DWORD alphaType = bitmapInfo & 0x1F;

    char* data = (char*)[provider bytes];

    if (((__CGColorSpace*)colorSpace)->colorSpace == _ColorRGBA) {
        switch (alphaType) {
            case kCGImageAlphaNoneSkipFirst:
                switch (bitsPerComponent) {
                    case 8:
                        newImage = new CGBitmapImage(width, height, _ColorRGB32, data);
                        break;

                    case 5:
                        newImage = new CGBitmapImage(width, height, _Color565, data);
                        break;
                }
                break;

            case kCGImageAlphaNoneSkipLast:
                newImage = new CGBitmapImage(width, height, _ColorRGB32HE, data);
                break;

            case kCGImageAlphaFirst:
            case kCGImageAlphaPremultipliedLast: //  [TODO: Make this true]
            case kCGImageAlphaPremultipliedFirst: //  [TODO: Make this true]
                newImage = new CGBitmapImage(width, height, _ColorRGBA, data);
                break;

            case kCGImageAlphaLast:
                newImage = new CGBitmapImage(width, height, _ColorRGBA, data);
                break;

            case kCGImageAlphaNone:
                if (bitsPerPixel == 32) {
                    newImage = new CGBitmapImage(width, height, _ColorRGBA, data);
                } else {
                    newImage = new CGBitmapImage(width, height, _ColorRGB, data);
                }
                break;

            default:
                assert(0);
                break;
        }
    } else if (((__CGColorSpace*)colorSpace)->colorSpace == _ColorIndexed) {
        newImage = new CGBitmapImage(width, height, _ColorRGB, NULL);
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
    } else {
        newImage = new CGBitmapImage(width, height, ((__CGColorSpace*)colorSpace)->colorSpace, data);
    }

    newImage->_provider = (id)provider;

    return (CGImageRef)newImage;
}

static void PNGWriteFunc(png_structp png_ptr, png_bytep data, png_size_t length) {
    id dataOut = (id)png_get_io_ptr(png_ptr);

    [dataOut appendBytes:data length:length];
}

NSData* UIImagePNGRepresentation(UIImage* img) {
    if (img == nil) {
        EbrDebugLog("UIImagePNGRepresentation: img = nil!\n");
        return nil;
    }

    CGImageRef pImage = (CGImageRef)[img CGImage];
    if (pImage == NULL) {
        EbrDebugLog("No image passed to UIImagePNGRepresentation\n");
        return nil;
    }
    NSMutableData* ret = [NSMutableData data];

    if (pImage == NULL || pImage->Backing()->Width() == 0 || pImage->Backing()->Height() == 0) {
        EbrDebugLog("%x\n", pImage);
        *((char*)0) = 0;
    }

    png_structp png_ptr;
    png_infop info_ptr;

    // Initialize write structure
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    // Initialize info structure
    info_ptr = png_create_info_struct(png_ptr);

    if (setjmp(png_jmpbuf(png_ptr))) {
        EbrDebugLog("Error during png creation\n");
        return nil;
    }

    png_set_write_fn(png_ptr, (void*)ret, PNGWriteFunc, NULL);

    int width = pImage->Backing()->Width();
    int height = pImage->Backing()->Height();
    int xstride = pImage->Backing()->BytesPerPixel();
    int ystride = pImage->Backing()->BytesPerRow();
    BYTE* pImgData = (BYTE*)pImage->Backing()->LockImageData();
    bool rotate = false;

    int orientation = [img imageOrientation];
    switch (orientation) {
        case UIImageOrientationDown:
            pImgData += ystride * (height - 1);
            ystride = -ystride;
            break;
        case UIImageOrientationRight: {
            pImgData += xstride * (width - 1);

            int tmp = ystride;
            ystride = -xstride;
            xstride = tmp;

            tmp = width;
            width = height;
            height = tmp;
            rotate = true;
        } break;
        case UIImageOrientationLeft: {
            pImgData += ystride * (height - 1);

            int tmp = ystride;
            ystride = xstride;
            xstride = -tmp;

            tmp = width;
            width = height;
            height = tmp;
            rotate = true;
        } break;

        case UIImageOrientationUp:
            break;

        default:
            EbrDebugLog("Unknown image orientation %d\n", orientation);
            break;
    }

    // Write header (8 bit colour depth)
    switch (pImage->Backing()->SurfaceFormat()) {
        case _ColorRGB:
            png_set_IHDR(png_ptr,
                         info_ptr,
                         width,
                         height,
                         8,
                         PNG_COLOR_TYPE_RGB,
                         PNG_INTERLACE_NONE,
                         PNG_COMPRESSION_TYPE_BASE,
                         PNG_FILTER_TYPE_BASE);
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
            break;

        default:
            png_set_IHDR(png_ptr,
                         info_ptr,
                         width,
                         height,
                         8,
                         PNG_COLOR_TYPE_RGB_ALPHA,
                         PNG_INTERLACE_NONE,
                         PNG_COMPRESSION_TYPE_BASE,
                         PNG_FILTER_TYPE_BASE);
            break;
    }

    png_write_info(png_ptr, info_ptr);

    int x, y;
    if (!rotate) {
        for (y = 0; y < height; y++) {
            png_write_row(png_ptr, ((BYTE*)pImgData) + y * ystride);
        }
    } else {
        int bytesperpixel = pImage->Backing()->BytesPerPixel();
        BYTE* pRow = (BYTE*)malloc(width * bytesperpixel);
        for (y = 0; y < height; y++) {
            BYTE* rowStart = pImgData;
            BYTE* rowOut = pRow;

            for (x = 0; x < width; x++) {
                int bpp = bytesperpixel;
                BYTE* pixel = rowStart;
                while (bpp--) {
                    *(rowOut++) = *(pixel++);
                }
                rowStart += xstride;
            }
            pImgData += ystride;
            png_write_row(png_ptr, pRow);
        }
        free(pRow);
    }
    pImage->Backing()->ReleaseImageData();

    png_write_end(png_ptr, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);

    return ret;
}

NSData* UIImageJPEGRepresentation(UIImage* img) {
    EbrDebugLog("UIImageJPEGRepresentation not supported - returning PNG\n");

    return UIImagePNGRepresentation(img);
}

@interface _UIImageWriterCallback : NSObject
- (void)image:(UIImage*)image didFinishSavingWithError:(NSError*)err contextInfo:(void*)contextInfo;
@end

void UIImageWriteToSavedPhotosAlbum(UIImage* image, id completionTarget, SEL completionSelector, void* contextInfo) {
    EbrDebugLog("UIImageWriteToSavedPhotosAlbum not supported\n");

    [(_UIImageWriterCallback*)completionTarget image:nil didFinishSavingWithError:nil contextInfo:contextInfo];
}
