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
#include "Foundation/NSTextCheckingResult.h"
#include "Foundation/NSMutableArray.h"

// String constants confirmed from reference platform.
NSString* const NSTextCheckingAirlineKey = @"^Airline";
NSString* const NSTextCheckingFlightKey = @"^Flight";
NSString* const NSTextCheckingNameKey = @"^Name";
NSString* const NSTextCheckingJobTitleKey = @"^JobTitle";
NSString* const NSTextCheckingOrganizationKey = @"^Organization";
NSString* const NSTextCheckingStreetKey = @"^Street";
NSString* const NSTextCheckingCityKey = @"^City";
NSString* const NSTextCheckingStateKey = @"^State";
NSString* const NSTextCheckingZIPKey = @"^ZIP";
NSString* const NSTextCheckingCountryKey = @"^Country";
NSString* const NSTextCheckingPhoneKey = @"^Phone";

@interface NSTextCheckingResult ()
@property (readwrite) NSRange range;
@property (readwrite) NSTextCheckingType resultType;
@property (readwrite) NSUInteger numberOfRanges;
@property (readwrite) NSTimeInterval duration;
@property (readwrite, copy) NSString* replacementString;
@property (readwrite, copy) NSRegularExpression* regularExpression;
@property (readwrite, copy) NSDictionary* components;
@property (readwrite, copy) NSURL* URL;
@property (readwrite, copy) NSDictionary* addressComponents;
@property (readwrite, copy) NSString* phoneNumber;
@property (readwrite, copy) NSDate* date;
@property (readwrite, copy) NSTimeZone* timeZone;
@property (readwrite, copy) NSOrthography* orthography;
@property (readwrite, copy) NSArray* grammarDetails;
@end

@implementation NSTextCheckingResult {
    NSMutableArray* _rangesForResult;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_replacementString release];
    [_regularExpression release];
    [_components release];
    [_URL release];
    [_addressComponents release];
    [_phoneNumber release];
    [_date release];
    [_timeZone release];
    [_orthography release];
    [_grammarDetails release];
    [_rangesForResult release];

    [super dealloc];
}

- (instancetype)_initWithRanges:(NSRangePointer)ranges count:(int)count {
    if (self = [super init]) {
        _rangesForResult = [[NSMutableArray alloc] initWithCapacity:count];
        for (int i = 0; i < count; i++) {
            [_rangesForResult insertObject:[NSValue valueWithRange:ranges[i]] atIndex:i];
        }
        _range = ranges[0];
        _numberOfRanges = count;
    }

    return self;
}

- (instancetype)_initWithDictionaryComponents:(NSRangePointer)ranges count:(int)count components:(NSDictionary*)components {
    if (self = [self _initWithRanges:ranges count:count]) {
        _components = [components copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)transitInformationCheckingResultWithRange:(NSRange)range components:(NSDictionary*)components {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithDictionaryComponents:&range count:1 components:components];
    retval.resultType = NSTextCheckingTypeTransitInformation;
    return [retval autorelease];
}

- (instancetype)_initWithDictionaryAddressComponents:(NSRangePointer)ranges count:(int)count components:(NSDictionary*)components {
    if (self = [self _initWithRanges:ranges count:count]) {
        _addressComponents = [components copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)addressCheckingResultWithRange:(NSRange)range components:(NSDictionary*)components {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithDictionaryAddressComponents:&range count:1 components:components];
    retval.resultType = NSTextCheckingTypeAddress;
    return [retval autorelease];
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)correctionCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacement {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithReplacement:&range count:1 replacementString:replacement];

    return [retval autorelease];
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)dashCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacement {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithReplacement:&range count:1 replacementString:replacement];
    retval.resultType = NSTextCheckingTypeDash;
    return [retval autorelease];
}

