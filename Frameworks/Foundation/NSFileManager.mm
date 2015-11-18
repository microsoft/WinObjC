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

#include "Starboard.h"
#include "Foundation/NSFileManager.h"
#include "Foundation/NSError.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSDate.h"
#include "Foundation/NSData.h"
#include "Foundation/NSURL.h"
#include "Foundation/NSDirectoryEnumerator.h"
#import <Foundation/NSDictionary.h>

#include <string>
#include <vector>

#include <sys/stat.h>
#include <errno.h>

#ifdef __linux__
#define _S_IFDIR S_IFDIR
#endif

// file attribute keys
NSString* const NSFileType = @"NSFileType";
NSString* const NSFileSize = @"NSFileSize";
NSString* const NSFileModificationDate = @"NSFileModificationDate";
NSString* const NSFileReferenceCount = @"NSFileReferenceCount";
NSString* const NSFileDeviceIdentifier = @"NSFileDeviceIdentifier";
NSString* const NSFileOwnerAccountName = @"NSFileOwnerAccountName";
NSString* const NSFileGroupOwnerAccountName = @"NSFileGroupOwnerAccountName";
NSString* const NSFilePosixPermissions = @"NSFilePosixPermissions";
NSString* const NSFileSystemNumber = @"NSFileSystemNumber";
NSString* const NSFileSystemFileNumber = @"NSFileSystemFileNumber";
NSString* const NSFileExtensionHidden = @"NSFileExtensionHidden";
NSString* const NSFileHFSCreatorCode = @"NSFileHFSCreatorCode";
NSString* const NSFileHFSTypeCode = @"NSFileHFSTypeCode";
NSString* const NSFileImmutable = @"NSFileImmutable";
NSString* const NSFileAppendOnly = @"NSFileAppendOnly";
NSString* const NSFileCreationDate = @"NSFileCreationDate";
NSString* const NSFileOwnerAccountID = @"NSFileOwnerAccountID";
NSString* const NSFileGroupOwnerAccountID = @"NSFileGroupOwnerAccountID";
NSString* const NSFileBusy = @"NSFileBusy";

NSString* const NSFileProtectionKey = @"NSFileProtectionKey";

// NSFileType Attribute Values
NSString* const NSFileTypeDirectory = @"NSFileTypeDirectory";
NSString* const NSFileTypeRegular = @"NSFileTypeRegular";
NSString* const NSFileTypeSymbolicLink = @"NSFileTypeSymbolicLink";
NSString* const NSFileTypeSocket = @"NSFileTypeSocket";
NSString* const NSFileTypeCharacterSpecial = @"NSFileTypeCharacterSpecial";
NSString* const NSFileTypeBlockSpecial = @"NSFileTypeBlockSpecial";
NSString* const NSFileTypeUnknown = @"NSFileTypeUnknown";

// File-System attribute Keys
NSString* const NSFileSystemSize = @"NSFileSystemSize";
NSString* const NSFileSystemFreeSize = @"NSFileSystemFreeSize";
NSString* const NSFileSystemNodes = @"NSFileSystemNodes";
NSString* const NSFileSystemFreeNodes = @"NSFileSystemFreeNodes";

// File Protection Values
NSString* const NSFileProtectionNone = @"NSFileProtectionNone";
NSString* const NSFileProtectionComplete = @"NSFileProtectionComplete";
NSString* const NSFileProtectionCompleteUnlessOpen = @"NSFileProtectionCompleteUnlessOpen";
NSString* const NSFileProtectionCompleteUntilFirstUserAuthentication = @"NSFileProtectionCompleteUntilFirstUserAuthentication";

/// NSDirectoryEnumerator implementation
@implementation NSDirectoryEnumerator {
    idretaint<NSMutableDictionary> _rootFiles;
    idretaint<NSString> _currentFile;
    std::vector<idretaint<NSDirectoryEnumerator>> _currrentEnumerator;
    int _currentDepth;
    BOOL _skipDescendents;
    idretaint<NSString> _searchPath;
}

- (instancetype)init {
    return self;
}

