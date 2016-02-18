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
#import <AVFoundation/AVAudioNode.h>
#import <AudioUnit/AudioUnitTypes.h>
#import <AudioUnit/AudioUnitComponent.h>

@class NSURL;
@class NSError;
@class NSString;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioUnit : AVAudioNode
@property (readonly, nonatomic) AudioUnit audioUnit STUB_PROPERTY;
- (BOOL)loadAudioUnitPresetAtURL:(NSURL*)url error:(NSError* _Nullable*)error STUB_METHOD;
@property (readonly, nonatomic) AudioComponentDescription audioComponentDescription STUB_PROPERTY;
@property (readonly, nonatomic) NSString* manufacturerName STUB_PROPERTY;
@property (readonly, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger version STUB_PROPERTY;
@end
