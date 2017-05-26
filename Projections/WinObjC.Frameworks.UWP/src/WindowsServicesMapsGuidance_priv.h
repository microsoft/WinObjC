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

// WindowsServicesMapsGuidance_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsServicesMaps_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsDevicesGeolocation_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRouteStatics> WSMGIGuidanceRouteStatics_inst();
ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics2> WSMGIGuidanceNavigatorStatics2_inst();
ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics> WSMGIGuidanceNavigatorStatics_inst();
ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollectorStatics> WSMGIGuidanceTelemetryCollectorStatics_inst();

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WSMGGuidanceLaneInfo_create(IInspectable* val);
id RTProxiedNSArray_WSMGGuidanceManeuver_create(IInspectable* val);
id RTProxiedNSArray_WSMGGuidanceRoadSegment_create(IInspectable* val);

@class RTProxiedNSArray_NSString, RTProxiedNSArray_WSMGGuidanceLaneInfo, RTProxiedNSArray_WSMGGuidanceManeuver,
    RTProxiedNSArray_WSMGGuidanceRoadSegment;

#ifndef __ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object__DEFINED
class ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Services::Maps::Guidance::GuidanceNavigator*, IInspectable*>> {
    void (^_delegate)(WSMGGuidanceNavigator*, RTObject*);

public:
    ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object(void (^del)(WSMGGuidanceNavigator*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSMGGuidanceNavigator>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceAudioNotificationRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceAudioNotificationRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceAudioNotificationRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Services::Maps::Guidance::GuidanceNavigator*,
                              ABI::Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs*>> {
    void (^_delegate)(WSMGGuidanceNavigator*, WSMGGuidanceAudioNotificationRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceAudioNotificationRequestedEventArgs(
        void (^del)(WSMGGuidanceNavigator*, WSMGGuidanceAudioNotificationRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceAudioNotificationRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator* arg0,
           ABI::Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSMGGuidanceNavigator>(arg0), _createRtProxy<WSMGGuidanceAudioNotificationRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceReroutedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceReroutedEventArgs__DEFINED
class ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceReroutedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Services::Maps::Guidance::GuidanceNavigator*,
                                                       ABI::Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs*>> {
    void (^_delegate)(WSMGGuidanceNavigator*, WSMGGuidanceReroutedEventArgs*);

public:
    ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceReroutedEventArgs(
        void (^del)(WSMGGuidanceNavigator*, WSMGGuidanceReroutedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceReroutedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator* arg0,
                                             ABI::Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSMGGuidanceNavigator>(arg0), _createRtProxy<WSMGGuidanceReroutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceUpdatedEventArgs__DEFINED
class ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceUpdatedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Services::Maps::Guidance::GuidanceNavigator*,
                                                                       ABI::Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs*>> {
    void (^_delegate)(WSMGGuidanceNavigator*, WSMGGuidanceUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceUpdatedEventArgs(
        void (^del)(WSMGGuidanceNavigator*, WSMGGuidanceUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator* arg0,
                                             ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSMGGuidanceNavigator>(arg0), _createRtProxy<WSMGGuidanceUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
