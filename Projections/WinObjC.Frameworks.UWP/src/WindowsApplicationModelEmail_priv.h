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

// WindowsApplicationModelEmail_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModelAppointments_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsSecurityCryptographyCertificates_priv.h"
static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryOptionsFactory> WAEIEmailQueryOptionsFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipientFactory> WAEIEmailRecipientFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplateFactory> WAEIEmailIrmTemplateFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmInfoFactory> WAEIEmailIrmInfoFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachmentFactory2> WAEIEmailAttachmentFactory2_inst();
static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachmentFactory> WAEIEmailAttachmentFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics3> WAEIEmailManagerStatics3_inst();
ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics> WAEIEmailManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics2> WAEIEmailManagerStatics2_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_WAEEmailRecipient_create(IInspectable* val);
id RTProxiedIterableNSArray_WSCCCertificate_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailCertificateValidationStatus_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailConversation_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailFolder_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailMailbox_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailMailboxChange_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailMessage_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailRecipientResolutionResult_create(IInspectable* val);
id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WAEEmailAttachment_create(IInspectable* val);
id RTProxiedNSMutableArray_WAEEmailMailboxAction_create(IInspectable* val);
id RTProxiedNSMutableArray_WAEEmailRecipient_create(IInspectable* val);

@class Nullable_WAEEmailMailboxSmimeEncryptionAlgorithm, Nullable_WAEEmailMailboxSmimeSigningAlgorithm, Nullable_WFDateTime,
    Nullable_WFTimeSpan;
@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_WAEEmailRecipient, RTProxiedIterableNSArray_WSCCCertificate,
    RTProxiedNSArray_WAEEmailCertificateValidationStatus;
@class RTProxiedNSArray_WAEEmailConversation, RTProxiedNSArray_WAEEmailFolder, RTProxiedNSArray_WAEEmailMailbox,
    RTProxiedNSArray_WAEEmailMailboxChange;
@class RTProxiedNSArray_WAEEmailMessage, RTProxiedNSArray_WAEEmailRecipientResolutionResult, RTProxiedNSArray_WSCCCertificate,
    RTProxiedNSMutableArray_NSString;
@class RTProxiedNSMutableArray_WAEEmailAttachment, RTProxiedNSMutableArray_WAEEmailMailboxAction, RTProxiedNSMutableArray_WAEEmailRecipient;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailboxSyncManager_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailboxSyncManager_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailboxSyncManager_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Email::EmailMailboxSyncManager*, IInspectable*>> {
    void (^_delegate)(WAEEmailMailboxSyncManager*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailboxSyncManager_System_Object(void (^del)(WAEEmailMailboxSyncManager*,
                                                                                                        RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailboxSyncManager_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEEmailMailboxSyncManager>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailbox_Windows_ApplicationModel_Email_EmailMailboxChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailbox_Windows_ApplicationModel_Email_EmailMailboxChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailbox_Windows_ApplicationModel_Email_EmailMailboxChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Email::EmailMailbox*,
                                                       ABI::Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs*>> {
    void (^_delegate)(WAEEmailMailbox*, WAEEmailMailboxChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailbox_Windows_ApplicationModel_Email_EmailMailboxChangedEventArgs(
        void (^del)(WAEEmailMailbox*, WAEEmailMailboxChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailbox_Windows_ApplicationModel_Email_EmailMailboxChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Email::IEmailMailbox* arg0,
                                             ABI::Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEEmailMailbox>(arg0), _createRtProxy<WAEEmailMailboxChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
