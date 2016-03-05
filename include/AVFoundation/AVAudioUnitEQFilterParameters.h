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

typedef NSInteger AVAudioUnitEQFilterType;
enum {
    AVAudioUnitEQFilterTypeParametric = 0,
    AVAudioUnitEQFilterTypeLowPass = 1,
    AVAudioUnitEQFilterTypeHighPass = 2,
    AVAudioUnitEQFilterTypeResonantLowPass = 3,
    AVAudioUnitEQFilterTypeResonantHighPass = 4,
    AVAudioUnitEQFilterTypeBandPass = 5,
    AVAudioUnitEQFilterTypeBandStop = 6,
    AVAudioUnitEQFilterTypeLowShelf = 7,
    AVAudioUnitEQFilterTypeHighShelf = 8,
    AVAudioUnitEQFilterTypeResonantLowShelf = 9,
    AVAudioUnitEQFilterTypeResonantHighShelf = 10,
};

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioUnitEQFilterParameters : NSObject
@property (nonatomic) float bandwidth STUB_PROPERTY;
@property (nonatomic) BOOL bypass STUB_PROPERTY;
@property (nonatomic) AVAudioUnitEQFilterType filterType STUB_PROPERTY;
@property (nonatomic) float frequency STUB_PROPERTY;
@property (nonatomic) float gain STUB_PROPERTY;
@end
