//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsDataXmlDom.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDXDXmlNodeList, WDXDXmlNamedNodeMap, WDXDXmlDocument, WDXDXmlAttribute, WDXDXmlDocumentType, WDXDXmlDomImplementation,
    WDXDXmlElement, WDXDXmlDocumentFragment, WDXDXmlText, WDXDXmlComment, WDXDXmlProcessingInstruction, WDXDXmlEntityReference,
    WDXDXmlCDataSection, WDXDXmlLoadSettings, WDXDDtdNotation, WDXDDtdEntity;
@protocol WDXDIXmlNodeSelector
, WDXDIXmlNodeSerializer, WDXDIXmlNode, WDXDIXmlDomImplementation, WDXDIXmlDocumentType, WDXDIXmlAttribute, WDXDIXmlDocumentFragment,
    WDXDIXmlElement, WDXDIDtdNotation, WDXDIDtdEntity, WDXDIXmlEntityReference, WDXDIXmlProcessingInstruction, WDXDIXmlCharacterData,
    WDXDIXmlComment, WDXDIXmlText, WDXDIXmlCDataSection, WDXDIXmlDocument, WDXDIXmlNamedNodeMap, WDXDIXmlNodeList, WDXDIXmlLoadSettings,
    WDXDIXmlDocumentIO, WDXDIXmlDocumentStatics;

// Windows.Data.Xml.Dom.NodeType
enum _WDXDNodeType {
    WDXDNodeTypeInvalid = 0,
    WDXDNodeTypeElementNode = 1,
    WDXDNodeTypeAttributeNode = 2,
    WDXDNodeTypeTextNode = 3,
    WDXDNodeTypeDataSectionNode = 4,
    WDXDNodeTypeEntityReferenceNode = 5,
    WDXDNodeTypeEntityNode = 6,
    WDXDNodeTypeProcessingInstructionNode = 7,
    WDXDNodeTypeCommentNode = 8,
    WDXDNodeTypeDocumentNode = 9,
    WDXDNodeTypeDocumentTypeNode = 10,
    WDXDNodeTypeDocumentFragmentNode = 11,
    WDXDNodeTypeNotationNode = 12,
};
typedef unsigned WDXDNodeType;

#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"
#include "WindowsFoundation.h"

// Windows.Data.Xml.Dom.IXmlNodeSelector
#ifndef __WDXDIXmlNodeSelector_DEFINED__
#define __WDXDIXmlNodeSelector_DEFINED__

@protocol WDXDIXmlNodeSelector
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
@end

#endif // __WDXDIXmlNodeSelector_DEFINED__

// Windows.Data.Xml.Dom.IXmlNodeSerializer
#ifndef __WDXDIXmlNodeSerializer_DEFINED__
#define __WDXDIXmlNodeSerializer_DEFINED__

@protocol WDXDIXmlNodeSerializer
@property (copy) NSString* innerText;
- (NSString*)getXml;
@end

#endif // __WDXDIXmlNodeSerializer_DEFINED__

// Windows.Data.Xml.Dom.IXmlNode
#ifndef __WDXDIXmlNode_DEFINED__
#define __WDXDIXmlNode_DEFINED__

@protocol WDXDIXmlNode <WDXDIXmlNodeSelector, WDXDIXmlNodeSerializer>
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (copy) RTObject* nodeValue;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (copy) RTObject* prefix;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDIXmlNode_DEFINED__

// Windows.Data.Xml.Dom.IXmlCharacterData
#ifndef __WDXDIXmlCharacterData_DEFINED__
#define __WDXDIXmlCharacterData_DEFINED__

@protocol WDXDIXmlCharacterData <WDXDIXmlNode, WDXDIXmlNodeSelector, WDXDIXmlNodeSerializer>
@property (copy) NSString* data;
@property (readonly) unsigned length;
- (NSString*)substringData:(unsigned)offset count:(unsigned)count;
- (void)appendData:(NSString*)data;
- (void)insertData:(unsigned)offset data:(NSString*)data;
- (void)deleteData:(unsigned)offset count:(unsigned)count;
- (void)replaceData:(unsigned)offset count:(unsigned)count data:(NSString*)data;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDIXmlCharacterData_DEFINED__

