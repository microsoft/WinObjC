//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.h>
#include "COMIncludes_End.h"

@class UIFont;

// Provides basic mocking support
@interface _MockObjectBase : NSObject

// Override this in your implmentation to specify which class you'd like to mock
+ (Class)_mockClass;

@end

// Provides basic UIView pass-throughs
@interface _UIView_Proxy : _MockObjectBase

- (instancetype)initWithXamlElement:(const winrt::Windows::UI::Xaml::FrameworkElement&)xamlElement;

@property (nonatomic, readonly) winrt::Windows::UI::Xaml::FrameworkElement xamlElement;

@end

<<<<<<< 17c9442ca7373bbb57c3f561cd59160aa9296832
=======
// NOTE: current _UILabel_Proxy is merely a bridge to xaml TextBlock, which is only
// used to in a very confined scope - that is when accessing some properties
// of UIButton.titleLabel.  So it has very limited usage right now.
// However, we will replace UILabel the full implemention of _UILabel in the future
@interface _UILabel_Proxy : _UIView_Proxy

- (instancetype)initWithXamlElement:(const winrt::Windows::UI::Xaml::FrameworkElement&)xamlElement font:(UIFont*)font;

@end

>>>>>>> Switch UIKit from projections to C++/WinRT (rough draft)
@interface _UIImageView_Proxy : _UIView_Proxy

@property (nonatomic, retain) UIImage* image;

@end