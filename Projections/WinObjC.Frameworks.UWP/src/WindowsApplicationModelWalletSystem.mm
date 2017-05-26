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

// WindowsApplicationModelWalletSystem.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Wallet.System.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelWalletSystem.h"
#include "WindowsApplicationModelWalletSystem_priv.h"

@implementation WAWSWalletItemSystemStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getItemsAsyncWithSuccess:(void (^)(NSArray* /* WAWWalletItem* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAWWalletItem_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)deleteAsync:(WAWWalletItem*)item {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(_getRtInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(item).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)importItemAsync:(RTObject<WSSIRandomAccessStreamReference>*)stream
                success:(void (^)(WAWWalletItem*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::WalletItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->ImportItemAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(stream).Get(),
                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Wallet::WalletItem*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::WalletItem*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAWWalletItem>(result.Get()));
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

- (WAWSWalletItemAppAssociation)getAppStatusForItem:(WAWWalletItem*)item {
    ABI::Windows::ApplicationModel::Wallet::System::WalletItemAppAssociation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetAppStatusForItem(_getRtInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(item).Get(),
                                                     &unmarshalledReturn));
    return (WAWSWalletItemAppAssociation)unmarshalledReturn;
}

- (void)launchAppForItemAsync:(WAWWalletItem*)item success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore>(self);
    THROW_NS_IF_FAILED(_comInst->LaunchAppForItemAsync(_getRtInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(item).Get(),
                                                       &unmarshalledReturn));

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

- (EventRegistrationToken)addItemsChangedEvent:(void (^)(WAWSWalletItemSystemStore*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemsChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Wallet_System_WalletItemSystemStore_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemsChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemsChanged(cookie));
}

@end

@implementation WAWSWalletManagerSystem

ComPtr<ABI::Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> WAWSIWalletManagerSystemStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Wallet.System.WalletManagerSystem").Get(), &inst));
    return inst;
}

+ (void)requestStoreAsyncWithSuccess:(void (^)(WAWSWalletItemSystemStore*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::System::WalletItemSystemStore*>>
        unmarshalledReturn;
    auto _comInst = WAWSIWalletManagerSystemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Wallet::System::WalletItemSystemStore*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::System::WalletItemSystemStore*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAWSWalletItemSystemStore>(result.Get()));
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

id RTProxiedNSArray_WAWWalletItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Wallet::IWalletItem*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>,
                                                    WAWWalletItem,
                                                    ABI::Windows::ApplicationModel::Wallet::WalletItem*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
