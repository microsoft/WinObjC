// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

/*	CFXMLInterface.c
	Copyright (c) 2015 Apple Inc. and the Swift project authors
 */

#include <CoreFoundation/CFRuntime.h>
#include <libxml/globals.h>
#include <libxml/xmlerror.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/tree.h>
#include <libxml/xmlmemory.h>
#include <libxml/xmlsave.h>
#include <libxml/xpath.h>
#include <libxml/dict.h>
#include "CFInternal.h"

/*
 libxml2 does not have nullability annotations and does not import well into swift when given potentially differing versions of the library that might be installed on the host operating system. This is a simple C wrapper to simplify some of that interface layer to libxml2.
 */

CFIndex _kCFXMLInterfaceRecover = XML_PARSE_RECOVER;
CFIndex _kCFXMLInterfaceNoEnt = XML_PARSE_NOENT;
CFIndex _kCFXMLInterfaceDTDLoad = XML_PARSE_DTDLOAD;
CFIndex _kCFXMLInterfaceDTDAttr = XML_PARSE_DTDATTR;
CFIndex _kCFXMLInterfaceDTDValid = XML_PARSE_DTDVALID;
CFIndex _kCFXMLInterfaceNoError = XML_PARSE_NOERROR;
CFIndex _kCFXMLInterfaceNoWarning = XML_PARSE_NOWARNING;
CFIndex _kCFXMLInterfacePedantic = XML_PARSE_PEDANTIC;
CFIndex _kCFXMLInterfaceNoBlanks = XML_PARSE_NOBLANKS;
CFIndex _kCFXMLInterfaceSAX1 = XML_PARSE_SAX1;
CFIndex _kCFXMLInterfaceXInclude = XML_PARSE_XINCLUDE;
CFIndex _kCFXMLInterfaceNoNet = XML_PARSE_NONET;
CFIndex _kCFXMLInterfaceNoDict = XML_PARSE_NODICT;
CFIndex _kCFXMLInterfaceNSClean = XML_PARSE_NSCLEAN;
CFIndex _kCFXMLInterfaceNoCdata = XML_PARSE_NOCDATA;
CFIndex _kCFXMLInterfaceNoXIncnode = XML_PARSE_NOXINCNODE;
CFIndex _kCFXMLInterfaceCompact = XML_PARSE_COMPACT;
CFIndex _kCFXMLInterfaceOld10 = XML_PARSE_OLD10;
CFIndex _kCFXMLInterfaceNoBasefix = XML_PARSE_NOBASEFIX;
CFIndex _kCFXMLInterfaceHuge = XML_PARSE_HUGE;
CFIndex _kCFXMLInterfaceOldsax = XML_PARSE_OLDSAX;
CFIndex _kCFXMLInterfaceIgnoreEnc = XML_PARSE_IGNORE_ENC;
CFIndex _kCFXMLInterfaceBigLines = XML_PARSE_BIG_LINES;

CFIndex _kCFXMLTypeInvalid = 0;
CFIndex _kCFXMLTypeDocument = XML_DOCUMENT_NODE;
CFIndex _kCFXMLTypeElement = XML_ELEMENT_NODE;
CFIndex _kCFXMLTypeAttribute = XML_ATTRIBUTE_NODE;
CFIndex _kCFXMLTypeDTD = XML_DTD_NODE;
CFIndex _kCFXMLDocTypeHTML = XML_DOC_HTML;

CFIndex _kCFXMLDTDNodeTypeEntity = XML_ENTITY_DECL;
CFIndex _kCFXMLDTDNodeTypeAttribute = XML_ATTRIBUTE_DECL;
CFIndex _kCFXMLDTDNodeTypeElement = XML_ELEMENT_DECL;
CFIndex _kCFXMLDTDNodeTypeNotation = XML_NOTATION_NODE;

CFIndex _kCFXMLDTDNodeElementTypeUndefined = XML_ELEMENT_TYPE_UNDEFINED;
CFIndex _kCFXMLDTDNodeElementTypeEmpty = XML_ELEMENT_TYPE_EMPTY;
CFIndex _kCFXMLDTDNodeElementTypeAny = XML_ELEMENT_TYPE_ANY;
CFIndex _kCFXMLDTDNodeElementTypeMixed = XML_ELEMENT_TYPE_MIXED;
CFIndex _kCFXMLDTDNodeElementTypeElement = XML_ELEMENT_TYPE_ELEMENT;

CFIndex _kCFXMLDTDNodeEntityTypeInternalGeneral = XML_INTERNAL_GENERAL_ENTITY;
CFIndex _kCFXMLDTDNodeEntityTypeExternalGeneralParsed = XML_EXTERNAL_GENERAL_PARSED_ENTITY;
CFIndex _kCFXMLDTDNodeEntityTypeExternalGeneralUnparsed = XML_EXTERNAL_GENERAL_UNPARSED_ENTITY;
CFIndex _kCFXMLDTDNodeEntityTypeInternalParameter = XML_INTERNAL_PARAMETER_ENTITY;
CFIndex _kCFXMLDTDNodeEntityTypeExternalParameter = XML_EXTERNAL_PARAMETER_ENTITY;
CFIndex _kCFXMLDTDNodeEntityTypeInternalPredefined = XML_INTERNAL_PREDEFINED_ENTITY;

CFIndex _kCFXMLDTDNodeAttributeTypeCData = XML_ATTRIBUTE_CDATA;
CFIndex _kCFXMLDTDNodeAttributeTypeID = XML_ATTRIBUTE_ID;
CFIndex _kCFXMLDTDNodeAttributeTypeIDRef = XML_ATTRIBUTE_IDREF;
CFIndex _kCFXMLDTDNodeAttributeTypeIDRefs = XML_ATTRIBUTE_IDREFS;
CFIndex _kCFXMLDTDNodeAttributeTypeEntity = XML_ATTRIBUTE_ENTITY;
CFIndex _kCFXMLDTDNodeAttributeTypeEntities = XML_ATTRIBUTE_ENTITIES;
CFIndex _kCFXMLDTDNodeAttributeTypeNMToken = XML_ATTRIBUTE_NMTOKEN;
CFIndex _kCFXMLDTDNodeAttributeTypeNMTokens = XML_ATTRIBUTE_NMTOKENS;
CFIndex _kCFXMLDTDNodeAttributeTypeEnumeration = XML_ATTRIBUTE_ENUMERATION;
CFIndex _kCFXMLDTDNodeAttributeTypeNotation = XML_ATTRIBUTE_NOTATION;

CFIndex _kCFXMLNodePreserveWhitespace = 1 << 25;
CFIndex _kCFXMLNodeCompactEmptyElement = 1 << 2;
CFIndex _kCFXMLNodePrettyPrint = 1 << 17;
CFIndex _kCFXMLNodeLoadExternalEntitiesNever = 1 << 19;
CFIndex _kCFXMLNodeLoadExternalEntitiesAlways = 1 << 14;

