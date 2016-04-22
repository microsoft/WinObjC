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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Starboard.h>
#import "NSPathUtilitiesInternal.h"

#import <Foundation/NSData.h>
#import <Foundation/NSFileManager.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSString.h>
#import <Foundation/NSURL.h>

#import "CFFoundationInternal.h"

NSString* _NSGetSlashStr() {
    static StrongId<NSString> s_slashStr = static_cast<NSString*>(_CFGetSlashStr());
    return s_slashStr;
}

NSString* _stringFromDataWithEncoding(NSString* self, NSData* data, NSStringEncoding encoding) {
    if (!data) {
        return nil;
    }

    if (encoding == NSUnicodeStringEncoding) {
        // Check BOM (Byte Order Marker) to determine endian-ness.
        const unichar* unicodeCharacters = reinterpret_cast<const unichar*>([data bytes]);
        unsigned int length = [data length];

        if (length > sizeof(unichar) && unicodeCharacters[0] == 0xFEFF) {
            return [self initWithBytes:&unicodeCharacters[1] length:(length - sizeof(unichar)) encoding:NSUnicodeStringEncoding];
        } else if (length > sizeof(unichar) && unicodeCharacters[0] == 0xFFFE) {
            return [self initWithBytes:&unicodeCharacters[1] length:(length - sizeof(unichar)) encoding:NSUTF16BigEndianStringEncoding];
        } else {
            // No BOM. Assume normal UTF-16
            return [self initWithBytes:&unicodeCharacters[0] length:(length) encoding:NSUnicodeStringEncoding];
        }
    } else if (encoding == NSUTF32StringEncoding) {
        // Check BOM to determine endianness.
        const uint32_t* unicodeCharacters = reinterpret_cast<const uint32_t*>([data bytes]);
        unsigned int length = [data length];

        if (length > sizeof(unichar) && unicodeCharacters[0] == 0x0000FEFF) {
            return [self initWithBytes:&unicodeCharacters[1] length:(length - sizeof(uint32_t)) encoding:NSUTF32StringEncoding];
        } else if (length > sizeof(unichar) && unicodeCharacters[0] == 0xFFFE0000) {
            return [self initWithBytes:&unicodeCharacters[1] length:(length - sizeof(uint32_t)) encoding:NSUTF32BigEndianStringEncoding];
        } else {
            // No BOM. Assume normal UTF-32
            return [self initWithBytes:&unicodeCharacters[0] length:(length) encoding:NSUTF32StringEncoding];
        }
    }

    return [self initWithData:data encoding:[NSString defaultCStringEncoding]];
}

NSString* _stringFromDataByDeterminingEncoding(NSString* self, NSData* data, NSStringEncoding* usedEncoding) {
    if (!data) {
        return nil;
    }

    NSStringEncoding encoding = [NSString defaultCStringEncoding];
    const void* bytes = [data bytes];
    const unichar* unicodeCharacters = reinterpret_cast<const unichar*>(bytes);
    unsigned int length = [data length];

    if (length > sizeof(unichar) && unicodeCharacters[0] == 0xFEFF) {
        bytes = &unicodeCharacters[1];
        encoding = NSUnicodeStringEncoding;
        length = length - sizeof(unichar);
    } else if (length > sizeof(unichar) && unicodeCharacters[0] == 0xFFFE) {
        bytes = &unicodeCharacters[1];
        encoding = NSUTF16BigEndianStringEncoding;
        length = length - sizeof(unichar);
    }

    if (usedEncoding) {
        *usedEncoding = encoding;
    }

    return [self initWithBytes:bytes length:length encoding:encoding];
}

