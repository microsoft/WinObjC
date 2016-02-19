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

NSString* const NSUndoManagerGroupIsDiscardableKey = @"NSUndoManagerGroupIsDiscardableKey";

@implementation NSUndoManager
/**
 @Status Stub
 @Notes
*/
- (void)registerUndoWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject {
    UNIMPLEMENTED();
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
 @Status Stub
 @Notes
*/
- (void)undo {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)undoNestedGroup {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)redo {
    UNIMPLEMENTED();
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
 @Status Stub
 @Notes
*/
- (void)disableUndoRegistration {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enableUndoRegistration {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllActions {
    UNIMPLEMENTED();
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

@end
