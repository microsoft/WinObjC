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

@class NSDictionary, NSURL, NSOrthography, NSRegularExpression;

FOUNDATION_EXPORT NSString* const NSTextCheckingAirlineKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingFlightKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingNameKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingJobTitleKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingOrganizationKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingStreetKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingCityKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingStateKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingZIPKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingCountryKey;
FOUNDATION_EXPORT NSString* const NSTextCheckingPhoneKey;

typedef NS_ENUM(NSUInteger, NSTextCheckingType) {
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

typedef NS_ENUM(NSUInteger, NSTextCheckingTypes) {
    NSTextCheckingAllSystemTypes = 0xffffffffULL,
    NSTextCheckingAllCustomTypes = 0xffffffffULL << 32,
    NSTextCheckingAllTypes = (NSTextCheckingAllSystemTypes | NSTextCheckingAllCustomTypes),
};

FOUNDATION_EXPORT_CLASS
@interface NSTextCheckingResult : NSObject <NSSecureCoding, NSCopying, NSObject>

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
+ (NSTextCheckingResult*)regularExpressionCheckingResultWithRanges:(NSRangePointer)ranges
                                                             count:(NSUInteger)count
                                                 regularExpression:(NSRegularExpression*)regularExpression;
+ (NSTextCheckingResult*)transitInformationCheckingResultWithRange:(NSRange)range components:(NSDictionary*)components;

- (NSRange)rangeAtIndex:(NSUInteger)idx;
- (NSTextCheckingResult*)resultByAdjustingRangesWithOffset:(NSInteger)offset;

@property (readonly) NSRange range;
@property (readonly) NSTextCheckingType resultType;
@property (readonly) NSUInteger numberOfRanges;
@property (readonly) NSTimeInterval duration;
@property (readonly, copy) NSString* replacementString;
@property (readonly, copy) NSRegularExpression* regularExpression;
@property (readonly, copy) NSDictionary* components;
@property (readonly, copy) NSURL* URL;
@property (readonly, copy) NSDictionary* addressComponents;
@property (readonly, copy) NSString* phoneNumber;
@property (readonly, copy) NSDate* date;
@property (readonly, copy) NSTimeZone* timeZone;
@property (readonly, copy) NSOrthography* orthography;
@property (readonly, copy) NSArray* grammarDetails;

@end

#endif /* _NSTEXTCHECKINGRESULT_H_ */