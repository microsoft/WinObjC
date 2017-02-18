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
#import "XamlCompositor.h"

#import "DisplayProperties.h"
#import "DisplayTexture.h"
#import "LayerAnimation.h"
#import "LayerProxy.h"
#import "LayerTransaction.h"
#import "CGImageInternal.h"

#import "CGContextInternal.h"
#import "UIApplicationInternal.h"

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"XamlCompositor";

using namespace XamlCompositor::Internal;

CompositionMode g_compositionMode = CompositionModeDefault;

void OnRenderedFrame() {
    CASignalDisplayLink();
}

std::deque<std::shared_ptr<ICompositorTransaction>> s_queuedTransactions;

class CAXamlCompositor : public CACompositorInterface {
public:
    // Compositor APIs
    virtual bool IsRunningAsFramework() override {
        return g_compositionMode == CompositionModeLibrary;
    }

    float GetScreenScale() override {
        return DisplayProperties::ScreenScale();
    }

    // CATransaction support
    std::shared_ptr<ILayerTransaction> CreateLayerTransaction() override {
        return std::make_shared<LayerTransaction>();
    }

    void QueueLayerTransaction(const std::shared_ptr<ILayerTransaction>& transaction,
                               const std::shared_ptr<ILayerTransaction>& onTransaction) override {
        if (onTransaction) {
            std::dynamic_pointer_cast<LayerTransaction>(onTransaction)->QueueTransaction(transaction);
        } else {
            s_queuedTransactions.push_back(std::dynamic_pointer_cast<ICompositorTransaction>(transaction));
        }
    }

    void ProcessLayerTransactions() override {
        for (auto& transaction : s_queuedTransactions) {
            transaction->Process();
        }
        s_queuedTransactions.clear();
    }

    // CALayer support
    virtual std::shared_ptr<ILayerProxy> CreateLayerProxy(const ComPtr<IInspectable>& xamlElement) override {
        return std::make_shared<LayerProxy>(xamlElement.Get());
    }

    // CAAnimation support
    virtual std::shared_ptr<ILayerAnimation> CreateBasicAnimation(CAAnimation* animation,
                                                                  NSString* propertyName,
                                                                  NSObject* fromValue,
                                                                  NSObject* toValue,
                                                                  NSObject* byValue,
                                                                  CAMediaTimingProperties* timingProperties) override {
        return LayerAnimation::CreateBasicAnimation(animation, propertyName, fromValue, toValue, byValue, timingProperties);
    }

    virtual std::shared_ptr<ILayerAnimation> CreateTransitionAnimation(CAAnimation* animation, NSString* type, NSString* subType) override {
        return LayerAnimation::CreateTransitionAnimation(animation, type, subType);
    }

    // DisplayTexture support
    std::shared_ptr<IDisplayTexture> CreateDisplayTexture(int width, int height) override {
        return std::make_shared<DisplayTexture>(width, height);
    }

    virtual std::shared_ptr<IDisplayTexture> GetDisplayTextureForCGImage(CGImageRef img) override {
        return DisplayTexture::GetForCGImage(img);
    }

    // DisplayLink support
    void EnableDisplaySyncNotification() override {
        EnableRenderingListener(OnRenderedFrame);
    }

    void DisableDisplaySyncNotification() override {
        DisableRenderingListener();
    }
};

void UIReleaseDisplayTextureForCGImage(CGImageRef img) {
    DisplayTexture::ClearCacheForCGImage(img);
}

namespace XamlCompositor {
namespace Internal {

void CreateXamlCompositor(CompositionMode compositionMode) {
    g_compositionMode = compositionMode;
    _CGImageAddDestructionListener(UIReleaseDisplayTextureForCGImage);
    static CAXamlCompositor* s_compositor = new CAXamlCompositor();
    SetCACompositor(s_compositor);
}

void RootGridSizeChanged(float newWidth, float newHeight) {
    [[UIApplication displayMode] _setWindowSize:CGSizeMake(newWidth, newHeight)];
    [[UIApplication displayMode] _updateDisplaySettings];
}

} /* namespace Internal */
} /* namespace XamlCompositor */