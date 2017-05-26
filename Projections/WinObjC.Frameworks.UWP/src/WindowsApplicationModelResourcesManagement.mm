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

// WindowsApplicationModelResourcesManagement.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Resources.Management.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelResourcesManagement.h"
#include "WindowsApplicationModelResourcesManagement_priv.h"

@implementation WARMIndexedResourceCandidate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WARMIndexedResourceType)type {
    ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WARMIndexedResourceType)unmarshalledReturn;
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, NSString * */)metadata {
    ComPtr<IMapView<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Metadata(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* WARMIndexedResourceQualifier* */)qualifiers {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Qualifiers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WARMIndexedResourceQualifier_create(unmarshalledReturn.Get());
}

- (NSString*)valueAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValueAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getQualifierValue:(NSString*)qualifierName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->GetQualifierValue(nsStrToHstr(qualifierName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WARMResourceIndexer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexerFactory> WARMIResourceIndexerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Resources.Management.ResourceIndexer").Get(), &inst));
    return inst;
}

+ (WARMResourceIndexer*)makeResourceIndexer:(WFUri*)projectRoot {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexer> unmarshalledReturn;
    auto _comInst = WARMIResourceIndexerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateResourceIndexer(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(projectRoot).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WARMResourceIndexer>(unmarshalledReturn.Get()) retain];
}

static ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexerFactory2> WARMIResourceIndexerFactory2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexerFactory2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Resources.Management.ResourceIndexer").Get(), &inst));
    return inst;
}

+ (WARMResourceIndexer*)makeResourceIndexerWithExtension:(WFUri*)projectRoot extensionDllPath:(WFUri*)extensionDllPath {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexer> unmarshalledReturn;
    auto _comInst = WARMIResourceIndexerFactory2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateResourceIndexerWithExtension(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(projectRoot).Get(),
                                                     _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(extensionDllPath).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WARMResourceIndexer>(unmarshalledReturn.Get()) retain];
}

- (WARMIndexedResourceCandidate*)indexFilePath:(WFUri*)filePath {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexer>(self);
    THROW_NS_IF_FAILED(_comInst->IndexFilePath(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(filePath).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARMIndexedResourceCandidate>(unmarshalledReturn.Get());
}

- (void)indexFileContentsAsync:(WFUri*)file
                       success:(void (^)(NSArray* /* WARMIndexedResourceCandidate* */))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IResourceIndexer>(self);
    THROW_NS_IF_FAILED(
        _comInst->IndexFileContentsAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WARMIndexedResourceCandidate_create(result.Get()));
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

@implementation WARMIndexedResourceQualifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceQualifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)qualifierName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceQualifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_QualifierName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)qualifierValue {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceQualifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_QualifierValue(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedNSArray_WARMIndexedResourceCandidate_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate*>,
                        RTArrayObj<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceCandidate*,
                                   IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate*>,
                                   WARMIndexedResourceCandidate,
                                   ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WARMIndexedResourceQualifier_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier*>,
                        RTArrayObj<ABI::Windows::ApplicationModel::Resources::Management::IIndexedResourceQualifier*,
                                   IVectorView<ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier*>,
                                   WARMIndexedResourceQualifier,
                                   ABI::Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, HSTRING>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          NSString,
                                          NSString,
                                          IMapView<HSTRING, HSTRING>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
