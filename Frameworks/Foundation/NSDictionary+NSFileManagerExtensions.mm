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
 @Status Interoperable
*/
- (BOOL)fileExtensionHidden {
    return [[self objectForKey:NSFileExtensionHidden] boolValue];
}

/**
 @Status Interoperable
*/
- (NSNumber*)fileGroupOwnerAccountID {
    return [self objectForKey:NSFileGroupOwnerAccountID];
}

/**
 @Status Interoperable
*/
- (NSString*)fileGroupOwnerAccountName {
    return [self objectForKey:NSFileGroupOwnerAccountName];
}

/**
 @Status Interoperable
*/
- (OSType)fileHFSCreatorCode {
    return [[self objectForKey:NSFileHFSCreatorCode] unsignedIntegerValue];
}

/**
 @Status Interoperable
*/
- (OSType)fileHFSTypeCode {
    return [[self objectForKey:NSFileHFSTypeCode] unsignedIntegerValue];
}

/**
 @Status Interoperable
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
 @Status Interoperable
*/
- (NSNumber*)fileOwnerAccountID {
    return [self objectForKey:NSFileOwnerAccountID];
}

/**
 @Status Interoperable
*/
- (NSString*)fileOwnerAccountName {
    return [self objectForKey:NSFileOwnerAccountName];
}

/**
 @Status Interoperable
*/
- (NSUInteger)filePosixPermissions {
    return [[self objectForKey:NSFilePosixPermissions] unsignedIntegerValue];
}

/**
 @Status Interoperable
*/
- (unsigned long long int)fileSize {
    return [[self objectForKey:NSFileSize] unsignedLongLongValue];
}

/**
 @Status Interoperable
*/
- (NSUInteger)fileSystemFileNumber {
    return [[self objectForKey:NSFileSystemFileNumber] unsignedIntegerValue];
}

/**
 @Status Interoperable
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