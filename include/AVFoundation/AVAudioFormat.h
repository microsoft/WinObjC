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

@class AVAudioChannelLayout;
@class NSDictionary;

typedef NSUInteger AVAudioCommonFormat;
enum {
    AVAudioOtherFormat = 0,
    AVAudioPCMFormatFloat32 = 1,
    AVAudioPCMFormatFloat64 = 2,
    AVAudioPCMFormatInt16 = 3,
    AVAudioPCMFormatInt32 = 4
};

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioFormat : NSObject <NSSecureCoding>
- (instancetype)initStandardFormatWithSampleRate:(double)sampleRate channelLayout:(AVAudioChannelLayout*)layout STUB_METHOD;
- (instancetype)initStandardFormatWithSampleRate:(double)sampleRate channels:(AVAudioChannelCount)channels STUB_METHOD;
- (instancetype)initWithCommonFormat:(AVAudioCommonFormat)format
                          sampleRate:(double)sampleRate
                            channels:(AVAudioChannelCount)channels
                         interleaved:(BOOL)interleaved STUB_METHOD;
- (instancetype)initWithCommonFormat:(AVAudioCommonFormat)format
                          sampleRate:(double)sampleRate
                         interleaved:(BOOL)interleaved
                       channelLayout:(AVAudioChannelLayout*)layout STUB_METHOD;
- (instancetype)initWithSettings:(NSDictionary*)settings STUB_METHOD;
- (instancetype)initWithStreamDescription:(const AudioStreamBasicDescription*)asbd STUB_METHOD;
- (instancetype)initWithStreamDescription:(const AudioStreamBasicDescription*)asbd channelLayout:(AVAudioChannelLayout*)layout STUB_METHOD;
@property (readonly, nonatomic) const AudioStreamBasicDescription* streamDescription STUB_PROPERTY;
- (BOOL)isEqual:(id)object STUB_METHOD;
@property (readonly, nonatomic) AVAudioChannelCount channelCount STUB_PROPERTY;
@property (readonly, nonatomic) const AVAudioChannelLayout* channelLayout STUB_PROPERTY;
@property (readonly, nonatomic) double sampleRate STUB_PROPERTY;
@property (readonly, getter=isStandard, nonatomic) BOOL standard STUB_PROPERTY;
@property (readonly, getter=isInterleaved, nonatomic) BOOL interleaved STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioCommonFormat commonFormat STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* settings STUB_PROPERTY;
@end
