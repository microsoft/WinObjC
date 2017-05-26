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

// WindowsDevicesSms_priv.h
// Forward decls for private object generation
#pragma once

// Can't create proxy instantiator for type: Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.ISmsMessage>

// Can't create proxy instantiator for type: Can't marshal
// Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>

// Can't create proxy instantiator for type: Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.SmsDevice>

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessageStatics> WDSISmsTextMessageStatics_inst();
ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceStatics2> WDSISmsDeviceStatics2_inst();
ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceStatics> WDSISmsDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::Sms::ISmsDevice2Statics> WDSISmsDevice2Statics_inst();
static ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRuleFactory> WDSISmsFilterRuleFactory_inst();
static ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRulesFactory> WDSISmsFilterRulesFactory_inst();
ComPtr<ABI::Windows::Devices::Sms::ISmsMessageRegistrationStatics> WDSISmsMessageRegistrationStatics_inst();
@interface WDSSmsEncodedLength (Internal)
+ (instancetype)createWith:(ABI::Windows::Devices::Sms::SmsEncodedLength)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Devices::Sms::SmsEncodedLength*)internalStruct;
@end
inline WDSSmsEncodedLength* WDSSmsEncodedLength_create(ABI::Windows::Devices::Sms::SmsEncodedLength val) {
    return [WDSSmsEncodedLength createWith:val];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_Int32_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WDSISmsBinaryMessage_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WDSISmsMessage_create(IInspectable* val);
id RTProxiedNSArray_WDSSmsMessageRegistration_create(IInspectable* val);
id RTProxiedNSMutableArray_Int32_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WDSSmsBroadcastType_create(IInspectable* val);
id RTProxiedNSMutableArray_WDSSmsFilterRule_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class Nullable_Int32, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_Int32, RTProxiedNSArray_RTObject_WDSISmsBinaryMessage,
    RTProxiedNSArray_RTObject_WDSISmsMessage;
@class RTProxiedNSArray_WDSSmsMessageRegistration, RTProxiedNSMutableArray_Int32, RTProxiedNSMutableArray_NSString,
    RTProxiedNSMutableArray_WDSSmsBroadcastType;
@class RTProxiedNSMutableArray_WDSSmsFilterRule, RTProxiedNSMutableDictionary_NSString_NSString;

#ifndef __ITypedEventHandler_Windows_Devices_Sms_SmsDevice2_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sms_SmsDevice2_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Sms_SmsDevice2_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sms::SmsDevice2*, IInspectable*>> {
    void (^_delegate)(WDSSmsDevice2*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Sms_SmsDevice2_System_Object(void (^del)(WDSSmsDevice2*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sms_SmsDevice2_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sms::ISmsDevice2* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmsDevice2>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sms_SmsMessageRegistration_Windows_Devices_Sms_SmsMessageReceivedTriggerDetails__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sms_SmsMessageRegistration_Windows_Devices_Sms_SmsMessageReceivedTriggerDetails__DEFINED
class ITypedEventHandler_Windows_Devices_Sms_SmsMessageRegistration_Windows_Devices_Sms_SmsMessageReceivedTriggerDetails
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sms::SmsMessageRegistration*,
                                                                       ABI::Windows::Devices::Sms::SmsMessageReceivedTriggerDetails*>> {
    void (^_delegate)(WDSSmsMessageRegistration*, WDSSmsMessageReceivedTriggerDetails*);

public:
    ITypedEventHandler_Windows_Devices_Sms_SmsMessageRegistration_Windows_Devices_Sms_SmsMessageReceivedTriggerDetails(
        void (^del)(WDSSmsMessageRegistration*, WDSSmsMessageReceivedTriggerDetails*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sms_SmsMessageRegistration_Windows_Devices_Sms_SmsMessageReceivedTriggerDetails() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sms::ISmsMessageRegistration* arg0,
                                             ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmsMessageRegistration>(arg0), _createRtProxy<WDSSmsMessageReceivedTriggerDetails>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WDSSmsDeviceStatusChangedEventHandler_shim__DEFINED
#define __WDSSmsDeviceStatusChangedEventHandler_shim__DEFINED
class WDSSmsDeviceStatusChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Devices::Sms::ISmsDeviceStatusChangedEventHandler> {
    void (^_delegate)(WDSSmsDevice*);

public:
    WDSSmsDeviceStatusChangedEventHandler_shim(void (^del)(WDSSmsDevice*)) : _delegate([del copy]) {
    }
    ~WDSSmsDeviceStatusChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sms::ISmsDevice* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmsDevice>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WDSSmsMessageReceivedEventHandler_shim__DEFINED
#define __WDSSmsMessageReceivedEventHandler_shim__DEFINED
class WDSSmsMessageReceivedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Devices::Sms::ISmsMessageReceivedEventHandler> {
    void (^_delegate)(WDSSmsDevice*, WDSSmsMessageReceivedEventArgs*);

public:
    WDSSmsMessageReceivedEventHandler_shim(void (^del)(WDSSmsDevice*, WDSSmsMessageReceivedEventArgs*)) : _delegate([del copy]) {
    }
    ~WDSSmsMessageReceivedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sms::ISmsDevice* arg0,
                                             ABI::Windows::Devices::Sms::ISmsMessageReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmsDevice>(arg0), _createRtProxy<WDSSmsMessageReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WFAsyncActionCompletedHandler_shim__DEFINED
#define __WFAsyncActionCompletedHandler_shim__DEFINED
class WFAsyncActionCompletedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IAsyncActionCompletedHandler> {
    void (^_delegate)(RTObject<WFIAsyncAction>*, WFAsyncStatus);

public:
    WFAsyncActionCompletedHandler_shim(void (^del)(RTObject<WFIAsyncAction>*, WFAsyncStatus)) : _delegate([del copy]) {
    }
    ~WFAsyncActionCompletedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Foundation::IAsyncAction* arg0, AsyncStatus arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WFIAsyncAction>(arg0), (unsigned)arg1);
            return 0;
        };
    }
};
#endif
