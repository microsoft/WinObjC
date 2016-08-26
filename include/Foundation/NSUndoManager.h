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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;

enum { NSUndoCloseGroupingRunLoopOrdering = 350000 };

FOUNDATION_EXPORT NSString* const NSUndoManagerGroupIsDiscardableKey;
FOUNDATION_EXPORT NSString* const NSUndoManagerCheckpointNotification;
FOUNDATION_EXPORT NSString* const NSUndoManagerDidOpenUndoGroupNotification;
FOUNDATION_EXPORT NSString* const NSUndoManagerWillCloseUndoGroupNotification;
FOUNDATION_EXPORT NSString* const NSUndoManagerWillUndoChangeNotification;
FOUNDATION_EXPORT NSString* const NSUndoManagerDidUndoChangeNotification;
FOUNDATION_EXPORT NSString* const NSUndoManagerWillRedoChangeNotification;
FOUNDATION_EXPORT NSString* const NSUndoManagerDidRedoChangeNotification;
FOUNDATION_EXPORT NSString* const NSUndoManagerDidCloseUndoGroupNotification;

FOUNDATION_EXPORT_CLASS
@interface NSUndoManager : NSObject
- (void)registerUndoWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject;
- (id)prepareWithInvocationTarget:(id)target STUB_METHOD;
@property (readonly) BOOL canUndo;
@property (readonly) BOOL canRedo;
- (void)undo;
- (void)undoNestedGroup;
- (void)redo;
@property NSUInteger levelsOfUndo;
- (void)beginUndoGrouping;
- (void)endUndoGrouping;
@property BOOL groupsByEvent;
@property (readonly) NSInteger groupingLevel;
- (void)disableUndoRegistration;
- (void)enableUndoRegistration;
- (BOOL)isUndoRegistrationEnabled;
@property (readonly, getter=isUndoing) BOOL undoing;
@property (readonly, getter=isRedoing) BOOL redoing;
- (void)removeAllActions;
- (void)removeAllActionsWithTarget:(id)target;
@property (readonly, copy) NSString* undoActionName;
@property (readonly, copy) NSString* redoActionName;
- (void)setActionName:(NSString*)actionName;
@property (readonly, copy) NSString* undoMenuItemTitle STUB_PROPERTY;
@property (readonly, copy) NSString* redoMenuItemTitle STUB_PROPERTY;
- (NSString*)undoMenuTitleForUndoActionName:(NSString*)actionName STUB_METHOD;
- (NSString*)redoMenuTitleForUndoActionName:(NSString*)actionName STUB_METHOD;
@property (copy) NSArray* runLoopModes;
- (void)setActionIsDiscardable:(BOOL)discardable STUB_METHOD;
@property (readonly) BOOL undoActionIsDiscardable STUB_PROPERTY;
@property (readonly) BOOL redoActionIsDiscardable STUB_PROPERTY;
@end
