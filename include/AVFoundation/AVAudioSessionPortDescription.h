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

@class NSString;
@class NSArray;
@class AVAudioSessionDataSourceDescription;
@class NSError;

AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortBluetoothHFP;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortUSBAudio;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortLineIn;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortBuiltInMic;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortHeadsetMic;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortLineOut;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortHeadphones;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortBluetoothA2DP;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortBuiltInReceiver;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortBuiltInSpeaker;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortHDMI;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortAirPlay;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortBluetoothLE;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioSessionPortDescription : NSObject
@property (readonly) NSString* portName STUB_PROPERTY;
@property (readonly) NSString* portType STUB_PROPERTY;
@property (readonly) NSArray* channels STUB_PROPERTY;
@property (readonly) NSString* UID STUB_PROPERTY;
@property (readonly) NSArray* dataSources STUB_PROPERTY;
@property (readonly) AVAudioSessionDataSourceDescription* selectedDataSource STUB_PROPERTY;
@property (readonly) AVAudioSessionDataSourceDescription* preferredDataSource STUB_PROPERTY;
- (BOOL)setPreferredDataSource:(AVAudioSessionDataSourceDescription*)dataSource error:(NSError* _Nullable*)outError STUB_METHOD;
@end
