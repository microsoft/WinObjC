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

@class GKChallenge;

@protocol GKChallengeEventHandlerDelegate <NSObject>
@optional
- (void)localPlayerDidSelectChallenge:(GKChallenge*)challenge;
- (void)localPlayerDidReceiveChallenge:(GKChallenge*)challenge;
- (BOOL)shouldShowBannerForLocallyReceivedChallenge:(GKChallenge*)challenge;
- (void)localPlayerDidCompleteChallenge:(GKChallenge*)challenge;
- (BOOL)shouldShowBannerForLocallyCompletedChallenge:(GKChallenge*)challenge;
- (void)remotePlayerDidCompleteChallenge:(GKChallenge*)challenge;
- (BOOL)shouldShowBannerForRemotelyCompletedChallenge:(GKChallenge*)challenge;
@end
