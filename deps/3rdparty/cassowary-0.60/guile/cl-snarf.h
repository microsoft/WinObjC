/* $id$
 * cl-snarf.h
 * (C) 1999 Greg J. Badros
 */

#ifndef CL_SNARF_H__
#define CL_SNARF_H__

#include <libguile/snarf.h>

/* Can extract comment post-cpp using, e.g.:
gcc -DHAVE_CONFIG_H -I. -I. -I../include -I/usr/X11R6/include -I/uns/include -E -C -DCL_EXTRACT_COMMENTS binding.c
*/

#ifndef CL_EXTRACT_COMMENTS
#ifndef SCM_MAGIC_SNARFER
#define CL_PROC(fname,primname, req, opt, var, ARGLIST, docstring) \
	SCM_PROC(s_ ## fname, primname, req, opt, var, fname); \
SCM fname ARGLIST
#else
#define CL_PROC(fname,primname, req, opt, var, ARGLIST, docstring) \
	SCM_PROC(s_ ## fname, primname, req, opt, var, fname);
#endif
#endif

#endif
