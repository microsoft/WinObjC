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

@class UIViewController;
@class NSArray;
@class NSError;
@class NSDate;
@class NSString;
@class GKPlayer;

typedef void (^GKChallengeComposeCompletionBlock)(UIViewController* composeController, BOOL didIssueChallenge, NSArray* sentPlayerIDs);

typedef NS_ENUM(NSUInteger, GKChallengeState){
    GKChallengeStateInvalid = 0,
    GKChallengeStatePending = 1,
    GKChallengeStateCompleted = 2,
    GKChallengeStateDeclined = 3,
};

GAMEKIT_EXPORT_CLASS
@interface GKChallenge : NSObject <NSCoding, NSObject, NSSecureCoding>
+ (void)loadReceivedChallengesWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)decline STUB_METHOD;
@property (readonly, retain, nonatomic) NSDate* issueDate STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* issuingPlayerID STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* receivingPlayerID STUB_PROPERTY;
@property (readonly, copy, nonatomic) GKPlayer* issuingPlayer STUB_PROPERTY;
@property (readonly, copy, nonatomic) GKPlayer* receivingPlayer STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* message STUB_PROPERTY;
@property (readonly, assign, nonatomic) GKChallengeState state STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSDate* completionDate STUB_PROPERTY;
@end
