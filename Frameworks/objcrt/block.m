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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "runtime.h"
#include "runtime-private.h"
#include "block.h"

#include "winrt-interop.h"
#include <windows.h>
#undef interface

#define OF_RETAIN_COUNT_MAX 0x7FFFFFFF

typedef struct of_block_byref_t of_block_byref_t;
struct of_block_byref_t {
    WinRT_isa isa;
    of_block_byref_t *forwarding;
    int flags;
    int size;
    void (*byref_keep)(void *dest, void *src);
    void (*byref_dispose)(void*);
};

enum {
    OF_BLOCK_HAS_COPY_DISPOSE = (1 << 25),
    OF_BLOCK_HAS_CTOR     = (1 << 26),
    OF_BLOCK_IS_GLOBAL    = (1 << 28),
    OF_BLOCK_HAS_STRET    = (1 << 29),
    OF_BLOCK_HAS_SIGNATURE    = (1 << 30),
};
#define OF_BLOCK_REFCOUNT_MASK 0xFFFF

enum {
    OF_BLOCK_FIELD_IS_OBJECT =   3,
    OF_BLOCK_FIELD_IS_BLOCK  =   7,
    OF_BLOCK_FIELD_IS_BYREF  =   8,
    OF_BLOCK_FIELD_IS_WEAK   =  16,
    OF_BLOCK_BYREF_CALLER    = 128,
};

extern void __objc_exec_class(struct objc_abi_module*);

/* Begin of ObjC module */
static struct objc_abi_class _NSConcreteStackBlock_metaclass = {
    (void*)"NSBlock", "NSBlock", "NSStackBlock", 8,
    OBJC_CLASS_INFO_METACLASS, sizeof(struct objc_abi_class), NULL, NULL
};

struct objc_abi_class _NSConcreteStackBlockCls = {
    &_NSConcreteStackBlock_metaclass, "NSBlock", "NSStackBlock", 8,
    OBJC_CLASS_INFO_CLASS, sizeof(of_block_literal_t), NULL, NULL
};

//  The layout of _block_isa is absolutely critical - we have to separate out the real
//  isa pointer and the IInspectable interface definitions so that the pointer
//  for _NSConcrete*Block works correctly.
//
//  Don't add members in between or change the order of _NSConcrete*BlockRealIsa and _NSConcrete*Block!
#pragma section("_block_isa",read)

__declspec(allocate("_block_isa"))
void *_NSConcreteStackBlockRealIsa = (void *) &_NSConcreteStackBlockCls;
__declspec(allocate("_block_isa"))
struct winrt_isa _NSConcreteStackBlock = {
    { 
        (void *) _winrt_inspect_QueryInterface,
        (void *) _winrt_inspect_AddRef,
        (void *) _winrt_inspect_Release,
        (void *) _winrt_inspect_GetIids,
        (void *) _winrt_inspect_GetRuntimeClassName,
        (void *) _winrt_inspect_GetTrustLevel,
        (void *) _winrt_iwmsgsend_MsgSend,
    },
};

static struct objc_abi_class _NSConcreteGlobalBlock_metaclass = {
    (void*)"NSBlock", "NSBlock", "NSGlobalBlock", 8,
    OBJC_CLASS_INFO_METACLASS, sizeof(struct objc_abi_class), NULL, NULL
};

struct objc_abi_class _NSConcreteGlobalBlockCls = {
    &_NSConcreteGlobalBlock_metaclass, "NSBlock", "NSGlobalBlock",
    8, OBJC_CLASS_INFO_CLASS, sizeof(of_block_literal_t), NULL, NULL
};

