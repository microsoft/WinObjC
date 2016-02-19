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

#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class GKEntity;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKComponentSystem : NSObject <NSFastEnumeration>
- (instancetype)initWithComponentClass:(Class)classObj STUB_METHOD;
@property (readonly, nonatomic) Class componentClass STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSArray* components STUB_PROPERTY;
- (void)addComponent:(GKComponent*)component STUB_METHOD;
- (void)addComponentWithEntity:(GKEntity*)entity STUB_METHOD;
- (void)removeComponent:(GKComponent*)component STUB_METHOD;
- (void)removeComponentWithEntity:(GKEntity*)entity STUB_METHOD;
- (void)updateWithDeltaTime:(NSTimeInterval)seconds STUB_METHOD;
- (GKComponent*)objectAtIndexedSubscript:(NSUInteger)idx STUB_METHOD;
@end
