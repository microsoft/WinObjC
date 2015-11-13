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

// WindowsUI.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUColorHelper, WUColors;
@class WUColor;
@protocol WUIColorHelper
, WUIColorHelperStatics, WUIColors, WUIColorsStatics;

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Color
WINRT_EXPORT
@interface WUColor : NSObject
+ (instancetype) new;
@property uint8_t a;
@property uint8_t r;
@property uint8_t g;
@property uint8_t b;
@end

// Windows.UI.ColorHelper
#ifndef __WUColorHelper_DEFINED__
#define __WUColorHelper_DEFINED__

WINRT_EXPORT
@interface WUColorHelper : RTObject
+ (WUColor*)fromArgb:(uint8_t)a r:(uint8_t)r g:(uint8_t)g b:(uint8_t)b;
@end

#endif // __WUColorHelper_DEFINED__

// Windows.UI.Colors
#ifndef __WUColors_DEFINED__
#define __WUColors_DEFINED__

WINRT_EXPORT
@interface WUColors : RTObject
+ (WUColor*)aliceBlue;
+ (WUColor*)antiqueWhite;
+ (WUColor*)aqua;
+ (WUColor*)aquamarine;
+ (WUColor*)azure;
+ (WUColor*)beige;
+ (WUColor*)bisque;
+ (WUColor*)black;
+ (WUColor*)blanchedAlmond;
+ (WUColor*)blue;
+ (WUColor*)blueViolet;
+ (WUColor*)brown;
+ (WUColor*)burlyWood;
+ (WUColor*)cadetBlue;
+ (WUColor*)chartreuse;
+ (WUColor*)chocolate;
+ (WUColor*)coral;
+ (WUColor*)cornflowerBlue;
+ (WUColor*)cornsilk;
+ (WUColor*)crimson;
+ (WUColor*)cyan;
+ (WUColor*)darkBlue;
+ (WUColor*)darkCyan;
+ (WUColor*)darkGoldenrod;
+ (WUColor*)darkGray;
+ (WUColor*)darkGreen;
+ (WUColor*)darkKhaki;
+ (WUColor*)darkMagenta;
+ (WUColor*)darkOliveGreen;
+ (WUColor*)darkOrange;
+ (WUColor*)darkOrchid;
+ (WUColor*)darkRed;
+ (WUColor*)darkSalmon;
+ (WUColor*)darkSeaGreen;
+ (WUColor*)darkSlateBlue;
+ (WUColor*)darkSlateGray;
+ (WUColor*)darkTurquoise;
+ (WUColor*)darkViolet;
+ (WUColor*)deepPink;
+ (WUColor*)deepSkyBlue;
+ (WUColor*)dimGray;
+ (WUColor*)dodgerBlue;
+ (WUColor*)firebrick;
+ (WUColor*)floralWhite;
+ (WUColor*)forestGreen;
+ (WUColor*)fuchsia;
+ (WUColor*)gainsboro;
+ (WUColor*)ghostWhite;
+ (WUColor*)gold;
+ (WUColor*)goldenrod;
+ (WUColor*)gray;
+ (WUColor*)green;
+ (WUColor*)greenYellow;
+ (WUColor*)honeydew;
+ (WUColor*)hotPink;
+ (WUColor*)indianRed;
+ (WUColor*)indigo;
+ (WUColor*)ivory;
+ (WUColor*)khaki;
+ (WUColor*)lavender;
+ (WUColor*)lavenderBlush;
+ (WUColor*)lawnGreen;
+ (WUColor*)lemonChiffon;
+ (WUColor*)lightBlue;
+ (WUColor*)lightCoral;
+ (WUColor*)lightCyan;
+ (WUColor*)lightGoldenrodYellow;
+ (WUColor*)lightGray;
+ (WUColor*)lightGreen;
+ (WUColor*)lightPink;
+ (WUColor*)lightSalmon;
+ (WUColor*)lightSeaGreen;
+ (WUColor*)lightSkyBlue;
+ (WUColor*)lightSlateGray;
+ (WUColor*)lightSteelBlue;
+ (WUColor*)lightYellow;
+ (WUColor*)lime;
+ (WUColor*)limeGreen;
+ (WUColor*)linen;
+ (WUColor*)magenta;
+ (WUColor*)maroon;
+ (WUColor*)mediumAquamarine;
+ (WUColor*)mediumBlue;
+ (WUColor*)mediumOrchid;
+ (WUColor*)mediumPurple;
+ (WUColor*)mediumSeaGreen;
+ (WUColor*)mediumSlateBlue;
+ (WUColor*)mediumSpringGreen;
+ (WUColor*)mediumTurquoise;
+ (WUColor*)mediumVioletRed;
+ (WUColor*)midnightBlue;
+ (WUColor*)mintCream;
+ (WUColor*)mistyRose;
+ (WUColor*)moccasin;
+ (WUColor*)navajoWhite;
+ (WUColor*)navy;
+ (WUColor*)oldLace;
+ (WUColor*)olive;
+ (WUColor*)oliveDrab;
+ (WUColor*)orange;
+ (WUColor*)orangeRed;
+ (WUColor*)orchid;
+ (WUColor*)paleGoldenrod;
+ (WUColor*)paleGreen;
+ (WUColor*)paleTurquoise;
+ (WUColor*)paleVioletRed;
+ (WUColor*)papayaWhip;
+ (WUColor*)peachPuff;
+ (WUColor*)peru;
+ (WUColor*)pink;
+ (WUColor*)plum;
+ (WUColor*)powderBlue;
+ (WUColor*)purple;
+ (WUColor*)red;
+ (WUColor*)rosyBrown;
+ (WUColor*)royalBlue;
+ (WUColor*)saddleBrown;
+ (WUColor*)salmon;
+ (WUColor*)sandyBrown;
+ (WUColor*)seaGreen;
+ (WUColor*)seaShell;
+ (WUColor*)sienna;
+ (WUColor*)silver;
+ (WUColor*)skyBlue;
+ (WUColor*)slateBlue;
+ (WUColor*)slateGray;
+ (WUColor*)snow;
+ (WUColor*)springGreen;
+ (WUColor*)steelBlue;
+ (WUColor*)tan;
+ (WUColor*)teal;
+ (WUColor*)thistle;
+ (WUColor*)tomato;
+ (WUColor*)transparent;
+ (WUColor*)turquoise;
+ (WUColor*)violet;
+ (WUColor*)wheat;
+ (WUColor*)white;
+ (WUColor*)whiteSmoke;
+ (WUColor*)yellow;
+ (WUColor*)yellowGreen;
@end

#endif // __WUColors_DEFINED__
