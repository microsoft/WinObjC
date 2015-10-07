//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _NSUBIQUITOUSKEYVALUESTORE_H_
#define _NSUBIQUITOUSKEYVALUESTORE_H_

#import <StarboardExport.h>
#import <Foundation/NSObject.h>

enum {
    NSUbiquitousKeyValueStoreServerChange,
    NSUbiquitousKeyValueStoreInitialSyncChange,
    NSUbiquitousKeyValueStoreQuotaViolationChange,
    NSUbiquitousKeyValueStoreAccountChange
};

@class NSDictionary;

@interface NSUbiquitousKeyValueStore : NSObject

- (long long)longLongForKey:(NSString *)key;
- (id)objectForKey:(NSString *)aKey;
- (void)setObject:(id)anObject forKey:(NSString *)aKey;
- (void)removeObjectForKey:(NSString *)aKey;
- (BOOL)synchronize;
- (NSDictionary *)dictionaryRepresentation;
- (void)setLongLong:(long long)value forKey:(NSString *)aKey;
- (NSString *)stringForKey:(NSString *)aKey;
- (void)setString:(NSString *)aString forKey:(NSString *)aKey;
- (BOOL)boolForKey:(NSString *)aKey;
- (void)setBool:(BOOL)value forKey:(NSString *)aKey;

+ (NSUbiquitousKeyValueStore *)defaultStore;

@end

SB_EXPORT NSString *const NSUbiquitousKeyValueStoreChangedKeysKey;
SB_EXPORT NSString *const NSUbiquitousKeyValueStoreDidChangeExternallyNotification;
SB_EXPORT NSString *const NSUbiquitousKeyValueStoreChangeReasonKey;

#endif /* _NSUBIQUITOUSKEYVALUESTORE_H_ */