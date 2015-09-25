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
            _path = (char*)malloc(strlen(_uri->path) + 1);
            strcpy(_path, _uri->path);

            char* params = strstr(_path, ";");
            if (params != NULL) {
                *params = 0;
                params++;

                _parameters = (char*)malloc(strlen(params) + 1);
                strcpy(_parameters, params);
            }

            //  Remove trailing /
            if (strlen(_path) > 0) {
                if (_path[strlen(_path) - 1] == '/') {
                    _path[strlen(_path) - 1] = 0;
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
        if (_uri)
            xmlFreeURI(_uri);
        if (_parameters)
            free(_parameters);
        if (_path)
            free(_path);
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
            _uri->scheme = (char*)xmlMalloc(strlen(pScheme) + 1);
            strcpy(_uri->scheme, pScheme);
        }
        if (pHost) {
            _uri->server = (char*)xmlMalloc(strlen(pHost) + 1);
            strcpy(_uri->server, pHost);
        }
        if (pPath) {
            _uri->path = (char*)xmlMalloc(strlen(pPath) + 1);
            strcpy(_uri->path, pPath);
        }
        ProcessURI();
    }

    static char* escape(const char* in, const char* escapeChars) {
        char* ret = (char*)malloc(strlen(in) * 3 + 1);
        int retLen = 0;
        int inLen = strlen(in);
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
        if (_uri)
            ProcessURI();
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

    void SetPath(char* path, char* params) {
        char* oldPath = _path;
        char* oldParams = _parameters;

        _path = NULL;
        _parameters = NULL;

        int newLen = 16;

        if (path) {
            _path = (char*)malloc(strlen(path) + 1);
            strcpy(_path, path);
            newLen += strlen(_path);
        }
        if (params) {
            _parameters = (char*)malloc(strlen(params) + 1);
            strcpy(_parameters, params);
            newLen += strlen(params);
        }

        //  Strip out parameter
        char* newPath = (char*)xmlMalloc(newLen);
        strcpy(newPath, "");
        if (path)
            strcat(newPath, path);
        if (params) {
            strcat(newPath, ";");
            strcat(newPath, params);
        }

        xmlFree(_uri->path);
        _uri->path = newPath;

        if (oldPath)
            free(oldPath);
        if (oldParams)
            free(oldParams);
    }

    void AppendPath(char* pPath) {
        int newLen = 16;

        if (_path)
            newLen += strlen(_path);
        if (pPath)
            newLen += strlen(pPath);

        //  Strip out parameter
        char* newPath = (char*)malloc(newLen);
        strcpy(newPath, "");
        if (_path)
            strcpy(newPath, _path);
        strcat(newPath, "/");
        strcat(newPath, pPath);
        xmlNormalizeURIPath(newPath);

        SetPath(newPath, _parameters);
        free(newPath);
    }
};

