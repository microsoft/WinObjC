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

// WindowsApplicationModelPreviewInkWorkspace.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWINKWORKSPACEEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWINKWORKSPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelPreviewInkWorkspace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAPIInkWorkspaceHostedAppManager;
@protocol WAPIIInkWorkspaceHostedAppManager, WAPIIInkWorkspaceHostedAppManagerStatics;

#include "WindowsGraphicsImaging.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Preview.InkWorkspace.InkWorkspaceHostedAppManager
#ifndef __WAPIInkWorkspaceHostedAppManager_DEFINED__
#define __WAPIInkWorkspaceHostedAppManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWINKWORKSPACEEXPORT
@interface WAPIInkWorkspaceHostedAppManager : RTObject
+ (WAPIInkWorkspaceHostedAppManager*)getForCurrentApp;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (RTObject<WFIAsyncAction>*)setThumbnailAsync:(WGISoftwareBitmap*)bitmap;
@end

#endif // __WAPIInkWorkspaceHostedAppManager_DEFINED__

