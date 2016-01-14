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
#pragma once

#import <Foundation/NSObject.h>

@class NSString;
@class NSDictionary;

FOUNDATION_EXPORT NSString* const NSProgressEstimatedTimeRemainingKey;
FOUNDATION_EXPORT NSString* const NSProgressThroughputKey;

FOUNDATION_EXPORT NSString* const NSProgressKindFile;

FOUNDATION_EXPORT NSString* const NSProgressFileOperationKindKey;
FOUNDATION_EXPORT NSString* const NSProgressFileTotalCountKey;
FOUNDATION_EXPORT NSString* const NSProgressFileCompletedCountKey;

FOUNDATION_EXPORT NSString* const NSProgressFileOperationKindDownloading;
FOUNDATION_EXPORT NSString* const NSProgressFileOperationKindDecompressingAfterDownloading;
FOUNDATION_EXPORT NSString* const NSProgressFileOperationKindReceiving;
FOUNDATION_EXPORT NSString* const NSProgressFileOperationKindCopying;

FOUNDATION_EXPORT_CLASS
@interface NSProgress : NSObject

- (instancetype)initWithParent:(NSProgress*)parentProgressOrNil userInfo:(NSDictionary*)userInfoOrNil;
+ (NSProgress*)discreteProgressWithTotalUnitCount:(int64_t)unitCount;
+ (NSProgress*)progressWithTotalUnitCount:(int64_t)unitCount;
+ (NSProgress*)progressWithTotalUnitCount:(int64_t)unitCount
                                   parent:(NSProgress*)Parent
                         pendingUnitCount:(int64_t)portionOfParentTotalUnitCount;

+ (NSProgress*)currentProgress;
- (void)becomeCurrentWithPendingUnitCount:(int64_t)unitCount;
- (void)addChild:(NSProgress*)child withPendingUnitCount:(int64_t)inUnitCount;
- (void)resignCurrent;

@property int64_t totalUnitCount;
@property int64_t completedUnitCount;
@property (copy) NSString* localizedDescription;
@property (copy) NSString* localizedAdditionalDescription;

@property (readonly) double fractionCompleted;

// Note that NSProgress does not do anything with these values besides report them
@property (getter=isCancellable) BOOL cancellable;
@property (getter=isPausable) BOOL pausable;

@property (readonly, getter=isCancelled) BOOL cancelled;
@property (copy) void (^cancellationHandler)(void);
@property (readonly, getter=isPaused) BOOL paused;
@property (copy) void (^pausingHandler)(void);
@property (copy) void (^resumingHandler)(void);

- (void)cancel;
- (void)pause;
- (void)resume;

@property (readonly, getter=isIndeterminate) BOOL indeterminate;
@property (copy) NSString* kind;
@property (readonly, copy) NSDictionary* userInfo;

- (void)setUserInfoObject:(id)objectOrNil forKey:(NSString*)key;

@end