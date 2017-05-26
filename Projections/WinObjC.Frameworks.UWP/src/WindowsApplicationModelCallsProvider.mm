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

// WindowsApplicationModelCallsProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Calls.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelCallsProvider.h"
#include "WindowsApplicationModelCallsProvider_priv.h"

@implementation WACPPhoneCallOrigin

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Calls.Provider.PhoneCallOrigin").Get(),
                                              &out));
    return [_createRtProxy<WACPPhoneCallOrigin>(out.Get()) retain];
}

- (NSString*)category {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCategory:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>(self);
    THROW_NS_IF_FAILED(_comInst->put_Category(nsStrToHstr(value).Get()));
}

- (NSString*)categoryDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>(self);
    THROW_NS_IF_FAILED(_comInst->get_CategoryDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCategoryDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>(self);
    THROW_NS_IF_FAILED(_comInst->put_CategoryDescription(nsStrToHstr(value).Get()));
}

- (NSString*)location {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLocation:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>(self);
    THROW_NS_IF_FAILED(_comInst->put_Location(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (WSStorageFile*)displayPicture {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayPicture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

- (void)setDisplayPicture:(WSStorageFile*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin3>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayPicture(_getRtInterface<ABI::Windows::Storage::IStorageFile>(value).Get()));
}

@end

@implementation WACPPhoneCallOriginManager

ComPtr<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics> WACPIPhoneCallOriginManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Calls.Provider.PhoneCallOriginManager").Get(), &inst));
    return inst;
}

+ (BOOL)isCurrentAppActiveCallOriginApp {
    boolean unmarshalledReturn;
    auto _comInst = WACPIPhoneCallOriginManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsCurrentAppActiveCallOriginApp(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)showPhoneCallOriginSettingsUI {
    auto _comInst = WACPIPhoneCallOriginManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowPhoneCallOriginSettingsUI());
}

+ (void)setCallOrigin:(WFGUID*)requestId callOrigin:(WACPPhoneCallOrigin*)callOrigin {
    auto _comInst = WACPIPhoneCallOriginManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetCallOrigin(requestId.guidValue,
                                _getRtInterface<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>(callOrigin).Get()));
}

ComPtr<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2> WACPIPhoneCallOriginManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Calls.Provider.PhoneCallOriginManager").Get(), &inst));
    return inst;
}

+ (void)requestSetAsActiveCallOriginAppAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WACPIPhoneCallOriginManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestSetAsActiveCallOriginAppAsync(&unmarshalledReturn));

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

@end
