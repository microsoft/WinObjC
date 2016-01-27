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
#import <UIKit/UIViewController.h>

@class UIView;

typedef NS_ENUM(NSInteger, ADInterstitialPresentationPolicy) {
    ADInterstitialPresentationPolicyNone = 0,
    ADInterstitialPresentationPolicyAutomatic,
    ADInterstitialPresentationPolicyManual
};

@interface UIViewController (iAd)
@property (nonatomic, assign) BOOL canDisplayBannerAds STUB_PROPERTY;
@property (nonatomic, retain, readonly) UIView* originalContentView STUB_PROPERTY;
@property (nonatomic, readonly, getter=isPresentingFullScreenAd) BOOL presentingFullScreenAd STUB_PROPERTY;
@property (nonatomic, readonly, getter=isDisplayingBannerAd) BOOL displayingBannerAd STUB_PROPERTY;
@property (nonatomic, assign) ADInterstitialPresentationPolicy interstitialPresentationPolicy STUB_PROPERTY;
+ (void)prepareInterstitialAds STUB_METHOD;
- (BOOL)requestInterstitialAdPresentation STUB_METHOD;
@property (readonly, nonatomic) BOOL shouldPresentInterstitialAd STUB_PROPERTY;
@end
