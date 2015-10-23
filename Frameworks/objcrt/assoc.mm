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

#include "runtime.h"
#include "runtime-private.h"
#include <objc/objc.h>

#include <Windows.h>
#include <unordered_map>
#include <memory>
#include <mutex>

// These lifetime traits encapsulate the transfer of ownership (or lack thereof)
// of an Objective-C instance into an assocation.
// - Assign does not transfer ownership.
struct LifetimeAssign {
    // takes ownership of value
    static id capture(id value) {
        return value;
    }
    // releases ownership of value
    static void release(id value) {
        return;
    }
    // extends the lifetime of value
    static id extend(id value) {
        return value;
    }
};

// - Retain takes a strong refcounting reference and releases it when the object is no longer desired.
struct LifetimeRetain {
    static id capture(id value) {
        return [value retain];
    }
    static void release(id value) {
        [value release];
    }
    static id extend(id value) {
        // like a property getter, we have to extend the lifetime of value by
        // retaining it and transferring it into our autorelease pool.
        // If the owning object goes out of scope or is otherwise deallocated,
        // the returned value needs to live until the next autorelease pool drain.
        return [[value retain] autorelease];
    }
};

// - Copy takes a copy of the provided object and releases it when the object is no longer desired.
//   If the object is not NSCopying-compliant, this will throw an invalid selector exception.
struct LifetimeCopy {
    static id capture(id value) {
        return [value copy];
    }
    static void release(id value) {
        [value release];
    }
    static id extend(id value) {
        // as above in LifetimeRetain
        return [[value retain] autorelease];
    }
};

// ObjcAssociation is a lifetime trait erasing container for an associated object.
class ObjcAssociation {
public:
    virtual void exchange(id) = 0;
    virtual id load() const = 0;
    virtual ~ObjcAssociation() = default;
};

// _ObjcLifetimeAssociation is Starboard's idretain<> with customizable lifetime traits.
template <typename LifetimeTraits>
class _ObjcLifetimeAssociation : public virtual ObjcAssociation {
private:
    id _value;

public:
    void exchange(id value) override {
        id old = _value;
        _value = LifetimeTraits::capture(value);
        LifetimeTraits::release(old);
    }
    id load() const override {
        return LifetimeTraits::extend(_value);
    }
    ~_ObjcLifetimeAssociation() {
        LifetimeTraits::release(_value);
    }
};

// Associated objects support both atomic and nonatomic associations; however,
// we're cautious with locking over instance and global association tables,
// providing what appears to be atomicity to external callers. As such,
// we treat atomic/nonatomic associations the same way.
class ObjcAssociationTable {
private:
    mutable std::mutex _mutex;
    std::unordered_map<const void*, std::unique_ptr<ObjcAssociation>> _entries;

public:
    void set(const void* key, id associatedObject, objc_associationPolicy policy) {
        std::lock_guard<std::mutex> lock(_mutex);

        std::unique_ptr<ObjcAssociation> newEntry;
        if (associatedObject) {
            switch (policy) {
                case OBJC_ASSOCIATION_ASSIGN:
                    newEntry = std::make_unique<_ObjcLifetimeAssociation<LifetimeAssign>>();
                    break;
                case OBJC_ASSOCIATION_RETAIN_NONATOMIC:
                case OBJC_ASSOCIATION_RETAIN:
                    newEntry = std::make_unique<_ObjcLifetimeAssociation<LifetimeRetain>>();
                    break;
                case OBJC_ASSOCIATION_COPY_NONATOMIC:
                case OBJC_ASSOCIATION_COPY:
                    newEntry = std::make_unique<_ObjcLifetimeAssociation<LifetimeCopy>>();
                    break;
            }
            newEntry->exchange(associatedObject);
        }

        // This will cause the destruction of the previously associated object
        // for this key.
        _entries[key] = std::move(newEntry);
    }
    id get(const void* key) const {
        std::lock_guard<std::mutex> lock(_mutex);
        const auto found = _entries.find(key);
        if (found == _entries.end()) {
            return nil;
        }

        return found->second->load();
    }
};

class ObjcAssociationTables {
    std::recursive_mutex _mutex;
    std::unordered_map<id, ObjcAssociationTable> _instanceAssociations;

public:
    void set(id object, void* key, id associatedObject, objc_associationPolicy policy) {
        std::lock_guard<std::recursive_mutex> lock(_mutex);
        auto& instanceTable = _instanceAssociations[object];
        instanceTable.set(key, associatedObject, policy);
    }
    id get(id object, void* key) {
        std::lock_guard<std::recursive_mutex> lock(_mutex);
        auto& instanceTable = _instanceAssociations[object];
        return instanceTable.get(key);
    }
    void erase(id object) {
        std::lock_guard<std::recursive_mutex> lock(_mutex);
        _instanceAssociations.erase(object);
    }
    ~ObjcAssociationTables() {
        // By clearing this during destruction, we avoid calling back
        // into erase() when the map is already being destroyed.
        // This generally happens in the automatic atexit dtor.
        _instanceAssociations.clear();
    }
};

static ObjcAssociationTables g_instanceAssociations;

OBJCRT_EXPORT
void objc_setAssociatedObject(id object, void* key, id associatedObject, objc_associationPolicy policy) {
    g_instanceAssociations.set(object, key, associatedObject, policy);
}

OBJCRT_EXPORT
id objc_getAssociatedObject(id object, void* key) {
    return g_instanceAssociations.get(object, key);
}

OBJCRT_EXPORT
void objc_removeAssociatedObjects(id object) {
    g_instanceAssociations.erase(object);
}
