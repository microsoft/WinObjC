/*
 * Copyright (c) 2008, 2009, 2010, 2011, 2012
 *   Jonathan Schleifer <js@webkeks.org>
 *
 * All rights reserved.
 *
 * This file is part of ObjFW. It may be distributed under the terms of the
 * Q Public License 1.0, which can be found in the file LICENSE.QPL included in
 * the packaging of this file.
 *
 * Alternatively, it may be distributed under the terms of the GNU General
 * Public License, either version 2 or 3, which can be found in the file
 * LICENSE.GPLv2 or LICENSE.GPLv3 respectively included in the packaging of this
 * file.
 */

#include <stdio.h>
#include <stdlib.h>

#include "runtime.h"
#include "runtime-private.h"

static struct objc_abi_static_instances **static_instances = NULL;
static size_t static_instances_cnt = 0;

void
objc_init_static_instances(struct objc_abi_symtab *symtab)
{
    struct objc_abi_static_instances **si;
    size_t i;

    /* Check if the class for a static instance became available */
    for (i = 0; i < static_instances_cnt; i++) {
        Class cls = objc_lookup_class(static_instances[i]->class_name);

        if (cls != Nil) {
            id *instances;

            for (instances = static_instances[i]->instances;
                *instances != nil; instances++)
                _object_setClass(*instances, cls);

            static_instances_cnt--;

            if (static_instances_cnt == 0) {
                free(static_instances);
                static_instances = NULL;
                continue;
            }

            static_instances[i] =
                static_instances[static_instances_cnt];

            static_instances = realloc(static_instances,
                sizeof(struct objc_abi_static_instances*) *
                static_instances_cnt);

            if (static_instances == NULL)
                OBJC_ERROR("Not enough memory for list of "
                    "static instances!");
        }
    }

    si = (struct objc_abi_static_instances**)
        symtab->defs[symtab->cls_def_cnt + symtab->cat_def_cnt];

    if (si == NULL)
        return;

    for (; *si != NULL; si++) {
        Class cls = objc_lookup_class((*si)->class_name);

        if (cls != Nil) {
            id *instances;

            for (instances = (*si)->instances; *instances != nil;
                instances++)
                _object_setClass(*instances, cls);
        } else {
            if (static_instances == NULL)
                static_instances = malloc(sizeof(
                    struct objc_abi_static_instances*));
            else
                static_instances = realloc(static_instances,
                    sizeof(struct objc_abi_static_instances*) *
                    (static_instances_cnt + 1));

            if (static_instances == NULL)
                OBJC_ERROR("Not enough memory for list of "
                    "static instances!");

            static_instances[static_instances_cnt++] = *si;
        }
    }
}
