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

@class NSURL;
@class NSError;
@class NSData;
@class NSString;
@protocol AVAudioPlayerDelegate;
@class NSDictionary;
@class NSArray;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioPlayer : NSObject
- (instancetype)initWithContentsOfURL:(NSURL*)url error:(NSError* _Nullable*)outError;
- (instancetype)initWithData:(NSData*)data error:(NSError* _Nullable*)outError;
- (instancetype)initWithContentsOfURL:(NSURL*)url fileTypeHint:(NSString*)utiString error:(NSError* _Nullable*)outError;
- (instancetype)initWithData:(NSData*)data fileTypeHint:(NSString*)utiString error:(NSError* _Nullable*)outError;
- (BOOL)play;
- (BOOL)playAtTime:(NSTimeInterval)time STUB_METHOD;
- (void)pause;
- (void)stop;
- (BOOL)prepareToPlay STUB_METHOD;
@property (readonly, getter=isPlaying) BOOL playing;
@property float volume;
@property float pan;
@property float rate;
@property BOOL enableRate;
@property NSInteger numberOfLoops;
@property (assign) id<AVAudioPlayerDelegate> delegate;
@property (readonly) NSDictionary* settings STUB_PROPERTY;
@property (readonly) NSUInteger numberOfChannels STUB_PROPERTY;
@property (copy, nonatomic) NSArray* channelAssignments STUB_PROPERTY;
@property (readonly) NSTimeInterval duration;
@property NSTimeInterval currentTime;
@property (readonly) NSTimeInterval deviceCurrentTime;
@property (readonly) NSURL* url;
@property (readonly) NSData* data;
@property (getter=isMeteringEnabled) BOOL meteringEnabled STUB_PROPERTY;
- (float)averagePowerForChannel:(NSUInteger)channelNumber STUB_METHOD;
- (float)peakPowerForChannel:(NSUInteger)channelNumber STUB_METHOD;
- (void)updateMeters STUB_METHOD;
@end
