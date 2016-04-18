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

#import "Starboard.h"
#import "StubReturn.h"
#import "Foundation/NSCharacterSet.h"
#import "Foundation/NSMutableCharacterSet.h"
#import "Foundation/NSMutableString.h"
#import "unicode/uniset.h"

@implementation NSCharacterSet

// We provide our own accessors so we also have to synthesize the ivar backing our property.
@synthesize invertedSet = _invertedSet;

/**
 @Status Interoperable
*/
+ (instancetype)characterSetWithICUCharacterSet:(const char*)chars {
    NSCharacterSet* ret = [self alloc];

    ret->_icuSet = setWithCharacters(chars);
    ret->_icuSet->freeze();

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)characterSetWithCharactersInString:(NSString*)str {
    NSCharacterSet* ret = [self alloc];

    UStringHolder s1(str);
    UnicodeString& str1 = s1.string();
    int strLen = str1.length();

    ret->_icuSet = new UnicodeSet();

    for (int i = 0; i < strLen; i++) {
        ret->_icuSet->add(str1.charAt(i));
    }

    ret->_icuSet->freeze();

    return [ret autorelease];
}

static UnicodeSet* setWithCharacters(const char* chars) {
    int len = strlen(chars);

    UnicodeSet* ret = new UnicodeSet();

    for (int i = 0; i < len; i++) {
        ret->add(chars[i]);
    }

    return ret;
}

/**
 @Status Caveat
 @Notes English characters only
*/
+ (instancetype)alphanumericCharacterSet {
    return [self characterSetWithICUCharacterSet:"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"];
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    _icuSet = new UnicodeSet();

    return self;
}

/**
@Status Stub
@Notes
*/
+ (instancetype)capitalizedLetterCharacterSet {
    UNIMPLEMENTED();

    return [[[self alloc] init] autorelease];
}

/**
 @Status Interoperable
 @Notes English characters only
*/
+ (instancetype)uppercaseLetterCharacterSet {
    return [self characterSetWithICUCharacterSet:"ABCDEFGHIJKLMNOPQRSTUVWXYZ"];
}

/**
 @Status Interoperable
*/
+ (instancetype)controlCharacterSet {
    NSCharacterSet* ret = [self alloc];

    ret->_icuSet = new UnicodeSet();
    ret->_icuSet->add(0, 0x20);
    ret->_icuSet->add(0x7F, 0xA0);

    ret->_icuSet->freeze();

    return [ret autorelease];
}

/**
 @Status Interoperable
 @Notes English characters only
*/
+ (instancetype)lowercaseLetterCharacterSet {
    return [self characterSetWithICUCharacterSet:"abcdefghijklmnopqrstuvwxyz"];
}

/**
 @Status Interoperable
 @Notes English characters only
*/
+ (instancetype)letterCharacterSet {
    return [self characterSetWithICUCharacterSet:"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"];
}

/**
 @Status Interoperable
*/
+ (instancetype)whitespaceAndNewlineCharacterSet {
    // Special-case for immutable NSCharacterSet
    if (self == [NSCharacterSet class]) {
        static id cachedRet;

        if (cachedRet == nil) {
            NSCharacterSet* ret = [NSCharacterSet alloc];
            ret->_icuSet = setWithCharacters(" \t\r\n");
            ret->_icuSet->freeze();
            cachedRet = ret;
        }

        return cachedRet;
    }

    // Polymorphic creation
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters(" \t\r\n");

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)punctuationCharacterSet {
    return [self characterSetWithICUCharacterSet:"!\"%'(),-./:;?[\\]{}"];
}

/**
 @Status Interoperable
*/
+ (instancetype)decimalDigitCharacterSet {
    return [self characterSetWithICUCharacterSet:"0123456789"];
}

/**
 @Status Interoperable
*/
+ (instancetype)newlineCharacterSet {
    return [self characterSetWithICUCharacterSet:"\r\n"];
}

/**
 @Status Interoperable
*/
+ (instancetype)whitespaceCharacterSet {
    // Special-case for immutable NSCharacterSet
    if (self == [NSCharacterSet class]) {
        static id cachedRet;

        if (cachedRet == nil) {
            NSCharacterSet* ret = [NSCharacterSet alloc];
            ret->_icuSet = setWithCharacters(" \t");
            ret->_icuSet->freeze();
            cachedRet = ret;
        }

        return cachedRet;
    }

    // Polymorphic creation
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters(" \t");
    ret->_icuSet->freeze();

    return [ret autorelease];
}

/**
 @Status Interoperable
 @Notes This is not the correct character set. There are many more symbols that are used.
*/
+ (instancetype)symbolCharacterSet {
    return [self characterSetWithICUCharacterSet:"!@#$%^&*()-+"];
}

/**
 @Status Interoperable
*/
+ (instancetype)URLFragmentAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

/**
 @Status Interoperable
*/
+ (instancetype)URLHostAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-.0123456789:;=ABCDEFGHIJKLMNOPQRSTUVWXYZ[]_abcdefghijklmnopqrstuvwxyz~"];
}

