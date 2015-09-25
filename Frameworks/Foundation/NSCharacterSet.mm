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

+ (instancetype)alphanumericCharacterSet {
    NSCharacterSet* ret = [self alloc];

    ret->_icuSet = setWithCharacters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    return [ret autorelease];
}

- (instancetype)init {
    _icuSet = new UnicodeSet();

    return self;
}

+ (instancetype)uppercaseLetterCharacterSet {
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    return [ret autorelease];
}

+ (instancetype)controlCharacterSet {
    NSCharacterSet* ret = [self alloc];

    ret->_icuSet = new UnicodeSet();
    ret->_icuSet->add(0, 0x20);
    ret->_icuSet->add(0x7F, 0xA0);

    return [ret autorelease];
}

+ (instancetype)lowercaseLetterCharacterSet {
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters("abcdefghijklmnopqrstuvwxyz");

    return [ret autorelease];
}

+ (instancetype)letterCharacterSet {
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    return [ret autorelease];
}

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

+ (instancetype)punctuationCharacterSet {
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters("!\"%'(),-./:;?[\\]{}");

    return [ret autorelease];
}

+ (instancetype)decimalDigitCharacterSet {
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters("0123456789");

    return [ret autorelease];
}

+ (instancetype)newlineCharacterSet {
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters("\r\n");

    return [ret autorelease];
}

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
    NSCharacterSet* ret = [self alloc];
    ret->_icuSet = setWithCharacters("!@#$%^&*()-+"); //  [BUG: This is not correct!]

    return [ret autorelease];
}

- (instancetype)set {
    assert(0);
    *((char*)0) = 0;
    //  _icuSet->toPattern?
    return nil;
}

- (id)mutableCopy {
    NSCharacterSet* ret = [NSMutableCharacterSet alloc];
    ret->_icuSet = new UnicodeSet(*_icuSet);

    return ret;
}

- (void)dealloc {
    assert(_icuSet != NULL);
    delete _icuSet;
    [super dealloc];
}

- (instancetype)invertedSet {
    NSCharacterSet* ret = [NSMutableCharacterSet alloc];
    ret->_icuSet = new UnicodeSet(*_icuSet);
    ret->_icuSet->complement();

    return [ret autorelease];
}

- (BOOL)characterIsMember:(unichar)member {
    if (_icuSet->contains(member)) {
        return TRUE;
    }
    return FALSE;
}

- (BOOL)isSupersetOfSet:(NSCharacterSet*)set {
    if (_icuSet->containsAll(*set->_icuSet)) {
        return TRUE;
    }
    return FALSE;
}

- (NSUInteger)count {
    return _icuSet->size();
}

- (unichar)characterAtIndex:(NSUInteger)idx {
    return _icuSet->charAt(idx);
}

@end
