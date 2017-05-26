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

// WindowsWebSyndication.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Web.Syndication.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsWebSyndication.h"
#include "WindowsWebSyndication_priv.h"

@implementation WWSISyndicationNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@implementation WWSISyndicationText

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type(nsStrToHstr(value).Get()));
}

- (WDXDXmlDocument*)xml {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Xml(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (void)setXml:(WDXDXmlDocument*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Xml(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(value).Get()));
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

@implementation WWSISyndicationClient

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationClient> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@implementation WWSSyndicationAttribute

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationAttribute> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationAttributeFactory> WWSISyndicationAttributeFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationAttributeFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationAttribute").Get(),
                                                       &inst));
    return inst;
}

+ (WWSSyndicationAttribute*)makeSyndicationAttribute:(NSString*)attributeName
                                  attributeNamespace:(NSString*)attributeNamespace
                                      attributeValue:(NSString*)attributeValue {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationAttribute> unmarshalledReturn;
    auto _comInst = WWSISyndicationAttributeFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationAttribute(nsStrToHstr(attributeName).Get(),
                                                            nsStrToHstr(attributeNamespace).Get(),
                                                            nsStrToHstr(attributeValue).Get(),
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationAttribute>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationAttribute").Get(), &out));
    return [_createRtProxy<WWSSyndicationAttribute>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)Namespace {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Namespace(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNamespace:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->put_Namespace(nsStrToHstr(value).Get()));
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(nsStrToHstr(value).Get()));
}

@end

@implementation WWSSyndicationNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationNode").Get(), &out));
    return [_createRtProxy<WWSSyndicationNode>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationNodeFactory> WWSISyndicationNodeFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationNodeFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationNode").Get(), &inst));
    return inst;
}

+ (WWSSyndicationNode*)makeSyndicationNode:(NSString*)nodeName nodeNamespace:(NSString*)nodeNamespace nodeValue:(NSString*)nodeValue {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationNode> unmarshalledReturn;
    auto _comInst = WWSISyndicationNodeFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationNode(nsStrToHstr(nodeName).Get(),
                                                       nsStrToHstr(nodeNamespace).Get(),
                                                       nsStrToHstr(nodeValue).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationNode>(unmarshalledReturn.Get()) retain];
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

@implementation WWSSyndicationGenerator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationGenerator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationGeneratorFactory> WWSISyndicationGeneratorFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationGeneratorFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationGenerator").Get(),
                                                       &inst));
    return inst;
}

+ (WWSSyndicationGenerator*)makeSyndicationGenerator:(NSString*)text {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationGenerator> unmarshalledReturn;
    auto _comInst = WWSISyndicationGeneratorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationGenerator(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationGenerator>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationGenerator").Get(), &out));
    return [_createRtProxy<WWSSyndicationGenerator>(out.Get()) retain];
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)Version {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_Version(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)SetVersion:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->put_Version(nsStrToHstr(value).Get()));
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

@implementation WWSSyndicationText

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationText").Get(), &out));
    return [_createRtProxy<WWSSyndicationText>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationTextFactory> WWSISyndicationTextFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationTextFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationText").Get(), &inst));
    return inst;
}

+ (WWSSyndicationText*)makeSyndicationText:(NSString*)text {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = WWSISyndicationTextFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationText(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationText>(unmarshalledReturn.Get()) retain];
}

+ (WWSSyndicationText*)makeSyndicationTextEx:(NSString*)text type:(WWSSyndicationTextType)type {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = WWSISyndicationTextFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationTextEx(nsStrToHstr(text).Get(),
                                                         (ABI::Windows::Web::Syndication::SyndicationTextType)type,
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationText>(unmarshalledReturn.Get()) retain];
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type(nsStrToHstr(value).Get()));
}

