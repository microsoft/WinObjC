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

#include <sys/stat.h>
#include <errno.h>

#ifdef __linux__
#define _S_IFDIR S_IFDIR
#endif

#define DEFN_STR(name) SB_EXPORT NSString* const name = @ #name;

DEFN_STR(NSFileTypeDirectory)
DEFN_STR(NSFileTypeRegular)
DEFN_STR(NSFileType)
DEFN_STR(NSFileSize)
DEFN_STR(NSFileModificationDate)
DEFN_STR(NSFileOwnerAccountName)
DEFN_STR(NSFileSystemFreeSize)
DEFN_STR(NSFileSystemSize)
DEFN_STR(NSFilePosixPermissions)
DEFN_STR(NSFileSystemFileNumber)
DEFN_STR(NSFilePathErrorKey)
DEFN_STR(NSFileProtectionKey)
DEFN_STR(NSFileProtectionComplete)
DEFN_STR(NSFileProtectionCompleteUnlessOpen)

@implementation NSDirectoryEnumerator : NSEnumerator {
    idretain rootFiles;
    idretain curFile;
    idretain enumerators;
    idretain curEnumerator[32];
    int curDepth;
    bool _skipDescendents;
    idretain searchPath;
}

- (instancetype)init {
    return self;
}

static void searchRecursive(const char* rootpath, const char* subpath, id objArray, BOOL shallow) {
    char searchPath[4096];
    strcpy(searchPath, rootpath);
    if (searchPath[strlen(searchPath) - 1] != '/') {
        strcat(searchPath, "/");
    }
    strcat(searchPath, subpath);
    if (searchPath[strlen(searchPath) - 1] != '/') {
        strcat(searchPath, "/");
    }

    EbrDir* ebrDir = EbrOpenDir(searchPath);
    if (ebrDir != NULL) {
        EbrDirEnt dirEnt;
        while (EbrReadDir(ebrDir, &dirEnt)) {
            if (strcmp(dirEnt.fileName, ".") == 0 || strcmp(dirEnt.fileName, "..") == 0)
                continue;

            char filename[4096];
            strcpy(filename, subpath);

            if (strlen(filename) > 0 && filename[strlen(filename) - 1] != '/') {
                strcat(filename, "/");
            }
            strcat(filename, dirEnt.fileName);

            id newStr = [NSString stringWithCString:filename];
            [objArray addObject:newStr];

            if (!shallow) {
                if (dirEnt.isDir) {
                    searchRecursive(rootpath, filename, objArray, shallow);
                }
            }
        }

        EbrCloseDir(ebrDir);
    }
    return;
}

- (id)initWithPath:(const char*)path shallow:(BOOL)shallow {
    rootFiles.attach([NSMutableArray new]);
    searchRecursive(path, "", rootFiles, shallow);
    searchPath = [NSString stringWithCString:path];

    curEnumerator[0] = [rootFiles objectEnumerator];
    curDepth = 0;

    return self;
}

static void addAllFiles(id enumerator, id allFiles) {
    id curObj = [enumerator nextObject];

    while (curObj != nil) {
        if ([curObj isKindOfClass:[NSString class]]) {
            [allFiles addObject:curObj];
        } else {
            id subEnum = [curObj objectEnumerator];

            addAllFiles(subEnum, allFiles);
        }

        curObj = [enumerator nextObject];
    }
}

- (id) /* use typed version */ allObjects {
    id ret = [NSMutableArray array];
    id curEnum = [rootFiles objectEnumerator];

    addAllFiles(curEnum, ret);

    return ret;
}

- (unsigned)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(DWORD)maxCount {
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
        id next = [state->extra[0] nextObject];
        if (next == nil)
            break;

        *stackBuf = next;
        stackBuf++;
        numRet++;
        maxCount--;
    }

    return numRet;
}

- (void)dealloc {
    rootFiles = nil;
    curFile = nil;
    enumerators = nil;
    for (int i = 0; i <= curDepth; i++) {
        curEnumerator[i] = nil;
    }
    searchPath = nil;

    [super dealloc];
}

- (id) /* use typed version */ skipDescendents {
    _skipDescendents = true;

    return self;
}

- (id) /* use typed version */ nextObject {
    id curObj, ret = nil;

    while (curDepth >= 0) {
        curObj = [curEnumerator[curDepth] nextObject];
        if (curObj == nil) {
            curEnumerator[curDepth] = nil;
            curDepth--;
            _skipDescendents = false;
            continue;
        }

        if ([curObj isKindOfClass:[NSString class]]) {
            ret = curObj;
            break;
        } else {
            if (!_skipDescendents) {
                curDepth++;
                assert(curDepth < 32);
                curEnumerator[curDepth] = [curObj objectEnumerator];
            }
        }
    }

    curFile = ret;

    return ret;
}

