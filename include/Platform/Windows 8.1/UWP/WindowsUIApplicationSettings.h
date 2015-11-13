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

// WindowsUIApplicationSettings.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUASettingsCommand, WUASettingsPaneCommandsRequest, WUASettingsPaneCommandsRequestedEventArgs, WUASettingsPane,
    WUAWebAccountProviderCommand, WUAWebAccountCommand, WUAWebAccountInvokedArgs, WUACredentialCommand,
    WUAAccountsSettingsPaneEventDeferral, WUAAccountsSettingsPaneCommandsRequestedEventArgs, WUAAccountsSettingsPane;
@protocol WUAISettingsCommandFactory
, WUAISettingsCommandStatics, WUAISettingsPaneCommandsRequest, WUAISettingsPaneCommandsRequestedEventArgs, WUAISettingsPaneStatics,
    WUAISettingsPane, WUAIWebAccountProviderCommandFactory, WUAIWebAccountCommandFactory, WUAICredentialCommandFactory,
    WUAIWebAccountProviderCommand, WUAIWebAccountInvokedArgs, WUAIWebAccountCommand, WUAICredentialCommand,
    WUAIAccountsSettingsPaneEventDeferral, WUAIAccountsSettingsPaneCommandsRequestedEventArgs, WUAIAccountsSettingsPaneStatics,
    WUAIAccountsSettingsPane;

// Windows.UI.ApplicationSettings.SettingsEdgeLocation
enum _WUASettingsEdgeLocation {
    WUASettingsEdgeLocationRight = 0,
    WUASettingsEdgeLocationLeft = 1,
};
typedef unsigned WUASettingsEdgeLocation;

// Windows.UI.ApplicationSettings.SupportedWebAccountActions
enum _WUASupportedWebAccountActions {
    WUASupportedWebAccountActionsNone = 0,
    WUASupportedWebAccountActionsReconnect = 1,
    WUASupportedWebAccountActionsRemove = 2,
    WUASupportedWebAccountActionsViewDetails = 4,
    WUASupportedWebAccountActionsManage = 8,
    WUASupportedWebAccountActionsMore = 16,
};
typedef unsigned WUASupportedWebAccountActions;

// Windows.UI.ApplicationSettings.WebAccountAction
enum _WUAWebAccountAction {
    WUAWebAccountActionReconnect = 0,
    WUAWebAccountActionRemove = 1,
    WUAWebAccountActionViewDetails = 2,
    WUAWebAccountActionManage = 3,
    WUAWebAccountActionMore = 4,
};
typedef unsigned WUAWebAccountAction;

#include "WindowsFoundation.h"
#include "WindowsUIPopups.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsFoundationCollections.h"
// Windows.UI.ApplicationSettings.CredentialCommandCredentialDeletedHandler
#ifndef __WUACredentialCommandCredentialDeletedHandler__DEFINED
#define __WUACredentialCommandCredentialDeletedHandler__DEFINED
typedef void (^WUACredentialCommandCredentialDeletedHandler)(WUACredentialCommand* command);
#endif // __WUACredentialCommandCredentialDeletedHandler__DEFINED

// Windows.UI.ApplicationSettings.WebAccountCommandInvokedHandler
#ifndef __WUAWebAccountCommandInvokedHandler__DEFINED
#define __WUAWebAccountCommandInvokedHandler__DEFINED
typedef void (^WUAWebAccountCommandInvokedHandler)(WUAWebAccountCommand* command, WUAWebAccountInvokedArgs* args);
#endif // __WUAWebAccountCommandInvokedHandler__DEFINED

// Windows.UI.ApplicationSettings.WebAccountProviderCommandInvokedHandler
#ifndef __WUAWebAccountProviderCommandInvokedHandler__DEFINED
#define __WUAWebAccountProviderCommandInvokedHandler__DEFINED
typedef void (^WUAWebAccountProviderCommandInvokedHandler)(WUAWebAccountProviderCommand* command);
#endif // __WUAWebAccountProviderCommandInvokedHandler__DEFINED

// Windows.UI.Popups.UICommandInvokedHandler
#ifndef __WUPUICommandInvokedHandler__DEFINED
#define __WUPUICommandInvokedHandler__DEFINED
typedef void (^WUPUICommandInvokedHandler)(RTObject<WUPIUICommand>* command);
#endif // __WUPUICommandInvokedHandler__DEFINED

