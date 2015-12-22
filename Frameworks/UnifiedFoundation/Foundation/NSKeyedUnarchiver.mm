/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include "Starboard.h"

#include "CoreFoundation/CFDictionary.h"

#include "Foundation/NSDictionary.h"
#include "Foundation/NSString.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSKeyedUnarchiver.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSData.h"
#include "Foundation/NSValue.h"
#include "NSPropertyListReader.h"
#include "NSXMLPropertyList.h"

#include <stack>
#include <memory>
#include <functional>

NSString* NSInvalidUnarchiveOperationException = @"NSInvalidUnarchiveOperationException";
static NSString* _NSUnarchiverEncounteredInvalidClassException = @"_NSUnarchiverEncounteredInvalidClassException";
static NSString* _NSUnarchiverEncounteredInvalidClassExceptionClassType = @"_NSUnarchiverEncounteredInvalidClassExceptionClassType";
static NSString* _NSUnarchiverEncounteredInvalidClassExceptionExpectedClasses =
    @"_NSUnarchiverEncounteredInvalidClassExceptionExpectedClasses";

static IWLazyClassLookup _LazyUIClassSwapper("UIClassSwapper");

@implementation NSKeyedUnarchiver {
    idretaintype(NSMutableDictionary) _nameToReplacementClass;
    idretaintype(NSDictionary) _propertyList;
    idretaintype(NSArray) _objects;
    idretaintype(NSMutableArray) _plistStack;
    idretaintype(NSMutableDictionary) _uidToObject;
    idretaintype(NSMutableDictionary) _objectToUid;
    idretaintype(NSMutableDictionary) _classVersions;

    int _unnamedKeyIndex;

    idretaintype(NSMutableArray) _dataObjects;
    idretaintype(NSBundle) _bundle;
    int _curUid;

    BOOL _requiresSecureCoding;
    std::stack<idretaint<NSSet>> _expectedClassesInDecodePass;
    bool _objectFailedSecureDecoding;
}

- (BOOL)requiresSecureCoding {
    return _requiresSecureCoding;
}

- (void)setRequiresSecureCoding:(BOOL)requiresSecureCoding {
    if (_requiresSecureCoding && !requiresSecureCoding) {
        [NSException raise:NSInvalidUnarchiveOperationException
                    format:@"an unarchiver, once set to require secure coding, cannot be stripped of that requirement."];
    }
    _requiresSecureCoding = requiresSecureCoding;
}

