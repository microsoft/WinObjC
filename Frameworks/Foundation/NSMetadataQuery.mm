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
#import <Foundation/NSMetadataQuery.h>

FOUNDATION_EXPORT NSString* const NSMetadataQueryUbiquitousDocumentsScope = @"NSMetadataQueryUbiquitousDocumentsScope";
FOUNDATION_EXPORT NSString* const NSMetadataQueryUbiquitousDataScope = @"NSMetadataQueryUbiquitousDataScope";
FOUNDATION_EXPORT NSString* const NSMetadataQueryAccessibleUbiquitousExternalDocumentsScope =
    @"NSMetadataQueryAccessibleUbiquitousExternalDocumentsScope";
FOUNDATION_EXPORT NSString* const NSMetadataQueryResultContentRelevanceAttribute = @"NSMetadataQueryResultContentRelevanceAttribute";
FOUNDATION_EXPORT NSString* const NSMetadataQueryUpdateAddedItemsKey = @"NSMetadataQueryUpdateAddedItemsKey";
FOUNDATION_EXPORT NSString* const NSMetadataQueryUpdateChangedItemsKey = @"NSMetadataQueryUpdateChangedItemsKey";
FOUNDATION_EXPORT NSString* const NSMetadataQueryUpdateRemovedItemsKey = @"NSMetadataQueryUpdateRemovedItemsKey";

@implementation NSMetadataQuery
/**
 @Status Stub
 @Notes
*/
- (BOOL)startQuery {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopQuery {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)resultAtIndex:(NSUInteger)index {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexOfResult:(id)result {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateResultsUsingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateResultsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)valueOfAttribute:(NSString*)attributeName forResultAtIndex:(NSUInteger)index {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enableUpdates {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)disableUpdates {
    UNIMPLEMENTED();
}

@end
