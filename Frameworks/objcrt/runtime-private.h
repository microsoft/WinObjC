//******************************************************************************
//
// Copyright (c) 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015
//   Jonathan Schleifer <js@webkeks.org>. All rights reserved.
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

#include <stdlib.h>

struct objc_abi_class {
    struct winrt_isa* metaclass;
    const char* superclass;
    const char* name;
    unsigned long version;
    unsigned long info;
    unsigned long instance_size;
    void* ivars;
    struct objc_abi_method_list* methodlist;
    void* dtable;
    void* subclass_list;
    void* sibling_class;
    void* protocols;
    void* gc_object_type;
    long abi_version;
    void* ivar_offsets;
    void* properties;
};

struct objc_abi_method {
    const char* name;
    const char* types;
    IMP imp;
};

struct objc_abi_method_list {
    struct objc_abi_method_list* next;
    unsigned int count;
    struct objc_abi_method methods[1];
};

struct objc_abi_selector {
    const char* name;
    const char* types;
};

struct objc_abi_category {
    const char* category_name;
    const char* class_name;
    struct objc_abi_method_list* instance_methods;
    struct objc_abi_method_list* class_methods;
    struct objc_protocol_list* protocols;
};

struct objc_abi_method_description {
    const char* name;
    const char* types;
};

struct objc_abi_method_description_list {
    int count;
    struct objc_abi_method_description list[1];
};

struct objc_abi_static_instances {
    const char* class_name;
    id instances[1];
};

struct objc_abi_symtab {
    unsigned long unknown;
    struct objc_abi_selector* sel_refs;
    uint16_t cls_def_cnt;
    uint16_t cat_def_cnt;
    void* defs[1];
};

struct objc_abi_module {
    unsigned long version; /* 9 = non-fragile */
    unsigned long size;
    const char* name;
    struct objc_abi_symtab* symtab;
};

struct objc_hashtable_bucket {
    const char* key;
    const void* obj;
    uint32_t hash;
};

struct objc_hashtable {
    uint32_t count;
    uint32_t last_idx;
    struct objc_hashtable_bucket** data;
};

struct objc_sparsearray {
    struct objc_sparsearray_level2* buckets[256];
};

#ifndef OF_SELUID16
struct objc_sparsearray_level2 {
    struct objc_sparsearray_level3* buckets[256];
    BOOL empty;
};

struct objc_sparsearray_level3 {
    const void* buckets[256];
    BOOL empty;
};
#else
struct objc_sparsearray_level2 {
    const void* buckets[256];
    BOOL empty;
};
#endif

extern void objc_register_all_categories(struct objc_abi_symtab*);
extern struct objc_category** objc_categories_for_class(Class);
extern void objc_free_all_categories(void);
extern void objc_initialize_class(Class);
extern void objc_update_dtable(Class);
extern void objc_register_all_classes(struct objc_abi_symtab*);
extern Class objc_classname_to_class(const char*);
extern void objc_free_all_classes(void);
extern uint32_t objc_hash_string(const char*);
extern struct objc_hashtable* objc_hashtable_new(uint32_t);
extern void objc_hashtable_set(struct objc_hashtable*, const char*, const void*);
extern void objc_hashtable_set_ptr(struct objc_hashtable*, const void*, const void*);
extern void* objc_hashtable_get(struct objc_hashtable*, const char*);
extern void* objc_hashtable_get_ptr(struct objc_hashtable*, const void*);
extern void objc_hashtable_free(struct objc_hashtable* h);
extern void objc_register_selector(struct objc_abi_selector*);
extern void objc_register_all_selectors(struct objc_abi_symtab*);
extern void objc_free_all_selectors(void);
extern struct objc_sparsearray* objc_sparsearray_new(void);
extern void objc_sparsearray_copy(struct objc_sparsearray*, struct objc_sparsearray*);
extern void objc_sparsearray_set(struct objc_sparsearray*, uint32_t, const void*);
extern void objc_sparsearray_free(struct objc_sparsearray*);
extern void objc_sparsearray_cleanup(void);
extern void objc_init_static_instances(struct objc_abi_symtab*);
OBJCRT_EXPORT extern void __objc_exec_class(struct objc_abi_module*);
extern void objc_global_mutex_lock(void);
extern void objc_global_mutex_unlock(void);
extern void objc_global_mutex_free(void);

#ifdef __cplusplus
extern "C" {
#endif
void objc_RaiseNotImplementedException(const char* format, ...);
void objc_RaiseGeneralFailureException(const char* format, ...);
#ifdef __cplusplus
}
#endif

static void* objc_sparsearray_get(const struct objc_sparsearray* s, uint32_t idx) {
#ifndef OF_SELUID16
    uint8_t i = idx >> 16;
    uint8_t j = idx >> 8;
    uint8_t k = idx;

    return (void*)s->buckets[i]->buckets[j]->buckets[k];
#else
    uint8_t i = idx >> 8;
    uint8_t j = idx;

    return (void*)s->buckets[i]->buckets[j];
#endif
}

#define OBJC_PADDED(len, align) ((size_t)((len) + (align)-1) & ~((align)-1))
#define OBJC_ID_PADDED(len) OBJC_PADDED((len), sizeof(id))

#ifdef DEBUG
#define OBJC_ERROR(...)                                                     \
    {                                                                       \
        char buf[1024] = { 0 };                                             \
        sprintf_s(buf, sizeof(buf), "[objc @ " __FILE__ ":%d] ", __LINE__); \
        OutputDebugStringA(buf);                                            \
        sprintf_s(buf, sizeof(buf), __VA_ARGS__);                           \
        OutputDebugStringA(buf);                                            \
                                                                            \
        objc_RaiseGeneralFailureException(__VA_ARGS__);                     \
    }
#define OBJC_NOT_IMPLEMENTED_ERROR(...)                                     \
    {                                                                       \
        char buf[1024] = { 0 };                                             \
        sprintf_s(buf, sizeof(buf), "[objc @ " __FILE__ ":%d] ", __LINE__); \
        OutputDebugStringA(buf);                                            \
        sprintf_s(buf, sizeof(buf), __VA_ARGS__);                           \
        OutputDebugStringA(buf);                                            \
                                                                            \
        if (!getenv("OBJC_APP_BRINGUP")) {                                  \
            objc_RaiseNotImplementedException(__VA_ARGS__);                 \
        }                                                                   \
    }
#else
#define OBJC_ERROR(...) \
    { objc_RaiseGeneralFailureException(__VA_ARGS__); }
#define OBJC_NOT_IMPLEMENTED_ERROR(...) \
    { objc_RaiseNotImplementedException(__VA_ARGS__); }
#endif