@implementation NSURL : NSObject {
    struct EbrURL *_uri, *_fullUri;
    id _baseURL;
    idretain _absoluteString;
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

- (instancetype)initWithScheme:(NSString*)scheme host:(NSString*)host path:(NSString*)path {
    initPath(self, [scheme UTF8String], [host UTF8String], [path UTF8String]);
    return self;
}

- (instancetype)initFileURLWithPath:(NSString*)path {
    if (path == nil)
        return nil;

    NSURL* baseURL = nil;
    char szBasePath[4096] = "";

    if ([path isAbsolutePath] == FALSE) {
        EbrGetcwd(szBasePath, sizeof(szBasePath));

        //  Add trailing /
        if (strlen(szBasePath) > 0 && szBasePath[strlen(szBasePath) - 1] != '/')
            strcat(szBasePath, "/");
    }

    const char* pPath = [path UTF8String];
    char* szPath = (char*)malloc(strlen(pPath) + 16);
    strcpy(szPath, pPath);

    //  Strip trailing /'s
    while (strlen(szPath) > 0 && szPath[strlen(szPath) - 1] == '/') {
        szPath[strlen(szPath) - 1] = 0;
    }

    BOOL isDirectory = FALSE;
    if (EbrAccess(szPath, 0) == -1 || EbrIsDir(szPath))
        isDirectory = TRUE;
    free(szPath);

    return [self initFileURLWithPath:path isDirectory:isDirectory];
}

static void StripSlashes(char* pPath) {
    while (strlen(pPath) > 0 && pPath[strlen(pPath) - 1] == '/') {
        pPath[strlen(pPath) - 1] = 0;
    }
}

- (instancetype)initFileURLWithPath:(NSString*)path isDirectory:(BOOL)isDirectory {
    NSURL* baseURL = nil;
    char szBasePath[4096] = "";

    if ([path isAbsolutePath] == FALSE) {
        EbrGetcwd(szBasePath, sizeof(szBasePath));

        //  Add trailing /
        if (strlen(szBasePath) > 0 && szBasePath[strlen(szBasePath) - 1] != '/')
            strcat(szBasePath, "/");

        baseURL = [NSURL alloc];
        initPath(baseURL, "file", "localhost", szBasePath);
        buildFullURI(baseURL, nil);
    }

    const char* pPath = [path UTF8String];
    char* szPath = (char*)malloc(strlen(pPath) + 16);
    strcpy(szPath, pPath);

    //  Strip trailing /'s
    while (strlen(szPath) > 0 && szPath[strlen(szPath) - 1] == '/') {
        szPath[strlen(szPath) - 1] = 0;
    }
    if (isDirectory) {
        //  Add trailing /
        if (strlen(szPath) > 0 && szPath[strlen(szPath) - 1] != '/')
            strcat(szPath, "/");
    }

    if (baseURL == nil) {
        initPath(self, "file", "localhost", szPath);
    } else {
        initPath(self, NULL, NULL, szPath);
    }
    free(szPath);

    buildFullURI(self, baseURL);

    return self;
}

- (instancetype)initWithString:(NSString*)string {
    return [self initWithString:string relativeToURL:nil];
}

- (NSURL*)URLByAppendingPathComponent:(id)path {
    return [self URLByAppendingPathComponent:path isDirectory:FALSE];
}

- (NSURL*)URLByAppendingPathComponent:(id)path isDirectory:(BOOL)isDirectory {
    if (path == nil) {
        EbrDebugLog("URLByAppendingPathComponent: path is nil!\n");
        return nil;
    }

    NSURL* ret = [[self class] alloc];
    const char* pPath = [path UTF8String];
    char* szPath = (char*)malloc(strlen(pPath) + 16);
    strcpy(szPath, pPath);
    StripSlashes(szPath);
    if (isDirectory)
        strcat(szPath, "/");

    ret->_uri = _uri->Clone();
    ret->_uri->AppendPath(szPath);
    free(szPath);
    buildFullURI(ret, nil);

    return [ret autorelease];
}

- (instancetype)initWithString:(id)string relativeToURL:(id)parent {
    if (string == nil)
        return nil;

    const char* pURL = [string UTF8String];
    buildURIs(self, pURL, parent);
    _baseURL = [parent retain];
    if (_uri == NULL) {
        return nil;
    }

    return self;
}

- (id)initWithString:(id)string relativeToURL:(id)parent isDirectory:(DWORD)isDirectory {
    if (string == nil)
        return nil;

    const char* pURL = [string UTF8String];
    char* szPath = (char*)malloc(strlen(pURL) + 16);
    strcpy(szPath, pURL);
    StripSlashes(szPath);
    if (isDirectory)
        strcat(szPath, "/");

    buildURIs(self, szPath, parent);
    free(szPath);
    _baseURL = [parent retain];
    if (_uri == NULL) {
        return nil;
    }

    return self;
}

+ (NSURL*)fileURLWithPath:(id)path {
    return [[[self alloc] initFileURLWithPath:path] autorelease];
}

+ (NSURL*)fileURLWithPath:(id)path isDirectory:(BOOL)isDirectory {
    return [[[self alloc] initFileURLWithPath:path isDirectory:isDirectory] autorelease];
}

+ (NSURL*)URLWithString:(id)string {
    return [[[self alloc] initWithString:string] autorelease];
}

+ (NSURL*)URLWithString:(id)string relativeToURL:(id)parent {
    return [[[self alloc] initWithString:string relativeToURL:parent] autorelease];
}

- (void)dealloc {
    [_baseURL release];
    if (_uri)
        delete _uri;
    if (_fullUri)
        delete _fullUri;
    _absoluteString = nil;

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
        return murmurHash3(_fullUri->_path, strlen(_fullUri->_path), 0x834cba12);
    }
    return 0;
}

