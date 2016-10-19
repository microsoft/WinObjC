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
#import <math.h>
#import <vector>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGDataProvider.h>
#import <Foundation/NSData.h>
#import <LoggingNative.h>
#import <CFRuntime.h>
#import <CFBridgeUtilities.h>
#import "D2DWrapper.h"
#import "CGColorSpaceInternal.h"
#import "CGImageInternal.h"
#import "CGSurfaceInfoInternal.h"

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"CGImage";

#define RETURN_FALSE_IF_FAILED(input) RETURN_FALSE_IF(FAILED(input));

// TODO: remove old code
#pragma region OLD_CODE
static std::vector<CGImageDestructionListener> _imageDestructionListeners;
COREGRAPHICS_EXPORT void CGImageAddDestructionListener(CGImageDestructionListener listener) {
    _imageDestructionListeners.push_back(listener);
}

//  Default implementation does a deep copy
CGImageRef CGImageBacking::CopyOnWrite() {
    CGImageRef ret;

    ret = new CGBitmapImage(_parent);

    return ret;
}

#pragma endregion OLD_CODE

/**
 @Status Interoperable
*/
CFTypeID CGImageGetTypeID() {
    return __CGImage::GetTypeID();
}

/**
 @Status Caveat
 @Notes Limited bitmap formats available and decode is not supported.
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
    RETURN_NULL_IF(((provider == nullptr) || ![(NSObject*)provider isKindOfClass:[NSData class]]));

    NSData* dataProvider = (__bridge NSData*)provider;

    unsigned char* data = (unsigned char*)[dataProvider bytes];

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

    ComPtr<IWICBitmap> image;
    ComPtr<IWICImagingFactory> imageFactory = _GetWICFactory();

    REFGUID pixelFormat = _CGImageGetWICPixelFormat(bitsPerComponent, bitsPerPixel, colorSpace, bitmapInfo);

    // TODO: take care of the stride (mapping of the guids)
    HRESULT status = imageFactory->CreateBitmapFromMemory(width, height, pixelFormat, bytesPerRow, height * bytesPerRow, data, &image);

    CGImageRef imageRef = __CGImage::CreateInstance();
    imageRef->ImageSource().Attach(image.Detach());

    imageRef->SetBitmapInfo(bitmapInfo).SetColorSpace(colorSpace).SetRenderingIntent(intent).SetInterpolate(shouldInterpolate);

    if (colorSpaceAllocated) {
        CGColorSpaceRelease(colorSpace);
    }

    return imageRef;
}

/**
 @Status Interoperable
*/
CGImageRef CGImageCreateWithImageInRect(CGImageRef ref, CGRect rect) {
    RETURN_NULL_IF(!ref);

    CGImageRef imageRef = __CGImage::CreateInstance();

    ComPtr<IWICImagingFactory> imageFactory = _GetWICFactory();
    ComPtr<IWICBitmap> rectImage;
    RETURN_NULL_IF_FAILED(imageFactory->CreateBitmapFromSourceRect(
        ref->ImageSource().Get(), rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, &rectImage));

    imageRef->ImageSource().Attach(rectImage.Detach());

    imageRef->SetBitmapInfo(ref->BitmapInfo())
        .SetColorSpace(ref->ColorSpace())
        .SetRenderingIntent(ref->RenderingIntent())
        .SetInterpolate(ref->Interpolate());

    return imageRef;
}

/**
 @Status Interoperable
*/
CGImageRef CGImageCreateCopy(CGImageRef ref) {
    RETURN_NULL_IF(!ref);

    CGImageRef imageRef = __CGImage::CreateInstance();

    ComPtr<IWICImagingFactory> imageFactory = _GetWICFactory();
    ComPtr<IWICBitmap> image;

    RETURN_NULL_IF_FAILED(imageFactory->CreateBitmapFromSource(ref->ImageSource().Get(), WICBitmapCacheOnDemand, &image));

    imageRef->ImageSource().Attach(image.Detach());
    imageRef->SetBitmapInfo(ref->BitmapInfo())
        .SetIsMask(ref->IsMask())
        .SetInterpolate(ref->Interpolate())
        .SetColorSpace(ref->ColorSpace())
        .SetRenderingIntent(ref->RenderingIntent());

    return imageRef;
}

