// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


#ifndef __COREFOUNDATION_FORSWIFTFOUNDATIONONLY__
#define __COREFOUNDATION_FORSWIFTFOUNDATIONONLY__ 1

#if !defined(CF_PRIVATE)
#define CF_PRIVATE __attribute__((__visibility__("hidden")))
#endif

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFNumber.h>
#include <CoreFoundation/CFLocaleInternal.h>
#include <CoreFoundation/CFCalendar.h>
#include <CoreFoundation/CFPriv.h>
#include <CoreFoundation/CFXMLInterface.h>
#include <CoreFoundation/CFRegularExpression.h>
#include <CoreFoundation/CFLogUtilities.h>
#include <CoreFoundation/ForFoundationOnly.h>
#include <fts.h>

_CF_EXPORT_SCOPE_BEGIN

struct __CFSwiftObject {
    uintptr_t isa;
};

typedef struct __CFSwiftObject *CFSwiftRef;

#define CF_IS_SWIFT(type, obj) (_CFIsSwift(type, (CFSwiftRef)obj))

#define CF_SWIFT_FUNCDISPATCHV(type, ret, obj, fn, ...) do { \
    if (CF_IS_SWIFT(type, obj)) { \
        return (ret)__CFSwiftBridge.fn((CFSwiftRef)obj, ##__VA_ARGS__); \
    } \
} while (0)

CF_PRIVATE CF_EXPORT bool _CFIsSwift(CFTypeID type, CFSwiftRef obj);
CF_PRIVATE CF_EXPORT void _CFDeinit(CFTypeRef cf);

struct _NSObjectBridge {
    CFTypeID (*_cfTypeID)(CFTypeRef object);
    CFHashCode (*hash)(CFTypeRef object);
    bool (*isEqual)(CFTypeRef object, CFTypeRef other);
};

struct _NSArrayBridge {
    CFIndex (*_Nonnull count)(CFTypeRef obj);
    _Nonnull CFTypeRef (*_Nonnull objectAtIndex)(CFTypeRef obj, CFIndex index);
    void (*_Nonnull getObjects)(CFTypeRef array, CFRange range, CFTypeRef _Nonnull * _Nonnull values);
};

struct _NSMutableArrayBridge {
    void (*addObject)(CFTypeRef array, CFTypeRef value);
    void (*setObject)(CFTypeRef array, CFTypeRef value, CFIndex idx);
    void (*replaceObjectAtIndex)(CFTypeRef array, CFIndex idx, CFTypeRef value);
    void (*insertObject)(CFTypeRef array, CFIndex idx, CFTypeRef value);
    void (*exchangeObjectAtIndex)(CFTypeRef array, CFIndex idx1, CFIndex idx2);
    void (*removeObjectAtIndex)(CFTypeRef array, CFIndex idx);
    void (*removeAllObjects)(CFTypeRef array);
    void (*replaceObjectsInRange)(CFTypeRef array, CFRange range, CFTypeRef _Nonnull * _Nonnull newValues, CFIndex newCount);
};

struct _NSDictionaryBridge {
    CFIndex (*count)(CFTypeRef dictionary);
    CFIndex (*countForKey)(CFTypeRef dictionary, CFTypeRef key);
    bool (*containsKey)(CFTypeRef dictionary, CFTypeRef key);
    _Nullable CFTypeRef (*_Nonnull objectForKey)(CFTypeRef dictionary, CFTypeRef key);
    bool (*_getValueIfPresent)(CFTypeRef dictionary, CFTypeRef key, CFTypeRef _Nonnull * _Nullable value);
    CFIndex (*__getValue)(CFTypeRef dictionary, CFTypeRef value, CFTypeRef key);
    bool (*containsObject)(CFTypeRef dictionary, CFTypeRef value);
    CFIndex (*countForObject)(CFTypeRef dictionary, CFTypeRef value);
    void (*getObjects)(CFTypeRef dictionary, CFTypeRef _Nonnull * _Nonnull valuebuf, CFTypeRef _Nonnull * _Nonnull keybuf);
    void (*__apply)(CFTypeRef dictionary, void (*applier)(CFTypeRef key, CFTypeRef value, void *context), void *context);
};

struct _NSMutableDictionaryBridge {
    void (*__addObject)(CFTypeRef dictionary, CFTypeRef key, CFTypeRef value);
    void (*replaceObject)(CFTypeRef dictionary, CFTypeRef key, CFTypeRef value);
    void (*__setObject)(CFTypeRef dictionary, CFTypeRef key, CFTypeRef value);
    void (*removeObjectForKey)(CFTypeRef dictionary, CFTypeRef key);
    void (*removeAllObjects)(CFTypeRef dictionary);
};

