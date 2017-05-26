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

// WindowsDevicesEnumerationPnp.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Enumeration.Pnp.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesEnumerationPnp.h"
#include "WindowsDevicesEnumerationPnp_priv.h"

@implementation WDEPPnpObjectUpdate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEPPnpObjectType)type {
    ABI::Windows::Devices::Enumeration::Pnp::PnpObjectType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDEPPnpObjectType)unmarshalledReturn;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WDEPPnpObjectCollection {
    RTArrayObj<ABI::Windows::Devices::Enumeration::Pnp::IPnpObject*,
               IVectorView<ABI::Windows::Devices::Enumeration::Pnp::PnpObject*>,
               WDEPPnpObject,
               ABI::Windows::Devices::Enumeration::Pnp::PnpObject*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             WDEPPnpObject,
                             ABI::Windows::Devices::Enumeration::Pnp::IPnpObject*,
                             ABI::Windows::Devices::Enumeration::Pnp::PnpObject*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::Pnp::PnpObject*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WDEPPnpObjectWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addAddedEvent:(void (^)(WDEPPnpObjectWatcher*, WDEPPnpObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Added(
        Make<ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObject>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Added(token));
}

- (EventRegistrationToken)addUpdatedEvent:(void (^)(WDEPPnpObjectWatcher*, WDEPPnpObjectUpdate*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Updated(
        Make<ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObjectUpdate>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Updated(token));
}

- (EventRegistrationToken)addRemovedEvent:(void (^)(WDEPPnpObjectWatcher*, WDEPPnpObjectUpdate*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Removed(
        Make<ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObjectUpdate>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Removed(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDEPPnpObjectWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnumerationCompleted(
        Make<ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WDEPPnpObjectWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Stopped(Make<ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_System_Object>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (WDEDeviceWatcherStatus)status {
    ABI::Windows::Devices::Enumeration::DeviceWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDEDeviceWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WDEPPnpObject

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObject> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectStatics> WDEPIPnpObjectStatics_inst() {
    ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Enumeration.Pnp.PnpObject").Get(), &inst));
    return inst;
}

+ (void)createFromIdAsync:(WDEPPnpObjectType)type
                       id:(NSString*)id
      requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties
                  success:(void (^)(WDEPPnpObject*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::Pnp::PnpObject*>> unmarshalledReturn;
    auto _comInst = WDEPIPnpObjectStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromIdAsync((ABI::Windows::Devices::Enumeration::Pnp::PnpObjectType)type,
                                    nsStrToHstr(id).Get(),
                                    static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                        ConvertToIterable<NSString, HSTRING>(requestedProperties).Get()),
                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::Pnp::PnpObject*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::Pnp::PnpObject*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObject> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDEPPnpObject>(result.Get()));
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

+ (void)findAllAsync:(WDEPPnpObjectType)type
    requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties
                success:(void (^)(WDEPPnpObjectCollection*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectCollection*>> unmarshalledReturn;
    auto _comInst = WDEPIPnpObjectStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindAllAsync((ABI::Windows::Devices::Enumeration::Pnp::PnpObjectType)type,
                               static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                   ConvertToIterable<NSString, HSTRING>(requestedProperties).Get()),
                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectCollection*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectCollection*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::Pnp::PnpObject*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEPPnpObjectCollection>(result.Get()));
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

+ (void)findAllAsyncAqsFilter:(WDEPPnpObjectType)type
          requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties
                    aqsFilter:(NSString*)aqsFilter
                      success:(void (^)(WDEPPnpObjectCollection*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectCollection*>> unmarshalledReturn;
    auto _comInst = WDEPIPnpObjectStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindAllAsyncAqsFilter((ABI::Windows::Devices::Enumeration::Pnp::PnpObjectType)type,
                                        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(requestedProperties).Get()),
                                        nsStrToHstr(aqsFilter).Get(),
                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectCollection*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectCollection*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Enumeration::Pnp::PnpObject*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDEPPnpObjectCollection>(result.Get()));
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

+ (WDEPPnpObjectWatcher*)createWatcher:(WDEPPnpObjectType)type
                   requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties {
    ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher> unmarshalledReturn;
    auto _comInst = WDEPIPnpObjectStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWatcher((ABI::Windows::Devices::Enumeration::Pnp::PnpObjectType)type,
                                static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                    ConvertToIterable<NSString, HSTRING>(requestedProperties).Get()),
                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEPPnpObjectWatcher>(unmarshalledReturn.Get());
}

+ (WDEPPnpObjectWatcher*)createWatcherAqsFilter:(WDEPPnpObjectType)type
                            requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties
                                      aqsFilter:(NSString*)aqsFilter {
    ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher> unmarshalledReturn;
    auto _comInst = WDEPIPnpObjectStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcherAqsFilter(
        (ABI::Windows::Devices::Enumeration::Pnp::PnpObjectType)type,
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(requestedProperties).Get()),
        nsStrToHstr(aqsFilter).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEPPnpObjectWatcher>(unmarshalledReturn.Get());
}

- (WDEPPnpObjectType)type {
    ABI::Windows::Devices::Enumeration::Pnp::PnpObjectType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDEPPnpObjectType)unmarshalledReturn;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (void)update:(WDEPPnpObjectUpdate*)updateInfo {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObject>(self);
    THROW_NS_IF_FAILED(_comInst->Update(_getRtInterface<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate>(updateInfo).Get()));
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
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
