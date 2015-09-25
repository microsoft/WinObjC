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

#include <math.h>
#include "Starboard.h"

#include "CGContextInternal.h"
#include "CoreGraphics/CGGeometry.h"

#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSBundle.h"

#include "UIKit/UIImage.h"
#include "UIImageCachedObject.h"

#include "Windows.h"
#include "COMIncludes.h"
#include "Wincodec.h"
#include "COMIncludes_End.h"

#include "BMPDecode.h"

typedef struct insetInfo {
    UIImage* img;
    CGRect size;
};

CFMutableDictionaryRef g_imageCache;
static EbrLock imageCacheLock;

void UIImageSetLayerContents(CALayer* layer, UIImage* image) {
    CGImageRef cgImage = (CGImageRef)[image CGImage];
    CGImageRef curImage = (CGImageRef)[layer contents];

    if (cgImage != curImage) {
        [layer setContents:(id)cgImage];
        [layer setContentsScale:[image scale]];
        [layer setContentsOrientation:[image imageOrientation]];

        CGRect stretch;
        stretch = [image _imageStretch];
        if (stretch.origin.x != 0.0f || stretch.size.width != 1.0f || stretch.origin.y != 0.0f ||
            stretch.size.height != 1.0f) {
            [layer setContentsCenter:stretch];
        }
    }
}

#ifdef UIIMAGE_CACHE_MANAGEMENT
class imageCacheInfo {
private:
    UIImage** _images;
    DWORD _numImages, _maxImages;
    DWORD _totalSize;

public:
    imageCacheInfo() {
        _images = NULL;
        _numImages = 0;
        _maxImages = 0;
        _totalSize = 0;
    }

    void addImage(UIImage* image) {
        if (_numImages + 1 >= _maxImages) {
            _maxImages += 64;
            _images = (UIImage**)EbrRealloc(_images, sizeof(id) * _maxImages);
        }

        _images[_numImages] = image;
        _totalSize += image->m_pImage->Backing()->Width() * image->m_pImage->Backing()->Height();
        _numImages++;
    }

    void cullCache() {
        for (int i = 0; i < _numImages; i++) {
            if (_totalSize < 16 * 1024) {
                return;
            }

            if (CFGetRetainCount(H2E(_images[i]->m_pImage)) == 1) {
                id cacheName = _images[i]->_cacheName;
                _totalSize -= _images[i]->m_pImage->Backing()->Width() * _images[i]->m_pImage->Backing()->Height();
                memmove(&_images[i], &_images[i + 1], sizeof(id) * (_numImages - i - 1));
                _numImages--;
                i--;
                [g_imageCache removeObjectForKey:cacheName];

                continue;
            }
        }
    }

    void removeImage(UIImage* image) {
        for (int i = 0; i < _numImages; i++) {
            if (_images[i] == image) {
                memmove(&_images[i], &_images[i + 1], sizeof(id) * (_numImages - i - 1));
                _totalSize -= image->m_pImage->Backing()->Width() * image->m_pImage->Backing()->Height();
                _numImages--;
                return;
            }
        }
    }
};

imageCacheInfo imageInfo;
#endif

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
    idretaintype(NSData) _deferredImageData;
}
+ (UIImageCachedObject*)cacheImage:(UIImage*)image withName:(NSString*)name {
    //  Cache the image
    UIImageCachedObject* obj = [UIImageCachedObject new];
    obj->_scale = image->_scale;
    obj->_imageStretch = image->_imageStretch;
    obj->m_pImage = image->m_pImage;
    obj->_cacheName = [name copy];
    [(id)g_imageCache setObject:(id)obj forKey:obj->_cacheName];

    return obj;
}
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
                found->_cacheImage.attach([UIImage cacheImage:ret withName:pathAddr]);
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

+ (UIImage*)imageWithContentsOfFile:(id)pathAddr {
    return [[[self alloc] initWithContentsOfFile:pathAddr] autorelease];
}

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

