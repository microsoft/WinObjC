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

// WindowsNetworkingNetworkOperators.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.NetworkOperators.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworkingNetworkOperators.h"
#include "WindowsNetworkingNetworkOperators_priv.h"

@implementation WNNMobileBroadbandAccount

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountStatics> WNNIMobileBroadbandAccountStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.MobileBroadbandAccount").Get(), &inst));
    return inst;
}

+ (NSArray* /* NSString * */)availableNetworkAccountIds {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WNNIMobileBroadbandAccountStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AvailableNetworkAccountIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

+ (WNNMobileBroadbandAccount*)createFromNetworkAccountId:(NSString*)networkAccountId {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount> unmarshalledReturn;
    auto _comInst = WNNIMobileBroadbandAccountStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromNetworkAccountId(nsStrToHstr(networkAccountId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandAccount>(unmarshalledReturn.Get());
}

- (NSString*)networkAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)serviceProviderGuid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceProviderGuid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)serviceProviderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceProviderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNNMobileBroadbandNetwork*)currentNetwork {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentNetwork(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandNetwork>(unmarshalledReturn.Get());
}

- (WNNMobileBroadbandDeviceInformation*)currentDeviceInformation {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentDeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandDeviceInformation>(unmarshalledReturn.Get());
}

- (NSArray* /* WNCConnectionProfile* */)getConnectionProfiles {
    ComPtr<IVectorView<ABI::Windows::Networking::Connectivity::ConnectionProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount2>(self);
    THROW_NS_IF_FAILED(_comInst->GetConnectionProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNCConnectionProfile_create(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandNetwork

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNCNetworkAdapter*)networkAdapter {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkAdapter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAdapter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCNetworkAdapter>(unmarshalledReturn.Get());
}

- (WNNNetworkRegistrationState)networkRegistrationState {
    ABI::Windows::Networking::NetworkOperators::NetworkRegistrationState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkRegistrationState(&unmarshalledReturn));
    return (WNNNetworkRegistrationState)unmarshalledReturn;
}

- (unsigned int)registrationNetworkError {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegistrationNetworkError(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)packetAttachNetworkError {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_PacketAttachNetworkError(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)activationNetworkError {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivationNetworkError(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)accessPointName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessPointName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNNDataClasses)registeredDataClass {
    ABI::Windows::Networking::NetworkOperators::DataClasses unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegisteredDataClass(&unmarshalledReturn));
    return (WNNDataClasses)unmarshalledReturn;
}

- (NSString*)registeredProviderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegisteredProviderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)registeredProviderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegisteredProviderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)showConnectionUI {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>(self);
    THROW_NS_IF_FAILED(_comInst->ShowConnectionUI());
}

- (void)getVoiceCallSupportAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork2>(self);
    THROW_NS_IF_FAILED(_comInst->GetVoiceCallSupportAsync(&unmarshalledReturn));

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

- (NSArray* /* WNNMobileBroadbandUiccApp* */)registrationUiccApps {
    ComPtr<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccApp*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegistrationUiccApps(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNNMobileBroadbandUiccApp_create(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandDeviceInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNNetworkDeviceStatus)networkDeviceStatus {
    ABI::Windows::Networking::NetworkOperators::NetworkDeviceStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkDeviceStatus(&unmarshalledReturn));
    return (WNNNetworkDeviceStatus)unmarshalledReturn;
}

- (NSString*)manufacturer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Manufacturer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)model {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Model(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)firmwareInformation {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirmwareInformation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WNNDataClasses)dataClasses {
    ABI::Windows::Networking::NetworkOperators::DataClasses unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataClasses(&unmarshalledReturn));
    return (WNNDataClasses)unmarshalledReturn;
}

- (NSString*)customDataClass {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomDataClass(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)mobileEquipmentId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MobileEquipmentId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* NSString * */)telephoneNumbers {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TelephoneNumbers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)subscriberId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubscriberId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNNMobileBroadbandDeviceType)deviceType {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceType(&unmarshalledReturn));
    return (WNNMobileBroadbandDeviceType)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNNMobileBroadbandRadioState)currentRadioState {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandRadioState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentRadioState(&unmarshalledReturn));
    return (WNNMobileBroadbandRadioState)unmarshalledReturn;
}

- (WNNMobileBroadbandPinManager*)pinManager {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandPinManager>(unmarshalledReturn.Get());
}

