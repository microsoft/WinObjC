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

//#include "RTHelpers.h"

#import <CoreFoundation/CFBase.h>
#import <Foundation/NSObject.h>
#import <StoreKit/SKPaymentQueue.h>
#import <StoreKit/SKPaymentTransaction.h>
#import <StoreKit/SKProduct.h>
#import <StoreKit/SKPayment.h>

static SKPaymentQueue* _defaultQueue;

@implementation SKPaymentTransaction
- (instancetype)initWithIdentifier:(NSString*)ident date:(NSDate*)date payment:(SKPayment*)payment {
    _transactionIdentifier = ident;
    _transactionDate = date;
    _transactionState = SKPaymentTransactionStatePurchased;
    _payment = payment;
    return self;
}
@end

@implementation SKPaymentQueue {
    NSMutableArray* _transactionObservers;
}

- (instancetype)init {
    _transactionObservers = [[NSMutableArray alloc] init];

    return [super init];
}

+ (instancetype)defaultQueue {
    if (!_defaultQueue) {
        _defaultQueue = [[SKPaymentQueue alloc] init];
    }

    return _defaultQueue;
}

+ (BOOL)canMakePayments {
    return TRUE;
}

- (void)addTransactionObserver:(id)observer {
    [_transactionObservers addObject:observer];
}

- (void)removeTransactionObserver:(id)observer {
    [_transactionObservers removeObject:observer];
}

#if WRL
HSTRING fromNS(NSString* str) {
    HSTRING ret;
    WindowsCreateString((const wchar_t*)[str rawCharacters], [str length], &ret);
    return ret;
}

- (void)processTransaction:(HSTRING)hReceipt withPayment:(SKPayment*)payment {
    NSString* receipt = _nsstringFromHstring(hReceipt);

    SKPaymentTransaction* transaction =
        [[SKPaymentTransaction alloc] initWithIdentifier:receipt date:[NSDate date] payment:payment];

    NSArray* transactions = [NSArray arrayWithObject:transaction];
    for (id<SKPaymentTransactionObserver> obs in _transactionObservers) {
        [obs paymentQueue:self updatedTransactions:transactions];
    }
}
#endif

- (void)finishTransaction:(SKPaymentTransaction*)transaction {
#if WRL
    NSString* identifier = transaction.payment.productIdentifier;
    HSTRING hid = fromNS(identifier);

    // Sadly desktop store doesn't support ReportProductFulfillment so we can't rebuy things...
    auto currentApp = getCurrentApp();
#endif
}

- (void)addPayment:(SKPayment*)payment {
#if WRL
    auto currentApp = getCurrentApp();

    auto identifier = fromNS(payment.productIdentifier);
    IAsyncOperation<HSTRING>* op;

    currentApp->RequestProductPurchaseAsync(identifier, true, &op);
    auto innerHandler = new CompletionHandler<HSTRING>([=](IAsyncOperation<HSTRING>* purchaseInfo) {
        HSTRING result;
        purchaseInfo->GetResults(&result);
        [self processTransaction:result withPayment:payment];
    });
    op->put_Completed(innerHandler);
    innerHandler->Release();

/*
currentApp->GetProductReceiptAsync(identifier, &op);

auto handler = new CompletionHandler<HSTRING>([&](IAsyncOperation<HSTRING>* receiptInfo) {
HSTRING result;
if (receiptInfo->GetResults(&result) != S_OK || result == nullptr) {
currentApp->RequestProductPurchaseAsync(identifier, true, &op);
auto innerHandler = new CompletionHandler<HSTRING>([&](IAsyncOperation<HSTRING>* purchaseInfo) {
purchaseInfo->GetResults(&result);
receipt = result;
[self processTransaction:receipt];
});
op->put_Completed(innerHandler);
innerHandler->Release();
} else {
receipt = result;
[self processTransaction:receipt];
}
});
op->put_Completed(handler);
handler->Release();
*/
#endif
}

- (NSArray*)transactions {
    return nil;
}

- (void)dealloc {
    [_transactionObservers release];
    return [super dealloc];
}

@end