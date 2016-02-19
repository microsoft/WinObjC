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

@protocol SKPaymentTransactionObserver;
@class NSArray;
@class SKPayment;
@class SKPaymentTransaction;
@class NSString;

STOREKIT_EXPORT_CLASS
@interface SKPaymentQueue : NSObject <NSObject>
+ (BOOL)canMakePayments STUB_METHOD;
+ (instancetype)defaultQueue STUB_METHOD;
- (void)addTransactionObserver:(id<SKPaymentTransactionObserver>)observer STUB_METHOD;
- (void)removeTransactionObserver:(id<SKPaymentTransactionObserver>)observer STUB_METHOD;
@property (readonly, nonatomic) NSArray* transactions STUB_PROPERTY;
- (void)addPayment:(SKPayment*)payment STUB_METHOD;
- (void)finishTransaction:(SKPaymentTransaction*)transaction STUB_METHOD;
- (void)restoreCompletedTransactions STUB_METHOD;
- (void)restoreCompletedTransactionsWithApplicationUsername:(NSString*)username STUB_METHOD;
- (void)startDownloads:(NSArray*)downloads STUB_METHOD;
- (void)cancelDownloads:(NSArray*)downloads STUB_METHOD;
- (void)pauseDownloads:(NSArray*)downloads STUB_METHOD;
- (void)resumeDownloads:(NSArray*)downloads STUB_METHOD;
@end
