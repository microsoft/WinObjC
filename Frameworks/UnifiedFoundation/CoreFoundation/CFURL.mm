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

#import "CoreFoundation/CoreFoundation.h"
#import "Starboard.h"
#import <algorithm>
#import <memory>

const CFStringRef kCFURLNameKey = CFSTR("");
const CFStringRef kCFURLLocalizedNameKey = CFSTR("");
const CFStringRef kCFURLPathKey = CFSTR("");
const CFStringRef kCFURLIsRegularFileKey = CFSTR("");
const CFStringRef kCFURLIsDirectoryKey = CFSTR("");
const CFStringRef kCFURLIsSymbolicLinkKey = CFSTR("");
const CFStringRef kCFURLIsVolumeKey = CFSTR("");
const CFStringRef kCFURLIsPackageKey = CFSTR("");
const CFStringRef kCFURLIsSystemImmutableKey = CFSTR("");
const CFStringRef kCFURLIsUserImmutableKey = CFSTR("");
const CFStringRef kCFURLIsHiddenKey = CFSTR("");
const CFStringRef kCFURLHasHiddenExtensionKey = CFSTR("");
const CFStringRef kCFURLCreationDateKey = CFSTR("");
const CFStringRef kCFURLContentAccessDateKey = CFSTR("");
const CFStringRef kCFURLContentModificationDateKey = CFSTR("");
const CFStringRef kCFURLAttributeModificationDateKey = CFSTR("");
const CFStringRef kCFURLLinkCountKey = CFSTR("");
const CFStringRef kCFURLParentDirectoryURLKey = CFSTR("");
const CFStringRef kCFURLVolumeURLKey = CFSTR("");
const CFStringRef kCFURLTypeIdentifierKey = CFSTR("");
const CFStringRef kCFURLLocalizedTypeDescriptionKey = CFSTR("");
const CFStringRef kCFURLLabelNumberKey = CFSTR("");
const CFStringRef kCFURLLabelColorKey = CFSTR("");
const CFStringRef kCFURLLocalizedLabelKey = CFSTR("");
const CFStringRef kCFURLEffectiveIconKey = CFSTR("");
const CFStringRef kCFURLCustomIconKey = CFSTR("");
const CFStringRef kCFURLFileResourceIdentifierKey = CFSTR("");
const CFStringRef kCFURLVolumeIdentifierKey = CFSTR("");
const CFStringRef kCFURLPreferredIOBlockSizeKey = CFSTR("");
const CFStringRef kCFURLIsReadableKey = CFSTR("");
const CFStringRef kCFURLIsWritableKey = CFSTR("");
const CFStringRef kCFURLIsExecutableKey = CFSTR("");
const CFStringRef kCFURLFileSecurityKey = CFSTR("");
const CFStringRef kCFURLIsExcludedFromBackupKey = CFSTR("");
const CFStringRef kCFURLFileResourceTypeKey = CFSTR("");
const CFStringRef kCFURLFileResourceTypeBlockSpecial = CFSTR("");
const CFStringRef kCFURLFileResourceTypeCharacterSpecial = CFSTR("");
const CFStringRef kCFURLFileResourceTypeDirectory = CFSTR("");
const CFStringRef kCFURLFileResourceTypeNamedPipe = CFSTR("");
const CFStringRef kCFURLFileResourceTypeRegular = CFSTR("");
const CFStringRef kCFURLFileResourceTypeSocket = CFSTR("");
const CFStringRef kCFURLFileResourceTypeSymbolicLink = CFSTR("");
const CFStringRef kCFURLFileResourceTypeUnknown = CFSTR("");
const CFStringRef kCFURLFileAllocatedSizeKey = CFSTR("");
const CFStringRef kCFURLFileSizeKey = CFSTR("");
const CFStringRef kCFURLIsAliasFileKey = CFSTR("");
const CFStringRef kCFURLIsMountTriggerKey = CFSTR("");
const CFStringRef kCFURLTotalFileAllocatedSizeKey = CFSTR("");
const CFStringRef kCFURLTotalFileSizeKey = CFSTR("");
const CFStringRef kCFURLIsUbiquitousItemKey = CFSTR("");
const CFStringRef kCFURLUbiquitousItemHasUnresolvedConflictsKey = CFSTR("");
const CFStringRef kCFURLUbiquitousItemIsDownloadedKey = CFSTR("");
const CFStringRef kCFURLUbiquitousItemIsDownloadingKey = CFSTR("");
const CFStringRef kCFURLUbiquitousItemIsUploadedKey = CFSTR("");
const CFStringRef kCFURLUbiquitousItemIsUploadingKey = CFSTR("");
const CFStringRef kCFURLUbiquitousItemPercentDownloadedKey = CFSTR("");
const CFStringRef kCFURLUbiquitousItemPercentUploadedKey = CFSTR("");
const CFStringRef kCFURLVolumeNameKey = CFSTR("");
const CFStringRef kCFURLVolumeLocalizedNameKey = CFSTR("");
const CFStringRef kCFURLVolumeLocalizedFormatDescriptionKey = CFSTR("");
const CFStringRef kCFURLVolumeTotalCapacityKey = CFSTR("");
const CFStringRef kCFURLVolumeAvailableCapacityKey = CFSTR("");
const CFStringRef kCFURLVolumeResourceCountKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsSymbolicLinksKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsHardLinksKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsJournalingKey = CFSTR("");
const CFStringRef kCFURLVolumeIsJournalingKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsSparseFilesKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsZeroRunsKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsCaseSensitiveNamesKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsCasePreservedNamesKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsRootDirectoryDatesKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsVolumeSizesKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsRenamingKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsAdvisoryFileLockingKey = CFSTR("");
const CFStringRef kCFURLVolumeSupportsExtendedSecurityKey = CFSTR("");
const CFStringRef kCFURLVolumeIsBrowsableKey = CFSTR("");
const CFStringRef kCFURLVolumeMaximumFileSizeKey = CFSTR("");
const CFStringRef kCFURLVolumeIsEjectableKey = CFSTR("");
const CFStringRef kCFURLVolumeIsRemovableKey = CFSTR("");
const CFStringRef kCFURLVolumeIsInternalKey = CFSTR("");
const CFStringRef kCFURLVolumeIsAutomountedKey = CFSTR("");
const CFStringRef kCFURLVolumeIsLocalKey = CFSTR("");
const CFStringRef kCFURLVolumeIsReadOnlyKey = CFSTR("");
const CFStringRef kCFURLVolumeCreationDateKey = CFSTR("");
const CFStringRef kCFURLVolumeURLForRemountingKey = CFSTR("");
const CFStringRef kCFURLVolumeUUIDStringKey = CFSTR("");
const CFStringRef kCFURLKeysOfUnsetValuesKey = CFSTR("");

