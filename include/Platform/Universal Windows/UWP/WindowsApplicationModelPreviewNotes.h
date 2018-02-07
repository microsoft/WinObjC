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

// WindowsApplicationModelPreviewNotes.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWNOTESEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWNOTESEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelPreviewNotes.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAPNNotePlacementChangedPreviewEventArgs, WAPNNoteVisibilityChangedPreviewEventArgs, WAPNNotesWindowManagerPreviewShowNoteOptions, WAPNNotesWindowManagerPreview;
@protocol WAPNINotePlacementChangedPreviewEventArgs, WAPNINoteVisibilityChangedPreviewEventArgs, WAPNINotesWindowManagerPreviewShowNoteOptions, WAPNINotesWindowManagerPreview, WAPNINotesWindowManagerPreview2, WAPNINotesWindowManagerPreviewStatics;

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsImaging.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Preview.Notes.NotePlacementChangedPreviewEventArgs
#ifndef __WAPNNotePlacementChangedPreviewEventArgs_DEFINED__
#define __WAPNNotePlacementChangedPreviewEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWNOTESEXPORT
@interface WAPNNotePlacementChangedPreviewEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int viewId;
@end

#endif // __WAPNNotePlacementChangedPreviewEventArgs_DEFINED__

// Windows.ApplicationModel.Preview.Notes.NoteVisibilityChangedPreviewEventArgs
#ifndef __WAPNNoteVisibilityChangedPreviewEventArgs_DEFINED__
#define __WAPNNoteVisibilityChangedPreviewEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWNOTESEXPORT
@interface WAPNNoteVisibilityChangedPreviewEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isVisible;
@property (readonly) int viewId;
@end

#endif // __WAPNNoteVisibilityChangedPreviewEventArgs_DEFINED__

// Windows.ApplicationModel.Preview.Notes.NotesWindowManagerPreviewShowNoteOptions
#ifndef __WAPNNotesWindowManagerPreviewShowNoteOptions_DEFINED__
#define __WAPNNotesWindowManagerPreviewShowNoteOptions_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWNOTESEXPORT
@interface WAPNNotesWindowManagerPreviewShowNoteOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL showWithFocus;
@end

#endif // __WAPNNotesWindowManagerPreviewShowNoteOptions_DEFINED__

// Windows.ApplicationModel.Preview.Notes.NotesWindowManagerPreview
#ifndef __WAPNNotesWindowManagerPreview_DEFINED__
#define __WAPNNotesWindowManagerPreview_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWNOTESEXPORT
@interface WAPNNotesWindowManagerPreview : RTObject
+ (WAPNNotesWindowManagerPreview*)getForCurrentApp;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isScreenLocked;
- (EventRegistrationToken)addNotePlacementChangedEvent:(void(^)(WAPNNotesWindowManagerPreview*, WAPNNotePlacementChangedPreviewEventArgs*))del;
- (void)removeNotePlacementChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNoteVisibilityChangedEvent:(void(^)(WAPNNotesWindowManagerPreview*, WAPNNoteVisibilityChangedPreviewEventArgs*))del;
- (void)removeNoteVisibilityChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSystemLockStateChangedEvent:(void(^)(WAPNNotesWindowManagerPreview*, RTObject*))del;
- (void)removeSystemLockStateChangedEvent:(EventRegistrationToken)tok;
- (void)showNote:(int)noteViewId;
- (void)showNoteRelativeTo:(int)noteViewId anchorNoteViewId:(int)anchorNoteViewId;
- (void)showNoteWithPlacement:(int)noteViewId data:(RTObject<WSSIBuffer>*)data;
- (void)hideNote:(int)noteViewId;
- (RTObject<WSSIBuffer>*)getNotePlacement:(int)noteViewId;
- (BOOL)trySetNoteSize:(int)noteViewId size:(WFSize*)size;
- (void)setFocusToNextView;
- (RTObject<WFIAsyncAction>*)setNotesThumbnailAsync:(RTObject<WSSIBuffer>*)thumbnail;
- (void)showNoteRelativeToWithOptions:(int)noteViewId anchorNoteViewId:(int)anchorNoteViewId options:(WAPNNotesWindowManagerPreviewShowNoteOptions*)options;
- (void)showNoteWithPlacementWithOptions:(int)noteViewId data:(RTObject<WSSIBuffer>*)data options:(WAPNNotesWindowManagerPreviewShowNoteOptions*)options;
- (void)setFocusToPreviousView;
- (RTObject<WFIAsyncAction>*)setThumbnailImageForTaskSwitcherAsync:(WGISoftwareBitmap*)bitmap;
@end

#endif // __WAPNNotesWindowManagerPreview_DEFINED__

