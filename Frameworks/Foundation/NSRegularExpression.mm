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
#include <stdlib.h>
#include <vector>

#import "LoggingNative.h"

@interface NSRegularExpression () {
    std::unique_ptr<RegexPattern> _icuRegex;
}
@property (readwrite, copy) NSString* pattern;
@property (readwrite) NSRegularExpressionOptions options;
@property (readwrite) NSUInteger numberOfCaptureGroups;
@end

static StrongId<NSCharacterSet> s_patternMetaCharacters;
static StrongId<NSCharacterSet> s_templateMetaCharacters;

@implementation NSRegularExpression
/**
 @Status Interoperable
*/
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

// Helper function for evaluating option and flag membership
static bool _evaluateOptionOrFlag(NSUInteger expectedOption, NSUInteger userOptions) {
    return (expectedOption & userOptions) != 0;
}

static const wchar_t* TAG = L"NSRegularExpression";
// Helper function for logging an ICU error code.
static bool _U_LogIfError(UErrorCode status) {
    if (U_FAILURE(status)) {
        TraceError(TAG, L"ICU Status Error. Error Code : %hs.", u_errorName(status));
        return true;
    }
    return false;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithPattern:(NSString*)pattern options:(NSRegularExpressionOptions)options error:(NSError**)error {
    if (self = [super init]) {
        _pattern = [pattern copy];

        int icuRegexOptions = 0;
        if (_evaluateOptionOrFlag(NSRegularExpressionCaseInsensitive, options)) {
            icuRegexOptions |= UREGEX_CASE_INSENSITIVE;
        }
        if (_evaluateOptionOrFlag(NSRegularExpressionAllowCommentsAndWhitespace, options)) {
            icuRegexOptions |= UREGEX_COMMENTS;
        }
        if (_evaluateOptionOrFlag(NSRegularExpressionIgnoreMetacharacters, options)) {
            // TODO - VSO 6264731: UREGEX_LITERAL causes faliures in ICU. Workaround is to use escaped version of pattern.

            // icuRegexOptions |= UREGEX_LITERAL;
            _pattern = [[NSRegularExpression escapedPatternForString:pattern] retain];
        }
        if (_evaluateOptionOrFlag(NSRegularExpressionDotMatchesLineSeparators, options)) {
            icuRegexOptions |= UREGEX_DOTALL;
        }
        if (_evaluateOptionOrFlag(NSRegularExpressionAnchorsMatchLines, options)) {
            icuRegexOptions |= UREGEX_MULTILINE;
        }
        if (_evaluateOptionOrFlag(NSRegularExpressionUseUnixLineSeparators, options)) {
            icuRegexOptions |= UREGEX_UNIX_LINES;
        }
        if (_evaluateOptionOrFlag(NSRegularExpressionUseUnicodeWordBoundaries, options)) {
            icuRegexOptions |= UREGEX_UWORD;
        }

        UErrorCode status = U_ZERO_ERROR;
        UParseError parseStatus;
        _icuRegex.reset(RegexPattern::compile(UnicodeString([_pattern UTF8String]), icuRegexOptions, parseStatus, status));

        if (_U_LogIfError(status)) {
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

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_pattern release];

    [super dealloc];
}

// Helper function for setting ICU Regex options.
static void _setMatcherOptions(RegexMatcher& icuRegex, int options) {
    // Set transparent bounds
    if (_evaluateOptionOrFlag(NSMatchingWithTransparentBounds, options)) {
        icuRegex.useTransparentBounds(true);
    }

    // Without anchoring bounds
    if (!(_evaluateOptionOrFlag(NSMatchingWithoutAnchoringBounds, options))) {
        icuRegex.useAnchoringBounds(true);
    } else {
        icuRegex.useAnchoringBounds(false);
    }
}

/**
 @Status Interoperable
*/
- (NSUInteger)numberOfMatchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    __block NSUInteger count = 0;

    [self enumerateMatchesInString:string
                           options:options
                             range:range
                        usingBlock:^void(NSTextCheckingResult* textResult, NSMatchingFlags flags, BOOL* stop) {
                            if (textResult) {
                                count++;
                            }
                        }];

    return count;
}

/**
 @Status Interoperable
*/
- (NSTextCheckingResult*)firstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    NSRange tempRange = NSMakeRange(NSNotFound, 0);
    __block NSTextCheckingResult* result =
        [[NSTextCheckingResult regularExpressionCheckingResultWithRanges:&tempRange count:1 regularExpression:self] retain];

    [self enumerateMatchesInString:string
                           options:options
                             range:range
                        usingBlock:^void(NSTextCheckingResult* textResult, NSMatchingFlags flags, BOOL* stop) {
                            if (textResult) {
                                result = [textResult retain];
                                *stop = YES;
                            }
                        }];

    return [result autorelease];
}