// Windows.Data.Xml.Dom.IXmlText
#ifndef __WDXDIXmlText_DEFINED__
#define __WDXDIXmlText_DEFINED__

@protocol WDXDIXmlText <WDXDIXmlCharacterData, WDXDIXmlNode, WDXDIXmlNodeSelector, WDXDIXmlNodeSerializer>
- (RTObject<WDXDIXmlText>*)splitText:(unsigned)offset;
- (NSString*)substringData:(unsigned)offset count:(unsigned)count;
- (void)appendData:(NSString*)data;
- (void)insertData:(unsigned)offset data:(NSString*)data;
- (void)deleteData:(unsigned)offset count:(unsigned)count;
- (void)replaceData:(unsigned)offset count:(unsigned)count data:(NSString*)data;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDIXmlText_DEFINED__

// Windows.Data.Xml.Dom.XmlNodeList
#ifndef __WDXDXmlNodeList_DEFINED__
#define __WDXDXmlNodeList_DEFINED__

WINRT_EXPORT
@interface WDXDXmlNodeList : RTObject
@property (readonly) unsigned length;
@property (readonly) unsigned size;
- (RTObject<WDXDIXmlNode>*)item:(unsigned)index;
@end

#endif // __WDXDXmlNodeList_DEFINED__

// Windows.Data.Xml.Dom.XmlNamedNodeMap
#ifndef __WDXDXmlNamedNodeMap_DEFINED__
#define __WDXDXmlNamedNodeMap_DEFINED__

WINRT_EXPORT
@interface WDXDXmlNamedNodeMap : RTObject
@property (readonly) unsigned size;
@property (readonly) unsigned length;
- (RTObject<WDXDIXmlNode>*)item:(unsigned)index;
- (RTObject<WDXDIXmlNode>*)getNamedItem:(NSString*)name;
- (RTObject<WDXDIXmlNode>*)setNamedItem:(RTObject<WDXDIXmlNode>*)node;
- (RTObject<WDXDIXmlNode>*)removeNamedItem:(NSString*)name;
- (RTObject<WDXDIXmlNode>*)getNamedItemNS:(RTObject*)namespaceUri name:(NSString*)name;
- (RTObject<WDXDIXmlNode>*)removeNamedItemNS:(RTObject*)namespaceUri name:(NSString*)name;
- (RTObject<WDXDIXmlNode>*)setNamedItemNS:(RTObject<WDXDIXmlNode>*)node;
@end

#endif // __WDXDXmlNamedNodeMap_DEFINED__

// Windows.Data.Xml.Dom.XmlDocument
#ifndef __WDXDXmlDocument_DEFINED__
#define __WDXDXmlDocument_DEFINED__

WINRT_EXPORT
@interface WDXDXmlDocument : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
+ (void)loadFromUriAsync:(WFUri*)uri success:(void (^)(WDXDXmlDocument*))success failure:(void (^)(NSError*))failure;
+ (void)loadFromUriWithSettingsAsync:(WFUri*)uri
                        loadSettings:(WDXDXmlLoadSettings*)loadSettings
                             success:(void (^)(WDXDXmlDocument*))success
                             failure:(void (^)(NSError*))failure;
+ (void)loadFromFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WDXDXmlDocument*))success failure:(void (^)(NSError*))failure;
+ (void)loadFromFileWithSettingsAsync:(RTObject<WSIStorageFile>*)file
                         loadSettings:(WDXDXmlLoadSettings*)loadSettings
                              success:(void (^)(WDXDXmlDocument*))success
                              failure:(void (^)(NSError*))failure;
