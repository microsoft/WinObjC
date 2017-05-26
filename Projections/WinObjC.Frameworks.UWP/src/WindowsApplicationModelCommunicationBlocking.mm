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

// WindowsApplicationModelCommunicationBlocking.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.CommunicationBlocking.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelCommunicationBlocking.h"
#include "WindowsApplicationModelCommunicationBlocking_priv.h"

@implementation WACCommunicationBlockingAppManager

ComPtr<ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2>
WACICommunicationBlockingAppManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAppManager").Get(), &inst));
    return inst;
}

+ (void)requestSetAsActiveBlockingAppAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WACICommunicationBlockingAppManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestSetAsActiveBlockingAppAsync(&unmarshalledReturn));

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

ComPtr<ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>
WACICommunicationBlockingAppManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAppManager").Get(), &inst));
    return inst;
}

+ (BOOL)isCurrentAppActiveBlockingApp {
    boolean unmarshalledReturn;
    auto _comInst = WACICommunicationBlockingAppManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsCurrentAppActiveBlockingApp(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)showCommunicationBlockingSettingsUI {
    auto _comInst = WACICommunicationBlockingAppManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowCommunicationBlockingSettingsUI());
}

@end

@implementation WACCommunicationBlockingAccessManager

ComPtr<ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics>
WACICommunicationBlockingAccessManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAccessManager").Get(), &inst));
    return inst;
}

+ (BOOL)isBlockingActive {
    boolean unmarshalledReturn;
    auto _comInst = WACICommunicationBlockingAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsBlockingActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)isBlockedNumberAsync:(NSString*)number success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WACICommunicationBlockingAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsBlockedNumberAsync(nsStrToHstr(number).Get(), &unmarshalledReturn));

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

+ (BOOL)showBlockNumbersUI:(id<NSFastEnumeration> /* NSString * */)phoneNumbers {
    boolean unmarshalledReturn;
    auto _comInst = WACICommunicationBlockingAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowBlockNumbersUI(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToIterable<NSString, HSTRING>(phoneNumbers).Get()),
                                     &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)showUnblockNumbersUI:(id<NSFastEnumeration> /* NSString * */)phoneNumbers {
    boolean unmarshalledReturn;
    auto _comInst = WACICommunicationBlockingAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowUnblockNumbersUI(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                           ConvertToIterable<NSString, HSTRING>(phoneNumbers).Get()),
                                       &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)showBlockedCallsUI {
    auto _comInst = WACICommunicationBlockingAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowBlockedCallsUI());
}

+ (void)showBlockedMessagesUI {
    auto _comInst = WACICommunicationBlockingAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowBlockedMessagesUI());
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
