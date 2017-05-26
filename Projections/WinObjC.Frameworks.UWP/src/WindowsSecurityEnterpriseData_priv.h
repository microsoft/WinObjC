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

// WindowsSecurityEnterpriseData_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfoFactory> WSEIProtectionPolicyAuditInfoFactory_inst();
ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics> WSEIProtectionPolicyManagerStatics_inst();
ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics2> WSEIProtectionPolicyManagerStatics2_inst();
ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics3> WSEIProtectionPolicyManagerStatics3_inst();
ComPtr<ABI::Windows::Security::EnterpriseData::IFileRevocationManagerStatics> WSEIFileRevocationManagerStatics_inst();
ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionManagerStatics> WSEIFileProtectionManagerStatics_inst();
ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionManagerStatics2> WSEIFileProtectionManagerStatics2_inst();
ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionManagerStatics> WSEIDataProtectionManagerStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedNSArray_NSString;

#ifndef __EventHandler_System_Object__DEFINED
#define __EventHandler_System_Object__DEFINED
class EventHandler_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IEventHandler<IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    EventHandler_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~EventHandler_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_Security_EnterpriseData_ProtectedAccessResumedEventArgs__DEFINED
#define __EventHandler_Windows_Security_EnterpriseData_ProtectedAccessResumedEventArgs__DEFINED
class EventHandler_Windows_Security_EnterpriseData_ProtectedAccessResumedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Security::EnterpriseData::ProtectedAccessResumedEventArgs*>> {
    void (^_delegate)(RTObject*, WSEProtectedAccessResumedEventArgs*);

public:
    EventHandler_Windows_Security_EnterpriseData_ProtectedAccessResumedEventArgs(void (^del)(RTObject*,
                                                                                             WSEProtectedAccessResumedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Security_EnterpriseData_ProtectedAccessResumedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Security::EnterpriseData::IProtectedAccessResumedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WSEProtectedAccessResumedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_Security_EnterpriseData_ProtectedAccessSuspendingEventArgs__DEFINED
#define __EventHandler_Windows_Security_EnterpriseData_ProtectedAccessSuspendingEventArgs__DEFINED
class EventHandler_Windows_Security_EnterpriseData_ProtectedAccessSuspendingEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs*>> {
    void (^_delegate)(RTObject*, WSEProtectedAccessSuspendingEventArgs*);

public:
    EventHandler_Windows_Security_EnterpriseData_ProtectedAccessSuspendingEventArgs(void (^del)(RTObject*,
                                                                                                WSEProtectedAccessSuspendingEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Security_EnterpriseData_ProtectedAccessSuspendingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WSEProtectedAccessSuspendingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_Security_EnterpriseData_ProtectedContentRevokedEventArgs__DEFINED
#define __EventHandler_Windows_Security_EnterpriseData_ProtectedContentRevokedEventArgs__DEFINED
class EventHandler_Windows_Security_EnterpriseData_ProtectedContentRevokedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Security::EnterpriseData::ProtectedContentRevokedEventArgs*>> {
    void (^_delegate)(RTObject*, WSEProtectedContentRevokedEventArgs*);

public:
    EventHandler_Windows_Security_EnterpriseData_ProtectedContentRevokedEventArgs(void (^del)(RTObject*,
                                                                                              WSEProtectedContentRevokedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Security_EnterpriseData_ProtectedContentRevokedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Security::EnterpriseData::IProtectedContentRevokedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WSEProtectedContentRevokedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
