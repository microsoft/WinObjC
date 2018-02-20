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

// WindowsApplicationModelPreviewHolographic.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWHOLOGRAPHICEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWHOLOGRAPHICEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelPreviewHolographic.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAPHHolographicApplicationPreview;
@protocol WAPHIHolographicApplicationPreviewStatics;

#include "WindowsApplicationModelActivation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Preview.Holographic.HolographicApplicationPreview
#ifndef __WAPHHolographicApplicationPreview_DEFINED__
#define __WAPHHolographicApplicationPreview_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPREVIEWHOLOGRAPHICEXPORT
@interface WAPHHolographicApplicationPreview : RTObject
+ (BOOL)isCurrentViewPresentedOnHolographicDisplay;
+ (BOOL)isHolographicActivation:(RTObject<WAAIActivatedEventArgs>*)activatedEventArgs;
@end

#endif // __WAPHHolographicApplicationPreview_DEFINED__

