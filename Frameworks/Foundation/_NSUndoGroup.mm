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

#import <Foundation/NSUndoManager.h>
#import "_NSUndoGroup.h"
#import "_NSUndoCall.h"

@implementation _NSUndoGroup : _NSUndoObject

- (id)initWithLevel:(NSUInteger)level {
    if (self = [super init]) {
        _undoGrouping = [NSMutableArray array];
        _undoLevel = level;
        _isClosed = NO;
    }
    return self;
}

- (id)initWithOwner:(NSUndoManager*)manager {
    if (self = [self initWithLevel:0]) {
        _owningManager = manager;
    }
    return self;
}

- (void)addUndoCallToUndoGroup:(_NSUndoCall*)undoCall {
    _NSUndoObject* topObjectInGroup = [_undoGrouping firstObject];
    if ([topObjectInGroup isKindOfClass:[_NSUndoGroup class]] && ![topObjectInGroup isClosed]) {
        [topObjectInGroup addUndoCallToUndoGroup:undoCall];
    }
    [_undoGrouping insertObject:undoCall atIndex:0];
}

- (void)callUndoGroup {
    while ([_undoGrouping count] > 0) {
        _NSUndoObject* object = [_undoGrouping firstObject];
        if ([object isKindOfClass:[_NSUndoGroup class]]) {
            [_owningManager callNestedGroup];
        } else {
            [((_NSUndoCall*)object)_invokeBasicUndo];
        }
        [_undoGrouping removeObjectAtIndex:0];
    }
}

- (void)callOnlyNestedGroup {
    for (int i = 0; i < [_undoGrouping count]; i++) {
        _NSUndoObject* object = [_undoGrouping objectAtIndex:i];
        if ([object isKindOfClass:[_NSUndoGroup class]]) {
            [((_NSUndoGroup*)object)invokeAllInNestedGroup];
        }
    }
}

- (void)invokeAllInNestedGroup {
    while ([_undoGrouping count] > 0) {
        _NSUndoObject* object = [_undoGrouping firstObject];
        if ([object isKindOfClass:[_NSUndoGroup class]]) {
            [((_NSUndoGroup*)object)invokeAllInNestedGroup];
        } else {
            [((_NSUndoCall*)object)_invokeBasicUndo];
        }
        [_undoGrouping removeObjectAtIndex:0];
    }
}

- (NSUInteger)createUndoGroup {
    id topObjectInGroup = [_undoGrouping firstObject];
    if ([topObjectInGroup isKindOfClass:[_NSUndoGroup class]] && [((_NSUndoGroup*)topObjectInGroup)isClosed]) {
        return [((_NSUndoGroup*)topObjectInGroup)createUndoGroup];
    }

    _NSUndoGroup* newGroup = [[[_NSUndoGroup alloc] initWithLevel:(_undoLevel + 1)] autorelease];
    [_undoGrouping insertObject:newGroup atIndex:0];
    return _undoLevel + 1;
}

- (BOOL)closeUndoGroup {
    id topObjectInGroup = [_undoGrouping firstObject];
    if ([topObjectInGroup isKindOfClass:[_NSUndoGroup class]] && ![((_NSUndoGroup*)topObjectInGroup)isClosed]) {
        return [((_NSUndoGroup*)topObjectInGroup)closeUndoGroup];
    }
    if (_isClosed) {
        // error case, already closed, bad state
    }
    _isClosed = YES;
    return YES;
}

- (BOOL)canUndo {
    // Top level undo group does not need to be closed.
    _NSUndoObject* topObjectInGroup = [_undoGrouping firstObject];

    if ([topObjectInGroup canUndo] && (_isClosed || _undoLevel == 0)) {
        return YES;
    }

    return NO;
}

@end