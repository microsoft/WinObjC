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

// WindowsApplicationModelDataTransferShareTarget.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WADSQuickLink, WADSShareOperation;
@protocol WADSIQuickLink, WADSIShareOperation, WADSIShareOperation2, WADSIShareOperation3;

#include "WindowsApplicationModelContacts.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.DataTransfer.ShareTarget.QuickLink
#ifndef __WADSQuickLink_DEFINED__
#define __WADSQuickLink_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WADSQuickLink : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (retain) WSSRandomAccessStreamReference* thumbnail;
@property (retain) NSString * id;
@property (readonly) NSMutableArray* /* NSString * */ supportedDataFormats;
@property (readonly) NSMutableArray* /* NSString * */ supportedFileTypes;
@end

#endif // __WADSQuickLink_DEFINED__

// Windows.ApplicationModel.DataTransfer.ShareTarget.ShareOperation
#ifndef __WADSShareOperation_DEFINED__
#define __WADSShareOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WADSShareOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WADDataPackageView* data;
@property (readonly) NSString * quickLinkId;
@property (readonly) NSArray* /* WACContact* */ contacts;
- (void)removeThisQuickLink;
- (void)reportStarted;
- (void)reportDataRetrieved;
- (void)reportSubmittedBackgroundTask;
- (void)reportCompletedWithQuickLink:(WADSQuickLink*)quicklink;
- (void)reportCompleted;
- (void)reportError:(NSString *)value;
- (void)dismissUI;
@end

#endif // __WADSShareOperation_DEFINED__

