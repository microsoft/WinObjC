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
#import <AVFoundation/AVAudioUnitEffect.h>

typedef NSInteger AVAudioUnitDistortionPreset;
enum {
    AVAudioUnitDistortionPresetDrumsBitBrush = 0,
    AVAudioUnitDistortionPresetDrumsBufferBeats = 1,
    AVAudioUnitDistortionPresetDrumsLoFi = 2,
    AVAudioUnitDistortionPresetMultiBrokenSpeaker = 3,
    AVAudioUnitDistortionPresetMultiCellphoneConcert = 4,
    AVAudioUnitDistortionPresetMultiDecimated1 = 5,
    AVAudioUnitDistortionPresetMultiDecimated2 = 6,
    AVAudioUnitDistortionPresetMultiDecimated3 = 7,
    AVAudioUnitDistortionPresetMultiDecimated4 = 8,
    AVAudioUnitDistortionPresetMultiDistortedFunk = 9,
    AVAudioUnitDistortionPresetMultiDistortedCubed = 10,
    AVAudioUnitDistortionPresetMultiDistortedSquared = 11,
    AVAudioUnitDistortionPresetMultiEcho1 = 12,
    AVAudioUnitDistortionPresetMultiEcho2 = 13,
    AVAudioUnitDistortionPresetMultiEchoTight1 = 14,
    AVAudioUnitDistortionPresetMultiEchoTight2 = 15,
    AVAudioUnitDistortionPresetMultiEverythingIsBroken = 16,
    AVAudioUnitDistortionPresetSpeechAlienChatter = 17,
    AVAudioUnitDistortionPresetSpeechCosmicInterference = 18,
    AVAudioUnitDistortionPresetSpeechGoldenPi = 19,
    AVAudioUnitDistortionPresetSpeechRadioTower = 20,
    AVAudioUnitDistortionPresetSpeechWaves = 21
};

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioUnitDistortion : AVAudioUnitEffect
- (void)loadFactoryPreset:(AVAudioUnitDistortionPreset)preset STUB_METHOD;
@property (nonatomic) float preGain STUB_PROPERTY;
@property (nonatomic) float wetDryMix STUB_PROPERTY;
@end
