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

// WindowsDevicesPerceptionProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Perception.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesPerceptionProvider.h"
#include "WindowsDevicesPerceptionProvider_priv.h"

@implementation WDPPIPerceptionFrameProviderManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDPPIPerceptionFrameProvider>*)getFrameProvider:(WDPPPerceptionFrameProviderInfo*)frameProviderInfo {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetFrameProvider(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(frameProviderInfo).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPIPerceptionFrameProvider>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPIPerceptionFrameProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPPerceptionFrameProviderInfo*)frameProviderInfo {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameProviderInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPPerceptionFrameProviderInfo>(unmarshalledReturn.Get());
}

- (BOOL)available {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Available(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)setProperty:(WDPPPerceptionPropertyChangeRequest*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetProperty(_getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest>(value).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPPerceptionFrameProviderInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Perception.Provider.PerceptionFrameProviderInfo").Get(), &out));
    return [_createRtProxy<WDPPPerceptionFrameProviderInfo>(out.Get()) retain];
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)deviceKind {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceKind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDeviceKind:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DeviceKind(nsStrToHstr(value).Get()));
}

- (NSString*)frameKind {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameKind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFrameKind:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_FrameKind(nsStrToHstr(value).Get()));
}

- (BOOL)hidden {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Hidden(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHidden:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Hidden((boolean)value));
}

@end

@implementation WDPPPerceptionPropertyChangeRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WDPPerceptionFrameSourcePropertyChangeStatus)status {
    ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDPPerceptionFrameSourcePropertyChangeStatus)unmarshalledReturn;
}

- (void)setStatus:(WDPPerceptionFrameSourcePropertyChangeStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus)value));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WDPPPerceptionFaceAuthenticationGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroupFactory>
WDPPIPerceptionFaceAuthenticationGroupFactory_inst() {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroupFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.Provider.PerceptionFaceAuthenticationGroup").Get(), &inst));
    return inst;
}

+ (WDPPPerceptionFaceAuthenticationGroup*)make:(id<NSFastEnumeration> /* NSString * */)ids
                                  startHandler:(WDPPPerceptionStartFaceAuthenticationHandler)startHandler
                                   stopHandler:(WDPPPerceptionStopFaceAuthenticationHandler)stopHandler {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup> unmarshalledReturn;
    auto _comInst = WDPPIPerceptionFaceAuthenticationGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(ids).Get()),
                                        Make<WDPPPerceptionStartFaceAuthenticationHandler_shim>(startHandler).Get(),
                                        Make<WDPPPerceptionStopFaceAuthenticationHandler_shim>(stopHandler).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDPPPerceptionFaceAuthenticationGroup>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* NSString * */)frameProviderIds {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameProviderIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WDPPPerceptionControlGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroupFactory> WDPPIPerceptionControlGroupFactory_inst() {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroupFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.Provider.PerceptionControlGroup").Get(), &inst));
    return inst;
}

+ (WDPPPerceptionControlGroup*)make:(id<NSFastEnumeration> /* NSString * */)ids {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroup> unmarshalledReturn;
    auto _comInst = WDPPIPerceptionControlGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(ids).Get()),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDPPPerceptionControlGroup>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* NSString * */)frameProviderIds {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameProviderIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WDPPPerceptionCorrelationGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroupFactory>
WDPPIPerceptionCorrelationGroupFactory_inst() {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroupFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.Provider.PerceptionCorrelationGroup").Get(), &inst));
    return inst;
}

+ (WDPPPerceptionCorrelationGroup*)make:(id<NSFastEnumeration> /* WDPPPerceptionCorrelation* */)relativeLocations {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup> unmarshalledReturn;
    auto _comInst = WDPPIPerceptionCorrelationGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*,
            ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation*>>::type>*>(
            ConvertToIterable<
                WDPPPerceptionCorrelation,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*,
                                                                  ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation*>>(
                relativeLocations)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDPPPerceptionCorrelationGroup>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* WDPPPerceptionCorrelation* */)relativeLocations {
    ComPtr<IVectorView<ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPPerceptionCorrelation_create(unmarshalledReturn.Get());
}

@end

@implementation WDPPPerceptionFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)relativeTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setRelativeTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelativeTime(*[value internalStruct]));
}