- (WDXDXmlDocument*)xml {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Xml(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (void)setXml:(WDXDXmlDocument*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Xml(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(value).Get()));
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

@implementation WWSSyndicationContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationContentFactory> WWSISyndicationContentFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationContentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationContent").Get(), &inst));
    return inst;
}

+ (WWSSyndicationContent*)makeSyndicationContent:(NSString*)text type:(WWSSyndicationTextType)type {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationContent> unmarshalledReturn;
    auto _comInst = WWSISyndicationContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationContent(nsStrToHstr(text).Get(),
                                                          (ABI::Windows::Web::Syndication::SyndicationTextType)type,
                                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationContent>(unmarshalledReturn.Get()) retain];
}

+ (WWSSyndicationContent*)makeSyndicationContentWithSourceUri:(WFUri*)sourceUri {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationContent> unmarshalledReturn;
    auto _comInst = WWSISyndicationContentFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateSyndicationContentWithSourceUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(sourceUri).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationContent>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationContent").Get(), &out));
    return [_createRtProxy<WWSSyndicationContent>(out.Get()) retain];
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type(nsStrToHstr(value).Get()));
}

- (WDXDXmlDocument*)xml {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->get_Xml(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (void)setXml:(WDXDXmlDocument*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationText>(self);
    THROW_NS_IF_FAILED(_comInst->put_Xml(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(value).Get()));
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

- (WFUri*)sourceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setSourceUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_SourceUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WWSSyndicationLink

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationLink> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationLink").Get(), &out));
    return [_createRtProxy<WWSSyndicationLink>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationLinkFactory> WWSISyndicationLinkFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationLinkFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationLink").Get(), &inst));
    return inst;
}

+ (WWSSyndicationLink*)makeSyndicationLink:(WFUri*)uri {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationLink> unmarshalledReturn;
    auto _comInst = WWSISyndicationLinkFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationLink(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationLink>(unmarshalledReturn.Get()) retain];
}

+ (WWSSyndicationLink*)makeSyndicationLinkEx:(WFUri*)uri
                                relationship:(NSString*)relationship
                                       title:(NSString*)title
                                   mediaType:(NSString*)mediaType
                                      length:(unsigned int)length {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationLink> unmarshalledReturn;
    auto _comInst = WWSISyndicationLinkFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationLinkEx(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                         nsStrToHstr(relationship).Get(),
                                                         nsStrToHstr(title).Get(),
                                                         nsStrToHstr(mediaType).Get(),
                                                         length,
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationLink>(unmarshalledReturn.Get()) retain];
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLength:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_Length(value));
}

- (NSString*)mediaType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMediaType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaType(nsStrToHstr(value).Get()));
}

- (NSString*)relationship {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_Relationship(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRelationship:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_Relationship(nsStrToHstr(value).Get()));
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)resourceLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setResourceLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_ResourceLanguage(nsStrToHstr(value).Get()));
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

@implementation WWSSyndicationPerson

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationPerson> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationPerson").Get(), &out));
    return [_createRtProxy<WWSSyndicationPerson>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationPersonFactory> WWSISyndicationPersonFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationPersonFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationPerson").Get(), &inst));
    return inst;
}

+ (WWSSyndicationPerson*)makeSyndicationPerson:(NSString*)name {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationPerson> unmarshalledReturn;
    auto _comInst = WWSISyndicationPersonFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationPerson(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationPerson>(unmarshalledReturn.Get()) retain];
}

+ (WWSSyndicationPerson*)makeSyndicationPersonEx:(NSString*)name email:(NSString*)email uri:(WFUri*)uri {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationPerson> unmarshalledReturn;
    auto _comInst = WWSISyndicationPersonFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationPersonEx(nsStrToHstr(name).Get(),
                                                           nsStrToHstr(email).Get(),
                                                           _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationPerson>(unmarshalledReturn.Get()) retain];
}

