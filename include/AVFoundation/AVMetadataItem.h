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
#import <CoreMedia/CMTime.h>

@class NSString;
@class NSArray;
@class NSError;
@class NSLocale;
@class NSData;
@class NSDictionary;
@class NSNumber;
@class NSDate;
@class AVMetadataItemFilter;

AVFOUNDATION_EXPORT_CLASS
@interface AVMetadataItem : NSObject <AVAsynchronousKeyValueLoading, NSCopying, NSMutableCopying>
@property (readonly, copy, nonatomic) id<NSObject, NSCopying> key STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* keySpace STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* commonKey STUB_PROPERTY;
- (void)loadValuesAsynchronouslyForKeys:(NSArray*)keys completionHandler:(void (^)(void))handler STUB_METHOD;
- (AVKeyValueStatus)statusOfValueForKey:(NSString*)key error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly, copy, nonatomic) id<NSObject, NSCopying> value STUB_PROPERTY;
@property (readonly, nonatomic) CMTime time STUB_PROPERTY;
@property (readonly, nonatomic) CMTime duration STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSLocale* locale STUB_PROPERTY;
@property (readonly, nonatomic) NSData* dataValue STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDictionary* extraAttributes STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* dataType STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* extendedLanguageTag STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* identifier STUB_PROPERTY;
+ (NSString*)identifierForKey:(id)key keySpace:(NSString*)keySpace STUB_METHOD;
+ (id)keyForIdentifier:(NSString*)identifier STUB_METHOD;
+ (NSString*)keySpaceForIdentifier:(NSString*)identifier STUB_METHOD;
@property (readonly, nonatomic) NSString* stringValue STUB_PROPERTY;
@property (readonly, nonatomic) NSNumber* numberValue STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* dateValue STUB_PROPERTY;
+ (NSArray*)metadataItemsFromArray:(NSArray*)array withKey:(id)key keySpace:(NSString*)keySpace STUB_METHOD;
+ (NSArray*)metadataItemsFromArray:(NSArray*)array withLocale:(NSLocale*)locale STUB_METHOD;
+ (NSArray*)metadataItemsFromArray:(NSArray*)metadataItems
    filteredAndSortedAccordingToPreferredLanguages:(NSArray*)preferredLanguages STUB_METHOD;
+ (NSArray*)metadataItemsFromArray:(NSArray*)metadataItems
      filteredByMetadataItemFilter:(AVMetadataItemFilter*)metadataItemFilter STUB_METHOD;
+ (NSArray*)metadataItemsFromArray:(NSArray*)metadataItems filteredByIdentifier:(NSString*)identifier STUB_METHOD;
@end
