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

// WindowsMediaContentRestrictions.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.ContentRestrictions.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaContentRestrictions.h"
#include "WindowsMediaContentRestrictions_priv.h"

@implementation WMCRatedContentDescription

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::ContentRestrictions::IRatedContentDescriptionFactory> WMCIRatedContentDescriptionFactory_inst() {
    ComPtr<ABI::Windows::Media::ContentRestrictions::IRatedContentDescriptionFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.ContentRestrictions.RatedContentDescription").Get(), &inst));
    return inst;
}

+ (WMCRatedContentDescription*)make:(NSString*)id title:(NSString*)title category:(WMCRatedContentCategory)category {
    ComPtr<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription> unmarshalledReturn;
    auto _comInst = WMCIRatedContentDescriptionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(id).Get(),
                                        nsStrToHstr(title).Get(),
                                        (ABI::Windows::Media::ContentRestrictions::RatedContentCategory)category,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMCRatedContentDescription>(unmarshalledReturn.Get()) retain];
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)image {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Image(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setImage:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->put_Image(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (WMCRatedContentCategory)category {
    ABI::Windows::Media::ContentRestrictions::RatedContentCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return (WMCRatedContentCategory)unmarshalledReturn;
}

- (void)setCategory:(WMCRatedContentCategory)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->put_Category((ABI::Windows::Media::ContentRestrictions::RatedContentCategory)value));
}

- (NSMutableArray* /* NSString * */)ratings {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Ratings(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (void)setRatings:(NSMutableArray* /* NSString * */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Ratings(static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToVector<NSString, HSTRING>(value).Get())));
}

@end

@implementation WMCContentRestrictionsBrowsePolicy

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)geographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* unsigned int */)maxBrowsableAgeRating {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxBrowsableAgeRating(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)preferredAgeRating {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredAgeRating(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

@end

@implementation WMCRatedContentRestrictions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.ContentRestrictions.RatedContentRestrictions").Get(),
                                              &out));
    return [_createRtProxy<WMCRatedContentRestrictions>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictionsFactory> WMCIRatedContentRestrictionsFactory_inst() {
    ComPtr<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictionsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.ContentRestrictions.RatedContentRestrictions").Get(), &inst));
    return inst;
}

+ (WMCRatedContentRestrictions*)makeWithMaxAgeRating:(unsigned int)maxAgeRating {
    ComPtr<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictions> unmarshalledReturn;
    auto _comInst = WMCIRatedContentRestrictionsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithMaxAgeRating(maxAgeRating, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMCRatedContentRestrictions>(unmarshalledReturn.Get()) retain];
}

- (void)getBrowsePolicyAsyncWithSuccess:(void (^)(WMCContentRestrictionsBrowsePolicy*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictions>(self);
    THROW_NS_IF_FAILED(_comInst->GetBrowsePolicyAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCContentRestrictionsBrowsePolicy>(result.Get()));
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

- (void)getRestrictionLevelAsync:(WMCRatedContentDescription*)RatedContentDescription
                         success:(void (^)(WMCContentAccessRestrictionLevel))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictions>(self);
    THROW_NS_IF_FAILED(_comInst->GetRestrictionLevelAsync(
        _getRtInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(RatedContentDescription).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMCContentAccessRestrictionLevel)result);
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

- (void)requestContentAccessAsync:(WMCRatedContentDescription*)RatedContentDescription
                          success:(void (^)(BOOL))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictions>(self);
    THROW_NS_IF_FAILED(_comInst->RequestContentAccessAsync(
        _getRtInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentDescription>(RatedContentDescription).Get(),
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

- (EventRegistrationToken)addRestrictionsChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictions>(self);
    THROW_NS_IF_FAILED(_comInst->add_RestrictionsChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRestrictionsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ContentRestrictions::IRatedContentRestrictions>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RestrictionsChanged(token));
}

@end

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
