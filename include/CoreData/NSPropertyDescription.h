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
#import <Foundation/NSCoding.h>
#import <Foundation/NSCopying.h>
#import <Foundation/NSObject.h>

@class NSEntityDescription;
@class NSString;
@class NSDictionary;
@class NSArray;
@class NSData;

COREDATA_EXPORT_CLASS
@interface NSPropertyDescription : NSObject <NSCoding, NSCopying>
@property (readonly, assign, nonatomic) NSEntityDescription* entity STUB_PROPERTY;
@property (getter=isIndexed) BOOL indexed STUB_PROPERTY;
@property (getter=isOptional) BOOL optional STUB_PROPERTY;
@property (getter=isTransient) BOOL transient STUB_PROPERTY;
@property (copy, nonatomic) NSString* name STUB_PROPERTY;
@property (nonatomic, strong) NSDictionary* userInfo STUB_PROPERTY;
@property (readonly, strong) NSArray* validationPredicates STUB_PROPERTY;
@property (readonly, strong) NSArray* validationWarnings STUB_PROPERTY;
- (void)setValidationPredicates:(NSArray*)validationPredicates withValidationWarnings:(NSArray*)validationWarnings STUB_METHOD;
@property (readonly, copy) NSData* versionHash STUB_PROPERTY;
@property (copy) NSString* versionHashModifier STUB_PROPERTY;
@property (copy) NSString* renamingIdentifier STUB_PROPERTY;
@property (getter=isIndexedBySpotlight) BOOL indexedBySpotlight STUB_PROPERTY;
@property (getter=isStoredInExternalRecord) BOOL storedInExternalRecord STUB_PROPERTY;
@end
