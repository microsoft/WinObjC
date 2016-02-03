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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSDate;
@class NSInputStream;
@class NSOutputStream;
@class NSError;
@class NSDictionary;
@protocol NSUserActivityDelegate;
@class CSSearchableItemAttributeSet;
@class NSSet;
@class NSURL;

FOUNDATION_EXPORT_CLASS
@interface NSUserActivity : NSObject
- (instancetype)initWithActivityType:(NSString*)activityType STUB_METHOD;
- (instancetype)init STUB_METHOD;
@property (getter=isEligibleForPublicIndexing) BOOL eligibleForPublicIndexing STUB_PROPERTY;
@property (getter=isEligibleForSearch) BOOL eligibleForSearch STUB_PROPERTY;
@property (getter=isEligibleForHandoff) BOOL eligibleForHandoff STUB_PROPERTY;
@property (copy) NSDate* expirationDate STUB_PROPERTY;
@property BOOL supportsContinuationStreams STUB_PROPERTY;
- (void)getContinuationStreamsWithCompletionHandler:(void (^)(NSInputStream*, NSOutputStream*, NSError*))completionHandler STUB_METHOD;
@property (copy) NSDictionary* userInfo STUB_PROPERTY;
- (void)addUserInfoEntriesFromDictionary:(NSDictionary*)otherDictionary STUB_METHOD;
- (void)becomeCurrent STUB_METHOD;
- (void)resignCurrent STUB_METHOD;
@property (weak) id<NSUserActivityDelegate> delegate STUB_PROPERTY;
@property (assign) BOOL needsSave STUB_PROPERTY;
- (void)invalidate STUB_METHOD;
@property (readonly, copy) NSString* activityType STUB_PROPERTY;
@property (copy) NSString* title STUB_PROPERTY;
@property (copy) CSSearchableItemAttributeSet* contentAttributeSet STUB_PROPERTY;
@property (copy) NSSet* keywords STUB_PROPERTY;
@property (copy) NSSet* requiredUserInfoKeys STUB_PROPERTY;
@property (copy) NSURL* webpageURL STUB_PROPERTY;
@end

@protocol NSUserActivityDelegate <NSObject>
@optional
- (void)userActivity:(NSUserActivity*)userActivity
    didReceiveInputStream:(NSInputStream*)inputStream
             outputStream:(NSOutputStream*)outputStream;
- (void)userActivityWasContinued:(NSUserActivity*)userActivity;
- (void)userActivityWillSave:(NSUserActivity*)userActivity;
@end
