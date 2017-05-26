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

// WindowsNetworkingConnectivity.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.Connectivity.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworkingConnectivity.h"
#include "WindowsNetworkingConnectivity_priv.h"

@implementation WNCIPInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IIPInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNCNetworkAdapter*)networkAdapter {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkAdapter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IIPInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAdapter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCNetworkAdapter>(unmarshalledReturn.Get());
}

- (id /* uint8_t */)prefixLength {
    ComPtr<IReference<uint8_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IIPInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrefixLength(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint8_t, uint8_t>::convert(unmarshalledReturn.Get());
}

@end

@implementation WNCDataPlanUsage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IDataPlanUsage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)megabytesUsed {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataPlanUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MegabytesUsed(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)lastSyncTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataPlanUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastSyncTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WNCConnectionCost

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionCost> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNCNetworkCostType)networkCostType {
    ABI::Windows::Networking::Connectivity::NetworkCostType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionCost>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkCostType(&unmarshalledReturn));
    return (WNCNetworkCostType)unmarshalledReturn;
}

- (BOOL)roaming {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionCost>(self);
    THROW_NS_IF_FAILED(_comInst->get_Roaming(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)overDataLimit {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionCost>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverDataLimit(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)approachingDataLimit {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionCost>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApproachingDataLimit(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)backgroundDataUsageRestricted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionCost2>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundDataUsageRestricted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNCDataPlanStatus

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IDataPlanStatus> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNCDataPlanUsage*)dataPlanUsage {
    ComPtr<ABI::Windows::Networking::Connectivity::IDataPlanUsage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataPlanStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataPlanUsage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCDataPlanUsage>(unmarshalledReturn.Get());
}

- (id /* unsigned int */)dataLimitInMegabytes {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataPlanStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataLimitInMegabytes(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)inboundBitsPerSecond {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataPlanStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_InboundBitsPerSecond(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)outboundBitsPerSecond {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataPlanStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundBitsPerSecond(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)nextBillingCycle {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataPlanStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextBillingCycle(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)maxTransferSizeInMegabytes {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataPlanStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxTransferSizeInMegabytes(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

@end

@implementation WNCNetworkAdapter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkAdapter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)outboundMaxBitsPerSecond {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundMaxBitsPerSecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)inboundMaxBitsPerSecond {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->get_InboundMaxBitsPerSecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)ianaInterfaceType {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IanaInterfaceType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WNCNetworkItem*)networkItem {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCNetworkItem>(unmarshalledReturn.Get());
}

- (WFGUID*)networkAdapterId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAdapterId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)getConnectedProfileAsyncWithSuccess:(void (^)(WNCConnectionProfile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Connectivity::ConnectionProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkAdapter>(self);
    THROW_NS_IF_FAILED(_comInst->GetConnectedProfileAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Connectivity::ConnectionProfile*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Connectivity::ConnectionProfile*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionProfile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNCConnectionProfile>(result.Get()));
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

@implementation WNCDataUsage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IDataUsage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)bytesSent {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesSent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)bytesReceived {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IDataUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesReceived(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WNCNetworkSecuritySettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkSecuritySettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNCNetworkAuthenticationType)networkAuthenticationType {
    ABI::Windows::Networking::Connectivity::NetworkAuthenticationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkSecuritySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAuthenticationType(&unmarshalledReturn));
    return (WNCNetworkAuthenticationType)unmarshalledReturn;
}

- (WNCNetworkEncryptionType)networkEncryptionType {
    ABI::Windows::Networking::Connectivity::NetworkEncryptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkSecuritySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkEncryptionType(&unmarshalledReturn));
    return (WNCNetworkEncryptionType)unmarshalledReturn;
}

@end

@implementation WNCWlanConnectionProfileDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IWlanConnectionProfileDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)getConnectedSsid {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IWlanConnectionProfileDetails>(self);
    THROW_NS_IF_FAILED(_comInst->GetConnectedSsid(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNCNetworkUsage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkUsage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)bytesSent {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesSent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)bytesReceived {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesReceived(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)connectionDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WNCConnectivityInterval

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectivityInterval> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectivityInterval>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)connectionDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectivityInterval>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WNCAttributedNetworkUsage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IAttributedNetworkUsage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)bytesSent {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IAttributedNetworkUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesSent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)bytesReceived {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IAttributedNetworkUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesReceived(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)attributionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IAttributedNetworkUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)attributionName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IAttributedNetworkUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributionName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIRandomAccessStreamReference>*)attributionThumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IAttributedNetworkUsage>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributionThumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

@end

@implementation WNCLanIdentifierData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::ILanIdentifierData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)type {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ILanIdentifierData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* uint8_t */)value {
    ComPtr<IVectorView<uint8_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ILanIdentifierData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt8_create(unmarshalledReturn.Get());
}

@end

@implementation WNCConnectionProfile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionProfile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)profileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProfileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNCNetworkConnectivityLevel)getNetworkConnectivityLevel {
    ABI::Windows::Networking::Connectivity::NetworkConnectivityLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->GetNetworkConnectivityLevel(&unmarshalledReturn));
    return (WNCNetworkConnectivityLevel)unmarshalledReturn;
}

- (NSArray* /* NSString * */)getNetworkNames {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->GetNetworkNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (WNCConnectionCost*)getConnectionCost {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionCost> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->GetConnectionCost(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCConnectionCost>(unmarshalledReturn.Get());
}

- (WNCDataPlanStatus*)getDataPlanStatus {
    ComPtr<ABI::Windows::Networking::Connectivity::IDataPlanStatus> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->GetDataPlanStatus(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCDataPlanStatus>(unmarshalledReturn.Get());
}

- (WNCNetworkAdapter*)networkAdapter {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkAdapter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAdapter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCNetworkAdapter>(unmarshalledReturn.Get());
}

- (WNCDataUsage*)getLocalUsage:(WFDateTime*)StartTime EndTime:(WFDateTime*)EndTime {
    ComPtr<ABI::Windows::Networking::Connectivity::IDataUsage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->GetLocalUsage(*[StartTime internalStruct], *[EndTime internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCDataUsage>(unmarshalledReturn.Get());
}

- (WNCDataUsage*)getLocalUsagePerRoamingStates:(WFDateTime*)StartTime EndTime:(WFDateTime*)EndTime States:(WNCRoamingStates)States {
    ComPtr<ABI::Windows::Networking::Connectivity::IDataUsage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->GetLocalUsagePerRoamingStates(*[StartTime internalStruct],
                                                               *[EndTime internalStruct],
                                                               (ABI::Windows::Networking::Connectivity::RoamingStates)States,
                                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCDataUsage>(unmarshalledReturn.Get());
}

- (WNCNetworkSecuritySettings*)networkSecuritySettings {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkSecuritySettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkSecuritySettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCNetworkSecuritySettings>(unmarshalledReturn.Get());
}

- (BOOL)isWwanConnectionProfile {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWwanConnectionProfile(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isWlanConnectionProfile {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWlanConnectionProfile(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WNCWwanConnectionProfileDetails*)wwanConnectionProfileDetails {
    ComPtr<ABI::Windows::Networking::Connectivity::IWwanConnectionProfileDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WwanConnectionProfileDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCWwanConnectionProfileDetails>(unmarshalledReturn.Get());
}

- (WNCWlanConnectionProfileDetails*)wlanConnectionProfileDetails {
    ComPtr<ABI::Windows::Networking::Connectivity::IWlanConnectionProfileDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WlanConnectionProfileDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCWlanConnectionProfileDetails>(unmarshalledReturn.Get());
}

- (id /* WFGUID* */)serviceProviderGuid {
    ComPtr<IReference<GUID>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceProviderGuid(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFGUID, GUID>::convert(unmarshalledReturn.Get());
}

- (id /* uint8_t */)getSignalBars {
    ComPtr<IReference<uint8_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->GetSignalBars(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint8_t, uint8_t>::convert(unmarshalledReturn.Get());
}

- (WNCDomainConnectivityLevel)getDomainConnectivityLevel {
    ABI::Windows::Networking::Connectivity::DomainConnectivityLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->GetDomainConnectivityLevel(&unmarshalledReturn));
    return (WNCDomainConnectivityLevel)unmarshalledReturn;
}

- (void)getNetworkUsageAsync:(WFDateTime*)startTime
                     endTime:(WFDateTime*)endTime
                 granularity:(WNCDataUsageGranularity)granularity
                      states:(WNCNetworkUsageStates*)states
                     success:(void (^)(NSArray* /* WNCNetworkUsage* */))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Connectivity::NetworkUsage*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->GetNetworkUsageAsync(*[startTime internalStruct],
                                                      *[endTime internalStruct],
                                                      (ABI::Windows::Networking::Connectivity::DataUsageGranularity)granularity,
                                                      *[states internalStruct],
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Networking::Connectivity::NetworkUsage*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Connectivity::NetworkUsage*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::Connectivity::NetworkUsage*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNCNetworkUsage_create(result.Get()));
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

- (void)getConnectivityIntervalsAsync:(WFDateTime*)startTime
                              endTime:(WFDateTime*)endTime
                               states:(WNCNetworkUsageStates*)states
                              success:(void (^)(NSArray* /* WNCConnectivityInterval* */))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Connectivity::ConnectivityInterval*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile2>(self);
    THROW_NS_IF_FAILED(_comInst->GetConnectivityIntervalsAsync(*[startTime internalStruct],
                                                               *[endTime internalStruct],
                                                               *[states internalStruct],
                                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Networking::Connectivity::ConnectivityInterval*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Connectivity::ConnectivityInterval*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::Connectivity::ConnectivityInterval*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNCConnectivityInterval_create(result.Get()));
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

- (void)getAttributedNetworkUsageAsync:(WFDateTime*)startTime
                               endTime:(WFDateTime*)endTime
                                states:(WNCNetworkUsageStates*)states
                               success:(void (^)(NSArray* /* WNCAttributedNetworkUsage* */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Connectivity::AttributedNetworkUsage*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile3>(self);
    THROW_NS_IF_FAILED(_comInst->GetAttributedNetworkUsageAsync(*[startTime internalStruct],
                                                                *[endTime internalStruct],
                                                                *[states internalStruct],
                                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Networking::Connectivity::AttributedNetworkUsage*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Connectivity::AttributedNetworkUsage*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::Connectivity::AttributedNetworkUsage*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNCAttributedNetworkUsage_create(result.Get()));
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

@implementation WNCLanIdentifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::ILanIdentifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNCLanIdentifierData*)infrastructureId {
    ComPtr<ABI::Windows::Networking::Connectivity::ILanIdentifierData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ILanIdentifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_InfrastructureId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCLanIdentifierData>(unmarshalledReturn.Get());
}

- (WNCLanIdentifierData*)portId {
    ComPtr<ABI::Windows::Networking::Connectivity::ILanIdentifierData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ILanIdentifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_PortId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCLanIdentifierData>(unmarshalledReturn.Get());
}

- (WFGUID*)networkAdapterId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ILanIdentifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAdapterId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WNCProxyConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IProxyConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WFUri* */)proxyUris {
    ComPtr<IVectorView<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IProxyConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyUris(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WFUri_create(unmarshalledReturn.Get());
}

- (BOOL)canConnectDirectly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IProxyConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanConnectDirectly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNCConnectionProfileFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Connectivity.ConnectionProfileFilter").Get(),
                                              &out));
    return [_createRtProxy<WNCConnectionProfileFilter>(out.Get()) retain];
}

- (void)setIsConnected:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsConnected((boolean)value));
}

- (BOOL)isConnected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsConnected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsWwanConnectionProfile:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsWwanConnectionProfile((boolean)value));
}

- (BOOL)isWwanConnectionProfile {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWwanConnectionProfile(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsWlanConnectionProfile:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsWlanConnectionProfile((boolean)value));
}

- (BOOL)isWlanConnectionProfile {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWlanConnectionProfile(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setNetworkCostType:(WNCNetworkCostType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_NetworkCostType((ABI::Windows::Networking::Connectivity::NetworkCostType)value));
}

- (WNCNetworkCostType)networkCostType {
    ABI::Windows::Networking::Connectivity::NetworkCostType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkCostType(&unmarshalledReturn));
    return (WNCNetworkCostType)unmarshalledReturn;
}

- (void)setServiceProviderGuid:(id /* WFGUID* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ServiceProviderGuid(BuildNullable<GUID>(value)));
}

- (id /* WFGUID* */)serviceProviderGuid {
    ComPtr<IReference<GUID>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceProviderGuid(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFGUID, GUID>::convert(unmarshalledReturn.Get());
}

- (void)setIsRoaming:(id /* BOOL */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRoaming(BuildNullable<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>(value)));
}

- (id /* BOOL */)isRoaming {
    ComPtr<IReference<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRoaming(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<BOOL, ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>::convert(unmarshalledReturn.Get());
}

- (void)setIsOverDataLimit:(id /* BOOL */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_IsOverDataLimit(BuildNullable<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>(value)));
}

- (id /* BOOL */)isOverDataLimit {
    ComPtr<IReference<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOverDataLimit(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<BOOL, ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>::convert(unmarshalledReturn.Get());
}

- (void)setIsBackgroundDataUsageRestricted:(id /* BOOL */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsBackgroundDataUsageRestricted(
        BuildNullable<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>(value)));
}

- (id /* BOOL */)isBackgroundDataUsageRestricted {
    ComPtr<IReference<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBackgroundDataUsageRestricted(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<BOOL, ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>::convert(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WNCNetworkItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)networkId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WNCNetworkTypes)getNetworkTypes {
    ABI::Windows::Networking::Connectivity::NetworkTypes unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkItem>(self);
    THROW_NS_IF_FAILED(_comInst->GetNetworkTypes(&unmarshalledReturn));
    return (WNCNetworkTypes)unmarshalledReturn;
}

@end

@implementation WNCRoutePolicy

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IRoutePolicy> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::Connectivity::IRoutePolicyFactory> WNCIRoutePolicyFactory_inst() {
    ComPtr<ABI::Windows::Networking::Connectivity::IRoutePolicyFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Connectivity.RoutePolicy").Get(),
                                                       &inst));
    return inst;
}

+ (WNCRoutePolicy*)makeRoutePolicy:(WNCConnectionProfile*)connectionProfile hostName:(WNHostName*)hostName type:(WNDomainNameType)type {
    ComPtr<ABI::Windows::Networking::Connectivity::IRoutePolicy> unmarshalledReturn;
    auto _comInst = WNCIRoutePolicyFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateRoutePolicy(_getRtInterface<ABI::Windows::Networking::Connectivity::IConnectionProfile>(connectionProfile).Get(),
                                    _getRtInterface<ABI::Windows::Networking::IHostName>(hostName).Get(),
                                    (ABI::Windows::Networking::DomainNameType)type,
                                    unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNCRoutePolicy>(unmarshalledReturn.Get()) retain];
}

- (WNCConnectionProfile*)connectionProfile {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IRoutePolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCConnectionProfile>(unmarshalledReturn.Get());
}

- (WNHostName*)hostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IRoutePolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_HostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (WNDomainNameType)hostNameType {
    ABI::Windows::Networking::DomainNameType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IRoutePolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_HostNameType(&unmarshalledReturn));
    return (WNDomainNameType)unmarshalledReturn;
}

@end

@implementation WNCCellularApnContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::ICellularApnContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.Connectivity.CellularApnContext").Get(), &out));
    return [_createRtProxy<WNCCellularApnContext>(out.Get()) retain];
}

- (NSString*)providerId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setProviderId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProviderId(nsStrToHstr(value).Get()));
}

- (NSString*)accessPointName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessPointName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAccessPointName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_AccessPointName(nsStrToHstr(value).Get()));
}

- (NSString*)userName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUserName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_UserName(nsStrToHstr(value).Get()));
}

