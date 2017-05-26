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

// WindowsSystemThreadingCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.Threading.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemThreadingCore.h"
#include "WindowsSystemThreadingCore_priv.h"

@implementation WSTCSignalNotifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Threading::Core::ISignalNotifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::System::Threading::Core::ISignalNotifierStatics> WSTCISignalNotifierStatics_inst() {
    ComPtr<ABI::Windows::System::Threading::Core::ISignalNotifierStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Threading.Core.SignalNotifier").Get(),
                                                       &inst));
    return inst;
}

+ (WSTCSignalNotifier*)attachToEvent:(NSString*)name handler:(WSTCSignalHandler)handler {
    ComPtr<ABI::Windows::System::Threading::Core::ISignalNotifier> unmarshalledReturn;
    auto _comInst = WSTCISignalNotifierStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AttachToEvent(nsStrToHstr(name).Get(), Make<WSTCSignalHandler_shim>(handler).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSTCSignalNotifier>(unmarshalledReturn.Get());
}

+ (WSTCSignalNotifier*)attachToEventWithTimeout:(NSString*)name handler:(WSTCSignalHandler)handler timeout:(WFTimeSpan*)timeout {
    ComPtr<ABI::Windows::System::Threading::Core::ISignalNotifier> unmarshalledReturn;
    auto _comInst = WSTCISignalNotifierStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AttachToEventWithTimeout(nsStrToHstr(name).Get(),
                                                          Make<WSTCSignalHandler_shim>(handler).Get(),
                                                          *[timeout internalStruct],
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSTCSignalNotifier>(unmarshalledReturn.Get());
}

+ (WSTCSignalNotifier*)attachToSemaphore:(NSString*)name handler:(WSTCSignalHandler)handler {
    ComPtr<ABI::Windows::System::Threading::Core::ISignalNotifier> unmarshalledReturn;
    auto _comInst = WSTCISignalNotifierStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AttachToSemaphore(nsStrToHstr(name).Get(),
                                                   Make<WSTCSignalHandler_shim>(handler).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSTCSignalNotifier>(unmarshalledReturn.Get());
}

+ (WSTCSignalNotifier*)attachToSemaphoreWithTimeout:(NSString*)name handler:(WSTCSignalHandler)handler timeout:(WFTimeSpan*)timeout {
    ComPtr<ABI::Windows::System::Threading::Core::ISignalNotifier> unmarshalledReturn;
    auto _comInst = WSTCISignalNotifierStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AttachToSemaphoreWithTimeout(nsStrToHstr(name).Get(),
                                                              Make<WSTCSignalHandler_shim>(handler).Get(),
                                                              *[timeout internalStruct],
                                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSTCSignalNotifier>(unmarshalledReturn.Get());
}

- (void)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::System::Threading::Core::ISignalNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->Enable());
}

- (void)terminate {
    auto _comInst = _getInnerInterface<ABI::Windows::System::Threading::Core::ISignalNotifier>(self);
    THROW_NS_IF_FAILED(_comInst->Terminate());
}

@end

@implementation WSTCPreallocatedWorkItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Threading::Core::IPreallocatedWorkItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::System::Threading::Core::IPreallocatedWorkItemFactory> WSTCIPreallocatedWorkItemFactory_inst() {
    ComPtr<ABI::Windows::System::Threading::Core::IPreallocatedWorkItemFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Threading.Core.PreallocatedWorkItem").Get(),
                                                       &inst));
    return inst;
}

+ (WSTCPreallocatedWorkItem*)makeWorkItem:(WSTWorkItemHandler)handler {
    ComPtr<ABI::Windows::System::Threading::Core::IPreallocatedWorkItem> unmarshalledReturn;
    auto _comInst = WSTCIPreallocatedWorkItemFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWorkItem(Make<WSTWorkItemHandler_shim>(handler).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSTCPreallocatedWorkItem>(unmarshalledReturn.Get()) retain];
}

+ (WSTCPreallocatedWorkItem*)makeWorkItemWithPriority:(WSTWorkItemHandler)handler priority:(WSTWorkItemPriority)priority {
    ComPtr<ABI::Windows::System::Threading::Core::IPreallocatedWorkItem> unmarshalledReturn;
    auto _comInst = WSTCIPreallocatedWorkItemFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWorkItemWithPriority(Make<WSTWorkItemHandler_shim>(handler).Get(),
                                                            (ABI::Windows::System::Threading::WorkItemPriority)priority,
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSTCPreallocatedWorkItem>(unmarshalledReturn.Get()) retain];
}

+ (WSTCPreallocatedWorkItem*)makeWorkItemWithPriorityAndOptions:(WSTWorkItemHandler)handler
                                                       priority:(WSTWorkItemPriority)priority
                                                        options:(WSTWorkItemOptions)options {
    ComPtr<ABI::Windows::System::Threading::Core::IPreallocatedWorkItem> unmarshalledReturn;
    auto _comInst = WSTCIPreallocatedWorkItemFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWorkItemWithPriorityAndOptions(Make<WSTWorkItemHandler_shim>(handler).Get(),
                                                                      (ABI::Windows::System::Threading::WorkItemPriority)priority,
                                                                      (ABI::Windows::System::Threading::WorkItemOptions)options,
                                                                      unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSTCPreallocatedWorkItem>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WFIAsyncAction>*)runAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::Threading::Core::IPreallocatedWorkItem>(self);
    THROW_NS_IF_FAILED(_comInst->RunAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end
