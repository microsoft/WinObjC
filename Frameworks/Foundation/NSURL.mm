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

#import "Starboard.h"
#import "Foundation/NSMutableString.h"
#import "Foundation/NSMutableArray.h"
#import "Foundation/NSNumber.h"
#import "Foundation/NSURL.h"
#import "NSCFURL.h"
#import <CoreFoundation/CFURL.h>
#import <NSRaise.h>

#import "BridgeHelpers.h"
#import "LoggingNative.h"
#import "NSPathUtilitiesInternal.h"
#import "StubReturn.h"

#import <memory>

// Keys that apply to file system URLs.
NSString* const NSURLAddedToDirectoryDateKey = static_cast<NSString*>(kCFURLAddedToDirectoryDateKey);
NSString* const NSURLAttributeModificationDateKey = static_cast<NSString*>(kCFURLAttributeModificationDateKey);
NSString* const NSURLFileScheme = @"file";
NSString* const NSURLContentAccessDateKey = static_cast<NSString*>(kCFURLContentAccessDateKey);
NSString* const NSURLContentModificationDateKey = static_cast<NSString*>(kCFURLContentModificationDateKey);
NSString* const NSURLCreationDateKey = static_cast<NSString*>(kCFURLCreationDateKey);
NSString* const NSURLCustomIconKey = static_cast<NSString*>(kCFURLCustomIconKey);
NSString* const NSURLDocumentIdentifierKey = static_cast<NSString*>(kCFURLDocumentIdentifierKey);
NSString* const NSURLEffectiveIconKey = static_cast<NSString*>(kCFURLEffectiveIconKey);
NSString* const NSURLFileResourceIdentifierKey = static_cast<NSString*>(kCFURLFileResourceIdentifierKey);
NSString* const NSURLFileResourceTypeKey = static_cast<NSString*>(kCFURLFileResourceIdentifierKey);
NSString* const NSURLFileSecurityKey = static_cast<NSString*>(kCFURLFileSecurityKey);
NSString* const NSURLHasHiddenExtensionKey = static_cast<NSString*>(kCFURLHasHiddenExtensionKey);
NSString* const NSURLIsDirectoryKey = static_cast<NSString*>(kCFURLIsDirectoryKey);
NSString* const NSURLIsExcludedFromBackupKey = static_cast<NSString*>(kCFURLIsExcludedFromBackupKey);
NSString* const NSURLIsExecutableKey = static_cast<NSString*>(kCFURLIsExecutableKey);
NSString* const NSURLIsHiddenKey = static_cast<NSString*>(kCFURLIsHiddenKey);
NSString* const NSURLIsMountTriggerKey = static_cast<NSString*>(kCFURLIsMountTriggerKey);
NSString* const NSURLIsPackageKey = static_cast<NSString*>(kCFURLIsPackageKey);
NSString* const NSURLIsReadableKey = static_cast<NSString*>(kCFURLIsReadableKey);
NSString* const NSURLIsRegularFileKey = static_cast<NSString*>(kCFURLIsRegularFileKey);
NSString* const NSURLIsSymbolicLinkKey = static_cast<NSString*>(kCFURLIsSymbolicLinkKey);
NSString* const NSURLIsSystemImmutableKey = static_cast<NSString*>(kCFURLIsSystemImmutableKey);
NSString* const NSURLIsUserImmutableKey = static_cast<NSString*>(kCFURLIsUserImmutableKey);
NSString* const NSURLIsVolumeKey = static_cast<NSString*>(kCFURLIsVolumeKey);
NSString* const NSURLIsWritableKey = static_cast<NSString*>(kCFURLIsWritableKey);
NSString* const NSURLLabelColorKey = static_cast<NSString*>(kCFURLLabelColorKey);
NSString* const NSURLLabelNumberKey = static_cast<NSString*>(kCFURLLabelNumberKey);
NSString* const NSURLLinkCountKey = static_cast<NSString*>(kCFURLLinkCountKey);
NSString* const NSURLLocalizedLabelKey = static_cast<NSString*>(kCFURLLocalizedLabelKey);
NSString* const NSURLLocalizedNameKey = static_cast<NSString*>(kCFURLLocalizedNameKey);
NSString* const NSURLLocalizedTypeDescriptionKey = static_cast<NSString*>(kCFURLLocalizedTypeDescriptionKey);
NSString* const NSURLNameKey = static_cast<NSString*>(kCFURLNameKey);
NSString* const NSURLParentDirectoryURLKey = static_cast<NSString*>(kCFURLParentDirectoryURLKey);
NSString* const NSURLPathKey = static_cast<NSString*>(kCFURLPathKey);
NSString* const NSURLPreferredIOBlockSizeKey = static_cast<NSString*>(kCFURLPreferredIOBlockSizeKey);
NSString* const NSURLTypeIdentifierKey = static_cast<NSString*>(kCFURLTypeIdentifierKey);
NSString* const NSURLVolumeIdentifierKey = static_cast<NSString*>(kCFURLVolumeIdentifierKey);
NSString* const NSURLVolumeURLKey = static_cast<NSString*>(kCFURLVolumeURLKey);

