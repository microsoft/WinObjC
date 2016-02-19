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
    NSEnergyFormatterUnitJoule = 11,
    NSEnergyFormatterUnitKilojoule = 14,
    NSEnergyFormatterUnitCalorie = (7 << 8) + 1,
    NSEnergyFormatterUnitKilocalorie = (7 << 8) + 2,
} NSEnergyFormatterUnit;

FOUNDATION_EXPORT_CLASS
@interface NSEnergyFormatter : NSFormatter <NSCoding, NSCopying>
@property (getter=isForFoodEnergyUse) BOOL forFoodEnergyUse STUB_PROPERTY;
- (BOOL)getObjectValue:(id _Nullable*)obj forString:(NSString*)string errorDescription:(NSString* _Nullable*)error STUB_METHOD;
@property (copy) NSNumberFormatter* numberFormatter STUB_PROPERTY;
- (NSString*)stringFromJoules:(double)numberInJoules STUB_METHOD;
- (NSString*)stringFromValue:(double)value unit:(NSEnergyFormatterUnit)unit STUB_METHOD;
- (NSString*)unitStringFromJoules:(double)numberInJoules usedUnit:(NSEnergyFormatterUnit*)unitp STUB_METHOD;
- (NSString*)unitStringFromValue:(double)value unit:(NSEnergyFormatterUnit)unit STUB_METHOD;
@property NSFormattingUnitStyle unitStyle STUB_PROPERTY;
@end
