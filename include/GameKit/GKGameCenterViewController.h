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
#import <GameKit/GKLeaderboard.h>

#import <Foundation/NSObject.h>

#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UINavigationController.h>

@protocol GKGameCenterControllerDelegate;
@class NSString;

typedef enum {
    GKGameCenterViewControllerStateDefault = -1,
    GKGameCenterViewControllerStateLeaderboards,
    GKGameCenterViewControllerStateAchievements,
    GKGameCenterViewControllerStateChallenges,
} GKGameCenterViewControllerState;

GAMEKIT_EXPORT_CLASS
@interface GKGameCenterViewController
    : UINavigationController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
@property (assign, nonatomic) id<GKGameCenterControllerDelegate> gameCenterDelegate STUB_PROPERTY;
@property (assign, nonatomic) GKGameCenterViewControllerState viewState STUB_PROPERTY;
@property (retain, nonatomic) NSString* leaderboardIdentifier STUB_PROPERTY;
@property (retain, nonatomic) NSString* leaderboardCategory STUB_PROPERTY;
@property (assign, nonatomic) GKLeaderboardTimeScope leaderboardTimeScope STUB_PROPERTY;
@end
