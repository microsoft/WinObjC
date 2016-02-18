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
#import <AVFoundation/AVMetadataItem.h>
#import <CoreMedia/CMTime.h>

@class NSString;
@class NSLocale;
@class NSDictionary;
@class NSDate;

AVFOUNDATION_EXPORT_CLASS
@interface AVMutableMetadataItem : AVMetadataItem <AVAsynchronousKeyValueLoading, NSCopying, NSMutableCopying>
+ (AVMutableMetadataItem*)metadataItem STUB_METHOD;
@property (readwrite, copy, nonatomic) id<NSObject, NSCopying> key STUB_PROPERTY;
@property (readwrite, copy, nonatomic) NSString* keySpace STUB_PROPERTY;
@property (readwrite, copy, nonatomic) id<NSObject, NSCopying> value STUB_PROPERTY;
@property (readwrite, copy, nonatomic) NSLocale* locale STUB_PROPERTY;
@property (readwrite, nonatomic) CMTime time STUB_PROPERTY;
@property (readwrite, nonatomic) CMTime duration STUB_PROPERTY;
@property (readwrite, copy, nonatomic) NSDictionary* extraAttributes STUB_PROPERTY;
@property (readwrite, copy, nonatomic) NSString* dataType STUB_PROPERTY;
@property (readwrite, copy, nonatomic) NSString* extendedLanguageTag STUB_PROPERTY;
@property (readwrite, copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (readwrite, copy, nonatomic) NSDate* startDate STUB_PROPERTY;
@end
