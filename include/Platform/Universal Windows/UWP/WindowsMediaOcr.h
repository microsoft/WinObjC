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

// WindowsMediaOcr.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_MEDIA_OCR_EXPORT
#define OBJCUWP_WINDOWS_MEDIA_OCR_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Media_Ocr.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMOOcrWord, WMOOcrLine, WMOOcrResult, WMOOcrEngine;
@protocol WMOIOcrWord
, WMOIOcrLine, WMOIOcrResult, WMOIOcrEngine, WMOIOcrEngineStatics;

#include "WindowsFoundation.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsGlobalization.h"

#import <Foundation/Foundation.h>

// Windows.Media.Ocr.OcrWord
#ifndef __WMOOcrWord_DEFINED__
#define __WMOOcrWord_DEFINED__

OBJCUWP_WINDOWS_MEDIA_OCR_EXPORT
@interface WMOOcrWord : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WFRect* boundingRect;
@property (readonly) NSString* text;
@end

#endif // __WMOOcrWord_DEFINED__

// Windows.Media.Ocr.OcrLine
#ifndef __WMOOcrLine_DEFINED__
#define __WMOOcrLine_DEFINED__

OBJCUWP_WINDOWS_MEDIA_OCR_EXPORT
@interface WMOOcrLine : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString* text;
@property (readonly) NSArray* /* WMOOcrWord* */ words;
@end

#endif // __WMOOcrLine_DEFINED__

// Windows.Media.Ocr.OcrResult
#ifndef __WMOOcrResult_DEFINED__
#define __WMOOcrResult_DEFINED__

OBJCUWP_WINDOWS_MEDIA_OCR_EXPORT
@interface WMOOcrResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* WMOOcrLine* */ lines;
@property (readonly) NSString* text;
@property (readonly) id /* double */ textAngle;
@end

#endif // __WMOOcrResult_DEFINED__

// Windows.Media.Ocr.OcrEngine
#ifndef __WMOOcrEngine_DEFINED__
#define __WMOOcrEngine_DEFINED__

OBJCUWP_WINDOWS_MEDIA_OCR_EXPORT
@interface WMOOcrEngine : RTObject
+ (BOOL)isLanguageSupported:(WGLanguage*)language;
+ (WMOOcrEngine*)tryCreateFromLanguage:(WGLanguage*)language;
+ (WMOOcrEngine*)tryCreateFromUserProfileLanguages;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WGLanguage* recognizerLanguage;
+ (NSArray* /* WGLanguage* */)availableRecognizerLanguages;
+ (unsigned int)maxImageDimension;
- (void)recognizeAsync:(WGISoftwareBitmap*)bitmap success:(void (^)(WMOOcrResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMOOcrEngine_DEFINED__