/**
 @Status Caveat
 @Notes decode parameter is ignored
*/
CGImageRef CGImageMaskCreate(size_t width,
                             size_t height,
                             size_t bitsPerComponent,
                             size_t bitsPerPixel,
                             size_t bytesPerRow,
                             CGDataProviderRef provider,
                             const CGFloat* decode,
                             bool shouldInterpolate) {
    RETURN_NULL_IF(((bitsPerComponent == 8) && (bitsPerPixel == 32)));

    RETURN_NULL_IF(((provider == nullptr) || ![(NSObject*)provider isKindOfClass:[NSData class]]));

    NSData* dataProvider = (__bridge NSData*)provider;

    unsigned char* data = (unsigned char*)[dataProvider bytes];

    ComPtr<IWICBitmap> image;
    ComPtr<IWICImagingFactory> imageFactory = _GetWICFactory();

    HRESULT status =
        imageFactory->CreateBitmapFromMemory(width, height, GUID_WICPixelFormatBlackWhite, bytesPerRow, height * bytesPerRow, data, &image);

    CGImageRef imageRef = __CGImage::CreateInstance();
    imageRef->ImageSource().Attach(image.Detach());
    imageRef->SetIsMask(true).SetInterpolate(shouldInterpolate);

    return imageRef;
}

/**
 @Status Interoperable
*/
CGDataProviderRef CGImageGetDataProvider(CGImageRef img) {
    RETURN_NULL_IF(!img);

    size_t height, width;
    RETURN_NULL_IF_FAILED(img->ImageSource()->GetSize(&width, &height));

    // TODO: should be using the CGImageGetBytesPerRow
    const unsigned int stride = width * 4;
    const unsigned int size = height * stride;
    woc::unique_iw<unsigned char> data(static_cast<unsigned char*>(IwMalloc(size)));

    RETURN_NULL_IF_FAILED(img->ImageSource()->CopyPixels(0, stride, stride, data.get()));

    NSData* byteData = [NSData dataWithBytesNoCopy:data.release() length:size freeWhenDone:YES];
    CGDataProviderRef ret = CGDataProviderCreateWithCFData((CFDataRef)byteData);
    CFAutorelease(ret);
    return ret;
}

/**
 @Status Interoperable
*/
CGColorRenderingIntent CGImageGetRenderingIntent(CGImageRef image) {
    if (!image) {
        return kCGRenderingIntentDefault;
    }

    return image->RenderingIntent();
}

/**
 @Status Interoperable
*/
bool CGImageGetShouldInterpolate(CGImageRef image) {
    RETURN_FALSE_IF(!image);
    return image->Interpolate();
}

