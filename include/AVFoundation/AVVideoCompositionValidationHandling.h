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

#import <AVFoundation/AVFoundationExport.h>
#import <Foundation/NSObject.h>
#import <CoreMedia/CMTimeRange.h>

@class AVVideoComposition;
@class NSString;
@protocol AVVideoCompositionInstruction;
@class AVVideoCompositionLayerInstruction;
@class AVAsset;

@protocol AVVideoCompositionValidationHandling <NSObject>
@optional
- (BOOL)videoComposition:(AVVideoComposition*)videoComposition shouldContinueValidatingAfterFindingInvalidValueForKey:(NSString*)key;
- (BOOL)videoComposition:(AVVideoComposition*)videoComposition shouldContinueValidatingAfterFindingEmptyTimeRange:(CMTimeRange)timeRange;
- (BOOL)videoComposition:(AVVideoComposition*)videoComposition
    shouldContinueValidatingAfterFindingInvalidTimeRangeInInstruction:(id<AVVideoCompositionInstruction>)videoCompositionInstruction;
- (BOOL)videoComposition:(AVVideoComposition*)videoComposition
    shouldContinueValidatingAfterFindingInvalidTrackIDInInstruction:(id<AVVideoCompositionInstruction>)videoCompositionInstruction
                                                   layerInstruction:(AVVideoCompositionLayerInstruction*)layerInstruction
                                                              asset:(AVAsset*)asset;
@end
