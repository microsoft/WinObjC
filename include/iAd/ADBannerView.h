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

#import <CoreGraphics/CGGeometry.h>

#import <Foundation/NSObject.h>

#import <UIKit/UIAppearance.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UICoordinateSpace.h>
#import <UIKit/UIDynamicItem.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIView.h>

@protocol ADBannerViewDelegate;

@class NSSet;
@class NSString;

typedef NS_ENUM(NSInteger, ADError) {
    ADErrorUnknown = 0,
    ADErrorServerFailure = 1,
    ADErrorLoadingThrottled = 2,
    ADErrorInventoryUnavailable = 3,
    ADErrorConfigurationError = 4,
    ADErrorBannerVisibleWithoutContent = 5,
    ADErrorApplicationInactive = 6,
    ADErrorAdUnloaded = 7,
};

typedef NS_ENUM(NSInteger, ADAdType) { 
    ADAdTypeBanner,
    ADAdTypeMediumRectangle
};

IAD_EXPORT NSString* const ADBannerContentSizeIdentifier320x50;
IAD_EXPORT NSString* const ADBannerContentSizeIdentifier480x32;
IAD_EXPORT NSString* const ADBannerContentSizeIdentifierPortrait;
IAD_EXPORT NSString* const ADBannerContentSizeIdentifierLandscape;
IAD_EXPORT NSString* const ADErrorDomain;

IAD_EXPORT_CLASS
@interface ADBannerView : UIView <NSCoding,
                                  NSObject,
                                  UIAppearance,
                                  UIAppearanceContainer,
                                  UICoordinateSpace,
                                  UIDynamicItem,
                                  UIFocusEnvironment,
                                  UITraitEnvironment>
- (instancetype)initWithAdType:(ADAdType)type STUB_METHOD;
@property (readonly, nonatomic) ADAdType adType STUB_PROPERTY;
@property (nonatomic, unsafe_unretained) id<ADBannerViewDelegate> delegate STUB_PROPERTY;
@property (copy, nonatomic) NSString* advertisingSection STUB_PROPERTY;
@property (copy, nonatomic) NSSet* requiredContentSizeIdentifiers STUB_PROPERTY;
@property (copy, nonatomic) NSString* currentContentSizeIdentifier STUB_PROPERTY;
+ (CGSize)sizeFromBannerContentSizeIdentifier:(NSString*)contentSizeIdentifier STUB_METHOD;
@property (readonly, getter=isBannerLoaded, nonatomic) BOOL bannerLoaded STUB_PROPERTY;
@property (readonly, getter=isBannerViewActionInProgress, nonatomic) BOOL bannerViewActionInProgress STUB_PROPERTY;
- (void)cancelBannerViewAction STUB_METHOD;
@end
