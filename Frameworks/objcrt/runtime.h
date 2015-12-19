//******************************************************************************
//
// Copyright (c) 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015
//   Jonathan Schleifer <js@webkeks.org>. All rights reserved.
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

#ifndef __OBJFW_RUNTIME_H__
#define __OBJFW_RUNTIME_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __has_feature
#define __has_feature(x) 0
#endif

#if __has_feature(objc_arc)
#define OBJC_UNSAFE_UNRETAINED __unsafe_unretained
#define OBJC_BRIDGE __bridge
#else
#define OBJC_UNSAFE_UNRETAINED
#define OBJC_BRIDGE
#endif

#ifndef OBJCRT_EXPORT
#define OBJCRT_EXPORT
#endif

typedef struct objc_class* Class;
typedef struct objc_method* Method;
typedef struct objc_property* Property;
typedef struct objc_object* id;
typedef struct objc_ivar* Ivar;
typedef const struct objc_selector* SEL;
typedef int BOOL;
typedef id (*IMP)(id, SEL, ...);

#ifndef __OBJC_OBJC_H

#define WINRT_ISA_REALCLS(isa) ((Class*)(isa))[-1]
struct winrt_isa {
    //  struct objc_class *realCls;
    //  The ObjC isa points to IW_IInspectable - the realCls member lives immediately BEHIND IW_Inspectable
    void* IW_IInspectable[];
};

typedef struct winrt_isa* WinRT_isa;

struct objc_class {
    struct winrt_isa* isa;
    Class superclass;
    const char* name;
    unsigned long version;
    unsigned long info;
    unsigned long instance_size;
    struct objc_ivar_list* ivars;
    struct objc_method_list* methodlist;
    struct objc_sparsearray* dtable;
    Class* subclass_list;
    void* sibling_class;
    struct objc_protocol_list* protocols;
    void* gc_object_type;
    unsigned long abi_version;
    void* ivar_offsets;
    struct objc_property_list* properties;
};
#endif

enum objc_abi_class_info {
    OBJC_CLASS_INFO_CLASS = 0x001,
    OBJC_CLASS_INFO_METACLASS = 0x002,
    OBJC_CLASS_INFO_NEW_ABI = 0x010,
    OBJC_CLASS_INFO_SETUP = 0x100,
    OBJC_CLASS_INFO_LOADED = 0x200,
    OBJC_CLASS_INFO_DTABLE = 0x400,
    OBJC_CLASS_INFO_INITIALIZED = 0x800,
    OBJC_CLASS_INFO_CREATED_RUNTIME = 0x1000
};

struct objc_object {
    WinRT_isa isa;
};

struct objc_selector {
    uintptr_t uid;
    const char* types;
};

struct objc_super {
    OBJC_UNSAFE_UNRETAINED id self;
    Class cls;
};

struct objc_method {
    struct objc_selector sel;
    IMP imp;
};

struct objc_method_list {
    struct objc_method_list* next;
    unsigned int count;
    struct objc_method methods[1];
};

struct objc_category {
    const char* category_name;
    const char* class_name;
    struct objc_method_list* instance_methods;
    struct objc_method_list* class_methods;
    struct objc_protocol_list* protocols;
};

struct objc_ivar {
    const char* name;
    const char* type;
    unsigned offset;
};

struct objc_ivar_list {
    unsigned count;
    struct objc_ivar ivars[1];
};

#define OBJC_PROPERTY_READONLY 0x01
#define OBJC_PROPERTY_GETTER 0x02
#define OBJC_PROPERTY_ASSIGN 0x04
#define OBJC_PROPERTY_READWRITE 0x08
#define OBJC_PROPERTY_RETAIN 0x10
#define OBJC_PROPERTY_COPY 0x20
#define OBJC_PROPERTY_NONATOMIC 0x40
#define OBJC_PROPERTY_SETTER 0x80

struct objc_property {
    const char* name;
    unsigned char attributes;
    signed char synthesized;
    struct {
        const char* name;
        const char* type;
    } getter, setter;
};

struct objc_property_list {
    unsigned count;
    struct objc_property_list* next;
    struct objc_property properties[1];
};

#ifdef __OBJC__
@interface Protocol {
@public
#else
typedef struct {
#endif
    Class isa;
    const char* name;
    struct objc_protocol_list* protocol_list;
    struct objc_abi_method_description_list* instance_methods;
    struct objc_abi_method_description_list* class_methods;
#ifdef __OBJC__
}
@end
#else
} Protocol;
#endif

struct objc_protocol_list {
    struct objc_protocol_list* next;
    long count;
    OBJC_UNSAFE_UNRETAINED Protocol* list[1];
};

#define Nil (Class)0
#define nil NULL
#define YES (BOOL)1
#define NO (BOOL)0

extern OBJCRT_EXPORT IMP objc_msg_lookup(id obj, SEL sel);

