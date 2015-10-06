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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>

#include "runtime.h"
#include "runtime-private.h"

#include "winrt-interop.h"
#include <windows.h>

static struct objc_hashtable *classes = NULL;
static Class *load_queue = NULL;
static size_t load_queue_cnt = 0;
static struct objc_sparsearray *empty_dtable = NULL;

static struct objc_hashtable *isas = NULL;

struct winrt_isa *class_isa_for_class(Class cls)
{
    objc_global_mutex_lock();
    if (isas == NULL)
        isas = objc_hashtable_new(2);

    struct winrt_isa *ret = (struct winrt_isa *)objc_hashtable_get_ptr(isas, cls);
    if ( ret == NULL ) {
        ret = (struct winrt_isa *) malloc(sizeof(void *) * 8);

        //  Adjust pointer for realCls offset
        ret = (struct winrt_isa *) (((void **) ret) + 1);
        WINRT_ISA_REALCLS(ret) = cls;
        ret->IW_IInspectable[0] = (void *) _winrt_inspect_QueryInterface;
        ret->IW_IInspectable[1] = (void *) _winrt_inspect_AddRef;
        ret->IW_IInspectable[2] = (void *) _winrt_inspect_Release;
        ret->IW_IInspectable[3] = (void *) _winrt_inspect_GetIids;
        ret->IW_IInspectable[4] = (void *) _winrt_inspect_GetRuntimeClassName;
        ret->IW_IInspectable[5] = (void *) _winrt_inspect_GetTrustLevel;
        ret->IW_IInspectable[6] = (void *) _winrt_iwmsgsend_MsgSend;

        objc_hashtable_set_ptr(isas, cls, ret);
    }

    objc_global_mutex_unlock();

    return ret;
}

static void
register_class(struct objc_abi_class *cls)
{
    if (classes == NULL)
        classes = objc_hashtable_new(2);

    objc_hashtable_set(classes, cls->name, cls);

    if (empty_dtable == NULL)
        empty_dtable = objc_sparsearray_new();

    cls->dtable = empty_dtable;
    struct winrt_isa *isa = class_isa_for_class((Class) cls->metaclass);
    cls->metaclass = isa;
    WINRT_ISA_REALCLS(cls->metaclass)->dtable = empty_dtable;
}

BOOL
class_registerAlias_np(Class cls, const char *name)
{
    if (classes == NULL)
        return NO;

    objc_hashtable_set(classes, name, cls);

    return YES;
}

static void
register_selectors(struct objc_abi_class *cls)
{
    struct objc_abi_method_list *ml;
    unsigned int i;

    for (ml = cls->methodlist; ml != NULL; ml = ml->next)
        for (i = 0; i < ml->count; i++)
            objc_register_selector(
                (struct objc_abi_selector*)&ml->methods[i]);
}

Class
objc_classname_to_class(const char *name)
{
    Class c;

    if (classes == NULL)
        return Nil;

    objc_global_mutex_lock();
    c = (Class)objc_hashtable_get(classes, name);
    objc_global_mutex_unlock();

    return c;
}

static void
call_method(Class cls, const char *method)
{
    struct objc_method_list *ml;
    SEL selector;
    unsigned int i;

    selector = sel_registerName(method);

    for (ml = object_getClass((id) cls)->methodlist; ml != NULL; ml = ml->next)
        for (i = 0; i < ml->count; i++)
            if (sel_isEqual((SEL)&ml->methods[i].sel, selector))
                ((void(*)(id, SEL))ml->methods[i].imp)((id) cls,
                    selector);
}

static BOOL
has_load(Class cls)
{
    struct objc_method_list *ml;
    SEL selector;
    unsigned int i;

    selector = sel_registerName("load");

    for (ml = object_getClass((id) cls)->methodlist; ml != NULL; ml = ml->next)
        for (i = 0; i < ml->count; i++)
            if (sel_isEqual((SEL)&ml->methods[i].sel, selector))
                return YES;

    return NO;
}

static void
call_load(Class cls)
{
    if (cls->info & OBJC_CLASS_INFO_LOADED)
        return;

    if (cls->superclass != Nil)
        call_load(cls->superclass);

    call_method(cls, "load");

    cls->info |= OBJC_CLASS_INFO_LOADED;
}