+ (id)imageWithCGImage:(CGImageRef)image {
    return [[[self alloc] initWithCGImage:image] autorelease];
}

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
        dest->m_pImage = CGImageCreate(
            width, height, 8, 32, width * 4, clrRgb, kCGImageAlphaFirst, nil, NULL, false, kCGRenderingIntentDefault);
        CGColorSpaceRelease(clrRgb);

        hr = pFactory->CreateFormatConverter(&pFormatConverter);
        if (SUCCEEDED(hr)) {
            hr = pFormatConverter->Initialize(
                pFrame, GUID_WICPixelFormat32bppRGB, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeCustom);
            if (SUCCEEDED(hr)) {
                BYTE* imageData = (BYTE*)dest->m_pImage->Backing()->LockImageData();
                hr = pFormatConverter->CopyPixels(NULL,
                                                  dest->m_pImage->Backing()->BytesPerRow(),
                                                  dest->m_pImage->Backing()->BytesPerRow() *
                                                      dest->m_pImage->Backing()->Height(),
                                                  imageData);
                dest->m_pImage->Backing()->ReleaseImageData();

                if (SUCCEEDED(hr)) {
                    ret = true;
                } else {
                    EbrDebugLog("IWICFormatConverter::CopyPixels failed hr=%x\n", hr);
                    ret = false;
                }
            } else {
                EbrDebugLog("IWICFormatConverter::Initialize failed hr=%x\n", hr);
                ret = false;
            }
        } else {
            EbrDebugLog("IWICImagingFactory::CreateFormatConverter failed hr=%x\n", hr);
            ret = false;
        }
    } else {
        EbrDebugLog("IWICBitmapDecoder::GetFrame failed hr=%x\n", hr);
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

    hr = CoCreateInstance(
        CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&pFactory);

    if (SUCCEEDED(hr)) {
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
                            EbrDebugLog("loadImageFromWICFrame failed\n");
                            hr = E_FAIL;
                        }
                    } else {
                        EbrDebugLog("IWICBitmapDecoder::GetFrame failed hr=%x\n", hr);
                    }
                } else {
                    EbrDebugLog("IWICBitmapDecoder::Initialize failed hr=%x\n", hr);
                }
            } else {
                EbrDebugLog("IStream::Write failed hr=%x len=%d written=%d\n", hr, length, written);
            }
        } else {
            EbrDebugLog("CreateStreamOnHGlobal failed hr=%x\n", hr);
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

- (instancetype)initWithContentsOfFile:(NSString*)pathAddr {
    if (pathAddr == nil) {
        return nil;
    }

    _scale = 1.0f;
    _imageStretch.origin.x = 0.0f;
    _imageStretch.origin.y = 0.0f;
    _imageStretch.size.width = 1.0f;
    _imageStretch.size.height = 1.0f;

#ifdef UIIMAGE_CACHE_MANAGEMENT
    imageInfo.cullCache();
#endif

    NSBundle* bundle = [NSBundle mainBundle];

    const char* path = (char*)[pathAddr UTF8String];
    bool found = false;
    char* pathStr = NULL;

    if (strlen(path) == 0) {
        EbrDebugLog("UIImage: path is blank\n");
        return nil;
    }

    if (strrchr(path, '.') != NULL && GetCACompositor()->screenScale() > 1.5f) {
        char* newStr = (char*)malloc(strlen(path) + 10);
        const char* pathEnd = strrchr(path, '.');
        memcpy(newStr, path, pathEnd - path);
        newStr[pathEnd - path] = 0;
        strcat(newStr, "@2x");
        strcat(newStr, pathEnd);

        pathStr = _strdup(newStr);

        if (EbrAccess(pathStr, 0) == -1) {
            id pathFind = [bundle pathForResource:[NSString stringWithCString:newStr]
                                           ofType:nil
                                      inDirectory:nil
                                  forLocalization:@"English"];

            if (pathFind != nil) {
                path = (char*)[pathFind UTF8String];
                if (pathStr)
                    free(pathStr);
                pathStr = _strdup(path);
                found = true;
            }
        } else {
            found = true;
        }
        free(newStr);
    }

    if (!found) {
        if (pathStr)
            free(pathStr);
        pathStr = _strdup(path);

        if (EbrAccess(pathStr, 0) == -1) {
            NSString* pathFind =
                [bundle pathForResource:pathAddr ofType:nil inDirectory:nil forLocalization:@"English"];

            if (pathFind != nil) {
                path = [pathFind UTF8String];
                if (pathStr)
                    free(pathStr);
                pathStr = _strdup(path);
            }
        }
    }
    if (!found && GetCACompositor()->screenScale() > 1.5f) {
        NSString* _2x = [pathAddr stringByAppendingString:@"@2x"];

        NSString* pathFind = [bundle pathForResource:_2x ofType:@"png" inDirectory:nil forLocalization:@"English"];

        if (pathFind != nil) {
            path = [pathFind UTF8String];
            if (pathStr)
                free(pathStr);
            pathStr = _strdup(path);
            found = true;
        } else {
            pathFind = [bundle pathForResource:pathAddr ofType:@"png" inDirectory:nil forLocalization:@"English"];

            if (pathFind != nil) {
                path = [pathFind UTF8String];
                if (pathStr)
                    free(pathStr);
                pathStr = _strdup(path);
                found = true;
            }
        }
    }

    //  Check if it's already loaded
    if (g_imageCache == nil) {
        g_imageCache = CFDictionaryCreateMutable(NULL, 10, &kCFTypeDictionaryKeyCallBacks, NULL);
        EbrLockInit(&imageCacheLock);
    }

    UIImageCachedObject* cachedImage = [g_imageCache objectForKey:[NSString stringWithCString:pathStr]];
    if (cachedImage != nil) {
        if (pathStr)
            free(pathStr);
        m_pImage = cachedImage->m_pImage;
        _cacheImage = cachedImage;
        CFRetain((id)m_pImage);
        _scale = cachedImage->_scale;
        _imageStretch = cachedImage->_imageStretch;
        _isFromCache = true;
        return self;
    }

    EbrFile* fpIn;
    BYTE in[8] = { 0 };

    fpIn = EbrFopen(pathStr, "rb");
    if (!fpIn) {
        EbrDebugLog("Image %s not found\n", pathStr);
        // m_pImage = new CGBitmapImage(64, 64, surfaceFormat::_ColorRGBA, NULL);
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
        char* in;

        fpIn = EbrFopen(pathStr, "rb");
        if (!fpIn) {
            EbrDebugLog("Image %s not found\n", pathStr);
            // m_pImage = new CGBitmapImage(64, 64, surfaceFormat::_ColorRGBA, NULL);
            return nil;
        }

        EbrFseek(fpIn, 0, SEEK_END);
        int len = EbrFtell(fpIn);
        if (len <= 0) {
            EbrDebugLog("Image %s invalid\n", pathStr);
            // m_pImage = new CGBitmapImage(64, 64, surfaceFormat::_ColorRGBA, NULL);
            EbrFclose(fpIn);
            return nil;
        }
        EbrFseek(fpIn, 0, SEEK_SET);

        in = (char*)malloc(len);
        len = EbrFread(in, 1, len, fpIn);

        EbrFclose(fpIn);

        if (!loadTIFF(self, in, len)) {
            if (!loadGIF(self, in, len)) {
                if (!loadBMP(self, in, len)) {
                    EbrDebugLog("Unrecognized image\n");
                    for (int i = 0; i < 64; i++) {
                        EbrDebugLog("%02x ", in[i]);
                        if ((i + 1) % 16 == 0)
                            EbrDebugLog("\n");
                    }
                    EbrDebugLog("Image type %s not recognized header=%x\n", pathStr, *((DWORD*)in));
                    // m_pImage = new CGBitmapImage(64, 64, surfaceFormat::_ColorRGBA, NULL);
                    return nil;
                }
            }
        }

        free(in);
    }

    if (strstr(pathStr, "@2x") != NULL) {
        _scale = 2.0f;
    }

    _imageStretch.origin.x = 0.0f;
    _imageStretch.origin.y = 0.0f;
    _imageStretch.size.width = 1.0f;
    _imageStretch.size.height = 1.0f;

    //  Cache the image
    _cacheImage.attach([UIImage cacheImage:self withName:[NSString stringWithCString:pathStr]]);

    if (pathStr)
        free(pathStr);

#ifdef UIIMAGE_CACHE_MANAGEMENT
    imageInfo.addImage(self);
#endif

    return self;
}

+ (UIImage*)imageWithData:(NSData*)data {
    return [[[self alloc] initWithData:data] autorelease];
}

+ (UIImage*)imageWithData:(NSData*)data scale:(float)scale {
    return [[[self alloc] initWithData:data scale:scale] autorelease];
}

- (instancetype)initWithData:(NSData*)data {
    return [self initWithData:data scale:1.0];
}

- (instancetype)initWithData:(NSData*)data scale:(float)scale {
    if (data == nil) {
        EbrDebugLog("UIImage: imageWithData, data=nil!\n");
        return nil;
    }

#ifdef UIIMAGE_CACHE_MANAGEMENT
    id cachePath = [data _filePath];
    if (cachePath != nil) {
        UIImage* cachedImage = [g_imageCache objectForKey:cachePath];
        if (cachedImage != nil) {
            m_pImage = cachedImage->m_pImage;
            CFRetain(H2E(m_pImage));
            _scale = cachedImage->_scale;
            return self;
        }
    }

    imageInfo.cullCache();
#endif

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
        EbrDebugLog("Unrecognized image\n");
        for (int i = 0; i < 64; i++) {
            EbrDebugLog("%02x ", in[i]);
            if ((i + 1) % 16 == 0)
                EbrDebugLog("\n");
        }
        return nil;
    }

    if (!m_pImage) {
        _deferredImageData.attach([data copy]);
    }

#ifdef UIIMAGE_CACHE_MANAGEMENT
    if (cachePath != nil) {
        [g_imageCache setObject:self forKey:cachePath];
        _cacheName = [cachePath copy];
        imageInfo.addImage(self);
    }
#endif

    return self;
}

