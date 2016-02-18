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
@class NSArray;
@class NSData;
@class NSDictionary;

FOUNDATION_EXPORT NSString* const NSUbiquitousKeyValueStoreChangeReasonKey;
FOUNDATION_EXPORT NSString* const NSUbiquitousKeyValueStoreChangedKeysKey;
FOUNDATION_EXPORT NSString* const NSUbiquitousKeyValueStoreDidChangeExternallyNotification;

enum {
    NSUbiquitousKeyValueStoreServerChange,
    NSUbiquitousKeyValueStoreInitialSyncChange,
    NSUbiquitousKeyValueStoreQuotaViolationChange,
    NSUbiquitousKeyValueStoreAccountChange
};

FOUNDATION_EXPORT_CLASS
@interface NSUbiquitousKeyValueStore : NSObject
+ (NSUbiquitousKeyValueStore*)defaultStore;
- (NSArray*)arrayForKey:(NSString*)aKey;
- (BOOL)boolForKey:(NSString*)aKey;
- (NSData*)dataForKey:(NSString*)aKey;
- (NSDictionary*)dictionaryForKey:(NSString*)aKey;
- (double)doubleForKey:(NSString*)aKey;
- (long long)longLongForKey:(NSString*)aKey;
- (id)objectForKey:(NSString*)aKey;
- (NSString*)stringForKey:(NSString*)aKey;
- (void)setArray:(NSArray*)anArray forKey:(NSString*)aKey;
- (void)setBool:(BOOL)value forKey:(NSString*)aKey;
- (void)setData:(NSData*)aData forKey:(NSString*)aKey;
- (void)setDictionary:(NSDictionary*)aDictionary forKey:(NSString*)aKey;
- (void)setDouble:(double)value forKey:(NSString*)aKey;
- (void)setLongLong:(long long)value forKey:(NSString*)aKey;
- (void)setObject:(id)anObject forKey:(NSString*)aKey;
- (void)setString:(NSString*)aString forKey:(NSString*)aKey;
- (BOOL)synchronize;
- (void)removeObjectForKey:(NSString*)aKey;
@property (readonly, copy) NSDictionary* dictionaryRepresentation;
@end
