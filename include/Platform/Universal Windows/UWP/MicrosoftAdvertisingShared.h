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

// MicrosoftAdvertisingShared.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPMICROSOFTADVERTISINGEXPORT
#define OBJCUWPMICROSOFTADVERTISINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_MSAds_BUILD
#pragma comment(lib, "ObjCUWPMicrosoftAdvertising.lib")
#endif
#endif
#include <UWP/interopBase.h>

// Microsoft.Advertising.Shared.AdType
enum _MASAdType {
    MASAdTypeUnknown = 0,
    MASAdTypeUniversalAd = 1,
    MASAdTypeVASTAd = 2,
    MASAdTypeAll = 3,
};
typedef unsigned MASAdType;

// Microsoft.Advertising.Shared.SdkPlatform
enum _MASSdkPlatform {
    MASSdkPlatformUnknown = 0,
    MASSdkPlatformWindows = 1,
    MASSdkPlatformWindowsPhone = 2,
    MASSdkPlatformOthers = 3,
};
typedef unsigned MASSdkPlatform;

#import <Foundation/Foundation.h>

