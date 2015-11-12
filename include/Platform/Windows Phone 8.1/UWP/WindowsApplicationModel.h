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

// WindowsApplicationModel.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WASuspendingEventArgs, WASuspendingDeferral, WASuspendingOperation, WAPackageId, WAPackage, WADesignMode;
@class WAPackageVersion;
@protocol WAISuspendingDeferral
, WAISuspendingOperation, WAISuspendingEventArgs, WAIPackageId, WAIPackage, WAIPackage2, WAIPackageStatics, WAIDesignModeStatics;

#include "WindowsSystem.h"
#include "WindowsFoundation.h"
#include "WindowsStorage.h"
#include "WindowsFoundationCollections.h"

// [struct] Windows.ApplicationModel.PackageVersion
WINRT_EXPORT
@interface WAPackageVersion : NSObject
+ (instancetype) new;
@property unsigned short major;
@property unsigned short minor;
@property unsigned short build;
@property unsigned short revision;
@end

// Windows.ApplicationModel.ISuspendingDeferral
#ifndef __WAISuspendingDeferral_DEFINED__
#define __WAISuspendingDeferral_DEFINED__

@protocol WAISuspendingDeferral
- (void)complete;
@end

#endif // __WAISuspendingDeferral_DEFINED__

// Windows.ApplicationModel.ISuspendingOperation
#ifndef __WAISuspendingOperation_DEFINED__
#define __WAISuspendingOperation_DEFINED__

@protocol WAISuspendingOperation
@property (readonly) WFDateTime* deadline;
- (WASuspendingDeferral*)getDeferral;
@end

#endif // __WAISuspendingOperation_DEFINED__

// Windows.ApplicationModel.ISuspendingEventArgs
#ifndef __WAISuspendingEventArgs_DEFINED__
#define __WAISuspendingEventArgs_DEFINED__

@protocol WAISuspendingEventArgs
@property (readonly) WASuspendingOperation* suspendingOperation;
@end

#endif // __WAISuspendingEventArgs_DEFINED__

// Windows.ApplicationModel.SuspendingEventArgs
#ifndef __WASuspendingEventArgs_DEFINED__
#define __WASuspendingEventArgs_DEFINED__

WINRT_EXPORT
@interface WASuspendingEventArgs : RTObject <WAISuspendingEventArgs>
@property (readonly) WASuspendingOperation* suspendingOperation;
@end

#endif // __WASuspendingEventArgs_DEFINED__

// Windows.ApplicationModel.SuspendingDeferral
#ifndef __WASuspendingDeferral_DEFINED__
#define __WASuspendingDeferral_DEFINED__

WINRT_EXPORT
@interface WASuspendingDeferral : RTObject <WAISuspendingDeferral>
- (void)complete;
@end

#endif // __WASuspendingDeferral_DEFINED__

// Windows.ApplicationModel.SuspendingOperation
#ifndef __WASuspendingOperation_DEFINED__
#define __WASuspendingOperation_DEFINED__

WINRT_EXPORT
@interface WASuspendingOperation : RTObject <WAISuspendingOperation>
@property (readonly) WFDateTime* deadline;
- (WASuspendingDeferral*)getDeferral;
@end

#endif // __WASuspendingOperation_DEFINED__

// Windows.ApplicationModel.PackageId
#ifndef __WAPackageId_DEFINED__
#define __WAPackageId_DEFINED__

WINRT_EXPORT
@interface WAPackageId : RTObject
@property (readonly) WSProcessorArchitecture architecture;
@property (readonly) NSString* familyName;
@property (readonly) NSString* fullName;
@property (readonly) NSString* name;
@property (readonly) NSString* publisher;
@property (readonly) NSString* publisherId;
@property (readonly) NSString* resourceId;
@property (readonly) WAPackageVersion* version;
@end

#endif // __WAPackageId_DEFINED__

// Windows.ApplicationModel.Package
#ifndef __WAPackage_DEFINED__
#define __WAPackage_DEFINED__

WINRT_EXPORT
@interface WAPackage : RTObject
@property (readonly) id<NSFastEnumeration> /*WAPackage*/ dependencies;
@property (readonly) WAPackageId* id;
@property (readonly) WSStorageFolder* installedLocation;
@property (readonly) BOOL isFramework;
@property (readonly) NSString* description;
@property (readonly) NSString* displayName;
@property (readonly) BOOL isBundle;
@property (readonly) BOOL isDevelopmentMode;
@property (readonly) BOOL isResourcePackage;
@property (readonly) WFUri* logo;
@property (readonly) NSString* publisherDisplayName;
+ (WAPackage*)current;
@end

#endif // __WAPackage_DEFINED__

// Windows.ApplicationModel.DesignMode
#ifndef __WADesignMode_DEFINED__
#define __WADesignMode_DEFINED__

WINRT_EXPORT
@interface WADesignMode : RTObject
+ (BOOL)designModeEnabled;
@end

#endif // __WADesignMode_DEFINED__
