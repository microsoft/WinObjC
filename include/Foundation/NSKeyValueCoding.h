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
@class NSDictionary;
@class NSArray;
@class NSMutableArray;
@class NSMutableSet;
@class NSMutableOrderedSet;

#import <Foundation/NSError.h>
FOUNDATION_EXPORT NSString* const NSUndefinedKeyException;
FOUNDATION_EXPORT NSString* const NSTargetObjectUserInfoKey;
FOUNDATION_EXPORT NSString* const NSUnknownUserInfoKey;
FOUNDATION_EXPORT NSString* const NSAverageKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSCountKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSDistinctUnionOfArraysKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSDistinctUnionOfObjectsKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSDistinctUnionOfSetsKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSMaximumKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSMinimumKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSSumKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSUnionOfArraysKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSUnionOfObjectsKeyValueOperator;
FOUNDATION_EXPORT NSString* const NSUnionOfSetsKeyValueOperator;

@interface NSObject (NSKeyValueCoding)
- (id)valueForKey:(NSString*)key;
- (id)valueForKeyPath:(NSString*)keyPath;
- (NSDictionary*)dictionaryWithValuesForKeys:(NSArray*)keys;
- (id)valueForUndefinedKey:(NSString*)key;
- (NSMutableArray*)mutableArrayValueForKey:(NSString*)key;
- (NSMutableArray*)mutableArrayValueForKeyPath:(NSString*)keyPath;
- (NSMutableSet*)mutableSetValueForKey:(NSString*)key STUB_METHOD;
- (NSMutableSet*)mutableSetValueForKeyPath:(NSString*)keyPath STUB_METHOD;
- (NSMutableOrderedSet*)mutableOrderedSetValueForKey:(NSString*)key STUB_METHOD;
- (NSMutableOrderedSet*)mutableOrderedSetValueForKeyPath:(NSString*)keyPath STUB_METHOD;
- (void)setValue:(id)value forKeyPath:(NSString*)keyPath;
- (void)setValuesForKeysWithDictionary:(NSDictionary*)keyedValues;
- (void)setNilValueForKey:(NSString*)key STUB_METHOD;
- (void)setValue:(id)value forKey:(NSString*)key;
- (void)setValue:(id)value forUndefinedKey:(NSString*)key;
+ (BOOL)accessInstanceVariablesDirectly;
- (BOOL)validateValue:(inout id _Nullable*)ioValue forKey:(NSString*)key error:(out NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)validateValue:(inout id _Nullable*)ioValue forKeyPath:(NSString*)key error:(out NSError* _Nullable*)outError STUB_METHOD;
@end
