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
#import <CoreMedia/CMFormatDescription.h>
#import <CoreMedia/CMTime.h>

@class NSString;
@class NSArray;
@class NSDictionary;

AVFOUNDATION_EXPORT NSString* const AVOutputSettingsPreset640x480;
AVFOUNDATION_EXPORT NSString* const AVOutputSettingsPreset960x540;
AVFOUNDATION_EXPORT NSString* const AVOutputSettingsPreset1280x720;
AVFOUNDATION_EXPORT NSString* const AVOutputSettingsPreset1920x1080;

AVFOUNDATION_EXPORT_CLASS
@interface AVOutputSettingsAssistant : NSObject
+ (instancetype)outputSettingsAssistantWithPreset:(NSString*)presetIdentifier STUB_METHOD;
+ (NSArray*)availableOutputSettingsPresets STUB_METHOD;
@property (readonly, nonatomic) NSString* outputFileType STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* audioSettings STUB_PROPERTY;
@property (nonatomic)
    CMAudioFormatDescriptionRef sourceAudioFormat STUB_PROPERTY; // removed retain from this line as it was causing an error
@property (nonatomic) CMTime sourceVideoAverageFrameDuration STUB_PROPERTY;
@property (nonatomic)
    CMVideoFormatDescriptionRef sourceVideoFormat STUB_PROPERTY; // removed retain from this line as it was causing an error
@property (readonly, nonatomic) NSDictionary* videoSettings STUB_PROPERTY;
@property (nonatomic) CMTime sourceVideoMinFrameDuration STUB_PROPERTY;
@end
