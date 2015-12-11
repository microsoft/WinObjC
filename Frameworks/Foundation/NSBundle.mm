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

#include <string.h>
#include <ctype.h>
#include "Starboard.h"
#include "Foundation/NSBundle.h"
#include "Foundation/NSString.h"
#include "Foundation/NSPropertyList.h"
#include "Foundation/NSData.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSFileManager.h"
#include "Foundation/NSNib.h"

#include <sys/stat.h>

@class NSNib;

static NSString* mainBundlePath;
static NSMutableArray* allBundles;
static NSBundle* mainBundle;
char g_globalExecutableName[255] = "";
static const int c_maxPath = 4096;
static IWLazyClassLookup _LazyCALayer("UIDevice");

bool isTabletDevice() {
    return [[_LazyCALayer currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad;
}

class StringPool {
    char* _base;
    int _maxLen;
    int _curLen;
    int _availableSpace;

public:
    StringPool() {
        _base = NULL;
        _maxLen = 0;
        _curLen = 0;
    }

    char* AddString(int len) {
        if (_curLen + len + 1 >= _maxLen) {
            _maxLen = 8192;
            _curLen = 0;
            _base = (char*)malloc(_maxLen);
        }

        char* ret = &_base[_curLen];
        _curLen += len + 1;

        return ret;
    }

    char* AddString(char* str) {
        size_t strLen = strlen(str);
        char* ret = AddString(strLen);
        strcpy_s(ret, GetAvailableSpace() + strLen, str);

        return ret;
    }

    int GetAvailableSpace() {
        return _maxLen - _curLen + 1;
    }
};

static StringPool _bundleStrings;

class BundleFile {
public:
    char* pszFullPath;
    char* pszDirectory;
    char* pszFilename;
    char* pszExtension;
    char* pszLocalization;
    char* pszPlatform;

    bool fullMatch(const char* filename, const char* extension) {
        if (pszFilename == NULL)
            return false;

        if (filename == NULL)
            return false;

        char* pFullPath = pszFullPath;
        if (strncmp(filename, pFullPath, strlen(filename)) != 0)
            return false;
        pFullPath += strlen(filename);
        if (strlen(pFullPath) == 0 && (extension == NULL || strlen(extension) == 0))
            return true;
        if (*pFullPath != '.')
            return false;
        pFullPath++;

        if (extension) {
            if (strcmp(pFullPath, extension) != 0)
                return false;
        }
        return true;
    }

    bool extensionMatch(const char* extension) {
        if (pszFilename == NULL)
            return false;

        if (pszExtension == NULL)
            return false;
        if (strcmp(extension, pszExtension) != 0)
            return false;

        return true;
    }

    bool filenameMatches(const char* filename, const char* extension) {
        if (pszFilename == NULL || filename == NULL)
            return false;

        if (extension) {
            if (strcmp(filename, pszFilename) != 0)
                return false;
            if (pszExtension == NULL)
                return false;
            if (strcmp(extension, pszExtension) != 0)
                return false;
            return true;
        } else {
            if (filename == NULL)
                return false;
            if (strncmp(filename, pszFilename, strlen(pszFilename)) != 0)
                return false;
            filename += strlen(pszFilename);
            if (pszExtension == NULL && strlen(filename) == 0)
                return true;
            if (*filename != '.')
                return false;
            filename++;
            if (strcmp(filename, pszExtension) != 0)
                return false;
            return true;
        }
    }
};

static bool hasExtension(const char* name, const char* ext) {
    int nameLen = strlen(name);
    int extLen = strlen(ext);

    if (nameLen < extLen)
        return false;
    if (_stricmp(&name[nameLen - extLen], ext) == 0)
        return true;
    return false;
}

static char* copyWithoutExtension(const char* name, const char* ext) {
    int nameLen = strlen(name);
    int extLen = strlen(ext);

    char* ret = (char*)_bundleStrings.AddString(nameLen - extLen);
    memcpy(ret, name, nameLen - extLen);
    ret[nameLen - extLen] = 0;

    return ret;
}

bool ScanFilename(BundleFile* dest, char* pDirectory, char* pFilename) {
    memset(dest, 0, sizeof(BundleFile));
    size_t strLen = strlen(pDirectory) + strlen(pFilename) + 1;
    dest->pszFullPath = (char*)_bundleStrings.AddString(strLen);
    int pszFullPathSize = _bundleStrings.GetAvailableSpace() + strLen;

    if (strlen(pDirectory) > 0) {
        sprintf_s(dest->pszFullPath, pszFullPathSize, "%s/%s", pDirectory, pFilename);
    } else {
        sprintf_s(dest->pszFullPath, pszFullPathSize, "%s", pFilename);
    }
    char szTemp[c_maxPath];
    strcpy_s(szTemp, sizeof(szTemp), pDirectory);
    char* save;
    char* curToken;
    curToken = strtok_r(szTemp, "/", &save);

    if (curToken != NULL) {
        if (hasExtension(curToken, ".lproj")) {
            dest->pszLocalization = copyWithoutExtension(curToken, ".lproj");
            curToken = strtok_r(NULL, "", &save);
            if (curToken != NULL) {
                dest->pszDirectory = copyWithoutExtension(curToken, "");
            }
        } else {
            dest->pszDirectory = copyWithoutExtension(pDirectory, "");
        }
    }

    //  Parse filename
    strcpy_s(szTemp, sizeof(szTemp), pFilename);

    //  Scan for a .
    char* pExtension = strrchr(szTemp, '.');
    if (pExtension) {
        *pExtension = 0;
        dest->pszExtension = copyWithoutExtension(pExtension + 1, "");
    }

    if (hasExtension(szTemp, "~iphone")) {
        if (isTabletDevice()) {
            return false;
        }
        dest->pszPlatform = copyWithoutExtension("~iphone", "");
        szTemp[strlen(szTemp) - 7] = 0;
    } else if (hasExtension(szTemp, "~iPad")) {
        if (!isTabletDevice()) {
            return false;
        }
        dest->pszPlatform = copyWithoutExtension("~iPad", "");
        szTemp[strlen(szTemp) - 5] = 0;
    }

    dest->pszFilename = copyWithoutExtension(szTemp, "");

    return true;
}

__declspec(dllexport) bool isOSTarget(NSString* versionStr) {
    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString* minOSVersion = [infoDict objectForKey:@"MinimumOSVersion"];
    if (minOSVersion != nil) {
        if (((int)[minOSVersion versionStringCompare:versionStr]) >= 0) {
            return true;
        }
    }

    NSString* platformVersion = [infoDict objectForKey:@"DTPlatformVersion"];
    if (platformVersion != nil) {
        if (((int)[platformVersion versionStringCompare:versionStr]) >= 0) {
            return true;
        }
    }

    char* pSDKVersion = (char*)[[infoDict objectForKey:@"DTSDKName"] UTF8String];
    if (pSDKVersion) {
        char* sdkEnd = pSDKVersion + strlen(pSDKVersion) - 1;
        while (sdkEnd > pSDKVersion) {
            if (!isdigit(*sdkEnd) && *sdkEnd != '.') {
                if (*sdkEnd != 0)
                    sdkEnd++;
                break;
            }
            sdkEnd--;
        }

        char* versionUTF = (char*)[versionStr UTF8String];
        if (strcmp(sdkEnd, versionUTF) >= 0) {
            return true;
        }
    }

    return false;
}

@interface NSBundle () {
    NSDictionary* _infoDictionary;
    NSDictionary* _localizedStrings;
    NSMutableArray* _preferredLocalizations;

    struct BundleFile* _files;
    int _numFiles;
    int _maxFiles;
}

@property (readwrite, copy) NSURL* bundleURL;
@property (readwrite, copy) NSString* bundlePath;

@end

@implementation NSBundle

static void ScanDir(NSBundle* self, char* curDirectory, const char* path) {
    EbrDir* dir = EbrOpenDir(path);
    if (dir) {
        EbrDirEnt ent;
        while (EbrReadDir(dir, &ent)) {
            if (strcmp(ent.fileName, ".") == 0 || strcmp(ent.fileName, "..") == 0)
                continue;

            if (ent.isDir) {
                //  The directory itself is also a file
                if (self->_numFiles + 1 > self->_maxFiles) {
                    self->_maxFiles += 1024;
                    self->_files = (BundleFile*)realloc(self->_files, sizeof(BundleFile) * self->_maxFiles);
                }

                if (ScanFilename(&self->_files[self->_numFiles], curDirectory, ent.fileName)) {
                    self->_numFiles++;
                }

                char fullPath[c_maxPath]; // max path?
                char relativePath[c_maxPath];
                sprintf_s(fullPath, sizeof(fullPath), "%s/%s", path, ent.fileName);

                if (strlen(curDirectory) > 0) {
                    sprintf_s(relativePath, sizeof(relativePath), "%s/%s", curDirectory, ent.fileName);
                } else {
                    sprintf_s(relativePath, sizeof(relativePath), "%s", ent.fileName);
                }
                ScanDir(self, relativePath, fullPath);
            } else {
                if (self->_numFiles + 1 > self->_maxFiles) {
                    self->_maxFiles += 1024;
                    self->_files = (BundleFile*)realloc(self->_files, sizeof(BundleFile) * self->_maxFiles);
                }

                if (ScanFilename(&self->_files[self->_numFiles], curDirectory, ent.fileName)) {
                    self->_numFiles++;
                }
            }
        }
        EbrCloseDir(dir);
    }
}

char* pszDirectory;
char* pszFilename;
char* pszExtension;
char* pszLocalization;
char* pszPlatform;

static int sortString(char* s1, char* s2) {
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    return strcmp(s1, s2);
}

static int localizationPriority(const char* str) {
    if (strcmp(str, "Base") == 0)
        return 0;
    if (strcmp(str, "en") == 0)
        return 1;
    if (strcmp(str, "English") == 0)
        return 2;
    if (strcmp(str, "eng") == 0)
        return 3;

    return 4;
}

static int sortLocalization(char* s1, char* s2) {
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;

    int p1 = localizationPriority(s1);
    int p2 = localizationPriority(s2);
    if (p1 == p2) {
        return strcmp(s1, s2);
    } else {
        return p1 - p2;
    }
}

static int compareString(char* s1, char* s2) {
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s2 == NULL && s1 != NULL && strlen(s1) == 0)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    return strcmp(s1, s2);
}

static int sortFiles(const void* p1, const void* p2) {
    BundleFile* f1 = (BundleFile*)p1;
    BundleFile* f2 = (BundleFile*)p2;

    int ret;

    ret = sortString(f1->pszFilename, f2->pszFilename);
    if (ret != 0)
        return ret;

    ret = sortString(f1->pszExtension, f2->pszExtension);
    if (ret != 0)
        return ret;

    ret = sortString(f1->pszDirectory, f2->pszDirectory);
    if (ret != 0)
        return ret;

    ret = sortString(f1->pszPlatform, f2->pszPlatform);
    if (ret != 0)
        return ret;

    ret = sortLocalization(f1->pszLocalization, f2->pszLocalization);

    return ret;
}

static void scanBundle(NSBundle* self, NSString* path) {
    char* bundlePath = (char*)[path UTF8String];
    ScanDir(self, "", bundlePath);

    qsort(self->_files, self->_numFiles, sizeof(BundleFile), sortFiles);
    return;
}

typedef struct {
    char* pFilename;
    char* pExtension;
} BundleFindParams;

static int strCompNull(const char* s1, const char* s2) {
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    return strcmp(s1, s2);
}

static int strNCompNull(const char* s1, const char* s2, int len) {
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    return strncmp(s1, s2, len);
}

typedef struct {
    char* pszFilename;
    char* pszExtension;
    char* pszDirectory;
} BundleFileComparison;

static int compareFiles(const void* findParams, const void* bundleFile) {
    BundleFile* f1 = (BundleFile*)bundleFile;
    BundleFileComparison* comp = (BundleFileComparison*)findParams;

    int ret = 0;

    if (comp->pszFilename)
        ret = compareString(comp->pszFilename, f1->pszFilename);
    if (ret != 0)
        return ret;

    if (comp->pszExtension)
        ret = compareString(comp->pszExtension, f1->pszExtension);
    if (ret != 0)
        return ret;

    if (comp->pszDirectory)
        ret = compareString(comp->pszDirectory, f1->pszDirectory);
    if (ret != 0)
        return ret;

    /* [BUG: blamb] We should find the "highest score" match, since we may end up in the middle of a directory/filename
    * match */

    return ret;
}

static BundleFile* findFullFile(NSBundle* self, NSString* filename, NSString* extension, NSString* directory, NSString* localization) {
    char* pFilename = (char*)[filename UTF8String];
    char* pExtension = (char*)[extension UTF8String];
    char* pDirectory = (char*)[directory UTF8String];
    char* pLocalization = (char*)[localization UTF8String];

    char szFullPath[c_maxPath];
    strcpy_s(szFullPath, sizeof(szFullPath), "");
    if (pDirectory) {
        strcat_s(szFullPath, sizeof(szFullPath) - strlen(szFullPath), pDirectory);
        strcat_s(szFullPath, sizeof(szFullPath) - strlen(szFullPath), "/");
    }

    if (pFilename) {
        strcat_s(szFullPath, sizeof(szFullPath) - strlen(szFullPath), pFilename);
    }
    if (pExtension && strlen(pExtension) > 0) {
        strcat_s(szFullPath, sizeof(szFullPath) - strlen(szFullPath), ".");
        strcat_s(szFullPath, sizeof(szFullPath) - strlen(szFullPath), pExtension);
    }

    BundleFileComparison b;
    b.pszFilename = NULL;
    b.pszExtension = NULL;
    b.pszDirectory = NULL;

    b.pszFilename = szFullPath;
    char* lastSlash = strrchr(szFullPath, '/');
    if (lastSlash) {
        b.pszDirectory = b.pszFilename;
        b.pszFilename = lastSlash + 1;
        while (lastSlash >= szFullPath && *lastSlash == '/') {
            *lastSlash = 0;
            lastSlash--;
        }
    }

    char* lastDot = strrchr(b.pszFilename, '.');
    if (lastDot) {
        b.pszExtension = lastDot + 1;
        *lastDot = 0;
    }

    if (b.pszFilename && strlen(b.pszFilename) == 0)
        b.pszFilename = NULL;
    if (b.pszExtension && strlen(b.pszExtension) == 0)
        b.pszExtension = NULL;

    BundleFile* result = (BundleFile*)bsearch(&b, self->_files, self->_numFiles, sizeof(BundleFile), compareFiles);

    int idx = result - self->_files;
    while (idx >= 0) {
        if (compareFiles(&b, self->_files + idx) != 0) {
            break;
        }

        result = self->_files + idx--;
    }

    return result;
}

static BundleFile* findFile(NSBundle* self, NSString* filename, NSString* extension) {
    return findFullFile(self, filename, extension, @"", nil);
}

static BundleFile* findFileDirectory(NSBundle* self, NSString* filename, NSString* extension, NSString* directory) {
    return findFullFile(self, filename, extension, directory, nil);
}

static BundleFile* findFileDirectoryLocal(
    NSBundle* self, NSString* filename, NSString* extension, NSString* directory, NSString* localization) {
    return findFullFile(self, filename, extension, directory, localization);
}

static NSArray* findFilesDirectory(NSBundle* self, NSString* bundlePath, NSString* extension, NSString* directory) {
    char* pExtension = (char*)[extension UTF8String];
    char* pDirectory = (char*)[directory UTF8String];
    NSMutableArray* retArr = [NSMutableArray array];

    if (pExtension && strlen(pExtension) == 0)
        pExtension = NULL;
    if (pDirectory && strlen(pDirectory) == 0)
        pDirectory = NULL;

    for (int i = 0; i < self->_numFiles; i++) {
        BundleFile* cur = &self->_files[i];

        if (pDirectory != NULL) {
            if (pExtension == NULL) {
                if (strNCompNull(pDirectory, cur->pszDirectory, strlen(pDirectory)) != 0)
                    continue;
            } else {
                if (strCompNull(pDirectory, cur->pszDirectory) != 0)
                    continue;
            }
        } else {
            if (cur->pszDirectory != NULL)
                continue;
        }

        if (!cur->extensionMatch(pExtension))
            continue;

        if (cur->pszLocalization == NULL) {
            [retArr addObject:[NSString stringWithFormat:@"%@%s", bundlePath, cur->pszFullPath]];
        } else if (strCompNull(cur->pszLocalization, "Base") == 0) {
            [retArr addObject:[NSString stringWithFormat:@"%@%s", bundlePath, cur->pszFullPath]];
        } else if (strCompNull(cur->pszLocalization, "en") == 0) {
            [retArr addObject:[NSString stringWithFormat:@"%@%s", bundlePath, cur->pszFullPath]];
        } else if (strCompNull(cur->pszLocalization, "English") == 0) {
            [retArr addObject:[NSString stringWithFormat:@"%@%s", bundlePath, cur->pszFullPath]];
        } else if (strCompNull(cur->pszLocalization, "eng") == 0) {
            [retArr addObject:[NSString stringWithFormat:@"%@%s", bundlePath, cur->pszFullPath]];
        }
    }

    return retArr;
}

/**
 @Status Interoperable
*/
- (NSString*)bundleIdentifier {
    return [_infoDictionary objectForKey:@"CFBundleIdentifier"];
}

/**
 @Status Caveat
 @Notes Always returns +[NSBundle mainBundle]
*/
+ (NSBundle*)bundleForClass:(id)_class {
    EbrDebugLog("bundleForClass: %s\n", _class ? object_getClassName(_class) : "nil");
    return [self mainBundle];
}

/**
 @Status Caveat
 @Notes Forwards to +[NSBundle bundleWithPath:]
*/
+ (NSBundle*)bundleWithIdentifier:(NSString*)identifier {
    EbrDebugLog("bundleForIdentifier: %s\n", [identifier UTF8String]);
    return [self bundleWithPath:identifier];
}

/**
 @Status Interoperable
*/
+ (NSArray*)allBundles {
    return allBundles;
}

/**
 @Status Interoperable
*/
+ (NSBundle*)mainBundle {
    if (allBundles == nil) {
        allBundles = [NSMutableArray new];
    }

    if (mainBundle == nil && mainBundlePath != nil) {
        mainBundle = [[self bundleWithPath:mainBundlePath] retain];
    }

    return mainBundle;
}

/**
 @Status Interoperable
*/
+ (NSBundle*)bundleWithPath:(NSString*)path {
    return [[[self alloc] initWithPath:path] autorelease];
}

+ (NSBundle*)bundleWithURL:(NSURL*)url {
    if ([url isFileURL]) {
        return [[[self alloc] initWithPath:[url path]] autorelease];
    } else {
        EbrDebugLog("bad URL\n");
        assert(0);
        return nil;
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUrl:(NSURL*)url {
    if ([url isFileURL]) {
        return [self initwithPath:[url path]];
    }

    EbrDebugLog("bad URL\n");
    return nil;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithPath:(NSString*)path {
    if (path == nil) {
        return nil;
    }

    if (self = [super init]) {
        [allBundles addObject:self];

        if (![path hasSuffix:@"/"]) {
            _bundlePath = [[path stringByAppendingString:@"/"] retain];
        } else {
            _bundlePath = [path copy];
        }

        _bundleURL = [[NSURL fileURLWithPath:_bundlePath] retain];

        logPerf("Scanning assets");
        scanBundle(self, _bundlePath);
        logPerf("Assets scanned");

        NSData* data = nil;

        if (data == nil) {
            NSString* nextPath = [path stringByAppendingPathComponent:@"Info.plist"];
            data = [NSData dataWithContentsOfFile:nextPath];
            path = nextPath;
        }
        if (data == nil) {
            NSString* nextPath = [path stringByAppendingPathComponent:@"Contents/Info.plist"];
            data = [NSData dataWithContentsOfFile:nextPath];
            path = nextPath;
        }

        if ([data length] > 0) {
            _infoDictionary = [
                [NSPropertyListSerialization propertyListFromData:data mutabilityOption:NSPropertyListImmutable format:0 errorDescription:0]
                retain];

            //  Find localized sttrings
            NSString* stringPath = [self pathForResource:@"Localizable" ofType:@"strings"];

            if (stringPath != nil) {
                NSData* stringData = [NSData dataWithContentsOfFile:stringPath];
                if ([stringData length] > 0) {
                    char* bytes = (char*)[stringData bytes];
                    if (*((WORD*)bytes) == 0xFFFE || *((WORD*)bytes) == 0xFEFF) {
                        NSString* str = [[[NSString alloc] initWithData:stringData encoding:NSUTF16BigEndianStringEncoding] autorelease];
                        _localizedStrings = [[str propertyListFromStringsFileFormat] retain];
                    } else if (*((WORD*)bytes) != 0xbbef) {
                        _localizedStrings = [[NSPropertyListSerialization propertyListFromData:stringData
                                                                              mutabilityOption:NSPropertyListImmutable
                                                                                        format:0
                                                                              errorDescription:0] retain];
                    }

                    if (_localizedStrings == nil) {
                        NSString* str = [[[NSString alloc] initWithData:stringData encoding:NSUTF8StringEncoding] autorelease];
                        _localizedStrings = [[str propertyListFromStringsFileFormat] retain];
                    }
                }
            }
        }

        logPerf("Bundle initialized");
    }

    return self;
}

- (void)dealloc {
    [_infoDictionary release];
    [_localizedStrings release];
    [_preferredLocalizations release];
    [_bundleURL release];
    [_bundlePath release];

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (NSString*)localizedStringForKey:(NSString*)key value:(NSString*)value table:(NSString*)table {
    NSString* strRet = nil;

    if (table == nil) {
        strRet = [_localizedStrings objectForKey:key];
    } else {
        char* tableName = (char*)[table UTF8String];

        static NSMutableDictionary* tables;

        if (tables == nil) {
            tables = [NSMutableDictionary new];
        }

        NSDictionary* stringDict = [tables objectForKey:table];
        if (stringDict == nil) {
            NSString* path = [self pathForResource:table ofType:@"strings"];

            if (path != nil) {
                NSData* stringData = [NSData dataWithContentsOfFile:path];
                char* bytes = (char*)[stringData bytes];
                stringDict = [NSPropertyListSerialization propertyListFromData:stringData
                                                              mutabilityOption:NSPropertyListImmutable
                                                                        format:0
                                                              errorDescription:0];

                [tables setObject:stringDict forKey:table];
            }
        }

        strRet = [stringDict objectForKey:key];
    }

    if (strRet == nil) {
        strRet = value;
    }
    if (strRet == nil || [strRet length] == 0) {
        strRet = key;
    }

    return strRet;
}

static NSString* makePath(NSBundle* self,
                          NSString* name,
                          NSString* extension,
                          NSString* directory,
                          NSString* localization,
                          NSString* sublocal = nil,
                          NSString* devtype = nil) {
    char szPath[c_maxPath];
    size_t numCharWritten = sprintf_s(szPath, sizeof(szPath), "%s/", [self->_bundlePath UTF8String]);

    if (name == nil) {
        assert(0);
    }
    if (localization != nil) {
        numCharWritten += sprintf_s(&szPath[numCharWritten], sizeof(szPath) - numCharWritten, "/%s.lproj/", [localization UTF8String]);
    }
    if (sublocal != nil) {
        numCharWritten += sprintf_s(&szPath[numCharWritten], sizeof(szPath) - numCharWritten, "/%s/", [sublocal UTF8String]);
    }
    if (directory != nil) {
        numCharWritten += sprintf_s(&szPath[numCharWritten], sizeof(szPath) - numCharWritten, "/%s/", [directory UTF8String]);
    }
    sprintf_s(&szPath[numCharWritten], sizeof(szPath) - numCharWritten, "/%s", [name UTF8String]);
    if (!isTabletDevice()) {
        if (strstr(szPath, "~iphone") != NULL) {
            char* pPos = strstr(szPath, "~iphone");
            memmove(pPos, pPos + 7, strlen(pPos + 7) + 1);
        }
    } else {
        if (strstr(szPath, "~iPad") != NULL) {
            char* pPos = strstr(szPath, "~iPad");
            memmove(pPos, pPos + 4, strlen(pPos + 4) + 1);
        }
    }

    if (extension != nil && [extension length] > 0) {
        char* pExtension = (char*)[extension UTF8String];

        if (pExtension[0] == '.' || (strlen(szPath) > 0 && szPath[strlen(szPath) - 1] == '.')) {
            sprintf_s(&szPath[strlen(szPath)], sizeof(szPath) - strlen(szPath), "%s", pExtension);
        } else {
            sprintf_s(&szPath[strlen(szPath)], sizeof(szPath) - strlen(szPath), ".%s", pExtension);
        }
    }
    if (devtype != nil && [devtype length] > 0) {
        char* pdevtype = (char*)[devtype UTF8String];
        char* pExtPos = strrchr(szPath, '.');

        if (pExtPos != NULL) {
            memmove(pExtPos + strlen(pdevtype), pExtPos, (szPath + strlen(szPath) - pExtPos) + 1);
            memcpy(pExtPos, pdevtype, strlen(pdevtype));
        } else {
            sprintf_s(&szPath[strlen(szPath)], sizeof(szPath) - strlen(szPath), "%s", pdevtype);
        }
    }

    return [NSString stringWithCString:szPath];
}

static NSString* checkPath(
    NSBundle* self, NSString* name, NSString* extension, NSString* directory, NSString* localization, NSString* sublocal = nil) {
    NSString* ret = makePath(self, name, extension, directory, localization, sublocal);

    char* path = (char*)[ret UTF8String];
    EbrDebugLog("Finding %s", path);

    if (EbrAccess(path, 0) == -1 || EbrIsDir(path)) {
        EbrDebugLog(" - not found\n");

        if (!isTabletDevice()) {
            ret = makePath(self, name, extension, directory, localization, sublocal, @"~iphone");
        } else {
            ret = makePath(self, name, extension, directory, localization, sublocal, @"~iPad");
        }

        path = (char*)[ret UTF8String];
        EbrDebugLog("Finding %s", path);

        if (EbrAccess(path, 0) == -1 || EbrIsDir(path)) {
            EbrDebugLog(" - not found\n");
            return nil;
        } else {
            EbrDebugLog(" - OK\n");
            return ret;
        }
#if 0
ret = makePath(name, extension, directory, localization, sublocal, @"-iPad");

path = (char *) [ret UTF8String];
EbrDebugLog("Finding %s", path);

if (EbrAccess(path, 0) == -1 ) {
EbrDebugLog(" - not found\n");
return nil;
} else {
EbrDebugLog(" - OK\n");
return ret;
}
#else
        return nil;
#endif
    } else {
        EbrDebugLog(" - OK\n");
        return ret;
    }
}

static NSString* makePathNonLocal(NSString* name, NSString* extension, NSString* directory, NSString* localization) {
    NSString* path = [NSString stringWithFormat:@""];

    if (name == nil) {
        assert(0);
    }
    if (localization != nil) {
        path = [path stringByAppendingFormat:@"/%@.lproj/", localization];
    }
    if (directory != nil) {
        path = [path stringByAppendingFormat:@"/%@/", directory];
    }
    path = [path stringByAppendingFormat:@"/%@", name];
    if (extension != nil && [extension length] > 0) {
        char* pExtension = (char*)[extension UTF8String];
        if (pExtension[0] == '.')
            pExtension++;

        path = [path stringByAppendingFormat:@".%s", pExtension];
    }

    return path;
}

static NSString* checkPathNonLocal(NSString* name, NSString* extension, NSString* directory, NSString* localization) {
    NSString* ret = makePathNonLocal(name, extension, directory, localization);

    char* path = (char*)[ret UTF8String];
    EbrDebugLog("Finding %s", path);

    if (EbrAccess(path, 0) == -1 || EbrIsDir(path)) {
        EbrDebugLog(" - not found\n");
        return nil;
    } else {
        EbrDebugLog(" - OK\n");
        return ret;
    }
}

/**
 @Status Interoperable
*/
- (NSURL*)URLForResource:(NSString*)name withExtension:(NSString*)extension {
    NSString* path = [self pathForResource:name ofType:extension];
    if (path == nil)
        return nil;

    return [NSURL fileURLWithPath:path];
}

/**
 @Status Interoperable
*/
+ (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension inDirectory:(NSString*)directory {
    return checkPathNonLocal(name, extension, directory, nil);
}

/**
 @Status Interoperable
*/
+ (NSArray*)pathsForResourcesOfType:(NSString*)type inDirectory:(NSString*)directory {
    NSMutableArray* ret = [NSMutableArray array];

    if (directory == nil) {
        directory = @".";
    }

    NSEnumerator* files = [[NSFileManager defaultManager] enumeratorAtPath:directory];

    char* pDir = (char*)[directory UTF8String];
    char* pExt = (char*)[type UTF8String];

    EbrDebugLog("Searching for %s in %s\n", pDir, pExt ? pExt : "(null)");

    NSString* curFile = [files nextObject];
    while (curFile != nil) {
        if (type == nil || [[curFile pathExtension] isEqual:type] == TRUE) {
            NSString* fullPath = [directory stringByAppendingPathComponent:curFile];
            char* pFile = (char*)[fullPath UTF8String];

            if (!EbrIsDir(pFile)) {
                EbrDebugLog("Found file %s\n", pFile);
                [ret addObject:fullPath];
            }
        }
        curFile = [files nextObject];
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension {
    BundleFile* pFile = findFile(self, name, extension);
    if (pFile) {
        NSString* ret = [NSString stringWithFormat:@"%@/%s", _bundlePath, pFile->pszFullPath];
#ifdef NSBUNDLE_LOG
        EbrDebugLog("Found %s\n", [ret UTF8String]);
#endif
        return ret;
    }
    /*
    if ( [name length] == 0 ) {
    id paths = [self pathsForResourcesOfType:extension inDirectory:nil];
    if ( [paths count] > 0 ) {
    return [paths objectAtIndex:0];
    }
    return nil;
    }

    id ret = checkPath(name, extension, nil, nil);
    if ( ret != nil ) {
    return ret;
    }

    //  Search localizations
    [self preferredLocalizations];

    int count = [_preferredLocalizations count];
    for ( int i = 0; i < count; i ++ ) {
    id curLocalization = [_preferredLocalizations objectAtIndex:i];

    ret = checkPath(name, extension, nil, curLocalization);
    if ( ret != nil ) return ret;
    }
    */

    return nil;
}

/**
 @Status Interoperable
*/
- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension inDirectory:(NSString*)directory {
    BundleFile* pFile = findFileDirectory(self, name, extension, directory);
    if (pFile) {
        NSString* ret = [NSString stringWithFormat:@"%@%s", _bundlePath, pFile->pszFullPath];
#ifdef NSBUNDLE_LOG
        EbrDebugLog("Found %s\n", [ret UTF8String]);
#endif
        return ret;
    }

    return nil;
}

/**
 @Status Caveat
 @Notes Localization parameter is not supported
*/
- (NSString*)pathForResource:(NSString*)name
                      ofType:(NSString*)extension
                 inDirectory:(NSString*)directory
             forLocalization:(NSString*)localization {
    BundleFile* pFile = findFileDirectoryLocal(self, name, extension, directory, localization);
    if (pFile) {
        NSString* ret = [NSString stringWithFormat:@"%@%s", _bundlePath, pFile->pszFullPath];
#ifdef NSBUNDLE_LOG
        EbrDebugLog("Found %s\n", [ret UTF8String]);
#endif
        return ret;
    }
    return nil;
    /*
    id ret = checkPath(name, extension, directory, nil);
    if ( ret != nil ) {
    return ret;
    }

    ret = checkPath(name, extension, directory, localiza

    */

    return nil;
}

/**
 @Status Interoperable
*/
- (id)objectForInfoDictionaryKey:(NSString*)name {
    assert(_infoDictionary != nil);

    return [_infoDictionary objectForKey:name];
}

/**
 @Status Caveat
 @Notes Returns bundlePath
*/
- (NSString*)resourcePath {
    return [[_bundlePath retain] autorelease];
}

/**
 @Status Stub
*/
- (NSString*)executablePath {
    UNIMPLEMENTED();
    return [_bundlePath stringByAppendingPathComponent:[NSString stringWithCString:g_globalExecutableName]];
}

/**
 @Status Interoperable
*/
- (NSDictionary*)infoDictionary {
    return _infoDictionary;
}

/**
 @Status Stub
*/
- (NSArray*)preferredLocalizations {
    UNIMPLEMENTED();
    if (_preferredLocalizations == nil) {
        _preferredLocalizations = [[NSMutableArray arrayWithObject:@"en"] retain];
        [_preferredLocalizations addObject:@"Base"];
        [_preferredLocalizations addObject:@"eng"];
        [_preferredLocalizations addObject:@"English"];
    }

    return _preferredLocalizations;
}

/**
 @Status Stub
*/
+ (NSArray*)preferredLocalizationsFromArray:(NSArray*)localizations {
    UNIMPLEMENTED();
    NSMutableArray* ret = [NSMutableArray array];

    if ([localizations containsObject:@"en"]) {
        [ret addObject:@"en"];
    }
    if ([localizations containsObject:@"eng"]) {
        [ret addObject:@"eng"];
    }
    if ([localizations containsObject:@"English"]) {
        [ret addObject:@"English"];
    }

    return ret;
}

/**
 @Status Stub
*/
+ (NSArray*)preferredLocalizationsFromArray:(NSArray*)localizations forPreferences:(NSArray*)preferences {
    UNIMPLEMENTED();
    NSMutableArray* ret = [NSMutableArray array];

    if ([localizations containsObject:@"en"]) {
        [ret addObject:@"en"];
    }
    if ([localizations containsObject:@"eng"]) {
        [ret addObject:@"eng"];
    }
    if ([localizations containsObject:@"English"]) {
        [ret addObject:@"English"];
    }

    return ret;
}

/**
 @Status Caveat
 @Notes Returns objc_getClass(name)
*/
- (id)classNamed:(NSString*)name {
    char* pName = (char*)[name UTF8String];

    EbrDebugLog("Finding class %s\n", pName);
    return objc_getClass(pName);
}

+ (void)setMainBundlePath:(NSString*)path {
    mainBundlePath = [path copy];
}

/**
 @Status Interoperable
*/
- (NSArray*)loadNibNamed:(NSString*)name owner:(id)owner options:(NSDictionary*)options {
    assert(options == nil);

    NSString* nibFile = [self pathForResource:name ofType:@"nib"];

    if (nibFile == nil) {
        EbrDebugLog("*** NIB not found ***\n");
        return nil;
    } else {
        NSNib* nib = [NSNib nibWithNibName: nibFile bundle: self];
        NSArray* topLevelObjects = [nib instantiateWithOwner: owner options: options];

        return topLevelObjects;
    }
}

/**
 @Status Interoperable
*/
- (NSArray*)pathsForResourcesOfType:(NSString*)type inDirectory:(NSString*)directory {
    return findFilesDirectory(self, _bundlePath, type, directory);
}

/**
 @Status Interoperable
*/
- (NSArray*)URLsForResourcesWithExtension:(NSString*)type subdirectory:(NSString*)directory {
    NSArray *paths = findFilesDirectory(self, _bundlePath, type, directory);

    NSMutableArray *ret = [NSMutableArray new];
    for ( NSString *path in paths ) {
        [ret addObject: [NSURL fileURLWithPath: path]];
    }

    return [ret autorelease];
}

/**
 @Status Interoperable
 @Notes Always returns TRUE, NSBundle is loaded @ designated initializer
*/
- (BOOL)load {
    return TRUE;
}

@end