/**
 @Status Interoperable
*/
- (NSRange)rangeOfFirstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    __block NSRange result = { NSNotFound, 0 };

    [self enumerateMatchesInString:string
                           options:options
                             range:range
                        usingBlock:^void(NSTextCheckingResult* textResult, NSMatchingFlags flags, BOOL* stop) {
                            if (textResult) {
                                result = textResult.range;
                                *stop = YES;
                            }
                        }];

    return result;
}

/**
 @Status Interoperable
*/
- (NSArray*)matchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    __block NSMutableArray* result = [NSMutableArray array];

    [self enumerateMatchesInString:string
                           options:options
                             range:range
                        usingBlock:^void(NSTextCheckingResult* textResult, NSMatchingFlags flags, BOOL* stop) {
                            if (textResult) {
                                [result addObject:textResult];
                            }
                        }];

    return result;
}

/**
 @Status Interoperable
*/
- (NSUInteger)replaceMatchesInString:(NSMutableString*)string
                             options:(NSMatchingOptions)options
                               range:(NSRange)range
                        withTemplate:(NSString*)templateStr {
    NSArray* matches = [self matchesInString:string options:options range:range];

    int offset = 0;

    for (NSTextCheckingResult* result in matches) {
        NSString* replacedText = [self replacementStringForResult:result inString:string offset:offset template:templateStr];

        if (replacedText == nil) {
            break;
        }

        NSRange foundRange = result.range;
        foundRange.location += offset;
        [string replaceCharactersInRange:foundRange withString:replacedText];

        offset += replacedText.length - foundRange.length;
    }
    return [matches count];
}

/**
 @Status Interoperable
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
    NSData* dataOfString = [string dataUsingEncoding:NSUTF8StringEncoding];
    const char* buffer = (const char*)dataOfString.bytes;
    NSUInteger length = [dataOfString length];

    NSMutableString* returnVal = [NSMutableString stringWithCapacity:length * 2];

    int lastTouchedByteIndex = -1;
    int i = 0;
    UChar32 currentCharacter = 0;

    while (i < length) {
        // Use U8_NEXT to step over code points
        U8_NEXT(buffer, i, length, currentCharacter);
        if ([set characterIsMember:currentCharacter]) {
            if (lastTouchedByteIndex < i - 1) {
                // Get substring that we can append now up to this point.
                _appendBufferToNSString(buffer, (lastTouchedByteIndex + 1), (i - lastTouchedByteIndex - 2), returnVal);
            }
            lastTouchedByteIndex = i - 1;

            // Append escaped metacharacter
            [returnVal appendFormat:@"\\%c", currentCharacter];
        }
    }

    // If nothing was escaped return original string
    if (lastTouchedByteIndex == -1) {
        return string;
    } else if (lastTouchedByteIndex < length) {
        // Get the rest of the characters that weren't escaped.
        // Length is the length everything between i and the last encoded character exclusively.
        _appendBufferToNSString(buffer, (lastTouchedByteIndex + 1), (length - (lastTouchedByteIndex + 1)), returnVal);
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

struct CallBackContext {
    BOOL* stop;
    void (^block)(NSTextCheckingResult* result, NSMatchingFlags flags, BOOL* stop);

    // This callback services NSMatchingProgress where the second argument does not matter.
    // Two callbacks are serviced with slightly different args, only the first of which we care about.
    template <typename... Args>
    static UBool matchCallback(const void* context, Args... args) {
        // cast context to struct type
        auto callbackStruct = reinterpret_cast<const CallBackContext*>(context);

        // call block with struct's stop
        callbackStruct->block(nil, NSMatchingProgress, callbackStruct->stop);

        // return stop...?
        return !(*callbackStruct->stop);
    }
};

/**
 @Status Interoperable
*/
- (void)enumerateMatchesInString:(NSString*)string
                         options:(NSMatchingOptions)options
                           range:(NSRange)range
                      usingBlock:(void (^)(NSTextCheckingResult* result, NSMatchingFlags flags, BOOL* stop))block {
    UErrorCode status = U_ZERO_ERROR;

    RegexMatcher* matcher = _icuRegex->matcher(UnicodeString([string UTF8String]), status);
    if (_U_LogIfError(status)) {
        return;
    }

    BOOL stop = NO;
    CallBackContext context = { &stop, block };

    // Set callbacks for reporting progress
    if (options & NSMatchingReportProgress) {
        matcher->setMatchCallback(&CallBackContext::matchCallback<int32_t>, &context, status);
        if (_U_LogIfError(status)) {
            return;
        }

        matcher->setFindProgressCallback(&CallBackContext::matchCallback<int64_t>, &context, status);
        if (_U_LogIfError(status)) {
            return;
        }
    }

    NSMatchingFlags flags = 0;

    matcher->region(range.location, range.location + range.length, status);

    if (_U_LogIfError(status)) {
        return;
    }

    _setMatcherOptions(*matcher, options);

    bool anchorMatch = _evaluateOptionOrFlag(NSMatchingAnchored, options);

    // Find matches, if match do block
    while (matcher->find() && !stop) {
        flags = 0;

        // TODO: ICU 48 does not support find(status) implemented in ICU 55. This is required for accurate NSMatchingInternalError flagging
        if (_U_LogIfError(status)) {
            flags |= NSMatchingInternalError;
            block(nil, flags, &stop);
        } else {
            // Create NSTextCheckingResult
            int startpos = matcher->start(status);
            if (_U_LogIfError(status)) {
                block(nil, NSMatchingInternalError, &stop);
                break;
            }

            int endpos = matcher->end(status);
            if (_U_LogIfError(status)) {
                block(nil, NSMatchingInternalError, &stop);
                break;
            }

            NSRange foundRange = NSMakeRange(startpos, endpos - startpos);
            if (!anchorMatch || (anchorMatch && startpos == range.location)) {
                NSTextCheckingResult* result = nil;

                std::vector<NSRange> ranges(matcher->groupCount() + 1);
                for (int i = 0; i <= matcher->groupCount(); i++) {
                    int start = matcher->start(i, status);
                    if (_U_LogIfError(status)) {
                        return;
                    }
                    int length = matcher->end(i, status) - start;
                    if (_U_LogIfError(status)) {
                        return;
                    }

                    ranges[i].location = start;
                    ranges[i].length = length;
                }

                result = [NSTextCheckingResult regularExpressionCheckingResultWithRanges:ranges.data()
                                                                                   count:ranges.size()
                                                                       regularExpression:self];

                if (matcher->requireEnd()) {
                    flags |= NSMatchingRequiredEnd;
                }

                if (matcher->hitEnd()) {
                    flags |= NSMatchingHitEnd;
                }
                block(result, flags, &stop);
            }
        }

        status = U_ZERO_ERROR;
    }

    if (_evaluateOptionOrFlag(NSMatchingCompleted, options)) {
        flags |= NSMatchingCompleted;
        block(nil, flags, &stop);
    }
}

