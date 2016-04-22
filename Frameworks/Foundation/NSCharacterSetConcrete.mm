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
#include "NSCharacterSetConcrete.h"
#include <CoreFoundation/CFURLComponents.h>
#include <CoreFoundation/CFCharacterSet.h>
#include <Foundation/NSData.h>

#pragma region NSCharacterSetConcrete

@implementation NSCharacterSetConcrete {
@private
    StrongId<NSCharacterSet> _nscf;
}

- (instancetype)init {
    if (self = [super init]) {
        _nscf.attach(static_cast<NSCharacterSet*>(CFCharacterSetCreateWithCharactersInString(NULL, CFSTR(""))));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, BOOL, characterIsMember:(unichar)aCharacter);
- INNER_BRIDGE_CALL(_nscf, BOOL, hasMemberInPlane:(uint8_t)thePlane);
- INNER_BRIDGE_CALL(_nscf, BOOL, isSupersetOfSet:(NSCharacterSet*)theOtherSet);
- INNER_BRIDGE_CALL(_nscf, BOOL, longCharacterIsMember:(UTF32Char)theLongChar);
- INNER_BRIDGE_CALL(_nscf, NSData*, bitmapRepresentation);

@end

#pragma endregion

#pragma region NSMutableCharacterSetConcrete

@implementation NSMutableCharacterSetConcrete {
@private
    StrongId<NSMutableCharacterSet> _nscf;
}

- (instancetype)init {
    if (self = [super init]) {
        _nscf.attach(static_cast<NSMutableCharacterSet*>(CFCharacterSetCreateMutable(NULL)));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, BOOL, characterIsMember:(unichar)aCharacter);
- INNER_BRIDGE_CALL(_nscf, BOOL, hasMemberInPlane:(uint8_t)thePlane);
- INNER_BRIDGE_CALL(_nscf, BOOL, isSupersetOfSet:(NSCharacterSet*)theOtherSet);
- INNER_BRIDGE_CALL(_nscf, BOOL, longCharacterIsMember:(UTF32Char)theLongChar);
- INNER_BRIDGE_CALL(_nscf, NSData*, bitmapRepresentation);

- INNER_BRIDGE_CALL(_nscf, void, addCharactersInRange:(NSRange)aRange);
- INNER_BRIDGE_CALL(_nscf, void, removeCharactersInRange:(NSRange)aRange);
- INNER_BRIDGE_CALL(_nscf, void, addCharactersInString:(NSString*)aString);
- INNER_BRIDGE_CALL(_nscf, void, removeCharactersInString:(NSString*)aString);
- INNER_BRIDGE_CALL(_nscf, void, formIntersectionWithCharacterSet:(NSCharacterSet*)otherSet);
- INNER_BRIDGE_CALL(_nscf, void, formUnionWithCharacterSet:(NSCharacterSet*)otherSet);
- INNER_BRIDGE_CALL(_nscf, void, invert);

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
    CFCharacterSetAddCharactersInRange(static_cast<CFMutableCharacterSetRef>(self), CFRange{ aRange.location, aRange.length });
}

- (void)removeCharactersInRange:(NSRange)aRange {
    CFCharacterSetRemoveCharactersInRange(static_cast<CFMutableCharacterSetRef>(self), CFRange{ aRange.location, aRange.length });
}

- (void)addCharactersInString:(NSString*)aString {
    CFCharacterSetAddCharactersInString(static_cast<CFMutableCharacterSetRef>(self), static_cast<CFStringRef>(aString));
}

- (void)removeCharactersInString:(NSString*)aString {
    CFCharacterSetRemoveCharactersInString(static_cast<CFMutableCharacterSetRef>(self), static_cast<CFStringRef>(aString));
}

- (void)formIntersectionWithCharacterSet:(NSCharacterSet*)otherSet {
    CFCharacterSetIntersect(static_cast<CFMutableCharacterSetRef>(self), static_cast<CFCharacterSetRef>(otherSet));
}

- (void)formUnionWithCharacterSet:(NSCharacterSet*)otherSet {
    CFCharacterSetUnion(static_cast<CFMutableCharacterSetRef>(self), static_cast<CFCharacterSetRef>(otherSet));
}

- (void)invert {
    CFCharacterSetInvert(static_cast<CFMutableCharacterSetRef>(self));
}

- (instancetype)copyWithZone:(NSZone*)zone {
    return static_cast<NSCharacterSet*>(CFCharacterSetCreateCopy(nullptr, static_cast<CFCharacterSetRef>(self)));
}

- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    return static_cast<NSCharacterSet*>(CFCharacterSetCreateMutableCopy(nullptr, static_cast<CFCharacterSetRef>(self)));
}

@end

#pragma endregion