// Possible values for the NSURLFileResourceTypeKey key.
NSString* const NSURLFileResourceTypeNamedPipe = static_cast<NSString*>(kCFURLFileResourceTypeNamedPipe);
NSString* const NSURLFileResourceTypeCharacterSpecial = static_cast<NSString*>(kCFURLFileResourceTypeCharacterSpecial);
NSString* const NSURLFileResourceTypeDirectory = static_cast<NSString*>(kCFURLFileResourceTypeDirectory);
NSString* const NSURLFileResourceTypeBlockSpecial = static_cast<NSString*>(kCFURLFileResourceTypeBlockSpecial);
NSString* const NSURLFileResourceTypeRegular = static_cast<NSString*>(kCFURLFileResourceTypeRegular);
NSString* const NSURLFileResourceTypeSymbolicLink = static_cast<NSString*>(kCFURLFileResourceTypeSymbolicLink);
NSString* const NSURLFileResourceTypeSocket = static_cast<NSString*>(kCFURLFileResourceTypeSocket);
NSString* const NSURLFileResourceTypeUnknown = static_cast<NSString*>(kCFURLFileResourceTypeUnknown);

// Keys that apply to properties of files.
NSString* const NSURLFileSizeKey = static_cast<NSString*>(kCFURLFileSizeKey);
NSString* const NSURLFileAllocatedSizeKey = static_cast<NSString*>(kCFURLFileAllocatedSizeKey);
NSString* const NSURLIsAliasFileKey = static_cast<NSString*>(kCFURLIsAliasFileKey);
NSString* const NSURLTotalFileAllocatedSizeKey = static_cast<NSString*>(kCFURLTotalFileAllocatedSizeKey);
NSString* const NSURLTotalFileSizeKey = static_cast<NSString*>(kCFURLTotalFileSizeKey);

