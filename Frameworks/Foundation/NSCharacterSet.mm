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
#include "Foundation/NSCharacterSet.h"
#include "Foundation/NSMutableCharacterSet.h"
#include "Foundation/NSMutableString.h"

#include "unicode/uniset.h"

@interface NSCharacterSetPermanent : NSCharacterSet {
@public
}
@end

@implementation NSCharacterSetPermanent : NSCharacterSet
- (id)autorelease {
    return self;
}

- (void)dealloc {
}

- (id)retain {
    return self;
}

- (void)release {
}

@end

@implementation NSCharacterSet : NSObject

/**
 @Status Interoperable
*/
+ (instancetype)characterSetWithICUCharacterSet:(char*) chars {
    NSCharacterSet* ret = [self alloc];

    ret->_icuSet = setWithCharacters(chars);

    return [ret autorelease];
}

+ (instancetype)characterSetWithCharactersInString:(NSString*)str {
    NSCharacterSet* ret = [self alloc];

    UStringHolder s1(str);
    UnicodeString& str1 = s1.string();
    int strLen = str1.length();

    ret->_icuSet = new UnicodeSet();

    for (int i = 0; i < strLen; i++) {
        ret->_icuSet->add(str1.charAt(i));
    }

    return [ret autorelease];
}

static UnicodeSet* setWithCharacters(char* chars) {
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

- (instancetype)init {
    _icuSet = new UnicodeSet();

    return self;
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
    if (self == [NSCharacterSet class]) {
        static id cachedRet;

        if (cachedRet == nil) {
            NSCharacterSet* ret = [NSCharacterSetPermanent alloc];
            ret->_icuSet = setWithCharacters(" \t\r\n");
            ret->_icuSet->freeze();
            cachedRet = ret;
        }

        return cachedRet;
    }

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
    if (self == [NSCharacterSet class]) {
        static id cachedRet;

        if (cachedRet == nil) {
            NSCharacterSet* ret = [NSCharacterSetPermanent alloc];
            ret->_icuSet = setWithCharacters(" \t");
            ret->_icuSet->freeze();
            cachedRet = ret;
        }

        return cachedRet;
    }
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters(" \t");

    return [ret autorelease];
}

+ (instancetype)symbolCharacterSet {
    return [self characterSetWithICUCharacterSet:"!@#$%^&*()-+"]; //  [BUG: This is not correct!]
}

+ (instancetype)URLFragmentAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

+ (instancetype)URLHostAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-.0123456789:;=ABCDEFGHIJKLMNOPQRSTUVWXYZ[]_abcdefghijklmnopqrstuvwxyz~"];
}

+ (instancetype)URLPasswordAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-.0123456789;=ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

+ (instancetype)URLPathAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-./0123456789:=@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

+ (instancetype)URLQueryAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

+ (instancetype)URLUserAllowedCharacterSet {
    return [self characterSetWithICUCharacterSet:"!$&'()*+,-.0123456789;=ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~"];
}

- (instancetype)set {
    assert(0);
    *((char*)0) = 0;
    //  _icuSet->toPattern?
    return nil;
}

- (id)mutableCopy {
    NSCharacterSet* ret = [NSMutableCharacterSet alloc];
    ret->_icuSet = static_cast<UnicodeSet*>(_icuSet->cloneAsThawed());

    return ret;
}

- (void)dealloc {
    assert(_icuSet != NULL);
    delete _icuSet;
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (instancetype)invertedSet {
    NSCharacterSet* ret = [NSMutableCharacterSet alloc];
    ret->_icuSet = static_cast<UnicodeSet*>(_icuSet->cloneAsThawed());
    ret->_icuSet->complement();

    return [ret autorelease];
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

@end