- (NSString*)password {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_Password(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPassword:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_Password(nsStrToHstr(value).Get()));
}

- (BOOL)isCompressionEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCompressionEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsCompressionEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsCompressionEnabled((boolean)value));
}

- (WNCCellularApnAuthenticationType)authenticationType {
    ABI::Windows::Networking::Connectivity::CellularApnAuthenticationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationType(&unmarshalledReturn));
    return (WNCCellularApnAuthenticationType)unmarshalledReturn;
}

- (void)setAuthenticationType:(WNCCellularApnAuthenticationType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_AuthenticationType((ABI::Windows::Networking::Connectivity::CellularApnAuthenticationType)value));
}

@end

@implementation WNCConnectionSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNCConnectionProfile*)connectionProfile {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IConnectionSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCConnectionProfile>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WNCNetworkInformation

ComPtr<ABI::Windows::Networking::Connectivity::INetworkInformationStatics2> WNCINetworkInformationStatics2_inst() {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkInformationStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Connectivity.NetworkInformation").Get(),
                                                       &inst));
    return inst;
}

+ (void)findConnectionProfilesAsync:(WNCConnectionProfileFilter*)pProfileFilter
                            success:(void (^)(NSArray* /* WNCConnectionProfile* */))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Connectivity::ConnectionProfile*>*>>
        unmarshalledReturn;
    auto _comInst = WNCINetworkInformationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FindConnectionProfilesAsync(
        _getRtInterface<ABI::Windows::Networking::Connectivity::IConnectionProfileFilter>(pProfileFilter).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Networking::Connectivity::ConnectionProfile*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::Connectivity::ConnectionProfile*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::Connectivity::ConnectionProfile*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNCConnectionProfile_create(result.Get()));
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