struct _NSSetBridge {
    
};

struct _NSMutableSetBridge {
    
};

struct _NSStringBridge {
    _Nonnull CFTypeRef (*_Nonnull _createSubstringWithRange)(CFTypeRef str, CFRange range);
    _Nonnull CFTypeRef (*_Nonnull copy)(CFTypeRef str);
    _Nonnull CFTypeRef (*_Nonnull mutableCopy)(CFTypeRef str);
    CFIndex (*length)(CFTypeRef str);
    UniChar (*characterAtIndex)(CFTypeRef str, CFIndex idx);
    void (*getCharacters)(CFTypeRef str, CFRange range, UniChar *buffer);
    CFIndex (*__getBytes)(CFTypeRef str, CFStringEncoding encoding, CFRange range, uint8_t *buffer, CFIndex maxBufLen, CFIndex *usedBufLen);
    const char *_Nullable (*_Nonnull _fastCStringContents)(CFTypeRef str);
    const UniChar *_Nullable (*_Nonnull _fastCharacterContents)(CFTypeRef str);
    bool (*_getCString)(CFTypeRef str, char *buffer, size_t len, UInt32 encoding);
    bool (*_encodingCantBeStoredInEightBitCFString)(CFTypeRef str);
};

struct _NSMutableStringBridge {
    void (*insertString)(CFTypeRef str, CFIndex idx, CFTypeRef inserted);
    void (*deleteCharactersInRange)(CFTypeRef str, CFRange range);
    void (*replaceCharactersInRange)(CFTypeRef str, CFRange range, CFTypeRef replacement);
    void (*setString)(CFTypeRef str, CFTypeRef replacement);
    void (*appendString)(CFTypeRef str, CFTypeRef appended);
    void (*appendCharacters)(CFTypeRef str, const UniChar *chars, CFIndex appendLength);
    void (*_cfAppendCString)(CFTypeRef str, const char *chars, CFIndex appendLength);
};

struct _NSXMLParserBridge {
    _CFXMLInterface _Nullable (*_Nonnull currentParser)();
    _CFXMLInterfaceParserInput _Nonnull (*_Nonnull _xmlExternalEntityWithURL)(_CFXMLInterface interface, const char *url, const char * identifier, _CFXMLInterfaceParserContext context, _CFXMLInterfaceExternalEntityLoader originalLoaderFunction);
    
    _CFXMLInterfaceParserContext _Nonnull (*_Nonnull getContext)(_CFXMLInterface ctx);
    
    void (*internalSubset)(_CFXMLInterface ctx, const unsigned char *name, const unsigned char *ExternalID, const unsigned char *SystemID);
    int (*isStandalone)(_CFXMLInterface ctx);
    int (*hasInternalSubset)(_CFXMLInterface ctx);
    int (*hasExternalSubset)(_CFXMLInterface ctx);
    _CFXMLInterfaceEntity _Nonnull (*_Nonnull getEntity)(_CFXMLInterface ctx, const unsigned char *name);
    void (*notationDecl)(_CFXMLInterface ctx,
                         const unsigned char *name,
                         const unsigned char *publicId,
                         const unsigned char *systemId);
    void (*attributeDecl)(_CFXMLInterface ctx,
                          const unsigned char *elem,
                          const unsigned char *fullname,
                          int type,
                          int def,
                          const unsigned char *defaultValue,
                          _CFXMLInterfaceEnumeration tree);
    void (*elementDecl)(_CFXMLInterface ctx,
                        const unsigned char *name,
                        int type,
                        _CFXMLInterfaceElementContent content);
    void (*unparsedEntityDecl)(_CFXMLInterface ctx,
                               const unsigned char *name,
                               const unsigned char *publicId,
                               const unsigned char *systemId,
                               const unsigned char *notationName);
    void (*startDocument)(_CFXMLInterface ctx);
    void (*endDocument)(_CFXMLInterface ctx);
    void (*startElementNs)(_CFXMLInterface ctx,
                           const unsigned char *localname,
                           const unsigned char *prefix,
                           const unsigned char *URI,
                           int nb_namespaces,
                           const unsigned char *_Nonnull *_Nonnull namespaces,
                           int nb_attributes,
                           int nb_defaulted,
                           const unsigned char *_Nonnull *_Nonnull attributes);
    void (*endElementNs)(_CFXMLInterface ctx,
                         const unsigned char *localname,
                         const unsigned char *prefix,
                         const unsigned char *URI);
    void (*characters)(_CFXMLInterface ctx,
                       const unsigned char *ch,
                       int len);
    void (*processingInstruction)(_CFXMLInterface ctx,
                                  const unsigned char *target,
                                  const unsigned char *data);
    void (*cdataBlock)(_CFXMLInterface ctx,
                       const unsigned char *value,
                       int len);
    void (*comment)(_CFXMLInterface ctx, const unsigned char *value);
    void (*externalSubset)(_CFXMLInterface ctx,
                           const unsigned char *name,
                           const unsigned char *ExternalID,
                           const unsigned char *SystemID);
};

