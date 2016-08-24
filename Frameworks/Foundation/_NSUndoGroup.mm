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
    StrongId<_NSUndoManagerStack*> _undoGrouping;
    NSInteger _undoLevel;
    BOOL _isClosed;
}

- (BOOL)isClosed {
    return _isClosed;
}

- (id)initWithLevel:(NSInteger)level {
    if (self = [super init]) {
        _undoGrouping = [[_NSUndoManagerStack alloc] init];
        _undoLevel = level;
        _isClosed = NO;
    }
    return self;
}

- (void)addUndoCallToUndoGroup:(_NSUndoBasicAction*)undoCall {
    _NSUndoBasicAction* topObjectInGroup = [_undoGrouping peek];
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        [topObjectInGroup addUndoCallToUndoGroup:undoCall];
    } else {
        [_undoGrouping push:undoCall];
    }
}

- (void)undo {
    if ([_undoGrouping count] == 0) {
        [NSException raise:NSInternalInconsistencyException format:@"No undo operations in undo group."];
    }
    if (!_isClosed) {
        [NSException raise:NSInternalInconsistencyException format:@"Undo group was not closed."];
    }
    while ([_undoGrouping count] > 0) {
        id<_NSUndoable> object = [_undoGrouping peek];
        [object undo];
        [_undoGrouping pop];
    }
}

- (void)createUndoGroupWithLevel:(NSInteger)level {
    id<_NSUndoable> topObjectInGroup = [_undoGrouping peek];
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        // Object must be a group in order to be an open object. Cast to ensure proper return type, otherwise return type is default id.
        [(_NSUndoGroup*)topObjectInGroup createUndoGroupWithLevel:level + 1];
    }

    _NSUndoGroup* newGroup = [[_NSUndoGroup alloc] initWithLevel:level];
    [_undoGrouping push:newGroup];
}

- (void)closeUndoGroup {
    id<_NSUndoable> topObjectInGroup = [_undoGrouping peek];
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        [topObjectInGroup closeUndoGroup];
    } else {
        _isClosed = YES;
    }
}

@end