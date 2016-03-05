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
@class NSIndexSet;
@class NSSet;

typedef NSUInteger NSKeyValueChange;
typedef NSUInteger NSKeyValueObservingOptions;
typedef NSUInteger NSKeyValueSetMutationKind;

enum { NSKeyValueChangeSetting = 1, NSKeyValueChangeInsertion = 2, NSKeyValueChangeRemoval = 3, NSKeyValueChangeReplacement = 4 };

enum {
    NSKeyValueObservingOptionNew = 0x01,
    NSKeyValueObservingOptionOld = 0x02,
    NSKeyValueObservingOptionInitial = 0x04,
    NSKeyValueObservingOptionPrior = 0x08
};

enum { NSKeyValueUnionSetMutation = 1, NSKeyValueMinusSetMutation = 2, NSKeyValueIntersectSetMutation = 3, NSKeyValueSetSetMutation = 4 };

FOUNDATION_EXPORT NSString* const NSKeyValueChangeKindKey;
FOUNDATION_EXPORT NSString* const NSKeyValueChangeNewKey;
FOUNDATION_EXPORT NSString* const NSKeyValueChangeOldKey;
FOUNDATION_EXPORT NSString* const NSKeyValueChangeIndexesKey;
FOUNDATION_EXPORT NSString* const NSKeyValueChangeNotificationIsPriorKey;

@interface NSObject (NSKeyValueObserving)
- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context;
- (void)addObserver:(NSObject*)anObserver forKeyPath:(NSString*)keyPath options:(NSKeyValueObservingOptions)options context:(void*)context;
- (void)removeObserver:(NSObject*)anObserver forKeyPath:(NSString*)keyPath;
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath context:(void*)context;
- (void)willChangeValueForKey:(NSString*)key;
- (void)didChangeValueForKey:(NSString*)key;
- (void)willChange:(NSKeyValueChange)change valuesAtIndexes:(NSIndexSet*)indexes forKey:(NSString*)key;
- (void)didChange:(NSKeyValueChange)change valuesAtIndexes:(NSIndexSet*)indexes forKey:(NSString*)key;
- (void)willChangeValueForKey:(NSString*)key withSetMutation:(NSKeyValueSetMutationKind)mutationKind usingObjects:(NSSet*)objects;
- (void)didChangeValueForKey:(NSString*)key withSetMutation:(NSKeyValueSetMutationKind)mutationKind usingObjects:(NSSet*)objects;
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key;
+ (NSSet*)keyPathsForValuesAffectingValueForKey:(NSString*)key;
@property void* observationInfo;
@end
