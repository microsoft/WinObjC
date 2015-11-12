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

// WindowsWebSyndication.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WWSSyndicationAttribute, WWSSyndicationNode, WWSSyndicationGenerator, WWSSyndicationText, WWSSyndicationContent, WWSSyndicationLink,
    WWSSyndicationPerson, WWSSyndicationCategory, WWSSyndicationFeed, WWSSyndicationItem, WWSSyndicationClient, WWSSyndicationError;
@class WWSRetrievalProgress, WWSTransferProgress;
@protocol WWSISyndicationAttribute
, WWSISyndicationAttributeFactory, WWSISyndicationNode, WWSISyndicationNodeFactory, WWSISyndicationGenerator,
    WWSISyndicationGeneratorFactory, WWSISyndicationText, WWSISyndicationTextFactory, WWSISyndicationContent, WWSISyndicationContentFactory,
    WWSISyndicationLink, WWSISyndicationLinkFactory, WWSISyndicationPerson, WWSISyndicationPersonFactory, WWSISyndicationCategory,
    WWSISyndicationCategoryFactory, WWSISyndicationItem, WWSISyndicationItemFactory, WWSISyndicationFeed, WWSISyndicationFeedFactory,
    WWSISyndicationClient, WWSISyndicationClientFactory, WWSISyndicationErrorStatics;

// Windows.Web.Syndication.SyndicationFormat
enum _WWSSyndicationFormat {
    WWSSyndicationFormatAtom10 = 0,
    WWSSyndicationFormatRss20 = 1,
    WWSSyndicationFormatRss10 = 2,
    WWSSyndicationFormatRss092 = 3,
    WWSSyndicationFormatRss091 = 4,
    WWSSyndicationFormatAtom03 = 5,
};
typedef unsigned WWSSyndicationFormat;

// Windows.Web.Syndication.SyndicationErrorStatus
enum _WWSSyndicationErrorStatus {
    WWSSyndicationErrorStatusUnknown = 0,
    WWSSyndicationErrorStatusMissingRequiredElement = 1,
    WWSSyndicationErrorStatusMissingRequiredAttribute = 2,
    WWSSyndicationErrorStatusInvalidXml = 3,
    WWSSyndicationErrorStatusUnexpectedContent = 4,
    WWSSyndicationErrorStatusUnsupportedFormat = 5,
};
typedef unsigned WWSSyndicationErrorStatus;

// Windows.Web.Syndication.SyndicationTextType
enum _WWSSyndicationTextType {
    WWSSyndicationTextTypeText = 0,
    WWSSyndicationTextTypeHtml = 1,
    WWSSyndicationTextTypeXhtml = 2,
};
typedef unsigned WWSSyndicationTextType;

#include "WindowsFoundation.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsFoundationCollections.h"
#include "WindowsDataXmlDom.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Web.Syndication.RetrievalProgress
WINRT_EXPORT
@interface WWSRetrievalProgress : NSObject
+ (instancetype) new;
@property unsigned int bytesRetrieved;
@property unsigned int totalBytesToRetrieve;
@end

// [struct] Windows.Web.Syndication.TransferProgress
WINRT_EXPORT
@interface WWSTransferProgress : NSObject
+ (instancetype) new;
@property unsigned int bytesSent;
@property unsigned int totalBytesToSend;
@property unsigned int bytesRetrieved;
@property unsigned int totalBytesToRetrieve;
@end

// Windows.Web.Syndication.ISyndicationNode
#ifndef __WWSISyndicationNode_DEFINED__
#define __WWSISyndicationNode_DEFINED__

@protocol WWSISyndicationNode
@property (readonly) NSMutableArray* attributeExtensions;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* elementExtensions;
@property (copy) NSString* language;
@property (copy) NSString* nodeName;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeValue;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSISyndicationNode_DEFINED__

// Windows.Web.Syndication.ISyndicationText
#ifndef __WWSISyndicationText_DEFINED__
#define __WWSISyndicationText_DEFINED__

@protocol WWSISyndicationText <WWSISyndicationNode>
@property (copy) NSString* text;
@property (copy) NSString* type;
@property (copy) WDXDXmlDocument* xml;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSISyndicationText_DEFINED__

// Windows.Web.Syndication.ISyndicationClient
#ifndef __WWSISyndicationClient_DEFINED__
#define __WWSISyndicationClient_DEFINED__

@protocol WWSISyndicationClient
@property BOOL bypassCacheOnRetrieve;
@property unsigned int maxResponseBufferSize;
@property (copy) WSCPasswordCredential* proxyCredential;
@property (copy) WSCPasswordCredential* serverCredential;
@property unsigned int timeout;
- (void)setRequestHeader:(NSString*)name value:(NSString*)value;
- (void)retrieveFeedAsync:(WFUri*)uri
                  success:(void (^)(WWSSyndicationFeed*))success
                 progress:(void (^)(WWSRetrievalProgress*))progress
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WWSISyndicationClient_DEFINED__