/*
* This function search files/directories in a directory path. It starts with rootpath and subpath.
* (e.g., rootpath is "." and subPath is "saved"). the search will start at "./saved" seach path.  which is "saved" sub-directory of
* current working directory. together, rootpath + subpath is called searchPath.
*
* Search behaviour:  if shallow is YES, the search only happens at the top level of the search path. if shallow is NO,  the search
* will happen recusively on search path and any of its subdirectories as well.

* Search Result: If returnNSURL is YES, the result objArray will contains NSURL object, if returnNSURL is NO, however,
* the result objectArray contains NSString object. either of which represent a file or direcotry found during the search
* If specifying returnNSURL as YES, NSDirectoryEnumerationOptions is used to exclude specified results. e.g.,
NSDirectoryEnumerationSkipsHiddenFiles
* will exclude hidden files from the result. Also, If specifying returnNSURL as YES, A NSArray of keys (property bag) can be passed in, so
that
* specified properties for the file or drectiroy can be prefeched and included in returned NSURL object.
*/
static void searchRecursive(const char* rootpath,
                            const char* subpath,
                            BOOL shallow,
                            id objArray,
                            NSArray* keys,
                            NSDirectoryEnumerationOptions mask,
                            BOOL returnNSURL) {
    std::string _searchPath = rootpath;
    if (_searchPath[_searchPath.length() - 1] != '/') {
        _searchPath.append("/");
    }

    _searchPath.append(subpath);
    if (_searchPath[_searchPath.length() - 1] != '/') {
        _searchPath.push_back('/');
    }

    EbrDir* ebrDir = EbrOpenDir(_searchPath.c_str());
    if (ebrDir != NULL) {
        EbrDirEnt dirEnt;
        while (EbrReadDir(ebrDir, &dirEnt)) {
            if (strcmp(dirEnt.fileName, ".") == 0 || strcmp(dirEnt.fileName, "..") == 0) {
                continue;
            }

            std::string filename = subpath;
            if (filename.length() > 0 && filename[filename.length() - 1] != '/') {
                filename.push_back('/');
            }

            filename.append(dirEnt.fileName);
            if (returnNSURL) {
                // TODO: ignore all mask for now, not needed for 1511
                std::string fileFullPath = _searchPath;
                fileFullPath.append(filename);

                if (keys != nil) { // caller wants to fetch some properties for this URL
                    NSDictionary* fileAttributes = fileAttributesForFilePath(fileFullPath.c_str());
                    if (fileAttributes != nil) {
                        NSURL* newURL = [NSURL fileURLWithPath:[NSString stringWithCString:fileFullPath.c_str()]];
                        for (NSString* key in keys) {
                            if ([key isEqualToString:NSURLContentModificationDateKey]) {
                                BOOL ret = [newURL setProperty:[fileAttributes objectForKey:NSFileModificationDate]
                                                        forKey:NSURLContentModificationDateKey];

                                assert(ret);
                            } else {
                                // TODO: add aditional properties, not needed in 1511.
                            }
                        }

                        [objArray addObject:newURL];
                    }
                }

            } else {
                NSString* newStr = [NSString stringWithCString:filename.c_str()];
                [objArray addObject:newStr];
            }

            if (!shallow) {
                if (dirEnt.isDir) {
                    searchRecursive(rootpath, filename.c_str(), shallow, objArray, keys, mask, returnNSURL);
                }
            }
        }

        EbrCloseDir(ebrDir);
    }
    return;
}

- (instancetype)initWithPath:(const char*)path
                     shallow:(BOOL)shallow
  includingPropertiesForKeys:(NSArray*)keys
                     options:(NSDirectoryEnumerationOptions)mask
                 returnNSURL:(BOOL)returnNSURL {
    _rootFiles.attach([NSMutableArray new]);
    _searchPath = [NSString stringWithCString:path];
    searchRecursive(path, "", shallow, _rootFiles, keys, mask, returnNSURL);
    _currrentEnumerator.push_back([_rootFiles objectEnumerator]);
    _currentDepth = 0;
    return self;
}

static void addAllFiles(NSDirectoryEnumerator* enumerator, NSMutableArray* allFiles) {
    id curObj = [enumerator nextObject];

    while (curObj != nil) {
        if ([curObj isKindOfClass:[NSString class]] || [curObj isKindOfClass:[NSURL class]]) {
            [allFiles addObject:curObj];
        } else {
            id subEnum = [curObj objectEnumerator];

            addAllFiles(subEnum, allFiles);
        }

        curObj = [enumerator nextObject];
    }
}

