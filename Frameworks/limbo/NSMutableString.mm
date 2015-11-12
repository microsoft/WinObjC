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

#define U_STATIC_IMPLEMENTATION 1
#include "unicode/unistr.h"

void setToUnicode(NSString* inst, UnicodeString& str);

@implementation NSMutableString : NSString
- (NSObject*)init {
    UnicodeString str(16, 0, 0);
    setToUnicode(self, str);

    return self;
}

/**
 @Status Interoperable
*/
+ (instancetype)stringWithCapacity:(NSUInteger)capacity {
    return [[[self alloc] initWithCapacity:capacity] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(NSUInteger)capacity {
    if (capacity < 16)
        capacity = 16;

    UnicodeString str(capacity, 0, 0);
    setToUnicode(self, str);

    return self;
}

/**
 @Status Interoperable
*/
+ (instancetype)string {
    return [[self new] autorelease];
}

/**
 @Status Interoperable
*/
- (void)insertString:(NSString*)str atIndex:(NSUInteger)idx {
    UStringHolder s1(self);
    UStringHolder s2(str);
    UnicodeString& curStr = s1.string();

    curStr.insert(idx, s2.string());
    setToUnicode(self, curStr);
}

/**
 @Status Interoperable
*/
- (void)replaceCharactersInRange:(NSRange)range withString:(NSString*)str {
    UStringHolder s1(self);
    UStringHolder s2(str);
    UnicodeString& curStr = s1.string();

    curStr.replace(range.location, range.length, s2.string());
    setToUnicode(self, curStr);
}

/**
 @Status Interoperable
*/
- (void)deleteCharactersInRange:(NSRange)range {
    UStringHolder s1(self);
    UnicodeString& curStr = s1.string();

    curStr.remove(range.location, range.length);
    setToUnicode(self, curStr);
}

/**
 @Status Interoperable
*/
- (void)appendFormat:(NSString*)formatStr, ... {
    void setToFormat(NSString * inst, NSString * format, va_list list, NSString * string);

    va_list reader;
    va_start(reader, formatStr);

    NSString* endStr = [[self class] alloc];
    setToFormat(self, formatStr, reader, endStr);
    va_end(reader);

    [self appendString:endStr];
}

/**
 @Status Interoperable
*/
- (void)appendString:(NSString*)str {
    UStringHolder s1(self);
    UStringHolder s2(str);
    UnicodeString& curStr = s1.string();

    curStr.append(s2.string());
    setToUnicode(self, curStr);
}

- (void)__appendCharacter:(WORD)character {
    UStringHolder s1(self);
    UnicodeString& curStr = s1.string();

    curStr.append((UChar)character);
    setToUnicode(self, curStr);
}

- (void)__appendCharacters:(WORD*)characters length:(int)length {
    UStringHolder s1(self);
    UnicodeString& curStr = s1.string();

    curStr.append((const UChar*)characters, length);
    setToUnicode(self, curStr);
}

- (void)__appendLocale:(NSLocale*)locale key:(NSString*)key index:(int)index {
    id array = [locale objectForKey:key];

    if (array != nil)
        [self appendString:[array objectAtIndex:index]];
}

/**
 @Status Interoperable
*/
- (void)setString:(NSString*)str {
    UStringHolder s1(str);

    setToUnicode(self, s1.string());
}

/**
 @Status Interoperable
*/
- (NSUInteger)replaceOccurrencesOfString:(id)target withString:(id)replacement options:(DWORD)options range:(NSRange)range {
    if (target == nil) {
        // NSRaiseException(NSInvalidArgumentException,self,_cmd,@"nil target object");
        assert(0);
    }
    if (replacement == nil) {
        // NSRaiseException(NSInvalidArgumentException,self,_cmd,@"nil replacement object");
        assert(0);
    }
    if (range.location + range.length > [self length]) {
        // NSRaiseException(NSRangeException,self,_cmd,@"end of search range %d beyond length %d",
        // searchRange.location+searchRange.length, [self length]);
        assert(0);
    }

    if (options & NSRegularExpressionSearch) {
        NSRegularExpressionOptions regOptions = 0;
        uint32_t searchOptions = 0;

        if (options & NSCaseInsensitiveSearch) {
            regOptions |= NSRegularExpressionCaseInsensitive;
        }
        if (options & NSAnchoredSearch) {
            searchOptions = NSMatchingAnchored;
        }

        NSRegularExpression* regExp = [[NSRegularExpression alloc] initWithPattern:target options:regOptions error:NULL];

        int count = [regExp replaceMatchesInString:self options:searchOptions range:range withTemplate:replacement];
        [regExp release];

        return count;
    }

    const BOOL isBackwards = (options & NSBackwardsSearch) ? YES : NO;
    const NSUInteger replacementLen = [replacement length];
    NSRange subrange;

    NSUInteger n = 0;
    subrange = [self rangeOfString:target options:options range:range];
    while (subrange.location != 0x7fffffff) {
        [self replaceCharactersInRange:subrange withString:replacement];

        if (!isBackwards) {
            range.length -= (subrange.location - range.location) + subrange.length;
            range.location = subrange.location + replacementLen;
        } else {
            range.length = subrange.location - range.location;
        }

        n++;
        subrange = [self rangeOfString:target options:options range:range];
    }

    return n;
}

- (NSObject*)copyWithZone:(NSZone*)zone {
    NSString* newStr = [[NSString alloc] initWithString:self];

    return newStr;
}

@end
