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

@class NSURL;
@class NSArray;
@class NSString;
@class NSDate;
@protocol NSCoding;
@class NSError;

typedef NSUInteger NSFileVersionAddingOptions;
typedef NSUInteger NSFileVersionReplacingOptions;
enum { NSFileVersionAddingByMoving = 1 << 0 };
enum { NSFileVersionReplacingByMoving = 1 << 0 };

FOUNDATION_EXPORT_CLASS
@interface NSFileVersion : NSObject
+ (NSFileVersion*)currentVersionOfItemAtURL:(NSURL*)url STUB_METHOD;
+ (NSArray*)otherVersionsOfItemAtURL:(NSURL*)url STUB_METHOD;
+ (NSFileVersion*)versionOfItemAtURL:(NSURL*)url forPersistentIdentifier:(id)persistentIdentifier STUB_METHOD;
@property (readonly, copy) NSURL* URL STUB_PROPERTY;
@property (readonly, copy) NSString* localizedName STUB_PROPERTY;
@property (readonly, copy) NSString* localizedNameOfSavingComputer STUB_PROPERTY;
@property (readonly, copy) NSDate* modificationDate STUB_PROPERTY;
@property (readonly, retain) id<NSCoding> persistentIdentifier STUB_PROPERTY;
@property (readonly, getter=isConflict) BOOL conflict STUB_PROPERTY;
@property (getter=isResolved) BOOL resolved STUB_PROPERTY;
+ (NSArray*)unresolvedConflictVersionsOfItemAtURL:(NSURL*)url STUB_METHOD;
- (NSURL*)replaceItemAtURL:(NSURL*)url options:(NSFileVersionReplacingOptions)options error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)removeAndReturnError:(NSError* _Nullable*)outError STUB_METHOD;
+ (BOOL)removeOtherVersionsOfItemAtURL:(NSURL*)inFileURL error:(NSError* _Nullable*)outError STUB_METHOD;
@end
