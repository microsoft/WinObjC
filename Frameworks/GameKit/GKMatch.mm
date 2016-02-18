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
#import <GameKit/GKMatch.h>

@implementation GKMatch
/**
 @Status Stub
 @Notes
*/
- (void)chooseBestHostingPlayerWithCompletionHandler:(void (^)(GKPlayer*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)sendData:(NSData*)data toPlayers:(NSArray*)players dataMode:(GKMatchSendDataMode)mode error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)sendDataToAllPlayers:(NSData*)data withDataMode:(GKMatchSendDataMode)mode error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)chooseBestHostPlayerWithCompletionHandler:(void (^)(NSString*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)sendData:(NSData*)data toPlayers:(NSArray*)playerIDs withDataMode:(GKMatchSendDataMode)mode error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (GKVoiceChat*)voiceChatWithName:(NSString*)name {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)disconnect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)rematchWithCompletionHandler:(void (^)(GKMatch*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

@end
