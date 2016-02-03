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

#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UINavigationController.h>

@protocol GKFriendRequestComposeViewControllerDelegate;
@class NSArray;
@class NSString;

GAMEKIT_EXPORT_CLASS
@interface GKFriendRequestComposeViewController
    : UINavigationController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
+ (NSUInteger)maxNumberOfRecipients STUB_METHOD;
- (void)addRecipientsWithEmailAddresses:(NSArray*)emailAddresses STUB_METHOD;
- (void)addRecipientPlayers:(NSArray*)players STUB_METHOD;
- (void)addRecipientsWithPlayerIDs:(NSArray*)playerIDs STUB_METHOD;
- (void)setMessage:(NSString*)message STUB_METHOD;
@property (assign, nonatomic) id<GKFriendRequestComposeViewControllerDelegate> composeViewDelegate STUB_PROPERTY;
@end
