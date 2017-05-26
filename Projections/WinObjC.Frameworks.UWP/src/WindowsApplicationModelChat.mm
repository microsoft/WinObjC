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

// WindowsApplicationModelChat.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Chat.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelChat.h"
#include "WindowsApplicationModelChat_priv.h"

@implementation WACIChatItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACChatItemKind)itemKind {
    ABI::Windows::ApplicationModel::Chat::ChatItemKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemKind(&unmarshalledReturn));
    return (WACChatItemKind)unmarshalledReturn;
}

@end

@implementation WACChatMessageTransportConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)maxAttachmentCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxAttachmentCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxMessageSizeInKilobytes {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxMessageSizeInKilobytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxRecipientCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxRecipientCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMMediaEncodingProfile*)supportedVideoFormat {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedVideoFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, RTObject* */)extendedProperties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WACChatMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatMessage").Get(), &out));
    return [_createRtProxy<WACChatMessage>(out.Get()) retain];
}

- (NSMutableArray* /* WACChatMessageAttachment* */)attachments {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Chat::ChatMessageAttachment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attachments(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACChatMessageAttachment_create(unmarshalledReturn.Get());
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setBody:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Body(nsStrToHstr(value).Get()));
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isForwardingDisabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsForwardingDisabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isIncoming {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsIncoming(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isRead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDateTime*)localTimestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalTimestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)networkTimestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkTimestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSMutableArray* /* NSString * */)recipients {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Recipients(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, WACChatMessageStatus */)recipientSendStatuses {
    ComPtr<IMapView<HSTRING, ABI::Windows::ApplicationModel::Chat::ChatMessageStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecipientSendStatuses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WACChatMessageStatus_create(unmarshalledReturn.Get());
}

- (WACChatMessageStatus)status {
    ABI::Windows::ApplicationModel::Chat::ChatMessageStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WACChatMessageStatus)unmarshalledReturn;
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)transportFriendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportFriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)transportId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTransportId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransportId(nsStrToHstr(value).Get()));
}

- (uint64_t)estimatedDownloadSize {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EstimatedDownloadSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setEstimatedDownloadSize:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_EstimatedDownloadSize(value));
}

- (void)setFrom:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_From(nsStrToHstr(value).Get()));
}

- (BOOL)isAutoReply {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAutoReply(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsAutoReply:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsAutoReply((boolean)value));
}

- (void)setIsForwardingDisabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsForwardingDisabled((boolean)value));
}

- (BOOL)isReplyDisabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReplyDisabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsIncoming:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsIncoming((boolean)value));
}

- (void)setIsRead:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRead((boolean)value));
}

- (BOOL)isSeen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSeen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSeen:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSeen((boolean)value));
}

- (BOOL)isSimMessage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSimMessage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setLocalTimestamp:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LocalTimestamp(*[value internalStruct]));
}

- (WACChatMessageKind)messageKind {
    ABI::Windows::ApplicationModel::Chat::ChatMessageKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageKind(&unmarshalledReturn));
    return (WACChatMessageKind)unmarshalledReturn;
}

- (void)setMessageKind:(WACChatMessageKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MessageKind((ABI::Windows::ApplicationModel::Chat::ChatMessageKind)value));
}

- (WACChatMessageOperatorKind)messageOperatorKind {
    ABI::Windows::ApplicationModel::Chat::ChatMessageOperatorKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageOperatorKind(&unmarshalledReturn));
    return (WACChatMessageOperatorKind)unmarshalledReturn;
}

- (void)setMessageOperatorKind:(WACChatMessageOperatorKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MessageOperatorKind((ABI::Windows::ApplicationModel::Chat::ChatMessageOperatorKind)value));
}

- (void)setNetworkTimestamp:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_NetworkTimestamp(*[value internalStruct]));
}

- (BOOL)isReceivedDuringQuietHours {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReceivedDuringQuietHours(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsReceivedDuringQuietHours:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsReceivedDuringQuietHours((boolean)value));
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (void)setStatus:(WACChatMessageStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::ApplicationModel::Chat::ChatMessageStatus)value));
}

- (void)setSubject:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subject(nsStrToHstr(value).Get()));
}

