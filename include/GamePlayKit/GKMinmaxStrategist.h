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

@protocol GKGameModel;
@protocol GKRandom;
@protocol GKGameModelUpdate;
@protocol GKGameModelPlayer;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKMinmaxStrategist : NSObject
@property (retain, nonatomic) id<GKGameModel> gameModel STUB_PROPERTY;
@property (assign, nonatomic) NSInteger maxLookAheadDepth STUB_PROPERTY;
@property (retain, nonatomic) id<GKRandom> randomSource STUB_PROPERTY;
- (id<GKGameModelUpdate>)bestMoveForPlayer:(id<GKGameModelPlayer>)player STUB_METHOD;
- (id<GKGameModelUpdate>)randomMoveForPlayer:(id<GKGameModelPlayer>)player fromNumberOfBestMoves:(NSInteger)numMovesToConsider STUB_METHOD;
@end