void
objc_update_dtable(Class cls)
{
    struct objc_method_list *ml;
    struct objc_category **cats;
    unsigned int i;

    if (!(cls->info & OBJC_CLASS_INFO_DTABLE))
        return;

    if (cls->dtable == empty_dtable)
        cls->dtable = objc_sparsearray_new();

    if (cls->superclass != Nil)
        objc_sparsearray_copy(cls->dtable, cls->superclass->dtable);

    for (ml = cls->methodlist; ml != NULL; ml = ml->next)
        for (i = 0; i < ml->count; i++)
            objc_sparsearray_set(cls->dtable,
                (uint32_t)ml->methods[i].sel.uid,
                ml->methods[i].imp);

    if ((cats = objc_categories_for_class(cls)) != NULL) {
        for (i = 0; cats[i] != NULL; i++) {
            unsigned int j;

            ml = (cls->info & OBJC_CLASS_INFO_CLASS ?
                cats[i]->instance_methods : cats[i]->class_methods);

            for (; ml != NULL; ml = ml->next)
                for (j = 0; j < ml->count; j++)
                    objc_sparsearray_set(cls->dtable,
                        (uint32_t)ml->methods[j].sel.uid,
                        ml->methods[j].imp);
        }
    }

    if (cls->subclass_list != NULL)
        for (i = 0; cls->subclass_list[i] != NULL; i++)
            objc_update_dtable(cls->subclass_list[i]);
}

static void
add_subclass(Class cls)
{
    size_t i;

    if (cls->superclass->subclass_list == NULL) {
        if ((cls->superclass->subclass_list =
            malloc(2 * sizeof(Class))) == NULL)
            OBJC_ERROR("Not enough memory for subclass list of "
                "class %s!", cls->superclass->name);

        cls->superclass->subclass_list[0] = cls;
        cls->superclass->subclass_list[1] = Nil;

        return;
    }

    for (i = 0; cls->superclass->subclass_list[i] != Nil; i++);

    cls->superclass->subclass_list =
        realloc(cls->superclass->subclass_list, (i + 2) * sizeof(Class));

    if (cls->superclass->subclass_list == NULL)
        OBJC_ERROR("Not enough memory for subclass list of class %s\n",
            cls->superclass->name);

    cls->superclass->subclass_list[i] = cls;
    cls->superclass->subclass_list[i + 1] = Nil;
}

static void
setup_class(Class cls)
{
    const char *superclass;
    Class metaclass = object_getClass((id) cls);

    if (cls->info & OBJC_CLASS_INFO_SETUP)
        return;

    if ((superclass = ((struct objc_abi_class*)cls)->superclass) != NULL) {
        Class super = Nil;
        // Classes loaded from the image contain a superclass name instead of a superclass. Resolve it.
        if ((cls->info & OBJC_CLASS_INFO_CREATED_RUNTIME) == 0)
        {
            super = objc_classname_to_class(superclass);
        }
        else
        {
            super = (Class) superclass;
        }

        if (super == (Class) nil)
            return;

        setup_class(super);

        if (!(super->info & OBJC_CLASS_INFO_SETUP))
            return;

        cls->superclass = super;
        metaclass->superclass = object_getClass((id) super);

        add_subclass(cls);
        add_subclass(metaclass);
    } else
        metaclass->superclass = cls;

    //  Calculate size based on ivars
    int slide = 0;
    cls->instance_size = -(int) cls->instance_size;
    if ( cls->superclass ) {
        slide = cls->superclass->instance_size;
    }

    if ( slide ) {
        struct objc_ivar_list *list = (struct objc_ivar_list *) cls->ivars;
        if ( list ) {
            //  If first ivar has a negative offset (???) .. increase slide by that amount
            if ( list->count > 0 ) {
                if ( (int) list->ivars[0].offset < 0 ) {
                    printf("Warning: Class %s has first ivar %s with a negative offset of %d!\n", cls->name, list->ivars[0].name, list->ivars[0].offset);
                    slide += -(int) list->ivars[0].offset;
                }
            }

            for ( unsigned i = 0; i < list->count; i ++ ) {
                struct objc_ivar *curIvar = &list->ivars[i];
                curIvar->offset += slide;
                *((int **) cls->ivar_offsets)[i] += slide;
                assert(*((int **) cls->ivar_offsets)[i] == curIvar->offset);
            }
        }
    }
    cls->instance_size += slide;

    cls->info |= OBJC_CLASS_INFO_SETUP;
    metaclass->info |= OBJC_CLASS_INFO_SETUP;
    metaclass->instance_size = sizeof(struct objc_class);
}

