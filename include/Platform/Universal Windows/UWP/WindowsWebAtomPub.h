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

// WindowsWebAtomPub.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_WEB_ATOMPUB_EXPORT
#define OBJCUWP_WINDOWS_WEB_ATOMPUB_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Web_AtomPub.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WWAResourceCollection, WWAWorkspace, WWAServiceDocument, WWAAtomPubClient;
@protocol WWAIResourceCollection
, WWAIWorkspace, WWAIServiceDocument, WWAIAtomPubClient, WWAIAtomPubClientFactory;

#include "WindowsWebSyndication.h"
#include "WindowsFoundation.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsStorageStreams.h"
#include "WindowsDataXmlDom.h"

#import <Foundation/Foundation.h>

// Windows.Web.Syndication.ISyndicationNode
#ifndef __WWSISyndicationNode_DEFINED__
#define __WWSISyndicationNode_DEFINED__

@protocol WWSISyndicationNode
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
@property (retain) NSString* language;
@property (retain) NSString* nodeName;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeValue;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

OBJCUWP_WINDOWS_WEB_ATOMPUB_EXPORT
@interface WWSISyndicationNode : RTObject <WWSISyndicationNode>
@end

#endif // __WWSISyndicationNode_DEFINED__

// Windows.Web.AtomPub.ResourceCollection
#ifndef __WWAResourceCollection_DEFINED__
#define __WWAResourceCollection_DEFINED__

OBJCUWP_WINDOWS_WEB_ATOMPUB_EXPORT
@interface WWAResourceCollection : RTObject <WWSISyndicationNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* NSString * */ accepts;
@property (readonly) NSArray* /* WWSSyndicationCategory* */ categories;
@property (readonly) RTObject<WWSISyndicationText>* title;
@property (readonly) WFUri* uri;
@property (retain) WFUri* baseUri;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWAResourceCollection_DEFINED__

// Windows.Web.AtomPub.Workspace
#ifndef __WWAWorkspace_DEFINED__
#define __WWAWorkspace_DEFINED__

OBJCUWP_WINDOWS_WEB_ATOMPUB_EXPORT
@interface WWAWorkspace : RTObject <WWSISyndicationNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* WWAResourceCollection* */ collections;
@property (readonly) RTObject<WWSISyndicationText>* title;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWAWorkspace_DEFINED__

// Windows.Web.AtomPub.ServiceDocument
#ifndef __WWAServiceDocument_DEFINED__
#define __WWAServiceDocument_DEFINED__

OBJCUWP_WINDOWS_WEB_ATOMPUB_EXPORT
@interface WWAServiceDocument : RTObject <WWSISyndicationNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* WWAWorkspace* */ workspaces;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWAServiceDocument_DEFINED__

// Windows.Web.Syndication.ISyndicationClient
#ifndef __WWSISyndicationClient_DEFINED__
#define __WWSISyndicationClient_DEFINED__

@protocol WWSISyndicationClient
@property BOOL bypassCacheOnRetrieve;
@property unsigned int maxResponseBufferSize;
@property (retain) WSCPasswordCredential* proxyCredential;
@property (retain) WSCPasswordCredential* serverCredential;
@property unsigned int timeout;
- (void)setRequestHeader:(NSString*)name value:(NSString*)value;
- (void)retrieveFeedAsync:(WFUri*)uri
                  success:(void (^)(WWSSyndicationFeed*))success
                 progress:(void (^)(WWSRetrievalProgress*))progress
                  failure:(void (^)(NSError*))failure;
@end

OBJCUWP_WINDOWS_WEB_ATOMPUB_EXPORT
@interface WWSISyndicationClient : RTObject <WWSISyndicationClient>
@end

#endif // __WWSISyndicationClient_DEFINED__

// Windows.Web.AtomPub.AtomPubClient
#ifndef __WWAAtomPubClient_DEFINED__
#define __WWAAtomPubClient_DEFINED__

OBJCUWP_WINDOWS_WEB_ATOMPUB_EXPORT
@interface WWAAtomPubClient : RTObject <WWSISyndicationClient>
+ (WWAAtomPubClient*)makeAtomPubClientWithCredentials:(WSCPasswordCredential*)serverCredential ACTIVATOR;
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property unsigned int timeout;
@property (retain) WSCPasswordCredential* serverCredential;
@property (retain) WSCPasswordCredential* proxyCredential;
@property unsigned int maxResponseBufferSize;
@property BOOL bypassCacheOnRetrieve;
- (void)retrieveServiceDocumentAsync:(WFUri*)uri
                             success:(void (^)(WWAServiceDocument*))success
                            progress:(void (^)(WWSRetrievalProgress*))progress
                             failure:(void (^)(NSError*))failure;
- (void)retrieveMediaResourceAsync:(WFUri*)uri
                           success:(void (^)(RTObject<WSSIInputStream>*))success
                          progress:(void (^)(WWSRetrievalProgress*))progress
                           failure:(void (^)(NSError*))failure;
- (void)retrieveResourceAsync:(WFUri*)uri
                      success:(void (^)(WWSSyndicationItem*))success
                     progress:(void (^)(WWSRetrievalProgress*))progress
                      failure:(void (^)(NSError*))failure;
- (void)createResourceAsync:(WFUri*)uri
                description:(NSString*)description
                       item:(WWSSyndicationItem*)item
                    success:(void (^)(WWSSyndicationItem*))success
                   progress:(void (^)(WWSTransferProgress*))progress
                    failure:(void (^)(NSError*))failure;
- (void)createMediaResourceAsync:(WFUri*)uri
                       mediaType:(NSString*)mediaType
                     description:(NSString*)description
                     mediaStream:(RTObject<WSSIInputStream>*)mediaStream
                         success:(void (^)(WWSSyndicationItem*))success
                        progress:(void (^)(WWSTransferProgress*))progress
                         failure:(void (^)(NSError*))failure;
// Failed to generate member UpdateMediaResourceAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
// Failed to generate member UpdateResourceAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
// Failed to generate member UpdateResourceItemAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
// Failed to generate member DeleteResourceAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
// Failed to generate member DeleteResourceItemAsync (Can't marshal
// Windows.Foundation.IAsyncActionWithProgress`1<Windows.Web.Syndication.TransferProgress>)
- (void)cancelAsyncOperations;
- (void)setRequestHeader:(NSString*)name value:(NSString*)value;
- (void)retrieveFeedAsync:(WFUri*)uri
                  success:(void (^)(WWSSyndicationFeed*))success
                 progress:(void (^)(WWSRetrievalProgress*))progress
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WWAAtomPubClient_DEFINED__
