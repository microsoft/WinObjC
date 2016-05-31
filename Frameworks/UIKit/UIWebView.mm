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

#include "Starboard.h"
#include "UIKit/UIKit.h"
#include "UIKit/UIView.h"
#include "CoreGraphics/CGContext.h"
#include "Foundation/NSMutableString.h"
#include "Foundation/NSDictionary.h"
#include "Foundation/NSURL.h"
#include "Foundation/NSError.h"
#include "UIKit/UIScrollView.h"
#include "UIKit/UIApplication.h"
#include "UIKit/UIColor.h"

#include "UIKit/UIWebView.h"
#include "UWP/WindowsUIXamlControls.h"

#include <algorithm>

@implementation UIWebView {
    id _delegate;
    idretaintype(NSURLRequest) _request;
    bool _isLoading;
    UIScrollView* _scrollView;
    WXCWebView* _xamlWebControl;
    EventRegistrationToken _xamlLoadCompletedEventCookie;
    EventRegistrationToken _xamlLoadStartedEventCookie;
}

/**
 @Status Stub
*/
- (void)setScalesPageToFit:(BOOL)scaleToFit {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id)delegate {
    _delegate = delegate;
}

/**
 @Status Interoperable
*/
- (id)delegate {
    return _delegate;
}

/**
 @Status Interoperable
*/
- (BOOL)isLoading {
    return _isLoading;
}

/**
 @Status Caveat
 @Notes Only URL property in request is used
*/
- (void)loadRequest:(NSURLRequest*)request {
    _request = request;
    NSURL* url = [request URL];
    NSString* urlStr = [url absoluteString];

    _isLoading = true;
    [_xamlWebControl navigate:[[WFUri makeUri:urlStr] autorelease]];
}

static void initWebKit(UIWebView* self) {
    self->_xamlWebControl = [WXCWebView make];
    [self layer].contentsElement = self->_xamlWebControl;
    self->_xamlLoadCompletedEventCookie = [self->_xamlWebControl addLoadCompletedEvent:^void(RTObject* sender, WUXNNavigationEventArgs* e) {
        self->_isLoading = false;

        if ([self->_delegate respondsToSelector:@selector(webViewDidFinishLoad:)]) {
            [self->_delegate webViewDidFinishLoad:self];
        }

    }];
    self->_xamlLoadStartedEventCookie =
        [self->_xamlWebControl addNavigationStartingEvent:^void(RTObject* sender, WXCWebViewNavigationStartingEventArgs* e) {
            if ([self->_delegate respondsToSelector:@selector(webViewDidStartLoad:)]) {
                [self->_delegate webViewDidStartLoad:self];
            }
        }];

    CGRect bounds;
    bounds = [self bounds];

    //  For compatibility only
    self->_scrollView = [[UIScrollView alloc] initWithFrame:bounds];

    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    [super init];

    initWebKit(self);

    return self;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    initWebKit(self);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)rect {
    [super initWithFrame:rect];

    initWebKit(self);

    return self;
}

/**
 @Status Caveat
 @Notes baseURL parameter not supported
*/
- (void)loadHTMLString:(NSString*)string baseURL:(NSURL*)baseURL {
    _isLoading = true;

    NSString* urlStr = [baseURL absoluteString];
    [_xamlWebControl navigateToString:string];

    [self sizeToFit];
}

/**
 @Status Stub
*/
- (void)loadData:(NSData*)data MIMEType:(NSString*)mimeType textEncodingName:(NSString*)encoding baseURL:(NSURL*)baseURL {
    UNIMPLEMENTED();
    _isLoading = true;

    assert(0 && "loadData:mimeTime:textEncodingName: not implemented");
}

/**
 @Status Interoperable
*/
- (void)stopLoading {
    _isLoading = false;
    [_xamlWebControl stop];
}

- (void)setDetectsPhoneNumbers:(BOOL)detect {
}

/**
 @Status Interoperable
*/
- (NSString*)stringByEvaluatingJavaScriptFromString:(NSString*)string {
    NSString* ret = [_xamlWebControl invokeScript:@"eval" arguments:[NSArray arrayWithObject:string]];
    return ret;
}

/**
 @Status Stub
*/
- (void)setDataDetectorTypes:(UIDataDetectorTypes)types {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (BOOL)canGoBack {
    return _xamlWebControl.canGoBack;
}

/**
 @Status Interoperable
*/
- (BOOL)canGoForward {
    return _xamlWebControl.canGoForward;
}

/**
 @Status Interoperable
*/
- (void)reload {
    [_xamlWebControl refresh];
}

/**
 @Status Interoperable
*/
- (void)goBack {
    [_xamlWebControl goBack];
}

/**
 @Status Interoperable
*/
- (void)goForward {
    [_xamlWebControl goForward];
}

/**
 @Status Interoperable
*/
- (NSURLRequest*)request {
    return _request;
}

/**
 @Status Interoperable
*/
- (void)setBackgroundColor:(UIColor*)color {
    CGFloat r = 0;
    CGFloat g = 0;
    CGFloat b = 0;
    CGFloat a = 0;

    [super setBackgroundColor:color];

    [color getRed:&r green:&g blue:&b alpha:&a];

    // XAML WebView transparency is not used unless it's set to the transparent system color.
    if (a != 1.0f) {
        [_xamlWebControl setDefaultBackgroundColor:[WUColors transparent]];
    } else {
        [_xamlWebControl setDefaultBackgroundColor:[WUColorHelper fromArgb:255
                                                                         r:(unsigned char)(r * 255.0)
                                                                         g:(unsigned char)(g * 255.0)
                                                                         b:(unsigned char)(b * 255.0)]];
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_xamlWebControl removeLoadCompletedEvent:_xamlLoadCompletedEventCookie];
    [_xamlWebControl removeNavigationStartingEvent:_xamlLoadStartedEventCookie];
    [_xamlWebControl release];

    [super dealloc];
}

/**
 @Status Stub
*/
- (UIScrollView*)scrollView {
    UNIMPLEMENTED();
    return _scrollView;
}

/**
 @Status Stub
*/
- (void)setScrollsToTop:(BOOL)scrollsToTop {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setAllowsInlineMediaPlayback:(BOOL)allow {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMediaPlaybackRequiresUserAction:(BOOL)allow {
    UNIMPLEMENTED();
}
@end
