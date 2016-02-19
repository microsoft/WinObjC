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

#import <GameKit/GameKitExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;
@class NSError;
@class NSDate;
@class NSData;
@class GKTurnBasedParticipant;

typedef enum _GKTurnBasedExchangeStatus : int8_t {
    GKTurnBasedExchangeStatusUnknown = 0,
    GKTurnBasedExchangeStatusActive = 1,
    GKTurnBasedExchangeStatusComplete = 2,
    GKTurnBasedExchangeStatusResolved = 3,
    GKTurnBasedExchangeStatusCanceled = 4,
} GKTurnBasedExchangeStatus;

GAMEKIT_EXPORT const NSTimeInterval GKExchangeTimeoutDefault;
GAMEKIT_EXPORT const NSTimeInterval GKExchangeTimeoutNone;

GAMEKIT_EXPORT_CLASS
@interface GKTurnBasedExchange : NSObject <NSObject>
- (void)cancelWithLocalizableMessageKey:(NSString*)key
                              arguments:(NSArray*)arguments
                      completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)replyWithLocalizableMessageKey:(NSString*)key
                             arguments:(NSArray*)arguments
                                  data:(NSData*)data
                     completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
@property (readonly, nonatomic) NSDate* sendDate STUB_PROPERTY;
@property (readonly, nonatomic) GKTurnBasedParticipant* sender STUB_PROPERTY;
@property (readonly, assign, nonatomic) GKTurnBasedExchangeStatus status STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* timeoutDate STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* completionDate STUB_PROPERTY;
@property (readonly, nonatomic) NSData* data STUB_PROPERTY;
@property (readonly, nonatomic) NSString* exchangeID STUB_PROPERTY;
@property (readonly, nonatomic) NSString* message STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* recipients STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* replies STUB_PROPERTY;
@end
