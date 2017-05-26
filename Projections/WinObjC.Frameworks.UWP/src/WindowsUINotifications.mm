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

// WindowsUINotifications.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Notifications.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUINotifications.h"
#include "WindowsUINotifications_priv.h"

@implementation WUNIAdaptiveNotificationContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IAdaptiveNotificationContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNAdaptiveNotificationContentKind)kind {
    ABI::Windows::UI::Notifications::AdaptiveNotificationContentKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IAdaptiveNotificationContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WUNAdaptiveNotificationContentKind)unmarshalledReturn;
}

- (NSMutableDictionary* /* NSString *, NSString * */)hints {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IAdaptiveNotificationContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Hints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WUNShownTileNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IShownTileNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)arguments {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IShownTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUNNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::INotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Notifications.Notification").Get(), &out));
    return [_createRtProxy<WUNNotification>(out.Get()) retain];
}

- (id /* WFDateTime* */)expirationTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setExpirationTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExpirationTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WUNNotificationVisual*)visual {
    ComPtr<ABI::Windows::UI::Notifications::INotificationVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visual(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNNotificationVisual>(unmarshalledReturn.Get());
}

- (void)setVisual:(WUNNotificationVisual*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_Visual(_getRtInterface<ABI::Windows::UI::Notifications::INotificationVisual>(value).Get()));
}

@end

@implementation WUNNotificationBinding

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::INotificationBinding> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)Template {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_Template(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTemplate:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_Template(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, NSString * */)hints {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_Hints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* WUNAdaptiveNotificationText* */)getTextElements {
    ComPtr<IVectorView<ABI::Windows::UI::Notifications::AdaptiveNotificationText*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationBinding>(self);
    THROW_NS_IF_FAILED(_comInst->GetTextElements(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUNAdaptiveNotificationText_create(unmarshalledReturn.Get());
}

@end

@implementation WUNAdaptiveNotificationText

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IAdaptiveNotificationText> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Notifications.AdaptiveNotificationText").Get(), &out));
    return [_createRtProxy<WUNAdaptiveNotificationText>(out.Get()) retain];
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IAdaptiveNotificationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IAdaptiveNotificationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IAdaptiveNotificationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IAdaptiveNotificationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (WUNAdaptiveNotificationContentKind)kind {
    ABI::Windows::UI::Notifications::AdaptiveNotificationContentKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IAdaptiveNotificationContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WUNAdaptiveNotificationContentKind)unmarshalledReturn;
}

- (NSMutableDictionary* /* NSString *, NSString * */)hints {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IAdaptiveNotificationContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Hints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WUNTileUpdater

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)update:(WUNTileNotification*)notification {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->Update(_getRtInterface<ABI::Windows::UI::Notifications::ITileNotification>(notification).Get()));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (void)enableNotificationQueue:(BOOL)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->EnableNotificationQueue((boolean)enable));
}

- (WUNNotificationSetting)setting {
    ABI::Windows::UI::Notifications::NotificationSetting unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Setting(&unmarshalledReturn));
    return (WUNNotificationSetting)unmarshalledReturn;
}

- (void)addToSchedule:(WUNScheduledTileNotification*)scheduledTile {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddToSchedule(_getRtInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(scheduledTile).Get()));
}

- (void)removeFromSchedule:(WUNScheduledTileNotification*)scheduledTile {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveFromSchedule(_getRtInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(scheduledTile).Get()));
}

- (NSArray* /* WUNScheduledTileNotification* */)getScheduledTileNotifications {
    ComPtr<IVectorView<ABI::Windows::UI::Notifications::ScheduledTileNotification*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->GetScheduledTileNotifications(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUNScheduledTileNotification_create(unmarshalledReturn.Get());
}

- (void)startPeriodicUpdate:(WFUri*)tileContent requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StartPeriodicUpdate(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(tileContent).Get(),
                                                     (ABI::Windows::UI::Notifications::PeriodicUpdateRecurrence)requestedInterval));
}

- (void)startPeriodicUpdateAtTime:(WFUri*)tileContent
                        startTime:(WFDateTime*)startTime
                requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StartPeriodicUpdateAtTime(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(tileContent).Get(),
                                                           *[startTime internalStruct],
                                                           (ABI::Windows::UI::Notifications::PeriodicUpdateRecurrence)requestedInterval));
}

