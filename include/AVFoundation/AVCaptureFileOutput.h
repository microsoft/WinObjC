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
#import <AVFoundation/AVCaptureOutput.h>
#import <CoreMedia/CMTime.h>

@class NSURL;
@protocol AVCaptureFileOutputRecordingDelegate;

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureFileOutput : AVCaptureOutput
- (void)startRecordingToOutputFileURL:(NSURL*)outputFileURL
                    recordingDelegate:(id<AVCaptureFileOutputRecordingDelegate>)delegate STUB_METHOD;
- (void)stopRecording STUB_METHOD;
@property (readonly, getter=isRecording, nonatomic) BOOL recording STUB_PROPERTY;
@property (nonatomic) CMTime maxRecordedDuration STUB_PROPERTY;
@property (nonatomic) int64_t maxRecordedFileSize STUB_PROPERTY;
@property (nonatomic) int64_t minFreeDiskSpaceLimit STUB_PROPERTY;
@property (readonly, nonatomic) NSURL* outputFileURL STUB_PROPERTY;
@property (readonly, nonatomic) CMTime recordedDuration STUB_PROPERTY;
@property (readonly, nonatomic) int64_t recordedFileSize STUB_PROPERTY;
@end
