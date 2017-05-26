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

// WindowsWebAtomPub.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Web.AtomPub.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsWebAtomPub.h"
#include "WindowsWebAtomPub_priv.h"

@implementation WWAResourceCollection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::AtomPub::IResourceCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WWSISyndicationText>*)title {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IResourceCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSISyndicationText>(unmarshalledReturn.Get());
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IResourceCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSArray* /* WWSSyndicationCategory* */)categories {
    ComPtr<IVectorView<ABI::Windows::Web::Syndication::SyndicationCategory*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IResourceCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Categories(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WWSSyndicationCategory_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)accepts {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IResourceCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Accepts(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeName(nsStrToHstr(value).Get()));
}

- (NSString*)nodeNamespace {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeNamespace(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeNamespace:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeNamespace(nsStrToHstr(value).Get()));
}

- (NSString*)nodeValue {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (WFUri*)baseUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_BaseUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setBaseUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_BaseUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSMutableArray* /* WWSSyndicationAttribute* */)attributeExtensions {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationAttribute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributeExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationAttribute_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WWSISyndicationNode>* */)elementExtensions {
    ComPtr<IVector<ABI::Windows::Web::Syndication::ISyndicationNode*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WWSISyndicationNode_create(unmarshalledReturn.Get());
}

- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetXmlDocument((ABI::Windows::Web::Syndication::SyndicationFormat)format, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

@end

@implementation WWAWorkspace

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::AtomPub::IWorkspace> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WWSISyndicationText>*)title {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IWorkspace>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSISyndicationText>(unmarshalledReturn.Get());
}

- (NSArray* /* WWAResourceCollection* */)collections {
    ComPtr<IVectorView<ABI::Windows::Web::AtomPub::ResourceCollection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IWorkspace>(self);
    THROW_NS_IF_FAILED(_comInst->get_Collections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WWAResourceCollection_create(unmarshalledReturn.Get());
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeName(nsStrToHstr(value).Get()));
}

- (NSString*)nodeNamespace {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeNamespace(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeNamespace:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeNamespace(nsStrToHstr(value).Get()));
}

- (NSString*)nodeValue {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (WFUri*)baseUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_BaseUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setBaseUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_BaseUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSMutableArray* /* WWSSyndicationAttribute* */)attributeExtensions {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationAttribute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributeExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationAttribute_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WWSISyndicationNode>* */)elementExtensions {
    ComPtr<IVector<ABI::Windows::Web::Syndication::ISyndicationNode*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WWSISyndicationNode_create(unmarshalledReturn.Get());
}

- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetXmlDocument((ABI::Windows::Web::Syndication::SyndicationFormat)format, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

@end

@implementation WWAServiceDocument

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::AtomPub::IServiceDocument> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WWAWorkspace* */)workspaces {
    ComPtr<IVectorView<ABI::Windows::Web::AtomPub::Workspace*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IServiceDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_Workspaces(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WWAWorkspace_create(unmarshalledReturn.Get());
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeName(nsStrToHstr(value).Get()));
}

- (NSString*)nodeNamespace {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeNamespace(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeNamespace:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeNamespace(nsStrToHstr(value).Get()));
}

- (NSString*)nodeValue {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNodeValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (WFUri*)baseUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_BaseUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setBaseUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_BaseUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSMutableArray* /* WWSSyndicationAttribute* */)attributeExtensions {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationAttribute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttributeExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationAttribute_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WWSISyndicationNode>* */)elementExtensions {
    ComPtr<IVector<ABI::Windows::Web::Syndication::ISyndicationNode*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WWSISyndicationNode_create(unmarshalledReturn.Get());
}

- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetXmlDocument((ABI::Windows::Web::Syndication::SyndicationFormat)format, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

@end

@implementation WWAAtomPubClient

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::AtomPub::IAtomPubClient> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.AtomPub.AtomPubClient").Get(), &out));
    return [_createRtProxy<WWAAtomPubClient>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::AtomPub::IAtomPubClientFactory> WWAIAtomPubClientFactory_inst() {
    ComPtr<ABI::Windows::Web::AtomPub::IAtomPubClientFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.AtomPub.AtomPubClient").Get(), &inst));
    return inst;
}

+ (WWAAtomPubClient*)makeAtomPubClientWithCredentials:(WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Web::AtomPub::IAtomPubClient> unmarshalledReturn;
    auto _comInst = WWAIAtomPubClientFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAtomPubClientWithCredentials(
        _getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(serverCredential).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWAAtomPubClient>(unmarshalledReturn.Get()) retain];
}

- (void)retrieveServiceDocumentAsync:(WFUri*)uri
                             success:(void (^)(WWAServiceDocument*))success
                            progress:(void (^)(WWSRetrievalProgress*))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::AtomPub::ServiceDocument*,
                                                                 ABI::Windows::Web::Syndication::RetrievalProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IAtomPubClient>(self);
    THROW_NS_IF_FAILED(_comInst->RetrieveServiceDocumentAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                              &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::AtomPub::ServiceDocument*,
                                                                     ABI::Windows::Web::Syndication::RetrievalProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::AtomPub::ServiceDocument*,
                                                                               ABI::Windows::Web::Syndication::RetrievalProgress>* op,
                         ABI::Windows::Web::Syndication::RetrievalProgress status) {
                @autoreleasepool {
                    progressRc(WWSRetrievalProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::AtomPub::ServiceDocument*,
                                                                              ABI::Windows::Web::Syndication::RetrievalProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::AtomPub::ServiceDocument*,
                                                                                     ABI::Windows::Web::Syndication::RetrievalProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::AtomPub::IServiceDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWAServiceDocument>(result.Get()));
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

- (void)retrieveMediaResourceAsync:(WFUri*)uri
                           success:(void (^)(RTObject<WSSIInputStream>*))success
                          progress:(void (^)(WWSRetrievalProgress*))progress
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*,
                                                                 ABI::Windows::Web::Syndication::RetrievalProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IAtomPubClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->RetrieveMediaResourceAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*,
                                                                     ABI::Windows::Web::Syndication::RetrievalProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*,
                                                                               ABI::Windows::Web::Syndication::RetrievalProgress>* op,
                         ABI::Windows::Web::Syndication::RetrievalProgress status) {
                @autoreleasepool {
                    progressRc(WWSRetrievalProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*,
                                                                              ABI::Windows::Web::Syndication::RetrievalProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*,
                                                                                     ABI::Windows::Web::Syndication::RetrievalProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)retrieveResourceAsync:(WFUri*)uri
                      success:(void (^)(WWSSyndicationItem*))success
                     progress:(void (^)(WWSRetrievalProgress*))progress
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                 ABI::Windows::Web::Syndication::RetrievalProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IAtomPubClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->RetrieveResourceAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                     ABI::Windows::Web::Syndication::RetrievalProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                               ABI::Windows::Web::Syndication::RetrievalProgress>* op,
                         ABI::Windows::Web::Syndication::RetrievalProgress status) {
                @autoreleasepool {
                    progressRc(WWSRetrievalProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                              ABI::Windows::Web::Syndication::RetrievalProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                                     ABI::Windows::Web::Syndication::RetrievalProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Syndication::ISyndicationItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWSSyndicationItem>(result.Get()));
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

- (void)createResourceAsync:(WFUri*)uri
                description:(NSString*)description
                       item:(WWSSyndicationItem*)item
                    success:(void (^)(WWSSyndicationItem*))success
                   progress:(void (^)(WWSTransferProgress*))progress
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                 ABI::Windows::Web::Syndication::TransferProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IAtomPubClient>(self);
    THROW_NS_IF_FAILED(_comInst->CreateResourceAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                     nsStrToHstr(description).Get(),
                                                     _getRtInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(item).Get(),
                                                     &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                     ABI::Windows::Web::Syndication::TransferProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                               ABI::Windows::Web::Syndication::TransferProgress>* op,
                         ABI::Windows::Web::Syndication::TransferProgress status) {
                @autoreleasepool {
                    progressRc(WWSTransferProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                              ABI::Windows::Web::Syndication::TransferProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                                     ABI::Windows::Web::Syndication::TransferProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Syndication::ISyndicationItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWSSyndicationItem>(result.Get()));
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

- (void)createMediaResourceAsync:(WFUri*)uri
                       mediaType:(NSString*)mediaType
                     description:(NSString*)description
                     mediaStream:(RTObject<WSSIInputStream>*)mediaStream
                         success:(void (^)(WWSSyndicationItem*))success
                        progress:(void (^)(WWSTransferProgress*))progress
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                 ABI::Windows::Web::Syndication::TransferProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IAtomPubClient>(self);
    THROW_NS_IF_FAILED(_comInst->CreateMediaResourceAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                          nsStrToHstr(mediaType).Get(),
                                                          nsStrToHstr(description).Get(),
                                                          _getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(mediaStream).Get(),
                                                          &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                     ABI::Windows::Web::Syndication::TransferProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                               ABI::Windows::Web::Syndication::TransferProgress>* op,
                         ABI::Windows::Web::Syndication::TransferProgress status) {
                @autoreleasepool {
                    progressRc(WWSTransferProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                              ABI::Windows::Web::Syndication::TransferProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                                     ABI::Windows::Web::Syndication::TransferProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Syndication::ISyndicationItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWSSyndicationItem>(result.Get()));
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

// Failed to generate member UpdateMediaResourceAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
// Failed to generate member UpdateResourceAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
// Failed to generate member UpdateResourceItemAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
// Failed to generate member DeleteResourceAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
// Failed to generate member DeleteResourceItemAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
- (void)cancelAsyncOperations {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::AtomPub::IAtomPubClient>(self);
    THROW_NS_IF_FAILED(_comInst->CancelAsyncOperations());
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (unsigned int)maxResponseBufferSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxResponseBufferSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxResponseBufferSize:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxResponseBufferSize(value));
}

- (unsigned int)timeout {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timeout(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTimeout:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->put_Timeout(value));
}

- (BOOL)bypassCacheOnRetrieve {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->get_BypassCacheOnRetrieve(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBypassCacheOnRetrieve:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->put_BypassCacheOnRetrieve((boolean)value));
}

- (void)setRequestHeader:(NSString*)name value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(_comInst->SetRequestHeader(nsStrToHstr(name).Get(), nsStrToHstr(value).Get()));
}

- (void)retrieveFeedAsync:(WFUri*)uri
                  success:(void (^)(WWSSyndicationFeed*))success
                 progress:(void (^)(WWSRetrievalProgress*))progress
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationFeed*,
                                                                 ABI::Windows::Web::Syndication::RetrievalProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->RetrieveFeedAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Syndication::SyndicationFeed*,
                                                                     ABI::Windows::Web::Syndication::RetrievalProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationFeed*,
                                                                               ABI::Windows::Web::Syndication::RetrievalProgress>* op,
                         ABI::Windows::Web::Syndication::RetrievalProgress status) {
                @autoreleasepool {
                    progressRc(WWSRetrievalProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Syndication::SyndicationFeed*,
                                                                              ABI::Windows::Web::Syndication::RetrievalProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Syndication::SyndicationFeed*,
                                                                                     ABI::Windows::Web::Syndication::RetrievalProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Syndication::ISyndicationFeed> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWSSyndicationFeed>(result.Get()));
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

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WWAResourceCollection_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Web::AtomPub::ResourceCollection*>,
                                         RTArrayObj<ABI::Windows::Web::AtomPub::IResourceCollection*,
                                                    IVectorView<ABI::Windows::Web::AtomPub::ResourceCollection*>,
                                                    WWAResourceCollection,
                                                    ABI::Windows::Web::AtomPub::ResourceCollection*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WWAWorkspace_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Web::AtomPub::Workspace*>,
                                                                             RTArrayObj<ABI::Windows::Web::AtomPub::IWorkspace*,
                                                                                        IVectorView<ABI::Windows::Web::AtomPub::Workspace*>,
                                                                                        WWAWorkspace,
                                                                                        ABI::Windows::Web::AtomPub::Workspace*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WWSSyndicationCategory_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Web::Syndication::SyndicationCategory*>,
                                         RTArrayObj<ABI::Windows::Web::Syndication::ISyndicationCategory*,
                                                    IVectorView<ABI::Windows::Web::Syndication::SyndicationCategory*>,
                                                    WWSSyndicationCategory,
                                                    ABI::Windows::Web::Syndication::SyndicationCategory*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WWSISyndicationNode_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Web::Syndication::ISyndicationNode*>,
                                                RTMutableArrayObj<ABI::Windows::Web::Syndication::ISyndicationNode*,
                                                                  IVector<ABI::Windows::Web::Syndication::ISyndicationNode*>,
                                                                  RTObject<WWSISyndicationNode>,
                                                                  ABI::Windows::Web::Syndication::ISyndicationNode*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WWSSyndicationAttribute_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Web::Syndication::SyndicationAttribute*>,
                                                RTMutableArrayObj<ABI::Windows::Web::Syndication::ISyndicationAttribute*,
                                                                  IVector<ABI::Windows::Web::Syndication::SyndicationAttribute*>,
                                                                  WWSSyndicationAttribute,
                                                                  ABI::Windows::Web::Syndication::SyndicationAttribute*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
