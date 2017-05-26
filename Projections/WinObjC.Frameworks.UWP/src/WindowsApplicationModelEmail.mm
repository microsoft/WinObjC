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

// WindowsApplicationModelEmail.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Email.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelEmail.h"
#include "WindowsApplicationModelEmail_priv.h"

@implementation WAEEmailMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailMessage").Get(), &out));
    return [_createRtProxy<WAEEmailMessage>(out.Get()) retain];
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubject:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subject(nsStrToHstr(value).Get()));
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setBody:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Body(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WAEEmailRecipient* */)to {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Email::EmailRecipient*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAEEmailRecipient_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAEEmailRecipient* */)cC {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Email::EmailRecipient*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_CC(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAEEmailRecipient_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAEEmailRecipient* */)bcc {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Email::EmailRecipient*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bcc(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAEEmailRecipient_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAEEmailAttachment* */)attachments {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Email::EmailAttachment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attachments(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAEEmailAttachment_create(unmarshalledReturn.Get());
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (NSString*)mailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)conversationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConversationId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)folderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FolderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)allowInternetImages {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowInternetImages(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowInternetImages:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowInternetImages((boolean)value));
}

- (uint64_t)changeNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WAEEmailMessageDownloadState)downloadState {
    ABI::Windows::ApplicationModel::Email::EmailMessageDownloadState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DownloadState(&unmarshalledReturn));
    return (WAEEmailMessageDownloadState)unmarshalledReturn;
}

- (void)setDownloadState:(WAEEmailMessageDownloadState)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DownloadState((ABI::Windows::ApplicationModel::Email::EmailMessageDownloadState)value));
}

- (unsigned int)estimatedDownloadSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EstimatedDownloadSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setEstimatedDownloadSizeInBytes:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_EstimatedDownloadSizeInBytes(value));
}

- (WAEEmailFlagState)flagState {
    ABI::Windows::ApplicationModel::Email::EmailFlagState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlagState(&unmarshalledReturn));
    return (WAEEmailFlagState)unmarshalledReturn;
}

- (void)setFlagState:(WAEEmailFlagState)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_FlagState((ABI::Windows::ApplicationModel::Email::EmailFlagState)value));
}

- (BOOL)hasPartialBodies {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasPartialBodies(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WAEEmailImportance)importance {
    ABI::Windows::ApplicationModel::Email::EmailImportance unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Importance(&unmarshalledReturn));
    return (WAEEmailImportance)unmarshalledReturn;
}

- (void)setImportance:(WAEEmailImportance)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Importance((ABI::Windows::ApplicationModel::Email::EmailImportance)value));
}

- (NSString*)inResponseToMessageId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_InResponseToMessageId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailIrmInfo*)irmInfo {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IrmInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailIrmInfo>(unmarshalledReturn.Get());
}

- (void)setIrmInfo:(WAEEmailIrmInfo*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IrmInfo(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(value).Get()));
}

- (BOOL)isDraftMessage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDraftMessage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isRead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsRead:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRead((boolean)value));
}

- (BOOL)isSeen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSeen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSeen:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSeen((boolean)value));
}

- (BOOL)isServerSearchMessage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsServerSearchMessage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isSmartSendable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSmartSendable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)messageClass {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMessageClass:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MessageClass(nsStrToHstr(value).Get()));
}

- (NSString*)normalizedSubject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_NormalizedSubject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)originalCodePage {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalCodePage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOriginalCodePage:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_OriginalCodePage(value));
}

- (NSString*)preview {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Preview(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPreview:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Preview(nsStrToHstr(value).Get()));
}

- (WAEEmailMessageResponseKind)lastResponseKind {
    ABI::Windows::ApplicationModel::Email::EmailMessageResponseKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastResponseKind(&unmarshalledReturn));
    return (WAEEmailMessageResponseKind)unmarshalledReturn;
}

- (void)setLastResponseKind:(WAEEmailMessageResponseKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastResponseKind((ABI::Windows::ApplicationModel::Email::EmailMessageResponseKind)value));
}

- (WAEEmailRecipient*)sender {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipient> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sender(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailRecipient>(unmarshalledReturn.Get());
}

- (void)setSender:(WAEEmailRecipient*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Sender(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipient>(value).Get()));
}

- (id /* WFDateTime* */)sentTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SentTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setSentTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SentTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WAEEmailMeetingInfo*)meetingInfo {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MeetingInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMeetingInfo>(unmarshalledReturn.Get());
}

