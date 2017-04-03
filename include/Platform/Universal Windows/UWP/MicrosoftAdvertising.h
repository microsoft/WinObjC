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

// MicrosoftAdvertising.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPMICROSOFTADVERTISINGEXPORT
#define OBJCUWPMICROSOFTADVERTISINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_MSAds_BUILD
#pragma comment(lib, "ObjCUWPMicrosoftAdvertising.lib")
#endif
#endif
#include <UWP/interopBase.h>

// Microsoft.Advertising.ErrorCode
enum _MAErrorCode {
    MAErrorCodeUnknown = 0,
    MAErrorCodeNoAdAvailable = 1,
    MAErrorCodeNetworkConnectionFailure = 2,
    MAErrorCodeClientConfiguration = 3,
    MAErrorCodeServerSideError = 4,
    MAErrorCodeInvalidServerResponse = 5,
    MAErrorCodeOther = 6,
    MAErrorCodeRefreshNotAllowed = 7,
    MAErrorCodeCreativeError = 8,
    MAErrorCodeMraidOperationFailure = 9,
    MAErrorCodeSuccess = 10,
    MAErrorCodeCancelled = 11,
    MAErrorCodeFileOperationFailure = 12,
    MAErrorCodeParseToBOMFailure = 13,
    MAErrorCodeValidationFailure = 14,
};
typedef unsigned MAErrorCode;

#import <Foundation/Foundation.h>