- (void)draw1PartImageInRect:(CGRect)pos {
    EbrDebugLog("UIImage::draw1PartImageInRect\n");

    CGContextRef cur = UIGraphicsGetCurrentContext();

    CGRect srcRect;

    srcRect.origin.x = 0;
    srcRect.origin.y = float(getImage(self)->Backing()->Height());
    srcRect.size.width = pos.size.width;
    srcRect.size.height = -pos.size.height;

    CGContextDrawImageRect(cur, getImage(self), srcRect, pos);
}

- (void)drawAtPoint:(CGPoint)point {
    [self drawAtPoint:CGPointMake(point.x, point.y) blendMode:kCGBlendModeNormal alpha:0.0f];
}

- (void)drawAtPoint:(CGPoint)point blendMode:(CGBlendMode)mode alpha:(float)alpha {
    CGContextRef cur = UIGraphicsGetCurrentContext();
    if (!cur) {
        EbrDebugLog("CGContext = NULL!\n");
        return;
    }
    if (!getImage(self)) {
        EbrDebugLog("m_pImage = NULL!\n");
        return;
    }

    CGContextSaveGState(cur);
    CGContextSetBlendMode(cur, mode);

    CGRect srcRect;
    CGRect pos;
    pos.origin = point;
    pos.size.width = ((float)getImage(self)->Backing()->Width() / _scale);
    pos.size.height = ((float)getImage(self)->Backing()->Height() / _scale);

    srcRect.origin.x = 0;
    srcRect.origin.y = float(getImage(self)->Backing()->Height());
    srcRect.size.width = float(getImage(self)->Backing()->Width());
    srcRect.size.height = -((float)getImage(self)->Backing()->Height());

    CGContextDrawImageRect(cur, getImage(self), srcRect, pos);

    CGContextRestoreGState(cur);
}