// Windows.UI.ApplicationSettings.WebAccountProviderCommandInvokedHandler
#ifndef __WUAWebAccountProviderCommandInvokedHandler__DEFINED
#define __WUAWebAccountProviderCommandInvokedHandler__DEFINED
typedef void (^WUAWebAccountProviderCommandInvokedHandler)(WUAWebAccountProviderCommand* command);
#endif // __WUAWebAccountProviderCommandInvokedHandler__DEFINED

// Windows.UI.ApplicationSettings.WebAccountCommandInvokedHandler
#ifndef __WUAWebAccountCommandInvokedHandler__DEFINED
#define __WUAWebAccountCommandInvokedHandler__DEFINED
typedef void (^WUAWebAccountCommandInvokedHandler)(WUAWebAccountCommand* command, WUAWebAccountInvokedArgs* args);
#endif // __WUAWebAccountCommandInvokedHandler__DEFINED

// Windows.UI.ApplicationSettings.CredentialCommandCredentialDeletedHandler
#ifndef __WUACredentialCommandCredentialDeletedHandler__DEFINED
#define __WUACredentialCommandCredentialDeletedHandler__DEFINED
typedef void (^WUACredentialCommandCredentialDeletedHandler)(WUACredentialCommand* command);
#endif // __WUACredentialCommandCredentialDeletedHandler__DEFINED

// Windows.UI.Popups.IUICommand
#ifndef __WUPIUICommand_DEFINED__
#define __WUPIUICommand_DEFINED__

@protocol WUPIUICommand
@property (copy) RTObject* id;
@property (copy) WUPUICommandInvokedHandler invoked;
@property (copy) NSString* label;
@end

#endif // __WUPIUICommand_DEFINED__

// Windows.UI.ApplicationSettings.SettingsCommand
#ifndef __WUASettingsCommand_DEFINED__
#define __WUASettingsCommand_DEFINED__

WINRT_EXPORT
@interface WUASettingsCommand : RTObject <WUPIUICommand>
+ (WUASettingsCommand*)createSettingsCommand:(RTObject*)settingsCommandId
                                       label:(NSString*)label
                                     handler:(WUPUICommandInvokedHandler)handler ACTIVATOR;
@property (copy) NSString* label;
@property (copy) WUPUICommandInvokedHandler invoked;
@property (copy) RTObject* id;
+ (WUASettingsCommand*)accountsCommand;
@end

#endif // __WUASettingsCommand_DEFINED__

// Windows.UI.ApplicationSettings.SettingsPaneCommandsRequest
#ifndef __WUASettingsPaneCommandsRequest_DEFINED__
#define __WUASettingsPaneCommandsRequest_DEFINED__

WINRT_EXPORT
@interface WUASettingsPaneCommandsRequest : RTObject
@property (readonly) id<NSFastEnumeration> /*WUASettingsCommand*/ applicationCommands;
@end

#endif // __WUASettingsPaneCommandsRequest_DEFINED__

// Windows.UI.ApplicationSettings.SettingsPaneCommandsRequestedEventArgs
#ifndef __WUASettingsPaneCommandsRequestedEventArgs_DEFINED__
#define __WUASettingsPaneCommandsRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUASettingsPaneCommandsRequestedEventArgs : RTObject
@property (readonly) WUASettingsPaneCommandsRequest* request;
@end

#endif // __WUASettingsPaneCommandsRequestedEventArgs_DEFINED__

// Windows.UI.ApplicationSettings.SettingsPane
#ifndef __WUASettingsPane_DEFINED__
#define __WUASettingsPane_DEFINED__

WINRT_EXPORT
@interface WUASettingsPane : RTObject
+ (WUASettingsPane*)getForCurrentView;
+ (void)show;
+ (WUASettingsEdgeLocation)edge;
- (EventRegistrationToken)addCommandsRequestedEvent:(void (^)(WUASettingsPane*, WUASettingsPaneCommandsRequestedEventArgs*))del;
- (void)removeCommandsRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUASettingsPane_DEFINED__

// Windows.UI.ApplicationSettings.WebAccountProviderCommand
#ifndef __WUAWebAccountProviderCommand_DEFINED__
#define __WUAWebAccountProviderCommand_DEFINED__

WINRT_EXPORT
@interface WUAWebAccountProviderCommand : RTObject
+ (WUAWebAccountProviderCommand*)createWebAccountProviderCommand:(WSCWebAccountProvider*)webAccountProvider
                                                         invoked:(WUAWebAccountProviderCommandInvokedHandler)invoked ACTIVATOR;
