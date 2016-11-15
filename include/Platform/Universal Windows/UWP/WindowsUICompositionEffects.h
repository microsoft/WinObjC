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

// WindowsUICompositionEffects.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_UI_COMPOSITION_EFFECTS_EXPORT
#define OBJCUWP_WINDOWS_UI_COMPOSITION_EFFECTS_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_UI_Composition_Effects.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUCESceneLightingEffect;
@protocol WUCEISceneLightingEffect;

#include "WindowsGraphicsEffects.h"

#import <Foundation/Foundation.h>

// Windows.Graphics.Effects.IGraphicsEffectSource
#ifndef __WGEIGraphicsEffectSource_DEFINED__
#define __WGEIGraphicsEffectSource_DEFINED__

@protocol WGEIGraphicsEffectSource
@end

OBJCUWP_WINDOWS_UI_COMPOSITION_EFFECTS_EXPORT
@interface WGEIGraphicsEffectSource : RTObject <WGEIGraphicsEffectSource>
@end

#endif // __WGEIGraphicsEffectSource_DEFINED__

// Windows.Graphics.Effects.IGraphicsEffect
#ifndef __WGEIGraphicsEffect_DEFINED__
#define __WGEIGraphicsEffect_DEFINED__

@protocol WGEIGraphicsEffect <WGEIGraphicsEffectSource>
@property (retain) NSString * name;
@end

OBJCUWP_WINDOWS_UI_COMPOSITION_EFFECTS_EXPORT
@interface WGEIGraphicsEffect : RTObject <WGEIGraphicsEffect>
@end

#endif // __WGEIGraphicsEffect_DEFINED__

// Windows.UI.Composition.Effects.SceneLightingEffect
#ifndef __WUCESceneLightingEffect_DEFINED__
#define __WUCESceneLightingEffect_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EFFECTS_EXPORT
@interface WUCESceneLightingEffect : RTObject <WGEIGraphicsEffect, WGEIGraphicsEffectSource>
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) NSString * name;
@property float specularShine;
@property float specularAmount;
@property (retain) RTObject<WGEIGraphicsEffectSource>* normalMapSource;
@property float diffuseAmount;
@property float ambientAmount;
@end

#endif // __WUCESceneLightingEffect_DEFINED__

