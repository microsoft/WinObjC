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

#import "Starboard.h"
#import "StubReturn.h"
#import <algorithm>
#import <memory>
#import <string>
#import "Foundation/NSMutableData.h"
#import "Foundation/NSError.h"
#import "Foundation/NSScanner.h"
#import "Foundation/NSString.h"
#import "Foundation/NSMutableArray.h"
#import "Foundation/NSValue.h"
#import <CoreFoundation/CFData.h>
#import <UWP/WindowsStorageStreams.h>
#import <UWP/WindowsSecurityCryptography.h>
#include <COMIncludes.h>
#import "ErrorHandling.h"
#import "RawBuffer.h"
#import <wrl\wrappers\corewrappers.h>
#import <windows.security.cryptography.h>
#import <windows.storage.streams.h>
#include <COMIncludes_End.h>
#import <string>
#import <sstream>
#import <iomanip>
#import "NSCFData.h"
#import "NSRaise.h"
#import "StringHelpers.h"
#import "LoggingNative.h"

static const wchar_t* TAG = L"NSData";

using namespace Microsoft::WRL;
using namespace ABI::Windows::Security::Cryptography;
using namespace ABI::Windows::Storage::Streams;
using namespace Windows::Foundation;

// TODO: BUG 192601: Enable ARC on this file once the code gen error is fixed

@implementation NSData

BASE_CLASS_REQUIRED_IMPLS(NSData, NSDataPrototype, CFDataGetTypeID);

