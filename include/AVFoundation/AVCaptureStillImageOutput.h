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
#import <CoreMedia/CMSampleBuffer.h>

@class AVCaptureConnection;
@class NSError;
@class NSDictionary;
@class NSArray;
@class NSData;
@class AVCaptureBracketedStillImageSettings;

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureStillImageOutput : AVCaptureOutput
- (void)captureStillImageAsynchronouslyFromConnection:(AVCaptureConnection*)connection
                                    completionHandler:(void (^)(CMSampleBufferRef, NSError*))handler STUB_METHOD;
@property (readonly, getter=isCapturingStillImage) BOOL capturingStillImage STUB_PROPERTY;
@property (readonly, getter=isStillImageStabilizationActive, nonatomic) BOOL stillImageStabilizationActive STUB_PROPERTY;
@property (nonatomic) BOOL automaticallyEnablesStillImageStabilizationWhenAvailable STUB_PROPERTY;
@property (readonly, getter=isStillImageStabilizationSupported, nonatomic) BOOL stillImageStabilizationSupported STUB_PROPERTY;
@property (getter=isHighResolutionStillImageOutputEnabled, nonatomic) BOOL highResolutionStillImageOutputEnabled STUB_PROPERTY;
@property (copy, nonatomic) NSDictionary* outputSettings STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* availableImageDataCVPixelFormatTypes STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* availableImageDataCodecTypes STUB_PROPERTY;
+ (NSData*)jpegStillImageNSDataRepresentation:(CMSampleBufferRef)jpegSampleBuffer STUB_METHOD;
- (void)captureStillImageBracketAsynchronouslyFromConnection:(AVCaptureConnection*)connection
                                           withSettingsArray:(NSArray*)settings
                                           completionHandler:
                                               (void (^)(CMSampleBufferRef, AVCaptureBracketedStillImageSettings*, NSError*))handler
    STUB_METHOD;
@property (readonly, nonatomic) NSUInteger maxBracketedCaptureStillImageCount STUB_PROPERTY;
- (void)prepareToCaptureStillImageBracketFromConnection:(AVCaptureConnection*)connection
                                      withSettingsArray:(NSArray*)settings
                                      completionHandler:(void (^)(BOOL, NSError*))handler STUB_METHOD;
@end
