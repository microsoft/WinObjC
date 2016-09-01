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
#import <CoreGraphics/CGGeometry.h>
#import <AVFoundation/AVCaptureOutput.h>
@protocol AVCaptureMetadataOutputObjectsDelegate;

@class NSArray;

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureMetadataOutput : AVCaptureOutput
- (void)setMetadataObjectsDelegate:(id<AVCaptureMetadataOutputObjectsDelegate>)objectsDelegate
                             queue:(dispatch_queue_t)objectsCallbackQueue STUB_METHOD;
@property (readonly, nonatomic) id<AVCaptureMetadataOutputObjectsDelegate> metadataObjectsDelegate STUB_PROPERTY;
@property (readonly, nonatomic) dispatch_queue_t metadataObjectsCallbackQueue STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* availableMetadataids STUB_PROPERTY;
@property (copy, nonatomic) NSArray* metadataids STUB_PROPERTY;
@property (nonatomic) CGRect rectOfInterest STUB_PROPERTY;
@end
