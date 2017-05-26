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

// WindowsApplicationModelEmailDataProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Email.DataProvider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelEmailDataProvider.h"
#include "WindowsApplicationModelEmailDataProvider_priv.h"

@implementation WAEDEmailDataProviderConnection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addMailboxSyncRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                 WAEDEmailMailboxSyncManagerSyncRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_MailboxSyncRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSyncManagerSyncRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMailboxSyncRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MailboxSyncRequested(token));
}

- (EventRegistrationToken)addDownloadMessageRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                     WAEDEmailMailboxDownloadMessageRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_DownloadMessageRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadMessageRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDownloadMessageRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DownloadMessageRequested(token));
}

- (EventRegistrationToken)addDownloadAttachmentRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                        WAEDEmailMailboxDownloadAttachmentRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_DownloadAttachmentRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDownloadAttachmentRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDownloadAttachmentRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DownloadAttachmentRequested(token));
}

- (EventRegistrationToken)addCreateFolderRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                  WAEDEmailMailboxCreateFolderRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_CreateFolderRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxCreateFolderRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCreateFolderRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CreateFolderRequested(token));
}

- (EventRegistrationToken)addDeleteFolderRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                  WAEDEmailMailboxDeleteFolderRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_DeleteFolderRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxDeleteFolderRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDeleteFolderRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DeleteFolderRequested(token));
}

- (EventRegistrationToken)addEmptyFolderRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                 WAEDEmailMailboxEmptyFolderRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_EmptyFolderRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxEmptyFolderRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEmptyFolderRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EmptyFolderRequested(token));
}

- (EventRegistrationToken)addMoveFolderRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                WAEDEmailMailboxMoveFolderRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_MoveFolderRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxMoveFolderRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMoveFolderRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MoveFolderRequested(token));
}

- (EventRegistrationToken)addUpdateMeetingResponseRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                           WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_UpdateMeetingResponseRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxUpdateMeetingResponseRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdateMeetingResponseRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UpdateMeetingResponseRequested(token));
}

- (EventRegistrationToken)addForwardMeetingRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                    WAEDEmailMailboxForwardMeetingRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ForwardMeetingRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxForwardMeetingRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeForwardMeetingRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ForwardMeetingRequested(token));
}

- (EventRegistrationToken)addProposeNewTimeForMeetingRequestedEvent:
    (void (^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ProposeNewTimeForMeetingRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxProposeNewTimeForMeetingRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProposeNewTimeForMeetingRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ProposeNewTimeForMeetingRequested(token));
}

- (EventRegistrationToken)addSetAutoReplySettingsRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                          WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_SetAutoReplySettingsRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxSetAutoReplySettingsRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSetAutoReplySettingsRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SetAutoReplySettingsRequested(token));
}

- (EventRegistrationToken)addGetAutoReplySettingsRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                          WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_GetAutoReplySettingsRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxGetAutoReplySettingsRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeGetAutoReplySettingsRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_GetAutoReplySettingsRequested(token));
}

- (EventRegistrationToken)addResolveRecipientsRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                       WAEDEmailMailboxResolveRecipientsRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ResolveRecipientsRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxResolveRecipientsRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeResolveRecipientsRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ResolveRecipientsRequested(token));
}

- (EventRegistrationToken)addValidateCertificatesRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                          WAEDEmailMailboxValidateCertificatesRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ValidateCertificatesRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxValidateCertificatesRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeValidateCertificatesRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ValidateCertificatesRequested(token));
}