/**
 @Status Interoperable
*/
+ (instancetype)URLPasswordAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-.0123456789;=ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

/**
 @Status Interoperable
*/
+ (instancetype)URLPathAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-./0123456789:=@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

/**
 @Status Interoperable
*/
+ (instancetype)URLQueryAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

/**
 @Status Interoperable
*/
+ (instancetype)URLUserAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-.0123456789;=ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    assert(_icuSet != NULL);
    delete _icuSet;
    [_invertedSet release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (BOOL)characterIsMember:(unichar)member {
    if (_icuSet->contains(member)) {
        return TRUE;
    }
    return FALSE;
}

/**
 @Status Interoperable
*/
- (BOOL)isSupersetOfSet:(NSCharacterSet*)set {
    if (_icuSet->containsAll(*set->_icuSet)) {
        return TRUE;
    }
    return FALSE;
}

/**
 @Status Interoperable
*/
- (NSUInteger)count {
    return _icuSet->size();
}

/**
 @Status Interoperable
*/
- (unichar)characterAtIndex:(NSUInteger)idx {
    return _icuSet->charAt(idx);
}

/**
 @Status Stub
*/
+ (instancetype)characterSetWithBitmapRepresentation:(NSData*)data {
    UNIMPLEMENTED();

    NSCharacterSet* ret = [[self alloc] init];
    ret->_bitmapRepresentation = data;
    return [ret autorelease];
}

/**
 @Status Stub
*/
+ (instancetype)characterSetWithContentsOfFile:(NSString*)path {
    UNIMPLEMENTED();

    return [[[self alloc] init] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)characterSetWithRange:(NSRange)range {
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = new UnicodeSet(range.location, range.location + range.length - 1);
    ret->_icuSet->freeze();
    return [ret autorelease];
}

/**
 @Status Stub
*/
+ (instancetype)decomposableCharacterSet {
    UNIMPLEMENTED();

    // There are 220 characters that are in this character set that should not be.
    // This is also assuming that the character set only includes values < 65535 or 0xffff
    // Todo: determine a better way of insantiating this set.
    NSRange decomposeRange;

    decomposeRange.location = 192;
    decomposeRange.length = 64334;
    NSCharacterSet* ret = [self characterSetWithRange:decomposeRange];
    return ret;
}

/**
 @Status Stub
*/
+ (instancetype)illegalCharacterSet {
    UNIMPLEMENTED();

    return [[[self alloc] init] autorelease];
}

/**
 @Status Stub
*/
+ (instancetype)nonBaseCharacterSet {
    UNIMPLEMENTED();

    return [[[self alloc] init] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    NSMutableCharacterSet* copy = [[NSMutableCharacterSet class] allocWithZone:zone];
    copy->_icuSet = static_cast<UnicodeSet*>(_icuSet->cloneAsThawed());

    static_cast<NSCharacterSet*>(copy)->_bitmapRepresentation = [_bitmapRepresentation mutableCopyWithZone:zone];

    return copy;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super init]) {
        _icuSet = new UnicodeSet();
        NSString* stringSet = [[coder decodeObjectForKey:@"characterSet"] retain];

        const UnicodeString* str1 = new UnicodeString([stringSet UTF8String]);
        UErrorCode status = U_ZERO_ERROR;
        _icuSet = new UnicodeSet(*str1, status);

        _icuSet->freeze();

        _bitmapRepresentation = [[coder decodeObjectOfClass:[NSData class] forKey:@"bitmapRepresentation"] retain];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UnicodeString* str1 = new UnicodeString();
    _icuSet->toPattern(*str1, false);
    std::string utf8String;
    utf8String = str1->toUTF8String(utf8String);
    NSString* stringSet = [NSString stringWithCString:utf8String.c_str() encoding:[NSString defaultCStringEncoding]];
    [coder encodeObject:stringSet forKey:@"characterSet"];

    [coder encodeObject:_bitmapRepresentation forKey:@"bitmapRepresentation"];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)longCharacterIsMember:(UTF32Char)theLongChar {
    return _icuSet->contains(theLongChar);
}

/**
 @Status Stub
*/
- (BOOL)hasMemberInPlane:(uint8_t)thePlane {
    UNIMPLEMENTED();
    return false;
}

/**
 @Status Interoperable
 */
- (NSCharacterSet*)invertedSet {
    @synchronized(self) {
        if (_invertedSet == nil) {
            _invertedSet = [[NSCharacterSet alloc] init];
            _invertedSet->_icuSet = static_cast<UnicodeSet*>(_icuSet->cloneAsThawed());
            _invertedSet->_icuSet->complement();
            _invertedSet->_icuSet->freeze();

            // This will prevent a retain cycle:
            // If the invertedSet property of this invertedSet object is requested then we
            // simply create a new NSCharacterSet object to hold the inverse and return that.
            _invertedSet->_invertedSet = nil;
        }
        return [[_invertedSet retain] autorelease];
    }
}

@end
