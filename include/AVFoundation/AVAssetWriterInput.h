//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreMedia/CMFormatDescription.h>
#import <CoreMedia/CMSampleBuffer.h>
#import <CoreMedia/CMTime.h>

@class NSString;
@class NSDictionary;
@class NSArray;
@class NSURL;
@class AVAssetWriterInputPassDescription;

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetWriterInput : NSObject
+ (instancetype)assetWriterInputWithMediaType:(NSString*)mediaType outputSettings:(NSDictionary*)outputSettings STUB_METHOD;
+ (instancetype)assetWriterInputWithMediaType:(NSString*)mediaType
                               outputSettings:(NSDictionary*)outputSettings
                             sourceFormatHint:(CMFormatDescriptionRef)sourceFormatHint STUB_METHOD;
- (instancetype)initWithMediaType:(NSString*)mediaType outputSettings:(NSDictionary*)outputSettings STUB_METHOD;
- (instancetype)initWithMediaType:(NSString*)mediaType
                   outputSettings:(NSDictionary*)outputSettings
                 sourceFormatHint:(CMFormatDescriptionRef)sourceFormatHint STUB_METHOD;
- (BOOL)appendSampleBuffer:(CMSampleBufferRef)sampleBuffer STUB_METHOD;
@property (readonly, getter=isReadyForMoreMediaData, nonatomic) BOOL readyForMoreMediaData STUB_PROPERTY;
- (void)markAsFinished STUB_METHOD;
- (void)requestMediaDataWhenReadyOnQueue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block STUB_METHOD;
@property (copy, nonatomic) NSArray* metadata STUB_PROPERTY;
@property (nonatomic) CGAffineTransform transform STUB_PROPERTY;
@property (nonatomic) CMTimeScale mediaTimeScale STUB_PROPERTY;
@property (nonatomic) BOOL expectsMediaDataInRealTime STUB_PROPERTY;
@property (nonatomic) BOOL marksOutputTrackAsEnabled STUB_PROPERTY;
@property (nonatomic) CGSize naturalSize STUB_PROPERTY;
@property (nonatomic) float preferredVolume STUB_PROPERTY;
- (void)addTrackAssociationWithTrackOfInput:(AVAssetWriterInput*)input type:(NSString*)trackAssociationType STUB_METHOD;
- (BOOL)canAddTrackAssociationWithTrackOfInput:(AVAssetWriterInput*)input type:(NSString*)trackAssociationType STUB_METHOD;
@property (readonly, nonatomic) NSString* mediaType STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* outputSettings STUB_PROPERTY;
@property (readonly, nonatomic) CMFormatDescriptionRef sourceFormatHint STUB_PROPERTY;
@property (copy, nonatomic) NSURL* sampleReferenceBaseURL STUB_PROPERTY;
@property (copy, nonatomic) NSString* extendedLanguageTag STUB_PROPERTY;
@property (copy, nonatomic) NSString* languageCode STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canPerformMultiplePasses STUB_PROPERTY;
@property (readonly) AVAssetWriterInputPassDescription* currentPassDescription STUB_PROPERTY;
- (void)markCurrentPassAsFinished STUB_METHOD;
@property (nonatomic) BOOL performsMultiPassEncodingIfSupported STUB_PROPERTY;
@property (nonatomic) NSInteger preferredMediaChunkAlignment STUB_PROPERTY;
@property (nonatomic) CMTime preferredMediaChunkDuration STUB_PROPERTY;
- (void)respondToEachPassDescriptionOnQueue:(dispatch_queue_t)queue usingBlock:(dispatch_block_t)block STUB_METHOD;
@end
