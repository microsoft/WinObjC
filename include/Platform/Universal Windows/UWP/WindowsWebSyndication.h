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

#include <UWP/interopBase.h>

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
#include "WindowsDataXmlDom.h"
#include "WindowsSecurityCredentials.h"

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
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
@property (retain) NSString* language;
@property (retain) NSString* nodeName;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeValue;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSISyndicationNode_DEFINED__

// Windows.Web.Syndication.ISyndicationText
#ifndef __WWSISyndicationText_DEFINED__
#define __WWSISyndicationText_DEFINED__

@protocol WWSISyndicationText <WWSISyndicationNode>
@property (retain) NSString* text;
@property (retain) NSString* type;
@property (retain) WDXDXmlDocument* xml;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSISyndicationText_DEFINED__

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

#endif // __WWSISyndicationClient_DEFINED__

// Windows.Web.Syndication.SyndicationAttribute
#ifndef __WWSSyndicationAttribute_DEFINED__
#define __WWSSyndicationAttribute_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationAttribute : RTObject
+ (instancetype)make ACTIVATOR;
+ (WWSSyndicationAttribute*)makeSyndicationAttribute:(NSString*)attributeName
                                  attributeNamespace:(NSString*)attributeNamespace
                                      attributeValue:(NSString*)attributeValue ACTIVATOR;
@property (retain) NSString* value;
@property (retain) NSString* Namespace;
@property (retain) NSString* name;
@end

#endif // __WWSSyndicationAttribute_DEFINED__

// Windows.Web.Syndication.SyndicationNode
#ifndef __WWSSyndicationNode_DEFINED__
#define __WWSSyndicationNode_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationNode : RTObject <WWSISyndicationNode>
+ (WWSSyndicationNode*)makeSyndicationNode:(NSString*)nodeName
                             nodeNamespace:(NSString*)nodeNamespace
                                 nodeValue:(NSString*)nodeValue ACTIVATOR;
+ (instancetype)make ACTIVATOR;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationNode_DEFINED__

// Windows.Web.Syndication.SyndicationGenerator
#ifndef __WWSSyndicationGenerator_DEFINED__
#define __WWSSyndicationGenerator_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationGenerator : RTObject <WWSISyndicationNode>
+ (instancetype)make ACTIVATOR;
+ (WWSSyndicationGenerator*)makeSyndicationGenerator:(NSString*)text ACTIVATOR;
@property (retain) NSString* Version;
@property (retain) WFUri* uri;
@property (retain) NSString* text;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationGenerator_DEFINED__

// Windows.Web.Syndication.SyndicationText
#ifndef __WWSSyndicationText_DEFINED__
#define __WWSSyndicationText_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationText : RTObject <WWSISyndicationText, WWSISyndicationNode>
+ (WWSSyndicationText*)makeSyndicationText:(NSString*)text ACTIVATOR;
+ (WWSSyndicationText*)makeSyndicationTextEx:(NSString*)text type:(WWSSyndicationTextType)type ACTIVATOR;
+ (instancetype)make ACTIVATOR;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
@property (retain) WDXDXmlDocument* xml;
@property (retain) NSString* type;
@property (retain) NSString* text;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationText_DEFINED__

// Windows.Web.Syndication.SyndicationContent
#ifndef __WWSSyndicationContent_DEFINED__
#define __WWSSyndicationContent_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationContent : RTObject <WWSISyndicationText, WWSISyndicationNode>
+ (WWSSyndicationContent*)makeSyndicationContent:(NSString*)text type:(WWSSyndicationTextType)type ACTIVATOR;
+ (WWSSyndicationContent*)makeSyndicationContentWithSourceUri:(WFUri*)sourceUri ACTIVATOR;
+ (instancetype)make ACTIVATOR;
@property (retain) WFUri* sourceUri;
@property (retain) NSString* nodeValue;
@property (retain) WFUri* baseUri;
@property (retain) NSString* language;
@property (retain) NSString* nodeName;
@property (retain) NSString* nodeNamespace;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
@property (retain) NSString* text;
@property (retain) NSString* type;
@property (retain) WDXDXmlDocument* xml;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationContent_DEFINED__

// Windows.Web.Syndication.SyndicationLink
#ifndef __WWSSyndicationLink_DEFINED__
#define __WWSSyndicationLink_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationLink : RTObject <WWSISyndicationNode>
+ (instancetype)make ACTIVATOR;
+ (WWSSyndicationLink*)makeSyndicationLink:(WFUri*)uri ACTIVATOR;
+ (WWSSyndicationLink*)makeSyndicationLinkEx:(WFUri*)uri
                                relationship:(NSString*)relationship
                                       title:(NSString*)title
                                   mediaType:(NSString*)mediaType
                                      length:(unsigned int)length ACTIVATOR;
@property (retain) WFUri* uri;
@property (retain) NSString* title;
@property (retain) NSString* resourceLanguage;
@property (retain) NSString* relationship;
@property (retain) NSString* mediaType;
@property unsigned int length;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationLink_DEFINED__

// Windows.Web.Syndication.SyndicationPerson
#ifndef __WWSSyndicationPerson_DEFINED__
#define __WWSSyndicationPerson_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationPerson : RTObject <WWSISyndicationNode>
+ (WWSSyndicationPerson*)makeSyndicationPerson:(NSString*)name ACTIVATOR;
+ (WWSSyndicationPerson*)makeSyndicationPersonEx:(NSString*)name email:(NSString*)email uri:(WFUri*)uri ACTIVATOR;
+ (instancetype)make ACTIVATOR;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
@property (retain) WFUri* uri;
@property (retain) NSString* name;
@property (retain) NSString* email;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationPerson_DEFINED__

