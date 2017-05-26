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

// WindowsApplicationModelStoreLicenseManagement.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Store.LicenseManagement.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelStoreLicenseManagement.h"
#include "WindowsApplicationModelStoreLicenseManagement_priv.h"

@implementation WASLLicenseSatisfactionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)satisfiedByDevice {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SatisfiedByDevice(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)satisfiedByOpenLicense {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SatisfiedByOpenLicense(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)satisfiedByTrial {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SatisfiedByTrial(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)satisfiedByPass {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SatisfiedByPass(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)satisfiedByInstallMedia {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SatisfiedByInstallMedia(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)satisfiedBySignedInUser {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SatisfiedBySignedInUser(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isSatisfied {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSatisfied(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WASLLicenseSatisfactionResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSDictionary* /* NSString *, WASLLicenseSatisfactionInfo* */)licenseSatisfactionInfos {
    ComPtr<IMapView<HSTRING, ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_LicenseSatisfactionInfos(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WASLLicenseSatisfactionInfo_create(unmarshalledReturn.Get());
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WASLLicenseManager

ComPtr<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics> WASLILicenseManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Store.LicenseManagement.LicenseManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)addLicenseAsync:(RTObject<WSSIBuffer>*)license {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WASLILicenseManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AddLicenseAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(license).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)getSatisfactionInfosAsync:(id<NSFastEnumeration> /* NSString * */)contentIds
                           keyIds:(id<NSFastEnumeration> /* NSString * */)keyIds
                          success:(void (^)(WASLLicenseSatisfactionResult*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult*>>
        unmarshalledReturn;
    auto _comInst = WASLILicenseManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSatisfactionInfosAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(contentIds).Get()),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(keyIds).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASLLicenseSatisfactionResult>(result.Get()));
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

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WASLLicenseSatisfactionInfo_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING,
                                   HSTRING,
                                   NSString,
                                   ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo*,
                     ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo*,
                     NSString,
                     WASLLicenseSatisfactionInfo,
                     IMapView<HSTRING, ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
