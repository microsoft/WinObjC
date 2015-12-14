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

#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSString.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSNull.h"
#include "Foundation/NSValue.h"
#include "Foundation/NSPropertyList.h"
#include "Foundation/NSKeyedArchiver.h"
#include "Foundation/NSDate.h"
#include "Foundation/NSAutoreleasePool.h"
#include "Etc.h"

#include "Hash.h"
typedef HashMap<id, unsigned> o2uHash;
typedef HashMap<id, id> o2oHash;

struct NSKeyedArchiverPriv {
    o2oHash clsMap; /* Map classes to names.    */
    o2uHash cIdMap; /* Conditionally coded.     */
    o2uHash uIdMap; /* Unconditionally coded.   */
    o2oHash repMap; /* Mappings for objects.    */
};

// static o2uHash *globalClassMap;

static id NSStringClass = 0;
static id NSScannerClass = 0;
static char* scanFloatSel;
static char* scanStringSel;
static char* scannerSel;
static BOOL (*scanFloatImp)(id, const char*, float*);
static BOOL (*scanStringImp)(id, const char*, id, id*);
static id (*scannerImp)(id, const char*, id);

#define RELEASE(object) [object release]
#define RETAIN(object) [object retain]
#define DESTROY(object) [object release]
#define AUTORELEASE(object) [object autorelease]
#define CREATE_AUTORELEASE_POOL(object) id(pool) = [[NSAutoreleasePool alloc] init]

void printContents(int level, id obj);

static inline void setupCache(void) {
    if (NSStringClass == 0) {
        NSStringClass = [NSString class];
        assert(0);
        // NSScannerClass = [NSScanner class];
        scanFloatSel = "scanFloat:";
        scanStringSel = "scanString:intoString:";
        scannerSel = "scannerWithString:";
        /*
        scanFloatImp = (BOOL (*)(NSScanner*, SEL, float*))
        [NSScannerClass instanceMethodForSelector: scanFloatSel];
        scanStringImp = (BOOL (*)(NSScanner*, SEL, NSString*, NSString**))
        [NSScannerClass instanceMethodForSelector: scanStringSel];
        scannerImp = (id (*)(Class, SEL, NSString*))
        [NSScannerClass methodForSelector: scannerSel];
        */
    }
}

#define CHECKKEY                                       \
    if ([aKey isKindOfClass:[NSString class]] == NO) { \
        assert(0);                                     \
    }                                                  \
    if ([aKey hasPrefix:@"$"] == YES) {                \
        aKey = [@"$" stringByAppendingString:aKey];    \
    }                                                  \
    if ([_enc objectForKey:aKey] != nil) {             \
        assert(0);                                     \
    }

/*
* Make a dictionary referring to the object at ref in the array of all objects.
*/
static id makeReference(unsigned ref) {
    id n;
    id d;

    n = [NSNumber numberWithUnsignedInt:ref];
    d = [NSDictionary dictionaryWithObject:n forKey:@"CF$UID"];
    return d;
}

@implementation NSKeyedArchiver : NSCoder {
    NSMutableData* _data;
    NSMutableArray* _plistStack;
    NSMutableArray* _objects;
    NSMutableDictionary* _top;
    id _delegate;
    NSPropertyListFormat _outputFormat;
    NSMapTable* _nameToClass;
    NSUInteger _pass;
    NSMapTable* _objectToUid;

    NSPropertyListFormat _format;
    unsigned _keyNum;
    id _enc, _obj, _retainList;

    struct NSKeyedArchiverPriv* _priv;
}

- (void)_encodeArrayOfObjects:(NSArray*)anArray forKey:(NSString*)aKey {
    id o;
    CHECKKEY

    if (anArray == nil) {
        o = makeReference(0);
    } else {
        unsigned c = [anArray count];
        NSMutableArray* m = [NSMutableArray arrayWithCapacity:c];

        for (unsigned i = 0; i < c; i++) {
            o = [self _encodeObject:[anArray objectAtIndex:i] conditional:NO];
            [m addObject:o];
        }
        o = m;
    }
    [_enc setObject:o forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeInt:(int)anInteger forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSNumber numberWithInt:anInteger] forKey:aKey];
}

- (void)encodeInteger:(int)anInteger forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSNumber numberWithInt:anInteger] forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeInt32:(int32_t)anInteger forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSNumber numberWithLong:anInteger] forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeInt64:(int64_t)anInteger forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSNumber numberWithLongLong:anInteger] forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeBool:(BOOL)aBool forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSNumber numberWithBool:aBool] forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeFloat:(float)aFloat forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSNumber numberWithFloat:aFloat] forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeDouble:(double)aDouble forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSNumber numberWithDouble:aDouble] forKey:aKey];
}