+ (instancetype)create ACTIVATOR;
@property (readonly) WDXDXmlDocumentType* doctype;
@property (readonly) WDXDXmlElement* documentElement;
@property (readonly) NSString* documentUri;
@property (readonly) WDXDXmlDomImplementation* implementation;
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (copy) NSString* innerText;
- (WDXDXmlElement*)createElement:(NSString*)tagName;
- (WDXDXmlDocumentFragment*)createDocumentFragment;
- (WDXDXmlText*)createTextNode:(NSString*)data;
- (WDXDXmlComment*)createComment:(NSString*)data;
- (WDXDXmlProcessingInstruction*)createProcessingInstruction:(NSString*)target data:(NSString*)data;
- (WDXDXmlAttribute*)createAttribute:(NSString*)name;
- (WDXDXmlEntityReference*)createEntityReference:(NSString*)name;
- (WDXDXmlNodeList*)getElementsByTagName:(NSString*)tagName;
- (WDXDXmlCDataSection*)createCDataSection:(NSString*)data;
- (WDXDXmlAttribute*)createAttributeNS:(RTObject*)namespaceUri qualifiedName:(NSString*)qualifiedName;
- (WDXDXmlElement*)createElementNS:(RTObject*)namespaceUri qualifiedName:(NSString*)qualifiedName;
- (WDXDXmlElement*)getElementById:(NSString*)elementId;
- (RTObject<WDXDIXmlNode>*)importNode:(RTObject<WDXDIXmlNode>*)node deep:(BOOL)deep;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
- (void)loadXml:(NSString*)xml;
- (void)loadXmlWithSettings:(NSString*)xml loadSettings:(WDXDXmlLoadSettings*)loadSettings;
- (RTObject<WFIAsyncAction>*)saveToFileAsync:(RTObject<WSIStorageFile>*)file;
@end

#endif // __WDXDXmlDocument_DEFINED__

// Windows.Data.Xml.Dom.XmlAttribute
#ifndef __WDXDXmlAttribute_DEFINED__
#define __WDXDXmlAttribute_DEFINED__

WINRT_EXPORT
@interface WDXDXmlAttribute : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (copy) NSString* value;
@property (readonly) NSString* name;
@property (readonly) BOOL specified;
@property (copy) NSString* innerText;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlAttribute_DEFINED__

// Windows.Data.Xml.Dom.XmlDocumentType
#ifndef __WDXDXmlDocumentType_DEFINED__
#define __WDXDXmlDocumentType_DEFINED__

WINRT_EXPORT
@interface WDXDXmlDocumentType : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (copy) NSString* innerText;
@property (copy) RTObject* nodeValue;
@property (copy) RTObject* prefix;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (readonly) NSString* name;
@property (readonly) WDXDXmlNamedNodeMap* notations;
@property (readonly) WDXDXmlNamedNodeMap* entities;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlDocumentType_DEFINED__

// Windows.Data.Xml.Dom.XmlDomImplementation
#ifndef __WDXDXmlDomImplementation_DEFINED__
#define __WDXDXmlDomImplementation_DEFINED__

WINRT_EXPORT
@interface WDXDXmlDomImplementation : RTObject
- (BOOL)hasFeature:(NSString*)feature version:(RTObject*)version;
@end

#endif // __WDXDXmlDomImplementation_DEFINED__

// Windows.Data.Xml.Dom.XmlElement
#ifndef __WDXDXmlElement_DEFINED__
#define __WDXDXmlElement_DEFINED__