- (void)setMeetingInfo:(WAEEmailMeetingInfo*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MeetingInfo(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)getBodyStream:(WAEEmailMessageBodyKind)type {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetBodyStream((ABI::Windows::ApplicationModel::Email::EmailMessageBodyKind)type, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setBodyStream:(WAEEmailMessageBodyKind)type stream:(RTObject<WSSIRandomAccessStreamReference>*)stream {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage2>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetBodyStream((ABI::Windows::ApplicationModel::Email::EmailMessageBodyKind)type,
                                _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(stream).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)smimeData {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage3>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmimeData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setSmimeData:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage3>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmimeData(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (WAEEmailMessageSmimeKind)smimeKind {
    ABI::Windows::ApplicationModel::Email::EmailMessageSmimeKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage3>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmimeKind(&unmarshalledReturn));
    return (WAEEmailMessageSmimeKind)unmarshalledReturn;
}

- (void)setSmimeKind:(WAEEmailMessageSmimeKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage3>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmimeKind((ABI::Windows::ApplicationModel::Email::EmailMessageSmimeKind)value));
}

@end

@implementation WAEEmailStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)findMailboxesAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailMailbox* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailbox*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindMailboxesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailbox*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailbox*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailbox*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAEEmailMailbox_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WAEEmailConversationReader*)getConversationReader {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailConversationReader>(unmarshalledReturn.Get());
}

- (WAEEmailConversationReader*)getConversationReaderWithOptions:(WAEEmailQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationReaderWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(options).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailConversationReader>(unmarshalledReturn.Get());
}

- (WAEEmailMessageReader*)getMessageReader {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMessageReader>(unmarshalledReturn.Get());
}

- (WAEEmailMessageReader*)getMessageReaderWithOptions:(WAEEmailQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetMessageReaderWithOptions(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(options).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMessageReader>(unmarshalledReturn.Get());
}

- (void)getMailboxAsync:(NSString*)id success:(void (^)(WAEEmailMailbox*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailbox*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetMailboxAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMailbox*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailbox*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailbox> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMailbox>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getConversationAsync:(NSString*)id success:(void (^)(WAEEmailConversation*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailConversation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailConversation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailConversation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailConversation>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFolderAsync:(NSString*)id success:(void (^)(WAEEmailFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailFolder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailFolder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Email::IEmailFolder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAEEmailFolder>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getMessageAsync:(NSString*)id success:(void (^)(WAEEmailMessage*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMessage*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessage*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMessage>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)createMailboxAsync:(NSString*)accountName
            accountAddress:(NSString*)accountAddress
                   success:(void (^)(WAEEmailMailbox*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailbox*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateMailboxAsync(nsStrToHstr(accountName).Get(), nsStrToHstr(accountAddress).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMailbox*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailbox*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailbox> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMailbox>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)createMailboxInAccountAsync:(NSString*)accountName
                     accountAddress:(NSString*)accountAddress
                  userDataAccountId:(NSString*)userDataAccountId
                            success:(void (^)(WAEEmailMailbox*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailbox*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailStore>(self);
    THROW_NS_IF_FAILED(_comInst->CreateMailboxInAccountAsync(nsStrToHstr(accountName).Get(),
                                                             nsStrToHstr(accountAddress).Get(),
                                                             nsStrToHstr(userDataAccountId).Get(),
                                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMailbox*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailbox*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailbox> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMailbox>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WAEEmailManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)showComposeNewEmailAsync:(WAEEmailMessage*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->ShowComposeNewEmailAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(message).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)requestStoreAsync:(WAEEmailStoreAccessType)accessType
                  success:(void (^)(WAEEmailStore*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailStore*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestStoreAsync((ABI::Windows::ApplicationModel::Email::EmailStoreAccessType)accessType, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailStore*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailStore*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Email::IEmailStore> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAEEmailStore>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAEEmailMailbox

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailbox> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEEmailMailboxCapabilities*)capabilities {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capabilities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxCapabilities>(unmarshalledReturn.Get());
}

- (WAEEmailMailboxChangeTracker*)changeTracker {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeTracker(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxChangeTracker>(unmarshalledReturn.Get());
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isOwnedByCurrentApp {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOwnedByCurrentApp(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDataEncryptedUnderLock {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDataEncryptedUnderLock(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)mailAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_MailAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMailAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->put_MailAddress(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)mailAddressAliases {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_MailAddressAliases(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WAEEmailMailboxOtherAppReadAccess)otherAppReadAccess {
    ABI::Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherAppReadAccess(&unmarshalledReturn));
    return (WAEEmailMailboxOtherAppReadAccess)unmarshalledReturn;
}

- (void)setOtherAppReadAccess:(WAEEmailMailboxOtherAppReadAccess)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->put_OtherAppReadAccess((ABI::Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess)value));
}

- (WAEEmailMailboxOtherAppWriteAccess)otherAppWriteAccess {
    ABI::Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherAppWriteAccess(&unmarshalledReturn));
    return (WAEEmailMailboxOtherAppWriteAccess)unmarshalledReturn;
}

- (void)setOtherAppWriteAccess:(WAEEmailMailboxOtherAppWriteAccess)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->put_OtherAppWriteAccess((ABI::Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess)value));
}

- (WAEEmailMailboxPolicies*)policies {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_Policies(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxPolicies>(unmarshalledReturn.Get());
}

- (NSString*)sourceDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailMailboxSyncManager*)syncManager {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_SyncManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxSyncManager>(unmarshalledReturn.Get());
}

- (NSString*)userDataAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserDataAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailConversationReader*)getConversationReader {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailConversationReader>(unmarshalledReturn.Get());
}

- (WAEEmailConversationReader*)getConversationReaderWithOptions:(WAEEmailQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationReaderWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(options).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailConversationReader>(unmarshalledReturn.Get());
}

- (WAEEmailMessageReader*)getMessageReader {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMessageReader>(unmarshalledReturn.Get());
}

- (WAEEmailMessageReader*)getMessageReaderWithOptions:(WAEEmailQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetMessageReaderWithOptions(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(options).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMessageReader>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getConversationAsync:(NSString*)id success:(void (^)(WAEEmailConversation*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailConversation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailConversation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailConversation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailConversation>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFolderAsync:(NSString*)id success:(void (^)(WAEEmailFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailFolder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailFolder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Email::IEmailFolder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAEEmailFolder>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getMessageAsync:(NSString*)id success:(void (^)(WAEEmailMessage*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMessage*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessage*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMessage>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getSpecialFolderAsync:(WAEEmailSpecialFolderKind)folderType
                      success:(void (^)(WAEEmailFolder*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetSpecialFolderAsync((ABI::Windows::ApplicationModel::Email::EmailSpecialFolderKind)folderType, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailFolder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailFolder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Email::IEmailFolder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAEEmailFolder>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)saveAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->SaveAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markMessageAsSeenAsync:(NSString*)messageId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->MarkMessageAsSeenAsync(nsStrToHstr(messageId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markFolderAsSeenAsync:(NSString*)folderId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->MarkFolderAsSeenAsync(nsStrToHstr(folderId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markMessageReadAsync:(NSString*)messageId isRead:(BOOL)isRead {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->MarkMessageReadAsync(nsStrToHstr(messageId).Get(), (boolean)isRead, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)changeMessageFlagStateAsync:(NSString*)messageId flagState:(WAEEmailFlagState)flagState {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->ChangeMessageFlagStateAsync(nsStrToHstr(messageId).Get(),
                                                             (ABI::Windows::ApplicationModel::Email::EmailFlagState)flagState,
                                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)tryMoveMessageAsync:(NSString*)messageId
          newParentFolderId:(NSString*)newParentFolderId
                    success:(void (^)(BOOL))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryMoveMessageAsync(nsStrToHstr(messageId).Get(), nsStrToHstr(newParentFolderId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryMoveFolderAsync:(NSString*)folderId
         newParentFolderId:(NSString*)newParentFolderId
                   success:(void (^)(BOOL))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryMoveFolderAsync(nsStrToHstr(folderId).Get(), nsStrToHstr(newParentFolderId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryMoveFolderWithNewNameAsync:(NSString*)folderId
                    newParentFolderId:(NSString*)newParentFolderId
                        newFolderName:(NSString*)newFolderName
                              success:(void (^)(BOOL))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->TryMoveFolderWithNewNameAsync(nsStrToHstr(folderId).Get(),
                                                               nsStrToHstr(newParentFolderId).Get(),
                                                               nsStrToHstr(newFolderName).Get(),
                                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)deleteMessageAsync:(NSString*)messageId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteMessageAsync(nsStrToHstr(messageId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markFolderSyncEnabledAsync:(NSString*)folderId isSyncEnabled:(BOOL)isSyncEnabled {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(
        _comInst->MarkFolderSyncEnabledAsync(nsStrToHstr(folderId).Get(), (boolean)isSyncEnabled, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)sendMessageAsync:(WAEEmailMessage*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessageAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(message).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)saveDraftAsync:(WAEEmailMessage*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->SaveDraftAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(message).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)downloadMessageAsync:(NSString*)messageId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->DownloadMessageAsync(nsStrToHstr(messageId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)downloadAttachmentAsync:(NSString*)attachmentId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->DownloadAttachmentAsync(nsStrToHstr(attachmentId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)createResponseMessageAsync:(NSString*)messageId
                      responseType:(WAEEmailMessageResponseKind)responseType
                           subject:(NSString*)subject
                responseHeaderType:(WAEEmailMessageBodyKind)responseHeaderType
                    responseHeader:(NSString*)responseHeader
                           success:(void (^)(WAEEmailMessage*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->CreateResponseMessageAsync(nsStrToHstr(messageId).Get(),
                                                            (ABI::Windows::ApplicationModel::Email::EmailMessageResponseKind)responseType,
                                                            nsStrToHstr(subject).Get(),
                                                            (ABI::Windows::ApplicationModel::Email::EmailMessageBodyKind)responseHeaderType,
                                                            nsStrToHstr(responseHeader).Get(),
                                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMessage*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessage*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMessage>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryUpdateMeetingResponseAsync:(WAEEmailMessage*)meeting
                             response:(WAEEmailMeetingResponseType)response
                              subject:(NSString*)subject
                              comment:(NSString*)comment
                           sendUpdate:(BOOL)sendUpdate
                              success:(void (^)(BOOL))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryUpdateMeetingResponseAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(meeting).Get(),
                                                (ABI::Windows::ApplicationModel::Email::EmailMeetingResponseType)response,
                                                nsStrToHstr(subject).Get(),
                                                nsStrToHstr(comment).Get(),
                                                (boolean)sendUpdate,
                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryForwardMeetingAsync:(WAEEmailMessage*)meeting
                    recipients:(id<NSFastEnumeration> /* WAEEmailRecipient* */)recipients
                       subject:(NSString*)subject
             forwardHeaderType:(WAEEmailMessageBodyKind)forwardHeaderType
                 forwardHeader:(NSString*)forwardHeader
                       comment:(NSString*)comment
                       success:(void (^)(BOOL))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->TryForwardMeetingAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(meeting).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Email::EmailRecipient*,
                                                              ABI::Windows::ApplicationModel::Email::IEmailRecipient*>>::type>*>(
            ConvertToIterable<WAEEmailRecipient,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Email::EmailRecipient*,
                                                                                ABI::Windows::ApplicationModel::Email::IEmailRecipient*>>(
                recipients)
                .Get()),
        nsStrToHstr(subject).Get(),
        (ABI::Windows::ApplicationModel::Email::EmailMessageBodyKind)forwardHeaderType,
        nsStrToHstr(forwardHeader).Get(),
        nsStrToHstr(comment).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryProposeNewTimeForMeetingAsync:(WAEEmailMessage*)meeting
                            newStartTime:(WFDateTime*)newStartTime
                             newDuration:(WFTimeSpan*)newDuration
                                 subject:(NSString*)subject
                                 comment:(NSString*)comment
                                 success:(void (^)(BOOL))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryProposeNewTimeForMeetingAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(meeting).Get(),
                                                   *[newStartTime internalStruct],
                                                   *[newDuration internalStruct],
                                                   nsStrToHstr(subject).Get(),
                                                   nsStrToHstr(comment).Get(),
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addMailboxChangedEvent:(void (^)(WAEEmailMailbox*, WAEEmailMailboxChangedEventArgs*))pHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->add_MailboxChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailbox_Windows_ApplicationModel_Email_EmailMailboxChangedEventArgs>(
            pHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMailboxChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MailboxChanged(token));
}

- (RTObject<WFIAsyncAction>*)smartSendMessageAsync:(WAEEmailMessage*)message smartSend:(BOOL)smartSend {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->SmartSendMessageAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(message).Get(),
                                                       (boolean)smartSend,
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)trySetAutoReplySettingsAsync:(WAEEmailMailboxAutoReplySettings*)autoReplySettings
                             success:(void (^)(BOOL))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetAutoReplySettingsAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(autoReplySettings).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryGetAutoReplySettingsAsync:(WAEEmailMailboxAutoReplyMessageResponseKind)requestedFormat
                             success:(void (^)(WAEEmailMailboxAutoReplySettings*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetAutoReplySettingsAsync(
        (ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind)requestedFormat, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMailboxAutoReplySettings>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSString*)linkedMailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinkedMailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)networkAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox2>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)networkId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox2>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)resolveRecipientsAsync:(id<NSFastEnumeration> /* NSString * */)recipients
                       success:(void (^)(NSArray* /* WAEEmailRecipientResolutionResult* */))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox3>(self);
    THROW_NS_IF_FAILED(_comInst->ResolveRecipientsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(recipients).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*>*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*>*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WAEEmailRecipientResolutionResult_create(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)validateCertificatesAsync:(id<NSFastEnumeration> /* WSCCCertificate* */)certificates
                          success:(void (^)(NSArray* /* WAEEmailCertificateValidationStatus */))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox3>(self);
    THROW_NS_IF_FAILED(_comInst->ValidateCertificatesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                              ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>::type>*>(
            ConvertToIterable<
                WSCCCertificate,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                                  ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>(
                certificates)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAEEmailCertificateValidationStatus_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryEmptyFolderAsync:(NSString*)folderId
                    success:(void (^)(WAEEmailMailboxEmptyFolderStatus))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox3>(self);
    THROW_NS_IF_FAILED(_comInst->TryEmptyFolderAsync(nsStrToHstr(folderId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WAEEmailMailboxEmptyFolderStatus)result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryCreateFolderAsync:(NSString*)parentFolderId
                        name:(NSString*)name
                     success:(void (^)(WAEEmailMailboxCreateFolderResult*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox3>(self);
    THROW_NS_IF_FAILED(_comInst->TryCreateFolderAsync(nsStrToHstr(parentFolderId).Get(), nsStrToHstr(name).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMailboxCreateFolderResult>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryDeleteFolderAsync:(NSString*)folderId
                     success:(void (^)(WAEEmailMailboxDeleteFolderStatus))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox3>(self);
    THROW_NS_IF_FAILED(_comInst->TryDeleteFolderAsync(nsStrToHstr(folderId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WAEEmailMailboxDeleteFolderStatus)result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)registerSyncManagerAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailbox4>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterSyncManagerAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEEmailConversationReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(WAEEmailConversationBatch*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailConversationBatch*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversationReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailConversationBatch*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailConversationBatch*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationBatch> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAEEmailConversationBatch>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WAEEmailQueryOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryOptionsFactory> WAEIEmailQueryOptionsFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryOptionsFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailQueryOptions").Get(),
                                                       &inst));
    return inst;
}

+ (WAEEmailQueryOptions*)makeWithText:(NSString*)text {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions> unmarshalledReturn;
    auto _comInst = WAEIEmailQueryOptionsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithText(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAEEmailQueryOptions>(unmarshalledReturn.Get()) retain];
}

+ (WAEEmailQueryOptions*)makeWithTextAndFields:(NSString*)text fields:(WAEEmailQuerySearchFields)fields {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions> unmarshalledReturn;
    auto _comInst = WAEIEmailQueryOptionsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithTextAndFields(nsStrToHstr(text).Get(),
                                                         (ABI::Windows::ApplicationModel::Email::EmailQuerySearchFields)fields,
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAEEmailQueryOptions>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailQueryOptions").Get(), &out));
    return [_createRtProxy<WAEEmailQueryOptions>(out.Get()) retain];
}

- (WAEEmailQueryTextSearch*)textSearch {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextSearch(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailQueryTextSearch>(unmarshalledReturn.Get());
}

- (WAEEmailQuerySortDirection)sortDirection {
    ABI::Windows::ApplicationModel::Email::EmailQuerySortDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_SortDirection(&unmarshalledReturn));
    return (WAEEmailQuerySortDirection)unmarshalledReturn;
}

- (void)setSortDirection:(WAEEmailQuerySortDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_SortDirection((ABI::Windows::ApplicationModel::Email::EmailQuerySortDirection)value));
}

- (WAEEmailQuerySortProperty)sortProperty {
    ABI::Windows::ApplicationModel::Email::EmailQuerySortProperty unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_SortProperty(&unmarshalledReturn));
    return (WAEEmailQuerySortProperty)unmarshalledReturn;
}

- (void)setSortProperty:(WAEEmailQuerySortProperty)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_SortProperty((ABI::Windows::ApplicationModel::Email::EmailQuerySortProperty)value));
}

- (WAEEmailQueryKind)kind {
    ABI::Windows::ApplicationModel::Email::EmailQueryKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAEEmailQueryKind)unmarshalledReturn;
}

- (void)setKind:(WAEEmailQueryKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Kind((ABI::Windows::ApplicationModel::Email::EmailQueryKind)value));
}

- (NSMutableArray* /* NSString * */)folderIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FolderIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WAEEmailMessageReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(WAEEmailMessageBatch*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessageBatch*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessageReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMessageBatch*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessageBatch*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageBatch> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMessageBatch>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WAEEmailConversation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)mailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailFlagState)flagState {
    ABI::Windows::ApplicationModel::Email::EmailFlagState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlagState(&unmarshalledReturn));
    return (WAEEmailFlagState)unmarshalledReturn;
}

- (BOOL)hasAttachment {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasAttachment(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WAEEmailImportance)importance {
    ABI::Windows::ApplicationModel::Email::EmailImportance unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Importance(&unmarshalledReturn));
    return (WAEEmailImportance)unmarshalledReturn;
}

- (WAEEmailMessageResponseKind)lastEmailResponseKind {
    ABI::Windows::ApplicationModel::Email::EmailMessageResponseKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastEmailResponseKind(&unmarshalledReturn));
    return (WAEEmailMessageResponseKind)unmarshalledReturn;
}

- (unsigned int)messageCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)mostRecentMessageId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MostRecentMessageId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)mostRecentMessageTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MostRecentMessageTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)preview {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Preview(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailRecipient*)latestSender {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipient> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LatestSender(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailRecipient>(unmarshalledReturn.Get());
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)unreadMessageCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnreadMessageCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)findMessagesAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailMessage* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->FindMessagesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAEEmailMessage_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findMessagesWithCountAsync:(unsigned int)count
                           success:(void (^)(NSArray* /* WAEEmailMessage* */))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversation>(self);
    THROW_NS_IF_FAILED(_comInst->FindMessagesWithCountAsync(count, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAEEmailMessage_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WAEEmailFolder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailFolder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (NSString*)mailboxId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->get_MailboxId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)parentFolderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentFolderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (BOOL)isSyncEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSyncEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSyncEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSyncEnabled((boolean)value));
}

- (WFDateTime*)lastSuccessfulSyncTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastSuccessfulSyncTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setLastSuccessfulSyncTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastSuccessfulSyncTime(*[value internalStruct]));
}

- (WAEEmailSpecialFolderKind)kind {
    ABI::Windows::ApplicationModel::Email::EmailSpecialFolderKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAEEmailSpecialFolderKind)unmarshalledReturn;
}

- (void)createFolderAsync:(NSString*)name success:(void (^)(WAEEmailFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFolderAsync(nsStrToHstr(name).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailFolder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailFolder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Email::IEmailFolder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAEEmailFolder>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)findChildFoldersAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailFolder* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailFolder*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->FindChildFoldersAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Email::EmailFolder*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailFolder*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailFolder*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAEEmailFolder_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WAEEmailConversationReader*)getConversationReader {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailConversationReader>(unmarshalledReturn.Get());
}

- (WAEEmailConversationReader*)getConversationReaderWithOptions:(WAEEmailQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationReaderWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(options).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailConversationReader>(unmarshalledReturn.Get());
}

- (void)getMessageAsync:(NSString*)id success:(void (^)(WAEEmailMessage*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailMessage*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailMessage*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailMessage>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WAEEmailMessageReader*)getMessageReader {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMessageReader>(unmarshalledReturn.Get());
}

- (WAEEmailMessageReader*)getMessageReaderWithOptions:(WAEEmailQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetMessageReaderWithOptions(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryOptions>(options).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMessageReader>(unmarshalledReturn.Get());
}

- (void)getMessageCountsAsyncWithSuccess:(void (^)(WAEEmailItemCounts*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailItemCounts*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageCountsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailItemCounts*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailItemCounts*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailItemCounts> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAEEmailItemCounts>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryMoveAsync:(WAEEmailFolder*)newParentFolder success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->TryMoveAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(newParentFolder).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryMoveWithNewNameAsync:(WAEEmailFolder*)newParentFolder
                  newFolderName:(NSString*)newFolderName
                        success:(void (^)(BOOL))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryMoveWithNewNameAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(newParentFolder).Get(),
                                          nsStrToHstr(newFolderName).Get(),
                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)trySaveAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->TrySaveAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)saveMessageAsync:(WAEEmailMessage*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailFolder>(self);
    THROW_NS_IF_FAILED(_comInst->SaveMessageAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(message).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAEEmailRecipient

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipient> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipientFactory> WAEIEmailRecipientFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipientFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailRecipient").Get(),
                                                       &inst));
    return inst;
}

+ (WAEEmailRecipient*)make:(NSString*)address {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipient> unmarshalledReturn;
    auto _comInst = WAEIEmailRecipientFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(address).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAEEmailRecipient>(unmarshalledReturn.Get()) retain];
}

+ (WAEEmailRecipient*)makeWithName:(NSString*)address name:(NSString*)name {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipient> unmarshalledReturn;
    auto _comInst = WAEIEmailRecipientFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithName(nsStrToHstr(address).Get(), nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAEEmailRecipient>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailRecipient").Get(), &out));
    return [_createRtProxy<WAEEmailRecipient>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipient>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipient>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)address {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipient>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipient>(self);
    THROW_NS_IF_FAILED(_comInst->put_Address(nsStrToHstr(value).Get()));
}

@end

@implementation WAEEmailIrmTemplate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplateFactory> WAEIEmailIrmTemplateFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplateFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailIrmTemplate").Get(),
                                                       &inst));
    return inst;
}

+ (WAEEmailIrmTemplate*)make:(NSString*)id name:(NSString*)name description:(NSString*)description {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate> unmarshalledReturn;
    auto _comInst = WAEIEmailIrmTemplateFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(id).Get(),
                                        nsStrToHstr(name).Get(),
                                        nsStrToHstr(description).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAEEmailIrmTemplate>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailIrmTemplate").Get(), &out));
    return [_createRtProxy<WAEEmailIrmTemplate>(out.Get()) retain];
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

@end

@implementation WAEEmailIrmInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailIrmInfo").Get(), &out));
    return [_createRtProxy<WAEEmailIrmInfo>(out.Get()) retain];
}

static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmInfoFactory> WAEIEmailIrmInfoFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmInfoFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailIrmInfo").Get(),
                                                       &inst));
    return inst;
}

+ (WAEEmailIrmInfo*)make:(WFDateTime*)expiration irmTemplate:(WAEEmailIrmTemplate*)irmTemplate {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo> unmarshalledReturn;
    auto _comInst = WAEIEmailIrmInfoFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(*[expiration internalStruct],
                                        _getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate>(irmTemplate).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAEEmailIrmInfo>(unmarshalledReturn.Get()) retain];
}

- (BOOL)canEdit {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanEdit(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanEdit:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanEdit((boolean)value));
}

- (BOOL)canExtractData {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanExtractData(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanExtractData:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanExtractData((boolean)value));
}

- (BOOL)canForward {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanForward(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanForward:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanForward((boolean)value));
}

- (BOOL)canModifyRecipientsOnResponse {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanModifyRecipientsOnResponse(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanModifyRecipientsOnResponse:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanModifyRecipientsOnResponse((boolean)value));
}

- (BOOL)canPrintData {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanPrintData(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanPrintData:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanPrintData((boolean)value));
}

- (BOOL)canRemoveIrmOnResponse {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanRemoveIrmOnResponse(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanRemoveIrmOnResponse:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanRemoveIrmOnResponse((boolean)value));
}

- (BOOL)canReply {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanReply(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanReply:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanReply((boolean)value));
}

- (BOOL)canReplyAll {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanReplyAll(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanReplyAll:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanReplyAll((boolean)value));
}

- (WFDateTime*)expirationDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setExpirationDate:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExpirationDate(*[value internalStruct]));
}

- (BOOL)isIrmOriginator {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsIrmOriginator(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsIrmOriginator:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsIrmOriginator((boolean)value));
}

- (BOOL)isProgramaticAccessAllowed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsProgramaticAccessAllowed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsProgramaticAccessAllowed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsProgramaticAccessAllowed((boolean)value));
}

- (WAEEmailIrmTemplate*)Template {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Template(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailIrmTemplate>(unmarshalledReturn.Get());
}

- (void)setTemplate:(WAEEmailIrmTemplate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Template(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate>(value).Get()));
}

@end

@implementation WAEEmailAttachment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailAttachment").Get(), &out));
    return [_createRtProxy<WAEEmailAttachment>(out.Get()) retain];
}

static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachmentFactory2> WAEIEmailAttachmentFactory2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachmentFactory2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailAttachment").Get(),
                                                       &inst));
    return inst;
}

+ (WAEEmailAttachment*)make:(NSString*)fileName data:(RTObject<WSSIRandomAccessStreamReference>*)data mimeType:(NSString*)mimeType {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachment> unmarshalledReturn;
    auto _comInst = WAEIEmailAttachmentFactory2_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(fileName).Get(),
                                        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(data).Get(),
                                        nsStrToHstr(mimeType).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAEEmailAttachment>(unmarshalledReturn.Get()) retain];
}

static ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachmentFactory> WAEIEmailAttachmentFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachmentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailAttachment").Get(),
                                                       &inst));
    return inst;
}

+ (WAEEmailAttachment*)make:(NSString*)fileName data:(RTObject<WSSIRandomAccessStreamReference>*)data {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailAttachment> unmarshalledReturn;
    auto _comInst = WAEIEmailAttachmentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(fileName).Get(),
                                        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(data).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAEEmailAttachment>(unmarshalledReturn.Get()) retain];
}

- (NSString*)fileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFileName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->put_FileName(nsStrToHstr(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setData:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)contentId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContentId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentId(nsStrToHstr(value).Get()));
}

- (NSString*)contentLocation {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentLocation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContentLocation:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentLocation(nsStrToHstr(value).Get()));
}

- (WAEEmailAttachmentDownloadState)downloadState {
    ABI::Windows::ApplicationModel::Email::EmailAttachmentDownloadState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DownloadState(&unmarshalledReturn));
    return (WAEEmailAttachmentDownloadState)unmarshalledReturn;
}

- (void)setDownloadState:(WAEEmailAttachmentDownloadState)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DownloadState((ABI::Windows::ApplicationModel::Email::EmailAttachmentDownloadState)value));
}

- (uint64_t)estimatedDownloadSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EstimatedDownloadSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setEstimatedDownloadSizeInBytes:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_EstimatedDownloadSizeInBytes(value));
}

- (BOOL)isFromBaseMessage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFromBaseMessage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isInline {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInline(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInline:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInline((boolean)value));
}

- (NSString*)mimeType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MimeType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMimeType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MimeType(nsStrToHstr(value).Get()));
}

@end

@implementation WAEEmailMeetingInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailMeetingInfo").Get(), &out));
    return [_createRtProxy<WAEEmailMeetingInfo>(out.Get()) retain];
}

- (BOOL)allowNewTimeProposal {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowNewTimeProposal(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowNewTimeProposal:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowNewTimeProposal((boolean)value));
}

- (NSString*)appointmentRoamingId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentRoamingId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAppointmentRoamingId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppointmentRoamingId(nsStrToHstr(value).Get()));
}

- (id /* WFDateTime* */)appointmentOriginalStartTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentOriginalStartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setAppointmentOriginalStartTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppointmentOriginalStartTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (BOOL)isAllDay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAllDay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsAllDay:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsAllDay((boolean)value));
}

- (BOOL)isResponseRequested {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsResponseRequested(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsResponseRequested:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsResponseRequested((boolean)value));
}

- (NSString*)location {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLocation:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Location(nsStrToHstr(value).Get()));
}

- (id /* WFDateTime* */)proposedStartTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProposedStartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setProposedStartTime:(id /* WFDateTime* */)proposedStartTime {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProposedStartTime(BuildNullable<ABI::Windows::Foundation::DateTime>(proposedStartTime)));
}

- (id /* WFTimeSpan* */)proposedDuration {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProposedDuration(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setProposedDuration:(id /* WFTimeSpan* */)duration {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProposedDuration(BuildNullable<ABI::Windows::Foundation::TimeSpan>(duration)));
}

- (id /* WFDateTime* */)recurrenceStartTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecurrenceStartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setRecurrenceStartTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_RecurrenceStartTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WAAAppointmentRecurrence*)recurrence {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Recurrence(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentRecurrence>(unmarshalledReturn.Get());
}

- (void)setRecurrence:(WAAAppointmentRecurrence*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Recurrence(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(value).Get()));
}

- (uint64_t)remoteChangeNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteChangeNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRemoteChangeNumber:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteChangeNumber(value));
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setStartTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(*[value internalStruct]));
}

- (BOOL)isReportedOutOfDateByServer {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReportedOutOfDateByServer(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WAEEmailMailboxChangedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WAEEmailMailboxCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canForwardMeetings {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanForwardMeetings(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canGetAndSetExternalAutoReplies {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanGetAndSetExternalAutoReplies(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canGetAndSetInternalAutoReplies {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanGetAndSetInternalAutoReplies(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canUpdateMeetingResponses {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanUpdateMeetingResponses(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canServerSearchFolders {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanServerSearchFolders(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canServerSearchMailbox {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanServerSearchMailbox(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canProposeNewTimeForMeetings {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanProposeNewTimeForMeetings(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canSmartSend {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSmartSend(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canResolveRecipients {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanResolveRecipients(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canValidateCertificates {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanValidateCertificates(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canEmptyFolder {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanEmptyFolder(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canCreateFolder {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanCreateFolder(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canDeleteFolder {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanDeleteFolder(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canMoveFolder {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanMoveFolder(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanForwardMeetings:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanForwardMeetings((boolean)value));
}

- (void)setCanGetAndSetExternalAutoReplies:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanGetAndSetExternalAutoReplies((boolean)value));
}

- (void)setCanGetAndSetInternalAutoReplies:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanGetAndSetInternalAutoReplies((boolean)value));
}

- (void)setCanUpdateMeetingResponses:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanUpdateMeetingResponses((boolean)value));
}

- (void)setCanServerSearchFolders:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanServerSearchFolders((boolean)value));
}

- (void)setCanServerSearchMailbox:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanServerSearchMailbox((boolean)value));
}

- (void)setCanProposeNewTimeForMeetings:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanProposeNewTimeForMeetings((boolean)value));
}

- (void)setCanSmartSend:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanSmartSend((boolean)value));
}

- (void)setCanResolveRecipients:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanResolveRecipients((boolean)value));
}

- (void)setCanValidateCertificates:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanValidateCertificates((boolean)value));
}

- (void)setCanEmptyFolder:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanEmptyFolder((boolean)value));
}

- (void)setCanCreateFolder:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanCreateFolder((boolean)value));
}

- (void)setCanDeleteFolder:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanDeleteFolder((boolean)value));
}

- (void)setCanMoveFolder:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanMoveFolder((boolean)value));
}

@end

@implementation WAEEmailMailboxChangeTracker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isTracking {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTracking(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Enable());
}

- (WAEEmailMailboxChangeReader*)getChangeReader {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->GetChangeReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxChangeReader>(unmarshalledReturn.Get());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

@end

@implementation WAEEmailMailboxPolicies

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation)allowedSmimeEncryptionAlgorithmNegotiation {
    ABI::Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowedSmimeEncryptionAlgorithmNegotiation(&unmarshalledReturn));
    return (WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation)unmarshalledReturn;
}

- (BOOL)allowSmimeSoftCertificates {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowSmimeSoftCertificates(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (id /* WAEEmailMailboxSmimeEncryptionAlgorithm */)requiredSmimeEncryptionAlgorithm {
    ComPtr<IReference<ABI::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequiredSmimeEncryptionAlgorithm(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WAEEmailMailboxSmimeEncryptionAlgorithm,
                            ABI::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm>::convert(unmarshalledReturn.Get());
}

- (id /* WAEEmailMailboxSmimeSigningAlgorithm */)requiredSmimeSigningAlgorithm {
    ComPtr<IReference<ABI::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequiredSmimeSigningAlgorithm(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WAEEmailMailboxSmimeSigningAlgorithm,
                            ABI::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm>::convert(unmarshalledReturn.Get());
}

- (BOOL)mustEncryptSmimeMessages {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MustEncryptSmimeMessages(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)mustSignSmimeMessages {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MustSignSmimeMessages(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowedSmimeEncryptionAlgorithmNegotiation:(WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowedSmimeEncryptionAlgorithmNegotiation(
        (ABI::Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation)value));
}

- (void)setAllowSmimeSoftCertificates:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowSmimeSoftCertificates((boolean)value));
}

- (void)setRequiredSmimeEncryptionAlgorithm:(id /* WAEEmailMailboxSmimeEncryptionAlgorithm */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequiredSmimeEncryptionAlgorithm(
        BuildNullable<ABI::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm>(value)));
}

- (void)setRequiredSmimeSigningAlgorithm:(id /* WAEEmailMailboxSmimeSigningAlgorithm */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequiredSmimeSigningAlgorithm(
        BuildNullable<ABI::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm>(value)));
}

- (void)setMustEncryptSmimeMessages:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>(self);
    THROW_NS_IF_FAILED(_comInst->put_MustEncryptSmimeMessages((boolean)value));
}

- (void)setMustSignSmimeMessages:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>(self);
    THROW_NS_IF_FAILED(_comInst->put_MustSignSmimeMessages((boolean)value));
}

@end

@implementation WAEEmailMailboxSyncManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEEmailMailboxSyncStatus)status {
    ABI::Windows::ApplicationModel::Email::EmailMailboxSyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WAEEmailMailboxSyncStatus)unmarshalledReturn;
}

- (WFDateTime*)lastSuccessfulSyncTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastSuccessfulSyncTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)lastAttemptedSyncTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastAttemptedSyncTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)syncAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->SyncAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addSyncStatusChangedEvent:(void (^)(WAEEmailMailboxSyncManager*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SyncStatusChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Email_EmailMailboxSyncManager_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSyncStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SyncStatusChanged(token));
}