__declspec(allocate("_block_isa"))
void *_NSConcreteGlobalBlockRealIsa = (void *) &_NSConcreteGlobalBlockCls;
__declspec(allocate("_block_isa"))
struct winrt_isa _NSConcreteGlobalBlock = {
    { 
        (void *) _winrt_inspect_QueryInterface,
        (void *) _winrt_inspect_AddRef,
        (void *) _winrt_inspect_Release,
        (void *) _winrt_inspect_GetIids,
        (void *) _winrt_inspect_GetRuntimeClassName,
        (void *) _winrt_inspect_GetTrustLevel,
        (void *) _winrt_iwmsgsend_MsgSend,
    },
};

static struct objc_abi_class _NSConcreteMallocBlock_metaclass = {
    (void*)"NSBlock", "NSBlock", "NSMallocBlock", 8,
    OBJC_CLASS_INFO_METACLASS, sizeof(struct objc_abi_class), NULL, NULL
};

struct objc_abi_class _NSConcreteMallocBlockCls = {
    &_NSConcreteMallocBlock_metaclass, "NSBlock", "NSMallocBlock",
    8, OBJC_CLASS_INFO_CLASS, sizeof(of_block_literal_t), NULL, NULL
};

__declspec(allocate("_block_isa"))
void *_NSConcreteMallocBlockRealCls = (void *) &_NSConcreteMallocBlockCls;
__declspec(allocate("_block_isa"))
struct winrt_isa _NSConcreteMallocBlock = {
    { 
        (void *) _winrt_inspect_QueryInterface,
        (void *) _winrt_inspect_AddRef,
        (void *) _winrt_inspect_Release,
        (void *) _winrt_inspect_GetIids,
        (void *) _winrt_inspect_GetRuntimeClassName,
        (void *) _winrt_inspect_GetTrustLevel,
        (void *) _winrt_iwmsgsend_MsgSend,
    },
};

static struct {
    unsigned int unknown;
    struct objc_abi_selector *sel_refs;
    uint16_t cls_def_cnt, cat_def_cnt;
    void *defs[4];
} symtab = {
    0, NULL, 3, 0,
    {
        &_NSConcreteStackBlockCls, &_NSConcreteGlobalBlockCls,
        &_NSConcreteMallocBlockCls, NULL
    }
};

static struct objc_abi_module module = {
    8, sizeof(module), NULL, (struct objc_abi_symtab*)&symtab
};

#pragma section(".CRT$XCU",read)
static void __cdecl constructor(void);
__declspec(allocate(".CRT$XCU")) void (__cdecl*fconstructor_)(void) = constructor;
static void __cdecl constructor(void)
{
    __objc_exec_class(&module);
}
/* End of ObjC module */

void*
_Block_copy(const void *block_)
{
    of_block_literal_t *block = (of_block_literal_t*)block_;

    if (object_getClass((id)block) == (Class)&_NSConcreteStackBlockCls) {
        of_block_literal_t *copy;

        if ((copy = malloc(block->descriptor->size)) == NULL) {
            assert(0);
        }
        memcpy(copy, block, block->descriptor->size);

        _object_setClass((id)copy, (Class)&_NSConcreteMallocBlockCls);
        copy->flags++;

        if (block->flags & OF_BLOCK_HAS_COPY_DISPOSE)
            block->descriptor->copy_helper(copy, block);

        return copy;
    }

    if (object_getClass((id)block) == (Class)&_NSConcreteMallocBlockCls) {
        InterlockedIncrement((volatile LONG*)&block->flags);
    }

    return block;
}

OBJCRT_EXPORT void
_Block_release(const void *block_)
{
    of_block_literal_t *block = (of_block_literal_t*)block_;

    if (object_getClass((id)block) != (Class)&_NSConcreteMallocBlockCls)
        return;

    if ((InterlockedDecrement((volatile LONG*)&block->flags) & OF_BLOCK_REFCOUNT_MASK) == 0) {
        if (block->flags & OF_BLOCK_HAS_COPY_DISPOSE)
            block->descriptor->dispose_helper(block);

        free(block);
    }
}

