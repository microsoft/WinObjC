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
@property (getter=isCancellable) BOOL cancellable;
@property (readonly, getter=isCancelled) BOOL cancelled;
- (void)cancel;
@property (copy) void (^cancellationHandler)(void);
@property (getter=isPausable) BOOL pausable;
@property (readonly, getter=isPaused) BOOL paused;
- (void)pause;
@property (copy) void (^pausingHandler)(void);
- (void)resume;
@property (copy) void (^resumingHandler)(void);
@property (readonly, getter=isIndeterminate) BOOL indeterminate;
@property (copy) NSString* kind;
- (void)setUserInfoObject:(id)objectOrNil forKey:(NSString*)key;
@property (readonly, copy) NSDictionary* userInfo;
@end
