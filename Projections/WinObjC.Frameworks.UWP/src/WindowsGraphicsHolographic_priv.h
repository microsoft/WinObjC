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

// WindowsGraphicsHolographic_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsPerceptionSpatial_priv.h"
#include "WindowsUICore_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsDirectXDirect3D11_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsPerception_priv.h"
ComPtr<ABI::Windows::Graphics::Holographic::IHolographicSpaceStatics> WGHIHolographicSpaceStatics_inst();
@interface WGHHolographicStereoTransform (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::Holographic::HolographicStereoTransform)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::Holographic::HolographicStereoTransform*)internalStruct;
@end
inline WGHHolographicStereoTransform* WGHHolographicStereoTransform_create(
    ABI::Windows::Graphics::Holographic::HolographicStereoTransform val) {
    return [WGHHolographicStereoTransform createWith:val];
}
@interface WGHHolographicAdapterId (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::Holographic::HolographicAdapterId)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::Holographic::HolographicAdapterId*)internalStruct;
@end
inline WGHHolographicAdapterId* WGHHolographicAdapterId_create(ABI::Windows::Graphics::Holographic::HolographicAdapterId val) {
    return [WGHHolographicAdapterId createWith:val];
}

id RTProxiedNSArray_WGHHolographicCamera_create(IInspectable* val);
id RTProxiedNSArray_WGHHolographicCameraPose_create(IInspectable* val);

@class Nullable_WGHHolographicStereoTransform, Nullable_WPSSpatialBoundingFrustum, RTProxiedNSArray_WGHHolographicCamera,
    RTProxiedNSArray_WGHHolographicCameraPose;

#ifndef __ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraAddedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraAddedEventArgs__DEFINED
class ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraAddedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Holographic::HolographicSpace*,
                                                       ABI::Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs*>> {
    void (^_delegate)(WGHHolographicSpace*, WGHHolographicSpaceCameraAddedEventArgs*);

public:
    ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraAddedEventArgs(
        void (^del)(WGHHolographicSpace*, WGHHolographicSpaceCameraAddedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraAddedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Holographic::IHolographicSpace* arg0,
                                             ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGHHolographicSpace>(arg0), _createRtProxy<WGHHolographicSpaceCameraAddedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraRemovedEventArgs__DEFINED
class ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraRemovedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Holographic::HolographicSpace*,
                                                       ABI::Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs*>> {
    void (^_delegate)(WGHHolographicSpace*, WGHHolographicSpaceCameraRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraRemovedEventArgs(
        void (^del)(WGHHolographicSpace*, WGHHolographicSpaceCameraRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Holographic::IHolographicSpace* arg0,
                                             ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGHHolographicSpace>(arg0), _createRtProxy<WGHHolographicSpaceCameraRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
