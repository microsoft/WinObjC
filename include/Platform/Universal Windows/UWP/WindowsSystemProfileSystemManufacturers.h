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

// WindowsSystemProfileSystemManufacturers.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSYSTEMPROFILESYSTEMMANUFACTURERSEXPORT
#define OBJCUWPWINDOWSSYSTEMPROFILESYSTEMMANUFACTURERSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSystemProfileSystemManufacturers.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSPSOemSupportInfo, WSPSSystemSupportInfo, WSPSSmbiosInformation;
@protocol WSPSIOemSupportInfo, WSPSISystemSupportInfoStatics, WSPSISmbiosInformationStatics;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.System.Profile.SystemManufacturers.OemSupportInfo
#ifndef __WSPSOemSupportInfo_DEFINED__
#define __WSPSOemSupportInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILESYSTEMMANUFACTURERSEXPORT
@interface WSPSOemSupportInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFUri* supportAppLink;
@property (readonly) WFUri* supportLink;
@property (readonly) NSString * supportProvider;
@end

#endif // __WSPSOemSupportInfo_DEFINED__

// Windows.System.Profile.SystemManufacturers.SystemSupportInfo
#ifndef __WSPSSystemSupportInfo_DEFINED__
#define __WSPSSystemSupportInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILESYSTEMMANUFACTURERSEXPORT
@interface WSPSSystemSupportInfo : RTObject
+ (NSString *)localSystemEdition;
+ (WSPSOemSupportInfo*)oemSupportInfo;
@end

#endif // __WSPSSystemSupportInfo_DEFINED__

// Windows.System.Profile.SystemManufacturers.SmbiosInformation
#ifndef __WSPSSmbiosInformation_DEFINED__
#define __WSPSSmbiosInformation_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILESYSTEMMANUFACTURERSEXPORT
@interface WSPSSmbiosInformation : RTObject
+ (NSString *)serialNumber;
@end

#endif // __WSPSSmbiosInformation_DEFINED__