- (void)drawAsPatternInRect:(CGRect)pos {
    [self drawAtPoint:pos.origin];
}

static void drawNinePatchCallBack(void* info, CGContextRef context) {
    insetInfo* ii = (insetInfo*)info;
    UIImage* img = ii->img;

    if (img->_imageInsets.top) {
        CGContextDrawImageRect(
            context,
            getImage(img),
            makeRect(0,
                     getImage(img)->Backing()->Height() - img->_imageInsets.top,
                     img->_imageInsets.left,
                     img->_imageInsets.top),
            makeRect(0, ii->size.size.height - img->_imageInsets.top, img->_imageInsets.left, img->_imageInsets.top));
        if (getImage(img)->Backing()->Width() - img->_imageInsets.left - img->_imageInsets.right > 0) {
            CGContextDrawImageRect(
                context,
                getImage(img),
                makeRect(img->_imageInsets.left,
                         getImage(img)->Backing()->Height() - img->_imageInsets.top,
                         getImage(img)->Backing()->Width() - img->_imageInsets.left - img->_imageInsets.right,
                         img->_imageInsets.top),
                makeRect(img->_imageInsets.left,
                         ii->size.size.height - img->_imageInsets.top,
                         ii->size.size.width - img->_imageInsets.left - img->_imageInsets.right,
                         img->_imageInsets.top));
        }
        CGContextDrawImageRect(context,
                               getImage(img),
                               makeRect(getImage(img)->Backing()->Width() - img->_imageInsets.right,
                                        getImage(img)->Backing()->Height() - img->_imageInsets.top,
                                        img->_imageInsets.right,
                                        img->_imageInsets.top),
                               makeRect(ii->size.size.width - img->_imageInsets.right,
                                        ii->size.size.height - img->_imageInsets.top,
                                        img->_imageInsets.right,
                                        img->_imageInsets.top));
    }

    // Coordinates flipped on Y
    if (getImage(img)->Backing()->Height() - img->_imageInsets.top - img->_imageInsets.bottom > 0) {
        CGContextDrawImageRect(
            context,
            getImage(img),
            makeRect(0,
                     img->_imageInsets.bottom,
                     img->_imageInsets.left,
                     getImage(img)->Backing()->Height() - img->_imageInsets.top - img->_imageInsets.bottom),
            makeRect(0,
                     img->_imageInsets.bottom,
                     img->_imageInsets.left,
                     ii->size.size.height - img->_imageInsets.top - img->_imageInsets.bottom));
        if (getImage(img)->Backing()->Width() - img->_imageInsets.left - img->_imageInsets.right > 0) {
            CGContextDrawImageRect(
                context,
                getImage(img),
                makeRect(img->_imageInsets.left,
                         img->_imageInsets.bottom,
                         getImage(img)->Backing()->Width() - img->_imageInsets.left - img->_imageInsets.right,
                         getImage(img)->Backing()->Height() - img->_imageInsets.top - img->_imageInsets.bottom),
                makeRect(img->_imageInsets.left,
                         img->_imageInsets.bottom,
                         ii->size.size.width - img->_imageInsets.left - img->_imageInsets.right,
                         ii->size.size.height - img->_imageInsets.top - img->_imageInsets.bottom));
        } else {
            assert(0);
        }
        CGContextDrawImageRect(
            context,
            getImage(img),
            makeRect(getImage(img)->Backing()->Width() - img->_imageInsets.right,
                     img->_imageInsets.bottom,
                     img->_imageInsets.right,
                     getImage(img)->Backing()->Height() - img->_imageInsets.top - img->_imageInsets.bottom),
            makeRect(ii->size.size.width - img->_imageInsets.right,
                     img->_imageInsets.bottom,
                     img->_imageInsets.right,
                     ii->size.size.height - img->_imageInsets.top - img->_imageInsets.bottom));
    }

    if (img->_imageInsets.bottom) {
        CGContextDrawImageRect(context,
                               getImage(img),
                               makeRect(0, 0, img->_imageInsets.left, img->_imageInsets.bottom),
                               makeRect(0, 0, img->_imageInsets.left, img->_imageInsets.bottom));
        if (getImage(img)->Backing()->Width() - img->_imageInsets.left - img->_imageInsets.right > 0) {
            CGContextDrawImageRect(
                context,
                getImage(img),
                makeRect(img->_imageInsets.left,
                         0,
                         getImage(img)->Backing()->Width() - img->_imageInsets.left - img->_imageInsets.right,
                         img->_imageInsets.bottom),
                makeRect(img->_imageInsets.left,
                         0,
                         ii->size.size.width - img->_imageInsets.left - img->_imageInsets.right,
                         img->_imageInsets.bottom));
        }
        CGContextDrawImageRect(
            context,
            getImage(img),
            makeRect(getImage(img)->Backing()->Width() - img->_imageInsets.right,
                     0,
                     img->_imageInsets.right,
                     img->_imageInsets.bottom),
            makeRect(
                ii->size.size.width - img->_imageInsets.right, 0, img->_imageInsets.right, img->_imageInsets.bottom));
    }
}