struct _NSRunLoop {
    _Nonnull CFTypeRef (*_Nonnull _new)(CFRunLoopRef rl);
};

struct _CFSwiftBridge {
    struct _NSObjectBridge NSObject;
    struct _NSArrayBridge NSArray;
    struct _NSMutableArrayBridge NSMutableArray;
    struct _NSDictionaryBridge NSDictionary;
    struct _NSMutableDictionaryBridge NSMutableDictionary;
    struct _NSSetBridge NSSet;
    struct _NSMutableSetBridge NSMutableSet;
    struct _NSStringBridge NSString;
    struct _NSMutableStringBridge NSMutableString;
    struct _NSXMLParserBridge NSXMLParser;
    struct _NSRunLoop NSRunLoop;
};

CF_PRIVATE CF_EXPORT struct _CFSwiftBridge __CFSwiftBridge;

CF_PRIVATE CF_EXPORT void _CFRuntimeBridgeTypeToClass(CFTypeID type, const void *isa);

typedef	unsigned char __cf_uuid[16];
typedef	char __cf_uuid_string[37];
typedef __cf_uuid _cf_uuid_t;
typedef __cf_uuid_string _cf_uuid_string_t;

CF_PRIVATE CF_EXPORT void _cf_uuid_clear(_cf_uuid_t uu);
CF_PRIVATE CF_EXPORT int _cf_uuid_compare(const _cf_uuid_t uu1, const _cf_uuid_t uu2);
CF_PRIVATE CF_EXPORT void _cf_uuid_copy(_cf_uuid_t dst, const _cf_uuid_t src);
CF_PRIVATE CF_EXPORT void _cf_uuid_generate(_cf_uuid_t out);
CF_PRIVATE CF_EXPORT void _cf_uuid_generate_random(_cf_uuid_t out);
CF_PRIVATE CF_EXPORT void _cf_uuid_generate_time(_cf_uuid_t out);
CF_PRIVATE CF_EXPORT int _cf_uuid_is_null(const _cf_uuid_t uu);
CF_PRIVATE CF_EXPORT int _cf_uuid_parse(const _cf_uuid_string_t in, _cf_uuid_t uu);
CF_PRIVATE CF_EXPORT void _cf_uuid_unparse(const _cf_uuid_t uu, _cf_uuid_string_t out);
CF_PRIVATE CF_EXPORT void _cf_uuid_unparse_lower(const _cf_uuid_t uu, _cf_uuid_string_t out);
CF_PRIVATE CF_EXPORT void _cf_uuid_unparse_upper(const _cf_uuid_t uu, _cf_uuid_string_t out);


CF_PRIVATE CF_EXPORT int32_t _CF_SOCK_STREAM();
extern CFWriteStreamRef _CFWriteStreamCreateFromFileDescriptor(CFAllocatorRef alloc, int fd);
#if !__COREFOUNDATION_FORFOUNDATIONONLY__
typedef const struct __CFKeyedArchiverUID * CFKeyedArchiverUIDRef;
extern CFTypeID _CFKeyedArchiverUIDGetTypeID(void);
extern CFKeyedArchiverUIDRef _CFKeyedArchiverUIDCreate(CFAllocatorRef allocator, uint32_t value);
extern uint32_t _CFKeyedArchiverUIDGetValue(CFKeyedArchiverUIDRef uid);
#endif

extern CFIndex __CFBinaryPlistWriteToStream(CFPropertyListRef plist, CFTypeRef stream);
extern CFDataRef _CFPropertyListCreateXMLDataWithExtras(CFAllocatorRef allocator, CFPropertyListRef propertyList);
extern CFWriteStreamRef _CFWriteStreamCreateFromFileDescriptor(CFAllocatorRef alloc, int fd);

extern _Nullable CFDateRef CFCalendarCopyGregorianStartDate(CFCalendarRef calendar);
extern void CFCalendarSetGregorianStartDate(CFCalendarRef calendar, CFDateRef date);

CF_PRIVATE CF_EXPORT char *_Nonnull*_Nonnull _CFEnviron(void);

CF_EXPORT void CFLog1(CFLogLevel lev, CFStringRef message);

_CF_EXPORT_SCOPE_END

#endif /* __COREFOUNDATION_FORSWIFTFOUNDATIONONLY__ */