extern OBJCRT_EXPORT SEL sel_registerName(const char*);
extern OBJCRT_EXPORT const char* sel_getName(SEL);
extern OBJCRT_EXPORT BOOL sel_isEqual(SEL, SEL);
extern OBJCRT_EXPORT id objc_getClass(const char*);
extern OBJCRT_EXPORT Class objc_lookup_class(const char*);
extern OBJCRT_EXPORT const char* class_getName(Class);
extern OBJCRT_EXPORT Class class_getSuperclass(Class);
extern OBJCRT_EXPORT BOOL class_isKindOfClass(Class, Class);
extern OBJCRT_EXPORT unsigned long class_getInstanceSize(Class);
extern OBJCRT_EXPORT BOOL class_respondsToSelector(Class, SEL);
extern OBJCRT_EXPORT BOOL class_conformsToProtocol(Class, Protocol*);
extern OBJCRT_EXPORT Method* class_copyMethodList(Class classRef, unsigned int* outCount);
extern OBJCRT_EXPORT IMP class_getMethodImplementation(Class, SEL);
extern OBJCRT_EXPORT IMP class_replaceMethod(Class, SEL, IMP, const char*);
extern OBJCRT_EXPORT Ivar class_getInstanceVariable(Class cls, const char* name);
extern OBJCRT_EXPORT Ivar* class_copyIvarList(Class cls, unsigned int* outCount);
extern OBJCRT_EXPORT Method class_getInstanceMethod(Class cls, SEL name);
extern OBJCRT_EXPORT Property class_getProperty(Class cls, const char* name);
extern OBJCRT_EXPORT Property* class_copyPropertyList(Class cls, unsigned int* outCount);

extern OBJCRT_EXPORT const char* property_getAttributes(Property property);
extern OBJCRT_EXPORT const char* property_getName(Property property);

extern OBJCRT_EXPORT SEL method_getName(Method m);
extern OBJCRT_EXPORT char* method_copyReturnType(Method m);
extern OBJCRT_EXPORT unsigned int method_getNumberOfArguments(Method m);
extern OBJCRT_EXPORT void method_exchangeImplementations(Method m1, Method m2);
extern OBJCRT_EXPORT IMP method_getImplementation(Method method);
extern OBJCRT_EXPORT IMP method_setImplementation(Method method, IMP imp);
extern OBJCRT_EXPORT const char* method_getTypeEncoding(Method method);

extern OBJCRT_EXPORT ptrdiff_t ivar_getOffset(Ivar ivar);
extern OBJCRT_EXPORT const char* ivar_getName(Ivar ivar);
extern OBJCRT_EXPORT const char* objc_get_type_encoding(Class, SEL);
extern OBJCRT_EXPORT IMP objc_msg_lookup(id, SEL);
extern OBJCRT_EXPORT IMP objc_msg_lookup_super(struct objc_super*, SEL);
extern OBJCRT_EXPORT int objc_getClassList(Class* classes, int maxCount);
extern OBJCRT_EXPORT void* object_getIndexedIvars(id);

extern OBJCRT_EXPORT Class objc_allocateClassPair(Class super, const char* name, size_t extraBytes);
extern OBJCRT_EXPORT void objc_registerClassPair(Class cls);
extern OBJCRT_EXPORT BOOL class_addMethod(Class cls, SEL sel, IMP imp, const char* types);

extern const char* protocol_getName(Protocol*);
extern BOOL protocol_isEqual(Protocol*, Protocol*);
extern BOOL protocol_conformsToProtocol(Protocol*, Protocol*);
extern void objc_thread_add(void);
extern void objc_thread_remove(void);
extern void objc_exit(void);
extern IMP (*objc_forward_handler)(id, SEL);
extern id objc_constructInstance(Class, void*);
extern void* objc_destructInstance(id);
extern id objc_autorelease(id);
extern void* objc_autoreleasePoolPush(void);
extern void objc_autoreleasePoolPop(void*);
extern id _objc_rootAutorelease(id);

extern OBJCRT_EXPORT BOOL objc_isRetained(id obj);
extern OBJCRT_EXPORT size_t objc_getRetainCount(id obj);
extern OBJCRT_EXPORT id objc_retain_ref(id obj);
extern OBJCRT_EXPORT void objc_release_ref(id obj);
id objc_retain_internal_ref(id obj);
void objc_release_internal_ref(id obj);

extern OBJCRT_EXPORT id objc_allocateObject(Class classRef, unsigned int extraBytes);
extern OBJCRT_EXPORT void objc_deallocateObject(id obj);

// Not yet exposed in runtime.h due to conflicting or even missing declarations of objc_associationPolicy.
// extern OBJCRT_EXPORT void objc_setAssociatedObject(id self, void* key, id object, objc_associationPolicy policy);
// extern OBJCRT_EXPORT id objc_getAssociatedObject(id self, void* key);
extern OBJCRT_EXPORT void objc_removeAssociatedObjects(id self);

OBJCRT_EXPORT Class object_getClass(id obj_);
OBJCRT_EXPORT Class object_setClass(id obj_, Class cls);
void _object_setClass(id obj_, Class cls);
OBJCRT_EXPORT void object_setIvar(id object, Ivar ivar, id value);
OBJCRT_EXPORT const char* object_getClassName(id obj);

OBJCRT_EXPORT BOOL class_isMetaClass(Class cls_);

extern OBJCRT_EXPORT id objc_getProperty(id, SEL, ptrdiff_t, BOOL);
extern OBJCRT_EXPORT void objc_setProperty(id, SEL, ptrdiff_t, id, BOOL, signed char);
extern OBJCRT_EXPORT void objc_getPropertyStruct(void*, const void*, ptrdiff_t, BOOL, BOOL);
extern OBJCRT_EXPORT void objc_setPropertyStruct(void*, const void*, ptrdiff_t, BOOL, BOOL);

#undef OBJC_UNSAFE_UNRETAINED
#undef OBJC_BRIDGE

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <algorithm>
namespace std {
// These specializations allow for the use of SEL in STL collections.
template <>
struct equal_to<SEL> {
    bool operator()(const SEL& lhs, const SEL& rhs) const {
        return sel_isEqual(lhs, rhs) == YES;
    }
};

template <>
struct hash<SEL> {
    std::size_t operator()(const SEL& s) const {
        return std::hash<decltype(s->uid)>()(s->uid);
    }
};
}
#endif

#endif
