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

typedef NS_ENUM(NSInteger, AVAudioQuality) { AVAudioQualityMin = 0, AVAudioQualityLow = 0x20, AVAudioQualityMedium = 0x40, AVAudioQualityHigh = 0x60, AVAudioQualityMax = 0x7F };

struct AVAudio3DPoint {
    float x;
    float y;
    float z;
};
typedef struct AVAudio3DPoint AVAudio3DVector;

struct AVAudio3DVectorOrientation {
    AVAudio3DVector forward;
    AVAudio3DVector up;
};

struct AVAudio3DAngularOrientation {
    float yaw;
    float pitch;
    float roll;
};

typedef int64_t AVAudioFramePosition;
typedef uint32_t AVAudioFrameCount;
typedef uint32_t AVAudioChannelCount;
typedef void (^AVAudioNodeCompletionBlock)(void);
typedef NSUInteger AVAudioNodeBus;
typedef struct AVAudio3DPoint AVAudio3DPoint;
typedef struct AVAudio3DVectorOrientation AVAudio3DVectorOrientation;
typedef struct AVAudio3DAngularOrientation AVAudio3DAngularOrientation;

typedef enum : NSInteger {
    AVCaptureVideoOrientationPortrait = 1,
    AVCaptureVideoOrientationPortraitUpsideDown,
    AVCaptureVideoOrientationLandscapeRight,
    AVCaptureVideoOrientationLandscapeLeft,
} AVCaptureVideoOrientation;

AVFOUNDATION_EXPORT CGRect AVMakeRectWithAspectRatioInsideRect(CGSize aspectRatio, CGRect boundingRect) STUB_METHOD;
