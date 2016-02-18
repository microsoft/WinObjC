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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;
@class NSPredicate;
@protocol NSMetadataQueryDelegate;
@class NSDictionary;
@class NSOperationQueue;
@class NSMetadataItem;

FOUNDATION_EXPORT NSString* const NSMetadataQueryUbiquitousDocumentsScope;
FOUNDATION_EXPORT NSString* const NSMetadataQueryUbiquitousDataScope;
FOUNDATION_EXPORT NSString* const NSMetadataQueryAccessibleUbiquitousExternalDocumentsScope;
FOUNDATION_EXPORT NSString* const NSMetadataQueryResultContentRelevanceAttribute;
FOUNDATION_EXPORT NSString* const NSMetadataQueryUpdateAddedItemsKey;
FOUNDATION_EXPORT NSString* const NSMetadataQueryUpdateChangedItemsKey;
FOUNDATION_EXPORT NSString* const NSMetadataQueryUpdateRemovedItemsKey;
FOUNDATION_EXPORT NSString* const NSMetadataQueryDidFinishGatheringNotification;
FOUNDATION_EXPORT NSString* const NSMetadataQueryDidStartGatheringNotification;
FOUNDATION_EXPORT NSString* const NSMetadataQueryDidUpdateNotification;
FOUNDATION_EXPORT NSString* const NSMetadataQueryGatheringProgressNotification;

FOUNDATION_EXPORT_CLASS
@interface NSMetadataQuery : NSObject
@property (copy) NSArray* searchScopes STUB_PROPERTY;
@property (copy) NSPredicate* predicate STUB_PROPERTY;
@property (copy) NSArray* sortDescriptors STUB_PROPERTY;
@property (copy) NSArray* valueListAttributes STUB_PROPERTY;
@property (copy) NSArray* groupingAttributes STUB_PROPERTY;
@property NSTimeInterval notificationBatchingInterval STUB_PROPERTY;
@property (assign) id<NSMetadataQueryDelegate> delegate STUB_PROPERTY;
@property (copy) NSArray* searchItems STUB_PROPERTY;
@property (readonly, getter=isStarted) BOOL started STUB_PROPERTY;
- (BOOL)startQuery STUB_METHOD;
@property (readonly, getter=isGathering) BOOL gathering STUB_PROPERTY;
@property (readonly, getter=isStopped) BOOL stopped STUB_PROPERTY;
- (void)stopQuery STUB_METHOD;
@property (readonly, copy) NSArray* results STUB_PROPERTY;
@property (readonly) NSUInteger resultCount STUB_PROPERTY;
- (id)resultAtIndex:(NSUInteger)index STUB_METHOD;
- (NSUInteger)indexOfResult:(id)result STUB_METHOD;
@property (readonly, copy) NSArray* groupedResults STUB_PROPERTY;
- (void)enumerateResultsUsingBlock:(void (^)(id, NSUInteger, BOOL*))block STUB_METHOD;
- (void)enumerateResultsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id, NSUInteger, BOOL*))block STUB_METHOD;
@property (readonly, copy) NSDictionary* valueLists STUB_PROPERTY;
- (id)valueOfAttribute:(NSString*)attributeName forResultAtIndex:(NSUInteger)index STUB_METHOD;
- (void)enableUpdates STUB_METHOD;
- (void)disableUpdates STUB_METHOD;
@property (retain) NSOperationQueue* operationQueue STUB_PROPERTY;
@end

@protocol NSMetadataQueryDelegate <NSObject>
@optional
- (id)metadataQuery:(NSMetadataQuery*)query replacementObjectForResultObject:(NSMetadataItem*)result;
- (id)metadataQuery:(NSMetadataQuery*)query replacementValueForAttribute:(NSString*)attribute value:(id)attributeValue;
@end