- (BOOL)shouldSuppressNotification {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShouldSuppressNotification(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShouldSuppressNotification:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShouldSuppressNotification((boolean)value));
}

- (WACChatConversationThreadingInfo*)threadingInfo {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThreadingInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatConversationThreadingInfo>(unmarshalledReturn.Get());
}

- (void)setThreadingInfo:(WACChatConversationThreadingInfo*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ThreadingInfo(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(value).Get()));
}

- (NSMutableArray* /* WACChatRecipientDeliveryInfo* */)recipientsDeliveryInfos {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecipientsDeliveryInfos(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACChatRecipientDeliveryInfo_create(unmarshalledReturn.Get());
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage3>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)syncId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage4>(self);
    THROW_NS_IF_FAILED(_comInst->get_SyncId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSyncId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage4>(self);
    THROW_NS_IF_FAILED(_comInst->put_SyncId(nsStrToHstr(value).Get()));
}

- (WACChatItemKind)itemKind {
    ABI::Windows::ApplicationModel::Chat::ChatItemKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemKind(&unmarshalledReturn));
    return (WACChatItemKind)unmarshalledReturn;
}

@end

@implementation WACChatMessageChange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageChange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACChatMessageChangeType)changeType {
    ABI::Windows::ApplicationModel::Chat::ChatMessageChangeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeType(&unmarshalledReturn));
    return (WACChatMessageChangeType)unmarshalledReturn;
}

- (WACChatMessage*)message {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessage>(unmarshalledReturn.Get());
}

@end

@implementation WACChatMessageChangeReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)acceptChanges {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChanges());
}

- (void)acceptChangesThrough:(WACChatMessageChange*)lastChangeToAcknowledge {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChangesThrough(
        _getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChange>(lastChangeToAcknowledge).Get()));
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WACChatMessageChange* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageChange*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageChange*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageChange*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageChange*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACChatMessageChange_create(result.Get()));
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

@implementation WACChatMessageAttachment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachmentFactory> WACIChatMessageAttachmentFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachmentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatMessageAttachment").Get(),
                                                       &inst));
    return inst;
}

+ (WACChatMessageAttachment*)makeChatMessageAttachment:(NSString*)mimeType
                                   dataStreamReference:(RTObject<WSSIRandomAccessStreamReference>*)dataStreamReference {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment> unmarshalledReturn;
    auto _comInst = WACIChatMessageAttachmentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateChatMessageAttachment(
        nsStrToHstr(mimeType).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(dataStreamReference).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACChatMessageAttachment>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WSSIRandomAccessStreamReference>*)dataStreamReference {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataStreamReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setDataStreamReference:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_DataStreamReference(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (unsigned int)groupId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_GroupId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGroupId:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->put_GroupId(value));
}

- (NSString*)mimeType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_MimeType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMimeType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->put_MimeType(nsStrToHstr(value).Get()));
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (double)transferProgress {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransferProgress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTransferProgress:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransferProgress(value));
}

- (NSString*)originalFileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalFileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOriginalFileName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_OriginalFileName(nsStrToHstr(value).Get()));
}

@end

@implementation WACChatConversationThreadingInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatConversationThreadingInfo").Get(),
                                              &out));
    return [_createRtProxy<WACChatConversationThreadingInfo>(out.Get()) retain];
}

- (NSString*)contactId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContactId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContactId(nsStrToHstr(value).Get()));
}

- (NSString*)custom {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Custom(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCustom:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Custom(nsStrToHstr(value).Get()));
}

- (NSString*)conversationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConversationId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setConversationId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConversationId(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)participants {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Participants(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WACChatConversationThreadingKind)kind {
    ABI::Windows::ApplicationModel::Chat::ChatConversationThreadingKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WACChatConversationThreadingKind)unmarshalledReturn;
}

- (void)setKind:(WACChatConversationThreadingKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Kind((ABI::Windows::ApplicationModel::Chat::ChatConversationThreadingKind)value));
}

@end

@implementation WACChatRecipientDeliveryInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatRecipientDeliveryInfo").Get(),
                                              &out));
    return [_createRtProxy<WACChatRecipientDeliveryInfo>(out.Get()) retain];
}

