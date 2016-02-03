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
@class AVSpeechSynthesisVoice;

AVFOUNDATION_EXPORT const float AVSpeechUtteranceMinimumSpeechRate;
AVFOUNDATION_EXPORT const float AVSpeechUtteranceMaximumSpeechRate;
AVFOUNDATION_EXPORT const float AVSpeechUtteranceDefaultSpeechRate;

AVFOUNDATION_EXPORT_CLASS
@interface AVSpeechUtterance : NSObject <NSCopying, NSObject, NSSecureCoding>
- (instancetype)initWithString:(NSString*)string STUB_METHOD;
+ (instancetype)speechUtteranceWithString:(NSString*)string STUB_METHOD;
@property (nonatomic) float pitchMultiplier STUB_PROPERTY;
@property (nonatomic) NSTimeInterval postUtteranceDelay STUB_PROPERTY;
@property (nonatomic) NSTimeInterval preUtteranceDelay STUB_PROPERTY;
@property (nonatomic) float rate STUB_PROPERTY;
@property (readonly, nonatomic) NSString* speechString STUB_PROPERTY;
@property (retain, nonatomic) AVSpeechSynthesisVoice* voice STUB_PROPERTY;
@property (nonatomic) float volume STUB_PROPERTY;
@end
