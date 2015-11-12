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

#import "NSKeyValueObserving-Internal.h"

static Class NSKVO$class(id self, SEL);
static Class NSKVO$meta$superclass(Class self, SEL);
static void NSKVO$setObject$forKey$(id self, SEL _cmd, id object, NSString* key);
static void NSKVO$removeObjectForKey$(id self, SEL _cmd, NSString* key);
static void NSKVO$dealloc(id self, SEL);

namespace {

// Swizzling stuff
struct NSKVOSwizzledMethod {
    std::string key;
    size_t valueSize;
    IMP origImp;
    NSKVOSwizzledMethod(const std::string& key) : key(key), valueSize(0), origImp(nullptr) {
    }
    NSKVOSwizzledMethod(const std::string& key, const char* objcType, IMP origImp)
        : key(key), valueSize(getArgumentSize(objcType)), origImp(origImp) {
    }
    NSKVOSwizzledMethod(IMP origImp) : origImp(origImp) {
    }
    template <typename... Args>
    void callOriginal(id self, SEL _cmd, Args... args) {
        ((void (*)(id, SEL, Args...))origImp)(self, _cmd, std::forward<Args>(args)...);
    }
    template <typename... Args>
    void callOriginalVariadic(id self, SEL _cmd, Args... args) {
        ((void (*)(id, SEL, ...))origImp)(self, _cmd, std::forward<Args>(args)...);
    }
};

class NSKVOSwizzledClass : public NSKVOClass {
private:
    std::unordered_map<SEL, NSKVOSwizzledMethod> _selectorMethodInfo;
    std::recursive_mutex _mutex;
    std::function<void(id)> _deallocInstance;

public:
    NSKVOSwizzledClass(Class originalClass, Class notifyingClass)
        : NSKVOClass(originalClass, notifyingClass), _selectorMethodInfo(), _mutex() {
        auto deallocIMP = (void (*)(id, SEL))class_getMethodImplementation(originalClass, @selector(dealloc));
        _deallocInstance = std::bind(deallocIMP, std::placeholders::_1, @selector(dealloc));
    }
    NSKVOSwizzledMethod& swizzledMethod(SEL sel) {
        std::lock_guard<std::recursive_mutex> lock(_mutex);
        return _selectorMethodInfo.at(sel);
    }

    void dealloc(id instance) override {
        NSKVOClass::dealloc(instance);
        _deallocInstance(instance);
    }

    // Two entrypoints into method swizzling: one key-based, one imp-based.
    void swizzleMethod(SEL sel, IMP newImp);
    void ensureKeyWillNotify(const std::string& key) override;

private:
    void _swizzleMethodWithMethodInfo(SEL sel, IMP newImp, NSKVOSwizzledMethod&& methodInfo);
};
}

// NSKVOSwizzledNotifyingClassForClass constructs at runtime a notifying version of a given class.
// happen only under lock.
Class NSKVOSwizzledNotifyingClassForClass(Class originalClass) {
    const char* name = class_getName(originalClass);
    auto newName(woc::string::format("_NSKVONotifying_%s", name));
    Class notifyingClass = objc_allocateClassPair(originalClass, newName.c_str(), 0);
    Class notifyingMetaclass = object_getClass(notifyingClass);

    auto swizzledClassInfo(std::shared_ptr<NSKVOSwizzledClass>(new NSKVOSwizzledClass(originalClass, notifyingClass)));

    class_replaceMethod(notifyingClass, @selector(dealloc), reinterpret_cast<IMP>(NSKVO$dealloc), "v@:");
    class_replaceMethod(notifyingClass, @selector(class), reinterpret_cast<IMP>(NSKVO$class), "#@:");
    class_replaceMethod(notifyingMetaclass, @selector(superclass), reinterpret_cast<IMP>(NSKVO$meta$superclass), "##:");

    swizzledClassInfo->swizzleMethod(@selector(setObject:forKey:), reinterpret_cast<IMP>(NSKVO$setObject$forKey$));
    swizzledClassInfo->swizzleMethod(@selector(removeObjectForKey:), reinterpret_cast<IMP>(NSKVO$removeObjectForKey$));

    objc_registerClassPair(notifyingClass);

    NSKVOClass::registerClassPair(notifyingClass, originalClass, swizzledClassInfo);
    return notifyingClass;
}

template <typename T>
void notifyingSetImpl(id self, SEL _cmd, T val) {
    // These dynamic casts should never fail: we only have these methods
    // on classes we created a NSKVOSwizzledClass for.
    NSKVOSwizzledClass& trailer(dynamic_cast<NSKVOSwizzledClass&>(NSKVOClass::forInstance(self)));
    auto& obMethod(trailer.swizzledMethod(_cmd));
    NSString* key = [NSString stringWithUTF8String:obMethod.key.c_str()];

    [self willChangeValueForKey:key];
    obMethod.callOriginal(self, _cmd, val);
    [self didChangeValueForKey:key];
}

