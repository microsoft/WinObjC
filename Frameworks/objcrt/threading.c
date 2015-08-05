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
#include "threading.h"

static of_rmutex_t global_mutex;
static BOOL global_mutex_init = NO;

static void
objc_global_mutex_new(void)
{
    if (!of_rmutex_new(&global_mutex))
        OBJC_ERROR("Failed to create global mutex!");

    global_mutex_init = YES;
}

void
objc_global_mutex_lock(void)
{
    if (!global_mutex_init)
        objc_global_mutex_new();

    if (!of_rmutex_lock(&global_mutex))
        OBJC_ERROR("Failed to lock global mutex!");
}

void
objc_global_mutex_unlock(void)
{
    if (!of_rmutex_unlock(&global_mutex))
        OBJC_ERROR("Failed to unlock global mutex!");
}

void
objc_global_mutex_free(void)
{
    if (!of_rmutex_free(&global_mutex))
        OBJC_ERROR("Failed to free global mutex!");
}
