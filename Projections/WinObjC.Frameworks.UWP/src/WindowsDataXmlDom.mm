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

// WindowsDataXmlDom.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Data.Xml.Dom.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDataXmlDom.h"
#include "WindowsDataXmlDom_priv.h"

@implementation WDXDIXmlNodeSelector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

@end

@implementation WDXDIXmlNodeSerializer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDIXmlNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDIXmlCharacterData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlCharacterData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)data {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(nsStrToHstr(value).Get()));
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)substringData:(unsigned int)offset count:(unsigned int)count {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->SubstringData(offset, count, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)appendData:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->AppendData(nsStrToHstr(data).Get()));
}

- (void)insertData:(unsigned int)offset data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->InsertData(offset, nsStrToHstr(data).Get()));
}

- (void)deleteData:(unsigned int)offset count:(unsigned int)count {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteData(offset, count));
}

- (void)replaceData:(unsigned int)offset count:(unsigned int)count data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceData(offset, count, nsStrToHstr(data).Get()));
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDIXmlText

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlText> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDXDIXmlText>*)splitText:(unsigned int)offset {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlText>(self);
    THROW_NS_IF_FAILED(_comInst->SplitText(offset, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlText>(unmarshalledReturn.Get());
}

- (NSString*)data {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(nsStrToHstr(value).Get()));
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)substringData:(unsigned int)offset count:(unsigned int)count {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->SubstringData(offset, count, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)appendData:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->AppendData(nsStrToHstr(data).Get()));
}

- (void)insertData:(unsigned int)offset data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->InsertData(offset, nsStrToHstr(data).Get()));
}

- (void)deleteData:(unsigned int)offset count:(unsigned int)count {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteData(offset, count));
}

