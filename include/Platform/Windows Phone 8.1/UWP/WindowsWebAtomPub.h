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

#include "interopBase.h"
@class WWAResourceCollection, WWAWorkspace, WWAServiceDocument, WWAAtomPubClient;
@protocol WWAIResourceCollection
, WWAIWorkspace, WWAIServiceDocument, WWAIAtomPubClient, WWAIAtomPubClientFactory;

#include "WindowsWebSyndication.h"
#include "WindowsFoundation.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsDataXmlDom.h"

// Windows.Web.Syndication.ISyndicationNode
#ifndef __WWSISyndicationNode_DEFINED__
#define __WWSISyndicationNode_DEFINED__

@protocol WWSISyndicationNode
@property (readonly) id<NSFastEnumeration> /*WWSSyndicationAttribute*/ attributeExtensions;
@property (copy) WFUri* baseUri;
@property (readonly) id<NSFastEnumeration> /*WWSISyndicationNode*/ elementExtensions;
@property (copy) NSString* language;
@property (copy) NSString* nodeName;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeValue;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSISyndicationNode_DEFINED__

// Windows.Web.AtomPub.ResourceCollection
#ifndef __WWAResourceCollection_DEFINED__
#define __WWAResourceCollection_DEFINED__

WINRT_EXPORT
@interface WWAResourceCollection : RTObject <WWSISyndicationNode>
@property (readonly) id<NSFastEnumeration> /*String*/ accepts;
@property (readonly) id<NSFastEnumeration> /*WWSSyndicationCategory*/ categories;
@property (readonly) RTObject<WWSISyndicationText>* title;
@property (readonly) WFUri* uri;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) id<NSFastEnumeration> /*WWSSyndicationAttribute*/ attributeExtensions;
@property (readonly) id<NSFastEnumeration> /*WWSISyndicationNode*/ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWAResourceCollection_DEFINED__

// Windows.Web.AtomPub.Workspace
#ifndef __WWAWorkspace_DEFINED__
#define __WWAWorkspace_DEFINED__

WINRT_EXPORT
@interface WWAWorkspace : RTObject <WWSISyndicationNode>
@property (readonly) id<NSFastEnumeration> /*WWAResourceCollection*/ collections;
@property (readonly) RTObject<WWSISyndicationText>* title;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) id<NSFastEnumeration> /*WWSSyndicationAttribute*/ attributeExtensions;
@property (readonly) id<NSFastEnumeration> /*WWSISyndicationNode*/ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWAWorkspace_DEFINED__

// Windows.Web.AtomPub.ServiceDocument
#ifndef __WWAServiceDocument_DEFINED__
#define __WWAServiceDocument_DEFINED__

WINRT_EXPORT
@interface WWAServiceDocument : RTObject <WWSISyndicationNode>
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) id<NSFastEnumeration> /*WWSSyndicationAttribute*/ attributeExtensions;
@property (readonly) id<NSFastEnumeration> /*WWSISyndicationNode*/ elementExtensions;
@property (readonly) id<NSFastEnumeration> /*WWAWorkspace*/ workspaces;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWAServiceDocument_DEFINED__

// Windows.Web.Syndication.ISyndicationClient
#ifndef __WWSISyndicationClient_DEFINED__
#define __WWSISyndicationClient_DEFINED__

@protocol WWSISyndicationClient
@property BOOL bypassCacheOnRetrieve;
@property unsigned maxResponseBufferSize;
@property (copy) WSCPasswordCredential* proxyCredential;
@property (copy) WSCPasswordCredential* serverCredential;
@property unsigned timeout;
- (void)setRequestHeader:(NSString*)name value:(NSString*)value;
- (void)retrieveFeedAsync:(WFUri*)uri
                  success:(void (^)(WWSSyndicationFeed*))success
                 progress:(void (^)(WWSRetrievalProgress*))progress
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WWSISyndicationClient_DEFINED__

// Windows.Web.AtomPub.AtomPubClient
#ifndef __WWAAtomPubClient_DEFINED__
#define __WWAAtomPubClient_DEFINED__

WINRT_EXPORT
@interface WWAAtomPubClient : RTObject <WWSISyndicationClient>
+ (instancetype)create ACTIVATOR;
+ (WWAAtomPubClient*)createAtomPubClientWithCredentials:(WSCPasswordCredential*)serverCredential ACTIVATOR;
@property unsigned timeout;
@property (copy) WSCPasswordCredential* serverCredential;
@property (copy) WSCPasswordCredential* proxyCredential;
@property unsigned maxResponseBufferSize;
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
