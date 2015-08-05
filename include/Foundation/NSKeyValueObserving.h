/* Copyright (c) 2007 Johannes Fortmann

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSKEYVALUEOBSERVING_H_
#define _NSKEYVALUEOBSERVING_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSOrderedSet.h>
#import <StarboardExport.h>

@class NSDictionary, NSSet;

SB_EXPORT NSString * const NSKeyValueChangeKindKey;
SB_EXPORT NSString * const NSKeyValueChangeNewKey;
SB_EXPORT NSString * const NSKeyValueChangeOldKey;
SB_EXPORT NSString * const NSKeyValueChangeIndexesKey;
SB_EXPORT NSString * const NSKeyValueChangeNotificationIsPriorKey;


enum {
    NSKeyValueObservingOptionNew = 0x01,
    NSKeyValueObservingOptionOld = 0x02,
    NSKeyValueObservingOptionInitial = 0x04,
    NSKeyValueObservingOptionPrior = 0x08
};
typedef NSUInteger NSKeyValueObservingOptions;

enum {
    NSKeyValueChangeSetting=1,
    NSKeyValueChangeInsertion=2,
    NSKeyValueChangeRemoval=3,
    NSKeyValueChangeReplacement=4,
};
typedef NSUInteger NSKeyValueChange;

@interface NSObject (NSKeyValueObserving)
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString *)key;
+ (NSSet*)keyPathsForValuesAffectingValueForKey:(NSString*)key;
+ (void)setKeys:(NSArray *)keys triggerChangeNotificationsForDependentKey:(NSString *)dependentKey;

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)changeDict context:(void*)context;
- (void)addObserver:(id)observer forKeyPath:(NSString*)keyPath options:(NSKeyValueObservingOptions)options context:(void*)context;
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(void *)context;
- (void)removeObserver:(id)observer forKeyPath:(NSString*)keyPath;

- (void)willChangeValueForKey:(NSString*)key;
- (void)didChangeValueForKey:(NSString*)key;
- (void)willChange:(NSKeyValueChange)change valuesAtIndexes:(NSIndexSet *)indexes forKey:(NSString *)key;
- (void)didChange:(NSKeyValueChange)change valuesAtIndexes:(NSIndexSet *)indexes forKey:(NSString *)key;

- (void)setObservationInfo:(void*)newInfo;
- (void*)observationInfo;
@end

@interface NSArray (KeyValueObserving)
- (void)addObserver:(NSObject *)observer toObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context;
- (void)removeObserver:(NSObject *)observer fromObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath;
- (void)removeObserver:(NSObject *)observer fromObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath context:(void *)context;
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(void *)context;
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;
@end

@interface NSSet (KeyValueObserving)
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(void *)context;
@end

@interface NSOrderedSet (KeyValueObserving)
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(void *)context;
@end

@protocol NSKeyValueObserver
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context;
@end


enum {
    kNSKeyValueDebugLevel1 = 1, // public method calls
    kNSKeyValueDebugLevel2, // some clarifying logging
    kNSKeyValueDebugLevel3, // Most intimate function calls
};

SB_EXPORT void NSDetermineKeyValueDebugLoggingLevel();

SB_EXPORT int NSKeyValueDebugLogLevel;

#define NSKeyValueDebugLog(level, format, args...) NSDetermineKeyValueDebugLoggingLevel(); if (level <= NSKeyValueDebugLogLevel) NSLog(@"%d: %s line: %d | %@", level, __PRETTY_FUNCTION__, __LINE__, [NSString stringWithFormat: format, ## args])

#endif /* _NSKEYVALUEOBSERVING_H_ */