- (NSString*)email {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationPerson>(self);
    THROW_NS_IF_FAILED(_comInst->get_Email(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setEmail:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationPerson>(self);
    THROW_NS_IF_FAILED(_comInst->put_Email(nsStrToHstr(value).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationPerson>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationPerson>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationPerson>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationPerson>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
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

@implementation WWSSyndicationCategory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationCategory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationCategoryFactory> WWSISyndicationCategoryFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationCategoryFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationCategory").Get(),
                                                       &inst));
    return inst;
}

+ (WWSSyndicationCategory*)makeSyndicationCategory:(NSString*)term {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationCategory> unmarshalledReturn;
    auto _comInst = WWSISyndicationCategoryFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationCategory(nsStrToHstr(term).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationCategory>(unmarshalledReturn.Get()) retain];
}

+ (WWSSyndicationCategory*)makeSyndicationCategoryEx:(NSString*)term scheme:(NSString*)scheme label:(NSString*)label {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationCategory> unmarshalledReturn;
    auto _comInst = WWSISyndicationCategoryFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationCategoryEx(nsStrToHstr(term).Get(),
                                                             nsStrToHstr(scheme).Get(),
                                                             nsStrToHstr(label).Get(),
                                                             unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationCategory>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationCategory").Get(), &out));
    return [_createRtProxy<WWSSyndicationCategory>(out.Get()) retain];
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationCategory>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationCategory>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)scheme {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationCategory>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scheme(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setScheme:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationCategory>(self);
    THROW_NS_IF_FAILED(_comInst->put_Scheme(nsStrToHstr(value).Get()));
}

- (NSString*)term {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationCategory>(self);
    THROW_NS_IF_FAILED(_comInst->get_Term(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTerm:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationCategory>(self);
    THROW_NS_IF_FAILED(_comInst->put_Term(nsStrToHstr(value).Get()));
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

@implementation WWSSyndicationFeed

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationFeed> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationFeed").Get(), &out));
    return [_createRtProxy<WWSSyndicationFeed>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationFeedFactory> WWSISyndicationFeedFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationFeedFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationFeed").Get(), &inst));
    return inst;
}

+ (WWSSyndicationFeed*)makeSyndicationFeed:(NSString*)title subtitle:(NSString*)subtitle uri:(WFUri*)uri {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationFeed> unmarshalledReturn;
    auto _comInst = WWSISyndicationFeedFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationFeed(nsStrToHstr(title).Get(),
                                                       nsStrToHstr(subtitle).Get(),
                                                       _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationFeed>(unmarshalledReturn.Get()) retain];
}

- (NSMutableArray* /* WWSSyndicationPerson* */)authors {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationPerson*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Authors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationPerson_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WWSSyndicationCategory* */)categories {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationCategory*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Categories(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationCategory_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WWSSyndicationPerson* */)contributors {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationPerson*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contributors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationPerson_create(unmarshalledReturn.Get());
}

- (WWSSyndicationGenerator*)generator {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationGenerator> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Generator(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSSyndicationGenerator>(unmarshalledReturn.Get());
}

- (void)setGenerator:(WWSSyndicationGenerator*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->put_Generator(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationGenerator>(value).Get()));
}

- (WFUri*)iconUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_IconUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setIconUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->put_IconUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WWSSyndicationItem* */)items {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationItem_create(unmarshalledReturn.Get());
}

- (WFDateTime*)lastUpdatedTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastUpdatedTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setLastUpdatedTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastUpdatedTime(*[value internalStruct]));
}

- (NSMutableArray* /* WWSSyndicationLink* */)links {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationLink*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Links(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationLink_create(unmarshalledReturn.Get());
}

- (WFUri*)imageUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setImageUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->put_ImageUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (RTObject<WWSISyndicationText>*)rights {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rights(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSISyndicationText>(unmarshalledReturn.Get());
}

- (void)setRights:(RTObject<WWSISyndicationText>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rights(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationText>(value).Get()));
}

- (RTObject<WWSISyndicationText>*)subtitle {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtitle(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSISyndicationText>(unmarshalledReturn.Get());
}

- (void)setSubtitle:(RTObject<WWSISyndicationText>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtitle(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationText>(value).Get()));
}

- (RTObject<WWSISyndicationText>*)title {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSISyndicationText>(unmarshalledReturn.Get());
}

- (void)setTitle:(RTObject<WWSISyndicationText>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationText>(value).Get()));
}

- (WFUri*)firstUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WFUri*)lastUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WFUri*)nextUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WFUri*)previousUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WWSSyndicationFormat)sourceFormat {
    ABI::Windows::Web::Syndication::SyndicationFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceFormat(&unmarshalledReturn));
    return (WWSSyndicationFormat)unmarshalledReturn;
}

