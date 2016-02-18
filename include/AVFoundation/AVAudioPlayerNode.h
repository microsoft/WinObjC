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
#import <AVFoundation/AVAudioMixing.h>
#import <Foundation/NSObject.h>
#import <AVFoundation/AVAudioNode.h>
#import <AVFoundation/AVFoundationTypes.h>

@class AVAudioPCMBuffer;
@class AVAudioTime;
@class AVAudioFile;

typedef NSUInteger AVAudioPlayerNodeBufferOptions;
enum {
    AVAudioPlayerNodeBufferLoops = 1UL << 0,
    AVAudioPlayerNodeBufferInterrupts = 1UL << 1,
    AVAudioPlayerNodeBufferInterruptsAtLoop = 1UL << 2
};

typedef void (^AVAudioNodeCompletionHandler)();

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioPlayerNode : AVAudioNode <AVAudioMixing>
- (void)scheduleBuffer:(AVAudioPCMBuffer*)buffer
                atTime:(AVAudioTime*)when
               options:(AVAudioPlayerNodeBufferOptions)options
     completionHandler:(AVAudioNodeCompletionHandler)completionHandler STUB_METHOD;
- (void)scheduleBuffer:(AVAudioPCMBuffer*)buffer completionHandler:(AVAudioNodeCompletionHandler)completionHandler STUB_METHOD;
- (void)scheduleFile:(AVAudioFile*)file
              atTime:(AVAudioTime*)when
   completionHandler:(AVAudioNodeCompletionHandler)completionHandler STUB_METHOD;
- (void)scheduleSegment:(AVAudioFile*)file
          startingFrame:(AVAudioFramePosition)startFrame
             frameCount:(AVAudioFrameCount)numberFrames
                 atTime:(AVAudioTime*)when
      completionHandler:(AVAudioNodeCompletionHandler)completionHandler STUB_METHOD;
- (AVAudioTime*)nodeTimeForPlayerTime:(AVAudioTime*)playerTime STUB_METHOD;
- (AVAudioTime*)playerTimeForNodeTime:(AVAudioTime*)nodeTime STUB_METHOD;
- (void)prepareWithFrameCount:(AVAudioFrameCount)frameCount STUB_METHOD;
- (void)play STUB_METHOD;
- (void)playAtTime:(AVAudioTime*)when STUB_METHOD;
@property (readonly, getter=isPlaying, nonatomic) BOOL playing STUB_PROPERTY;
- (void)pause STUB_METHOD;
- (void)stop STUB_METHOD;

@property (nonatomic) float obstruction STUB_PROPERTY;
@property (nonatomic) float occlusion STUB_PROPERTY;
@property (nonatomic) AVAudio3DPoint position STUB_PROPERTY;
@property (nonatomic) float rate STUB_PROPERTY;
@property (nonatomic) AVAudio3DMixingRenderingAlgorithm renderingAlgorithm STUB_PROPERTY;
@property (nonatomic) float reverbBlend STUB_PROPERTY;
@property (nonatomic) float pan STUB_PROPERTY;
@property (nonatomic) float volume STUB_PROPERTY;
@end