// Internal method for string building in replace calls.
static void _appendBufferToNSString(const char* string, int start, int length, NSMutableString* appendString) {
    NSString* part =
        [[NSString alloc] initWithBytesNoCopy:(void*)(string + start) length:length encoding:NSUTF8StringEncoding freeWhenDone:false];
    [appendString appendString:part];
    [part release];
}

/**
 @Status Interoperable
*/
- (NSString*)replacementStringForResult:(NSTextCheckingResult*)result
                               inString:(NSString*)string
                                 offset:(NSInteger)offset
                               template:(NSString*)templateStr {
    NSData* dataOfString = [templateStr dataUsingEncoding:NSUTF8StringEncoding];
    const char* bytesOfString = (const char*)dataOfString.bytes;

    int lastByteIndex = -1;
    int lengthOfBytes = [dataOfString length];
    NSMutableString* returnString = [NSMutableString stringWithCapacity:lengthOfBytes];
    UChar32 currentCharacter = 0;
    int i = 0;

    while (i < lengthOfBytes) {
        // Use U8_NEXT to step over code points
        U8_NEXT(bytesOfString, i, lengthOfBytes, currentCharacter);
        if (currentCharacter == '$') {
            const char nextCharacter = bytesOfString[i];
            if (nextCharacter >= '0' && nextCharacter <= '9') {
                // Optimized append step to avoid single character string building.
                if (lastByteIndex != (i - 1)) {
                    // Append characters from last touched character up to but excluding this capture group
                    _appendBufferToNSString(bytesOfString, (lastByteIndex + 1), ((i - 1) - (lastByteIndex + 1)), returnString);
                }
                char* final = nullptr;
                unsigned long matchIdx = strtoul(&bytesOfString[i], &final, 10);

                // We want i to represent that we stepped over these decimal characters.
                i = final - bytesOfString - 1;
                if (matchIdx <= _numberOfCaptureGroups) {
                    NSRange range = [result rangeAtIndex:matchIdx];
                    range.location += offset;
                    [returnString appendString:[string substringWithRange:range]];
                }

                lastByteIndex = i;
            }
        } else if (currentCharacter == '\\') {
            // Append characters up to and excluding the '\'
            if (lastByteIndex != (i - 1)) {
                // Get a substring based on the bytes offset by the last touched index to the current index
                // Length is the length everything between i and the last encoded character exclusively.
                _appendBufferToNSString(bytesOfString, (lastByteIndex + 1), ((i - 1) - (lastByteIndex + 1)), returnString);
            }

            // Ignore the escaped '\'
            lastByteIndex = i - 1;
            i++;
        }
    }

    if (lastByteIndex == -1) {
        return [[templateStr copy] autorelease];
    } else if (lastByteIndex < lengthOfBytes) {
        // Get the rest of the characters that weren't already appended
        // Length is the length everything between i and the last modified character.
        _appendBufferToNSString(bytesOfString, (lastByteIndex + 1), (lengthOfBytes - (lastByteIndex + 1)), returnString);
    }

    return returnString;
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