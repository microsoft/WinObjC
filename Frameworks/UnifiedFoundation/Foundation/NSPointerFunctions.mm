//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/NSException.h>
#import <Foundation/NSPointerFunctions.h>
#import <Foundation/NSString.h>
#import <NSPointerFunctionsConcrete.h>
#import <NSRaise.h>
#import "NSLogging.h"

#import <objc/objc-arc.h>
#import <string>

// NSPointerOptions memory options are mutually exclusive, and personality options are mutually exclusive.
// These bit masks are used to isolate just the memory option/personality option from a NSPointerFunctionsOptions
static const NSUInteger kNSPointerFunctionsMemoryMask = (0b111 << 0);
static const NSUInteger kNSPointerFunctionsPersonalityMask = (0b111 << 8);

static const wchar_t* TAG = L"NSPointerFunctions";

// Default functions for this class's @properties
NSUInteger _NSPointerFunctionsHashNSObject(const void* item, NSUInteger (*size)(const void* item)) {
    return [static_cast<id>(item) hash];
}

NSUInteger _NSPointerFunctionsHashCString(const void* item, NSUInteger (*size)(const void* item)) {
    // Sadly, it seems that copy into std::string here is unavoidable - std::string wants to own the string buffer,
    // and std::hash has specializations for std::string et al, but not char* et al
    return std::hash<std::string>()(std::string(static_cast<const char*>(item)));
}

NSUInteger _NSPointerFunctionsHashMemory(const void* item, NSUInteger (*size)(const void* item)) {
    return std::hash<const void*>()(item);
}

NSUInteger _NSPointerFunctionsHashShiftedPointer(const void* item, NSUInteger (*size)(const void* item)) {
    return reinterpret_cast<size_t>(item) << 3;
}

NSUInteger _NSPointerFunctionsHashUnshiftedPointer(const void* item, NSUInteger (*size)(const void* item)) {
    return reinterpret_cast<size_t>(item);
}

BOOL _NSPointerFunctionsIsEqualNSObject(const void* item1, const void* item2, NSUInteger (*size)(const void* item)) {
    return [static_cast<id>(item1) isEqual:static_cast<id>(item2)];
}

BOOL _NSPointerFunctionsIsEqualStrCmp(const void* item1, const void* item2, NSUInteger (*size)(const void* item)) {
    return strcmp(reinterpret_cast<const char*>(item1), reinterpret_cast<const char*>(item2)) == 0;
}

BOOL _NSPointerFunctionsIsEqualMemCmp(const void* item1, const void* item2, NSUInteger (*size)(const void* item)) {
    size_t size1 = size(item1);
    size_t size2 = size(item2);
    return (size1 == size2) && (memcmp(item1, item2, size1) == 0);
}

BOOL _NSPointerFunctionsIsEqualDirectCompare(const void* item1, const void* item2, NSUInteger (*size)(const void* item)) {
    return item1 == item2;
}

NSString* _NSPointerFunctionsDescriptionNSObject(const void* item) {
    return [static_cast<id>(item) description];
}

NSString* _NSPointerFunctionsDescriptionCString(const void* item) {
    return [NSString stringWithFormat:@"%s", item];
}

void* _NSPointerFunctionsAcquireNSObject(const void* src, NSUInteger (*size)(const void* item), BOOL shouldCopy) {
    if (shouldCopy) {
        return [static_cast<id>(src) copy];
    } else {
        return [static_cast<id>(src) retain];
    }
}

void _NSPointerFunctionsRelinquishNSObject(const void* item, NSUInteger (*size)(const void* item)) {
    [static_cast<id>(item) release];
}

@implementation NSPointerFunctions

/**
 @Status Interoperable
*/
+ (instancetype)allocWithZone:(NSZone*)zone {
    // alloc the concrete subclass instead
    if (self == [NSPointerFunctions class]) {
        return [_NSConcretePointerFunctions allocWithZone:zone];
    }

    return NSAllocateObject((Class)self, 0, zone);
}

