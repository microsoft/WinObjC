//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _AVCAPTUREOUTPUT_H_
#define _AVCAPTUREOUTPUT_H_

#include <dispatch/dispatch.h>
#import <Foundation/Foundation.h>

@class NSDictionary;

@protocol AVCaptureVideoDataOutputSampleBufferDelegate <NSObject>
@end

@interface AVCaptureOutput : NSObject
@end

@interface AVCaptureVideoDataOutput : AVCaptureOutput

@property (nonatomic) BOOL alwaysDiscardsLateVideoFrames;
@property (nonatomic, copy) NSDictionary* videoSettings;

- (void)setSampleBufferDelegate:(id<AVCaptureVideoDataOutputSampleBufferDelegate>)sampleBufferDelegate
                          queue:(dispatch_queue_t)sampleBufferCallbackQueue;

@end

#endif /* _AVCAPTUREOUTPUT_H_ */
