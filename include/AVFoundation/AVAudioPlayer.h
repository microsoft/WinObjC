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
- (instancetype)initWithContentsOfURL:(NSURL*)url error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initWithData:(NSData*)data error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initWithContentsOfURL:(NSURL*)url fileTypeHint:(NSString*)utiString error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initWithData:(NSData*)data fileTypeHint:(NSString*)utiString error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)play STUB_METHOD;
- (BOOL)playAtTime:(NSTimeInterval)time STUB_METHOD;
- (void)pause STUB_METHOD;
- (void)stop STUB_METHOD;
- (BOOL)prepareToPlay STUB_METHOD;
@property (readonly, getter=isPlaying) BOOL playing STUB_PROPERTY;
@property float volume STUB_PROPERTY;
@property float pan STUB_PROPERTY;
@property float rate STUB_PROPERTY;
@property BOOL enableRate STUB_PROPERTY;
@property NSInteger numberOfLoops STUB_PROPERTY;
@property (assign) id<AVAudioPlayerDelegate> delegate STUB_PROPERTY;
@property (readonly) NSDictionary* settings STUB_PROPERTY;
@property (readonly) NSUInteger numberOfChannels STUB_PROPERTY;
@property (copy, nonatomic) NSArray* channelAssignments STUB_PROPERTY;
@property (readonly) NSTimeInterval duration STUB_PROPERTY;
@property NSTimeInterval currentTime STUB_PROPERTY;
@property (readonly) NSTimeInterval deviceCurrentTime STUB_PROPERTY;
@property (readonly) NSURL* url STUB_PROPERTY;
@property (readonly) NSData* data STUB_PROPERTY;
@property (getter=isMeteringEnabled) BOOL meteringEnabled STUB_PROPERTY;
- (float)averagePowerForChannel:(NSUInteger)channelNumber STUB_METHOD;
- (float)peakPowerForChannel:(NSUInteger)channelNumber STUB_METHOD;
- (void)updateMeters STUB_METHOD;
@end
