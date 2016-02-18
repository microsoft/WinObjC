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
#import <CoreMedia/CMTypes.h>

@class CALayer;
@class NSArray;

AVFOUNDATION_EXPORT_CLASS
@interface AVVideoCompositionCoreAnimationTool : NSObject
+ (instancetype)videoCompositionCoreAnimationToolWithAdditionalLayer:(CALayer*)layer asTrackID:(CMPersistentTrackID)trackID STUB_METHOD;
+ (instancetype)videoCompositionCoreAnimationToolWithPostProcessingAsVideoLayer:(CALayer*)videoLayer
                                                                        inLayer:(CALayer*)animationLayer STUB_METHOD;
+ (instancetype)videoCompositionCoreAnimationToolWithPostProcessingAsVideoLayers:(NSArray*)videoLayers
                                                                         inLayer:(CALayer*)animationLayer STUB_METHOD;
@end
