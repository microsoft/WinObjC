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

#import <AVFoundation/AVFoundation.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

@implementation AVAudioPlayerNode
/**
@Status Stub
@Notes
*/
- (void)scheduleBuffer:(AVAudioPCMBuffer*)buffer
                atTime:(AVAudioTime*)when
               options:(AVAudioPlayerNodeBufferOptions)options
     completionHandler:(AVAudioNodeCompletionHandler)completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)scheduleBuffer:(AVAudioPCMBuffer*)buffer completionHandler:(AVAudioNodeCompletionHandler)completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)scheduleFile:(AVAudioFile*)file atTime:(AVAudioTime*)when completionHandler:(AVAudioNodeCompletionHandler)completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)scheduleSegment:(AVAudioFile*)file
          startingFrame:(AVAudioFramePosition)startFrame
             frameCount:(AVAudioFrameCount)numberFrames
                 atTime:(AVAudioTime*)when
      completionHandler:(AVAudioNodeCompletionHandler)completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVAudioTime*)nodeTimeForPlayerTime:(AVAudioTime*)playerTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVAudioTime*)playerTimeForNodeTime:(AVAudioTime*)nodeTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)prepareWithFrameCount:(AVAudioFrameCount)frameCount {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)play {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)playAtTime:(AVAudioTime*)when {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)pause {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)stop {
    UNIMPLEMENTED();
}

@end
