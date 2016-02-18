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

@class AVSpeechUtterance;
@protocol AVSpeechSynthesizerDelegate;

typedef enum : NSInteger { AVSpeechBoundaryImmediate, AVSpeechBoundaryWord } AVSpeechBoundary;

AVFOUNDATION_EXPORT_CLASS
@interface AVSpeechSynthesizer : NSObject
- (void)speakUtterance:(AVSpeechUtterance*)utterance STUB_METHOD;
- (BOOL)continueSpeaking STUB_METHOD;
- (BOOL)pauseSpeakingAtBoundary:(AVSpeechBoundary)boundary STUB_METHOD;
@property (readonly, getter=isPaused, nonatomic) BOOL paused STUB_PROPERTY;
@property (readonly, getter=isSpeaking, nonatomic) BOOL speaking STUB_PROPERTY;
- (BOOL)stopSpeakingAtBoundary:(AVSpeechBoundary)boundary STUB_METHOD;
@property (assign, nonatomic) id<AVSpeechSynthesizerDelegate> delegate STUB_PROPERTY;
@end
