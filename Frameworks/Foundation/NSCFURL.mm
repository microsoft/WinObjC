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

#import "NSCFURL.h"
#import "BridgeHelpers.h"
#import "NSPathUtilitiesInternal.h"
#import <CoreFoundation/CFURL.h>
#import <CFFoundationInternal.h>

#import <StubReturn.h>

@interface NSCFURL : NSURL
@end

#pragma region NSURLPrototype

@implementation NSURLPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSCFURL)

- (instancetype)initWithString:(NSString*)URLString relativeToURL:(NSURL*)baseURL {
    return reinterpret_cast<NSURLPrototype*>(
        static_cast<NSURL*>(CFURLCreateWithString(NULL, static_cast<CFStringRef>(URLString), static_cast<CFURLRef>(baseURL))));
}

- (instancetype)initFileURLWithPath:(NSString*)path isDirectory:(BOOL)isDir {
    return reinterpret_cast<NSURLPrototype*>(
        static_cast<NSURL*>(CFURLCreateWithFileSystemPath(NULL, static_cast<CFStringRef>(path), kCFURLWindowsPathStyle, isDir)));
}

- (instancetype)initByResolvingBookmarkData:(NSData*)bookmarkData
                                    options:(NSURLBookmarkResolutionOptions)options
                              relativeToURL:(NSURL*)relativeURL
                        bookmarkDataIsStale:(BOOL*)isStale
                                      error:(NSError* _Nullable*)error {
    // TODO: 7491994: CFURL BookmarkData functions are unimplemented
    Boolean isStaleTemp;
    auto ret = reinterpret_cast<NSURLPrototype*>(
        static_cast<NSURL*>(CFURLCreateByResolvingBookmarkData(NULL,
                                                               static_cast<CFDataRef>(bookmarkData),
                                                               static_cast<CFURLBookmarkResolutionOptions>(options),
                                                               static_cast<CFURLRef>(relativeURL),
                                                               NULL,
                                                               &isStaleTemp,
                                                               reinterpret_cast<CFErrorRef*>(error))));

    if (isStale) {
        *isStale = isStaleTemp ? YES : NO;
    }

    return ret;
}

- (instancetype)initFileURLWithFileSystemRepresentation:(const char*)path isDirectory:(BOOL)isDir relativeToURL:(NSURL*)baseURL {
    return reinterpret_cast<NSURLPrototype*>(static_cast<NSURL*>(CFURLCreateFromFileSystemRepresentationRelativeToBase(
        NULL, reinterpret_cast<const uint8_t*>(path), strlen(path), isDir, static_cast<CFURLRef>(baseURL))));
}

@end

#pragma endregion

#pragma region NSCFURL
@implementation NSCFURL

BRIDGED_CLASS_REQUIRED_IMPLS(CFURLRef, CFURLGetTypeID, NSURL, NSCFURL)

- (BOOL)getFileSystemRepresentation:(char*)buffer maxLength:(NSUInteger)maxBufferLength {
    return CFURLGetFileSystemRepresentation(static_cast<CFURLRef>(self), true, reinterpret_cast<uint8_t*>(buffer), maxBufferLength);
}

- (BOOL)isFileReferenceURL {
    return CFURLIsFileReferenceURL(static_cast<CFURLRef>(self));
}

- (NSURL*)absoluteURL {
    return [static_cast<NSURL*>(CFURLCopyAbsoluteURL(static_cast<CFURLRef>(self))) autorelease];
}

- (NSURL*)baseURL {
    return static_cast<NSURL*>(CFURLGetBaseURL(static_cast<CFURLRef>(self)));
}

- (NSString*)fragment {
    return [static_cast<NSString*>(CFURLCopyFragment(static_cast<CFURLRef>(self), NULL)) autorelease];
}

- (NSString*)host {
    return [static_cast<NSString*>(CFURLCopyHostName(static_cast<CFURLRef>(self))) autorelease];
}

- (NSString*)lastPathComponent {
    if ([self baseURL]) {
        // Concatenate to absolute URL before returning a value
        return [[self absoluteURL] lastPathComponent];
    } else {
        // CF behavior diverges from NS behavior here on the reference platform -
        // NS seems to return nil instead of empty string when there is no path
        NSString* ret = nil;
        if ([self path]) {
            ret = [static_cast<NSString*>(CFURLCopyLastPathComponent(static_cast<CFURLRef>(self))) autorelease];
        }
        return ret;
    }
}

- (NSString*)parameterString {
    return [static_cast<NSString*>(CFURLCopyParameterString(static_cast<CFURLRef>(self), NULL)) autorelease];
}

- (NSString*)password {
    return [static_cast<NSString*>(_CFURLCopyPasswordNotUnescaped(static_cast<CFURLRef>(self))) autorelease];
}

