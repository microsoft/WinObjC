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

#import <StubReturn.h>
#import <GameKit/GKSession.h>

NSString* const GKSessionErrorDomain = @"GKSessionErrorDomain";

@implementation GKSession
/**
 @Status Stub
 @Notes
*/
- (id)initWithSessionID:(NSString*)sessionID displayName:(NSString*)name sessionMode:(GKSessionMode)mode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)peersWithConnectionState:(GKPeerConnectionState)state {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)displayNameForPeer:(NSString*)peerID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)connectToPeer:(NSString*)peerID withTimeout:(NSTimeInterval)timeout {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancelConnectToPeer:(NSString*)peerID {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)acceptConnectionFromPeer:(NSString*)peerID error:(NSError**)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)denyConnectionFromPeer:(NSString*)peerID {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDataReceiveHandler:(id)handler withContext:(void*)context {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)sendData:(NSData*)data toPeers:(NSArray*)peers withDataMode:(GKSendDataMode)mode error:(NSError**)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)sendDataToAllPeers:(NSData*)data withDataMode:(GKSendDataMode)mode error:(NSError**)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)disconnectFromAllPeers {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)disconnectPeerFromAllPeers:(NSString*)peerID {
    UNIMPLEMENTED();
}

@end
