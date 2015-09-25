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
typedef wchar_t WCHAR;
#include "UWP/WindowsUIXamlControls.h"

#include <algorithm>

@implementation UIWebView {
    id _delegate;
    idretaintype(NSURLRequest) _request;
    idretaintype(NSURLRequest) _delayLoadURL;
    bool _isLoading;
    bool _isVisible;
    UIScrollView* _scrollView;
    WXCWebView* _xamlWebControl;
    EventRegistrationToken _xamlLoadCompletedEventCookie;
    EventRegistrationToken _xamlLoadStartedEventCookie;
}

- (void)setScalesPageToFit:(BOOL)scaleToFit {
}

- (void)setDelegate:(id)delegate {
    _delegate = delegate;
}

- (id)delegate {
    return _delegate;
}

- (BOOL)isLoading {
    return _isLoading;
}

- (void)loadRequest:(NSURLRequest*)request {
    _request = request;
    NSURL* url = [request URL];
    NSString* urlStr = [url absoluteString];

    _isLoading = true;
    _isVisible = true;
    if (!_isVisible) {
        _delayLoadURL = urlStr;
    } else {
        _delayLoadURL = nil;
        [_xamlWebControl navigate:[[WFUri createUri:urlStr] autorelease]];
    }
}

static void initWebKit(UIWebView* self) {
    self->_xamlWebControl = [WXCWebView create];
    [self layer].contentsElement = self->_xamlWebControl;
    self->_xamlLoadCompletedEventCookie =
        [self->_xamlWebControl addLoadCompletedEvent:^void(RTObject* sender, WUXNNavigationEventArgs* e) {
            self->_isLoading = false;

            if ([self->_delegate respondsToSelector:@selector(webViewDidFinishLoad:)]) {
                [self->_delegate webViewDidFinishLoad:self];
            }

        }];
    self->_xamlLoadStartedEventCookie = [self->_xamlWebControl
        addNavigationStartingEvent:^void(RTObject* sender, WXCWebViewNavigationStartingEventArgs* e) {
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

- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    initWebKit(self);

    return self;
}

- (instancetype)initWithFrame:(CGRect)rect {
    [super initWithFrame:rect];

    initWebKit(self);

    return self;
}

- (void)loadHTMLString:(NSString*)string baseURL:(NSURL*)baseURL {
    _isLoading = true;
    _delayLoadURL = nil;

    NSString* urlStr = [baseURL absoluteString];
    [_xamlWebControl navigateToString:string];

    [self sizeToFit];
}

- (void)loadData:(NSData*)data
        MIMEType:(NSString*)mimeType
textEncodingName:(NSString*)encoding
         baseURL:(NSURL*)baseURL {
    _isLoading = true;
    _delayLoadURL = nil;

    assert(0 && "loadData:mimeTime:textEncodingName: not implemented");
}

- (void)stopLoading {
    _isLoading = false;
    [_xamlWebControl stop];
}

- (void)setDetectsPhoneNumbers:(BOOL)detect {
}

- (NSString*)stringByEvaluatingJavaScriptFromString:(NSString*)string {
    NSString* ret = [_xamlWebControl invokeScript:@"eval" arguments:[NSArray arrayWithObject:string]];
    return ret;
}

- (void)setDataDetectorTypes:(UIDataDetectorTypes)types {
}

- (BOOL)canGoBack {
    return _xamlWebControl.canGoBack;
}

- (BOOL)canGoForward {
    return _xamlWebControl.canGoForward;
}

- (void)reload {
    [_xamlWebControl refresh];
}

- (void)goBack {
    [_xamlWebControl goBack];
}

- (void)goForward {
    [_xamlWebControl goForward];
}

- (NSURLRequest*)request {
    return _request;
}

- (void)dealloc {
    _delayLoadURL = nil;
    [_xamlWebControl removeLoadCompletedEvent:_xamlLoadCompletedEventCookie];
    [_xamlWebControl removeNavigationStartingEvent:_xamlLoadStartedEventCookie];
    [_xamlWebControl release];

    [super dealloc];
}

- (UIScrollView*)scrollView {
    return _scrollView;
}

- (void)setScrollsToTop:(BOOL)scrollsToTop {
}

- (void)setAllowsInlineMediaPlayback:(BOOL)allow {
}

- (void)setMediaPlaybackRequiresUserAction:(BOOL)allow {
}
@end
