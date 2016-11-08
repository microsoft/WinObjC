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

// WindowsPhoneSpeechRecognition.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_PHONE_SPEECH_RECOGNITION_EXPORT
#define OBJCUWP_WINDOWS_PHONE_SPEECH_RECOGNITION_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Phone_Speech_Recognition.lib")
#endif
#endif
#include <UWP/interopBase.h>

// Windows.Phone.Speech.Recognition.SpeechRecognitionUIStatus
enum _WPSRSpeechRecognitionUIStatus {
    WPSRSpeechRecognitionUIStatusSucceeded = 0,
    WPSRSpeechRecognitionUIStatusBusy = 1,
    WPSRSpeechRecognitionUIStatusCancelled = 2,
    WPSRSpeechRecognitionUIStatusPreempted = 3,
    WPSRSpeechRecognitionUIStatusPrivacyPolicyDeclined = 4,
};
typedef unsigned WPSRSpeechRecognitionUIStatus;

#import <Foundation/Foundation.h>