- (void)Load:(NSString*)feed {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->Load(nsStrToHstr(feed).Get()));
}

- (void)loadFromXml:(WDXDXmlDocument*)feedDocument {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(self);
    THROW_NS_IF_FAILED(_comInst->LoadFromXml(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(feedDocument).Get()));
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

@implementation WWSSyndicationItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationItemFactory> WWSISyndicationItemFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationItemFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationItem").Get(), &inst));
    return inst;
}

+ (WWSSyndicationItem*)makeSyndicationItem:(NSString*)title content:(WWSSyndicationContent*)content uri:(WFUri*)uri {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationItem> unmarshalledReturn;
    auto _comInst = WWSISyndicationItemFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSyndicationItem(nsStrToHstr(title).Get(),
                                                       _getRtInterface<ABI::Windows::Web::Syndication::ISyndicationContent>(content).Get(),
                                                       _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationItem>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationItem").Get(), &out));
    return [_createRtProxy<WWSSyndicationItem>(out.Get()) retain];
}

- (NSMutableArray* /* WWSSyndicationPerson* */)authors {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationPerson*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Authors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationPerson_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WWSSyndicationCategory* */)categories {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationCategory*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Categories(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationCategory_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WWSSyndicationPerson* */)contributors {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationPerson*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contributors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationPerson_create(unmarshalledReturn.Get());
}

- (WWSSyndicationContent*)content {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSSyndicationContent>(unmarshalledReturn.Get());
}

- (void)setContent:(WWSSyndicationContent*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Content(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationContent>(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (WFDateTime*)lastUpdatedTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastUpdatedTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setLastUpdatedTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastUpdatedTime(*[value internalStruct]));
}

- (NSMutableArray* /* WWSSyndicationLink* */)links {
    ComPtr<IVector<ABI::Windows::Web::Syndication::SyndicationLink*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Links(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWSSyndicationLink_create(unmarshalledReturn.Get());
}

- (WFDateTime*)publishedDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublishedDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setPublishedDate:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_PublishedDate(*[value internalStruct]));
}

- (RTObject<WWSISyndicationText>*)rights {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rights(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSISyndicationText>(unmarshalledReturn.Get());
}

- (void)setRights:(RTObject<WWSISyndicationText>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rights(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationText>(value).Get()));
}

- (WWSSyndicationFeed*)source {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationFeed> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSSyndicationFeed>(unmarshalledReturn.Get());
}

- (void)setSource:(WWSSyndicationFeed*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationFeed>(value).Get()));
}

- (RTObject<WWSISyndicationText>*)summary {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Summary(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSISyndicationText>(unmarshalledReturn.Get());
}

- (void)setSummary:(RTObject<WWSISyndicationText>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Summary(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationText>(value).Get()));
}

- (RTObject<WWSISyndicationText>*)title {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWSISyndicationText>(unmarshalledReturn.Get());
}

- (void)setTitle:(RTObject<WWSISyndicationText>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(_getRtInterface<ABI::Windows::Web::Syndication::ISyndicationText>(value).Get()));
}

- (WFUri*)commentsUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommentsUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setCommentsUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_CommentsUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)editUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_EditUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WFUri*)editMediaUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_EditMediaUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)eTag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ETag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)itemUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)Load:(NSString*)item {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->Load(nsStrToHstr(item).Get()));
}