void notifyingVariadicSetImpl(id self, SEL _cmd, ...) {
    NSKVOSwizzledClass& trailer(dynamic_cast<NSKVOSwizzledClass&>(NSKVOClass::forInstance(self)));
    auto& obMethod(trailer.swizzledMethod(_cmd));
    auto argSz = obMethod.valueSize;
    auto nStackArgs = argSz / sizeof(unsigned);
    unsigned* raw = static_cast<unsigned*>(calloc(sizeof(unsigned), nStackArgs));
    va_list ap;
    va_start(ap, _cmd);
    for (unsigned int i = 0; i < nStackArgs; ++i) {
        unsigned val = va_arg(ap, unsigned);
        memcpy(raw + i, &val, sizeof(unsigned));
    }
    va_end(ap);

    NSString* key = [NSString stringWithUTF8String:obMethod.key.c_str()];

    [self willChangeValueForKey:key];

    switch (nStackArgs) {
        case 1:
            obMethod.callOriginalVariadic(self, _cmd, raw[0]);
            break;
        case 2:
            obMethod.callOriginalVariadic(self, _cmd, raw[0], raw[1]);
            break;
        case 3:
            obMethod.callOriginalVariadic(self, _cmd, raw[0], raw[1], raw[2]);
            break;
        case 4:
            obMethod.callOriginalVariadic(self, _cmd, raw[0], raw[1], raw[2], raw[3]);
            break;
        case 5:
            obMethod.callOriginalVariadic(self, _cmd, raw[0], raw[1], raw[2], raw[3], raw[4]);
            break;
        case 6:
            obMethod.callOriginalVariadic(self, _cmd, raw[0], raw[1], raw[2], raw[3], raw[4], raw[5]);
            break;
    }

    [self didChangeValueForKey:key];
}

void NSKVOSwizzledClass::swizzleMethod(SEL sel, IMP newImp) {
    std::lock_guard<std::recursive_mutex> lock(_mutex);
    if (_selectorMethodInfo.find(sel) != _selectorMethodInfo.end()) {
        return;
    }

    auto origImp = class_getMethodImplementation(originalClass, sel);
    _swizzleMethodWithMethodInfo(sel, newImp, NSKVOSwizzledMethod{ origImp });
}

void NSKVOSwizzledClass::_swizzleMethodWithMethodInfo(SEL sel, IMP newImp, NSKVOSwizzledMethod&& methodInfo) {
    _selectorMethodInfo.emplace(std::piecewise_construct, std::forward_as_tuple(sel), std::forward_as_tuple(std::move(methodInfo)));
    class_addMethod(notifyingClass, sel, newImp, objc_get_type_encoding(originalClass, sel));
}

void NSKVOSwizzledClass::ensureKeyWillNotify(const std::string& key) {
    std::lock_guard<std::recursive_mutex> lock(_mutex);

    auto accessorName(woc::string::format("set%c%s:", toupper(key[0]), &key[1]));
    auto sel = sel_registerName(accessorName.c_str());

    if (_selectorMethodInfo.find(sel) != _selectorMethodInfo.end()) {
        return;
    }

    NSMethodSignature* sig = [originalClass instanceMethodSignatureForSelector:sel];
    if (!sig || ![originalClass automaticallyNotifiesObserversForKey:[NSString stringWithUTF8String:key.c_str()]]) {
        // There is no known setter for this property, but we do still want to observe it.
        // This keeps us from going down this path again.
        _selectorMethodInfo.emplace(std::piecewise_construct, std::forward_as_tuple(sel), std::forward_as_tuple(key));
        return;
    }
    auto valueType = [sig getArgumentTypeAtIndex:2];
    IMP newImpl = NULL;

    switch (valueType[0]) {
        case '@':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<id>);
            break;
        case '#':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<Class>);
            break;
        case 'c':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<char>);
            break;
        case 'i':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<int>);
            break;
        case 's':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<short>);
            break;
        case 'l':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<long>);
            break;
        case 'q':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<long long>);
            break;
        case 'C':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<unsigned char>);
            break;
        case 'I':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<unsigned int>);
            break;
        case 'S':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<unsigned short>);
            break;
        case 'L':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<unsigned long>);
            break;
        case 'Q':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<unsigned long long>);
            break;
        case 'f':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<float>);
            break;
        case 'd':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<double>);
            break;
        case 'B':
            newImpl = reinterpret_cast<IMP>(&notifyingSetImpl<bool>);
            break;
        case '{':
        case '[':
            newImpl = reinterpret_cast<IMP>(&notifyingVariadicSetImpl);
            break;
        default:
            [NSException raise:NSInvalidArgumentException
                        format:@"Class %s is not KVO compliant for key %s.", class_getName(originalClass), key.c_str()];
            return;
    }

    auto origImp = class_getMethodImplementation(originalClass, sel);
    _swizzleMethodWithMethodInfo(sel, newImpl, { key, valueType, origImp });
}

//@implementation NSObject (NSKeyValueObservation)
// - (Class)class
static Class NSKVO$class(id self, SEL) {
    return NSKVOClass::forInstance(self).originalClass;
}

// + (Class)superclass
static Class NSKVO$meta$superclass(Class self, SEL) {
    return class_getSuperclass(NSKVOClass::forClass(self).originalClass);
}

// - (void)setObject:(id)object forKey:(NSString*)key
static void NSKVO$setObject$forKey$(id self, SEL _cmd, id object, NSString* key) {
    NSKVOSwizzledClass& trailer(dynamic_cast<NSKVOSwizzledClass&>(NSKVOClass::forInstance(self)));
    auto& obMethod(trailer.swizzledMethod(_cmd));

    [self willChangeValueForKey:key];
    obMethod.callOriginal(self, _cmd, object, key);
    [self didChangeValueForKey:key];
}

// - (void)removeObjectForKey:(NSString*)key
static void NSKVO$removeObjectForKey$(id self, SEL _cmd, NSString* key) {
    NSKVOSwizzledClass& trailer(dynamic_cast<NSKVOSwizzledClass&>(NSKVOClass::forInstance(self)));
    auto& obMethod(trailer.swizzledMethod(_cmd));

    [self willChangeValueForKey:key];
    obMethod.callOriginal(self, _cmd, key);
    [self didChangeValueForKey:key];
}

// - (void)dealloc
static void NSKVO$dealloc(id self, SEL) {
    // NSKVOClass::dealloc calls super dealloc for us.
    NSKVOClass::forClass(object_getClass(self)).dealloc(self);
}
//@end
