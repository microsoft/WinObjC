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
    NSLengthFormatterUnitMillimeter = 8,
    NSLengthFormatterUnitCentimeter = 9,
    NSLengthFormatterUnitMeter = 11,
    NSLengthFormatterUnitKilometer = 14,
    NSLengthFormatterUnitInch = (5 << 8) + 1,
    NSLengthFormatterUnitFoot = (5 << 8) + 2,
    NSLengthFormatterUnitYard = (5 << 8) + 3,
    NSLengthFormatterUnitMile = (5 << 8) + 4,
} NSLengthFormatterUnit;

FOUNDATION_EXPORT_CLASS
@interface NSLengthFormatter : NSFormatter <NSCoding, NSCopying>
@property (getter=isForPersonHeightUse) BOOL forPersonHeightUse STUB_PROPERTY;
- (BOOL)getObjectValue:(id _Nullable*)obj forString:(NSString*)string errorDescription:(NSString* _Nullable*)error STUB_METHOD;
@property (copy) NSNumberFormatter* numberFormatter STUB_PROPERTY;
- (NSString*)stringFromMeters:(double)numberInMeters STUB_METHOD;
- (NSString*)stringFromValue:(double)value unit:(NSLengthFormatterUnit)unit STUB_METHOD;
- (NSString*)unitStringFromMeters:(double)numberInMeters usedUnit:(NSLengthFormatterUnit*)unitp STUB_METHOD;
- (NSString*)unitStringFromValue:(double)value unit:(NSLengthFormatterUnit)unit STUB_METHOD;
@property NSFormattingUnitStyle unitStyle STUB_PROPERTY;
@end