static void
initialize_class(Class cls)
{
    if (cls->info & OBJC_CLASS_INFO_INITIALIZED)
        return;

    if (cls->superclass)
        initialize_class(cls->superclass);

    cls->info |= OBJC_CLASS_INFO_DTABLE;
    object_getClass((id) cls)->info |= OBJC_CLASS_INFO_DTABLE;

    objc_update_dtable(cls);
    objc_update_dtable(object_getClass((id) cls));

    /*
     * Set it first to prevent calling it recursively due to message sends
     * in the initialize method
     */
    cls->info |= OBJC_CLASS_INFO_INITIALIZED;
    object_getClass((id) cls)->info |= OBJC_CLASS_INFO_INITIALIZED;

    call_method(cls, "initialize");
}

void
objc_initialize_class(Class cls)
{
    if (cls->info & OBJC_CLASS_INFO_INITIALIZED)
        return;

    objc_global_mutex_lock();

    /*
     * It's possible that two threads try to initialize a class at the same
     * time. Make sure that the thread which held the lock did not already
     * initialize it.
     */
    if (cls->info & OBJC_CLASS_INFO_INITIALIZED) {
        objc_global_mutex_unlock();
        return;
    }

    setup_class(cls);

    if (!(cls->info & OBJC_CLASS_INFO_SETUP)) {
        objc_global_mutex_unlock();
        return;
    }

    initialize_class(cls);

    objc_global_mutex_unlock();
}

void
objc_register_all_classes(struct objc_abi_symtab *symtab)
{
    uint_fast32_t i;

    for (i = 0; i < symtab->cls_def_cnt; i++) {
        struct objc_abi_class *cls =
            (struct objc_abi_class*)symtab->defs[i];

        register_class(cls);
        register_selectors(cls);
        register_selectors((struct objc_abi_class *) object_getClass((id) cls));
    }

    for (i = 0; i < symtab->cls_def_cnt; i++) {
        Class cls = (Class)symtab->defs[i];

        if (has_load(cls)) {
            setup_class(cls);

            if (cls->info & OBJC_CLASS_INFO_SETUP)
                call_load(cls);
            else {
                if (load_queue == NULL)
                    load_queue = malloc(sizeof(Class));
                else
                    load_queue = realloc(load_queue,
                        sizeof(Class) *
                        (load_queue_cnt + 1));

                if (load_queue == NULL)
                    OBJC_ERROR("Not enough memory for load "
                        "queue!");

                load_queue[load_queue_cnt++] = cls;
            }
        } else
            cls->info |= OBJC_CLASS_INFO_LOADED;
    }

    /* Process load queue */
    for (i = 0; i < load_queue_cnt; i++) {
        setup_class(load_queue[i]);

        if (load_queue[i]->info & OBJC_CLASS_INFO_SETUP) {
            call_load(load_queue[i]);

            load_queue_cnt--;

            if (load_queue_cnt == 0) {
                free(load_queue);
                load_queue = NULL;
                continue;
            }

            load_queue[i] = load_queue[load_queue_cnt];

            load_queue = realloc(load_queue,
                sizeof(Class) * load_queue_cnt);

            if (load_queue == NULL)
                OBJC_ERROR("Not enough memory for load queue!");
        }
    }
}

Class
objc_lookup_class(const char *name)
{
    Class cls = objc_classname_to_class(name);

    if (cls == NULL)
        return Nil;

    if (cls->info & OBJC_CLASS_INFO_SETUP)
        return cls;

    objc_global_mutex_lock();

    setup_class(cls);

    objc_global_mutex_unlock();

    if (!(cls->info & OBJC_CLASS_INFO_SETUP))
        return Nil;

    return cls;
}

