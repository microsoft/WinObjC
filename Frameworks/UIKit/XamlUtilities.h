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

#import <UIKit/UIControl.h>
#import <UWP/WindowsUIXamlControls.h>

@interface XamlUtilities : NSObject
// convert UIColor to Color on windows
+ (WUColor*)convertUIColorToWUColor:(UIColor*)uiColor;

// convert UITextAlignment to TextAlignment on windows
+ (WXTextAlignment)convertUITextAlignmentToWXTextAlignment:(UITextAlignment)alignment;

// convert ios KeyboardType to Windows InputScope
+ (WUXIInputScope*)convertKeyboardTypeToInputScope:(UIKeyboardType)keyboardType secureTextMode:(BOOL)secureTextMode;

// Find the named template child in control tempate of a xaml control
+ (WXFrameworkElement*)findTemplateChild:(WXCControl*)control name:(NSString*)name;

// set up border style for a control
+ (void)setControlBorderStyle:(WXCControl*)control borderStyle:(UITextBorderStyle)style;

@end
