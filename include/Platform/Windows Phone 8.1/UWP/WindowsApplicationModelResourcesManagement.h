//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsApplicationModelResourcesManagement.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WARMIndexedResourceCandidate, WARMResourceIndexer, WARMIndexedResourceQualifier;
@protocol WARMIResourceIndexer
, WARMIResourceIndexerFactory, WARMIResourceIndexerFactory2, WARMIIndexedResourceQualifier, WARMIIndexedResourceCandidate;

// Windows.ApplicationModel.Resources.Management.IndexedResourceType
enum _WARMIndexedResourceType {
    WARMIndexedResourceTypeString = 0,
    WARMIndexedResourceTypePath = 1,
    WARMIndexedResourceTypeEmbeddedData = 2,
};
typedef unsigned WARMIndexedResourceType;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

// Windows.ApplicationModel.Resources.Management.IndexedResourceCandidate
#ifndef __WARMIndexedResourceCandidate_DEFINED__
#define __WARMIndexedResourceCandidate_DEFINED__

WINRT_EXPORT
@interface WARMIndexedResourceCandidate : RTObject
@property (readonly) NSDictionary* /*String, String*/ metadata;
@property (readonly) id<NSFastEnumeration> /*WARMIndexedResourceQualifier*/ qualifiers;
@property (readonly) WARMIndexedResourceType type;
@property (readonly) WFUri* uri;
@property (readonly) NSString* valueAsString;
- (NSString*)getQualifierValue:(NSString*)qualifierName;
@end

#endif // __WARMIndexedResourceCandidate_DEFINED__

// Windows.ApplicationModel.Resources.Management.ResourceIndexer
#ifndef __WARMResourceIndexer_DEFINED__
#define __WARMResourceIndexer_DEFINED__

WINRT_EXPORT
@interface WARMResourceIndexer : RTObject
+ (WARMResourceIndexer*)createResourceIndexer:(WFUri*)projectRoot ACTIVATOR;
+ (instancetype)create ACTIVATOR;
+ (WARMResourceIndexer*)createResourceIndexerWithExtension:(WFUri*)projectRoot extensionDllPath:(WFUri*)extensionDllPath ACTIVATOR;
- (WARMIndexedResourceCandidate*)indexFilePath:(WFUri*)filePath;
- (void)indexFileContentsAsync:(WFUri*)file
                       success:(void (^)(id<NSFastEnumeration> /*WARMIndexedResourceCandidate*/))success
                       failure:(void (^)(NSError*))failure;
@end

#endif // __WARMResourceIndexer_DEFINED__

// Windows.ApplicationModel.Resources.Management.IndexedResourceQualifier
#ifndef __WARMIndexedResourceQualifier_DEFINED__
#define __WARMIndexedResourceQualifier_DEFINED__

WINRT_EXPORT
@interface WARMIndexedResourceQualifier : RTObject
@property (readonly) NSString* qualifierName;
@property (readonly) NSString* qualifierValue;
@end

#endif // __WARMIndexedResourceQualifier_DEFINED__
