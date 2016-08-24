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

NSString* const NSUndoManagerGroupIsDiscardableKey = @"NSUndoManagerGroupIsDiscardableKey";

@implementation NSUndoManager {
    StrongId<_NSUndoManagerStack> _undoStack;
    StrongId<_NSUndoManagerStack> _redoStack;
    NSUInteger _disableCount;
    BOOL _isAutomaticGroupOpen;
}

/**
 @Status Interoperable
*/
- (id)init {
    if (self = [super init]) {
        _groupsByEvent = YES;
        _undoRegistrationEnabled = YES;
        _disableCount = 0;

        _undoStack = [[_NSUndoManagerStack alloc] init];
        _redoStack = [[_NSUndoManagerStack alloc] init];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)registerUndoWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject {
    if (_undoRegistrationEnabled) {
        _NSUndoBasicAction* undoCall = [[_NSUndoBasicAction alloc] _initWithTarget:target selector:aSelector object:anObject];
        [self _registerUndoAction:undoCall];
    }
}

- (void)_createAutomaticUndoGroup {
    if (!_isAutomaticGroupOpen && _groupingLevel == 0) {
        [self beginUndoGrouping];
        _isAutomaticGroupOpen = YES;
    }
}

// Internal function for proper registration of the deferred call.
- (void)_registerUndoAction:(_NSUndoBasicAction*)undoCall {
    // If groupsByEvent is set then have a top level undo group to catch all undo calls.
    if (_groupsByEvent) {
        if (_undoing) {
            if ([_redoStack count] == 0) {
                _NSUndoGroup* startingRedoGroup = [[_NSUndoGroup alloc] initWithLevel:1];
                [_redoStack push:startingRedoGroup];
            }
            _NSUndoGroup* redoGroup = [_redoStack peek];
            if (redoGroup == nil) {
                [NSException raise:NSInternalInconsistencyException format:@"No group for redo operation to be registered."];
            }
            [redoGroup addUndoCallToUndoGroup:undoCall];
        } else {
            // Any new actions invalidate any redo actions
            if (!_redoing) {
                [self _removeRedoActions];
            }
            [self _createAutomaticUndoGroup];
            _NSUndoGroup* undoGroup = [_undoStack peek];
            if (undoGroup == nil) {
                [NSException raise:NSInternalInconsistencyException format:@"No group for undo operation to be registered."];
            }
            [undoGroup addUndoCallToUndoGroup:undoCall];
        }
    } else {
        // TODO: Issue #811 - Support undo grouping.
        UNIMPLEMENTED_WITH_MSG("Manual undo grouping not supported.");
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
    _groupingLevel = [_undoStack count];
    if (_groupingLevel == 1) {
        [self endUndoGrouping];
    }

    [self undoNestedGroup];
}

/**
 @Status Interoperable
*/
- (void)undoNestedGroup {
    _groupingLevel = [_undoStack count];

    if (![self canUndo]) {
        return;
    }

    if (_groupingLevel == 0) {
        [NSException raise:NSInternalInconsistencyException format:@"No top level group to undo."];
    }

    _undoing = YES;

    _NSUndoGroup* undoGroup = [_undoStack peek];

    // Record redo operation as a single redo group
    [self _beginRedoGrouping];
    [undoGroup undo];
    [self _endRedoGrouping];
    [_undoStack pop];

    _groupingLevel = [_undoStack count];
    ;

    _undoing = NO;
}

/**
 @Status Interoperable
*/
- (void)redo {
    _groupingLevel = [_redoStack count];
    if (![self canRedo]) {
        return;
    }

    if (_undoing) {
        [NSException raise:NSInternalInconsistencyException format:@"Cannot invoke redo while undoing is active."];
    }

    _redoing = YES;

    _NSUndoGroup* redoGroup = [_redoStack peek];

    // Record undo operation as a single group
    [self beginUndoGrouping];
    [redoGroup undo];
    [self endUndoGrouping];
    [_redoStack pop];

    _groupingLevel = [_redoStack count];

    _redoing = NO;
}

/**
 @Status Interoperable
*/
- (void)beginUndoGrouping {
    _NSUndoGroup* undoGroup = [_undoStack peek];

    if (undoGroup == nil || [undoGroup isClosed]) {
        _NSUndoGroup* newGroup = [[_NSUndoGroup alloc] initWithLevel:1];
        [_undoStack push:newGroup];
    } else {
        [undoGroup createUndoGroupWithLevel:1];
    }
    _groupingLevel = [_undoStack count];
}

/**
 @Status Interoperable
*/
- (void)endUndoGrouping {
    // No group to close.
    if ([_undoStack count] == 0) {
        [NSException raise:NSInternalInconsistencyException format:@"No group to close."];
    }
    _NSUndoGroup* undoGroup = [_undoStack peek];
    [undoGroup closeUndoGroup];
}

// Internal redo grouping
- (void)_beginRedoGrouping {
    _NSUndoGroup* redoGroup = [_redoStack peek];

    if (redoGroup == nil || [redoGroup isClosed]) {
        _NSUndoGroup* newGroup = [[_NSUndoGroup alloc] initWithLevel:1];
        [_redoStack push:newGroup];
    } else {
        [redoGroup createUndoGroupWithLevel:1];
    }
    _groupingLevel = [_redoStack count];
}

- (void)_endRedoGrouping {
    // No group to close.
    if ([_redoStack count] == 0) {
        [NSException raise:NSInternalInconsistencyException format:@"No redo group to close."];
    }
    _NSUndoGroup* redoGroup = [_redoStack peek];
    [redoGroup closeUndoGroup];
}

/**
 @Status Interoperable
*/
- (void)disableUndoRegistration {
    _disableCount++;
    _undoRegistrationEnabled = NO;
}

/**
 @Status Interoperable
*/
- (void)enableUndoRegistration {
    if (_disableCount == 0) {
        [NSException raise:NSInternalInconsistencyException format:@"Undo Registration Already Enabled."];
    }
    _disableCount--;
    if (_disableCount == 0) {
        _undoRegistrationEnabled = YES;
    }
}

/**
 @Status Interoperable
*/
- (void)removeAllActions {
    [self _removeUndoActions];
    [self _removeRedoActions];
}

- (void)_removeUndoActions {
    _undoStack = [[_NSUndoManagerStack alloc] init];
}

- (void)_removeRedoActions {
    _redoStack = [[_NSUndoManagerStack alloc] init];
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllActionsWithTarget:(id)target {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setActionName:(NSString*)actionName {
    UNIMPLEMENTED();
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

@end
