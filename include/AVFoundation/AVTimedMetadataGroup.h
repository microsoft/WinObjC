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

#import <AVFoundation/AVMetadataGroup.h>

@class NSArray;

AVFOUNDATION_EXPORT_CLASS
@interface AVTimedMetadataGroup : AVMetadataGroup <NSCopying, NSMutableCopying>
- (instancetype)initWithItems:(NSArray*)items timeRange:(CMTimeRange)timeRange STUB_METHOD;
@property (readonly, nonatomic) CMTimeRange timeRange STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* items STUB_PROPERTY;
@end