// We define this structure because libxml2's "notation" node does not contain the fields
// nearly all other libxml2 node fields contain, that we use extensively.
typedef struct {
    void * _private;
    xmlElementType type;
    const xmlChar* name;
    xmlNodePtr children;
    xmlNodePtr last;
    xmlNodePtr parent;
    xmlNodePtr next;
    xmlNodePtr prev;
    xmlDocPtr doc;
    xmlNotationPtr notation;
} _cfxmlNotation;

static xmlExternalEntityLoader __originalLoader = NULL;

static xmlParserInputPtr _xmlExternalEntityLoader(const char *urlStr, const char * ID, xmlParserCtxtPtr context) {
    _CFXMLInterface parser = __CFSwiftBridge.NSXMLParser.currentParser();
    if (parser != NULL) {
        return __CFSwiftBridge.NSXMLParser._xmlExternalEntityWithURL(parser, urlStr, ID, context, __originalLoader);
    }
    return __originalLoader(urlStr, ID, context);
}

void _CFSetupXMLInterface(void) {
    static dispatch_once_t xmlInitGuard;
    dispatch_once(&xmlInitGuard, ^{
        xmlInitParser();
        // set up the external entity loader
        __originalLoader = xmlGetExternalEntityLoader();
        xmlSetExternalEntityLoader(_xmlExternalEntityLoader);
    });
}

_CFXMLInterfaceParserInput _CFXMLInterfaceNoNetExternalEntityLoader(const char *URL, const char *ID, _CFXMLInterfaceParserContext ctxt) {
    return xmlNoNetExternalEntityLoader(URL, ID, ctxt);
}

static void _errorCallback(void *ctx, const char *msg, ...) {
    xmlParserCtxtPtr context = __CFSwiftBridge.NSXMLParser.getContext((_CFXMLInterface)ctx);
    xmlErrorPtr error = xmlCtxtGetLastError(context);
// TODO: reporting
//    _reportError(error, (_CFXMLInterface)ctx);
}

_CFXMLInterfaceSAXHandler _CFXMLInterfaceCreateSAXHandler() {
    _CFXMLInterfaceSAXHandler saxHandler = (_CFXMLInterfaceSAXHandler)calloc(1, sizeof(struct _xmlSAXHandler));
    saxHandler->internalSubset = (internalSubsetSAXFunc)__CFSwiftBridge.NSXMLParser.internalSubset;
    saxHandler->isStandalone = (isStandaloneSAXFunc)__CFSwiftBridge.NSXMLParser.isStandalone;
    
    saxHandler->hasInternalSubset = (hasInternalSubsetSAXFunc)__CFSwiftBridge.NSXMLParser.hasInternalSubset;
    saxHandler->hasExternalSubset = (hasExternalSubsetSAXFunc)__CFSwiftBridge.NSXMLParser.hasExternalSubset;
    
    saxHandler->getEntity = (getEntitySAXFunc)__CFSwiftBridge.NSXMLParser.getEntity;
    
    saxHandler->notationDecl = (notationDeclSAXFunc)__CFSwiftBridge.NSXMLParser.notationDecl;
    saxHandler->attributeDecl = (attributeDeclSAXFunc)__CFSwiftBridge.NSXMLParser.attributeDecl;
    saxHandler->elementDecl = (elementDeclSAXFunc)__CFSwiftBridge.NSXMLParser.elementDecl;
    saxHandler->unparsedEntityDecl = (unparsedEntityDeclSAXFunc)__CFSwiftBridge.NSXMLParser.unparsedEntityDecl;
    saxHandler->startDocument = (startDocumentSAXFunc)__CFSwiftBridge.NSXMLParser.startDocument;
    saxHandler->endDocument = (endDocumentSAXFunc)__CFSwiftBridge.NSXMLParser.endDocument;
    saxHandler->startElementNs = (startElementNsSAX2Func)__CFSwiftBridge.NSXMLParser.startElementNs;
    saxHandler->endElementNs = (endElementNsSAX2Func)__CFSwiftBridge.NSXMLParser.endElementNs;
    saxHandler->characters = (charactersSAXFunc)__CFSwiftBridge.NSXMLParser.characters;
    saxHandler->processingInstruction = (processingInstructionSAXFunc)__CFSwiftBridge.NSXMLParser.processingInstruction;
    saxHandler->error = _errorCallback;
    saxHandler->cdataBlock = (cdataBlockSAXFunc)__CFSwiftBridge.NSXMLParser.cdataBlock;
    saxHandler->comment = (commentSAXFunc)__CFSwiftBridge.NSXMLParser.comment;
    
    saxHandler->externalSubset = (externalSubsetSAXFunc)__CFSwiftBridge.NSXMLParser.externalSubset;
    
    saxHandler->initialized = XML_SAX2_MAGIC; // make sure start/endElementNS are used
    return saxHandler;
}

void _CFXMLInterfaceDestroySAXHandler(_CFXMLInterfaceSAXHandler handler) {
    free(handler);
}

void _CFXMLInterfaceSetStructuredErrorFunc(_CFXMLInterface ctx, _CFXMLInterfaceStructuredErrorFunc handler) {
    xmlSetStructuredErrorFunc(ctx, (xmlStructuredErrorFunc)handler);
}

_CFXMLInterfaceParserContext _CFXMLInterfaceCreatePushParserCtxt(_CFXMLInterfaceSAXHandler sax, _CFXMLInterface user_data, const char *chunk, int size, const char *filename) {
    return xmlCreatePushParserCtxt(sax, user_data, chunk, size, filename);
}

void _CFXMLInterfaceCtxtUseOptions(_CFXMLInterfaceParserContext ctx, CFIndex options) {
    xmlCtxtUseOptions(ctx, options);
}

int _CFXMLInterfaceParseChunk(_CFXMLInterfaceParserContext ctxt, const char *chunk, int size, int terminate) {
    return xmlParseChunk(ctxt, chunk, size, terminate);
}

void _CFXMLInterfaceStopParser(_CFXMLInterfaceParserContext ctx) {
    xmlStopParser(ctx);
}

void _CFXMLInterfaceDestroyContext(_CFXMLInterfaceParserContext ctx) {
    if (ctx == NULL) return;
    if (ctx->myDoc) {
        xmlFreeDoc(ctx->myDoc);
    }
    xmlFreeParserCtxt(ctx);
}

int _CFXMLInterfaceSAX2GetLineNumber(_CFXMLInterfaceParserContext ctx) {
    if (ctx == NULL) return 0;
    return xmlSAX2GetLineNumber(ctx);
}

int _CFXMLInterfaceSAX2GetColumnNumber(_CFXMLInterfaceParserContext ctx) {
    if (ctx == NULL) return 0;
    return xmlSAX2GetColumnNumber(ctx);
}

