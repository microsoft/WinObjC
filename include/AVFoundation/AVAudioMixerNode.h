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
#import <AVFoundation/AVAudioMixing.h>
#import <Foundation/NSObject.h>
#import <AVFoundation/AVAudioNode.h>
#import <AVFoundation/AVFoundationTypes.h>

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioMixerNode : AVAudioNode <AVAudioMixing>
@property (nonatomic) float obstruction STUB_PROPERTY;
@property (nonatomic) float occlusion STUB_PROPERTY;
@property (nonatomic) AVAudio3DPoint position STUB_PROPERTY;
@property (nonatomic) float rate STUB_PROPERTY;
@property (nonatomic) AVAudio3DMixingRenderingAlgorithm renderingAlgorithm STUB_PROPERTY;
@property (nonatomic) float reverbBlend STUB_PROPERTY;
@property (nonatomic) float pan STUB_PROPERTY;
@property (nonatomic) float volume STUB_PROPERTY;
@property (nonatomic) float outputVolume STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioNodeBus nextAvailableInputBus STUB_PROPERTY;
@end
