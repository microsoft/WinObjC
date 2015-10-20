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

#include "runtime.h"
#include "runtime-private.h"

#include <windows.h>

#ifndef OF_SELUID16
#define SEL_MAX 0xFFFFFF
#else
#define SEL_MAX 0xFFFF
#endif

static struct objc_hashtable* selectors = NULL;
static uint32_t selectors_cnt = 0;
static struct objc_sparsearray* selector_names = NULL;

void objc_register_selector(struct objc_abi_selector* sel) {
    struct objc_selector* rsel;
    const char* name;

    if (selectors == NULL)
        selectors = objc_hashtable_new(2);
    else if ((rsel = objc_hashtable_get(selectors, sel->name)) != NULL) {
        ((struct objc_selector*)sel)->uid = rsel->uid;
        return;
    }

    if (selector_names == NULL)
        selector_names = objc_sparsearray_new();

    name = sel->name;
    rsel = (struct objc_selector*)sel;
    rsel->uid = selectors_cnt++;

    if (selectors_cnt > SEL_MAX)
        OBJC_ERROR("Out of selector slots!");

    objc_hashtable_set(selectors, name, rsel);
    objc_sparsearray_set(selector_names, (uint32_t)rsel->uid, name);
}

SEL sel_registerName(const char* name) {
    const struct objc_abi_selector* rsel;
    struct objc_abi_selector* sel;

    objc_global_mutex_lock();

    if (selectors != NULL && (rsel = objc_hashtable_get(selectors, name)) != NULL) {
        objc_global_mutex_unlock();
        return (SEL)rsel;
    }

    /* FIXME: Free on objc_exit() */
    if ((sel = malloc(sizeof(struct objc_abi_selector))) == NULL)
        OBJC_ERROR("Not enough memory to allocate selector!");

    if ((sel->name = _strdup(name)) == NULL)
        OBJC_ERROR("Not enough memory to allocate selector!");

    sel->types = NULL;

    objc_register_selector(sel);

    objc_global_mutex_unlock();
    return (SEL)sel;
}

void objc_register_all_selectors(struct objc_abi_symtab* symtab) {
    struct objc_abi_selector* sel;

    if (symtab->sel_refs == NULL)
        return;

    for (sel = symtab->sel_refs; sel->name != NULL; sel++)
        objc_register_selector(sel);
}

const char* sel_getName(SEL sel) {
    const char* ret;

    objc_global_mutex_lock();
    ret = objc_sparsearray_get(selector_names, (uint32_t)sel->uid);
    objc_global_mutex_unlock();

    return ret;
}

BOOL sel_isEqual(SEL sel1, SEL sel2) {
    return sel1->uid == sel2->uid;
}

void objc_free_all_selectors(void) {
    objc_hashtable_free(selectors);
    objc_sparsearray_free(selector_names);

    selectors = NULL;
    selectors_cnt = 0;
    selector_names = NULL;
}
