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
#import <Foundation/NSObject.h>
#import <CoreMedia/CMTime.h>

@class NSURL;
@class NSString;
@class NSError;
@class NSArray;
@class AVAssetWriterInput;
@class NSDictionary;
@class AVAssetWriterInputGroup;

typedef NSInteger AVAssetWriterStatus;
enum {
    AVAssetWriterStatusUnknown = 0,
    AVAssetWriterStatusWriting,
    AVAssetWriterStatusCompleted,
    AVAssetWriterStatusFailed,
    AVAssetWriterStatusCancelled
};

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetWriter : NSObject
+ (instancetype)assetWriterWithURL:(NSURL*)outputURL fileType:(NSString*)outputFileType error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initWithURL:(NSURL*)outputURL fileType:(NSString*)outputFileType error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly, nonatomic) NSArray* availableMediaTypes STUB_PROPERTY;
- (BOOL)startWriting STUB_METHOD;
- (BOOL)finishWriting STUB_METHOD;
- (void)finishWritingWithCompletionHandler:(void (^)(void))handler STUB_METHOD;
- (void)cancelWriting STUB_METHOD;
@property (readonly, copy, nonatomic) NSURL* outputURL STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* outputFileType STUB_PROPERTY;
@property (readonly) NSError* error STUB_PROPERTY;
@property (readonly) AVAssetWriterStatus status STUB_PROPERTY;
@property (copy, nonatomic) NSURL* directoryForTemporaryFiles STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* inputs STUB_PROPERTY;
- (void)addInput:(AVAssetWriterInput*)input STUB_METHOD;
- (BOOL)canAddInput:(AVAssetWriterInput*)input STUB_METHOD;
- (void)startSessionAtSourceTime:(CMTime)startTime STUB_METHOD;
- (void)endSessionAtSourceTime:(CMTime)endTime STUB_METHOD;
- (BOOL)canApplyOutputSettings:(NSDictionary*)outputSettings forMediaType:(NSString*)mediaType STUB_METHOD;
@property (copy, nonatomic) NSArray* metadata STUB_PROPERTY;
@property (nonatomic) CMTime movieFragmentInterval STUB_PROPERTY;
@property (nonatomic) CMTimeScale movieTimeScale STUB_PROPERTY;
@property (nonatomic) BOOL shouldOptimizeForNetworkUse STUB_PROPERTY;
- (void)addInputGroup:(AVAssetWriterInputGroup*)inputGroup STUB_METHOD;
- (BOOL)canAddInputGroup:(AVAssetWriterInputGroup*)inputGroup STUB_METHOD;
@property (readonly, nonatomic) NSArray* inputGroups STUB_PROPERTY;
@end
