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
#import <CoreVideo/CVPixelBuffer.h>
#import <CoreMedia/CMTime.h>
#import <CoreVideo/CVPixelBufferPool.h>

@class AVAssetWriterInput;
@class NSDictionary;

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetWriterInputPixelBufferAdaptor : NSObject
+ (instancetype)assetWriterInputPixelBufferAdaptorWithAssetWriterInput:(AVAssetWriterInput*)input
                                           sourcePixelBufferAttributes:(NSDictionary*)sourcePixelBufferAttributes STUB_METHOD;
- (instancetype)initWithAssetWriterInput:(AVAssetWriterInput*)input
             sourcePixelBufferAttributes:(NSDictionary*)sourcePixelBufferAttributes STUB_METHOD;
- (BOOL)appendPixelBuffer:(CVPixelBufferRef)pixelBuffer withPresentationTime:(CMTime)presentationTime STUB_METHOD;
@property (readonly, nonatomic) AVAssetWriterInput* assetWriterInput STUB_PROPERTY;
@property (readonly, nonatomic) CVPixelBufferPoolRef pixelBufferPool STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* sourcePixelBufferAttributes STUB_PROPERTY;
@end
