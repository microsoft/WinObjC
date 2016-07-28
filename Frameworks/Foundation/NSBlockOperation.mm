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

#import "Foundation/NSError.h"
#import "Foundation/NSString.h"
#import "Foundation/NSMethodSignature.h"
#import "Foundation/NSInvocation.h"
#import "Foundation/NSMutableArray.h"
#import "Foundation/NSOperation.h"

@implementation NSBlockOperation {
    idretaintype(NSMutableArray) _executionBlocks;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _executionBlocks = nil;
    [super dealloc];
}

/**
 @Status Interoperable
*/
+ (instancetype)blockOperationWithBlock:(void (^)())block {
    id ret = [self new];
    [ret addExecutionBlock:block];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _executionBlocks.attach([NSMutableArray new]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)addExecutionBlock:(void (^)(void))block {
    [_executionBlocks addObject:[[block copy] autorelease]];
}

/**
 @Status Interoperable
*/
- (void)main {
    for (void (^curblock)() in(NSArray*)_executionBlocks) {
        curblock();
    }
    _executionBlocks = nil;
    _executionBlocks.attach([NSMutableArray new]);
}

/**
@Status Interoperable
*/
- (NSArray*)executionBlocks {
    return [[_executionBlocks retain] autorelease];
}

@end
