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

#import <UIKit/UIViewController.h>
#import <SafariServices/SFSafariViewControllerDelegate.h>

@class NSURL;

SAFARISERVICES_EXPORT_CLASS
@interface SFSafariViewController : UIViewController
@property (nonatomic, weak) id<SFSafariViewControllerDelegate> delegate;

- (instancetype)initWithNibName:(NSString*)nibName bundle:(NSBundle*)nibBundle NS_UNAVAILABLE;

- (instancetype)initWithURL:(NSURL*)URL;
- (instancetype)initWithURL:(NSURL*)URL entersReaderIfAvailable:(BOOL)entersReaderIfAvailable NS_DESIGNATED_INITIALIZER;

// WINOBJC extension: To be used specifically when the view controller will be hosting
// an OAuth login. This will use the Windows WebAuthenticationBroker UI rather than a
// generic web view UI.
- (instancetype)initWithOAuthURL:(NSURL*)URL substituteRedirectURL:(NSURL*)redirectURL NS_DESIGNATED_INITIALIZER;
@end
