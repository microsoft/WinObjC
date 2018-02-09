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

// WindowsUIPopups.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIPOPUPSEXPORT
#define OBJCUWPWINDOWSUIPOPUPSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIPopups.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUPMessageDialog, WUPUICommand, WUPUICommandSeparator, WUPPopupMenu;
@protocol WUPIMessageDialog, WUPIMessageDialogFactory, WUPIUICommand, WUPIUICommandFactory, WUPIPopupMenu;

// Windows.UI.Popups.MessageDialogOptions
enum _WUPMessageDialogOptions {
    WUPMessageDialogOptionsNone = 0,
    WUPMessageDialogOptionsAcceptUserInputAfterDelay = 1,
};
typedef unsigned WUPMessageDialogOptions;

// Windows.UI.Popups.Placement
enum _WUPPlacement {
    WUPPlacementDefault = 0,
    WUPPlacementAbove = 1,
    WUPPlacementBelow = 2,
    WUPPlacementLeft = 3,
    WUPPlacementRight = 4,
};
typedef unsigned WUPPlacement;

#include "WindowsFoundation.h"
// Windows.UI.Popups.UICommandInvokedHandler
#ifndef __WUPUICommandInvokedHandler__DEFINED
#define __WUPUICommandInvokedHandler__DEFINED
typedef void(^WUPUICommandInvokedHandler)(RTObject<WUPIUICommand>* command);
#endif // __WUPUICommandInvokedHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.UI.Popups.UICommandInvokedHandler
#ifndef __WUPUICommandInvokedHandler__DEFINED
#define __WUPUICommandInvokedHandler__DEFINED
typedef void(^WUPUICommandInvokedHandler)(RTObject<WUPIUICommand>* command);
#endif // __WUPUICommandInvokedHandler__DEFINED

// Windows.UI.Popups.IUICommand
#ifndef __WUPIUICommand_DEFINED__
#define __WUPIUICommand_DEFINED__

@protocol WUPIUICommand
@property (retain) RTObject* id;
@property (copy) WUPUICommandInvokedHandler invoked;
@property (retain) NSString * label;
@end

OBJCUWPWINDOWSUIPOPUPSEXPORT
@interface WUPIUICommand : RTObject <WUPIUICommand>
@end

#endif // __WUPIUICommand_DEFINED__

// Windows.UI.Popups.MessageDialog
#ifndef __WUPMessageDialog_DEFINED__
#define __WUPMessageDialog_DEFINED__

OBJCUWPWINDOWSUIPOPUPSEXPORT
@interface WUPMessageDialog : RTObject
+ (WUPMessageDialog*)make:(NSString *)content ACTIVATOR;
+ (WUPMessageDialog*)makeWithTitle:(NSString *)content title:(NSString *)title ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property WUPMessageDialogOptions options;
@property unsigned int defaultCommandIndex;
@property (retain) NSString * content;
@property unsigned int cancelCommandIndex;
@property (readonly) NSMutableArray* /* RTObject<WUPIUICommand>* */ commands;
- (void)showAsyncWithSuccess:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUPMessageDialog_DEFINED__

// Windows.UI.Popups.UICommand
#ifndef __WUPUICommand_DEFINED__
#define __WUPUICommand_DEFINED__

OBJCUWPWINDOWSUIPOPUPSEXPORT
@interface WUPUICommand : RTObject <WUPIUICommand>
+ (WUPUICommand*)make:(NSString *)label ACTIVATOR;
+ (WUPUICommand*)makeWithHandler:(NSString *)label action:(WUPUICommandInvokedHandler)action ACTIVATOR;
+ (WUPUICommand*)makeWithHandlerAndId:(NSString *)label action:(WUPUICommandInvokedHandler)action commandId:(RTObject*)commandId ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * label;
@property (copy) WUPUICommandInvokedHandler invoked;
@property (retain) RTObject* id;
@end

#endif // __WUPUICommand_DEFINED__

// Windows.UI.Popups.UICommandSeparator
#ifndef __WUPUICommandSeparator_DEFINED__
#define __WUPUICommandSeparator_DEFINED__

OBJCUWPWINDOWSUIPOPUPSEXPORT
@interface WUPUICommandSeparator : RTObject <WUPIUICommand>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * label;
@property (copy) WUPUICommandInvokedHandler invoked;
@property (retain) RTObject* id;
@end

#endif // __WUPUICommandSeparator_DEFINED__

// Windows.UI.Popups.PopupMenu
#ifndef __WUPPopupMenu_DEFINED__
#define __WUPPopupMenu_DEFINED__

OBJCUWPWINDOWSUIPOPUPSEXPORT
@interface WUPPopupMenu : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* RTObject<WUPIUICommand>* */ commands;
- (void)showAsync:(WFPoint*)invocationPoint success:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
- (void)showAsyncWithRect:(WFRect*)selection success:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
- (void)showAsyncWithRectAndPlacement:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement success:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUPPopupMenu_DEFINED__