/**
 @Status Interoperable
*/
- (NSString*)base64EncodedStringWithOptions:(NSDataBase64EncodingOptions)options {
    ComPtr<IBuffer> wrlBuffer;
    IBuffer* rawBuffer = nullptr;
    HRESULT result;

    result = BufferFromRawData(&rawBuffer, const_cast<byte*>(reinterpret_cast<const byte*>([self bytes])), [self length]);

    if (FAILED(result)) {
        return nil;
    }

    wrlBuffer.Attach(rawBuffer);

    ComPtr<ICryptographicBufferStatics> cryptographicBufferStatics;
    RETURN_NULL_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_CryptographicBuffer).Get(),
                             &cryptographicBufferStatics));

    Wrappers::HString encodedString;
    RETURN_NULL_IF_FAILED(cryptographicBufferStatics->EncodeToBase64String(wrlBuffer.Get(), encodedString.GetAddressOf()));

    unsigned int rawLength;
    const wchar_t* rawEncodedString = WindowsGetStringRawBuffer(encodedString.Get(), &rawLength);

    NSString* nsEncodedString = [NSString _stringWithHSTRING:encodedString.Get()];

    // Do any necessary post-processing for options
    // If line length specified, place a newline character (/r, /n, or /r/n every (specified number) characters)
    if ((options & NSDataBase64Encoding64CharacterLineLength) || (options & NSDataBase64Encoding76CharacterLineLength)) {
        size_t lineLength = (options & NSDataBase64Encoding64CharacterLineLength) ? 64 : 76;
        // Calculate number of times to insert newlines
        // Since no newline is needed at the end if stringLength is evenly divisible by lineLength,
        // subtract 1 from stringLength when dividing
        size_t stringLength = [nsEncodedString length];
        size_t newLineCount = (stringLength != 0) ? ((stringLength - 1) / lineLength) : 0;

        if (newLineCount > 0) {
            NSDataBase64EncodingOptions useCR = options & NSDataBase64EncodingEndLineWithCarriageReturn;
            NSDataBase64EncodingOptions useLF = options & NSDataBase64EncodingEndLineWithLineFeed;

            StrongId<NSString> newLineChar;
            if (useCR && !useLF) {
                newLineChar = @"\r";
            } else if (!useCR && useLF) {
                newLineChar = @"\n";
            } else {
                // Use CRLF by default, but can also be manually specified
                newLineChar = @"\r\n";
            }

            NSMutableString* mutableEncodedString = [NSMutableString stringWithString:nsEncodedString];

            // Add new line every (lineLength) chars
            // Iterate backwards to avoid compensating for changes in length
            for (size_t i = newLineCount; i > 0; i--) {
                [mutableEncodedString insertString:newLineChar atIndex:(i * lineLength)];
            }

            return [NSString stringWithString:mutableEncodedString];
        }
    }

    // If line length not specified, or newLineCount <= 0, none of the other options matter, just return nsEncodedString
    return nsEncodedString;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithBase64EncodedString:(NSString*)base64String options:(NSDataBase64DecodingOptions)options {
    StrongId<NSString> stringToUse = base64String;

    // Create a clean version of the string if IgnoreUnknownCharacters is specified
    if (options & NSDataBase64DecodingIgnoreUnknownCharacters) {
        NSMutableString* cleanedString = [NSMutableString stringWithCapacity:[base64String length]];
        StrongId<NSScanner> scanner = [NSScanner scannerWithString:base64String];
        StrongId<NSCharacterSet> base64AllowedCharacters =
            [NSCharacterSet characterSetWithCharactersInString:@"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="];

        while (![scanner isAtEnd]) {
            NSString* buf;
            if ([scanner scanCharactersFromSet:base64AllowedCharacters intoString:&buf]) {
                [cleanedString appendString:buf];
            } else {
                [scanner setScanLocation:[scanner scanLocation] + 1];
            }
        }

        stringToUse = cleanedString;
    }

    if ([stringToUse length] == 0) {
        return [self initWithBytes:"" length:0];
    }

    ComPtr<ICryptographicBufferStatics> cryptographicBufferStatics;
    RETURN_NULL_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_CryptographicBuffer).Get(),
                             &cryptographicBufferStatics));

    Wrappers::HString wrlBase64String = Strings::NarrowToWide<HSTRING>(stringToUse);

    ComPtr<IBuffer> wrlBuffer;
    RETURN_NULL_IF_FAILED(cryptographicBufferStatics->DecodeFromBase64String(wrlBase64String.Get(), wrlBuffer.GetAddressOf()));

    ComPtr<IBufferByteAccess> bufferAccess;
    RETURN_NULL_IF_FAILED(wrlBuffer.As(&bufferAccess));

    uint8_t* rawBuffer;
    RETURN_NULL_IF_FAILED(bufferAccess->Buffer(&rawBuffer));

    unsigned int bufferLength;
    RETURN_NULL_IF_FAILED(wrlBuffer->get_Length(&bufferLength));

    return [self initWithBytes:rawBuffer length:bufferLength];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithData:(NSData*)data {
    return [[[self alloc] initWithData:data] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)data {
    return [[[self alloc] init] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithBytes:(const void*)bytes length:(unsigned)length {
    return [[[self alloc] initWithBytes:bytes length:length] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithBytesNoCopy:(void*)bytes length:(unsigned)length {
    return [[[self alloc] initWithBytesNoCopy:(void*)bytes length:length freeWhenDone:YES] autorelease];
}

/**
 @Status Caveat
 @Notes The CRT used between Islandwood and the application must match if freeWhenDone=TRUE
*/
+ (instancetype)dataWithBytesNoCopy:(void*)bytes length:(unsigned)length freeWhenDone:(BOOL)free {
    return [[[self alloc] initWithBytesNoCopy:(void*)bytes length:length freeWhenDone:free] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithData:(NSData*)data {
    return [self initWithBytes:[data bytes] length:[data length]];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithBytes:(const void*)bytes length:(unsigned)length {
    // The created NSData takes ownership of freeing this
    woc::unique_iw<uint8_t> copiedBytes(static_cast<uint8_t*>(IwMalloc(length)));
    if (!copiedBytes) {
        [self release];
        return nil;
    }

    memcpy_s(copiedBytes.get(), length, bytes, length);
    self = [self initWithBytesNoCopy:copiedBytes.release() length:length];
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeBytes:reinterpret_cast<const unsigned char*>([self bytes]) length:[self length] forKey:@"NS.data"];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    return [self initWithData:[coder decodeObjectForKey:@"NS.data"]];
}

/**
 @Status Caveat
 @Notes The CRT used between Islandwood and the application must match if freeWhenDone=TRUE
        Designated initializer
*/
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(unsigned)length freeWhenDone:(BOOL)freeWhenDone {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)getBytes:(void*)dest {
    [self getBytes:dest length:[self length]];
}

/**
 @Status Interoperable
*/
- (void)getBytes:(void*)dest length:(unsigned)length {
    [self getBytes:dest range:{ 0, length }];
}

/**
 @Status Interoperable
*/
- (void)getBytes:(void*)dest range:(NSRange)range {
    if (range.location + range.length > [self length]) {
        [NSException raise:NSRangeException
                    format:@"Specified range { %d, %d } exceeds data's length %d", range.location, range.length, [self length]];
    }
    memcpy_s(dest, range.length, reinterpret_cast<const void*>(reinterpret_cast<const byte*>(self.bytes) + range.location), range.length);
}

/**
 @Status Caveat
 @Notes File is not mapped; defers to initWithContentsOfFile:
*/
- (instancetype)initWithContentsOfMappedFile:(NSString*)filename {
    TraceVerbose(TAG, L"Not actually mapping file ...");
    return [self initWithContentsOfFile:filename];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithContentsOfFile:(NSString*)filename {
    return [self initWithContentsOfFile:filename options:0 error:nullptr];
}

/**
 @Status Caveat
 @Notes atomically parameter not supported
*/
- (BOOL)writeToFile:(NSString*)filename atomically:(BOOL)atomically {
    char* fname = (char*)[filename UTF8String];

    TraceVerbose(TAG, L"NSData writing %hs (%d bytes)", fname, [self length]);
    if (!fname) {
        TraceVerbose(TAG, L"Filename is null!");
        return FALSE;
    }
    EbrFile* fpOut = EbrFopen((const char*)fname, "wb");
    if (fpOut) {
        EbrFwrite([self bytes], 1, [self length], fpOut);
        EbrFclose(fpOut);

        return TRUE;
    } else {
        TraceVerbose(TAG, L"NSData couldn't open %hs for write", fname);
        return FALSE;
    }
}

/**
 @Status Caveat
 @Notes Only file:// URLs supported. atomically parameter not supported.
*/
- (BOOL)writeToURL:(NSURL*)url atomically:(BOOL)atomically {
    if (![url isFileURL]) {
        TraceVerbose(TAG, L"-[NSData::writeToURL]: Only file: URLs are supported. (%hs)", [[url absoluteString] UTF8String]);
        return NO;
    }
    return [self writeToFile:[url path] atomically:atomically];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (BOOL)writeToFile:(NSString*)filename options:(NSDataWritingOptions)options error:(NSError**)error {
    char* fname = (char*)[filename UTF8String];

    TraceVerbose(TAG, L"NSData writing %hs (%d bytes)", fname, [self length]);
    EbrFile* fpOut = EbrFopen((const char*)fname, "wb");
    if (fpOut) {
        EbrFwrite([self bytes], 1, [self length], fpOut);
        EbrFclose(fpOut);

        return TRUE;
    } else {
        TraceVerbose(TAG, L"NSData couldn't open %hs for write (with options)", fname);
        return FALSE;
    }
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (BOOL)writeToURL:(NSURL*)url options:(NSDataWritingOptions)options error:(NSError**)errorp {
    if (![url isFileURL]) {
        TraceVerbose(TAG, L"-[NSData::writeToURL]: Only file: URLs are supported. (%hs)", [[url absoluteString] UTF8String]);
        return NO;
    }
    return [self writeToFile:[url path] options:options error:errorp];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithContentsOfFile:(NSString*)filename {
    return [[[self alloc] initWithContentsOfFile:filename] autorelease];
}

/**
 @Status Caveat
 @Notes File is not mapped; defers to initWithContentsOfFile:
*/
+ (instancetype)dataWithContentsOfMappedFile:(NSString*)filename {
    return [[[self alloc] initWithContentsOfMappedFile:filename] autorelease];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (instancetype)initWithContentsOfFile:(NSString*)filename options:(NSDataReadingOptions)options error:(NSError**)error {
    if (!filename) {
        if (error) {
            *error = [NSError errorWithDomain:@"NSData" code:100 userInfo:nil];
        }
        [self release];
        return nil;
    }

    char* fname = (char*)[filename UTF8String];

    TraceVerbose(TAG, L"NSData extended-opening %hs", fname);
    EbrFile* fpIn = EbrFopen(fname, "rb");
    if (fpIn) {
        auto closeFile = wil::ScopeExit([&]() { EbrFclose(fpIn); });

        EbrFseek(fpIn, 0, SEEK_END);
        size_t length = EbrFtell(fpIn);
        EbrFseek(fpIn, 0, SEEK_SET);

        if (length) {
            // The created NSData takes ownership of freeing this
            woc::unique_iw<uint8_t> copiedBytes(static_cast<uint8_t*>(IwMalloc(length)));
            if (!copiedBytes.get()) {
                if (error) {
                    *error = [NSError errorWithDomain:@"NSData" code:100 userInfo:nil];
                }
                [self release];
                return nil;
            }

            size_t fileLength = EbrFread(copiedBytes.get(), 1, length, fpIn);
            self = [self initWithBytesNoCopy:copiedBytes.release() length:fileLength];
        }

    } else {
        TraceVerbose(TAG, L"NSData couldn't open %hs for read (extended)", fname);
        if (error) {
            *error = [NSError errorWithDomain:@"NSData" code:100 userInfo:nil];
        }
        [self release];
        return nil;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithBase64EncodedData:(NSData*)base64Data options:(NSDataBase64DecodingOptions)options {
    StrongId<NSString> base64String = [[[NSString alloc] initWithData:base64Data encoding:NSUTF8StringEncoding] autorelease];
    auto ret = [self initWithBase64EncodedString:base64String options:options];
    return ret;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithBase64Encoding:(NSString*)base64String {
    return [self initWithBase64EncodedString:base64String options:0];
}

/**
 @Status Stub
*/
- (instancetype)initWithBytesNoCopy:(void*)bytes
                             length:(NSUInteger)length
                        deallocator:(void (^)(void* bytes, NSUInteger length))deallocator {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(unsigned)length {
    return [self initWithBytesNoCopy:bytes length:length freeWhenDone:YES];
}

/**
 @Status Stub
*/
- (void)enumerateByteRangesUsingBlock:(void (^)(const void* bytes, NSRange byteRange, BOOL* stop))block {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (NSRange)rangeOfData:(NSData*)dataToFind options:(NSDataSearchOptions)mask range:(NSRange)searchRange {
    // Safe to directly call into CF here, as the CF function only access this class's data through primitive functions
    CFRange cfRange = CFDataFind(static_cast<CFDataRef>(self),
                                 static_cast<CFDataRef>(dataToFind),
                                 { searchRange.location, searchRange.length },
                                 static_cast<CFDataSearchFlags>(mask));
    if (cfRange.location < 0) {
        return { NSNotFound, 0 };
    } else {
        return { cfRange.location, cfRange.length };
    }
}

/**
 @Status Interoperable
*/
- (NSData*)base64EncodedDataWithOptions:(NSDataBase64EncodingOptions)options {
    return [[self base64EncodedStringWithOptions:options] dataUsingEncoding:NSUTF8StringEncoding];
}

/**
 @Status Interoperable
*/
- (NSString*)base64Encoding {
    return [self base64EncodedStringWithOptions:0];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
+ (instancetype)dataWithContentsOfFile:(NSString*)filename options:(NSDataReadingOptions)options error:(NSError**)error {
    return [[[self alloc] initWithContentsOfFile:filename options:options error:error] autorelease];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
+ (instancetype)dataWithContentsOfURL:(NSURL*)url options:(NSDataReadingOptions)options error:(NSError**)error {
    return [[[self alloc] initWithContentsOfURL:url options:options error:error] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithContentsOfURL:(NSURL*)url {
    return [[[self alloc] initWithContentsOfURL:url] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url {
    return [self initWithContentsOfURL:url options:0 error:NULL];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url options:(NSDataReadingOptions)options error:(NSError**)error {
    TraceVerbose(TAG, L"initWithContentsOfURL: %hs", [[url absoluteString] UTF8String]);

    if ([url isFileURL]) {
        return [self initWithContentsOfFile:[url path] options:options error:error];
    }

    NSURLRequest* request = [NSURLRequest requestWithURL:url];
    id response; // what type is this?
    NSData* data = [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:error];

    return [self initWithData:data];
}

/**
 @Status Interoperable
*/
- (instancetype)subdataWithRange:(NSRange)range {
    return [NSData dataWithBytes:reinterpret_cast<const void*>(reinterpret_cast<const byte*>(self.bytes) + range.location)
                          length:range.length];
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (NSMutableData*)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableData alloc] initWithData:self];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToData:(NSData*)data {
    NSData* other = (NSData*)data;
    if ([self length] != [other length]) {
        return false;
    }
    return memcmp([self bytes], [other bytes], [self length]) == 0;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)objAddr {
    if (objAddr == self) {
        return TRUE;
    }
    if (objAddr != nil && [objAddr isKindOfClass:[NSData class]]) {
        return [self isEqualToData:objAddr];
    }

    return FALSE;
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    const char* bytes = (const char*)[self bytes];
    NSUInteger length = [self length];

    // length * 2   = 2 chars (hex representation) for each byte
    // length / 4   = spaces - one every 4 bytes
    // 16           = <> and misc
    // if the length > 1024, describe only the first 512 bytes and the last 512 bytes,
    // and add a "... " (4 bytes) in the middle
    const NSUInteger lengthToUse = std::min(1024u, length);
    const int tmpBufSize = 16 + lengthToUse * 2 + (lengthToUse / 4) + (length > 1024 ? 4 : 0);

    std::vector<char> tmpBuf(tmpBufSize);
    int tmpBufLen = 0;

    tmpBuf[tmpBufLen++] = '<';

    for (auto i = 0; i < length;) {
        // skip the middle portion, if length > 1024, and go directly to the last 512 bytes
        if ((length > 1024) && (i == 512)) {
            tmpBuf[tmpBufLen++] = '.';
            tmpBuf[tmpBufLen++] = '.';
            tmpBuf[tmpBufLen++] = '.';
            tmpBuf[tmpBufLen++] = ' ';
            i = length - 512;
            continue;
        }

        int outDigit = ((bytes[i] & 0xF0) >> 4);
        if (outDigit < 10) {
            tmpBuf[tmpBufLen++] = '0' + outDigit;
        } else {
            tmpBuf[tmpBufLen++] = 'a' + outDigit - 10;
        }
        assert(tmpBufLen < tmpBufSize);
        outDigit = bytes[i] & 0xF;
        if (outDigit < 10) {
            tmpBuf[tmpBufLen++] = '0' + outDigit;
        } else {
            tmpBuf[tmpBufLen++] = 'a' + outDigit - 10;
        }
        assert(tmpBufLen < tmpBufSize);
        i++;

        if ((i % 4) == 0 && i < length) {
            tmpBuf[tmpBufLen++] = ' ';
            assert(tmpBufLen < tmpBufSize);
        }
    }
    tmpBuf[tmpBufLen++] = '>';

    NSString* ret = [[NSString alloc] initWithCString:tmpBuf.data() length:tmpBufLen];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (const void*)bytes {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSUInteger)length {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [super dealloc];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

@end