- (EventRegistrationToken)addServerSearchReadBatchRequestedEvent:(void (^)(WAEDEmailDataProviderConnection*,
                                                                           WAEDEmailMailboxServerSearchReadBatchRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ServerSearchReadBatchRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Email_DataProvider_EmailDataProviderConnection_Windows_ApplicationModel_Email_DataProvider_EmailMailboxServerSearchReadBatchRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeServerSearchReadBatchRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ServerSearchReadBatchRequested(token));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

@end

@implementation WAEDEmailMailboxSyncManagerSyncRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxSyncManagerSyncRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxSyncManagerSyncRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxDownloadMessageRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxDownloadMessageRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxDownloadMessageRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxDownloadAttachmentRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxDownloadAttachmentRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxDownloadAttachmentRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxCreateFolderRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxCreateFolderRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxCreateFolderRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxDeleteFolderRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxDeleteFolderRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxDeleteFolderRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxEmptyFolderRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxEmptyFolderRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxEmptyFolderRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxMoveFolderRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxMoveFolderRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxMoveFolderRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxUpdateMeetingResponseRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxUpdateMeetingResponseRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxForwardMeetingRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxForwardMeetingRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxForwardMeetingRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxProposeNewTimeForMeetingRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxProposeNewTimeForMeetingRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxSetAutoReplySettingsRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxSetAutoReplySettingsRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxGetAutoReplySettingsRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxGetAutoReplySettingsRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxResolveRecipientsRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxResolveRecipientsRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxResolveRecipientsRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxValidateCertificatesRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxValidateCertificatesRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxValidateCertificatesRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxServerSearchReadBatchRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailMailboxServerSearchReadBatchRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailMailboxServerSearchReadBatchRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailDataProviderTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEDEmailDataProviderConnection*)connection {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Connection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEDEmailDataProviderConnection>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxSyncManagerSyncRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxDownloadMessageRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailMessageId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMessageId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxDownloadAttachmentRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailMessageId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMessageId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailAttachmentId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailAttachmentId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxCreateFolderRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)parentFolderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentFolderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(WAEEmailFolder*)folder {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(folder).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WAEEmailMailboxCreateFolderStatus)status {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync((ABI::Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus)status,
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxDeleteFolderRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailFolderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailFolderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WAEEmailMailboxDeleteFolderStatus)status {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync((ABI::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus)status,
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxEmptyFolderRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailFolderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailFolderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WAEEmailMailboxEmptyFolderStatus)status {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync((ABI::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus)status,
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxMoveFolderRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailFolderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailFolderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)newParentFolderId __attribute__((ns_returns_not_retained)) {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewParentFolderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)newFolderName __attribute__((ns_returns_not_retained)) {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewFolderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxUpdateMeetingResponseRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailMessageId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMessageId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailMeetingResponseType)response {
    ABI::Windows::ApplicationModel::Email::EmailMeetingResponseType unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Response(&unmarshalledReturn));
    return (WAEEmailMeetingResponseType)unmarshalledReturn;
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)sendUpdate {
    boolean unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SendUpdate(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxForwardMeetingRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailMessageId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMessageId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WAEEmailRecipient* */)recipients {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipient*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Recipients(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WAEEmailRecipient_create(unmarshalledReturn.Get());
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailMessageBodyKind)forwardHeaderType {
    ABI::Windows::ApplicationModel::Email::EmailMessageBodyKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForwardHeaderType(&unmarshalledReturn));
    return (WAEEmailMessageBodyKind)unmarshalledReturn;
}

- (NSString*)forwardHeader {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForwardHeader(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxProposeNewTimeForMeetingRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailMessageId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMessageId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)newStartTime __attribute__((ns_returns_not_retained)) {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewStartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)newDuration __attribute__((ns_returns_not_retained)) {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxSetAutoReplySettingsRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailMailboxAutoReplySettings*)autoReplySettings {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoReplySettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxAutoReplySettings>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxGetAutoReplySettingsRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailMailboxAutoReplyMessageResponseKind)requestedFormat {
    ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedFormat(&unmarshalledReturn));
    return (WAEEmailMailboxAutoReplyMessageResponseKind)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(WAEEmailMailboxAutoReplySettings*)autoReplySettings {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(autoReplySettings).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxResolveRecipientsRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* NSString * */)recipients {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Recipients(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(id<NSFastEnumeration> /* WAEEmailRecipientResolutionResult* */)resolutionResults {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*,
            ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult*>>::type>*>(
            ConvertToIterable<
                WAEEmailRecipientResolutionResult,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*,
                                                                  ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult*>>(
                resolutionResults)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxValidateCertificatesRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WSCCCertificate* */)certificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Certificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(id<NSFastEnumeration> /* WAEEmailCertificateValidationStatus */)validationStatuses {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>::type>*>(
            ConvertToIterable<WAEEmailCertificateValidationStatus, ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>(
                validationStatuses)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEDEmailMailboxServerSearchReadBatchRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)sessionId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emailFolderId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailFolderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Options(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailQueryOptions>(unmarshalledReturn.Get());
}

- (unsigned int)suggestedBatchSize {
    unsigned int unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuggestedBatchSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)saveMessageAsync:(WAEEmailMessage*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->SaveMessageAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(message).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WAEEmailBatchStatus)batchStatus {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync((ABI::Windows::ApplicationModel::Email::EmailBatchStatus)batchStatus,
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_WAEEmailCertificateValidationStatus_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>,
                                RTIterableObj<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus,
                                              IIterable<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>,
                                              WAEEmailCertificateValidationStatus,
                                              ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WAEEmailRecipientResolutionResult_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*>,
                                RTIterableObj<ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult*,
                                              IIterable<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*>,
                                              WAEEmailRecipientResolutionResult,
                                              ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAEEmailRecipient_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipient*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Email::IEmailRecipient*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipient*>,
                                                    WAEEmailRecipient,
                                                    ABI::Windows::ApplicationModel::Email::EmailRecipient*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                         RTArrayObj<ABI::Windows::Security::Cryptography::Certificates::ICertificate*,
                                                    IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                    WSCCCertificate,
                                                    ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
