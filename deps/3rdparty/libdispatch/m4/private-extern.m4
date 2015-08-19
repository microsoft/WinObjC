#
# Does the platform support __private_extern__?  There is surely a better way
# to check this.
#
AC_DEFUN([DISPATCH_C_PRIVATE_EXTERN], [

AC_LANG_WERROR

AC_CACHE_CHECK([for __attribute__((visibility("hidden")))],
    dispatch_cv_hidden_visibility_attribute, [
	AC_TRY_LINK([int foo; extern __attribute__ ((visibility ("hidden"))) int foo;], 
		[foo = 0;],
                    [dispatch_cv_hidden_visibility_attribute=yes],
                    [dispatch_cv_hidden_visibility_attribute=no])])

AC_CACHE_CHECK([for __private_extern__],
    dispatch_cv_private_extern, [
        AC_TRY_LINK([], [__private_extern__ int foo;],
                    [dispatch_cv_private_extern=yes],
                    [dispatch_cv_private_extern=no])])

if test $dispatch_cv_private_extern = yes; then
  AC_DEFINE(HAVE_PRIVATE_EXTERN, 1, Define if __private_extern__ present)
elif test $dispatch_cv_hidden_visibility_attribute = yes; then
  AC_DEFINE(HAVE_PRIVATE_EXTERN, 1, Define if __private_extern__ present)
  AC_DEFINE([__private_extern__], [extern __attribute__ ((visibility ("hidden")))],
	    [Define to a replacement for __private_extern])
else
  AC_DEFINE([__private_extern__], [extern],
	    [Define to a replacement for __private_extern])
fi

])
