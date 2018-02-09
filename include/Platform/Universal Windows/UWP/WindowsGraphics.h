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

// WindowsGraphics.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGRAPHICSEXPORT
#define OBJCUWPWINDOWSGRAPHICSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGraphics.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGPointInt32, WGSizeInt32, WGRectInt32;

#import <Foundation/Foundation.h>

// [struct] Windows.Graphics.PointInt32
OBJCUWPWINDOWSGRAPHICSEXPORT
@interface WGPointInt32 : NSObject
+ (instancetype)new;
@property int x;
@property int y;
@end

// [struct] Windows.Graphics.SizeInt32
OBJCUWPWINDOWSGRAPHICSEXPORT
@interface WGSizeInt32 : NSObject
+ (instancetype)new;
@property int width;
@property int height;
@end

// [struct] Windows.Graphics.RectInt32
OBJCUWPWINDOWSGRAPHICSEXPORT
@interface WGRectInt32 : NSObject
+ (instancetype)new;
@property int x;
@property int y;
@property int width;
@property int height;
@end

