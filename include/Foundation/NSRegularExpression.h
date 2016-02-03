//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>

@class NSString;
@class NSError;
@class NSTextCheckingResult;
@class NSArray;
@class NSMutableString;

typedef NSUInteger NSRegularExpressionOptions;
typedef NSUInteger NSMatchingFlags;
typedef NSUInteger NSMatchingOptions;
enum {
    NSRegularExpressionCaseInsensitive = 1 << 0,
    NSRegularExpressionAllowCommentsAndWhitespace = 1 << 1,
    NSRegularExpressionIgnoreMetacharacters = 1 << 2,
    NSRegularExpressionDotMatchesLineSeparators = 1 << 3,
    NSRegularExpressionAnchorsMatchLines = 1 << 4,
    NSRegularExpressionUseUnixLineSeparators = 1 << 5,
    NSRegularExpressionUseUnicodeWordBoundaries = 1 << 6
};

enum {
    NSMatchingProgress = 1 << 0,
    NSMatchingCompleted = 1 << 1,
    NSMatchingHitEnd = 1 << 2,
    NSMatchingRequiredEnd = 1 << 3,
    NSMatchingInternalError = 1 << 4
};

enum {
    NSMatchingReportProgress = 1 << 0,
    NSMatchingReportCompletion = 1 << 1,
    NSMatchingAnchored = 1 << 2,
    NSMatchingWithTransparentBounds = 1 << 3,
    NSMatchingWithoutAnchoringBounds = 1 << 4
};

FOUNDATION_EXPORT_CLASS
@interface NSRegularExpression : NSObject <NSCoding, NSCopying>
+ (NSRegularExpression*)regularExpressionWithPattern:(NSString*)pattern
                                             options:(NSRegularExpressionOptions)options
                                               error:(NSError* _Nullable*)error;
- (instancetype)initWithPattern:(NSString*)pattern options:(NSRegularExpressionOptions)options error:(NSError* _Nullable*)error;
@property (readonly, copy) NSString* pattern;
@property (readonly) NSRegularExpressionOptions options;
@property (readonly) NSUInteger numberOfCaptureGroups;
- (NSUInteger)numberOfMatchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range;
- (void)enumerateMatchesInString:(NSString*)string
                         options:(NSMatchingOptions)options
                           range:(NSRange)range
                      usingBlock:(void (^)(NSTextCheckingResult*, NSMatchingFlags, BOOL*))block;
- (NSArray*)matchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range;
- (NSTextCheckingResult*)firstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range;
- (NSRange)rangeOfFirstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range;

- (NSUInteger)replaceMatchesInString:(NSMutableString*)string
                             options:(NSMatchingOptions)options
                               range:(NSRange)range
                        withTemplate:(NSString*)templateObj;
- (NSString*)stringByReplacingMatchesInString:(NSString*)string
                                      options:(NSMatchingOptions)options
                                        range:(NSRange)range
                                 withTemplate:(NSString*)templateObj;
+ (NSString*)escapedTemplateForString:(NSString*)string;
+ (NSString*)escapedPatternForString:(NSString*)string;
- (NSString*)replacementStringForResult:(NSTextCheckingResult*)result
                               inString:(NSString*)string
                                 offset:(NSInteger)offset
                               template:(NSString*)templateObj;
@end
