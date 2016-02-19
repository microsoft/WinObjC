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
@class NSDictionary;

FOUNDATION_EXPORT NSString* const NSMetadataItemFSNameKey;
FOUNDATION_EXPORT NSString* const NSMetadataItemDisplayNameKey;
FOUNDATION_EXPORT NSString* const NSMetadataItemURLKey;
FOUNDATION_EXPORT NSString* const NSMetadataItemPathKey;
FOUNDATION_EXPORT NSString* const NSMetadataItemFSSizeKey;
FOUNDATION_EXPORT NSString* const NSMetadataItemFSCreationDateKey;
FOUNDATION_EXPORT NSString* const NSMetadataItemFSContentChangeDateKey;
FOUNDATION_EXPORT NSString* const NSMetadataItemIsUbiquitousKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemHasUnresolvedConflictsKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemIsDownloadedKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemIsDownloadingKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemIsUploadedKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemIsUploadingKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemPercentDownloadedKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemPercentUploadedKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingStatusKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingErrorKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemUploadingErrorKey;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingStatusCurrent;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingStatusDownloaded;
FOUNDATION_EXPORT NSString* const NSMetadataUbiquitousItemDownloadingStatusNotDownloaded;

FOUNDATION_EXPORT_CLASS
@interface NSMetadataItem : NSObject
@property (readonly, copy) NSArray* attributes STUB_PROPERTY;
- (id)valueForAttribute:(NSString*)key STUB_METHOD;
- (NSDictionary*)valuesForAttributes:(NSArray*)keys STUB_METHOD;
@end