- (id) /* use typed version */ fileAttributes {
    const char* rootPath = [searchPath UTF8String];
    const char* path = [curFile UTF8String];

    char fullPath[4096];

    strcpy(fullPath, rootPath);
    if (fullPath[strlen(fullPath) - 1] != '/')
        strcat(fullPath, "/");
    strcat(fullPath, path);

    EbrDebugLog("fileAttributesAtPath: %s\n", fullPath);

    struct stat st;

    if (EbrStat(fullPath, &st) == -1) {
        assert(0);
        return nil;
    }

    id ret = [NSMutableDictionary dictionary];

    [ret setValue:[NSNumber numberWithInt:st.st_size] forKey:@"NSFileSize"];
    [ret setValue:NSFileTypeRegular forKey:@"NSFileType"];

    id date = [NSDate dateWithTimeIntervalSince1970:(double)st.st_ctime];
    [ret setValue:@"NSFileCreationDate" forKey:date];

    return ret;
}

@end

extern "C" bool doLog;

@implementation NSFileManager : NSObject
- (BOOL)fileExistsAtPath:(id)pathAddr {
    if (pathAddr == nil)
        return FALSE;

    const char* path = [pathAddr UTF8String];

    if (strcmp(path, "") == 0)
        return FALSE;

    if (EbrAccess(path, 0) == 0) {
        return TRUE;
    } else {
        EbrDebugLog("File @ %s doesn't exist\n", path);
        return FALSE;
    }
}

- (BOOL)isReadableFileAtPath:(id)pathAddr {
    const char* path = [pathAddr UTF8String];

    if (EbrAccess(path, 6) == 0) {
        return TRUE;
    } else {
        EbrDebugLog("File @ %s isn't writable\n", path);
        return FALSE;
    }
}

- (BOOL)isWritableFileAtPath:(id)pathAddr {
    const char* path = [pathAddr UTF8String];

    if (EbrAccess(path, 4) == 0) {
        return TRUE;
    } else {
        EbrDebugLog("File @ %s isn't readable\n", path);
        return FALSE;
    }
}