NSString* const NSThumbnail1024x1024SizeKey = @"NSThumbnail1024x1024SizeKey";
NSString* const NSURLGenerationIdentifierKey = static_cast<NSString*>(kCFURLGenerationIdentifierKey);
NSString* const NSURLVolumeLocalizedFormatDescriptionKey = static_cast<NSString*>(kCFURLVolumeLocalizedFormatDescriptionKey);
NSString* const NSURLVolumeTotalCapacityKey = static_cast<NSString*>(kCFURLVolumeTotalCapacityKey);
NSString* const NSURLVolumeAvailableCapacityKey = static_cast<NSString*>(kCFURLVolumeAvailableCapacityKey);
NSString* const NSURLVolumeResourceCountKey = static_cast<NSString*>(kCFURLVolumeResourceCountKey);
NSString* const NSURLVolumeSupportsPersistentIDsKey = static_cast<NSString*>(kCFURLVolumeSupportsPersistentIDsKey);
NSString* const NSURLVolumeSupportsSymbolicLinksKey = static_cast<NSString*>(kCFURLVolumeSupportsSymbolicLinksKey);
NSString* const NSURLVolumeSupportsHardLinksKey = static_cast<NSString*>(kCFURLVolumeSupportsHardLinksKey);
NSString* const NSURLVolumeSupportsJournalingKey = static_cast<NSString*>(kCFURLVolumeSupportsJournalingKey);
NSString* const NSURLVolumeIsJournalingKey = static_cast<NSString*>(kCFURLVolumeIsJournalingKey);
NSString* const NSURLVolumeSupportsSparseFilesKey = static_cast<NSString*>(kCFURLVolumeSupportsSparseFilesKey);
NSString* const NSURLVolumeSupportsZeroRunsKey = static_cast<NSString*>(kCFURLVolumeSupportsZeroRunsKey);
NSString* const NSURLVolumeSupportsCaseSensitiveNamesKey = static_cast<NSString*>(kCFURLVolumeSupportsCaseSensitiveNamesKey);
NSString* const NSURLVolumeSupportsCasePreservedNamesKey = static_cast<NSString*>(kCFURLVolumeSupportsCasePreservedNamesKey);
NSString* const NSURLVolumeSupportsRootDirectoryDatesKey = static_cast<NSString*>(kCFURLVolumeSupportsRootDirectoryDatesKey);
NSString* const NSURLVolumeSupportsVolumeSizesKey = static_cast<NSString*>(kCFURLVolumeSupportsVolumeSizesKey);
NSString* const NSURLVolumeSupportsRenamingKey = static_cast<NSString*>(kCFURLVolumeSupportsRenamingKey);
NSString* const NSURLVolumeSupportsAdvisoryFileLockingKey = static_cast<NSString*>(kCFURLVolumeSupportsAdvisoryFileLockingKey);
NSString* const NSURLVolumeSupportsExtendedSecurityKey = static_cast<NSString*>(kCFURLVolumeSupportsExtendedSecurityKey);
NSString* const NSURLVolumeIsBrowsableKey = static_cast<NSString*>(kCFURLVolumeIsBrowsableKey);
NSString* const NSURLVolumeMaximumFileSizeKey = static_cast<NSString*>(kCFURLVolumeMaximumFileSizeKey);
NSString* const NSURLVolumeIsEjectableKey = static_cast<NSString*>(kCFURLVolumeIsEjectableKey);
NSString* const NSURLVolumeIsRemovableKey = static_cast<NSString*>(kCFURLVolumeIsRemovableKey);
NSString* const NSURLVolumeIsInternalKey = static_cast<NSString*>(kCFURLVolumeIsInternalKey);
NSString* const NSURLVolumeIsAutomountedKey = static_cast<NSString*>(kCFURLVolumeIsAutomountedKey);
NSString* const NSURLVolumeIsLocalKey = static_cast<NSString*>(kCFURLVolumeIsLocalKey);
NSString* const NSURLVolumeIsReadOnlyKey = static_cast<NSString*>(kCFURLVolumeIsReadOnlyKey);
NSString* const NSURLVolumeCreationDateKey = static_cast<NSString*>(kCFURLVolumeCreationDateKey);
NSString* const NSURLVolumeURLForRemountingKey = static_cast<NSString*>(kCFURLVolumeURLForRemountingKey);
NSString* const NSURLVolumeUUIDStringKey = static_cast<NSString*>(kCFURLVolumeUUIDStringKey);
NSString* const NSURLVolumeNameKey = static_cast<NSString*>(kCFURLVolumeNameKey);
NSString* const NSURLVolumeLocalizedNameKey = static_cast<NSString*>(kCFURLVolumeLocalizedNameKey);
NSString* const NSURLKeysOfUnsetValuesKey = static_cast<NSString*>(kCFURLKeysOfUnsetValuesKey);
NSString* const NSURLIsUbiquitousItemKey = static_cast<NSString*>(kCFURLIsUbiquitousItemKey);
NSString* const NSURLUbiquitousItemDownloadingErrorKey = static_cast<NSString*>(kCFURLUbiquitousItemDownloadingErrorKey);
NSString* const NSURLUbiquitousItemDownloadingStatusKey = static_cast<NSString*>(kCFURLUbiquitousItemDownloadingStatusKey);
NSString* const NSURLUbiquitousItemHasUnresolvedConflictsKey = static_cast<NSString*>(kCFURLUbiquitousItemHasUnresolvedConflictsKey);
NSString* const NSURLUbiquitousItemIsDownloadedKey = static_cast<NSString*>(kCFURLUbiquitousItemIsDownloadedKey);
NSString* const NSURLUbiquitousItemIsDownloadingKey = static_cast<NSString*>(kCFURLUbiquitousItemIsDownloadingKey);
NSString* const NSURLUbiquitousItemIsUploadedKey = static_cast<NSString*>(kCFURLUbiquitousItemIsUploadedKey);
NSString* const NSURLUbiquitousItemIsUploadingKey = static_cast<NSString*>(kCFURLUbiquitousItemIsUploadingKey);
NSString* const NSURLUbiquitousItemUploadingErrorKey = static_cast<NSString*>(kCFURLUbiquitousItemUploadingErrorKey);
NSString* const NSURLUbiquitousItemDownloadRequestedKey = @"NSURLUbiquitousItemDownloadRequestedKey";
NSString* const NSURLUbiquitousItemContainerDisplayNameKey = @"NSURLUbiquitousItemContainerDisplayNameKey";
NSString* const NSURLUbiquitousItemPercentUploadedKey = static_cast<NSString*>(kCFURLUbiquitousItemPercentUploadedKey);
NSString* const NSURLUbiquitousItemDownloadingStatusCurrent = static_cast<NSString*>(kCFURLUbiquitousItemDownloadingStatusCurrent);
NSString* const NSURLUbiquitousItemDownloadingStatusDownloaded = static_cast<NSString*>(kCFURLUbiquitousItemDownloadingStatusDownloaded);
NSString* const NSURLUbiquitousItemDownloadingStatusNotDownloaded =
    static_cast<NSString*>(kCFURLUbiquitousItemDownloadingStatusNotDownloaded);