- (void)setStatus:(WAEEmailMailboxSyncStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::ApplicationModel::Email::EmailMailboxSyncStatus)value));
}

- (void)setLastSuccessfulSyncTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastSuccessfulSyncTime(*[value internalStruct]));
}

- (void)setLastAttemptedSyncTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastAttemptedSyncTime(*[value internalStruct]));
}

@end

@implementation WAEEmailMailboxChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEEmailMailboxChangedDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxChangedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEEmailMailboxAutoReplySettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailMailboxAutoReplySettings").Get(),
                                              &out));
    return [_createRtProxy<WAEEmailMailboxAutoReplySettings>(out.Get()) retain];
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (WAEEmailMailboxAutoReplyMessageResponseKind)responseKind {
    ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseKind(&unmarshalledReturn));
    return (WAEEmailMailboxAutoReplyMessageResponseKind)unmarshalledReturn;
}

- (void)setResponseKind:(WAEEmailMailboxAutoReplyMessageResponseKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ResponseKind((ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind)value));
}

- (id /* WFDateTime* */)startTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setStartTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)endTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setEndTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_EndTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WAEEmailMailboxAutoReply*)internalReply {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_InternalReply(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxAutoReply>(unmarshalledReturn.Get());
}

- (WAEEmailMailboxAutoReply*)knownExternalReply {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_KnownExternalReply(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxAutoReply>(unmarshalledReturn.Get());
}

- (WAEEmailMailboxAutoReply*)unknownExternalReply {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnknownExternalReply(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMailboxAutoReply>(unmarshalledReturn.Get());
}

@end

@implementation WAEEmailRecipientResolutionResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Email.EmailRecipientResolutionResult").Get(), &out));
    return [_createRtProxy<WAEEmailRecipientResolutionResult>(out.Get()) retain];
}

- (WAEEmailRecipientResolutionStatus)status {
    ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WAEEmailRecipientResolutionStatus)unmarshalledReturn;
}

- (NSArray* /* WSCCCertificate* */)publicKeys {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublicKeys(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (void)setStatus:(WAEEmailRecipientResolutionStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionStatus)value));
}

