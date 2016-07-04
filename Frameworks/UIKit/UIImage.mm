//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#include <StubReturn.h>
#include <math.h>
#import <StubReturn.h>
#include "Starboard.h"

#include "CGImageInternal.h"
#include "CGContextInternal.h"
#include "CoreGraphics/CGGeometry.h"

#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSBundle.h"

#include "UIKit/UIImage.h"
#include "UIImageCachedObject.h"
#include "CALayerInternal.h"
#include "CACompositor.h"

#include "windows.h"
#include "COMIncludes.h"
#include "Wincodec.h"
#include "COMIncludes_End.h"

#include "LoggingNative.h"

@interface UIImage ()
- (CGRect)_imageStretch;
@end

static const wchar_t* TAG = L"UIImage";

CFMutableDictionaryRef g_imageCache;
pthread_mutex_t imageCacheLock = PTHREAD_MUTEX_INITIALIZER;

/**
 @Status Interoperable
*/
void UIImageSetLayerContents(CALayer* layer, UIImage* image) {
    CGImageRef cgImage = (CGImageRef)[image CGImage];
    CGImageRef curImage = (CGImageRef)[layer contents];

    if (cgImage != curImage) {
        [layer setContents:(id)cgImage];
    }
    if ([layer contentsScale] != [image scale]) {
        [layer setContentsScale:[image scale]];
    }
    if ([layer contentsOrientation] != [image imageOrientation]) {
        [layer setContentsOrientation:[image imageOrientation]];
    }
    CGRect stretch = [image _imageStretch];
    if (!CGRectEqualToRect([layer contentsCenter], stretch)) {
        [layer setContentsCenter:stretch];
    }
}

@implementation UIImage {
    CGImageRef m_pImage;
    id _cacheName;
    idretain _cacheImage;
    CGRect _imageStretch;
    UIEdgeInsets _imageInsets;
    float _scale;
    UIImageOrientation _orientation;
    bool _isFromCache;
    uint8_t* out;
    uint8_t** row_pointers;
    StrongId<NSData> _deferredImageData;
}

/**
 @Status Stub
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

+ (UIImageCachedObject*)cacheImage:(UIImage*)image withName:(NSString*)name {
    //  Cache the image
    UIImageCachedObject* obj = [UIImageCachedObject new];
    obj->_scale = image->_scale;
    obj->_imageStretch = image->_imageStretch;
    obj->m_pImage = image->m_pImage;
    CGImageRetain(obj->m_pImage);
    obj->_cacheName = [name copy];
    pthread_mutex_lock(&imageCacheLock);
    [(id)g_imageCache setObject:(id)obj forKey:obj->_cacheName];
    pthread_mutex_unlock(&imageCacheLock);

    return [obj autorelease];
}

/**
 @Status Interoperable
*/
+ (UIImage*)imageNamed:(NSString*)pathAddr {
    return [self applicationImageNamed:pathAddr];
}

+ (UIImage*)applicationImageNamed:(NSString*)pathAddr {
    UIImage* ret = [UIImage alloc];
    UIImage* found = [ret initWithContentsOfFile:pathAddr];

    if (found == nil) {
        NSData* loadPackagedImage(NSString * name);
        NSData* fileData = loadPackagedImage(pathAddr);
        float scale = 1.f;
        if (strstr([pathAddr UTF8String], "@2x") != NULL)
            scale = 2.0f;
        if (fileData) {
            found = [ret initWithData:fileData scale:scale];
            if (found) {
                found->_cacheImage = [UIImage cacheImage:ret withName:pathAddr];
            }
        }
    }

    if (found == nil) {
        [ret release];
        return nil;
    }

    //  Application images should stay in the cache
    if (ret->_isFromCache) {
        [ret autorelease];
    }

    return ret;
}

