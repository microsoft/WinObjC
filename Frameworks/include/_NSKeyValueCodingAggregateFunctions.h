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

#import <Foundation/NSArray.h>
#import <Foundation/NSNumber.h>
#import <Foundation/NSFastEnumeration.h>

@interface _NSKeyValueCodingAggregateFunctions : NSObject
+ (NSSet*)distinctUnionOfSets:(NSSet*)values;
+ (NSArray*)distinctUnionOfArrays:(NSArray*)values;
+ (NSArray*)distinctUnionOfObjects:(id<NSFastEnumeration>)values;
+ (NSNumber*)count:(id<NSFastEnumeration>)values;
+ (id)min:(id<NSFastEnumeration>)values;
+ (id)max:(id<NSFastEnumeration>)values;
+ (NSNumber*)avg:(id<NSFastEnumeration>)values;
+ (NSNumber*)sum:(id<NSFastEnumeration>)values;
+ (SEL)resolveFunction:(NSString*)fun;
@end