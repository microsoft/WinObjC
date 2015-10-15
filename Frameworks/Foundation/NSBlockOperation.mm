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

#include "Foundation/NSError.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMethodSignature.h"
#include "Foundation/NSInvocation.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSOperation.h"

@implementation NSBlockOperation {
    idretaintype(NSMutableArray) _executionBlocks;
}

- (void)dealloc {
    _executionBlocks = nil;
    [super dealloc];
}

+ (instancetype)blockOperationWithBlock:(void (^)())block {
    id ret = [self new];
    [ret addExecutionBlock:block];

    return [ret autorelease];
}

- (instancetype)init {
    _executionBlocks.attach([NSMutableArray new]);
    return self;
}

- (void)addExecutionBlock:(id)block {
    [_executionBlocks addObject:[[block copy] autorelease]];
}

- (void)main {
    for (void (^curblock)() in (NSArray*)_executionBlocks) {
        curblock();
    }
    _executionBlocks = nil;
    _executionBlocks.attach([NSMutableArray new]);
}

@end
