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
#import <AVFoundation/AVAudioBuffer.h>
#import <AVFoundation/AVFoundationTypes.h>

@class AVAudioFormat;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioPCMBuffer : AVAudioBuffer <NSCopying, NSMutableCopying>
- (instancetype)initWithPCMFormat:(AVAudioFormat*)format frameCapacity:(AVAudioFrameCount)frameCapacity STUB_METHOD;
@property (nonatomic) AVAudioFrameCount frameLength STUB_PROPERTY;
// removed nonnull from the properties with pointers below as it was causing an
// error
@property (readonly, nonatomic) float* const* floatChannelData STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioFrameCount frameCapacity STUB_PROPERTY;
@property (readonly, nonatomic) int16_t* const* int16ChannelData STUB_PROPERTY;
@property (readonly, nonatomic) int32_t* const* int32ChannelData STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger stride STUB_PROPERTY;
@end