- (NSString*)revision {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Revision(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)serialNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SerialNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNNMobileBroadbandPinManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WNNMobileBroadbandPinType */)supportedPins {
    ComPtr<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedPins(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNNMobileBroadbandPinType_create(unmarshalledReturn.Get());
}

- (WNNMobileBroadbandPin*)getPin:(WNNMobileBroadbandPinType)pinType {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPin((ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinType)pinType, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandPin>(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandUiccApp

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)id {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WNNUiccAppKind)kind {
    ABI::Windows::Networking::NetworkOperators::UiccAppKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WNNUiccAppKind)unmarshalledReturn;
}

- (void)getRecordDetailsAsync:(id<NSFastEnumeration> /* unsigned int */)uiccFilePath
                      success:(void (^)(WNNMobileBroadbandUiccAppRecordDetailsResult*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecordDetailsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<unsigned int>::type>*>(
            ConvertToIterable<unsigned int, unsigned int>(uiccFilePath).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNNMobileBroadbandUiccAppRecordDetailsResult>(result.Get()));
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

- (void)readRecordAsync:(id<NSFastEnumeration> /* unsigned int */)uiccFilePath
            recordIndex:(int)recordIndex
                success:(void (^)(WNNMobileBroadbandUiccAppReadRecordResult*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReadRecordAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<unsigned int>::type>*>(
                                      ConvertToIterable<unsigned int, unsigned int>(uiccFilePath).Get()),
                                  recordIndex,
                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNMobileBroadbandUiccAppReadRecordResult>(result.Get()));
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

@implementation WNNNetworkOperatorTetheringAccessPointConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.NetworkOperatorTetheringAccessPointConfiguration").Get(), &out));
    return [_createRtProxy<WNNNetworkOperatorTetheringAccessPointConfiguration>(out.Get()) retain];
}

- (NSString*)ssid {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Ssid(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSsid:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Ssid(nsStrToHstr(value).Get()));
}

- (NSString*)passphrase {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Passphrase(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPassphrase:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Passphrase(nsStrToHstr(value).Get()));
}

@end

@implementation WNNNetworkOperatorTetheringOperationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNTetheringOperationStatus)status {
    ABI::Windows::Networking::NetworkOperators::TetheringOperationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNNTetheringOperationStatus)unmarshalledReturn;
}

- (NSString*)additionalErrorMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdditionalErrorMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNNNetworkOperatorTetheringManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3>
WNNINetworkOperatorTetheringManagerStatics3_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.NetworkOperatorTetheringManager").Get(), &inst));
    return inst;
}

+ (WNNNetworkOperatorTetheringManager*)createFromConnectionProfileWithTargetAdapter:(WNCConnectionProfile*)profile
                                                                            adapter:(WNCNetworkAdapter*)adapter {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager> unmarshalledReturn;
    auto _comInst = WNNINetworkOperatorTetheringManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromConnectionProfileWithTargetAdapter(
        _getRtInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(profile).Get(),
        _getRtInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(adapter).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNNetworkOperatorTetheringManager>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2>
WNNINetworkOperatorTetheringManagerStatics2_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.NetworkOperatorTetheringManager").Get(), &inst));
    return inst;
}

+ (WNNTetheringCapability)getTetheringCapabilityFromConnectionProfile:(WNCConnectionProfile*)profile {
    ABI::Windows::Networking::NetworkOperators::TetheringCapability unmarshalledReturn;
    auto _comInst = WNNINetworkOperatorTetheringManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetTetheringCapabilityFromConnectionProfile(
        _getRtInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(profile).Get(), &unmarshalledReturn));
    return (WNNTetheringCapability)unmarshalledReturn;
}

+ (WNNNetworkOperatorTetheringManager*)createFromConnectionProfile:(WNCConnectionProfile*)profile {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager> unmarshalledReturn;
    auto _comInst = WNNINetworkOperatorTetheringManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromConnectionProfile(_getRtInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(profile).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNNetworkOperatorTetheringManager>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics>
WNNINetworkOperatorTetheringManagerStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.NetworkOperatorTetheringManager").Get(), &inst));
    return inst;
}

+ (WNNTetheringCapability)getTetheringCapability:(NSString*)networkAccountId {
    ABI::Windows::Networking::NetworkOperators::TetheringCapability unmarshalledReturn;
    auto _comInst = WNNINetworkOperatorTetheringManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTetheringCapability(nsStrToHstr(networkAccountId).Get(), &unmarshalledReturn));
    return (WNNTetheringCapability)unmarshalledReturn;
}

+ (WNNNetworkOperatorTetheringManager*)createFromNetworkAccountId:(NSString*)networkAccountId {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager> unmarshalledReturn;
    auto _comInst = WNNINetworkOperatorTetheringManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromNetworkAccountId(nsStrToHstr(networkAccountId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNNetworkOperatorTetheringManager>(unmarshalledReturn.Get());
}

- (unsigned int)maxClientCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxClientCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)clientCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WNNTetheringOperationalState)tetheringOperationalState {
    ABI::Windows::Networking::NetworkOperators::TetheringOperationalState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_TetheringOperationalState(&unmarshalledReturn));
    return (WNNTetheringOperationalState)unmarshalledReturn;
}

