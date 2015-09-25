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
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSEnumerator.h"

@implementation NSEnumerator : NSObject
+ (NSEnumerator*)enumeratorWithArray:(NSArray*)array {
    NSEnumerator* ret = [self alloc];

    ret->objArray = array;
    ret->curIndex = 0;
    ret->dir = 1;

    return [ret autorelease];
}

+ (NSEnumerator*)enumeratorWithArrayReverse:(NSArray*)array {
    NSEnumerator* ret = [self alloc];

    ret->objArray = array;
    ret->curIndex = [array count] - 1;
    ret->dir = -1;

    return [ret autorelease];
}

+ (NSEnumerator*)enumeratorWithIterator:(initIteratorFunc)initIterator
                              forObject:(id)obj
                           nextFunction:(nextValueFunc)nextValueFunction {
    NSEnumerator* ret = [self alloc];

    ret->getNextValueFunction = nextValueFunction;
    ret->iteratorObj = obj;
    initIterator(obj, ret->iteratorState);

    return [ret autorelease];
}

- (NSArray*)allObjects {
    NSArray* ret = [NSMutableArray new];

    id cur = [self nextObject];
    while (cur != nil) {
        [ret addObject:cur];
        cur = [self nextObject];
    }

    return [ret autorelease];
}

- (NSObject*)nextObject {
    if (iteratorObj != nil) {
        id ret;
        int count = getNextValueFunction(iteratorObj, iteratorState, &ret, 1);
        if (count == 1)
            return ret;
        return nil;
    }

    if (dir == 1) {
        int count = [objArray count];

        if (curIndex >= count)
            return nil;

        NSObject* ret = [objArray objectAtIndex:curIndex];
        curIndex++;

        return ret;
    } else {
        if (curIndex < 0)
            return nil;

        NSObject* ret = [objArray objectAtIndex:curIndex];
        curIndex--;

        return ret;
    }
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state
                                  objects:(id*)stackBuf
                                    count:(NSUInteger)maxCount {
    if (iteratorObj != nil) {
        if (state->state == 0) {
            state->state = 1;
            state->mutationsPtr = (unsigned long*)&state->state;
        }
        assert(maxCount > 0);

        state->itemsPtr = (id*)stackBuf;
        int ret = getNextValueFunction(iteratorObj, iteratorState, stackBuf, maxCount);

        return ret;
    }

    if (state->state == 0) {
        state->mutationsPtr = (unsigned long*)&state->extra[1];
        state->extra[0] = (unsigned long)self;
        state->state = 1;
    }
    assert(maxCount > 0);

    NSUInteger numRet = 0;
    state->itemsPtr = (id*)stackBuf;

    while (maxCount > 0) {
        id next = [state->extra[0] nextObject];
        if (next == nil)
            break;

        *stackBuf = next;
        stackBuf++;
        numRet++;
        maxCount--;
    }

    return numRet;
}

@end
