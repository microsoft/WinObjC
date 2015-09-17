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

static struct objc_hashtable *categories = NULL;

static void
register_selectors(struct objc_abi_category *cat)
{
    struct objc_abi_method_list *ml;
    unsigned int i;

    for (ml = cat->instance_methods; ml != NULL; ml = ml->next)
        for (i = 0; i < ml->count; i++)
            objc_register_selector(
                (struct objc_abi_selector*)&ml->methods[i]);

    for (ml = cat->class_methods; ml != NULL; ml = ml->next)
        for (i = 0; i < ml->count; i++)
            objc_register_selector(
                (struct objc_abi_selector*)&ml->methods[i]);
}

static void
register_category(struct objc_abi_category *cat)
{
    struct objc_abi_category **cats;
    Class cls = objc_classname_to_class(cat->class_name);

    if (categories == NULL)
        categories = objc_hashtable_new(2);

    cats = (struct objc_abi_category**)objc_hashtable_get(categories,
        cat->class_name);

    if (cats != NULL) {
        struct objc_abi_category **ncats;
        size_t i;

        for (i = 0; cats[i] != NULL; i++);

        if ((ncats = realloc(cats,
            (i + 2) * sizeof(struct objc_abi_category*))) == NULL)
            OBJC_ERROR("Not enough memory for category %s of "
                "class %s!", cat->category_name, cat->class_name);

        ncats[i] = cat;
        ncats[i + 1] = NULL;
        objc_hashtable_set(categories, cat->class_name, ncats);

        if (cls != Nil && cls->info & OBJC_CLASS_INFO_SETUP) {
            objc_update_dtable(cls);
            objc_update_dtable(object_getClass((id) cls));
        }

        return;
    }

    if ((cats = malloc(2 * sizeof(struct objc_abi_category*))) == NULL)
        OBJC_ERROR("Not enough memory for category %s of class %s!\n",
            cat->category_name, cat->class_name);

    cats[0] = cat;
    cats[1] = NULL;
    objc_hashtable_set(categories, cat->class_name, cats);

    if (cls != Nil && cls->info & OBJC_CLASS_INFO_SETUP) {
        objc_update_dtable(cls);
        objc_update_dtable(object_getClass((id) cls));
    }
}

void
objc_register_all_categories(struct objc_abi_symtab *symtab)
{
    struct objc_abi_category **cats;
    size_t i;

    cats = (struct objc_abi_category**)symtab->defs + symtab->cls_def_cnt;

    for (i = 0; i < symtab->cat_def_cnt; i++) {
        register_selectors(cats[i]);
        register_category(cats[i]);
    }
}

struct objc_category**
objc_categories_for_class(Class cls)
{
    if (categories == NULL)
        return NULL;

    return (struct objc_category**)objc_hashtable_get(categories,
        cls->name);
}

void
objc_free_all_categories(void)
{
    uint32_t i;

    if (categories == NULL)
        return;

    for (i = 0; i <= categories->last_idx; i++)
        if (categories->data[i] != NULL)
            free((void*)categories->data[i]->obj);

    objc_hashtable_free(categories);
    categories = NULL;
}