static void drawLeftCap(UIImage* self, CGContextRef cur, CGRect pos) {
    CGRect srcRect;
    CGRect destRect = pos;

    srcRect.origin.x = 0;
    srcRect.origin.y = 0;
    srcRect.size.width = float(getImage(self)->Backing()->Width());
    srcRect.size.height = float(getImage(self)->Backing()->Height());

    CGRect drawRect, capRect;

    //  Draw the left cap
    drawRect.origin.x = destRect.origin.x;
    drawRect.origin.y = destRect.origin.y;
    drawRect.size.width = self->_imageInsets.left;
    drawRect.size.height = destRect.size.height;

    capRect = srcRect;
    capRect.size.width = self->_imageInsets.left * self->_scale;

    capRect.origin.y = getImage(self)->Backing()->Height() - capRect.origin.y;
    capRect.size.height = -capRect.size.height;

    float minX = drawRect.origin.x + drawRect.size.width;
    CGContextDrawImageRect(cur, getImage(self), capRect, drawRect);

    //  Draw cap fragment
    drawRect.origin.x = destRect.origin.x + self->_imageInsets.left;
    drawRect.origin.y = destRect.origin.y;
    drawRect.size.width = pos.size.width - srcRect.size.width / self->_scale;
    drawRect.size.height = destRect.size.height;

    capRect.origin.x = self->_imageInsets.left * self->_scale;
    capRect.origin.y = getImage(self)->Backing()->Height() - srcRect.origin.y;
    capRect.size.width = 1;
    capRect.size.height = -srcRect.size.height;
    if (drawRect.size.width > 0.0f) {
        CGContextDrawImageRect(cur, getImage(self), capRect, drawRect);
    }

    //  Adjust the source and desination rects
    srcRect.origin.x = self->_imageInsets.left * self->_scale;
    srcRect.size.width = getImage(self)->Backing()->Width() - self->_imageInsets.left * self->_scale;
    destRect.origin.x += pos.size.width - (srcRect.size.width / self->_scale);
    destRect.size.width = srcRect.size.width / self->_scale;

    //  Invert srcRect
    srcRect.origin.y = getImage(self)->Backing()->Height() - srcRect.origin.y;
    srcRect.size.height = -srcRect.size.height;

    if (destRect.origin.x < minX) {
        float diff = minX - destRect.origin.x;
        destRect.origin.x += diff;
        destRect.size.width -= diff;
        srcRect.origin.x += diff * self->_scale;
        srcRect.size.width -= diff * self->_scale;
    }
    if (destRect.size.width > 0.0f) {
        CGContextDrawImageRect(cur, getImage(self), srcRect, destRect);
    }
}

