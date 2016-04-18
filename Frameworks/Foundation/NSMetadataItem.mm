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
#import <Foundation/NSMetadataItem.h>

FOUNDATION_EXPORT NSString* const NSMetadataItemFSNameKey = @"NSMetadataItemFSNameKey";
FOUNDATION_EXPORT NSString* const NSMetadataItemDisplayNameKey = @"NSMetadataItemDisplayNameKey";
FOUNDATION_EXPORT NSString* const NSMetadataItemURLKey = @"NSMetadataItemURLKey";
FOUNDATION_EXPORT NSString* const NSMetadataItemPathKey = @"NSMetadataItemPathKey";
FOUNDATION_EXPORT NSString* const NSMetadataItemFSSizeKey = @"NSMetadataItemFSSizeKey";
FOUNDATION_EXPORT NSString* const NSMetadataItemFSCreationDateKey = @"NSMetadataItemFSCreationDateKey";
FOUNDATION_EXPORT NSString* const NSMetadataItemFSContentChangeDateKey = @"NSMetadataItemFSContentChangeDateKey";
FOUNDATION_EXPORT NSString* const NSMetadataItemIsUbiquitousKey = @"NSMetadataItemIsUbiquitousKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemHasUnresolvedConflictsKey = @"NSMetadataUbiquitousItemHasUnresolvedConflictsKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemIsDownloadedKey = @"NSMetadataUbiquitousItemIsDownloadedKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemIsDownloadingKey = @"NSMetadataUbiquitousItemIsDownloadingKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemIsUploadedKey = @"NSMetadataUbiquitousItemIsUploadedKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemIsUploadingKey = @"NSMetadataUbiquitousItemIsUploadingKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemPercentDownloadedKey = @"NSMetadataUbiquitousItemPercentDownloadedKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemPercentUploadedKey = @"NSMetadataUbiquitousItemPercentUploadedKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingStatusKey = @"NSMetadataUbiquitousItemDownloadingStatusKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingErrorKey = @"NSMetadataUbiquitousItemDownloadingErrorKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemUploadingErrorKey = @"NSMetadataUbiquitousItemUploadingErrorKey";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingStatusCurrent = @"NSMetadataUbiquitousItemDownloadingStatusCurrent";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingStatusDownloaded =
    @"NSMetadataUbiquitousItemDownloadingStatusDownloaded";
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingStatusNotDownloaded =
    @"NSMetadataUbiquitousItemDownloadingStatusNotDownloaded";

@implementation NSMetadataItem
/**
 @Status Stub
 @Notes
*/
- (id)valueForAttribute:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDictionary*)valuesForAttributes:(NSArray*)keys {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
