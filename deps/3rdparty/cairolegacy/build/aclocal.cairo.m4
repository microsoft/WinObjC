dnl ==========================================================================
dnl
dnl Cairo-specific macros
dnl

dnl ==========================================================================

dnl Usage:
dnl   CAIRO_BIGENDIAN
dnl
AC_DEFUN([CAIRO_BIGENDIAN],
[dnl
	case $host_os in
		darwin*)
	AH_VERBATIM([X_BYTE_ORDER],
[
/* Deal with multiple architecture compiles on Mac OS X */
#ifdef __APPLE_CC__
#ifdef __BIG_ENDIAN__
#define WORDS_BIGENDIAN 1
#define FLOAT_WORDS_BIGENDIAN 1
#else
#undef WORDS_BIGENDIAN
#undef FLOAT_WORDS_BIGENDIAN
#endif
#endif
])
		;;
		*) 
	AC_C_BIGENDIAN
	AX_C_FLOAT_WORDS_BIGENDIAN
		;;
	esac
])

dnl CAIRO_CHECK_FUNCS_WITH_FLAGS(FUNCTION..., CFLAGS, LIBS
dnl                              [, ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]])
dnl Like AC_CHECK_FUNCS but with additional CFLAGS and LIBS
dnl --------------------------------------------------------------------
AC_DEFUN([CAIRO_CHECK_FUNCS_WITH_FLAGS],
[dnl 
	_save_cflags="$CFLAGS"
	_save_libs="$LIBS"
	CFLAGS="$CFLAGS $2"
	LIBS="$LIBS $3"
	AC_CHECK_FUNCS($1, $4, $5)
	CFLAGS="$_save_cflags"
	LIBS="$_save_libs"
])

dnl CAIRO_CONFIG_COMMANDS is like AC_CONFIG_COMMANDS, except that:
dnl
dnl	1) It redirects the stdout of the command to the file.
dnl	2) It does not recreate the file if contents didn't change.
dnl
AC_DEFUN([CAIRO_CONFIG_COMMANDS],
[dnl
	AC_CONFIG_COMMANDS($1,
	[
		_config_file=$1
		_tmp_file=cairoconf.tmp
		AC_MSG_NOTICE([creating $_config_file])
		{
			$2
		} >> "$_tmp_file" ||
	        AC_MSG_ERROR([failed to write to $_tmp_file])

		if cmp -s "$_tmp_file" "$_config_file"; then
		  AC_MSG_NOTICE([$_config_file is unchanged])
		  rm -f "$_tmp_file"
		else
		  mv "$_tmp_file" "$_config_file" ||
	          AC_MSG_ERROR([failed to update $_config_file])
		fi
	], $3)
])

dnl CAIRO_CC_TRY_LINK_WITH_ENV_SILENT(env-setup, program,
dnl				      true-action, false-action)
dnl
dnl Compile and link the program with the given environment setup.
dnl The global cairo_cc_flag is set to "yes" or "no" according as
dnl the link succeeded or not.  The link step must complete without
dnl warnings or errors to stderr.
dnl
dnl Perform true-action on success and false-action on failure.
dnl The values of CFLAGS, LIBS, LDFLAGS are saved before env-setup
dnl is executed and restored right before the end of the macro.
AC_DEFUN([CAIRO_CC_TRY_LINK_WITH_ENV_SILENT],[dnl
	# AC_LANG_PROGRAM() produces a main() w/o args,
	# but -Wold-style-definition doesn't like that.
	# We need _some_ program so that we don't get
	# warnings about empty compilation units, so always
	# append a reasonable main().
	_compile_program="$2"'
		int main(int c, char **v) { (void)c; (void)v; return 0; }'

	_save_cflags="$CFLAGS"
	_save_ldflags="$LDFLAGS"
	_save_libs="$LIBS"
	$1
	AC_LINK_IFELSE(
		[AC_LANG_SOURCE([$_compile_program])],
		[cairo_cc_stderr=`test -f conftest.err && cat conftest.err`
		 cairo_cc_flag=yes],
		[cairo_cc_stderr=`test -f conftest.err && cat conftest.err`
		 cairo_cc_flag=no])

	if test "x$cairo_cc_stderr" != "x"; then
		cairo_cc_flag=no
	fi

	if test "x$cairo_cc_flag" = "xyes"; then
		ifelse([$3], , :, [$3])
	else
		ifelse([$4], , :, [$4])
	fi
	CFLAGS="$_save_cflags"
	LDFLAGS="$_save_ldflags"
	LIBS="$_save_libs"
])

dnl check compiler flags with a program and no muttering.
AC_DEFUN([CAIRO_CC_TRY_FLAG_SILENT],
[dnl     (flags..., optional program, true-action, false-action)
	CAIRO_CC_TRY_LINK_WITH_ENV_SILENT([CFLAGS="$CFLAGS $1"],
					  [$2], [$3], [$4])
])