static void drawTopCap(UIImage* self, CGContextRef cur, CGRect pos) {
    CGRect srcRect;
    CGRect destRect = pos;

    srcRect.origin.x = 0;
    srcRect.origin.y = 0;
    srcRect.size.width = float(getImage(self)->Backing()->Width());
    srcRect.size.height = float(getImage(self)->Backing()->Height());

    CGRect drawRect, capRect;

    //  Draw the left cap
    drawRect.origin.x = destRect.origin.x;
    drawRect.origin.y = destRect.origin.y;
    drawRect.size.width = destRect.size.width;
    drawRect.size.height = self->_imageInsets.top;

    capRect = srcRect;
    capRect.size.height = self->_imageInsets.top;

    capRect.origin.y = getImage(self)->Backing()->Height() - capRect.origin.y;
    capRect.size.height = -capRect.size.height;

    CGContextDrawImageRect(cur, getImage(self), capRect, drawRect);

    //  Draw cap fragment
    drawRect.origin.x = destRect.origin.x;
    drawRect.origin.y = destRect.origin.y + self->_imageInsets.top;
    drawRect.size.width = destRect.size.width;
    drawRect.size.height = pos.size.height - srcRect.size.height;

    capRect.origin.x = srcRect.origin.x;
    capRect.origin.y = self->_imageInsets.top;
    capRect.size.width = srcRect.size.width;
    capRect.size.height = -1;
    CGContextDrawImageRect(cur, getImage(self), capRect, drawRect);

    //  Adjust the source and desination rects
    srcRect.origin.y = self->_imageInsets.top;
    srcRect.size.height = getImage(self)->Backing()->Height() - self->_imageInsets.top;
    destRect.origin.y += pos.size.height - srcRect.size.height;
    destRect.size.height = srcRect.size.height;

    //  Invert srcRect
    srcRect.origin.y = getImage(self)->Backing()->Height() - srcRect.origin.y;
    srcRect.size.height = -srcRect.size.height;
    CGContextDrawImageRect(cur, getImage(self), srcRect, destRect);
}

static void drawFromRect(UIImage* self, CGContextRef ctx, CGRect dest, CGRect source) {
    source.origin.x *= self->_scale;
    source.origin.y *= self->_scale;
    source.size.width *= self->_scale;
    source.size.height *= self->_scale;

    source.origin.y = getImage(self)->Backing()->Height() - source.origin.y;
    source.size.height = -source.size.height;

    CGContextDrawImageRect(ctx, getImage(self), source, dest);
}

