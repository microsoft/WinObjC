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
#import <CoreMedia/CMTimeRange.h>

@class AVAsset;
@class NSError;
@class NSArray;
@class AVAssetReaderOutput;

typedef NSInteger AVAssetReaderStatus;
enum {
    AVAssetReaderStatusUnknown = 0,
    AVAssetReaderStatusReading,
    AVAssetReaderStatusCompleted,
    AVAssetReaderStatusFailed,
    AVAssetReaderStatusCancelled,
};

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetReader : NSObject
- (instancetype)initWithAsset:(AVAsset*)asset error:(NSError* _Nullable*)outError STUB_METHOD;
+ (instancetype)assetReaderWithAsset:(AVAsset*)asset error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly, nonatomic) NSArray* outputs STUB_PROPERTY;
- (void)addOutput:(AVAssetReaderOutput*)output STUB_METHOD;
- (BOOL)canAddOutput:(AVAssetReaderOutput*)output STUB_METHOD;
@property (readonly) AVAssetReaderStatus status STUB_PROPERTY;
- (BOOL)startReading STUB_METHOD;
- (void)cancelReading STUB_METHOD;
@property (readonly) NSError* error STUB_PROPERTY;
@property (nonatomic) CMTimeRange timeRange STUB_PROPERTY;
@property (readonly, retain, nonatomic) AVAsset* asset STUB_PROPERTY;
@end
