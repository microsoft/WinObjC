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

@class GKInvite;
@class GKMatchRequest;
@protocol GKMatchmakerViewControllerDelegate;
@class NSString;
@class GKMatch;
@class GKPlayer;

GAMEKIT_EXPORT_CLASS
@interface GKMatchmakerViewController
    : UINavigationController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
- (id)initWithInvite:(GKInvite*)invite STUB_METHOD;
- (id)initWithMatchRequest:(GKMatchRequest*)request STUB_METHOD;
- (void)addPlayersToMatch:(GKMatch*)match STUB_METHOD;
- (void)setHostedPlayer:(NSString*)playerID connected:(BOOL)connected STUB_METHOD;
- (void)setHostedPlayer:(GKPlayer*)player didConnect:(BOOL)connected STUB_METHOD;
- (void)setHostedPlayerReady:(NSString*)player STUB_METHOD;
@property (assign, nonatomic) id<GKMatchmakerViewControllerDelegate> matchmakerDelegate STUB_PROPERTY;
@property (copy, nonatomic) NSString* defaultInvitationMessage STUB_PROPERTY;
@property (getter=isHosted, assign, nonatomic) BOOL hosted STUB_PROPERTY;
@property (readonly, retain, nonatomic) GKMatchRequest* matchRequest STUB_PROPERTY;
@end
