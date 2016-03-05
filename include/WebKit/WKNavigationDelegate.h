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
#import <Foundation/Foundation.h>

@class WKWebView;
@class WKNavigation;
@class NSError;
@class NSURLAuthenticationChallenge;
@class NSURLCredential;
@class WKNavigationAction;
@class WKNavigationResponse;

typedef NS_ENUM(NSInteger, WKNavigationActionPolicy) { WKNavigationActionPolicyCancel, WKNavigationActionPolicyAllow };

typedef NS_ENUM(NSInteger, WKNavigationResponsePolicy) { WKNavigationResponsePolicyCancel, WKNavigationResponsePolicyAllow };

@protocol WKNavigationDelegate <NSObject>
@optional
- (void)webView:(WKWebView*)webView didCommitNavigation:(WKNavigation*)navigation;
- (void)webView:(WKWebView*)webView didFailNavigation:(WKNavigation*)navigation withError:(NSError*)error;
- (void)webView:(WKWebView*)webView didFailProvisionalNavigation:(WKNavigation*)navigation withError:(NSError*)error;
- (void)webView:(WKWebView*)webView didFinishNavigation:(WKNavigation*)navigation;
- (void)webView:(WKWebView*)webView
    didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge
                    completionHandler:
                        (void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;
- (void)webView:(WKWebView*)webView didReceiveServerRedirectForProvisionalNavigation:(WKNavigation*)navigation;
- (void)webView:(WKWebView*)webView didStartProvisionalNavigation:(WKNavigation*)navigation;
- (void)webView:(WKWebView*)webView
    decidePolicyForNavigationAction:(WKNavigationAction*)navigationAction
                    decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler;
- (void)webView:(WKWebView*)webView
    decidePolicyForNavigationResponse:(WKNavigationResponse*)navigationResponse
                      decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler;
@end
