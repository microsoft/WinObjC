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

@protocol NSFilePresenter;
@class NSArray;
@class NSString;
@class NSOperationQueue;
@class NSError;
@class NSURL;

typedef NSUInteger NSFileCoordinatorReadingOptions;
typedef NSUInteger NSFileCoordinatorWritingOptions;
enum {
    NSFileCoordinatorReadingWithoutChanges = 1 << 0,
    NSFileCoordinatorReadingResolvesSymbolicLink = 1 << 1,
    NSFileCoordinatorReadingImmediatelyAvailableMetadataOnly = 1 << 2,
    NSFileCoordinatorReadingForUploading = 1 << 3
};

enum {
    NSFileCoordinatorWritingForDeleting = 1 << 0,
    NSFileCoordinatorWritingForMoving = 1 << 1,
    NSFileCoordinatorWritingForMerging = 1 << 2,
    NSFileCoordinatorWritingForReplacing = 1 << 3,
    NSFileCoordinatorWritingContentIndependentMetadataOnly = 1 << 4
};

FOUNDATION_EXPORT_CLASS
@interface NSFileCoordinator : NSObject
- (instancetype)initWithFilePresenter:(id<NSFilePresenter>)filePresenterOrNil STUB_METHOD;
+ (void)addFilePresenter:(id<NSFilePresenter>)filePresenter STUB_METHOD;
+ (void)removeFilePresenter:(id<NSFilePresenter>)filePresenter STUB_METHOD;
+ (NSArray*)filePresenters STUB_METHOD;
@property (copy) NSString* purposeIdentifier STUB_PROPERTY;
- (void)coordinateAccessWithIntents:(NSArray*)intents queue:(NSOperationQueue*)queue byAccessor:(void (^)(NSError*))accessor STUB_METHOD;
- (void)coordinateReadingItemAtURL:(NSURL*)url
                           options:(NSFileCoordinatorReadingOptions)options
                             error:(NSError* _Nullable*)outError
                        byAccessor:(void (^)(NSURL*))reader STUB_METHOD;
- (void)coordinateWritingItemAtURL:(NSURL*)url
                           options:(NSFileCoordinatorWritingOptions)options
                             error:(NSError* _Nullable*)outError
                        byAccessor:(void (^)(NSURL*))writer STUB_METHOD;
- (void)coordinateReadingItemAtURL:(NSURL*)readingURL
                           options:(NSFileCoordinatorReadingOptions)readingOptions
                  writingItemAtURL:(NSURL*)writingURL
                           options:(NSFileCoordinatorWritingOptions)writingOptions
                             error:(NSError* _Nullable*)outError
                        byAccessor:(void (^)(NSURL*, NSURL*))readerWriter STUB_METHOD;
- (void)coordinateWritingItemAtURL:(NSURL*)url1
                           options:(NSFileCoordinatorWritingOptions)options1
                  writingItemAtURL:(NSURL*)url2
                           options:(NSFileCoordinatorWritingOptions)options2
                             error:(NSError* _Nullable*)outError
                        byAccessor:(void (^)(NSURL*, NSURL*))writer STUB_METHOD;
- (void)prepareForReadingItemsAtURLs:(NSArray*)readingURLs
                             options:(NSFileCoordinatorReadingOptions)readingOptions
                  writingItemsAtURLs:(NSArray*)writingURLs
                             options:(NSFileCoordinatorWritingOptions)writingOptions
                               error:(NSError* _Nullable*)outError
                          byAccessor:(void (^)(void (^)(void)))batchAccessor STUB_METHOD;
- (void)itemAtURL:(NSURL*)oldURL willMoveToURL:(NSURL*)newURL STUB_METHOD;
- (void)itemAtURL:(NSURL*)oldURL didMoveToURL:(NSURL*)newURL STUB_METHOD;
- (void)cancel STUB_METHOD;
@end
