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

#import <StoreKit/StoreKitExport.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIViewController.h>

@class NSString;
@protocol SKStoreProductViewControllerDelegate;
@class NSDictionary;
@class NSError;

STOREKIT_EXPORT NSString* const SKStoreProductParameterITunesItemIdentifier;
STOREKIT_EXPORT NSString* const SKStoreProductParameterAffiliateToken;
STOREKIT_EXPORT NSString* const SKStoreProductParameterCampaignToken;
STOREKIT_EXPORT NSString* const SKStoreProductParameterProviderToken;
STOREKIT_EXPORT_CLASS
@interface SKStoreProductViewController
    : UIViewController
@property (assign, nonatomic) id<SKStoreProductViewControllerDelegate> delegate STUB_PROPERTY;
- (void)loadProductWithParameters:(NSDictionary*)parameters completionBlock:(void (^)(BOOL, NSError*))block STUB_METHOD;
@end