- (void)setPublicKeys:(id<NSFastEnumeration> /* WSCCCertificate* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2>(self);
    THROW_NS_IF_FAILED(_comInst->SetPublicKeys(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                              ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>::type>*>(
            ConvertToIterable<
                WSCCCertificate,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                                  ABI::Windows::Security::Cryptography::Certificates::ICertificate*>>(value)
                .Get())));
}

@end

@implementation WAEEmailMailboxCreateFolderResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEEmailMailboxCreateFolderStatus)status {
    ABI::Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WAEEmailMailboxCreateFolderStatus)unmarshalledReturn;
}

- (WAEEmailFolder*)folder {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailFolder>(unmarshalledReturn.Get());
}

@end

@implementation WAEEmailMailboxAutoReply

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (NSString*)response {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply>(self);
    THROW_NS_IF_FAILED(_comInst->get_Response(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setResponse:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply>(self);
    THROW_NS_IF_FAILED(_comInst->put_Response(nsStrToHstr(value).Get()));
}

@end

@implementation WAEEmailItemCounts

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailItemCounts> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)flagged {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailItemCounts>(self);
    THROW_NS_IF_FAILED(_comInst->get_Flagged(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)important {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailItemCounts>(self);
    THROW_NS_IF_FAILED(_comInst->get_Important(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)total {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailItemCounts>(self);
    THROW_NS_IF_FAILED(_comInst->get_Total(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)unread {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailItemCounts>(self);
    THROW_NS_IF_FAILED(_comInst->get_Unread(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WAEEmailQueryTextSearch

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEEmailQuerySearchFields)fields {
    ABI::Windows::ApplicationModel::Email::EmailQuerySearchFields unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Fields(&unmarshalledReturn));
    return (WAEEmailQuerySearchFields)unmarshalledReturn;
}

- (void)setFields:(WAEEmailQuerySearchFields)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->put_Fields((ABI::Windows::ApplicationModel::Email::EmailQuerySearchFields)value));
}

- (WAEEmailQuerySearchScope)searchScope {
    ABI::Windows::ApplicationModel::Email::EmailQuerySearchScope unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchScope(&unmarshalledReturn));
    return (WAEEmailQuerySearchScope)unmarshalledReturn;
}

- (void)setSearchScope:(WAEEmailQuerySearchScope)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->put_SearchScope((ABI::Windows::ApplicationModel::Email::EmailQuerySearchScope)value));
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

@end

@implementation WAEEmailConversationBatch

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailConversationBatch> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WAEEmailConversation* */)conversations {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailConversation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversationBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Conversations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WAEEmailConversation_create(unmarshalledReturn.Get());
}

