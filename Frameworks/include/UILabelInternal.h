//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#import <UIKit/UILabel.h>

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Controls.h>
#include "COMIncludes_End.h"

@interface UILabel (Internal) {
}
// Returns access to the underlying TextBlock within the UILabel's Xaml representation
// Note: This is used for UX testing and won't be necessary when we are projecting
// UIKit.Label into ObjectiveC, as at that point we can just expose the TextBlock directly
// off of our UIKit.Label implementation.
- (winrt::Windows::UI::Xaml::Controls::TextBlock)_getXamlTextBlock;
@end
