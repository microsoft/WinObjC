//******************************************************************************
//
// Original Author: Michael Ash on 11/9/08
// Copyright (c) 2008 Rogue Amoeba Software LLC
// Copyright (c) Microsoft. All rights reserved.
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

#import <dispatch/dispatch.h>
#import <Foundation/FoundationExport.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSOperation.h>

@class NSOperation;
@class NSString;

enum { NSOperationQueueDefaultMaxConcurrentOperationCount = -1 };

FOUNDATION_EXPORT_CLASS
@interface NSOperationQueue : NSObject
+ (NSOperationQueue*)currentQueue;
+ (NSOperationQueue*)mainQueue;
- (void)addOperation:(NSOperation*)operation;
- (void)addOperations:(NSArray<NSOperation*>*)ops waitUntilFinished:(BOOL)wait;
- (void)addOperationWithBlock:(void (^)(void))block;
@property (readonly, copy) NSArray<__kindof NSOperation*>* operations;
@property (readonly) NSUInteger operationCount;
- (void)cancelAllOperations;
- (void)waitUntilAllOperationsAreFinished;
@property NSQualityOfService qualityOfService;
@property NSInteger maxConcurrentOperationCount;
@property (getter=isSuspended) BOOL suspended;
@property (assign) dispatch_queue_t underlyingQueue;
@property (copy) NSString* name;
@end
