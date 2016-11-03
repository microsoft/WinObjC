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

#import "Starboard.h"
#import "DisplayTexture.h"

#import "CoreGraphics/CGImage.h"
#import "CGContextInternal.h"
#import "UIColorInternal.h"

#include <map>
#include <mutex>

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"DisplayTexture";

// These are implemented in DisplayTexture.cpp
Microsoft::WRL::ComPtr<IInspectable> CreateBitmapFromBits(void* ptr, int width, int height, int stride);
Microsoft::WRL::ComPtr<IInspectable> CreateBitmapFromImageData(const void* ptr, int len);
Microsoft::WRL::ComPtr<IInspectable> CreateWritableBitmap(int width, int height);
Microsoft::WRL::ComPtr<IInspectable> LockWritableBitmap(const ComPtr<IInspectable>& bitmap, void** ptr, int* stride);

namespace {

std::mutex _displayTextureCacheLock;
std::map<CGImageRef, std::shared_ptr<IDisplayTexture>> _displayTextureCache;

std::shared_ptr<IDisplayTexture> CachedDisplayTextureForImage(CGImageRef img) {
    std::shared_ptr<IDisplayTexture> ret;
    _displayTextureCacheLock.lock();
    auto cachedEntry = _displayTextureCache.find(img);
    if (cachedEntry != _displayTextureCache.end()) {
        ret = cachedEntry->second;
    }
    _displayTextureCacheLock.unlock();

    return ret;
}

void SetCachedDisplayTextureForImage(CGImageRef img, const std::shared_ptr<IDisplayTexture>& texture) {
    _displayTextureCacheLock.lock();
    if (!texture) {
        // Clear the cache if the texture is nullptr
        _displayTextureCache.erase(img);
    } else {
        // Cache the texture
        _displayTextureCache[img] = texture;
    }
    _displayTextureCacheLock.unlock();
}
}

DisplayTexture::DisplayTexture(int width, int height) {
    _xamlImage = ::CreateWritableBitmap(width, height);
}

std::shared_ptr<IDisplayTexture> DisplayTexture::GetForCGImage(CGImageRef img) {
    CGImageRetain(img);
    auto cleanup = wil::ScopeExit([img] { CGImageRelease(img); });

    // If the image has a backing texture, use it
    std::shared_ptr<IDisplayTexture> texture = img->Backing()->GetDisplayTexture();
    if (texture) {
        return texture;
    }

    // If we have a cached texture for this image, use it
    texture = ::CachedDisplayTextureForImage(img);
    if (texture) {
        return texture;
    }

    // Else, create and cache a new texture
    // Note: Can't easily use make_shared here due to the private ctor being called
    texture = std::shared_ptr<IDisplayTexture>(new DisplayTexture(img));
    ::SetCachedDisplayTextureForImage(img, texture);
    return texture;
}

void DisplayTexture::ClearCacheForCGImage(CGImageRef img) {
    ::SetCachedDisplayTextureForImage(img, nullptr);
}

ComPtr<IInspectable> DisplayTexture::GetBitmapForCGImage(CGImageRef img) {
    return GetForCGImage(img)->GetContent();
}

DisplayTexture::DisplayTexture(CGImageRef img) {
    if (img->_imgType == CGImageTypePNG || img->_imgType == CGImageTypeJPEG) {
        const void* data = NULL;
        bool freeData = false;
        int len = 0;
        StrongId<NSData> fileData;

        switch (img->_imgType) {
            case CGImageTypePNG: {
                CGPNGImageBacking* pngImg = (CGPNGImageBacking*)img->Backing();

                if (pngImg->_fileName) {
                    fileData.attach([[NSData alloc] initWithContentsOfFile:[NSString stringWithUTF8String:pngImg->_fileName]]);
                    data = [fileData bytes];
                    len = [fileData length];
                } else {
                    data = [(NSData*)pngImg->_data bytes];
                    len = [(NSData*)pngImg->_data length];
                }
            } break;

            case CGImageTypeJPEG: {
                CGJPEGImageBacking* jpgImg = (CGJPEGImageBacking*)img->Backing();

                if (jpgImg->_fileName) {
                    fileData.attach([[NSData alloc] initWithContentsOfFile:[NSString stringWithUTF8String:jpgImg->_fileName]]);
                    data = [fileData bytes];
                    len = [fileData length];
                } else {
                    data = [(NSData*)jpgImg->_data bytes];
                    len = [(NSData*)jpgImg->_data length];
                }
            } break;
            default:
                TraceError(TAG, L"Warning: unrecognized image format sent to DisplayTextureContent!");
                break;
        }
        _xamlImage = CreateBitmapFromImageData(data, len);
        return;
    }
    _lockPtr = nullptr;

    int texWidth = img->Backing()->Width();
    int texHeight = img->Backing()->Height();
    int imageWidth = texWidth;
    int imageHeight = texHeight;
    int imageX = 0;
    int imageY = 0;
    CGImageRef pNewImage = 0;
    CGImageRef pTexImage = img;

    bool matched = false;
    if (img->Backing()->SurfaceFormat() == _ColorARGB) {
        matched = true;
    }

    // Unrecognized, make 8888 ARGB:
    if (!matched) {
        CGContextRef ctx = _CGBitmapContextCreateWithFormat(texWidth, texHeight, _ColorARGB);

        pNewImage = CGBitmapContextGetImage(ctx);
        CGImageRetain(pNewImage);

        pTexImage = pNewImage;

        CGRect rect, destRect;

        int w = fmin(imageWidth, texWidth), h = fmin(imageHeight, texHeight);

        rect.origin.x = float(imageX);
        rect.origin.y = float(imageY);
        rect.size.width = float(w);
        rect.size.height = float(h);

        destRect.origin.x = 0;
        destRect.origin.y = float(texHeight - imageHeight);
        destRect.size.width = float(w);
        destRect.size.height = float(h);

        CGContextDrawImageRect(ctx, img, rect, destRect);
        CGContextRelease(ctx);
    }

    void* data = (void*)pTexImage->Backing()->LockImageData();
    int bytesPerRow = pTexImage->Backing()->BytesPerRow();

    int width = pTexImage->Backing()->Width();
    int height = pTexImage->Backing()->Height();

    _xamlImage = CreateBitmapFromBits(data, width, height, bytesPerRow);

    pTexImage->Backing()->ReleaseImageData();
    img->Backing()->DiscardIfPossible();

    CGImageRelease(pNewImage);
}

void* DisplayTexture::Lock(int* stride) {
    void* ret = nullptr;
    _lockPtr = ::LockWritableBitmap(_xamlImage, &ret, stride);
    return ret;
}

void DisplayTexture::Unlock() {
    // Release our _lockPtr to unlock the bitmap
    _lockPtr.Reset();
}

ComPtr<IInspectable> DisplayTexture::GetContent() {
    return _xamlImage;
}