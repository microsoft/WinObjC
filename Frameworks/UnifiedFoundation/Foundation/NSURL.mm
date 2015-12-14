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
#include "Foundation/NSMutableString.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSURL.h"
#include "libxml/uri.h"
#include "HashFn.h"
#include "Etc.h"

#define NSURLMAXLEN SIZE_MAX

// Keys that apply to file system URLs.
NSString* const NSURLAddedToDirectoryDateKey = @"NSURLAddedToDirectoryDateKey";
NSString* const NSURLAttributeModificationDateKey = @"NSURLAttributeModificationDateKey";
NSString* const NSURLFileScheme = @"NSURLFileScheme";
NSString* const NSURLContentAccessDateKey = @"NSURLContentAccessDateKey";
NSString* const NSURLContentModificationDateKey = @"NSURLContentModificationDateKey";
NSString* const NSURLCreationDateKey = @"NSURLCreationDateKey";
NSString* const NSURLCustomIconKey = @"NSURLCustomIconKey";
NSString* const NSURLDocumentIdentifierKey = @"NSURLDocumentIdentifierKey";
NSString* const NSURLEffectiveIconKey = @"NSURLEffectiveIconKey";
NSString* const NSURLFileResourceIdentifierKey = @"NSURLFileResourceIdentifierKey";
NSString* const NSURLFileResourceTypeKey = @"NSURLFileResourceIdentifierKey";
NSString* const NSURLFileSecurityKey = @"NSURLFileSecurityKey";
NSString* const NSURLHasHiddenExtensionKey = @"NSURLHasHiddenExtensionKey";
NSString* const NSURLIsDirectoryKey = @"NSURLIsDirectoryKey";
NSString* const NSURLIsExcludedFromBackupKey = @"NSURLIsExcludedFromBackupKey";
NSString* const NSURLIsExecutableKey = @"NSURLIsExecutableKey";
NSString* const NSURLIsHiddenKey = @"NSURLIsHiddenKey";
NSString* const NSURLIsMountTriggerKey = @"NSURLIsMountTriggerKey";
NSString* const NSURLIsPackageKey = @"NSURLIsPackageKey";
NSString* const NSURLIsReadableKey = @"NSURLIsReadableKey";
NSString* const NSURLIsRegularFileKey = @"NSURLIsRegularFileKey";
NSString* const NSURLIsSymbolicLinkKey = @"NSURLIsSymbolicLinkKey";
NSString* const NSURLIsSystemImmutableKey = @"NSURLIsSystemImmutableKey";
NSString* const NSURLIsUserImmutableKey = @"NSURLIsUserImmutableKey";
NSString* const NSURLIsVolumeKey = @"NSURLIsVolumeKey";
NSString* const NSURLIsWritableKey = @"NSURLIsWritableKey";
NSString* const NSURLLabelColorKey = @"NSURLLabelColorKey";
NSString* const NSURLLabelNumberKey = @"NSURLLabelNumberKey";
NSString* const NSURLLinkCountKey = @"NSURLLinkCountKey";
NSString* const NSURLLocalizedLabelKey = @"NSURLLocalizedLabelKey";
NSString* const NSURLLocalizedNameKey = @"NSURLLocalizedNameKey";
NSString* const NSURLLocalizedTypeDescriptionKey = @"NSURLLocalizedTypeDescriptionKey";
NSString* const NSURLNameKey = @"NSURLNameKey";
NSString* const NSURLParentDirectoryURLKey = @"NSURLParentDirectoryURLKey";
NSString* const NSURLPathKey = @"NSURLPathKey";
NSString* const NSURLPreferredIOBlockSizeKey = @"NSURLPreferredIOBlockSizeKey";
NSString* const NSURLTypeIdentifierKey = @"NSURLTypeIdentifierKey";
NSString* const NSURLVolumeIdentifierKey = @"NSURLVolumeIdentifierKey";
NSString* const NSURLVolumeURLKey = @"NSURLVolumeURLKey";