- (WNNNetworkOperatorTetheringAccessPointConfiguration*)getCurrentAccessPointConfiguration {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentAccessPointConfiguration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNNetworkOperatorTetheringAccessPointConfiguration>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)configureAccessPointAsync:(WNNNetworkOperatorTetheringAccessPointConfiguration*)configuration {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager>(self);
    THROW_NS_IF_FAILED(_comInst->ConfigureAccessPointAsync(
        _getRtInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration>(configuration).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)startTetheringAsyncWithSuccess:(void (^)(WNNNetworkOperatorTetheringOperationResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager>(self);
    THROW_NS_IF_FAILED(_comInst->StartTetheringAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNNetworkOperatorTetheringOperationResult>(result.Get()));
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

- (void)stopTetheringAsyncWithSuccess:(void (^)(WNNNetworkOperatorTetheringOperationResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager>(self);
    THROW_NS_IF_FAILED(_comInst->StopTetheringAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNNetworkOperatorTetheringOperationResult>(result.Get()));
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

- (NSArray* /* WNNNetworkOperatorTetheringClient* */)getTetheringClients {
    ComPtr<IVectorView<ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringClient*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringClientManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetTetheringClients(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNNNetworkOperatorTetheringClient_create(unmarshalledReturn.Get());
}

@end

@implementation WNNNetworkOperatorTetheringClient

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringClient> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)macAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringClient>(self);
    THROW_NS_IF_FAILED(_comInst->get_MacAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WNHostName* */)hostNames {
    ComPtr<IVectorView<ABI::Windows::Networking::HostName*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringClient>(self);
    THROW_NS_IF_FAILED(_comInst->get_HostNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNHostName_create(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandAccountEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)networkAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNNMobileBroadbandAccountUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)networkAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)hasDeviceInformationChanged {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasDeviceInformationChanged(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNetworkChanged {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNetworkChanged(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNNMobileBroadbandAccountWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.MobileBroadbandAccountWatcher").Get(), &out));
    return [_createRtProxy<WNNMobileBroadbandAccountWatcher>(out.Get()) retain];
}

- (EventRegistrationToken)addAccountAddedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*, WNNMobileBroadbandAccountEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_AccountAdded(
        Make<
            ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAccountAddedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AccountAdded(cookie));
}

- (EventRegistrationToken)addAccountUpdatedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*,
                                                           WNNMobileBroadbandAccountUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_AccountUpdated(
        Make<
            ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAccountUpdatedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AccountUpdated(cookie));
}

- (EventRegistrationToken)addAccountRemovedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*, WNNMobileBroadbandAccountEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_AccountRemoved(
        Make<
            ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAccountRemovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AccountRemoved(cookie));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnumerationCompleted(
        Make<ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(cookie));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Stopped(
        Make<ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(cookie));
}

- (WNNMobileBroadbandAccountWatcherStatus)status {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNNMobileBroadbandAccountWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WNNMobileBroadbandModem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModemStatics> WNNIMobileBroadbandModemStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModemStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.MobileBroadbandModem").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WNNIMobileBroadbandModemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WNNMobileBroadbandModem*)fromId:(NSString*)deviceId {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem> unmarshalledReturn;
    auto _comInst = WNNIMobileBroadbandModemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromId(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandModem>(unmarshalledReturn.Get());
}

+ (WNNMobileBroadbandModem*)getDefault {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem> unmarshalledReturn;
    auto _comInst = WNNIMobileBroadbandModemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandModem>(unmarshalledReturn.Get());
}

- (WNNMobileBroadbandAccount*)currentAccount {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccount> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentAccount(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandAccount>(unmarshalledReturn.Get());
}

- (WNNMobileBroadbandDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandDeviceInformation>(unmarshalledReturn.Get());
}

- (unsigned int)maxDeviceServiceCommandSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxDeviceServiceCommandSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxDeviceServiceDataSizeInBytes {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxDeviceServiceDataSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* WNNMobileBroadbandDeviceServiceInformation* */)deviceServices {
    ComPtr<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceServices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNNMobileBroadbandDeviceServiceInformation_create(unmarshalledReturn.Get());
}

- (WNNMobileBroadbandDeviceService*)getDeviceService:(WFGUID*)deviceServiceId {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeviceService(deviceServiceId.guidValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandDeviceService>(unmarshalledReturn.Get());
}

- (BOOL)isResetSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsResetSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)resetAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->ResetAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getCurrentConfigurationAsyncWithSuccess:(void (^)(WNNMobileBroadbandModemConfiguration*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandModemConfiguration*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentConfigurationAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandModemConfiguration*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandModemConfiguration*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModemConfiguration> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNMobileBroadbandModemConfiguration>(result.Get()));
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

- (WNNMobileBroadbandNetwork*)currentNetwork {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModem>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentNetwork(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandNetwork>(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandUicc

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUicc> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUicc>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)getUiccAppsAsyncWithSuccess:(void (^)(WNNMobileBroadbandUiccAppsResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppsResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUicc>(self);
    THROW_NS_IF_FAILED(_comInst->GetUiccAppsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppsResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppsResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNMobileBroadbandUiccAppsResult>(result.Get()));
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

@implementation WNNMobileBroadbandModemConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModemConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNMobileBroadbandUicc*)uicc {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUicc> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModemConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uicc(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandUicc>(unmarshalledReturn.Get());
}

- (NSString*)homeProviderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModemConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_HomeProviderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)homeProviderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModemConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_HomeProviderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNNMobileBroadbandDeviceServiceInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)deviceServiceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (BOOL)isDataReadSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDataReadSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDataWriteSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDataWriteSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNNMobileBroadbandDeviceService

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)deviceServiceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSArray* /* unsigned int */)supportedCommands {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCommands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

- (WNNMobileBroadbandDeviceServiceDataSession*)openDataSession {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->OpenDataSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandDeviceServiceDataSession>(unmarshalledReturn.Get());
}

- (WNNMobileBroadbandDeviceServiceCommandSession*)openCommandSession {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService>(self);
    THROW_NS_IF_FAILED(_comInst->OpenCommandSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandDeviceServiceCommandSession>(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandPin

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNMobileBroadbandPinType)type {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WNNMobileBroadbandPinType)unmarshalledReturn;
}

- (WNNMobileBroadbandPinLockState)lockState {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinLockState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_LockState(&unmarshalledReturn));
    return (WNNMobileBroadbandPinLockState)unmarshalledReturn;
}

- (WNNMobileBroadbandPinFormat)format {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WNNMobileBroadbandPinFormat)unmarshalledReturn;
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)maxLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)minLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)attemptsRemaining {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttemptsRemaining(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)enableAsync:(NSString*)currentPin
            success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->EnableAsync(nsStrToHstr(currentPin).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNMobileBroadbandPinOperationResult>(result.Get()));
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

- (void)disableAsync:(NSString*)currentPin
             success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->DisableAsync(nsStrToHstr(currentPin).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNMobileBroadbandPinOperationResult>(result.Get()));
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

- (void)enterAsync:(NSString*)currentPin
           success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->EnterAsync(nsStrToHstr(currentPin).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNMobileBroadbandPinOperationResult>(result.Get()));
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

- (void)changeAsync:(NSString*)currentPin
             newPin:(NSString*)newPin
            success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->ChangeAsync(nsStrToHstr(currentPin).Get(), nsStrToHstr(newPin).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNMobileBroadbandPinOperationResult>(result.Get()));
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

- (void)unblockAsync:(NSString*)pinUnblockKey
              newPin:(NSString*)newPin
             success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPin>(self);
    THROW_NS_IF_FAILED(_comInst->UnblockAsync(nsStrToHstr(pinUnblockKey).Get(), nsStrToHstr(newPin).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNMobileBroadbandPinOperationResult>(result.Get()));
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

@implementation WNNMobileBroadbandPinOperationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isSuccessful {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSuccessful(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)attemptsRemaining {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttemptsRemaining(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WNNMobileBroadbandDeviceServiceDataSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)writeDataAsync:(RTObject<WSSIBuffer>*)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->WriteDataAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)closeSession {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession>(self);
    THROW_NS_IF_FAILED(_comInst->CloseSession());
}

- (EventRegistrationToken)addDataReceivedEvent:(void (^)(WNNMobileBroadbandDeviceServiceDataSession*,
                                                         WNNMobileBroadbandDeviceServiceDataReceivedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_DataReceived(
        Make<
            ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataSession_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataReceivedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDataReceivedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DataReceived(eventCookie));
}

@end

@implementation WNNMobileBroadbandDeviceServiceCommandSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)sendQueryCommandAsync:(unsigned int)commandId
                         data:(RTObject<WSSIBuffer>*)data
                      success:(void (^)(WNNMobileBroadbandDeviceServiceCommandResult*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession>(self);
    THROW_NS_IF_FAILED(_comInst->SendQueryCommandAsync(commandId,
                                                       _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNNMobileBroadbandDeviceServiceCommandResult>(result.Get()));
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

- (void)sendSetCommandAsync:(unsigned int)commandId
                       data:(RTObject<WSSIBuffer>*)data
                    success:(void (^)(WNNMobileBroadbandDeviceServiceCommandResult*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession>(self);
    THROW_NS_IF_FAILED(_comInst->SendSetCommandAsync(commandId,
                                                     _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNNMobileBroadbandDeviceServiceCommandResult>(result.Get()));
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

- (void)closeSession {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession>(self);
    THROW_NS_IF_FAILED(_comInst->CloseSession());
}

@end

@implementation WNNMobileBroadbandDeviceServiceDataReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)receivedData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReceivedData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandDeviceServiceCommandResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)statusCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_StatusCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)responseData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandUiccAppsResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNMobileBroadbandUiccAppOperationStatus)status {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNNMobileBroadbandUiccAppOperationStatus)unmarshalledReturn;
}

- (NSArray* /* WNNMobileBroadbandUiccApp* */)uiccApps {
    ComPtr<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccApp*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_UiccApps(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNNMobileBroadbandUiccApp_create(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandUiccAppRecordDetailsResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNMobileBroadbandUiccAppOperationStatus)status {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNNMobileBroadbandUiccAppOperationStatus)unmarshalledReturn;
}

- (WNNUiccAppRecordKind)kind {
    ABI::Windows::Networking::NetworkOperators::UiccAppRecordKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WNNUiccAppRecordKind)unmarshalledReturn;
}

- (int)recordCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecordCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)recordSize {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecordSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WNNUiccAccessCondition)readAccessCondition {
    ABI::Windows::Networking::NetworkOperators::UiccAccessCondition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadAccessCondition(&unmarshalledReturn));
    return (WNNUiccAccessCondition)unmarshalledReturn;
}

- (WNNUiccAccessCondition)writeAccessCondition {
    ABI::Windows::Networking::NetworkOperators::UiccAccessCondition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_WriteAccessCondition(&unmarshalledReturn));
    return (WNNUiccAccessCondition)unmarshalledReturn;
}

@end

@implementation WNNMobileBroadbandUiccAppReadRecordResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNMobileBroadbandUiccAppOperationStatus)status {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WNNMobileBroadbandUiccAppOperationStatus)unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandNetworkRegistrationStateChange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNNMobileBroadbandNetwork*)network {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetwork> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Network(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNMobileBroadbandNetwork>(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandNetworkRegistrationStateChangeTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WNNMobileBroadbandNetworkRegistrationStateChange* */)networkRegistrationStateChanges {
    ComPtr<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange*>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkRegistrationStateChanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNNMobileBroadbandNetworkRegistrationStateChange_create(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandRadioStateChange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNNMobileBroadbandRadioState)radioState {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandRadioState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_RadioState(&unmarshalledReturn));
    return (WNNMobileBroadbandRadioState)unmarshalledReturn;
}

@end

@implementation WNNMobileBroadbandRadioStateChangeTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WNNMobileBroadbandRadioStateChange* */)radioStateChanges {
    ComPtr<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandRadioStateChange*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_RadioStateChanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNNMobileBroadbandRadioStateChange_create(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandPinLockStateChange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNNMobileBroadbandPinType)pinType {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinType(&unmarshalledReturn));
    return (WNNMobileBroadbandPinType)unmarshalledReturn;
}

- (WNNMobileBroadbandPinLockState)pinLockState {
    ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinLockState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinLockState(&unmarshalledReturn));
    return (WNNMobileBroadbandPinLockState)unmarshalledReturn;
}

@end

@implementation WNNMobileBroadbandPinLockStateChangeTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WNNMobileBroadbandPinLockStateChange* */)pinLockStateChanges {
    ComPtr<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinLockStateChange*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinLockStateChanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNNMobileBroadbandPinLockStateChange_create(unmarshalledReturn.Get());
}

@end

@implementation WNNMobileBroadbandDeviceServiceTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)deviceServiceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceServiceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)receivedData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReceivedData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WNNKnownCSimFilePaths

ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownCSimFilePathsStatics> WNNIKnownCSimFilePathsStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownCSimFilePathsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.KnownCSimFilePaths").Get(), &inst));
    return inst;
}

+ (NSArray* /* unsigned int */)eFSpn {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownCSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EFSpn(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)gid1 {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownCSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gid1(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)gid2 {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownCSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gid2(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WNNKnownRuimFilePaths

ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownRuimFilePathsStatics> WNNIKnownRuimFilePathsStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownRuimFilePathsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.KnownRuimFilePaths").Get(), &inst));
    return inst;
}

+ (NSArray* /* unsigned int */)eFSpn {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownRuimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EFSpn(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)gid1 {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownRuimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gid1(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)gid2 {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownRuimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gid2(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WNNKnownSimFilePaths

ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownSimFilePathsStatics> WNNIKnownSimFilePathsStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownSimFilePathsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.KnownSimFilePaths").Get(), &inst));
    return inst;
}

+ (NSArray* /* unsigned int */)eFOns {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EFOns(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)eFSpn {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EFSpn(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)gid1 {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gid1(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)gid2 {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gid2(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WNNKnownUSimFilePaths

ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownUSimFilePathsStatics> WNNIKnownUSimFilePathsStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownUSimFilePathsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.KnownUSimFilePaths").Get(), &inst));
    return inst;
}

+ (NSArray* /* unsigned int */)eFSpn {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownUSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EFSpn(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)eFOpl {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownUSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EFOpl(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)eFPnn {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownUSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EFPnn(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)gid1 {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownUSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gid1(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

+ (NSArray* /* unsigned int */)gid2 {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = WNNIKnownUSimFilePathsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gid2(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WNNHotspotAuthenticationEventDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationEventDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)eventToken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_EventToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNNHotspotAuthenticationContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContextStatics> WNNIHotspotAuthenticationContextStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContextStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.HotspotAuthenticationContext").Get(), &inst));
    return inst;
}

+ (BOOL)tryGetAuthenticationContext:(NSString*)evenToken context:(WNNHotspotAuthenticationContext**)context {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext> contextOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WNNIHotspotAuthenticationContextStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryGetAuthenticationContext(nsStrToHstr(evenToken).Get(), contextOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *context = _createRtProxy<WNNHotspotAuthenticationContext>(contextOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* uint8_t */)wirelessNetworkId {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_WirelessNetworkId(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (WNCNetworkAdapter*)networkAdapter {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkAdapter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAdapter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCNetworkAdapter>(unmarshalledReturn.Get());
}

- (WFUri*)redirectMessageUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_RedirectMessageUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WDXDXmlDocument*)redirectMessageXml {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_RedirectMessageXml(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (WFUri*)authenticationUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)issueCredentials:(NSString*)userName
                        password:(NSString*)password
                 extraParameters:(NSString*)extraParameters
    markAsManualConnectOnFailure:(BOOL)markAsManualConnectOnFailure {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(_comInst->IssueCredentials(nsStrToHstr(userName).Get(),
                                                  nsStrToHstr(password).Get(),
                                                  nsStrToHstr(extraParameters).Get(),
                                                  (boolean)markAsManualConnectOnFailure));
}

- (void)abortAuthentication:(BOOL)markAsManual {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(_comInst->AbortAuthentication((boolean)markAsManual));
}

- (void)skipAuthentication {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(_comInst->SkipAuthentication());
}

- (void)triggerAttentionRequired:(NSString*)packageRelativeApplicationId applicationParameters:(NSString*)applicationParameters {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->TriggerAttentionRequired(nsStrToHstr(packageRelativeApplicationId).Get(), nsStrToHstr(applicationParameters).Get()));
}

- (void)issueCredentialsAsync:(NSString*)userName
                        password:(NSString*)password
                 extraParameters:(NSString*)extraParameters
    markAsManualConnectOnFailure:(BOOL)markAsManualConnectOnFailure
                         success:(void (^)(WNNHotspotCredentialsAuthenticationResult*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContext2>(self);
    THROW_NS_IF_FAILED(_comInst->IssueCredentialsAsync(nsStrToHstr(userName).Get(),
                                                       nsStrToHstr(password).Get(),
                                                       nsStrToHstr(extraParameters).Get(),
                                                       (boolean)markAsManualConnectOnFailure,
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNHotspotCredentialsAuthenticationResult>(result.Get()));
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

@implementation WNNHotspotCredentialsAuthenticationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)hasNetworkErrorOccurred {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNetworkErrorOccurred(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WNNHotspotAuthenticationResponseCode)responseCode {
    ABI::Windows::Networking::NetworkOperators::HotspotAuthenticationResponseCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCode(&unmarshalledReturn));
    return (WNNHotspotAuthenticationResponseCode)unmarshalledReturn;
}

- (WFUri*)logoffUrl {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogoffUrl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WDXDXmlDocument*)authenticationReplyXml {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationReplyXml(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

@end

@implementation WNNProvisionFromXmlDocumentResults

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisionFromXmlDocumentResults> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)allElementsProvisioned {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IProvisionFromXmlDocumentResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllElementsProvisioned(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)provisionResultsXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IProvisionFromXmlDocumentResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProvisionResultsXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNNProvisionedProfile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisionedProfile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)updateCost:(WNCNetworkCostType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IProvisionedProfile>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateCost((ABI::Windows::Networking::Connectivity::NetworkCostType)value));
}

- (void)updateUsage:(WNNProfileUsage*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IProvisionedProfile>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateUsage(*[value internalStruct]));
}

@end

@implementation WNNProvisioningAgent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisioningAgent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.NetworkOperators.ProvisioningAgent").Get(),
                                              &out));
    return [_createRtProxy<WNNProvisioningAgent>(out.Get()) retain];
}

ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisioningAgentStaticMethods> WNNIProvisioningAgentStaticMethods_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisioningAgentStaticMethods> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.ProvisioningAgent").Get(), &inst));
    return inst;
}

+ (WNNProvisioningAgent*)createFromNetworkAccountId:(NSString*)networkAccountId {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisioningAgent> unmarshalledReturn;
    auto _comInst = WNNIProvisioningAgentStaticMethods_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromNetworkAccountId(nsStrToHstr(networkAccountId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNProvisioningAgent>(unmarshalledReturn.Get());
}

- (void)provisionFromXmlDocumentAsync:(NSString*)provisioningXmlDocument
                              success:(void (^)(WNNProvisionFromXmlDocumentResults*))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::ProvisionFromXmlDocumentResults*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IProvisioningAgent>(self);
    THROW_NS_IF_FAILED(_comInst->ProvisionFromXmlDocumentAsync(nsStrToHstr(provisioningXmlDocument).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::NetworkOperators::ProvisionFromXmlDocumentResults*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::ProvisionFromXmlDocumentResults*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisionFromXmlDocumentResults> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNNProvisionFromXmlDocumentResults>(result.Get()));
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

- (WNNProvisionedProfile*)getProvisionedProfile:(WNNProfileMediaType)mediaType profileName:(NSString*)profileName {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisionedProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IProvisioningAgent>(self);
    THROW_NS_IF_FAILED(_comInst->GetProvisionedProfile((ABI::Windows::Networking::NetworkOperators::ProfileMediaType)mediaType,
                                                       nsStrToHstr(profileName).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNProvisionedProfile>(unmarshalledReturn.Get());
}

@end

@implementation WNNUssdMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdMessageFactory> WNNIUssdMessageFactory_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.NetworkOperators.UssdMessage").Get(),
                                                       &inst));
    return inst;
}

+ (WNNUssdMessage*)makeMessage:(NSString*)messageText {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdMessage> unmarshalledReturn;
    auto _comInst = WNNIUssdMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMessage(nsStrToHstr(messageText).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNNUssdMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)dataCodingScheme {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataCodingScheme(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDataCodingScheme:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataCodingScheme(value));
}

- (NSArray* /* uint8_t */)getPayload {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdMessage>(self);
    THROW_NS_IF_FAILED(_comInst->GetPayload(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (void)setPayload:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdMessage>(self);
    THROW_NS_IF_FAILED(_comInst->SetPayload(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (NSString*)payloadAsText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PayloadAsText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPayloadAsText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_PayloadAsText(nsStrToHstr(value).Get()));
}

@end

@implementation WNNUssdReply

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdReply> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNUssdResultCode)resultCode {
    ABI::Windows::Networking::NetworkOperators::UssdResultCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdReply>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResultCode(&unmarshalledReturn));
    return (WNNUssdResultCode)unmarshalledReturn;
}

- (WNNUssdMessage*)message {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdReply>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNUssdMessage>(unmarshalledReturn.Get());
}

@end

@implementation WNNUssdSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdSessionStatics> WNNIUssdSessionStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdSessionStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.NetworkOperators.UssdSession").Get(),
                                                       &inst));
    return inst;
}

+ (WNNUssdSession*)createFromNetworkAccountId:(NSString*)networkAccountId {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdSession> unmarshalledReturn;
    auto _comInst = WNNIUssdSessionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromNetworkAccountId(nsStrToHstr(networkAccountId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNUssdSession>(unmarshalledReturn.Get());
}

+ (WNNUssdSession*)createFromNetworkInterfaceId:(NSString*)networkInterfaceId {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdSession> unmarshalledReturn;
    auto _comInst = WNNIUssdSessionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromNetworkInterfaceId(nsStrToHstr(networkInterfaceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNNUssdSession>(unmarshalledReturn.Get());
}

- (void)sendMessageAndGetReplyAsync:(WNNUssdMessage*)message success:(void (^)(WNNUssdReply*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::UssdReply*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendMessageAndGetReplyAsync(_getRtInterface<ABI::Windows::Networking::NetworkOperators::IUssdMessage>(message).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::NetworkOperators::UssdReply*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::NetworkOperators::UssdReply*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdReply> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNNUssdReply>(result.Get()));
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::IUssdSession>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WNNNetworkOperatorNotificationEventDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNNNetworkOperatorEventMessageType)notificationType {
    ABI::Windows::Networking::NetworkOperators::NetworkOperatorEventMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_NotificationType(&unmarshalledReturn));
    return (WNNNetworkOperatorEventMessageType)unmarshalledReturn;
}

- (NSString*)networkAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (uint8_t)encodingType {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)ruleId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_RuleId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDSISmsMessage>*)smsMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmsMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSISmsMessage>(unmarshalledReturn.Get());
}

- (void)authorizeTethering:(BOOL)allow entitlementFailureReason:(NSString*)entitlementFailureReason {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck>(self);
    THROW_NS_IF_FAILED(_comInst->AuthorizeTethering((boolean)allow, nsStrToHstr(entitlementFailureReason).Get()));
}

@end

@implementation WNNFdnAccessManager

ComPtr<ABI::Windows::Networking::NetworkOperators::IFdnAccessManagerStatics> WNNIFdnAccessManagerStatics_inst() {
    ComPtr<ABI::Windows::Networking::NetworkOperators::IFdnAccessManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.NetworkOperators.FdnAccessManager").Get(), &inst));
    return inst;
}

+ (void)requestUnlockAsync:(NSString*)contactListId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WNNIFdnAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestUnlockAsync(nsStrToHstr(contactListId).Get(), &unmarshalledReturn));

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

@end

@implementation WNNProfileUsage {
    ABI::Windows::Networking::NetworkOperators::ProfileUsage structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Networking::NetworkOperators::ProfileUsage)s {
    WNNProfileUsage* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Networking::NetworkOperators::ProfileUsage*)internalStruct {
    return &structVal;
}
- (unsigned int)usageInMegabytes {
    return structVal.UsageInMegabytes;
}
- (void)setUsageInMegabytes:(unsigned int)val {
    structVal.UsageInMegabytes = val;
}
- (WFDateTime*)lastSyncTime {
    return WFDateTime_create(structVal.LastSyncTime);
}
- (void)setLastSyncTime:(WFDateTime*)val {
    structVal.LastSyncTime = *[val internalStruct];
}
@end
id RTProxiedIterableNSArray_UInt32_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<unsigned int>,
        RTIterableObj<unsigned int, IIterable<unsigned int>, unsigned int, unsigned int, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_UInt32_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<
        IVectorView<unsigned int>,
        RTArrayObj<unsigned int, IVectorView<unsigned int>, unsigned int, unsigned int, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNCConnectionProfile_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Connectivity::ConnectionProfile*>,
                                         RTArrayObj<ABI::Windows::Networking::Connectivity::IConnectionProfile*,
                                                    IVectorView<ABI::Windows::Networking::Connectivity::ConnectionProfile*>,
                                                    WNCConnectionProfile,
                                                    ABI::Windows::Networking::Connectivity::ConnectionProfile*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNHostName_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::HostName*>,
                                                                             RTArrayObj<ABI::Windows::Networking::IHostName*,
                                                                                        IVectorView<ABI::Windows::Networking::HostName*>,
                                                                                        WNHostName,
                                                                                        ABI::Windows::Networking::HostName*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNNMobileBroadbandDeviceServiceInformation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation*>,
                        RTArrayObj<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation*,
                                   IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation*>,
                                   WNNMobileBroadbandDeviceServiceInformation,
                                   ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNNMobileBroadbandNetworkRegistrationStateChange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange*>,
                        RTArrayObj<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange*,
                                   IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange*>,
                                   WNNMobileBroadbandNetworkRegistrationStateChange,
                                   ABI::Windows::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNNMobileBroadbandPinLockStateChange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinLockStateChange*>,
                        RTArrayObj<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange*,
                                   IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinLockStateChange*>,
                                   WNNMobileBroadbandPinLockStateChange,
                                   ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinLockStateChange*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNNMobileBroadbandPinType_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinType>,
                                         RTArrayObj<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinType,
                                                    IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinType>,
                                                    WNNMobileBroadbandPinType,
                                                    ABI::Windows::Networking::NetworkOperators::MobileBroadbandPinType,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNNMobileBroadbandRadioStateChange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandRadioStateChange*>,
                        RTArrayObj<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChange*,
                                   IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandRadioStateChange*>,
                                   WNNMobileBroadbandRadioStateChange,
                                   ABI::Windows::Networking::NetworkOperators::MobileBroadbandRadioStateChange*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNNMobileBroadbandUiccApp_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccApp*>,
                                         RTArrayObj<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp*,
                                                    IVectorView<ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccApp*>,
                                                    WNNMobileBroadbandUiccApp,
                                                    ABI::Windows::Networking::NetworkOperators::MobileBroadbandUiccApp*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNNNetworkOperatorTetheringClient_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringClient*>,
                        RTArrayObj<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringClient*,
                                   IVectorView<ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringClient*>,
                                   WNNNetworkOperatorTetheringClient,
                                   ABI::Windows::Networking::NetworkOperators::NetworkOperatorTetheringClient*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
