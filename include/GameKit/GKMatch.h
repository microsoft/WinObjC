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

#ifndef _GKMATCH_H_
#define _GKMATCH_H_

#import <Foundation/NSObject.h>

enum {
    GKPlayerStateUnknown,
    GKPlayerStateConnected,
    GKPlayerStateDisconnected
};
typedef uint32_t GKPlayerConnectionState;

enum {
    GKMatchSendDataReliable,
    GKMatchSendDataUnreliable
};
typedef int32_t GKMatchSendDataMode;

@class NSArray;
@class NSData;
@class NSError;

@protocol GKMatchDelegate <NSObject>
@end

@interface GKMatch : NSObject

@property (nonatomic, assign) id<GKMatchDelegate> delegate;
@property (nonatomic, readonly) NSArray *playerIDs;
@property (nonatomic, readonly) NSUInteger expectedPlayerCount;

- (void)disconnect;
- (BOOL)sendDataToAllPlayers:(NSData *)data withDataMode:(GKMatchSendDataMode)mode error:(NSError **)error;
- (BOOL)sendData:(NSData *)data toPlayers:(NSArray *)playerIDs withDataMode:(GKMatchSendDataMode)mode error:(NSError **)error;

@end

#endif /* _GKMATCH_H_ */