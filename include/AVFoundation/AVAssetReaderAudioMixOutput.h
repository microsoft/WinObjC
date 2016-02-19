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
#import <AVFoundation/AVAssetReaderOutput.h>

@class NSArray;
@class NSDictionary;
@class AVAudioMix;
@class NSString;

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetReaderAudioMixOutput : AVAssetReaderOutput
- (instancetype)initWithAudioTracks:(NSArray*)audioTracks audioSettings:(NSDictionary*)audioSettings STUB_METHOD;
+ (instancetype)assetReaderAudioMixOutputWithAudioTracks:(NSArray*)audioTracks audioSettings:(NSDictionary*)audioSettings STUB_METHOD;
@property (copy, nonatomic) AVAudioMix* audioMix STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* audioSettings STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* audioTracks STUB_PROPERTY;
@property (copy, nonatomic) NSString* audioTimePitchAlgorithm STUB_PROPERTY;
@end