void _CFXMLInterfaceSAX2InternalSubset(_CFXMLInterfaceParserContext ctx,
                                       const unsigned char *name,
                                       const unsigned char *ExternalID,
                                       const unsigned char *SystemID) {
    if (ctx != NULL) xmlSAX2InternalSubset(ctx, name, ExternalID, SystemID);
}

void _CFXMLInterfaceSAX2ExternalSubset(_CFXMLInterfaceParserContext ctx,
                                       const unsigned char *name,
                                       const unsigned char *ExternalID,
                                       const unsigned char *SystemID) {
    if (ctx != NULL) xmlSAX2ExternalSubset(ctx, name, ExternalID, SystemID);
}

int _CFXMLInterfaceIsStandalone(_CFXMLInterfaceParserContext ctx) {
    if (ctx != NULL) return ctx->myDoc->standalone;
    return 0;
}

int _CFXMLInterfaceHasInternalSubset(_CFXMLInterfaceParserContext ctx) {
    if (ctx != NULL) return ctx->myDoc->intSubset != NULL;
    return 0;
}

int _CFXMLInterfaceHasExternalSubset(_CFXMLInterfaceParserContext ctx) {
    if (ctx != NULL) return ctx->myDoc->extSubset != NULL;
    return 0;
}

_CFXMLInterfaceEntity _CFXMLInterfaceGetPredefinedEntity(const unsigned char *name) {
    return xmlGetPredefinedEntity(name);
}

_CFXMLDTDNodePtr _Nullable _CFXMLDTDNewElementDesc(_CFXMLDTDPtr dtd, const unsigned char* name) {
    bool freeDTD = false;
    if (!dtd) {
        dtd = xmlNewDtd(NULL, (const xmlChar*)"tempDTD", NULL, NULL);
        freeDTD = true;
    }

    if (!name) {
        name = (const xmlChar*)"";
    }

    xmlElementPtr result = xmlAddElementDecl(NULL, dtd, name, XML_ELEMENT_TYPE_ANY, NULL);

    if (freeDTD) {
        _CFXMLUnlinkNode(result);
        xmlFreeDtd(dtd);
    }

    return result;
}

_CFXMLDTDNodePtr _Nullable _CFXMLDTDNewAttributeDesc(_CFXMLDTDPtr dtd, const unsigned char* name)
{
    bool freeDTD = false;
    if (!dtd) {
        dtd = xmlNewDtd(NULL, (const xmlChar*)"tempDTD", NULL, NULL);
        freeDTD = true;
    }

    if (!name) {
        name = (const xmlChar*)"";
    }

    xmlAttributePtr result = xmlAddAttributeDecl(NULL, dtd, NULL, name, NULL, XML_ATTRIBUTE_ID, XML_ATTRIBUTE_NONE, NULL, NULL);

    if (freeDTD) {
        _CFXMLUnlinkNode(result);
        xmlFreeDtd(dtd);
    }

    return result;
}


_CFXMLInterfaceEntity _CFXMLInterfaceSAX2GetEntity(_CFXMLInterfaceParserContext ctx, const unsigned char *name) {
    if (ctx == NULL) return NULL;
    _CFXMLInterfaceEntity entity = xmlSAX2GetEntity(ctx, name);
    if (entity && ctx->instate == XML_PARSER_CONTENT) ctx->_private = (void *)1;
    return entity;
}

int _CFXMLInterfaceInRecursiveState(_CFXMLInterfaceParserContext ctx) {
    return ctx->_private == (void *)1;
}

void _CFXMLInterfaceResetRecursiveState(_CFXMLInterfaceParserContext ctx) {
    ctx->_private = NULL;
}

int _CFXMLInterfaceHasDocument(_CFXMLInterfaceParserContext ctx) {
    if (ctx == NULL) return 0;
    return ctx->myDoc != NULL;
}

void _CFXMLInterfaceFreeEnumeration(_CFXMLInterfaceEnumeration enumeration) {
    if (enumeration == NULL) return;
    xmlFreeEnumeration(enumeration);
}

void _CFXMLInterfaceSAX2UnparsedEntityDecl(_CFXMLInterfaceParserContext ctx, const unsigned char *name, const unsigned char *publicId, const unsigned char *systemId, const unsigned char *notationName) {
    if (ctx == NULL) return;
    xmlSAX2UnparsedEntityDecl(ctx, name, publicId, systemId, notationName);
}

CFErrorRef _CFErrorCreateFromXMLInterface(_CFXMLInterfaceError err) {
    return CFErrorCreate(kCFAllocatorSystemDefault, CFSTR("NSXMLParserErrorDomain"), err->code, nil);
}

_CFXMLNodePtr _CFXMLNewNode(_CFXMLNamespacePtr namespace, const char* name) {
    return xmlNewNode(namespace, (const xmlChar*)name);
}

_CFXMLNodePtr _CFXMLCopyNode(_CFXMLNodePtr node, bool recursive) {
    int recurse = recursive ? 1 : 0;
    switch (((xmlNodePtr)node)->type) {
        case XML_DOCUMENT_NODE:
            return xmlCopyDoc(node, recurse);

        case XML_DTD_NODE:
            return xmlCopyDtd(node);

        default:
            return xmlCopyNode(node, recurse);
    }
}

_CFXMLDocPtr _CFXMLNewDoc(const unsigned char* version) {
    return xmlNewDoc(version);
}

_CFXMLNodePtr _CFXMLNewProcessingInstruction(const unsigned char* name, const unsigned char* value) {
    return xmlNewPI(name, value);
}

_CFXMLNodePtr _CFXMLNewTextNode(const unsigned char* value) {
    return xmlNewText(value);
}

_CFXMLNodePtr _CFXMLNewComment(const unsigned char* value) {
    return xmlNewComment(value);
}

_CFXMLNodePtr _CFXMLNewProperty(_CFXMLNodePtr node, const unsigned char* name, const unsigned char* value) {
    return xmlNewProp(node, name, value);
}

_CFXMLNamespacePtr _CFXMLNewNamespace(_CFXMLNodePtr node, const unsigned char* uri, const unsigned char* prefix) {
    return xmlNewNs(node, uri, prefix);
}

CF_RETURNS_RETAINED CFStringRef _CFXMLNodeURI(_CFXMLNodePtr node) {
    xmlNodePtr nodePtr = (xmlNodePtr)node;
    switch (nodePtr->type) {
        case XML_ATTRIBUTE_NODE:
        case XML_ELEMENT_NODE:
            return CFStringCreateWithCString(NULL, (const char*)nodePtr->ns->href, kCFStringEncodingUTF8);

        case XML_DOCUMENT_NODE:
        {
            xmlDocPtr doc = (xmlDocPtr)node;
            return CFStringCreateWithCString(NULL, (const char*)doc->URL, kCFStringEncodingUTF8);
        }

        default:
            return NULL;
    }
}