static CGRect makeRect(float left, float top, float width, float height) {
    CGRect ret = { left, top, width, height };

    return ret;
}

static void drawLeftAndTopCap(UIImage* self, CGContextRef ctx, CGRect rect) {
    CGSize size = { 0, 0 };
    size = [self size];
    // FIXME: Floating point accuracy messes with the seams.
    float stretchyWidth = (self->_imageInsets.left < size.width) ? 0.999f : 0.f;
    float stretchyHeight = (self->_imageInsets.top < size.height) ? 0.999f : 0.f;
    float bottomCapHeight = size.height - self->_imageInsets.top - stretchyHeight;
    float rightCapWidth = size.width - self->_imageInsets.left - stretchyWidth;

    // topLeftCorner
    drawFromRect(self,
                 ctx,
                 makeRect(CGRectGetMinX(rect), CGRectGetMinY(rect), self->_imageInsets.left, self->_imageInsets.top),
                 makeRect(0, 0, self->_imageInsets.left, self->_imageInsets.top));

    // topEdgeFill
    drawFromRect(self,
                 ctx,
                 makeRect(CGRectGetMinX(rect) + self->_imageInsets.left,
                          CGRectGetMinY(rect),
                          rect.size.width - rightCapWidth - self->_imageInsets.left,
                          self->_imageInsets.top),
                 makeRect(self->_imageInsets.left, 0, stretchyWidth, self->_imageInsets.top));

    // topRightCorner
    drawFromRect(
        self,
        ctx,
        makeRect(CGRectGetMaxX(rect) - rightCapWidth, CGRectGetMinY(rect), rightCapWidth, self->_imageInsets.top),
        makeRect(size.width - rightCapWidth, 0, rightCapWidth, self->_imageInsets.top));

    // bottomLeftCorner
    drawFromRect(
        self,
        ctx,
        makeRect(CGRectGetMinX(rect), CGRectGetMaxY(rect) - bottomCapHeight, self->_imageInsets.left, bottomCapHeight),
        makeRect(0, size.height - bottomCapHeight, self->_imageInsets.left, bottomCapHeight));

    // bottomEdgeFill
    drawFromRect(self,
                 ctx,
                 makeRect(CGRectGetMinX(rect) + self->_imageInsets.left,
                          CGRectGetMaxY(rect) - bottomCapHeight,
                          rect.size.width - rightCapWidth - self->_imageInsets.left,
                          bottomCapHeight),
                 makeRect(self->_imageInsets.left, size.height - bottomCapHeight, stretchyWidth, bottomCapHeight));

    // bottomRightCorner
    drawFromRect(
        self,
        ctx,
        makeRect(
            CGRectGetMaxX(rect) - rightCapWidth, CGRectGetMaxY(rect) - bottomCapHeight, rightCapWidth, bottomCapHeight),
        makeRect(size.width - rightCapWidth, size.height - bottomCapHeight, rightCapWidth, bottomCapHeight));

    // leftEdgeFill
    drawFromRect(self,
                 ctx,
                 makeRect(CGRectGetMinX(rect),
                          CGRectGetMinY(rect) + self->_imageInsets.top,
                          self->_imageInsets.left,
                          rect.size.height - bottomCapHeight - self->_imageInsets.top),
                 makeRect(0, self->_imageInsets.top, self->_imageInsets.left, stretchyHeight));

    // rightEdgeFill
    drawFromRect(self,
                 ctx,
                 makeRect(CGRectGetMaxX(rect) - rightCapWidth,
                          CGRectGetMinY(rect) + self->_imageInsets.top,
                          rightCapWidth,
                          rect.size.height - bottomCapHeight - self->_imageInsets.top),
                 makeRect(size.width - rightCapWidth, self->_imageInsets.top, rightCapWidth, stretchyHeight));

    // centerFill
    drawFromRect(self,
                 ctx,
                 makeRect(CGRectGetMinX(rect) + self->_imageInsets.left,
                          CGRectGetMinY(rect) + self->_imageInsets.top,
                          rect.size.width - rightCapWidth - self->_imageInsets.left,
                          rect.size.height - bottomCapHeight - self->_imageInsets.top),
                 makeRect(self->_imageInsets.left, self->_imageInsets.top, stretchyWidth, stretchyHeight));
}