- (NSMutableArray*)allObjects {
    id ret = [NSMutableArray array];
    id curEnum = [_rootFiles objectEnumerator];

    addAllFiles(curEnum, ret);

    return ret;
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(NSUInteger)maxCount {
    if (state->state == 0) {
        state->mutationsPtr = (unsigned long*)&state->extra[1];
        state->extra[0] = *(unsigned long*)&self;
        state->state = 1;
    }
    assert(maxCount > 0);

    unsigned numRet = 0;
    state->itemsPtr = stackBuf;
    maxCount = 1;

    while (maxCount > 0) {
        id next = [(id)state->extra[0] nextObject];
        if (next == nil) {
            break;
        }

        *stackBuf = next;
        stackBuf++;
        numRet++;
        maxCount--;
    }

    return numRet;
}

- (void)dealloc {
    _rootFiles = nil;
    _currentFile = nil;
    _searchPath = nil;

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)skipDescendents {
    _skipDescendents = true;
}

/**
 @Status Interoperable
*/
- (void)skipDescendants {
    _skipDescendents = true;
}

- (id) /* use typed version */ nextObject {
    id curObj, ret = nil;

    while (_currentDepth >= 0) {
        curObj = [_currrentEnumerator[_currentDepth] nextObject];
        if (curObj == nil) {
            _currrentEnumerator[_currentDepth] = nil;
            _currrentEnumerator.pop_back();
            _currentDepth--;
            _skipDescendents = false;
            continue;
        }

        if ([curObj isKindOfClass:[NSString class]] || [curObj isKindOfClass:[NSURL class]]) {
            ret = curObj;
            break;
        } else {
            if (!_skipDescendents) {
                _currentDepth++;
                _currrentEnumerator.push_back([curObj objectEnumerator]);
            }
        }
    }

    _currentFile = ret;

    return ret;
}

static NSDictionary* fileAttributesForFilePath(const char* path) {
    struct stat st;

    // check if file exist or not
    if (EbrStat(path, &st) == -1) {
        return nil;
    }

    NSDictionary* ret = [NSMutableDictionary dictionary];
    [ret setValue:[NSNumber numberWithInt:st.st_size] forKey:NSFileSize];
    [ret setValue:NSFileTypeRegular forKey:NSFileType];
    [ret setValue:[NSDate dateWithTimeIntervalSince1970:st.st_ctime] forKey:NSFileCreationDate];
    [ret setValue:[NSDate dateWithTimeIntervalSince1970:st.st_mtime] forKey:NSFileModificationDate];

    return ret;
}

/**
 @Status Caveat
 @Notes Only NSFileSize and NSFileCreationDate attributes are supported
*/
- (NSDictionary*)fileAttributes {
    const char* rootPath = [_searchPath UTF8String];
    const char* path = [_currentFile UTF8String];

    char fullPath[4096];

    strcpy_s(fullPath, _countof(fullPath), rootPath);
    if (fullPath[strlen(fullPath) - 1] != '/') {
        strcpy_s(fullPath, _countof(fullPath), "/");
    }
    strcpy_s(fullPath, _countof(fullPath), path);

    EbrDebugLog("fileAttributesAtPath: %s\n", fullPath);

    return fileAttributesForFilePath(fullPath);
}

@end

/// NSFileManager implementation
@implementation NSFileManager {
    // instance variable to keep current directory path.
    idretaint<NSString> _currentDirectoryPath;
}

// Creating a File Manager

/**
 @Status Interoperable
*/
+ (NSFileManager*)defaultManager {
    static id defaultManager = [[self alloc] init];

    return defaultManager;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    // on init, current Directory path is specified as "/" for current working directory
    _currentDirectoryPath = [NSString stringWithCString:"/"];
    return self;
}

// Locating System Directories

/**
 @Status Stub
*/
- (NSURL*)URLForDirectory:(NSSearchPathDirectory)directory
                 inDomain:(NSSearchPathDomainMask)domains
        appropriateForURL:(NSURL*)forURL
                   create:(BOOL)create
                    error:(NSError**)error {
    UNIMPLEMENTED();
    assert(forURL == nil);
    id paths = NSSearchPathForDirectoriesInDomains(directory, domains, TRUE);

    int count = [paths count];

    for (int i = 0; i < count; i++) {
        id curObj = [paths objectAtIndex:i];

        id newUrl = [NSURL fileURLWithPath:curObj];

        return newUrl;
    }

    assert(0);

    return nil;
}

/**
 @Status Interoperable
*/
- (NSArray*)URLsForDirectory:(NSSearchPathDirectory)directory inDomains:(NSSearchPathDomainMask)domains {
    id paths = NSSearchPathForDirectoriesInDomains(directory, domains, TRUE);

    int count = [paths count];

    id ret = [NSMutableArray array];

    for (int i = 0; i < count; i++) {
        id curObj = [paths objectAtIndex:i];

        id newUrl = [NSURL fileURLWithPath:curObj];

        [ret addObject:newUrl];
    }

    return ret;
}

// Locating Application Group Container Directories

/**
 @Status Stub
*/
- (NSURL*)containerURLForSecurityApplicationGroupIdentifier:(NSString*)groupIdentifier {
    UNIMPLEMENTED();
    return nil;
}

// Discovering Directory Contents

/**
 @Status Caveat
 @Notes Fetching directory contents, return an array of NSURL objects. Currently ignoring passed in mask
   and only support prefecch NSURLContentModificationDateKey
*/
- (NSArray*)contentsOfDirectoryAtURL:(NSURL*)url
          includingPropertiesForKeys:(NSArray*)keys
                             options:(NSDirectoryEnumerationOptions)mask
                               error:(NSError**)error {
    if (error) {
        *error = nil;
    }

    // check existence of target dir
    auto isDir = NO;
    if (![self fileExistsAtPath:url.absoluteString isDirectory:&isDir]) {
        if (error) {
            // TODO: standardize the error code and message
            *error = [NSError errorWithDomain:@"Target path does not exist" code:100 userInfo:nil];
        }
        return nil;
    } else if (!isDir) {
        // TODO: standardize the error code and message
        if (error) {
            *error = [NSError errorWithDomain:@"Target Path is not a directory" code:100 userInfo:nil];
        }
        return nil;
    }

    id enumerator = [[NSDirectoryEnumerator alloc] initWithPath:[[url path] UTF8String]
                                                        shallow:YES
                                     includingPropertiesForKeys:keys
                                                        options:mask
                                                    returnNSURL:YES];

    // by enumerating the directory, construct the direcotry contents at this URL
    id ret = [enumerator allObjects];
    [enumerator release];
    return ret;
}

/**
 @Status Caveat
 @Notes Path must exist
*/
- (NSArray*)contentsOfDirectoryAtPath:(NSString*)pathAddr error:(NSError**)error {
    id enumerator = [NSDirectoryEnumerator new];
    enumerator = [enumerator initWithPath:[pathAddr UTF8String]
                                  shallow:YES
               includingPropertiesForKeys:nil
                                  options:NSDirectoryEnumerationSkipsSubdirectoryDescendants
                              returnNSURL:NO];

    id ret = [enumerator allObjects];
    [enumerator release];
    return ret;
}

/**
 @Status Stub
*/
- (NSDirectoryEnumerator*)enumeratorAtURL:(NSURL*)url
               includingPropertiesForKeys:(NSArray*)keys
                                  options:(NSDirectoryEnumerationOptions)mask
                             errorHandler:(BOOL (^)(NSURL* url, NSError* error))handler {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (id)enumeratorAtPath:(id)pathAddr {
    const char* path = [pathAddr UTF8String];

    NSDirectoryEnumerator* directoryEnum = [NSDirectoryEnumerator new];
    [directoryEnum initWithPath:path
                           shallow:FALSE
        includingPropertiesForKeys:nil
                           options:NSDirectoryEnumerationSkipsSubdirectoryDescendants
                       returnNSURL:NO];

    return directoryEnum;
}

/**
 @Status Stub
*/
- (NSArray**)mountedVolumeURLsIncludingResourceValuesForKeys:(NSArray**)propertyKeys options:(NSVolumeEnumerationOptions)options {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (NSArray*)subpathsOfDirectoryAtPath:(NSString*)path error:(NSError**)error {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (NSArray*)subpathsAtPath:(NSString*)path {
    UNIMPLEMENTED();
    return nil;
}

// Creating and Deleting Items

/**
 @Status Caveat
 @Notes attributes parameter not supported. error parameter not supported.
*/
- (BOOL)createDirectoryAtURL:(NSURL*)url
 withIntermediateDirectories:(BOOL)createIntermediates
                  attributes:(NSDictionary*)attrs
                       error:(NSError**)err {
    id path = [url path];

    return [self createDirectoryAtPath:path withIntermediateDirectories:createIntermediates attributes:attrs error:err];
}

/**
 @Status Caveat
 @Notes attributes parameter not supported.  error parameter is not populated
*/
- (BOOL)createDirectoryAtPath:(NSString*)pathAddr
  withIntermediateDirectories:(BOOL)createIntermediates
                   attributes:(NSDictionary*)attrs
                        error:(NSError**)err {
    if (createIntermediates) {
        const char* path = [pathAddr UTF8String];
        id components = [pathAddr pathComponents];
        char curPath[256] = "";

        int count = [components count];
        for (int i = 0; i < count; i++) {
            id curComponent = [components objectAtIndex:i];
            const char* pComponent = [curComponent UTF8String];

            if (strlen(pComponent) > 0) {
                strcat_s(curPath, _countof(curPath), pComponent);
                strcat_s(curPath, _countof(curPath), "/");
            }

            if (strlen(curPath) > 0) {
                bool success = EbrMkdir(curPath);
                if (!success && errno != EEXIST) {
                    EbrDebugLog("Failed to make path %s: %d\n", curPath, errno);
                    // return FALSE;
                }
            }
        }

        return TRUE;
    } else {
        const char* path = [pathAddr UTF8String];
        if (EbrMkdir(path) == 0) {
            return TRUE;
        } else {
            return FALSE;
        }
    }
}

/**
 @Status Caveat
 @Notes attributes parameter not supported
*/
- (BOOL)createFileAtPath:(id)pathAddr contents:(id)contents attributes:(id)attributes {
    const char* path = [pathAddr UTF8String];

    EbrDebugLog("createFileAtPath: %s\n", path);

    EbrFile* fpOut = EbrFopen(path, "wb");

    if (!fpOut) {
        EbrDebugLog("failed to createFileAtPath: %s\n", path);
        return FALSE;
    }

    char* bytes = (char*)[contents bytes];
    int length = [contents length];

    EbrFwrite(bytes, 1, length, fpOut);

    EbrFclose(fpOut);

    return TRUE;
}

/**
 @Status Interoperable
*/
- (BOOL)removeItemAtURL:(NSURL*)URL error:(NSError**)error {
    id pathAddr = [URL path];
    if (pathAddr == nil) {
        EbrDebugLog("removeItemAtURL: nil!\n");
        return YES;
    }

    return [self removeItemAtPath:pathAddr error:error];
}

/**
 @Status Stub
*/
- (BOOL)replaceItemAtURL:(NSURL*)originalItemURL
           withItemAtURL:(NSURL*)newItemURL
          backupItemName:(NSString*)backupItemName
                 options:(NSFileManagerItemReplacementOptions)options
        resultingItemURL:(NSURL**)resultingURL
                   error:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)trashItemAtURL:(NSURL*)url resultingItemURL:(NSURL**)outResultingURL error:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

// Moving and Copying Items

/**
 @Status Stub
*/
- (BOOL)copyItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError**)error {
    UNIMPLEMENTED();

    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)copyItemAtPath:(id)srcPath toPath:(id)destPath error:(NSError**)error {
    if (srcPath == nil || destPath == nil) {
        EbrDebugLog("copyItemAtPath: nil!\n");
        return FALSE;
    }

    const char* src = [srcPath UTF8String];
    const char* dest = [destPath UTF8String];

    if (EbrAccess(dest, 0) == 0) {
        if (error) {
            // TODO: standardize the error code and message
            *error = [NSError errorWithDomain:@"Would overwrite destination" code:100 userInfo:nil];
        }
        EbrDebugLog("Not copying %s to %s because dest exists\n", src, dest);
        return FALSE;
    }

    EbrDebugLog("Copying %s to %s\n", src, dest);

    EbrFile* fpIn = EbrFopen(src, "rb");
    if (!fpIn) {
        EbrDebugLog("Error opening %s\n", src);
        return FALSE;
    }

    EbrFile* fpOut = EbrFopen(dest, "wb");
    if (!fpOut) {
        EbrFclose(fpIn);
        EbrDebugLog("Error opening %s\n", dest);
        return FALSE;
    }

    while (!EbrFeof(fpIn)) {
        BYTE in[4096];
        int read = EbrFread(in, 1, 4096, fpIn);
        EbrFwrite(in, 1, read, fpOut);
    }

    EbrFclose(fpOut);
    EbrFclose(fpIn);

    EbrDebugLog("Done copying\n");

    return TRUE;
}

/**
 @Status Stub
*/
- (BOOL)moveItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError**)error {
    UNIMPLEMENTED();

    return NO;
}

/**
 @Status Caveat
 @Notes error parameter is not populated
*/
- (BOOL)moveItemAtPath:(id)srcPath toPath:(id)destPath error:(NSError**)error {
    const char* src = [srcPath UTF8String];
    const char* dest = [destPath UTF8String];

    EbrDebugLog("Moving %s to %s\n", src, dest);

    bool success = EbrRename(src, dest);
    if (!success) {
        EbrDebugLog("Rename failed.\n");
        return FALSE;
        // assert(0);
    }

    return TRUE;
}

// Managing iCloud-Based Items

/**
 @Status Stub
*/
- (NSURL*)URLForUbiquityContainerIdentifier:(NSString*)containerID {
    UNIMPLEMENTED();

    return nil;
}

/**
 @Status Stub
*/
- (BOOL)isUbiquitousItemAtURL:(NSURL*)url {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)setUbiquitous:(BOOL)flag itemAtURL:(NSURL*)url destinationURL:(NSURL*)destinationURL error:(NSError**)errorOut {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)startDownloadingUbiquitousItemAtURL:(NSURL*)url error:(NSError**)errorOut {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)evictUbiquitousItemAtURL:(NSURL*)url error:(NSError**)errorOut {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (NSURL*)URLForPublishingUbiquitousItemAtURL:(NSURL*)url expirationDate:(NSDate**)outDate error:(NSError**)error {
    UNIMPLEMENTED();
    return nil;
}

// Creating Symbolic and Hard Links
/**
 @Status Stub
*/
- (BOOL)createSymbolicLinkAtURL:(NSURL*)url withDestinationURL:(NSURL*)destURL error:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)createSymbolicLinkAtPath:(NSString*)path withDestinationPath:(NSString*)toPath error:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)linkItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)linkItemAtPath:(NSString*)fromPath toPath:(NSString*)toPath error:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (id)destinationOfSymbolicLinkAtPath:(id)path error:(NSError**)error {
    UNIMPLEMENTED();
    const char* pPath = [path UTF8String];
    EbrDebugLog("destinationOfSymbolicLinkAtPath: %s\n", pPath);

    return [path retain];
}

