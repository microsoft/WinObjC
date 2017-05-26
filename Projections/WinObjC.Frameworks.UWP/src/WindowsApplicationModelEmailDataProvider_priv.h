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

// WindowsApplicationModelEmailDataProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelEmail_priv.h"
#include "WindowsSecurityCryptographyCertificates_priv.h"

id RTProxiedIterableNSArray_WAEEmailCertificateValidationStatus_create(IInspectable* val);
id RTProxiedIterableNSArray_WAEEmailRecipientResolutionResult_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailRecipient_create(IInspectable* val);
id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val);

@class RTProxiedIterableNSArray_WAEEmailCertificateValidationStatus, RTProxiedIterableNSArray_WAEEmailRecipientResolutionResult,
    RTProxiedNSArray_NSString;
@class RTProxiedNSArray_WAEEmailRecipient, RTProxiedNSArray_WSCCCertificate;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxCreateFolderRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxCreateFolderRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxCreateFolderRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxCreateFolderRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxCreateFolderRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxCreateFolderRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxCreateFolderRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxCreateFolderRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDeleteFolderRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDeleteFolderRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDeleteFolderRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDeleteFolderRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDeleteFolderRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDeleteFolderRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDeleteFolderRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxDeleteFolderRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadAttachmentRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadAttachmentRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadAttachmentRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDownloadAttachmentRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadAttachmentRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDownloadAttachmentRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadAttachmentRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxDownloadAttachmentRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadMessageRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadMessageRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadMessageRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDownloadMessageRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadMessageRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDownloadMessageRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadMessageRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxDownloadMessageRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxEmptyFolderRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxEmptyFolderRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxEmptyFolderRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxEmptyFolderRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxEmptyFolderRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxEmptyFolderRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxEmptyFolderRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxEmptyFolderRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxForwardMeetingRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxForwardMeetingRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxForwardMeetingRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxForwardMeetingRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxForwardMeetingRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxForwardMeetingRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxForwardMeetingRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxForwardMeetingRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxGetAutoReplySettingsRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxGetAutoReplySettingsRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxGetAutoReplySettingsRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxGetAutoReplySettingsRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxGetAutoReplySettingsRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxMoveFolderRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxMoveFolderRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxMoveFolderRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxMoveFolderRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxMoveFolderRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxMoveFolderRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxMoveFolderRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxMoveFolderRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxProposeNewTimeForMeetingRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxProposeNewTimeForMeetingRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxProposeNewTimeForMeetingRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxProposeNewTimeForMeetingRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxProposeNewTimeForMeetingRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxResolveRecipientsRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxResolveRecipientsRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxResolveRecipientsRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxResolveRecipientsRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxResolveRecipientsRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxResolveRecipientsRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxResolveRecipientsRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxResolveRecipientsRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxServerSearchReadBatchRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxServerSearchReadBatchRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxServerSearchReadBatchRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxServerSearchReadBatchRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxServerSearchReadBatchRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxServerSearchReadBatchRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxServerSearchReadBatchRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxServerSearchReadBatchRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSetAutoReplySettingsRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSetAutoReplySettingsRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSetAutoReplySettingsRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSetAutoReplySettingsRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSetAutoReplySettingsRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSyncManagerSyncRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSyncManagerSyncRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSyncManagerSyncRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxSyncManagerSyncRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSyncManagerSyncRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxSyncManagerSyncRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSyncManagerSyncRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxSyncManagerSyncRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxUpdateMeetingResponseRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxUpdateMeetingResponseRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxUpdateMeetingResponseRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxUpdateMeetingResponseRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxUpdateMeetingResponseRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxValidateCertificatesRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxValidateCertificatesRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxValidateCertificatesRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs*>> {
    void (^_delegate)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxValidateCertificatesRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxValidateCertificatesRequestEventArgs(
        void (^del)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxValidateCertificatesRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxValidateCertificatesRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAEDEmailDataProviderConnection>(arg0),
                      _createRtProxy<WAEDEmailMailboxValidateCertificatesRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
