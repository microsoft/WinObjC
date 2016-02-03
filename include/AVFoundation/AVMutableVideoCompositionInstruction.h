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
#import <AVFoundation/AVVideoCompositionInstruction.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGColor.h>

@class NSArray;

AVFOUNDATION_EXPORT_CLASS
@interface AVMutableVideoCompositionInstruction
    : AVVideoCompositionInstruction <AVVideoCompositionInstruction, NSCopying, NSMutableCopying, NSObject, NSSecureCoding>
+ (instancetype)videoCompositionInstruction STUB_METHOD;
@property (nonatomic) CGColorRef backgroundColor STUB_PROPERTY; // removed retain from list as it was causing an error
@property (copy, nonatomic) NSArray* layerInstructions STUB_PROPERTY;
@property (assign, nonatomic) CMTimeRange timeRange STUB_PROPERTY;
@property (assign, nonatomic) BOOL enablePostProcessing STUB_PROPERTY;
@end