/**
 @Status Interoperable
 @Notes Designated Initializer
*/
- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSPointerFunctions*)pointerFunctionsWithOptions:(NSPointerFunctionsOptions)options {
    return [[[self alloc] initWithOptions:options] autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    return NSInvalidAbstractInvocationReturn();
}

@end

@implementation _NSConcretePointerFunctions

- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options {
    if (self = [super init]) {
        _options = options;
        NSUInteger memoryOption = options & kNSPointerFunctionsMemoryMask;
        NSUInteger personalityOption = options & kNSPointerFunctionsPersonalityMask;
        bool partialInit = false;

        switch (memoryOption) {
            case NSPointerFunctionsStrongMemory:
                if ((personalityOption == NSPointerFunctionsObjectPersonality) ||
                    (personalityOption == NSPointerFunctionsObjectPointerPersonality)) {
                    self.acquireFunction = &_NSPointerFunctionsAcquireNSObject;
                    self.relinquishFunction = &_NSPointerFunctionsRelinquishNSObject;
                }

                self.usesStrongWriteBarrier = YES;
                break;

            case NSPointerFunctionsOpaqueMemory:
                // _acquireFunction/_relinquishFunction are left as nil
                break;

            case NSPointerFunctionsWeakMemory:
                // _acquireFunction/_relinquishFunction are left as nil
                self.usesWeakReadAndWriteBarriers = YES;

                if ((personalityOption == NSPointerFunctionsObjectPersonality) ||
                    (personalityOption == NSPointerFunctionsObjectPointerPersonality)) {
                    self.weakMemory = YES;
                }
                break;

            default:
                partialInit = true;
                NSTraceWarning(
                    TAG,
                    @"*** An unsupported PointerFunctions configuration was request, probably for use by NSMapTable, NSHashTable, or "
                    @"NSPointerArray. The requested configuration fails due to objects with none of strong, weak, or opaque memory");
                break;
        }

        switch (personalityOption) {
            case NSPointerFunctionsObjectPersonality:
                self.hashFunction = &_NSPointerFunctionsHashNSObject;
                self.isEqualFunction = &_NSPointerFunctionsIsEqualNSObject;
                self.descriptionFunction = &_NSPointerFunctionsDescriptionNSObject;
                break;

            case NSPointerFunctionsOpaquePersonality:
                self.hashFunction = &_NSPointerFunctionsHashShiftedPointer;
                self.isEqualFunction = &_NSPointerFunctionsIsEqualDirectCompare;
                break;

            case NSPointerFunctionsObjectPointerPersonality:
                self.hashFunction = &_NSPointerFunctionsHashShiftedPointer;
                self.isEqualFunction = &_NSPointerFunctionsIsEqualDirectCompare;
                self.descriptionFunction = &_NSPointerFunctionsDescriptionNSObject;
                break;

            case NSPointerFunctionsCStringPersonality:
                self.hashFunction = &_NSPointerFunctionsHashCString;
                self.isEqualFunction = &_NSPointerFunctionsIsEqualStrCmp;
                self.descriptionFunction = &_NSPointerFunctionsDescriptionCString;
                break;

            case NSPointerFunctionsStructPersonality:
                self.hashFunction = &_NSPointerFunctionsHashMemory;
                self.isEqualFunction = &_NSPointerFunctionsIsEqualMemCmp;
                break;

            case NSPointerFunctionsIntegerPersonality:
                if (memoryOption == NSPointerFunctionsOpaqueMemory) {
                    self.hashFunction = &_NSPointerFunctionsHashUnshiftedPointer;
                    self.isEqualFunction = &_NSPointerFunctionsIsEqualDirectCompare;
                } else {
                    partialInit = true;
                    NSTraceWarning(
                        TAG,
                        @"*** An unsupported PointerFunctions configuration was request, probably for use by NSMapTable, NSHashTable, or "
                        @"NSPointerArray. The requested configuration fails due to integer personality not using opaque memory");
                }
                break;

            default:
                partialInit = true;
                break;
        }

        if (options & NSPointerFunctionsCopyIn) {
            if ((memoryOption == NSPointerFunctionsStrongMemory) && (personalityOption != NSPointerFunctionsOpaquePersonality)) {
                _copyIn = true;
            } else {
                partialInit = true;
                NSTraceWarning(
                    TAG,
                    @"*** An unsupported PointerFunctions configuration was request, probably for use by NSMapTable, NSHashTable, or "
                    @"NSPointerArray. The requested configuration fails due to copyin with opaque personality or opaque or weak memory");
            }
        }

        if (partialInit) {
            [NSException
                 raise:NSInvalidArgumentException
                format:@"*** An unsupported PointerFunctions configuration was request, probably for use by NSMapTable, NSHashTable, or "
                       @"NSPointerArray. The requested configuration would create only a partially initialized NSPointerFunctions object"];
        }
    }

    return self;
}

/**
 @Status Interoperable
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    _NSConcretePointerFunctions* ret;

    if ((ret = [[[_NSConcretePointerFunctions class] allocWithZone:zone] init])) {
        ret.hashFunction = self.hashFunction;
        ret.isEqualFunction = self.isEqualFunction;
        ret.sizeFunction = self.sizeFunction;
        ret.descriptionFunction = self.descriptionFunction;
        ret.acquireFunction = self.acquireFunction;
        ret.relinquishFunction = self.relinquishFunction;
        ret.usesStrongWriteBarrier = self.usesStrongWriteBarrier;
        ret.usesWeakReadAndWriteBarriers = self.usesWeakReadAndWriteBarriers;

        ret.copyIn = _copyIn;
        ret.weakMemory = _weakMemory;
        ret->_options = _options;
    }

    return ret;
}

@end
