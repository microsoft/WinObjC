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
#import <GamePlayKit/GKType.h>

@class NSArray;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKPath : NSObject
- (instancetype)initWithPoints:(vector_float2*)points count:(size_t)count radius:(float)radius cyclical:(BOOL)cyclical STUB_METHOD;
+ (instancetype)pathWithPoints:(vector_float2*)points count:(size_t)count radius:(float)radius cyclical:(BOOL)cyclical STUB_METHOD;
- (instancetype)initWithGraphNodes:(NSArray*)graphNodes radius:(float)radius STUB_METHOD;
+ (instancetype)pathWithGraphNodes:(NSArray*)graphNodes radius:(float)radius STUB_METHOD;
@property (assign, nonatomic) float radius STUB_PROPERTY;
@property (getter=isCyclical, assign, nonatomic) BOOL cyclical STUB_PROPERTY;
@property (readonly) NSUInteger numPoints STUB_PROPERTY;
- (vector_float2)pointAtIndex:(NSUInteger)index STUB_METHOD;
@end
