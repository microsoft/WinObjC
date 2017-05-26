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

// WindowsApplicationModelChat_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsSecurityCredentials_priv.h"
#include "WindowsStorageStreams_priv.h"
static ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachmentFactory> WACIChatMessageAttachmentFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManager2Statics> WACIChatMessageManager2Statics_inst();
ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManagerStatic> WACIChatMessageManagerStatic_inst();
ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManagerStatics3> WACIChatMessageManagerStatics3_inst();
ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageBlockingStatic> WACIChatMessageBlockingStatic_inst();
ComPtr<ABI::Windows::ApplicationModel::Chat::IChatCapabilitiesManagerStatics> WACIChatCapabilitiesManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsManagerStatics> WACIRcsManagerStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WACIChatItem_create(IInspectable* val);
id RTProxiedNSArray_WACChatConversation_create(IInspectable* val);
id RTProxiedNSArray_WACChatMessage_create(IInspectable* val);
id RTProxiedNSArray_WACChatMessageChange_create(IInspectable* val);
id RTProxiedNSArray_WACChatMessageTransport_create(IInspectable* val);
id RTProxiedNSArray_WACRcsEndUserMessageAction_create(IInspectable* val);
id RTProxiedNSArray_WACRcsTransport_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WACChatMessageStatus_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WACChatMessageAttachment_create(IInspectable* val);
id RTProxiedNSMutableArray_WACChatRecipientDeliveryInfo_create(IInspectable* val);

@class Nullable_UInt32, Nullable_WFDateTime, RTProxiedIterableNSArray_NSString, RTProxiedNSArray_RTObject_WACIChatItem,
    RTProxiedNSArray_WACChatConversation;
@class RTProxiedNSArray_WACChatMessage, RTProxiedNSArray_WACChatMessageChange, RTProxiedNSArray_WACChatMessageTransport,
    RTProxiedNSArray_WACRcsEndUserMessageAction;
@class RTProxiedNSArray_WACRcsTransport, RTProxiedNSDictionary_NSString_RTObject, RTProxiedNSDictionary_NSString_WACChatMessageStatus;
@class RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_WACChatMessageAttachment,
    RTProxiedNSMutableArray_WACChatRecipientDeliveryInfo;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Chat_ChatConversation_Windows_ApplicationModel_Chat_RemoteParticipantComposingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Chat_ChatConversation_Windows_ApplicationModel_Chat_RemoteParticipantComposingChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Chat_ChatConversation_Windows_ApplicationModel_Chat_RemoteParticipantComposingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Chat::ChatConversation*,
                                                       ABI::Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs*>> {
    void (^_delegate)(WACChatConversation*, WACRemoteParticipantComposingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Chat_ChatConversation_Windows_ApplicationModel_Chat_RemoteParticipantComposingChangedEventArgs(
        void (^del)(WACChatConversation*, WACRemoteParticipantComposingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Chat_ChatConversation_Windows_ApplicationModel_Chat_RemoteParticipantComposingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Chat::IChatConversation* arg0,
           ABI::Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACChatConversation>(arg0), _createRtProxy<WACRemoteParticipantComposingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Chat::ChatMessageStore*,
                                                       ABI::Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs*>> {
    void (^_delegate)(WACChatMessageStore*, WACChatMessageChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageChangedEventArgs(
        void (^del)(WACChatMessageStore*, WACChatMessageChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Chat::IChatMessageStore* arg0,
                                             ABI::Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACChatMessageStore>(arg0), _createRtProxy<WACChatMessageChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageStoreChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageStoreChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageStoreChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Chat::ChatMessageStore*,
                                                       ABI::Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs*>> {
    void (^_delegate)(WACChatMessageStore*, WACChatMessageStoreChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageStoreChangedEventArgs(
        void (^del)(WACChatMessageStore*, WACChatMessageStoreChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageStoreChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Chat::IChatMessageStore* arg0,
                                             ABI::Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACChatMessageStore>(arg0), _createRtProxy<WACChatMessageStoreChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Chat_RcsEndUserMessageManager_Windows_ApplicationModel_Chat_RcsEndUserMessageAvailableEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Chat_RcsEndUserMessageManager_Windows_ApplicationModel_Chat_RcsEndUserMessageAvailableEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Chat_RcsEndUserMessageManager_Windows_ApplicationModel_Chat_RcsEndUserMessageAvailableEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageManager*,
                                                       ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs*>> {
    void (^_delegate)(WACRcsEndUserMessageManager*, WACRcsEndUserMessageAvailableEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Chat_RcsEndUserMessageManager_Windows_ApplicationModel_Chat_RcsEndUserMessageAvailableEventArgs(
        void (^del)(WACRcsEndUserMessageManager*, WACRcsEndUserMessageAvailableEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Chat_RcsEndUserMessageManager_Windows_ApplicationModel_Chat_RcsEndUserMessageAvailableEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageManager* arg0,
                                             ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACRcsEndUserMessageManager>(arg0), _createRtProxy<WACRcsEndUserMessageAvailableEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Chat_RcsTransport_Windows_ApplicationModel_Chat_RcsServiceKindSupportedChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Chat_RcsTransport_Windows_ApplicationModel_Chat_RcsServiceKindSupportedChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Chat_RcsTransport_Windows_ApplicationModel_Chat_RcsServiceKindSupportedChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Chat::RcsTransport*,
                                                       ABI::Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs*>> {
    void (^_delegate)(WACRcsTransport*, WACRcsServiceKindSupportedChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Chat_RcsTransport_Windows_ApplicationModel_Chat_RcsServiceKindSupportedChangedEventArgs(
        void (^del)(WACRcsTransport*, WACRcsServiceKindSupportedChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Chat_RcsTransport_Windows_ApplicationModel_Chat_RcsServiceKindSupportedChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Chat::IRcsTransport* arg0,
           ABI::Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACRcsTransport>(arg0), _createRtProxy<WACRcsServiceKindSupportedChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
