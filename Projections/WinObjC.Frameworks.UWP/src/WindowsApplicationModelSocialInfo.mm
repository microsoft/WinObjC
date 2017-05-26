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

// WindowsApplicationModelSocialInfo.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.SocialInfo.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelSocialInfo.h"
#include "WindowsApplicationModelSocialInfo_priv.h"

@implementation WASSocialUserInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)userName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUserName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_UserName(nsStrToHstr(value).Get()));
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (WFUri*)targetUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setTargetUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WASSocialFeedContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMessage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Message(nsStrToHstr(value).Get()));
}

- (WFUri*)targetUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setTargetUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WASSocialItemThumbnail

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.SocialInfo.SocialItemThumbnail").Get(),
                                              &out));
    return [_createRtProxy<WASSocialItemThumbnail>(out.Get()) retain];
}

- (WFUri*)targetUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setTargetUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)imageUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setImageUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(self);
    THROW_NS_IF_FAILED(_comInst->put_ImageUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WGIBitmapSize*)bitmapSize {
    ABI::Windows::Graphics::Imaging::BitmapSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapSize(&unmarshalledReturn));
    return WGIBitmapSize_create(unmarshalledReturn);
}

- (void)setBitmapSize:(WGIBitmapSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(self);
    THROW_NS_IF_FAILED(_comInst->put_BitmapSize(*[value internalStruct]));
}

- (RTObject<WFIAsyncAction>*)setImageAsync:(RTObject<WSSIInputStream>*)image {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(self);
    THROW_NS_IF_FAILED(_comInst->SetImageAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(image).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WASSocialFeedSharedItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.SocialInfo.SocialFeedSharedItem").Get(),
                                              &out));
    return [_createRtProxy<WASSocialFeedSharedItem>(out.Get()) retain];
}

- (WFUri*)originalSource {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setOriginalSource:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_OriginalSource(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WASSocialFeedContent*)content {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedContent>(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setTimestamp:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Timestamp(*[value internalStruct]));
}

- (WFUri*)targetUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setTargetUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (void)setThumbnail:(WASSocialItemThumbnail*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Thumbnail(_getRtInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(value).Get()));
}

- (WASSocialItemThumbnail*)thumbnail {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialItemThumbnail>(unmarshalledReturn.Get());
}

@end

@implementation WASSocialFeedChildItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.SocialInfo.SocialFeedChildItem").Get(),
                                              &out));
    return [_createRtProxy<WASSocialFeedChildItem>(out.Get()) retain];
}

- (WASSocialUserInfo*)author {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Author(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialUserInfo>(unmarshalledReturn.Get());
}

- (WASSocialFeedContent*)primaryContent {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrimaryContent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedContent>(unmarshalledReturn.Get());
}

- (WASSocialFeedContent*)secondaryContent {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_SecondaryContent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedContent>(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setTimestamp:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Timestamp(*[value internalStruct]));
}

- (WFUri*)targetUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setTargetUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSMutableArray* /* WASSocialItemThumbnail* */)thumbnails {
    ComPtr<IVector<ABI::Windows::ApplicationModel::SocialInfo::SocialItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnails(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WASSocialItemThumbnail_create(unmarshalledReturn.Get());
}

- (WASSocialFeedSharedItem*)sharedItem {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharedItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedSharedItem>(unmarshalledReturn.Get());
}

- (void)setSharedItem:(WASSocialFeedSharedItem*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SharedItem(_getRtInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(value).Get()));
}

@end

@implementation WASSocialFeedItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.SocialInfo.SocialFeedItem").Get(), &out));
    return [_createRtProxy<WASSocialFeedItem>(out.Get()) retain];
}

- (WASSocialUserInfo*)author {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialUserInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Author(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialUserInfo>(unmarshalledReturn.Get());
}

- (WASSocialFeedContent*)primaryContent {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrimaryContent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedContent>(unmarshalledReturn.Get());
}

- (WASSocialFeedContent*)secondaryContent {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_SecondaryContent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedContent>(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setTimestamp:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Timestamp(*[value internalStruct]));
}

- (WFUri*)targetUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setTargetUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSMutableArray* /* WASSocialItemThumbnail* */)thumbnails {
    ComPtr<IVector<ABI::Windows::ApplicationModel::SocialInfo::SocialItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnails(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WASSocialItemThumbnail_create(unmarshalledReturn.Get());
}

- (WASSocialFeedSharedItem*)sharedItem {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharedItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedSharedItem>(unmarshalledReturn.Get());
}

- (void)setSharedItem:(WASSocialFeedSharedItem*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SharedItem(_getRtInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedSharedItem>(value).Get()));
}

- (WASSocialItemBadgeStyle)badgeStyle {
    ABI::Windows::ApplicationModel::SocialInfo::SocialItemBadgeStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_BadgeStyle(&unmarshalledReturn));
    return (WASSocialItemBadgeStyle)unmarshalledReturn;
}

- (void)setBadgeStyle:(WASSocialItemBadgeStyle)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_BadgeStyle((ABI::Windows::ApplicationModel::SocialInfo::SocialItemBadgeStyle)value));
}

- (int)badgeCountValue {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_BadgeCountValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBadgeCountValue:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_BadgeCountValue(value));
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (WASSocialFeedChildItem*)childItem {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedChildItem>(unmarshalledReturn.Get());
}

- (void)setChildItem:(WASSocialFeedChildItem*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ChildItem(_getRtInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedChildItem>(value).Get()));
}

- (WASSocialFeedItemStyle)style {
    ABI::Windows::ApplicationModel::SocialInfo::SocialFeedItemStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Style(&unmarshalledReturn));
    return (WASSocialFeedItemStyle)unmarshalledReturn;
}

- (void)setStyle:(WASSocialFeedItemStyle)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Style((ABI::Windows::ApplicationModel::SocialInfo::SocialFeedItemStyle)value));
}

@end

id RTProxiedNSMutableArray_WASSocialItemThumbnail_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::SocialInfo::SocialItemThumbnail*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail*,
                                                                  IVector<ABI::Windows::ApplicationModel::SocialInfo::SocialItemThumbnail*>,
                                                                  WASSocialItemThumbnail,
                                                                  ABI::Windows::ApplicationModel::SocialInfo::SocialItemThumbnail*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