void _CFXMLNodeSetURI(_CFXMLNodePtr node, const unsigned char* URI) {
    xmlNodePtr nodePtr = (xmlNodePtr)node;
    switch (nodePtr->type) {
        case XML_ATTRIBUTE_NODE:
        case XML_ELEMENT_NODE:

            if (!URI) {
                if (nodePtr->ns) {
                    xmlFree(nodePtr->ns);
                }
                nodePtr->ns = NULL;
                return;
            }

            xmlNsPtr ns = xmlSearchNsByHref(nodePtr->doc, nodePtr, URI);
            if (!ns) {
                if (nodePtr->ns && (nodePtr->ns->href == NULL)) {
                    nodePtr->ns->href = xmlStrdup(URI);
                    return;
                }

                ns = xmlNewNs(nodePtr, URI, NULL);
            }

            xmlSetNs(nodePtr, ns);
            break;

        case XML_DOCUMENT_NODE:
        {
            xmlDocPtr doc = (xmlDocPtr)node;
            if (doc->URL) {
                xmlFree((xmlChar*)doc->URL);
            }
            doc->URL = URI;
        }
            break;

        default:
            return;
    }
}

void _CFXMLNodeSetPrivateData(_CFXMLNodePtr node, void* data) {
    if (!node) {
        return;
    }
    
    ((xmlNodePtr)node)->_private = data;
}

void* _Nullable  _CFXMLNodeGetPrivateData(_CFXMLNodePtr node) {
    return ((xmlNodePtr)node)->_private;
}

_CFXMLNodePtr _CFXMLNodeProperties(_CFXMLNodePtr node) {
    return ((xmlNodePtr)node)->properties;
}

CFIndex _CFXMLNodeGetType(_CFXMLNodePtr node) {
    if (!node) {
        return _kCFXMLTypeInvalid;
    }
    return ((xmlNodePtr)node)->type;
}

const char* _CFXMLNodeGetName(_CFXMLNodePtr node) {
    return (const char*)(((xmlNodePtr)node)->name);
}

void _CFXMLNodeSetName(_CFXMLNodePtr node, const char* name) {
    xmlNodeSetName(node, (const xmlChar*)name);
}

CFStringRef _CFXMLNodeGetContent(_CFXMLNodePtr node) {
    switch (((xmlNodePtr)node)->type) {
        case XML_ELEMENT_DECL:
        {
            char* buffer = calloc(2048, 1);
            xmlSnprintfElementContent(buffer, 2047, ((xmlElementPtr)node)->content, 1);
            CFStringRef result = CFStringCreateWithCString(NULL, buffer, kCFStringEncodingUTF8);
            free(buffer);
            return result;
        }

        default:
        {
            xmlChar* content = xmlNodeGetContent(node);
            if (content == NULL) {
                return NULL;
            }
            CFStringRef result = CFStringCreateWithCString(NULL, (const char*)content, kCFStringEncodingUTF8);
            xmlFree(content);
            
            return result;
        }
    }
}

void _CFXMLNodeSetContent(_CFXMLNodePtr node, const unsigned char* _Nullable  content) {
    // So handling set content on XML_ELEMENT_DECL is listed as a TODO !!! in libxml2's source code.
    // that means we have to do it ourselves.
    switch (((xmlNodePtr)node)->type) {
        case XML_ELEMENT_DECL:
        {
            xmlElementPtr element = (xmlElementPtr)node;
            if (content == NULL) {
                xmlFreeDocElementContent(element->doc, element->content);
                element->content = NULL;
                return;
            }

            // rather than writing custom code to parse the new content into the correct
            // xmlElementContent structures, let's leverage what we've already got.
            CFMutableStringRef xmlString = CFStringCreateMutable(NULL, 0);
            CFStringAppend(xmlString, CFSTR("<!ELEMENT "));
            CFStringAppendCString(xmlString, _CFXMLNodeGetName(node), kCFStringEncodingUTF8);
            CFStringAppend(xmlString, CFSTR(" "));
            CFStringAppendCString(xmlString, (const char*)content, kCFStringEncodingUTF8);
            CFStringAppend(xmlString, CFSTR(">"));

            size_t bufferSize = CFStringGetMaximumSizeForEncoding(CFStringGetLength(xmlString), kCFStringEncodingUTF8) + 1;
            char* buffer = calloc(bufferSize, 1);
            CFStringGetCString(xmlString, buffer, bufferSize, kCFStringEncodingUTF8);
            xmlElementPtr resultNode = _CFXMLParseDTDNode((const xmlChar*)buffer);

            if (resultNode) {
                xmlFreeDocElementContent(element->doc, element->content);
                _CFXMLFreeNode(element->attributes);
                xmlRegFreeRegexp(element->contModel);

                element->type = resultNode->type;
                element->etype = resultNode->etype;
                element->content = resultNode->content;
                element->attributes = resultNode->attributes;
                element->contModel = resultNode->contModel;

                resultNode->content = NULL;
                resultNode->attributes = NULL;
                resultNode->contModel = NULL;
                _CFXMLFreeNode(resultNode);
            }

            return;
        }

        default:
            if (content == NULL) {
                xmlNodeSetContent(node, nil);
                return;
            }

            xmlNodeSetContent(node, content);
    }
}

_CFXMLDocPtr _CFXMLNodeGetDocument(_CFXMLNodePtr node) {
    return ((xmlNodePtr)node)->doc;
}

CFStringRef _CFXMLEncodeEntities(_CFXMLDocPtr doc, const unsigned char* string) {
    if (!string) {
        return NULL;
    }
    
    const xmlChar* stringResult = xmlEncodeEntitiesReentrant(doc, string);
    
    CFStringRef result = CFStringCreateWithCString(NULL, (const char*)stringResult, kCFStringEncodingUTF8);

    xmlFree((xmlChar*)stringResult);

    return result;
}

static inline void _removeHashEntry(xmlHashTablePtr table, const xmlChar* name, xmlNodePtr node);
static inline void _removeHashEntry(xmlHashTablePtr table, const xmlChar* name, xmlNodePtr node) {
    if (xmlHashLookup(table, name) == node) {
        xmlHashRemoveEntry(table, name, NULL);
    }
}

