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

#ifndef _GKMATCHMAKER_H_
#define _GKMATCHMAKER_H_

#import <Foundation/NSObject.h>

@class NSArray;

@interface GKInvite : NSObject
@end

@interface GKMatchRequest : NSObject

@property (nonatomic, assign) NSUInteger maxPlayers;
@property (nonatomic, assign) NSUInteger minPlayers;
@property (nonatomic, assign) NSUInteger playerGroup;
@property (nonatomic, retain) NSArray *playersToInvite;

@end

@interface GKMatchmaker : NSObject

@property (nonatomic, copy) void (^inviteHandler)(GKInvite *acceptedInvite, NSArray *playerIDsToInvite);

+ (GKMatchmaker *)sharedMatchmaker;

@end


#endif /* _GKMATCHMAKER_H_ */