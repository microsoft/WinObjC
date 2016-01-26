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
#import <Foundation/NSCopying.h>
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSMutableCopying.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSecureCoding.h>

#import <Foundation/NSSet.h>

@class NSPredicate;
@class NSArray;

FOUNDATION_EXPORT_CLASS
@interface NSMutableSet : NSSet <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding>
+ (instancetype)setWithCapacity:(NSUInteger)numItems;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)addObject:(id)object;
- (void)filterUsingPredicate:(NSPredicate*)predicate STUB_METHOD;
- (void)removeObject:(id)object;
- (void)removeAllObjects;
- (void)addObjectsFromArray:(NSArray*)array;
- (void)unionSet:(NSSet*)otherSet;
- (void)minusSet:(NSSet*)otherSet;
- (void)intersectSet:(NSSet*)otherSet;
- (void)setSet:(NSSet*)otherSet;
@end