- (void)stopPeriodicUpdate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StopPeriodicUpdate());
}

- (void)startPeriodicUpdateBatch:(id<NSFastEnumeration> /* WFUri* */)tileContents
               requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StartPeriodicUpdateBatch(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(tileContents)
                .Get()),
        (ABI::Windows::UI::Notifications::PeriodicUpdateRecurrence)requestedInterval));
}

- (void)startPeriodicUpdateBatchAtTime:(id<NSFastEnumeration> /* WFUri* */)tileContents
                             startTime:(WFDateTime*)startTime
                     requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StartPeriodicUpdateBatchAtTime(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(tileContents)
                .Get()),
        *[startTime internalStruct],
        (ABI::Windows::UI::Notifications::PeriodicUpdateRecurrence)requestedInterval));
}

- (void)enableNotificationQueueForSquare150x150:(BOOL)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater2>(self);
    THROW_NS_IF_FAILED(_comInst->EnableNotificationQueueForSquare150x150((boolean)enable));
}

- (void)enableNotificationQueueForWide310x150:(BOOL)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater2>(self);
    THROW_NS_IF_FAILED(_comInst->EnableNotificationQueueForWide310x150((boolean)enable));
}

- (void)enableNotificationQueueForSquare310x310:(BOOL)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdater2>(self);
    THROW_NS_IF_FAILED(_comInst->EnableNotificationQueueForSquare310x310((boolean)enable));
}

@end

@implementation WUNTileUpdateManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdateManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNTileUpdater*)createTileUpdaterForApplication {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdateManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->CreateTileUpdaterForApplication(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdater>(unmarshalledReturn.Get());
}

- (WUNTileUpdater*)createTileUpdaterForApplicationWithId:(NSString*)applicationId {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdateManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateTileUpdaterForApplicationWithId(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdater>(unmarshalledReturn.Get());
}

- (WUNTileUpdater*)createTileUpdaterForSecondaryTile:(NSString*)tileId {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdateManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->CreateTileUpdaterForSecondaryTile(nsStrToHstr(tileId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdater>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileUpdateManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUNTileNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::ITileNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Notifications::ITileNotificationFactory> WUNITileNotificationFactory_inst() {
    ComPtr<ABI::Windows::UI::Notifications::ITileNotificationFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.TileNotification").Get(), &inst));
    return inst;
}

+ (WUNTileNotification*)makeTileNotification:(WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::UI::Notifications::ITileNotification> unmarshalledReturn;
    auto _comInst = WUNITileNotificationFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTileNotification(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(content).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUNTileNotification>(unmarshalledReturn.Get()) retain];
}

- (WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (void)setExpirationTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExpirationTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)expirationTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUNScheduledTileNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IScheduledTileNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Notifications::IScheduledTileNotificationFactory> WUNIScheduledTileNotificationFactory_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IScheduledTileNotificationFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.ScheduledTileNotification").Get(),
                                                       &inst));
    return inst;
}

+ (WUNScheduledTileNotification*)makeScheduledTileNotification:(WDXDXmlDocument*)content deliveryTime:(WFDateTime*)deliveryTime {
    ComPtr<ABI::Windows::UI::Notifications::IScheduledTileNotification> unmarshalledReturn;
    auto _comInst = WUNIScheduledTileNotificationFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateScheduledTileNotification(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(content).Get(),
                                                                 *[deliveryTime internalStruct],
                                                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUNScheduledTileNotification>(unmarshalledReturn.Get()) retain];
}

- (WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (WFDateTime*)deliveryTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeliveryTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setExpirationTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExpirationTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)expirationTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledTileNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUNTileFlyoutUpdater

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutUpdater> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)update:(WUNTileFlyoutNotification*)notification {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->Update(_getRtInterface<ABI::Windows::UI::Notifications::ITileFlyoutNotification>(notification).Get()));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (void)startPeriodicUpdate:(WFUri*)tileFlyoutContent requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StartPeriodicUpdate(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(tileFlyoutContent).Get(),
                                                     (ABI::Windows::UI::Notifications::PeriodicUpdateRecurrence)requestedInterval));
}