OBJCRT_EXPORT void
_Block_object_assign(void *dst_, const void *src_, const int flags_)
{
    int flags = flags_ & (OF_BLOCK_FIELD_IS_BLOCK |
        OF_BLOCK_FIELD_IS_OBJECT | OF_BLOCK_FIELD_IS_BYREF);

    if (src_ == NULL)
        return;

    if (flags_ & OF_BLOCK_BYREF_CALLER)
        return;

    switch (flags) {
    case OF_BLOCK_FIELD_IS_BLOCK:
        *(of_block_literal_t**)dst_ = _Block_copy(src_);
        break;
    case OF_BLOCK_FIELD_IS_OBJECT:
        *(id*)dst_ = [(id)src_ retain];
        break;
    case OF_BLOCK_FIELD_IS_BYREF:;
        of_block_byref_t *src = (of_block_byref_t*)src_;
        of_block_byref_t **dst = (of_block_byref_t**)dst_;

        if ((src->flags & OF_BLOCK_REFCOUNT_MASK) == 0) {
            if ((*dst = malloc(src->size)) == NULL) {
                assert(0);
            }

            src->forwarding = (*dst);
            (*dst)->forwarding = *dst;

            memcpy(*dst, src, src->size);

            if (src->size >= sizeof(of_block_byref_t) && (src->flags & OF_BLOCK_HAS_COPY_DISPOSE) )
                src->byref_keep(*dst, src);
        } else
            *dst = src;

        (*dst)->flags++;
        break;
    }
}

OBJCRT_EXPORT void
_Block_object_dispose(const void *obj_, const int flags_)
{
    const int flags = flags_ & (OF_BLOCK_FIELD_IS_BLOCK |
        OF_BLOCK_FIELD_IS_OBJECT | OF_BLOCK_FIELD_IS_BYREF);

    if (obj_ == NULL)
        return;

    if (flags_ & OF_BLOCK_BYREF_CALLER)
        return;

    switch (flags) {
    case OF_BLOCK_FIELD_IS_BLOCK:
        _Block_release(obj_);
        break;
    case OF_BLOCK_FIELD_IS_OBJECT:
        [(id)obj_ release];
        break;
    case OF_BLOCK_FIELD_IS_BYREF:;
        of_block_byref_t *obj = (of_block_byref_t*)obj_;

        if ((--obj->flags & OF_BLOCK_REFCOUNT_MASK) == 0) {
            if (obj->size >= sizeof(of_block_byref_t) && (obj->flags & OF_BLOCK_HAS_COPY_DISPOSE) )
                obj->byref_dispose(obj);

            free(obj);
        }
        break;
    }
}

@implementation NSBlock
+ alloc
{
    [self doesNotRecognizeSelector: _cmd];
    return nil;
}

- init
{
    [self doesNotRecognizeSelector: _cmd];
    return nil;
}

- retain
{
    if (object_getClass(self) == (Class)&_NSConcreteMallocBlockCls)
        return Block_copy(self);

    return self;
}

- copy
{
    return Block_copy(self);
}

- autorelease
{
    if (object_getClass(self) == (Class)&_NSConcreteMallocBlockCls)
        return [super autorelease];

    return self;
}

- (unsigned int)retainCount
{
    if (object_getClass(self) == (Class)&_NSConcreteMallocBlockCls)
        return ((of_block_literal_t*)self)->flags &
            OF_BLOCK_REFCOUNT_MASK;

    return OF_RETAIN_COUNT_MAX;
}

- (oneway void)release
{
    if (object_getClass(self) == (Class)&_NSConcreteMallocBlockCls)
        Block_release(self);
}

- (void)dealloc
{
    [self doesNotRecognizeSelector: _cmd];
    [super dealloc];    /* Get rid of a stupid warning */
}

- (void) invoke
{
    of_block_literal_t *block = (of_block_literal_t*)self;
    block->invoke(self);
}
@end

OBJCRT_EXPORT id
objc_retainBlock(id block)
{
    return (id)_Block_copy(block);
}
