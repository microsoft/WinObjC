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

@class NSString;

FOUNDATION_EXPORT_CLASS
@interface NSSortDescriptor : NSObject <NSCopying, NSSecureCoding>
+ (instancetype)sortDescriptorWithKey:(NSString*)key ascending:(BOOL)ascending;
- (instancetype)initWithKey:(NSString*)keyPath ascending:(BOOL)ascending;
+ (instancetype)sortDescriptorWithKey:(NSString*)key ascending:(BOOL)ascending selector:(SEL)selector;
- (instancetype)initWithKey:(NSString*)keyPath ascending:(BOOL)ascending selector:(SEL)selector;
+ (instancetype)sortDescriptorWithKey:(NSString*)key ascending:(BOOL)ascending comparator:(NSComparator)cmptr;
- (instancetype)initWithKey:(NSString*)key ascending:(BOOL)ascending comparator:(NSComparator)cmptr;
@property (readonly) BOOL ascending;
@property (readonly, copy) NSString* key;
@property (readonly) SEL selector;
- (NSComparisonResult)compareObject:(id)object1 toObject:(id)object2;
@property (readonly, retain) id reversedSortDescriptor;
- (void)allowEvaluation STUB_METHOD;
@property (readonly) NSComparator comparator;
@end
