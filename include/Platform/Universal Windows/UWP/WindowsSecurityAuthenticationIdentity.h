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

// WindowsSecurityAuthenticationIdentity.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_SECURITY_AUTHENTICATION_IDENTITY_EXPORT
#define OBJCUWP_WINDOWS_SECURITY_AUTHENTICATION_IDENTITY_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Security_Authentication_Identity.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSAIEnterpriseKeyCredentialRegistrationInfo, WSAIEnterpriseKeyCredentialRegistrationManager;
@protocol WSAIIEnterpriseKeyCredentialRegistrationInfo, WSAIIEnterpriseKeyCredentialRegistrationManagerStatics, WSAIIEnterpriseKeyCredentialRegistrationManager;

#import <Foundation/Foundation.h>

// Windows.Security.Authentication.Identity.EnterpriseKeyCredentialRegistrationInfo
#ifndef __WSAIEnterpriseKeyCredentialRegistrationInfo_DEFINED__
#define __WSAIEnterpriseKeyCredentialRegistrationInfo_DEFINED__

OBJCUWP_WINDOWS_SECURITY_AUTHENTICATION_IDENTITY_EXPORT
@interface WSAIEnterpriseKeyCredentialRegistrationInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString * keyId;
@property (readonly) NSString * keyName;
@property (readonly) NSString * subject;
@property (readonly) NSString * tenantId;
@property (readonly) NSString * tenantName;
@end

#endif // __WSAIEnterpriseKeyCredentialRegistrationInfo_DEFINED__

// Windows.Security.Authentication.Identity.EnterpriseKeyCredentialRegistrationManager
#ifndef __WSAIEnterpriseKeyCredentialRegistrationManager_DEFINED__
#define __WSAIEnterpriseKeyCredentialRegistrationManager_DEFINED__

OBJCUWP_WINDOWS_SECURITY_AUTHENTICATION_IDENTITY_EXPORT
@interface WSAIEnterpriseKeyCredentialRegistrationManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
+ (WSAIEnterpriseKeyCredentialRegistrationManager*)current;
- (void)getRegistrationsAsyncWithSuccess:(void (^)(NSArray* /* WSAIEnterpriseKeyCredentialRegistrationInfo* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSAIEnterpriseKeyCredentialRegistrationManager_DEFINED__

