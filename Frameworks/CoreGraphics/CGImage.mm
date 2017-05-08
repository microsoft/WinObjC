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
#import <CoreGraphics/CGBitmapContext.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGDataProvider.h>
#import <LoggingNative.h>
#import <CFRuntime.h>
#import <CFBridgeUtilities.h>
#import <CoreGraphics/D2DWrapper.h>
#import "CGColorSpaceInternal.h"
#import "CGImageInternal.h"
#import "CGIWICBitmap.h"
#import "CGDataProviderInternal.h"

#import <algorithm>

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"CGImage";

// This is used by XamlCompositor to flush the DisplayTexture cache.
// TODO GH#2098 look at where we're using the image cache and what we can do to avoid it.
static std::vector<CGImageDestructionListener> _imageDestructionListeners;
COREGRAPHICS_EXPORT void _CGImageAddDestructionListener(CGImageDestructionListener listener) {
    _imageDestructionListeners.push_back(listener);
}

#pragma region CGImageImplementation

struct __CGImage : CoreFoundation::CppBase<__CGImage> {
    ComPtr<IWICBitmap> _bitmapImageSource;

    // Calculated from pixel format + WIC backing
    WICPixelFormatGUID _pixelFormat;
    woc::StrongCF<CGColorSpaceRef> _colorSpace;
    size_t _width;
    size_t _height;
    size_t _bitsPerPixel;
    size_t _bitsPerComponent;
    size_t _bytesPerRow;
    CGBitmapInfo _bitmapInfo;
    CGImageAlphaInfo _alphaInfo;

    // User-specified
    bool _isMask;
    bool _interpolate; // default: true
    CGColorRenderingIntent _renderingIntent;

    __CGImage()
        : Parent(),
          _bitmapImageSource(nullptr),
          _pixelFormat(GUID_WICPixelFormatUndefined),
          _width(0),
          _height(0),
          _bitsPerPixel(0),
          _bitsPerComponent(0),
          _bytesPerRow(0),
          _bitmapInfo(kCGBitmapByteOrderDefault),
          _alphaInfo(kCGImageAlphaNone),
          _isMask(false),
          _interpolate(true),
          _renderingIntent(kCGRenderingIntentDefault) {
    }

    // We would use a copy constructor here, but they cannot return HRESULTs.
    // There are no other throwing constructors in our code, so it doesn't make sense to introduce our first one.
    HRESULT CopyFromImage(const __CGImage& other, WICPixelFormatGUID newFormat = GUID_WICPixelFormatDontCare, CGRect* region = nullptr) {
        CGRect rect = region ? *region : CGRect{ CGPointZero, { other._width, other._height } };

        ComPtr<IWICImagingFactory> imageFactory;
        RETURN_IF_FAILED(_CGGetWICFactory(&imageFactory));

        ComPtr<IWICBitmapSource> bitmapSource;

        if (newFormat == GUID_WICPixelFormatDontCare || newFormat == other._pixelFormat) {
            bitmapSource = other.ImageSource();
        } else {
            ComPtr<IWICFormatConverter> converter;
            RETURN_IF_FAILED(imageFactory->CreateFormatConverter(&converter));

            RETURN_IF_FAILED(converter->Initialize(
                other.ImageSource(), newFormat, WICBitmapDitherTypeNone, nullptr, 0.f, WICBitmapPaletteTypeMedianCut));

            bitmapSource = converter;
        }

        ComPtr<IWICBitmap> newBitmap;
        RETURN_IF_FAILED(imageFactory->CreateBitmapFromSourceRect(bitmapSource.Get(), rect.origin.x, rect.origin.y, rect.size.width, rect.size.height, &newBitmap));

        RETURN_IF_FAILED(SetImageSource(newBitmap.Get())); // also sets _colorSpace
        _isMask = other._isMask;
        _interpolate = other._interpolate;
        _renderingIntent = other._renderingIntent;

        return S_OK;
    }

