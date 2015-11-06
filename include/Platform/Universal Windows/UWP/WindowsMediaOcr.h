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

#include "interopBase.h"
@class WMOOcrWord, WMOOcrLine, WMOOcrResult, WMOOcrEngine;
@protocol WMOIOcrWord
, WMOIOcrLine, WMOIOcrResult, WMOIOcrEngine, WMOIOcrEngineStatics;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsGlobalization.h"

#import <Foundation/Foundation.h>

// Windows.Media.Ocr.OcrWord
#ifndef __WMOOcrWord_DEFINED__
#define __WMOOcrWord_DEFINED__

WINRT_EXPORT
@interface WMOOcrWord : RTObject
@property (readonly) WFRect* boundingRect;
@property (readonly) NSString* text;
@end

#endif // __WMOOcrWord_DEFINED__

// Windows.Media.Ocr.OcrLine
#ifndef __WMOOcrLine_DEFINED__
#define __WMOOcrLine_DEFINED__

WINRT_EXPORT
@interface WMOOcrLine : RTObject
@property (readonly) NSString* text;
@property (readonly) NSArray* words;
@end

#endif // __WMOOcrLine_DEFINED__

// Windows.Media.Ocr.OcrResult
#ifndef __WMOOcrResult_DEFINED__
#define __WMOOcrResult_DEFINED__

WINRT_EXPORT
@interface WMOOcrResult : RTObject
@property (readonly) NSArray* lines;
@property (readonly) NSString* text;
@property (readonly) id textAngle;
@end

#endif // __WMOOcrResult_DEFINED__

// Windows.Media.Ocr.OcrEngine
#ifndef __WMOOcrEngine_DEFINED__
#define __WMOOcrEngine_DEFINED__

WINRT_EXPORT
@interface WMOOcrEngine : RTObject
+ (BOOL)isLanguageSupported:(WGLanguage*)language;
+ (WMOOcrEngine*)tryCreateFromLanguage:(WGLanguage*)language;
+ (WMOOcrEngine*)tryCreateFromUserProfileLanguages;
@property (readonly) WGLanguage* recognizerLanguage;
+ (NSArray*)availableRecognizerLanguages;
+ (unsigned int)maxImageDimension;
- (void)recognizeAsync:(WGISoftwareBitmap*)bitmap success:(void (^)(WMOOcrResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMOOcrEngine_DEFINED__
