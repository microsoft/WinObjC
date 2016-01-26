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

#import <StubReturn.h>
#import <Foundation/NSFileCoordinator.h>

@implementation NSFileCoordinator
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithFilePresenter:(id<NSFilePresenter>)filePresenterOrNil {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (void)addFilePresenter:(id<NSFilePresenter>)filePresenter {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)removeFilePresenter:(id<NSFilePresenter>)filePresenter {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)filePresenters {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)coordinateAccessWithIntents:(NSArray*)intents queue:(NSOperationQueue*)queue byAccessor:(void (^)(NSError*))accessor {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)coordinateReadingItemAtURL:(NSURL*)url
                           options:(NSFileCoordinatorReadingOptions)options
                             error:(NSError* _Nullable*)outError
                        byAccessor:(void (^)(NSURL*))reader {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)coordinateWritingItemAtURL:(NSURL*)url
                           options:(NSFileCoordinatorWritingOptions)options
                             error:(NSError* _Nullable*)outError
                        byAccessor:(void (^)(NSURL*))writer {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)coordinateReadingItemAtURL:(NSURL*)readingURL
                           options:(NSFileCoordinatorReadingOptions)readingOptions
                  writingItemAtURL:(NSURL*)writingURL
                           options:(NSFileCoordinatorWritingOptions)writingOptions
                             error:(NSError* _Nullable*)outError
                        byAccessor:(void (^)(NSURL*, NSURL*))readerWriter {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)coordinateWritingItemAtURL:(NSURL*)url1
                           options:(NSFileCoordinatorWritingOptions)options1
                  writingItemAtURL:(NSURL*)url2
                           options:(NSFileCoordinatorWritingOptions)options2
                             error:(NSError* _Nullable*)outError
                        byAccessor:(void (^)(NSURL*, NSURL*))writer {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)prepareForReadingItemsAtURLs:(NSArray*)readingURLs
                             options:(NSFileCoordinatorReadingOptions)readingOptions
                  writingItemsAtURLs:(NSArray*)writingURLs
                             options:(NSFileCoordinatorWritingOptions)writingOptions
                               error:(NSError* _Nullable*)outError
                          byAccessor:(void (^)(void (^)(void)))batchAccessor {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)itemAtURL:(NSURL*)oldURL willMoveToURL:(NSURL*)newURL {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)itemAtURL:(NSURL*)oldURL didMoveToURL:(NSURL*)newURL {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancel {
    UNIMPLEMENTED();
}

@end
