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
#import <CoreAudio/CoreAudioTypes.h>
#import <AVFoundation/AVFoundationTypes.h>

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioChannelLayout : NSObject <NSSecureCoding>
+ (instancetype)layoutWithLayout:(const AudioChannelLayout*)layout STUB_METHOD;
- (instancetype)initWithLayout:(const AudioChannelLayout*)layout STUB_METHOD;
+ (instancetype)layoutWithLayoutTag:(AudioChannelLayoutTag)layoutTag STUB_METHOD;
- (instancetype)initWithLayoutTag:(AudioChannelLayoutTag)layoutTag STUB_METHOD;
@property (readonly, nonatomic) const AudioChannelLayout* layout STUB_PROPERTY;
@property (readonly, nonatomic) AudioChannelLayoutTag layoutTag STUB_PROPERTY;
@property (readonly, nonatomic) AVAudioChannelCount channelCount STUB_PROPERTY;
- (BOOL)isEqual:(id)object STUB_METHOD;
@end
