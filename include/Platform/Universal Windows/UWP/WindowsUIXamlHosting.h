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

// WindowsUIXamlHosting.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_UI_XAML_HOSTING_EXPORT
#define OBJCUWP_WINDOWS_UI_XAML_HOSTING_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_UI_Xaml_Hosting.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUXHElementCompositionPreview;
@protocol WUXHIElementCompositionPreview
, WUXHIElementCompositionPreviewStatics;

#include "WindowsUIXaml.h"

#import <Foundation/Foundation.h>

// Windows.UI.Xaml.Hosting.ElementCompositionPreview
#ifndef __WUXHElementCompositionPreview_DEFINED__
#define __WUXHElementCompositionPreview_DEFINED__

OBJCUWP_WINDOWS_UI_XAML_HOSTING_EXPORT
@interface WUXHElementCompositionPreview : RTObject
+ (RTObject*)getContainerVisual:(WXUIElement*)element;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@end

#endif // __WUXHElementCompositionPreview_DEFINED__
