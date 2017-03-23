//******************************************************************************
//
// Original Author: Michael Ash on 11/9/08.
// Copyright (c) 2008 Rogue Amoeba Software LLC
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

typedef NS_ENUM(NSInteger, NSOperationQueuePriority) {
    NSOperationQueuePriorityVeryLow = -8,
    NSOperationQueuePriorityLow = -4,
    NSOperationQueuePriorityNormal = 0,
    NSOperationQueuePriorityHigh = 4,
    NSOperationQueuePriorityVeryHigh = 8
};

typedef NS_ENUM(NSInteger, NSQualityOfService) {
    NSQualityOfServiceDefault,
    NSQualityOfServiceUserInteractive,
    NSQualityOfServiceUserInitiated,
    NSQualityOfServiceUtility,
    NSQualityOfServiceBackground
};

FOUNDATION_EXPORT_CLASS
@interface NSOperation : NSObject
- (void)start;
- (void)main;
@property (copy) void (^completionBlock)(void);
- (void)cancel;
@property (readonly, getter=isCancelled) BOOL cancelled;
@property (readonly, getter=isExecuting) BOOL executing;
@property (readonly, getter=isFinished) BOOL finished;
@property (readonly, getter=isConcurrent) BOOL concurrent;
@property (readonly, getter=isAsynchronous) BOOL asynchronous;
@property (readonly, getter=isReady) BOOL ready;
@property (copy) NSString* name;
- (void)addDependency:(NSOperation*)operation;
- (void)removeDependency:(NSOperation*)operation;
@property (readonly, copy) NSArray* dependencies;
@property NSQualityOfService qualityOfService;
@property double threadPriority STUB_PROPERTY;
@property NSOperationQueuePriority queuePriority;
- (void)waitUntilFinished;
@end

FOUNDATION_EXPORT NSString* const NSInvocationOperationVoidResultException;
FOUNDATION_EXPORT NSString* const NSInvocationOperationCancelledException;
