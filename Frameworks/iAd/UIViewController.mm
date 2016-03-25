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

#import <iAd/UIViewController.h>
#import <StubReturn.h>

@implementation UIViewController (iAd)
/**
 @Status Stub
 @Notes
*/
- (BOOL)canDisplayBannerAds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setCanDisplayBannerAds:(BOOL)canDisplayBannerAds {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UIView*)originalContentView {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isPresentingFullScreenAd {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isDisplayingBannerAd {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (ADInterstitialPresentationPolicy)interstitialPresentationPolicy {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setInterstitialPresentationPolicy:(ADInterstitialPresentationPolicy)interstitialPresentationPolicy {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)prepareInterstitialAds {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)requestInterstitialAdPresentation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)shouldPresentInterstitialAd {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setShouldPresentInterstitialAd:(BOOL)shouldPresentInterstitialAd {
    UNIMPLEMENTED();
}

@end
