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
#import <Foundation/NSUndoManager.h>
#import "_NSUndoManagerInternal.h"

@implementation _NSUndoGroup {
    StrongId<_NSUndoManagerStack> _undoObjectsInGroup;
    BOOL _isClosed;
}

- (NSUInteger)count {
    return [_undoObjectsInGroup count];
}

- (BOOL)isClosed {
    return _isClosed;
}

- (id)init {
    if (self = [super init]) {
        _undoObjectsInGroup = [[_NSUndoManagerStack alloc] init];
        _isClosed = NO;
    }
    return self;
}
- (void)addUndoable:(id<_NSUndoable>)undoCall {
    _NSUndoBasicAction* topObjectInGroup = [_undoObjectsInGroup peek];
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        [topObjectInGroup addUndoable:undoCall];
    } else {
        [_undoObjectsInGroup push:undoCall];
    }
}

- (void)undo:(BOOL)undoAll {
    if (!_isClosed && undoAll) {
        [NSException raise:NSInternalInconsistencyException format:@"Undo group was not closed."];
    }
    do {
        id<_NSUndoable> object = [_undoObjectsInGroup peek];
        [object undo:YES];
        [_undoObjectsInGroup pop];
    } while (undoAll && [_undoObjectsInGroup count] > 0);
}

- (void)createUndoSubGroup {
    id<_NSUndoable> topObjectInGroup = [_undoObjectsInGroup peek];

    // If there is an open sub group to pass this call onto, do so.
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        [(_NSUndoGroup*)topObjectInGroup createUndoSubGroup];
    } else {
        _NSUndoGroup* newGroup = [[_NSUndoGroup alloc] init];
        [_undoObjectsInGroup push:newGroup];
        [newGroup release];
    }
}

- (void)closeUndoGroup {
    id<_NSUndoable> topObjectInGroup = [_undoObjectsInGroup peek];
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        [topObjectInGroup closeUndoGroup];
    } else {
        _isClosed = YES;
    }
}

- (BOOL)targets:(id)target {
    return NO;
}

- (void)removeAllWithTarget:(id)target {
    [_undoObjectsInGroup removeAllWithTarget:target];
}

- (NSUInteger)getNumberOfOpenGroups {
    if (!_isClosed) {
        return [[_undoObjectsInGroup peek] getNumberOfOpenGroups] + 1;
    }
    return 0;
}

- (BOOL)hasNestedGroup {
    if ([[_undoObjectsInGroup peek] isKindOfClass:[_NSUndoGroup class]]) {
        return YES;
    } else {
        return NO;
    }
}

@end