//******************************************************************************
//
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

#import <Starboard.h>
#import "_NSUndoManagerInternal.h"
#include <list>

@implementation _NSUndoManagerStack {
    std::list<StrongId<id<_NSUndoable>>> _stack;
}

- (void)pop {
    if ([self count] > 0) {
        _stack.pop_front();
    }
}

- (void)popBack {
    if ([self count] > 0) {
        _stack.pop_back();
    }
}

- (id<_NSUndoable>)peek {
    if ([self count] > 0) {
        return _stack.front();
    }
    return nil;
}

- (void)push:(id<_NSUndoable>)undoObject {
    _stack.push_front(undoObject);
}

- (NSUInteger)count {
    return _stack.size();
}

- (void)removeAllWithTarget:(id)target {
    std::list<StrongId<id<_NSUndoable>>>::const_iterator iterator = _stack.begin();

    while (iterator != _stack.end()) {
        if ([*iterator targets:target]) {
            std::list<StrongId<id<_NSUndoable>>>::const_iterator toRemove = iterator;
            ++iterator;
            _stack.erase(toRemove);
        } else {
            [*iterator removeAllWithTarget:target];
            ++iterator;
        }
    }
}

@end
