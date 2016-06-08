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
#include "StubReturn.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSCFCharacterSet.h"
#include <CoreFoundation/CFURLComponents.h>
#include <CoreFoundation/CFCharacterSet.h>
#include <Foundation/NSData.h>

@interface NSCFCharacterSet : NSMutableCharacterSet
@end

#pragma region NSCharacterSetPrototype
@implementation NSCharacterSetPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSCFCharacterSet)

- (_Nullable instancetype)init {
    return reinterpret_cast<NSCharacterSetPrototype*>(
        static_cast<NSCharacterSet*>(CFCharacterSetCreateWithCharactersInString(kCFAllocatorDefault, CFSTR(""))));
}

@end
#pragma endregion

#pragma region NSMutableCharacterSetPrototype
@implementation NSMutableCharacterSetPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSCFCharacterSet)

- (_Nullable instancetype)init {
    return reinterpret_cast<NSMutableCharacterSetPrototype*>(CFCharacterSetCreateMutable(kCFAllocatorDefault));
}

@end
#pragma endregion

#pragma region NSCFCharacterSet

@implementation NSCFCharacterSet

BRIDGED_CLASS_REQUIRED_IMPLS(CFCharacterSetRef, CFCharacterSetGetTypeID, NSCharacterSet, NSCFCharacterSet)

- (BOOL)characterIsMember:(unichar)aCharacter {
    return CFCharacterSetIsCharacterMember(static_cast<CFCharacterSetRef>(self), aCharacter);
}

- (BOOL)hasMemberInPlane:(uint8_t)thePlane {
    return CFCharacterSetHasMemberInPlane(static_cast<CFCharacterSetRef>(self), thePlane);
}

- (BOOL)isSupersetOfSet:(NSCharacterSet*)theOtherSet {
    return CFCharacterSetIsSupersetOfSet(static_cast<CFCharacterSetRef>(self), static_cast<CFCharacterSetRef>(theOtherSet));
}

- (BOOL)longCharacterIsMember:(UTF32Char)theLongChar {
    return CFCharacterSetIsLongCharacterMember(static_cast<CFCharacterSetRef>(self), theLongChar);
}

- (NSData*)bitmapRepresentation {
    return [static_cast<NSData*>(CFCharacterSetCreateBitmapRepresentation(nullptr, static_cast<CFCharacterSetRef>(self))) autorelease];
}

- (void)addCharactersInRange:(NSRange)aRange {
    BRIDGED_THROW_IF_IMMUTABLE(__CFCharacterSetIsMutable, CFCharacterSetRef);
    CFCharacterSetAddCharactersInRange(static_cast<CFMutableCharacterSetRef>(self), CFRange{ aRange.location, aRange.length });
}

- (void)removeCharactersInRange:(NSRange)aRange {
    BRIDGED_THROW_IF_IMMUTABLE(__CFCharacterSetIsMutable, CFCharacterSetRef);
    CFCharacterSetRemoveCharactersInRange(static_cast<CFMutableCharacterSetRef>(self), CFRange{ aRange.location, aRange.length });
}

- (void)addCharactersInString:(NSString*)aString {
    BRIDGED_THROW_IF_IMMUTABLE(__CFCharacterSetIsMutable, CFCharacterSetRef);
    CFCharacterSetAddCharactersInString(static_cast<CFMutableCharacterSetRef>(self), static_cast<CFStringRef>(aString));
}

- (void)removeCharactersInString:(NSString*)aString {
    BRIDGED_THROW_IF_IMMUTABLE(__CFCharacterSetIsMutable, CFCharacterSetRef);
    CFCharacterSetRemoveCharactersInString(static_cast<CFMutableCharacterSetRef>(self), static_cast<CFStringRef>(aString));
}

- (void)formIntersectionWithCharacterSet:(NSCharacterSet*)otherSet {
    BRIDGED_THROW_IF_IMMUTABLE(__CFCharacterSetIsMutable, CFCharacterSetRef);
    CFCharacterSetIntersect(static_cast<CFMutableCharacterSetRef>(self), static_cast<CFCharacterSetRef>(otherSet));
}

- (void)formUnionWithCharacterSet:(NSCharacterSet*)otherSet {
    BRIDGED_THROW_IF_IMMUTABLE(__CFCharacterSetIsMutable, CFCharacterSetRef);
    CFCharacterSetUnion(static_cast<CFMutableCharacterSetRef>(self), static_cast<CFCharacterSetRef>(otherSet));
}

- (void)invert {
    BRIDGED_THROW_IF_IMMUTABLE(__CFCharacterSetIsMutable, CFCharacterSetRef);
    CFCharacterSetInvert(static_cast<CFMutableCharacterSetRef>(self));
}

- (NSObject*)copyWithZone:(NSZone*)zone {
    if (__CFCharacterSetIsMutable(static_cast<CFCharacterSetRef>(self))) {
        return reinterpret_cast<NSCFCharacterSet*>(static_cast<NSMutableCharacterSet*>(CFCharacterSetCreateCopy(nullptr, static_cast<CFCharacterSetRef>(self))));
    }

    return [self retain];
}

- (NSObject*)mutableCopyWithZone:(NSZone*)zone {
    return reinterpret_cast<NSCFCharacterSet*>(static_cast<NSMutableCharacterSet*>(CFCharacterSetCreateMutableCopy(nullptr, static_cast<CFCharacterSetRef>(self))));
}

@end

#pragma endregion