WINRT_EXPORT
@interface WDXDXmlElement : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (readonly) NSString* tagName;
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (copy) NSString* innerText;
- (NSString*)getAttribute:(NSString*)attributeName;
- (void)setAttribute:(NSString*)attributeName attributeValue:(NSString*)attributeValue;
- (void)removeAttribute:(NSString*)attributeName;
- (WDXDXmlAttribute*)getAttributeNode:(NSString*)attributeName;
- (WDXDXmlAttribute*)setAttributeNode:(WDXDXmlAttribute*)newAttribute;
- (WDXDXmlAttribute*)removeAttributeNode:(WDXDXmlAttribute*)attributeNode;
- (WDXDXmlNodeList*)getElementsByTagName:(NSString*)tagName;
- (void)setAttributeNS:(RTObject*)namespaceUri qualifiedName:(NSString*)qualifiedName value:(NSString*)value;
- (NSString*)getAttributeNS:(RTObject*)namespaceUri localName:(NSString*)localName;
- (void)removeAttributeNS:(RTObject*)namespaceUri localName:(NSString*)localName;
- (WDXDXmlAttribute*)setAttributeNodeNS:(WDXDXmlAttribute*)newAttribute;
- (WDXDXmlAttribute*)getAttributeNodeNS:(RTObject*)namespaceUri localName:(NSString*)localName;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlElement_DEFINED__

// Windows.Data.Xml.Dom.XmlDocumentFragment
#ifndef __WDXDXmlDocumentFragment_DEFINED__
#define __WDXDXmlDocumentFragment_DEFINED__

WINRT_EXPORT
@interface WDXDXmlDocumentFragment : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (copy) NSString* innerText;
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlDocumentFragment_DEFINED__

// Windows.Data.Xml.Dom.XmlText
#ifndef __WDXDXmlText_DEFINED__
#define __WDXDXmlText_DEFINED__

WINRT_EXPORT
@interface WDXDXmlText : RTObject <WDXDIXmlText, WDXDIXmlCharacterData, WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (copy) NSString* data;
@property (readonly) unsigned length;
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (copy) NSString* innerText;
- (RTObject<WDXDIXmlText>*)splitText:(unsigned)offset;
- (NSString*)substringData:(unsigned)offset count:(unsigned)count;
- (void)appendData:(NSString*)data;
- (void)insertData:(unsigned)offset data:(NSString*)data;
- (void)deleteData:(unsigned)offset count:(unsigned)count;
- (void)replaceData:(unsigned)offset count:(unsigned)count data:(NSString*)data;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlText_DEFINED__

// Windows.Data.Xml.Dom.XmlComment
#ifndef __WDXDXmlComment_DEFINED__
#define __WDXDXmlComment_DEFINED__

WINRT_EXPORT
@interface WDXDXmlComment : RTObject <WDXDIXmlCharacterData, WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (copy) NSString* data;
@property (readonly) unsigned length;
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (copy) NSString* innerText;
- (NSString*)substringData:(unsigned)offset count:(unsigned)count;
- (void)appendData:(NSString*)data;
- (void)insertData:(unsigned)offset data:(NSString*)data;
- (void)deleteData:(unsigned)offset count:(unsigned)count;
- (void)replaceData:(unsigned)offset count:(unsigned)count data:(NSString*)data;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlComment_DEFINED__

// Windows.Data.Xml.Dom.XmlProcessingInstruction
#ifndef __WDXDXmlProcessingInstruction_DEFINED__
#define __WDXDXmlProcessingInstruction_DEFINED__

WINRT_EXPORT
@interface WDXDXmlProcessingInstruction : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (copy) NSString* innerText;
@property (copy) NSString* data;
@property (readonly) NSString* target;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlProcessingInstruction_DEFINED__

// Windows.Data.Xml.Dom.XmlEntityReference
#ifndef __WDXDXmlEntityReference_DEFINED__
#define __WDXDXmlEntityReference_DEFINED__

WINRT_EXPORT
@interface WDXDXmlEntityReference : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (copy) NSString* innerText;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlEntityReference_DEFINED__

// Windows.Data.Xml.Dom.XmlCDataSection
#ifndef __WDXDXmlCDataSection_DEFINED__
#define __WDXDXmlCDataSection_DEFINED__

