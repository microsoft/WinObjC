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
#import <QuartzCore/CAMediaTiming.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
#import <QuartzCore/CALayer.h>
#import <AVFoundation/AVCaptureConnection.h>

@class AVCaptureSession;
@class NSString;
@class AVCaptureConnection;
@class AVMetadataObject;

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureVideoPreviewLayer : CALayer <CAMediaTiming, NSCoding>
- (instancetype)initWithSession:(AVCaptureSession*)session STUB_METHOD;
+ (instancetype)layerWithSession:(AVCaptureSession*)session STUB_METHOD;
- (instancetype)initWithSessionWithNoConnection:(AVCaptureSession*)session STUB_METHOD;
+ (instancetype)layerWithSessionWithNoConnection:(AVCaptureSession*)session STUB_METHOD;
@property (copy) NSString* videoGravity STUB_PROPERTY;
@property (nonatomic) AVCaptureVideoOrientation orientation STUB_PROPERTY;
@property (readonly, getter=isOrientationSupported, nonatomic) BOOL orientationSupported STUB_PROPERTY;
@property (getter=isMirrored, nonatomic) BOOL mirrored STUB_PROPERTY;
@property (readonly, getter=isMirroringSupported, nonatomic) BOOL mirroringSupported STUB_PROPERTY;
@property (nonatomic) BOOL automaticallyAdjustsMirroring STUB_PROPERTY;
@property (readonly, nonatomic) AVCaptureConnection* connection STUB_PROPERTY;
@property (retain, nonatomic) AVCaptureSession* session STUB_PROPERTY;
- (void)setSessionWithNoConnection:(AVCaptureSession*)session STUB_METHOD;
- (CGPoint)captureDevicePointOfInterestForPoint:(CGPoint)pointInLayer STUB_METHOD;
- (CGPoint)pointForCaptureDevicePointOfInterest:(CGPoint)captureDevicePointOfInterest STUB_METHOD;
- (AVMetadataObject*)transformedMetadataObjectForMetadataObject:(AVMetadataObject*)metadataObject STUB_METHOD;
- (CGRect)metadataOutputRectOfInterestForRect:(CGRect)rectInLayerCoordinates STUB_METHOD;
- (CGRect)rectForMetadataOutputRectOfInterest:(CGRect)rectInMetadataOutputCoordinates STUB_METHOD;
@end
