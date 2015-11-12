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

// WindowsManagementCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMCApplicationDataManager;
@protocol WMCIApplicationDataManagerStatics
, WMCIApplicationDataManager;

#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.Management.Core.ApplicationDataManager
#ifndef __WMCApplicationDataManager_DEFINED__
#define __WMCApplicationDataManager_DEFINED__

WINRT_EXPORT
@interface WMCApplicationDataManager : RTObject
+ (WSApplicationData*)createForPackageFamily:(NSString*)packageFamilyName;
@end

#endif // __WMCApplicationDataManager_DEFINED__