void _CFXMLUnlinkNode(_CFXMLNodePtr node) {
    // DTD DECL nodes have references in the parent DTD's various hash tables.
    // For some reason, libxml2's xmlUnlinkNode doesn't actually remove those references for
    // anything other than entities, and even then only if there is a parent document!
    // To make matters worse, when you run xmlFreeDtd on the dtd, it actually deallocs everything
    // that it has a hash table reference to in addition to all of it's children. So, we need
    // to manually remove the node from the correct hash table before we can unlink it.
    switch (((xmlNodePtr)node)->type) {
        case XML_ELEMENT_DECL:
        {
            xmlElementPtr elemDecl = (xmlElementPtr)node;
            xmlDtdPtr dtd = elemDecl->parent;
            _removeHashEntry(dtd->elements, elemDecl->name, node);
        }
            break;

        case XML_ENTITY_DECL:
        {
            xmlEntityPtr entityDecl = (xmlEntityPtr)node;
            xmlDtdPtr dtd = entityDecl->parent;
            _removeHashEntry(dtd->entities, entityDecl->name, node);
            _removeHashEntry(dtd->pentities, entityDecl->name, node);
        }
            break;

        case XML_ATTRIBUTE_DECL:
        {
            xmlAttributePtr attrDecl = (xmlAttributePtr)node;
            xmlDtdPtr dtd = attrDecl->parent;
            if (xmlHashLookup3(dtd->attributes, attrDecl->name, NULL, attrDecl->elem) == node) {
                xmlHashRemoveEntry3(dtd->attributes, attrDecl->name, NULL, attrDecl->elem, NULL);
            }
        }
            break;

        case XML_NOTATION_NODE:
        {
            // Since we're handling notation nodes instead of libxml2, we need to do some extra work here
            xmlNotationPtr notation = ((_cfxmlNotation*)node)->notation;
            xmlDtdPtr dtd = (xmlDtdPtr)((_cfxmlNotation*)node)->parent;
            _removeHashEntry(dtd->notations, notation->name, (xmlNodePtr)notation);
            return;
        }

        default:
            break;
    }
    xmlUnlinkNode(node);
}

_CFXMLNodePtr _CFXMLNodeGetFirstChild(_CFXMLNodePtr node) {
    return ((xmlNodePtr)node)->children;
}

_CFXMLNodePtr _CFXMLNodeGetLastChild(_CFXMLNodePtr node) {
    return ((xmlNodePtr)node)->last;
}

_CFXMLNodePtr _CFXMLNodeGetNextSibling(_CFXMLNodePtr node) {
    return ((xmlNodePtr)node)->next;
}

_CFXMLNodePtr _CFXMLNodeGetPrevSibling(_CFXMLNodePtr node) {
    return ((xmlNodePtr)node)->prev;
}

_CFXMLNodePtr _CFXMLNodeGetParent(_CFXMLNodePtr node) {
    return ((xmlNodePtr)node)->parent;
}

bool _CFXMLDocStandalone(_CFXMLDocPtr doc) {
    return ((xmlDocPtr)doc)->standalone == 1;
}
void _CFXMLDocSetStandalone(_CFXMLDocPtr doc, bool standalone) {
    ((xmlDocPtr)doc)->standalone = standalone ? 1 : 0;
}

_CFXMLNodePtr _CFXMLDocRootElement(_CFXMLDocPtr doc) {
    return xmlDocGetRootElement(doc);
}

void _CFXMLDocSetRootElement(_CFXMLDocPtr doc, _CFXMLNodePtr node) {
    xmlDocSetRootElement(doc, node);
}

CF_RETURNS_RETAINED CFStringRef _CFXMLDocCharacterEncoding(_CFXMLDocPtr doc) {
    return CFStringCreateWithCString(NULL, (const char*)((xmlDocPtr)doc)->encoding, kCFStringEncodingUTF8);
}

void _CFXMLDocSetCharacterEncoding(_CFXMLDocPtr doc,  const unsigned char* _Nullable  encoding) {
    xmlDocPtr docPtr = (xmlDocPtr)doc;

    if (docPtr->encoding) {
        xmlFree((xmlChar*)docPtr->encoding);
    }

    docPtr->encoding = encoding;
}

CF_RETURNS_RETAINED CFStringRef _CFXMLDocVersion(_CFXMLDocPtr doc) {
    return CFStringCreateWithCString(NULL, (const char*)((xmlDocPtr)doc)->version, kCFStringEncodingUTF8);
}

void _CFXMLDocSetVersion(_CFXMLDocPtr doc, const unsigned char* version) {
    xmlDocPtr docPtr = (xmlDocPtr)doc;

    if (docPtr->version) {
        xmlFree((xmlChar*)docPtr->version);
    }

    docPtr->version = xmlStrdup(version);
}

int _CFXMLDocProperties(_CFXMLDocPtr doc) {
    return ((xmlDocPtr)doc)->properties;
}

void _CFXMLDocSetProperties(_CFXMLDocPtr doc, int newProperties) {
    ((xmlDocPtr)doc)->properties = newProperties;
}

_CFXMLDTDPtr _Nullable _CFXMLDocDTD(_CFXMLDocPtr doc) {
    return xmlGetIntSubset(doc);
}

void _CFXMLDocSetDTD(_CFXMLDocPtr doc, _CFXMLDTDPtr _Nullable dtd) {
    if (!dtd) {
        ((xmlDocPtr)doc)->intSubset = NULL;
        return;
    }

    xmlDocPtr docPtr = (xmlDocPtr)doc;
    xmlDtdPtr dtdPtr = (xmlDtdPtr)dtd;
    docPtr->intSubset = dtdPtr;
    if (docPtr->children == NULL) {
        xmlAddChild(doc, dtd);
    } else {
        xmlAddPrevSibling(docPtr->children, dtd);
    }
}

CFIndex _CFXMLNodeGetElementChildCount(_CFXMLNodePtr node) {
    return xmlChildElementCount(node);
}

void _CFXMLNodeAddChild(_CFXMLNodePtr node, _CFXMLNodePtr child) {
    if (((xmlNodePtr)node)->type == XML_NOTATION_NODE) {// the "artificial" node we created
        if (((xmlNodePtr)node)->type == XML_DTD_NODE) {// the only circumstance under which this actually makes sense
            xmlNotationPtr notation = ((_cfxmlNotation*)child)->notation;
            xmlDtdPtr dtd = (xmlDtdPtr)node;

            if (dtd->notations == NULL) {
                xmlDictPtr dict = dtd->doc ? dtd->doc->dict : NULL;
                dtd->notations = xmlHashCreateDict(0, dict);
            }
            xmlHashAddEntry(dtd->notations, notation->name, notation);
        }
        return;
    }
    xmlAddChild(node, child);
}

void _CFXMLNodeAddPrevSibling(_CFXMLNodePtr node, _CFXMLNodePtr prevSibling) {
    xmlAddPrevSibling(node, prevSibling);
}

void _CFXMLNodeAddNextSibling(_CFXMLNodePtr node, _CFXMLNodePtr nextSibling) {
    xmlAddNextSibling(node, nextSibling);
}

void _CFXMLNodeReplaceNode(_CFXMLNodePtr node, _CFXMLNodePtr replacement) {
    xmlReplaceNode(node, replacement);
}

_CFXMLEntityPtr _CFXMLGetDocEntity(_CFXMLDocPtr doc, const char* entity) {
    return xmlGetDocEntity(doc, (const xmlChar*)entity);
}

_CFXMLEntityPtr _CFXMLGetDTDEntity(_CFXMLDocPtr doc, const char* entity) {
    return xmlGetDtdEntity(doc, (const xmlChar*)entity);
}

