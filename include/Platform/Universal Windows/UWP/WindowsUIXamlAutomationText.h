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

// WindowsUIXamlAutomationText.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_UI_XAML_AUTOMATION_TEXT_EXPORT
#define OBJCUWP_WINDOWS_UI_XAML_AUTOMATION_TEXT_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_UI_Xaml_Automation_Text.lib")
#endif
#endif
#include <UWP/interopBase.h>

// Windows.UI.Xaml.Automation.Text.TextPatternRangeEndpoint
enum _WUXATTextPatternRangeEndpoint {
    WUXATTextPatternRangeEndpointStart = 0,
    WUXATTextPatternRangeEndpointEnd = 1,
};
typedef unsigned WUXATTextPatternRangeEndpoint;

// Windows.UI.Xaml.Automation.Text.TextUnit
enum _WUXATTextUnit {
    WUXATTextUnitCharacter = 0,
    WUXATTextUnitFormat = 1,
    WUXATTextUnitWord = 2,
    WUXATTextUnitLine = 3,
    WUXATTextUnitParagraph = 4,
    WUXATTextUnitPage = 5,
    WUXATTextUnitDocument = 6,
};
typedef unsigned WUXATTextUnit;

#import <Foundation/Foundation.h>