id
objc_getClass(const char *name)
{
    return objc_lookup_class(name);
}

const char*
class_getName(Class cls)
{
    return cls->name;
}

Class
class_getSuperclass(Class cls)
{
    objc_initialize_class(cls);
    return cls->superclass;
}

BOOL
class_isKindOfClass(Class cls1, Class cls2)
{
    objc_initialize_class(cls1);
    objc_initialize_class(cls2);

    Class iter;

    for (iter = cls1; iter != Nil; iter = iter->superclass)
        if (iter == cls2)
            return YES;

    return NO;
}

unsigned long
class_getInstanceSize(Class cls)
{
    objc_initialize_class(cls);

    return cls->instance_size;
}

Ivar
class_getInstanceVariable(Class cls, const char *name)
{
    objc_initialize_class(cls);

    struct objc_ivar_list *list = (struct objc_ivar_list *) cls->ivars;
    if ( list ) {
        for ( unsigned i = 0; i < list->count; i ++ ) {
            struct objc_ivar *curIvar = &list->ivars[i];

            if ( strcmp(curIvar->name, name) == 0 ) {
                return curIvar;
            }
        }
    }

    return NULL;
}

Ivar* class_copyIvarList(Class cls, unsigned int* outCount)
{
    unsigned int count = 0;
    size_t size = 0;
    if (cls->ivars)
    {
        count = cls->ivars->count;
        size = sizeof(Ivar) * cls->ivars->count;
    }

    if (outCount)
    {
        *outCount = count;
    }

    if (size == 0)
    {
        return NULL;
    }

    Ivar* ivs = malloc(size);
    for (unsigned i = 0; i < count; ++i)
    {
        ivs[i] = &cls->ivars->ivars[i];
    }
    return ivs;
}

ptrdiff_t ivar_getOffset(Ivar ivar)
{
    return ivar->offset;
}

const char* ivar_getName(Ivar ivar)
{
    return ivar->name;
}

OBJCRT_EXPORT IMP
class_getMethodImplementation(Class cls, SEL sel)
{
    return objc_sparsearray_get(cls->dtable, (uint32_t)sel->uid);
}

OBJCRT_EXPORT BOOL object_isMethodFromClass(id dwObj, SEL pSel, const char *fromClass)
{
    Class pClass = object_getClass(dwObj);
    char *clsname = NULL;

    while ( pClass != NULL ) {
        clsname = (char *) pClass->name;

        struct objc_method_list *methodList = pClass->methodlist;

        while ( methodList != NULL ) {
            for ( unsigned i = 0; i < methodList->count; i ++ ) {
                if ( methodList->methods[i].sel.uid == pSel->uid ) {
                    if ( strcmp(clsname, fromClass) == 0 ) {
                        return TRUE;
                    } else {
                        return FALSE;
                    }
                }
            }

            methodList = methodList->next;
        }

        pClass = pClass->superclass;
    }

    return FALSE;
}

const char*
objc_get_type_encoding(Class cls, SEL sel)
{
    struct objc_method_list *ml;
    struct objc_category **cats;
    unsigned int i;

    objc_global_mutex_lock();

    for (ml = cls->methodlist; ml != NULL; ml = ml->next) {
        for (i = 0; i < ml->count; i++) {
            if (ml->methods[i].sel.uid == sel->uid) {
                const char *ret = ml->methods[i].sel.types;
                objc_global_mutex_unlock();
                return ret;
            }
        }
    }

    if ((cats = objc_categories_for_class(cls)) != NULL) {
        for (; *cats != NULL; cats++) {
            for (ml = (*cats)->instance_methods; ml != NULL;
                ml = ml->next) {
                for (i = 0; i < ml->count; i++) {
                    if (ml->methods[i].sel.uid ==
                        sel->uid) {
                        const char *ret =
                            ml->methods[i].sel.types;
                        objc_global_mutex_unlock();
                        return ret;
                    }
                }
            }
        }
    }

    objc_global_mutex_unlock();

    return NULL;
}

