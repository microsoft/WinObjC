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

#pragma once

#include <Foundation/NSObject.h>
#include <Foundation/NSException.h>

#include <new> // For placement new
#include <type_traits>

// ObjC class type for CF*Refs that have no equivalent NS version.
FOUNDATION_EXPORT_CLASS
@interface NSCFBridgeBase : NSObject
@end

//
// CFBridgeBase acts as the base class for bridged classes.
//
// It provides a mechanism for allocating such classes (CFBridgeBase::alloc), taking an optional
// Objective-C Class to function as the object's type. It is templated on the C version's bridged
// analogue, which will include all state for the object.
//
// We use NSAllocateObject's extraSpace parameter to store any private state we want, after the
// Objective-C portion of the object (enforced to be only the isa field).
//
// Note that the Objective-C class version can have no ivar state, since this changes the size of
// the object and, thus, the position we're storing our private information. We cannot know this
// at compile time, so cannot account for the size in the C version's structure.
//

// Type-erased base for holding isa and the destructor, so when destructing we don't need to know
// the bridge derived type.
struct CFBridgeBaseState {
    void* isa;

    // This is a cached function that calls the destructor to the derived class.
    void (*destruct)(CFBridgeBaseState* self);
};

template<typename Bridge>
struct CFBridgeBase : CFBridgeBaseState {
    template <typename... Args>
    static Bridge* alloc(Class cls, Args&& ...args) {
        // Do static validation here since this code must be hit and the full Bridge type isn't realized in the class's scope:
        static_assert(offsetof(Bridge, isa) == 0, "Isa must be first element: Make sure there are no virtuals or multiple inheritance!");
        static_assert(std::is_base_of<CFBridgeBase<Bridge>, Bridge>::value, "CFBridgeBase<Bridge> must be the base of Bridge!");

        static const size_t nsObjectSize = class_getInstanceSize([NSObject class]);
        assert(nsObjectSize == sizeof(void*) && "NSObject must contain only isa!");

        // If we have no tolled bridge class, default to NSCFBridgeBase for retain/release semantics:
        if (!cls) {
            cls = [NSCFBridgeBase class];
        } else if (class_getInstanceSize(cls) != nsObjectSize) {
            [NSException raise:@"Invalid CFBridgeBase instantiation" format:@"Bridged classes cannot have ivars!"];
        }

        // This is the real allocation for the object, being careful to allocate through the ObjC runtime,
        // making sure to keep extra bytes at the end for the bridge structure.
        id newObject = NSAllocateObject(cls, sizeof(Bridge) - nsObjectSize, nullptr);
        auto originalIsa = reinterpret_cast<CFBridgeBase*>(newObject)->isa;

        // Call the constructor on the C-struct that is our private state:
        auto returnValue = new(reinterpret_cast<void*>(newObject)) Bridge(std::forward<Args>(args)...);

        // After the placement-new, our constructor leaves the original values in an unspecified state.
        // Re-asign the isa so we're not leaving it in an unspecified state:
        returnValue->isa = originalIsa;

        returnValue->destruct = &_doDestruct;
        return returnValue;
    }

private:
    static void _doDestruct(CFBridgeBaseState* self) {
        static_cast<Bridge*>(self)->~Bridge();
    }
};

// This will generally come in as the NS version of the type, since it's expected we'll
// deallocate via a call to -dealloc.
template<typename Derived>
static inline void bridgeDealloc(Derived self) {
    auto bridgeBase = reinterpret_cast<CFBridgeBaseState*>(self);
    bridgeBase->destruct(bridgeBase);
}
