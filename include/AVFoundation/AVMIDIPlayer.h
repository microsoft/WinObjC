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

@class NSURL;
@class NSError;
@class NSData;

typedef void (^AVMIDIPlayerCompletionHandler)(void);

AVFOUNDATION_EXPORT_CLASS
@interface AVMIDIPlayer : NSObject
- (instancetype)initWithContentsOfURL:(NSURL*)inURL soundBankURL:(NSURL*)bankURL error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initWithData:(NSData*)data soundBankURL:(NSURL*)bankURL error:(NSError* _Nullable*)outError STUB_METHOD;
- (void)prepareToPlay STUB_METHOD;
- (void)play:(AVMIDIPlayerCompletionHandler)completionHandler STUB_METHOD;
@property (readonly, getter=isPlaying, nonatomic) BOOL playing STUB_PROPERTY;
- (void)stop STUB_METHOD;
@property (readonly, nonatomic) NSTimeInterval duration STUB_PROPERTY;
@property (nonatomic) NSTimeInterval currentPosition STUB_PROPERTY;
@property (nonatomic) float rate STUB_PROPERTY;
@end
