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
#import <AVFoundation/AVAsynchronousKeyValueLoading.h>
#import <Foundation/NSObject.h>
#import <AVFoundation/AVAsset.h>

@class NSString;
@class NSURL;
@class NSDictionary;
@class AVAssetResourceLoader;
@class AVAssetTrack;
@class AVCompositionTrack;
@class NSArray;

AVFOUNDATION_EXPORT NSString* const AVURLAssetPreferPreciseDurationAndTimingKey;
AVFOUNDATION_EXPORT NSString* const AVURLAssetReferenceRestrictionsKey;
AVFOUNDATION_EXPORT NSString* const AVURLAssetHTTPCookiesKey;

AVFOUNDATION_EXPORT_CLASS
@interface AVURLAsset : AVAsset <AVAsynchronousKeyValueLoading, NSCopying>
- (instancetype)initWithURL:(NSURL*)URL options:(NSDictionary*)options STUB_METHOD;
+ (instancetype)URLAssetWithURL:(NSURL*)URL options:(NSDictionary*)options STUB_METHOD;
@property (readonly, copy, nonatomic) NSURL* URL STUB_PROPERTY;
@property (readonly, nonatomic) AVAssetResourceLoader* resourceLoader STUB_PROPERTY;
- (AVAssetTrack*)compatibleTrackForCompositionTrack:(AVCompositionTrack*)compositionTrack STUB_METHOD;
+ (NSArray*)audiovisualMIMETypes STUB_METHOD;
+ (NSArray*)audiovisualTypes STUB_METHOD;
+ (BOOL)isPlayableExtendedMIMEType:(NSString*)extendedMIMEType STUB_METHOD;
@end
