//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#import "CGImageInternal.h"
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
    std::shared_ptr<IDisplayTexture> texture = _CGImageGetDisplayTexture(img);
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
    woc::unique_cf<CGImageRef> image(_CGImageCreateCopyWithPixelFormat(img, GUID_WICPixelFormat32bppPBGRA));
    _xamlImage = CreateBitmapFromBits(_CGImageGetRawBytes(image.get()),
                                      CGImageGetWidth(image.get()),
                                      CGImageGetHeight(image.get()),
                                      CGImageGetBytesPerRow(image.get()));
    return;
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