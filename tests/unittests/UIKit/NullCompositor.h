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
#pragma once

#import "CACompositor.h"

class NullCompositor : public CACompositorInterface {
public:
    // Compositor APIs
    bool IsRunningAsFramework() override {
        return false;
    }
    float GetScreenScale() override {
        return 1.0f;
    }

    // CATransaction support
    std::shared_ptr<ILayerTransaction> CreateLayerTransaction() override {
        return nullptr;
    }
    void QueueLayerTransaction(const std::shared_ptr<ILayerTransaction>& transaction,
                               const std::shared_ptr<ILayerTransaction>& onTransaction) override {
    }
    void ProcessLayerTransactions() override {
    }

    // CALayer support
    std::shared_ptr<ILayerProxy> CreateLayerProxy(const Microsoft::WRL::ComPtr<IInspectable>& xamlElement) override {
        return nullptr;
    }

    // CAAnimation support
    std::shared_ptr<ILayerAnimation> CreateBasicAnimation(CAAnimation* animation,
                                                          NSString* propertyName,
                                                          NSObject* fromValue,
                                                          NSObject* toValue,
                                                          NSObject* byValue,
                                                          CAMediaTimingProperties* timingProperties) override {
        return nullptr;
    }
    std::shared_ptr<ILayerAnimation> CreateTransitionAnimation(CAAnimation* animation, NSString* type, NSString* subtype) override {
        return nullptr;
    }

    // DisplayTexture support
    std::shared_ptr<IDisplayTexture> CreateDisplayTexture(int width, int height) override {
        return nullptr;
    }
    std::shared_ptr<IDisplayTexture> GetDisplayTextureForCGImage(CGImageRef img) override {
        return nullptr;
    }

    // DisplayLink support
    void EnableDisplaySyncNotification() override {
    }
    void DisableDisplaySyncNotification() override {
    }
};