- (NSString*)path {
    if ([self baseURL]) {
        // Concatenate to absolute URL before returning a value
        return [[self absoluteURL] path];
    } else {
        NSString* ret = [static_cast<NSString*>(CFURLCopyPath(static_cast<CFURLRef>(self))) autorelease];

        // If the path has a trailing slash and the string is not length 1, it is stripped
        if ([ret hasSuffix:_NSGetSlashStr()] && [ret length] > 1) {
            ret = [ret substringToIndex:[ret length] - 1];
        }

        // CF version of this function doesn't unescape percent-encoded chars, while NS does
        ret = [ret stringByRemovingPercentEncoding];

        // Remove slashes from before drives
        if ([ret length] >= 3 && ([ret hasPrefix:_NSGetSlashStr()]) && (_isLetter([ret characterAtIndex:1])) && ([ret characterAtIndex:2] == ':')) {
            ret = [ret substringFromIndex:1];
        }

        // Add a slash after drive
        if (([ret length] == 2) && (_isLetter([ret characterAtIndex:0])) && ([ret characterAtIndex:1] == ':')) {
            ret = [ret stringByAppendingString:_NSGetSlashStr()];
        }

        return ret;
    }
}

- (NSString*)pathExtension {
    // CF behavior diverges from NS behavior on the reference platform
    // 1) NS can return nil if there is no last path component
    // 2) NS returns an empty string if the extension is the entire last path component (eg: file:///a/b/.g returns 'g' in CF but '' in NS)
    NSString* lastPathComponent = [self lastPathComponent];
    if (lastPathComponent) {
        NSRange range = [lastPathComponent rangeOfString:@"." options:NSBackwardsSearch];
        if ((range.location != NSNotFound) && (range.location > 0)) {
            return [lastPathComponent substringFromIndex:range.location + range.length];
        } else {
            return @"";
        }
    } else {
        return nil;
    }
}

- (NSNumber*)port {
    // CF returns -1 if there is no port, whereas this returns nil
    int32_t port = CFURLGetPortNumber(static_cast<CFURLRef>(self));
    return (port >= 0) ? [NSNumber numberWithInt:port] : nil;
}

- (NSString*)query {
    return [static_cast<NSString*>(CFURLCopyQueryString(static_cast<CFURLRef>(self), NULL)) autorelease];
}

- (NSString*)relativeString {
    return static_cast<NSString*>(CFURLGetString(static_cast<CFURLRef>(self)));
}

- (NSString*)resourceSpecifier {
    // If the receiver does not specify a net location portion of the URL, as returned by the toll-free bridged CFURL function
    // CFURLCopyNetLocation, then this method returns only the path of the receiver.
    // For example, in the URL file:///file.txt, the resource specifier is /file.txt.
    CFStringRef netLocation = CFURLCopyNetLocation(static_cast<CFURLRef>(self));
    CFAutorelease(netLocation);

    if (netLocation) {
        // CF behavior diverges from NS behavior on the ref platform -
        // CF would return null for file://localhost/usr/local/bin here, whereas NS would return //localhost/usr/local/bin
        // Get the section after the scheme
        NSString* relativeString = [self relativeString];
        NSRange range = [relativeString rangeOfString:[self scheme]];
        if (range.location != NSNotFound) {
            // + 1 for ":" in "scheme:"
            return [relativeString substringFromIndex:range.location + range.length + 1];
        } else {
            return relativeString;
        }
    } else {
        // Use CFURLCopyPath rather than [self path] here - resourceSpecifier should not unescape, whereas [self path] does
        // (CFURLCopyPath does not unescape)
        NSString* path = [static_cast<NSString*>(CFURLCopyPath(static_cast<CFURLRef>(self))) autorelease];

        // Return everything in the path and after
        if (path) {
            NSString* relativeString = [self relativeString];
            NSRange range = [relativeString rangeOfString:path options:NSBackwardsSearch];
            if (range.location != NSNotFound) {
                return [relativeString substringFromIndex:range.location];
            } else {
                return nil;
            }
        } else {
            return [static_cast<NSString*>(CFURLCopyResourceSpecifier(static_cast<CFURLRef>(self))) autorelease];
        }
    }
}

- (NSString*)scheme {
    return [static_cast<NSString*>(CFURLCopyScheme(static_cast<CFURLRef>(self))) autorelease];
}

- (NSString*)user {
    return [static_cast<NSString*>(CFURLCopyUserName(static_cast<CFURLRef>(self))) autorelease];
}

- (NSURL*)fileReferenceURL {
    return [static_cast<NSURL*>(CFURLCreateFileReferenceURL(NULL, static_cast<CFURLRef>(self), NULL)) autorelease];
}

- (NSURL*)URLByAppendingPathComponent:(NSString*)pathComponent isDirectory:(BOOL)isDirectory {
    return [static_cast<NSURL*>(
        CFURLCreateCopyAppendingPathComponent(NULL, static_cast<CFURLRef>(self), static_cast<CFStringRef>(pathComponent), isDirectory))
        autorelease];
}

- (NSURL*)URLByAppendingPathExtension:(NSString*)pathExtension {
    return [static_cast<NSURL*>(
        CFURLCreateCopyAppendingPathExtension(NULL, static_cast<CFURLRef>(self), static_cast<CFStringRef>(pathExtension))) autorelease];
}

- (NSURL*)URLByDeletingLastPathComponent {
    return [static_cast<NSURL*>(CFURLCreateCopyDeletingLastPathComponent(NULL, static_cast<CFURLRef>(self))) autorelease];
}

- (NSURL*)URLByDeletingPathExtension {
    return [static_cast<NSURL*>(CFURLCreateCopyDeletingPathExtension(NULL, static_cast<CFURLRef>(self))) autorelease];
}

@end

#pragma endregion