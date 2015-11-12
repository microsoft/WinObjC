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

#ifndef _NSTEXTCHECKINGRESULT_H_
#define _NSTEXTCHECKINGRESULT_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSDate.h>

@class NSDictionary, NSURL, NSOrthography;

SB_EXPORT NSString* const NSTextCheckingNameKey;
SB_EXPORT NSString* const NSTextCheckingJobTitleKey;
SB_EXPORT NSString* const NSTextCheckingOrganizationKey;
SB_EXPORT NSString* const NSTextCheckingStreetKey;
SB_EXPORT NSString* const NSTextCheckingCityKey;
SB_EXPORT NSString* const NSTextCheckingStateKey;
SB_EXPORT NSString* const NSTextCheckingZIPKey;
SB_EXPORT NSString* const NSTextCheckingCountryKey;
SB_EXPORT NSString* const NSTextCheckingPhoneKey;

enum {
    NSTextCheckingTypeOrthography = 1ULL << 0,
    NSTextCheckingTypeSpelling = 1ULL << 1,
    NSTextCheckingTypeGrammar = 1ULL << 2,
    NSTextCheckingTypeDate = 1ULL << 3,
    NSTextCheckingTypeAddress = 1ULL << 4,
    NSTextCheckingTypeLink = 1ULL << 5,
    NSTextCheckingTypeQuote = 1ULL << 6,
    NSTextCheckingTypeDash = 1ULL << 7,
    NSTextCheckingTypeReplacement = 1ULL << 8,
    NSTextCheckingTypeCorrection = 1ULL << 9,
    NSTextCheckingTypeRegularExpression = 1ULL << 10,
    NSTextCheckingTypePhoneNumber = 1ULL << 11,
    NSTextCheckingTypeTransitInformation = 1ULL << 12
};
typedef uint32_t NSTextCheckingType;

enum : uint64_t {
    NSTextCheckingAllSystemTypes = 0xffffffffULL,
    NSTextCheckingAllCustomTypes = 0xffffffffULL << 32,
    NSTextCheckingAllTypes = (NSTextCheckingAllSystemTypes | NSTextCheckingAllCustomTypes),
};
typedef uint64_t NSTextCheckingTypes;

@interface NSTextCheckingResult : NSObject

+ (NSTextCheckingResult*)addressCheckingResultWithRange:(NSRange)range components:(NSDictionary*)components;
+ (NSTextCheckingResult*)correctionCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacement;
+ (NSTextCheckingResult*)dashCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacement;
+ (NSTextCheckingResult*)dateCheckingResultWithRange:(NSRange)range date:(NSDate*)date;
+ (NSTextCheckingResult*)dateCheckingResultWithRange:(NSRange)range
                                                date:(NSDate*)date
                                            timeZone:(NSTimeZone*)timeZone
                                            duration:(NSTimeInterval)duration;
+ (NSTextCheckingResult*)grammarCheckingResultWithRange:(NSRange)range details:(NSArray*)details;
+ (NSTextCheckingResult*)linkCheckingResultWithRange:(NSRange)range URL:(NSURL*)url;
+ (NSTextCheckingResult*)orthographyCheckingResultWithRange:(NSRange)range orthography:(NSOrthography*)orthography;
+ (NSTextCheckingResult*)quoteCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacement;
+ (NSTextCheckingResult*)replacementCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacement;
+ (NSTextCheckingResult*)spellCheckingResultWithRange:(NSRange)range;
+ (NSTextCheckingResult*)phoneNumberCheckingResultWithRange:(NSRange)range phoneNumber:(NSString*)phoneNumber;

- (NSRange)rangeAtIndex:(NSUInteger)idx;

@property (readonly) NSDictionary* addressComponents;
@property (readonly) NSDate* date;
@property (readonly) NSTimeInterval duration;
@property (readonly) NSArray* grammarDetails;
@property (readonly) NSOrthography* orthography;
@property (readonly) NSRange range;
@property (readonly) NSString* replacementString;
@property (readonly) NSTextCheckingType resultType;
@property (readonly) NSTimeZone* timeZone;
@property (readonly) NSURL* URL;
@property (readonly) NSString* phoneNumber;
@property (readonly) NSUInteger numberOfRanges;

@end

#endif /* _NSTEXTCHECKINGRESULT_H_ */