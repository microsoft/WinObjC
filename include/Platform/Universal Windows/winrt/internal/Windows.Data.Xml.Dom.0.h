// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Data::Xml::Dom {

struct IDtdEntity;
struct IDtdNotation;
struct IXmlAttribute;
struct IXmlCDataSection;
struct IXmlCharacterData;
struct IXmlComment;
struct IXmlDocument;
struct IXmlDocumentFragment;
struct IXmlDocumentIO;
struct IXmlDocumentIO2;
struct IXmlDocumentStatics;
struct IXmlDocumentType;
struct IXmlDomImplementation;
struct IXmlElement;
struct IXmlEntityReference;
struct IXmlLoadSettings;
struct IXmlNamedNodeMap;
struct IXmlNode;
struct IXmlNodeList;
struct IXmlNodeSelector;
struct IXmlNodeSerializer;
struct IXmlProcessingInstruction;
struct IXmlText;
struct DtdEntity;
struct DtdNotation;
struct XmlAttribute;
struct XmlCDataSection;
struct XmlComment;
struct XmlDocument;
struct XmlDocumentFragment;
struct XmlDocumentType;
struct XmlDomImplementation;
struct XmlElement;
struct XmlEntityReference;
struct XmlLoadSettings;
struct XmlNamedNodeMap;
struct XmlNodeList;
struct XmlProcessingInstruction;
struct XmlText;

}

namespace Windows::Data::Xml::Dom {

struct IDtdEntity;
struct IDtdNotation;
struct IXmlAttribute;
struct IXmlCDataSection;
struct IXmlCharacterData;
struct IXmlComment;
struct IXmlDocument;
struct IXmlDocumentFragment;
struct IXmlDocumentIO;
struct IXmlDocumentIO2;
struct IXmlDocumentStatics;
struct IXmlDocumentType;
struct IXmlDomImplementation;
struct IXmlElement;
struct IXmlEntityReference;
struct IXmlLoadSettings;
struct IXmlNamedNodeMap;
struct IXmlNode;
struct IXmlNodeList;
struct IXmlNodeSelector;
struct IXmlNodeSerializer;
struct IXmlProcessingInstruction;
struct IXmlText;
struct DtdEntity;
struct DtdNotation;
struct XmlAttribute;
struct XmlCDataSection;
struct XmlComment;
struct XmlDocument;
struct XmlDocumentFragment;
struct XmlDocumentType;
struct XmlDomImplementation;
struct XmlElement;
struct XmlEntityReference;
struct XmlLoadSettings;
struct XmlNamedNodeMap;
struct XmlNodeList;
struct XmlProcessingInstruction;
struct XmlText;

}

namespace Windows::Data::Xml::Dom {

template <typename T> struct impl_IDtdEntity;
template <typename T> struct impl_IDtdNotation;
template <typename T> struct impl_IXmlAttribute;
template <typename T> struct impl_IXmlCDataSection;
template <typename T> struct impl_IXmlCharacterData;
template <typename T> struct impl_IXmlComment;
template <typename T> struct impl_IXmlDocument;
template <typename T> struct impl_IXmlDocumentFragment;
template <typename T> struct impl_IXmlDocumentIO;
template <typename T> struct impl_IXmlDocumentIO2;
template <typename T> struct impl_IXmlDocumentStatics;
template <typename T> struct impl_IXmlDocumentType;
template <typename T> struct impl_IXmlDomImplementation;
template <typename T> struct impl_IXmlElement;
template <typename T> struct impl_IXmlEntityReference;
template <typename T> struct impl_IXmlLoadSettings;
template <typename T> struct impl_IXmlNamedNodeMap;
template <typename T> struct impl_IXmlNode;
template <typename T> struct impl_IXmlNodeList;
template <typename T> struct impl_IXmlNodeSelector;
template <typename T> struct impl_IXmlNodeSerializer;
template <typename T> struct impl_IXmlProcessingInstruction;
template <typename T> struct impl_IXmlText;

}

namespace Windows::Data::Xml::Dom {

enum class NodeType
{
    Invalid = 0,
    ElementNode = 1,
    AttributeNode = 2,
    TextNode = 3,
    DataSectionNode = 4,
    EntityReferenceNode = 5,
    EntityNode = 6,
    ProcessingInstructionNode = 7,
    CommentNode = 8,
    DocumentNode = 9,
    DocumentTypeNode = 10,
    DocumentFragmentNode = 11,
    NotationNode = 12,
};

}

}