- (void)encodeCGPoint:(CGPoint)pt forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSValue valueWithCGPoint:pt] forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeBytes:(char*)aPointer length:(int)length forKey:(NSString*)aKey {
    CHECKKEY

        [_enc setObject:[NSData dataWithBytes:aPointer length:length] forKey:aKey];
}

/**
 @Status Interoperable
*/
+ (NSData*)archivedDataWithRootObject:(id)anObject {
    NSMutableData* m = [[NSMutableData alloc] initWithCapacity:10240];
    NSKeyedArchiver* a = [[NSKeyedArchiver alloc] initForWritingWithMutableData:m];
    [a encodeObject:anObject forKey:@"root"];
    [a finishEncoding];
    NSMutableData* d = [m copy];
    DESTROY(m);
    DESTROY(a);
    return AUTORELEASE(d);
}

- (void)dealloc {
    RELEASE(_enc);
    RELEASE(_obj);
    RELEASE(_data);
    RELEASE(_retainList);
    delete _priv;

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)finishEncoding {
    id error;

    [_delegate archiverWillFinish:self];

    NSMutableDictionary* final = [NSMutableDictionary new];
    [final setObject:NSStringFromClass([self class]) forKey:@"$archiver"];
    [final setObject:[NSNumber numberWithInt:100000] forKey:@"$version"];
    [final setObject:_enc forKey:@"$top"];
    [final setObject:_obj forKey:@"$objects"];
    id data = [NSPropertyListSerialization dataFromPropertyList:final format:_format errorDescription:&error];
    RELEASE(final);
    [_data setData:data];
    [_delegate archiverDidFinish:self];
}

/**
 @Status Interoperable
*/
+ (BOOL)archiveRootObject:(id)anObject toFile:(NSString*)aPath {
    CREATE_AUTORELEASE_POOL(pool);
    id d;
    BOOL result;

    d = [self archivedDataWithRootObject:anObject];
    result = [d writeToFile:aPath atomically:YES];
    RELEASE(pool);
    return result;
}