ComPtr<ABI::Windows::Networking::Connectivity::INetworkInformationStatics> WNCINetworkInformationStatics_inst() {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkInformationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Connectivity.NetworkInformation").Get(),
                                                       &inst));
    return inst;
}

+ (NSArray* /* WNCConnectionProfile* */)getConnectionProfiles {
    ComPtr<IVectorView<ABI::Windows::Networking::Connectivity::ConnectionProfile*>> unmarshalledReturn;
    auto _comInst = WNCINetworkInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetConnectionProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNCConnectionProfile_create(unmarshalledReturn.Get());
}

+ (WNCConnectionProfile*)getInternetConnectionProfile {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionProfile> unmarshalledReturn;
    auto _comInst = WNCINetworkInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetInternetConnectionProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCConnectionProfile>(unmarshalledReturn.Get());
}

+ (NSArray* /* WNCLanIdentifier* */)getLanIdentifiers {
    ComPtr<IVectorView<ABI::Windows::Networking::Connectivity::LanIdentifier*>> unmarshalledReturn;
    auto _comInst = WNCINetworkInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetLanIdentifiers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNCLanIdentifier_create(unmarshalledReturn.Get());
}

+ (NSArray* /* WNHostName* */)getHostNames {
    ComPtr<IVectorView<ABI::Windows::Networking::HostName*>> unmarshalledReturn;
    auto _comInst = WNCINetworkInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetHostNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNHostName_create(unmarshalledReturn.Get());
}

