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

#include "QuartzCore/CALayer.h"

#include "UIKit/UIWebView.h"

#include "CACompositor.h"

CA_EXPORT_CLASS
@interface CAWebLayer : CALayer
    -(WebViewControl *) innerControl;
@end

#include <algorithm>

@implementation UIWebView {
    id       _delegate;
    idretain _request;
    idretain _delayLoadURL;
    bool     _isLoading;
    bool     _isVisible;
    UIScrollView *_scrollView;
    WebViewControl *_innerControl;
}

    -(void) setScalesPageToFit: (BOOL)scaleToFit {
    }

    -(void) setDelegate:(id)delegate {
        _delegate = delegate;
    }

    -(id) delegate {
        return _delegate;
    }

    -(BOOL) isLoading {
        return _isLoading;
    }

    -(void) loadRequest:(NSURLRequest *)request {
        _request = request;
        NSURL *url = [request URL];
        NSString *urlStr = [url absoluteString];

        _isLoading = true;
        _isVisible = true;
        if ( !_isVisible ) {
            _delayLoadURL = urlStr;
        } else {
            _delayLoadURL = nil;
            if ( _innerControl ) _innerControl->LoadURL(urlStr);
            //EbrWebViewLoadURL(_webView, urlStr);
        }
    }

    static void initWebKit(UIWebView *self)
    {
        self->_innerControl = [(CAWebLayer *) [self layer] innerControl];

        CGRect bounds;
        bounds = [self bounds];
        self->_scrollView = [[UIScrollView alloc] initWithFrame:bounds];
        /*
        [self->_scrollView setShowsVerticalScrollIndicator:FALSE];
        [self->_scrollView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
        [self addSubview:self->_scrollView];
        [self->_scrollView setBackgroundColor:[UIColor colorWithRed:0.f green:0.f blue:0.f alpha:0.f]];
        [self->_scrollView release];
        */

        [self setNeedsLayout];
        [self setContentMode: UIViewContentModeRedraw];
    }

    -(instancetype) initWithCoder:(NSCoder *)coder {
        [super initWithCoder:coder];

        initWebKit(self);

        return self;
    }

    /* annotate with type */ -(id) initWithFrame:(CGRect)rect {
        [super initWithFrame:rect];

#if defined(USE_SIMPLE_UIWEBVIEW)
        rect.origin.x = 0.f;
        rect.origin.y = 0.f;

        _textView = [[UITextView alloc] initWithFrame:rect];
        [self addSubview:(id)_textView];
//        [_textView setFont:[UIFont systemFontOfSize:12.f]];
        [_textView release];
#endif

        initWebKit(self);

        return self;
    }
    
    -(void) loadHTMLString:(NSString *)string baseURL:(NSURL *)baseURL {
        _isLoading = true;
        _delayLoadURL = nil;

        NSString *urlStr = [baseURL absoluteString];
        if ( _innerControl ) _innerControl->LoadHTMLString(string, urlStr);
        //EbrWebViewLoadHTMLString(_webView, string, baseURL);
        //[_scrollView setContentSize:estimateContentSize(string)];

        [self sizeToFit];
    }

    -(void) loadData: (NSData *)data MIMEType: (NSString *)mimeType textEncodingName: (NSString *)encoding baseURL: (NSURL *)baseURL {
        _isLoading = true;
        _delayLoadURL = nil;

        //EbrWebViewLoadData(_webView, data, mimeType, encoding, baseURL);
        //[_scrollView setContentSize:estimateContentSize(data)];

        [self sizeToFit];
    }

    -(void) stopLoading {
        _isLoading = false;

        //EbrWebViewStopLoading(_webView);
    }

    -(void) setDetectsPhoneNumbers:(BOOL)detect {
    }

    -(NSString *) stringByEvaluatingJavaScriptFromString: (NSString *)string {
        //return EbrWebViewEvaluateJavascript(_webView, string);
    }

    -(void) setDataDetectorTypes:(UIDataDetectorTypes)types {
    }

    -(BOOL) canGoBack {
        //return EbrWebViewCanGoBack(_webView);
        return FALSE;
    }

    -(BOOL) canGoForward {
        return FALSE;
        //return EbrWebViewCanGoForward(_webView);
    }

    -(void) reload {
         //EbrWebViewReload(_webView);
    }

    -(void) goBack {
        //EbrWebViewGoBack(_webView);
    }

    -(void) goForward {
        //EbrWebViewGoForward(_webView);
    }

    -(NSURLRequest *) request {
        return _request;
    }

    -(void) dealloc {
        //EbrWebViewSetDelegate(_webView, nil);
        //_webView = nil;
        _delayLoadURL = nil;

        [super dealloc];
    }

    -(UIScrollView *) scrollView {
        return _scrollView;
    }

    -(void) setScrollsToTop:(BOOL)scrollsToTop {
    }

    +(Class) layerClass {
        return [CAWebLayer class];
    }

    #if 0
    /* annotate with type */ -(id) _webViewEvent:(EbrNativeWebViewEvent*)params {
        switch ( params->_event ) {
            case nativeWebViewShouldStartLoad: {
                id url = [NSURL URLWithString:(id) params->_url];
                id request = [NSURLRequest requestWithURL:url];
                BOOL ret = true;

                if ( [_delegate respondsToSelector:@selector(webView:shouldStartLoadWithRequest:navigationType:)] ) {
                    EbrDebugLog("Should start load request (%s)?\n", [params->_url UTF8String]);
                    ret = [_delegate webView:self shouldStartLoadWithRequest:request navigationType:(DWORD) params->_navigationType];
                    EbrDebugLog(" - %s\n", ret ? "true" : "false");
                }
                params->_result = ret;
            }
                break;

            case nativeWebViewDidStartLoad: {
                if ( [_delegate respondsToSelector:@selector(webViewDidStartLoad:)] ) {
                    [_delegate webViewDidStartLoad:self];
                }
            }
                break;

            case nativeWebViewDidFinishLoad: {
                _isLoading = false;

                if ( [_delegate respondsToSelector:@selector(webViewDidFinishLoad:)] ) {
                    [_delegate webViewDidFinishLoad:self];
                }
            }
                break;

            case nativeWebViewDidFailLoad: {
                _isLoading = false;

                if ( [_delegate respondsToSelector:@selector(webView:didFailLoadWithError:)] ) {
                    [_delegate webView:self didFailLoadWithError:(id) params->_error];
                }
            }
                break;
        }

        return self;
    }

    /* annotate with type */ -(id) setHidden:(DWORD)hide {
        [super setHidden:hide];
#ifndef NO_WEBVIEW
#if defined(USE_SIMPLE_UIWEBVIEW)
        [_textView setHidden:hide];
#else 
        if ( hide ) {
            if ( _webView ) EbrWebViewHide(_webView);
        }
#endif 
#endif // NO_WEBVIEW
        return (DWORD) self;
    }
    #endif

    -(void) setAllowsInlineMediaPlayback:(BOOL)allow {
    }
        
    -(void) setMediaPlaybackRequiresUserAction:(BOOL)allow {
    }

    #if 0
    /* annotate with type */ -(id) _webViewHidden {
        _isVisible = false;
        return self;
    }

    /* annotate with type */ -(id) layoutSubviews {
        initClipRegion(self);
        return self;
    }
    
    /* annotate with type */ -(id) _webViewVisible {
        if ( _delayLoadURL ) {
            idretain url = _delayLoadURL;
            _delayLoadURL = nil;
#if !defined(NO_WEBVIEW)
#if defined(USE_SIMPLE_UIWEBVIEW)
            // TODO: implement me!
            EbrDebugLog("Ack! USE_SIMPLE_UIWEBVIEW doesn't implement this yet!\n");
#else
            EbrWebViewLoadURL(_webView, url);
#endif             
#endif
        }
        return self;
    }

    /* annotate with type */ -(id) _nativeDidFail {
        EbrNativeWebViewEvent* params = [EbrNativeWebViewEvent alloc];
        params->_event = nativeWebViewDidFailLoad;
        params->_error = [NSError errorWithDomain:@"NSURLErrorDomain" code:50 userInfo:nil];

        [self performSelectorOnMainThread:@selector(_webViewEvent:) withObject:(id) params waitUntilDone:FALSE];
        [params release];
        return self;
    }
    
    /* annotate with type */ -(id) _nativeDidFinishLoad {
        EbrNativeWebViewEvent* params = [EbrNativeWebViewEvent alloc];
        params->_event = nativeWebViewDidFinishLoad;
        params->_result = 0;

        params->_navigationType = UIWebViewNavigationTypeOther;
        EbrDebugLog("Nav type %d\n", params->_navigationType);

        [self performSelectorOnMainThread:@selector(_webViewEvent:) withObject:(id) params waitUntilDone:FALSE];
        [params release];
        return self;
    }
    
    /* annotate with type */ -(id) _nativeNavigating:(id)url {
        EbrNativeWebViewEvent* params = [EbrNativeWebViewEvent alloc];
        params->_event = nativeWebViewShouldStartLoad;
        params->_url = url;
        params->_result = 0;

        params->_navigationType = UIWebViewNavigationTypeOther;
        EbrDebugLog("Nav type %d\n", params->_navigationType);

        BOOL success = [self _performSelectorOnMainThreadAbortIfBackground:@selector(_webViewEvent:) withObject:(id) params waitUntilDone:TRUE];
        int result = 0;
        if ( success ) {
            result = params->_result;
        } else {
            //  App switched to background - queue up a failure
            EbrNativeWebViewEvent* failparams = [EbrNativeWebViewEvent alloc];
            failparams->_event = nativeWebViewDidFailLoad;
            failparams->_error = [NSError errorWithDomain:@"NSURLErrorDomain" code:50 userInfo:nil];

            [self performSelectorOnMainThread:@selector(_webViewEvent:) withObject:(id) failparams waitUntilDone:FALSE];
            [failparams release];
        }
        [params release];
        return result;
    }
    #endif
    
@end