@property (readonly) WUAWebAccountProviderCommandInvokedHandler invoked;
@property (readonly) WSCWebAccountProvider* webAccountProvider;
@end

#endif // __WUAWebAccountProviderCommand_DEFINED__

// Windows.UI.ApplicationSettings.WebAccountCommand
#ifndef __WUAWebAccountCommand_DEFINED__
#define __WUAWebAccountCommand_DEFINED__

WINRT_EXPORT
@interface WUAWebAccountCommand : RTObject
+ (WUAWebAccountCommand*)createWebAccountCommand:(WSCWebAccount*)webAccount
                                         invoked:(WUAWebAccountCommandInvokedHandler)invoked
                                         actions:(WUASupportedWebAccountActions)actions ACTIVATOR;
@property (readonly) WUASupportedWebAccountActions actions;
@property (readonly) WUAWebAccountCommandInvokedHandler invoked;
@property (readonly) WSCWebAccount* webAccount;
@end

#endif // __WUAWebAccountCommand_DEFINED__

// Windows.UI.ApplicationSettings.WebAccountInvokedArgs
#ifndef __WUAWebAccountInvokedArgs_DEFINED__
#define __WUAWebAccountInvokedArgs_DEFINED__

WINRT_EXPORT
@interface WUAWebAccountInvokedArgs : RTObject
@property (readonly) WUAWebAccountAction action;
@end

#endif // __WUAWebAccountInvokedArgs_DEFINED__

// Windows.UI.ApplicationSettings.CredentialCommand
#ifndef __WUACredentialCommand_DEFINED__
#define __WUACredentialCommand_DEFINED__

WINRT_EXPORT
@interface WUACredentialCommand : RTObject
+ (WUACredentialCommand*)createCredentialCommand:(WSCPasswordCredential*)passwordCredential ACTIVATOR;
+ (WUACredentialCommand*)createCredentialCommandWithHandler:(WSCPasswordCredential*)passwordCredential
                                                    deleted:(WUACredentialCommandCredentialDeletedHandler)deleted ACTIVATOR;
@property (readonly) WUACredentialCommandCredentialDeletedHandler credentialDeleted;
@property (readonly) WSCPasswordCredential* passwordCredential;
@end

#endif // __WUACredentialCommand_DEFINED__

// Windows.UI.ApplicationSettings.AccountsSettingsPaneEventDeferral
#ifndef __WUAAccountsSettingsPaneEventDeferral_DEFINED__
#define __WUAAccountsSettingsPaneEventDeferral_DEFINED__

WINRT_EXPORT
@interface WUAAccountsSettingsPaneEventDeferral : RTObject
- (void)complete;
@end

#endif // __WUAAccountsSettingsPaneEventDeferral_DEFINED__

// Windows.UI.ApplicationSettings.AccountsSettingsPaneCommandsRequestedEventArgs
#ifndef __WUAAccountsSettingsPaneCommandsRequestedEventArgs_DEFINED__
#define __WUAAccountsSettingsPaneCommandsRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUAAccountsSettingsPaneCommandsRequestedEventArgs : RTObject
@property (copy) NSString* headerText;
@property (readonly) id<NSFastEnumeration> /*WUASettingsCommand*/ commands;
@property (readonly) id<NSFastEnumeration> /*WUACredentialCommand*/ credentialCommands;
@property (readonly) id<NSFastEnumeration> /*WUAWebAccountCommand*/ webAccountCommands;
@property (readonly) id<NSFastEnumeration> /*WUAWebAccountProviderCommand*/ webAccountProviderCommands;
- (WUAAccountsSettingsPaneEventDeferral*)getDeferral;
@end

#endif // __WUAAccountsSettingsPaneCommandsRequestedEventArgs_DEFINED__

// Windows.UI.ApplicationSettings.AccountsSettingsPane
#ifndef __WUAAccountsSettingsPane_DEFINED__
#define __WUAAccountsSettingsPane_DEFINED__

WINRT_EXPORT
@interface WUAAccountsSettingsPane : RTObject
+ (WUAAccountsSettingsPane*)getForCurrentView;
+ (void)show;
- (EventRegistrationToken)addAccountCommandsRequestedEvent:(void (^)(WUAAccountsSettingsPane*,
                                                                     WUAAccountsSettingsPaneCommandsRequestedEventArgs*))del;
- (void)removeAccountCommandsRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUAAccountsSettingsPane_DEFINED__