- (BOOL)isEqual:(id)other {
    NSURL* otherURL;

    if (self == other)
        return YES;

    if (![other isKindOfClass:[NSURL class]])
        return NO;

    otherURL = other;
    if (otherURL->_fullUri->_scheme && _fullUri->_scheme) {
        if (strcmp(otherURL->_fullUri->_scheme, _fullUri->_scheme) != 0)
            return NO;
    } else if (otherURL->_fullUri->_scheme != _fullUri->_scheme)
        return NO;

    if (otherURL->_fullUri->_server && _fullUri->_server) {
        if (strcmp(otherURL->_fullUri->_server, _fullUri->_server) != 0)
            return NO;
    } else if (otherURL->_fullUri->_server != _fullUri->_server)
        return NO;

    if (otherURL->_fullUri->_path && _fullUri->_path) {
        if (strcmp(otherURL->_fullUri->_path, _fullUri->_path) != 0)
            return NO;
    } else if (otherURL->_fullUri->_path != _fullUri->_path)
        return NO;

    if (otherURL->_fullUri->_parameters && _fullUri->_parameters) {
        if (strcmp(otherURL->_fullUri->_parameters, _fullUri->_parameters) != 0)
            return NO;
    } else if (otherURL->_fullUri->_parameters != _fullUri->_parameters)
        return NO;

    if (otherURL->_fullUri->_query && _fullUri->_query) {
        if (strcmp(otherURL->_fullUri->_query, _fullUri->_query) != 0)
            return NO;
    } else if (otherURL->_fullUri->_query != _fullUri->_query)
        return NO;

    if (otherURL->_fullUri->_fragment && _fullUri->_fragment) {
        if (strcmp(otherURL->_fullUri->_fragment, _fullUri->_fragment) != 0)
            return NO;
    } else if (otherURL->_fullUri->_fragment != _fullUri->_fragment)
        return NO;

    if (otherURL->_fullUri->_port != _fullUri->_port)
        return NO;

    return YES;
}

- (NSString*)relativeString {
    if (!_uri) {
        return [self absoluteString];
    } else {
        char* uriStr = (char*)xmlSaveUri(_uri->_uri);
        if (uriStr == NULL)
            return nil;
        id ret = [NSString stringWithCString:uriStr];
        xmlFree(uriStr);

        return ret;
    }
}

- (NSString*)absoluteString {
    if (_absoluteString == nil) {
        if (_fullUri) {
            char* uriStr = (char*)xmlSaveUri(_fullUri->_uri);
            if (uriStr == NULL)
                return nil;
            _absoluteString = [NSString stringWithCString:uriStr];
            xmlFree(uriStr);
        } else {
            char* uriStr = (char*)xmlSaveUri(_uri->_uri);
            if (uriStr == NULL)
                return nil;
            _absoluteString = [NSString stringWithCString:uriStr];
            xmlFree(uriStr);
        }
    }

    return (NSString*)_absoluteString;
}

- (NSString*)resourceSpecifier {
    char* uriStr = (char*)xmlSaveUri(_fullUri->_uri);
    if (uriStr == NULL)
        return nil;

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

- (NSString*)parameterString {
    if (!_fullUri->_parameters)
        return nil;

    id ret = [NSString stringWithCString:(char*)_fullUri->_parameters];

    return ret;
}

- (NSString*)scheme {
    if (!_fullUri)
        return nil;
    if (!_fullUri->_scheme)
        return nil;

    id ret = [NSString stringWithCString:(char*)_fullUri->_scheme];

    return ret;
}

- (NSString*)host {
    if (!_fullUri)
        return nil;

    if (!_fullUri->_server)
        return @"";

    id ret = [NSString stringWithCString:(char*)_fullUri->_server];

    return ret;
}

- (NSString*)fragment {
    if (!_fullUri->_fragment)
        return nil;

    id ret = [NSString stringWithCString:(char*)_fullUri->_fragment];

    return ret;
}

- (id)path {
    if (!_fullUri)
        return nil;
    if (!_fullUri->_path)
        return nil;

    id ret = [NSString stringWithCString:(char*)_fullUri->_path];

    return ret;
}

- (id)pathComponents {
    return [[self path] pathComponents];
}

- (id)port {
    if (_fullUri->_port == -1)
        return nil;

    return [NSNumber numberWithInt:_fullUri->_port];
}

- (id)query {
    if (!_fullUri->_query)
        return nil;

    id ret = [NSString stringWithCString:(char*)_fullUri->_query];

    return ret;
}

- (id)relativePath {
    if (!_uri->_path)
        return nil;

    id ret = [NSString stringWithCString:(char*)_uri->_path];

    return ret;
}

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

- (id)absoluteURL {
    if (_baseURL == nil)
        return self;

    return [NSURL URLWithString:[self absoluteString]];
}

- (id)standardizedURL {
    EbrDebugLog("standardizedURL needs attention\n");
    return [self copy];
}

- (id)lastPathComponent {
    return [[self path] lastPathComponent];
}

- (id)pathExtension {
    return [[self path] pathExtension];
}

- (id)baseURL {
    return _baseURL;
}

- (BOOL)setResourceValue:(id)value forKey:(id)key error:(NSError**)error {
    if (error)
        *error = nil;
    EbrDebugLog("NSURL::setResourceValue not supported\n");
    return TRUE;
}

//
@end
