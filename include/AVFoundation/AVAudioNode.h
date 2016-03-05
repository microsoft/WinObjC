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
#import <AVFoundation/AVFoundationTypes.h>

@class AVAudioPCMBuffer;
@class AVAudioTime;
@class AVAudioFormat;
@class NSString;
@class AVAudioEngine;

typedef void (^AVAudioNodeTapBlock)(AVAudioPCMBuffer* buffer, AVAudioTime* when);

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioNode : NSObject
- (AVAudioFormat*)inputFormatForBus:(AVAudioNodeBus)bus STUB_METHOD;
- (NSString*)nameForInputBus:(AVAudioNodeBus)bus STUB_METHOD;
@property (readonly, nonatomic) NSUInteger numberOfInputs STUB_PROPERTY;
- (AVAudioFormat*)outputFormatForBus:(AVAudioNodeBus)bus STUB_METHOD;
- (NSString*)nameForOutputBus:(AVAudioNodeBus)bus STUB_METHOD;
@property (readonly, nonatomic) NSUInteger numberOfOutputs STUB_PROPERTY;
- (void)installTapOnBus:(AVAudioNodeBus)bus
             bufferSize:(AVAudioFrameCount)bufferSize
                 format:(AVAudioFormat*)format
                  block:(AVAudioNodeTapBlock)tapBlock STUB_METHOD;
- (void)removeTapOnBus:(AVAudioNodeBus)bus STUB_METHOD;
@property (readonly, nonatomic) AVAudioEngine* engine STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioTime* lastRenderTime STUB_PROPERTY;
- (void)reset STUB_METHOD;
@end
