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

// WindowsSystemDisplay.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSYSTEMDISPLAYEXPORT
#define OBJCUWPWINDOWSSYSTEMDISPLAYEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSystemDisplay.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSDDisplayRequest;
@protocol WSDIDisplayRequest;

#import <Foundation/Foundation.h>

// Windows.System.Display.DisplayRequest
#ifndef __WSDDisplayRequest_DEFINED__
#define __WSDDisplayRequest_DEFINED__

OBJCUWPWINDOWSSYSTEMDISPLAYEXPORT
@interface WSDDisplayRequest : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)requestActive;
- (void)requestRelease;
@end

#endif // __WSDDisplayRequest_DEFINED__