- (void)startPeriodicUpdateAtTime:(WFUri*)tileFlyoutContent
                        startTime:(WFDateTime*)startTime
                requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutUpdater>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartPeriodicUpdateAtTime(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(tileFlyoutContent).Get(),
                                            *[startTime internalStruct],
                                            (ABI::Windows::UI::Notifications::PeriodicUpdateRecurrence)requestedInterval));
}

- (void)stopPeriodicUpdate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StopPeriodicUpdate());
}

- (WUNNotificationSetting)setting {
    ABI::Windows::UI::Notifications::NotificationSetting unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Setting(&unmarshalledReturn));
    return (WUNNotificationSetting)unmarshalledReturn;
}

@end

@implementation WUNTileFlyoutNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutNotificationFactory> WUNITileFlyoutNotificationFactory_inst() {
    ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutNotificationFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.TileFlyoutNotification").Get(),
                                                       &inst));
    return inst;
}

+ (WUNTileFlyoutNotification*)makeTileFlyoutNotification:(WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutNotification> unmarshalledReturn;
    auto _comInst = WUNITileFlyoutNotificationFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTileFlyoutNotification(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(content).Get(),
                                                              unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUNTileFlyoutNotification>(unmarshalledReturn.Get()) retain];
}

- (WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (void)setExpirationTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExpirationTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)expirationTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::ITileFlyoutNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

@end

@implementation WUNBadgeUpdater

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)update:(WUNBadgeNotification*)notification {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->Update(_getRtInterface<ABI::Windows::UI::Notifications::IBadgeNotification>(notification).Get()));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (void)startPeriodicUpdate:(WFUri*)badgeContent requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StartPeriodicUpdate(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(badgeContent).Get(),
                                                     (ABI::Windows::UI::Notifications::PeriodicUpdateRecurrence)requestedInterval));
}

- (void)startPeriodicUpdateAtTime:(WFUri*)badgeContent
                        startTime:(WFDateTime*)startTime
                requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StartPeriodicUpdateAtTime(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(badgeContent).Get(),
                                                           *[startTime internalStruct],
                                                           (ABI::Windows::UI::Notifications::PeriodicUpdateRecurrence)requestedInterval));
}

- (void)stopPeriodicUpdate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->StopPeriodicUpdate());
}

@end

@implementation WUNBadgeUpdateManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdateManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNBadgeUpdater*)createBadgeUpdaterForApplication {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdateManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->CreateBadgeUpdaterForApplication(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdater>(unmarshalledReturn.Get());
}

- (WUNBadgeUpdater*)createBadgeUpdaterForApplicationWithId:(NSString*)applicationId {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdateManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateBadgeUpdaterForApplicationWithId(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdater>(unmarshalledReturn.Get());
}

- (WUNBadgeUpdater*)createBadgeUpdaterForSecondaryTile:(NSString*)tileId {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdateManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->CreateBadgeUpdaterForSecondaryTile(nsStrToHstr(tileId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdater>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeUpdateManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUNBadgeNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Notifications::IBadgeNotificationFactory> WUNIBadgeNotificationFactory_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeNotificationFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.BadgeNotification").Get(), &inst));
    return inst;
}

+ (WUNBadgeNotification*)makeBadgeNotification:(WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeNotification> unmarshalledReturn;
    auto _comInst = WUNIBadgeNotificationFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBadgeNotification(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(content).Get(),
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUNBadgeNotification>(unmarshalledReturn.Get()) retain];
}

- (WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (void)setExpirationTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExpirationTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)expirationTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IBadgeNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

@end

@implementation WUNToastNotifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)show:(WUNToastNotification*)notification {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->Show(_getRtInterface<ABI::Windows::UI::Notifications::IToastNotification>(notification).Get()));
}

- (void)hide:(WUNToastNotification*)notification {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->Hide(_getRtInterface<ABI::Windows::UI::Notifications::IToastNotification>(notification).Get()));
}

- (WUNNotificationSetting)setting {
    ABI::Windows::UI::Notifications::NotificationSetting unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_Setting(&unmarshalledReturn));
    return (WUNNotificationSetting)unmarshalledReturn;
}

