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
#import <StubReturn.h>
#import <Foundation/NSUndoManager.h>
#import <Foundation/NSMutableArray.h>
#import "_NSUndoManagerInternal.h"

NSString* const NSUndoManagerGroupIsDiscardableKey = @"NSUndoManagerGroupIsDiscardableKey";

@implementation NSUndoManager {
    StrongId<NSMutableArray<_NSUndoGroup*>> _undoStack;
    StrongId<NSMutableArray<_NSUndoGroup*>> _redoStack;
    NSInteger _redoGroupingLevel;
    NSInteger _undoGroupingLevel;
    BOOL _isAutomaticGroupOpen;
}

/**
 @Status Interoperable
*/
- (id)init {
    if (self = [super init]) {
        _groupsByEvent = YES;
        _undoRegistrationEnabled = YES;

        _undoStack = [NSMutableArray array];
        _redoStack = [NSMutableArray array];

        _undoGroupingLevel = 0;
        _redoGroupingLevel = 0;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)registerUndoWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject {
    if (_undoRegistrationEnabled) {
        _NSUndoBasicAction* undoCall = [[[_NSUndoBasicAction alloc] _initWithTarget:target selector:aSelector object:anObject] autorelease];
        [self _registerUndoAction:undoCall];
    }
}

- (void)_createAutomaticUndoGroup {
    if (!_isAutomaticGroupOpen) {
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
                _NSUndoGroup* startingRedoGroup = [[[_NSUndoGroup alloc] initWithLevel:1] autorelease];
                [_redoStack addObject:startingRedoGroup];
            }
            [[_redoStack lastObject] addUndoCallToUndoGroup:undoCall];
        } else {
            // Any new actions invalidate any redo actions
            if (!_redoing) {
                [self _removeRedoActions];
            }
            [self _createAutomaticUndoGroup];
            [[_undoStack lastObject] addUndoCallToUndoGroup:undoCall];
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
    _groupingLevel = _undoGroupingLevel;
    _NSUndoGroup* lastGroup = [_undoStack lastObject];
    if (_groupingLevel == 1) {
        [lastGroup closeUndoGroup];
    }

    if (![self canUndo]) {
        return;
    }

    [self undoNestedGroup];
}

/**
 @Status Interoperable
*/
- (void)undoNestedGroup {
    _groupingLevel = _undoGroupingLevel;
    if (_groupingLevel == 0) {
        // NSInternalInconsistencyException
    }
    _undoing = YES;

    _NSUndoGroup* undoGroup = [_undoStack lastObject];

    // Record redo operation as a single redo group
    [self _beginRedoGrouping];
    [undoGroup undo];
    [self _endRedoGrouping];
    [_undoStack removeLastObject];

    _NSUndoGroup* nextGroup = [_undoStack lastObject];
    _undoGroupingLevel = [nextGroup _getDepth];
    _groupingLevel = _undoGroupingLevel;

    _undoing = NO;
}

/**
 @Status Interoperable
*/
- (void)redo {
    _groupingLevel = _redoGroupingLevel;
    if (![self canRedo]) {
        return;
    }
    _redoing = YES;

    _NSUndoGroup* redoGroup = [_redoStack lastObject];

    // Record undo operation as a single group
    [self beginUndoGrouping];
    [redoGroup undo];
    [self endUndoGrouping];
    [_redoStack removeLastObject];

    _NSUndoGroup* nextGroup = [_redoStack lastObject];
    _redoGroupingLevel = [nextGroup _getDepth];
    _groupingLevel = _redoGroupingLevel;

    _redoing = NO;
}

/**
 @Status Interoperable
*/
- (void)beginUndoGrouping {
    _NSUndoGroup* undoGroup = [_undoStack lastObject];

    if (undoGroup == nil || [undoGroup isClosed]) {
        _NSUndoGroup* newGroup = [[[_NSUndoGroup alloc] initWithLevel:1] autorelease];
        [_undoStack addObject:newGroup];
        _undoGroupingLevel = 1;
    } else {
        _undoGroupingLevel = [undoGroup createUndoGroupWithLevel:1];
    }
    _groupingLevel = _undoGroupingLevel;
}

/**
 @Status Interoperable
*/
- (void)endUndoGrouping {
    _NSUndoGroup* undoGroup = [_undoStack lastObject];
    [undoGroup closeUndoGroup];
    if (_undoGroupingLevel == 0) {
        // NSInternalInconsistencyException
    }
}

// Internal redo grouping
- (void)_beginRedoGrouping {
    _NSUndoGroup* redoGroup = [_redoStack lastObject];

    if ([redoGroup isClosed]) {
        _NSUndoGroup* newGroup = [[[_NSUndoGroup alloc] initWithLevel:1] autorelease];
        [_redoStack addObject:newGroup];
        _redoGroupingLevel = 1;
    } else {
        _redoGroupingLevel = [redoGroup createUndoGroupWithLevel:1];
    }
    _groupingLevel = _redoGroupingLevel;
}

- (void)_endRedoGrouping {
    _NSUndoGroup* redoGroup = [_redoStack lastObject];
    [redoGroup closeUndoGroup];
    if (_redoGroupingLevel == 0) {
        // NSInternalInconsistencyException
    }
}

/**
 @Status Interoperable
*/
- (void)disableUndoRegistration {
    _undoRegistrationEnabled = NO;
}

/**
 @Status Interoperable
*/
- (void)enableUndoRegistration {
    _undoRegistrationEnabled = YES;
}

/**
 @Status Interoperable
*/
- (void)removeAllActions {
    [self _removeUndoActions];
    [self _removeRedoActions];
}

- (void)_removeUndoActions {
    _undoStack = [NSMutableArray array];
}

- (void)_removeRedoActions {
    _redoStack = [NSMutableArray array];
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
    return [[_undoStack lastObject] canUndo];
}

/**
 @Status Interoperable
*/
- (BOOL)canRedo {
    return [[_redoStack lastObject] canUndo];
}

@end