- (instancetype)_initWithDate:(NSRangePointer)ranges count:(int)count date:(NSDate*)date {
    if (self = [self _initWithRanges:ranges count:count]) {
        _date = [date copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)dateCheckingResultWithRange:(NSRange)range date:(NSDate*)date {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithDate:&range count:1 date:date];
    retval.resultType = NSTextCheckingTypeDate;
    return [retval autorelease];
}

- (instancetype)_initWithDateAndTime:(NSRangePointer)ranges
                               count:(int)count
                                date:(NSDate*)date
                            timeZone:(NSTimeZone*)timeZone
                            duration:(NSTimeInterval)duration {
    if (self = [self _initWithDate:ranges count:count date:date]) {
        _timeZone = [timeZone copy];
        _duration = duration;
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)dateCheckingResultWithRange:(NSRange)range
                                                date:(NSDate*)date
                                            timeZone:(NSTimeZone*)timeZone
                                            duration:(NSTimeInterval)duration {
    NSTextCheckingResult* retval =
        [[NSTextCheckingResult alloc] _initWithDateAndTime:&range count:1 date:date timeZone:timeZone duration:duration];
    retval.resultType = NSTextCheckingTypeDate;
    return [retval autorelease];
}

- (instancetype)_initWithGrammar:(NSRangePointer)ranges count:(int)count details:(NSArray*)details {
    if (self = [self _initWithRanges:ranges count:count]) {
        _grammarDetails = [details copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)grammarCheckingResultWithRange:(NSRange)range details:(NSArray*)details {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithGrammar:&range count:1 details:details];
    retval.resultType = NSTextCheckingTypeGrammar;
    return [retval autorelease];
}

- (instancetype)_initWithLink:(NSRangePointer)ranges count:(int)count URL:(NSURL*)url {
    if (self = [self _initWithRanges:ranges count:count]) {
        _URL = [url copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)linkCheckingResultWithRange:(NSRange)range URL:(NSURL*)url {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithLink:&range count:1 URL:url];
    retval.resultType = NSTextCheckingTypeLink;
    return [retval autorelease];
}

- (instancetype)_initWithOrthography:(NSRangePointer)ranges count:(int)count orthography:(NSOrthography*)orthography {
    if (self = [self _initWithRanges:ranges count:count]) {
        _orthography = [orthography copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)orthographyCheckingResultWithRange:(NSRange)range orthography:(NSOrthography*)orthography {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithOrthography:&range count:1 orthography:orthography];
    retval.resultType = NSTextCheckingTypeOrthography;
    return [retval autorelease];
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)quoteCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacement {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithReplacement:&range count:1 replacementString:replacement];
    retval.resultType = NSTextCheckingTypeQuote;
    return [retval autorelease];
}

- (instancetype)_initWithReplacement:(NSRangePointer)ranges count:(int)count replacementString:(NSString*)replacement {
    if (self = [self _initWithRanges:ranges count:count]) {
        _replacementString = [replacement copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)replacementCheckingResultWithRange:(NSRange)range replacementString:(NSString*)replacement {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithReplacement:&range count:1 replacementString:replacement];
    retval.resultType = NSTextCheckingTypeReplacement;
    return [retval autorelease];
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)spellCheckingResultWithRange:(NSRange)range {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithRanges:&range count:1];
    retval.resultType = NSTextCheckingTypeSpelling;
    return [retval autorelease];
}

- (instancetype)_initWithPhoneNumber:(NSRangePointer)ranges count:(int)count phoneNumber:(NSString*)phoneNumber {
    if (self = [self _initWithRanges:ranges count:count]) {
        _phoneNumber = [phoneNumber copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)phoneNumberCheckingResultWithRange:(NSRange)range phoneNumber:(NSString*)phoneNumber {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithPhoneNumber:&range count:1 phoneNumber:phoneNumber];
    retval.resultType = NSTextCheckingTypePhoneNumber;
    return [retval autorelease];
}

- (instancetype)_initWithRanges:(NSRangePointer)ranges count:(int)count regularExpression:(NSRegularExpression*)regularexpression {
    if (self = [self _initWithRanges:ranges count:count]) {
        _regularExpression = [regularexpression copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTextCheckingResult*)regularExpressionCheckingResultWithRanges:(NSRangePointer)ranges
                                                             count:(NSUInteger)count
                                                 regularExpression:(NSRegularExpression*)regularExpression {
    NSTextCheckingResult* retval = [[NSTextCheckingResult alloc] _initWithRanges:ranges count:count regularExpression:regularExpression];
    retval.resultType = NSTextCheckingTypeRegularExpression;
    return [retval autorelease];
}

/**
 @Status Interoperable
*/
- (NSRange)rangeAtIndex:(NSUInteger)idx {
    return [[_rangesForResult objectAtIndex:idx] rangeValue];
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
    if (self = [super init]) {
        NSUInteger rangeLocation = [coder decodeInt64ForKey:@"rangeLocation"];
        NSUInteger rangeLength = [coder decodeInt64ForKey:@"rangeLength"];
        _range = { rangeLocation, rangeLength };

        _resultType = (NSTextCheckingType)[coder decodeInt64ForKey:@"resultType"];
        _numberOfRanges = [coder decodeInt64ForKey:@"numberOfRanges"];
        _duration = [coder decodeDoubleForKey:@"duration"];

        _replacementString = [[coder decodeObjectForKey:@"replacementString"] retain];
        _regularExpression = [[coder decodeObjectOfClass:[NSRegularExpression class] forKey:@"regularExpression"] retain];
        _components = [[coder decodeObjectOfClass:[NSDictionary class] forKey:@"components"] retain];
        _URL = [[coder decodeObjectOfClass:[NSURL class] forKey:@"URL"] retain];
        _addressComponents = [[coder decodeObjectOfClass:[NSDictionary class] forKey:@"addressComponents"] retain];
        _phoneNumber = [[coder decodeObjectForKey:@"phoneNumber"] retain];
        _date = [[coder decodeObjectOfClass:[NSDate class] forKey:@"date"] retain];
        _timeZone = [[coder decodeObjectOfClass:[NSTimeZone class] forKey:@"timeZone"] retain];
        // TODO: NSOrthography not implemented.
        // _orthography = [[coder decodeObjectOfClass:[NSOrthography class] forKey:@"orthography"] retain];
        _grammarDetails = [[coder decodeObjectOfClass:[NSArray class] forKey:@"grammarDetails"] retain];
        _rangesForResult = [[[coder decodeObjectOfClass:[NSArray class] forKey:@"rangesForResult"] mutableCopy] retain];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeInt64:_range.location forKey:@"rangeLocation"];
    [coder encodeInt64:_range.length forKey:@"rangeLength"];
    [coder encodeInt64:_resultType forKey:@"resultType"];
    [coder encodeInt64:_numberOfRanges forKey:@"numberOfRanges"];
    [coder encodeDouble:_duration forKey:@"duration"];

    [coder encodeObject:_replacementString forKey:@"replacementString"];
    [coder encodeObject:_regularExpression forKey:@"regularExpression"];
    [coder encodeObject:_components forKey:@"components"];
    [coder encodeObject:_URL forKey:@"URL"];
    [coder encodeObject:_addressComponents forKey:@"addressComponents"];
    [coder encodeObject:_phoneNumber forKey:@"phoneNumber"];
    [coder encodeObject:_date forKey:@"date"];
    [coder encodeObject:_timeZone forKey:@"timeZone"];
    [coder encodeObject:_orthography forKey:@"orthography"];
    [coder encodeObject:_grammarDetails forKey:@"grammarDetails"];
    [coder encodeObject:_rangesForResult forKey:@"rangesForResult"];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

- (NSTextCheckingResult*)_initWithTextCheckingResult:(NSTextCheckingResult*)copy offset:(NSInteger)offset {
    if (self = [super init]) {
        _replacementString = [copy.replacementString copy];
        _regularExpression = [copy.regularExpression copy];
        _components = [copy.components copy];
        _URL = [copy.URL copy];
        _addressComponents = [copy.addressComponents copy];
        _phoneNumber = [copy.phoneNumber copy];
        _date = [copy.date copy];
        _timeZone = [copy.timeZone copy];
        _orthography = [copy.orthography copy];
        _grammarDetails = [copy.grammarDetails copy];

        _resultType = copy.resultType;
        _numberOfRanges = copy->_rangesForResult.count;
        _duration = copy.duration;

        _rangesForResult = [[NSMutableArray alloc] initWithCapacity:_numberOfRanges];

        for (int i = 0; i < _numberOfRanges; i++) {
            NSRange tempRange = [[copy->_rangesForResult objectAtIndex:i] rangeValue];
            tempRange.location += offset;
            [_rangesForResult insertObject:[NSValue valueWithRange:tempRange] atIndex:i];
        }

        _range = copy.range;
        _range.location += offset;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (NSTextCheckingResult*)resultByAdjustingRangesWithOffset:(NSInteger)offset {
    NSTextCheckingResult* copy = [[NSTextCheckingResult alloc] _initWithTextCheckingResult:self offset:offset];

    return [copy autorelease];
}

@end