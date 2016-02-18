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

@class GKMatch;
@class NSData;
@class GKPlayer;
@class NSString;
@class NSError;

typedef NSInteger GKPlayerConnectionState;
enum {
    GKPlayerStateUnknown,
    GKPlayerStateConnected,
    GKPlayerStateDisconnected,
};

@protocol GKMatchDelegate <NSObject>
@optional
- (void)match:(GKMatch*)match didReceiveData:(NSData*)data forRecipient:(GKPlayer*)recipient fromRemotePlayer:(GKPlayer*)player;
- (void)match:(GKMatch*)match didReceiveData:(NSData*)data fromRemotePlayer:(GKPlayer*)player;
- (void)match:(GKMatch*)match didReceiveData:(NSData*)data fromPlayer:(NSString*)player;
- (void)match:(GKMatch*)match player:(GKPlayer*)player didChangeConnectionState:(GKPlayerConnectionState)state;
- (void)match:(GKMatch*)match player:(NSString*)player didChangeState:(GKPlayerConnectionState)state;
- (void)match:(GKMatch*)match didFailWithError:(NSError*)error;
- (BOOL)match:(GKMatch*)match shouldReinviteDisconnectedPlayer:(GKPlayer*)player;
- (BOOL)match:(GKMatch*)match shouldReinvitePlayer:(NSString*)playerID;
@end