WINRT_EXPORT
@interface WDXDXmlCDataSection : RTObject <WDXDIXmlText, WDXDIXmlCharacterData, WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (copy) NSString* innerText;
@property (copy) NSString* data;
@property (readonly) unsigned length;
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
- (RTObject<WDXDIXmlText>*)splitText:(unsigned)offset;
- (NSString*)substringData:(unsigned)offset count:(unsigned)count;
- (void)appendData:(NSString*)data;
- (void)insertData:(unsigned)offset data:(NSString*)data;
- (void)deleteData:(unsigned)offset count:(unsigned)count;
- (void)replaceData:(unsigned)offset count:(unsigned)count data:(NSString*)data;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDXmlCDataSection_DEFINED__

// Windows.Data.Xml.Dom.XmlLoadSettings
#ifndef __WDXDXmlLoadSettings_DEFINED__
#define __WDXDXmlLoadSettings_DEFINED__

WINRT_EXPORT
@interface WDXDXmlLoadSettings : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL validateOnParse;
@property BOOL resolveExternals;
@property BOOL prohibitDtd;
@property unsigned maxElementDepth;
@property BOOL elementContentWhiteSpace;
@end

#endif // __WDXDXmlLoadSettings_DEFINED__

// Windows.Data.Xml.Dom.DtdNotation
#ifndef __WDXDDtdNotation_DEFINED__
#define __WDXDDtdNotation_DEFINED__

WINRT_EXPORT
@interface WDXDDtdNotation : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (readonly) RTObject* publicId;
@property (readonly) RTObject* systemId;
@property (copy) NSString* innerText;
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDDtdNotation_DEFINED__

// Windows.Data.Xml.Dom.DtdEntity
#ifndef __WDXDDtdEntity_DEFINED__
#define __WDXDDtdEntity_DEFINED__

WINRT_EXPORT
@interface WDXDDtdEntity : RTObject <WDXDIXmlNode, WDXDIXmlNodeSerializer, WDXDIXmlNodeSelector>
@property (readonly) RTObject* notationName;
@property (readonly) RTObject* publicId;
@property (readonly) RTObject* systemId;
@property (copy) RTObject* prefix;
@property (copy) RTObject* nodeValue;
@property (readonly) RTObject<WDXDIXmlNode>* firstChild;
@property (readonly) RTObject<WDXDIXmlNode>* lastChild;
@property (readonly) RTObject* localName;
@property (readonly) RTObject* namespaceUri;
@property (readonly) RTObject<WDXDIXmlNode>* nextSibling;
@property (readonly) NSString* nodeName;
@property (readonly) WDXDNodeType nodeType;
@property (readonly) WDXDXmlNamedNodeMap* attributes;
@property (readonly) WDXDXmlDocument* ownerDocument;
@property (readonly) RTObject<WDXDIXmlNode>* parentNode;
@property (readonly) WDXDXmlNodeList* childNodes;
@property (readonly) RTObject<WDXDIXmlNode>* previousSibling;
@property (copy) NSString* innerText;
- (BOOL)hasChildNodes;
- (RTObject<WDXDIXmlNode>*)insertBefore:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)replaceChild:(RTObject<WDXDIXmlNode>*)newChild referenceChild:(RTObject<WDXDIXmlNode>*)referenceChild;
- (RTObject<WDXDIXmlNode>*)removeChild:(RTObject<WDXDIXmlNode>*)childNode;
- (RTObject<WDXDIXmlNode>*)appendChild:(RTObject<WDXDIXmlNode>*)newChild;
- (RTObject<WDXDIXmlNode>*)cloneNode:(BOOL)deep;
- (void)normalize;
- (RTObject<WDXDIXmlNode>*)selectSingleNode:(NSString*)xpath;
- (WDXDXmlNodeList*)selectNodes:(NSString*)xpath;
- (RTObject<WDXDIXmlNode>*)selectSingleNodeNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (WDXDXmlNodeList*)selectNodesNS:(NSString*)xpath namespaces:(RTObject*)namespaces;
- (NSString*)getXml;
@end

#endif // __WDXDDtdEntity_DEFINED__