/**
 @Status Interoperable
*/
+ (UIImage*)imageWithContentsOfFile:(id)pathAddr {
    return [[[self alloc] initWithContentsOfFile:pathAddr] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCGImage:(CGImageRef)image {
    CFRetain((id)image);
    m_pImage = image;
    _scale = 1.0f;

    _imageStretch.origin.x = 0.0f;
    _imageStretch.origin.y = 0.0f;
    _imageStretch.size.width = 1.0f;
    _imageStretch.size.height = 1.0f;

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCGImage:(CGImageRef)image scale:(float)scale orientation:(UIImageOrientation)orientation {
    CFRetain((id)image);
    m_pImage = image;
    _scale = scale;
    _orientation = orientation;

    _imageStretch.origin.x = 0.0f;
    _imageStretch.origin.y = 0.0f;
    _imageStretch.size.width = 1.0f;
    _imageStretch.size.height = 1.0f;

    return self;
}

/**
 @Status Interoperable
*/
+ (id)imageWithCGImage:(CGImageRef)image {
    return [[[self alloc] initWithCGImage:image] autorelease];
}

/**
 @Status Interoperable
*/
+ (id)imageWithCGImage:(CGImageRef)image scale:(float)scaleFactor orientation:(UIImageOrientation)orientation {
    return [[[self alloc] initWithCGImage:image scale:scaleFactor orientation:orientation] autorelease];
}

static bool loadImageFromWICFrame(UIImage* dest, IWICImagingFactory* pFactory, IWICBitmapFrameDecode* pFrame) {
    bool ret = false;
    IWICFormatConverter* pFormatConverter = NULL;
    UINT width = 0, height = 0;
    HRESULT hr = S_OK;

    hr = pFrame->GetSize(&width, &height);

    if (SUCCEEDED(hr)) {
        CGColorSpaceRef clrRgb = CGColorSpaceCreateDeviceRGB();
        dest->m_pImage =
            CGImageCreate(width, height, 8, 32, width * 4, clrRgb, kCGImageAlphaLast, nil, NULL, false, kCGRenderingIntentDefault);
        CGColorSpaceRelease(clrRgb);

        hr = pFactory->CreateFormatConverter(&pFormatConverter);
        if (SUCCEEDED(hr)) {
            hr = pFormatConverter
                     ->Initialize(pFrame, GUID_WICPixelFormat32bppRGB, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeCustom);
            if (SUCCEEDED(hr)) {
                BYTE* imageData = (BYTE*)dest->m_pImage->Backing()->LockImageData();
                hr = pFormatConverter->CopyPixels(NULL,
                                                  dest->m_pImage->Backing()->BytesPerRow(),
                                                  dest->m_pImage->Backing()->BytesPerRow() * dest->m_pImage->Backing()->Height(),
                                                  imageData);
                dest->m_pImage->Backing()->ReleaseImageData();

                if (SUCCEEDED(hr)) {
                    ret = true;
                } else {
                    TraceError(TAG, L"IWICFormatConverter::CopyPixels failed hr=%x", hr);
                    ret = false;
                }
            } else {
                TraceError(TAG, L"IWICFormatConverter::Initialize failed hr=%x", hr);
                ret = false;
            }
        } else {
            TraceError(TAG, L"IWICImagingFactory::CreateFormatConverter failed hr=%x", hr);
            ret = false;
        }
    } else {
        TraceError(TAG, L"IWICBitmapDecoder::GetFrame failed hr=%x", hr);
        ret = false;
    }

    if (pFormatConverter) {
        pFormatConverter->Release();
    }

    return ret;
}

static bool loadImageWithWICDecoder(UIImage* dest, REFGUID decoderCls, void* bytes, int length) {
    IWICImagingFactory* pFactory = NULL;
    IWICBitmapDecoder* pDecoder = NULL;
    IStream* spStream = NULL;
    IWICBitmapFrameDecode* pFrame = NULL;
    HRESULT hr = S_OK;

    MULTI_QI mq = { 0 };

    mq.pIID = &IID_IWICImagingFactory;
    hr = CoCreateInstanceFromApp(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, NULL, 1, &mq);

    if (SUCCEEDED(hr)) {
        pFactory = (IWICImagingFactory*)mq.pItf;
        hr = pFactory->CreateDecoder(decoderCls, NULL, &pDecoder);
    }

    if (SUCCEEDED(hr)) {
        hr = ::CreateStreamOnHGlobal(NULL, FALSE, &spStream);
        if (SUCCEEDED(hr)) {
            ULONG written = 0;
            hr = spStream->Write(bytes, length, &written);
            if (SUCCEEDED(hr) && written == length) {
                hr = pDecoder->Initialize(spStream, WICDecodeMetadataCacheOnLoad);

                if (SUCCEEDED(hr)) {
                    hr = pDecoder->GetFrame(0, &pFrame);
                    if (SUCCEEDED(hr)) {
                        if (!loadImageFromWICFrame(dest, pFactory, pFrame)) {
                            TraceError(TAG, L"loadImageFromWICFrame failed");
                            hr = E_FAIL;
                        }
                    } else {
                        TraceError(TAG, L"IWICBitmapDecoder::GetFrame failed hr=%x", hr);
                    }
                } else {
                    TraceError(TAG, L"IWICBitmapDecoder::Initialize failed hr=%x", hr);
                }
            } else {
                TraceError(TAG, L"IStream::Write failed hr=%x len=%d written=%d", hr, length, written);
            }
        } else {
            TraceError(TAG, L"CreateStreamOnHGlobal failed hr=%x", hr);
        }
    }

    if (pFactory) {
        pFactory->Release();
    }

    if (pDecoder) {
        pDecoder->Release();
    }

    if (spStream) {
        spStream->Release();
    }

    if (pFrame) {
        pFrame->Release();
    }

    return SUCCEEDED(hr);
}

static bool loadGIF(UIImage* dest, void* bytes, int length) {
    return loadImageWithWICDecoder(dest, GUID_ContainerFormatGif, bytes, length);
}

static bool loadBMP(UIImage* dest, void* bytes, size_t length) {
    return loadImageWithWICDecoder(dest, GUID_ContainerFormatBmp, bytes, length);
}

static bool loadTIFF(UIImage* dest, void* bytes, int length) {
    return loadImageWithWICDecoder(dest, GUID_ContainerFormatTiff, bytes, length);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithContentsOfFile:(NSString*)pathAddr {
    if (pathAddr == nil) {
        return nil;
    }

    _scale = 1.0f;
    _imageStretch.origin.x = 0.0f;
    _imageStretch.origin.y = 0.0f;
    _imageStretch.size.width = 1.0f;
    _imageStretch.size.height = 1.0f;

    NSBundle* bundle = [NSBundle mainBundle];

    const char* path = (char*)[pathAddr UTF8String];
    bool found = false;
    char* pathStr = NULL;

    if (strlen(path) == 0) {
        TraceVerbose(TAG, L"UIImage: path is blank");
        return nil;
    }

    if (strrchr(path, '.') != NULL && GetCACompositor()->screenScale() > 1.5f) {
        size_t newStrSize = strlen(path) + 10;
        char* newStr = (char*)IwMalloc(newStrSize);
        const char* pathEnd = strrchr(path, '.');
        memcpy(newStr, path, pathEnd - path);
        newStr[pathEnd - path] = 0;
        strcat_s(newStr, newStrSize, "@2x");
        strcat_s(newStr, newStrSize, pathEnd);

        pathStr = IwStrDup(newStr);

        if (EbrAccess(pathStr, 0) == -1) {
            id pathFind =
                [bundle pathForResource:[NSString stringWithCString:newStr] ofType:@"png" inDirectory:nil forLocalization:@"English"];

            if (pathFind != nil) {
                path = (char*)[pathFind UTF8String];
                if (pathStr)
                    IwFree(pathStr);
                pathStr = IwStrDup(path);
                found = true;
            }
        } else {
            found = true;
        }
        IwFree(newStr);
    }

    if (!found) {
        if (pathStr)
            IwFree(pathStr);
        pathStr = IwStrDup(path);

        if (EbrAccess(pathStr, 0) == -1) {
            NSString* pathFind = [bundle pathForResource:pathAddr ofType:@"png" inDirectory:nil forLocalization:@"English"];

            if (pathFind != nil) {
                path = [pathFind UTF8String];
                if (pathStr)
                    IwFree(pathStr);
                pathStr = IwStrDup(path);
            }
        }
    }
    if (!found && GetCACompositor()->screenScale() > 1.5f) {
        NSString* _2x = [pathAddr stringByAppendingString:@"@2x"];

        NSString* pathFind = [bundle pathForResource:_2x ofType:@"png" inDirectory:nil forLocalization:@"English"];

        if (pathFind != nil) {
            path = [pathFind UTF8String];
            if (pathStr)
                IwFree(pathStr);
            pathStr = IwStrDup(path);
            found = true;
        } else {
            pathFind = [bundle pathForResource:pathAddr ofType:@"png" inDirectory:nil forLocalization:@"English"];

            if (pathFind != nil) {
                path = [pathFind UTF8String];
                if (pathStr)
                    IwFree(pathStr);
                pathStr = IwStrDup(path);
                found = true;
            }
        }
    }

    pthread_mutex_lock(&imageCacheLock);
    //  Check if it's already loaded
    if (g_imageCache == nil) {
        g_imageCache = CFDictionaryCreateMutable(NULL, 10, &kCFTypeDictionaryKeyCallBacks, NULL);
    }

    const UIImageCachedObject* cachedImage =
        reinterpret_cast<const UIImageCachedObject*>(CFDictionaryGetValue(g_imageCache, [NSString stringWithCString:pathStr]));

    if (cachedImage) {
        if (pathStr)
            IwFree(pathStr);
        m_pImage = cachedImage->m_pImage;
        _cacheImage = cachedImage;
        CFRetain((id)m_pImage);
        _scale = cachedImage->_scale;
        _imageStretch = cachedImage->_imageStretch;
        _isFromCache = true;
        pthread_mutex_unlock(&imageCacheLock);
        return self;
    }
    pthread_mutex_unlock(&imageCacheLock);

    EbrFile* fpIn;
    BYTE in[8] = { 0 };

    fpIn = EbrFopen(pathStr, "rb");
    if (!fpIn) {
        TraceVerbose(TAG, L"Image %hs not found", pathStr);
        // m_pImage = new CGBitmapImage(64, 64, __CGSurfaceFormat::_ColorABGR, NULL);
        return nil;
    }

    EbrFread(in, 1, 8, fpIn);

    EbrFclose(fpIn);

    if (in[0] == 0x89 && in[1] == 'P' && in[2] == 'N' && in[3] == 'G') {
        m_pImage = CGPNGImageCreateFromFile([NSString stringWithCString:pathStr]);
    } else if ((in[0] == 0xFF && in[1] == 0xD8) || (in[0] == 0xD8 && in[1] == 0xFF)) {
        m_pImage = CGJPEGImageCreateFromFile([NSString stringWithCString:pathStr]);
        if (((CGJPEGImageBacking*)m_pImage->Backing()) && ((CGJPEGImageBacking*)m_pImage->Backing())->_orientation) {
            [self setOrientation:((CGJPEGImageBacking*)m_pImage->Backing())->_orientation];
        }
    } else {
        EbrFile* fpIn;

        fpIn = EbrFopen(pathStr, "rb");
        if (!fpIn) {
            TraceVerbose(TAG, L"Image %hs not found", pathStr);
            // m_pImage = new CGBitmapImage(64, 64, __CGSurfaceFormat::_ColorABGR, NULL);
            return nil;
        }

        EbrFseek(fpIn, 0, SEEK_END);
        int len = EbrFtell(fpIn);
        if (len <= 0) {
            TraceVerbose(TAG, L"Image %hs invalid", pathStr);
            // m_pImage = new CGBitmapImage(64, 64, __CGSurfaceFormat::_ColorABGR, NULL);
            EbrFclose(fpIn);
            return nil;
        }
        EbrFseek(fpIn, 0, SEEK_SET);

        auto inBuffer = std::make_unique<char[]>(len);
        len = EbrFread(inBuffer.get(), 1, len, fpIn);

        EbrFclose(fpIn);

        if (!loadTIFF(self, inBuffer.get(), len)) {
            if (!loadGIF(self, inBuffer.get(), len)) {
                if (!loadBMP(self, inBuffer.get(), len)) {
                    TraceVerbose(TAG, L"Unrecognized image");
                    for (int i = 0; i < MIN(len, 64); i++) {
                        TraceVerbose(TAG, L"%02x ", inBuffer[i]);
                        if ((i + 1) % 16 == 0)
                            TraceVerbose(TAG, L"");
                    }
                    TraceVerbose(TAG, L"Image type %hs not recognized header=%x", pathStr, *((DWORD*)in));
                    // m_pImage = new CGBitmapImage(64, 64, __CGSurfaceFormat::_ColorABGR, NULL);
                    return nil;
                }
            }
        }
    }

    if (strstr(pathStr, "@2x") != NULL) {
        _scale = 2.0f;
    }

    _imageStretch.origin.x = 0.0f;
    _imageStretch.origin.y = 0.0f;
    _imageStretch.size.width = 1.0f;
    _imageStretch.size.height = 1.0f;

    //  Cache the image
    _cacheImage = [UIImage cacheImage:self withName:[NSString stringWithCString:pathStr]];

    if (pathStr)
        IwFree(pathStr);

    return self;
}

/**
 @Status Interoperable
*/
+ (UIImage*)imageWithData:(NSData*)data {
    return [[[self alloc] initWithData:data] autorelease];
}

/**
 @Status Interoperable
*/
+ (UIImage*)imageWithData:(NSData*)data scale:(float)scale {
    return [[[self alloc] initWithData:data scale:scale] autorelease];
}

- (UIImage*)_initWithCopyOfImage:(UIImage*)imageToCopy WithRenderingMode:(UIImageRenderingMode)renderingMode {
    m_pImage = getImage(imageToCopy);
    CFRetain((id)m_pImage);
    _scale = imageToCopy->_scale;
    _orientation = imageToCopy->_orientation;
    _imageInsets = imageToCopy->_imageInsets;
    _imageStretch = imageToCopy->_imageStretch;
    _renderingMode = renderingMode;
    return self;
}

/**
 @Status Caveat
 @Notes Ignores the UIImageRenderingMode passed in and will always be treated as the orginal ignoring the template.
*/
- (UIImage*)imageWithRenderingMode:(UIImageRenderingMode)renderingMode {
    return [[[UIImage alloc] _initWithCopyOfImage:self WithRenderingMode:renderingMode] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithData:(NSData*)data {
    return [self initWithData:data scale:1.0];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithData:(NSData*)data scale:(float)scale {
    if (data == nil) {
        TraceVerbose(TAG, L"UIImage: imageWithData, data=nil!");
        return nil;
    }

    unsigned char* in = (unsigned char*)[data bytes];
    _scale = scale;
    _imageStretch.origin.x = 0.0f;
    _imageStretch.origin.y = 0.0f;
    _imageStretch.size.width = 1.0f;
    _imageStretch.size.height = 1.0f;

    if ([data length] == 0)
        return nil;

    // Early out on some file formats so we don't get silly error messages from trying
    // everything:

    bool loaded = false;

    if ((in[0] == 0xFF && in[1] == 0xD8) || (in[0] == 0xD8 && in[1] == 0xFF)) {
        m_pImage = CGJPEGImageCreateFromData(data);
        if (((CGJPEGImageBacking*)m_pImage->Backing()) && ((CGJPEGImageBacking*)m_pImage->Backing())->_orientation) {
            [self setOrientation:((CGJPEGImageBacking*)m_pImage->Backing())->_orientation];
        }
        loaded = true;
    }

    if (in[0] == 0x89 && in[1] == 'P' && in[2] == 'N' && in[3] == 'G') {
        m_pImage = CGPNGImageCreateFromData(data);
        loaded = true;
    }

    if (in[0] == 'G' && in[1] == 'I' && in[2] == 'F') {
        loaded = true;
    }

    if ((in[0] == 'I' && in[1] == 'I') || (in[0] == 'M' && in[1] == 'M')) {
        loaded = true;
    }

    if (in[0] == 'B' && in[1] == 'M') {
        loaded = true;
    }

    // Fall back on the less common cases:
    if (!loaded) {
        TraceVerbose(TAG, L"Unrecognized image");
        for (int i = 0; i < 64; i++) {
            TraceVerbose(TAG, L"%02x ", in[i]);
            if ((i + 1) % 16 == 0)
                TraceVerbose(TAG, L"");
        }
        return nil;
    }

    if (!m_pImage) {
        _deferredImageData.attach([data copy]);
    }

    return self;
}

- (void)draw1PartImageInRect:(CGRect)pos {
    TraceVerbose(TAG, L"UIImage::draw1PartImageInRect");

    CGContextRef cur = UIGraphicsGetCurrentContext();

    CGRect srcRect;

    srcRect.origin.x = 0;
    srcRect.origin.y = float(getImage(self)->Backing()->Height());
    srcRect.size.width = pos.size.width;
    srcRect.size.height = -pos.size.height;

    CGContextDrawImageRect(cur, getImage(self), srcRect, pos);
}

/**
 @Status Interoperable
*/
- (void)drawAtPoint:(CGPoint)point {
    [self drawAtPoint:point blendMode:kCGBlendModeNormal alpha:1.0f];
}

/**
 @Status Interoperable
*/
- (void)drawAtPoint:(CGPoint)point blendMode:(CGBlendMode)mode alpha:(float)alpha {
    CGContextRef cur = UIGraphicsGetCurrentContext();
    CGImageRef img = getImage(self);

    if (!cur) {
        TraceVerbose(TAG, L"CGContext = NULL!");
        return;
    }

    if (!img) {
        TraceVerbose(TAG, L"m_pImage = NULL!");
        return;
    }

    CGContextSaveGState(cur);

    CGContextSetBlendMode(cur, mode);
    CGContextSetAlpha(cur, alpha);

    CGImageBacking* imgBacking = img->Backing();

    CGRect srcRect;
    CGRect pos;
    pos.origin = point;
    pos.size.width = ((float)imgBacking->Width() / _scale);
    pos.size.height = ((float)imgBacking->Height() / _scale);

    srcRect.origin.x = 0;
    srcRect.origin.y = float(imgBacking->Height());
    srcRect.size.width = float(imgBacking->Width());
    srcRect.size.height = -((float)imgBacking->Height());

    CGContextDrawImageRect(cur, img, srcRect, pos);

    CGContextRestoreGState(cur);
}

/**
 @Status Interoperable
*/
- (void)drawAsPatternInRect:(CGRect)pos {
    [self drawAtPoint:pos.origin];
}

static inline void drawPatches(CGContextRef context, UIImage* img, CGRect* dst) {
    // Note: Subdivides image into 1-9 patches which are drawn individually and the number of
    // subdivisions depends on what insets have been set.

    // Note: Since source image has a TL origin (UIKit) and destination image has BL origin (QuartzCore) by default and there may be a
    // custom transform applied to the GFX context, we need to at the very least ensure images are sampledFrom and writtenTo the right
    // location for each pixel.
    // Thus, the patch rects are constructed according to their default origin and the sign of the rect height indicates the sampling Y
    // direction
    // relative to its the origin. Any custom transforms applied to the GFX context are handled in the underlying draw function.

    CGImageRef cgImg = getImage(img);
    CGImageBacking* imgBacking = cgImg->Backing();

    const float srcHeight = static_cast<float>(imgBacking->Height());
    const float srcWidth = static_cast<float>(imgBacking->Width());
    const float srcTopCap = img->_imageInsets.top * img->_scale;
    const float srcBotCap = img->_imageInsets.bottom * img->_scale;
    const float srcLeftCap = img->_imageInsets.left * img->_scale;
    const float srcRightCap = img->_imageInsets.right * img->_scale;

    const float dstHeight = dst->size.height;
    const float dstWidth = dst->size.width;
    const float dstX = dst->origin.x;
    const float dstY = dst->origin.y;
    const float dstTopCap = img->_imageInsets.top;
    const float dstBotCap = img->_imageInsets.bottom;
    const float dstLeftCap = img->_imageInsets.left;
    const float dstRightCap = img->_imageInsets.right;

    // Center strip
    if (dstHeight - dstTopCap - dstBotCap > 0) {
        if (dstLeftCap) {
            // MidHeightLeft
            CGContextDrawImageRect(context,
                                   cgImg,
                                   CGRectMake(0, srcHeight - srcBotCap, srcLeftCap, -(srcHeight - srcTopCap - srcBotCap)),
                                   CGRectMake(dstX, (dstY + dstBotCap), dstLeftCap, (dstHeight - dstTopCap - dstBotCap)));
        }

        if (dstWidth - dstLeftCap - dstRightCap > 0) {
            // MidHeightMidWidth
            CGContextDrawImageRect(context,
                                   cgImg,
                                   CGRectMake(srcLeftCap,
                                              srcHeight - srcBotCap,
                                              (srcWidth - srcLeftCap - srcRightCap),
                                              -(srcHeight - srcTopCap - srcBotCap)),
                                   CGRectMake((dstX + dstLeftCap),
                                              (dstY + dstBotCap),
                                              (dstWidth - dstLeftCap - dstRightCap),
                                              (dstHeight - dstTopCap - dstBotCap)));
        } else {
            UNIMPLEMENTED_WITH_MSG(
                "Patched draws only supported when sum of dstLeftCap and dstRightCap is less than the width of the UI element.");
        }

        if (dstRightCap) {
            // MidHeightRight
            CGContextDrawImageRect(
                context,
                cgImg,
                CGRectMake((srcWidth - srcRightCap), srcHeight - srcBotCap, srcRightCap, -(srcHeight - srcTopCap - srcBotCap)),
                CGRectMake((dstX + dstWidth - dstRightCap), (dstY + dstBotCap), dstRightCap, (dstHeight - dstTopCap - dstBotCap)));
        }
    } else {
        UNIMPLEMENTED_WITH_MSG(
            "Patched draws only supported when sum of dstTopCap and dstBotCap is less than the height of the UI element.");
    }

    if (dstTopCap) {
        if (dstLeftCap) {
            // TL corner
            CGContextDrawImageRect(context,
                                   cgImg,
                                   CGRectMake(0, srcTopCap, srcLeftCap, -srcTopCap),
                                   CGRectMake(dstX, (dstY + dstHeight - dstTopCap), dstLeftCap, dstTopCap));
        }

        if (dstWidth - dstLeftCap - dstRightCap > 0) {
            // TCenter
            CGContextDrawImageRect(context,
                                   cgImg,
                                   CGRectMake(srcLeftCap, srcTopCap, (srcWidth - srcLeftCap - srcRightCap), -srcTopCap),
                                   CGRectMake((dstX + dstLeftCap),
                                              (dstY + dstHeight - dstTopCap),
                                              (dstWidth - dstLeftCap - dstRightCap),
                                              dstTopCap));
        }

        if (dstRightCap) {
            // TR corner
            CGContextDrawImageRect(context,
                                   cgImg,
                                   CGRectMake((srcWidth - srcRightCap), srcTopCap, srcRightCap, -srcTopCap),
                                   CGRectMake((dstX + dstWidth - dstRightCap), (dstY + dstHeight - dstTopCap), dstRightCap, dstTopCap));
        }
    }

    if (dstBotCap) {
        if (dstLeftCap) {
            // BL Corner
            CGContextDrawImageRect(context,
                                   cgImg,
                                   CGRectMake(0, srcHeight, srcLeftCap, -srcBotCap),
                                   CGRectMake(dstX, dstY, dstLeftCap, dstBotCap));
        }

        if (dstWidth - dstLeftCap - dstRightCap > 0) {
            // bottomMidWidth
            CGContextDrawImageRect(context,
                                   cgImg,
                                   CGRectMake(srcLeftCap, srcHeight, (srcWidth - srcLeftCap - srcRightCap), -srcBotCap),
                                   CGRectMake((dstX + dstLeftCap), dstY, (dstWidth - dstLeftCap - dstRightCap), dstBotCap));
        }

        if (dstRightCap) {
            CGContextDrawImageRect(context,
                                   cgImg,
                                   CGRectMake((srcWidth - srcRightCap), srcHeight, srcRightCap, -srcBotCap),
                                   CGRectMake((dstX + dstWidth - dstRightCap), dstY, dstRightCap, dstBotCap));
        }
    }
}

/**
 @Status Interoperable
*/
- (void)drawInRect:(CGRect)pos {
    [self drawInRect:pos blendMode:kCGBlendModeNormal alpha:1.0f];
}

/**
 @Status Interoperable
*/
- (void)drawInRect:(CGRect)pos blendMode:(CGBlendMode)mode alpha:(float)alpha {
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGImageRef img = getImage(self);

    if (img == NULL) {
        TraceWarning(TAG, L"m_pImage = NULL!");
        return;
    }

    if (_scale == 0.0f) {
        TraceWarning(TAG, L"Scale should be non-zero!");
        return;
    }

    CGContextSaveGState(ctx);

    CGContextSetBlendMode(ctx, mode);
    CGContextSetAlpha(ctx, alpha);

    // Draw image and divide into patches if necessary
    drawPatches(ctx, self, &pos);

    CGContextRestoreGState(ctx);
}

- (void)setOrientation:(UIImageOrientation)orientation {
    _orientation = orientation;
}

/**
 @Status Interoperable
*/
- (CGSize)size {
    CGSize size;

    if (getImage(self)) {
        size.width = float(getImage(self)->Backing()->Width());
        size.height = float(getImage(self)->Backing()->Height());

        if (_scale > 0.0f) {
            size.width /= _scale;
            size.height /= _scale;
        }
    } else {
        size.width = 0;
        size.height = 0;
    }

    return size;
}

/**
 @Status Interoperable
*/
- (CGRect)_imageStretch {
    return _imageStretch;
}

- (CGImageRef)imageRef {
    return getImage(self);
}

/**
 @Status Interoperable
*/
- (CGImageRef)CGImage {
    return getImage(self);
}

/**
 @Status Interoperable
*/
- (UIImageOrientation)imageOrientation {
    return _orientation;
}

/**
 @Status Interoperable
*/
- (int)leftCapWidth {
    return (int)_imageInsets.left;
}

/**
 @Status Interoperable
*/
- (int)topCapHeight {
    return (int)_imageInsets.top;
}

/**
 @Status Interoperable
*/
- (UIImage*)stretchableImageWithLeftCapWidth:(int)leftCap topCapHeight:(int)topCap {
    UIImage* ret = [UIImage alloc];

    ret->m_pImage = getImage(self);
    CFRetain((id)ret->m_pImage);
    ret->_imageInsets.left = float(leftCap);
    ret->_imageInsets.top = float(topCap);
    ret->_scale = _scale;
    ret->_orientation = _orientation;
    ret->_imageStretch.origin.x = 0.0f;
    ret->_imageStretch.origin.y = 0.0f;
    ret->_imageStretch.size.width = 1.0f;
    ret->_imageStretch.size.height = 1.0f;

    CGSize imgSize;

    imgSize = [self size];
    if (leftCap != 0) {
        ret->_imageStretch.origin.x = leftCap / imgSize.width;
        ret->_imageStretch.size.width = 1.0f / imgSize.width;
    }
    if (topCap != 0) {
        ret->_imageStretch.origin.y = topCap / imgSize.height;
        ret->_imageStretch.size.height = 1.0f / imgSize.height;
    }

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (UIImage*)resizableImageWithCapInsets:(UIEdgeInsets)insets {
    UIImage* ret = [UIImage alloc];

    ret->m_pImage = getImage(self);
    CFRetain((id)ret->m_pImage);
    ret->_imageInsets.left = 0;
    ret->_imageInsets.top = 0;

    CGSize imgSize;

    imgSize = [self size];

    ret->_imageStretch.origin.x = insets.left / imgSize.width;
    ret->_imageStretch.origin.y = insets.top / imgSize.width;
    ret->_imageStretch.size.width = (imgSize.width - (insets.left + insets.right + 1)) / imgSize.width;
    ret->_imageStretch.size.height = (imgSize.height - (insets.top + insets.bottom + 1)) / imgSize.height;
    ret->_scale = _scale;
    ret->_orientation = _orientation;
    ret->_imageInsets = insets;

    return [ret autorelease];
}

/**
 @Status Caveat
 @Notes resizeMode not supported
*/
- (UIImage*)resizableImageWithCapInsets:(UIEdgeInsets)insets resizingMode:(unsigned)resizeMode {
    UIImage* ret = [UIImage alloc];

    ret->m_pImage = getImage(self);
    CGImageRetain(ret->m_pImage);
    ret->_imageInsets.left = 0;
    ret->_imageInsets.top = 0;
    ret->_scale = _scale;
    ret->_orientation = _orientation;
    CGSize imgSize;

    imgSize = [self size];

    ret->_imageStretch.origin.x = insets.left / imgSize.width;
    ret->_imageStretch.origin.y = insets.top / imgSize.width;
    ret->_imageStretch.size.width = (imgSize.width - (insets.left + insets.right + 1)) / imgSize.width;
    ret->_imageStretch.size.height = (imgSize.height - (insets.top + insets.bottom + 1)) / imgSize.height;

    ret->_imageInsets = insets;

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _cacheImage = nil;
    _deferredImageData = nil;

    if (m_pImage)
        CGImageRelease(m_pImage);
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (float)scale {
    return _scale;
}

- (void)_setScale:(float)scale {
    _scale = scale;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Stub
*/
- (NSArray*)images {
    UNIMPLEMENTED();
    return nil;
}

static CGImageRef getImage(UIImage* self) {
    if (!self->m_pImage && self->_deferredImageData != nil) {
        unsigned char* in = (unsigned char*)[self->_deferredImageData bytes];
        int len = [self->_deferredImageData length];

        if (in[0] == 'G' && in[1] == 'I' && in[2] == 'F') {
            if (!loadGIF(self, in, len)) {
                TraceVerbose(TAG, L"Something looked like a GIF but wasn't!");
            }
        }

        if ((in[0] == 'I' && in[1] == 'I') || (in[0] == 'M' && in[1] == 'M')) {
            if (!loadTIFF(self, in, len)) {
                TraceVerbose(TAG, L"Something looked like a TIFF but wasn't!");
            }
        }

        if (in[0] == 'B' && in[1] == 'M') {
            if (!loadBMP(self, in, len)) {
                TraceVerbose(TAG, L"Something looked like a BMP but wasn't!");
            }
        }

        self->_deferredImageData = nil;
    }

    return self->m_pImage;
}

/**
 @Status Stub
*/
- (UIImage*)imageFlippedForRightToLeftLayoutDirection {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIImage*)imageWithAlignmentRectInsets:(UIEdgeInsets)alignmentInsets {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIImage*)animatedImageNamed:(NSString*)name duration:(NSTimeInterval)duration {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIImage*)animatedImageWithImages:(NSArray*)images duration:(NSTimeInterval)duration {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIImage*)animatedResizableImageNamed:(NSString*)name capInsets:(UIEdgeInsets)capInsets duration:(NSTimeInterval)duration {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
NSData* UIImagePNGRepresentation(UIImage* img) {
    return _CGImagePNGRepresentation(img);
}

/**
 @Status Stub
*/
+ (UIImage*)animatedResizableImageNamed:(NSString*)name
                              capInsets:(UIEdgeInsets)capInsets
                           resizingMode:(UIImageResizingMode)resizingMode
                               duration:(NSTimeInterval)duration {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
NSData* UIImageJPEGRepresentation(UIImage* img, CGFloat quality) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIImage*)imageNamed:(NSString*)name inBundle:(NSBundle*)bundle compatibleWithTraitCollection:(UITraitCollection*)traitCollection {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIImage*)imageWithCIImage:(CIImage*)ciImage scale:(CGFloat)scale orientation:(UIImageOrientation)orientation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIImage*)imageWithCIImage:(CIImage*)ciImage {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