/**
 @Status Interoperable
*/
bool CGImageIsMask(CGImageRef image) {
    RETURN_FALSE_IF(!image);
    return image->IsMask();
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGImageGetColorSpace(CGImageRef img) {
    RETURN_NULL_IF(!img);
    return img->ColorSpace();
}

/**
 @Status Interoperable
*/
size_t CGImageGetWidth(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    return img->Width();
}

/**
 @Status Interoperable
*/
size_t CGImageGetHeight(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    return img->Height();
}

/**
 @Status Interoperable
*/
void CGImageRelease(CGImageRef img) {
    RETURN_IF(!img);
    CFRelease((CFTypeRef)img);
}

/**
 @Status Interoperable
*/
CGImageRef CGImageRetain(CGImageRef img) {
    RETURN_NULL_IF(!img);
    CFRetain((CFTypeRef)img);
    return img;
}

/**
 @Status Interoperable
*/
CGBitmapInfo CGImageGetBitmapInfo(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    return img->BitmapInfo();
}

/**
 @Status Caveat
 @Notes decode parameter not supported and must be nullptr.
*/
CGImageRef CGImageCreateWithJPEGDataProvider(CGDataProviderRef source,
                                             const CGFloat decode[],
                                             bool shouldInterpolate,
                                             CGColorRenderingIntent intent) {
    RETURN_NULL_IF((source == nullptr) || ![(NSObject*)source isKindOfClass:[NSData class]]);

    NSData* sourceData = (__bridge NSData*)source;
    CGImageRef imageRef = _CGImageLoadJPEG((void*)[sourceData bytes], [sourceData length]);

    RETURN_NULL_IF(!imageRef);
    imageRef->SetInterpolate(shouldInterpolate).SetRenderingIntent(intent);

    return imageRef;
}

/**
 @Status Caveat
 @Notes decode parameter not supported and must be nullptr.
*/
CGImageRef CGImageCreateWithPNGDataProvider(CGDataProviderRef source,
                                            const CGFloat decode[],
                                            bool shouldInterpolate,
                                            CGColorRenderingIntent intent) {
    RETURN_NULL_IF((source == nullptr) || ![(NSObject*)source isKindOfClass:[NSData class]]);

    NSData* sourceData = (__bridge NSData*)source;
    CGImageRef imageRef = _CGImageLoadPNG((void*)[sourceData bytes], [sourceData length]);

    RETURN_NULL_IF(!imageRef);
    imageRef->SetInterpolate(shouldInterpolate).SetRenderingIntent(intent);

    return imageRef;
}

/**
 @Status Stub
 @Notes
*/
CGImageRef CGImageCreateCopyWithColorSpace(CGImageRef ref, CGColorSpaceRef colorSpace) {
    RETURN_NULL_IF(!ref);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 */
CGImageRef CGImageCreateWithMask(CGImageRef image, CGImageRef mask) {
    // TODO: Given how masks are applied during rendering via D2D, we will hold onto the
    // mask then apply it at the appropriate time.
    RETURN_NULL_IF(!image);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CGImageAlphaInfo CGImageGetAlphaInfo(CGImageRef img) {
    if (!img) {
        return kCGImageAlphaNone;
    }
    // We would only have three values.
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGImageGetBitsPerPixel(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGImageGetBitsPerComponent(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGImageGetBytesPerRow(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
const CGFloat* CGImageGetDecode(CGImageRef image) {
    RETURN_NULL_IF(!image);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGImageRef CGImageCreateWithMaskingColors(CGImageRef image, const CGFloat* components) {
    RETURN_NULL_IF(!image);
    UNIMPLEMENTED();
    return StubReturn();
}

#pragma region WIC_HELPERS

CGImageRef _CGImageGetImageFromData(void* data, int length) {
    return _CGImageLoadImageWithWICDecoder(GUID_NULL, data, length);
}

CGImageRef _CGImageLoadGIF(void* bytes, int length) {
    return _CGImageLoadImageWithWICDecoder(GUID_ContainerFormatGif, bytes, length);
}

CGImageRef _CGImageLoadBMP(void* bytes, size_t length) {
    return _CGImageLoadImageWithWICDecoder(GUID_ContainerFormatBmp, bytes, length);
}

CGImageRef _CGImageLoadTIFF(void* bytes, int length) {
    return _CGImageLoadImageWithWICDecoder(GUID_ContainerFormatTiff, bytes, length);
}

CGImageRef _CGImageLoadPNG(void* bytes, int length) {
    return _CGImageLoadImageWithWICDecoder(GUID_ContainerFormatPng, bytes, length);
}

CGImageRef _CGImageLoadJPEG(void* bytes, int length) {
    return _CGImageLoadImageWithWICDecoder(GUID_ContainerFormatJpeg, bytes, length);
}

CGImageRef _CGImageLoadImageWithWICDecoder(REFGUID decoderCls, void* bytes, int length) {
    ComPtr<IWICImagingFactory> imageFactory = _GetWICFactory();

    ComPtr<IWICBitmapDecoder> pDecoder;

    if (decoderCls != GUID_NULL) {
        ComPtr<IStream> spStream;
        RETURN_NULL_IF_FAILED(::CreateStreamOnHGlobal(NULL, FALSE, &spStream));

        ULONG written = 0;
        HRESULT hr = spStream->Write(bytes, length, &written);
        if (FAILED(hr) || (written != length)) {
            TraceError(TAG, L"IStream::Write failed hr=%x len=%d written=%d", hr, length, written);
            return NULL;
        }

        // seek to start
        LARGE_INTEGER offset;
        offset.QuadPart = 0;
        RETURN_NULL_IF_FAILED(spStream->Seek(offset, STREAM_SEEK_SET, NULL));

        RETURN_NULL_IF_FAILED(imageFactory->CreateDecoder(decoderCls, NULL, &pDecoder));

        hr = pDecoder->Initialize(spStream.Get(), WICDecodeMetadataCacheOnLoad);
        RETURN_NULL_IF_FAILED(hr);

    } else {
        ComPtr<IWICStream> spStream;
        RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&spStream));

        RETURN_NULL_IF_FAILED(spStream->InitializeFromMemory(static_cast<unsigned char*>(bytes), length));
        RETURN_NULL_IF_FAILED(imageFactory->CreateDecoderFromStream(spStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &pDecoder));
    }

    ComPtr<IWICBitmapFrameDecode> bitMapFrameDecoder;
    RETURN_NULL_IF_FAILED(pDecoder->GetFrame(0, &bitMapFrameDecoder));

    CGImageRef imageRef = __CGImage::CreateInstance();
    imageRef->ImageSource().Attach(bitMapFrameDecoder.Detach());
    // TODO:(JJ) Set the color space
    return imageRef;
}

NSData* _CGImagePNGRepresentation(CGImageRef image) {
    return _CGImageRepresentation(image, GUID_WICPixelFormat32bppBGRA);
}

NSData* _CGImageJPEGRepresentation(CGImageRef image) {
    return _CGImageRepresentation(image, GUID_WICPixelFormat32bppCMYK);
}

NSData* _CGImageRepresentation(CGImageRef image, REFGUID guid) {
    RETURN_NULL_IF(!image);

    ComPtr<IWICImagingFactory> imageFactory = _GetWICFactory();
    ComPtr<IWICFormatConverter> imageFormatConverter;

    RETURN_NULL_IF_FAILED(imageFactory->CreateFormatConverter(&imageFormatConverter));

    RETURN_NULL_IF_FAILED(imageFormatConverter->Initialize(
        image->ImageSource().Get(), guid, WICBitmapDitherTypeNone, nullptr, 0.f, WICBitmapPaletteTypeCustom));

    size_t height, width;
    RETURN_NULL_IF_FAILED(image->ImageSource()->GetSize(&width, &height));

    const unsigned int size = height * width * 4;
    woc::unique_iw<unsigned char> data(static_cast<unsigned char*>(IwMalloc(size)));
    RETURN_NULL_IF_FAILED(imageFormatConverter->CopyPixels(0, width * 4, size, data.get()));

    return [NSData dataWithBytesNoCopy:data.release() length:size freeWhenDone:YES];
}

REFGUID _CGImageGetWICPixelFormat(unsigned int bitsPerComponent,
                                  unsigned int bitsPerPixel,
                                  CGColorSpaceRef colorSpace,
                                  CGBitmapInfo bitmapInfo) {
    // TODO: NUll check?
    CGColorSpaceModel colorSpaceModel = CGColorSpaceGetModel(colorSpace);

    unsigned int alphaInfo = bitmapInfo & kCGBitmapAlphaInfoMask;
    // TODO: support for kCGBitmapFloatComponents
    // TODO: make this more verbose, map?

    if (colorSpaceModel == kCGColorSpaceModelRGB) {
        switch (alphaInfo) {
            case kCGImageAlphaPremultipliedLast:
            case kCGImageAlphaLast:
                if (bitsPerPixel == 32) {
                    return GUID_WICPixelFormat32bppRGBA;
                } else if (bitsPerPixel == 64) {
                    return GUID_WICPixelFormat64bppRGBA;
                } else {
                    UNIMPLEMENTED_WITH_MSG("kCGImageAlphaLast: Unknown pixelformat: %d", bitsPerPixel);
                    return GUID_WICPixelFormat32bppRGBA;
                }
                break;
            case kCGImageAlphaPremultipliedFirst:
                if (bitsPerPixel == 32) {
                    return GUID_WICPixelFormat32bppPRGBA;
                } else if (bitsPerPixel == 64) {
                    return GUID_WICPixelFormat64bppPRGBA;
                } else {
                    UNIMPLEMENTED_WITH_MSG("kCGImageAlphaPremultipliedFirst: Unknown pixelformat: %d", bitsPerPixel);
                    return GUID_WICPixelFormat32bppPRGBA;
                }

            case kCGImageAlphaFirst:
                return GUID_WICPixelFormat32bppRGBA;
                break;
            case kCGImageAlphaNoneSkipFirst:
            case kCGImageAlphaNoneSkipLast:
            case kCGImageAlphaNone:
                if (bitsPerPixel == 32) {
                    return GUID_WICPixelFormat32bppRGB;
                } else if (bitsPerPixel == 48) {
                    return GUID_WICPixelFormat48bppRGB;
                } else if (bitsPerPixel == 64) {
                    return GUID_WICPixelFormat64bppRGB;
                } else {
                    UNIMPLEMENTED_WITH_MSG("Alpha None: Unknown pixelformat: %d", bitsPerPixel);
                    return GUID_WICPixelFormat32bppRGB;
                }
                break;
            case kCGImageAlphaOnly:
                return GUID_WICPixelFormat8bppAlpha;
                break;
            default:
                UNIMPLEMENTED_WITH_MSG("Unknown pixel format, alphaInfo:%d, assuming RGBA", alphaInfo);
                return GUID_WICPixelFormat32bppRGBA;
                break;
        }
    } else if (colorSpaceModel == kCGColorSpaceModelCMYK) {
        if (bitsPerPixel == 32) {
            return GUID_WICPixelFormat32bppCMYK;
        } else if (bitsPerPixel == 64) {
            return GUID_WICPixelFormat64bppCMYK;
        } else if (bitsPerPixel == 40) {
            return GUID_WICPixelFormat40bppCMYKAlpha;
        } else if (bitsPerPixel == 80) {
            return GUID_WICPixelFormat80bppCMYKAlpha;
        }
    } else if (colorSpaceModel == kCGColorSpaceModelMonochrome) {
        if (bitsPerPixel == 4) {
            return GUID_WICPixelFormat4bppGray;
        } else if (bitsPerPixel == 8) {
            return GUID_WICPixelFormat8bppGray;
        } else if (bitsPerPixel == 16) {
            return GUID_WICPixelFormat16bppGray;
        } else if (bitsPerPixel == 32) {
            return GUID_WICPixelFormat32bppGrayFloat;
        }

    } else if (colorSpaceModel == kCGColorSpaceModelIndexed) {
        if (bitsPerPixel == 1) {
            return GUID_WICPixelFormat1bppIndexed;
        } else if (bitsPerPixel == 2) {
            return GUID_WICPixelFormat2bppIndexed;
        } else if (bitsPerPixel == 4) {
            return GUID_WICPixelFormat4bppIndexed;
        } else if (bitsPerPixel == 8) {
            return GUID_WICPixelFormat8bppIndexed;
        }
    }

    return GUID_WICPixelFormat32bppRGBA;
}

#pragma endregion WIC_HELPERS