    inline HRESULT SetImageSource(IWICBitmap* source) {
        RETURN_IF_FAILED(source->GetPixelFormat(&_pixelFormat));

        _bitmapImageSource = source;

        const __CGImagePixelProperties* properties = _CGGetPixelFormatProperties(_pixelFormat);

        // populate the image info.
        if (FAILED(_bitmapImageSource->GetSize(&_width, &_height))) {
            _height = 0;
            _width = 0;
        }

        _bitmapInfo = properties->bitmapInfo;
        _alphaInfo = static_cast<CGImageAlphaInfo>(_bitmapInfo & kCGBitmapAlphaInfoMask);
        _bitsPerPixel = properties->bitsPerPixel;
        _bitsPerComponent = properties->bitsPerComponent;
        _bytesPerRow = (_bitsPerPixel >> 3) * _width;
        if (!_colorSpace) {
            // create a new empty colorspace of the appropriate model
            _colorSpace.attach(_CGColorSpaceCreate(properties->colorSpaceModel));
        }

        return S_OK;
    }

    inline IWICBitmap* ImageSource() const {
        return _bitmapImageSource.Get();
    }

    inline WICPixelFormatGUID PixelFormat() const {
        return _pixelFormat;
    }

    inline void* Data() const {
        Microsoft::WRL::ComPtr<IWICBitmapLock> lock;
        RETURN_NULL_IF_FAILED(_bitmapImageSource->Lock(nullptr, WICBitmapLockWrite, &lock));
        BYTE* data;
        UINT size;
        RETURN_NULL_IF_FAILED(lock->GetDataPointer(&size, &data));
        return static_cast<void*>(data);
    }

    inline size_t Height() const {
        return _height;
    }

    inline size_t Width() const {
        return _width;
    }

    inline CGColorSpaceRef ColorSpace() const {
        return _colorSpace.get();
    }

    inline void SetColorSpace(CGColorSpaceRef space) {
        _colorSpace = space;
    }

    inline CGBitmapInfo BitmapInfo() const {
        return _bitmapInfo;
    }

    inline CGImageAlphaInfo AlphaInfo() const {
        return _alphaInfo;
    }

    inline size_t BitsPerPixel() const {
        return _bitsPerPixel;
    }

    inline size_t BytesPerRow() const {
        return _bytesPerRow;
    }

    inline size_t BitsPerComponent() const {
        return _bitsPerComponent;
    }

    inline bool IsMask() const {
        return _isMask;
    }

    inline void SetIsMask(bool mask) {
        _isMask = mask;
    }

    inline bool Interpolate() const {
        return _interpolate;
    }

    inline void SetInterpolate(bool interpolate) {
        _interpolate = interpolate;
    }

    inline CGColorRenderingIntent RenderingIntent() const {
        return _renderingIntent;
    }

    inline void SetRenderingIntent(CGColorRenderingIntent intent) {
        _renderingIntent = intent;
    }

    ~__CGImage() {
        for (auto listener : _imageDestructionListeners) {
            listener(this);
        }
    }
};

#pragma endregion CGImageImplementation

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
    RETURN_NULL_IF(provider == nullptr || colorSpace == nullptr);

    ComPtr<IWICBitmap> image;
    ComPtr<IWICImagingFactory> imageFactory;
    RETURN_NULL_IF_FAILED(_CGGetWICFactory(&imageFactory));

    GUID pixelFormat;
    RETURN_NULL_IF_FAILED(
        _CGImageGetWICPixelFormatFromImageProperties(bitsPerComponent, bitsPerPixel, colorSpace, bitmapInfo, &pixelFormat));

    unsigned char* bytes = static_cast<unsigned char*>(const_cast<void*>(_CGDataProviderGetData(provider)));
    RETURN_NULL_IF_FAILED(
        imageFactory->CreateBitmapFromMemory(width, height, pixelFormat, bytesPerRow, height * bytesPerRow, bytes, &image));

    CGImageRef imageRef = __CGImage::CreateInstance();
    RETURN_NULL_IF_FAILED(imageRef->SetImageSource(image.Get()));
    imageRef->SetColorSpace(colorSpace);
    imageRef->SetRenderingIntent(intent);
    imageRef->SetInterpolate(shouldInterpolate);

    return imageRef;
}

