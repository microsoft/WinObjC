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
#import "Foundation/NSMutableCharacterSet.h"
#import "Foundation/NSMutableString.h"

#import "unicode/uniset.h"

@implementation NSMutableCharacterSet

- (void)_thawICUSetIfNeeded {
    if (_icuSet->isFrozen()) {
        UnicodeSet* temp = static_cast<UnicodeSet*>(_icuSet->cloneAsThawed());
        delete _icuSet;
        _icuSet = temp;
    }
}

/**
 @Status Interoperable
*/
- (void)removeCharactersInRange:(NSRange)range {
    [self _thawICUSetIfNeeded];
    _icuSet->remove(range.location, range.location + range.length - 1);
}

/**
 @Status Interoperable
*/
- (void)invert {
    [self _thawICUSetIfNeeded];
    _icuSet->complement();
}

/**
 @Status Interoperable
*/
- (void)addCharactersInString:(NSString*)str {
    [self _thawICUSetIfNeeded];

    UStringHolder s1(str);
    UnicodeString& str1 = s1.string();
    int strLen = str1.length();

    for (int i = 0; i < strLen; i++) {
        _icuSet->add(str1.charAt(i));
    }
}

/**
 @Status Interoperable
*/
- (void)addCharactersInRange:(NSRange)range {
    [self _thawICUSetIfNeeded];

    _icuSet->add(range.location, range.location + range.length - 1);
}

/**
 @Status Interoperable
*/
- (void)removeCharactersInString:(NSString*)str {
    [self _thawICUSetIfNeeded];

    UStringHolder s1(str);
    UnicodeString& str1 = s1.string();
    int strLen = str1.length();

    for (int i = 0; i < strLen; i++) {
        _icuSet->remove(str1.charAt(i));
    }
}

/**
 @Status Interoperable
*/
- (void)formUnionWithCharacterSet:(NSCharacterSet*)other {
    [self _thawICUSetIfNeeded];

    _icuSet->addAll(*other->_icuSet);
}

/**
 @Status Interoperable
*/
- (void)formIntersectionWithCharacterSet:(NSCharacterSet*)other {
    [self _thawICUSetIfNeeded];

    _icuSet->retainAll(*other->_icuSet);
}

/**
 @Status Interoperable
*/
- (void)removeCharactersInSet:(NSCharacterSet*)other {
    [self _thawICUSetIfNeeded];

    _icuSet->removeAll(*other->_icuSet);
}

/**
 @Status Interoperable
*/
- (void)removeAllCharacters {
    [self _thawICUSetIfNeeded];

    _icuSet->clear();
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    NSCharacterSet* ret = [NSCharacterSet allocWithZone:zone];
    ret->_icuSet = new UnicodeSet(*_icuSet);

    return ret;
}

/**
 @Status Interoperable
 */
- (NSMutableCharacterSet*)invertedSet {
    NSMutableCharacterSet* ret = [self mutableCopy];
    [ret invert];
    return ret;
}

@end
