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

#if defined(__OBJC__)

#import <QuartzCore/CAAnimation.h>
#import <QuartzCore/CALayer.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wignored-attributes"

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#import <IDisplayTexture.h>
#include <COMIncludes_end.h>

#pragma clang diagnostic pop

#else

#include <memory>
#include <wrl/client.h>
#include <IDisplayTexture.h>

#endif

// Proxy between CALayer and its Xaml representation
struct ILayerProxy {
public:
    virtual ~ILayerProxy(){};

    // Returns the Xaml element backing this layer
    virtual Microsoft::WRL::ComPtr<IInspectable> GetXamlElement() = 0;

    // Returns the Xaml element used for hosting this layer's sublayer element
    virtual Microsoft::WRL::ComPtr<IInspectable> GetSublayerXamlElement() = 0;

    // Returns the property value as an NSObject*
    virtual void* GetPropertyValue(const char* propertyName) = 0;
    virtual void SetShouldRasterize(bool shouldRasterize) = 0;

    // TODO: Can we remove this altogether at some point?
    virtual void SetTopMost() = 0;
};

// Proxy between CAAnimation and its Xaml representation
struct ILayerAnimation {
public:
    virtual ~ILayerAnimation(){};
};

#if defined(__cplusplus) && defined(__OBJC__)

// Proxy between CATransaction and its backing implementation
struct ILayerTransaction {
public:
    virtual ~ILayerTransaction(){};

    // Sublayer management
    virtual void AddLayer(const std::shared_ptr<ILayerProxy>& layer,
                          const std::shared_ptr<ILayerProxy>& superLayer,
                          const std::shared_ptr<ILayerProxy>& beforeLayer,
                          const std::shared_ptr<ILayerProxy>& afterLayer) = 0;
    virtual void MoveLayer(const std::shared_ptr<ILayerProxy>& layer,
                           const std::shared_ptr<ILayerProxy>& beforeLayer,
                           const std::shared_ptr<ILayerProxy>& afterLayer) = 0;
    virtual void RemoveLayer(const std::shared_ptr<ILayerProxy>& layer) = 0;

    // Property management
    virtual void SetLayerProperty(const std::shared_ptr<ILayerProxy>& layer, const char* propertyName, NSObject* newValue) = 0;

    // Display management
    virtual void SetLayerTexture(const std::shared_ptr<ILayerProxy>& layer,
                                 const std::shared_ptr<IDisplayTexture>& newTexture,
                                 CGSize contentsSize,
                                 float contentsScale) = 0;

    // Animation management
    virtual void AddAnimation(CALayer* layer, CAAnimation* animation, NSString* forKey) = 0;
    virtual void RemoveAnimation(const std::shared_ptr<ILayerAnimation>& animation) = 0;
};

struct CAMediaTimingProperties;

class CACompositorInterface {
public:
    virtual ~CACompositorInterface(){};

    // Compositor APIs
    virtual bool IsRunningAsFramework() = 0;
    virtual float GetScreenScale() = 0;

    // CATransaction support
    virtual std::shared_ptr<ILayerTransaction> CreateLayerTransaction() = 0;
    virtual void QueueLayerTransaction(const std::shared_ptr<ILayerTransaction>& transaction,
                                       const std::shared_ptr<ILayerTransaction>& onTransaction) = 0;
    virtual void ProcessLayerTransactions() = 0;

    // CALayer support
    virtual std::shared_ptr<ILayerProxy> CreateLayerProxy(const Microsoft::WRL::ComPtr<IInspectable>& xamlElement) = 0;

    // CAAnimation support
    virtual std::shared_ptr<ILayerAnimation> CreateBasicAnimation(CAAnimation* animation,
                                                                  NSString* propertyName,
                                                                  NSObject* fromValue,
                                                                  NSObject* toValue,
                                                                  NSObject* byValue,
                                                                  CAMediaTimingProperties* timingProperties) = 0;
    virtual std::shared_ptr<ILayerAnimation> CreateTransitionAnimation(CAAnimation* animation, NSString* type, NSString* subtype) = 0;

    // DisplayTexture support
    virtual std::shared_ptr<IDisplayTexture> CreateDisplayTexture(int width, int height) = 0;
    virtual std::shared_ptr<IDisplayTexture> GetDisplayTextureForCGImage(CGImageRef img) = 0;

    // DisplayLink support
    // TODO: Move to a displaylink helper API?
    virtual void EnableDisplaySyncNotification() = 0;
    virtual void DisableDisplaySyncNotification() = 0;
};

extern CACompositorInterface* _globalCompositor;

#ifndef CA_EXPORT
#define CA_EXPORT
#endif

CA_EXPORT CACompositorInterface* GetCACompositor();
CA_EXPORT void SetCACompositor(CACompositorInterface* compositorInterface);

CA_EXPORT bool CASignalDisplayLink();

#endif