/**
 @Status Interoperable
*/
CGImageRef CGImageCreateWithImageInRect(CGImageRef ref, CGRect rect) {
    RETURN_NULL_IF(!ref);

    woc::StrongCF<CGImageRef> newImage{ woc::TakeOwnership, __CGImage::CreateInstance() };
    RETURN_NULL_IF_FAILED(newImage->CopyFromImage(*ref, GUID_WICPixelFormatDontCare, &rect));
    return newImage.detach();
}

/**
 @Status Interoperable
*/
CGImageRef CGImageCreateCopy(CGImageRef ref) {
    RETURN_NULL_IF(!ref);

    woc::StrongCF<CGImageRef> newImage{ woc::TakeOwnership, __CGImage::CreateInstance() };
    RETURN_NULL_IF_FAILED(newImage->CopyFromImage(*ref, GUID_WICPixelFormatDontCare, nullptr));
    return newImage.detach();
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
    RETURN_NULL_IF(provider == nullptr);

    ComPtr<IWICBitmap> image;
    ComPtr<IWICImagingFactory> imageFactory;
    RETURN_NULL_IF_FAILED(_CGGetWICFactory(&imageFactory));

    woc::unique_cf<CGColorSpaceRef> colorSpace(CGColorSpaceCreateDeviceGray());
    GUID pixelFormat;
    RETURN_NULL_IF_FAILED(
        _CGImageGetWICPixelFormatFromImageProperties(bitsPerComponent, bitsPerPixel, colorSpace, kCGBitmapByteOrderDefault, &pixelFormat));

    unsigned char* bytes = static_cast<unsigned char*>(const_cast<void*>(_CGDataProviderGetData(provider)));
    RETURN_NULL_IF_FAILED(
        imageFactory->CreateBitmapFromMemory(width, height, pixelFormat, bytesPerRow, height * bytesPerRow, bytes, &image));

    CGImageRef imageRef = __CGImage::CreateInstance();
    RETURN_NULL_IF_FAILED(imageRef->SetImageSource(image.Get()));
    imageRef->SetIsMask(true);
    imageRef->SetInterpolate(shouldInterpolate);

    return imageRef;
}

/**
 @Status Interoperable
*/
CGDataProviderRef CGImageGetDataProvider(CGImageRef img) {
    RETURN_NULL_IF(!img);

    const unsigned int stride = CGImageGetBytesPerRow(img);
    const unsigned int size = CGImageGetHeight(img) * stride;
    std::unique_ptr<unsigned char[]> buffer(new unsigned char[size]);

    RETURN_NULL_IF_FAILED(img->ImageSource()->CopyPixels(nullptr, stride, size, buffer.get()));

    CGDataProviderRef dataProvider =
        CGDataProviderCreateWithData(nullptr, buffer.release(), size, [](void* info, const void* data, size_t size) {
            delete[](const unsigned char*) data;
        });
    CFAutorelease(dataProvider);
    return dataProvider;
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
CGBitmapInfo CGImageGetBitmapInfo(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, kCGBitmapByteOrderDefault);
    return img->BitmapInfo();
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
 @Status Caveat
 @Notes decode parameter not supported and must be nullptr.
*/
CGImageRef CGImageCreateWithJPEGDataProvider(CGDataProviderRef source,
                                             const CGFloat decode[],
                                             bool shouldInterpolate,
                                             CGColorRenderingIntent intent) {
    RETURN_NULL_IF(source == nullptr);

    unsigned char* bytes = static_cast<unsigned char*>(const_cast<void*>(_CGDataProviderGetData(source)));
    CGImageRef imageRef = _CGImageLoadJPEG(bytes, _CGDataProviderGetSize(source));

    RETURN_NULL_IF(!imageRef);
    imageRef->SetInterpolate(shouldInterpolate);
    imageRef->SetRenderingIntent(intent);

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
    RETURN_NULL_IF(source == nullptr);

    unsigned char* bytes = static_cast<unsigned char*>(const_cast<void*>(_CGDataProviderGetData(source)));
    CGImageRef imageRef = _CGImageLoadPNG(bytes, _CGDataProviderGetSize(source));

    RETURN_NULL_IF(!imageRef);
    imageRef->SetInterpolate(shouldInterpolate);
    imageRef->SetRenderingIntent(intent);

    return imageRef;
}

/**
 @Status Interoperable
*/
size_t CGImageGetBitsPerPixel(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    return img->BitsPerPixel();
}

/**
 @Status Interoperable
*/
size_t CGImageGetBitsPerComponent(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    return img->BitsPerComponent();
}

/**
 @Status Interoperable
*/
size_t CGImageGetBytesPerRow(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, 0);
    return img->BytesPerRow();
}

