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

@class GKPlayer;
@class NSString;
@class NSArray;

typedef NSInteger GKVoiceChatPlayerState;

enum {
    GKVoiceChatPlayerConnected,
    GKVoiceChatPlayerDisconnected,
    GKVoiceChatPlayerSpeaking,
    GKVoiceChatPlayerSilent,
    GKVoiceChatPlayerConnecting,
};

GAMEKIT_EXPORT_CLASS
@interface GKVoiceChat : NSObject <NSObject>
+ (BOOL)isVoIPAllowed STUB_METHOD;
- (void)start STUB_METHOD;
- (void)stop STUB_METHOD;
- (void)setMute:(BOOL)isMuted forPlayer:(NSString*)player STUB_METHOD;
- (void)setPlayer:(GKPlayer*)player muted:(BOOL)isMuted STUB_METHOD;
@property (assign, nonatomic) float volume STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* players STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* playerIDs STUB_PROPERTY;
@property (getter=isActive, assign, nonatomic) BOOL active STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^playerVoiceChatStateDidChangeHandler)(GKPlayer*, GKVoiceChatPlayerState) STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^playerStateUpdateHandler)(NSString*, GKVoiceChatPlayerState) STUB_PROPERTY;
@end
