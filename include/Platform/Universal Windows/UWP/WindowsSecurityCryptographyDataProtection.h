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

// WindowsSecurityCryptographyDataProtection.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_SECURITY_CRYPTOGRAPHY_DATAPROTECTION_EXPORT
#define OBJCUWP_WINDOWS_SECURITY_CRYPTOGRAPHY_DATAPROTECTION_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Security_Cryptography_DataProtection.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSCDDataProtectionProvider;
@protocol WSCDIDataProtectionProvider
, WSCDIDataProtectionProviderFactory;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Security.Cryptography.DataProtection.DataProtectionProvider
#ifndef __WSCDDataProtectionProvider_DEFINED__
#define __WSCDDataProtectionProvider_DEFINED__

OBJCUWP_WINDOWS_SECURITY_CRYPTOGRAPHY_DATAPROTECTION_EXPORT
@interface WSCDDataProtectionProvider : RTObject
+ (instancetype)make ACTIVATOR;
+ (WSCDDataProtectionProvider*)makeOverloadExplicit:(NSString*)protectionDescriptor ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)protectAsync:(RTObject<WSSIBuffer>*)data success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (void)unprotectAsync:(RTObject<WSSIBuffer>*)data success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)protectStreamAsync:(RTObject<WSSIInputStream>*)src dest:(RTObject<WSSIOutputStream>*)dest;
- (RTObject<WFIAsyncAction>*)unprotectStreamAsync:(RTObject<WSSIInputStream>*)src dest:(RTObject<WSSIOutputStream>*)dest;
@end

#endif // __WSCDDataProtectionProvider_DEFINED__
