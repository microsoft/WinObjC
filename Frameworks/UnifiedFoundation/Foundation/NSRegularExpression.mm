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
#include "Foundation/NSRegularExpression.h"
#include <unicode/regex.h>
#include <memory>

@interface NSRegularExpression ()
@property (readwrite, copy) NSString* pattern;
@property (readwrite) NSRegularExpressionOptions options;
@property (readwrite) NSUInteger numberOfCaptureGroups;
@end

static StrongId<NSCharacterSet> s_patternMetaCharacters;
static StrongId<NSCharacterSet> s_templateMetaCharacters;

@implementation NSRegularExpression {
    std::unique_ptr<RegexPattern> _icuRegex;
}

+ (void)initialize {
    s_patternMetaCharacters = [NSCharacterSet characterSetWithCharactersInString:@"$^*()+/?[{}.\\"];
    s_templateMetaCharacters = [NSCharacterSet characterSetWithCharactersInString:@"$\\"];
}

/**
@Status Interoperable
*/
+ (NSRegularExpression*)regularExpressionWithPattern:(NSString*)pattern options:(NSRegularExpressionOptions)options error:(NSError**)error {
    return [[[self alloc] initWithPattern:pattern options:options error:error] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithPattern:(NSString*)pattern options:(NSRegularExpressionOptions)options error:(NSError**)error {
    if (self = [super init]) {
        _pattern = [pattern copy];

        int icuRegexOptions = 0;
        if (NSRegularExpressionCaseInsensitive & options) {
            icuRegexOptions |= UREGEX_CASE_INSENSITIVE;
        }
        if (NSRegularExpressionAllowCommentsAndWhitespace & options) {
            icuRegexOptions |= UREGEX_COMMENTS;
        }
        if (NSRegularExpressionIgnoreMetacharacters & options) {
            // TODO - VSO 6264731: UREGEX_LITERAL causes faliures in ICU. Workaround is to use escaped version of pattern.

            // icuRegexOptions |= UREGEX_LITERAL;
            _pattern = [[NSRegularExpression escapedPatternForString:pattern] retain];
        }
        if (NSRegularExpressionDotMatchesLineSeparators & options) {
            icuRegexOptions |= UREGEX_DOTALL;
        }
        if (NSRegularExpressionAnchorsMatchLines & options) {
            icuRegexOptions |= UREGEX_MULTILINE;
        }
        if (NSRegularExpressionUseUnixLineSeparators & options) {
            icuRegexOptions |= UREGEX_UNIX_LINES;
        }
        if (NSRegularExpressionUseUnicodeWordBoundaries & options) {
            icuRegexOptions |= UREGEX_UWORD;
        }

        // Create backing ICU regex handle:
        UStringHolder unicodePattern(_pattern);
        UErrorCode status = U_ZERO_ERROR;
        UParseError parseStatus;

        _icuRegex.reset(RegexPattern::compile(unicodePattern.string(), icuRegexOptions, parseStatus, status));

        if (U_FAILURE(status)) {
            if (error) {
                *error = (NSError*)[NSError errorWithDomain:NSCocoaErrorDomain code:2048 userInfo:nil];
            }
            [self release];
            return nil;
        } else {
            if (error) {
                *error = nil;
            }
        }

        RegexMatcher* matcher = _icuRegex->matcher(status);
        _numberOfCaptureGroups = matcher->groupCount();
        delete matcher;
    }

    return self;
}

- (void)dealloc {
    [_pattern release];

    [super dealloc];
}

/**
 @Status Caveat
 @Notes Ignores NSMatchingOptions
*/
- (NSUInteger)numberOfMatchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    __block NSUInteger count = 0;

    [self enumerateMatchesInString:string
                           options:options
                             range:range
                        usingBlock:^void(NSTextCheckingResult* textResult, NSMatchingFlags flags, BOOL* stop) {
                            count++;
                        }];

    return count;
}

/**
 @Status Caveat
 @Notes Ignores NSMatchingOptions
*/
- (NSTextCheckingResult*)firstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    NSRange tempRange = NSMakeRange(NSNotFound, 0);
    __block NSTextCheckingResult* result =
        [[NSTextCheckingResult regularExpressionCheckingResultWithRanges:&tempRange count:1 regularExpression:self] retain];

    [self enumerateMatchesInString:string
                           options:options
                             range:range
                        usingBlock:^void(NSTextCheckingResult* textResult, NSMatchingFlags flags, BOOL* stop) {
                            result = [textResult retain];
                            *stop = YES;
                        }];

    return [result autorelease];
}