// Windows.Web.Syndication.SyndicationCategory
#ifndef __WWSSyndicationCategory_DEFINED__
#define __WWSSyndicationCategory_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationCategory : RTObject <WWSISyndicationNode>
+ (WWSSyndicationCategory*)makeSyndicationCategory:(NSString*)term ACTIVATOR;
+ (WWSSyndicationCategory*)makeSyndicationCategoryEx:(NSString*)term scheme:(NSString*)scheme label:(NSString*)label ACTIVATOR;
+ (instancetype)make ACTIVATOR;
@property (retain) NSString* term;
@property (retain) NSString* scheme;
@property (retain) NSString* label;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationCategory_DEFINED__

// Windows.Web.Syndication.SyndicationFeed
#ifndef __WWSSyndicationFeed_DEFINED__
#define __WWSSyndicationFeed_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationFeed : RTObject <WWSISyndicationNode>
+ (WWSSyndicationFeed*)makeSyndicationFeed:(NSString*)title subtitle:(NSString*)subtitle uri:(WFUri*)uri ACTIVATOR;
+ (instancetype)make ACTIVATOR;
@property (retain) RTObject<WWSISyndicationText>* title;
@property (retain) RTObject<WWSISyndicationText>* subtitle;
@property (retain) RTObject<WWSISyndicationText>* rights;
@property (retain) WWSSyndicationGenerator* generator;
@property (retain) WFDateTime* lastUpdatedTime;
@property (retain) WFUri* imageUri;
@property (retain) WFUri* iconUri;
@property (retain) NSString* id;
@property (readonly) WFUri* firstUri;
@property (readonly) NSMutableArray* /* WWSSyndicationItem* */ items;
@property (readonly) WFUri* lastUri;
@property (readonly) NSMutableArray* /* WWSSyndicationLink* */ links;
@property (readonly) WFUri* nextUri;
@property (readonly) WFUri* previousUri;
@property (readonly) NSMutableArray* /* WWSSyndicationCategory* */ categories;
@property (readonly) WWSSyndicationFormat sourceFormat;
@property (readonly) NSMutableArray* /* WWSSyndicationPerson* */ contributors;
@property (readonly) NSMutableArray* /* WWSSyndicationPerson* */ authors;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (void)Load:(NSString*)feed;
- (void)loadFromXml:(WDXDXmlDocument*)feedDocument;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationFeed_DEFINED__

// Windows.Web.Syndication.SyndicationItem
#ifndef __WWSSyndicationItem_DEFINED__
#define __WWSSyndicationItem_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationItem : RTObject <WWSISyndicationNode>
+ (instancetype)make ACTIVATOR;
+ (WWSSyndicationItem*)makeSyndicationItem:(NSString*)title content:(WWSSyndicationContent*)content uri:(WFUri*)uri ACTIVATOR;
@property (retain) RTObject<WWSISyndicationText>* title;
@property (retain) WWSSyndicationFeed* source;
@property (retain) RTObject<WWSISyndicationText>* rights;
@property (retain) RTObject<WWSISyndicationText>* summary;
@property (retain) WFDateTime* publishedDate;
@property (retain) WFUri* commentsUri;
@property (retain) NSString* id;
@property (retain) WFDateTime* lastUpdatedTime;
@property (retain) WWSSyndicationContent* content;
@property (readonly) WFUri* editUri;
@property (readonly) NSMutableArray* /* WWSSyndicationLink* */ links;
@property (readonly) NSMutableArray* /* WWSSyndicationPerson* */ authors;
@property (readonly) NSMutableArray* /* WWSSyndicationCategory* */ categories;
@property (readonly) NSMutableArray* /* WWSSyndicationPerson* */ contributors;
@property (readonly) WFUri* itemUri;
@property (readonly) NSString* eTag;
@property (readonly) WFUri* editMediaUri;
@property (retain) NSString* nodeValue;
@property (retain) NSString* nodeNamespace;
@property (retain) NSString* nodeName;
@property (retain) NSString* language;
@property (retain) WFUri* baseUri;
@property (readonly) NSMutableArray* /* WWSSyndicationAttribute* */ attributeExtensions;
@property (readonly) NSMutableArray* /* RTObject<WWSISyndicationNode>* */ elementExtensions;
- (void)Load:(NSString*)item;
- (void)loadFromXml:(WDXDXmlDocument*)itemDocument;
- (WDXDXmlDocument*)getXmlDocument:(WWSSyndicationFormat)format;
@end

#endif // __WWSSyndicationItem_DEFINED__

// Windows.Web.Syndication.SyndicationClient
#ifndef __WWSSyndicationClient_DEFINED__
#define __WWSSyndicationClient_DEFINED__

WINRT_EXPORT
@interface WWSSyndicationClient : RTObject <WWSISyndicationClient>
+ (instancetype)make ACTIVATOR;
+ (WWSSyndicationClient*)makeSyndicationClient:(WSCPasswordCredential*)serverCredential ACTIVATOR;
@property unsigned int timeout;
@property (retain) WSCPasswordCredential* serverCredential;
@property (retain) WSCPasswordCredential* proxyCredential;
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
