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
#include "CoreFoundation/CoreFoundation.h"
#include "Foundation/NSUUID.h"
#include "NSUUID-Private.h"
#include <map>

static IWLazyClassLookup _LazyNSUUID("NSUUID");
static IWLazyClassLookup _LazyNSConstantUUID("_NSConstantUUID");

bool operator<(const CFUUIDBytes& lhs, const CFUUIDBytes& rhs) {
   return memcmp(&(lhs.byte0), &(rhs.byte0), 16) < 0;
}

static std::map<CFUUIDBytes, id> constantUUIDs;

CFUUIDRef CFUUIDCreate(CFAllocatorRef allocator) {
    return (CFUUIDRef)[[_LazyNSUUID alloc] init];
}

CFUUIDRef CFUUIDCreateFromString(CFAllocatorRef allocator, CFStringRef string) {
    return (CFUUIDRef) [[_LazyNSUUID alloc] initWithUUIDString:(NSString*)string];
}

CFUUIDRef CFUUIDCreateFromUUIDBytes(CFAllocatorRef allocator,CFUUIDBytes bytes) {
    return (CFUUIDRef) [[_LazyNSUUID alloc] initWithUUIDBytes:&bytes];
}

CFUUIDRef CFUUIDCreateWithBytes(CFAllocatorRef allocator,
                                uint8_t byte0,
                                uint8_t byte1,
                                uint8_t byte2,
                                uint8_t byte3,
                                uint8_t byte4,
                                uint8_t byte5,
                                uint8_t byte6,
                                uint8_t byte7,
                                uint8_t byte8,
                                uint8_t byte9,
                                uint8_t byte10,
                                uint8_t byte11,
                                uint8_t byte12,
                                uint8_t byte13,
                                uint8_t byte14,
                                uint8_t byte15) {
    CFUUIDBytes bytes =
        {byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7, byte8, byte9, byte10, byte11, byte12, byte13, byte14, byte15};
    return CFUUIDCreateFromUUIDBytes(allocator, bytes);
}

CFUUIDRef CFUUIDGetConstantUUIDWithBytes(CFAllocatorRef allocator,
                                        uint8_t byte0,
                                        uint8_t byte1,
                                        uint8_t byte2,
                                        uint8_t byte3,
                                        uint8_t byte4,
                                        uint8_t byte5,
                                        uint8_t byte6,
                                        uint8_t byte7,
                                        uint8_t byte8,
                                        uint8_t byte9,
                                        uint8_t byte10,
                                        uint8_t byte11,
                                        uint8_t byte12,
                                        uint8_t byte13,
                                        uint8_t byte14,
                                        uint8_t byte15) {
    CFUUIDBytes bytes =
        {byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7, byte8, byte9, byte10, byte11, byte12, byte13, byte14, byte15};
    auto findResult = constantUUIDs.find(bytes);
    if (findResult == constantUUIDs.end()) {
        id uuid = [[_LazyNSConstantUUID alloc] initWithUUIDBytes:&bytes];
        constantUUIDs[bytes] = uuid;
    }
    return (CFUUIDRef) constantUUIDs[bytes];
}

CFUUIDBytes CFUUIDGetUUIDBytes(CFUUIDRef self) {
    CFUUIDBytes bytes;
    [(NSUUID*)self getUUIDBytes:&bytes];
    return bytes;
}

CFStringRef CFUUIDCreateString(CFAllocatorRef allocator, CFUUIDRef self) {
    return (CFStringRef) [[(NSUUID*)self UUIDString] retain];
}