// Possible values for the NSURLFileResourceTypeKey key.
NSString* const NSURLFileResourceTypeNamedPipe = @"NSURLFileResourceTypeNamedPipe";
NSString* const NSURLFileResourceTypeCharacterSpecial = @"NSURLFileResourceTypeCharacterSpecial";
NSString* const NSURLFileResourceTypeDirectory = @"NSURLFileResourceTypeDirectory";
NSString* const NSURLFileResourceTypeBlockSpecial = @"NSURLFileResourceTypeBlockSpecial";
NSString* const NSURLFileResourceTypeRegular = @"NSURLFileResourceTypeRegular";
NSString* const NSURLFileResourceTypeSymbolicLink = @"NSURLFileResourceTypeSymbolicLink";
NSString* const NSURLFileResourceTypeSocket = @"NSURLFileResourceTypeSocket";
NSString* const NSURLFileResourceTypeUnknown = @"NSURLFileResourceTypeUnknown";

// Keys that apply to properties of files.
NSString* const NSURLFileSizeKey = @"NSURLFileSizeKey";
NSString* const NSURLFileAllocatedSizeKey = @"NSURLFileAllocatedSizeKey";
NSString* const NSURLIsAliasFileKey = @"NSURLIsAliasFileKey";
NSString* const NSURLTotalFileAllocatedSizeKey = @"NSURLTotalFileAllocatedSizeKey";
NSString* const NSURLTotalFileSizeKey = @"NSURLTotalFileSizeKey";

static void StripSlashes(char* pPath) {
    size_t length = strnlen_s(pPath, NSURLMAXLEN);
    while (length > 0 && pPath[length - 1] == '/') {
        pPath[length - 1] = '\0';
        length--;
    }
}

struct EbrURL {
    xmlURIPtr uriForAppending() {
        //  Copy our URI
        xmlURIPtr ret;
        xmlChar* copyStr = xmlSaveUri(_uri);
        ret = xmlParseURIRaw((char*)copyStr, 0);
        xmlFree(copyStr);

        //  Remove any parameters
        if (ret->path) {
            char* param = strstr(ret->path, ";");
            if (param) {
                *param = NULL;
            }
        }

        return ret;
    }

    xmlURIPtr _uri;
    char* _parameters;
    char* _path;
    char* _scheme;
    char* _server;
    int _port;
    char* _query;
    char* _fragment;

    EbrURL* Clone() {
        //  Copy our URI
        xmlURIPtr copyUri;
        xmlChar* copyStr = xmlSaveUri(_uri);
        copyUri = xmlParseURIRaw((char*)copyStr, 0);
        xmlFree(copyStr);

        EbrURL* ret = new EbrURL();
        ret->_uri = copyUri;
        ret->ProcessURI();

        return ret;
    }

    void ProcessURI() {
        if (_path) {
            free(_path);
            _path = NULL;
        }
        if (_parameters) {
            free(_parameters);
            _parameters = NULL;
        }

        //  Remove parameters and any trailing / from the path we report to the app
        if (_uri->path) {
            size_t newSize = strnlen_s(_uri->path, NSURLMAXLEN) + 1;
            _path = (char*)malloc(newSize);
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(_path, newSize, _uri->path) != 0);

            char* params = strstr(_path, ";");
            if (params != NULL) {
                *params = 0;
                params++;

                size_t newParamSize = strnlen_s(params, NSURLMAXLEN) + 1;
                _parameters = (char*)malloc(newParamSize);
                FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(_parameters, newParamSize, params) != 0);
            }