_CFXMLEntityPtr _CFXMLGetParameterEntity(_CFXMLDocPtr doc, const char* entity) {
    return xmlGetParameterEntity(doc, (const xmlChar*)entity);
}

CFStringRef _CFXMLGetEntityContent(_CFXMLEntityPtr entity) {
    const xmlChar* content = ((xmlEntityPtr)entity)->content;
    if (!content) {
        return NULL;
    }

    CFIndex length = ((xmlEntityPtr)entity)->length;
    CFStringRef result = CFStringCreateWithBytes(NULL, content, length, kCFStringEncodingUTF8, false);

    return result;
}

CFStringRef _CFXMLStringWithOptions(_CFXMLNodePtr node, uint32_t options) {
    if (((xmlNodePtr)node)->type == XML_ENTITY_DECL &&
        ((xmlEntityPtr)node)->etype == XML_INTERNAL_PREDEFINED_ENTITY) {
        // predefined entities need special handling, libxml2 just tosses an error and returns a NULL string
        // if we try to use xmlSaveTree on a predefined entity
        CFMutableStringRef result = CFStringCreateMutable(NULL, 0);
        CFStringAppend(result, CFSTR("<!ENTITY "));
        CFStringAppendCString(result, (const char*)((xmlEntityPtr)node)->name, kCFStringEncodingUTF8);
        CFStringAppend(result, CFSTR(" \""));
        CFStringAppendCString(result, (const char*)((xmlEntityPtr)node)->content, kCFStringEncodingUTF8);
        CFStringAppend(result, CFSTR("\">"));

        return result;
    } else if (((xmlNodePtr)node)->type == XML_NOTATION_NODE) {
        // This is not actually a thing that occurs naturally in libxml2
        xmlNotationPtr notation = ((_cfxmlNotation*)node)->notation;
        CFMutableStringRef result = CFStringCreateMutable(NULL, 0);
        CFStringAppend(result, CFSTR("<!NOTATION "));
        CFStringAppendCString(result, (const char*)notation->name, kCFStringEncodingUTF8);
        CFStringAppend(result, CFSTR(" "));
        if (notation->PublicID == NULL && notation->SystemID != NULL) {
            CFStringAppend(result, CFSTR("SYSTEM "));
        } else if (notation->PublicID != NULL) {
            CFStringAppend(result, CFSTR("PUBLIC \""));
            CFStringAppendCString(result, (const char*)notation->PublicID, kCFStringEncodingUTF8);
            CFStringAppend(result, CFSTR("\""));
        }

        if (notation->SystemID != NULL) {
            CFStringAppend(result, CFSTR("\""));
            CFStringAppendCString(result, (const char*)notation->SystemID, kCFStringEncodingUTF8);
            CFStringAppend(result, CFSTR("\""));
        }

        CFStringAppend(result, CFSTR(" >"));

        return result;
    }
    
    xmlBufferPtr buffer = xmlBufferCreate();

    uint32_t xmlOptions = XML_SAVE_AS_XML;

    if (options & _kCFXMLNodePreserveWhitespace) {
        xmlOptions |= XML_SAVE_WSNONSIG;
    }

    if (!(options & _kCFXMLNodeCompactEmptyElement)) {
        xmlOptions |= XML_SAVE_NO_EMPTY;
    }

    if (options & _kCFXMLNodePrettyPrint) {
        xmlOptions |= XML_SAVE_FORMAT;
    }

    xmlSaveCtxtPtr ctx = xmlSaveToBuffer(buffer, "utf-8", xmlOptions);
    xmlSaveTree(ctx, node);
    int error = xmlSaveClose(ctx);

    if (error == -1) {
        return CFSTR("");
    }

    const xmlChar* bufferContents = xmlBufferContent(buffer);

    CFStringRef result = CFStringCreateWithCString(NULL, (const char*)bufferContents, kCFStringEncodingUTF8);

    xmlBufferFree(buffer);

    return result;
}

CF_RETURNS_RETAINED CFArrayRef _CFXMLNodesForXPath(_CFXMLNodePtr node, const unsigned char* xpath) {

    if (((xmlNodePtr)node)->doc == NULL) {
        return NULL;
    }

    xmlXPathContextPtr context = xmlXPathNewContext(((xmlNodePtr)node)->doc);
    xmlXPathObjectPtr evalResult = xmlXPathNodeEval(node, xpath, context);

    xmlNodeSetPtr nodes = evalResult->nodesetval;

    int count = nodes->nodeNr;

    CFMutableArrayRef results = CFArrayCreateMutable(NULL, count, NULL);
    for (int i = 0; i < count; i++) {
        CFArrayAppendValue(results, nodes->nodeTab[i]);
    }

    xmlFree(context);
    xmlFree(evalResult);

    return results;
}

_CFXMLNodePtr _CFXMLNodeHasProp(_CFXMLNodePtr node, const unsigned char* propertyName) {
    return xmlHasProp(node, propertyName);
}

_CFXMLDocPtr _CFXMLDocPtrFromDataWithOptions(CFDataRef data, int options) {
    uint32_t xmlOptions = 0;

    if ((options & _kCFXMLNodePreserveWhitespace) == 0) {
        xmlOptions |= XML_PARSE_NOBLANKS;
    }

    if (options & _kCFXMLNodeLoadExternalEntitiesNever) {
        xmlOptions &= ~(XML_PARSE_NOENT);
    } else {
        xmlOptions |= XML_PARSE_NOENT;
    }

    if (options & _kCFXMLNodeLoadExternalEntitiesAlways) {
        xmlOptions |= XML_PARSE_DTDLOAD;
    }

    return xmlReadMemory((const char*)CFDataGetBytePtr(data), CFDataGetLength(data), NULL, NULL, xmlOptions);
}

CF_RETURNS_RETAINED CFStringRef _CFXMLNodeLocalName(_CFXMLNodePtr node) {
    int length = 0;
    const xmlChar* result = xmlSplitQName3(((xmlNodePtr)node)->name, &length);
    return CFStringCreateWithCString(NULL, (const char*)result, kCFStringEncodingUTF8);
}

CF_RETURNS_RETAINED CFStringRef _CFXMLNodePrefix(_CFXMLNodePtr node) {
    xmlChar* result = NULL;
    xmlChar* unused = xmlSplitQName2(((xmlNodePtr)node)->name, &result);

    CFStringRef resultString = CFStringCreateWithCString(NULL, (const char*)result, kCFStringEncodingUTF8);
    xmlFree(result);
    xmlFree(unused);

    return resultString;
}

void _CFXMLValidityErrorHandler(void* ctxt, const char* msg, ...);
void _CFXMLValidityErrorHandler(void* ctxt, const char* msg, ...) {
    char* formattedMessage = calloc(1, 1024);

    va_list args;
    va_start(args, msg);
    vsprintf(formattedMessage, msg, args);
    va_end(args);

    CFStringRef message = CFStringCreateWithCString(NULL, formattedMessage, kCFStringEncodingUTF8);
    CFStringAppend(ctxt, message);
    CFRelease(message);
    free(formattedMessage);
}

