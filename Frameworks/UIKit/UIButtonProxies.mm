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

#import "Starboard.h"
#import <UIKit/UILabel.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIImageView.h>
#import <Foundation/NSString.h>
#include "CppWinRTHelpers.h"

#import <CoreGraphics/CGContext.h>
#import <UIKit/UIView.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIColor.h>
#import "UIButtonProxies.h"
#import "UIFontInternal.h"

#import "XamlUtilities.h"

#import "Activation.h"

#include <Windows.UI.Xaml.Media.h>

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.h>
#import <winrt/Windows.UI.Xaml.Media.h>
#import <winrt/Windows.UI.Text.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;

static const wchar_t* tag = L"UIButtonProxies";

@implementation _MockObjectBase

+ (Class)_mockClass {
    return [NSObject class];
}

- (void)forwardInvocation:(NSInvocation*)invocation {
    TraceWarning(tag,
                 L"Warning: unsupported API or property is invoked on this class - %hs is currently a mock %hs and only supports a subset "
                 L"of its selectors",
                 class_getName([self class]),
                 class_getName([[self class] _mockClass]));
}

- (NSMethodSignature*)methodSignatureForSelector:(SEL)aSelector {
    if ([[[self class] _mockClass] instancesRespondToSelector:aSelector]) {
        return [[[self class] _mockClass] instanceMethodSignatureForSelector:aSelector];
    }
    return [super methodSignatureForSelector:aSelector];
}

@end

@implementation _UIView_Proxy {
    TrivialDefaultConstructor<FrameworkElement> _xamlElement;
}

+ (Class)_mockClass {
    return [UIView class];
}

- (instancetype)initWithXamlElement:(const FrameworkElement&)xamlElement {
    if (self = [super init]) {
        _xamlElement = xamlElement;
    }
    return self;
}

- (FrameworkElement)_winrtXamlElement {
    return _xamlElement;
}

- (void)setFrame:(CGRect)frame {
    // Only set canvas top/left values if we have a non-null frame.
    // Otherwise we set them to infinity, which causes touch input issues.
    if (!CGRectIsNull(frame)) {
        // We're assuming everything will be held in a Canvas
        Controls::Canvas::SetTop(_xamlElement, frame.origin.y);
        Controls::Canvas::SetLeft(_xamlElement, frame.origin.x);
    }

    _xamlElement.Width(frame.size.width);
    _xamlElement.Height(frame.size.height);
}

- (CGRect)frame {
    CGRect ret = { 0 };

    // We're assuming everything will be held in a Canvas
    Controls::Canvas::GetTop(_xamlElement);
    Controls::Canvas::GetLeft(_xamlElement);

    ret.size.width = _xamlElement.Width();
    ret.size.height = _xamlElement.Height();

    return ret;
}

@end

@implementation _UIImageView_Proxy {
    // For convenience
    TrivialDefaultConstructor<Controls::Image> _xamlImage;
}

+ (Class)_mockClass {
    return [UIImageView class];
}

- (instancetype)initWithXamlElement:(const FrameworkElement&)xamlElement {
    FAIL_FAST_IF_NULL(xamlElement);
    auto image = xamlElement.try_as<Controls::Image>();
    FAIL_FAST_IF_NULL(image);

    if (self = [super initWithXamlElement:xamlElement]) {
        _xamlImage = image;
    }

    return self;
}

- (CGSize)intrinsicContentSize {
    if (self.image) {
        // TODO: Do we have to care about cap insets?
        return self.image.size;
    } else {
        return CGSizeMake(UIViewNoIntrinsicMetric, UIViewNoIntrinsicMetric);
    }
}

- (CGSize)sizeThatFits:(CGSize)curSize {
    if (self.image) {
        // TODO: Do we have to care about cap insets?
        return self.image.size;
    } else {
        return CGSizeMake(0, 0);
    }
}

@end