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

#include "Starboard.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSData.h"
#include "Foundation/NSAutoreleasePool.h"
#include "Foundation/NSXMLParser.h"

#include <libxml/parser.h>

//#define LOG_PARSED

@implementation NSXMLParser : NSObject

/**
 @Status Interoperable
*/
- (instancetype)initWithContentsOfURL:(id)URL {
    return [self initWithContentsOfFile:[URL path]];
}

- (instancetype)initWithContentsOfFile:(id)path {
    id data = [[NSData alloc] initWithContentsOfFile:path];
    if (data == nil) {
        [self dealloc];
        return nil;
    }

    id ret = [self initWithData:data];
    [data release];

    return ret;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithData:(id)data {
    _data = [data retain];

    return self;
}

- (void)dealloc {
    [_data release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id)delegate {
    _delegate = delegate;
    _hasDidStartElement = [_delegate respondsToSelector:@selector(parser:didStartElement:namespaceURI:qualifiedName:attributes:)] != FALSE;
    _hasDidEndElement = [_delegate respondsToSelector:@selector(parser:didEndElement:namespaceURI:qualifiedName:)] != FALSE;
    _hasFoundCharacters = [_delegate respondsToSelector:@selector(parser:foundCharacters:)] != FALSE;
    _hasFoundCData = [_delegate respondsToSelector:@selector(parser:foundCDATA:)] != FALSE;
}

/**
 @Status Interoperable
*/
- (id)delegate {
    return _delegate;
}

/**
 @Status Stub
*/
- (void)setShouldProcessNamespaces:(BOOL)flag {
    UNIMPLEMENTED();
    _shouldProcessNamespaces = flag;
}

/**
 @Status Stub
*/
- (void)setShouldReportNamespacePrefixes:(BOOL)flag {
    UNIMPLEMENTED();
    _shouldReportNamespacePrefixes = flag;
}

/**
 @Status Interoperable
*/
- (BOOL)shouldProcessNamespaces {
    return _shouldProcessNamespaces;
}

/**
 @Status Interoperable
*/
- (BOOL)shouldReportNamespacePrefixes {
    return _shouldReportNamespacePrefixes;
}

/**
 @Status Stub
*/
- (void)setShouldResolveExternalEntities:(BOOL)flag {
    UNIMPLEMENTED();
    _shouldResolveExternalEntities = flag;
}

/**
 @Status Interoperable
*/
- (BOOL)shouldResolveExternalEntities {
    return _shouldResolveExternalEntities;
}

static void startDocumentCallback(void* ctx) {
    NSXMLParser* self = (NSXMLParser*)ctx;

    if ([self->_delegate respondsToSelector:@selector(parserDidStartDocument:)])
        [self->_delegate parserDidStartDocument:self];
}

static void endDocumentCallback(void* ctx) {
    NSXMLParser* self = (NSXMLParser*)ctx;

    if ([self->_delegate respondsToSelector:@selector(parserDidEndDocument:)])
        [self->_delegate parserDidEndDocument:self];
}

static void warningCallback(void* ctx, const char* msg, ...) {
    NSXMLParser* self = (NSXMLParser*)ctx;

    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
}

static void startElementCallback(void* ctx, const xmlChar* name, const xmlChar** atts) {
    NSXMLParser* self = (NSXMLParser*)ctx;

    if (self->_hasDidStartElement) {
        const xmlChar** currAttr = atts;

        id attrs = nil;

        if (!currAttr || !*currAttr) {
            attrs = [self->_emptyDictionary retain];
        } else {
            attrs = [NSMutableDictionary new];
            while (currAttr && *currAttr) {
                id key = [[NSString alloc] initWithUTF8String:(const char*)currAttr[0]];
                id val = [[NSString alloc] initWithUTF8String:(const char*)currAttr[1]];

                [attrs setObject:val forKey:key];
                [key release];
                [val release];

                currAttr += 2;
            }
        }

        id nameString = [[NSString alloc] initWithUTF8String:(const char*)name];

        [self->_delegate parser:self didStartElement:nameString namespaceURI:nil qualifiedName:nil attributes:attrs];

        [nameString release];
        [attrs release];
    }
}

static void endElementCallback(void* ctx, const xmlChar* name) {
    NSXMLParser* self = (NSXMLParser*)ctx;

    if (self->_hasDidEndElement) {
        id nameString = [[NSString alloc] initWithUTF8String:(const char*)name];
        [self->_delegate parser:self didEndElement:nameString namespaceURI:nil qualifiedName:nil];
        [nameString release];
    }
}

static void charactersCallback(void* ctx, const xmlChar* ch, int len) {
    NSXMLParser* self = (NSXMLParser*)ctx;

    if (self->_hasFoundCharacters) {
        id str = [[NSString alloc] initWithBytes:ch length:len encoding:NSUTF8StringEncoding];
        [self->_delegate parser:self foundCharacters:str];
        [str release];
    }
}

static void cdataCallback(void* ctx, const xmlChar* value, int len) {
    NSXMLParser* self = (NSXMLParser*)ctx;

    if (self->_hasFoundCData) {
        id data = [NSData dataWithBytes:value length:len];
        [self->_delegate parser:self foundCDATA:data];
    }
}

static xmlEntityPtr entityCallback(void* user_data, const xmlChar* name) {
    return xmlGetPredefinedEntity(name);
}

/**
 @Status Interoperable
*/
- (BOOL)parse {
    _bytes = (uint8_t*)[_data bytes];
    _length = [_data length];
    _emptyDictionary = [NSDictionary new];

    xmlSubstituteEntitiesDefault(1);

    xmlSAXHandler sax;
    memset(&sax, 0, sizeof(sax));
    sax.initialized = XML_SAX2_MAGIC;
    sax.startDocument = startDocumentCallback;
    sax.endDocument = endDocumentCallback;
    sax.warning = warningCallback;
    sax.startElement = startElementCallback;
    sax.endElement = endElementCallback;
    sax.characters = charactersCallback;
    sax.cdataBlock = cdataCallback;
    sax.getEntity = entityCallback;

    int ret = xmlSAXUserParseMemory(&sax, (void*)self, (const char*)_bytes, _length);
    [_emptyDictionary release];

    return ret == 0;
}

void abortParsing__unused() {
    // NSUnimplementedMethod();
    assert(0);
}

/**
 @Status Stub
*/
- (NSError*)parserError {
    UNIMPLEMENTED();
    return _parserError;
}

/**
 @Status Stub
*/
- (NSString*)systemID {
    UNIMPLEMENTED();
    return _systemID;
}

/**
 @Status Stub
*/
- (NSString*)publicID {
    UNIMPLEMENTED();
    return _publicID;
}

/**
 @Status Stub
*/
- (int)columnNumber {
    UNIMPLEMENTED();
    return xmlSAX2GetColumnNumber((void*)self);
}

/**
 @Status Stub
*/
- (int)lineNumber {
    UNIMPLEMENTED();
    return xmlSAX2GetColumnNumber((void*)self);
}

@end
