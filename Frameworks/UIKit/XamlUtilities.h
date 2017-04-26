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
#pragma once

#import <Starboard.h>

#import "StringHelpers.h"

#import <UIKit/UIControl.h>
#import <UIKit/UITextField.h>
#import <UIKit/UITextInputTraits.h>
#import <UIKit/UIFont.h>

#include "COMIncludes.h"
#import "winrt/Windows.UI.Xaml.h"
#import "winrt/Windows.UI.Xaml.Controls.h"
#import "winrt/Windows.UI.Xaml.Media.h"
#import "winrt/Windows.UI.Xaml.Media.Imaging.h"
#import "winrt/Windows.UI.Xaml.Input.h"
#import "winrt/Windows.UI.Input.h"
#include "COMIncludes_End.h"

// NOTE: These need to stay #includes
#include "COMIncludes.h"
#include "WinString.h"
#include "RoApi.h"
#include "Windows.UI.Xaml.Markup.h"
#include "COMIncludes_End.h"

namespace XamlUtilities {
NSString* const XamlAutoGenNamespace = @"IslandwoodAutoGenNamespace";

winrt::Windows::UI::Xaml::Media::FontFamily WUXFontFamilyFromUIFontName(NSString* uiFontName);

// Convert UIColor to Color on windows
winrt::Windows::UI::Color ConvertUIColorToWUColor(UIColor* uiColor);

// Convert windows color to UIColor
UIColor* ConvertWUColorToUIColor(const winrt::Windows::UI::Color& wuColor);

// Convert UIImage to WUXMImageBrush on windows
winrt::Windows::UI::Xaml::Media::ImageBrush ConvertUIImageToWUXMImageBrush(UIImage* image);

// Convert UIImage to WUXMIBitmapSource on windows
winrt::Windows::UI::Xaml::Media::Imaging::BitmapSource ConvertUIImageToWUXMIBitmapSource(UIImage* image);

// Convert UITextAlignment to TextAlignment on windows
winrt::Windows::UI::Xaml::TextAlignment ConvertUITextAlignmentToWXTextAlignment(UITextAlignment alignment);

// Convert TextAlignment to UITextAlignment
UITextAlignment ConvertWXTextAlignmentToUITextAlignment(winrt::Windows::UI::Xaml::TextAlignment alignment);

// Convert ios KeyboardType to Windows InputScope
winrt::Windows::UI::Xaml::Input::InputScopeNameValue ConvertKeyboardTypeToInputScopeNameValue(UIKeyboardType keyboardType,
                                                                                              BOOL secureTextMode);

// Convert UIControlContentVerticalAlignment to Windows vertical Alignment
winrt::Windows::UI::Xaml::VerticalAlignment ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(
    UIControlContentVerticalAlignment alignment);

// Find the named template child in control template of a xaml control
winrt::Windows::UI::Xaml::FrameworkElement FindTemplateChild(const winrt::Windows::UI::Xaml::Controls::Control& control, NSString* name);

// Passing a string between ObjC and WRL requires encasing an NSString within a WFPropertyValue/WFIPropertyValue
// BUGBUG:8791977 - WFIPropertyValue is not publicly exposed via projections so we used a workaround
NSString* NSStringFromPropertyValue(const Microsoft::WRL::ComPtr<IInspectable>& inspPropValue);
NSString* NSStringFromPropertyValue(const winrt::Windows::Foundation::IInspectable& rtPropertyValue);

// Set up border style for a control
void SetControlBorderStyle(const winrt::Windows::UI::Xaml::Controls::Control& control, UITextBorderStyle style);

// Determine if the XAML type specified by the class name is activatable
Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> ReturnXamlType(NSString* xamlClassName);

// Determine the type of XAML control and generate the UIKit equivalent
UIView* GenerateUIKitControlFromXamlType(const winrt::Windows::Foundation::IInspectable& xamlObject);

// apply LineBreakMode on xaml TextBock
void ApplyLineBreakModeOnTextBlock(const winrt::Windows::UI::Xaml::Controls::TextBlock& textBlock, UILineBreakMode mode, int numberOfLines);

// Helper searches max font size for a string that can fit into given rect using given font/linebreak/numerOfLines config .
// font size returned must be between mininumFontSize and maximumFontSize.
float FindMaxFontSizeToFit(CGRect rect, NSString* text, UIFont* font, int numberOfLines, float mininumFontSize, float maximumFontSize);
}