/**
 @Status Caveat
 @Notes Ignores NSMatchingOptions
*/
- (NSRange)rangeOfFirstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    __block NSRange result = { NSNotFound, 0 };

    [self enumerateMatchesInString:string
                           options:options
                             range:range
                        usingBlock:^void(NSTextCheckingResult* textResult, NSMatchingFlags flags, BOOL* stop) {
                            result = textResult.range;
                            *stop = YES;
                        }];

    return result;
}

/**
 @Status Caveat
 @Notes Ignores NSMatchingOptions
*/
- (NSArray*)matchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    __block NSMutableArray* result = [NSMutableArray array];

    [self enumerateMatchesInString:string
                           options:options
                             range:range
                        usingBlock:^void(NSTextCheckingResult* textResult, NSMatchingFlags flags, BOOL* stop) {
                            [result addObject:textResult];
                        }];

    return result;
}

static NSUInteger _replaceAll(
    NSMutableString* string, NSRegularExpression* regex, RegexMatcher& icuRegex, NSString* replacement, UErrorCode status) {
    if (U_FAILURE(status)) {
        return 0;
    }

    NSUInteger count = 0;
    int offset = 0;

    while (icuRegex.find() && status == U_ZERO_ERROR) {
        NSString* replacedText;
        NSTextCheckingResult* result;

        NSRange foundRange = NSMakeRange(icuRegex.start(status), icuRegex.end(status));
        if (U_FAILURE(status)) {
            if (replacedText) {
                [replacedText release];
            }
            if (result) {
                [result release];
            }
            return count;
        }

        result = [NSTextCheckingResult regularExpressionCheckingResultWithRanges:&foundRange count:1 regularExpression:regex];

        replacedText = [regex replacementStringForResult:result inString:string offset:offset template:replacement];

        if (replacedText == nil) {
            return count;
        }

        [string replaceCharactersInRange:foundRange withString:replacedText];

        offset += replacedText.length - foundRange.length;
        count++;
    }
    return count;
}

/**
 @Status Caveat
 @Notes Ignores NSMatchingOptions
*/
- (NSUInteger)replaceMatchesInString:(NSMutableString*)string
                             options:(NSMatchingOptions)options
                               range:(NSRange)range
                        withTemplate:(NSString*)templateStr {
    if (string == nil) {
        return 0;
    }

    UStringHolder matchStr(string);

    UErrorCode status = U_ZERO_ERROR;
    RegexMatcher* matcher = _icuRegex->matcher(matchStr.string(), status);
    if (U_FAILURE(status)) {
        return 0;
    }

    matcher->region(range.location, range.location + range.length, status);
    if (U_FAILURE(status)) {
        return 0;
    }

    return _replaceAll(string, self, *matcher, templateStr, status);
}

/**
 @Status Caveat
 @Notes Uses default behavior only. Ignores NSMatchingOptions.
*/
- (NSString*)stringByReplacingMatchesInString:(NSString*)string
                                      options:(NSMatchingOptions)options
                                        range:(NSRange)range
                                 withTemplate:(NSString*)templateStr {
    // This is just a non-mutable version of replaceMatchesInString
    NSMutableString* mutableStr = [string mutableCopy];
    [self replaceMatchesInString:mutableStr options:options range:range withTemplate:templateStr];
    return [mutableStr autorelease];
}

