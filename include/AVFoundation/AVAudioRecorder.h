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
@class NSDictionary;
@class NSError;
@protocol AVAudioRecorderDelegate;
@class NSArray;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioRecorder : NSObject
- (instancetype)initWithURL:(NSURL*)url settings:(NSDictionary*)settings error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)prepareToRecord STUB_METHOD;
- (BOOL)record STUB_METHOD;
- (BOOL)recordAtTime:(NSTimeInterval)time STUB_METHOD;
- (BOOL)recordForDuration:(NSTimeInterval)duration STUB_METHOD;
- (BOOL)recordAtTime:(NSTimeInterval)time forDuration:(NSTimeInterval)duration STUB_METHOD;
- (void)pause STUB_METHOD;
- (void)stop STUB_METHOD;
@property (assign) id<AVAudioRecorderDelegate> delegate STUB_PROPERTY;
- (BOOL)deleteRecording STUB_METHOD;
@property (readonly, getter=isRecording) BOOL recording STUB_PROPERTY;
@property (readonly) NSURL* url STUB_PROPERTY;
@property (copy, nonatomic) NSArray* channelAssignments STUB_PROPERTY;
@property (readonly) NSTimeInterval currentTime STUB_PROPERTY;
@property (readonly) NSTimeInterval deviceCurrentTime STUB_PROPERTY;
@property (readonly) NSDictionary* settings STUB_PROPERTY;
@property (getter=isMeteringEnabled) BOOL meteringEnabled STUB_PROPERTY;
- (void)updateMeters STUB_METHOD;
- (float)peakPowerForChannel:(NSUInteger)channelNumber STUB_METHOD;
- (float)averagePowerForChannel:(NSUInteger)channelNumber STUB_METHOD;
@end
