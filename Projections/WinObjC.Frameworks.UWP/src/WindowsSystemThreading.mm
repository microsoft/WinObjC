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

// WindowsSystemThreading.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.Threading.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemThreading.h"
#include "WindowsSystemThreading_priv.h"

@implementation WSTThreadPoolTimer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Threading::IThreadPoolTimer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::System::Threading::IThreadPoolTimerStatics> WSTIThreadPoolTimerStatics_inst() {
    ComPtr<ABI::Windows::System::Threading::IThreadPoolTimerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Threading.ThreadPoolTimer").Get(), &inst));
    return inst;
}

+ (WSTThreadPoolTimer*)createPeriodicTimer:(WSTTimerElapsedHandler)handler period:(WFTimeSpan*)period {
    ComPtr<ABI::Windows::System::Threading::IThreadPoolTimer> unmarshalledReturn;
    auto _comInst = WSTIThreadPoolTimerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePeriodicTimer(Make<WSTTimerElapsedHandler_shim>(handler).Get(),
                                                     *[period internalStruct],
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSTThreadPoolTimer>(unmarshalledReturn.Get());
}

+ (WSTThreadPoolTimer*)createTimer:(WSTTimerElapsedHandler)handler delay:(WFTimeSpan*)delay {
    ComPtr<ABI::Windows::System::Threading::IThreadPoolTimer> unmarshalledReturn;
    auto _comInst = WSTIThreadPoolTimerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTimer(Make<WSTTimerElapsedHandler_shim>(handler).Get(),
                                             *[delay internalStruct],
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSTThreadPoolTimer>(unmarshalledReturn.Get());
}

+ (WSTThreadPoolTimer*)createPeriodicTimerWithCompletion:(WSTTimerElapsedHandler)handler
                                                  period:(WFTimeSpan*)period
                                               destroyed:(WSTTimerDestroyedHandler)destroyed {
    ComPtr<ABI::Windows::System::Threading::IThreadPoolTimer> unmarshalledReturn;
    auto _comInst = WSTIThreadPoolTimerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePeriodicTimerWithCompletion(Make<WSTTimerElapsedHandler_shim>(handler).Get(),
                                                                   *[period internalStruct],
                                                                   Make<WSTTimerDestroyedHandler_shim>(destroyed).Get(),
                                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSTThreadPoolTimer>(unmarshalledReturn.Get());
}

+ (WSTThreadPoolTimer*)createTimerWithCompletion:(WSTTimerElapsedHandler)handler
                                           delay:(WFTimeSpan*)delay
                                       destroyed:(WSTTimerDestroyedHandler)destroyed {
    ComPtr<ABI::Windows::System::Threading::IThreadPoolTimer> unmarshalledReturn;
    auto _comInst = WSTIThreadPoolTimerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTimerWithCompletion(Make<WSTTimerElapsedHandler_shim>(handler).Get(),
                                                           *[delay internalStruct],
                                                           Make<WSTTimerDestroyedHandler_shim>(destroyed).Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSTThreadPoolTimer>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)period {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Threading::IThreadPoolTimer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Period(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)delay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Threading::IThreadPoolTimer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::System::Threading::IThreadPoolTimer>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

@end

@implementation WSTThreadPool

ComPtr<ABI::Windows::System::Threading::IThreadPoolStatics> WSTIThreadPoolStatics_inst() {
    ComPtr<ABI::Windows::System::Threading::IThreadPoolStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Threading.ThreadPool").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)runAsync:(WSTWorkItemHandler)handler {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSTIThreadPoolStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RunAsync(Make<WSTWorkItemHandler_shim>(handler).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)runWithPriorityAsync:(WSTWorkItemHandler)handler priority:(WSTWorkItemPriority)priority {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSTIThreadPoolStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RunWithPriorityAsync(Make<WSTWorkItemHandler_shim>(handler).Get(),
                                                      (ABI::Windows::System::Threading::WorkItemPriority)priority,
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)runWithPriorityAndOptionsAsync:(WSTWorkItemHandler)handler
                                                   priority:(WSTWorkItemPriority)priority
                                                    options:(WSTWorkItemOptions)options {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSTIThreadPoolStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RunWithPriorityAndOptionsAsync(Make<WSTWorkItemHandler_shim>(handler).Get(),
                                                                (ABI::Windows::System::Threading::WorkItemPriority)priority,
                                                                (ABI::Windows::System::Threading::WorkItemOptions)options,
                                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end