/**
 @Status Interoperable
*/
- (instancetype)initForWritingWithMutableData:(NSMutableData*)data {
    self = [super init];
    if (self) {
        _priv = new NSKeyedArchiverPriv;

        _keyNum = 0;
        _data = RETAIN(data);

        _enc = [NSMutableDictionary new]; // Top level mapping dict
        _obj = [NSMutableArray new]; // Array of objects.
        _retainList = [NSMutableArray new];
        [_obj addObject:@"$null"]; // Placeholder.

        _format = NSPropertyListBinaryFormat_v1_0;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeObject:(id)anObject forKey:(NSString*)aKey {
    CHECKKEY

    anObject = [self _encodeObject:anObject conditional:NO];
    [_enc setObject:anObject forKey:aKey];
}

- (void)encodeObject:(id)anObject {
    NSString* aKey = [NSString stringWithFormat:@"$%u", _keyNum++];

    anObject = [self _encodeObject:anObject conditional:NO];
    [_enc setObject:anObject forKey:aKey];
}

/*
* The real workhorse of the archiving process ... this deals with all
* archiving of objects. It returns the object to be stored in the
* mapping dictionary (_enc).
*/
- (NSDictionary*)_encodeObject:(id)anObject conditional:(BOOL)conditional {
    id original = anObject;
    id m = nil;

    if (anObject != nil) {
        // Obtain replacement object for the value being encoded.
        // Notify delegate of progress and set up new mapping if necessary.

        id* tempObj;
        if (_priv->repMap.get(anObject, tempObj)) {
            // If the object has a replacement, use it.
            anObject = *tempObj;
        } else {
            anObject = [original replacementObjectForKeyedArchiver:self];
            if (_delegate != nil) {
                if (anObject != nil)
                    anObject = [_delegate archiver:self willEncodeObject:anObject];
                if (original != anObject)
                    [_delegate archiver:self willReplaceObject:original withObject:anObject];
            }
            _priv->repMap.insert(original, anObject);

            //  Retain the original object
            [_retainList addObject:anObject];
        }
    }

    id objectInfo = nil; // Encoded object
    unsigned ref = 0;
    unsigned* refTmp;

    if (anObject != nil) {
        if (_priv->uIdMap.get(anObject, refTmp)) {
            ref = *refTmp;
        } else {
            if (conditional) {
                if (_priv->cIdMap.get(anObject, refTmp)) {
                    ref = [_obj count];
                    _priv->cIdMap.insert(anObject, ref);

                    // Use the null object as a placeholder for a conditionally encoded object.
                    [_obj addObject:[_obj objectAtIndex:0]];
                } else {
                    // This object has already been conditionally encoded.
                    ref = *refTmp;
                }
            } else {
                id c = [anObject classForKeyedArchiver];

                // FIXME ... exactly what classes are stored directly???
                if (c == [NSString class] || c == [NSNumber class] || c == [NSDate class] || c == [NSData class]) {
                    objectInfo = anObject;
                } else {
                    // We store a dictionary describing the object.
                    m = [NSMutableDictionary new];
                    objectInfo = m;
                }

                if (_priv->cIdMap.get(anObject, refTmp)) {
                    // Conditionally encoded ... replace with actual value.
                    ref = *refTmp;
                    _priv->uIdMap.insert(anObject, ref);
                    _priv->cIdMap.remove(anObject);
                    [_obj replaceObjectAtIndex:ref withObject:objectInfo];
                } else {
                    // Not encoded ... create dictionary for it.
                    ref = [_obj count];
                    _priv->uIdMap.insert(anObject, ref);
                    [_obj addObject:objectInfo];
                }
                RELEASE(m);
            }
        }
    }

    // Build an object to reference the encoded value of anObject
    id refObject = makeReference(ref);

    // objectInfo is a dictionary describing the object.
    if (objectInfo != nil && m == objectInfo) {
        id savedEnc = _enc;
        unsigned savedKeyNum = _keyNum;
        id c = [anObject class];
        id classname;
        id mapped;

        /*
        * Map the class of the object to the actual class it is encoded as.
        * First ask the object, then apply any name mappings to that value.
        */
        mapped = [anObject classForKeyedArchiver];
        if (mapped != nil) {
            c = mapped;
        }

        classname = [self classNameForClass:c];
        if (classname == nil) {
            classname = [[self class] classNameForClass:c];
        }
        if (classname == nil) {
            classname = NSStringFromClass(c);
        } else {
            c = NSClassFromString(classname);
        }

        /*
        * At last, get the object to encode itself.  Save and restore the
        * current object scope of course.
        */
        _enc = m;
        _keyNum = 0;
        [anObject encodeWithCoder:self];
        _keyNum = savedKeyNum;
        _enc = savedEnc;

        /*
        * This is ugly, but it seems to be the way MacOS-X does it ...
        * We create class information by storing it directly into the
        * table of all objects, and making a reference so we can look
        * up the table entry by class pointer.
        * A much cleaner way to do it would be by encoding the class
        * normally, but we are trying to be compatible.
        *
        * Also ... we encode the class *after* encoding the instance,
        * simply because that seems to be the way MacOS-X does it and
        * we want to maximise compatibility (perhaps they had good reason?)
        */
        if (_priv->uIdMap.get(c, refTmp)) {
            ref = *refTmp;
        } else {
            id cDict;
            id hierarchy;

            ref = [_obj count];
            _priv->uIdMap.insert(c, ref);
            cDict = [[NSMutableDictionary alloc] initWithCapacity:2];

            // Record class name
            [cDict setObject:classname forKey:@"$classname"];

            // Record the class hierarchy for this object.
            hierarchy = [NSMutableArray new];
            while (c != 0) {
                id next = [c superclass];

                [hierarchy addObject:NSStringFromClass(c)];
                if (next == c) {
                    break;
                }
                c = next;
            }
            [cDict setObject:hierarchy forKey:@"$classes"];
            RELEASE(hierarchy);
            [_obj addObject:cDict];
            RELEASE(cDict);
        }

        /*
        * Now create a reference to the class information and store it
        * in the object description dictionary for the object we just encoded.
        */
        [m setObject:makeReference(ref) forKey:@"$class"];
    }

    // If we have encoded the object information, tell the delegate.
    if (objectInfo != nil && _delegate != nil) {
        [_delegate archiver:self didEncodeObject:anObject];
    }

    // Return the dictionary identifying the encoded object.
    return refObject;
}

/**
 @Status Interoperable
*/
+ (NSString*)classNameForClass:(id)aClass {
    // return (NSString*)NSMapGet(globalClassMap, (void*)aClass);
    return nil;
}

/**
 @Status Interoperable
*/
- (NSString*)classNameForClass:(id)aClass {
    id* nameTmp;
    if (_priv->clsMap.get(aClass, nameTmp))
        return *nameTmp;
    return nil;
}

- (BOOL)allowsKeyedCoding {
    return TRUE;
}

- (void)encodeConditionalObject:(id)object {
    [self encodeObject:object];
}

//

@end
