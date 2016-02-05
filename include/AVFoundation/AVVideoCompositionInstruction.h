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
#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSObject.h>
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTimeRange.h>

@class NSArray;

@protocol AVVideoCompositionInstruction <NSObject>
@property (nonatomic, readonly) CMPersistentTrackID passthroughTrackID;
@property (nonatomic, readonly) NSArray* requiredSourceTrackIDs;
@property (nonatomic, readonly) BOOL containsTweening;
@property (nonatomic, readonly) BOOL enablePostProcessing;
@property (nonatomic, readonly) CMTimeRange timeRange;
@end

@interface AVVideoCompositionInstruction: NSObject <AVVideoCompositionInstruction, NSCopying, NSMutableCopying, NSSecureCoding>
@property (nonatomic, readonly) CMPersistentTrackID passthroughTrackID STUB_PROPERTY;
@property (nonatomic, readonly) NSArray* requiredSourceTrackIDs STUB_PROPERTY;
@property (nonatomic, readonly) BOOL containsTweening STUB_PROPERTY;
@property (nonatomic, readonly) BOOL enablePostProcessing STUB_PROPERTY;
@property (nonatomic, readonly) CMTimeRange timeRange STUB_PROPERTY;
@end