            //  Remove trailing /, except in "/" case where the path points to root
            if (strnlen_s(_path, newSize) > 1) {
                if (_path[strnlen_s(_path, newSize) - 1] == '/') {
                    _path[strnlen_s(_path, newSize) - 1] = '\0';
                }
            }
        }
        _scheme = _uri->scheme;
        _server = _uri->server;
        _port = _uri->port;
        if (_port == 0) {
            _port = -1;
            if (_uri->scheme && strcmp(_uri->scheme, "http") == 0) {
                _port = 80;
            } else if (_uri->scheme && strcmp(_uri->scheme, "https") == 0) {
                _port = 443;
            }
        }
        _query = _uri->query_raw;
        _fragment = _uri->fragment;
    }

    ~EbrURL() {
        if (_uri) {
            xmlFreeURI(_uri);
        }

        if (_parameters) {
            free(_parameters);
        }

        if (_path) {
            free(_path);
        }
    }

    EbrURL() {
        _uri = NULL;
        _parameters = NULL;
        _path = NULL;
        _scheme = NULL;
        _server = NULL;
        _port = -1;
        _query = NULL;
        _fragment = NULL;
    }

    EbrURL(const char* pScheme, const char* pHost, const char* pPath) {
        _uri = NULL;
        _parameters = NULL;
        _path = NULL;
        _scheme = NULL;
        _server = NULL;
        _port = -1;
        _query = NULL;
        _fragment = NULL;

        _uri = xmlCreateURI();

        if (pScheme) {
            _uri->scheme = (char*)xmlMalloc(strnlen_s(pScheme, NSURLMAXLEN) + 1);
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(_uri->scheme, NSURLMAXLEN, pScheme) != 0);
        }
        if (pHost) {
            _uri->server = (char*)xmlMalloc(strnlen_s(pHost, NSURLMAXLEN) + 1);
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(_uri->server, NSURLMAXLEN, pHost) != 0);
        }
        if (pPath) {
            _uri->path = (char*)xmlMalloc(strnlen_s(pPath, NSURLMAXLEN) + 1);
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(_uri->path, NSURLMAXLEN, pPath) != 0);
        }
        ProcessURI();
    }

    static char* escape(const char* in, const char* escapeChars) {
        char* ret = (char*)malloc(strnlen_s(in, NSURLMAXLEN) * 3 + 1);
        int retLen = 0;
        int inLen = strnlen_s(in, NSURLMAXLEN);
        const char* hex = "0123456789ABCDEF";

        for (int i = 0; i < inLen; i++) {
            const unsigned char inChar = in[i];

            if (!strchr(escapeChars, inChar)) {
                ret[retLen++] = in[i];
            } else {
                ret[retLen++] = '%';
                ret[retLen++] = hex[(inChar >> 4)];
                ret[retLen++] = hex[inChar & 0xF];
            }
        }

        ret[retLen] = 0;
        return ret;
    }

    EbrURL(const char* pStr) {
        _uri = NULL;
        _parameters = NULL;
        _path = NULL;
        _scheme = NULL;
        _server = NULL;
        _port = -1;
        _query = NULL;
        _fragment = NULL;

        char* escaped = escape(pStr, "{}\"[]");
        _uri = xmlParseURI(escaped);
        if (_uri) {
            ProcessURI();
        }

        if (!_uri) {
            char* str = (char*)xmlPathToURI((xmlChar*)escaped);
            _uri = xmlParseURI(str);
            xmlFree(str);
        }

        free(escaped);
        if (_uri) {
            ProcessURI();
        }
    }

    void SetBase(EbrURL* url) {
        xmlURIPtr baseURI = url->uriForAppending();
        xmlChar* baseURL = xmlSaveUri(baseURI);
        xmlChar* relativeURL = xmlSaveUri(_uri);
        xmlFreeURI(_uri);

        xmlChar* newURL = xmlBuildURI(relativeURL, baseURL);
        _uri = xmlParseURI((char*)newURL);

        xmlFree(baseURL);
        xmlFree(relativeURL);
        xmlFree(newURL);

        xmlFreeURI(baseURI);
        ProcessURI();
    }

    void SetPath(const char* path, char* params) {
        char* oldPath = _path;
        char* oldParams = _parameters;

        _path = NULL;
        _parameters = NULL;

        int newLen = 16;

        if (path) {
            _path = (char*)malloc(strnlen_s(path, NSURLMAXLEN) + 1);
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(_path, NSURLMAXLEN, path) != 0);
            newLen += strnlen_s(_path, NSURLMAXLEN);
        }
        if (params) {
            _parameters = (char*)malloc(strnlen_s(params, NSURLMAXLEN) + 1);
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(_parameters, NSURLMAXLEN, params) != 0);
            newLen += strnlen_s(params, NSURLMAXLEN);
        }

        //  Strip out parameter
        char* newPath = (char*)xmlMalloc(newLen);
        FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "") != 0);
        if (path) {
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(newPath, newLen, path) != 0);
        }

        if (params) {
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(newPath, newLen, ";") != 0);
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(newPath, newLen, params) != 0);
        }

        xmlFree(_uri->path);
        _uri->path = newPath;

        if (oldPath) {
            free(oldPath);
        }

        if (oldParams) {
            free(oldParams);
        }
    }

    void AppendPath(char* pPath) {
        int newLen = 16;

        if (_path) {
            newLen += strnlen_s(_path, NSURLMAXLEN);
        }

        if (pPath) {
            newLen += strnlen_s(pPath, NSURLMAXLEN);
        }

        //  Strip out parameter
        char* newPath = (char*)malloc(newLen);
        auto cleanupTemps = wil::ScopeExit([&]() { free(newPath); });

        FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "") != 0);
        if (_path) {
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, _path) != 0);
        }

        FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(newPath, newLen, "/") != 0);
        FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(newPath, newLen, pPath) != 0);
        xmlNormalizeURIPath(newPath);

        SetPath(newPath, _parameters);
    }

    void AppendExtension(const char* pPath) {
        int newLen = 2; // size of ".";

        if (_path) {
            newLen += strnlen_s(_path, NSURLMAXLEN);
        }

        if (pPath) {
            newLen += strnlen_s(pPath, NSURLMAXLEN);
        }

        char* newPath = (char*)malloc(newLen);
        auto cleanupTemps = wil::ScopeExit([&]() { free(newPath); });

        FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "") != 0);
        if (_path) {
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, _path) != 0);
        }

        if (0 != strcmp(newPath, "/")) {
            StripSlashes(newPath);
        }

        FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(newPath, newLen, ".") != 0);
        FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(newPath, newLen, pPath) != 0);
        SetPath(newPath, _parameters);
    }

    void DeleteExtension() {
        int newLen = 1; // size of ""
        if (_path) {
            newLen += strnlen_s(_path, NSURLMAXLEN);
        }

        char* newPath = (char*)malloc(newLen);
        auto cleanupTemps = wil::ScopeExit([&]() { free(newPath); });

        FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "") != 0);
        if (_path) {
            size_t lastComponentIndex = 0;
            size_t extensionIndex = std::string::npos;
            char* pLastComponent = strrchr(_path, '/');
            if (pLastComponent) {
                lastComponentIndex = static_cast<unsigned int>(pLastComponent - _path);
            }

            char* pExtension = strrchr(_path, '.');
            if (pExtension) {
                extensionIndex = static_cast<unsigned int>(pExtension - _path);
            }

            if (extensionIndex != std::string::npos && extensionIndex > lastComponentIndex) {
                FAIL_FAST_HR_IF(E_UNEXPECTED, strncpy_s(newPath, newLen, _path, extensionIndex) != 0);
                newPath[extensionIndex] = '\0';
            } else {
                // If no extension exists within the url, simply return without changing _path
                return;
            }
        }

        SetPath(newPath, _parameters);
    }

    void DeleteLastPathComponent() {
        int newLen = 5; // size of "/../"
        if (_path) {
            newLen += strnlen_s(_path, NSURLMAXLEN);
        }

        char* newPath = (char*)malloc(newLen);
        auto cleanupTemps = wil::ScopeExit([&]() { free(newPath); });

        FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "") != 0);
        if (_path) {
            char* pLastComponent = strrchr(_path, '/');
            size_t lastComponentIndex = std::string::npos;
            if (pLastComponent) {
                lastComponentIndex = static_cast<unsigned int>(pLastComponent - _path);
            }

            if (lastComponentIndex == 0) {
                if (1 == strnlen_s(_path, NSURLMAXLEN)) {
                    // iOS behavior conflicts with documentation in this case.
                    // The documentation claims "/" is the new path, while actually "/../" is returned.
                    FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "/../") != 0);
                } else {
                    FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "/") != 0);
                }
            } else if (0 == strnlen_s(_path, NSURLMAXLEN)) {
                // Edge case for when the path is empty
                FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "../") != 0);
            } else if (lastComponentIndex != std::string::npos) {
                FAIL_FAST_HR_IF(E_UNEXPECTED, strncpy_s(newPath, newLen, _path, lastComponentIndex) != 0);
                newPath[lastComponentIndex] = '\0';
            }
        } else {
            // Edge case for when the path is empty
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "../") != 0);
        }

        SetPath(newPath, _parameters);
    }

    void StandardizePath() {
        NSString* path = [[NSString alloc] initWithUTF8String:_path];
        const char* standardizedPath = [[path stringByStandardizingPath] UTF8String];

        int newLen = 1; // size of ""
        if (_path) {
            newLen += strnlen_s(standardizedPath, NSURLMAXLEN);
        }

        char* newPath = (char*)malloc(newLen);
        auto cleanupTemps = wil::ScopeExit([&]() { free(newPath); });

        FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, "") != 0);

        if (standardizedPath) {
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(newPath, newLen, standardizedPath) != 0);
        }

        xmlNormalizeURIPath(newPath);
        SetPath(newPath, _parameters);
        [path release];
    }
};