/**
 @Status Interoperable
*/
CGImageAlphaInfo CGImageGetAlphaInfo(CGImageRef img) {
    RETURN_RESULT_IF_NULL(img, kCGImageAlphaNone);
    return img->AlphaInfo();
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
 @Status Interoperable
 @Notes This function does not defer the composition of its mask.
        This function supports non-grayscale alpha masks, unlike the reference platform.
 */
CGImageRef CGImageCreateWithMask(CGImageRef image, CGImageRef mask) {
    RETURN_NULL_IF(!image);
    RETURN_NULL_IF(!mask);
    RETURN_NULL_IF(CGImageIsMask(image));

    size_t width = CGImageGetWidth(image);
    size_t height = CGImageGetHeight(image);

    woc::unique_cf<CGContextRef> context{
        CGBitmapContextCreate(nullptr, width, height, 8, width * 4, CGImageGetColorSpace(image), kCGImageAlphaPremultipliedLast)
    };
    RETURN_NULL_IF(!context);

    CGRect rect{
        CGPointZero, { width, height },
    };
    CGContextClipToMask(context.get(), rect, mask);
    CGContextDrawImage(context.get(), rect, image);

    return CGBitmapContextCreateImage(context.get());
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

WICPixelFormatGUID _CGImageGetWICPixelFormat(CGImageRef image) {
    RETURN_RESULT_IF_NULL(image, GUID_WICPixelFormatUndefined);
    return image->PixelFormat();
}

bool _CGIsValidRenderTargetPixelFormat(WICPixelFormatGUID pixelFormat) {
    auto iterator = s_ValidRenderTargetPixelFormat.find(pixelFormat);
    return iterator != s_ValidRenderTargetPixelFormat.end();
}

const __CGImagePixelProperties* _CGGetPixelFormatProperties(WICPixelFormatGUID pixelFormat) {
    RETURN_NULL_IF(pixelFormat == GUID_WICPixelFormatUndefined);

    auto iterator = s_PixelFormats.find(pixelFormat);
    RETURN_NULL_IF(iterator == s_PixelFormats.end());

    return &iterator->second;
}

HRESULT _CGImageGetWICImageSource(CGImageRef image, IWICBitmap** source) {
    RETURN_HR_IF_NULL(E_INVALIDARG, image);
    RETURN_HR_IF_NULL(E_POINTER, source);
    IWICBitmap* copy = image->ImageSource();
    copy->AddRef();
    *source = copy;
    return S_OK;
}

__declspec(dllexport) std::shared_ptr<IDisplayTexture> _CGImageGetDisplayTexture(CGImageRef image) {
    RETURN_NULL_IF(!image);

    ComPtr<ICGDisplayTexture> displayTextureAccess;
    RETURN_NULL_IF_FAILED(image->ImageSource()->QueryInterface(IID_PPV_ARGS(&displayTextureAccess)));
    RETURN_NULL_IF(!displayTextureAccess);

    return displayTextureAccess->DisplayTexture();
}

// Return the data pointer to the Image data.
void* _CGImageGetRawBytes(CGImageRef image) {
    RETURN_NULL_IF(!image);
    return image->Data();
}

CGImageRef _CGImageCreateWithWICBitmap(IWICBitmap* bitmap) {
    RETURN_NULL_IF(!bitmap);
    CGImageRef imageRef = __CGImage::CreateInstance();
    RETURN_NULL_IF_FAILED(imageRef->SetImageSource(bitmap));

    return imageRef;
}

CGImageRef _CGImageCreateCopyWithPixelFormat(CGImageRef ref, WICPixelFormatGUID pixelFormat) {
    RETURN_NULL_IF(!ref);
    if (IsEqualGUID(ref->PixelFormat(), pixelFormat)) {
        return CGImageRetain(ref);
    }

    woc::StrongCF<CGImageRef> newImage{ woc::TakeOwnership, __CGImage::CreateInstance() };
    RETURN_NULL_IF_FAILED(newImage->CopyFromImage(*ref, pixelFormat));
    return newImage.detach();
}

CGImageRef _CGImageCreateFromDataProvider(CGDataProviderRef provider) {
    RETURN_NULL_IF(!provider);
    unsigned char* dataBytes = static_cast<unsigned char*>(const_cast<void*>(_CGDataProviderGetData(provider)));
    return _CGImageGetImageFromData(dataBytes, _CGDataProviderGetSize(provider));
}

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
    ComPtr<IWICImagingFactory> imageFactory;
    RETURN_NULL_IF_FAILED(_CGGetWICFactory(&imageFactory));

    ComPtr<IWICBitmapDecoder> pDecoder;
    ComPtr<IWICStream> spStream;
    RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&spStream));
    RETURN_NULL_IF_FAILED(spStream->InitializeFromMemory(static_cast<unsigned char*>(bytes), length));

    if (!IsEqualGUID(decoderCls, GUID_NULL)) {
        RETURN_NULL_IF_FAILED(imageFactory->CreateDecoder(decoderCls, nullptr, &pDecoder));
        RETURN_NULL_IF_FAILED(pDecoder->Initialize(spStream.Get(), WICDecodeMetadataCacheOnLoad));
    } else {
        RETURN_NULL_IF_FAILED(imageFactory->CreateDecoderFromStream(spStream.Get(), nullptr, WICDecodeMetadataCacheOnLoad, &pDecoder));
    }

    ComPtr<IWICBitmapFrameDecode> bitMapFrameDecoder;
    RETURN_NULL_IF_FAILED(pDecoder->GetFrame(0, &bitMapFrameDecoder));

    ComPtr<IWICBitmap> bitmap;
    RETURN_NULL_IF_FAILED(imageFactory->CreateBitmapFromSource(bitMapFrameDecoder.Get(), WICBitmapCacheOnLoad, &bitmap));

    CGImageRef imageRef = __CGImage::CreateInstance();
    RETURN_NULL_IF_FAILED(imageRef->SetImageSource(bitmap.Get()));
    return imageRef;
}

