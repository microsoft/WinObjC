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

// WindowsApplicationModelDataTransferShareTarget.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WADSQuickLink, WADSShareOperation;
@protocol WADSIQuickLink
, WADSIShareOperation, WADSIShareOperation2;

#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.DataTransfer.ShareTarget.QuickLink
#ifndef __WADSQuickLink_DEFINED__
#define __WADSQuickLink_DEFINED__

WINRT_EXPORT
@interface WADSQuickLink : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* title;
@property (copy) WSSRandomAccessStreamReference* thumbnail;
@property (copy) NSString* id;
@property (readonly) NSMutableArray* supportedDataFormats;
@property (readonly) NSMutableArray* supportedFileTypes;
@end

#endif // __WADSQuickLink_DEFINED__

// Windows.ApplicationModel.DataTransfer.ShareTarget.ShareOperation
#ifndef __WADSShareOperation_DEFINED__
#define __WADSShareOperation_DEFINED__

WINRT_EXPORT
@interface WADSShareOperation : RTObject
@property (readonly) WADDataPackageView* data;
@property (readonly) NSString* quickLinkId;
- (void)removeThisQuickLink;
- (void)reportStarted;
- (void)reportDataRetrieved;
- (void)reportSubmittedBackgroundTask;
- (void)reportCompletedWithQuickLink:(WADSQuickLink*)quicklink;
- (void)reportCompleted;
- (void)reportError:(NSString*)value;
- (void)dismissUI;
@end

#endif // __WADSShareOperation_DEFINED__
