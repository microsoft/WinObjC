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

#import <Starboard.h>

#import "StringHelpers.h"

#import <UIKit/UIControl.h>

#import "UWP/WindowsUIXaml.h"
#import "UWP/WindowsUIXamlControls.h"

// NOTE: These need to stay #includes
#include "COMIncludes.h"
#include "WinString.h"
#include "RoApi.h"
#include "Windows.UI.Xaml.Markup.h"
#include "COMIncludes_End.h"

NSString* const XamlAutoGenNamespace = @"IslandwoodAutoGenNamespace";

// Convert UIColor to Color on windows
WUColor* ConvertUIColorToWUColor(UIColor* uiColor);

// Convert UIImage to WUXMImageBrush on windows
WUXMImageBrush* ConvertUIImageToWUXMImageBrush(UIImage* image);

// Convert UIImage to WUXMIBitmapSource on windows
WUXMIBitmapSource* ConvertUIImageToWUXMIBitmapSource(UIImage* image);

// Convert UITextAlignment to TextAlignment on windows
WXTextAlignment ConvertUITextAlignmentToWXTextAlignment(UITextAlignment alignment);

// Convert TextAlignment to UITextAlignment
UITextAlignment ConvertWXTextAlignmentToUITextAlignment(WXTextAlignment alignment);

// Convert ios KeyboardType to Windows InputScope
WUXIInputScope* ConvertKeyboardTypeToInputScope(UIKeyboardType keyboardType, BOOL secureTextMode);

// Convert UIControlContentVerticalAlignment to Windows vertical Alignment
WXVerticalAlignment ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(UIControlContentVerticalAlignment alignment);

// Find the named template child in control template of a xaml control
WXFrameworkElement* FindTemplateChild(WXCControl* control, NSString* name);

// Passing a string between ObjC and WRL requires encasing an NSString within a WFPropertyValue/WFIPropertyValue
// BUGBUG:8791977 - WFIPropertyValue is not publicly exposed via projections so we used a workaround
NSString* NSStringFromPropertyValue(const Microsoft::WRL::ComPtr<IInspectable>& inspPropValue);
NSString* NSStringFromPropertyValue(RTObject* rtPropertyValue);

// Set up border style for a control
void SetControlBorderStyle(WXCControl* control, UITextBorderStyle style);

// Determine if the XAML type specified by the class name is activatable
Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> ReturnXamlType(NSString* xamlClassName);

// Determine the type of XAML control and generate the UIKit equivalent
UIView* GenerateUIKitControlFromXamlType(RTObject* xamlObject);

// TODO: GitHub issue 508 and 509
// We need a type-safe way to do this with projections.  This is copied verbatim from the projections
// code and works perfectly for this limited usage, but we don't do any type validation below.
id CreateRtProxy(Class cls, IInspectable* iface);
