//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <Foundation/Foundation.h>
#import <AVFoundation/AVCaptureOutput.h>
#import <CoreMedia/CMTime.h>

@class NSDictionary;
@class NSString;
@class NSArray;
@protocol AVCaptureVideoDataOutputSampleBufferDelegate;

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureVideoDataOutput : AVCaptureOutput
@property (copy, nonatomic) NSDictionary* videoSettings STUB_PROPERTY;
@property (nonatomic) CMTime minFrameDuration STUB_PROPERTY;
@property (nonatomic) BOOL alwaysDiscardsLateVideoFrames STUB_PROPERTY;
- (NSDictionary*)recommendedVideoSettingsForAssetWriterWithOutputFileType:(NSString*)outputFileType STUB_METHOD;
@property (readonly, nonatomic) NSArray* availableVideoCVPixelFormatTypes STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* availableVideoCodecTypes STUB_PROPERTY;
- (void)setSampleBufferDelegate:(id<AVCaptureVideoDataOutputSampleBufferDelegate>)sampleBufferDelegate
                          queue:(dispatch_queue_t)sampleBufferCallbackQueue STUB_METHOD;
@property (readonly, nonatomic) id<AVCaptureVideoDataOutputSampleBufferDelegate> sampleBufferDelegate STUB_PROPERTY;
@property (readonly, nonatomic) dispatch_queue_t sampleBufferCallbackQueue STUB_PROPERTY;
@end
