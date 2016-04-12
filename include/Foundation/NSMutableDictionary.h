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
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSDictionary.h>

@class NSString;
@class NSArray;

FOUNDATION_EXPORT_CLASS
@interface NSMutableDictionary : NSDictionary <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding>
+ (instancetype)dictionaryWithCapacity:(NSUInteger)numItems;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
+ (NSMutableDictionary*)dictionaryWithSharedKeySet:(id)keyset STUB_METHOD;
- (void)setObject:(id)anObject forKey:(id<NSCopying>)aKey;
- (void)setObject:(id)object forKeyedSubscript:(id<NSCopying>)aKey;
- (void)setValue:(id)value forKey:(NSString*)key;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDictionary;
- (void)setDictionary:(NSDictionary*)otherDictionary;
- (void)removeObjectForKey:(id)aKey;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keyArray;
@end
