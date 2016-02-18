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
#import <dispatch/dispatch.h>
#import <AVFoundation/AVPlayerItemOutput.h>

@class NSString;
@class NSArray;
@protocol AVPlayerItemLegibleOutputPushDelegate;

AVFOUNDATION_EXPORT NSString* const AVPlayerItemLegibleOutputTextStylingResolutionDefault;
AVFOUNDATION_EXPORT NSString* const AVPlayerItemLegibleOutputTextStylingResolutionSourceAndRulesOnly;

AVFOUNDATION_EXPORT_CLASS
@interface AVPlayerItemLegibleOutput : AVPlayerItemOutput
- (id)init STUB_METHOD;
- (instancetype)initWithMediaSubtypesForNativeRepresentation:(NSArray*)subtypes STUB_METHOD;
@property (copy, nonatomic) NSString* textStylingResolution STUB_PROPERTY;
@property (readonly, nonatomic, weak) id<AVPlayerItemLegibleOutputPushDelegate> delegate STUB_PROPERTY;
@property (readwrite, nonatomic) NSTimeInterval advanceIntervalForDelegateInvocation STUB_PROPERTY;
@property (readonly, nonatomic) dispatch_queue_t delegateQueue STUB_PROPERTY;
- (void)setDelegate:(id<AVPlayerItemLegibleOutputPushDelegate>)delegate queue:(dispatch_queue_t)delegateQueue STUB_METHOD;
@end
