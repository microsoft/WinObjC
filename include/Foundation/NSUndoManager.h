//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
- (void)registerUndoWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject STUB_METHOD;
- (id)prepareWithInvocationTarget:(id)target STUB_METHOD;
@property (readonly) BOOL canUndo STUB_PROPERTY;
@property (readonly) BOOL canRedo STUB_PROPERTY;
- (void)undo STUB_METHOD;
- (void)undoNestedGroup STUB_METHOD;
- (void)redo STUB_METHOD;
@property NSUInteger levelsOfUndo STUB_PROPERTY;
- (void)beginUndoGrouping STUB_METHOD;
- (void)endUndoGrouping STUB_METHOD;
@property BOOL groupsByEvent STUB_PROPERTY;
@property (readonly) NSInteger groupingLevel STUB_PROPERTY;
- (void)disableUndoRegistration STUB_METHOD;
- (void)enableUndoRegistration STUB_METHOD;
@property (readonly, getter=isUndoRegistrationEnabled) BOOL undoRegistrationEnabled STUB_PROPERTY;
@property (readonly, getter=isUndoing) BOOL undoing STUB_PROPERTY;
@property (readonly, getter=isRedoing) BOOL redoing STUB_PROPERTY;
- (void)removeAllActions STUB_METHOD;
- (void)removeAllActionsWithTarget:(id)target STUB_METHOD;
@property (readonly, copy) NSString* undoActionName STUB_PROPERTY;
@property (readonly, copy) NSString* redoActionName STUB_PROPERTY;
- (void)setActionName:(NSString*)actionName STUB_METHOD;
@property (readonly, copy) NSString* undoMenuItemTitle STUB_PROPERTY;
@property (readonly, copy) NSString* redoMenuItemTitle STUB_PROPERTY;
- (NSString*)undoMenuTitleForUndoActionName:(NSString*)actionName STUB_METHOD;
- (NSString*)redoMenuTitleForUndoActionName:(NSString*)actionName STUB_METHOD;
@property (copy) NSArray* runLoopModes STUB_PROPERTY;
- (void)setActionIsDiscardable:(BOOL)discardable STUB_METHOD;
@property (readonly) BOOL undoActionIsDiscardable STUB_PROPERTY;
@property (readonly) BOOL redoActionIsDiscardable STUB_PROPERTY;
@end
