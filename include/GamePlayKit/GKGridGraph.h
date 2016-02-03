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
#import <GamePlayKit/GKGraph.h>
#import <GamePlayKit/GKType.h>

#import <Foundation/NSObject.h>

@class GKGridGraphNode;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKGridGraph : GKGraph
- (instancetype)initFromGridStartingAt:(vector_int2)position
                                 width:(int)width
                                height:(int)height
                      diagonalsAllowed:(BOOL)diagonalsAllowed STUB_METHOD;
+ (instancetype)graphFromGridStartingAt:(vector_int2)position
                                  width:(int)width
                                 height:(int)height
                       diagonalsAllowed:(BOOL)diagonalsAllowed STUB_METHOD;
- (GKGridGraphNode*)nodeAtGridPosition:(vector_int2)position STUB_METHOD;
- (void)connectNodeToAdjacentNodes:(GKGridGraphNode*)node STUB_METHOD;
@property (readonly, nonatomic) BOOL diagonalsAllowed STUB_PROPERTY;
@property (readonly, nonatomic) vector_int2 gridOrigin STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger gridWidth STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger gridHeight STUB_PROPERTY;
@end