// Determining Access to Files

/**
 @Status Interoperable
*/
- (BOOL)fileExistsAtPath:(NSString*)pathAddr {
    if (pathAddr == nil) {
        return FALSE;
    }

    const char* path = [pathAddr UTF8String];

    if (strcmp(path, "") == 0) {
        return FALSE;
    }

    if (EbrAccess(path, 0) == 0) {
        return TRUE;
    } else {
        EbrDebugLog("File @ %s doesn't exist\n", path);
        return FALSE;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)fileExistsAtPath:(NSString*)pathAddr isDirectory:(BOOL*)isDirectory {
    const char* path = [pathAddr UTF8String];
    struct stat st;

    if (EbrStat(path, &st) == 0) {
        if (isDirectory) {
            *isDirectory = (st.st_mode & _S_IFDIR) == _S_IFDIR;
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isReadableFileAtPath:(id)pathAddr {
    const char* path = [pathAddr UTF8String];

    if (EbrAccess(path, 6) == 0) {
        return TRUE;
    } else {
        EbrDebugLog("File @ %s isn't writable\n", path);
        return FALSE;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isWritableFileAtPath:(id)pathAddr {
    const char* path = [pathAddr UTF8String];

    if (EbrAccess(path, 4) == 0) {
        return TRUE;
    } else {
        EbrDebugLog("File @ %s isn't readable\n", path);
        return FALSE;
    }
}

/**
 @Status Stub
*/
- (BOOL)isExecutableFileAtPath:(NSString*)path {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)isDeletableFileAtPath:(NSString*)path {
    UNIMPLEMENTED();
    return NO;
}

// Getting and Setting Attributes

/**
 @Status Stub
*/
- (NSArray*)componentsToDisplayForPath:(NSString*)path {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (id)displayNameAtPath:(id)path {
    UNIMPLEMENTED();
    return path;
}

/**
 @Status Caveat
 @Notes Only NSFileSize and NSFileType attributes are supported
*/
- (id)attributesOfItemAtPath:(id)pathAddr error:(NSError**)error {
    if (pathAddr == nil) {
        EbrDebugLog("attributesOfItemAtPath nil!");

        if (error) {
            // TODO: standardize the error code and message
            *error = [NSError errorWithDomain:@"Empty File Path" code:100 userInfo:nil];
        }

        return nil;
    }

    struct stat st;

    const char* path = [pathAddr UTF8String];
    EbrDebugLog("attributesOfItemAtPath: %s\n", path);

    if (EbrStat(path, &st) == -1) {
        if (error) {
            // TODO: standardize the error code and message
            *error = [NSError errorWithDomain:@"File not found" code:100 userInfo:nil];
        }
        return nil;
    }

    id ret = [NSMutableDictionary dictionary];

    [ret setValue:[NSNumber numberWithInt:st.st_size] forKey:NSFileSize];
    if (st.st_mode & _S_IFDIR) {
        [ret setValue:NSFileTypeDirectory forKey:NSFileType];
    } else {
        [ret setValue:NSFileTypeRegular forKey:NSFileType];
    }

    return ret;
}

/**
 @Status Stub
*/
- (id)attributesOfFileSystemForPath:(id)pathAddr error:(NSError**)error {
    UNIMPLEMENTED();
    if (error) {
        *error = nil;
    }

    const char* path = [pathAddr UTF8String];

    EbrDebugLog("fileAttributesAtPath: %s\n", path);

    id ret = [NSMutableDictionary dictionary];
    [ret setValue:[NSNumber numberWithInt:256 * 1024 * 1024] forKey:NSFileSystemFreeSize];

    return ret;
}

/**
 @Status Stub
*/
- (BOOL)setAttributes:(id)attribs ofItemAtPath:(id)pathAddr error:(NSError**)err {
    UNIMPLEMENTED();
    return TRUE;
}

// Getting and Comparing File Contents

/**
 @Status Interoperable
*/
- (id)contentsAtPath:(id)pathAddr {
    return [NSData dataWithContentsOfFile:pathAddr];
}

/**
 @Status Caveat
 @Notes Comparing directories not supported
*/
- (BOOL)contentsEqualAtPath:(id)pathObj1 andPath:(id)pathObj2 {
    const char* path1 = [pathObj1 UTF8String];
    const char* path2 = [pathObj2 UTF8String];

    bool dir = EbrIsDir(path1);
    if (dir != EbrIsDir(path2)) {
        return false;
    }

    if (dir) {
        // no good:
        assert(0);
    } else {
        struct stat st1, st2;
        if (EbrStat(path1, &st1) != 0 || EbrStat(path2, &st2) != 0) {
            return false;
        }

        if (st1.st_size != st2.st_size) {
            return false;
        }

        id d1 = [[NSData alloc] initWithContentsOfFile:pathObj1];
        id d2 = [[NSData alloc] initWithContentsOfFile:pathObj2];

        bool ret = [d1 isEqualToData:d2] != 0;

        [d1 release];
        [d2 release];

        return ret;
    }

    return FALSE;
}

// Getting the Relationship Between Items

/**
 @Status Stub
*/
- (BOOL)getRelationship:(NSURLRelationship*)outRelationship
       ofDirectoryAtURL:(NSURL*)directoryURL
            toItemAtURL:(NSURL*)otherURL
                  error:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)getRelationship:(NSURLRelationship*)outRelationship
            ofDirectory:(NSSearchPathDirectory)directory
               inDomain:(NSSearchPathDomainMask)domainMask
            toItemAtURL:(NSURL*)url
                  error:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

// Converting File Paths to Strings

/**
 @Status Stub
*/
- (const char*)fileSystemRepresentationWithPath:(id)pathAddr {
    UNIMPLEMENTED();
    return [pathAddr UTF8String];
}

/**
 @Status Stub
*/
- (id)stringWithFileSystemRepresentation:(const char*)path length:(NSUInteger)length {
    UNIMPLEMENTED();
    return [NSString stringWithCString:path length:length];
}

// Managing the Delegate

// Managing the Current Directory

/**
 @Status Interoperable
*/
- (BOOL)changeCurrentDirectoryPath:(NSString*)path {
    _currentDirectoryPath = path;

    const char* pathAddress = [path UTF8String];
    EbrChdir(pathAddress);

    return TRUE;
}

- (NSString*)currentDirectoryPath {
    return _currentDirectoryPath;
}

// Deprecated Methods

/**
 @Status Stub
*/
- (BOOL)copyPath:(NSString*)src toPath:(NSString*)dest handler:handler {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)movePath:(NSString*)src toPath:(NSString*)dest handler:handler {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)removeFileAtPath:(NSString*)path handler:handler {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)changeFileAttributes:(NSDictionary*)attributes atPath:(NSString*)path {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Caveat
 @Notes Only NSFileSize, NSFileType, NSFileCreationDate, NSFileModificationDate attributes are supported.
 @traverseLink not supported.
*/
- (NSDictionary*)fileAttributesAtPath:(NSString*)pathAddr traverseLink:(BOOL)traveseLinks {
    if (pathAddr == nil) {
        EbrDebugLog("fileAttributesAtPath nil!");

        return nil;
    }

    struct stat st;

    const char* path = [pathAddr UTF8String];
    EbrDebugLog("fileAttributesAtPath: %s\n", path);

    if (EbrStat(path, &st) == -1) {
        return nil;
    }

    id ret = [NSMutableDictionary dictionary];

    [ret setValue:[NSNumber numberWithInt:st.st_size] forKey:NSFileSize];

    // NOTE: st_ctime is file creation time on windows for NTFS
    [ret setValue:[NSDate dateWithTimeIntervalSince1970:st.st_ctime] forKey:NSFileCreationDate];
    [ret setValue:[NSDate dateWithTimeIntervalSince1970:st.st_mtime] forKey:NSFileModificationDate];

    if (st.st_mode & _S_IFDIR) {
        [ret setValue:NSFileTypeDirectory forKey:NSFileType];
    } else {
        [ret setValue:NSFileTypeRegular forKey:NSFileType];
    }

    return ret;
}

/**
 @Status Stub
*/
- (NSDictionary*)fileSystemAttributesAtPath:(NSString*)pathAddr {
    UNIMPLEMENTED();
    const char* path = [pathAddr UTF8String];

    EbrDebugLog("fileAttributesAtPath: %s\n", path);

    id ret = [NSMutableDictionary dictionary];

    [ret setValue:[NSNumber numberWithInt:32 * 1024 * 1024] forKey:NSFileSystemFreeSize];
    [ret setValue:[NSNumber numberWithInt:64 * 1024 * 1024 * 1024] forKey:NSFileSystemSize];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSArray*)directoryContentsAtPath:(NSString*)pathAddr {
    id enumerator = [[[NSDirectoryEnumerator alloc] initWithPath:[pathAddr UTF8String]
                                                         shallow:YES
                                      includingPropertiesForKeys:nil
                                                         options:NSDirectoryEnumerationSkipsSubdirectoryDescendants
                                                     returnNSURL:NO] autorelease];

    id ret = [enumerator allObjects];
    return ret;
}

/**
 @Status Caveat
 @Notes attributes parameter not supported
*/
- (BOOL)createDirectoryAtPath:(id)pathAddr attributes:(NSDictionary*)attrs {
    const char* path = [pathAddr UTF8String];

    if (EbrMkdir(path)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 @Status Stub
*/
- (BOOL)createSymbolicLinkAtPath:(NSString*)path pathContent:(NSString*)destination {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (NSString*)pathContentOfSymbolicLinkAtPath:(NSString*)path {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (BOOL)linkPath:(NSString*)source toPath:(NSString*)destination handler:handler {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)removeItemAtPath:(id)pathAddr error:(NSError**)error {
    if (error) {
        *error = nil;
    }

    const char* path = [pathAddr UTF8String];
    EbrDebugLog("removeItemAtPath: %s\n", path);

    BOOL ret = EbrRemove(path);
    if (!ret && error) {
        // TODO: standardize the error code and message
        *error = [NSError errorWithDomain:@"Failed to delete file" code:100 userInfo:nil];
    }

    return ret;
}

- (void)dealloc {
    _currentDirectoryPath = nil;
    [super dealloc];
}

@end
