/* realpath.c
 * $Id$
 *
 * Provides an implementation of the "realpath" function, conforming
 * approximately to SUSv3, and adapted for use on native Microsoft(R)
 * Win32 platforms.
 *
 * Written by Keith Marshall <keithmarshall@users.sourceforge.net>
 *
 * This is free software.  You may redistribute and/or modify it as you
 * see fit, without restriction of copyright.
 *
 * This software is provided "as is", in the hope that it may be useful,
 * but WITHOUT WARRANTY OF ANY KIND, not even any implied warranty of
 * MERCHANTABILITY, nor of FITNESS FOR ANY PARTICULAR PURPOSE.  At no
 * time will the author accept any form of liability for any damages,
 * however caused, resulting from the use of this software.
 *
 */

#include <io.h>
#include <stdlib.h>
#include <errno.h>

#ifndef __cdecl /* If compiling on any non-Win32 platform ... */
#define __cdecl /* this may not be defined.                   */
#endif

char* __cdecl realpath(const char* __restrict name, char* __restrict resolved) {
    char* retname = NULL; /* we will return this, if we fail */

    /* SUSv3 says we must set `errno = EINVAL', and return NULL,
     * if `name' is passed as a NULL pointer.
     */

    if (name == NULL)
        errno = EINVAL;

    /* Otherwise, `name' must refer to a readable filesystem object,
     * if we are going to resolve its absolute path name.
     */

    else if (access(name, 4) == 0) {
        /* If `name' didn't point to an existing entity,
         * then we don't get to here; we simply fall past this block,
         * returning NULL, with `errno' appropriately set by `access'.
         *
         * When we _do_ get to here, then we can use `_fullpath' to
         * resolve the full path for `name' into `resolved', but first,
         * check that we have a suitable buffer, in which to return it.
         */

        if ((retname = resolved) == NULL) {
            /* Caller didn't give us a buffer, so we'll exercise the
             * option granted by SUSv3, and allocate one.
             *
             * `_fullpath' would do this for us, but it uses `malloc', and
             * Microsoft's implementation doesn't set `errno' on failure.
             * If we don't do this explicitly ourselves, then we will not
             * know if `_fullpath' fails on `malloc' failure, or for some
             * other reason, and we want to set `errno = ENOMEM' for the
             * `malloc' failure case.
             */

            retname = malloc(_MAX_PATH);
        }

        /* By now, we should have a valid buffer.
         * If we don't, then we know that `malloc' failed,
         * so we can set `errno = ENOMEM' appropriately.
         */

        if (retname == NULL)
            errno = ENOMEM;

        /* Otherwise, when we do have a valid buffer,
         * `_fullpath' should only fail if the path name is too long.
         */

        else if ((retname = _fullpath(retname, name, _MAX_PATH)) == NULL)
            errno = ENAMETOOLONG;
    }

    /* By the time we get to here,
     * `retname' either points to the required resolved path name,
     * or it is NULL, with `errno' set appropriately, either of which
     * is our required return condition.
     */

    return retname;
}

/* $RCSfile$: end of file */
