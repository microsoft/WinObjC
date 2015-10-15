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

#include "runtime.h"
#include "runtime-private.h"

#include "winrt-interop.h"
#include <windows.h>

IMP (*objc_forward_handler)(id, SEL) = NULL;

IMP objc_not_found_handler(id obj, SEL sel) {
    BOOL is_class = object_getClass(obj)->info & OBJC_CLASS_INFO_METACLASS;

    if (!(object_getClass(obj)->info & OBJC_CLASS_INFO_INITIALIZED)) {
        Class cls = (is_class ? (Class)obj : object_getClass(obj));

        objc_initialize_class(cls);

        if (!(cls->info & OBJC_CLASS_INFO_SETUP)) {
            if (is_class)
                return objc_msg_lookup(nil, sel);
            else
                OBJC_ERROR(
                    "Could not dispatch message for "
                    "incomplete class %s!",
                    cls->name);
        }

        /*
         * We don't need to handle the case that super was called.
         * The reason for this is that a call to super is not possible
         * before a message to the class has been sent and it thus has
         * been initialized together with its superclasses.
         */
        return objc_msg_lookup(obj, sel);
    }

    if (objc_forward_handler != NULL)
        return objc_forward_handler(obj, sel);

    OBJC_NOT_IMPLEMENTED_ERROR("Selector %c[%s] is not implemented for class %s on object 0x%x!",
                               (is_class ? '+' : '-'),
                               sel_getName(sel),
                               object_getClassName(obj),
                               obj);
}

BOOL class_respondsToSelector(Class cls, SEL sel) {
    if (cls == Nil)
        return NO;

    return (objc_sparsearray_get(cls->dtable, (uint32_t)sel->uid) != NULL ? YES : NO);
}

#ifndef OF_ASM_LOOKUP
static id nil_method(id self, SEL _cmd) {
    return nil;
}

OBJCRT_EXPORT IMP objc_msg_lookup(id obj, SEL sel) {
    IMP imp;

    if (obj == nil)
        return (IMP)nil_method;

    if (object_isWinRT(obj)) {
        // for debugging:
        const char* name = sel_getName(sel);

        return object_getWinRTImp(obj, name);
    }

    imp = objc_sparsearray_get(object_getClass(obj)->dtable, (uint32_t)sel->uid);

    if (imp == NULL)
        return objc_not_found_handler(obj, sel);

    return imp;
}

OBJCRT_EXPORT IMP objc_msg_lookup_stret(id obj, SEL sel) {
    IMP imp;

    if (obj == nil)
        return (IMP)nil_method;

    if (object_isWinRT(obj)) {
        // for debugging:
        const char* name = sel_getName(sel);

        return object_getWinRTImp(obj, name);
    }

    imp = objc_sparsearray_get(object_getClass(obj)->dtable, (uint32_t)sel->uid);

    if (imp == NULL)
        return objc_not_found_handler(obj, sel);

    return imp;
}

OBJCRT_EXPORT IMP objc_msg_lookup_super(struct objc_super* super, SEL sel) {
    IMP imp;

    if (super->self == nil)
        return (IMP)nil_method;

    imp = objc_sparsearray_get(super->cls->dtable, (uint32_t)sel->uid);

    if (imp == NULL)
        return objc_not_found_handler(super->self, sel);

    return imp;
}

OBJCRT_EXPORT IMP objc_msg_lookup_super_stret(struct objc_super* super, SEL sel) {
    IMP imp;

    if (super->self == nil)
        return (IMP)nil_method;

    imp = objc_sparsearray_get(super->cls->dtable, (uint32_t)sel->uid);

    if (imp == NULL)
        return objc_not_found_handler(super->self, sel);

    return imp;
}
#endif