Method *class_copyMethodList(Class classRef, unsigned int *outCount) 
{
    struct objc_method_list *mi = classRef->methodlist;

    unsigned max = 0;
    while ( mi != NULL ) {
        max += mi->count;
        mi = mi->next;
    }

    //  [POTENTIAL BUG: This memory will be free'd by the caller, which may cause CRT difficulties.]
    Method *ret = (Method *) malloc(sizeof(Method) * max);

    objc_global_mutex_lock();
    unsigned  count = 0;
    mi = classRef->methodlist;
    while ( mi != NULL ) {
        for ( unsigned i = 0; i < mi->count; i ++ ) {
            assert(count < max);
            if ( count < max ) {
                ret[count ++] = &mi->methods[i];
            }
        }
        mi = mi->next;
    }

    objc_global_mutex_unlock();

    if ( outCount ) *outCount = count;

    return ret;
}

// INVARIANT: This must happen under lock.
IMP _class_lookupMethodImplementation(Class cls, SEL sel, struct objc_method **outMethod) {
	struct objc_method *method = NULL;
	struct objc_method_list *ml;
	struct objc_category **cats;
	unsigned int i;

    for (ml = cls->methodlist; ml != NULL; ml = ml->next)
    {
        for (i = 0; i < ml->count; i++)
        {
            if (ml->methods[i].sel.uid == sel->uid)
            {
                method = &ml->methods[i];
                goto out;
            }
        }
    }

    if ((cats = objc_categories_for_class(cls)) != NULL)
    {
        for (; *cats != NULL; cats++)
        {
            if (cls->info & OBJC_CLASS_INFO_METACLASS)
                ml = (*cats)->class_methods;
            else
                ml = (*cats)->instance_methods;

            for (; ml != NULL; ml = ml->next)
            {
                for (i = 0; i < ml->count; i++)
                {
                    if (ml->methods[i].sel.uid ==
                        sel->uid)
                    {
                        method = &ml->methods[i];
                        goto out;
                    }
                }
            }
        }
    }

out:
	if(method) {
		if(outMethod) {
			*outMethod = method;
		}
		return method->imp;
	}

	return (IMP)nil;
}

Method 
class_getInstanceMethod(Class cls, SEL name)
{
    objc_global_mutex_lock();
    objc_initialize_class(cls);
    Method m = NULL;
    _class_lookupMethodImplementation(cls, name, &m);
    objc_global_mutex_unlock();
    return m;
}

// Add a method to a class, unconditionally
void
_class_addMethod(Class cls, SEL sel, IMP newimp, const char *types)
{
	struct objc_method_list *ml;
	/* FIXME: We need a way to free this at objc_exit() */
	if((ml = malloc(sizeof(struct objc_method_list))) == NULL)
		OBJC_ERROR("Not enough memory to add a new method!");
    objc_global_mutex_lock();

    ml->next = cls->methodlist;
    ml->count = 1;
    ml->methods[0].sel.uid = sel->uid;
    ml->methods[0].sel.types = types;
    ml->methods[0].imp = newimp;

    cls->methodlist = ml;

    objc_update_dtable(cls);

    objc_global_mutex_unlock();
}

IMP
class_replaceMethod(Class cls, SEL sel, IMP newimp, const char *types) {
	struct objc_method *meth = NULL;
	objc_global_mutex_lock();
	IMP oldImp = _class_lookupMethodImplementation(cls, sel, &meth);
	if(oldImp) {
		meth->imp = newimp;
		objc_global_mutex_unlock();
		return oldImp;
	} else {
		_class_addMethod(cls, sel, newimp, types);
		objc_global_mutex_unlock();
		return (IMP)nil;
	}
}

OBJCRT_EXPORT BOOL class_addMethod(Class cls, SEL sel, IMP imp, const char *types)
{
    objc_global_mutex_lock();
    IMP oldImp = _class_lookupMethodImplementation(cls, sel, NULL);
    if ( oldImp )
    {
        objc_global_mutex_unlock();
        return NO;
    }

    _class_addMethod(cls, sel, imp, types);
    objc_global_mutex_unlock();
    return YES;
}


static void
free_class(Class rcls)
{
    struct objc_abi_class *cls = (struct objc_abi_class*)rcls;

    if (rcls->subclass_list != NULL) {
        free(rcls->subclass_list);
        rcls->subclass_list = NULL;
    }

    if (rcls->dtable != NULL && rcls->dtable != empty_dtable)
        objc_sparsearray_free(rcls->dtable);

    rcls->dtable = NULL;

    if (rcls->superclass != Nil)
        cls->superclass = rcls->superclass->name;
}

