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

// WindowsDevicesPerceptionProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationNumerics_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsDevicesPerception_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsGraphicsImaging_priv.h"
#include "WindowsMedia_priv.h"
static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroupFactory>
WDPPIPerceptionFaceAuthenticationGroupFactory_inst();
static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroupFactory> WDPPIPerceptionControlGroupFactory_inst();
static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroupFactory>
WDPPIPerceptionCorrelationGroupFactory_inst();
static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationFactory> WDPPIPerceptionCorrelationFactory_inst();
static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocatorFactory>
WDPPIPerceptionVideoFrameAllocatorFactory_inst();
ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManagerServiceStatics>
WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::Provider::IKnownPerceptionFrameKindStatics> WDPPIKnownPerceptionFrameKindStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_WDPPPerceptionCorrelation_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WDPPPerceptionCorrelation_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_WDPPPerceptionCorrelation, RTProxiedNSArray_NSString,
    RTProxiedNSArray_WDPPPerceptionCorrelation;

#ifndef __WDPPPerceptionStartFaceAuthenticationHandler_shim__DEFINED
#define __WDPPPerceptionStartFaceAuthenticationHandler_shim__DEFINED
class WDPPPerceptionStartFaceAuthenticationHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Devices::Perception::Provider::IPerceptionStartFaceAuthenticationHandler> {
    void (^_delegate)(WDPPPerceptionFaceAuthenticationGroup*);

public:
    WDPPPerceptionStartFaceAuthenticationHandler_shim(void (^del)(WDPPPerceptionFaceAuthenticationGroup*)) : _delegate([del copy]) {
    }
    ~WDPPPerceptionStartFaceAuthenticationHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup* arg0,
                                             boolean*) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPPerceptionFaceAuthenticationGroup>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WDPPPerceptionStopFaceAuthenticationHandler_shim__DEFINED
#define __WDPPPerceptionStopFaceAuthenticationHandler_shim__DEFINED
class WDPPPerceptionStopFaceAuthenticationHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Devices::Perception::Provider::IPerceptionStopFaceAuthenticationHandler> {
    void (^_delegate)(WDPPPerceptionFaceAuthenticationGroup*);

public:
    WDPPPerceptionStopFaceAuthenticationHandler_shim(void (^del)(WDPPPerceptionFaceAuthenticationGroup*)) : _delegate([del copy]) {
    }
    ~WDPPPerceptionStopFaceAuthenticationHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPPerceptionFaceAuthenticationGroup>(arg0));
            return 0;
        };
    }
};
#endif
