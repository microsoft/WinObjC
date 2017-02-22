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
#include "StubReturn.h"
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
#include "UIViewInternal.h"
#include "StringHelpers.h"
#include "CppWinRTHelpers.h"

#include "UIKit/UIWebView.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Controls.h>
#import <winrt/Windows.UI.Xaml.Navigation.h>
#import <winrt/Windows.Web.Http.h>
#import <winrt/Windows.Web.Http.Headers.h>
#include "COMIncludes_End.h"

#include <algorithm>

using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::Web;
namespace WF = winrt::Windows::Foundation;

@interface UIWebView ()
@property (nonatomic, getter=isLoading) BOOL loading;
@end

@implementation UIWebView {
    id _delegate;
    idretaintype(NSURLRequest) _request;
    bool _isLoading;
    StrongId<UIScrollView> _scrollView;
    TrivialDefaultConstructor<Controls::WebView> _xamlWebControl;
    winrt::event_token _xamlLoadCompletedEventCookie;
    winrt::event_token _xamlLoadStartedEventCookie;
    winrt::event_token _xamlUnsupportedUriSchemeEventCookie;
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
 @Public No
*/
- (void)setLoading:(BOOL)loading {
    _isLoading = loading;
}

/**
 @Status Caveat
 @Notes Only URL property in request is used
*/
- (void)loadRequest:(NSURLRequest*)request {
    _request = request;
    NSURL* url = [request URL];
    NSString* urlStr = [url absoluteString];

    Http::HttpMethod method = winrt::hstring_ref(objcwinrt::string(request.HTTPMethod));
    WF::Uri uri = winrt::hstring_ref(objcwinrt::string(urlStr));

    Http::HttpRequestMessage msg(method, uri);

    [request.allHTTPHeaderFields enumerateKeysAndObjectsUsingBlock:^(NSString* field, NSString* value, BOOL* stop) {
        msg.Headers().Append(objcwinrt::string(field), objcwinrt::string(value));
    }];

    _isLoading = true;

    RunSynchronouslyOnMainThread(^{
        _xamlWebControl.NavigateWithHttpRequestMessage(msg);
    });
}

static void _initUIWebView(UIWebView* self) {
    // Store a strongly-typed backing scrollviewer
    self->_xamlWebControl = [self _xamlElementInternal].try_as<Controls::WebView>();
    if (!self->_xamlWebControl) {
        FAIL_FAST();
    }

    self->_xamlLoadCompletedEventCookie = self->_xamlWebControl.LoadCompleted([self] (auto&& sender, auto&& e) {
        self.loading = NO;

        if ([self.delegate respondsToSelector:@selector(webViewDidFinishLoad:)]) {
            [self.delegate webViewDidFinishLoad:self];
        }
    });

    self->_xamlLoadStartedEventCookie =
        self->_xamlWebControl.NavigationStarting([self] (auto&& sender, auto&& e) {
            // Give the client a chance to cancel the navigation
            if ([self.delegate respondsToSelector:@selector(webView:shouldStartLoadWithRequest:navigationType:)]) {
                NSString* urlStr = [NSString _stringWithHSTRING:winrt::get(e.Uri().AbsoluteUri())];
                NSURL* url = [NSURL URLWithString:urlStr];
                NSURLRequest* request = [NSURLRequest requestWithURL:url];

                // ???? XAML doesn't expose this information to us
                UIWebViewNavigationType navigationType = UIWebViewNavigationTypeOther;

                if (![self.delegate webView:self shouldStartLoadWithRequest:request navigationType:navigationType]) {
                    e.Cancel(true);
                    return;
                }
            }

            // Cancellation declined, navigation is proceeding
            if ([self.delegate respondsToSelector:@selector(webViewDidStartLoad:)]) {
                [self.delegate webViewDidStartLoad:self];
            }
        });

    self->_xamlUnsupportedUriSchemeEventCookie =
        self->_xamlWebControl.UnsupportedUriSchemeIdentified([self] (auto&& sender, auto&& e) {
            if ([self.delegate respondsToSelector:@selector(webView:shouldStartLoadWithRequest:navigationType:)]) {
                NSString* urlStr = [NSString _stringWithHSTRING:winrt::get(e.Uri().AbsoluteUri())];
                NSURL* url = [NSURL URLWithString:urlStr];
                NSURLRequest* request = [NSURLRequest requestWithURL:url];
                UIWebViewNavigationType navigationType = UIWebViewNavigationTypeOther;

                // The WebView doesn't know what to do with this URL, but give our client a crack at it
                if ([self.delegate webView:self shouldStartLoadWithRequest:request navigationType:navigationType]) {
                    // Client said to proceed, so pass the URL off to the system URI resolver
                } else {
                    // Client took care of the URL
                    e.Handled(true);
                }
            }
        });

    // Add handler which will be invoked when user calls window.external.notify(msg) function in javascript
    self->_xamlWebControl.ScriptNotify([self] (auto&& sender, auto&& e) {
        // Send event to webView delegate
        NSString* urlStr = [NSString _stringWithHSTRING:winrt::get(e.CallingUri().AbsoluteUri())];
        NSURL* url = [NSURL URLWithString:urlStr];
        if ([self.delegate respondsToSelector:@selector(webView:scriptNotify:value:)]) {
            NSString* value = [NSString _stringWithHSTRING:winrt::get(e.Value())];
            [self.delegate webView:self scriptNotify:url value:value];
        }
    });

    CGRect bounds;
    bounds = [self bounds];

    //  For compatibility only
    self->_scrollView.attach([[UIScrollView alloc] initWithFrame:bounds]);

    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        RunSynchronouslyOnMainThread(^{
            _initUIWebView(self);
        });
    }

    return self;
}

