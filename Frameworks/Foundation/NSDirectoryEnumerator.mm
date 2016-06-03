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
#import <Starboard.h>
#import <Foundation/Foundation.h>
#import <Foundation/NSDirectoryEnumerator.h>
#import "NSURLInternal.h"
#import <string>
#import <vector>
#import <sys/stat.h>
#import <errno.h>
#import "LoggingNative.h"

static const wchar_t* TAG = L"NSDirectoryEnumerator";

@implementation NSDirectoryEnumerator {
    idretaint<NSMutableDictionary> _rootFiles;
    idretaint<NSString> _currentFile;
    std::vector<idretaint<NSDirectoryEnumerator>> _currrentEnumerator;
    int _currentDepth;
    BOOL _skipDescendents;
    idretaint<NSString> _searchPath;
}

/**
 @Status Interoperable
*/
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
                                // TODO 7491994: Implement CFURL resourceValue APIs
                                // BOOL ret = [newURL setResourceValue:[fileAttributes objectForKey:NSFileModificationDate]
                                //                              forKey:NSURLContentModificationDateKey
                                //                               error:nil];
                                // assert(ret);
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

/**
 @Status Interoperable
 @Public No
*/
- (instancetype)_initWithPath:(const char*)path
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

/**
 @Status Interoperable
*/
- (NSMutableArray*)allObjects {
    id ret = [NSMutableArray array];
    id curEnum = [_rootFiles objectEnumerator];

    addAllFiles(curEnum, ret);

    return ret;
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
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

    NSMutableDictionary* ret = [NSMutableDictionary dictionary];
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

    TraceVerbose(TAG, L"fileAttributesAtPath: %hs", fullPath);

    return fileAttributesForFilePath(fullPath);
}

@end
