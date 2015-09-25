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
#include "Foundation/NSMutableCharacterSet.h"
#include "Foundation/NSMutableString.h"

#include "unicode/uniset.h"

@implementation NSMutableCharacterSet : NSCharacterSet
+ (instancetype)characterSetWithRange:(NSRange)range {
    NSMutableCharacterSet* ret = [NSMutableCharacterSet alloc];
    ret->_icuSet = new UnicodeSet(range.location, range.location + range.length);

    return [ret autorelease];
}

- (void)addCharactersInString:(NSString*)str {
    UStringHolder s1(str);
    UnicodeString& str1 = s1.string();
    int strLen = str1.length();

    for (int i = 0; i < strLen; i++) {
        _icuSet->add(str1.charAt(i));
    }
}

- (void)addCharactersInRange:(NSRange)range {
    _icuSet->add(range.location, range.location + range.length);
}

- (void)removeCharactersInString:(NSString*)str {
    UStringHolder s1(str);
    UnicodeString& str1 = s1.string();
    int strLen = str1.length();

    for (int i = 0; i < strLen; i++) {
        _icuSet->remove(str1.charAt(i));
    }
}

- (void)formUnionWithCharacterSet:(NSCharacterSet*)other {
    _icuSet->addAll(*other->_icuSet);
}

- (void)formIntersectionWithCharacterSet:(NSCharacterSet*)other {
    _icuSet->retainAll(*other->_icuSet);
}

- (void)removeCharactersInSet:(NSCharacterSet*)other {
    _icuSet->removeAll(*other->_icuSet);
}

- (void)removeAllCharacters {
    _icuSet->clear();
}
- (id)copyWithZone:(NSZone*)zone {
    NSCharacterSet* ret = [NSCharacterSet allocWithZone:zone];
    ret->_icuSet = new UnicodeSet(*_icuSet);

    return ret;
}

@end
