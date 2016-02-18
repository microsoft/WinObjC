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
@class NSError;
@class NSString;
@class NSDictionary;
@class NSData;

typedef NSUInteger NSFileWrapperReadingOptions;
typedef NSUInteger NSFileWrapperWritingOptions;
enum {
    NSFileWrapperReadingImmediate = 1 << 0,
    NSFileWrapperReadingWithoutMapping = 1 << 1,
};

enum {
    NSFileWrapperWritingAtomic = 1 << 0,
    NSFileWrapperWritingWithNameUpdating = 1 << 1,
};

FOUNDATION_EXPORT_CLASS
@interface NSFileWrapper : NSObject <NSCoding>
- (instancetype)initWithURL:(NSURL*)url options:(NSFileWrapperReadingOptions)options error:(NSError* _Nullable*)outError STUB_METHOD;
- (id)initWithPath:(NSString*)node STUB_METHOD;
- (instancetype)initDirectoryWithFileWrappers:(NSDictionary*)childrenByPreferredName STUB_METHOD;
- (instancetype)initRegularFileWithContents:(NSData*)contents STUB_METHOD;
- (id)initSymbolicLinkWithDestination:(NSString*)node STUB_METHOD;
- (instancetype)initSymbolicLinkWithDestinationURL:(NSURL*)url STUB_METHOD;
- (instancetype)initWithSerializedRepresentation:(NSData*)serializedRepresentation STUB_METHOD;
@property (readonly, getter=isRegularFile) BOOL regularFile STUB_PROPERTY;
@property (readonly, getter=isDirectory) BOOL directory STUB_PROPERTY;
@property (readonly, getter=isSymbolicLink) BOOL symbolicLink STUB_PROPERTY;
@property (readonly, copy) NSDictionary* fileWrappers STUB_PROPERTY;
- (NSString*)addFileWrapper:(NSFileWrapper*)child STUB_METHOD;
- (void)removeFileWrapper:(NSFileWrapper*)child STUB_METHOD;
- (NSString*)addFileWithPath:(NSString*)node STUB_METHOD;
- (NSString*)addRegularFileWithContents:(NSData*)data preferredFilename:(NSString*)filename STUB_METHOD;
- (NSString*)addSymbolicLinkWithDestination:(NSString*)node preferredFilename:(NSString*)preferredFilename STUB_METHOD;
- (NSString*)keyForFileWrapper:(NSFileWrapper*)child STUB_METHOD;
- (NSString*)symbolicLinkDestination STUB_METHOD;
@property (readonly, copy) NSURL* symbolicLinkDestinationURL STUB_PROPERTY;
- (BOOL)needsToBeUpdatedFromPath:(NSString*)node STUB_METHOD;
- (BOOL)matchesContentsOfURL:(NSURL*)url STUB_METHOD;
- (BOOL)updateFromPath:(NSString*)path STUB_METHOD;
- (BOOL)readFromURL:(NSURL*)url options:(NSFileWrapperReadingOptions)options error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly, copy) NSData* serializedRepresentation STUB_PROPERTY;
@property (copy) NSString* filename STUB_PROPERTY;
@property (copy) NSString* preferredFilename STUB_PROPERTY;
@property (copy) NSDictionary* fileAttributes STUB_PROPERTY;
@property (readonly, copy) NSData* regularFileContents STUB_PROPERTY;
- (BOOL)writeToFile:(NSString*)node atomically:(BOOL)atomically updateFilenames:(BOOL)updateNames STUB_METHOD;
- (BOOL)writeToURL:(NSURL*)url
                options:(NSFileWrapperWritingOptions)options
    originalContentsURL:(NSURL*)originalContentsURL
                  error:(NSError* _Nullable*)outError STUB_METHOD;
@end
