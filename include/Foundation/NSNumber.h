//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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

#import <Foundation/NSValue.h>
#import <Foundation/NSDecimal.h>

@class NSString;

FOUNDATION_EXPORT_CLASS
@interface NSNumber : NSValue <NSCopying, NSSecureCoding>

+ (NSNumber*)numberWithBool:(BOOL)value;
+ (NSNumber*)numberWithChar:(char)value;
+ (NSNumber*)numberWithDouble:(double)value;
+ (NSNumber*)numberWithFloat:(float)value;
+ (NSNumber*)numberWithInt:(int)value;
+ (NSNumber*)numberWithInteger:(NSInteger)value;
+ (NSNumber*)numberWithLong:(long)value;
+ (NSNumber*)numberWithLongLong:(long long)value;
+ (NSNumber*)numberWithShort:(short)value;
+ (NSNumber*)numberWithUnsignedChar:(unsigned char)value;
+ (NSNumber*)numberWithUnsignedInt:(unsigned int)value;
+ (NSNumber*)numberWithUnsignedInteger:(NSUInteger)value;
+ (NSNumber*)numberWithUnsignedLong:(unsigned long)value;
+ (NSNumber*)numberWithUnsignedLongLong:(unsigned long long)value;
+ (NSNumber*)numberWithUnsignedShort:(unsigned short)value;
- (NSNumber*)initWithBool:(BOOL)value;
- (NSNumber*)initWithChar:(char)value;
- (NSNumber*)initWithDouble:(double)value;
- (NSNumber*)initWithFloat:(float)value;
- (NSNumber*)initWithInt:(int)value;
- (NSNumber*)initWithInteger:(NSInteger)value;
- (NSNumber*)initWithLong:(long)value;
- (NSNumber*)initWithLongLong:(long long)value;
- (NSNumber*)initWithShort:(short)value;
- (NSNumber*)initWithUnsignedChar:(unsigned char)value;
- (NSNumber*)initWithUnsignedInt:(unsigned int)value;
- (NSNumber*)initWithUnsignedInteger:(NSUInteger)value;
- (NSNumber*)initWithUnsignedLong:(unsigned long)value;
- (NSNumber*)initWithUnsignedLongLong:(unsigned long long)value;
- (NSNumber*)initWithUnsignedShort:(unsigned short)value;
@property (readonly) BOOL boolValue;
@property (readonly) char charValue;
@property (readonly) NSDecimal decimalValue;
@property (readonly) double doubleValue;
@property (readonly) float floatValue;
@property (readonly) int intValue;
@property (readonly) NSInteger integerValue;
@property (readonly) long long longLongValue;
@property (readonly) long longValue;
@property (readonly) short shortValue;
@property (readonly) unsigned char unsignedCharValue;
@property (readonly) NSUInteger unsignedIntegerValue;
@property (readonly) unsigned int unsignedIntValue;
@property (readonly) unsigned long long unsignedLongLongValue;
@property (readonly) unsigned long unsignedLongValue;
@property (readonly) unsigned short unsignedShortValue;
- (NSString*)descriptionWithLocale:(id)aLocale;
@property (readonly, copy) NSString* stringValue;
- (NSComparisonResult)compare:(NSNumber*)aNumber;
- (BOOL)isEqualToNumber:(NSNumber*)aNumber;
- (const char*)objCType;
@end
