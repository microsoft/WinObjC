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

// WindowsManagementPolicies.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMANAGEMENTPOLICIESEXPORT
#define OBJCUWPWINDOWSMANAGEMENTPOLICIESEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsManagementPolicies.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMPNamedPolicyData, WMPNamedPolicy;
@protocol WMPINamedPolicyData, WMPINamedPolicyStatics;

// Windows.Management.Policies.NamedPolicyKind
enum _WMPNamedPolicyKind {
    WMPNamedPolicyKindInvalid = 0,
    WMPNamedPolicyKindBinary = 1,
    WMPNamedPolicyKindBoolean = 2,
    WMPNamedPolicyKindInt32 = 3,
    WMPNamedPolicyKindInt64 = 4,
    WMPNamedPolicyKindString = 5,
};
typedef unsigned WMPNamedPolicyKind;

#include "WindowsFoundation.h"
#include "WindowsSystem.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Management.Policies.NamedPolicyData
#ifndef __WMPNamedPolicyData_DEFINED__
#define __WMPNamedPolicyData_DEFINED__

OBJCUWPWINDOWSMANAGEMENTPOLICIESEXPORT
@interface WMPNamedPolicyData : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * area;
@property (readonly) BOOL isManaged;
@property (readonly) BOOL isUserPolicy;
@property (readonly) WMPNamedPolicyKind kind;
@property (readonly) NSString * name;
@property (readonly) WSUser* user;
- (EventRegistrationToken)addChangedEvent:(void(^)(WMPNamedPolicyData*, RTObject*))del;
- (void)removeChangedEvent:(EventRegistrationToken)tok;
- (BOOL)getBoolean;
- (RTObject<WSSIBuffer>*)getBinary;
- (int)getInt32;
- (int64_t)getInt64;
- (NSString *)getString;
@end

#endif // __WMPNamedPolicyData_DEFINED__

// Windows.Management.Policies.NamedPolicy
#ifndef __WMPNamedPolicy_DEFINED__
#define __WMPNamedPolicy_DEFINED__

OBJCUWPWINDOWSMANAGEMENTPOLICIESEXPORT
@interface WMPNamedPolicy : RTObject
+ (WMPNamedPolicyData*)getPolicyFromPath:(NSString *)area name:(NSString *)name;
+ (WMPNamedPolicyData*)getPolicyFromPathForUser:(WSUser*)user area:(NSString *)area name:(NSString *)name;
@end

#endif // __WMPNamedPolicy_DEFINED__

