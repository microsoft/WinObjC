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

// WindowsMediaProtectionPlayReady_priv.h
// Forward decls for private object generation
#pragma once

// Can't create proxy instantiator for type: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadyLicense>

// Can't create proxy instantiator for type: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadyDomain>

// Can't create proxy instantiator for type: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Media.Protection.PlayReady.IPlayReadySecureStopServiceRequest>

#include "WindowsFoundationCollections_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsMediaCore_priv.h"
#include "WindowsMediaProtection_priv.h"
static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeaderFactory> WMPPIPlayReadyContentHeaderFactory_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentHeaderFactory2> WMPPIPlayReadyContentHeaderFactory2_inst();
ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyContentResolver> WMPPIPlayReadyContentResolver_inst();
ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseManagement> WMPPIPlayReadyLicenseManagement_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseIterableFactory> WMPPIPlayReadyLicenseIterableFactory_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyDomainIterableFactory> WMPPIPlayReadyDomainIterableFactory_inst();
ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics2> WMPPIPlayReadyStatics2_inst();
ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics> WMPPIPlayReadyStatics_inst();
ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics4> WMPPIPlayReadyStatics4_inst();
ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyStatics3> WMPPIPlayReadyStatics3_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequestFactory>
WMPPIPlayReadySecureStopServiceRequestFactory_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadySecureStopIterableFactory>
WMPPIPlayReadySecureStopIterableFactory_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::IPlayReadyLicenseSessionFactory> WMPPIPlayReadyLicenseSessionFactory_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::INDTCPMessengerFactory> WMPPINDTCPMessengerFactory_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchDescriptorFactory> WMPPINDLicenseFetchDescriptorFactory_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::INDCustomDataFactory> WMPPINDCustomDataFactory_inst();
static ComPtr<ABI::Windows::Media::Protection::PlayReady::INDClientFactory> WMPPINDClientFactory_inst();

id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val);
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_C_WFGUID_create(UINT32 size, GUID* val);
id RTProxiedNSArray_C_WMPPNDCertificateFeature_create(UINT32 size, ABI::Windows::Media::Protection::PlayReady::NDCertificateFeature* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WMCAudioStreamDescriptor_create(IInspectable* val);
id RTProxiedNSMutableArray_WMCVideoStreamDescriptor_create(IInspectable* val);

@class Nullable_WFDateTime, RTProxiedNSArray_C_NSString, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_C_WFGUID,
    RTProxiedNSArray_C_WMPPNDCertificateFeature;
@class RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_WMCAudioStreamDescriptor, RTProxiedNSMutableArray_WMCVideoStreamDescriptor;

#ifndef __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Protection::PlayReady::NDClient*, IInspectable*>> {
    void (^_delegate)(WMPPNDClient*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_System_Object(void (^del)(WMPPNDClient*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Protection::PlayReady::INDClient* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPNDClient>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDClosedCaptionDataReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDClosedCaptionDataReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDClosedCaptionDataReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Protection::PlayReady::NDClient*,
                              ABI::Windows::Media::Protection::PlayReady::INDClosedCaptionDataReceivedEventArgs*>> {
    void (^_delegate)(WMPPNDClient*, RTObject<WMPPINDClosedCaptionDataReceivedEventArgs>*);

public:
    ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDClosedCaptionDataReceivedEventArgs(
        void (^del)(WMPPNDClient*, RTObject<WMPPINDClosedCaptionDataReceivedEventArgs>*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDClosedCaptionDataReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Protection::PlayReady::INDClient* arg0,
           ABI::Windows::Media::Protection::PlayReady::INDClosedCaptionDataReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPNDClient>(arg0), _createRtProxy<WMPPINDClosedCaptionDataReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDLicenseFetchCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDLicenseFetchCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDLicenseFetchCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Protection::PlayReady::NDClient*,
                                                       ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchCompletedEventArgs*>> {
    void (^_delegate)(WMPPNDClient*, RTObject<WMPPINDLicenseFetchCompletedEventArgs>*);

public:
    ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDLicenseFetchCompletedEventArgs(
        void (^del)(WMPPNDClient*, RTObject<WMPPINDLicenseFetchCompletedEventArgs>*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDLicenseFetchCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Protection::PlayReady::INDClient* arg0,
                                             ABI::Windows::Media::Protection::PlayReady::INDLicenseFetchCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPNDClient>(arg0), _createRtProxy<WMPPINDLicenseFetchCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDProximityDetectionCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDProximityDetectionCompletedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDProximityDetectionCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Protection::PlayReady::NDClient*,
                              ABI::Windows::Media::Protection::PlayReady::INDProximityDetectionCompletedEventArgs*>> {
    void (^_delegate)(WMPPNDClient*, RTObject<WMPPINDProximityDetectionCompletedEventArgs>*);

public:
    ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDProximityDetectionCompletedEventArgs(
        void (^del)(WMPPNDClient*, RTObject<WMPPINDProximityDetectionCompletedEventArgs>*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDProximityDetectionCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Protection::PlayReady::INDClient* arg0,
           ABI::Windows::Media::Protection::PlayReady::INDProximityDetectionCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPNDClient>(arg0), _createRtProxy<WMPPINDProximityDetectionCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDRegistrationCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDRegistrationCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDRegistrationCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Protection::PlayReady::NDClient*,
                                                       ABI::Windows::Media::Protection::PlayReady::INDRegistrationCompletedEventArgs*>> {
    void (^_delegate)(WMPPNDClient*, RTObject<WMPPINDRegistrationCompletedEventArgs>*);

public:
    ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDRegistrationCompletedEventArgs(
        void (^del)(WMPPNDClient*, RTObject<WMPPINDRegistrationCompletedEventArgs>*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Protection_PlayReady_NDClient_Windows_Media_Protection_PlayReady_INDRegistrationCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Protection::PlayReady::INDClient* arg0,
                                             ABI::Windows::Media::Protection::PlayReady::INDRegistrationCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPNDClient>(arg0), _createRtProxy<WMPPINDRegistrationCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
