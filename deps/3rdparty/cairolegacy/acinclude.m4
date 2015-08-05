dnl -*- mode: autoconf -*-

dnl [m4_newline] didn't appear until autoconf 2.62
m4_ifdef([m4_newline],,[m4_define([m4_newline],[
])])

dnl These are not available in autoconf 2.59

m4_ifdef([m4_foreach_w],,[m4_define([m4_foreach_w],
[m4_foreach([$1], m4_split(m4_normalize([$2]), [ ]), [$3])])])

m4_ifdef([AS_CASE],,[
m4_define([_AS_CASE],
[m4_if([$#], 0, [m4_fatal([$0: too few arguments: $#])],
       [$#], 1, [  *) $1 ;;],
       [$#], 2, [  $1) m4_default([$2], [:]) ;;],
       [  $1) m4_default([$2], [:]) ;;
$0(m4_shift2($@))])dnl
])
m4_defun([AS_CASE],
[m4_ifval([$2$3],
[case $1 in
_AS_CASE(m4_shift($@))
esac
])dnl
])# AS_CASE
])

m4_ifdef([m4_shift2],, [m4_define([m4_shift2], [m4_shift(m4_shift($@))])])


dnl ==========================================================================

dnl This has to be in acinclude.m4 as it includes other files

dnl Parse Version.mk and declare m4 variables out of it
m4_define([CAIRO_PARSE_VERSION],dnl
		m4_translit(dnl
		m4_bpatsubst(m4_include(cairo-version.h),
			     [^.define \([a-zA-Z0-9_]*\)  *\([0-9][0-9]*\)],
			     [[m4_define(\1, \2)]]),
			    [A-Z], [a-z])dnl
)dnl

dnl ==========================================================================

m4_pattern_forbid([^cr_])

dnl AC_AUTOCONF_VERSION was introduced in 2.62, so its definition works as
dnl a conditional on version >= 2.62.  Older versions did not call
dnl m4_pattern_allow from AC_DEFINE and friends.  To avoid lots of warnings we
dnl only forbid CAIRO_ if autoconf is recent enough.
m4_ifdef([AC_AUTOCONF_VERSION],
[m4_pattern_forbid([CAIRO])],
[m4_pattern_forbid([_CAIRO])])
