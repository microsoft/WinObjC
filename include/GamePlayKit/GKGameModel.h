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

#import <GamePlayKit/GameplayKitExport.h>
#import <Foundation/NSObject.h>

@class NSArray;
@protocol GKGameModelPlayer;
@protocol GKGameModelUpdate;

#define GKGameModelMaxScore (1 << 24)
#define GKGameModelMinScore (-(1 << 24))

@protocol GKGameModel <NSCopying, NSObject>
@property (nonatomic, readonly) NSArray* players;
@property (nonatomic, readonly) id<GKGameModelPlayer> activePlayer;
- (NSArray*)gameModelUpdatesForPlayer:(id<GKGameModelPlayer>)player;
- (void)applyGameModelUpdate:(id<GKGameModelUpdate>)gameModelUpdate;
- (void)setGameModel:(id<GKGameModel>)gameModel;
- (NSInteger)scoreForPlayer:(id<GKGameModelPlayer>)player;
- (BOOL)isLossForPlayer:(id<GKGameModelPlayer>)player;
- (BOOL)isWinForPlayer:(id<GKGameModelPlayer>)player;
@end
