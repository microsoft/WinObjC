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
#import <GamePlayKit/GKComponent.h>

#import <Foundation/NSObject.h>

@class GKBehavior;

@protocol GKAgentDelegate;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKAgent : GKComponent <NSCopying, NSObject>
@property (retain, nonatomic) GKBehavior* behavior STUB_PROPERTY;
@property (nonatomic) float mass STUB_PROPERTY;
@property (nonatomic) float maxAcceleration STUB_PROPERTY;
@property (nonatomic) float maxSpeed STUB_PROPERTY;
@property (nonatomic) float radius STUB_PROPERTY;
@property (nonatomic, retain) id<GKAgentDelegate> delegate STUB_PROPERTY;
@property (readonly, nonatomic) float speed STUB_PROPERTY;
@end