@implementation NSURL {
    struct EbrURL* _uri;
    struct EbrURL* _fullUri;
    id _baseURL;
    idretaint<NSString> _absoluteString;
    idretaint<NSMutableDictionary> _properties;
}

static void buildURIs(NSURL* self, const char* pStr, id baseURL) {
    self->_uri = new EbrURL(pStr);

    if (baseURL != nil) {
        NSURL* parentURL = baseURL;
        self->_fullUri = new EbrURL(pStr);
        self->_fullUri->SetBase(parentURL->_fullUri);
    } else {
        self->_fullUri = new EbrURL(pStr);
    }
}

static void buildFullURI(NSURL* url, NSURL* base) {
    if (base != nil) {
        NSURL* parentURL = base;
        url->_baseURL = [base retain];

        url->_fullUri = url->_uri->Clone();
        url->_fullUri->SetBase(parentURL->_fullUri);
    } else {
        url->_fullUri = url->_uri->Clone();
    }
}

static void initPath(NSURL* url, const char* pScheme, const char* pHost, const char* pPath) {
    url->_uri = new EbrURL(pScheme, pHost, pPath);

    return;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithScheme:(NSString*)scheme host:(NSString*)host path:(NSString*)path {
    initPath(self, [scheme UTF8String], [host UTF8String], [path UTF8String]);
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initFileURLWithPath:(NSString*)path {
    if (path == nil) {
        return nil;
    }

    NSURL* baseURL = nil;
    char szBasePath[4096] = "";

    if ([path isAbsolutePath] == FALSE) {
        EbrGetcwd(szBasePath, sizeof(szBasePath));

        //  Add trailing /
        if (strnlen_s(szBasePath, NSURLMAXLEN) > 0 && szBasePath[strnlen_s(szBasePath, NSURLMAXLEN) - 1] != '/') {
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(szBasePath, NSURLMAXLEN, "/") != 0);
        }
    }

    const char* pPath = [path UTF8String];
    char* szPath = (char*)malloc(strnlen_s(pPath, NSURLMAXLEN) + 16);
    FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(szPath, NSURLMAXLEN, pPath) != 0);

    //  Strip trailing /'s
    while (strnlen_s(szPath, NSURLMAXLEN) > 0 && szPath[strnlen_s(szPath, NSURLMAXLEN) - 1] == '/') {
        szPath[strnlen_s(szPath, NSURLMAXLEN) - 1] = 0;
    }

    BOOL isDirectory = FALSE;
    if (EbrAccess(szPath, 0) == -1 || EbrIsDir(szPath)) {
        isDirectory = TRUE;
    }

    free(szPath);

    return [self initFileURLWithPath:path isDirectory:isDirectory];
}

