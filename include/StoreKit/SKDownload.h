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

@class NSString;
@class SKPaymentTransaction;
@class NSError;
@class NSURL;

typedef NSInteger SKDownloadState;
enum {
    SKDownloadStateWaiting,
    SKDownloadStateActive,
    SKDownloadStatePaused,
    SKDownloadStateFinished,
    SKDownloadStateFailed,
    SKDownloadStateCancelled,
};

STOREKIT_EXPORT const NSTimeInterval SKDownloadTimeRemainingUnknown;

STOREKIT_EXPORT_CLASS
@interface SKDownload : NSObject <NSObject>
@property (readonly, nonatomic) NSString* contentIdentifier STUB_PROPERTY;
@property (readonly, nonatomic) long long contentLength STUB_PROPERTY;
@property (readonly, nonatomic) NSString* contentVersion STUB_PROPERTY;
@property (readonly, nonatomic) SKPaymentTransaction* transaction STUB_PROPERTY;
@property (readonly, nonatomic) SKDownloadState downloadState STUB_PROPERTY;
@property (readonly, nonatomic) float progress STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval timeRemaining STUB_PROPERTY;
@property (readonly, nonatomic) NSError* error STUB_PROPERTY;
@property (readonly, nonatomic) NSURL* contentURL STUB_PROPERTY;
@end
