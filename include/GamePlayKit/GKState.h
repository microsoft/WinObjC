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

@class GKStateMachine;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKState : NSObject
- (instancetype)init STUB_METHOD;
+ (instancetype)state STUB_METHOD;
@property (readonly, nonatomic, retain) GKStateMachine* stateMachine STUB_PROPERTY;
- (BOOL)isValidNextState:(Class)stateClass STUB_METHOD;
- (void)didEnterWithPreviousState:(GKState*)previousState STUB_METHOD;
- (void)updateWithDeltaTime:(NSTimeInterval)seconds STUB_METHOD;
- (void)willExitWithNextState:(GKState*)nextState STUB_METHOD;
@end