- (NSSet*)allowedClasses {
    return [[_expectedClassesInDecodePass.top() copy] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initForReadingWithData:(NSData*)data {
    if (data == nil) {
        return nil;
    }

    _nameToReplacementClass.attach([NSMutableDictionary new]);

    char* bytes = (char*)[data bytes];
    if (memcmp(bytes, "<?xml", 5) == 0) {
        bool returnNow = false;

        if (returnNow) {
            return nil;
        }
        _propertyList = [NSXMLPropertyList propertyListFromData:data];
    } else {
        NSPropertyListReaderA read;
        read.init(data);
        _propertyList = read.read();
    }
    _objects = [_propertyList objectForKey:@"$objects"];
    _plistStack.attach([NSMutableArray new]);

    if ([_propertyList objectForKey:@"$top"] != nil) {
        [_plistStack addObject:[_propertyList objectForKey:@"$top"]];
    }

    _uidToObject.attach((NSMutableDictionary*)CFDictionaryCreateMutable(nullptr, 128, &kCFTypeDictionaryKeyCallBacks, NULL));

    _dataObjects.attach([NSMutableArray new]);

    _expectedClassesInDecodePass.emplace(); // nil first entry

    return self;
}

static id decodeClassFromDictionary(NSKeyedUnarchiver* self, id classReference) {
    id plist = [classReference objectForKey:@"$class"];
    id uid = [plist objectForKey:@"CF$UID"];
    id profile = [self->_objects objectAtIndex:[uid intValue]];
    id classes = [profile objectForKey:@"$classes"];
    id className = [profile objectForKey:@"$classname"];

    return className;
}

static inline void checkClassForSecureCodingCompliance(NSKeyedUnarchiver* self, Class checkingClass) {
    if (![self requiresSecureCoding]) {
        return;
    }

    if ([checkingClass conformsToProtocol:@protocol(NSSecureCoding)] &&
        [reinterpret_cast<id<NSSecureCoding>>(checkingClass) supportsSecureCoding]) {
        return;
    }

    self->_objectFailedSecureDecoding = true;
    [NSException raise:NSInvalidUnarchiveOperationException
                format:@"This decoder will only decode classes that adopt NSSecureCoding. Class '%@' does not adopt it.", checkingClass];
}

static inline void checkClassAgainstExpectedClasses(NSKeyedUnarchiver* self, Class checkingClass, NSSet* expectedClasses) {
    if (![self requiresSecureCoding]) {
        return;
    }

    for (Class expectedClass in expectedClasses) {
        if ([checkingClass isSubclassOfClass:expectedClass]) {
            return;
        }
    }

    self->_objectFailedSecureDecoding = true;
    [[NSException exceptionWithName:_NSUnarchiverEncounteredInvalidClassException
                             reason:nil
                           userInfo:@{
                               _NSUnarchiverEncounteredInvalidClassExceptionClassType : checkingClass,
                               _NSUnarchiverEncounteredInvalidClassExceptionExpectedClasses : expectedClasses
                           }] raise];
}

static id decodeObjectForUID(NSKeyedUnarchiver* self, NSNumber* uid) {
    DWORD uidIntValue = [uid intValue];
    id result = [self->_uidToObject objectForKey:uid];

    if (result == NULL) {
        id plist = [self->_objects objectAtIndex:uidIntValue];

        // NSString and NSNumber can be returned directly without a class check.
        if ([plist isKindOfClass:[NSString class]]) {
            if ([plist isEqualToString:@"$null"]) {
                result = NULL;
            } else {
                result = plist;
            }
        } else if ([plist isKindOfClass:[NSNumber class]]) {
            result = plist;
        } else if ([plist isKindOfClass:[NSDictionary class]]) {
            // NSDictionary could be an object masquerading as a dictionary;
            // it performs its class check manually.
            id className = decodeClassFromDictionary(self, plist);

            Class classType = NSClassFromString(className);

            // These two methods will except (correct behaviour) if they fail to match.
            checkClassAgainstExpectedClasses(self, classType, self->_expectedClassesInDecodePass.top());
            checkClassForSecureCodingCompliance(self, classType);

            Class mapped = [classType classForKeyedUnarchiver];
            if (mapped != nil) {
                classType = mapped;
            }

            [self->_plistStack addObject:plist];
            if (classType != nil) {
                result = [classType alloc];

                if ([result isKindOfClass:[_LazyUIClassSwapper class]]) {
                    [self->_uidToObject setObject:result forKey:uid];

                    int curPos = self->_curUid;

                    self->_curUid = 0;

                    id orig = result;
                    result = [result instantiateWithCoder:self];
                    [orig autorelease];

                    self->_curUid = curPos;
                }

                [self->_uidToObject setObject:result forKey:uid];

                int curPos = self->_curUid;

                self->_curUid = 0;
                if ([result respondsToSelector:@selector(initWithCoder:)]) {
                    result = [result initWithCoder:self];
                } else {
                    if (result != nil) {
                        [NSException
                             raise:NSInvalidUnarchiveOperationException
                            format:@"instances of class '%@' do not conform to the NSCoding protocol; please implement -initWithCoder:",
                                   classType];
                    }
                }

                self->_curUid = curPos;

                if (result != nil) {
                    [self->_uidToObject setObject:result forKey:uid];
                    if ([result respondsToSelector:@selector(awakeAfterUsingCoder:)]) {
                        result = [result awakeAfterUsingCoder:self];
                    }

                    [result autorelease];
                } else {
                    [NSException raise:NSInvalidUnarchiveOperationException
                                format:@"failed to instantiate class '%@' during unarchival", classType];
                }
            }

            [self->_plistStack removeLastObject];
        } else {
            // Everything else requires a class check.

            // This might except. Let it.
            checkClassAgainstExpectedClasses(self, object_getClass(plist), self->_expectedClassesInDecodePass.top());
            result = plist;

            if ([plist isKindOfClass:[NSData class]]) {
                result = plist;
            } else if ([plist isKindOfClass:[NSDate class]]) {
                result = plist;
            } else {
                [NSException raise:NSInvalidUnarchiveOperationException
                            format:@"failed to unarchive unknown object of class '%@'", object_getClass(plist)];
            }
        }

        if (result) {
            [self->_uidToObject setObject:result forKey:uid];
        }
    }

    return result;
}

- (id)decodeRootObject {
    id top = [_propertyList objectForKey:@"$top"];
    id values = [top allValues];

    if ([values count] != 1) {
        [NSException raise:NSInvalidUnarchiveOperationException format:@"attempted to unarchive data with multiple root objects"];
        return nil;
    } else {
        id object = [values objectAtIndex:0];
        id uid = [object objectForKey:@"CF$UID"];

        return decodeObjectForUID(self, uid);
    }
}

static id unarchiveObjectWithData(id data) {
    id unarchiver = [NSKeyedUnarchiver alloc];
    [unarchiver initForReadingWithData:data];

    return [unarchiver decodeRootObject];
}

static BOOL containsValueForKey(NSKeyedUnarchiver* self, NSString* key) {
    return [[self->_plistStack lastObject] objectForKey:key] != NULL ? TRUE : FALSE;
}

static id _decodeObjectWithPropertyList(NSKeyedUnarchiver* self, id plist) {
    if ([plist isKindOfClass:[NSString class]] || [plist isKindOfClass:[NSData class]] || [plist isKindOfClass:[NSNumber class]]) {
        return plist;
    }

    if ([plist isKindOfClass:[NSDictionary class]]) {
        id uid = [plist objectForKey:@"CF$UID"];

        return decodeObjectForUID(self, uid);
    } else if ([plist isKindOfClass:[NSArray class]]) {
        id result = [NSMutableArray array];
        DWORD i, count = [plist count];

        for (i = 0; i < count; i++) {
            id sibling = [plist objectAtIndex:i];
            id objValue = _decodeObjectWithPropertyList(self, sibling);

            if (objValue != nil) {
                [result addObject:objValue];
            }
        }

        return result;
    }

    [NSException raise:NSInvalidUnarchiveOperationException
                format:@"unable to decode property list object with class %@", object_getClass(plist)];
    return nil;
}

/**
 @Status Interoperable
*/
- (id)decodeObjectForKey:(NSString*)key {
    if (_objectFailedSecureDecoding) {
        // This flag is set when we fail an object class check.
        // Empirically observed: On the reference platform, any decoding requests
        // after an object check failure return nil.
        return nil;
    }

    @try {
        id plist = [[_plistStack lastObject] objectForKey:key];

        if (!plist) {
            return nil;
        }

        return _decodeObjectWithPropertyList(self, plist);
    } @catch (NSException* exception) {
        if ([[exception name] isEqual:_NSUnarchiverEncounteredInvalidClassException]) {
            Class invalidClass = reinterpret_cast<Class>([exception userInfo][_NSUnarchiverEncounteredInvalidClassExceptionClassType]);
            NSSet* expectedClasses =
                reinterpret_cast<NSSet*>([exception userInfo][_NSUnarchiverEncounteredInvalidClassExceptionExpectedClasses]);
            [NSException
                 raise:NSInvalidUnarchiveOperationException
                format:@"value for key '%@' was of unexpected class '%@'. Allowed classes are '%@'.", key, invalidClass, expectedClasses];
        } else {
            [exception raise];
        }
    }
}

- (id)decodeObjectOfClass:(Class)expectedClass forKey:(NSString*)key {
    return [self decodeObjectOfClasses:[NSSet setWithObject:expectedClass] forKey:key];
}

- (id)decodeObjectOfClasses:(NSSet*)expectedClasses forKey:(NSString*)key {
    _expectedClassesInDecodePass.emplace(expectedClasses);
    auto deferPop = wil::ScopeExit([&self](){ _expectedClassesInDecodePass.pop(); });

    return [self decodeObjectForKey:key];
}

static id _numberForKey(NSKeyedUnarchiver* self, id key) {
    id result = [[self->_plistStack lastObject] objectForKey:key];
    if (!result || [result isKindOfClass:[NSNumber class]]) {
        return result;
    }

    [NSException raise:NSInvalidUnarchiveOperationException format:@"value for key '%@' is not an unboxed number", key];
    return nil;
}

static id _valueForKey(NSKeyedUnarchiver* self, id key) {
    return [self decodeObjectOfClass:[NSValue class] forKey:key];
}

/**
 @Status Interoperable
*/
- (BOOL)containsValueForKey:(NSString*)key {
    return ([[_plistStack lastObject] objectForKey:key] != nil) ? TRUE : FALSE;
}

- (id)decodeObject {
    NSString* idNum = [NSString stringWithFormat:@"$%d", _curUid++];
    return [self decodeObjectForKey:idNum];
}

/**
 @Status Interoperable
*/
- (int)decodeIntForKey:(NSString*)key {
    id number = _numberForKey(self, key);

    if (number == nil) {
        return 0;
    }

    return [number intValue];
}

/**
 @Status Interoperable
*/
- (int)decodeInt32ForKey:(NSString*)key {
    return [self decodeIntForKey:key];
}

- (int)decodeIntegerForKey:(NSString*)key {
    return [self decodeIntForKey:key];
}

/**
 @Status Interoperable
*/
- (BOOL)decodeBoolForKey:(NSString*)key {
    return [self decodeIntForKey:key];
}

/**
 @Status Interoperable
*/
- (__int64)decodeInt64ForKey:(NSString*)key {
    id number = _numberForKey(self, key);

    if (number == nil) {
        return 0;
    }

    unsigned __int64 val;

    [number _copyInt64Value:&val];

    return val;
}

/**
 @Status Interoperable
*/
- (float)decodeFloatForKey:(NSString*)key {
    id number = _numberForKey(self, key);

    if (number == nil) {
        return 0;
    }

    float ret = [number floatValue];

    return ret;
}

/**
 @Status Interoperable
*/
- (double)decodeDoubleForKey:(NSString*)key {
    id number = _numberForKey(self, key);

    if (number == nil) {
        return 0;
    }

    double ret = [number doubleValue];

    return ret;
}

- (CGPoint)decodeCGPointForKey:(NSString*)key {
    CGPoint ret = { 0, 0 };
    id value = _valueForKey(self, key);

    if (value != nil) {
        ret = [value CGPointValue];
    }

    return ret;
}

/**
 @Status Interoperable
*/
+ (id)unarchiveObjectWithFile:(NSString*)file {
    id data = [NSData dataWithContentsOfFile:file];

    if ([data length] == 0) {
        return nil;
    }

    NSKeyedUnarchiver* unarchiver = [NSKeyedUnarchiver alloc];
    [unarchiver initForReadingWithData:data];

    id ret = [unarchiver decodeRootObject];
    [unarchiver autorelease];

    return ret;
}

/**
 @Status Interoperable
*/
+ (id)unarchiveObjectWithData:(NSData*)data {
    if ([data length] == 0) {
        return nil;
    }

    NSKeyedUnarchiver* unarchiver = [NSKeyedUnarchiver alloc];
    [unarchiver initForReadingWithData:data];

    id ret = [unarchiver decodeRootObject];
    [unarchiver autorelease];

    return ret;
}

/**
 @Status Interoperable
*/
- (const uint8_t*)decodeBytesForKey:(NSString*)key returnedLength:(NSUInteger*)length {
    *length = 0;

    id data = [self decodeObjectForKey:key];
    if (data != nil) {
        [_dataObjects addObject:data];
        *length = [data length];
        return (const uint8_t*)[data bytes];
    } else {
        return 0;
    }
}

/**
 @Status Interoperable
*/
- (void)finishDecoding {
}

- (BOOL)allowsKeyedCoding {
    return TRUE;
}

- (void)_setBundle:(id)bundle {
    _bundle = bundle;
}

- (NSBundle*)_bundle {
    return _bundle;
}

- (void)dealloc {
    _nameToReplacementClass = nil;
    _propertyList = nil;
    _objects = nil;
    _plistStack = nil;
    _uidToObject = nil;
    _dataObjects = nil;
    _bundle = nil;

    [super dealloc];
}

@end