void
objc_free_all_classes(void)
{
    uint32_t i;

    if (classes == NULL)
        return;

    for (i = 0; i <= classes->last_idx; i++) {
        if (classes->data[i] != NULL) {
            free_class((Class)classes->data[i]->obj);
            free_class(object_getClass((id) classes->data[i]->obj));
        }
    }

    objc_hashtable_free(classes);
    classes = NULL;
}

Class
object_getClass(id obj_)
{
    struct objc_object *obj = (struct objc_object*)obj_;

    /* [HACK: blamb] 
     * 
     * Global block are emitted by the compiler as const structs, which can't directly
     * address variables imported from DLLs.  The isa member of the emitted block
     * will point to the DLL import table, which is patched with the actual address
     * of the imported symbol.  The loader (afaik) can't/won't patch
     * the isa member when it gets resolved at load time.
     *
     * To get around this, we check to see if the isa of the Class of the object
     * points to _NSConcreteGlobalBlock.  If it does, we'll do the extra deref here 
     * to get the object of the class. 
     */

    if ( obj && obj->isa ) {
        extern struct winrt_isa _NSConcreteGlobalBlock;

        if ( ((Class) obj->isa)->isa == &_NSConcreteGlobalBlock ) {
            return (Class) WINRT_ISA_REALCLS(&_NSConcreteGlobalBlock);
        }
        return WINRT_ISA_REALCLS(obj->isa);
    } else {
        return nil;
    }
}

//  Sets an object's class without reading back the previous isa - needed for
//  objects which do not have a valid isa set
void _object_setClass(id obj_, Class cls)
{
    struct objc_object *obj = (struct objc_object*)obj_;

    obj->isa = class_isa_for_class(cls);
}

Class
object_setClass(id obj_, Class cls)
{
    struct objc_object *obj = (struct objc_object*)obj_;
    Class old = nil;

    if ( obj->isa ) {
        old = WINRT_ISA_REALCLS(obj->isa);
    }

    obj->isa = class_isa_for_class(cls);

    return old;
}

const char*
object_getClassName(id obj)
{
    return class_getName(object_getClass(obj));
}

BOOL
class_isMetaClass(Class cls_)
{
    struct objc_class *cls = (struct objc_class*)cls_;

    return (cls->info & OBJC_CLASS_INFO_METACLASS);
}

SEL method_getName(Method m)
{
    return &m->sel;
}

void method_exchangeImplementations(Method m1, Method m2)
{
    objc_global_mutex_lock();
    IMP tmp = m1->imp;
    m1->imp = m2->imp;
    m2->imp = tmp;
    objc_global_mutex_unlock();
}

char *method_copyReturnType(Method m)
{
    const char *curArg = m->sel.types;

    const char *typeStart = curArg;

    switch ( *typeStart ) {
        case '{': {
            int curCount = 0;
            while ( *curArg ) {
                if ( *curArg == '{' ) {
                    curCount ++;
                }
                if ( *curArg == '}' ) {
                    curCount --;
                    if ( curCount == 0 ) break;
                }
                curArg ++;
            }
            while ( *curArg && !isdigit(*curArg) ) curArg ++;
        }
            break;

        default: {
            int curCount = 0;
            while ( *curArg ) {
                if ( *curArg == '{' ) {
                    curCount ++;
                }
                if ( *curArg == '}' ) {
                    curCount --;
                    assert(curCount >= 0);
                }
                if ( isdigit(*curArg) && curCount == 0 ) break;
                curArg ++;
            }
        }
            break;
    }

    const char *typeEnd = curArg;

    int typeLength = typeEnd - typeStart;

    while ( *curArg && isdigit(*curArg) ) curArg ++;

    const char *argOffsetEnd = curArg;

    int offsetLength = argOffsetEnd - typeEnd;

    assert(typeLength > 0);
    assert(offsetLength > 0);

    if ( typeLength > 0 ) {
        char *ret = (char *) calloc(typeLength + 1, 1);
        memcpy(ret, typeStart, typeLength);
        ret[typeLength] = 0;
        return ret;
    } else {
        return NULL;
    }
}

