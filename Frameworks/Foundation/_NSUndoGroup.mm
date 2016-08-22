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
    StrongId<NSUndoManager*> _owningManager;
    NSUInteger _undoLevel;
    BOOL _isClosed;
}

- (id)initWithLevel:(NSUInteger)level {
    if (self = [super init]) {
        _undoGrouping = [NSMutableArray array];
        _undoLevel = level;
        _isClosed = NO;
    }
    return self;
}

- (id)initWithOwner:(NSUndoManager*)manager {
    if (self = [self initWithLevel:1]) {
        _owningManager = manager;
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
        _NSUndoBasicAction* object = [_undoGrouping firstObject];
        [object undo];
        [_undoGrouping removeObjectAtIndex:0];
    }
}

- (NSUInteger)createUndoGroup {
    id topObjectInGroup = [_undoGrouping firstObject];
    if ([topObjectInGroup isKindOfClass:[_NSUndoGroup class]] && [topObjectInGroup isClosed]) {
        return [(topObjectInGroup)createUndoGroup];
    }

    _NSUndoGroup* newGroup = [[[_NSUndoGroup alloc] initWithLevel:(_undoLevel + 1)] autorelease];
    [_undoGrouping insertObject:newGroup atIndex:0];
    return _undoLevel + 1;
}

- (BOOL)closeUndoGroup {
    id topObjectInGroup = [_undoGrouping firstObject];
    if (![topObjectInGroup isClosed]) {
        return [topObjectInGroup closeUndoGroup];
    }
    _isClosed = YES;
    return YES;
}

- (BOOL)canUndo {
    // Top level undo group does not need to be closed.
    _NSUndoBasicAction* topObjectInGroup = [_undoGrouping firstObject];

    if ([topObjectInGroup canUndo] && (_isClosed || _undoLevel == 1)) {
        return YES;
    }

    return NO;
}

@end