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
#import <AVFoundation/AVFoundationTypes.h>

typedef NSInteger AVAudio3DMixingRenderingAlgorithm;
enum {
    AVAudio3DMixingRenderingAlgorithmEqualPowerPanning = 0,
    AVAudio3DMixingRenderingAlgorithmSphericalHead = 1,
    AVAudio3DMixingRenderingAlgorithmHRTF = 2,
    AVAudio3DMixingRenderingAlgorithmSoundField = 3,
    AVAudio3DMixingRenderingAlgorithmStereoPassThrough = 5
};
@protocol AVAudio3DMixing <NSObject>
@property (nonatomic) float obstruction;
@property (nonatomic) float occlusion;
@property (nonatomic) AVAudio3DPoint position;
@property (nonatomic) float rate;
@property (nonatomic) AVAudio3DMixingRenderingAlgorithm renderingAlgorithm;
@property (nonatomic) float reverbBlend;
@end
