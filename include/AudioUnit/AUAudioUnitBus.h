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

#import <AudioUnit/AudioUnitExport.h>
#import <Foundation/NSObject.h>
#import <CoreFoundation/CFData.h>
#import <AudioUnit/AudioUnitTypes.h>

@class AVAudioFormat;
@class NSError;
@class NSString;
@class AUAudioUnit;
@class NSArray;

#import <AudioUnit/AUAudioUnit.h>

AUDIOUNIT_EXPORT_CLASS
@interface AUAudioUnitBus : NSObject
- (BOOL)setFormat:(AVAudioFormat*)format error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly, nonatomic) AVAudioFormat* format STUB_PROPERTY;
@property (getter=isEnabled, nonatomic) BOOL enabled STUB_PROPERTY;
@property (copy, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger index STUB_PROPERTY;
@property (readonly, nonatomic) AUAudioUnitBusType busType STUB_PROPERTY;
@property (readonly, assign, nonatomic) AUAudioUnit* ownerAudioUnit STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* supportedChannelLayoutTags STUB_PROPERTY;
@property (nonatomic) NSTimeInterval contextPresentationLatency STUB_PROPERTY;
- (instancetype)initWithFormat:(AVAudioFormat*)format error:(NSError* _Nullable*)outError STUB_METHOD;
@property (retain, nonatomic) NSArray* supportedChannelCounts STUB_PROPERTY;
@property (nonatomic) AUAudioChannelCount maximumChannelCount STUB_PROPERTY;
@end
