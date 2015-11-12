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

#ifndef _SKSTOREPRODUCTVIEWCONTROLLER_H_
#define _SKSTOREPRODUCTVIEWCONTROLLER_H_

#import <StoreKit/StoreKitExport.h>
#import <UIKit/UIViewController.h>

@protocol SKStoreProductViewControllerDelegate <NSObject>
@end

@interface SKStoreProductViewController : UIViewController {
}

- (void)loadProductWithParameters:(NSDictionary*)params completionBlock:(void (^)(BOOL result, NSError* error))block;

@property (nonatomic, assign) id<SKStoreProductViewControllerDelegate> delegate;

@end

STOREKIT_EXPORT NSString* const SKStoreProductParameterITunesItemIdentifier;

#endif // _SKSTOREPRODUCTVIEWCONTROLLER_H_
