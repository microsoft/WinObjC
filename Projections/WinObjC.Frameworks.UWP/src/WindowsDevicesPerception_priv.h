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

// WindowsDevicesPerception_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationCollections_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsMedia_priv.h"
#include "WindowsMediaDevicesCore_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsGraphicsImaging_priv.h"
ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceStatics> WDPIPerceptionColorFrameSourceStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics> WDPIPerceptionDepthFrameSourceStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics> WDPIPerceptionInfraredFrameSourceStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics>
WDPIKnownPerceptionFrameSourcePropertiesStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2>
WDPIKnownPerceptionFrameSourcePropertiesStatics2_inst();
ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics>
WDPIKnownPerceptionVideoFrameSourcePropertiesStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics>
WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics>
WDPIKnownPerceptionDepthFrameSourcePropertiesStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics>
WDPIKnownPerceptionColorFrameSourcePropertiesStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics>
WDPIKnownPerceptionVideoProfilePropertiesStatics_inst();
ComPtr<ABI::Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics> WDPIKnownCameraIntrinsicsPropertiesStatics_inst();

id RTProxiedNSArray_C_WFNVector3_create(UINT32 size, ABI::Windows::Foundation::Numerics::Vector3* val);
id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val);
id RTProxiedNSArray_WDPPerceptionColorFrameSource_create(IInspectable* val);
id RTProxiedNSArray_WDPPerceptionDepthFrameSource_create(IInspectable* val);
id RTProxiedNSArray_WDPPerceptionInfraredFrameSource_create(IInspectable* val);
id RTProxiedNSArray_WDPPerceptionVideoProfile_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);

@class RTProxiedNSArray_C_WFNVector3, RTProxiedNSArray_C_WFPoint, RTProxiedNSArray_WDPPerceptionColorFrameSource,
    RTProxiedNSArray_WDPPerceptionDepthFrameSource;
