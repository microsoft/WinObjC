//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include <Foundation/Foundation.h>

@implementation NSDictionary (NSFileManagerExtensions)

/**
 @Status Interoperable
*/
- (NSDate*)fileCreationDate {
    return [self objectForKey:NSFileCreationDate];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (BOOL)fileExtensionHidden {
    return [[self objectForKey:NSFileExtensionHidden] boolValue];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (NSNumber*)fileGroupOwnerAccountID {
    return [self objectForKey:NSFileGroupOwnerAccountID];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (NSString*)fileGroupOwnerAccountName {
    return [self objectForKey:NSFileGroupOwnerAccountName];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (OSType)fileHFSCreatorCode {
    return [[self objectForKey:NSFileHFSCreatorCode] unsignedIntegerValue];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (OSType)fileHFSTypeCode {
    return [[self objectForKey:NSFileHFSTypeCode] unsignedIntegerValue];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (BOOL)fileIsAppendOnly {
    return [[self objectForKey:NSFileAppendOnly] boolValue];
}

/**
 @Status Interoperable
*/
- (BOOL)fileIsImmutable {
    return [[self objectForKey:NSFileImmutable] boolValue];
}

/**
 @Status Interoperable
*/
- (NSDate*)fileModificationDate {
    return [self objectForKey:NSFileModificationDate];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (NSNumber*)fileOwnerAccountID {
    return [self objectForKey:NSFileOwnerAccountID];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (NSString*)fileOwnerAccountName {
    return [self objectForKey:NSFileOwnerAccountName];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (NSUInteger)filePosixPermissions {
    // AND value with octal 01777 to return valid file permissions only
    return ([[self objectForKey:NSFilePosixPermissions] unsignedIntegerValue] & 01777);
}

/**
 @Status Interoperable
*/
- (unsigned long long int)fileSize {
    return [[self objectForKey:NSFileSize] unsignedLongLongValue];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (NSUInteger)fileSystemFileNumber {
    return [[self objectForKey:NSFileSystemFileNumber] unsignedIntegerValue];
}

/**
 @Status Caveat
 @Notes Value will not be set by NSFileManager methods
*/
- (NSInteger)fileSystemNumber {
    return [[self objectForKey:NSFileSystemNumber] unsignedIntegerValue];
}

/**
 @Status Interoperable
*/
- (NSString*)fileType {
    return [self objectForKey:NSFileType];
}

@end
