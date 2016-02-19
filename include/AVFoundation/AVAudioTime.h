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
#import <CoreAudio/CoreAudioTypes.h>
#import <AVFoundation/AVFoundationTypes.h>

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioTime : NSObject
- (instancetype)initWithAudioTimeStamp:(const AudioTimeStamp*)ts sampleRate:(double)sampleRate STUB_METHOD;
- (instancetype)initWithHostTime:(uint64_t)hostTime STUB_METHOD;
- (instancetype)initWithHostTime:(uint64_t)hostTime sampleTime:(AVAudioFramePosition)sampleTime atRate:(double)sampleRate STUB_METHOD;
- (instancetype)initWithSampleTime:(AVAudioFramePosition)sampleTime atRate:(double)sampleRate STUB_METHOD;
+ (instancetype)timeWithAudioTimeStamp:(const AudioTimeStamp*)ts sampleRate:(double)sampleRate STUB_METHOD;
+ (instancetype)timeWithHostTime:(uint64_t)hostTime sampleTime:(AVAudioFramePosition)sampleTime atRate:(double)sampleRate STUB_METHOD;
+ (instancetype)timeWithSampleTime:(AVAudioFramePosition)sampleTime atRate:(double)sampleRate STUB_METHOD;
+ (instancetype)timeWithHostTime:(uint64_t)hostTime STUB_METHOD;
- (AVAudioTime*)extrapolateTimeFromAnchor:(AVAudioTime*)anchorTime STUB_METHOD;
@property (readonly, nonatomic) uint64_t hostTime STUB_PROPERTY;
@property (readonly, getter=isHostTimeValid, nonatomic) BOOL hostTimeValid STUB_PROPERTY;
+ (uint64_t)hostTimeForSeconds:(NSTimeInterval)seconds STUB_METHOD;
+ (NSTimeInterval)secondsForHostTime:(uint64_t)hostTime STUB_METHOD;
@property (readonly, nonatomic) double sampleRate STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioFramePosition sampleTime STUB_PROPERTY;
@property (readonly, getter=isSampleTimeValid, nonatomic) BOOL sampleTimeValid STUB_PROPERTY;
@property (readonly, nonatomic) AudioTimeStamp audioTimeStamp STUB_PROPERTY;
@end
