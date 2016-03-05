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
#import <AVFoundation/AVAssetTrackSegment.h>
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTimeRange.h>

@class NSURL;

AVFOUNDATION_EXPORT_CLASS
@interface AVCompositionTrackSegment : AVAssetTrackSegment
+ (instancetype)compositionTrackSegmentWithTimeRange:(CMTimeRange)timeRange STUB_METHOD;
- (instancetype)initWithTimeRange:(CMTimeRange)timeRange STUB_METHOD;
+ (instancetype)compositionTrackSegmentWithURL:(NSURL*)URL
                                       trackID:(CMPersistentTrackID)trackID
                               sourceTimeRange:(CMTimeRange)sourceTimeRange
                               targetTimeRange:(CMTimeRange)targetTimeRange STUB_METHOD;
- (instancetype)initWithURL:(NSURL*)URL
                    trackID:(CMPersistentTrackID)trackID
            sourceTimeRange:(CMTimeRange)sourceTimeRange
            targetTimeRange:(CMTimeRange)targetTimeRange STUB_METHOD;
@property (readonly, nonatomic) NSURL* sourceURL STUB_PROPERTY;
@property (readonly, nonatomic) CMPersistentTrackID sourceTrackID STUB_PROPERTY;
@property (readonly, getter=isEmpty, nonatomic) BOOL empty STUB_PROPERTY;
@end
