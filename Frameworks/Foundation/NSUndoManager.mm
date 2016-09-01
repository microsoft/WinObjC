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
#import <StubReturn.h>
#import <Foundation/NSUndoManager.h>
#import "_NSUndoManagerInternal.h"

NSString* const NSUndoManagerGroupIsDiscardableKey = @"NSUndoManagerGroupIsDiscardable";

@implementation NSUndoManager {
    StrongId<_NSUndoManagerStack> _undoStack;
    StrongId<_NSUndoManagerStack> _redoStack;
    NSUInteger _undoGroupingLevel;
    NSUInteger _redoGroupingLevel;
    NSUInteger _disableCount;
    BOOL _isAutomaticGroupOpen;
    BOOL _hasNestedGroup;
}

/**
 @Status Interoperable
*/
- (id)init {
    if (self = [super init]) {
        _runLoopModes = [@[ NSDefaultRunLoopMode ] retain];
        _groupsByEvent = YES;

        _disableCount = 0;
        _undoGroupingLevel = 0;
        _redoGroupingLevel = 0;

        _undoStack.attach([[_NSUndoManagerStack alloc] init]);
        _redoStack.attach([[_NSUndoManagerStack alloc] init]);
    }
    return self;
}

- (void)_createAutomaticUndoGroup {
    if (!_isAutomaticGroupOpen && _undoGroupingLevel == 0 && _groupsByEvent) {
        _isAutomaticGroupOpen = YES;
        [self beginUndoGrouping];
    }
}

// Internal function for proper registration of the deferred call.
- (void)_registerUndoAction:(_NSUndoBasicAction*)undoCall {
    if (_undoing) {
        if ([_redoStack count] == 0) {
            _NSUndoGroup* startingRedoGroup = [[_NSUndoGroup alloc] init];
            [_redoStack push:startingRedoGroup];
            [startingRedoGroup release];
        }
        _NSUndoGroup* redoGroup = [_redoStack peek];
        if (redoGroup == nil) {
            [NSException raise:NSInternalInconsistencyException format:@"Registered action with no undo group open."];
        }
        [redoGroup addUndoable:undoCall];
    } else {
        // Any new actions invalidate any redo actions
        if (!_redoing) {
            _redoStack.attach([[_NSUndoManagerStack alloc] init]);
            _redoGroupingLevel = 0;
        }
        [self _createAutomaticUndoGroup];
        _NSUndoGroup* undoGroup = [_undoStack peek];
        if (undoGroup == nil) {
            [NSException raise:NSInternalInconsistencyException format:@"Registered action with no undo group open."];
        }
        [undoGroup addUndoable:undoCall];
    }
}

/**
 @Status Interoperable
*/
- (void)registerUndoWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject {
    if (_disableCount == 0) {
        _NSUndoBasicAction* undoCall =
            [[_NSUndoBasicAction alloc] _initWithTarget:target selector:aSelector object:anObject modes:self.runLoopModes];
        [self _registerUndoAction:undoCall];
    }
}

/**
 @Status Stub
 @Notes
*/
- (id)prepareWithInvocationTarget:(id)target {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)undo {
    if (_undoGroupingLevel == 1 && _groupsByEvent) {
        [self endUndoGrouping];
    }

    if (![self canUndo]) {
        return;
    }

    _NSUndoGroup* topLevelGroup = [_undoStack peek];
    NSUInteger undoSize = [_undoStack count];

    [self _beginRedoGrouping];
    // Continue calling undoNestedGroup until top level undo group is empty.
    while (undoSize == [_undoStack count]) {
        [self undoNestedGroup];
        _NSUndoGroup* topLevelGroup = [_undoStack peek];
    }
    [self _endRedoGrouping];
    _isAutomaticGroupOpen = NO;
}

/**
 @Status Interoperable
*/
- (void)undoNestedGroup {
    if (![self canUndo]) {
        return;
    }

    _undoing = YES;
    _groupingLevel = _undoGroupingLevel;

    if ((_groupingLevel == 1 && !_hasNestedGroup) || (_groupingLevel != 0 && !(_groupingLevel == 1 && _hasNestedGroup))) {
        [NSException raise:NSInternalInconsistencyException format:@"undoNestedGroup called with open undo group."];
    }

    _NSUndoGroup* undoGroup = [_undoStack peek];

    // Record redo operation as a single redo group
    [self _beginRedoGrouping];
    [undoGroup undo:!(_hasNestedGroup)];
    [self _endRedoGrouping];
    if ([undoGroup count] == 0) {
        [_undoStack pop];
    }

    _undoing = NO;
}

/**
 @Status Interoperable
*/
- (void)redo {
    if (![self canRedo]) {
        return;
    }

    if (_undoing) {
        [NSException raise:NSInternalInconsistencyException format:@"Redo called while undo is active."];
    }

    _redoing = YES;
    _groupingLevel = _redoGroupingLevel;

    _NSUndoGroup* redoGroup = [_redoStack peek];

    // Record undo operation as a single group
    [self beginUndoGrouping];
    [redoGroup undo:YES];
    [self endUndoGrouping];
    [_redoStack pop];

    _redoing = NO;
}

