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
#import <GamePlayKit/GKObstacle.h>
#import <GamePlayKit/GKType.h>

#import <Foundation/NSObject.h>

GAMEPLAYKIT_EXPORT_CLASS
@interface GKPolygonObstacle : GKObstacle
- (instancetype)initWithPoints:(vector_float2*)points count:(size_t)numPoints STUB_METHOD;
+ (instancetype)obstacleWithPoints:(vector_float2*)points count:(size_t)numPoints STUB_METHOD;
@property (readonly, nonatomic) NSUInteger vertexCount STUB_PROPERTY;
- (vector_float2)vertexAtIndex:(NSUInteger)index STUB_METHOD;
@end