- (void)replaceData:(unsigned int)offset count:(unsigned int)count data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceData(offset, count, nsStrToHstr(data).Get()));
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlNodeList {
    RTArrayObj<ABI::Windows::Data::Xml::Dom::IXmlNode*,
               IVectorView<ABI::Windows::Data::Xml::Dom::IXmlNode*>,
               RTObject<WDXDIXmlNode>,
               ABI::Windows::Data::Xml::Dom::IXmlNode*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             RTObject<WDXDIXmlNode>,
                             ABI::Windows::Data::Xml::Dom::IXmlNode*,
                             ABI::Windows::Data::Xml::Dom::IXmlNode*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WDXDIXmlNode>*)item:(unsigned int)index {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeList>(self);
    THROW_NS_IF_FAILED(_comInst->Item(index, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

@end

@implementation WDXDXmlNamedNodeMap {
    RTArrayObj<ABI::Windows::Data::Xml::Dom::IXmlNode*,
               IVectorView<ABI::Windows::Data::Xml::Dom::IXmlNode*>,
               RTObject<WDXDIXmlNode>,
               ABI::Windows::Data::Xml::Dom::IXmlNode*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             RTObject<WDXDIXmlNode>,
                             ABI::Windows::Data::Xml::Dom::IXmlNode*,
                             ABI::Windows::Data::Xml::Dom::IXmlNode*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WDXDIXmlNode>*)item:(unsigned int)index {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap>(self);
    THROW_NS_IF_FAILED(_comInst->Item(index, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)getNamedItem:(NSString*)name {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedItem(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)setNamedItem:(RTObject<WDXDIXmlNode>*)node {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetNamedItem(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(node).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeNamedItem:(NSString*)name {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveNamedItem(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)getNamedItemNS:(RTObject*)namespaceUri name:(NSString*)name {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedItemNS([namespaceUri comObj].Get(), nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeNamedItemNS:(RTObject*)namespaceUri name:(NSString*)name {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveNamedItemNS([namespaceUri comObj].Get(), nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)setNamedItemNS:(RTObject<WDXDIXmlNode>*)node {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetNamedItemNS(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(node).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

@end

@implementation WDXDXmlDocument

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Data.Xml.Dom.XmlDocument").Get(), &out));
    return [_createRtProxy<WDXDXmlDocument>(out.Get()) retain];
}

ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocumentStatics> WDXDIXmlDocumentStatics_inst() {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocumentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Xml.Dom.XmlDocument").Get(), &inst));
    return inst;
}

+ (void)loadFromUriAsync:(WFUri*)uri success:(void (^)(WDXDXmlDocument*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Xml::Dom::XmlDocument*>> unmarshalledReturn;
    auto _comInst = WDXDIXmlDocumentStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LoadFromUriAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Data::Xml::Dom::XmlDocument*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Xml::Dom::XmlDocument*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDXDXmlDocument>(result.Get()));
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

+ (void)loadFromUriWithSettingsAsync:(WFUri*)uri
                        loadSettings:(WDXDXmlLoadSettings*)loadSettings
                             success:(void (^)(WDXDXmlDocument*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Xml::Dom::XmlDocument*>> unmarshalledReturn;
    auto _comInst = WDXDIXmlDocumentStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LoadFromUriWithSettingsAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                               _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(loadSettings).Get(),
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Data::Xml::Dom::XmlDocument*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Xml::Dom::XmlDocument*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDXDXmlDocument>(result.Get()));
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

+ (void)loadFromFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WDXDXmlDocument*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Xml::Dom::XmlDocument*>> unmarshalledReturn;
    auto _comInst = WDXDIXmlDocumentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LoadFromFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Data::Xml::Dom::XmlDocument*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Xml::Dom::XmlDocument*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDXDXmlDocument>(result.Get()));
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

+ (void)loadFromFileWithSettingsAsync:(RTObject<WSIStorageFile>*)file
                         loadSettings:(WDXDXmlLoadSettings*)loadSettings
                              success:(void (^)(WDXDXmlDocument*))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Xml::Dom::XmlDocument*>> unmarshalledReturn;
    auto _comInst = WDXDIXmlDocumentStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LoadFromFileWithSettingsAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(loadSettings).Get(),
                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Data::Xml::Dom::XmlDocument*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Xml::Dom::XmlDocument*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDXDXmlDocument>(result.Get()));
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

- (WDXDXmlDocumentType*)doctype {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocumentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_Doctype(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocumentType>(unmarshalledReturn.Get());
}

- (WDXDXmlDomImplementation*)implementation {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDomImplementation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_Implementation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDomImplementation>(unmarshalledReturn.Get());
}

- (WDXDXmlElement*)documentElement {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentElement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlElement>(unmarshalledReturn.Get());
}

- (WDXDXmlElement*)createElement:(NSString*)tagName {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CreateElement(nsStrToHstr(tagName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlElement>(unmarshalledReturn.Get());
}

- (WDXDXmlDocumentFragment*)createDocumentFragment {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocumentFragment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDocumentFragment(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocumentFragment>(unmarshalledReturn.Get());
}

- (WDXDXmlText*)createTextNode:(NSString*)data {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CreateTextNode(nsStrToHstr(data).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlText>(unmarshalledReturn.Get());
}

- (WDXDXmlComment*)createComment:(NSString*)data {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlComment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CreateComment(nsStrToHstr(data).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlComment>(unmarshalledReturn.Get());
}

- (WDXDXmlProcessingInstruction*)createProcessingInstruction:(NSString*)target data:(NSString*)data {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlProcessingInstruction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateProcessingInstruction(nsStrToHstr(target).Get(), nsStrToHstr(data).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlProcessingInstruction>(unmarshalledReturn.Get());
}

- (WDXDXmlAttribute*)createAttribute:(NSString*)name {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAttribute(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlAttribute>(unmarshalledReturn.Get());
}

- (WDXDXmlEntityReference*)createEntityReference:(NSString*)name {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlEntityReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CreateEntityReference(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlEntityReference>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)getElementsByTagName:(NSString*)tagName {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->GetElementsByTagName(nsStrToHstr(tagName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (WDXDXmlCDataSection*)createCDataSection:(NSString*)data {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlCDataSection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->CreateCDataSection(nsStrToHstr(data).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlCDataSection>(unmarshalledReturn.Get());
}

- (NSString*)documentUri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentUri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDXDXmlAttribute*)createAttributeNS:(RTObject*)namespaceUri qualifiedName:(NSString*)qualifiedName {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateAttributeNS([namespaceUri comObj].Get(), nsStrToHstr(qualifiedName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlAttribute>(unmarshalledReturn.Get());
}

- (WDXDXmlElement*)createElementNS:(RTObject*)namespaceUri qualifiedName:(NSString*)qualifiedName {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateElementNS([namespaceUri comObj].Get(), nsStrToHstr(qualifiedName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlElement>(unmarshalledReturn.Get());
}

- (WDXDXmlElement*)getElementById:(NSString*)elementId {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->GetElementById(nsStrToHstr(elementId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlElement>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)importNode:(RTObject<WDXDIXmlNode>*)node deep:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(self);
    THROW_NS_IF_FAILED(_comInst->ImportNode(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(node).Get(),
                                            (boolean)deep,
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

- (void)loadXml:(NSString*)xml {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocumentIO>(self);
    THROW_NS_IF_FAILED(_comInst->LoadXml(nsStrToHstr(xml).Get()));
}

- (void)loadXmlWithSettings:(NSString*)xml loadSettings:(WDXDXmlLoadSettings*)loadSettings {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocumentIO>(self);
    THROW_NS_IF_FAILED(_comInst->LoadXmlWithSettings(nsStrToHstr(xml).Get(),
                                                     _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(loadSettings).Get()));
}

- (RTObject<WFIAsyncAction>*)saveToFileAsync:(RTObject<WSIStorageFile>*)file {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocumentIO>(self);
    THROW_NS_IF_FAILED(
        _comInst->SaveToFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)loadXmlFromBuffer:(RTObject<WSSIBuffer>*)buffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocumentIO2>(self);
    THROW_NS_IF_FAILED(_comInst->LoadXmlFromBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get()));
}

- (void)loadXmlFromBufferWithSettings:(RTObject<WSSIBuffer>*)buffer loadSettings:(WDXDXmlLoadSettings*)loadSettings {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocumentIO2>(self);
    THROW_NS_IF_FAILED(
        _comInst->LoadXmlFromBufferWithSettings(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                                _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(loadSettings).Get()));
}

@end

@implementation WDXDXmlAttribute

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)specified {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Specified(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlAttribute>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(nsStrToHstr(value).Get()));
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlDocumentType

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocumentType> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocumentType>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDXDXmlNamedNodeMap*)entities {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocumentType>(self);
    THROW_NS_IF_FAILED(_comInst->get_Entities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)notations {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDocumentType>(self);
    THROW_NS_IF_FAILED(_comInst->get_Notations(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlDomImplementation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDomImplementation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)hasFeature:(NSString*)feature version:(RTObject*)version {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlDomImplementation>(self);
    THROW_NS_IF_FAILED(_comInst->HasFeature(nsStrToHstr(feature).Get(), [version comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDXDXmlElement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlElement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)tagName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_TagName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getAttribute:(NSString*)attributeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->GetAttribute(nsStrToHstr(attributeName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAttribute:(NSString*)attributeName attributeValue:(NSString*)attributeValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->SetAttribute(nsStrToHstr(attributeName).Get(), nsStrToHstr(attributeValue).Get()));
}

- (void)removeAttribute:(NSString*)attributeName {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAttribute(nsStrToHstr(attributeName).Get()));
}

- (WDXDXmlAttribute*)getAttributeNode:(NSString*)attributeName {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->GetAttributeNode(nsStrToHstr(attributeName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlAttribute>(unmarshalledReturn.Get());
}

- (WDXDXmlAttribute*)setAttributeNode:(WDXDXmlAttribute*)newAttribute {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->SetAttributeNode(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlAttribute>(newAttribute).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlAttribute>(unmarshalledReturn.Get());
}

- (WDXDXmlAttribute*)removeAttributeNode:(WDXDXmlAttribute*)attributeNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAttributeNode(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlAttribute>(attributeNode).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlAttribute>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)getElementsByTagName:(NSString*)tagName {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->GetElementsByTagName(nsStrToHstr(tagName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (void)setAttributeNS:(RTObject*)namespaceUri qualifiedName:(NSString*)qualifiedName value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->SetAttributeNS([namespaceUri comObj].Get(), nsStrToHstr(qualifiedName).Get(), nsStrToHstr(value).Get()));
}

- (NSString*)getAttributeNS:(RTObject*)namespaceUri localName:(NSString*)localName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->GetAttributeNS([namespaceUri comObj].Get(), nsStrToHstr(localName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)removeAttributeNS:(RTObject*)namespaceUri localName:(NSString*)localName {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAttributeNS([namespaceUri comObj].Get(), nsStrToHstr(localName).Get()));
}

- (WDXDXmlAttribute*)setAttributeNodeNS:(WDXDXmlAttribute*)newAttribute {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(_comInst->SetAttributeNodeNS(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlAttribute>(newAttribute).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlAttribute>(unmarshalledReturn.Get());
}

- (WDXDXmlAttribute*)getAttributeNodeNS:(RTObject*)namespaceUri localName:(NSString*)localName {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlElement>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetAttributeNodeNS([namespaceUri comObj].Get(), nsStrToHstr(localName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlAttribute>(unmarshalledReturn.Get());
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlDocumentFragment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocumentFragment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlText

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlText> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDXDIXmlText>*)splitText:(unsigned int)offset {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlText>(self);
    THROW_NS_IF_FAILED(_comInst->SplitText(offset, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlText>(unmarshalledReturn.Get());
}

- (NSString*)data {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(nsStrToHstr(value).Get()));
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)substringData:(unsigned int)offset count:(unsigned int)count {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->SubstringData(offset, count, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)appendData:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->AppendData(nsStrToHstr(data).Get()));
}

- (void)insertData:(unsigned int)offset data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->InsertData(offset, nsStrToHstr(data).Get()));
}

- (void)deleteData:(unsigned int)offset count:(unsigned int)count {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteData(offset, count));
}

- (void)replaceData:(unsigned int)offset count:(unsigned int)count data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceData(offset, count, nsStrToHstr(data).Get()));
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlComment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlComment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)data {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(nsStrToHstr(value).Get()));
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)substringData:(unsigned int)offset count:(unsigned int)count {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->SubstringData(offset, count, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)appendData:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->AppendData(nsStrToHstr(data).Get()));
}

- (void)insertData:(unsigned int)offset data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->InsertData(offset, nsStrToHstr(data).Get()));
}

- (void)deleteData:(unsigned int)offset count:(unsigned int)count {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteData(offset, count));
}

- (void)replaceData:(unsigned int)offset count:(unsigned int)count data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceData(offset, count, nsStrToHstr(data).Get()));
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlProcessingInstruction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlProcessingInstruction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)target {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlProcessingInstruction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Target(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)data {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlProcessingInstruction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlProcessingInstruction>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(nsStrToHstr(value).Get()));
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlEntityReference

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlEntityReference> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlCDataSection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlCDataSection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDXDIXmlText>*)splitText:(unsigned int)offset {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlText> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlText>(self);
    THROW_NS_IF_FAILED(_comInst->SplitText(offset, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlText>(unmarshalledReturn.Get());
}

- (NSString*)data {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(nsStrToHstr(value).Get()));
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)substringData:(unsigned int)offset count:(unsigned int)count {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->SubstringData(offset, count, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)appendData:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->AppendData(nsStrToHstr(data).Get()));
}

- (void)insertData:(unsigned int)offset data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->InsertData(offset, nsStrToHstr(data).Get()));
}

- (void)deleteData:(unsigned int)offset count:(unsigned int)count {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteData(offset, count));
}

- (void)replaceData:(unsigned int)offset count:(unsigned int)count data:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlCharacterData>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceData(offset, count, nsStrToHstr(data).Get()));
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDXmlLoadSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Data.Xml.Dom.XmlLoadSettings").Get(), &out));
    return [_createRtProxy<WDXDXmlLoadSettings>(out.Get()) retain];
}

- (unsigned int)maxElementDepth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxElementDepth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxElementDepth:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxElementDepth(value));
}

- (BOOL)prohibitDtd {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProhibitDtd(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setProhibitDtd:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProhibitDtd((boolean)value));
}

- (BOOL)resolveExternals {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolveExternals(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setResolveExternals:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ResolveExternals((boolean)value));
}

- (BOOL)validateOnParse {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValidateOnParse(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setValidateOnParse:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ValidateOnParse((boolean)value));
}

- (BOOL)elementContentWhiteSpace {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementContentWhiteSpace(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setElementContentWhiteSpace:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlLoadSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_ElementContentWhiteSpace((boolean)value));
}

@end

@implementation WDXDDtdNotation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IDtdNotation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)publicId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IDtdNotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublicId(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)systemId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IDtdNotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemId(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end

@implementation WDXDDtdEntity

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Dom::IDtdEntity> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)publicId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IDtdEntity>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublicId(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)systemId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IDtdEntity>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemId(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)notationName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IDtdEntity>(self);
    THROW_NS_IF_FAILED(_comInst->get_NotationName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)nodeValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setNodeValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_NodeValue([value comObj].Get()));
}

- (WDXDNodeType)nodeType {
    ABI::Windows::Data::Xml::Dom::NodeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeType(&unmarshalledReturn));
    return (WDXDNodeType)unmarshalledReturn;
}

- (NSString*)nodeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NodeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WDXDIXmlNode>*)parentNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)childNodes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildNodes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)firstChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)lastChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastChild(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)previousSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)nextSibling {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextSibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNamedNodeMap*)attributes {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNamedNodeMap>(unmarshalledReturn.Get());
}

- (BOOL)hasChildNodes {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->HasChildNodes(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDXDXmlDocument*)ownerDocument {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerDocument(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBefore(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(),
                                              _getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(referenceChild).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(childNode).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendChild(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(newChild).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->CloneNode((boolean)deep, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (RTObject*)namespaceUri {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_NamespaceUri(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)localName {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)prefix {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Prefix(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)normalize {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->Normalize());
}

- (void)setPrefix:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_Prefix([value comObj].Get()));
}

- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectSingleNode(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodes(nsStrToHstr(xpath).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(
        _comInst->SelectSingleNodeNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDIXmlNode>(unmarshalledReturn.Get());
}

- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlNodeList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSelector>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNodesNS(nsStrToHstr(xpath).Get(), [namespaces comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlNodeList>(unmarshalledReturn.Get());
}

- (NSString*)getXml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->GetXml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)innerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setInnerText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerText(nsStrToHstr(value).Get()));
}

@end