/**
 @Status Interoperable
*/
- (void)beginUndoGrouping {
    if (_undoing) {
        return;
    }
    // Over the limit on undo operations
    if (self.levelsOfUndo != 0 && _undoGroupingLevel == 0 && [_undoStack count] >= self.levelsOfUndo) {
        [_undoStack popBack];
    }
    if (_groupsByEvent && !_isAutomaticGroupOpen) {
        [self _createAutomaticUndoGroup];
    }
    _NSUndoGroup* undoGroup = [_undoStack peek];

    if (undoGroup == nil || [undoGroup isClosed]) {
        _NSUndoGroup* newGroup = [[_NSUndoGroup alloc] init];
        [_undoStack push:newGroup];
        [newGroup release];
        _undoGroupingLevel = 1;
        _hasNestedGroup = NO;
    } else {
        [undoGroup createUndoSubGroup];
        _undoGroupingLevel++;
        _hasNestedGroup = YES;
    }
    if (!_redoing) {
        _groupingLevel = _undoGroupingLevel;
    }
}

/**
 @Status Interoperable
*/
- (void)endUndoGrouping {
    if (_undoing) {
        return;
    }
    // No group to close.
    if (_undoGroupingLevel == 0) {
        [NSException raise:NSInternalInconsistencyException format:@"endUndoGrouping called with no open group."];
    }
    _NSUndoGroup* undoGroup = [_undoStack peek];
    [undoGroup closeUndoGroup];
    _undoGroupingLevel--;
    if (!_redoing) {
        _groupingLevel = _undoGroupingLevel;
    }
}

// Internal redo grouping
- (void)_beginRedoGrouping {
    _NSUndoGroup* redoGroup = [_redoStack peek];

    if (redoGroup == nil || [redoGroup isClosed]) {
        _NSUndoGroup* newGroup = [[_NSUndoGroup alloc] init];
        [_redoStack push:newGroup];
        [newGroup release];
    } else {
        [redoGroup createUndoSubGroup];
    }
    _redoGroupingLevel++;
    if (!_redoing) {
        _groupingLevel = _redoGroupingLevel;
    }
}

- (void)_endRedoGrouping {
    // No group to close.
    if (_redoGroupingLevel == 0) {
        [NSException raise:NSInternalInconsistencyException format:@"Attempted to close a redo group with no open redo group."];
    }
    _NSUndoGroup* redoGroup = [_redoStack peek];
    [redoGroup closeUndoGroup];
    _redoGroupingLevel--;
    if (!_redoing) {
        _groupingLevel = _redoGroupingLevel;
    }
}

/**
@Status Interoperable
*/
- (BOOL)isUndoRegistrationEnabled {
    @synchronized(self) {
        return _disableCount == 0;
    }
}

/**
 @Status Interoperable
*/
- (void)disableUndoRegistration {
    @synchronized(self) {
        _disableCount++;
    }
}

/**
 @Status Interoperable
*/
- (void)enableUndoRegistration {
    @synchronized(self) {
        if (_disableCount == 0) {
            [NSException raise:NSInternalInconsistencyException
                        format:@"Called enable undo registration while undo registration is enabled."];
        }
        _disableCount--;
    }
}

/**
 @Status Interoperable
*/
- (void)removeAllActions {
    _undoStack.attach([[_NSUndoManagerStack alloc] init]);
    _redoStack.attach([[_NSUndoManagerStack alloc] init]);

    _undoGroupingLevel = 0;
    _redoGroupingLevel = 0;

    _isAutomaticGroupOpen = NO;
    _hasNestedGroup = NO;
}

/**
 @Status Interoperable
 @Notes
*/
- (void)removeAllActionsWithTarget:(id)target {
    [_undoStack removeAllWithTarget:target];
    [_redoStack removeAllWithTarget:target];

    _undoGroupingLevel = [[_undoStack peek] getNumberOfOpenGroups];
    _redoGroupingLevel = [[_undoStack peek] getNumberOfOpenGroups];
    _isAutomaticGroupOpen = (_undoGroupingLevel != 0);
    _hasNestedGroup = [((_NSUndoGroup*)[_undoStack peek])hasNestedGroup];
}

/**
 @Status Interoperable
 @Notes
*/
- (void)setActionName:(NSString*)actionName {
    if (_undoing) {
        [_redoActionName release];
        _redoActionName = [actionName copy];
    } else {
        [_undoActionName release];
        _undoActionName = [actionName copy];
    }
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)undoMenuTitleForUndoActionName:(NSString*)actionName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)redoMenuTitleForUndoActionName:(NSString*)actionName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setActionIsDiscardable:(BOOL)discardable {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (BOOL)canUndo {
    return [_undoStack count] > 0;
}

/**
 @Status Interoperable
*/
- (BOOL)canRedo {
    return [_redoStack count] > 0;
}

- (void)dealloc {
    [_undoActionName release];
    [_redoActionName release];
    [_runLoopModes release];

    [super dealloc];
}

@end