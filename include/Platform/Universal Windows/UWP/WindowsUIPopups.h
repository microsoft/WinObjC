//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "interopBase.h"
@class WUPMessageDialog, WUPUICommand, WUPUICommandSeparator, WUPPopupMenu;
@protocol WUPIMessageDialog
, WUPIMessageDialogFactory, WUPIUICommand, WUPIUICommandFactory, WUPIPopupMenu;

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
#include "WindowsFoundationCollections.h"
// Windows.UI.Popups.UICommandInvokedHandler
#ifndef __WUPUICommandInvokedHandler__DEFINED
#define __WUPUICommandInvokedHandler__DEFINED
typedef void (^WUPUICommandInvokedHandler)(RTObject<WUPIUICommand>* command);
#endif // __WUPUICommandInvokedHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.UI.Popups.UICommandInvokedHandler
#ifndef __WUPUICommandInvokedHandler__DEFINED
#define __WUPUICommandInvokedHandler__DEFINED
typedef void (^WUPUICommandInvokedHandler)(RTObject<WUPIUICommand>* command);
#endif // __WUPUICommandInvokedHandler__DEFINED

// Windows.UI.Popups.IUICommand
#ifndef __WUPIUICommand_DEFINED__
#define __WUPIUICommand_DEFINED__

@protocol WUPIUICommand
@property (copy) RTObject* id;
@property (copy) WUPUICommandInvokedHandler invoked;
@property (copy) NSString* label;
@end

#endif // __WUPIUICommand_DEFINED__

// Windows.UI.Popups.MessageDialog
#ifndef __WUPMessageDialog_DEFINED__
#define __WUPMessageDialog_DEFINED__

WINRT_EXPORT
@interface WUPMessageDialog : RTObject
+ (WUPMessageDialog*)create:(NSString*)content ACTIVATOR;
+ (WUPMessageDialog*)createWithTitle:(NSString*)content title:(NSString*)title ACTIVATOR;
@property (copy) NSString* title;
@property WUPMessageDialogOptions options;
@property unsigned int defaultCommandIndex;
@property (copy) NSString* content;
@property unsigned int cancelCommandIndex;
@property (readonly) NSMutableArray* commands;
- (void)showAsyncWithSuccess:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUPMessageDialog_DEFINED__

// Windows.UI.Popups.UICommand
#ifndef __WUPUICommand_DEFINED__
#define __WUPUICommand_DEFINED__

WINRT_EXPORT
@interface WUPUICommand : RTObject <WUPIUICommand>
+ (WUPUICommand*)create:(NSString*)label ACTIVATOR;
+ (WUPUICommand*)createWithHandler:(NSString*)label action:(WUPUICommandInvokedHandler)action ACTIVATOR;
+ (WUPUICommand*)createWithHandlerAndId:(NSString*)label action:(WUPUICommandInvokedHandler)action commandId:(RTObject*)commandId ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* label;
@property (copy) WUPUICommandInvokedHandler invoked;
@property (copy) RTObject* id;
@end

#endif // __WUPUICommand_DEFINED__

// Windows.UI.Popups.UICommandSeparator
#ifndef __WUPUICommandSeparator_DEFINED__
#define __WUPUICommandSeparator_DEFINED__

WINRT_EXPORT
@interface WUPUICommandSeparator : RTObject <WUPIUICommand>
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* label;
@property (copy) WUPUICommandInvokedHandler invoked;
@property (copy) RTObject* id;
@end

#endif // __WUPUICommandSeparator_DEFINED__

// Windows.UI.Popups.PopupMenu
#ifndef __WUPPopupMenu_DEFINED__
#define __WUPPopupMenu_DEFINED__

WINRT_EXPORT
@interface WUPPopupMenu : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) NSMutableArray* commands;
- (void)showAsync:(WFPoint*)invocationPoint success:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
- (void)showAsyncWithRect:(WFRect*)selection success:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
- (void)showAsyncWithRectAndPlacement:(WFRect*)selection
                   preferredPlacement:(WUPPlacement)preferredPlacement
                              success:(void (^)(RTObject<WUPIUICommand>*))success
                              failure:(void (^)(NSError*))failure;
@end

#endif // __WUPPopupMenu_DEFINED__
