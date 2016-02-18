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

@class NSString;
@class NSArray;
@class NSLocale;
@class AVMediaSelectionGroup;

AVFOUNDATION_EXPORT_CLASS
@interface AVMediaSelectionOption : NSObject <NSCopying>
@property (readonly, nonatomic) NSString* mediaType STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* mediaSubTypes STUB_PROPERTY;
- (BOOL)hasMediaCharacteristic:(NSString*)mediaCharacteristic STUB_METHOD;
@property (readonly, nonatomic) NSArray* commonMetadata STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* availableMetadataFormats STUB_PROPERTY;
- (NSArray*)metadataForFormat:(NSString*)format STUB_METHOD;
@property (readonly, getter=isPlayable, nonatomic) BOOL playable STUB_PROPERTY;
@property (readonly, nonatomic) NSString* displayName STUB_PROPERTY;
- (NSString*)displayNameWithLocale:(NSLocale*)locale STUB_METHOD;
@property (readonly, nonatomic) NSString* extendedLanguageTag STUB_PROPERTY;
@property (readonly, nonatomic) NSLocale* locale STUB_PROPERTY;
- (id)propertyList STUB_METHOD;
- (AVMediaSelectionOption*)associatedMediaSelectionOptionInMediaSelectionGroup:(AVMediaSelectionGroup*)mediaSelectionGroup STUB_METHOD;
@end
