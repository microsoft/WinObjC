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

@class AVCaptureFileOutput;
@class NSURL;
@class NSArray;
@class NSError;

@protocol AVCaptureFileOutputRecordingDelegate <NSObject>
@optional
- (void)captureOutput:(AVCaptureFileOutput*)captureOutput
    didStartRecordingToOutputFileAtURL:(NSURL*)fileURL
                       fromConnections:(NSArray*)connections;
@required
- (void)captureOutput:(AVCaptureFileOutput*)captureOutput
    didFinishRecordingToOutputFileAtURL:(NSURL*)outputFileURL
                        fromConnections:(NSArray*)connections
                                  error:(NSError*)error;
@end
