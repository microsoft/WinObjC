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

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/NSObject.h>
#import <StoreKit/SKProductsRequest.h>
#import <StoreKit/SKProductsResponse.h>
#import <StoreKit/SKProduct.h>
#import <StoreKit/SKRequest.h>
#import <StoreKit/SKPayment.h>
typedef wchar_t WCHAR;
#import "UWP/WindowsApplicationModelStore.h"

@implementation SKRequest : NSObject
@end

@implementation SKPayment : NSObject

/**
 @Status Interoperable
*/
+ (SKPayment*)paymentWithProduct:(SKProduct*)product {
    return [[self alloc] initWithProductIdentifier:product.productIdentifier];
}

/**
 @Status Interoperable
*/
+ (instancetype)paymentWithProductIdentifier:(NSString*)identifier {
    return [[self alloc] initWithProductIdentifier:identifier];
}

- (instancetype)initWithProductIdentifier:(NSString*)identifier {
    _productIdentifier = [identifier copy];
    return self;
}
@end

@implementation SKProduct : NSObject
- (instancetype)initWithTitle:(NSString*)title identifier:(NSString*)ident price:(NSString*)price {
    _productIdentifier = ident;
    _localizedTitle = title;

    auto nf = [[NSNumberFormatter alloc] init];
    [nf setNumberStyle:NSNumberFormatterCurrencyStyle];

    _price = [nf numberFromString:price];
    NSLog(@"%f", [_price doubleValue]);
    [nf release];
    return self;
}
@end

@implementation SKProductsResponse : NSObject
- (instancetype)init {
    _products = [[NSMutableArray alloc] init];
    return self;
}
@end

@implementation SKProductsRequest {
    NSMutableArray* _identifiers;
    SKProductsResponse* _response;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithProductIdentifiers:(NSArray*)identifiers {
    _identifiers = [identifiers mutableCopy];
    return [super init];
}

- (void)addProduct:(SKProduct*)product {
    for (NSString* identifier in _identifiers) {
        NSLog(@"%@", identifier);
        if ([identifier caseInsensitiveCompare:product.productIdentifier] == 0) {
            [_response.products addObject:product];
            break;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)start {
    _response = [[SKProductsResponse alloc] init];

    [self retain];
    [WSCurrentAppSimulator loadListingInformationAsyncWithSuccess:^void(WSListingInformation* listings) {
        for (NSString* prodKey in listings.productListings) {
            WSProductListing* curListing = listings.productListings[prodKey];

            [self addProduct:[[SKProduct alloc] initWithTitle:curListing.name
                                                   identifier:curListing.productId
                                                        price:curListing.formattedPrice]];
        }

        [self.delegate productsRequest:self didReceiveResponse:_response];

        [self release];
    }
                                                          failure:nil];
}

- (void)dealloc {
    [_identifiers release];
    [_response release];
    [super dealloc];
}

@end
