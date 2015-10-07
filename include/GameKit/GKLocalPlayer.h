//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _GKLOCALPLAYER_H_
#define _GKLOCALPLAYER_H_

#import <GameKit/GameKitExport.h>
#import <GameKit/GKPlayer.h>

@class UIViewController;

GAMEKIT_EXPORT_CLASS
@interface GKLocalPlayer : GKPlayer

@property (nonatomic, copy) void(^authenticateHandler)(UIViewController *viewController, NSError *err);
@property (nonatomic, readonly, getter=isAuthenticated) BOOL authenticated;

+ (GKLocalPlayer *)localPlayer;
- (void)authenticateWithCompletionHandler:(void (^)(NSError *error))completionHandler;
- (void)loadFriendsWithCompletionHandler:(void (^)(NSArray *friends, NSError *error))completionHandler;

@end

SB_EXPORT NSString *GKPlayerAuthenticationDidChangeNotificationName;

#endif /* _GKLOCALPLAYER_H_ */