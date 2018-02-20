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

// WindowsDataHtml.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDATAHTMLEXPORT
#define OBJCUWPWINDOWSDATAHTMLEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDataHtml.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDHHtmlUtilities;
@protocol WDHIHtmlUtilities;

#import <Foundation/Foundation.h>

// Windows.Data.Html.HtmlUtilities
#ifndef __WDHHtmlUtilities_DEFINED__
#define __WDHHtmlUtilities_DEFINED__

OBJCUWPWINDOWSDATAHTMLEXPORT
@interface WDHHtmlUtilities : RTObject
+ (NSString *)convertToText:(NSString *)html;
@end

#endif // __WDHHtmlUtilities_DEFINED__