- (void)addToSchedule:(WUNScheduledToastNotification*)scheduledToast {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotifier>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddToSchedule(_getRtInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification>(scheduledToast).Get()));
}

- (void)removeFromSchedule:(WUNScheduledToastNotification*)scheduledToast {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotifier>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveFromSchedule(_getRtInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification>(scheduledToast).Get()));
}

- (NSArray* /* WUNScheduledToastNotification* */)getScheduledToastNotifications {
    ComPtr<IVectorView<ABI::Windows::UI::Notifications::ScheduledToastNotification*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->GetScheduledToastNotifications(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUNScheduledToastNotification_create(unmarshalledReturn.Get());
}

@end

@implementation WUNToastNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Notifications::IToastNotificationFactory> WUNIToastNotificationFactory_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.ToastNotification").Get(), &inst));
    return inst;
}

+ (WUNToastNotification*)makeToastNotification:(WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotification> unmarshalledReturn;
    auto _comInst = WUNIToastNotificationFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateToastNotification(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(content).Get(),
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUNToastNotification>(unmarshalledReturn.Get()) retain];
}

- (WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (void)setExpirationTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExpirationTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)expirationTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addDismissedEvent:(void (^)(WUNToastNotification*, WUNToastDismissedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->add_Dismissed(
        Make<ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastDismissedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDismissedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Dismissed(cookie));
}

- (EventRegistrationToken)addActivatedEvent:(void (^)(WUNToastNotification*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Activated(Make<ITypedEventHandler_Windows_UI_Notifications_ToastNotification_System_Object>(handler).Get(),
                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActivatedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Activated(cookie));
}

- (EventRegistrationToken)addFailedEvent:(void (^)(WUNToastNotification*, WUNToastFailedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->add_Failed(
        Make<ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastFailedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Failed(token));
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGroup:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Group(nsStrToHstr(value).Get()));
}

- (NSString*)group {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSuppressPopup:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuppressPopup((boolean)value));
}

- (BOOL)suppressPopup {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuppressPopup(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUNNotificationMirroring)notificationMirroring {
    ABI::Windows::UI::Notifications::NotificationMirroring unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification3>(self);
    THROW_NS_IF_FAILED(_comInst->get_NotificationMirroring(&unmarshalledReturn));
    return (WUNNotificationMirroring)unmarshalledReturn;
}

- (void)setNotificationMirroring:(WUNNotificationMirroring)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification3>(self);
    THROW_NS_IF_FAILED(_comInst->put_NotificationMirroring((ABI::Windows::UI::Notifications::NotificationMirroring)value));
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification3>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotification3>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

@end

@implementation WUNScheduledToastNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IScheduledToastNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Notifications::IScheduledToastNotificationFactory> WUNIScheduledToastNotificationFactory_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IScheduledToastNotificationFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.ScheduledToastNotification").Get(),
                                                       &inst));
    return inst;
}

+ (WUNScheduledToastNotification*)makeScheduledToastNotification:(WDXDXmlDocument*)content deliveryTime:(WFDateTime*)deliveryTime {
    ComPtr<ABI::Windows::UI::Notifications::IScheduledToastNotification> unmarshalledReturn;
    auto _comInst = WUNIScheduledToastNotificationFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateScheduledToastNotification(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(content).Get(),
                                                   *[deliveryTime internalStruct],
                                                   unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUNScheduledToastNotification>(unmarshalledReturn.Get()) retain];
}

+ (WUNScheduledToastNotification*)makeScheduledToastNotificationRecurring:(WDXDXmlDocument*)content
                                                             deliveryTime:(WFDateTime*)deliveryTime
                                                           snoozeInterval:(WFTimeSpan*)snoozeInterval
                                                       maximumSnoozeCount:(unsigned int)maximumSnoozeCount {
    ComPtr<ABI::Windows::UI::Notifications::IScheduledToastNotification> unmarshalledReturn;
    auto _comInst = WUNIScheduledToastNotificationFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateScheduledToastNotificationRecurring(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(content).Get(),
                                                            *[deliveryTime internalStruct],
                                                            *[snoozeInterval internalStruct],
                                                            maximumSnoozeCount,
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUNScheduledToastNotification>(unmarshalledReturn.Get()) retain];
}