- (BOOL)fileExistsAtPath:(id)pathAddr isDirectory:(unsigned char*)isDirectory {
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

- (BOOL)createDirectoryAtPath:(id)pathAddr attributes:(DWORD)attrs {
    const char* path = [pathAddr UTF8String];

    if (EbrMkdir(path)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

- (BOOL)createDirectoryAtPath:(id)pathAddr withIntermediateDirectories:(BOOL)createIntermediates attributes:(id)attrs error:(id*)err {
    if (createIntermediates) {
        const char* path = [pathAddr UTF8String];
        id components = [pathAddr pathComponents];
        char curPath[256] = "";

        int count = [components count];
        for (int i = 0; i < count; i++) {
            id curComponent = [components objectAtIndex:i];
            const char* pComponent = [curComponent UTF8String];

            if (strlen(pComponent) > 0) {
                strcat(curPath, pComponent);
                strcat(curPath, "/");
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

- (BOOL)createDirectoryAtURL:(id)url withIntermediateDirectories:(BOOL)createIntermediates attributes:(id)attrs error:(id*)err {
    id path = [url path];

    return [self createDirectoryAtPath:path withIntermediateDirectories:createIntermediates attributes:attrs error:err];
}

- (id)enumeratorAtPath:(id)pathAddr {
    const char* path = [pathAddr UTF8String];

    NSDirectoryEnumerator* directoryEnum = [NSDirectoryEnumerator new];
    [directoryEnum initWithPath:path shallow:FALSE];

    return directoryEnum;
}

- (BOOL)changeCurrentDirectoryPath:(id)pathAddr {
    const char* path = [pathAddr UTF8String];
    EbrDebugLog("setting path to %s\n", path);

    EbrChdir(path);

    return TRUE;
}

- (id)directoryContentsAtPath:(id)pathAddr {
    id enumerator = [NSDirectoryEnumerator new];
    [enumerator initWithPath:[pathAddr UTF8String] shallow:TRUE];

    id ret = [enumerator allObjects];
    [enumerator release];
    return ret;
}

- (id)contentsAtPath:(id)pathAddr {
    return [NSData dataWithContentsOfFile:pathAddr];
}

- (id)contentsOfDirectoryAtPath:(id)pathAddr error:(id*)err {
    EbrDebugLog("contentsOfDirectoryAtPath: %s\n", [pathAddr UTF8String]);
    id enumerator = [NSDirectoryEnumerator new];
    [enumerator initWithPath:[pathAddr UTF8String] shallow:TRUE];

    id ret = [enumerator allObjects];
    [enumerator release];
    return ret;
}

- (id)fileAttributesAtPath:(id)pathAddr traverseLink:(DWORD)traveseLinks {
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

    [ret setValue:[NSNumber numberWithInt:st.st_size] forKey:@"NSFileSize"];
    if (st.st_mode & _S_IFDIR) {
        [ret setValue:NSFileTypeDirectory forKey:@"NSFileType"];
    } else {
        [ret setValue:NSFileTypeRegular forKey:@"NSFileType"];
    }

    return ret;
}

- (id)stringWithFileSystemRepresentation:(char*)path length:(int)length {
    return [NSString stringWithCString:path length:length];
}

- (id)displayNameAtPath:(id)path {
    return path;
}

- (id)attributesOfItemAtPath:(id)pathAddr error:(id*)error {
    if (pathAddr == nil) {
        EbrDebugLog("attributesOfItemAtPath nil!");

        if (error) {
            assert(0);
        }

        return nil;
    }

    struct stat st;

    const char* path = [pathAddr UTF8String];
    EbrDebugLog("attributesOfItemAtPath: %s\n", path);

    if (EbrStat(path, &st) == -1) {
        if (error) {
            *error = [NSError errorWithDomain:@"File not found" code:100 userInfo:nil];
        }
        return nil;
    }

    id ret = [NSMutableDictionary dictionary];

    [ret setValue:[NSNumber numberWithInt:st.st_size] forKey:@"NSFileSize"];
    if (st.st_mode & _S_IFDIR) {
        [ret setValue:NSFileTypeDirectory forKey:@"NSFileType"];
    } else {
        [ret setValue:NSFileTypeRegular forKey:@"NSFileType"];
    }

    return ret;
}

- (BOOL)setAttributes:(id)attribs ofItemAtPath:(id)pathAddr error:(id*)err {
    EbrDebugLog("setAttributes not implemented\n");

    return TRUE;
}

- (BOOL)removeItemAtPath:(id)pathAddr error:(id*)errRet {
    const char* path = [pathAddr UTF8String];
    EbrDebugLog("removeItemAtPath: %s\n", path);

    return EbrRemove(path);
}

- (BOOL)removeItemAtURL:(id)urlAddr error:(id*)errRet {
    id pathAddr = [urlAddr path];
    if (pathAddr == nil) {
        EbrDebugLog("removeItemAtURL: nil!\n");
        return FALSE;
    }

    return [self removeItemAtPath:pathAddr error:errRet];
}

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

+ (id) /* use typed version */ defaultManager {
    static id defaultManager;

    if (defaultManager == nil) {
        defaultManager = [self alloc];
    }

    return defaultManager;
}

- (BOOL)copyItemAtPath:(id)srcPath toPath:(id)destPath error:(id*)error {
    if (srcPath == nil || destPath == nil) {
        EbrDebugLog("copyItemAtPath: nil!\n");
        return FALSE;
    }

    const char* src = [srcPath UTF8String];
    const char* dest = [destPath UTF8String];

    if (EbrAccess(dest, 0) == 0) {
        if (error)
            *error = [NSError errorWithDomain:@"Would overwrite destination" code:100 userInfo:nil];
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

- (BOOL)moveItemAtPath:(id)srcPath toPath:(id)destPath error:(id*)error {
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

- (id)fileSystemAttributesAtPath:(id)pathAddr {
    const char* path = [pathAddr UTF8String];

    EbrDebugLog("fileAttributesAtPath: %s\n", path);

    id ret = [NSMutableDictionary dictionary];

    [ret setValue:[NSNumber numberWithInt:32 * 1024 * 1024] forKey:@"NSFileSystemFreeSize"];
    [ret setValue:[NSNumber numberWithInt:64 * 1024 * 1024 * 1024] forKey:@"NSFileSystemSize"];

    return ret;
}

- (id)attributesOfFileSystemForPath:(id)pathAddr error:(id*)error {
    const char* path = [pathAddr UTF8String];

    EbrDebugLog("fileAttributesAtPath: %s\n", path);

    id ret = [NSMutableDictionary dictionary];

    [ret setValue:[NSNumber numberWithInt:256 * 1024 * 1024] forKey:@"NSFileSystemFreeSize"];

    if (error)
        *error = nil;

    return ret;
}

- (const char*)fileSystemRepresentationWithPath:(id)pathAddr {
    return [pathAddr UTF8String];
}

- (id)destinationOfSymbolicLinkAtPath:(id)path error:(id*)error {
    const char* pPath = [path UTF8String];
    EbrDebugLog("destinationOfSymbolicLinkAtPath: %s\n", pPath);

    return [path retain];
}

- (id)URLsForDirectory:(DWORD)directory inDomains:(DWORD)domains {
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

- (id)URLForDirectory:(DWORD)directory inDomain:(DWORD)domains appropriateForURL:(id)forURL create:(BOOL)create error:(id*)error {
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

- (BOOL)contentsEqualAtPath:(id)pathObj1 andPath:(id)pathObj2 {
    const char* path1 = [pathObj1 UTF8String];
    const char* path2 = [pathObj2 UTF8String];

    bool dir = EbrIsDir(path1);
    if (dir != EbrIsDir(path2))
        return false;

    if (dir) {
        // no good:
        assert(0);
    } else {
        struct stat st1, st2;
        if (EbrStat(path1, &st1) != 0 || EbrStat(path2, &st2) != 0)
            return false;

        if (st1.st_size != st2.st_size)
            return false;

        id d1 = [[NSData alloc] initWithContentsOfFile:pathObj1];
        id d2 = [[NSData alloc] initWithContentsOfFile:pathObj2];

        bool ret = [d1 isEqualToData:d2] != 0;

        [d1 release];
        [d2 release];

        return ret;
    }

    return FALSE;
}

- (void)dealloc {
    EbrDebugLog("Warning: NSFileManager dealloced\n");
}

@end
