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
#import <AudioToolbox/MusicSequence.h>

@class AVAudioNode;
@class AVAudioInputNode;
@class AVAudioOutputNode;
@class AVAudioMixerNode;
@class AVAudioFormat;
@class NSError;

AVFOUNDATION_EXPORT NSString* const AVAudioEngineConfigurationChangeNotification;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioEngine : NSObject
- (instancetype)init STUB_METHOD;
- (void)attachNode:(AVAudioNode*)node STUB_METHOD;
- (void)detachNode:(AVAudioNode*)node STUB_METHOD;
@property (readonly, nonatomic) AVAudioInputNode* inputNode STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioOutputNode* outputNode STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioMixerNode* mainMixerNode STUB_PROPERTY;
- (void)disconnectNodeInput:(AVAudioNode*)node STUB_METHOD;
- (void)disconnectNodeInput:(AVAudioNode*)node bus:(AVAudioNodeBus)bus STUB_METHOD;
- (void)disconnectNodeOutput:(AVAudioNode*)node STUB_METHOD;
- (void)disconnectNodeOutput:(AVAudioNode*)node bus:(AVAudioNodeBus)bus STUB_METHOD;
- (void)connect:(AVAudioNode*)node1 to:(AVAudioNode*)node2 format:(AVAudioFormat*)format STUB_METHOD;
- (void)connect:(AVAudioNode*)node1
             to:(AVAudioNode*)node2
        fromBus:(AVAudioNodeBus)bus1
          toBus:(AVAudioNodeBus)bus2
         format:(AVAudioFormat*)format STUB_METHOD;
@property (nonatomic) MusicSequence musicSequence STUB_PROPERTY;
- (void)prepare STUB_METHOD;
- (BOOL)startAndReturnError:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly, getter=isRunning, nonatomic) BOOL running STUB_PROPERTY;
- (void)pause STUB_METHOD;
- (void)stop STUB_METHOD;
- (void)reset STUB_METHOD;
@end
