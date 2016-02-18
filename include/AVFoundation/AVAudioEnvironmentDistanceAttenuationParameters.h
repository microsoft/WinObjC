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

typedef NS_ENUM(NSInteger, AVAudioEnvironmentDistanceAttenuationModel) {
    AVAudioEnvironmentDistanceAttenuationModelExponential = 1,
    AVAudioEnvironmentDistanceAttenuationModelInverse = 2,
    AVAudioEnvironmentDistanceAttenuationModelLinear = 3
};

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioEnvironmentDistanceAttenuationParameters : NSObject
@property (nonatomic) AVAudioEnvironmentDistanceAttenuationModel distanceAttenuationModel STUB_PROPERTY;
@property (nonatomic) float maximumDistance STUB_PROPERTY;
@property (nonatomic) float referenceDistance STUB_PROPERTY;
@property (nonatomic) float rolloffFactor STUB_PROPERTY;
@end
