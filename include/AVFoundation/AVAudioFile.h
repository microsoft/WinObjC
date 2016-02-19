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
#import <AVFoundation/AVAudioFormat.h>
#import <AVFoundation/AVFoundationTypes.h>

@class NSURL;
@class NSError;
@class NSDictionary;
@class AVAudioPCMBuffer;
@class AVAudioFormat;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioFile : NSObject
- (instancetype)initForReading:(NSURL*)fileURL
                  commonFormat:(AVAudioCommonFormat)format
                   interleaved:(BOOL)interleaved
                         error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initForReading:(NSURL*)fileURL error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initForWriting:(NSURL*)fileURL
                      settings:(NSDictionary*)settings
                  commonFormat:(AVAudioCommonFormat)format
                   interleaved:(BOOL)interleaved
                         error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initForWriting:(NSURL*)fileURL settings:(NSDictionary*)settings error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)readIntoBuffer:(AVAudioPCMBuffer*)buffer error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)readIntoBuffer:(AVAudioPCMBuffer*)buffer frameCount:(AVAudioFrameCount)frames error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)writeFromBuffer:(const AVAudioPCMBuffer*)buffer error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly, nonatomic) AVAudioFormat* fileFormat STUB_PROPERTY;
@property (nonatomic) AVAudioFramePosition framePosition STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioFramePosition length STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioFormat* processingFormat STUB_PROPERTY;
@property (readonly, nonatomic) NSURL* url STUB_PROPERTY;
@end