/**
 @Status Interoperable
*/
- (instancetype)initFileURLWithPath:(NSString*)path isDirectory:(BOOL)isDirectory {
    NSURL* baseURL = nil;
    char szBasePath[4096] = "";

    if ([path isAbsolutePath] == FALSE) {
        EbrGetcwd(szBasePath, sizeof(szBasePath));

        //  Add trailing /
        if (strnlen_s(szBasePath, NSURLMAXLEN) > 0 && szBasePath[strnlen_s(szBasePath, NSURLMAXLEN) - 1] != '/') {
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(szBasePath, NSURLMAXLEN, "/") != 0);
        }

        baseURL = [NSURL alloc];
        initPath(baseURL, "file", "localhost", szBasePath);
        buildFullURI(baseURL, nil);
    }

    const char* pPath = [path UTF8String];
    char* szPath = (char*)malloc(strnlen_s(pPath, NSURLMAXLEN) + 16);
    FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(szPath, NSURLMAXLEN, pPath) != 0);

    //  Strip trailing /'s
    while (strnlen_s(szPath, NSURLMAXLEN) > 0 && szPath[strnlen_s(szPath, NSURLMAXLEN) - 1] == '/') {
        szPath[strnlen_s(szPath, NSURLMAXLEN) - 1] = 0;
    }
    if (isDirectory) {
        //  Add trailing /
        if (strnlen_s(szPath, NSURLMAXLEN) > 0 && szPath[strnlen_s(szPath, NSURLMAXLEN) - 1] != '/') {
            FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(szPath, NSURLMAXLEN, "/") != 0);
        }
    }

    if (baseURL == nil) {
        initPath(self, "file", "localhost", szPath);
    } else {
        initPath(self, NULL, NULL, szPath);
    }

    free(szPath);

    buildFullURI(self, baseURL);

    // initialize source dictionary for this URL
    _properties = [NSMutableDictionary dictionary];
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string {
    return [self initWithString:string relativeToURL:nil];
}

