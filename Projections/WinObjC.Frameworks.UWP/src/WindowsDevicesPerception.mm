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

// WindowsDevicesPerception.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Perception.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesPerception.h"
#include "WindowsDevicesPerception_priv.h"

@implementation WDPPerceptionColorFrameSourceWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addSourceAddedEvent:(void (^)(WDPPerceptionColorFrameSourceWatcher*,
                                                        WDPPerceptionColorFrameSourceAddedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceAdded(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceAddedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceAdded(token));
}

- (EventRegistrationToken)addSourceRemovedEvent:(void (^)(WDPPerceptionColorFrameSourceWatcher*,
                                                          WDPPerceptionColorFrameSourceRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceRemoved(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_Windows_Devices_Perception_PerceptionColorFrameSourceRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceRemoved(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WDPPerceptionColorFrameSourceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Stopped(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDPPerceptionColorFrameSourceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnumerationCompleted(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSourceWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (WDEDeviceWatcherStatus)status {
    ABI::Windows::Devices::Enumeration::DeviceWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDEDeviceWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WDPPerceptionColorFrameSourceAddedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPerceptionColorFrameSource*)frameSource {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionColorFrameSource>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionColorFrameSourceRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPerceptionColorFrameSource*)frameSource {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionColorFrameSource>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionDepthFrameSourceWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addSourceAddedEvent:(void (^)(WDPPerceptionDepthFrameSourceWatcher*,
                                                        WDPPerceptionDepthFrameSourceAddedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceAdded(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceAddedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceAdded(token));
}

- (EventRegistrationToken)addSourceRemovedEvent:(void (^)(WDPPerceptionDepthFrameSourceWatcher*,
                                                          WDPPerceptionDepthFrameSourceRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceRemoved(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_Windows_Devices_Perception_PerceptionDepthFrameSourceRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceRemoved(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WDPPerceptionDepthFrameSourceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Stopped(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDPPerceptionDepthFrameSourceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnumerationCompleted(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSourceWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (WDEDeviceWatcherStatus)status {
    ABI::Windows::Devices::Enumeration::DeviceWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDEDeviceWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WDPPerceptionDepthFrameSourceAddedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPerceptionDepthFrameSource*)frameSource {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionDepthFrameSource>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionDepthFrameSourceRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPerceptionDepthFrameSource*)frameSource {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionDepthFrameSource>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionInfraredFrameSourceWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addSourceAddedEvent:(void (^)(WDPPerceptionInfraredFrameSourceWatcher*,
                                                        WDPPerceptionInfraredFrameSourceAddedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceAdded(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceAddedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceAdded(token));
}

- (EventRegistrationToken)addSourceRemovedEvent:(void (^)(WDPPerceptionInfraredFrameSourceWatcher*,
                                                          WDPPerceptionInfraredFrameSourceRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceRemoved(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_Windows_Devices_Perception_PerceptionInfraredFrameSourceRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceRemoved(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WDPPerceptionInfraredFrameSourceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Stopped(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDPPerceptionInfraredFrameSourceWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnumerationCompleted(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSourceWatcher_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (WDEDeviceWatcherStatus)status {
    ABI::Windows::Devices::Enumeration::DeviceWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDEDeviceWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WDPPerceptionInfraredFrameSourceAddedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPerceptionInfraredFrameSource*)frameSource {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionInfraredFrameSource>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionInfraredFrameSourceRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPerceptionInfraredFrameSource*)frameSource {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionInfraredFrameSource>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionColorFrameSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceStatics> WDPIPerceptionColorFrameSourceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.PerceptionColorFrameSource").Get(), &inst));
    return inst;
}

+ (WDPPerceptionColorFrameSourceWatcher*)createWatcher {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher> unmarshalledReturn;
    auto _comInst = WDPIPerceptionColorFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionColorFrameSourceWatcher>(unmarshalledReturn.Get());
}

+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WDPPerceptionColorFrameSource* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>*>>
        unmarshalledReturn;
    auto _comInst = WDPIPerceptionColorFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDPPerceptionColorFrameSource_create(result.Get()));
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

+ (void)fromIdAsync:(NSString*)id success:(void (^)(WDPPerceptionColorFrameSource*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>> unmarshalledReturn;
    auto _comInst = WDPIPerceptionColorFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionColorFrameSource>(result.Get()));
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

+ (void)requestAccessAsyncWithSuccess:(void (^)(WDPPerceptionFrameSourceAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>>
        unmarshalledReturn;
    auto _comInst = WDPIPerceptionColorFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WDPPerceptionFrameSourceAccessStatus)result);
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

- (EventRegistrationToken)addAvailableChangedEvent:(void (^)(WDPPerceptionColorFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_AvailableChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAvailableChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AvailableChanged(token));
}

- (EventRegistrationToken)addActiveChangedEvent:(void (^)(WDPPerceptionColorFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_ActiveChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActiveChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ActiveChanged(token));
}

- (EventRegistrationToken)addPropertiesChangedEvent:(void (^)(WDPPerceptionColorFrameSource*,
                                                              WDPPerceptionFrameSourcePropertiesChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PropertiesChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePropertiesChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PropertiesChanged(token));
}

- (EventRegistrationToken)addVideoProfileChangedEvent:(void (^)(WDPPerceptionColorFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_VideoProfileChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVideoProfileChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VideoProfileChanged(token));
}

- (EventRegistrationToken)addCameraIntrinsicsChangedEvent:(void (^)(WDPPerceptionColorFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_CameraIntrinsicsChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCameraIntrinsicsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CameraIntrinsicsChanged(token));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceKind {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceKind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)available {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Available(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)active {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Active(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isControlled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsControlled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPerceptionVideoProfile* */)supportedVideoProfiles {
    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionVideoProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedVideoProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPerceptionVideoProfile_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPerceptionVideoProfile* */)availableVideoProfiles {
    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionVideoProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_AvailableVideoProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPerceptionVideoProfile_create(unmarshalledReturn.Get());
}

- (WDPPerceptionVideoProfile*)videoProfile {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionVideoProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionVideoProfile>(unmarshalledReturn.Get());
}

- (WMDCCameraIntrinsics*)cameraIntrinsics {
    ComPtr<ABI::Windows::Media::Devices::Core::ICameraIntrinsics> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraIntrinsics(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCCameraIntrinsics>(unmarshalledReturn.Get());
}

- (WDPPerceptionControlSession*)acquireControlSession {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionControlSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->AcquireControlSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionControlSession>(unmarshalledReturn.Get());
}

- (BOOL)canControlIndependentlyFrom:(NSString*)targetId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->CanControlIndependentlyFrom(nsStrToHstr(targetId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCorrelatedWith:(NSString*)targetId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->IsCorrelatedWith(nsStrToHstr(targetId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)tryGetTransformTo:(NSString*)targetId result:(WFNMatrix4x4**)result {
    ABI::Windows::Foundation::Numerics::Matrix4x4 resultOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetTransformTo(nsStrToHstr(targetId).Get(), &resultOutUnmarshaled, &unmarshalledReturn));
    *result = WFNMatrix4x4_create(resultOutUnmarshaled);
    return (BOOL)unmarshalledReturn;
}

- (void)tryGetDepthCorrelatedCameraIntrinsicsAsync:(WDPPerceptionDepthFrameSource*)correlatedDepthFrameSource
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCameraIntrinsics*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetDepthCorrelatedCameraIntrinsicsAsync(
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(correlatedDepthFrameSource).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionDepthCorrelatedCameraIntrinsics>(result.Get()));
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

- (void)tryGetDepthCorrelatedCoordinateMapperAsync:(NSString*)targetSourceId
                        correlatedDepthFrameSource:(WDPPerceptionDepthFrameSource*)correlatedDepthFrameSource
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCoordinateMapper*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetDepthCorrelatedCoordinateMapperAsync(
        nsStrToHstr(targetSourceId).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(correlatedDepthFrameSource).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionDepthCorrelatedCoordinateMapper>(result.Get()));
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

- (void)trySetVideoProfileAsync:(WDPPerceptionControlSession*)controlSession
                        profile:(WDPPerceptionVideoProfile*)profile
                        success:(void (^)(WDPPerceptionFrameSourcePropertyChangeResult*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetVideoProfileAsync(
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionControlSession>(controlSession).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(profile).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionFrameSourcePropertyChangeResult>(result.Get()));
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

- (WDPPerceptionColorFrameReader*)openReader {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->OpenReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionColorFrameReader>(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPPerceptionDepthFrameSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics> WDPIPerceptionDepthFrameSourceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.PerceptionDepthFrameSource").Get(), &inst));
    return inst;
}

+ (WDPPerceptionDepthFrameSourceWatcher*)createWatcher {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher> unmarshalledReturn;
    auto _comInst = WDPIPerceptionDepthFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionDepthFrameSourceWatcher>(unmarshalledReturn.Get());
}

+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WDPPerceptionDepthFrameSource* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>*>>
        unmarshalledReturn;
    auto _comInst = WDPIPerceptionDepthFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDPPerceptionDepthFrameSource_create(result.Get()));
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

+ (void)fromIdAsync:(NSString*)id success:(void (^)(WDPPerceptionDepthFrameSource*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>> unmarshalledReturn;
    auto _comInst = WDPIPerceptionDepthFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionDepthFrameSource>(result.Get()));
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

+ (void)requestAccessAsyncWithSuccess:(void (^)(WDPPerceptionFrameSourceAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>>
        unmarshalledReturn;
    auto _comInst = WDPIPerceptionDepthFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WDPPerceptionFrameSourceAccessStatus)result);
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

- (EventRegistrationToken)addAvailableChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_AvailableChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAvailableChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AvailableChanged(token));
}

- (EventRegistrationToken)addActiveChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_ActiveChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActiveChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ActiveChanged(token));
}

- (EventRegistrationToken)addPropertiesChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*,
                                                              WDPPerceptionFrameSourcePropertiesChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PropertiesChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePropertiesChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PropertiesChanged(token));
}

- (EventRegistrationToken)addVideoProfileChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_VideoProfileChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVideoProfileChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VideoProfileChanged(token));
}

- (EventRegistrationToken)addCameraIntrinsicsChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_CameraIntrinsicsChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCameraIntrinsicsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CameraIntrinsicsChanged(token));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceKind {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceKind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)available {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Available(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)active {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Active(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isControlled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsControlled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPerceptionVideoProfile* */)supportedVideoProfiles {
    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionVideoProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedVideoProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPerceptionVideoProfile_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPerceptionVideoProfile* */)availableVideoProfiles {
    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionVideoProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_AvailableVideoProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPerceptionVideoProfile_create(unmarshalledReturn.Get());
}

- (WDPPerceptionVideoProfile*)videoProfile {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionVideoProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionVideoProfile>(unmarshalledReturn.Get());
}

- (WMDCCameraIntrinsics*)cameraIntrinsics {
    ComPtr<ABI::Windows::Media::Devices::Core::ICameraIntrinsics> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraIntrinsics(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCCameraIntrinsics>(unmarshalledReturn.Get());
}

- (WDPPerceptionControlSession*)acquireControlSession {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionControlSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->AcquireControlSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionControlSession>(unmarshalledReturn.Get());
}

- (BOOL)canControlIndependentlyFrom:(NSString*)targetId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->CanControlIndependentlyFrom(nsStrToHstr(targetId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCorrelatedWith:(NSString*)targetId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->IsCorrelatedWith(nsStrToHstr(targetId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)tryGetTransformTo:(NSString*)targetId result:(WFNMatrix4x4**)result {
    ABI::Windows::Foundation::Numerics::Matrix4x4 resultOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetTransformTo(nsStrToHstr(targetId).Get(), &resultOutUnmarshaled, &unmarshalledReturn));
    *result = WFNMatrix4x4_create(resultOutUnmarshaled);
    return (BOOL)unmarshalledReturn;
}

- (void)tryGetDepthCorrelatedCameraIntrinsicsAsync:(WDPPerceptionDepthFrameSource*)target
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCameraIntrinsics*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetDepthCorrelatedCameraIntrinsicsAsync(
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(target).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionDepthCorrelatedCameraIntrinsics>(result.Get()));
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

- (void)tryGetDepthCorrelatedCoordinateMapperAsync:(NSString*)targetId
                         depthFrameSourceToMapWith:(WDPPerceptionDepthFrameSource*)depthFrameSourceToMapWith
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCoordinateMapper*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetDepthCorrelatedCoordinateMapperAsync(
        nsStrToHstr(targetId).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(depthFrameSourceToMapWith).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionDepthCorrelatedCoordinateMapper>(result.Get()));
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

- (void)trySetVideoProfileAsync:(WDPPerceptionControlSession*)controlSession
                        profile:(WDPPerceptionVideoProfile*)profile
                        success:(void (^)(WDPPerceptionFrameSourcePropertyChangeResult*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetVideoProfileAsync(
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionControlSession>(controlSession).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(profile).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionFrameSourcePropertyChangeResult>(result.Get()));
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

- (WDPPerceptionDepthFrameReader*)openReader {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->OpenReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionDepthFrameReader>(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPPerceptionInfraredFrameSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics> WDPIPerceptionInfraredFrameSourceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.PerceptionInfraredFrameSource").Get(), &inst));
    return inst;
}

+ (WDPPerceptionInfraredFrameSourceWatcher*)createWatcher {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher> unmarshalledReturn;
    auto _comInst = WDPIPerceptionInfraredFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionInfraredFrameSourceWatcher>(unmarshalledReturn.Get());
}

+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WDPPerceptionInfraredFrameSource* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>*>>
        unmarshalledReturn;
    auto _comInst = WDPIPerceptionInfraredFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDPPerceptionInfraredFrameSource_create(result.Get()));
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

+ (void)fromIdAsync:(NSString*)id success:(void (^)(WDPPerceptionInfraredFrameSource*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>> unmarshalledReturn;
    auto _comInst = WDPIPerceptionInfraredFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPPerceptionInfraredFrameSource>(result.Get()));
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

+ (void)requestAccessAsyncWithSuccess:(void (^)(WDPPerceptionFrameSourceAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>>
        unmarshalledReturn;
    auto _comInst = WDPIPerceptionInfraredFrameSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WDPPerceptionFrameSourceAccessStatus)result);
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

- (EventRegistrationToken)addAvailableChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_AvailableChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAvailableChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AvailableChanged(token));
}

- (EventRegistrationToken)addActiveChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_ActiveChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActiveChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ActiveChanged(token));
}

- (EventRegistrationToken)addPropertiesChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*,
                                                              WDPPerceptionFrameSourcePropertiesChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PropertiesChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_Windows_Devices_Perception_PerceptionFrameSourcePropertiesChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePropertiesChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PropertiesChanged(token));
}

- (EventRegistrationToken)addVideoProfileChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_VideoProfileChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVideoProfileChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VideoProfileChanged(token));
}

- (EventRegistrationToken)addCameraIntrinsicsChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_CameraIntrinsicsChanged(
        Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameSource_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCameraIntrinsicsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CameraIntrinsicsChanged(token));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceKind {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceKind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)available {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Available(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)active {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Active(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isControlled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsControlled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPerceptionVideoProfile* */)supportedVideoProfiles {
    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionVideoProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedVideoProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPerceptionVideoProfile_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPerceptionVideoProfile* */)availableVideoProfiles {
    ComPtr<IVectorView<ABI::Windows::Devices::Perception::PerceptionVideoProfile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_AvailableVideoProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPerceptionVideoProfile_create(unmarshalledReturn.Get());
}

- (WDPPerceptionVideoProfile*)videoProfile {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionVideoProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionVideoProfile>(unmarshalledReturn.Get());
}

- (WMDCCameraIntrinsics*)cameraIntrinsics {
    ComPtr<ABI::Windows::Media::Devices::Core::ICameraIntrinsics> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraIntrinsics(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCCameraIntrinsics>(unmarshalledReturn.Get());
}

- (WDPPerceptionControlSession*)acquireControlSession {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionControlSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->AcquireControlSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionControlSession>(unmarshalledReturn.Get());
}

- (BOOL)canControlIndependentlyFrom:(NSString*)targetId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->CanControlIndependentlyFrom(nsStrToHstr(targetId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCorrelatedWith:(NSString*)targetId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->IsCorrelatedWith(nsStrToHstr(targetId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)tryGetTransformTo:(NSString*)targetId result:(WFNMatrix4x4**)result {
    ABI::Windows::Foundation::Numerics::Matrix4x4 resultOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetTransformTo(nsStrToHstr(targetId).Get(), &resultOutUnmarshaled, &unmarshalledReturn));
    *result = WFNMatrix4x4_create(resultOutUnmarshaled);
    return (BOOL)unmarshalledReturn;
}

- (void)tryGetDepthCorrelatedCameraIntrinsicsAsync:(WDPPerceptionDepthFrameSource*)target
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCameraIntrinsics*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetDepthCorrelatedCameraIntrinsicsAsync(
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(target).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionDepthCorrelatedCameraIntrinsics>(result.Get()));
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

- (void)tryGetDepthCorrelatedCoordinateMapperAsync:(NSString*)targetId
                         depthFrameSourceToMapWith:(WDPPerceptionDepthFrameSource*)depthFrameSourceToMapWith
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCoordinateMapper*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetDepthCorrelatedCoordinateMapperAsync(
        nsStrToHstr(targetId).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource>(depthFrameSourceToMapWith).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionDepthCorrelatedCoordinateMapper>(result.Get()));
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

- (void)trySetVideoProfileAsync:(WDPPerceptionControlSession*)controlSession
                        profile:(WDPPerceptionVideoProfile*)profile
                        success:(void (^)(WDPPerceptionFrameSourcePropertyChangeResult*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetVideoProfileAsync(
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionControlSession>(controlSession).Get(),
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(profile).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionFrameSourcePropertyChangeResult>(result.Get()));
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

- (WDPPerceptionInfraredFrameReader*)openReader {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->OpenReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionInfraredFrameReader>(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPPerceptionControlSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionControlSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addControlLostEvent:(void (^)(WDPPerceptionControlSession*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionControlSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ControlLost(Make<ITypedEventHandler_Windows_Devices_Perception_PerceptionControlSession_System_Object>(handler).Get(),
                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeControlLostEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionControlSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ControlLost(token));
}

- (void)trySetPropertyAsync:(NSString*)name
                      value:(RTObject*)value
                    success:(void (^)(WDPPerceptionFrameSourcePropertyChangeResult*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionControlSession>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetPropertyAsync(nsStrToHstr(name).Get(), [value comObj].Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPerceptionFrameSourcePropertyChangeResult>(result.Get()));
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
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPerceptionFrameSourcePropertyChangeResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPerceptionFrameSourcePropertyChangeStatus)status {
    ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDPPerceptionFrameSourcePropertyChangeStatus)unmarshalledReturn;
}

- (RTObject*)newValue __attribute__((ns_returns_not_retained)) {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionFrameSourcePropertiesChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFCCollectionChange)collectionChange {
    ABI::Windows::Foundation::Collections::CollectionChange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CollectionChange(&unmarshalledReturn));
    return (WFCCollectionChange)unmarshalledReturn;
}

- (NSString*)key {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Key(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPPerceptionVideoProfile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionVideoProfile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGIBitmapPixelFormat)bitmapPixelFormat {
    ABI::Windows::Graphics::Imaging::BitmapPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapPixelFormat(&unmarshalledReturn));
    return (WGIBitmapPixelFormat)unmarshalledReturn;
}

- (WGIBitmapAlphaMode)bitmapAlphaMode {
    ABI::Windows::Graphics::Imaging::BitmapAlphaMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapAlphaMode(&unmarshalledReturn));
    return (WGIBitmapAlphaMode)unmarshalledReturn;
}

- (int)width {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)height {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)frameDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (BOOL)IsEqual:(WDPPerceptionVideoProfile*)other {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsEqual(_getRtInterface<ABI::Windows::Devices::Perception::IPerceptionVideoProfile>(other).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDPPerceptionDepthCorrelatedCameraIntrinsics

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector3*)unprojectPixelAtCorrelatedDepth:(WFPoint*)pixelCoordinate depthFrame:(WDPPerceptionDepthFrame*)depthFrame {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->UnprojectPixelAtCorrelatedDepth(
        *[pixelCoordinate internalStruct],
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(depthFrame).Get(),
        &unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)unprojectPixelsAtCorrelatedDepth:(NSArray* /* WFPoint* */)sourceCoordinates
                              depthFrame:(WDPPerceptionDepthFrame*)depthFrame
                                 results:(NSArray* /* WFNVector3* */*)results {
    UINT32 __sourceCoordinates_ArrayLen = 0;
    bool __sourceCoordinates_IsTemp = false;
    ABI::Windows::Foundation::Point* __sourceCoordinates_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(sourceCoordinates,
                                                          &__sourceCoordinates_ArrayLen,
                                                          &__sourceCoordinates_Array,
                                                          &__sourceCoordinates_IsTemp))
        assert(0);
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Numerics::Vector3* __results_Array = (ABI::Windows::Foundation::Numerics::Vector3*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->UnprojectPixelsAtCorrelatedDepth(
        __sourceCoordinates_ArrayLen,
        __sourceCoordinates_Array,
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(depthFrame).Get(),
        __results_ArrayLen,
        __results_Array));
    if (__sourceCoordinates_IsTemp)
        CoTaskMemFree(__sourceCoordinates_Array);
}

- (RTObject<WFIAsyncAction>*)unprojectRegionPixelsAtCorrelatedDepthAsync:(WFRect*)region
                                                              depthFrame:(WDPPerceptionDepthFrame*)depthFrame
                                                                 results:(NSArray* /* WFNVector3* */*)results {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Numerics::Vector3* __results_Array = (ABI::Windows::Foundation::Numerics::Vector3*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->UnprojectRegionPixelsAtCorrelatedDepthAsync(
        *[region internalStruct],
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(depthFrame).Get(),
        __results_ArrayLen,
        __results_Array,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)unprojectAllPixelsAtCorrelatedDepthAsync:(WDPPerceptionDepthFrame*)depthFrame
                                                              results:(NSArray* /* WFNVector3* */*)results {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Numerics::Vector3* __results_Array = (ABI::Windows::Foundation::Numerics::Vector3*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->UnprojectAllPixelsAtCorrelatedDepthAsync(
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(depthFrame).Get(),
        __results_ArrayLen,
        __results_Array,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionDepthCorrelatedCoordinateMapper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFPoint*)mapPixelToTarget:(WFPoint*)sourcePixelCoordinate depthFrame:(WDPPerceptionDepthFrame*)depthFrame {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper>(self);
    THROW_NS_IF_FAILED(
        _comInst->MapPixelToTarget(*[sourcePixelCoordinate internalStruct],
                                   _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(depthFrame).Get(),
                                   &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)mapPixelsToTarget:(NSArray* /* WFPoint* */)sourceCoordinates
               depthFrame:(WDPPerceptionDepthFrame*)depthFrame
                  results:(NSArray* /* WFPoint* */*)results {
    UINT32 __sourceCoordinates_ArrayLen = 0;
    bool __sourceCoordinates_IsTemp = false;
    ABI::Windows::Foundation::Point* __sourceCoordinates_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(sourceCoordinates,
                                                          &__sourceCoordinates_ArrayLen,
                                                          &__sourceCoordinates_Array,
                                                          &__sourceCoordinates_IsTemp))
        assert(0);
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Point* __results_Array = (ABI::Windows::Foundation::Point*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper>(self);
    THROW_NS_IF_FAILED(
        _comInst->MapPixelsToTarget(__sourceCoordinates_ArrayLen,
                                    __sourceCoordinates_Array,
                                    _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(depthFrame).Get(),
                                    __results_ArrayLen,
                                    __results_Array));
    if (__sourceCoordinates_IsTemp)
        CoTaskMemFree(__sourceCoordinates_Array);
}

- (RTObject<WFIAsyncAction>*)mapRegionOfPixelsToTargetAsync:(WFRect*)region
                                                 depthFrame:(WDPPerceptionDepthFrame*)depthFrame
                                          targetCoordinates:(NSArray* /* WFPoint* */*)targetCoordinates {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    UINT32 __targetCoordinates_ArrayLen = (UINT32)[targetCoordinates count];
    ABI::Windows::Foundation::Point* __targetCoordinates_Array = (ABI::Windows::Foundation::Point*)[targetCoordinates ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper>(self);
    THROW_NS_IF_FAILED(_comInst->MapRegionOfPixelsToTargetAsync(
        *[region internalStruct],
        _getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(depthFrame).Get(),
        __targetCoordinates_ArrayLen,
        __targetCoordinates_Array,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)mapAllPixelsToTargetAsync:(WDPPerceptionDepthFrame*)depthFrame
                                     targetCoordinates:(NSArray* /* WFPoint* */*)targetCoordinates {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    UINT32 __targetCoordinates_ArrayLen = (UINT32)[targetCoordinates count];
    ABI::Windows::Foundation::Point* __targetCoordinates_Array = (ABI::Windows::Foundation::Point*)[targetCoordinates ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper>(self);
    THROW_NS_IF_FAILED(
        _comInst->MapAllPixelsToTargetAsync(_getRtInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(depthFrame).Get(),
                                            __targetCoordinates_ArrayLen,
                                            __targetCoordinates_Array,
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionColorFrameReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addFrameArrivedEvent:(void (^)(WDPPerceptionColorFrameReader*, WDPPerceptionColorFrameArrivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_FrameArrived(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionColorFrameReader_Windows_Devices_Perception_PerceptionColorFrameArrivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFrameArrivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FrameArrived(token));
}

- (WDPPerceptionColorFrameSource*)source {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionColorFrameSource>(unmarshalledReturn.Get());
}

- (BOOL)isPaused {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaused(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPaused:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPaused((boolean)value));
}

- (WDPPerceptionColorFrame*)tryReadLatestFrame {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->TryReadLatestFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionColorFrame>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPerceptionDepthFrameReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addFrameArrivedEvent:(void (^)(WDPPerceptionDepthFrameReader*, WDPPerceptionDepthFrameArrivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_FrameArrived(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionDepthFrameReader_Windows_Devices_Perception_PerceptionDepthFrameArrivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFrameArrivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FrameArrived(token));
}

- (WDPPerceptionDepthFrameSource*)source {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionDepthFrameSource>(unmarshalledReturn.Get());
}

- (BOOL)isPaused {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaused(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPaused:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPaused((boolean)value));
}

- (WDPPerceptionDepthFrame*)tryReadLatestFrame {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->TryReadLatestFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionDepthFrame>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPerceptionInfraredFrameReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addFrameArrivedEvent:(void (^)(WDPPerceptionInfraredFrameReader*,
                                                         WDPPerceptionInfraredFrameArrivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_FrameArrived(
        Make<
            ITypedEventHandler_Windows_Devices_Perception_PerceptionInfraredFrameReader_Windows_Devices_Perception_PerceptionInfraredFrameArrivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFrameArrivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FrameArrived(token));
}

- (WDPPerceptionInfraredFrameSource*)source {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionInfraredFrameSource>(unmarshalledReturn.Get());
}

- (BOOL)isPaused {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaused(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPaused:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPaused((boolean)value));
}

- (WDPPerceptionInfraredFrame*)tryReadLatestFrame {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->TryReadLatestFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionInfraredFrame>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPerceptionColorFrameArrivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)relativeTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDPPerceptionColorFrame*)tryOpenFrame {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->TryOpenFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionColorFrame>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionColorFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionColorFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMVideoFrame*)videoFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionColorFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPerceptionDepthFrameArrivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)relativeTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDPPerceptionDepthFrame*)tryOpenFrame {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->TryOpenFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionDepthFrame>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionDepthFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionDepthFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMVideoFrame*)videoFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionDepthFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPerceptionInfraredFrameArrivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)relativeTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDPPerceptionInfraredFrame*)tryOpenFrame {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->TryOpenFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPerceptionInfraredFrame>(unmarshalledReturn.Get());
}

@end

@implementation WDPPerceptionInfraredFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Perception::IPerceptionInfraredFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMVideoFrame*)videoFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Perception::IPerceptionInfraredFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPKnownPerceptionFrameSourceProperties

ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics>
WDPIKnownPerceptionFrameSourcePropertiesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.KnownPerceptionFrameSourceProperties").Get(), &inst));
    return inst;
}

+ (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)physicalDeviceIds {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PhysicalDeviceIds(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)frameKind {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FrameKind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)deviceModelVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeviceModelVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)enclosureLocation {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnclosureLocation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2>
WDPIKnownPerceptionFrameSourcePropertiesStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.KnownPerceptionFrameSourceProperties").Get(), &inst));
    return inst;
}

+ (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionFrameSourcePropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPKnownPerceptionVideoFrameSourceProperties

ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics>
WDPIKnownPerceptionVideoFrameSourcePropertiesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.KnownPerceptionVideoFrameSourceProperties").Get(), &inst));
    return inst;
}

+ (NSString*)videoProfile {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VideoProfile(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)supportedVideoProfiles {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedVideoProfiles(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)availableVideoProfiles {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AvailableVideoProfiles(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)isMirrored {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsMirrored(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cameraIntrinsics {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CameraIntrinsics(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPKnownPerceptionInfraredFrameSourceProperties

ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics>
WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.KnownPerceptionInfraredFrameSourceProperties").Get(), &inst));
    return inst;
}

+ (NSString*)exposure {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Exposure(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)autoExposureEnabled {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutoExposureEnabled(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)exposureCompensation {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExposureCompensation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)activeIlluminationEnabled {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ActiveIlluminationEnabled(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ambientSubtractionEnabled {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AmbientSubtractionEnabled(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)structureLightPatternEnabled {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StructureLightPatternEnabled(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)interleavedIlluminationEnabled {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InterleavedIlluminationEnabled(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPKnownPerceptionDepthFrameSourceProperties

ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics>
WDPIKnownPerceptionDepthFrameSourcePropertiesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.KnownPerceptionDepthFrameSourceProperties").Get(), &inst));
    return inst;
}

+ (NSString*)minDepth {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionDepthFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinDepth(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)maxDepth {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionDepthFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxDepth(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPKnownPerceptionColorFrameSourceProperties

ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics>
WDPIKnownPerceptionColorFrameSourcePropertiesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.KnownPerceptionColorFrameSourceProperties").Get(), &inst));
    return inst;
}

+ (NSString*)exposure {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionColorFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Exposure(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)autoExposureEnabled {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionColorFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutoExposureEnabled(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)exposureCompensation {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionColorFrameSourcePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExposureCompensation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPKnownPerceptionVideoProfileProperties

ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics>
WDPIKnownPerceptionVideoProfilePropertiesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.KnownPerceptionVideoProfileProperties").Get(), &inst));
    return inst;
}

+ (NSString*)bitmapPixelFormat {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoProfilePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BitmapPixelFormat(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bitmapAlphaMode {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoProfilePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BitmapAlphaMode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)width {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoProfilePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)height {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoProfilePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)frameDuration {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownPerceptionVideoProfilePropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FrameDuration(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPKnownCameraIntrinsicsProperties

ComPtr<ABI::Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics> WDPIKnownCameraIntrinsicsPropertiesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Perception.KnownCameraIntrinsicsProperties").Get(), &inst));
    return inst;
}

+ (NSString*)focalLength {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownCameraIntrinsicsPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocalLength(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)principalPoint {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownCameraIntrinsicsPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PrincipalPoint(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)radialDistortion {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownCameraIntrinsicsPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RadialDistortion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tangentialDistortion {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIKnownCameraIntrinsicsPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TangentialDistortion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedNSArray_C_WFNVector3_create(UINT32 size, ABI::Windows::Foundation::Numerics::Vector3* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::Foundation::Numerics::Vector3,
                                          RTCArrayObj<ABI::Windows::Foundation::Numerics::Vector3, WFNVector3, dummyObjCCreator>>>(size,
                                                                                                                                   val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Point, RTCArrayObj<ABI::Windows::Foundation::Point, WFPoint, dummyObjCCreator>>>(size,
                                                                                                                                    val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDPPerceptionColorFrameSource_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>,
                                         RTArrayObj<ABI::Windows::Devices::Perception::IPerceptionColorFrameSource*,
                                                    IVectorView<ABI::Windows::Devices::Perception::PerceptionColorFrameSource*>,
                                                    WDPPerceptionColorFrameSource,
                                                    ABI::Windows::Devices::Perception::PerceptionColorFrameSource*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDPPerceptionDepthFrameSource_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>,
                                         RTArrayObj<ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource*,
                                                    IVectorView<ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*>,
                                                    WDPPerceptionDepthFrameSource,
                                                    ABI::Windows::Devices::Perception::PerceptionDepthFrameSource*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDPPerceptionInfraredFrameSource_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>,
                                         RTArrayObj<ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource*,
                                                    IVectorView<ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*>,
                                                    WDPPerceptionInfraredFrameSource,
                                                    ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDPPerceptionVideoProfile_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Perception::PerceptionVideoProfile*>,
                                         RTArrayObj<ABI::Windows::Devices::Perception::IPerceptionVideoProfile*,
                                                    IVectorView<ABI::Windows::Devices::Perception::PerceptionVideoProfile*>,
                                                    WDPPerceptionVideoProfile,
                                                    ABI::Windows::Devices::Perception::PerceptionVideoProfile*,
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
