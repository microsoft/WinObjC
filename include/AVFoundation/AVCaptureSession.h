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
#import <CoreMedia/CMSync.h>

@class NSString;
@class NSArray;
@class AVCaptureInput;
@class AVCaptureOutput;
@class AVCaptureConnection;

AVFOUNDATION_EXPORT NSString* const AVCaptureSessionErrorKey;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPresetPhoto;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPresetHigh;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPresetMedium;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPresetLow;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPreset352x288;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPreset640x480;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPreset1280x720;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPreset1920x1080;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPresetiFrame960x540;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPresetiFrame1280x720;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionPresetInputPriority;

AVFOUNDATION_EXPORT NSString* const AVCaptureSessionRuntimeErrorNotification;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionDidStartRunningNotification;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionDidStopRunningNotification;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionWasInterruptedNotification;
AVFOUNDATION_EXPORT NSString* const AVCaptureSessionInterruptionEndedNotification;

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureSession : NSObject
@property (readonly, nonatomic) NSArray* inputs STUB_PROPERTY;
- (BOOL)canAddInput:(AVCaptureInput*)input STUB_METHOD;
- (void)addInput:(AVCaptureInput*)input STUB_METHOD;
- (void)removeInput:(AVCaptureInput*)input STUB_METHOD;
@property (readonly, nonatomic) NSArray* outputs STUB_PROPERTY;
- (BOOL)canAddOutput:(AVCaptureOutput*)output STUB_METHOD;
- (void)addOutput:(AVCaptureOutput*)output STUB_METHOD;
- (void)removeOutput:(AVCaptureOutput*)output STUB_METHOD;
- (void)startRunning STUB_METHOD;
- (void)stopRunning STUB_METHOD;
@property (readonly, getter=isRunning, nonatomic) BOOL running STUB_PROPERTY;
@property (readonly, getter=isInterrupted, nonatomic) BOOL interrupted STUB_PROPERTY;
- (void)beginConfiguration STUB_METHOD;
- (void)commitConfiguration STUB_METHOD;
@property (copy, nonatomic) NSString* sessionPreset STUB_PROPERTY;
- (BOOL)canSetSessionPreset:(NSString*)preset STUB_METHOD;
- (void)addConnection:(AVCaptureConnection*)connection STUB_METHOD;
- (BOOL)canAddConnection:(AVCaptureConnection*)connection STUB_METHOD;
- (void)addInputWithNoConnections:(AVCaptureInput*)input STUB_METHOD;
- (void)addOutputWithNoConnections:(AVCaptureOutput*)output STUB_METHOD;
- (void)removeConnection:(AVCaptureConnection*)connection STUB_METHOD;
@property (nonatomic) BOOL usesApplicationAudioSession STUB_PROPERTY;
@property (nonatomic) BOOL automaticallyConfiguresApplicationAudioSession STUB_PROPERTY;
@property (readonly, nonatomic) CMClockRef masterClock STUB_PROPERTY;
@end
