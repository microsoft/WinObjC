/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSXMLPARSER_H_
#define _NSXMLPARSER_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>
#import <Foundation/NSHashTable.h>

enum {
    NSXMLParserInternalError = 1,
    NSXMLParserOutOfMemoryError = 2,
    NSXMLParserDocumentStartError = 3,
    NSXMLParserEmptyDocumentError = 4,
    NSXMLParserPrematureDocumentEndError = 5,
    NSXMLParserInvalidHexCharacterRefError = 6,
    NSXMLParserInvalidDecimalCharacterRefError = 7,
    NSXMLParserInvalidCharacterRefError = 8,
    NSXMLParserInvalidCharacterError = 9,
    NSXMLParserCharacterRefAtEOFError = 10,
    NSXMLParserCharacterRefInPrologError = 11,
    NSXMLParserCharacterRefInEpilogError = 12,
    NSXMLParserCharacterRefInDTDError = 13,
    NSXMLParserEntityRefAtEOFError = 14,
    NSXMLParserEntityRefInPrologError = 15,
    NSXMLParserEntityRefInEpilogError = 16,
    NSXMLParserEntityRefInDTDError = 17,
    NSXMLParserParsedEntityRefAtEOFError = 18,
    NSXMLParserParsedEntityRefInPrologError = 19,
    NSXMLParserParsedEntityRefInEpilogError = 20,
    NSXMLParserParsedEntityRefInInternalSubsetError = 21,
    NSXMLParserEntityReferenceWithoutNameError = 22,
    NSXMLParserEntityReferenceMissingSemiError = 23,
    NSXMLParserParsedEntityRefNoNameError = 24,
    NSXMLParserParsedEntityRefMissingSemiError = 25,
    NSXMLParserUndeclaredEntityError = 26,
    NSXMLParserUnparsedEntityError = 28,
    NSXMLParserEntityIsExternalError = 29,
    NSXMLParserEntityIsParameterError = 30,
    NSXMLParserUnknownEncodingError = 31,
    NSXMLParserEncodingNotSupportedError = 32,
    NSXMLParserStringNotStartedError = 33,
    NSXMLParserStringNotClosedError = 34,
    NSXMLParserNamespaceDeclarationError = 35,
    NSXMLParserEntityNotStartedError = 36,
    NSXMLParserEntityNotFinishedError = 37,
    NSXMLParserLessThanSymbolInAttributeError = 38,
    NSXMLParserAttributeNotStartedError = 39,
    NSXMLParserAttributeNotFinishedError = 40,
    NSXMLParserAttributeHasNoValueError = 41,
    NSXMLParserAttributeRedefinedError = 42,
    NSXMLParserLiteralNotStartedError = 43,
    NSXMLParserLiteralNotFinishedError = 44,
    NSXMLParserCommentNotFinishedError = 45,
    NSXMLParserProcessingInstructionNotStartedError = 46,
    NSXMLParserProcessingInstructionNotFinishedError = 47,
    NSXMLParserNotationNotStartedError = 48,
    NSXMLParserNotationNotFinishedError = 49,
    NSXMLParserAttributeListNotStartedError = 50,
    NSXMLParserAttributeListNotFinishedError = 51,
    NSXMLParserMixedContentDeclNotStartedError = 52,
    NSXMLParserMixedContentDeclNotFinishedError = 53,
    NSXMLParserElementContentDeclNotStartedError = 54,
    NSXMLParserElementContentDeclNotFinishedError = 55,
    NSXMLParserXMLDeclNotStartedError = 56,
    NSXMLParserXMLDeclNotFinishedError = 57,
    NSXMLParserConditionalSectionNotStartedError = 58,
    NSXMLParserConditionalSectionNotFinishedError = 59,
    NSXMLParserExternalSubsetNotFinishedError = 60,
    NSXMLParserDOCTYPEDeclNotFinishedError = 61,
    NSXMLParserMisplacedCDATAEndStringError = 62,
    NSXMLParserCDATANotFinishedError = 63,
    NSXMLParserMisplacedXMLDeclarationError = 64,
    NSXMLParserSpaceRequiredError = 65,
    NSXMLParserSeparatorRequiredError = 66,
    NSXMLParserNMTOKENRequiredError = 67,
    NSXMLParserNAMERequiredError = 68,
    NSXMLParserPCDATARequiredError = 69,
    NSXMLParserURIRequiredError = 70,
    NSXMLParserPublicIdentifierRequiredError = 71,
    NSXMLParserLTRequiredError = 72,
    NSXMLParserGTRequiredError = 73,
    NSXMLParserLTSlashRequiredError = 74,
    NSXMLParserEqualExpectedError = 75,
    NSXMLParserTagNameMismatchError = 76,
    NSXMLParserUnfinishedTagError = 77,
    NSXMLParserStandaloneValueError = 78,
    NSXMLParserInvalidEncodingNameError = 79,
    NSXMLParserCommentContainsDoubleHyphenError = 80,
    NSXMLParserInvalidEncodingError = 81,
    NSXMLParserExternalStandaloneEntityError = 82,
    NSXMLParserInvalidConditionalSectionError = 83,
    NSXMLParserEntityValueRequiredError = 84,
    NSXMLParserNotWellBalancedError = 85,
    NSXMLParserExtraContentError = 86,
    NSXMLParserInvalidCharacterInEntityError = 87,
    NSXMLParserParsedEntityRefInInternalError = 88,
    NSXMLParserEntityRefLoopError = 89,
    NSXMLParserEntityBoundaryError = 90,
    NSXMLParserInvalidURIError = 91,
    NSXMLParserURIFragmentError = 92,
    NSXMLParserNoDTDError = 94,
    NSXMLParserDelegateAbortedParseError = 512
};
typedef uint32_t NSXMLParserError;

