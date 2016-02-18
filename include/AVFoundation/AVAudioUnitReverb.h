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

typedef NSInteger AVAudioUnitReverbPreset;
enum {
    AVAudioUnitReverbPresetSmallRoom = 0,
    AVAudioUnitReverbPresetMediumRoom = 1,
    AVAudioUnitReverbPresetLargeRoom = 2,
    AVAudioUnitReverbPresetMediumHall = 3,
    AVAudioUnitReverbPresetLargeHall = 4,
    AVAudioUnitReverbPresetPlate = 5,
    AVAudioUnitReverbPresetMediumChamber = 6,
    AVAudioUnitReverbPresetLargeChamber = 7,
    AVAudioUnitReverbPresetCathedral = 8,
    AVAudioUnitReverbPresetLargeRoom2 = 9,
    AVAudioUnitReverbPresetMediumHall2 = 10,
    AVAudioUnitReverbPresetMediumHall3 = 11,
    AVAudioUnitReverbPresetLargeHall2 = 12
};

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioUnitReverb : AVAudioUnitEffect
- (void)loadFactoryPreset:(AVAudioUnitReverbPreset)preset STUB_METHOD;
@property (nonatomic) float wetDryMix STUB_PROPERTY;
@end
