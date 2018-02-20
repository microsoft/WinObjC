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

// WindowsUICompositionEffects.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUICOMPOSITIONEFFECTSEXPORT
#define OBJCUWPWINDOWSUICOMPOSITIONEFFECTSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUICompositionEffects.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUCESceneLightingEffect;
@protocol WUCEISceneLightingEffect, WUCEISceneLightingEffect2;

// Windows.UI.Composition.Effects.SceneLightingEffectReflectanceModel
enum _WUCESceneLightingEffectReflectanceModel {
    WUCESceneLightingEffectReflectanceModelBlinnPhong = 0,
    WUCESceneLightingEffectReflectanceModelPhysicallyBasedBlinnPhong = 1,
};
typedef unsigned WUCESceneLightingEffectReflectanceModel;

#include "WindowsGraphicsEffects.h"

#import <Foundation/Foundation.h>

// Windows.Graphics.Effects.IGraphicsEffectSource
#ifndef __WGEIGraphicsEffectSource_DEFINED__
#define __WGEIGraphicsEffectSource_DEFINED__

@protocol WGEIGraphicsEffectSource
@end

OBJCUWPWINDOWSUICOMPOSITIONEFFECTSEXPORT
@interface WGEIGraphicsEffectSource : RTObject <WGEIGraphicsEffectSource>
@end

#endif // __WGEIGraphicsEffectSource_DEFINED__

// Windows.Graphics.Effects.IGraphicsEffect
#ifndef __WGEIGraphicsEffect_DEFINED__
#define __WGEIGraphicsEffect_DEFINED__

@protocol WGEIGraphicsEffect <WGEIGraphicsEffectSource>
@property (retain) NSString * name;
@end

OBJCUWPWINDOWSUICOMPOSITIONEFFECTSEXPORT
@interface WGEIGraphicsEffect : RTObject <WGEIGraphicsEffect>
@end

#endif // __WGEIGraphicsEffect_DEFINED__

// Windows.UI.Composition.Effects.SceneLightingEffect
#ifndef __WUCESceneLightingEffect_DEFINED__
#define __WUCESceneLightingEffect_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEFFECTSEXPORT
@interface WUCESceneLightingEffect : RTObject <WGEIGraphicsEffect, WGEIGraphicsEffectSource>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * name;
@property float specularShine;
@property float specularAmount;
@property (retain) RTObject<WGEIGraphicsEffectSource>* normalMapSource;
@property float diffuseAmount;
@property float ambientAmount;
@property WUCESceneLightingEffectReflectanceModel reflectanceModel;
@end

#endif // __WUCESceneLightingEffect_DEFINED__

