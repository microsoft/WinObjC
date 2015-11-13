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

// WindowsSecurityCredentials.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSCPasswordCredential, WSCPasswordVault, WSCPasswordCredentialPropertyStore, WSCWebAccountProvider, WSCWebAccount;
@protocol WSCIPasswordCredential
, WSCICredentialFactory, WSCIPasswordVault, WSCIWebAccountProviderFactory, WSCIWebAccountFactory, WSCIWebAccountProvider, WSCIWebAccount;

// Windows.Security.Credentials.WebAccountState
enum _WSCWebAccountState {
    WSCWebAccountStateNone = 0,
    WSCWebAccountStateConnected = 1,
    WSCWebAccountStateError = 2,
};
typedef unsigned WSCWebAccountState;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

// Windows.Security.Credentials.PasswordCredential
#ifndef __WSCPasswordCredential_DEFINED__
#define __WSCPasswordCredential_DEFINED__

WINRT_EXPORT
@interface WSCPasswordCredential : RTObject
+ (WSCPasswordCredential*)createPasswordCredential:(NSString*)resource userName:(NSString*)userName password:(NSString*)password ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* userName;
@property (copy) NSString* resource;
@property (copy) NSString* password;
@property (readonly) RTObject<WFCIPropertySet>* properties;
- (void)retrievePassword;
@end

#endif // __WSCPasswordCredential_DEFINED__

// Windows.Security.Credentials.PasswordVault
#ifndef __WSCPasswordVault_DEFINED__
#define __WSCPasswordVault_DEFINED__

WINRT_EXPORT
@interface WSCPasswordVault : RTObject
+ (instancetype)create ACTIVATOR;
- (void)add:(WSCPasswordCredential*)credential;
- (void)remove:(WSCPasswordCredential*)credential;
- (WSCPasswordCredential*)retrieve:(NSString*)resource userName:(NSString*)userName;
- (id<NSFastEnumeration> /*WSCPasswordCredential*/)findAllByResource:(NSString*)resource;
- (id<NSFastEnumeration> /*WSCPasswordCredential*/)findAllByUserName:(NSString*)userName;
- (id<NSFastEnumeration> /*WSCPasswordCredential*/)retrieveAll;
@end

#endif // __WSCPasswordVault_DEFINED__

// Windows.Foundation.Collections.IPropertySet
#ifndef __WFCIPropertySet_DEFINED__
#define __WFCIPropertySet_DEFINED__

@protocol WFCIPropertySet
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
@end

#endif // __WFCIPropertySet_DEFINED__

// Windows.Security.Credentials.PasswordCredentialPropertyStore
#ifndef __WSCPasswordCredentialPropertyStore_DEFINED__
#define __WSCPasswordCredentialPropertyStore_DEFINED__

WINRT_EXPORT
@interface WSCPasswordCredentialPropertyStore : RTObject <WFCIPropertySet>
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,System.Object>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
@end

#endif // __WSCPasswordCredentialPropertyStore_DEFINED__

// Windows.Security.Credentials.WebAccountProvider
#ifndef __WSCWebAccountProvider_DEFINED__
#define __WSCWebAccountProvider_DEFINED__

WINRT_EXPORT
@interface WSCWebAccountProvider : RTObject
+ (WSCWebAccountProvider*)createWebAccountProvider:(NSString*)id displayName:(NSString*)displayName iconUri:(WFUri*)iconUri ACTIVATOR;
@property (readonly) NSString* displayName;
@property (readonly) WFUri* iconUri;
@property (readonly) NSString* id;
@end

#endif // __WSCWebAccountProvider_DEFINED__

// Windows.Security.Credentials.WebAccount
#ifndef __WSCWebAccount_DEFINED__
#define __WSCWebAccount_DEFINED__

WINRT_EXPORT
@interface WSCWebAccount : RTObject
+ (WSCWebAccount*)createWebAccount:(WSCWebAccountProvider*)webAccountProvider
                          userName:(NSString*)userName
                             state:(WSCWebAccountState)state ACTIVATOR;
@property (readonly) WSCWebAccountState state;
@property (readonly) NSString* userName;
@property (readonly) WSCWebAccountProvider* webAccountProvider;
@end

#endif // __WSCWebAccount_DEFINED__