NSString* _longestCommonPrefix(NSArray* strings, BOOL caseSensitive) {
    if (strings == nil || [strings count] == 0) {
        return nil;
    } else if ([strings count] == 1) {
        return strings[0];
    }

    NSString* firstString = strings[0];

    NSString* stringToUse = caseSensitive ? firstString : firstString.lowercaseString;
    unsigned int i;
    for (i = 0; i < [stringToUse length]; i++) {
        bool shouldContinue = true;
        for (NSString* string in strings) {
            NSString* stringToCompare = caseSensitive ? string : string.lowercaseString;
            if ([stringToUse characterAtIndex:i] != [stringToCompare characterAtIndex:i]) {
                shouldContinue = false;
                break;
            }
        }

        if (!shouldContinue) {
            break;
        }
    }

    return [strings[0] substringToIndex:i];
}

NSString* _ensureLastPathSeparator(NSString* path) {
    if (path == nil || [path hasSuffix:_NSGetSlashStr()] || [path isEqualToString:@""]) {
        return path;
    }

    return [path stringByAppendingString:_NSGetSlashStr()];
}

BOOL _stringIsPathToDirectory(NSString* path) {
    if (![path hasSuffix:_NSGetSlashStr()]) {
        return NO;
    }

    BOOL isDirectory = NO;
    BOOL exists = [[NSFileManager defaultManager] fileExistsAtPath:path isDirectory:&isDirectory];

    return exists && isDirectory;
}

BOOL _stringLooksLikeOrIsPathToDirectory(NSString* path) {
    if ([path hasSuffix:_NSGetSlashStr()]) {
        return YES;
    }

    BOOL isDirectory = NO;
    BOOL exists = [[NSFileManager defaultManager] fileExistsAtPath:path isDirectory:&isDirectory];

    return exists && isDirectory;
}

FilePathPredicate _getFileNamePredicate(NSString* thePrefix, BOOL caseSensitive) {
    if (!thePrefix) {
        return ^(NSString*) {
            return true;
        };
    }

    if (caseSensitive) {
        return Block_copy(^(NSString* input) {
            return input != nil && [input hasPrefix:thePrefix];
        });
    } else {
        return Block_copy(^(NSString* input) {
            return (input != nil) && ([input rangeOfString:thePrefix
                                                   options:(NSCaseInsensitiveSearch | NSAnchoredSearch)
                                                     range:NSMakeRange(0, [thePrefix length])]
                                          .location != NSNotFound);
        });
    }
}

FilePathPredicate _getExtensionPredicate(NSArray* exts, BOOL caseSensitive) {
    if (!exts) {
        return Block_copy(^(NSString*) {
            return true;
        });
    }

    if (caseSensitive) {
        NSSet* set = [NSSet setWithArray:exts];
        return Block_copy(^(NSString* input) {
            return input != nil && [set containsObject:input];
        });
    } else {
        NSMutableArray* lowerCaseExts = [NSMutableArray arrayWithCapacity:[exts count]];
        for (NSString* string in exts) {
            [lowerCaseExts addObject:[string lowercaseString]];
        }

        NSSet* set = [NSSet setWithArray:lowerCaseExts];
        return Block_copy(^(NSString* input) {
            return input != nil && [set containsObject:[input lowercaseString]];
        });
    }
}

NSMutableArray* _getNamesAtURL(NSURL* filePathURL,
                               NSString* prependWith,
                               FilePathPredicate namePredicate,
                               FilePathPredicate typePredicate) {
    NSMutableArray* result = [NSMutableArray array];
    NSEnumerator* enumerator = [[NSFileManager defaultManager] enumeratorAtURL:filePathURL
                                                    includingPropertiesForKeys:nil
                                                                       options:NSDirectoryEnumerationSkipsSubdirectoryDescendants
                                                                  errorHandler:nil];
    if (enumerator != nil) {
        for (NSURL* item in enumerator) {
            NSString* itemName = [item lastPathComponent];

            if (typePredicate([item pathExtension]) && namePredicate(itemName)) {
                if (prependWith == nil || [prependWith isEqual:@""]) {
                    [result addObject:itemName];
                } else {
                    [result addObject:[prependWith stringByAppendingPathComponent:itemName]];
                }
            }
        }
    }

    return result;
}

BOOL _isLetter(unichar character) {
    return ((character >= 'A') && (character <= 'Z')) || ((character >= 'a') && (character <= 'z'));
}