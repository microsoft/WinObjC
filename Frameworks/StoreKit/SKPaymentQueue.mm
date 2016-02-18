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

#import <StoreKit/SKPaymentQueue.h>
#import <StubReturn.h>

@implementation SKPaymentQueue
/**
 @Status Stub
 @Notes
*/
+ (BOOL)canMakePayments {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)defaultQueue {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addTransactionObserver:(id<SKPaymentTransactionObserver>)observer {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeTransactionObserver:(id<SKPaymentTransactionObserver>)observer {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addPayment:(SKPayment*)payment {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)finishTransaction:(SKPaymentTransaction*)transaction {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)restoreCompletedTransactions {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)restoreCompletedTransactionsWithApplicationUsername:(NSString*)username {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startDownloads:(NSArray*)downloads {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancelDownloads:(NSArray*)downloads {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)pauseDownloads:(NSArray*)downloads {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)resumeDownloads:(NSArray*)downloads {
    UNIMPLEMENTED();
}

@end