bool _CFXMLDocValidate(_CFXMLDocPtr doc, CFErrorRef _Nullable * error) {
    CFMutableStringRef errorMessage = CFStringCreateMutable(NULL, 0);

    xmlValidCtxtPtr ctxt = xmlNewValidCtxt();
    ctxt->error = &_CFXMLValidityErrorHandler;
    ctxt->userData = errorMessage;

    int result = xmlValidateDocument(ctxt, doc);
    
    xmlFreeValidCtxt(ctxt);

    if (result == 0 && error != NULL) {
        CFMutableDictionaryRef userInfo = CFDictionaryCreateMutable(NULL, 1, &kCFCopyStringDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
        CFDictionarySetValue(userInfo, kCFErrorLocalizedDescriptionKey, errorMessage);

        *error = CFErrorCreate(NULL, CFSTR("NSXMLParserErrorDomain"), 0, userInfo);

        CFRelease(userInfo);
    }

    CFRelease(errorMessage);

    return result != 0;
}

_CFXMLDTDPtr _CFXMLNewDTD(_CFXMLDocPtr doc, const unsigned char* name, const unsigned char* publicID, const unsigned char* systemID) {
    return xmlNewDtd(doc, name, publicID, systemID);
}

_CFXMLDTDNodePtr _CFXMLParseDTDNode(const unsigned char* xmlString) {
    CFDataRef data = CFDataCreateWithBytesNoCopy(NULL, xmlString, xmlStrlen(xmlString), kCFAllocatorNull);
    xmlDtdPtr dtd = _CFXMLParseDTDFromData(data, NULL);
    CFRelease(data);

    if (dtd == NULL) {
        return NULL;
    }
    
    xmlNodePtr node = dtd->children;
    xmlUnlinkNode(node);

    return node;
}

_CFXMLDTDPtr _Nullable _CFXMLParseDTD(const unsigned char* URL) {
    return xmlParseDTD(NULL, URL);
}

_CFXMLDTDPtr _Nullable _CFXMLParseDTDFromData(CFDataRef data, CFErrorRef _Nullable * error) {
    xmlParserInputBufferPtr inBuffer = xmlParserInputBufferCreateMem((const char*)CFDataGetBytePtr(data), CFDataGetLength(data), XML_CHAR_ENCODING_UTF8);

    xmlSAXHandler handler;
    handler.error = &_CFXMLValidityErrorHandler;
    CFMutableStringRef errorMessage = CFStringCreateMutable(NULL, 0);
    handler._private = errorMessage;

    xmlDtdPtr dtd = xmlIOParseDTD(NULL, inBuffer, XML_CHAR_ENCODING_UTF8);

    if (dtd == NULL && error != NULL) {
        CFMutableDictionaryRef userInfo = CFDictionaryCreateMutable(NULL, 1, &kCFCopyStringDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
        CFDictionarySetValue(userInfo, kCFErrorLocalizedDescriptionKey, errorMessage);

        *error = CFErrorCreate(NULL, CFSTR("NSXMLParserErrorDomain"), 0, userInfo);

        CFRelease(userInfo);
    }
    CFRelease(errorMessage);

    return dtd;
}

CF_RETURNS_RETAINED CFStringRef _Nullable _CFXMLDTDExternalID(_CFXMLDTDPtr dtd) {
    const unsigned char* externalID = ((xmlDtdPtr)dtd)->ExternalID;
    if (externalID) {
        return CFStringCreateWithCString(NULL, (const char*)externalID, kCFStringEncodingUTF8);
    }

    return NULL;
}

void _CFXMLDTDSetExternalID(_CFXMLDTDPtr dtd, const unsigned char* externalID) {
    xmlDtdPtr dtdPtr = (xmlDtdPtr)dtd;
    if (dtdPtr->ExternalID) {
        xmlDictPtr dict = dtdPtr->doc ? dtdPtr->doc->dict : NULL;
        if (dict) {
            if (!xmlDictOwns(dict, dtdPtr->ExternalID)) {
                xmlFree((xmlChar*)dtdPtr->ExternalID);
            }
        } else {
            xmlFree((xmlChar*)dtdPtr->ExternalID);
        }
    }

    dtdPtr->ExternalID = xmlStrdup(externalID);
}

CF_RETURNS_RETAINED CFStringRef _Nullable _CFXMLDTDSystemID(_CFXMLDTDPtr dtd) {
    const unsigned char* systemID = ((xmlDtdPtr)dtd)->SystemID;
    if (systemID) {
        return CFStringCreateWithCString(NULL, (const char*)systemID, kCFStringEncodingUTF8);
    }

    return NULL;
}

void _CFXMLDTDSetSystemID(_CFXMLDTDPtr dtd, const unsigned char* systemID) {
    xmlDtdPtr dtdPtr = (xmlDtdPtr)dtd;

    if (dtdPtr->SystemID) {
        xmlDictPtr dict = dtdPtr->doc ? dtdPtr->doc->dict : NULL;
        if (dict) {
            if (!xmlDictOwns(dict, dtdPtr->SystemID)) {
                xmlFree((xmlChar*)dtdPtr->SystemID);
            }
        } else {
            xmlFree((xmlChar*)dtdPtr->SystemID);
        }
    }

    dtdPtr->SystemID = xmlStrdup(systemID);
}

_CFXMLDTDNodePtr _Nullable _CFXMLDTDGetElementDesc(_CFXMLDTDPtr dtd, const unsigned char* name) {
    return xmlGetDtdElementDesc(dtd, name);
}

_CFXMLDTDNodePtr _Nullable _CFXMLDTDGetAttributeDesc(_CFXMLDTDPtr dtd, const unsigned char* elementName, const unsigned char* name) {
    return xmlGetDtdAttrDesc(dtd, elementName, name);
}

_CFXMLDTDNodePtr _Nullable _CFXMLDTDGetNotationDesc(_CFXMLDTDPtr dtd, const unsigned char* name) {
    xmlNotationPtr notation = xmlGetDtdNotationDesc(dtd, name);
    _cfxmlNotation *notationPtr = calloc(sizeof(_cfxmlNotation), 1);
    notationPtr->type = XML_NOTATION_NODE;
    notationPtr->notation = notation;
    notationPtr->parent = dtd;
    notationPtr->doc = ((xmlDtdPtr)dtd)->doc;
    notationPtr->name = notation->name;
    
    return notationPtr;
}

_CFXMLDTDNodePtr _Nullable _CFXMLDTDGetEntityDesc(_CFXMLDTDPtr dtd, const unsigned char* name) {
    xmlDocPtr doc = ((xmlDtdPtr)dtd)->doc;
    bool createdDoc = false;
    if (doc == NULL) {
        doc = xmlNewDoc((const xmlChar*)"1.0");
        doc->extSubset = dtd;
        ((xmlDtdPtr)dtd)->doc = doc;
        createdDoc = true;
    }

    xmlEntityPtr node = xmlGetDtdEntity(doc, name);

    if (!node) {
        node = xmlGetParameterEntity(doc, name);
    }
    
    if (createdDoc) {
        doc->extSubset = NULL;
        ((xmlDtdPtr)dtd)->doc = NULL;
        xmlFreeDoc(doc);
    }

    return node;
}

_CFXMLDTDNodePtr _Nullable _CFXMLDTDGetPredefinedEntity(const unsigned char* name) {
    return xmlGetPredefinedEntity(name);
}

CFIndex _CFXMLDTDElementNodeGetType(_CFXMLDTDNodePtr node) {
    return ((xmlElementPtr)node)->etype;
}

CFIndex _CFXMLDTDEntityNodeGetType(_CFXMLDTDNodePtr node) {
    return ((xmlEntityPtr)node)->etype;
}

CFIndex _CFXMLDTDAttributeNodeGetType(_CFXMLDTDNodePtr node) {
    return ((xmlAttributePtr)node)->atype;
}

CF_RETURNS_RETAINED CFStringRef _Nullable _CFXMLDTDNodeGetSystemID(_CFXMLDTDNodePtr node) {
    switch (((xmlNodePtr)node)->type) {
        case XML_ENTITY_DECL:
            return CFStringCreateWithCString(NULL, (const char*)((xmlEntityPtr)node)->SystemID, kCFStringEncodingUTF8);

        case XML_NOTATION_NODE:
            return CFStringCreateWithCString(NULL, (const char*)((_cfxmlNotation*)node)->notation->SystemID, kCFStringEncodingUTF8);

        default:
            return NULL;
    }
}

void _CFXMLDTDNodeSetSystemID(_CFXMLDTDNodePtr node, const unsigned char* systemID) {
    switch (((xmlNodePtr)node)->type) {
        case XML_ENTITY_DECL:
        {
            xmlEntityPtr entity = (xmlEntityPtr)node;
            xmlDictPtr dict = entity->doc ? entity->doc->dict : NULL;
            if (dict) {
                if (!xmlDictOwns(dict, entity->SystemID)) {
                    xmlFree((xmlChar*)entity->SystemID);
                }
            } else {
                xmlFree((xmlChar*)entity->SystemID);
            }
            entity->SystemID = systemID ? xmlStrdup(systemID) : NULL;
            return;
        }
        case XML_NOTATION_NODE:
        {
            xmlNotationPtr notation = ((_cfxmlNotation*)node)->notation;
            xmlFree((xmlChar*)notation->SystemID);
            notation->SystemID = systemID ? xmlStrdup(systemID) : NULL;
            return;
        }

        default:
            return;
    }
}

CF_RETURNS_RETAINED CFStringRef _Nullable _CFXMLDTDNodeGetPublicID(_CFXMLDTDNodePtr node) {
    switch (((xmlNodePtr)node)->type) {
        case XML_ENTITY_DECL:
            return CFStringCreateWithCString(NULL, (const char*)((xmlEntityPtr)node)->ExternalID, kCFStringEncodingUTF8);
            
        case XML_NOTATION_NODE:
            return CFStringCreateWithCString(NULL, (const char*)((_cfxmlNotation*)node)->notation->PublicID, kCFStringEncodingUTF8);
            
        default:
            return NULL;
    }
}

void _CFXMLDTDNodeSetPublicID(_CFXMLDTDNodePtr node, const unsigned char* publicID) {
    switch (((xmlNodePtr)node)->type) {
        case XML_ENTITY_DECL:
        {
            xmlEntityPtr entity = (xmlEntityPtr)node;
            xmlDictPtr dict = entity->doc ? entity->doc->dict : NULL;
            if (dict) {
                if (!xmlDictOwns(dict, entity->ExternalID)) {
                    xmlFree((xmlChar*)entity->ExternalID);
                }
            } else {
                xmlFree((xmlChar*)entity->ExternalID);
            }
            entity->ExternalID = publicID ? xmlStrdup(publicID) : NULL;
            return;
        }
        case XML_NOTATION_NODE:
        {
            xmlNotationPtr notation = ((_cfxmlNotation*)node)->notation;
            xmlFree((xmlChar*)notation->PublicID);
            notation->PublicID = publicID ? xmlStrdup(publicID) : NULL;
            return;
        }

        default:
            return;
    }
}

void _CFXMLFreeNode(_CFXMLNodePtr node) {
    if (!node) {
        return;
    }
    
    switch (((xmlNodePtr)node)->type) {
        case XML_ENTITY_DECL:
            if (((xmlEntityPtr)node)->etype == XML_INTERNAL_PREDEFINED_ENTITY) {
                // predefined entity nodes are statically declared in libxml2 and can't be free'd
                return;
            }

        case XML_NOTATION_NODE:
            xmlFree(((_cfxmlNotation*)node)->notation);
            free(node);
            return;

        case XML_ATTRIBUTE_DECL:
        {
            // xmlFreeNode doesn't take into account peculiarities of xmlAttributePtr, such
            // as not having a content field. So we need to handle freeing it the way libxml2 would if we were
            // behaving as it expected us to.
            xmlAttributePtr attribute = (xmlAttributePtr)node;
            xmlDictPtr dict = attribute->doc ? attribute->doc->dict : NULL;
            xmlUnlinkNode(node);
            if (attribute->tree != NULL) {
                xmlFreeEnumeration(attribute->tree);
            }
            if (dict) {
                if (!xmlDictOwns(dict, attribute->elem)) {
                    xmlFree((xmlChar*)attribute->elem);
                }
                if (!xmlDictOwns(dict, attribute->name)) {
                    xmlFree((xmlChar*)attribute->name);
                }
                if (!xmlDictOwns(dict, attribute->prefix)) {
                    xmlFree((xmlChar*)attribute->prefix);
                }
                if (!xmlDictOwns(dict, attribute->defaultValue)) {
                    xmlFree((xmlChar*)attribute->defaultValue);
                }
            } else {
                xmlFree((xmlChar*)attribute->elem);
                xmlFree((xmlChar*)attribute->name);
                xmlFree((xmlChar*)attribute->prefix);
                xmlFree((xmlChar*)attribute->defaultValue);
            }
            xmlFree(attribute);
            return;
        }

        default:
            xmlFreeNode(node);
    }
}

void _CFXMLFreeDocument(_CFXMLDocPtr doc) {
    xmlFreeDoc(doc);
}

void _CFXMLFreeDTD(_CFXMLDTDPtr dtd) {
    xmlFreeDtd(dtd);
}

void _CFXMLFreeProperty(_CFXMLNodePtr prop) {
    xmlFreeProp(prop);
}