@class RTProxiedNSArray_WDPPerceptionInfraredFrameSource, RTProxiedNSArray_WDPPerceptionVideoProfile,
    RTProxiedNSDictionary_NSString_RTObject;

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameReader_Windows_Devices_Perception_PerceptionColorFrameArrivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameReader_Windows_Devices_Perception_PerceptionColorFrameArrivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameReader_Windows_Devices_Perception_PerceptionColorFrameArrivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionColorFrameReader*,
                                                       ABI::Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs*>> {
    void (^_delegate)(WDPPerceptionColorFrameReader*, WDPPerceptionColorFrameArrivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameReader_Windows_Devices_Perception_PerceptionColorFrameArrivedEventArgs(
        void (^del)(WDPPerceptionColorFrameReader*, WDPPerceptionColorFrameArrivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameReader_Windows_Devices_Perception_PerceptionColorFrameArrivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionColorFrameReader* arg0,
                                             ABI::Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionColorFrameReader>(arg0), _createRtProxy<WDPPerceptionColorFrameArrivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::
                              ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionColorFrameSourceWatcher*, IInspectable*>> {
    void (^_delegate)(WDPPerceptionColorFrameSourceWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_System_Object(
        void (^del)(WDPPerceptionColorFrameSourceWatcher*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionColorFrameSourceWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceAddedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceAddedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceAddedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionColorFrameSourceWatcher*,
                                                       ABI::Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs*>> {
    void (^_delegate)(WDPPerceptionColorFrameSourceWatcher*, WDPPerceptionColorFrameSourceAddedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceAddedEventArgs(
        void (^del)(WDPPerceptionColorFrameSourceWatcher*, WDPPerceptionColorFrameSourceAddedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceAddedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher* arg0,
                                             ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionColorFrameSourceWatcher>(arg0),
                      _createRtProxy<WDPPerceptionColorFrameSourceAddedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceRemovedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceRemovedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionColorFrameSourceWatcher*,
                                                       ABI::Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs*>> {
    void (^_delegate)(WDPPerceptionColorFrameSourceWatcher*, WDPPerceptionColorFrameSourceRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceRemovedEventArgs(
        void (^del)(WDPPerceptionColorFrameSourceWatcher*, WDPPerceptionColorFrameSourceRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher* arg0,
           ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionColorFrameSourceWatcher>(arg0),
                      _createRtProxy<WDPPerceptionColorFrameSourceRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*, IInspectable*>> {
    void (^_delegate)(WDPPerceptionColorFrameSource*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object(void (^del)(WDPPerceptionColorFrameSource*,
                                                                                                       RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionColorFrameSource* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionColorFrameSource>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Perception::PerceptionColorFrameSource*,
                              ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs*>> {
    void (^_delegate)(WDPPerceptionColorFrameSource*, WDPPerceptionFrameSourcePropertiesChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs(
        void (^del)(WDPPerceptionColorFrameSource*, WDPPerceptionFrameSourcePropertiesChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Perception::IPerceptionColorFrameSource* arg0,
           ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionColorFrameSource>(arg0),
                      _createRtProxy<WDPPerceptionFrameSourcePropertiesChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionControlSession_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionControlSession_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Perception_PerceptionControlSession_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionControlSession*, IInspectable*>> {
    void (^_delegate)(WDPPerceptionControlSession*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionControlSession_System_Object(void (^del)(WDPPerceptionControlSession*,
                                                                                                     RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionControlSession_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionControlSession* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionControlSession>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameReader_Windows_Devices_Perception_PerceptionDepthFrameArrivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameReader_Windows_Devices_Perception_PerceptionDepthFrameArrivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameReader_Windows_Devices_Perception_PerceptionDepthFrameArrivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionDepthFrameReader*,
                                                       ABI::Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs*>> {
    void (^_delegate)(WDPPerceptionDepthFrameReader*, WDPPerceptionDepthFrameArrivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameReader_Windows_Devices_Perception_PerceptionDepthFrameArrivedEventArgs(
        void (^del)(WDPPerceptionDepthFrameReader*, WDPPerceptionDepthFrameArrivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameReader_Windows_Devices_Perception_PerceptionDepthFrameArrivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader* arg0,
                                             ABI::Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionDepthFrameReader>(arg0), _createRtProxy<WDPPerceptionDepthFrameArrivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::
                              ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher*, IInspectable*>> {
    void (^_delegate)(WDPPerceptionDepthFrameSourceWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_System_Object(
        void (^del)(WDPPerceptionDepthFrameSourceWatcher*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionDepthFrameSourceWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceAddedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceAddedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceAddedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher*,
                                                       ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs*>> {
    void (^_delegate)(WDPPerceptionDepthFrameSourceWatcher*, WDPPerceptionDepthFrameSourceAddedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceAddedEventArgs(
        void (^del)(WDPPerceptionDepthFrameSourceWatcher*, WDPPerceptionDepthFrameSourceAddedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceAddedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher* arg0,
                                             ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionDepthFrameSourceWatcher>(arg0),
                      _createRtProxy<WDPPerceptionDepthFrameSourceAddedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceRemovedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceRemovedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher*,
                                                       ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs*>> {
    void (^_delegate)(WDPPerceptionDepthFrameSourceWatcher*, WDPPerceptionDepthFrameSourceRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceRemovedEventArgs(
        void (^del)(WDPPerceptionDepthFrameSourceWatcher*, WDPPerceptionDepthFrameSourceRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher* arg0,
           ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionDepthFrameSourceWatcher>(arg0),
                      _createRtProxy<WDPPerceptionDepthFrameSourceRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*, IInspectable*>> {
    void (^_delegate)(WDPPerceptionDepthFrameSource*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object(void (^del)(WDPPerceptionDepthFrameSource*,
                                                                                                       RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionDepthFrameSource>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*,
                              ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs*>> {
    void (^_delegate)(WDPPerceptionDepthFrameSource*, WDPPerceptionFrameSourcePropertiesChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs(
        void (^del)(WDPPerceptionDepthFrameSource*, WDPPerceptionFrameSourcePropertiesChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource* arg0,
           ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionDepthFrameSource>(arg0),
                      _createRtProxy<WDPPerceptionFrameSourcePropertiesChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameReader_Windows_Devices_Perception_PerceptionInfraredFrameArrivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameReader_Windows_Devices_Perception_PerceptionInfraredFrameArrivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameReader_Windows_Devices_Perception_PerceptionInfraredFrameArrivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionInfraredFrameReader*,
                                                       ABI::Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs*>> {
    void (^_delegate)(WDPPerceptionInfraredFrameReader*, WDPPerceptionInfraredFrameArrivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameReader_Windows_Devices_Perception_PerceptionInfraredFrameArrivedEventArgs(
        void (^del)(WDPPerceptionInfraredFrameReader*, WDPPerceptionInfraredFrameArrivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameReader_Windows_Devices_Perception_PerceptionInfraredFrameArrivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader* arg0,
                                             ABI::Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionInfraredFrameReader>(arg0),
                      _createRtProxy<WDPPerceptionInfraredFrameArrivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::
                              ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher*, IInspectable*>> {
    void (^_delegate)(WDPPerceptionInfraredFrameSourceWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_System_Object(
        void (^del)(WDPPerceptionInfraredFrameSourceWatcher*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionInfraredFrameSourceWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceAddedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceAddedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceAddedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher*,
                                                       ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs*>> {
    void (^_delegate)(WDPPerceptionInfraredFrameSourceWatcher*, WDPPerceptionInfraredFrameSourceAddedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceAddedEventArgs(
        void (^del)(WDPPerceptionInfraredFrameSourceWatcher*, WDPPerceptionInfraredFrameSourceAddedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceAddedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher* arg0,
           ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionInfraredFrameSourceWatcher>(arg0),
                      _createRtProxy<WDPPerceptionInfraredFrameSourceAddedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceRemovedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceRemovedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher*,
                                                       ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs*>> {
    void (^_delegate)(WDPPerceptionInfraredFrameSourceWatcher*, WDPPerceptionInfraredFrameSourceRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceRemovedEventArgs(
        void (^del)(WDPPerceptionInfraredFrameSourceWatcher*, WDPPerceptionInfraredFrameSourceRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher* arg0,
           ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionInfraredFrameSourceWatcher>(arg0),
                      _createRtProxy<WDPPerceptionInfraredFrameSourceRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*, IInspectable*>> {
    void (^_delegate)(WDPPerceptionInfraredFrameSource*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object(void (^del)(WDPPerceptionInfraredFrameSource*,
                                                                                                          RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionInfraredFrameSource>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*,
                              ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs*>> {
    void (^_delegate)(WDPPerceptionInfraredFrameSource*, WDPPerceptionFrameSourcePropertiesChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs(
        void (^del)(WDPPerceptionInfraredFrameSource*, WDPPerceptionFrameSourcePropertiesChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource* arg0,
           ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPerceptionInfraredFrameSource>(arg0),
                      _createRtProxy<WDPPerceptionFrameSourcePropertiesChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
