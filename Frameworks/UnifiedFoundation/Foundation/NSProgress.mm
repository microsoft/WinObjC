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

#include "Starboard.h"
#include "Foundation/NSProgress.h"

NSString* const NSProgressEstimatedTimeRemainingKey = @"NSProgressEstimatedTimeRemainingKey";
NSString* const NSProgressThroughputKey = @"NSProgressThroughputKey";
NSString* const NSProgressKindFile = @"NSProgressKindFile";
NSString* const NSProgressFileOperationKindKey = @"NSProgressFileOperationKindKey";
NSString* const NSProgressFileTotalCountKey = @"NSProgressFileTotalCountKey";
NSString* const NSProgressFileCompletedCountKey = @"NSProgressFileCompletedCountKey";
NSString* const NSProgressFileOperationKindDownloading = @"NSProgressFileOperationKindDownloading";
NSString* const NSProgressFileOperationKindDecompressingAfterDownloading = @"NSProgressFileOperationKindDecompressingAfterDownloading";
NSString* const NSProgressFileOperationKindReceiving = @"NSProgressFileOperationKindReceiving";
NSString* const NSProgressFileOperationKindCopying = @"NSProgressFileOperationKindCopying";

@implementation NSProgress

/**
 @Status Stub
*/
- (instancetype)initWithParent:(NSProgress*)parentProgressOrNil userInfo:(NSDictionary*)userInfoOrNil {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSProgress*)discreteProgressWithTotalUnitCount:(int64_t)unitCount {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSProgress*)progressWithTotalUnitCount:(int64_t)unitCount {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSProgress*)progressWithTotalUnitCount:(int64_t)unitCount
                                   parent:(NSProgress*)Parent
                         pendingUnitCount:(int64_t)portionOfParentTotalUnitCount {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSProgress*)currentProgress {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (void)becomeCurrentWithPendingUnitCount:(int64_t)unitCount {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)addChild:(NSProgress*)child withPendingUnitCount:(int64_t)inUnitCount {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)resignCurrent {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)cancel {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)pause {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)resume {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setUserInfoObject:(id)objectOrNil forKey:(NSString*)key {
    UNIMPLEMENTED();
}

@end