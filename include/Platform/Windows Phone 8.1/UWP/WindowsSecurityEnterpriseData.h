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

// WindowsSecurityEnterpriseData.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSEFileRevocationManager;
@protocol WSEIFileRevocationManagerStatics;

// Windows.Security.EnterpriseData.FileProtectionStatus
enum _WSEFileProtectionStatus {
    WSEFileProtectionStatusUndetermined = 0,
    WSEFileProtectionStatusUnprotected = 1,
    WSEFileProtectionStatusRevoked = 2,
    WSEFileProtectionStatusProtected = 3,
    WSEFileProtectionStatusProtectedByOtherUser = 4,
    WSEFileProtectionStatusProtectedToOtherEnterprise = 5,
    WSEFileProtectionStatusNotProtectable = 6,
};
typedef unsigned WSEFileProtectionStatus;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"

// Windows.Security.EnterpriseData.FileRevocationManager
#ifndef __WSEFileRevocationManager_DEFINED__
#define __WSEFileRevocationManager_DEFINED__

WINRT_EXPORT
@interface WSEFileRevocationManager : RTObject
+ (void)protectAsync:(RTObject<WSIStorageItem>*)storageItem
  enterpriseIdentity:(NSString*)enterpriseIdentity
             success:(void (^)(WSEFileProtectionStatus))success
             failure:(void (^)(NSError*))failure;
+ (void)copyProtectionAsync:(RTObject<WSIStorageItem>*)sourceStorageItem
          targetStorageItem:(RTObject<WSIStorageItem>*)targetStorageItem
                    success:(void (^)(BOOL))success
                    failure:(void (^)(NSError*))failure;
+ (void)revoke:(NSString*)enterpriseIdentity;
+ (void)getStatusAsync:(RTObject<WSIStorageItem>*)storageItem
               success:(void (^)(WSEFileProtectionStatus))success
               failure:(void (^)(NSError*))failure;
@end

#endif // __WSEFileRevocationManager_DEFINED__
