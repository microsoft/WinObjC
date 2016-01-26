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
#import <AVFoundation/AVAssetReaderOutput.h>

@class NSArray;
@class NSDictionary;
@class AVVideoComposition;
@protocol AVVideoCompositing;

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetReaderVideoCompositionOutput : AVAssetReaderOutput
+ (instancetype)assetReaderVideoCompositionOutputWithVideoTracks:(NSArray*)videoTracks
                                                   videoSettings:(NSDictionary*)videoSettings STUB_METHOD;
- (instancetype)initWithVideoTracks:(NSArray*)videoTracks videoSettings:(NSDictionary*)videoSettings STUB_METHOD;
@property (copy, nonatomic) AVVideoComposition* videoComposition STUB_PROPERTY;
@property (readonly, nonatomic) id<AVVideoCompositing> customVideoCompositor STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* videoSettings STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* videoTracks STUB_PROPERTY;
@end
