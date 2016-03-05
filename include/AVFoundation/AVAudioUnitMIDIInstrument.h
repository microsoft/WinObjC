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
#import <AVFoundation/AVAudioUnit.h>

@class NSData;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioUnitMIDIInstrument : AVAudioUnit <AVAudioMixing>
- (instancetype)initWithAudioComponentDescription:(AudioComponentDescription)description STUB_METHOD;
- (void)sendController:(uint8_t)controller withValue:(uint8_t)value onChannel:(uint8_t)channel STUB_METHOD;
- (void)sendMIDIEvent:(uint8_t)midiStatus data1:(uint8_t)data1 STUB_METHOD;
- (void)sendMIDIEvent:(uint8_t)midiStatus data1:(uint8_t)data1 data2:(uint8_t)data2 STUB_METHOD;
- (void)sendMIDISysExEvent:(NSData*)midiData STUB_METHOD;
- (void)sendPitchBend:(uint16_t)pitchbend onChannel:(uint8_t)channel STUB_METHOD;
- (void)sendPressure:(uint8_t)pressure onChannel:(uint8_t)channel STUB_METHOD;
- (void)sendPressureForKey:(uint8_t)key withValue:(uint8_t)value onChannel:(uint8_t)channel STUB_METHOD;
- (void)sendProgramChange:(uint8_t)program bankMSB:(uint8_t)bankMSB bankLSB:(uint8_t)bankLSB onChannel:(uint8_t)channel STUB_METHOD;
- (void)sendProgramChange:(uint8_t)program onChannel:(uint8_t)channel STUB_METHOD;
- (void)startNote:(uint8_t)note withVelocity:(uint8_t)velocity onChannel:(uint8_t)channel STUB_METHOD;
- (void)stopNote:(uint8_t)note onChannel:(uint8_t)channel STUB_METHOD;

@property (nonatomic) float obstruction STUB_PROPERTY;
@property (nonatomic) float occlusion STUB_PROPERTY;
@property (nonatomic) AVAudio3DPoint position STUB_PROPERTY;
@property (nonatomic) float rate STUB_PROPERTY;
@property (nonatomic) AVAudio3DMixingRenderingAlgorithm renderingAlgorithm STUB_PROPERTY;
@property (nonatomic) float reverbBlend STUB_PROPERTY;
@property (nonatomic) float pan STUB_PROPERTY;
@property (nonatomic) float volume STUB_PROPERTY;
@end
