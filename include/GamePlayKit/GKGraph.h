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
@class GKGraphNode;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKGraph : NSObject
- (instancetype)initWithNodes:(NSArray*)nodes STUB_METHOD;
+ (instancetype)graphWithNodes:(NSArray*)nodes STUB_METHOD;
- (void)addNodes:(NSArray*)nodes STUB_METHOD;
- (void)connectNodeToLowestCostNode:(GKGraphNode*)node bidirectional:(BOOL)bidirectional STUB_METHOD;
- (void)removeNodes:(NSArray*)nodes STUB_METHOD;
@property (readonly, nonatomic) NSArray* nodes STUB_PROPERTY;
- (NSArray*)findPathFromNode:(GKGraphNode*)startNode toNode:(GKGraphNode*)endNode STUB_METHOD;
@end
