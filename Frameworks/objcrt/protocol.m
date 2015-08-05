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

#include <string.h>

#import "runtime.h"
#import "runtime-private.h"

@implementation Protocol
@end

inline const char*
protocol_getName(Protocol *p)
{
    return p->name;
}

inline BOOL
protocol_isEqual(Protocol *a, Protocol *b)
{
    return !strcmp(protocol_getName(a), protocol_getName(b));
}

BOOL
protocol_conformsToProtocol(Protocol *a, Protocol *b)
{
    struct objc_protocol_list *pl;
    size_t i;

    if (protocol_isEqual(a, b))
        return YES;

    for (pl = a->protocol_list; pl != NULL; pl = pl->next)
        for (i = 0; i < pl->count; i++)
            if (protocol_conformsToProtocol(pl->list[i], b))
                return YES;

    return NO;
}

BOOL
class_conformsToProtocol(Class cls, Protocol *p)
{
    struct objc_protocol_list *pl;
    struct objc_category **cats;
    long i, j;

    for (pl = cls->protocols; pl != NULL; pl = pl->next)
        for (i = 0; i < pl->count; i++)
            if (protocol_conformsToProtocol(pl->list[i], p))
                return YES;

    objc_global_mutex_lock();

    if ((cats = objc_categories_for_class(cls)) == NULL) {
        objc_global_mutex_unlock();
        return NO;
    }

    for (i = 0; cats[i] != NULL; i++) {
        for (pl = cats[i]->protocols; pl != NULL; pl = pl->next) {
            for (j = 0; j < pl->count; j++) {
                if (protocol_conformsToProtocol(
                    pl->list[j], p)) {
                    objc_global_mutex_unlock();
                    return YES;
                }
            }
        }
    }

    objc_global_mutex_unlock();

    return NO;
}
