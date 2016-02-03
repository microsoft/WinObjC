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
#import <GamePlayKit/GKRandom.h>
#import <GamePlayKit/GKRandomSource.h>

#import <Foundation/NSObject.h>

GAMEPLAYKIT_EXPORT_CLASS
@interface GKMersenneTwisterRandomSource : GKRandomSource <GKRandom, NSObject, NSSecureCoding>
- (instancetype)init STUB_METHOD;
- (instancetype)initWithSeed:(uint64_t)seed STUB_METHOD;
@property (assign, nonatomic) uint64_t seed STUB_PROPERTY;
@end
