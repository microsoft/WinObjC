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

#import <CoreData/CoreDataExport.h>
#import <Foundation/NSObject.h>

@class NSEntityDescription;
@class NSString;
@class NSDictionary;
@class NSArray;
@class NSData;

COREDATA_EXPORT_CLASS
@interface NSPropertyDescription : NSObject <NSCoding, NSCopying>
@property (readonly, assign, nonatomic) NSEntityDescription* entity;
@property (getter=isIndexed) BOOL indexed;
@property (getter=isOptional) BOOL optional;
@property (getter=isTransient) BOOL transient;
@property (copy, nonatomic) NSString* name;
@property (nonatomic, strong) NSDictionary* userInfo;
@property (readonly, strong) NSArray* validationPredicates;
@property (readonly, strong) NSArray* validationWarnings STUB_PROPERTY;
- (void)setValidationPredicates:(NSArray*)validationPredicates withValidationWarnings:(NSArray*)validationWarnings STUB_METHOD;
@property (readonly, copy) NSData* versionHash STUB_PROPERTY;
@property (copy) NSString* versionHashModifier;
@property (copy) NSString* renamingIdentifier;
@property (getter=isIndexedBySpotlight) BOOL indexedBySpotlight;
@property (getter=isStoredInExternalRecord) BOOL storedInExternalRecord;
@end
