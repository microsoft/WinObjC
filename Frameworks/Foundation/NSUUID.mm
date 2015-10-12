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

#include <Foundation/Foundation.h>
#include <Starboard.h>
#include <Windows.h>

#include <COMIncludes.h>
#include <objbase.h>
#include <COMIncludes_End.h>

@interface NSUUID () {
    GUID _guid;
}
@end

@implementation NSUUID
+ (NSUUID*)UUID {
    return [[[self alloc] init] autorelease];
}

- (id)init {
    if ((self = [super init]) != nil) {
        if (CoCreateGuid(&_guid) != S_OK) {
            [NSException raise:NSGenericException format:@"NSUUID failed to generate a unique ID."];
            [self release];
            return nil;
        }
    }
    return self;
}

- (id)initWithUUIDString:(NSString*)string {
    if ((self = [super init]) != nil) {
        const char* rawString = [string UTF8String];
        unsigned components[11];

        // sscanf here does not support hhx, and instead reads it as a uint32_t
        auto scanned = sscanf_s(
            rawString,
            "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
            &components[0],
            &components[1],
            &components[2],
            &components[3],
            &components[4],
            &components[5],
            &components[6],
            &components[7],
            &components[8],
            &components[9],
            &components[10]);

        if (scanned != 11) {
            [self release];
            return nil;
        }

        _guid.Data1 = static_cast<uint32_t>(components[0]);
        _guid.Data2 = static_cast<uint16_t>(components[1] & 0xFFFF);
        _guid.Data3 = static_cast<uint16_t>(components[2] & 0xFFFF);
        for (int i = 3; i < 11; ++i) {
            _guid.Data4[i - 3] = static_cast<uint8_t>(components[i] & 0xFF);
        }
    }
    return self;
}

- (id)initWithUUIDBytes:(const void*)bytes {
    if ((self = [super init]) != nil) {
        memcpy(&_guid, bytes, 16);
    }
    return self;
}

- (id)initWithCoder:(NSKeyedUnarchiver*)coder {
    NSUInteger len = 0;
    const uint8_t* bytes = [coder decodeBytesForKey:@"NSU.uuid" returnedLength:&len];
    if (!bytes || len != sizeof(_guid)) {
        [self release];
        return nil;
    }

    return [self initWithUUIDBytes:bytes];
}

- (void)encodeWithCoder:(NSKeyedArchiver*)coder {
    [coder encodeBytes:reinterpret_cast<uint8_t*>(&_guid) length:sizeof(_guid) forKey:@"NSU.uuid"];
}

- (NSString*)UUIDString {
    return [NSString stringWithFormat:@"%08lX-%04hX-%04hX-%02hX%02hX-%02hX%02hX%02hX%02hX%02hX%02hX",
        _guid.Data1,
        _guid.Data2,
        _guid.Data3,
        _guid.Data4[0],
        _guid.Data4[1],
        _guid.Data4[2],
        _guid.Data4[3],
        _guid.Data4[4],
        _guid.Data4[5],
        _guid.Data4[6],
        _guid.Data4[7]];
}

- (void)getUUIDBytes:(void*)bytes {
    memcpy(bytes, &_guid, 16);
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (BOOL)isEqual:(id)other {
    if (![other isKindOfClass:[self class]]) {
        return NO;
    }
    return memcmp(&_guid, &static_cast<NSUUID*>(other)->_guid, sizeof(_guid)) == 0;
}

// This is the same hashing function we use in objcrt and NSValue.
- (unsigned)hash {
    unsigned ret = 0;
    char* cur = (char*)&_guid;
    auto len = sizeof(_guid);

    while (len--) {
        ret = (ret << 8) | (ret >> 24);
        ret ^= *cur;
        cur++;
    }

    return ret;
}

- (NSString*)description {
    return [self UUIDString];
}
@end