- (WFCValueSet*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (RTObject<WFIMemoryBuffer>*)frameData {
    ComPtr<ABI::Windows::Foundation::IMemoryBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIMemoryBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDPPPerceptionCorrelation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationFactory> WDPPIPerceptionCorrelationFactory_inst() {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.Provider.PerceptionCorrelation").Get(), &inst));
    return inst;
}

+ (WDPPPerceptionCorrelation*)make:(NSString*)targetId position:(WFNVector3*)position orientation:(WFNQuaternion*)orientation {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation> unmarshalledReturn;
    auto _comInst = WDPPIPerceptionCorrelationFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(targetId).Get(),
                                        *[position internalStruct],
                                        *[orientation internalStruct],
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDPPPerceptionCorrelation>(unmarshalledReturn.Get()) retain];
}

- (NSString*)targetId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFNVector3*)position {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (WFNQuaternion*)orientation {
    ABI::Windows::Foundation::Numerics::Quaternion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return WFNQuaternion_create(unmarshalledReturn);
}

@end

@implementation WDPPPerceptionVideoFrameAllocator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocatorFactory>
WDPPIPerceptionVideoFrameAllocatorFactory_inst() {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocatorFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.Provider.PerceptionVideoFrameAllocator").Get(), &inst));
    return inst;
}

+ (WDPPPerceptionVideoFrameAllocator*)make:(unsigned int)maxOutstandingFrameCountForWrite
                                    format:(WGIBitmapPixelFormat)format
                                resolution:(WFSize*)resolution
                                     alpha:(WGIBitmapAlphaMode)alpha {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator> unmarshalledReturn;
    auto _comInst = WDPPIPerceptionVideoFrameAllocatorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(maxOutstandingFrameCountForWrite,
                                        (ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format,
                                        *[resolution internalStruct],
                                        (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alpha,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDPPPerceptionVideoFrameAllocator>(unmarshalledReturn.Get()) retain];
}

- (WDPPPerceptionFrame*)allocateFrame __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator>(self);
    THROW_NS_IF_FAILED(_comInst->AllocateFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPPerceptionFrame>(unmarshalledReturn.Get());
}

- (WDPPPerceptionFrame*)copyFromVideoFrame:(WMVideoFrame*)frame __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator>(self);
    THROW_NS_IF_FAILED(
        _comInst->CopyFromVideoFrame(_getRtInterface<ABI::Windows::Media::IVideoFrame>(frame).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPPerceptionFrame>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPPerceptionFrameProviderManagerService

ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManagerServiceStatics>
WDPPIPerceptionFrameProviderManagerServiceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManagerServiceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.Provider.PerceptionFrameProviderManagerService").Get(), &inst));
    return inst;
}

+ (void)registerFrameProviderInfo:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                frameProviderInfo:(WDPPPerceptionFrameProviderInfo*)frameProviderInfo {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterFrameProviderInfo(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(manager).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(frameProviderInfo).Get()));
}

+ (void)unregisterFrameProviderInfo:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                  frameProviderInfo:(WDPPPerceptionFrameProviderInfo*)frameProviderInfo {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnregisterFrameProviderInfo(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(manager).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>(frameProviderInfo).Get()));
}

+ (void)registerFaceAuthenticationGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                faceAuthenticationGroup:(WDPPPerceptionFaceAuthenticationGroup*)faceAuthenticationGroup {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterFaceAuthenticationGroup(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(manager).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup>(faceAuthenticationGroup).Get()));
}

+ (void)unregisterFaceAuthenticationGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                  faceAuthenticationGroup:(WDPPPerceptionFaceAuthenticationGroup*)faceAuthenticationGroup {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnregisterFaceAuthenticationGroup(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(manager).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup>(faceAuthenticationGroup).Get()));
}

+ (void)registerControlGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                controlGroup:(WDPPPerceptionControlGroup*)controlGroup {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterControlGroup(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(manager).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroup>(controlGroup).Get()));
}

+ (void)unregisterControlGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                  controlGroup:(WDPPPerceptionControlGroup*)controlGroup {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnregisterControlGroup(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(manager).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroup>(controlGroup).Get()));
}

+ (void)registerCorrelationGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                correlationGroup:(WDPPPerceptionCorrelationGroup*)correlationGroup {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterCorrelationGroup(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(manager).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup>(correlationGroup).Get()));
}

+ (void)unregisterCorrelationGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                  correlationGroup:(WDPPPerceptionCorrelationGroup*)correlationGroup {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnregisterCorrelationGroup(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>(manager).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup>(correlationGroup).Get()));
}

+ (void)updateAvailabilityForProvider:(RTObject<WDPPIPerceptionFrameProvider>*)provider available:(BOOL)available {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UpdateAvailabilityForProvider(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider>(provider).Get(), (boolean)available));
}

+ (void)publishFrameForProvider:(RTObject<WDPPIPerceptionFrameProvider>*)provider frame:(WDPPPerceptionFrame*)frame {
    auto _comInst = WDPPIPerceptionFrameProviderManagerServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->PublishFrameForProvider(
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider>(provider).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::Provider::IPerceptionFrame>(frame).Get()));
}

@end

@implementation WDPPKnownPerceptionFrameKind

ComPtr<ABI::Windows::Devices::Perception::Provider::IKnownPerceptionFrameKindStatics> WDPPIKnownPerceptionFrameKindStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::Provider::IKnownPerceptionFrameKindStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.Provider.KnownPerceptionFrameKind").Get(), &inst));
    return inst;
}

+ (NSString*)color {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPPIKnownPerceptionFrameKindStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)depth {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPPIKnownPerceptionFrameKindStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Depth(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)infrared {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPPIKnownPerceptionFrameKindStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Infrared(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WDPPPerceptionCorrelation_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*>,
                                RTIterableObj<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation*,
                                              IIterable<ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*>,
                                              WDPPPerceptionCorrelation,
                                              ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*,
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

id RTProxiedNSArray_WDPPPerceptionCorrelation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*>,
                                         RTArrayObj<ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation*,
                                                    IVectorView<ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*>,
                                                    WDPPPerceptionCorrelation,
                                                    ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