- (NSString*)transportAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTransportAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransportAddress(nsStrToHstr(value).Get()));
}

- (id /* WFDateTime* */)deliveryTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeliveryTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setDeliveryTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DeliveryTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)readTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setReadTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WACChatTransportErrorCodeCategory)transportErrorCodeCategory {
    ABI::Windows::ApplicationModel::Chat::ChatTransportErrorCodeCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportErrorCodeCategory(&unmarshalledReturn));
    return (WACChatTransportErrorCodeCategory)unmarshalledReturn;
}

- (WACChatTransportInterpretedErrorCode)transportInterpretedErrorCode {
    ABI::Windows::ApplicationModel::Chat::ChatTransportInterpretedErrorCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportInterpretedErrorCode(&unmarshalledReturn));
    return (WACChatTransportInterpretedErrorCode)unmarshalledReturn;
}

- (int)transportErrorCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportErrorCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isErrorPermanent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsErrorPermanent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WACChatMessageStatus)status {
    ABI::Windows::ApplicationModel::Chat::ChatMessageStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WACChatMessageStatus)unmarshalledReturn;
}

@end

@implementation WACChatMessageChangeTracker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeTracker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Enable());
}

- (WACChatMessageChangeReader*)getChangeReader {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->GetChangeReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessageChangeReader>(unmarshalledReturn.Get());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

@end

@implementation WACChatMessageReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WACChatMessage* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACChatMessage_create(result.Get()));
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