- (WDXDXmlDocument*)content {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (WFDateTime*)deliveryTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeliveryTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (id /* WFTimeSpan* */)snoozeInterval {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_SnoozeInterval(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (unsigned int)maximumSnoozeCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaximumSnoozeCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGroup:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Group(nsStrToHstr(value).Get()));
}

- (NSString*)group {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSuppressPopup:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuppressPopup((boolean)value));
}

- (BOOL)suppressPopup {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuppressPopup(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUNNotificationMirroring)notificationMirroring {
    ABI::Windows::UI::Notifications::NotificationMirroring unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification3>(self);
    THROW_NS_IF_FAILED(_comInst->get_NotificationMirroring(&unmarshalledReturn));
    return (WUNNotificationMirroring)unmarshalledReturn;
}

- (void)setNotificationMirroring:(WUNNotificationMirroring)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification3>(self);
    THROW_NS_IF_FAILED(_comInst->put_NotificationMirroring((ABI::Windows::UI::Notifications::NotificationMirroring)value));
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification3>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IScheduledToastNotification3>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

@end

@implementation WUNToastDismissedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastDismissedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNToastDismissalReason)reason {
    ABI::Windows::UI::Notifications::ToastDismissalReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastDismissedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WUNToastDismissalReason)unmarshalledReturn;
}

@end

@implementation WUNToastFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WUNNotificationVisual

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::INotificationVisual> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WUNNotificationBinding* */)bindings {
    ComPtr<IVector<ABI::Windows::UI::Notifications::NotificationBinding*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bindings(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUNNotificationBinding_create(unmarshalledReturn.Get());
}

- (WUNNotificationBinding*)getBinding:(NSString*)templateName {
    ComPtr<ABI::Windows::UI::Notifications::INotificationBinding> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::INotificationVisual>(self);
    THROW_NS_IF_FAILED(_comInst->GetBinding(nsStrToHstr(templateName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNNotificationBinding>(unmarshalledReturn.Get());
}

@end

@implementation WUNToastNotificationHistory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationHistory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)removeGroup:(NSString*)group {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveGroup(nsStrToHstr(group).Get()));
}

- (void)removeGroupWithId:(NSString*)group applicationId:(NSString*)applicationId {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveGroupWithId(nsStrToHstr(group).Get(), nsStrToHstr(applicationId).Get()));
}

- (void)removeGroupedTagWithId:(NSString*)tag group:(NSString*)group applicationId:(NSString*)applicationId {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveGroupedTagWithId(nsStrToHstr(tag).Get(), nsStrToHstr(group).Get(), nsStrToHstr(applicationId).Get()));
}

- (void)removeGroupedTag:(NSString*)tag group:(NSString*)group {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveGroupedTag(nsStrToHstr(tag).Get(), nsStrToHstr(group).Get()));
}

- (void)remove:(NSString*)tag {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(nsStrToHstr(tag).Get()));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (void)clearWithId:(NSString*)applicationId {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory>(self);
    THROW_NS_IF_FAILED(_comInst->ClearWithId(nsStrToHstr(applicationId).Get()));
}

