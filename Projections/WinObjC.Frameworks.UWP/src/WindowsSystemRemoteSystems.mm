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

// WindowsSystemRemoteSystems.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.RemoteSystems.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemRemoteSystems.h"
#include "WindowsSystemRemoteSystems_priv.h"

@implementation WSRIRemoteSystemFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WSRRemoteSystem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemStatics> WSRIRemoteSystemStatics_inst() {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.RemoteSystems.RemoteSystem").Get(), &inst));
    return inst;
}

+ (void)findByHostNameAsync:(WNHostName*)hostName success:(void (^)(WSRRemoteSystem*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteSystems::RemoteSystem*>> unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindByHostNameAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(hostName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::RemoteSystems::RemoteSystem*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteSystems::RemoteSystem*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSRRemoteSystem>(result.Get()));
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

+ (WSRRemoteSystemWatcher*)createWatcher {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher> unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSRRemoteSystemWatcher>(unmarshalledReturn.Get());
}

+ (WSRRemoteSystemWatcher*)createWatcherWithFilters:(id<NSFastEnumeration> /* RTObject<WSRIRemoteSystemFilter>* */)filters {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher> unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcherWithFilters(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::System::RemoteSystems::IRemoteSystemFilter*,
                                                              ABI::Windows::System::RemoteSystems::IRemoteSystemFilter*>>::type>*>(
            ConvertToIterable<RTObject<WSRIRemoteSystemFilter>,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::System::RemoteSystems::IRemoteSystemFilter*,
                                                                                ABI::Windows::System::RemoteSystems::IRemoteSystemFilter*>>(
                filters)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSRRemoteSystemWatcher>(unmarshalledReturn.Get());
}

+ (void)requestAccessAsyncWithSuccess:(void (^)(WSRRemoteSystemAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteSystems::RemoteSystemAccessStatus>> unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::RemoteSystems::RemoteSystemAccessStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteSystems::RemoteSystemAccessStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::RemoteSystems::RemoteSystemAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSRRemoteSystemAccessStatus)result);
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

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)kind {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSRRemoteSystemStatus)status {
    ABI::Windows::System::RemoteSystems::RemoteSystemStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSRRemoteSystemStatus)unmarshalledReturn;
}

- (BOOL)isAvailableByProximity {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAvailableByProximity(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSRRemoteSystemWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (EventRegistrationToken)addRemoteSystemAddedEvent:(void (^)(WSRRemoteSystemWatcher*, WSRRemoteSystemAddedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_RemoteSystemAdded(
        Make<ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemAddedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemoteSystemAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RemoteSystemAdded(token));
}

- (EventRegistrationToken)addRemoteSystemUpdatedEvent:(void (^)(WSRRemoteSystemWatcher*, WSRRemoteSystemUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_RemoteSystemUpdated(
        Make<ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemoteSystemUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RemoteSystemUpdated(token));
}

- (EventRegistrationToken)addRemoteSystemRemovedEvent:(void (^)(WSRRemoteSystemWatcher*, WSRRemoteSystemRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_RemoteSystemRemoved(
        Make<ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemoteSystemRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RemoteSystemRemoved(token));
}

@end

@implementation WSRRemoteSystemAddedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSRRemoteSystem*)remoteSystem {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSRRemoteSystem>(unmarshalledReturn.Get());
}

@end

@implementation WSRRemoteSystemUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSRRemoteSystem*)remoteSystem {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSRRemoteSystem>(unmarshalledReturn.Get());
}

@end

@implementation WSRRemoteSystemRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)remoteSystemId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteSystemId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSRRemoteSystemConnectionRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequestFactory> WSRIRemoteSystemConnectionRequestFactory_inst() {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequestFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.System.RemoteSystems.RemoteSystemConnectionRequest").Get(), &inst));
    return inst;
}

+ (WSRRemoteSystemConnectionRequest*)make:(WSRRemoteSystem*)remoteSystem {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest> unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemConnectionRequestFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::System::RemoteSystems::IRemoteSystem>(remoteSystem).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSRRemoteSystemConnectionRequest>(unmarshalledReturn.Get()) retain];
}

- (WSRRemoteSystem*)remoteSystem {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSRRemoteSystem>(unmarshalledReturn.Get());
}

@end

@implementation WSRRemoteSystemKinds

ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemKindStatics> WSRIRemoteSystemKindStatics_inst() {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemKindStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.RemoteSystems.RemoteSystemKinds").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)phone {
    HSTRING unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemKindStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Phone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hub {
    HSTRING unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemKindStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Hub(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)holographic {
    HSTRING unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemKindStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Holographic(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)desktop {
    HSTRING unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemKindStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Desktop(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)xbox {
    HSTRING unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemKindStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Xbox(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSRRemoteSystemKindFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemKindFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemKindFilterFactory> WSRIRemoteSystemKindFilterFactory_inst() {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemKindFilterFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.RemoteSystems.RemoteSystemKindFilter").Get(),
                                                       &inst));
    return inst;
}

+ (WSRRemoteSystemKindFilter*)make:(id<NSFastEnumeration> /* NSString * */)remoteSystemKinds {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemKindFilter> unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemKindFilterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(remoteSystemKinds).Get()),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSRRemoteSystemKindFilter>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* NSString * */)remoteSystemKinds {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemKindFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteSystemKinds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSRRemoteSystemDiscoveryTypeFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory>
WSRIRemoteSystemDiscoveryTypeFilterFactory_inst() {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.System.RemoteSystems.RemoteSystemDiscoveryTypeFilter").Get(), &inst));
    return inst;
}

+ (WSRRemoteSystemDiscoveryTypeFilter*)make:(WSRRemoteSystemDiscoveryType)discoveryType {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter> unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemDiscoveryTypeFilterFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::System::RemoteSystems::RemoteSystemDiscoveryType)discoveryType, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSRRemoteSystemDiscoveryTypeFilter>(unmarshalledReturn.Get()) retain];
}

- (WSRRemoteSystemDiscoveryType)remoteSystemDiscoveryType {
    ABI::Windows::System::RemoteSystems::RemoteSystemDiscoveryType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteSystemDiscoveryType(&unmarshalledReturn));
    return (WSRRemoteSystemDiscoveryType)unmarshalledReturn;
}

@end

@implementation WSRRemoteSystemStatusTypeFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory> WSRIRemoteSystemStatusTypeFilterFactory_inst() {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.System.RemoteSystems.RemoteSystemStatusTypeFilter").Get(), &inst));
    return inst;
}

+ (WSRRemoteSystemStatusTypeFilter*)make:(WSRRemoteSystemStatusType)remoteSystemStatusType {
    ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter> unmarshalledReturn;
    auto _comInst = WSRIRemoteSystemStatusTypeFilterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create((ABI::Windows::System::RemoteSystems::RemoteSystemStatusType)remoteSystemStatusType,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSRRemoteSystemStatusTypeFilter>(unmarshalledReturn.Get()) retain];
}

- (WSRRemoteSystemStatusType)remoteSystemStatusType {
    ABI::Windows::System::RemoteSystems::RemoteSystemStatusType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteSystemStatusType(&unmarshalledReturn));
    return (WSRRemoteSystemStatusType)unmarshalledReturn;
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_RTObject_WSRIRemoteSystemFilter_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::System::RemoteSystems::IRemoteSystemFilter*>,
                                                 RTIterableObj<ABI::Windows::System::RemoteSystems::IRemoteSystemFilter*,
                                                               IIterable<ABI::Windows::System::RemoteSystems::IRemoteSystemFilter*>,
                                                               RTObject<WSRIRemoteSystemFilter>,
                                                               ABI::Windows::System::RemoteSystems::IRemoteSystemFilter*,
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
