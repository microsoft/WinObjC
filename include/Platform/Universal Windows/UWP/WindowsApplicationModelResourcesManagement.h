//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESMANAGEMENTEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESMANAGEMENTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelResourcesManagement.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WARMIndexedResourceCandidate, WARMResourceIndexer, WARMIndexedResourceQualifier;
@protocol WARMIResourceIndexer, WARMIResourceIndexerFactory, WARMIResourceIndexerFactory2, WARMIIndexedResourceQualifier, WARMIIndexedResourceCandidate;

// Windows.ApplicationModel.Resources.Management.IndexedResourceType
enum _WARMIndexedResourceType {
    WARMIndexedResourceTypeString = 0,
    WARMIndexedResourceTypePath = 1,
    WARMIndexedResourceTypeEmbeddedData = 2,
};
typedef unsigned WARMIndexedResourceType;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Resources.Management.IndexedResourceCandidate
#ifndef __WARMIndexedResourceCandidate_DEFINED__
#define __WARMIndexedResourceCandidate_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESMANAGEMENTEXPORT
@interface WARMIndexedResourceCandidate : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSDictionary* /* NSString *, NSString * */ metadata;
@property (readonly) NSArray* /* WARMIndexedResourceQualifier* */ qualifiers;
@property (readonly) WARMIndexedResourceType type;
@property (readonly) WFUri* uri;
@property (readonly) NSString * valueAsString;
- (NSString *)getQualifierValue:(NSString *)qualifierName;
@end

#endif // __WARMIndexedResourceCandidate_DEFINED__

// Windows.ApplicationModel.Resources.Management.ResourceIndexer
#ifndef __WARMResourceIndexer_DEFINED__
#define __WARMResourceIndexer_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESMANAGEMENTEXPORT
@interface WARMResourceIndexer : RTObject
+ (WARMResourceIndexer*)makeResourceIndexerWithExtension:(WFUri*)projectRoot extensionDllPath:(WFUri*)extensionDllPath ACTIVATOR;
+ (WARMResourceIndexer*)makeResourceIndexer:(WFUri*)projectRoot ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WARMIndexedResourceCandidate*)indexFilePath:(WFUri*)filePath;
- (void)indexFileContentsAsync:(WFUri*)file success:(void (^)(NSArray* /* WARMIndexedResourceCandidate* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WARMResourceIndexer_DEFINED__

// Windows.ApplicationModel.Resources.Management.IndexedResourceQualifier
#ifndef __WARMIndexedResourceQualifier_DEFINED__
#define __WARMIndexedResourceQualifier_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESMANAGEMENTEXPORT
@interface WARMIndexedResourceQualifier : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * qualifierName;
@property (readonly) NSString * qualifierValue;
@end

#endif // __WARMIndexedResourceQualifier_DEFINED__