/**
 @Status Stub
*/
- (NSURL*)fileReferenceURL {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByAppendingPathComponent:(id)path {
    return [self URLByAppendingPathComponent:path isDirectory:FALSE];
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByAppendingPathComponent:(id)path isDirectory:(BOOL)isDirectory {
    if (path == nil) {
        EbrDebugLog("URLByAppendingPathComponent: path is nil!\n");
        return nil;
    }

    NSURL* ret = [[[self class] alloc] init];
    const char* pPath = [path UTF8String];
    char* szPath = (char*)malloc(strnlen_s(pPath, NSURLMAXLEN) + 16);
    FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(szPath, NSURLMAXLEN, pPath) != 0);
    StripSlashes(szPath);
    if (isDirectory) {
        FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(szPath, NSURLMAXLEN, "/") != 0);
    }

    ret->_uri = _uri->Clone();
    ret->_uri->AppendPath(szPath);
    free(szPath);
    buildFullURI(ret, _baseURL);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByAppendingPathExtension:(NSString*)pathExtension {
    NSURL* ret = [[[self class] alloc] init];

    ret->_uri = _uri->Clone();
    ret->_uri->AppendExtension([pathExtension UTF8String]);
    buildFullURI(ret, _baseURL);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByDeletingLastPathComponent {
    NSURL* ret = [[[self class] alloc] init];
    ret->_uri = _uri->Clone();
    ret->_uri->DeleteLastPathComponent();
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (NSURL*)URLByDeletingPathExtension {
    NSURL* ret = [[[self class] alloc] init];
    ret->_uri = _uri->Clone();
    ret->_uri->DeleteExtension();
    return [ret autorelease];
}

/**
 @Status Stub
*/
- (NSURL*)URLByResolvingSymlinksInPath {
    UNIMPLEMENTED();
    return self;
}

/**
 @Status Caveat
 @Notes Does not resolve symlinks in path or check /private
 */
- (NSURL*)URLByStandardizingPath {
    NSURL* ret = [[[self class] alloc] init];
    ret->_uri = _uri->Clone();
    if ([[self scheme] isEqualToString:@"file"]) {
        ret->_uri->StandardizePath();
    }
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(id)string relativeToURL:(id)parent {
    if (string == nil) {
        return nil;
    }

    const char* pURL = [string UTF8String];
    buildURIs(self, pURL, parent);
    _baseURL = [parent retain];
    if (_uri == NULL) {
        return nil;
    }

    return self;
}

- (id)initWithString:(id)string relativeToURL:(id)parent isDirectory:(DWORD)isDirectory {
    if (string == nil) {
        return nil;
    }

    const char* pURL = [string UTF8String];
    char* szPath = (char*)malloc(strnlen_s(pURL, NSURLMAXLEN) + 16);
    FAIL_FAST_HR_IF(E_UNEXPECTED, strcpy_s(szPath, NSURLMAXLEN, pURL) != 0);
    StripSlashes(szPath);
    if (isDirectory) {
        FAIL_FAST_HR_IF(E_UNEXPECTED, strcat_s(szPath, NSURLMAXLEN, "/") != 0);
    }

    buildURIs(self, szPath, parent);
    free(szPath);
    _baseURL = [parent retain];
    if (_uri == NULL) {
        return nil;
    }

    return self;
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
+ (NSURL*)fileURLWithPath:(id)path isDirectory:(BOOL)isDirectory {
    return [[[self alloc] initFileURLWithPath:path isDirectory:isDirectory] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSURL*)URLWithString:(id)string {
    return [[[self alloc] initWithString:string] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSURL*)URLWithString:(id)string relativeToURL:(id)parent {
    return [[[self alloc] initWithString:string relativeToURL:parent] autorelease];
}

- (void)dealloc {
    [_baseURL release];
    if (_uri) {
        delete _uri;
    }

    if (_fullUri) {
        delete _fullUri;
    }

    _absoluteString = nil;
    _properties = nil;

    [super dealloc];
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    if ([coder allowsKeyedCoding]) {
        id path = [coder decodeObjectForKey:@"NS.path"];

        [self initWithString:path relativeToURL:nil];

        return self;
    } else {
        assert(0);
        // NSLog(@"NSURL only supports keyed unarchiving");
        [self release];
        return nil;
    }
}

- (void)encodeWithCoder:(NSCoder*)coder {
    if ([coder isKindOfClass:[NSKeyedArchiver class]]) {
        /* [TODO: Encode baseURL as well] */
        id fullURL = [self absoluteString];
        [coder encodeObject:fullURL forKey:@"NS.path"];
    } else {
        assert(0);
        // NSLog(@"NSURL only supports keyed archiving");
    }
}

- (unsigned)hash {
    if (_fullUri->_path) {
        return murmurHash3(_fullUri->_path, strnlen_s(_fullUri->_path, NSURLMAXLEN), 0x834cba12);
    }
    return 0;
}

- (BOOL)isEqual:(id)other {
    NSURL* otherURL;

    if (self == other) {
        return YES;
    }

    if (![other isKindOfClass:[NSURL class]]) {
        return NO;
    }

    return ([[other absoluteString] isEqual:[self absoluteString]]);
}

/**
 @Status Interoperable
*/
- (NSString*)relativeString {
    if (!_uri) {
        return [self absoluteString];
    } else {
        char* uriStr = (char*)xmlSaveUri(_uri->_uri);
        if (uriStr == NULL) {
            return nil;
        }

        id ret = [NSString stringWithCString:uriStr];
        xmlFree(uriStr);

        return ret;
    }
}

/**
 @Status Interoperable
*/
- (NSString*)absoluteString {
    if (_absoluteString == nil) {
        if (_fullUri) {
            char* uriStr = (char*)xmlSaveUri(_fullUri->_uri);
            if (uriStr == NULL) {
                return nil;
            }

            _absoluteString = [NSString stringWithCString:uriStr];
            xmlFree(uriStr);
        } else {
            char* uriStr = (char*)xmlSaveUri(_uri->_uri);
            if (uriStr == NULL) {
                return nil;
            }

            _absoluteString = [NSString stringWithCString:uriStr];
            xmlFree(uriStr);
        }
    }

    return (NSString*)_absoluteString;
}

/**
 @Status Interoperable
*/
- (BOOL)checkResourceIsReachableAndReturnError:(NSError**)error {
    if (error) {
        *error = nil;
    }

    if (![self isFileURL]) {
        // checkResourceIsReachableAndReturnError return NO for any non-FileURL according to reference doc
        if (error) {
            // TODO: standardize the error domain and error code
            *error = [NSError errorWithDomain:@"NSURL" code:100 userInfo:nil];
        }
        return NO;
    }

    return [[NSFileManager defaultManager] fileExistsAtPath:[self path]];
}

/**
 @Status Interoperable
*/
- (NSString*)resourceSpecifier {
    char* uriStr = (char*)xmlSaveUri(_fullUri->_uri);
    if (uriStr == NULL) {
        return nil;
    }

    char* schemeSkipped = uriStr;
    if (_fullUri->_scheme != NULL) {
        while (*schemeSkipped++) {
            if (*schemeSkipped == ':') {
                schemeSkipped++;
                break;
            }
        }
    }
    id ret = [NSString stringWithCString:schemeSkipped];
    xmlFree(uriStr);

    return ret;
}

/**
 @Status Interoperable
*/
- (NSString*)parameterString {
    if (!_fullUri->_parameters) {
        return nil;
    }

    id ret = [NSString stringWithCString:(char*)_fullUri->_parameters];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSString*)scheme {
    if (!_fullUri) {
        return nil;
    }

    if (!_fullUri->_scheme) {
        return nil;
    }

    id ret = [NSString stringWithCString:(char*)_fullUri->_scheme];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSString*)host {
    if (!_fullUri) {
        return nil;
    }

    if (!_fullUri->_server) {
        return @"";
    }

    id ret = [NSString stringWithCString:(char*)_fullUri->_server];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSString*)fragment {
    if (!_fullUri->_fragment) {
        return nil;
    }

    id ret = [NSString stringWithCString:(char*)_fullUri->_fragment];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSString*)path {
    if (!_fullUri) {
        return nil;
    }

    if (!_fullUri->_path) {
        return nil;
    }

    id ret = [NSString stringWithCString:(char*)_fullUri->_path];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSArray*)pathComponents {
    return [[self path] pathComponents];
}

/**
 @Status Interoperable
*/
- (id)port {
    if (_fullUri->_port == -1) {
        return nil;
    }

    return [NSNumber numberWithInt:_fullUri->_port];
}

/**
 @Status Interoperable
*/
- (id)query {
    if (!_fullUri->_query) {
        return nil;
    }

    id ret = [NSString stringWithCString:(char*)_fullUri->_query];

    return ret;
}

/**
 @Status Interoperable
*/
- (id)relativePath {
    if (!_uri->_path) {
        return nil;
    }

    id ret = [NSString stringWithCString:(char*)_uri->_path];

    return ret;
}

/**
 @Status stub
 @Notes unlikely we will support FileReferenceURL ever
*/
- (BOOL)isFileReferenceURL {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)isFileURL {
    if (_fullUri) {
        if (_fullUri->_scheme == NULL) {
            if (_fullUri->_path && _fullUri->_path[0] == '/') {
                return TRUE;
            }
        }
    }
    return [[self scheme] isEqualToString:@"file"];
}

- (id)description {
    return [self absoluteString];
}

/**
 @Status Interoperable
*/
- (id)absoluteURL {
    if (_baseURL == nil) {
        return self;
    }

    return [NSURL URLWithString:[self absoluteString]];
}

/**
 @Status Stub
*/
- (id)standardizedURL {
    UNIMPLEMENTED();
    EbrDebugLog("standardizedURL needs attention\n");
    return [self copy];
}

/**
 @Status Interoperable
*/
- (id)lastPathComponent {
    return [[self path] lastPathComponent];
}

/**
 @Status Interoperable
*/
- (id)pathExtension {
    return [[self path] pathExtension];
}

/**
 @Status Interoperable
*/
- (id)baseURL {
    return _baseURL;
}

/**
 @Status Stub
*/
- (BOOL)setResourceValue:(id)value forKey:(id)key error:(NSError**)error {
    UNIMPLEMENTED();
    if (error) {
        *error = nil;
    }

    return TRUE;
}

/**
 @Status Caveat
 @Notes there is no property key validitiy check yet
*/
- (BOOL)setProperty:(id)propertyValue forKey:(NSString*)propertyKey {
    // TODO: do a check if propertyKey is a valid key
    [_properties setObject:propertyValue forKey:propertyKey];

    return YES;
}

/**
 @Status Interoperable
*/
- (id)propertyForKey:(NSString*)propertyKey {
    return [_properties objectForKey:propertyKey];
}
@end