// Windows.Web.Syndication.SyndicationAttribute
#ifndef __WWSSyndicationAttribute_DEFINED__
#define __WWSSyndicationAttribute_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationAttribute : RTObject
+ (instancetype)create ACTIVATOR;
+ (WWSSyndicationAttribute*)createSyndicationAttribute:(NSString*)attributeName
                                    attributeNamespace:(NSString*)attributeNamespace
                                        attributeValue:(NSString*)attributeValue ACTIVATOR;
@property (copy) NSString* value;
@property (copy) NSString* Namespace;
@property (copy) NSString* name;
@end

#endif // __WWSSyndicationAttribute_DEFINED__

// Windows.Web.Syndication.SyndicationNode
#ifndef __WWSSyndicationNode_DEFINED__
#define __WWSSyndicationNode_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationNode : RTObject <WWSISyndicationNode>
+ (WWSSyndicationNode*)createSyndicationNode:(NSString*)nodeName
                               nodeNamespace:(NSString*)nodeNamespace
                                   nodeValue:(NSString*)nodeValue ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationNode_DEFINED__

// Windows.Web.Syndication.SyndicationGenerator
#ifndef __WWSSyndicationGenerator_DEFINED__
#define __WWSSyndicationGenerator_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationGenerator : RTObject <WWSISyndicationNode>
+ (instancetype)create ACTIVATOR;
+ (WWSSyndicationGenerator*)createSyndicationGenerator:(NSString*)text ACTIVATOR;
@property (copy) NSString* version;
@property (copy) WFUri* uri;
@property (copy) NSString* text;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationGenerator_DEFINED__

// Windows.Web.Syndication.SyndicationText
#ifndef __WWSSyndicationText_DEFINED__
#define __WWSSyndicationText_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationText : RTObject <WWSISyndicationText, WWSISyndicationNode>
+ (instancetype)create ACTIVATOR;
+ (WWSSyndicationText*)createSyndicationText:(NSString*)text ACTIVATOR;
+ (WWSSyndicationText*)createSyndicationTextEx:(NSString*)text type:(WWSSyndicationTextType)type ACTIVATOR;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
@property (copy) WDXDXmlDocument* xml;
@property (copy) NSString* type;
@property (copy) NSString* text;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationText_DEFINED__

// Windows.Web.Syndication.SyndicationContent
#ifndef __WWSSyndicationContent_DEFINED__
#define __WWSSyndicationContent_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationContent : RTObject <WWSISyndicationText, WWSISyndicationNode>
+ (instancetype)create ACTIVATOR;
+ (WWSSyndicationContent*)createSyndicationContent:(NSString*)text type:(WWSSyndicationTextType)type ACTIVATOR;
+ (WWSSyndicationContent*)createSyndicationContentWithSourceUri:(WFUri*)sourceUri ACTIVATOR;
@property (copy) WFUri* sourceUri;
@property (copy) NSString* nodeValue;
@property (copy) WFUri* baseUri;
@property (copy) NSString* language;
@property (copy) NSString* nodeName;
@property (copy) NSString* nodeNamespace;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
@property (copy) NSString* text;
@property (copy) NSString* type;
@property (copy) WDXDXmlDocument* xml;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationContent_DEFINED__

// Windows.Web.Syndication.SyndicationLink
#ifndef __WWSSyndicationLink_DEFINED__
#define __WWSSyndicationLink_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationLink : RTObject <WWSISyndicationNode>
+ (WWSSyndicationLink*)createSyndicationLink:(WFUri*)uri ACTIVATOR;
+ (WWSSyndicationLink*)createSyndicationLinkEx:(WFUri*)uri
                                  relationship:(NSString*)relationship
                                         title:(NSString*)title
                                     mediaType:(NSString*)mediaType
                                        length:(unsigned int)length ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* uri;
@property (copy) NSString* title;
@property (copy) NSString* resourceLanguage;
@property (copy) NSString* relationship;
@property (copy) NSString* mediaType;
@property unsigned int length;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationLink_DEFINED__

// Windows.Web.Syndication.SyndicationPerson
#ifndef __WWSSyndicationPerson_DEFINED__
#define __WWSSyndicationPerson_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationPerson : RTObject <WWSISyndicationNode>
+ (WWSSyndicationPerson*)createSyndicationPerson:(NSString*)name ACTIVATOR;
+ (WWSSyndicationPerson*)createSyndicationPersonEx:(NSString*)name email:(NSString*)email uri:(WFUri*)uri ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
@property (copy) WFUri* uri;
@property (copy) NSString* name;
@property (copy) NSString* email;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationPerson_DEFINED__