static NSString* _escapeStringForCharacterSet(NSString* string, NSCharacterSet* set) {
    NSUInteger length = string.length;
    NSMutableString* returnVal = [NSMutableString stringWithCapacity:length * 2];

    const char* buffer = string.UTF8String;

    int lastTouchedCharacterIndex = -1;

    // For each character in buffer, check if it's a metacharacter that needs to be escaped.
    for (int i = 0; i < length; i++) {
        if ([set characterIsMember:buffer[i]]) {
            if (lastTouchedCharacterIndex != (i - 1)) {
                // Get substring that we can append now up to this point.
                NSString* part = [[NSString alloc] initWithBytesNoCopy:(void*)(buffer + (lastTouchedCharacterIndex + 1))
                                                                length:(i - (lastTouchedCharacterIndex + 1))
                                                              encoding:NSUTF8StringEncoding
                                                          freeWhenDone:false];

                [returnVal appendString:part];
                [part release];
            }
            lastTouchedCharacterIndex = i;

            // Append escaped metacharacter
            [returnVal appendFormat:@"\\%c", buffer[i]];
        }
    }

    // If nothing was escaped return original string
    if (lastTouchedCharacterIndex == -1) {
        return string;
    } else if (lastTouchedCharacterIndex != length - 1) {
        // Get the rest of the characters that weren't escaped.
        // Length is the length everything between i and the last encoded character exclusively.

        NSString* part = [[NSString alloc] initWithBytesNoCopy:(void*)(buffer + (lastTouchedCharacterIndex + 1))
                                                        length:(length - (lastTouchedCharacterIndex + 1))
                                                      encoding:NSUTF8StringEncoding
                                                  freeWhenDone:false];

        [returnVal appendString:part];
        [part release];
    }

    return returnVal;
}

/**
 @Status Interoperable
*/
+ (NSString*)escapedTemplateForString:(NSString*)string {
    return _escapeStringForCharacterSet(string, s_templateMetaCharacters);
}

/**
 @Status Interoperable
*/
+ (NSString*)escapedPatternForString:(NSString*)string {
    return _escapeStringForCharacterSet(string, s_patternMetaCharacters);
}

/**
 @Status Caveat
 @Notes Uses default behavior only. Ignores NSMatchingOptions.
*/
- (void)enumerateMatchesInString:(NSString*)string
                         options:(NSMatchingOptions)options
                           range:(NSRange)range
                      usingBlock:(void (^)(NSTextCheckingResult* result, NSMatchingFlags flags, BOOL* stop))block {
    // TODO - VSO 6262398: Switch on options to apply different ICU options to regex, remember to clear afterwards

    UErrorCode status = U_ZERO_ERROR;

    UStringHolder matchStr(string);

    RegexMatcher* matcher = _icuRegex->matcher(matchStr.string(), status);
    if (U_FAILURE(status)) {
        return;
    }

    NSTextCheckingResult* result;
    NSMatchingFlags flags = 0;
    BOOL stop = NO;

    matcher->region(range.location, range.location + range.length, status);
    if (U_FAILURE(status)) {
        return;
    }

    // Find matches, if match do block
    while (matcher->find() && !stop) {
        // Create NSTextCheckingResult
        NSRange foundRange = NSMakeRange(matcher->start(status), matcher->end(status) - matcher->start(status));
        if (U_FAILURE(status)) {
            break;
        } else {
            result = [NSTextCheckingResult regularExpressionCheckingResultWithRanges:&foundRange count:1 regularExpression:self];
            // Execute code block
            block(result, flags, &stop);
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)replacementStringForResult:(NSTextCheckingResult*)result
                               inString:(NSString*)string
                                 offset:(NSInteger)offset
                               template:(NSString*)templateStr {
    // get range from result
    NSRange range = result.range;

    // Create a new RegexMatcher by re-using the ivar pattern.
    UStringHolder tempStr(templateStr);
    UnicodeString replacedString;
    const UnicodeString unicodeTemplate = tempStr.string();
    UErrorCode status = U_ZERO_ERROR;

    NSString* newString = [string substringWithRange:{ range.location + offset, range.length }];

    UStringHolder newUString(newString);

    RegexMatcher* matcher = _icuRegex->matcher(newUString.string(), status);
    if (U_FAILURE(status)) {
        return nil;
    }

    replacedString = matcher->replaceAll(unicodeTemplate, status);

    if (U_FAILURE(status)) {
        return nil;
    }

    // Return only the replaced string
    std::string str;
    replacedString.toUTF8String(str);

    return [NSString stringWithUTF8String:str.c_str()];
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
- (instancetype)initWithCoder:(NSCoder*)coder {
    NSString* pattern = [[coder decodeObjectForKey:@"pattern"] retain];
    NSUInteger options = [coder decodeIntegerForKey:@"options"];

    return [self initWithPattern:pattern options:options error:nullptr];
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:_pattern forKey:@"pattern"];
    [coder encodeInteger:_options forKey:@"options"];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

@end