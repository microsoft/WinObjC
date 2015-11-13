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

#ifndef _GKSESSION_H_
#define _GKSESSION_H_

#import <Foundation/NSObject.h>
#import <GameKit/GKPublicConstants.h>

enum {
    GKSessionModeServer,
    GKSessionModeClient,
    GKSessionModePeer,
};
typedef uint32_t GKSessionMode;

enum {
    GKPeerStateAvailable,
    GKPeerStateUnavailable,
    GKPeerStateConnected,
    GKPeerStateDisconnected,
    GKPeerStateConnecting,
};
typedef uint32_t GKPeerConnectionState;

@class NSArray;
@class NSData;
@class NSError;

@protocol GKSessionDelegate
@end

@interface GKSession : NSObject

@property (assign) id<GKSessionDelegate> delegate;
@property (getter=isAvailable) BOOL available;
@property (readonly) NSString* peerID;

- (id)initWithSessionID:(NSString*)sessionID displayName:(NSString*)name sessionMode:(GKSessionMode)mode;
- (void)disconnectFromAllPeers;
- (void)setDataReceiveHandler:(id)handler withContext:(void*)context;
- (BOOL)sendDataToAllPeers:(NSData*)data withDataMode:(GKSendDataMode)mode error:(NSError**)error;
- (BOOL)sendData:(NSData*)data toPeers:(NSArray*)peers withDataMode:(GKSendDataMode)mode error:(NSError**)error;
- (NSString*)displayNameForPeer:(NSString*)peerID;

@end

#endif // _GKSESSION_H_