unsigned int method_getNumberOfArguments(Method m)
{
    const char *curArg = m->sel.types;
    unsigned int argCount = 0;
    BOOL returnTypeFound = FALSE;

    while ( *curArg ) {
        const char *typeStart = curArg;

        switch ( *typeStart ) {
            case '{': {
                int curCount = 0;
                while ( *curArg ) {
                    if ( *curArg == '{' ) {
                        curCount ++;
                    }
                    if ( *curArg == '}' ) {
                        curCount --;
                        if ( curCount == 0 ) break;
                    }
                    curArg ++;
                }
                while ( *curArg && !isdigit(*curArg) ) curArg ++;
            }
                break;

            default: {
                int curCount = 0;
                while ( *curArg ) {
                    if ( *curArg == '{' ) {
                        curCount ++;
                    }
                    if ( *curArg == '}' ) {
                        curCount --;
                        assert(curCount >= 0);
                    }
                    if ( isdigit(*curArg) && curCount == 0 ) break;
                    curArg ++;
                }
            }
                break;
        }

        const char *typeEnd = curArg;

        int typeLength = typeEnd - typeStart;

        while ( *curArg && isdigit(*curArg) ) curArg ++;

        const char *argOffsetEnd = curArg;

        int offsetLength = argOffsetEnd - typeEnd;

        assert(typeLength > 0);
        assert(offsetLength > 0);

        if ( !returnTypeFound ) {
            returnTypeFound = TRUE;
        } else {
            argCount ++;
        }
    }

    return argCount;
}

int objc_getClassList(Class *classesRet, int maxCount)
{
    if (classes == NULL) {
        return 0;
    }

    objc_global_mutex_lock();
    int ret = 0;

    uint32_t i;

    for (i = 0; i <= classes->last_idx; i++) {
        if (classes->data[i] != NULL) {
            if ( classesRet && maxCount > 0 ) {
                *classesRet = (Class) classes->data[i]->obj;
                classesRet ++;
                maxCount --;
            }

            ret ++;
        }
    }

    objc_global_mutex_unlock();

    return ret;
}

OBJCRT_EXPORT void
objc_enumerationMutation(id object)
{
    //enumeration_mutation_handler(object);
    assert(0);
}

OBJCRT_EXPORT id objc_get_class(const char *cls)
{
    return (id) objc_lookup_class(cls);
}

OBJCRT_EXPORT Class objc_allocateClassPair(Class super, const char *name, size_t extraBytes)
{
    // Per API contract: If the class name already exists,
    // the runtime refuses to create a new one.
    if (objc_classname_to_class(name) != Nil)
    {
        return Nil;
    }
    // allocate the metaclass and the class, back-to-back.
    size_t size = sizeof(struct objc_class) +        // Metaclass
        OBJC_ID_PADDED(sizeof(struct objc_class)) +  // Class + Alignment Padding
        extraBytes;
    Class newClasses = calloc(1, size);

    newClasses[0].name = newClasses[1].name = _strdup(name);
    newClasses[0].dtable = newClasses[1].dtable = empty_dtable;
    newClasses[0].info |= OBJC_CLASS_INFO_METACLASS | OBJC_CLASS_INFO_CREATED_RUNTIME;
    newClasses[1].info |= OBJC_CLASS_INFO_CLASS | OBJC_CLASS_INFO_CREATED_RUNTIME;
    newClasses[1].superclass = super;
    _object_setClass((id) &newClasses[1], &newClasses[0]);
    return &newClasses[1];
}

OBJCRT_EXPORT void objc_registerClassPair(Class cls)
{
    objc_global_mutex_lock();
    // metaclass super is set up by setup_class.
    setup_class(cls);

    objc_hashtable_set(classes, cls->name, cls);

    initialize_class(cls);
    objc_global_mutex_unlock();
}

OBJCRT_EXPORT void *object_getIndexedIvars(id obj)
{
    return (void *) ((uint8_t *) obj + OBJC_ID_PADDED(class_getInstanceSize(object_getClass(obj))));
}