- (void)readBatchWithCountAsync:(int)count success:(void (^)(NSArray* /* WACChatMessage* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageReader2>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchWithCountAsync(count, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACChatMessage_create(result.Get()));
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

@implementation WACChatMessageValidationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageValidationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* unsigned int */)maxPartCount {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageValidationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPartCount(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)partCount {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageValidationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartCount(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)remainingCharacterCountInPart {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageValidationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemainingCharacterCountInPart(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (WACChatMessageValidationStatus)status {
    ABI::Windows::ApplicationModel::Chat::ChatMessageValidationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageValidationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WACChatMessageValidationStatus)unmarshalledReturn;
}

@end

@implementation WACChatMessageStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACChatMessageChangeTracker*)changeTracker {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageChangeTracker> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeTracker(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessageChangeTracker>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteMessageAsync:(NSString*)localMessageId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteMessageAsync(nsStrToHstr(localMessageId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)downloadMessageAsync:(NSString*)localChatMessageId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->DownloadMessageAsync(nsStrToHstr(localChatMessageId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getMessageAsync:(NSString*)localChatMessageId success:(void (^)(WACChatMessage*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageAsync(nsStrToHstr(localChatMessageId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatMessage*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessage*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessage> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACChatMessage>(result.Get()));
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

- (WACChatMessageReader*)getMessageReader1 {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageReader1(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessageReader>(unmarshalledReturn.Get());
}

- (WACChatMessageReader*)getMessageReader2:(WFTimeSpan*)recentTimeLimit {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageReader2(*[recentTimeLimit internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessageReader>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markMessageReadAsync:(NSString*)localChatMessageId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->MarkMessageReadAsync(nsStrToHstr(localChatMessageId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)retrySendMessageAsync:(NSString*)localChatMessageId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->RetrySendMessageAsync(nsStrToHstr(localChatMessageId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)sendMessageAsync:(WACChatMessage*)chatMessage {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessageAsync(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(chatMessage).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WACChatMessageValidationResult*)validateMessage:(WACChatMessage*)chatMessage {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageValidationResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->ValidateMessage(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(chatMessage).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessageValidationResult>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addMessageChangedEvent:(void (^)(WACChatMessageStore*, WACChatMessageChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->add_MessageChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageChangedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMessageChangedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MessageChanged(value));
}

- (void)forwardMessageAsync:(NSString*)localChatMessageId
                  addresses:(id<NSFastEnumeration> /* NSString * */)addresses
                    success:(void (^)(WACChatMessage*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(
        _comInst->ForwardMessageAsync(nsStrToHstr(localChatMessageId).Get(),
                                      static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                          ConvertToIterable<NSString, HSTRING>(addresses).Get()),
                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatMessage*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessage*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessage> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACChatMessage>(result.Get()));
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

- (void)getConversationAsync:(NSString*)conversationId success:(void (^)(WACChatConversation*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatConversation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationAsync(nsStrToHstr(conversationId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatConversation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatConversation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACChatConversation>(result.Get()));
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

- (void)getConversationForTransportsAsync:(NSString*)conversationId
                             transportIds:(id<NSFastEnumeration> /* NSString * */)transportIds
                                  success:(void (^)(WACChatConversation*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatConversation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationForTransportsAsync(
        nsStrToHstr(conversationId).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(transportIds).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatConversation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatConversation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACChatConversation>(result.Get()));
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

- (void)getConversationFromThreadingInfoAsync:(WACChatConversationThreadingInfo*)threadingInfo
                                      success:(void (^)(WACChatConversation*))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatConversation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationFromThreadingInfoAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>(threadingInfo).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatConversation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatConversation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACChatConversation>(result.Get()));
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

- (WACChatConversationReader*)getConversationReader {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversationReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatConversationReader>(unmarshalledReturn.Get());
}

- (WACChatConversationReader*)getConversationForTransportsReader:(id<NSFastEnumeration> /* NSString * */)transportIds {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversationReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversationForTransportsReader(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(transportIds).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatConversationReader>(unmarshalledReturn.Get());
}

- (void)getMessageByRemoteIdAsync:(NSString*)transportId
                         remoteId:(NSString*)remoteId
                          success:(void (^)(WACChatMessage*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetMessageByRemoteIdAsync(nsStrToHstr(transportId).Get(), nsStrToHstr(remoteId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatMessage*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessage*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessage> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACChatMessage>(result.Get()));
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

- (void)getUnseenCountAsyncWithSuccess:(void (^)(int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetUnseenCountAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (void)getUnseenCountForTransportsReaderAsync:(id<NSFastEnumeration> /* NSString * */)transportIds
                                       success:(void (^)(int))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetUnseenCountForTransportsReaderAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(transportIds).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (RTObject<WFIAsyncAction>*)markAsSeenAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->MarkAsSeenAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markAsSeenForTransportsAsync:(id<NSFastEnumeration> /* NSString * */)transportIds {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->MarkAsSeenForTransportsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(transportIds).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WACChatSearchReader*)getSearchReader:(WACChatQueryOptions*)value {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatSearchReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetSearchReader(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatQueryOptions>(value).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatSearchReader>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)saveMessageAsync:(WACChatMessage*)chatMessage {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->SaveMessageAsync(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(chatMessage).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)tryCancelDownloadMessageAsync:(NSString*)localChatMessageId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->TryCancelDownloadMessageAsync(nsStrToHstr(localChatMessageId).Get(), &unmarshalledReturn));

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

- (void)tryCancelSendMessageAsync:(NSString*)localChatMessageId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->TryCancelSendMessageAsync(nsStrToHstr(localChatMessageId).Get(), &unmarshalledReturn));

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

- (EventRegistrationToken)addStoreChangedEvent:(void (^)(WACChatMessageStore*, WACChatMessageStoreChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->add_StoreChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Chat_ChatMessageStore_Windows_ApplicationModel_Chat_ChatMessageStoreChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoreChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StoreChanged(token));
}

- (void)getMessageBySyncIdAsync:(NSString*)syncId success:(void (^)(WACChatMessage*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStore3>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageBySyncIdAsync(nsStrToHstr(syncId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatMessage*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessage*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessage> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACChatMessage>(result.Get()));
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

@implementation WACChatMessageChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACChatMessageChangedDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageChangedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessageChangedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WACChatConversation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)hasUnreadMessages {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasUnreadMessages(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubject:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subject(nsStrToHstr(value).Get()));
}

- (BOOL)isConversationMuted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsConversationMuted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsConversationMuted:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsConversationMuted((boolean)value));
}

- (NSString*)mostRecentMessageId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MostRecentMessageId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSMutableArray* /* NSString * */)participants {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Participants(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WACChatConversationThreadingInfo*)threadingInfo {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThreadingInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatConversationThreadingInfo>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WACChatMessageReader*)getMessageReader {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessageReader>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markAllMessagesAsReadAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->MarkAllMessagesAsReadAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)markMessagesAsReadAsync:(WFDateTime*)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->MarkMessagesAsReadAsync(*[value internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)saveAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->SaveAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)notifyLocalParticipantComposing:(NSString*)transportId
                     participantAddress:(NSString*)participantAddress
                            isComposing:(BOOL)isComposing {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyLocalParticipantComposing(nsStrToHstr(transportId).Get(),
                                                                 nsStrToHstr(participantAddress).Get(),
                                                                 (boolean)isComposing));
}

- (void)notifyRemoteParticipantComposing:(NSString*)transportId
                      participantAddress:(NSString*)participantAddress
                             isComposing:(BOOL)isComposing {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyRemoteParticipantComposing(nsStrToHstr(transportId).Get(),
                                                                  nsStrToHstr(participantAddress).Get(),
                                                                  (boolean)isComposing));
}

- (EventRegistrationToken)addRemoteParticipantComposingChangedEvent:(void (^)(WACChatConversation*,
                                                                              WACRemoteParticipantComposingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->add_RemoteParticipantComposingChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Chat_ChatConversation_Windows_ApplicationModel_Chat_RemoteParticipantComposingChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemoteParticipantComposingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RemoteParticipantComposingChanged(token));
}

- (BOOL)canModifyParticipants {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanModifyParticipants(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanModifyParticipants:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanModifyParticipants((boolean)value));
}

- (WACChatItemKind)itemKind {
    ABI::Windows::ApplicationModel::Chat::ChatItemKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemKind(&unmarshalledReturn));
    return (WACChatItemKind)unmarshalledReturn;
}

@end

@implementation WACChatConversationReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatConversationReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WACChatConversation* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACChatConversation_create(result.Get()));
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

- (void)readBatchWithCountAsync:(int)count
                        success:(void (^)(NSArray* /* WACChatConversation* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatConversationReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchWithCountAsync(count, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACChatConversation_create(result.Get()));
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

@implementation WACChatQueryOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatQueryOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatQueryOptions").Get(), &out));
    return [_createRtProxy<WACChatQueryOptions>(out.Get()) retain];
}

- (NSString*)searchString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSearchString:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_SearchString(nsStrToHstr(value).Get()));
}

@end

@implementation WACChatSearchReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatSearchReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WACIChatItem>* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSearchReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_RTObject_WACIChatItem_create(result.Get()));
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

- (void)readBatchWithCountAsync:(int)count
                        success:(void (^)(NSArray* /* RTObject<WACIChatItem>* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSearchReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchWithCountAsync(count, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_RTObject_WACIChatItem_create(result.Get()));
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

@implementation WACChatMessageStoreChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACChatStoreChangedEventKind)kind {
    ABI::Windows::ApplicationModel::Chat::ChatStoreChangedEventKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WACChatStoreChangedEventKind)unmarshalledReturn;
}

@end

@implementation WACChatMessageChangedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageChangedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageChangedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WACChatMessageTransport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isAppSetAsNotificationProvider {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAppSetAsNotificationProvider(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)transportFriendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportFriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)transportId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)requestSetAsNotificationProviderAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport>(self);
    THROW_NS_IF_FAILED(_comInst->RequestSetAsNotificationProviderAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WACChatMessageTransportConfiguration*)configuration {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Configuration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessageTransportConfiguration>(unmarshalledReturn.Get());
}

- (WACChatMessageTransportKind)transportKind {
    ABI::Windows::ApplicationModel::Chat::ChatMessageTransportKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportKind(&unmarshalledReturn));
    return (WACChatMessageTransportKind)unmarshalledReturn;
}

@end

@implementation WACChatSyncManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatSyncManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACChatSyncConfiguration*)configuration {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatSyncConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_Configuration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatSyncConfiguration>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)associateAccountAsync:(WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->AssociateAccountAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)unassociateAccountAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->UnassociateAccountAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (BOOL)isAccountAssociated:(WSCWebAccount*)webAccount {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->IsAccountAssociated(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                                     &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)startSync {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->StartSync());
}

- (RTObject<WFIAsyncAction>*)setConfigurationAsync:(WACChatSyncConfiguration*)configuration {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetConfigurationAsync(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncConfiguration>(configuration).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACChatCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isOnline {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOnline(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isChatCapable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsChatCapable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isFileTransferCapable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFileTransferCapable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isGeoLocationPushCapable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGeoLocationPushCapable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isIntegratedMessagingCapable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsIntegratedMessagingCapable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WACRemoteParticipantComposingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)transportId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)participantAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParticipantAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isComposing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsComposing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WACChatSyncConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatSyncConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isSyncEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSyncEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSyncEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSyncEnabled((boolean)value));
}

- (WACChatRestoreHistorySpan)restoreHistorySpan {
    ABI::Windows::ApplicationModel::Chat::ChatRestoreHistorySpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_RestoreHistorySpan(&unmarshalledReturn));
    return (WACChatRestoreHistorySpan)unmarshalledReturn;
}

- (void)setRestoreHistorySpan:(WACChatRestoreHistorySpan)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatSyncConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_RestoreHistorySpan((ABI::Windows::ApplicationModel::Chat::ChatRestoreHistorySpan)value));
}

@end

@implementation WACRcsEndUserMessageManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addMessageAvailableChangedEvent:(void (^)(WACRcsEndUserMessageManager*,
                                                                    WACRcsEndUserMessageAvailableEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_MessageAvailableChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Chat_RcsEndUserMessageManager_Windows_ApplicationModel_Chat_RcsEndUserMessageAvailableEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMessageAvailableChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MessageAvailableChanged(token));
}

@end

@implementation WACRcsTransport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsTransport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSDictionary* /* NSString *, RTObject* */)extendedProperties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)transportFriendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportFriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)transportId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACRcsTransportConfiguration*)configuration {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Configuration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACRcsTransportConfiguration>(unmarshalledReturn.Get());
}

- (BOOL)isStoreAndForwardEnabled:(WACRcsServiceKind)serviceKind {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsStoreAndForwardEnabled((ABI::Windows::ApplicationModel::Chat::RcsServiceKind)serviceKind, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isServiceKindSupported:(WACRcsServiceKind)serviceKind {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsServiceKindSupported((ABI::Windows::ApplicationModel::Chat::RcsServiceKind)serviceKind, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addServiceKindSupportedChangedEvent:(void (^)(WACRcsTransport*,
                                                                        WACRcsServiceKindSupportedChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(_comInst->add_ServiceKindSupportedChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Chat_RcsTransport_Windows_ApplicationModel_Chat_RcsServiceKindSupportedChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeServiceKindSupportedChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransport>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ServiceKindSupportedChanged(token));
}

@end

@implementation WACRcsTransportConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)maxAttachmentCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxAttachmentCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxMessageSizeInKilobytes {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxMessageSizeInKilobytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxGroupMessageSizeInKilobytes {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxGroupMessageSizeInKilobytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxRecipientCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxRecipientCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxFileSizeInKilobytes {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxFileSizeInKilobytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)warningFileSizeInKilobytes {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_WarningFileSizeInKilobytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WACRcsServiceKindSupportedChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACRcsServiceKind)serviceKind {
    ABI::Windows::ApplicationModel::Chat::RcsServiceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceKind(&unmarshalledReturn));
    return (WACRcsServiceKind)unmarshalledReturn;
}

@end

@implementation WACRcsEndUserMessageAvailableEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isMessageAvailable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMessageAvailable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WACRcsEndUserMessage*)message {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACRcsEndUserMessage>(unmarshalledReturn.Get());
}

@end

@implementation WACRcsEndUserMessageAction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACRcsEndUserMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)transportId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isPinRequired {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPinRequired(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WACRcsEndUserMessageAction* */)actions {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageAction*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Actions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACRcsEndUserMessageAction_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)sendResponseAsync:(WACRcsEndUserMessageAction*)action {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendResponseAsync(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAction>(action).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)sendResponseWithPinAsync:(WACRcsEndUserMessageAction*)action pin:(NSString*)pin {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendResponseWithPinAsync(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAction>(action).Get(),
                                           nsStrToHstr(pin).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACChatMessageManager

ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManager2Statics> WACIChatMessageManager2Statics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManager2Statics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatMessageManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)registerTransportAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WACIChatMessageManager2Statics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterTransportAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)getTransportAsync:(NSString*)transportId success:(void (^)(WACChatMessageTransport*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>> unmarshalledReturn;
    auto _comInst = WACIChatMessageManager2Statics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTransportAsync(nsStrToHstr(transportId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACChatMessageTransport>(result.Get()));
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

ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManagerStatic> WACIChatMessageManagerStatic_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManagerStatic> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatMessageManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)getTransportsAsyncWithSuccess:(void (^)(NSArray* /* WACChatMessageTransport* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>*>>
        unmarshalledReturn;
    auto _comInst = WACIChatMessageManagerStatic_inst();
    THROW_NS_IF_FAILED(_comInst->GetTransportsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACChatMessageTransport_create(result.Get()));
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

+ (void)requestStoreAsyncWithSuccess:(void (^)(WACChatMessageStore*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessageStore*>> unmarshalledReturn;
    auto _comInst = WACIChatMessageManagerStatic_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatMessageStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatMessageStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACChatMessageStore>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)showComposeSmsMessageAsync:(WACChatMessage*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WACIChatMessageManagerStatic_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowComposeSmsMessageAsync(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatMessage>(message).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)showSmsSettings {
    auto _comInst = WACIChatMessageManagerStatic_inst();
    THROW_NS_IF_FAILED(_comInst->ShowSmsSettings());
}

ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManagerStatics3> WACIChatMessageManagerStatics3_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageManagerStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatMessageManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)requestSyncManagerAsyncWithSuccess:(void (^)(WACChatSyncManager*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatSyncManager*>> unmarshalledReturn;
    auto _comInst = WACIChatMessageManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->RequestSyncManagerAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatSyncManager*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatSyncManager*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatSyncManager> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACChatSyncManager>(result.Get()));
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

@implementation WACChatMessageNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACChatMessage*)chatMessage {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChatMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACChatMessage>(unmarshalledReturn.Get());
}

- (BOOL)shouldDisplayToast {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShouldDisplayToast(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)shouldUpdateDetailText {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShouldUpdateDetailText(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)shouldUpdateBadge {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShouldUpdateBadge(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)shouldUpdateActionCenter {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShouldUpdateActionCenter(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WACChatMessageBlocking

ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageBlockingStatic> WACIChatMessageBlockingStatic_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatMessageBlockingStatic> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatMessageBlocking").Get(),
                                                       &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)markMessageAsBlockedAsync:(NSString*)localChatMessageId blocked:(BOOL)blocked {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WACIChatMessageBlockingStatic_inst();
    THROW_NS_IF_FAILED(
        _comInst->MarkMessageAsBlockedAsync(nsStrToHstr(localChatMessageId).Get(), (boolean)blocked, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACChatCapabilitiesManager

ComPtr<ABI::Windows::ApplicationModel::Chat::IChatCapabilitiesManagerStatics> WACIChatCapabilitiesManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatCapabilitiesManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Chat.ChatCapabilitiesManager").Get(), &inst));
    return inst;
}

+ (void)getCachedCapabilitiesAsync:(NSString*)address success:(void (^)(WACChatCapabilities*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatCapabilities*>> unmarshalledReturn;
    auto _comInst = WACIChatCapabilitiesManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCachedCapabilitiesAsync(nsStrToHstr(address).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatCapabilities*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatCapabilities*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatCapabilities> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACChatCapabilities>(result.Get()));
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

+ (void)getCapabilitiesFromNetworkAsync:(NSString*)address
                                success:(void (^)(WACChatCapabilities*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatCapabilities*>> unmarshalledReturn;
    auto _comInst = WACIChatCapabilitiesManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCapabilitiesFromNetworkAsync(nsStrToHstr(address).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::ChatCapabilities*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::ChatCapabilities*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Chat::IChatCapabilities> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACChatCapabilities>(result.Get()));
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

@implementation WACRcsManager

ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsManagerStatics> WACIRcsManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Chat.RcsManager").Get(), &inst));
    return inst;
}

+ (WACRcsEndUserMessageManager*)getEndUserMessageManager {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageManager> unmarshalledReturn;
    auto _comInst = WACIRcsManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetEndUserMessageManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACRcsEndUserMessageManager>(unmarshalledReturn.Get());
}

+ (void)getTransportsAsyncWithSuccess:(void (^)(NSArray* /* WACRcsTransport* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::RcsTransport*>*>> unmarshalledReturn;
    auto _comInst = WACIRcsManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTransportsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Chat::RcsTransport*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Chat::RcsTransport*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Chat::RcsTransport*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACRcsTransport_create(result.Get()));
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

+ (void)getTransportAsync:(NSString*)transportId success:(void (^)(WACRcsTransport*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::RcsTransport*>> unmarshalledReturn;
    auto _comInst = WACIRcsManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTransportAsync(nsStrToHstr(transportId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Chat::RcsTransport*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Chat::RcsTransport*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsTransport> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACRcsTransport>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)leaveConversationAsync:(WACChatConversation*)conversation {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WACIRcsManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LeaveConversationAsync(_getRtInterface<ABI::Windows::ApplicationModel::Chat::IChatConversation>(conversation).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACRcsEndUserMessageAvailableTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WACIChatItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Chat::IChatItem*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Chat::IChatItem*>,
                                                    RTObject<WACIChatItem>,
                                                    ABI::Windows::ApplicationModel::Chat::IChatItem*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACChatConversation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Chat::IChatConversation*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Chat::ChatConversation*>,
                                                    WACChatConversation,
                                                    ABI::Windows::ApplicationModel::Chat::ChatConversation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACChatMessage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Chat::IChatMessage*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessage*>,
                                                    WACChatMessage,
                                                    ABI::Windows::ApplicationModel::Chat::ChatMessage*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACChatMessageChange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageChange*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Chat::IChatMessageChange*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageChange*>,
                                                    WACChatMessageChange,
                                                    ABI::Windows::ApplicationModel::Chat::ChatMessageChange*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACChatMessageTransport_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Chat::IChatMessageTransport*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*>,
                                                    WACChatMessageTransport,
                                                    ABI::Windows::ApplicationModel::Chat::ChatMessageTransport*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACRcsEndUserMessageAction_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageAction*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAction*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageAction*>,
                                                    WACRcsEndUserMessageAction,
                                                    ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageAction*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACRcsTransport_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Chat::RcsTransport*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Chat::IRcsTransport*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Chat::RcsTransport*>,
                                                    WACRcsTransport,
                                                    ABI::Windows::ApplicationModel::Chat::RcsTransport*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, IInspectable*>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          IInspectable*,
                                          IInspectable*,
                                          NSString,
                                          RTObject,
                                          IMapView<HSTRING, IInspectable*>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WACChatMessageStatus_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::ApplicationModel::Chat::ChatMessageStatus>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::ApplicationModel::Chat::ChatMessageStatus>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::ApplicationModel::Chat::ChatMessageStatus,
                     ABI::Windows::ApplicationModel::Chat::ChatMessageStatus,
                     NSString,
                     WACChatMessageStatus,
                     IMapView<HSTRING, ABI::Windows::ApplicationModel::Chat::ChatMessageStatus>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACChatMessageAttachment_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Chat::ChatMessageAttachment*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment*,
                                                                  IVector<ABI::Windows::ApplicationModel::Chat::ChatMessageAttachment*>,
                                                                  WACChatMessageAttachment,
                                                                  ABI::Windows::ApplicationModel::Chat::ChatMessageAttachment*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACChatRecipientDeliveryInfo_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo*,
                                                                  IVector<ABI::Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo*>,
                                                                  WACChatRecipientDeliveryInfo,
                                                                  ABI::Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
