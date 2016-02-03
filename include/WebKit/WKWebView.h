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

#import <WebKit/WebKitExport.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UICoordinateSpace.h>
#import <UIKit/UIDynamicItem.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIView.h>

@class NSURLRequest;
@class WKWebViewConfiguration;
@class UIScrollView;
@class NSString;
@class NSURL;
@class NSArray;
@protocol WKNavigationDelegate;
@protocol WKUIDelegate;
@class WKNavigation;
@class NSData;
@class WKBackForwardList;
@class WKBackForwardListItem;
@class NSError;

WEBKIT_EXPORT_CLASS
@interface WKWebView : UIView <NSCoding,
                               UIAppearance,
                               UIAppearanceContainer,
                               UICoordinateSpace,
                               UIDynamicItem,
                               UIFocusEnvironment,
                               UITraitEnvironment>
- (instancetype)initWithFrame:(CGRect)frame configuration:(WKWebViewConfiguration*)configuration;
@property (nonatomic, readonly, copy) WKWebViewConfiguration* configuration;
@property (nonatomic, readonly, strong) UIScrollView* scrollView;
@property (nonatomic, readonly, copy) NSString* title;
@property (nonatomic, readonly, copy) NSURL* URL;
@property (nonatomic, copy) NSString* customUserAgent;
@property (nonatomic, readonly, copy) NSArray* certificateChain;
@property (nonatomic, assign) id<WKNavigationDelegate> navigationDelegate;
@property (nonatomic, assign) id<WKUIDelegate> UIDelegate;
@property (nonatomic, readonly) double estimatedProgress;
@property (nonatomic, readonly) BOOL hasOnlySecureContent;
- (WKNavigation*)loadHTMLString:(NSString*)string baseURL:(NSURL*)baseURL;
@property (nonatomic, readonly, getter=isLoading) BOOL loading;
- (WKNavigation*)reload;
- (WKNavigation*)reloadFromOrigin;
- (void)stopLoading;
- (WKNavigation*)loadData:(NSData*)data
                 MIMEType:(NSString*)MIMEType
    characterEncodingName:(NSString*)characterEncodingName
                  baseURL:(NSURL*)baseURL;
- (WKNavigation*)loadFileURL:(NSURL*)URL allowingReadAccessToURL:(NSURL*)readAccessURL;
@property (nonatomic) BOOL allowsBackForwardNavigationGestures;
@property (nonatomic, readonly, strong) WKBackForwardList* backForwardList;
@property (nonatomic, readonly) BOOL canGoBack;
@property (nonatomic, readonly) BOOL canGoForward;
@property (nonatomic) BOOL allowsLinkPreview;
- (WKNavigation*)goBack;
- (WKNavigation*)goForward;
- (WKNavigation*)goToBackForwardListItem:(WKBackForwardListItem*)item;
- (WKNavigation*)loadRequest:(NSURLRequest*)request;
- (void)evaluateJavaScript:(NSString*)javaScriptString completionHandler:(void (^)(id, NSError* error))completionHandler;

/* UIFocusEnvironment */
@property (nonatomic, assign, readonly) UIView* preferredFocusedView;

/* UICoordinateSpace */
@property (readonly, nonatomic) CGRect bounds;

/* UITraitEnvironment */
@property (nonatomic, readonly) UITraitCollection* traitCollection;
@end