- (WAEEmailBatchStatus)status {
    ABI::Windows::ApplicationModel::Email::EmailBatchStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailConversationBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WAEEmailBatchStatus)unmarshalledReturn;
}

@end

@implementation WAEEmailMessageBatch

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessageBatch> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WAEEmailMessage* */)messages {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessageBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Messages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WAEEmailMessage_create(unmarshalledReturn.Get());
}

- (WAEEmailBatchStatus)status {
    ABI::Windows::ApplicationModel::Email::EmailBatchStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMessageBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WAEEmailBatchStatus)unmarshalledReturn;
}

@end

@implementation WAEEmailMailboxAction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxAction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEEmailMailboxActionKind)kind {
    ABI::Windows::ApplicationModel::Email::EmailMailboxActionKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAEEmailMailboxActionKind)unmarshalledReturn;
}

- (uint64_t)changeNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxAction>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WAEEmailMailboxChange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxChange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEEmailMailboxChangeType)changeType {
    ABI::Windows::ApplicationModel::Email::EmailMailboxChangeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeType(&unmarshalledReturn));
    return (WAEEmailMailboxChangeType)unmarshalledReturn;
}

- (NSMutableArray* /* WAEEmailMailboxAction* */)mailboxActions {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Email::EmailMailboxAction*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_MailboxActions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAEEmailMailboxAction_create(unmarshalledReturn.Get());
}

