//******************************************************************************
//
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
#pragma once

#import "Starboard.h"
#import "CoreGraphics/CGImage.h"
#import "CGContextInternal.h"
#import "CACompositor.h"

#import <memory>

class IDisplayTextureImpl : public IDisplayTexture {
public:
    IDisplayTextureImpl(DisplayTexture* texture) {
        m_texture = texture;
        GetCACompositor()->RetainDisplayTexture(m_texture);
    }

    Microsoft::WRL::ComPtr<IInspectable> GetContent() {
        return nullptr;
    }

    DisplayTexture* GetTexture() {
        return m_texture;
    }

    void* Lock(int* stride) {
        return GetCACompositor()->LockWritableBitmapTexture(m_texture, stride);
    }

    void Unlock() {
        GetCACompositor()->UnlockWritableBitmapTexture(m_texture);
    }

    ~IDisplayTextureImpl() {
        if (m_texture) {
            GetCACompositor()->ReleaseDisplayTexture(m_texture);
        }
    }

private:
    DisplayTexture* m_texture;
};