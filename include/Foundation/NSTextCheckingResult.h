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
@class NSRegularExpression;
@class NSDictionary;
@class NSURL;
@class NSDate;
@class NSTimeZone;
@class NSOrthography;
@class NSArray;

typedef uint64_t NSTextCheckingType;
typedef uint64_t NSTextCheckingTypes;
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

enum {
    NSTextCheckingAllSystemTypes = 0xffffffffULL,
    NSTextCheckingAllCustomTypes = 0xffffffffULL << 32,
    NSTextCheckingAllTypes = (NSTextCheckingAllSystemTypes | NSTextCheckingAllCustomTypes)
};

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

FOUNDATION_EXPORT_CLASS
@interface NSTextCheckingResult : NSObject <NSCoding, NSCopying>
@property (readonly) NSRange range;
@property (readonly) NSTextCheckingType resultType;
@property (readonly) NSUInteger numberOfRanges;
- (NSRange)rangeAtIndex:(NSUInteger)idx;
+ (NSTextCheckingResult*)replacementCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacementString;
@property (readonly, copy) NSString* replacementString;
+ (NSTextCheckingResult*)regularExpressionCheckingResultWithRanges:(NSRangePointer)ranges
                                                             count:(NSUInteger)count
                                                 regularExpression:(NSRegularExpression*)regularExpression;
@property (readonly, copy) NSRegularExpression* regularExpression;
@property (readonly, copy) NSDictionary* components;
+ (NSTextCheckingResult*)linkCheckingResultWithRange:(NSRange)range URL:(NSURL*)url;
@property (readonly, copy) NSURL* URL;
+ (NSTextCheckingResult*)addressCheckingResultWithRange:(NSRange)range components:(NSDictionary*)components;
@property (readonly, copy) NSDictionary* addressComponents;
+ (NSTextCheckingResult*)transitInformationCheckingResultWithRange:(NSRange)range components:(NSDictionary*)components;
+ (NSTextCheckingResult*)phoneNumberCheckingResultWithRange:(NSRange)range phoneNumber:(NSString*)phoneNumber;
@property (readonly, copy) NSString* phoneNumber;
+ (NSTextCheckingResult*)dateCheckingResultWithRange:(NSRange)range date:(NSDate*)date;
+ (NSTextCheckingResult*)dateCheckingResultWithRange:(NSRange)range
                                                date:(NSDate*)date
                                            timeZone:(NSTimeZone*)timeZone
                                            duration:(NSTimeInterval)duration;
@property (readonly, copy) NSDate* date;
@property (readonly) NSTimeInterval duration;
@property (readonly, copy) NSTimeZone* timeZone;
+ (NSTextCheckingResult*)dashCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacementString;
+ (NSTextCheckingResult*)quoteCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacementString;
+ (NSTextCheckingResult*)spellCheckingResultWithRange:(NSRange)range;
+ (NSTextCheckingResult*)correctionCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacementString;
+ (NSTextCheckingResult*)orthographyCheckingResultWithRange:(NSRange)range orthography:(NSOrthography*)orthography;
@property (readonly, copy) NSOrthography* orthography;
+ (NSTextCheckingResult*)grammarCheckingResultWithRange:(NSRange)range details:(NSArray*)details;
@property (readonly, copy) NSArray* grammarDetails;
- (NSTextCheckingResult*)resultByAdjustingRangesWithOffset:(NSInteger)offset;
@end
