//******************************************************************************
//
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
#pragma once

#include <IDisplayTexture.h>

#include <memory>

#if defined(__cplusplus) && defined(__OBJC__)

#import <CoreGraphics/CGImage.h>

class DisplayTexture : public IDisplayTexture {
public:
    DisplayTexture(int width, int height);

    // Retrieves a DisplayTexture for the CGImage either from the cache, or by creating and caching a new instance
    static std::shared_ptr<IDisplayTexture> GetForCGImage(CGImageRef img);
    static void ClearCacheForCGImage(CGImageRef img);

    // Returns a bitmap representation of a CGImage
    static Microsoft::WRL::ComPtr<IInspectable> GetBitmapForCGImage(CGImageRef img);

    // IDisplayTexture implementation
    Microsoft::WRL::ComPtr<IInspectable> GetContent() override;
    void* Lock(int* stride) override;
    void Unlock() override;

private:
    explicit DisplayTexture(CGImageRef img);

    Microsoft::WRL::ComPtr<IInspectable> _xamlImage;
    Microsoft::WRL::ComPtr<IInspectable> _lockPtr;
};

#endif