- (void)drawInRect:(CGRect)pos {
    [self drawInRect:pos blendMode:kCGBlendModeNormal alpha:1.0f];
}

- (void)drawInRect:(CGRect)pos blendMode:(CGBlendMode)mode alpha:(float)alpha {
    //  [BUG: Need to honor mode and alpha]
    CGContextRef cur = UIGraphicsGetCurrentContext();

    if (!getImage(self)) {
        EbrDebugLog("m_pImage = NULL!\n");
        return;
    }

    CGContextSaveGState(cur);
    CGContextSetBlendMode(cur, mode);

    if (alpha != 1.0) {
        EbrDebugLog("Should draw with alpha\n");
    }

    if (_scale == 0) {
        EbrDebugLog("Scale should be non-zero!\n");
        return;
    }

    if (_imageInsets.left == 0 && _imageInsets.top == 0 && _imageInsets.right == 0 && _imageInsets.bottom == 0) {
        CGRect srcRect;
        CGRect destRect = pos;

        srcRect.origin.x = 0;
        srcRect.origin.y = 0;
        srcRect.size.width = float(getImage(self)->Backing()->Width());
        srcRect.size.height = float(getImage(self)->Backing()->Height());

        //  Invert srcRect
        srcRect.origin.y = getImage(self)->Backing()->Height() - srcRect.origin.y;
        srcRect.size.height = -srcRect.size.height;
        CGContextDrawImageRect(cur, getImage(self), srcRect, destRect);
    } else {
        static const CGPatternCallbacks patCB = { 0, drawNinePatchCallBack, NULL };
        insetInfo ii = { self, makeRect(0, 0, pos.size.width * _scale, pos.size.height * _scale) };

        CGPatternRef pat = CGPatternCreate((void*)&ii,
                                           makeRect(0, 0, pos.size.width * _scale, pos.size.height * _scale),
                                           CGAffineTransformMakeScale(_scale, _scale),
                                           10,
                                           10,
                                           kCGPatternTilingConstantSpacing,
                                           true,
                                           &patCB);

        CGFloat alpha = 1.0f;
        CGContextSetFillPattern(cur, pat, &alpha);
        CGContextFillRect(cur, pos);

        CGPatternRelease(pat);
    }

    CGContextRestoreGState(cur);
}

- (void)setOrientation:(UIImageOrientation)orientation {
    _orientation = orientation;
}

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

- (CGRect)_imageStretch {
    return _imageStretch;
}

- (CGImageRef)imageRef {
    return getImage(self);
}

- (CGImageRef)CGImage {
    return getImage(self);
}

- (UIImageOrientation)imageOrientation {
    return _orientation;
}

- (int)leftCapWidth {
    return (int)_imageInsets.left;
}

- (int)topCapHeight {
    return (int)_imageInsets.top;
}

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

- (void)dealloc {
    _cacheImage = nil;
    _deferredImageData = nil;

    if (m_pImage)
        CGImageRelease(m_pImage);
    [super dealloc];
}

- (float)scale {
    return _scale;
}

- (void)_setScale:(float)scale {
    _scale = scale;
}

- (void)setAccessibilityLabel:(UILabel*)label {
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (NSArray*)images {
    return nil;
}

static CGImageRef getImage(UIImage* self) {
    if (!self->m_pImage && self->_deferredImageData != nil) {
        unsigned char* in = (unsigned char*)[self->_deferredImageData bytes];
        int len = [self->_deferredImageData length];

        if (in[0] == 'G' && in[1] == 'I' && in[2] == 'F') {
            if (!loadGIF(self, in, len)) {
                EbrDebugLog("Something looked like a GIF but wasn't!\n");
            }
        }

        if ((in[0] == 'I' && in[1] == 'I') || (in[0] == 'M' && in[1] == 'M')) {
            if (!loadTIFF(self, in, len)) {
                EbrDebugLog("Something looked like a TIFF but wasn't!\n");
            }
        }

        if (in[0] == 'B' && in[1] == 'M') {
            if (!loadBMP(self, in, len)) {
                EbrDebugLog("Something looked like a BMP but wasn't!\n");
            }
        }

        self->_deferredImageData = nil;
    }

    return self->m_pImage;
}

@end
