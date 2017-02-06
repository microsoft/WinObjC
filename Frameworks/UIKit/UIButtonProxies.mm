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

// TOOD: Bug 8706843:Constructor or Helper to create FontFamily isn't projected - thus no way to create a FontFamily from Objective C side.
// remove this once 8706843 is resolved
#ifdef __OBJC__
#pragma push_macro("interface")
#ifndef interface
#define interface struct
#endif
#pragma push_macro("Nil")
#undef Nil
#endif
#include <UWP/RTHelpers.h>
#ifdef __OBJC__
#pragma pop_macro("Nil")
#pragma pop_macro("interface")
#endif

#import <CoreGraphics/CGContext.h>
#import <UIKit/UIView.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIColor.h>
#import "UIButtonProxies.h"
#import "UIFontInternal.h"

#import <UWP/WindowsUIXamlControls.h>
#import "XamlUtilities.h"

#import "Activation.h"

#include <Windows.UI.Xaml.Media.h>

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

@implementation _UIView_Proxy

+ (Class)_mockClass {
    return [UIView class];
}

- (instancetype)initWithXamlElement:(WXFrameworkElement*)xamlElement {
    if (self = [super init]) {
        _xamlElement = xamlElement;
    }
    return self;
}

- (void)setFrame:(CGRect)frame {
    // Only set canvas top/left values if we have a non-null frame.
    // Otherwise we set them to infinity, which causes touch input issues.
    if (!CGRectIsNull(frame)) {
        // We're assuming everything will be held in a Canvas
        [WXCCanvas setTop:_xamlElement length:frame.origin.y];
        [WXCCanvas setLeft:_xamlElement length:frame.origin.x];
    }

    _xamlElement.width = frame.size.width;
    _xamlElement.height = frame.size.height;
}

- (CGRect)frame {
    CGRect ret = { 0 };

    // We're assuming everything will be held in a Canvas
    [WXCCanvas getTop:_xamlElement];
    [WXCCanvas getLeft:_xamlElement];

    ret.size.width = _xamlElement.width;
    ret.size.height = _xamlElement.height;

    return ret;
}

@end

@implementation _UIImageView_Proxy {
    // For convenience
    WXCImage* _xamlImage;
}

+ (Class)_mockClass {
    return [UIImageView class];
}

- (instancetype)initWithXamlElement:(WXFrameworkElement*)xamlElement {
    FAIL_FAST_IF_NULL(xamlElement);
    WXCImage* image = rt_dynamic_cast<WXCImage>(xamlElement);
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