NSString* const NSURLThumbnailDictionaryKey = @"NSURLThumbnailDictionaryKey";

@implementation NSURL

BASE_CLASS_REQUIRED_IMPLS(NSURL, NSURLPrototype, CFURLGetTypeID);

/**
 @Status Interoperable
*/
- (instancetype)initWithScheme:(NSString*)scheme host:(NSString*)host path:(NSString*)path {
    NSString* slash = _NSGetSlashStr();

    if ([host length] > 0) {
        // scheme://host/path
        return [self initWithString:[NSString stringWithFormat:@"%@:%@%@%@%@%@",
                                                               scheme,
                                                               slash,
                                                               slash,
                                                               [host stringByAddingPercentEscapesUsingEncoding:[host fastestEncoding]],
                                                               slash,
                                                               [path stringByAddingPercentEscapesUsingEncoding:[path fastestEncoding]]]];
    } else {
        // scheme://path
        return [self initWithString:[NSString stringWithFormat:@"%@:%@%@%@",
                                                               scheme,
                                                               slash,
                                                               slash,
                                                               [path stringByAddingPercentEscapesUsingEncoding:[path fastestEncoding]]]];
    }
}

/**
 @Status Interoperable
*/
+ (instancetype)URLWithString:(NSString*)URLString {
    return [[[self alloc] initWithString:URLString] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)URLString {
    return [self initWithString:URLString relativeToURL:nil];
}

/**
 @Status Interoperable
*/
+ (instancetype)URLWithString:(NSString*)URLString relativeToURL:(NSURL*)baseURL {
    return [[[self alloc] initWithString:URLString relativeToURL:baseURL] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)URLString relativeToURL:(NSURL*)baseURL {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
+ (NSURL*)fileURLWithPath:(NSString*)path isDirectory:(BOOL)isDir {
    return [[[self alloc] initFileURLWithPath:path isDirectory:isDir] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initFileURLWithPath:(NSString*)path isDirectory:(BOOL)isDir {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
+ (NSURL*)fileURLWithPath:(NSString*)path {
    return [[[self alloc] initFileURLWithPath:path] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initFileURLWithPath:(NSString*)path {
    if (!path) {
        [NSException raise:NSInvalidArgumentException format:@"initFileURLWithPath: path must not be null"];
    }

    if ([path length] > 0) {
        // This method assumes that path is a directory if it ends with a slash.
        // If path does not end with a slash, the method examines the file system to determine if path is a file or a directory.
        if (_stringLooksLikeOrIsPathToDirectory(path)) {
            // If path exists in the file system and is a directory, the method appends a trailing slash.
            // (If it already has a trailing slash, leave it alone)
            return [self initFileURLWithPath:_ensureLastPathSeparator(path) isDirectory:YES];
        } else {
            // If path does not exist in the file system, the method assumes that it represents a file and does not append a trailing slash.
            return [self initFileURLWithPath:path isDirectory:NO];
        }
    }

    [self release];

    return nil;
}

/**
 @Status Interoperable
*/
+ (NSURL*)fileURLWithPathComponents:(NSArray<NSString*>*)components {
    return [self fileURLWithPath:[components componentsJoinedByString:_NSGetSlashStr()]];
}

/**
 @Status Stub
*/
+ (instancetype)URLByResolvingAliasFileAtURL:(NSURL*)url options:(NSURLBookmarkResolutionOptions)options error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes 7491994: CFURL BookmarkData functions are unimplemented
*/
+ (instancetype)URLByResolvingBookmarkData:(NSData*)bookmarkData
                                   options:(NSURLBookmarkResolutionOptions)options
                             relativeToURL:(NSURL*)relativeURL
                       bookmarkDataIsStale:(BOOL*)isStale
                                     error:(NSError* _Nullable*)error {
    return [[[self alloc] initByResolvingBookmarkData:bookmarkData
                                              options:options
                                        relativeToURL:relativeURL
                                  bookmarkDataIsStale:isStale
                                                error:error] autorelease];
}

/**
 @Status Caveat
 @Notes 7491994: CFURL BookmarkData functions are unimplemented
*/
- (instancetype)initByResolvingBookmarkData:(NSData*)bookmarkData
                                    options:(NSURLBookmarkResolutionOptions)options
                              relativeToURL:(NSURL*)relativeURL
                        bookmarkDataIsStale:(BOOL*)isStale
                                      error:(NSError* _Nullable*)error {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
+ (NSURL*)fileURLWithFileSystemRepresentation:(const char*)path isDirectory:(BOOL)isDir relativeToURL:(NSURL*)baseURL {
    return [[[self alloc] initFileURLWithFileSystemRepresentation:path isDirectory:isDir relativeToURL:baseURL] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initFileURLWithFileSystemRepresentation:(const char*)path isDirectory:(BOOL)isDir relativeToURL:(NSURL*)baseURL {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)getFileSystemRepresentation:(char*)buffer maxLength:(NSUInteger)maxBufferLength {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSUInteger)hash {
    return [[self relativeString] hash] + [[[self baseURL] relativeString] hash];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)anObject {
    if (self == anObject) {
        return YES;
    }

    if (![anObject isKindOfClass:[NSURL class]]) {
        return NO;
    }

    NSURL* otherURL = static_cast<NSURL*>(anObject);
    NSURL* selfBaseURL = [self baseURL];
    NSURL* otherBaseURL = [otherURL baseURL];

    // Check pointer equality first, in case of nil, which always returns false for isEqual:
    BOOL baseEqual = (selfBaseURL == otherBaseURL) || ([selfBaseURL isEqual:otherBaseURL]);
    return baseEqual && [[self relativeString] isEqual:[otherURL relativeString]];
}

/**
 @Status Interoperable
*/
- (BOOL)checkResourceIsReachableAndReturnError:(NSError* _Nullable*)error {
    if (error) {
        *error = nil;
    }

    if (![self isFileURL] && ![self isFileReferenceURL]) {
        // checkResourceIsReachableAndReturnError return NO for any non-FileURL
        // according to reference doc
        if (error) {
            // TODO: 7492080: standardize the error domain and error code
            *error = [NSError errorWithDomain:@"NSURL" code:100 userInfo:nil];
        }
        return NO;
    }

    return [[NSFileManager defaultManager] fileExistsAtPath:[self path]];
}

/**
 @Status Interoperable
*/
- (BOOL)isFileReferenceURL {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)isFileURL {
    return [[[self scheme] lowercaseString] isEqualToString:NSURLFileScheme];
}

/**
 @Status Interoperable
*/
- (NSString*)absoluteString {
    return [[self absoluteURL] relativeString];
}

/**
 @Status Interoperable
*/
- (NSURL*)absoluteURL {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)baseURL {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (const char*)fileSystemRepresentation {
    // A created NSString takes ownership over freeing this
    std::unique_ptr<char[], decltype(&IwFree)> ret(static_cast<char*>(IwMalloc(MAX_PATH)), IwFree);

    RETURN_NULL_IF_NULL_ALLOC(ret);

    if ([self getFileSystemRepresentation:ret.get() maxLength:MAX_PATH]) {
        size_t length = strlen(ret.get());
        NSString* autoreleaseString =
            [[[NSString alloc] initWithBytesNoCopy:ret.release() length:length encoding:NSUTF8StringEncoding freeWhenDone:YES] autorelease];

        return [autoreleaseString cStringUsingEncoding:NSUTF8StringEncoding];
    }

    return nullptr;
}

/**
 @Status Interoperable
*/
- (NSString*)fragment {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)host {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)lastPathComponent {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)parameterString {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)password {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)path {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSArray<NSString*>*)pathComponents {
    // Cannot use [NSString pathComponents] here - [NSURL pathComponents] keeps empty components, while [NSString pathComponents] does not
    NSArray* components = [[self path] componentsSeparatedByString:_NSGetSlashStr()];
    NSMutableArray* ret = [NSMutableArray arrayWithCapacity:[components count]];

    for (NSString* component in components) {
        [ret addObject:[component stringByReplacingPercentEscapesUsingEncoding:[component fastestEncoding]]];
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (NSString*)pathExtension {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSNumber*)port {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)query {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)relativePath {
    return [[NSURL URLWithString:[self relativeString]] path];
}

/**
 @Status Interoperable
*/
- (NSString*)relativeString {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)resourceSpecifier {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)scheme {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)standardizedURL {
    // Cannot use [NSString stringByStandardizingPath] here - NSString has a different notion of path components,
    // and the function is explictly documented to not work with URLs
    NSMutableArray* pathComponents = [[[[self absoluteString] componentsSeparatedByString:_NSGetSlashStr()] mutableCopy] autorelease];

    for (size_t i = 0; i < [pathComponents count];) {
        NSString* pathComponent = static_cast<NSString*>([pathComponents objectAtIndex:i]);
        if ([pathComponent isEqualToString:@"."]) {
            [pathComponents removeObjectAtIndex:i];
        } else if ([pathComponent isEqualToString:@".."]) {
            [pathComponents removeObjectAtIndex:i]; // Remove ".."
            if (i > 0) {
                [pathComponents removeObjectAtIndex:i - 1]; // Remove the dir before ".." - it cancels out with ".."
                --i; // Since two components were removed, the next component is ++i - 2 = --i
            }
            // Since one component was removed, the next component is ++i - 1 = i
        } else {
            ++i;
        }
    }

    return [NSURL URLWithString:[pathComponents componentsJoinedByString:_NSGetSlashStr()]];
}

/**
 @Status Interoperable
*/
- (NSString*)user {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)filePathURL {
    // If the receiver is a file reference URL, this property contains a copy of the URL converted to a file path URL.
    if ([self isFileReferenceURL]) {
        return [[[NSURL alloc] initWithScheme:NSURLFileScheme host:[self host] path:[self path]] autorelease];
    }

    // If the receiver’s URL is a file path URL, this property contains the original URL.
    if ([self isFileURL]) {
        return [[self retain] autorelease];
    }

    // If the original URL is not a file URL, or if the resource is not reachable or no longer exists, this property contains nil.
    return nil;
}

/**
 @Status Interoperable
*/
- (NSURL*)fileReferenceURL {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByAppendingPathComponent:(NSString*)pathComponent {
    // Ensure exactly one slash exists between the original URL and pathComponent
    NSString* originalURL = _ensureLastPathSeparator([self relativeString]);
    if ([pathComponent hasPrefix:_NSGetSlashStr()]) {
        pathComponent = [pathComponent substringFromIndex:[_NSGetSlashStr() length]];
    }

    NSString* newURL = [originalURL stringByAppendingString:pathComponent];

    if (_stringLooksLikeOrIsPathToDirectory(newURL)) {
        // If path exists in the file system and is a directory, the method appends a trailing slash.
        // (If it already has a trailing slash, leave it alone)
        return [self URLByAppendingPathComponent:_ensureLastPathSeparator(pathComponent) isDirectory:YES];
    } else {
        // If path does not exist in the file system, the method assumes that it represents a file and does not append a trailing slash.
        return [self URLByAppendingPathComponent:pathComponent isDirectory:NO];
    }
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByAppendingPathComponent:(NSString*)pathComponent isDirectory:(BOOL)isDirectory {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByAppendingPathExtension:(NSString*)pathExtension {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByDeletingLastPathComponent {
    // This can probably leverage [NSString stringByDeletingLastPathComponent] in the future, but it is currently marked as Stub
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByDeletingPathExtension {
    // This can probably leverage [NSString stringByDeletingPathExtension] in the future, but it is currently marked as Stub
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByResolvingSymlinksInPath {
    // This property only works on URLs with the file: scheme
    if ([[self scheme] isEqualToString:NSURLFileScheme]) {
        NSString* resolvedPath = [[self path] stringByResolvingSymlinksInPath];
        return [NSURL fileURLWithPath:resolvedPath];
    } else {
        return [[self copy] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByStandardizingPath {
    // This property only works on URLs with the file: scheme
    if ([[self scheme] isEqualToString:NSURLFileScheme]) {
        NSString* standardizedPath = [[self path] stringByStandardizingPath];
        return [NSURL fileURLWithPath:standardizedPath];
    } else {
        return [[self copy] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [[NSURL alloc] initWithString:[self relativeString] relativeToURL:[self baseURL]];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if ([coder allowsKeyedCoding]) {
        NSString* path = [coder decodeObjectForKey:@"NS.path"];

        return [self initWithString:path relativeToURL:nil];

    } else {
        UNIMPLEMENTED_WITH_MSG("NSURL initWithCoder: with non-keyed NSCoder currently unsupported");
        [self release];
        return nil;
    }
}

/**
 @Status Caveat
 @ Notes Only supports NSKeyedArchiver coder type.
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    if ([coder isKindOfClass:[NSKeyedArchiver class]]) {
        /* [TODO: Encode baseURL as well] */
        NSString* fullURL = [self absoluteString];
        [coder encodeObject:fullURL forKey:@"NS.path"];
    } else {
        UNIMPLEMENTED_WITH_MSG("NSURL encodeWithCoder: with non-NSKeyedArchiver NSCoder currently unsupported");
    }
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return NO;
}

/**
 @Status Caveat
 @Notes 7491994: CFURL BookmarkData functions are unimplemented
*/
+ (NSData*)bookmarkDataWithContentsOfURL:(NSURL*)bookmarkFileURL error:(NSError* _Nullable*)error {
    return [static_cast<NSData*>(
        CFURLCreateBookmarkDataFromFile(NULL, static_cast<CFURLRef>(bookmarkFileURL), reinterpret_cast<CFErrorRef*>(error))) autorelease];
}

/**
 @Status Caveat
 @Notes 7491994: CFURL BookmarkData functions are unimplemented
*/
- (NSData*)bookmarkDataWithOptions:(NSURLBookmarkCreationOptions)options
    includingResourceValuesForKeys:(NSArray<NSString*>*)keys
                     relativeToURL:(NSURL*)relativeURL
                             error:(NSError* _Nullable*)error {
    return [static_cast<NSData*>(CFURLCreateBookmarkData(NULL,
                                                         static_cast<CFURLRef>(self),
                                                         static_cast<CFURLBookmarkCreationOptions>(options),
                                                         static_cast<CFArrayRef>(keys),
                                                         static_cast<CFURLRef>(relativeURL),
                                                         reinterpret_cast<CFErrorRef*>(error))) autorelease];
}

/**
 @Status Caveat
 @Notes 7491994: CFURL BookmarkData functions are unimplemented
*/
+ (NSDictionary<NSString*, id>*)resourceValuesForKeys:(NSArray<NSString*>*)keys fromBookmarkData:(NSData*)bookmarkData {
    return [static_cast<NSDictionary<NSString*, id>*>(
        CFURLCreateResourcePropertiesForKeysFromBookmarkData(NULL, static_cast<CFArrayRef>(keys), static_cast<CFDataRef>(bookmarkData)))
        autorelease];
}

/**
 @Status Caveat
 @Notes 7491994: CFURL BookmarkData functions are unimplemented
*/
+ (BOOL)writeBookmarkData:(NSData*)bookmarkData
                    toURL:(NSURL*)bookmarkFileURL
                  options:(NSURLBookmarkFileCreationOptions)options
                    error:(NSError* _Nullable*)error {
    return CFURLWriteBookmarkDataToFile(static_cast<CFDataRef>(bookmarkData),
                                        static_cast<CFURLRef>(bookmarkFileURL),
                                        static_cast<CFURLBookmarkCreationOptions>(options),
                                        reinterpret_cast<CFErrorRef*>(error));
}

/**
 @Status Caveat
 @Notes 7491994: CFURL SecurityScopedResource functions are unimplemented
*/
- (BOOL)startAccessingSecurityScopedResource {
    return CFURLStartAccessingSecurityScopedResource(static_cast<CFURLRef>(self));
}

/**
 @Status Caveat
 @Notes 7491994: CFURL SecurityScopedResource functions are unimplemented
*/
- (void)stopAccessingSecurityScopedResource {
    CFURLStopAccessingSecurityScopedResource(static_cast<CFURLRef>(self));
}

/**
 @Status Caveat
 @Notes 7491994: CFURL ResourceValue functions are unimplemented
*/
- (BOOL)getResourceValue:(out id _Nullable*)value forKey:(NSString*)key error:(out NSError* _Nullable*)error {
    return CFURLCopyResourcePropertyForKey(static_cast<CFURLRef>(self),
                                           static_cast<CFStringRef>(key),
                                           static_cast<void*>(value),
                                           reinterpret_cast<CFErrorRef*>(error));
}

/**
 @Status Caveat
 @Notes 7491994: CFURL ResourceValue functions are unimplemented
*/
- (NSDictionary<NSString*, id>*)resourceValuesForKeys:(NSArray<NSString*>*)keys error:(NSError* _Nullable*)error {
    return
        [static_cast<NSDictionary<NSString*, id>*>(CFURLCopyResourcePropertiesForKeys(static_cast<CFURLRef>(self),
                                                                                      static_cast<CFArrayRef>(keys),
                                                                                      reinterpret_cast<CFErrorRef*>(error))) autorelease];
}

/**
 @Status Caveat
 @Notes 7491994: CFURL ResourceValue functions are unimplemented
*/
- (BOOL)setResourceValue:(id)value forKey:(NSString*)key error:(NSError* _Nullable*)error {
    return CFURLSetResourcePropertyForKey(static_cast<CFURLRef>(self),
                                          static_cast<CFStringRef>(key),
                                          static_cast<CFTypeRef>(value),
                                          reinterpret_cast<CFErrorRef*>(error));
}

/**
 @Status Caveat
 @Notes 7491994: CFURL ResourceValue functions are unimplemented
*/
- (BOOL)setResourceValues:(NSDictionary<NSString*, id>*)keyedValues error:(NSError* _Nullable*)error {
    return CFURLSetResourcePropertiesForKeys(static_cast<CFURLRef>(self),
                                             static_cast<CFDictionaryRef>(keyedValues),
                                             reinterpret_cast<CFErrorRef*>(error));
}

/**
 @Status Caveat
 @Notes 7491994: CFURL ResourceValue functions are unimplemented
*/
- (void)removeAllCachedResourceValues {
    CFURLClearResourcePropertyCache(static_cast<CFURLRef>(self));
}

/**
 @Status Caveat
 @Notes 7491994: CFURL ResourceValue functions are unimplemented
*/
- (void)removeCachedResourceValueForKey:(NSString*)key {
    CFURLClearResourcePropertyCacheForKey(static_cast<CFURLRef>(self), static_cast<CFStringRef>(key));
}

/**
 @Status Caveat
 @Notes 7491994: CFURL ResourceValue functions are unimplemented
*/
- (void)setTemporaryResourceValue:(id)value forKey:(NSString*)key {
    CFURLSetTemporaryResourcePropertyForKey(static_cast<CFURLRef>(self), static_cast<CFStringRef>(key), static_cast<CFTypeRef>(value));
}

/**
 @Status Stub
*/
- (BOOL)checkPromisedItemIsReachableAndReturnError:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)getPromisedItemResourceValue:(id _Nullable*)value forKey:(NSString*)key error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSDictionary<NSString*, id>*)promisedItemResourceValuesForKeys:(NSArray<NSString*>*)keys error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

@end