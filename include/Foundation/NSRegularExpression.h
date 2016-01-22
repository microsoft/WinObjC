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

#ifndef _NSREGULAREXPRESSION_H_
#define _NSREGULAREXPRESSION_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSTextCheckingResult.h>

typedef NS_OPTIONS(NSUInteger, NSMatchingFlags) {
    NSMatchingProgress = 1,
    NSMatchingCompleted = 2,
    NSMatchingHitEnd = 4,
    NSMatchingRequiredEnd = 8,
    NSMatchingInternalError = 16,
};

typedef NS_OPTIONS(NSUInteger, NSRegularExpressionOptions) {
    NSRegularExpressionCaseInsensitive = 1,
    NSRegularExpressionAllowCommentsAndWhitespace = 2,
    NSRegularExpressionIgnoreMetacharacters = 4,
    NSRegularExpressionDotMatchesLineSeparators = 8,
    NSRegularExpressionAnchorsMatchLines = 16,
    NSRegularExpressionUseUnixLineSeparators = 32,
    NSRegularExpressionUseUnicodeWordBoundaries = 64
};

typedef NS_OPTIONS(NSUInteger, NSMatchingOptions) {
    NSMatchingReportProgress = 1,
    NSMatchingReportCompletion = 2,
    NSMatchingAnchored = 4,
    NSMatchingWithTransparentBounds = 8,
    NSMatchingWithoutAnchoringBounds = 16
};

@class NSError;
@class NSArray;
@class NSMutableString;

FOUNDATION_EXPORT_CLASS
@interface NSRegularExpression : NSObject <NSSecureCoding, NSCopying, NSObject>

@property (readonly, copy) NSString* pattern;
@property (readonly) NSRegularExpressionOptions options;
@property (readonly) NSUInteger numberOfCaptureGroups;

+ (NSRegularExpression*)regularExpressionWithPattern:(NSString*)pattern options:(NSRegularExpressionOptions)options error:(NSError**)error;
+ (NSString*)escapedTemplateForString:(NSString*)string;
+ (NSString*)escapedPatternForString:(NSString*)string;

- (instancetype)initWithPattern:(NSString*)pattern options:(NSRegularExpressionOptions)options error:(NSError**)error;
- (NSUInteger)numberOfMatchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range;
- (NSArray*)matchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range;
- (void)enumerateMatchesInString:(NSString*)string
                         options:(NSMatchingOptions)options
                           range:(NSRange)range
                      usingBlock:(void (^)(NSTextCheckingResult* result, NSMatchingFlags flags, BOOL* stop))block;

- (NSTextCheckingResult*)firstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range;
- (NSRange)rangeOfFirstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range;
- (NSString*)stringByReplacingMatchesInString:(NSString*)string
                                      options:(NSMatchingOptions)options
                                        range:(NSRange)range
                                 withTemplate:(NSString*)templateObj;

- (NSString*)replacementStringForResult:(NSTextCheckingResult*)result
                               inString:(NSString*)string
                                 offset:(NSInteger)offset
                               template:(NSString*)templateObj;

- (NSUInteger)replaceMatchesInString:(NSMutableString*)string
                             options:(NSMatchingOptions)options
                               range:(NSRange)range
                        withTemplate:(NSString*)templateStr;

@end

#endif /* _NSREGULAREXPRESSION_H_ */