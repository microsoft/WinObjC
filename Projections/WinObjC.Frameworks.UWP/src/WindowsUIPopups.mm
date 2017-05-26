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

// WindowsUIPopups.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Popups.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIPopups.h"
#include "WindowsUIPopups_priv.h"

@implementation WUPIUICommand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (WUPUICommandInvokedHandler)invoked {
    ComPtr<ABI::Windows::UI::Popups::IUICommandInvokedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Invoked(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)setInvoked:(WUPUICommandInvokedHandler)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Invoked(Make<WUPUICommandInvokedHandler_shim>(value).Get()));
}

- (RTObject*)id {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setId:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id([value comObj].Get()));
}

@end

@implementation WUPMessageDialog

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Popups::IMessageDialog> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Popups::IMessageDialogFactory> WUPIMessageDialogFactory_inst() {
    ComPtr<ABI::Windows::UI::Popups::IMessageDialogFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Popups.MessageDialog").Get(), &inst));
    return inst;
}

+ (WUPMessageDialog*)make:(NSString*)content {
    ComPtr<ABI::Windows::UI::Popups::IMessageDialog> unmarshalledReturn;
    auto _comInst = WUPIMessageDialogFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(content).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUPMessageDialog>(unmarshalledReturn.Get()) retain];
}

+ (WUPMessageDialog*)makeWithTitle:(NSString*)content title:(NSString*)title {
    ComPtr<ABI::Windows::UI::Popups::IMessageDialog> unmarshalledReturn;
    auto _comInst = WUPIMessageDialogFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithTitle(nsStrToHstr(content).Get(), nsStrToHstr(title).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUPMessageDialog>(unmarshalledReturn.Get()) retain];
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* RTObject<WUPIUICommand>* */)commands {
    ComPtr<IVector<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_Commands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WUPIUICommand_create(unmarshalledReturn.Get());
}

- (unsigned int)defaultCommandIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultCommandIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDefaultCommandIndex:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultCommandIndex(value));
}

- (unsigned int)cancelCommandIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_CancelCommandIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCancelCommandIndex:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_CancelCommandIndex(value));
}

- (NSString*)content {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContent:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_Content(nsStrToHstr(value).Get()));
}

- (void)showAsyncWithSuccess:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Popups::IUICommand*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::Popups::IUICommand> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUPIUICommand>(result.Get()));
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

- (WUPMessageDialogOptions)options {
    ABI::Windows::UI::Popups::MessageDialogOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_Options(&unmarshalledReturn));
    return (WUPMessageDialogOptions)unmarshalledReturn;
}

- (void)setOptions:(WUPMessageDialogOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IMessageDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_Options((ABI::Windows::UI::Popups::MessageDialogOptions)value));
}

@end

@implementation WUPUICommand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Popups.UICommand").Get(), &out));
    return [_createRtProxy<WUPUICommand>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::Popups::IUICommandFactory> WUPIUICommandFactory_inst() {
    ComPtr<ABI::Windows::UI::Popups::IUICommandFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Popups.UICommand").Get(), &inst));
    return inst;
}

+ (WUPUICommand*)make:(NSString*)label {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> unmarshalledReturn;
    auto _comInst = WUPIUICommandFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(label).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUPUICommand>(unmarshalledReturn.Get()) retain];
}

+ (WUPUICommand*)makeWithHandler:(NSString*)label action:(WUPUICommandInvokedHandler)action {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> unmarshalledReturn;
    auto _comInst = WUPIUICommandFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithHandler(nsStrToHstr(label).Get(),
                                                   Make<WUPUICommandInvokedHandler_shim>(action).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUPUICommand>(unmarshalledReturn.Get()) retain];
}

+ (WUPUICommand*)makeWithHandlerAndId:(NSString*)label action:(WUPUICommandInvokedHandler)action commandId:(RTObject*)commandId {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> unmarshalledReturn;
    auto _comInst = WUPIUICommandFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithHandlerAndId(nsStrToHstr(label).Get(),
                                                        Make<WUPUICommandInvokedHandler_shim>(action).Get(),
                                                        [commandId comObj].Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUPUICommand>(unmarshalledReturn.Get()) retain];
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (WUPUICommandInvokedHandler)invoked {
    ComPtr<ABI::Windows::UI::Popups::IUICommandInvokedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Invoked(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)setInvoked:(WUPUICommandInvokedHandler)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Invoked(Make<WUPUICommandInvokedHandler_shim>(value).Get()));
}

- (RTObject*)id {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setId:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id([value comObj].Get()));
}

@end

@implementation WUPUICommandSeparator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Popups.UICommandSeparator").Get(), &out));
    return [_createRtProxy<WUPUICommandSeparator>(out.Get()) retain];
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (WUPUICommandInvokedHandler)invoked {
    ComPtr<ABI::Windows::UI::Popups::IUICommandInvokedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Invoked(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)setInvoked:(WUPUICommandInvokedHandler)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Invoked(Make<WUPUICommandInvokedHandler_shim>(value).Get()));
}

- (RTObject*)id {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setId:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id([value comObj].Get()));
}

@end

@implementation WUPPopupMenu

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Popups::IPopupMenu> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Popups.PopupMenu").Get(), &out));
    return [_createRtProxy<WUPPopupMenu>(out.Get()) retain];
}

- (NSMutableArray* /* RTObject<WUPIUICommand>* */)commands {
    ComPtr<IVector<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IPopupMenu>(self);
    THROW_NS_IF_FAILED(_comInst->get_Commands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WUPIUICommand_create(unmarshalledReturn.Get());
}

- (void)showAsync:(WFPoint*)invocationPoint success:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IPopupMenu>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsync(*[invocationPoint internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Popups::IUICommand*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::Popups::IUICommand> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUPIUICommand>(result.Get()));
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

- (void)showAsyncWithRect:(WFRect*)selection success:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IPopupMenu>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsyncWithRect(*[selection internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Popups::IUICommand*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::Popups::IUICommand> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUPIUICommand>(result.Get()));
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

- (void)showAsyncWithRectAndPlacement:(WFRect*)selection
                   preferredPlacement:(WUPPlacement)preferredPlacement
                              success:(void (^)(RTObject<WUPIUICommand>*))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IPopupMenu>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsyncWithRectAndPlacement(*[selection internalStruct],
                                                               (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Popups::IUICommand*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::Popups::IUICommand> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUPIUICommand>(result.Get()));
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

id RTProxiedNSMutableArray_RTObject_WUPIUICommand_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Popups::IUICommand*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Popups::IUICommand*,
                                                                  IVector<ABI::Windows::UI::Popups::IUICommand*>,
                                                                  RTObject<WUPIUICommand>,
                                                                  ABI::Windows::UI::Popups::IUICommand*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
