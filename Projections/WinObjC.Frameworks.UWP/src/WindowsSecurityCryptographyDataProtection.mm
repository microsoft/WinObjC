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

// WindowsSecurityCryptographyDataProtection.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Cryptography.DataProtection.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityCryptographyDataProtection.h"
#include "WindowsSecurityCryptographyDataProtection_priv.h"

@implementation WSCDDataProtectionProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.Cryptography.DataProtection.DataProtectionProvider").Get(), &out));
    return [_createRtProxy<WSCDDataProtectionProvider>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>
WSCDIDataProtectionProviderFactory_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProviderFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Cryptography.DataProtection.DataProtectionProvider").Get(), &inst));
    return inst;
}

+ (WSCDDataProtectionProvider*)makeOverloadExplicit:(NSString*)protectionDescriptor {
    ComPtr<ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProvider> unmarshalledReturn;
    auto _comInst = WSCDIDataProtectionProviderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateOverloadExplicit(nsStrToHstr(protectionDescriptor).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSCDDataProtectionProvider>(unmarshalledReturn.Get()) retain];
}

- (void)protectAsync:(RTObject<WSSIBuffer>*)data success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ProtectAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)unprotectAsync:(RTObject<WSSIBuffer>*)data success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->UnprotectAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)protectStreamAsync:(RTObject<WSSIInputStream>*)src dest:(RTObject<WSSIOutputStream>*)dest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ProtectStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(src).Get(),
                                                    _getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(dest).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)unprotectStreamAsync:(RTObject<WSSIInputStream>*)src dest:(RTObject<WSSIOutputStream>*)dest {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Cryptography::DataProtection::IDataProtectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->UnprotectStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(src).Get(),
                                                      _getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(dest).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end