// Won't work so great with continuations... FIXME sometime

static bool charInNSString(CFStringRef str, short ch) {
    unsigned length = [(NSString*)str length];
    if (length == 0) {
        return false;
    }

    const char* cstring = [(NSString*)str UTF8String];
    for (size_t i = 0; i < length; ++i) {
        if (cstring[i] == ch) {
            return true;
        }
    }
    return false;
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCopyAbsoluteURL(CFURLRef relativeURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateAbsoluteURLWithBytes(CFAllocatorRef alloc,
                                         const UInt8* relativeURLBytes,
                                         CFIndex length,
                                         CFStringEncoding encoding,
                                         CFURLRef baseURL,
                                         Boolean useCompatibilityMode) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateByResolvingBookmarkData(CFAllocatorRef allocator,
                                            CFDataRef bookmark,
                                            CFURLBookmarkResolutionOptions options,
                                            CFURLRef relativeToURL,
                                            CFArrayRef resourcePropertiesToInclude,
                                            Boolean* isStale,
                                            CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateCopyAppendingPathComponent(CFAllocatorRef allocator, CFURLRef url, CFStringRef pathComponent, Boolean isDirectory) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateCopyAppendingPathExtension(CFAllocatorRef allocator, CFURLRef url, CFStringRef extension) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateCopyDeletingLastPathComponent(CFAllocatorRef allocator, CFURLRef url) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateCopyDeletingPathExtension(CFAllocatorRef allocator, CFURLRef url) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateFilePathURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateFileReferenceURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateFromFileSystemRepresentation(CFAllocatorRef allocator, const UInt8* buffer, CFIndex bufLen, Boolean isDirectory) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateFromFileSystemRepresentationRelativeToBase(
    CFAllocatorRef allocator, const UInt8* buffer, CFIndex bufLen, Boolean isDirectory, CFURLRef baseURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateFromFSRef(CFAllocatorRef allocator, const struct FSRef* fsRef) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateWithBytes(
    CFAllocatorRef allocator, const UInt8* URLBytes, CFIndex length, CFStringEncoding encoding, CFURLRef baseURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateWithFileSystemPath(CFAllocatorRef allocator, CFStringRef filePath, CFURLPathStyle pathStyle, Boolean isDirectory) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateWithFileSystemPathRelativeToBase(
    CFAllocatorRef allocator, CFStringRef filePath, CFURLPathStyle pathStyle, Boolean isDirectory, CFURLRef baseURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLCreateWithString(CFAllocatorRef allocator, CFStringRef URLString, CFURLRef baseURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLCanBeDecomposed(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyFileSystemPath(CFURLRef anURL, CFURLPathStyle pathStyle) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyFragment(CFURLRef anURL, CFStringRef charactersToLeaveEscaped) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyHostName(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyLastPathComponent(CFURLRef url) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyNetLocation(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyParameterString(CFURLRef anURL, CFStringRef charactersToLeaveEscaped) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyPassword(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Interoperable
*/
CFStringRef CFURLCopyPath(CFURLRef url) {
    return (CFStringRef)[[url path] retain];
}

/**
 @Status Interoperable
*/
CFStringRef CFURLCopyPathExtension(CFURLRef url) {
    return (CFStringRef)[[url pathExtension] retain];
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyQueryString(CFURLRef anURL, CFStringRef charactersToLeaveEscaped) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyResourceSpecifier(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyScheme(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyStrictPath(CFURLRef anURL, Boolean* isAbsolute) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLCopyUserName(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
SInt32 CFURLGetPortNumber(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLHasDirectoryPath(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CFURLCreateData(CFAllocatorRef allocator, CFURLRef url, CFStringEncoding encoding, Boolean escapeWhitespace) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Interoperable
*/
CFStringRef CFURLCreateStringByAddingPercentEscapes(CFAllocatorRef allocator,
                                                    CFStringRef origString,
                                                    CFStringRef charactersToLeaveUnescaped,
                                                    CFStringRef legalURLCharactersToBeEscaped,
                                                    CFStringEncoding encoding) {
    const char* utf8String = [(NSString*)origString UTF8String];

    NSUInteger length = [(NSString*)origString lengthOfBytesUsingEncoding:CFStringConvertEncodingToNSStringEncoding(encoding)];
    NSUInteger resultLength = 0;
    char* result = (char*)EbrMalloc(length * 3 * 2 + 1);

    const char hex[] = "0123456789ABCDEF";
    const char legalURLCharacters[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmno"
        "pqrstuvwxyz0123456789-._~:/"
        "?@!$&'()*+,;="
    };

    for (size_t i = 0; i < length; ++i) {
        char code = utf8String[i];

        bool legalCharacter = charInNSString(charactersToLeaveUnescaped, code);

        for (size_t n = 0; n < sizeof(legalURLCharacters) && !legalCharacter; ++n) {
            if (code == legalURLCharacters[n] && !charInNSString(legalURLCharactersToBeEscaped, code)) {
                legalCharacter = true;
            }
        }

        if (!legalCharacter) {
            result[resultLength++] = '%';
            result[resultLength++] = hex[(code >> 4) & 0xF];
            result[resultLength++] = hex[code & 0xF];
        } else {
            result[resultLength++] = code;
        }
    }

    NSString* ret;
    if (length == resultLength) {
        EbrFree(result);
        ret = [(NSString*)origString retain];
    } else {
        result[resultLength] = 0;

        ret = [[NSString alloc] initWithCString:result];
        EbrFree(result);
    }

    return (__bridge CFStringRef)ret;
}

/**
 @Status Interoperable
*/
CFStringRef CFURLCreateStringByReplacingPercentEscapes(CFAllocatorRef allocator, CFStringRef string, CFStringRef charactersToLeaveEscaped) {
    return CFURLCreateStringByReplacingPercentEscapesUsingEncoding(allocator, string, charactersToLeaveEscaped, kCFStringEncodingUTF8);
}

/**
 @Status Caveat
 @Notes Only UTF-8 is supported
*/
CFStringRef CFURLCreateStringByReplacingPercentEscapesUsingEncoding(CFAllocatorRef allocator,
                                                                    CFStringRef string,
                                                                    CFStringRef charactersToLeaveEscaped,
                                                                    CFStringEncoding encoding) {
    if (encoding != kCFStringEncodingUTF8) {
        UNIMPLEMENTED_WITH_MSG("Only UTF-8 is supported.");
        return { 0 };
    }

    NSUInteger length = [(NSString*)string length];
    NSUInteger resultLength = 0;

    const unichar* buffer = [(NSString*)string rawCharacters];
    std::unique_ptr<unichar[]> result(new unichar[length * 2]);
    unichar firstCharacter = 0;
    unichar firstNibble = 0;

    enum {
        STATE_NORMAL,
        STATE_PERCENT,
        STATE_HEX1,
    } state = STATE_NORMAL;

    // Unescape the charactersToLeaveEscaped
    // This can only recurse a maximum of once, since nullptr is passed for characters to leave escaped
    NSString* escapedStringToIgnore =
        charactersToLeaveEscaped ?
            (NSString*)CFURLCreateStringByReplacingPercentEscapes(nullptr, (CFStringRef)charactersToLeaveEscaped, nullptr) :
            nil;
    // Will be nil if escapedStringToIgnore is nil
    const unichar* escapedCharsToIgnore = [escapedStringToIgnore rawCharacters];
    const unichar* escapedCharsToIgnoreEnd = escapedCharsToIgnore ? escapedCharsToIgnore + [escapedStringToIgnore length] : nullptr;

    for (NSUInteger i = 0; i < length; i++) {
        unichar check = buffer[i];

        switch (state) {
            case STATE_NORMAL:
                if (check == '%')
                    state = STATE_PERCENT;
                else
                    result[resultLength++] = check;
                break;

            case STATE_PERCENT:
                state = STATE_HEX1;
                if (check >= '0' && check <= '9') {
                    firstCharacter = check;
                    firstNibble = (firstCharacter - '0');
                } else if (check >= 'a' && check <= 'f') {
                    firstCharacter = check;
                    firstNibble = (firstCharacter - 'a') + 10;
                } else if (check >= 'A' && check <= 'F') {
                    firstCharacter = check;
                    firstNibble = (firstCharacter - 'A') + 10;
                } else {
                    result[resultLength++] = '%';
                    result[resultLength++] = check;
                    state = STATE_NORMAL;
                }
                break;

            case STATE_HEX1:
                // Cache the result to first check if the unencoding needs to occur
                unichar resultChar;
                bool resultCharInitialized;

                if (check >= '0' && check <= '9') {
                    resultChar = firstNibble * 16 + check - '0';
                    resultCharInitialized = true;

                } else if (check >= 'a' && check <= 'f') {
                    resultChar = firstNibble * 16 + (check - 'a') + 10;
                    resultCharInitialized = true;

                } else if (check >= 'A' && check <= 'F') {
                    resultChar = firstNibble * 16 + (check - 'A') + 10;
                    resultCharInitialized = true;
                }

                // If resultCharInitialized
                //      If no escapedCharsToIgnore OR
                //      If escapedCharsToIgnore AND resultChar not in escapedCharsToIgnore
                if (resultCharInitialized &&
                    (!escapedCharsToIgnore ||
                     std::find(escapedCharsToIgnore, escapedCharsToIgnoreEnd, resultChar) == escapedCharsToIgnoreEnd)) {
                    result[resultLength++] = resultChar;
                } else {
                    result[resultLength++] = '%';
                    result[resultLength++] = firstCharacter;
                    result[resultLength++] = check;
                }
                state = STATE_NORMAL;
                break;
        }
    }

    [escapedStringToIgnore release];

    if (resultLength == length) {
        return (CFStringRef)CFRetain(string);
    }

    NSString* ret = [NSString stringWithCharacters:result.get() length:resultLength];

    return (CFStringRef)[ret retain];
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLGetFileSystemRepresentation(CFURLRef url, Boolean resolveAgainstBase, UInt8* buffer, CFIndex maxBufLen) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLGetFSRef(CFURLRef url, struct FSRef* fsRef) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CFURLGetString(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFURLRef CFURLGetBaseURL(CFURLRef anURL) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFIndex CFURLGetBytes(CFURLRef url, UInt8* buffer, CFIndex bufferLength) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFRange CFURLGetByteRangeForComponent(CFURLRef url, CFURLComponentType component, CFRange* rangeIncludingSeparators) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CFURLGetTypeID() {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLResourceIsReachable(CFURLRef url, CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
void CFURLClearResourcePropertyCache(CFURLRef url) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFURLClearResourcePropertyCacheForKey(CFURLRef url, CFStringRef key) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CFURLCopyResourcePropertiesForKeys(CFURLRef url, CFArrayRef keys, CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLCopyResourcePropertyForKey(CFURLRef url, CFStringRef key, void* propertyValueTypeRefPtr, CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CFURLCreateResourcePropertiesForKeysFromBookmarkData(CFAllocatorRef allocator,
                                                                     CFArrayRef resourcePropertiesToReturn,
                                                                     CFDataRef bookmark) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFTypeRef CFURLCreateResourcePropertyForKeyFromBookmarkData(CFAllocatorRef allocator, CFStringRef resourcePropertyKey, CFDataRef bookmark) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLSetResourcePropertiesForKeys(CFURLRef url, CFDictionaryRef keyedPropertyValues, CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLSetResourcePropertyForKey(CFURLRef url, CFStringRef key, CFTypeRef propertyValue, CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
void CFURLSetTemporaryResourcePropertyForKey(CFURLRef url, CFStringRef key, CFTypeRef propertyValue) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CFURLCreateBookmarkData(CFAllocatorRef allocator,
                                  CFURLRef url,
                                  CFURLBookmarkCreationOptions options,
                                  CFArrayRef resourcePropertiesToInclude,
                                  CFURLRef relativeToURL,
                                  CFErrorRef* error) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CFURLCreateBookmarkDataFromFile(CFAllocatorRef allocator, CFURLRef fileURL, CFErrorRef* errorRef) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLWriteBookmarkDataToFile(CFDataRef bookmarkRef,
                                     CFURLRef fileURL,
                                     CFURLBookmarkFileCreationOptions options,
                                     CFErrorRef* errorRef) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
Boolean CFURLStartAccessingSecurityScopedResource(CFURLRef url) {
    UNIMPLEMENTED();
    return { 0 };
}

/**
 @Status Stub
 @Notes
*/
void CFURLStopAccessingSecurityScopedResource(CFURLRef url) {
    UNIMPLEMENTED();
}
