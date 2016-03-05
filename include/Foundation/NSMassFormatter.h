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

#import <Foundation/NSFormatter.h>

@class NSString;
@class NSNumberFormatter;

typedef enum : NSInteger {
    NSMassFormatterUnitGram = 11,
    NSMassFormatterUnitKilogram = 14,
    NSMassFormatterUnitOunce = (6 << 8) + 1,
    NSMassFormatterUnitPound = (6 << 8) + 2,
    NSMassFormatterUnitStone = (6 << 8) + 3,
} NSMassFormatterUnit;

FOUNDATION_EXPORT_CLASS
@interface NSMassFormatter : NSFormatter <NSCoding, NSCopying>
@property (getter=isForPersonMassUse) BOOL forPersonMassUse STUB_PROPERTY;
- (BOOL)getObjectValue:(id _Nullable*)obj forString:(NSString*)string errorDescription:(NSString* _Nullable*)error STUB_METHOD;
@property (copy) NSNumberFormatter* numberFormatter STUB_PROPERTY;
- (NSString*)stringFromKilograms:(double)numberInKilograms STUB_METHOD;
- (NSString*)stringFromValue:(double)value unit:(NSMassFormatterUnit)unit STUB_METHOD;
- (NSString*)unitStringFromKilograms:(double)numberInKilograms usedUnit:(NSMassFormatterUnit*)unitp STUB_METHOD;
- (NSString*)unitStringFromValue:(double)value unit:(NSMassFormatterUnit)unit STUB_METHOD;
@property NSFormattingUnitStyle unitStyle STUB_PROPERTY;
@end