dnl find a -Werror equivalent
AC_DEFUN([CAIRO_CC_CHECK_WERROR],
[dnl
	_test_WERROR=${WERROR+set}
	if test "z$_test_WERROR" != zset; then
		WERROR=""
		for _werror in -Werror -errwarn; do
			AC_MSG_CHECKING([whether $CC supports $_werror])
			CAIRO_CC_TRY_FLAG_SILENT(
				[$_werror],,
				[WERROR="$WERROR $_werror"],
				[:])
			AC_MSG_RESULT($cairo_cc_flag)
		done
	fi
])

dnl check compiler flags possibly using -Werror if available.
AC_DEFUN([CAIRO_CC_TRY_FLAG],
[dnl     (flags..., optional program, true-action, false-action)
	CAIRO_CC_CHECK_WERROR
	AC_MSG_CHECKING([whether $CC supports $1])
	CAIRO_CC_TRY_FLAG_SILENT([$WERROR $1], [$2], [$3], [$4])
	AC_MSG_RESULT([$cairo_cc_flag])
])

dnl Usage:
dnl   CAIRO_CHECK_NATIVE_ATOMIC_PRIMITIVES
AC_DEFUN([CAIRO_CHECK_NATIVE_ATOMIC_PRIMITIVES],
[dnl
	AC_CACHE_CHECK([for native atomic primitives], cairo_cv_atomic_primitives,
	[
		cairo_cv_atomic_primitives="none"

		AC_TRY_LINK([
int atomic_add(int i) { return __sync_fetch_and_add (&i, 1); }
int atomic_cmpxchg(int i, int j, int k) { return __sync_val_compare_and_swap (&i, j, k); }
], [],
		  cairo_cv_atomic_primitives="Intel"
		  )

		AC_TRY_LINK([
int atomic_add(int i) { return __atomic_fetch_add(&i, 1, __ATOMIC_SEQ_CST); }
int atomic_cmpxchg(int i, int j, int k) { return __atomic_compare_exchange_n(&i, &j, k, 0, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST); }
], [],
		   cairo_cv_atomic_primitives="cxx11"
		   )

		if test "x$cairo_cv_atomic_primitives" = "xnone"; then
			AC_CHECK_HEADER([atomic_ops.h],
					cairo_cv_atomic_primitives="libatomic-ops")
		fi

		if test "x$cairo_cv_atomic_primitives" = "xnone"; then
			AC_CHECK_HEADER([libkern/OSAtomic.h],
					cairo_cv_atomic_primitives="OSAtomic")
		fi
	])
	if test "x$cairo_cv_atomic_primitives" = xcxx11; then
		AC_DEFINE(HAVE_CXX11_ATOMIC_PRIMITIVES, 1,
			  [Enable if your compiler supports the GCC __atomic_* atomic primitives])
	fi

	if test "x$cairo_cv_atomic_primitives" = xIntel; then
		AC_DEFINE(HAVE_INTEL_ATOMIC_PRIMITIVES, 1,
			  [Enable if your compiler supports the Intel __sync_* atomic primitives])
	fi

	if test "x$cairo_cv_atomic_primitives" = "xlibatomic-ops"; then
		AC_DEFINE(HAVE_LIB_ATOMIC_OPS, 1,
			  [Enable if you have libatomic-ops-dev installed])
	fi

	if test "x$cairo_cv_atomic_primitives" = xOSAtomic; then
		AC_DEFINE(HAVE_OS_ATOMIC_OPS, 1,
			  [Enable if you have MacOS X atomic operations])
	fi
])

dnl Usage:
dnl   CAIRO_CHECK_ATOMIC_OP_NEEDS_MEMORY_BARRIER
AC_DEFUN([CAIRO_CHECK_ATOMIC_OP_NEEDS_MEMORY_BARRIER],
[dnl
	AC_CACHE_CHECK([whether atomic ops require a memory barrier], cairo_cv_atomic_op_needs_memory_barrier,
	[
		case $host_cpu in
		    i?86)	cairo_cv_atomic_op_needs_memory_barrier="no"  ;;
		    x86_64)	cairo_cv_atomic_op_needs_memory_barrier="no"  ;;
		    arm*)	cairo_cv_atomic_op_needs_memory_barrier="no"  ;;
		    *)		cairo_cv_atomic_op_needs_memory_barrier="yes" ;;
		esac
	])
	if test "x$cairo_cv_atomic_op_needs_memory_barrier" = "xyes"; then
	    AC_DEFINE_UNQUOTED(ATOMIC_OP_NEEDS_MEMORY_BARRIER, 1,
			       [whether memory barriers are needed around atomic operations])
	fi
])

AC_DEFUN([CAIRO_TEXT_WRAP], [m4_text_wrap([$1], [$2],, 78)])