- (WAEEmailMessage*)message {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMessage>(unmarshalledReturn.Get());
}

- (WAEEmailFolder*)folder {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailFolder>(unmarshalledReturn.Get());
}

@end

@implementation WAEEmailMailboxChangeReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)acceptChanges {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChanges());
}

- (void)acceptChangesThrough:(WAEEmailMailboxChange*)lastChangeToAcknowledge {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChangesThrough(
        _getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChange>(lastChangeToAcknowledge).Get()));
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailMailboxChange* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailboxChange*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailboxChange*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailboxChange*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailboxChange*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAEEmailMailboxChange_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WAEEmailManager

ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics3> WAEIEmailManagerStatics3_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailManager").Get(),
                                                       &inst));
    return inst;
}

+ (WAEEmailManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerForUser> unmarshalledReturn;
    auto _comInst = WAEIEmailManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailManagerForUser>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics> WAEIEmailManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailManager").Get(),
                                                       &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)showComposeNewEmailAsync:(WAEEmailMessage*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAEIEmailManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowComposeNewEmailAsync(_getRtInterface<ABI::Windows::ApplicationModel::Email::IEmailMessage>(message).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics2> WAEIEmailManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Email.EmailManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)requestStoreAsync:(WAEEmailStoreAccessType)accessType
                  success:(void (^)(WAEEmailStore*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailStore*>> unmarshalledReturn;
    auto _comInst = WAEIEmailManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestStoreAsync((ABI::Windows::ApplicationModel::Email::EmailStoreAccessType)accessType, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Email::EmailStore*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Email::EmailStore*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Email::IEmailStore> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAEEmailStore>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WAEEmailStoreNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

id RTProxiedIterableNSArray_WAEEmailRecipient_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::Email::EmailRecipient*>,
                                                 RTIterableObj<ABI::Windows::ApplicationModel::Email::IEmailRecipient*,
                                                               IIterable<ABI::Windows::ApplicationModel::Email::EmailRecipient*>,
                                                               WAEEmailRecipient,
                                                               ABI::Windows::ApplicationModel::Email::EmailRecipient*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WSCCCertificate_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                 RTIterableObj<ABI::Windows::Security::Cryptography::Certificates::ICertificate*,
                                                               IIterable<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                               WSCCCertificate,
                                                               ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAEEmailCertificateValidationStatus_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus,
                                                    IVectorView<ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>,
                                                    WAEEmailCertificateValidationStatus,
                                                    ABI::Windows::ApplicationModel::Email::EmailCertificateValidationStatus,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAEEmailConversation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Email::EmailConversation*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Email::IEmailConversation*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Email::EmailConversation*>,
                                                    WAEEmailConversation,
                                                    ABI::Windows::ApplicationModel::Email::EmailConversation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAEEmailFolder_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Email::EmailFolder*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Email::IEmailFolder*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Email::EmailFolder*>,
                                                    WAEEmailFolder,
                                                    ABI::Windows::ApplicationModel::Email::EmailFolder*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAEEmailMailbox_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailbox*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Email::IEmailMailbox*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailbox*>,
                                                    WAEEmailMailbox,
                                                    ABI::Windows::ApplicationModel::Email::EmailMailbox*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAEEmailMailboxChange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailboxChange*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Email::IEmailMailboxChange*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Email::EmailMailboxChange*>,
                                                    WAEEmailMailboxChange,
                                                    ABI::Windows::ApplicationModel::Email::EmailMailboxChange*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAEEmailMessage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Email::IEmailMessage*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Email::EmailMessage*>,
                                                    WAEEmailMessage,
                                                    ABI::Windows::ApplicationModel::Email::EmailMessage*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAEEmailRecipientResolutionResult_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*>,
                                                    WAEEmailRecipientResolutionResult,
                                                    ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult*,
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

id RTProxiedNSMutableArray_WAEEmailAttachment_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Email::EmailAttachment*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Email::IEmailAttachment*,
                                                                  IVector<ABI::Windows::ApplicationModel::Email::EmailAttachment*>,
                                                                  WAEEmailAttachment,
                                                                  ABI::Windows::ApplicationModel::Email::EmailAttachment*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WAEEmailMailboxAction_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Email::EmailMailboxAction*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Email::IEmailMailboxAction*,
                                                                  IVector<ABI::Windows::ApplicationModel::Email::EmailMailboxAction*>,
                                                                  WAEEmailMailboxAction,
                                                                  ABI::Windows::ApplicationModel::Email::EmailMailboxAction*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WAEEmailRecipient_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Email::EmailRecipient*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Email::IEmailRecipient*,
                                                                  IVector<ABI::Windows::ApplicationModel::Email::EmailRecipient*>,
                                                                  WAEEmailRecipient,
                                                                  ABI::Windows::ApplicationModel::Email::EmailRecipient*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
