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

// WindowsSystemProfile.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.Profile.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemProfile.h"
#include "WindowsSystemProfile_priv.h"

@implementation WSPAnalyticsVersionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Profile::IAnalyticsVersionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceFamily {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Profile::IAnalyticsVersionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceFamily(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceFamilyVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Profile::IAnalyticsVersionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceFamilyVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSPAnalyticsInfo

ComPtr<ABI::Windows::System::Profile::IAnalyticsInfoStatics> WSPIAnalyticsInfoStatics_inst() {
    ComPtr<ABI::Windows::System::Profile::IAnalyticsInfoStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Profile.AnalyticsInfo").Get(), &inst));
    return inst;
}

+ (WSPAnalyticsVersionInfo*)versionInfo {
    ComPtr<ABI::Windows::System::Profile::IAnalyticsVersionInfo> unmarshalledReturn;
    auto _comInst = WSPIAnalyticsInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VersionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPAnalyticsVersionInfo>(unmarshalledReturn.Get());
}

+ (NSString*)deviceForm {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIAnalyticsInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeviceForm(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSPSystemIdentificationInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Profile::ISystemIdentificationInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)id {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Profile::ISystemIdentificationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WSPSystemIdentificationSource)source {
    ABI::Windows::System::Profile::SystemIdentificationSource unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Profile::ISystemIdentificationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(&unmarshalledReturn));
    return (WSPSystemIdentificationSource)unmarshalledReturn;
}

@end

@implementation WSPSystemIdentification

ComPtr<ABI::Windows::System::Profile::ISystemIdentificationStatics> WSPISystemIdentificationStatics_inst() {
    ComPtr<ABI::Windows::System::Profile::ISystemIdentificationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Profile.SystemIdentification").Get(),
                                                       &inst));
    return inst;
}

+ (WSPSystemIdentificationInfo*)getSystemIdForPublisher {
    ComPtr<ABI::Windows::System::Profile::ISystemIdentificationInfo> unmarshalledReturn;
    auto _comInst = WSPISystemIdentificationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSystemIdForPublisher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPSystemIdentificationInfo>(unmarshalledReturn.Get());
}

+ (WSPSystemIdentificationInfo*)getSystemIdForUser:(WSUser*)user {
    ComPtr<ABI::Windows::System::Profile::ISystemIdentificationInfo> unmarshalledReturn;
    auto _comInst = WSPISystemIdentificationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetSystemIdForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPSystemIdentificationInfo>(unmarshalledReturn.Get());
}

@end

@implementation WSPPlatformDiagnosticsAndUsageDataSettings

ComPtr<ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>
WSPIPlatformDiagnosticsAndUsageDataSettingsStatics_inst() {
    ComPtr<ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.System.Profile.PlatformDiagnosticsAndUsageDataSettings").Get(), &inst));
    return inst;
}

+ (WSPPlatformDataCollectionLevel)collectionLevel {
    ABI::Windows::System::Profile::PlatformDataCollectionLevel unmarshalledReturn;
    auto _comInst = WSPIPlatformDiagnosticsAndUsageDataSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CollectionLevel(&unmarshalledReturn));
    return (WSPPlatformDataCollectionLevel)unmarshalledReturn;
}

+ (EventRegistrationToken)addCollectionLevelChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSPIPlatformDiagnosticsAndUsageDataSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_CollectionLevelChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeCollectionLevelChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSPIPlatformDiagnosticsAndUsageDataSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_CollectionLevelChanged(token));
}

+ (BOOL)canCollectDiagnostics:(WSPPlatformDataCollectionLevel)level {
    boolean unmarshalledReturn;
    auto _comInst = WSPIPlatformDiagnosticsAndUsageDataSettingsStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CanCollectDiagnostics((ABI::Windows::System::Profile::PlatformDataCollectionLevel)level, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSPHardwareToken

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Profile::IHardwareToken> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)id {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Profile::IHardwareToken>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)signature {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Profile::IHardwareToken>(self);
    THROW_NS_IF_FAILED(_comInst->get_Signature(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)certificate {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Profile::IHardwareToken>(self);
    THROW_NS_IF_FAILED(_comInst->get_Certificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WSPHardwareIdentification

ComPtr<ABI::Windows::System::Profile::IHardwareIdentificationStatics> WSPIHardwareIdentificationStatics_inst() {
    ComPtr<ABI::Windows::System::Profile::IHardwareIdentificationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Profile.HardwareIdentification").Get(),
                                                       &inst));
    return inst;
}

+ (WSPHardwareToken*)getPackageSpecificToken:(RTObject<WSSIBuffer>*)nonce {
    ComPtr<ABI::Windows::System::Profile::IHardwareToken> unmarshalledReturn;
    auto _comInst = WSPIHardwareIdentificationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetPackageSpecificToken(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(nonce).Get(),
                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPHardwareToken>(unmarshalledReturn.Get());
}

@end

@implementation WSPRetailInfo

ComPtr<ABI::Windows::System::Profile::IRetailInfoStatics> WSPIRetailInfoStatics_inst() {
    ComPtr<ABI::Windows::System::Profile::IRetailInfoStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Profile.RetailInfo").Get(), &inst));
    return inst;
}

+ (BOOL)isDemoModeEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WSPIRetailInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsDemoModeEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = WSPIRetailInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WSPKnownRetailInfoProperties

ComPtr<ABI::Windows::System::Profile::IKnownRetailInfoPropertiesStatics> WSPIKnownRetailInfoPropertiesStatics_inst() {
    ComPtr<ABI::Windows::System::Profile::IKnownRetailInfoPropertiesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Profile.KnownRetailInfoProperties").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)retailAccessCode {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RetailAccessCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)manufacturerName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManufacturerName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)modelName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ModelName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)displayModelName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisplayModelName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)price {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Price(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)isFeatured {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsFeatured(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)formFactor {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FormFactor(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)screenSize {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScreenSize(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)weight {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Weight(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)displayDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisplayDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)batteryLifeDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BatteryLifeDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)processorDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ProcessorDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)memory {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Memory(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)storageDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StorageDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)graphicsDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GraphicsDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)frontCameraDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FrontCameraDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rearCameraDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RearCameraDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hasNfc {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HasNfc(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hasSdSlot {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HasSdSlot(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hasOpticalDrive {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HasOpticalDrive(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)isOfficeInstalled {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsOfficeInstalled(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)windowsEdition {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPIKnownRetailInfoPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WindowsEdition(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSPSharedModeSettings

ComPtr<ABI::Windows::System::Profile::ISharedModeSettingsStatics> WSPISharedModeSettingsStatics_inst() {
    ComPtr<ABI::Windows::System::Profile::ISharedModeSettingsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Profile.SharedModeSettings").Get(), &inst));
    return inst;
}

+ (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WSPISharedModeSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

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