- (void)loadFromXml:(WDXDXmlDocument*)itemDocument {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Syndication::ISyndicationItem>(self);
    THROW_NS_IF_FAILED(_comInst->LoadFromXml(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(itemDocument).Get()));
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

@implementation WWSSyndicationClient

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationClient> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Syndication.SyndicationClient").Get(), &out));
    return [_createRtProxy<WWSSyndicationClient>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Syndication::ISyndicationClientFactory> WWSISyndicationClientFactory_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationClientFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationClient").Get(), &inst));
    return inst;
}

+ (WWSSyndicationClient*)makeSyndicationClient:(WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationClient> unmarshalledReturn;
    auto _comInst = WWSISyndicationClientFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateSyndicationClient(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(serverCredential).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWSSyndicationClient>(unmarshalledReturn.Get()) retain];
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

@implementation WWSSyndicationError

ComPtr<ABI::Windows::Web::Syndication::ISyndicationErrorStatics> WWSISyndicationErrorStatics_inst() {
    ComPtr<ABI::Windows::Web::Syndication::ISyndicationErrorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Syndication.SyndicationError").Get(), &inst));
    return inst;
}

+ (WWSSyndicationErrorStatus)getStatus:(int)hresult {
    ABI::Windows::Web::Syndication::SyndicationErrorStatus unmarshalledReturn;
    auto _comInst = WWSISyndicationErrorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetStatus(hresult, &unmarshalledReturn));
    return (WWSSyndicationErrorStatus)unmarshalledReturn;
}

@end

@implementation WWSRetrievalProgress {
    ABI::Windows::Web::Syndication::RetrievalProgress structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Web::Syndication::RetrievalProgress)s {
    WWSRetrievalProgress* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Web::Syndication::RetrievalProgress*)internalStruct {
    return &structVal;
}
- (unsigned int)bytesRetrieved {
    return structVal.BytesRetrieved;
}
- (void)setBytesRetrieved:(unsigned int)val {
    structVal.BytesRetrieved = val;
}
- (unsigned int)totalBytesToRetrieve {
    return structVal.TotalBytesToRetrieve;
}
- (void)setTotalBytesToRetrieve:(unsigned int)val {
    structVal.TotalBytesToRetrieve = val;
}
@end
@implementation WWSTransferProgress {
    ABI::Windows::Web::Syndication::TransferProgress structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Web::Syndication::TransferProgress)s {
    WWSTransferProgress* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Web::Syndication::TransferProgress*)internalStruct {
    return &structVal;
}
- (unsigned int)bytesSent {
    return structVal.BytesSent;
}
- (void)setBytesSent:(unsigned int)val {
    structVal.BytesSent = val;
}
- (unsigned int)totalBytesToSend {
    return structVal.TotalBytesToSend;
}
- (void)setTotalBytesToSend:(unsigned int)val {
    structVal.TotalBytesToSend = val;
}
- (unsigned int)bytesRetrieved {
    return structVal.BytesRetrieved;
}
- (void)setBytesRetrieved:(unsigned int)val {
    structVal.BytesRetrieved = val;
}
- (unsigned int)totalBytesToRetrieve {
    return structVal.TotalBytesToRetrieve;
}
- (void)setTotalBytesToRetrieve:(unsigned int)val {
    structVal.TotalBytesToRetrieve = val;
}
@end
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

id RTProxiedNSMutableArray_WWSSyndicationCategory_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Web::Syndication::SyndicationCategory*>,
                                                RTMutableArrayObj<ABI::Windows::Web::Syndication::ISyndicationCategory*,
                                                                  IVector<ABI::Windows::Web::Syndication::SyndicationCategory*>,
                                                                  WWSSyndicationCategory,
                                                                  ABI::Windows::Web::Syndication::SyndicationCategory*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WWSSyndicationItem_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Web::Syndication::SyndicationItem*>,
                                                RTMutableArrayObj<ABI::Windows::Web::Syndication::ISyndicationItem*,
                                                                  IVector<ABI::Windows::Web::Syndication::SyndicationItem*>,
                                                                  WWSSyndicationItem,
                                                                  ABI::Windows::Web::Syndication::SyndicationItem*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WWSSyndicationLink_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Web::Syndication::SyndicationLink*>,
                                                RTMutableArrayObj<ABI::Windows::Web::Syndication::ISyndicationLink*,
                                                                  IVector<ABI::Windows::Web::Syndication::SyndicationLink*>,
                                                                  WWSSyndicationLink,
                                                                  ABI::Windows::Web::Syndication::SyndicationLink*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WWSSyndicationPerson_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Web::Syndication::SyndicationPerson*>,
                                                RTMutableArrayObj<ABI::Windows::Web::Syndication::ISyndicationPerson*,
                                                                  IVector<ABI::Windows::Web::Syndication::SyndicationPerson*>,
                                                                  WWSSyndicationPerson,
                                                                  ABI::Windows::Web::Syndication::SyndicationPerson*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
