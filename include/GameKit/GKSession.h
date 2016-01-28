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
@protocol GKSessionDelegate;
@class NSArray;
@class NSError;
@class NSData;

typedef enum {
    GKSendDataReliable,
    GKSendDataUnreliable,
} GKSendDataMode;

typedef enum {
    GKSessionModeServer,
    GKSessionModeClient,
    GKSessionModePeer,
} GKSessionMode;

typedef enum {
    GKPeerStateAvailable,
    GKPeerStateUnavailable,
    GKPeerStateConnected,
    GKPeerStateDisconnected,
    GKPeerStateConnecting
} GKPeerConnectionState;

typedef enum {
    GKSessionInvalidParameterError = 30500,
    GKSessionPeerNotFoundError = 30501,
    GKSessionDeclinedError = 30502,
    GKSessionTimedOutError = 30503,
    GKSessionCancelledError = 30504,
    GKSessionConnectionFailedError = 30505,
    GKSessionConnectionClosedError = 30506,
    GKSessionDataTooBigError = 30507,
    GKSessionNotConnectedError = 30508,
    GKSessionCannotEnableError = 30509,
    GKSessionInProgressError = 30510,
    GKSessionConnectivityError = 30201,
    GKSessionTransportError = 30202,
    GKSessionInternalError = 30203,
    GKSessionUnknownError = 30204,
    GKSessionSystemError = 30205,
} GKSessionError;

GAMEKIT_EXPORT NSString* const GKSessionErrorDomain;

GAMEKIT_EXPORT_CLASS
@interface GKSession : NSObject <NSObject>
- (id)initWithSessionID:(NSString*)sessionID displayName:(NSString*)name sessionMode:(GKSessionMode)mode STUB_METHOD;
- (NSArray*)peersWithConnectionState:(GKPeerConnectionState)state STUB_METHOD;
- (NSString*)displayNameForPeer:(NSString*)peerID STUB_METHOD;
- (void)connectToPeer:(NSString*)peerID withTimeout:(NSTimeInterval)timeout STUB_METHOD;
- (void)cancelConnectToPeer:(NSString*)peerID STUB_METHOD;
- (BOOL)acceptConnectionFromPeer:(NSString*)peerID error:(NSError**)error STUB_METHOD;
- (void)denyConnectionFromPeer:(NSString*)peerID STUB_METHOD;
- (void)setDataReceiveHandler:(id)handler withContext:(void*)context STUB_METHOD;
- (BOOL)sendData:(NSData*)data toPeers:(NSArray*)peers withDataMode:(GKSendDataMode)mode error:(NSError**)error STUB_METHOD;
- (BOOL)sendDataToAllPeers:(NSData*)data withDataMode:(GKSendDataMode)mode error:(NSError**)error STUB_METHOD;
- (void)disconnectFromAllPeers STUB_METHOD;
- (void)disconnectPeerFromAllPeers:(NSString*)peerID STUB_METHOD;
@property (readonly) NSString* displayName STUB_PROPERTY;
@property (readonly) NSString* peerID STUB_PROPERTY;
@property (readonly) NSString* sessionID STUB_PROPERTY;
@property (readonly) GKSessionMode sessionMode STUB_PROPERTY;
@property (assign) id<GKSessionDelegate> delegate STUB_PROPERTY;
@property (getter=isAvailable) BOOL available STUB_PROPERTY;
@property (assign) NSTimeInterval disconnectTimeout STUB_PROPERTY;
@end
