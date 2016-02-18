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

@class NSError;
@class SKPayment;
@class NSString;
@class NSData;
@class NSDate;
@class NSArray;

typedef NSInteger SKPaymentTransactionState;
enum {
    SKPaymentTransactionStatePurchasing,
    SKPaymentTransactionStatePurchased,
    SKPaymentTransactionStateFailed,
    SKPaymentTransactionStateRestored,
    SKPaymentTransactionStateDeferred,
};

STOREKIT_EXPORT_CLASS
@interface SKPaymentTransaction : NSObject <NSObject>
@property (readonly, nonatomic) NSError* error STUB_PROPERTY;
@property (readonly, nonatomic) SKPayment* payment STUB_PROPERTY;
@property (readonly, nonatomic) SKPaymentTransactionState transactionState STUB_PROPERTY;
@property (readonly, nonatomic) NSString* transactionIdentifier STUB_PROPERTY;
@property (readonly, nonatomic) NSData* transactionReceipt STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* transactionDate STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* downloads STUB_PROPERTY;
@property (readonly, nonatomic) SKPaymentTransaction* originalTransaction STUB_PROPERTY;
@end
