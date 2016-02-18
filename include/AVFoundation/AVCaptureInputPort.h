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
#import <CoreMedia/CMFormatDescription.h>
#import <CoreMedia/CMSync.h>

@class AVCaptureInput;
@class NSString;

AVFOUNDATION_EXPORT NSString* const AVCaptureInputPortFormatDescriptionDidChangeNotification;

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureInputPort : NSObject
@property (getter=isEnabled, nonatomic) BOOL enabled STUB_PROPERTY;
@property (readonly, nonatomic) CMFormatDescriptionRef formatDescription STUB_PROPERTY;
@property (readonly, nonatomic) AVCaptureInput* input STUB_PROPERTY;
@property (readonly, nonatomic) NSString* mediaType STUB_PROPERTY;
@property (readonly, nonatomic) CMClockRef clock STUB_PROPERTY;
@end