// Windows.Web.Syndication.SyndicationCategory
#ifndef __WWSSyndicationCategory_DEFINED__
#define __WWSSyndicationCategory_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationCategory : RTObject <WWSISyndicationNode>
+ (instancetype)create ACTIVATOR;
+ (WWSSyndicationCategory*)createSyndicationCategory:(NSString*)term ACTIVATOR;
+ (WWSSyndicationCategory*)createSyndicationCategoryEx:(NSString*)term scheme:(NSString*)scheme label:(NSString*)label ACTIVATOR;
@property (copy) NSString* term;
@property (copy) NSString* scheme;
@property (copy) NSString* label;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationCategory_DEFINED__

// Windows.Web.Syndication.SyndicationFeed
#ifndef __WWSSyndicationFeed_DEFINED__
#define __WWSSyndicationFeed_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationFeed : RTObject <WWSISyndicationNode>
+ (WWSSyndicationFeed*)createSyndicationFeed:(NSString*)title subtitle:(NSString*)subtitle uri:(WFUri*)uri ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject<WWSISyndicationText>* title;
@property (copy) RTObject<WWSISyndicationText>* subtitle;
@property (copy) RTObject<WWSISyndicationText>* rights;
@property (copy) WWSSyndicationGenerator* generator;
@property (copy) WFDateTime* lastUpdatedTime;
@property (copy) WFUri* imageUri;
@property (copy) WFUri* iconUri;
@property (copy) NSString* id;
@property (readonly) WFUri* firstUri;
@property (readonly) NSMutableArray* items;
@property (readonly) WFUri* lastUri;
@property (readonly) NSMutableArray* links;
@property (readonly) WFUri* nextUri;
@property (readonly) WFUri* previousUri;
@property (readonly) NSMutableArray* categories;
@property (readonly) WWSSyndicationFormat sourceFormat;
@property (readonly) NSMutableArray* contributors;
@property (readonly) NSMutableArray* authors;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
- (void)load:(NSString*)feed;
- (void)loadFromXml:(WDXDXmlDocument*)feedDocument;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationFeed_DEFINED__

// Windows.Web.Syndication.SyndicationItem
#ifndef __WWSSyndicationItem_DEFINED__
#define __WWSSyndicationItem_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationItem : RTObject <WWSISyndicationNode>
+ (WWSSyndicationItem*)createSyndicationItem:(NSString*)title content:(WWSSyndicationContent*)content uri:(WFUri*)uri ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject<WWSISyndicationText>* title;
@property (copy) WWSSyndicationFeed* source;
@property (copy) RTObject<WWSISyndicationText>* rights;
@property (copy) RTObject<WWSISyndicationText>* summary;
@property (copy) WFDateTime* publishedDate;
@property (copy) WFUri* commentsUri;
@property (copy) NSString* id;
@property (copy) WFDateTime* lastUpdatedTime;
@property (copy) WWSSyndicationContent* content;
@property (readonly) WFUri* editUri;
@property (readonly) NSMutableArray* links;
@property (readonly) NSMutableArray* authors;
@property (readonly) NSMutableArray* categories;
@property (readonly) NSMutableArray* contributors;
@property (readonly) WFUri* itemUri;
@property (readonly) NSString* eTag;
@property (readonly) WFUri* editMediaUri;
@property (copy) NSString* nodeValue;
@property (copy) NSString* nodeNamespace;
@property (copy) NSString* nodeName;
@property (copy) NSString* language;
@property (copy) WFUri* baseUri;
@property (readonly) NSMutableArray* attributeExtensions;
@property (readonly) NSMutableArray* elementExtensions;
- (void)load:(NSString*)item;
- (void)loadFromXml:(WDXDXmlDocument*)itemDocument;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationItem_DEFINED__

// Windows.Web.Syndication.SyndicationClient
#ifndef __WWSSyndicationClient_DEFINED__
#define __WWSSyndicationClient_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationClient : RTObject <WWSISyndicationClient>
+ (instancetype)create ACTIVATOR;
+ (WWSSyndicationClient*)createSyndicationClient:(WSCPasswordCredential*)serverCredential ACTIVATOR;
@property unsigned int timeout;
@property (copy) WSCPasswordCredential* serverCredential;
@property (copy) WSCPasswordCredential* proxyCredential;
@property unsigned int maxResponseBufferSize;
@property BOOL bypassCacheOnRetrieve;
- (void)setRequestHeader:(NSString*)name value:(NSString*)value;
- (void)retrieveFeedAsync:(WFUri*)uri
                  success:(void (^)(WWSSyndicationFeed*))success
                 progress:(void (^)(WWSRetrievalProgress*))progress
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WWSSyndicationClient_DEFINED__

// Windows.Web.Syndication.SyndicationError
#ifndef __WWSSyndicationError_DEFINED__
#define __WWSSyndicationError_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationError : RTObject
+ (WWSSyndicationErrorStatus)getStatus:(int)hresult;
@end

#endif // __WWSSyndicationError_DEFINED__
