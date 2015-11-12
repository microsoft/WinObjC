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

// WindowsMediaClosedCaptioning.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMCClosedCaptionProperties;
@protocol WMCIClosedCaptionPropertiesStatics;

// Windows.Media.ClosedCaptioning.ClosedCaptionStyle
enum _WMCClosedCaptionStyle {
    WMCClosedCaptionStyleDefault = 0,
    WMCClosedCaptionStyleMonospacedWithSerifs = 1,
    WMCClosedCaptionStyleProportionalWithSerifs = 2,
    WMCClosedCaptionStyleMonospacedWithoutSerifs = 3,
    WMCClosedCaptionStyleProportionalWithoutSerifs = 4,
    WMCClosedCaptionStyleCasual = 5,
    WMCClosedCaptionStyleCursive = 6,
    WMCClosedCaptionStyleSmallCapitals = 7,
};
typedef unsigned WMCClosedCaptionStyle;

// Windows.Media.ClosedCaptioning.ClosedCaptionEdgeEffect
enum _WMCClosedCaptionEdgeEffect {
    WMCClosedCaptionEdgeEffectDefault = 0,
    WMCClosedCaptionEdgeEffectNone = 1,
    WMCClosedCaptionEdgeEffectRaised = 2,
    WMCClosedCaptionEdgeEffectDepressed = 3,
    WMCClosedCaptionEdgeEffectUniform = 4,
    WMCClosedCaptionEdgeEffectDropShadow = 5,
};
typedef unsigned WMCClosedCaptionEdgeEffect;

// Windows.Media.ClosedCaptioning.ClosedCaptionOpacity
enum _WMCClosedCaptionOpacity {
    WMCClosedCaptionOpacityDefault = 0,
    WMCClosedCaptionOpacityOneHundredPercent = 1,
    WMCClosedCaptionOpacitySeventyFivePercent = 2,
    WMCClosedCaptionOpacityTwentyFivePercent = 3,
    WMCClosedCaptionOpacityZeroPercent = 4,
};
typedef unsigned WMCClosedCaptionOpacity;

// Windows.Media.ClosedCaptioning.ClosedCaptionColor
enum _WMCClosedCaptionColor {
    WMCClosedCaptionColorDefault = 0,
    WMCClosedCaptionColorWhite = 1,
    WMCClosedCaptionColorBlack = 2,
    WMCClosedCaptionColorRed = 3,
    WMCClosedCaptionColorGreen = 4,
    WMCClosedCaptionColorBlue = 5,
    WMCClosedCaptionColorYellow = 6,
    WMCClosedCaptionColorMagenta = 7,
    WMCClosedCaptionColorCyan = 8,
};
typedef unsigned WMCClosedCaptionColor;

// Windows.Media.ClosedCaptioning.ClosedCaptionSize
enum _WMCClosedCaptionSize {
    WMCClosedCaptionSizeDefault = 0,
    WMCClosedCaptionSizeFiftyPercent = 1,
    WMCClosedCaptionSizeOneHundredPercent = 2,
    WMCClosedCaptionSizeOneHundredFiftyPercent = 3,
    WMCClosedCaptionSizeTwoHundredPercent = 4,
};
typedef unsigned WMCClosedCaptionSize;

#include "WindowsUI.h"

#import <Foundation/Foundation.h>

// Windows.Media.ClosedCaptioning.ClosedCaptionProperties
#ifndef __WMCClosedCaptionProperties_DEFINED__
#define __WMCClosedCaptionProperties_DEFINED__

WINRT_EXPORT
@interface WMCClosedCaptionProperties : RTObject
+ (WMCClosedCaptionColor)backgroundColor;
+ (WMCClosedCaptionOpacity)backgroundOpacity;
+ (WUColor*)computedBackgroundColor;
+ (WUColor*)computedFontColor;
+ (WUColor*)computedRegionColor;
+ (WMCClosedCaptionColor)fontColor;
+ (WMCClosedCaptionEdgeEffect)fontEffect;
+ (WMCClosedCaptionOpacity)fontOpacity;
+ (WMCClosedCaptionSize)fontSize;
+ (WMCClosedCaptionStyle)fontStyle;
+ (WMCClosedCaptionColor)regionColor;
+ (WMCClosedCaptionOpacity)regionOpacity;
@end

#endif // __WMCClosedCaptionProperties_DEFINED__
