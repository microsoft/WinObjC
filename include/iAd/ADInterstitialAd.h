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

#import <iAd/iAdExport.h>
#import <Foundation/NSObject.h>

@protocol ADInterstitialAdDelegate;
@class UIViewController;
@class UIView;

IAD_EXPORT_CLASS
@interface ADInterstitialAd : NSObject <NSObject>
@property (nonatomic, unsafe_unretained) id<ADInterstitialAdDelegate> delegate STUB_PROPERTY;
@property (readonly, getter=isLoaded, nonatomic) BOOL loaded STUB_PROPERTY;
- (void)presentFromViewController:(UIViewController*)viewController STUB_METHOD;
- (BOOL)presentInView:(UIView*)containerView STUB_METHOD;
@property (readonly, getter=isActionInProgress, nonatomic) BOOL actionInProgress STUB_PROPERTY;
- (void)cancelAction STUB_METHOD;
@end
