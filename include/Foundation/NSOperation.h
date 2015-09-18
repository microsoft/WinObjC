/*
Original Author: Michael Ash on 11/9/08.
Copyright (c) 2008 Rogue Amoeba Software LLC

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef _NSOPERATION_H_
#define _NSOPERATION_H_

#import <Foundation/NSObject.h>

@class NSArray;
@class NSMutableArray;

enum {
    NSOperationQueuePriorityVeryLow = -8,
    NSOperationQueuePriorityLow = -4,
    NSOperationQueuePriorityNormal = 0,
    NSOperationQueuePriorityHigh = 4,
    NSOperationQueuePriorityVeryHigh = 8
};
typedef NSInteger NSOperationQueuePriority;

#if __cplusplus
#include <pthread.h>
struct NSOperationPriv
{
    NSOperationQueuePriority priority;
    id dependencies;
    id completionBlock;

    pthread_cond_t finishCondition;
    pthread_mutex_t finishLock;

    int executing : 1;
    int cancelled : 1;
    int finished : 1;

    NSOperationPriv()
    {
        memset(this, 0, sizeof(NSOperationPriv));
        pthread_cond_init(&finishCondition, 0);

        pthread_mutexattr_t attr;

        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&finishLock, &attr);
        pthread_mutexattr_destroy(&attr);
    }

    ~NSOperationPriv()
    {
        pthread_cond_destroy(&finishCondition);
        pthread_mutex_destroy(&finishLock);
    }
};
#else
struct NSOperationPriv;
#endif

FOUNDATION_EXPORT_CLASS
@interface NSOperation : NSObject {
    struct NSOperationPriv *priv;
}

- (void)start;

// abstract, override this to create a concrete subclass, don't call super
- (void)main;

- (NSArray *)dependencies;
- (void)addDependency:(NSOperation *)operation;
- (void)removeDependency:(NSOperation *)operation;

- (NSOperationQueuePriority)queuePriority;
- (void)setQueuePriority:(NSOperationQueuePriority)priority;

- (BOOL)isCancelled;
- (void)cancel;

- (BOOL)isConcurrent;
- (BOOL)isExecuting;
- (BOOL)isFinished;
- (BOOL)isReady;

- (void (^)(void))completionBlock;
- (void)setCompletionBlock:(void (^)(void))block;
- (void)waitUntilFinished;

@end

SB_EXPORT NSString * const NSInvocationOperationVoidResultException;
SB_EXPORT NSString * const NSInvocationOperationCancelledException;

FOUNDATION_EXPORT_CLASS
@interface NSInvocationOperation : NSOperation

-initWithInvocation:(NSInvocation *)invocation;
-initWithTarget:target selector:(SEL)selector object:argument;

- (NSInvocation *)invocation;

-result;

@end

FOUNDATION_EXPORT_CLASS
@interface NSBlockOperation : NSOperation

+ (id)blockOperationWithBlock:(void (^)(void))block;

@end

#endif /* _NSOPERATION_H_ */