/**
 Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        RunSynchronouslyOnMainThread(^{
            _initUIWebView(self);
        });
    }

    return self;
}

/**
 Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    Controls::WebView webView;
    return objcwinrt::to_rtobj(webView);
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    _initUIWebView(self);

    return self;
}

/**
 @Status Caveat
 @Notes baseURL parameter not supported
*/
- (void)loadHTMLString:(NSString*)string baseURL:(NSURL*)baseURL {
    _isLoading = true;

    auto hstring = Strings::NarrowToWide<HSTRING>(string);
    _xamlWebControl.NavigateToString(winrt::hstring_ref(hstring.Get()));

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
    _xamlWebControl.Stop();
}

- (void)setDetectsPhoneNumbers:(BOOL)detect {
}

/**
 @Status Stub
*/
- (NSString*)stringByEvaluatingJavaScriptFromString:(NSString*)string {
    UNIMPLEMENTED_WITH_MSG(
        "stringByEvaluatingJavaScriptFromString is not supported on our platform. Call evaluateJavaScript:completionHandler: instead.");
    return StubReturn();
}

/**
 @Status Caveat
  @Notes This is a workaround. Original UIWebView does not have this method
*/
- (void)evaluateJavaScript:(NSString*)javaScriptString completionHandler:(void (^)(id, NSError*))completionHandler {
    auto jsString = Strings::NarrowToWide<HSTRING>(javaScriptString);
    auto jsStringRef = winrt::hstring_ref(jsString.Get());

    _xamlWebControl.InvokeScriptAsync(winrt::hstring_ref(L"eval"), { jsStringRef });
    /*
        arguments:[NSArray arrayWithObject:javaScriptString]
        success:^void(NSString* success) {
            if (completionHandler != nil) {
                completionHandler(success, nil);
            }
        }
        failure:^void(NSError* failure) {
            if (completionHandler != nil) {
                completionHandler(nil, failure);
            }
        }];
    */
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
    return _xamlWebControl.CanGoBack() ? YES : NO;
}

/**
 @Status Interoperable
*/
- (BOOL)canGoForward {
    return _xamlWebControl.CanGoForward() ? YES : NO;
}

/**
 @Status Interoperable
*/
- (void)reload {
    _xamlWebControl.Refresh();
}

/**
 @Status Interoperable
*/
- (void)goBack {
    _xamlWebControl.GoBack();
}

/**
 @Status Interoperable
*/
- (void)goForward {
    _xamlWebControl.GoForward();
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
        _xamlWebControl.DefaultBackgroundColor(winrt::Windows::UI::Colors::Transparent());
    } else {
        _xamlWebControl.DefaultBackgroundColor(winrt::Windows::UI::ColorHelper::FromArgb(255,
                                                                         (unsigned char)(r * 255.0),
                                                                         (unsigned char)(g * 255.0),
                                                                         (unsigned char)(b * 255.0)));
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    RunSynchronouslyOnMainThread(^{
        _xamlWebControl.LoadCompleted(_xamlLoadCompletedEventCookie);
        _xamlWebControl.NavigationStarting(_xamlLoadStartedEventCookie);
        _xamlWebControl.UnsupportedUriSchemeIdentified(_xamlUnsupportedUriSchemeEventCookie);
        _xamlWebControl = nullptr;
    });

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
