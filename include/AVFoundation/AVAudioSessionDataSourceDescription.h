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
@class NSNumber;
@class NSArray;
@class NSError;

AVFOUNDATION_EXPORT NSString* const AVAudioSessionLocationUpper;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionLocationLower;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionOrientationTop;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionOrientationBottom;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionOrientationFront;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionOrientationBack;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPolarPatternOmnidirectional;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPolarPatternCardioid;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPolarPatternSubcardioid;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioSessionDataSourceDescription : NSObject
@property (readonly) NSNumber* dataSourceID STUB_PROPERTY;
@property (readonly) NSString* dataSourceName STUB_PROPERTY;
@property (readonly) NSString* location STUB_PROPERTY;
@property (readonly) NSString* orientation STUB_PROPERTY;
@property (readonly) NSString* selectedPolarPattern STUB_PROPERTY;
@property (readonly) NSArray* supportedPolarPatterns STUB_PROPERTY;
@property (readonly) NSString* preferredPolarPattern STUB_PROPERTY;
- (BOOL)setPreferredPolarPattern:(NSString*)pattern error:(NSError* _Nullable*)outError STUB_METHOD;
@end
