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

#import <StubReturn.h>
#import <Foundation/NSUndoManager.h>
#import <Foundation/NSMutableArray.h>
#import "_NSUndoCall.h"
#import "_NSUndoGroup.h"

@implementation NSUndoManager {
    NSMutableArray<_NSUndoGroup*>* _undoStack;
    NSMutableArray<_NSUndoGroup*>* _redoStack;
}

/**
 @Status Interoperable
*/
- (id)init {
    if (self = [super init]) {
        _groupsByEvent = YES;
        _NSUndoGroup* startingGroup = [[[_NSUndoGroup alloc] initWithOwner:self] autorelease];
        _NSUndoGroup* startingRedoGroup = [[[_NSUndoGroup alloc] initWithOwner:self] autorelease];

        _undoStack = [NSMutableArray array];
        _redoStack = [NSMutableArray array];

        [_undoStack addObject:startingGroup];
        [_redoStack addObject:startingRedoGroup];

        _undoRegistrationEnabled = YES;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)registerUndoWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject {
    if (!(self.isUndoRegistrationEnabled)) {
        return;
    }

    _NSUndoCall* undoCall = [[[_NSUndoCall alloc] _initWithTarget:target selector:aSelector object:anObject] autorelease];
    [self _registerUndoAction:undoCall];
}

// Internal function for proper registration of the deferred call.
- (void)_registerUndoAction:(_NSUndoCall*)undoCall {
    // If groupsByEvent is set then have a top level undo group to catch all undo calls.
    if (_groupsByEvent) {
        if (self.isUndoing) {
            if ([_redoStack count] == 0) {
                _NSUndoGroup* startingRedoGroup = [[[_NSUndoGroup alloc] initWithOwner:self] autorelease];
                [_redoStack addObject:startingRedoGroup];
            }
            [[_redoStack lastObject] addUndoCallToUndoGroup:undoCall];
        } else {
            // Any new actions invalidate any redo actions
            [self _removeRedoActions];
            if ([_undoStack count] == 0) {
                _NSUndoGroup* startingUndoGroup = [[[_NSUndoGroup alloc] initWithOwner:self] autorelease];
                [_undoStack addObject:startingUndoGroup];
            }
            [[_undoStack lastObject] addUndoCallToUndoGroup:undoCall];
        }
    } else {
        // TODO: Issue #811 - Support undo grouping.
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
    if (![self canUndo]) {
        return;
    }
    _undoing = YES;

    _NSUndoGroup* undoGroup = (_NSUndoGroup*)[_undoStack lastObject];
    [undoGroup callUndoGroup];
    [_undoStack removeLastObject];

    _undoing = NO;
}

/**
 @Status Stub
 @Notes
*/
- (void)undoNestedGroup {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)redo {
    if (![self canRedo]) {
        return;
    }
    _redoing = YES;

    _NSUndoGroup* undoGroup = (_NSUndoGroup*)[_redoStack lastObject];
    [undoGroup callUndoGroup];
    [_redoStack removeLastObject];

    _redoing = NO;
}

/**
 @Status Stub
 @Notes
*/
- (void)beginUndoGrouping {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)endUndoGrouping {
    UNIMPLEMENTED();
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
 @Status Stub
 @Notes
*/
- (void)removeAllActions {
    [self _removeUndoActions];
    [self _removeRedoActions];
}

- (void)_removeUndoActions {
    _undoStack = [NSMutableArray array];
    _NSUndoGroup* startingGroup = [[[_NSUndoGroup alloc] initWithOwner:self] autorelease];
    [_undoStack addObject:startingGroup];
}

- (void)_removeRedoActions {
    _redoStack = [NSMutableArray array];
    _NSUndoGroup* startingRedoGroup = [[[_NSUndoGroup alloc] initWithOwner:self] autorelease];
    [_redoStack addObject:startingRedoGroup];
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
    return [((_NSUndoGroup*)[_undoStack lastObject])canUndo];
}

/**
 @Status Interoperable
*/
- (BOOL)canRedo {
    return [((_NSUndoGroup*)[_redoStack lastObject])canUndo];
}

@end
