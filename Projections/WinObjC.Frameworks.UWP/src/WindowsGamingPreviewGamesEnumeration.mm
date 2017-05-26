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

// WindowsGamingPreviewGamesEnumeration.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Gaming.Preview.GamesEnumeration.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGamingPreviewGamesEnumeration.h"
#include "WindowsGamingPreviewGamesEnumeration_priv.h"

@implementation WGPGIGameListEntry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAppDisplayInfo*)displayInfo {
    ComPtr<ABI::Windows::ApplicationModel::IAppDisplayInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAppDisplayInfo>(unmarshalledReturn.Get());
}

- (void)launchAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->LaunchAsync(&unmarshalledReturn));

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

- (WGPGGameListCategory)category {
    ABI::Windows::Gaming::Preview::GamesEnumeration::GameListCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return (WGPGGameListCategory)unmarshalledReturn;
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setCategoryAsync:(WGPGGameListCategory)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->SetCategoryAsync((ABI::Windows::Gaming::Preview::GamesEnumeration::GameListCategory)value,
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WGPGGameListEntry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAppDisplayInfo*)displayInfo {
    ComPtr<ABI::Windows::ApplicationModel::IAppDisplayInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAppDisplayInfo>(unmarshalledReturn.Get());
}

- (void)launchAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->LaunchAsync(&unmarshalledReturn));

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

- (WGPGGameListCategory)category {
    ABI::Windows::Gaming::Preview::GamesEnumeration::GameListCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return (WGPGGameListCategory)unmarshalledReturn;
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setCategoryAsync:(WGPGGameListCategory)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->SetCategoryAsync((ABI::Windows::Gaming::Preview::GamesEnumeration::GameListCategory)value,
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WGPGGameList

ComPtr<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics> WGPGIGameListStatics_inst() {
    ComPtr<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Gaming.Preview.GamesEnumeration.GameList").Get(),
                                                       &inst));
    return inst;
}

+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WGPGGameListEntry* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>*>>
        unmarshalledReturn;
    auto _comInst = WGPGIGameListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WGPGGameListEntry_create(result.Get()));
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

+ (void)findAllAsyncPackageFamilyName:(NSString*)packageFamilyName
                              success:(void (^)(NSArray* /* WGPGGameListEntry* */))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>*>>
        unmarshalledReturn;
    auto _comInst = WGPGIGameListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsyncPackageFamilyName(nsStrToHstr(packageFamilyName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WGPGGameListEntry_create(result.Get()));
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

+ (EventRegistrationToken)addGameAddedEvent:(WGPGGameListChangedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGPGIGameListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_GameAdded(Make<WGPGGameListChangedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeGameAddedEvent:(EventRegistrationToken)token {
    auto _comInst = WGPGIGameListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_GameAdded(token));
}

+ (EventRegistrationToken)addGameRemovedEvent:(WGPGGameListRemovedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGPGIGameListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_GameRemoved(Make<WGPGGameListRemovedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeGameRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = WGPGIGameListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_GameRemoved(token));
}

+ (EventRegistrationToken)addGameUpdatedEvent:(WGPGGameListChangedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGPGIGameListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_GameUpdated(Make<WGPGGameListChangedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeGameUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = WGPGIGameListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_GameUpdated(token));
}

@end

id RTProxiedNSArray_WGPGGameListEntry_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>,
                                         RTArrayObj<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry*,
                                                    IVectorView<ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*>,
                                                    WGPGGameListEntry,
                                                    ABI::Windows::Gaming::Preview::GamesEnumeration::GameListEntry*,
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