- (NSArray* /* WUNToastNotification* */)getHistory {
    ComPtr<IVectorView<ABI::Windows::UI::Notifications::ToastNotification*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory2>(self);
    THROW_NS_IF_FAILED(_comInst->GetHistory(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUNToastNotification_create(unmarshalledReturn.Get());
}

- (NSArray* /* WUNToastNotification* */)getHistoryWithId:(NSString*)applicationId {
    ComPtr<IVectorView<ABI::Windows::UI::Notifications::ToastNotification*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistory2>(self);
    THROW_NS_IF_FAILED(_comInst->GetHistoryWithId(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUNToastNotification_create(unmarshalledReturn.Get());
}

@end

@implementation WUNToastNotificationManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNToastNotifier*)createToastNotifier {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->CreateToastNotifier(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotifier>(unmarshalledReturn.Get());
}

- (WUNToastNotifier*)createToastNotifierWithId:(NSString*)applicationId {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->CreateToastNotifierWithId(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotifier>(unmarshalledReturn.Get());
}

- (WUNToastNotificationHistory*)history {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationHistory> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_History(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotificationHistory>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUNUserNotificationChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IUserNotificationChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNUserNotificationChangedKind)changeKind {
    ABI::Windows::UI::Notifications::UserNotificationChangedKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IUserNotificationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeKind(&unmarshalledReturn));
    return (WUNUserNotificationChangedKind)unmarshalledReturn;
}

- (unsigned int)userNotificationId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IUserNotificationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserNotificationId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUNUserNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IUserNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNNotification*)notification {
    ComPtr<ABI::Windows::UI::Notifications::INotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IUserNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Notification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNNotification>(unmarshalledReturn.Get());
}

- (WAAppInfo*)appInfo {
    ComPtr<ABI::Windows::ApplicationModel::IAppInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IUserNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAppInfo>(unmarshalledReturn.Get());
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IUserNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)creationTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IUserNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_CreationTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WUNKnownAdaptiveNotificationHints

ComPtr<ABI::Windows::UI::Notifications::IKnownAdaptiveNotificationHintsStatics> WUNIKnownAdaptiveNotificationHintsStatics_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IKnownAdaptiveNotificationHintsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Notifications.KnownAdaptiveNotificationHints").Get(), &inst));
    return inst;
}

+ (NSString*)style {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationHintsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Style(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wrap {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationHintsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wrap(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)maxLines {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationHintsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxLines(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)minLines {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationHintsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinLines(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)textStacking {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationHintsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TextStacking(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)align {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationHintsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Align(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUNKnownNotificationBindings

ComPtr<ABI::Windows::UI::Notifications::IKnownNotificationBindingsStatics> WUNIKnownNotificationBindingsStatics_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IKnownNotificationBindingsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.KnownNotificationBindings").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)toastGeneric {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownNotificationBindingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ToastGeneric(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUNKnownAdaptiveNotificationTextStyles

ComPtr<ABI::Windows::UI::Notifications::IKnownAdaptiveNotificationTextStylesStatics> WUNIKnownAdaptiveNotificationTextStylesStatics_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IKnownAdaptiveNotificationTextStylesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Notifications.KnownAdaptiveNotificationTextStyles").Get(), &inst));
    return inst;
}

+ (NSString*)caption {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Caption(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)base {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Base(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)subtitle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Subtitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)subheader {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Subheader(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)header {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Header(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)titleNumeral {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TitleNumeral(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)subheaderNumeral {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SubheaderNumeral(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)headerNumeral {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeaderNumeral(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)captionSubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CaptionSubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bodySubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BodySubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)baseSubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BaseSubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)subtitleSubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SubtitleSubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)titleSubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TitleSubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)subheaderSubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SubheaderSubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)subheaderNumeralSubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SubheaderNumeralSubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)headerSubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeaderSubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)headerNumeralSubtle {
    HSTRING unmarshalledReturn;
    auto _comInst = WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeaderNumeralSubtle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUNTileUpdateManager

ComPtr<ABI::Windows::UI::Notifications::ITileUpdateManagerStatics2> WUNITileUpdateManagerStatics2_inst() {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdateManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.TileUpdateManager").Get(), &inst));
    return inst;
}

+ (WUNTileUpdateManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdateManagerForUser> unmarshalledReturn;
    auto _comInst = WUNITileUpdateManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdateManagerForUser>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Notifications::ITileUpdateManagerStatics> WUNITileUpdateManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdateManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.TileUpdateManager").Get(), &inst));
    return inst;
}

+ (WUNTileUpdater*)createTileUpdaterForApplication {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> unmarshalledReturn;
    auto _comInst = WUNITileUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTileUpdaterForApplication(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdater>(unmarshalledReturn.Get());
}

+ (WUNTileUpdater*)createTileUpdaterForApplicationWithId:(NSString*)applicationId {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> unmarshalledReturn;
    auto _comInst = WUNITileUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateTileUpdaterForApplicationWithId(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdater>(unmarshalledReturn.Get());
}

+ (WUNTileUpdater*)createTileUpdaterForSecondaryTile:(NSString*)tileId {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> unmarshalledReturn;
    auto _comInst = WUNITileUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTileUpdaterForSecondaryTile(nsStrToHstr(tileId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdater>(unmarshalledReturn.Get());
}

+ (WDXDXmlDocument*)getTemplateContent:(WUNTileTemplateType)type {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = WUNITileUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetTemplateContent((ABI::Windows::UI::Notifications::TileTemplateType)type, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

@end

@implementation WUNBadgeUpdateManager

ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdateManagerStatics> WUNIBadgeUpdateManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdateManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.BadgeUpdateManager").Get(),
                                                       &inst));
    return inst;
}

+ (WUNBadgeUpdater*)createBadgeUpdaterForApplication {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> unmarshalledReturn;
    auto _comInst = WUNIBadgeUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBadgeUpdaterForApplication(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdater>(unmarshalledReturn.Get());
}

+ (WUNBadgeUpdater*)createBadgeUpdaterForApplicationWithId:(NSString*)applicationId {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> unmarshalledReturn;
    auto _comInst = WUNIBadgeUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateBadgeUpdaterForApplicationWithId(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdater>(unmarshalledReturn.Get());
}

+ (WUNBadgeUpdater*)createBadgeUpdaterForSecondaryTile:(NSString*)tileId {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> unmarshalledReturn;
    auto _comInst = WUNIBadgeUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBadgeUpdaterForSecondaryTile(nsStrToHstr(tileId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdater>(unmarshalledReturn.Get());
}

+ (WDXDXmlDocument*)getTemplateContent:(WUNBadgeTemplateType)type {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = WUNIBadgeUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetTemplateContent((ABI::Windows::UI::Notifications::BadgeTemplateType)type, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdateManagerStatics2> WUNIBadgeUpdateManagerStatics2_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdateManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.BadgeUpdateManager").Get(),
                                                       &inst));
    return inst;
}

+ (WUNBadgeUpdateManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdateManagerForUser> unmarshalledReturn;
    auto _comInst = WUNIBadgeUpdateManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdateManagerForUser>(unmarshalledReturn.Get());
}

@end

@implementation WUNTileFlyoutUpdateManager

ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutUpdateManagerStatics> WUNITileFlyoutUpdateManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutUpdateManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.TileFlyoutUpdateManager").Get(),
                                                       &inst));
    return inst;
}

+ (WUNTileFlyoutUpdater*)createTileFlyoutUpdaterForApplication {
    ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutUpdater> unmarshalledReturn;
    auto _comInst = WUNITileFlyoutUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTileFlyoutUpdaterForApplication(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileFlyoutUpdater>(unmarshalledReturn.Get());
}

+ (WUNTileFlyoutUpdater*)createTileFlyoutUpdaterForApplicationWithId:(NSString*)applicationId {
    ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutUpdater> unmarshalledReturn;
    auto _comInst = WUNITileFlyoutUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateTileFlyoutUpdaterForApplicationWithId(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileFlyoutUpdater>(unmarshalledReturn.Get());
}

+ (WUNTileFlyoutUpdater*)createTileFlyoutUpdaterForSecondaryTile:(NSString*)tileId {
    ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutUpdater> unmarshalledReturn;
    auto _comInst = WUNITileFlyoutUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTileFlyoutUpdaterForSecondaryTile(nsStrToHstr(tileId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileFlyoutUpdater>(unmarshalledReturn.Get());
}

+ (WDXDXmlDocument*)getTemplateContent:(WUNTileFlyoutTemplateType)type {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = WUNITileFlyoutUpdateManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetTemplateContent((ABI::Windows::UI::Notifications::TileFlyoutTemplateType)type, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

@end

@implementation WUNToastNotificationManager

ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics> WUNIToastNotificationManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.ToastNotificationManager").Get(),
                                                       &inst));
    return inst;
}

+ (WUNToastNotifier*)createToastNotifier {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> unmarshalledReturn;
    auto _comInst = WUNIToastNotificationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateToastNotifier(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotifier>(unmarshalledReturn.Get());
}

+ (WUNToastNotifier*)createToastNotifierWithId:(NSString*)applicationId {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> unmarshalledReturn;
    auto _comInst = WUNIToastNotificationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateToastNotifierWithId(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotifier>(unmarshalledReturn.Get());
}

+ (WDXDXmlDocument*)getTemplateContent:(WUNToastTemplateType)type {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = WUNIToastNotificationManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetTemplateContent((ABI::Windows::UI::Notifications::ToastTemplateType)type, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics2> WUNIToastNotificationManagerStatics2_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.ToastNotificationManager").Get(),
                                                       &inst));
    return inst;
}

+ (WUNToastNotificationHistory*)history {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationHistory> unmarshalledReturn;
    auto _comInst = WUNIToastNotificationManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_History(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotificationHistory>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics4> WUNIToastNotificationManagerStatics4_inst() {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics4> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Notifications.ToastNotificationManager").Get(),
                                                       &inst));
    return inst;
}

+ (WUNToastNotificationManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerForUser> unmarshalledReturn;
    auto _comInst = WUNIToastNotificationManagerStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotificationManagerForUser>(unmarshalledReturn.Get());
}

+ (void)configureNotificationMirroring:(WUNNotificationMirroring)value {
    auto _comInst = WUNIToastNotificationManagerStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->ConfigureNotificationMirroring((ABI::Windows::UI::Notifications::NotificationMirroring)value));
}

@end

@implementation WUNToastActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)arguments {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUNToastNotificationHistoryChangedTriggerDetail

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNToastHistoryChangedType)changeType {
    ABI::Windows::UI::Notifications::ToastHistoryChangedType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeType(&unmarshalledReturn));
    return (WUNToastHistoryChangedType)unmarshalledReturn;
}

@end

@implementation WUNToastNotificationActionTriggerDetail

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotificationActionTriggerDetail> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)argument {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationActionTriggerDetail>(self);
    THROW_NS_IF_FAILED(_comInst->get_Argument(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFCValueSet*)userInput {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::IToastNotificationActionTriggerDetail>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserInput(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_WFUri_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Foundation::Uri*>,
                                                 RTIterableObj<ABI::Windows::Foundation::IUriRuntimeClass*,
                                                               IIterable<ABI::Windows::Foundation::Uri*>,
                                                               WFUri,
                                                               ABI::Windows::Foundation::Uri*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUNAdaptiveNotificationText_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Notifications::AdaptiveNotificationText*>,
                                         RTArrayObj<ABI::Windows::UI::Notifications::IAdaptiveNotificationText*,
                                                    IVectorView<ABI::Windows::UI::Notifications::AdaptiveNotificationText*>,
                                                    WUNAdaptiveNotificationText,
                                                    ABI::Windows::UI::Notifications::AdaptiveNotificationText*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUNScheduledTileNotification_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Notifications::ScheduledTileNotification*>,
                                         RTArrayObj<ABI::Windows::UI::Notifications::IScheduledTileNotification*,
                                                    IVectorView<ABI::Windows::UI::Notifications::ScheduledTileNotification*>,
                                                    WUNScheduledTileNotification,
                                                    ABI::Windows::UI::Notifications::ScheduledTileNotification*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUNScheduledToastNotification_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Notifications::ScheduledToastNotification*>,
                                         RTArrayObj<ABI::Windows::UI::Notifications::IScheduledToastNotification*,
                                                    IVectorView<ABI::Windows::UI::Notifications::ScheduledToastNotification*>,
                                                    WUNScheduledToastNotification,
                                                    ABI::Windows::UI::Notifications::ScheduledToastNotification*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUNToastNotification_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Notifications::ToastNotification*>,
                                         RTArrayObj<ABI::Windows::UI::Notifications::IToastNotification*,
                                                    IVectorView<ABI::Windows::UI::Notifications::ToastNotification*>,
                                                    WUNToastNotification,
                                                    ABI::Windows::UI::Notifications::ToastNotification*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUNNotificationBinding_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Notifications::NotificationBinding*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Notifications::INotificationBinding*,
                                                                  IVector<ABI::Windows::UI::Notifications::NotificationBinding*>,
                                                                  WUNNotificationBinding,
                                                                  ABI::Windows::UI::Notifications::NotificationBinding*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
