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

//#include "config.h"

#include "runtime.h"
#include "runtime-private.h"

int _objc_methtype;

OBJCRT_EXPORT void
__objc_exec_class(struct objc_abi_module *module)
{
    objc_global_mutex_lock();

    objc_register_all_selectors(module->symtab);
    objc_register_all_classes(module->symtab);
    objc_register_all_categories(module->symtab);
    objc_init_static_instances(module->symtab);

    objc_global_mutex_unlock();
}

void
objc_exit(void)
{
    objc_global_mutex_lock();

    objc_free_all_categories();
    objc_free_all_classes();
    objc_free_all_selectors();
    objc_sparsearray_cleanup();

    objc_global_mutex_unlock();
    objc_global_mutex_free();
}