size_t _CGImageImputeBitsPerPixelFromFormat(CGColorSpaceRef colorSpace, size_t bitsPerComponent, CGBitmapInfo bitmapInfo) {
    unsigned int alphaInfo = bitmapInfo & kCGBitmapAlphaInfoMask;
    unsigned int byteOrder = bitmapInfo & kCGBitmapByteOrderMask;

    // Try byte order first: The user can specify 32 or 16 directly.
    switch (byteOrder) {
        case kCGBitmapByteOrder32Little:
        case kCGBitmapByteOrder32Big:
            return 32;
        case kCGBitmapByteOrder16Little:
        case kCGBitmapByteOrder16Big:
            return 16;
    }

    // Otherwise, try to figure out how many components there are.
    size_t nComponents = CGColorSpaceGetNumberOfComponents(colorSpace);
    switch (alphaInfo) {
        case kCGImageAlphaNoneSkipFirst:
        case kCGImageAlphaPremultipliedFirst:
        case kCGImageAlphaFirst:
        case kCGImageAlphaNoneSkipLast:
        case kCGImageAlphaPremultipliedLast:
        case kCGImageAlphaLast:
            nComponents += 1;
            break;
    }

    return (bitsPerComponent * nComponents);
}

// CG packed format key
//  |Color  |bits/px|CGBitmapInfo   |
//  |-------|-------|---------------|
// 32      24      16               0
#define CG_FORMAT_KEY(colorSpaceModel, bpp, byteOrder, alpha) \
    (((colorSpaceModel & 0xFF) << 24) | ((bpp & 0xFF) << 16) | ((alpha | byteOrder) & 0xFFFF))

