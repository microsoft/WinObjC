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

// WindowsApplicationModelDataTransfer.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.DataTransfer.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsApplicationModelDataTransfer_priv.h"

@implementation WADStandardDataFormats

ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics> WADIStandardDataFormatsStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.StandardDataFormats").Get(), &inst));
    return inst;
}

+ (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIStandardDataFormatsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)uri {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIStandardDataFormatsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Uri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)html {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIStandardDataFormatsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Html(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rtf {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIStandardDataFormatsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rtf(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bitmap {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIStandardDataFormatsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bitmap(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)storageItems {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIStandardDataFormatsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StorageItems(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2> WADIStandardDataFormatsStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.StandardDataFormats").Get(), &inst));
    return inst;
}

+ (NSString*)webLink {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIStandardDataFormatsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_WebLink(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)applicationLink {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIStandardDataFormatsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ApplicationLink(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WADDataPackagePropertySetView {
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
                 dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAPVIEW(
    self.comObj, RTProxiedNSDictionary_NSString_RTObject, HSTRING, HSTRING, IInspectable*, IInspectable*, NSString, RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSSRandomAccessStreamReference*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)fileTypes {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)applicationName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)applicationListingUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationListingUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)packageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)contentSourceWebLink {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentSourceWebLink(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WFUri*)contentSourceApplicationLink {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentSourceApplicationLink(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStreamReference>*)square30x30Logo {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Square30x30Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (WUColor*)logoBackgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogoBackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (NSString*)enterpriseId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView3>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnterpriseId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WADDataPackagePropertySet {
    RTMapObj<HSTRING,
             HSTRING,
             IInspectable*,
             IInspectable*,
             NSString,
             RTObject,
             IMap<HSTRING, IInspectable*>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(
    self.comObj, RTProxiedNSMutableDictionary_NSString_RTObject, HSTRING, HSTRING, IInspectable*, IInspectable*, NSString, RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (NSMutableArray* /* NSString * */)fileTypes {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)applicationName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setApplicationName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->put_ApplicationName(nsStrToHstr(value).Get()));
}

- (WFUri*)applicationListingUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationListingUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setApplicationListingUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->put_ApplicationListingUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)contentSourceWebLink {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentSourceWebLink(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setContentSourceWebLink:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentSourceWebLink(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)contentSourceApplicationLink {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentSourceApplicationLink(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setContentSourceApplicationLink:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ContentSourceApplicationLink(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)packageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPackageFamilyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PackageFamilyName(nsStrToHstr(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)square30x30Logo {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Square30x30Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setSquare30x30Logo:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Square30x30Logo(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (WUColor*)logoBackgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogoBackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setLogoBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LogoBackgroundColor(*[value internalStruct]));
}

- (NSString*)enterpriseId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet3>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnterpriseId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setEnterpriseId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet3>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnterpriseId(nsStrToHstr(value).Get()));
}

@end

@implementation WADDataProviderDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataProviderDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataProviderDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WADDataProviderRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataProviderRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)formatId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataProviderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormatId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataProviderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WADDataProviderDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataProviderDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataProviderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataProviderDeferral>(unmarshalledReturn.Get());
}

- (void)setData:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataProviderRequest>(self);
    THROW_NS_IF_FAILED(_comInst->SetData([value comObj].Get()));
}

@end

@implementation WADOperationCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADDataPackageOperation)operation {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Operation(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

- (NSString*)acceptedFormatId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AcceptedFormatId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WADDataPackageView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADDataPackagePropertySetView*)properties {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySetView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackagePropertySetView>(unmarshalledReturn.Get());
}

- (WADDataPackageOperation)requestedOperation {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedOperation(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

- (void)reportOperationCompleted:(WADDataPackageOperation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->ReportOperationCompleted((ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation)value));
}

- (NSArray* /* NSString * */)availableFormats {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->get_AvailableFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (BOOL)contains:(NSString*)formatId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->Contains(nsStrToHstr(formatId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)getDataAsync:(NSString*)formatId success:(void (^)(RTObject*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetDataAsync(nsStrToHstr(formatId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IInspectable*>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IInspectable*>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        ComPtr<IInspectable> result;
                        HRESULT hr = op->GetResults(result.GetAddressOf());
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_createBareRTObj(result.Get()));
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

- (void)getTextAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetTextAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

- (void)getCustomTextAsync:(NSString*)formatId success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetCustomTextAsync(nsStrToHstr(formatId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

- (void)getUriAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetUriAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Foundation::Uri*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Uri*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WFUri>(result.Get()));
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

- (void)getHtmlFormatAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetHtmlFormatAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

- (void)getResourceMapAsyncWithSuccess:(void (^)(NSDictionary* /* NSString *, WSSRandomAccessStreamReference* */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMapView<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetResourceMapAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IMapView<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<IMapView<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IMapView<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSDictionary_NSString_WSSRandomAccessStreamReference_create(result.Get()));
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

- (void)getRtfAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetRtfAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

- (void)getBitmapAsyncWithSuccess:(void (^)(WSSRandomAccessStreamReference*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetBitmapAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSRandomAccessStreamReference>(result.Get()));
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

- (void)getStorageItemsAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView>(self);
    THROW_NS_IF_FAILED(_comInst->GetStorageItemsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::IStorageItem*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::IStorageItem*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_RTObject_WSIStorageItem_create(result.Get()));
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

- (void)getApplicationLinkAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView2>(self);
    THROW_NS_IF_FAILED(_comInst->GetApplicationLinkAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Foundation::Uri*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Uri*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WFUri>(result.Get()));
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

- (void)getWebLinkAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView2>(self);
    THROW_NS_IF_FAILED(_comInst->GetWebLinkAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Foundation::Uri*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Uri*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WFUri>(result.Get()));
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

- (void)requestAccessAsyncWithSuccess:(void (^)(WSEProtectionPolicyEvaluationResult))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView3>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEProtectionPolicyEvaluationResult)result);
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

- (void)requestAccessWithEnterpriseIdAsync:(NSString*)enterpriseId
                                   success:(void (^)(WSEProtectionPolicyEvaluationResult))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView3>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAccessWithEnterpriseIdAsync(nsStrToHstr(enterpriseId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEProtectionPolicyEvaluationResult)result);
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

- (WSEProtectionPolicyEvaluationResult)unlockAndAssumeEnterpriseIdentity {
    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView3>(self);
    THROW_NS_IF_FAILED(_comInst->UnlockAndAssumeEnterpriseIdentity(&unmarshalledReturn));
    return (WSEProtectionPolicyEvaluationResult)unmarshalledReturn;
}

- (void)setAcceptedFormatId:(NSString*)formatId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView4>(self);
    THROW_NS_IF_FAILED(_comInst->SetAcceptedFormatId(nsStrToHstr(formatId).Get()));
}

@end

@implementation WADDataPackage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.DataPackage").Get(), &out));
    return [_createRtProxy<WADDataPackage>(out.Get()) retain];
}

- (WADDataPackageView*)getView {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->GetView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackageView>(unmarshalledReturn.Get());
}

- (WADDataPackagePropertySet*)properties {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackagePropertySet>(unmarshalledReturn.Get());
}

- (WADDataPackageOperation)requestedOperation {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedOperation(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

- (void)setRequestedOperation:(WADDataPackageOperation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequestedOperation((ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation)value));
}

- (EventRegistrationToken)addOperationCompletedEvent:(void (^)(WADDataPackage*, WADOperationCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->add_OperationCompleted(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_Windows_ApplicationModel_DataTransfer_OperationCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOperationCompletedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OperationCompleted(eventCookie));
}

- (EventRegistrationToken)addDestroyedEvent:(void (^)(WADDataPackage*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Destroyed(Make<ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_System_Object>(handler).Get(),
                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDestroyedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Destroyed(eventCookie));
}

- (void)setData:(NSString*)formatId value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetData(nsStrToHstr(formatId).Get(), [value comObj].Get()));
}

- (void)setDataProvider:(NSString*)formatId delayRenderer:(WADDataProviderHandler)delayRenderer {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetDataProvider(nsStrToHstr(formatId).Get(), Make<WADDataProviderHandler_shim>(delayRenderer).Get()));
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetText(nsStrToHstr(value).Get()));
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (void)setHtmlFormat:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetHtmlFormat(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, WSSRandomAccessStreamReference* */)resourceMap {
    ComPtr<IMap<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceMap(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_WSSRandomAccessStreamReference_create(unmarshalledReturn.Get());
}

- (void)setRtf:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetRtf(nsStrToHstr(value).Get()));
}

- (void)setBitmap:(WSSRandomAccessStreamReference*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetBitmap(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (void)setStorageItemsReadOnly:(id<NSFastEnumeration> /* RTObject<WSIStorageItem>* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetStorageItemsReadOnly(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::IStorageItem*,
                                                              ABI::Windows::Storage::IStorageItem*>>::type>*>(
            ConvertToIterable<RTObject<WSIStorageItem>,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::IStorageItem*,
                                                                                ABI::Windows::Storage::IStorageItem*>>(value)
                .Get())));
}

- (void)setStorageItems:(id<NSFastEnumeration> /* RTObject<WSIStorageItem>* */)value readOnly:(BOOL)readOnly {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SetStorageItems(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::IStorageItem*,
                                                              ABI::Windows::Storage::IStorageItem*>>::type>*>(
            ConvertToIterable<RTObject<WSIStorageItem>,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::IStorageItem*,
                                                                                ABI::Windows::Storage::IStorageItem*>>(value)
                .Get()),
        (boolean)readOnly));
}

- (void)setApplicationLink:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->SetApplicationLink(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (void)setWebLink:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->SetWebLink(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WADHtmlFormatHelper

ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics> WADIHtmlFormatHelperStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.HtmlFormatHelper").Get(), &inst));
    return inst;
}

+ (NSString*)getStaticFragment:(NSString*)htmlFormat {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIHtmlFormatHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetStaticFragment(nsStrToHstr(htmlFormat).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)createHtmlFormat:(NSString*)htmlFragment {
    HSTRING unmarshalledReturn;
    auto _comInst = WADIHtmlFormatHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateHtmlFormat(nsStrToHstr(htmlFragment).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WADClipboard

ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IClipboardStatics> WADIClipboardStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IClipboardStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.Clipboard").Get(),
                                                       &inst));
    return inst;
}

+ (WADDataPackageView*)getContent {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView> unmarshalledReturn;
    auto _comInst = WADIClipboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetContent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackageView>(unmarshalledReturn.Get());
}

+ (void)setContent:(WADDataPackage*)content {
    auto _comInst = WADIClipboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetContent(_getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(content).Get()));
}

+ (void)flush {
    auto _comInst = WADIClipboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Flush());
}

+ (void)clear {
    auto _comInst = WADIClipboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Clear());
}

+ (EventRegistrationToken)addContentChangedEvent:(void (^)(RTObject*, RTObject*))changeHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WADIClipboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_ContentChanged(Make<EventHandler_System_Object>(changeHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeContentChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WADIClipboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ContentChanged(token));
}

@end

@implementation WADDataRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WADDataRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADDataPackage*)data {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackage>(unmarshalledReturn.Get());
}

- (void)setData:(WADDataPackage*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(value).Get()));
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)failWithDisplayText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataRequest>(self);
    THROW_NS_IF_FAILED(_comInst->FailWithDisplayText(nsStrToHstr(value).Get()));
}

- (WADDataRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataRequestDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WADDataRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADDataRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataRequest>(unmarshalledReturn.Get());
}

@end

@implementation WADTargetApplicationChosenEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)applicationName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WADDataTransferManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics> WADIDataTransferManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.DataTransferManager").Get(), &inst));
    return inst;
}

+ (void)showShareUI {
    auto _comInst = WADIDataTransferManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowShareUI());
}

+ (WADDataTransferManager*)getForCurrentView {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager> unmarshalledReturn;
    auto _comInst = WADIDataTransferManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataTransferManager>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics2> WADIDataTransferManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.DataTransferManager").Get(), &inst));
    return inst;
}

+ (BOOL)isSupported {
    boolean unmarshalledReturn;
    auto _comInst = WADIDataTransferManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addDataRequestedEvent:(void (^)(WADDataTransferManager*, WADDataRequestedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_DataRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_DataRequestedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDataRequestedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DataRequested(eventCookie));
}

- (EventRegistrationToken)addTargetApplicationChosenEvent:(void (^)(WADDataTransferManager*,
                                                                    WADTargetApplicationChosenEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_TargetApplicationChosen(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_TargetApplicationChosenEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTargetApplicationChosenEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TargetApplicationChosen(eventCookie));
}

@end

@implementation WADSharedStorageAccessManager

ComPtr<ABI::Windows::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics> WADISharedStorageAccessManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.SharedStorageAccessManager").Get(), &inst));
    return inst;
}

+ (NSString*)addFile:(RTObject<WSIStorageFile>*)file {
    HSTRING unmarshalledReturn;
    auto _comInst = WADISharedStorageAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AddFile(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)redeemTokenForFileAsync:(NSString*)token success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WADISharedStorageAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RedeemTokenForFileAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
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

+ (void)removeFile:(NSString*)token {
    auto _comInst = WADISharedStorageAccessManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RemoveFile(nsStrToHstr(token).Get()));
}

@end

id RTProxiedIterableNSArray_RTObject_WSIStorageItem_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Storage::IStorageItem*>,
                                                 RTIterableObj<ABI::Windows::Storage::IStorageItem*,
                                                               IIterable<ABI::Windows::Storage::IStorageItem*>,
                                                               RTObject<WSIStorageItem>,
                                                               ABI::Windows::Storage::IStorageItem*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::IStorageItem*>,
                                                                             RTArrayObj<ABI::Windows::Storage::IStorageItem*,
                                                                                        IVectorView<ABI::Windows::Storage::IStorageItem*>,
                                                                                        RTObject<WSIStorageItem>,
                                                                                        ABI::Windows::Storage::IStorageItem*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WSSRandomAccessStreamReference_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::Storage::Streams::RandomAccessStreamReference*,
                     ABI::Windows::Storage::Streams::IRandomAccessStreamReference*,
                     NSString,
                     WSSRandomAccessStreamReference,
                     IMapView<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_WSSRandomAccessStreamReference_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>>,
        RTMapObj<HSTRING,
                 HSTRING,
                 ABI::Windows::Storage::Streams::RandomAccessStreamReference*,
                 ABI::Windows::Storage::Streams::IRandomAccessStreamReference*,
                 NSString,
                 WSSRandomAccessStreamReference,
                 IMap<HSTRING, ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
