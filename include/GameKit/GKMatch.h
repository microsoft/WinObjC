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

#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSObject.h>

@protocol GKMatchDelegate;
@class NSArray;
@class GKPlayer;
@class NSData;
@class NSError;
@class NSString;
@class GKVoiceChat;

typedef NSInteger GKMatchSendDataMode;
enum {
    GKMatchSendDataReliable,
    GKMatchSendDataUnreliable,
};

typedef NSInteger GKPlayerConnectionState;
enum {
    GKPlayerStateUnknown,
    GKPlayerStateConnected,
    GKPlayerStateDisconnected,
};

GAMEKIT_EXPORT_CLASS
@interface GKMatch : NSObject <NSObject>
- (void)chooseBestHostingPlayerWithCompletionHandler:(void (^)(GKPlayer*))completionHandler STUB_METHOD;
- (BOOL)sendData:(NSData*)data toPlayers:(NSArray*)players dataMode:(GKMatchSendDataMode)mode error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)sendDataToAllPlayers:(NSData*)data withDataMode:(GKMatchSendDataMode)mode error:(NSError* _Nullable*)error STUB_METHOD;
- (void)chooseBestHostPlayerWithCompletionHandler:(void (^)(NSString*))completionHandler STUB_METHOD;
- (BOOL)sendData:(NSData*)data
       toPlayers:(NSArray*)playerIDs
    withDataMode:(GKMatchSendDataMode)mode
           error:(NSError* _Nullable*)error STUB_METHOD;
- (GKVoiceChat*)voiceChatWithName:(NSString*)name STUB_METHOD;
- (void)disconnect STUB_METHOD;
- (void)rematchWithCompletionHandler:(void (^)(GKMatch*, NSError*))completionHandler STUB_METHOD;
@property (assign, nonatomic) id<GKMatchDelegate> delegate STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger expectedPlayerCount STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* players STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* playerIDs STUB_PROPERTY;
@end