HRESULT _CGImageGetWICPixelFormatFromImageProperties(
    unsigned int bitsPerComponent, unsigned int bitsPerPixel, CGColorSpaceRef colorSpace, CGBitmapInfo bitmapInfo, GUID* pixelFormat) {
    // clang-format off
    static std::map<uint32_t, WICPixelFormatGUID> s_CGWICFormatMap{
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 24, kCGBitmapByteOrderDefault,  kCGImageAlphaNone),               GUID_WICPixelFormat24bppRGB       },

        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrderDefault,  kCGImageAlphaNoneSkipFirst     ), GUID_WICPixelFormat32bppBGR       },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrderDefault,  kCGImageAlphaNoneSkipLast      ), GUID_WICPixelFormat32bppRGB       },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrderDefault,  kCGImageAlphaPremultipliedFirst), GUID_WICPixelFormat32bppPBGRA     },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrderDefault,  kCGImageAlphaPremultipliedLast ), GUID_WICPixelFormat32bppPRGBA     },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrderDefault,  kCGImageAlphaFirst             ), GUID_WICPixelFormat32bppRGBA      },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrderDefault,  kCGImageAlphaLast              ), GUID_WICPixelFormat32bppRGBA      },

        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrder32Little, kCGImageAlphaNoneSkipFirst     ), GUID_WICPixelFormat32bppBGR       },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrder32Little, kCGImageAlphaPremultipliedFirst), GUID_WICPixelFormat32bppPBGRA     },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrder32Little, kCGImageAlphaFirst             ), GUID_WICPixelFormat32bppBGRA      },

        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrder32Big,    kCGImageAlphaNoneSkipLast      ), GUID_WICPixelFormat32bppRGB       },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrder32Big,    kCGImageAlphaPremultipliedLast ), GUID_WICPixelFormat32bppPRGBA     },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 32, kCGBitmapByteOrder32Big,    kCGImageAlphaLast              ), GUID_WICPixelFormat32bppRGBA      },

        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 64, kCGBitmapByteOrderDefault,  kCGImageAlphaPremultipliedLast ), GUID_WICPixelFormat64bppPRGBA     },
        { CG_FORMAT_KEY(kCGColorSpaceModelRGB       , 64, kCGBitmapByteOrderDefault,  kCGImageAlphaLast              ), GUID_WICPixelFormat64bppRGBA      },

        { CG_FORMAT_KEY(kCGColorSpaceModelCMYK      , 32, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat32bppCMYK      },
        { CG_FORMAT_KEY(kCGColorSpaceModelCMYK      , 32, kCGBitmapByteOrder32Big  ,  kCGImageAlphaNone              ), GUID_WICPixelFormat32bppCMYK      },
        { CG_FORMAT_KEY(kCGColorSpaceModelCMYK      , 40, kCGBitmapByteOrderDefault,  kCGImageAlphaLast              ), GUID_WICPixelFormat40bppCMYKAlpha },
        { CG_FORMAT_KEY(kCGColorSpaceModelCMYK      , 64, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat64bppCMYK      },
        { CG_FORMAT_KEY(kCGColorSpaceModelCMYK      , 80, kCGBitmapByteOrderDefault,  kCGImageAlphaLast              ), GUID_WICPixelFormat80bppCMYKAlpha },

        { CG_FORMAT_KEY(kCGColorSpaceModelMonochrome,  1, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormatBlackWhite     },
        { CG_FORMAT_KEY(kCGColorSpaceModelMonochrome,  2, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat2bppGray       },
        { CG_FORMAT_KEY(kCGColorSpaceModelMonochrome,  4, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat4bppGray       },
        { CG_FORMAT_KEY(kCGColorSpaceModelMonochrome,  8, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat8bppGray       },
        { CG_FORMAT_KEY(kCGColorSpaceModelMonochrome, 16, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat16bppGray      },
        { CG_FORMAT_KEY(kCGColorSpaceModelMonochrome, 16, kCGBitmapByteOrder16Little, kCGImageAlphaNone              ), GUID_WICPixelFormat16bppGray      },

        { CG_FORMAT_KEY(kCGColorSpaceModelMonochrome,  8, kCGBitmapByteOrderDefault,  kCGImageAlphaOnly              ), GUID_WICPixelFormat8bppAlpha      },

        { CG_FORMAT_KEY(kCGColorSpaceModelIndexed   ,  1, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat1bppIndexed    },
        { CG_FORMAT_KEY(kCGColorSpaceModelIndexed   ,  2, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat2bppIndexed    },
        { CG_FORMAT_KEY(kCGColorSpaceModelIndexed   ,  4, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat4bppIndexed    },
        { CG_FORMAT_KEY(kCGColorSpaceModelIndexed   ,  8, kCGBitmapByteOrderDefault,  kCGImageAlphaNone              ), GUID_WICPixelFormat8bppIndexed    },
    };
    // clang-format on

    RETURN_HR_IF(E_POINTER, !pixelFormat);

    size_t formatImputedBpp = _CGImageImputeBitsPerPixelFromFormat(colorSpace, bitsPerComponent, bitmapInfo);
    if (bitsPerPixel == 0) {
        bitsPerPixel = formatImputedBpp;
    }

    if (formatImputedBpp == bitsPerPixel) {
        CGColorSpaceModel colorSpaceModel = CGColorSpaceGetModel(colorSpace);
        auto found = s_CGWICFormatMap.find(CG_FORMAT_KEY(colorSpaceModel, bitsPerPixel, bitmapInfo, 0));
        if (found != s_CGWICFormatMap.end()) {
            *pixelFormat = found->second;
            return S_OK;
        }
    }

    size_t nComponents = CGColorSpaceGetNumberOfComponents(colorSpace);
    TraceError(TAG,
               L"Unfulfillable request for format with %dbpp%s (%d/component), %d-component color space, bitmap info %x",
               bitsPerPixel,
               (bitmapInfo & kCGBitmapFloatComponents) != 0 ? " (floating-point)" : "",
               bitsPerComponent,
               nComponents,
               bitmapInfo);
    return E_NOTIMPL;
}

static void __InvertMemcpy(void* dest, const void* src, size_t len) {
    uint32_t* d32 = (uint32_t*)dest;
    const uint32_t* s32 = (const uint32_t*)src;

    for (; len >= 4; len -= 4) {
        *d32++ = ~*s32++;
    }

    uint8_t* d8 = (uint8_t*)d32;
    const uint8_t* s8 = (const uint8_t*)s32;

    for (; len > 0; --len) {
        *d8++ = ~*s8++;
    }
}

// __CGImageMaskConvertToWICAlphaBitmap converts a 1, 2, 4, or 8-bpp grayscale "mask" into an alpha-only image for a D2D opacity brush.
// On the reference platform, mask images are grayscale images whose pixel values signify the pixel's alpha transmissivity.
// A fully black region (S = 0.0) is translated to a fully opaque region (A = 1.0).
// A fully white region (S = 1.0), on the other hand, becomes a fully transparent region (A = 0.0).
// Values that fall within the range (0.0, 1.0) are converted into complementary alpha values (A = 1.0 - S).
//
// Conversion of 8bpp grayscale images is simple: Subtract the pixel's value from 255 and use the result as the alpha value.
// Images of other bit depths have their pixels scaled to values between 0 and 255.
static HRESULT __CGImageMaskConvertToWICAlphaBitmap(CGImageRef image, IWICBitmap** pAlphaBitmap) {
    RETURN_HR_IF_NULL(E_INVALIDARG, image);
    RETURN_HR_IF_NULL(E_POINTER, pAlphaBitmap);

    RETURN_HR_IF(E_INVALIDARG, !CGImageIsMask(image));

    ComPtr<IWICImagingFactory> imagingFactory;
    RETURN_IF_FAILED(_CGGetWICFactory(&imagingFactory));

    woc::unique_cf<CGImageRef> gray8Bitmap{ _CGImageCreateCopyWithPixelFormat(image, GUID_WICPixelFormat8bppGray) };
    RETURN_HR_IF_NULL(E_INVALIDARG, gray8Bitmap);

    ComPtr<IWICBitmap> gray8Source;
    RETURN_IF_FAILED(_CGImageGetWICImageSource(gray8Bitmap.get(), &gray8Source));

    unsigned int w = 0, h = 0;
    RETURN_IF_FAILED(gray8Source->GetSize(&w, &h));

    ComPtr<IWICBitmapLock> gray8Lock;
    RETURN_IF_FAILED(gray8Source->Lock(nullptr, WICBitmapLockRead, &gray8Lock));

    unsigned char* gray8Data;
    size_t gray8Len, gray8Stride;
    RETURN_IF_FAILED(gray8Lock->GetStride(&gray8Stride));
    RETURN_IF_FAILED(gray8Lock->GetDataPointer(&gray8Len, &gray8Data));

    ComPtr<IWICBitmap> alphaBitmap;
    RETURN_IF_FAILED(imagingFactory->CreateBitmap(w, h, GUID_WICPixelFormat8bppAlpha, WICBitmapCacheOnDemand, &alphaBitmap));

    ComPtr<IWICBitmapLock> alpha8Lock;
    RETURN_IF_FAILED(alphaBitmap->Lock(nullptr, WICBitmapLockWrite, &alpha8Lock));

    unsigned char* alpha8Data;
    size_t alpha8Len, alpha8Stride;
    RETURN_IF_FAILED(alpha8Lock->GetStride(&alpha8Stride));
    RETURN_IF_FAILED(alpha8Lock->GetDataPointer(&alpha8Len, &alpha8Data));

    RETURN_HR_IF(E_UNEXPECTED, alpha8Len < gray8Len || alpha8Stride < gray8Stride);

    if (alpha8Len == gray8Len && alpha8Stride == gray8Stride) {
        __InvertMemcpy(alpha8Data, gray8Data, gray8Len);
    } else {
        // stride or length (likely both) differ
        uint8_t* destEnd = alpha8Data + alpha8Len;
        for (uint8_t *src = gray8Data, *dest = alpha8Data; dest < destEnd; src += gray8Stride, dest += alpha8Stride) {
            __InvertMemcpy(dest, src, gray8Stride);
        }
    }

    *pAlphaBitmap = alphaBitmap.Detach();
    return S_OK;
}

HRESULT _CGImageConvertToMaskCompatibleWICBitmap(CGImageRef image, IWICBitmap** pBitmap) {
    RETURN_HR_IF_NULL(E_INVALIDARG, image);
    RETURN_HR_IF_NULL(E_POINTER, pBitmap);

    if (CGImageIsMask(image)) {
        // Hard way: Convert the image's gray values to alpha values A where G = <pixel gray value>; A = (1 - G)
        // We can perhaps take the easy way out and create an A8 only image, since D2D supports them.

        // We can safely assume the image is already in Gray, so its pixels will be 1, 2, 4, or 8bpp grayscale.
        // Upconvert to 8bpp grayscale to simplify the code here. If it's bad perf-wise we can break it down.
        return __CGImageMaskConvertToWICAlphaBitmap(image, pBitmap);
    }

    // "Easy" way: Convert the image to an acceptable D2D pixel format (if necessary) and turn it into a D2D bitmap.
    WICPixelFormatGUID imagePixelFormat = _CGImageGetWICPixelFormat(image);

    woc::unique_cf<CGImageRef> convertedImage{ CGImageRetain(image) };
    if (!_CGIsValidRenderTargetPixelFormat(imagePixelFormat)) {
        // convert it to a valid pixelformat
        convertedImage.reset(_CGImageCreateCopyWithPixelFormat(image, GUID_WICPixelFormat32bppPRGBA));
    }

    return _CGImageGetWICImageSource(convertedImage.get(), pBitmap);
}

/**
* Creates an image from file, if the image is not in the requested format, it is converted to
* the requested format and returned.
*/
CGImageRef _CGImageCreateFromFileWithWICFormat(CFStringRef filename, WICPixelFormatGUID format) {
    RETURN_NULL_IF(!filename);

    woc::StrongCF<CFURLRef> url{ woc::MakeStrongCF(CFURLCreateWithFileSystemPath(nullptr, filename, kCFURLWindowsPathStyle, NO)) };
    woc::StrongCF<CGDataProviderRef> provider{ woc::MakeStrongCF(CGDataProviderCreateWithURL(url)) };

    woc::StrongCF<CGImageRef> image{ woc::MakeStrongCF(_CGImageCreateFromDataProvider(provider)) };

    return _CGImageCreateCopyWithPixelFormat(image, format);
}

#pragma endregion WIC_HELPERS
