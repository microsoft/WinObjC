//******************************************************************************
//
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

#import <Starboard.h>
#import <Foundation/NSUndoManager.h>
#import "_NSUndoManagerInternal.h"

@implementation _NSUndoGroup {
    StrongId<NSMutableArray*> _undoGrouping;
    NSInteger _undoLevel;
    NSInteger _depth;
}

- (BOOL)isClosed {
    return _depth == 0;
}

- (id)initWithLevel:(NSInteger)level {
    if (self = [super init]) {
        _undoGrouping = [NSMutableArray array];
        _undoLevel = level;
        _depth = 1;
    }
    return self;
}

- (void)addUndoCallToUndoGroup:(_NSUndoBasicAction*)undoCall {
    _NSUndoBasicAction* topObjectInGroup = [_undoGrouping firstObject];
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        [topObjectInGroup addUndoCallToUndoGroup:undoCall];
    } else {
        [_undoGrouping insertObject:undoCall atIndex:0];
    }
}

- (void)undo {
    while ([_undoGrouping count] > 0) {
        id<_NSUndoable> object = [_undoGrouping firstObject];
        [object undo];
        [_undoGrouping removeObjectAtIndex:0];
    }
}

- (NSInteger)createUndoGroupWithLevel:(NSInteger)level {
    id<_NSUndoable> topObjectInGroup = [_undoGrouping firstObject];
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        _depth++;
        // Object must be a group in order to be an open object. Cast to ensure proper return type, otherwise return type is default id.
        return [(_NSUndoGroup*)topObjectInGroup createUndoGroupWithLevel:level + 1];
    }

    _NSUndoGroup* newGroup = [[[_NSUndoGroup alloc] initWithLevel:level] autorelease];
    [_undoGrouping insertObject:newGroup atIndex:0];
    return level;
}

- (void)closeUndoGroup {
    id<_NSUndoable> topObjectInGroup = [_undoGrouping firstObject];
    if (topObjectInGroup != nil && ![topObjectInGroup isClosed]) {
        [topObjectInGroup closeUndoGroup];
    }
    _depth--;
}

- (BOOL)canUndo {
    // Top level undo group does not need to be closed.
    _NSUndoBasicAction* topObjectInGroup = [_undoGrouping firstObject];

    if ([topObjectInGroup canUndo] && ([self isClosed] || _undoLevel == 1)) {
        return YES;
    }

    return NO;
}

- (NSInteger)_getDepth {
    return _depth;
}

@end