@class NSURL, NSData, NSError, NSXMLParser, NSDictionary, NSMutableArray, NSMutableDictionary;

@protocol NSXMLParserDelegate
@optional

/**
 @Status Interoperable
*/
- (void)parserDidStartDocument:(NSXMLParser *)parser;

/**
 @Status Interoperable
*/
- (void)parserDidEndDocument:(NSXMLParser *)parser;

- (void)parser:(NSXMLParser *)parser foundElementDeclarationWithName:(NSString *)elementName model:(NSString *)model;

/**
 @Status Caveat
 @Notes nameSpaceURI and qualifiedName are always nil
*/
- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributes;

/**
 @Status Caveat
 @Notes nameSpaceURI and qualifiedName are always nil
*/
- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName;

- (void)parser:(NSXMLParser *)parser foundAttributeDeclarationWithName:(NSString *)attributeName forElement:(NSString *)elementName type:(NSString *)type defaultValue:(NSString *)defaultValue;

- (void)parser:(NSXMLParser *)parser didStartMappingPrefix:(NSString *)prefix toURI:(NSString *)uri;
- (void)parser:(NSXMLParser *)parser didEndMappingPrefix:(NSString *)prefix;

/**
 @Status Interoperable
*/
- (void)parser:(NSXMLParser *)parser foundCDATA:(NSData *)cdata;

/**
 @Status Interoperable
*/
- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string;

/**
 @Status Interoperable
*/
- (void)parser:(NSXMLParser *)parser foundComment:(NSString *)comment;
- (void)parser:(NSXMLParser *)parser foundIgnorableWhitespace:(NSString *)whitespace;

- (void)parser:(NSXMLParser *)parser foundExternalEntityDeclarationWithName:(NSString *)entityName publicID:(NSString *)publicID systemID:(NSString *)systemID;
- (void)parser:(NSXMLParser *)parser foundInternalEntityDeclarationWithName:(NSString *)entityName value:(NSString *)value;
- (void)parser:(NSXMLParser *)parser foundNotationDeclarationWithName:(NSString *)name publicID:(NSString *)publicID systemID:(NSString *)systemID;
- (void)parser:(NSXMLParser *)parser foundProcessingInstructionWithTarget:(NSString *)target data:(NSString *)data;
- (void)parser:(NSXMLParser *)parser foundUnparsedEntityDeclarationWithName:(NSString *)name publicID:(NSString *)publicID systemID:(NSString *)systemID notationName:(NSString *)notationName;
- (void)parser:(NSXMLParser *)parser parseErrorOccurred:(NSError *)parseError;
- (NSData *)parser:(NSXMLParser *)parser resolveExternalEntityName:(NSString *)entityName systemID:(NSString *)systemID;
- (void)parser:(NSXMLParser *)parser validationErrorOccurred:(NSError *)validationError;

@end

FOUNDATION_EXPORT_CLASS
@interface NSXMLParser : NSObject {
    id _data;
    id _delegate;
    BOOL _shouldProcessNamespaces;
    BOOL _shouldReportNamespacePrefixes;
    BOOL _shouldResolveExternalEntities;
    id  _parserError;
    id _systemID;
    id _publicID;
    id _emptyDictionary;

    // input:
    const uint8_t*       _bytes;
    NSUInteger           _length;

    // optimizations:
    bool _hasDidStartElement, _hasDidEndElement;
    bool _hasFoundCharacters, _hasFoundCData;
}

- initWithData:(NSData *)data;
- (id)initWithContentsOfURL:(NSURL *)url;

- delegate;
- (BOOL)shouldProcessNamespaces;
- (BOOL)shouldReportNamespacePrefixes;
- (BOOL)shouldResolveExternalEntities;

- (void)setDelegate:delegate;
- (void)setShouldProcessNamespaces:(BOOL)flag;
- (void)setShouldReportNamespacePrefixes:(BOOL)flag;
- (void)setShouldResolveExternalEntities:(BOOL)flag;

- (BOOL)parse;
- (void)abortParsing;
- (NSError *)parserError;

- (NSString *)systemID;
- (NSString *)publicID;
- (NSInteger)columnNumber;
- (NSInteger)lineNumber;

- (void)parser:(NSXMLParser *)parser foundElementDeclarationWithName:(NSString *)elementName model:(NSString *)model;
- (void)parser:(NSXMLParser *)parser foundAttributeDeclarationWithName:(NSString *)attributeName forElement:(NSString *)elementName type:(NSString *)type defaultValue:(NSString *)defaultValue;
- (void)parser:(NSXMLParser *)parser foundExternalEntityDeclarationWithName:(NSString *)entityName publicID:(NSString *)publicID systemID:(NSString *)systemID;
- (void)parser:(NSXMLParser *)parser foundNotationDeclarationWithName:(NSString *)name publicID:(NSString *)publicID systemID:(NSString *)systemID;
- (void)parser:(NSXMLParser *)parser foundUnparsedEntityDeclarationWithName:(NSString *)name publicID:(NSString *)publicID systemID:(NSString *)systemID notationName:(NSString *)notationName;
- (void)parser:(NSXMLParser *)parser foundInternalEntityDeclarationWithName:(NSString *)name value:(NSString *)value;

@end

#endif /* _NSXMLPARSER_H_ */