+ (void)getProxyConfigurationAsync:(WFUri*)uri success:(void (^)(WNCProxyConfiguration*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Connectivity::ProxyConfiguration*>> unmarshalledReturn;
    auto _comInst = WNCINetworkInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetProxyConfigurationAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Connectivity::ProxyConfiguration*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Connectivity::ProxyConfiguration*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::Connectivity::IProxyConfiguration> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNCProxyConfiguration>(result.Get()));
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

+ (NSArray* /* WNEndpointPair* */)getSortedEndpointPairs:(id<NSFastEnumeration> /* WNEndpointPair* */)destinationList
                                             sortOptions:(WNHostNameSortOptions)sortOptions {
    ComPtr<IVectorView<ABI::Windows::Networking::EndpointPair*>> unmarshalledReturn;
    auto _comInst = WNCINetworkInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSortedEndpointPairs(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::EndpointPair*,
                                                              ABI::Windows::Networking::IEndpointPair*>>::type>*>(
            ConvertToIterable<WNEndpointPair,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::EndpointPair*,
                                                                                ABI::Windows::Networking::IEndpointPair*>>(destinationList)
                .Get()),
        (ABI::Windows::Networking::HostNameSortOptions)sortOptions,
        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNEndpointPair_create(unmarshalledReturn.Get());
}

+ (EventRegistrationToken)addNetworkStatusChangedEvent:(WNCNetworkStatusChangedEventHandler)networkStatusHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WNCINetworkInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_NetworkStatusChanged(Make<WNCNetworkStatusChangedEventHandler_shim>(networkStatusHandler).Get(),
                                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeNetworkStatusChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = WNCINetworkInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_NetworkStatusChanged(eventCookie));
}

@end

@implementation WNCConnectivityManager

ComPtr<ABI::Windows::Networking::Connectivity::IConnectivityManagerStatics> WNCIConnectivityManagerStatics_inst() {
    ComPtr<ABI::Windows::Networking::Connectivity::IConnectivityManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.Connectivity.ConnectivityManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)acquireConnectionAsync:(WNCCellularApnContext*)cellularApnContext
                       success:(void (^)(WNCConnectionSession*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Connectivity::ConnectionSession*>> unmarshalledReturn;
    auto _comInst = WNCIConnectivityManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AcquireConnectionAsync(
        _getRtInterface<ABI::Windows::Networking::Connectivity::ICellularApnContext>(cellularApnContext).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::Connectivity::ConnectionSession*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::Connectivity::ConnectionSession*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::Connectivity::IConnectionSession> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNCConnectionSession>(result.Get()));
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

+ (void)addHttpRoutePolicy:(WNCRoutePolicy*)routePolicy {
    auto _comInst = WNCIConnectivityManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AddHttpRoutePolicy(_getRtInterface<ABI::Windows::Networking::Connectivity::IRoutePolicy>(routePolicy).Get()));
}

+ (void)removeHttpRoutePolicy:(WNCRoutePolicy*)routePolicy {
    auto _comInst = WNCIConnectivityManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->RemoveHttpRoutePolicy(_getRtInterface<ABI::Windows::Networking::Connectivity::IRoutePolicy>(routePolicy).Get()));
}

@end

@implementation WNCNetworkStateChangeEventDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)hasNewInternetConnectionProfile {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNewInternetConnectionProfile(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNewConnectionCost {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNewConnectionCost(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNewNetworkConnectivityLevel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNewNetworkConnectivityLevel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNewDomainConnectivityLevel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNewDomainConnectivityLevel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNewHostNameList {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNewHostNameList(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNewWwanRegistrationState {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNewWwanRegistrationState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNewTetheringOperationalState {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNewTetheringOperationalState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasNewTetheringClientCount {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasNewTetheringClientCount(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNCWwanConnectionProfileDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::Connectivity::IWwanConnectionProfileDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)homeProviderId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IWwanConnectionProfileDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HomeProviderId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)accessPointName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IWwanConnectionProfileDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessPointName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNCWwanNetworkRegistrationState)getNetworkRegistrationState {
    ABI::Windows::Networking::Connectivity::WwanNetworkRegistrationState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IWwanConnectionProfileDetails>(self);
    THROW_NS_IF_FAILED(_comInst->GetNetworkRegistrationState(&unmarshalledReturn));
    return (WNCWwanNetworkRegistrationState)unmarshalledReturn;
}

- (WNCWwanDataClass)getCurrentDataClass {
    ABI::Windows::Networking::Connectivity::WwanDataClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::Connectivity::IWwanConnectionProfileDetails>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentDataClass(&unmarshalledReturn));
    return (WNCWwanDataClass)unmarshalledReturn;
}

@end

@implementation WNCNetworkUsageStates {
    ABI::Windows::Networking::Connectivity::NetworkUsageStates structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Networking::Connectivity::NetworkUsageStates)s {
    WNCNetworkUsageStates* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Networking::Connectivity::NetworkUsageStates*)internalStruct {
    return &structVal;
}
- (WNCTriStates)roaming {
    return (WNCTriStates)structVal.Roaming;
}
- (void)setRoaming:(WNCTriStates)val {
    structVal.Roaming = (ABI::Windows::Networking::Connectivity::TriStates)val;
}
- (WNCTriStates)shared {
    return (WNCTriStates)structVal.Shared;
}
- (void)setShared:(WNCTriStates)val {
    structVal.Shared = (ABI::Windows::Networking::Connectivity::TriStates)val;
}
@end
id RTProxiedIterableNSArray_WNEndpointPair_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Networking::EndpointPair*>,
                                                 RTIterableObj<ABI::Windows::Networking::IEndpointPair*,
                                                               IIterable<ABI::Windows::Networking::EndpointPair*>,
                                                               WNEndpointPair,
                                                               ABI::Windows::Networking::EndpointPair*,
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

id RTProxiedNSArray_UInt8_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<uint8_t>,
                                         RTArrayObj<uint8_t, IVectorView<uint8_t>, uint8_t, uint8_t, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WFUri_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Foundation::Uri*>,
                                                                             RTArrayObj<ABI::Windows::Foundation::IUriRuntimeClass*,
                                                                                        IVectorView<ABI::Windows::Foundation::Uri*>,
                                                                                        WFUri,
                                                                                        ABI::Windows::Foundation::Uri*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNCAttributedNetworkUsage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Connectivity::AttributedNetworkUsage*>,
                                         RTArrayObj<ABI::Windows::Networking::Connectivity::IAttributedNetworkUsage*,
                                                    IVectorView<ABI::Windows::Networking::Connectivity::AttributedNetworkUsage*>,
                                                    WNCAttributedNetworkUsage,
                                                    ABI::Windows::Networking::Connectivity::AttributedNetworkUsage*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
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

id RTProxiedNSArray_WNCConnectivityInterval_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Connectivity::ConnectivityInterval*>,
                                         RTArrayObj<ABI::Windows::Networking::Connectivity::IConnectivityInterval*,
                                                    IVectorView<ABI::Windows::Networking::Connectivity::ConnectivityInterval*>,
                                                    WNCConnectivityInterval,
                                                    ABI::Windows::Networking::Connectivity::ConnectivityInterval*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNCLanIdentifier_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Connectivity::LanIdentifier*>,
                                         RTArrayObj<ABI::Windows::Networking::Connectivity::ILanIdentifier*,
                                                    IVectorView<ABI::Windows::Networking::Connectivity::LanIdentifier*>,
                                                    WNCLanIdentifier,
                                                    ABI::Windows::Networking::Connectivity::LanIdentifier*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNCNetworkUsage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::Connectivity::NetworkUsage*>,
                                         RTArrayObj<ABI::Windows::Networking::Connectivity::INetworkUsage*,
                                                    IVectorView<ABI::Windows::Networking::Connectivity::NetworkUsage*>,
                                                    WNCNetworkUsage,
                                                    ABI::Windows::Networking::Connectivity::NetworkUsage*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNEndpointPair_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::EndpointPair*>,
                                         RTArrayObj<ABI::Windows::Networking::IEndpointPair*,
                                                    IVectorView<ABI::Windows::Networking::EndpointPair*>,
                                                    WNEndpointPair,
                                                    ABI::Windows::Networking::EndpointPair*,
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
