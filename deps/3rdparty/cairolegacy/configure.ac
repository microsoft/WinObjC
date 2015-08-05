AC_PREREQ(2.59)
CAIRO_PARSE_VERSION
AC_INIT([cairo],
	[cairo_version_major.cairo_version_minor.cairo_version_micro],
	[http://bugs.freedesktop.org/enter_bug.cgi?product=cairo])
AC_CONFIG_AUX_DIR(build)
AC_CONFIG_MACRO_DIR(build)
AC_GNU_SOURCE
AC_USE_SYSTEM_EXTENSIONS
AC_CONFIG_SRCDIR(src/cairo.h)
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([1.9.6 gnu -Wall no-define])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_LIBTOOL_WIN32_DLL dnl Must be called before AC_PROG_LIBTOOL
AC_PROG_LIBTOOL dnl ([1.4]) Don't remove!
GTK_DOC_CHECK([1.6])

AC_SYS_LARGEFILE

dnl ===========================================================================
dnl
dnl The order of the includes here is rather important
dnl
m4_include(build/configure.ac.version)	dnl macros setting up various version declares
m4_include(build/configure.ac.tools)	dnl checks for tools we use
m4_include(build/configure.ac.features)	dnl macros for backend/feature handling
m4_include(build/configure.ac.warnings)	dnl checks for compiler warning
m4_include(build/configure.ac.system)	dnl checks for system functions, headers, libs
m4_include(build/configure.ac.analysis)	dnl checks for analysis tools (lcov, etc)
m4_include(build/configure.ac.noversion) dnl disable builtin libtool versioning
m4_include(build/configure.ac.pthread)  dnl checks for pthreads
AC_CACHE_SAVE

dnl ===========================================================================

AC_CHECK_LIB(z, compress,
	 [AC_CHECK_HEADER(zlib.h, [
	  have_libz=yes
	  AC_DEFINE(HAVE_ZLIB, 1, [Define to 1 if you have zlib available])
	 ],
	 [have_libz="no (requires zlib http://www.gzip.org/zlib/)"])],
	 [have_libz="no (requires zlib http://www.gzip.org/zlib/)"])

AC_CHECK_LIB(dl, dlsym,
	     [have_dlsym=yes; have_dl=yes],
	     [have_dlsym=no; have_dl=no])
if test "x$have_dlsym" = "xno"; then
   AC_CHECK_FUNC(dlsym, [have_dlsym=yes], [have_dlsym=no])
fi
AC_CHECK_HEADERS(dlfcn.h, [have_dlsym=yes], [have_dlsym=no])
AM_CONDITIONAL(CAIRO_HAS_DL, test "x$have_dl" = "xyes")

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(xlib, Xlib, auto, [
  xlib_REQUIRES="x11"
  PKG_CHECK_MODULES(xlib, $xlib_REQUIRES, ,
		    [AC_MSG_RESULT(no)
		     xlib_REQUIRES=""
		     AC_PATH_XTRA
		     if test "x$no_x" = xyes; then
		       use_xlib="no (requires X development libraries)"
		     else
		       xlib_NONPKGCONFIG_LIBS="$X_PRE_LIBS $X_LIBS -lX11 $X_EXTRA_LIBS"
		       xlib_NONPKGCONFIG_CFLAGS=$X_CFLAGS
		     fi])
])

CAIRO_ENABLE_SURFACE_BACKEND(xlib_xrender, Xlib Xrender, auto, [
  if test "x$use_xlib" != "xyes"; then
    use_xlib_xrender="no (requires --enable-xlib)"
  else
    dnl Check for Xrender header files if the Xrender package is not installed:
    xlib_xrender_BASE=cairo-xlib
    xlib_xrender_REQUIRES="xrender >= 0.6"
    PKG_CHECK_MODULES(xlib_xrender, $xlib_xrender_REQUIRES, ,
		      [AC_MSG_RESULT(no)
		       xlib_xrender_REQUIRES=""
		       old_CPPFLAGS=$CPPFLAGS
		       CPPFLAGS="$CPPFLAGS $xlib_CFLAGS $xlib_NONPKGCONFIG_CFLAGS"
		       AC_CHECK_HEADER(X11/extensions/Xrender.h,
				       [xlib_xrender_NONPKGCONFIG_LIBS="-lXrender"],
				       [use_xlib_xrender="no (requires $xlib_xrender_REQUIRES http://freedesktop.org/Software/xlibs)"])
		       CPPFLAGS=$old_CPPFLAGS
		      ])
  fi
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(xcb, XCB, no, [
  xcb_REQUIRES="xcb >= 1.1.92 xcb-render >= 0.9.92"
  PKG_CHECK_MODULES(xcb, $xcb_REQUIRES, ,
		    [AC_MSG_RESULT(no)
		    use_xcb="no (requires $xcb_REQUIRES http://xcb.freedesktop.org)"])
  if $PKG_CONFIG --atleast-version=1.4 xcb; then
    CAIRO_CFLAGS="$CAIRO_CFLAGS -DXCB_GENERIC_ERROR_HAS_MAJOR_MINOR_CODES"
  fi
])

CAIRO_ENABLE_FUNCTIONS(xlib_xcb, Xlib/XCB, no, [
  if test "x$use_xcb" = "xyes" -a "x$use_xlib" = "xyes"; then
    xlib_xcb_REQUIRES="x11-xcb"
    PKG_CHECK_MODULES(xlib_xcb, $xlib_xcb_REQUIRES, ,
		      [use_xlib_xcb="no (requires $xlib_xcb_REQUIRES http://xcb.freedesktop.org)"])
  else
    use_xlib_xcb="no (requires both --enable-xlib and --enable-xcb)"
  fi
])
AM_CONDITIONAL(BUILD_XLIB_XCB, test "x$use_xlib_xcb" = "xyes")

CAIRO_ENABLE_FUNCTIONS(xcb_shm, XCB/SHM, auto, [
  if test "x$use_xcb" = "xyes"; then
      xcb_shm_REQUIRES="xcb-shm"
      PKG_CHECK_MODULES(xcb_shm, $xcb_shm_REQUIRES, ,
			[AC_MSG_RESULT(no)
			use_xcb_shm="no (requires $xcb_shm http://xcb.freedesktop.org)"])
  else
    use_xcb_shm="no (requires --enable-xcb)"
  fi
])
AM_CONDITIONAL(BUILD_XCB_SHM, test "x$use_xcb_shm" = "xyes")

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(qt, Qt, no, [
  qt_REQUIRES="QtGui >= 4.4.0"
  PKG_CHECK_MODULES(qt, $qt_REQUIRES, ,
		    [AC_MSG_RESULT(no)
		     qt_REQUIRES=""
		     use_qt="no (requires Qt4 development libraries)"
		     ])
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(quartz, Quartz, auto, [
  dnl There is no pkgconfig for quartz; lets do a header check
  AC_CHECK_HEADER(ApplicationServices/ApplicationServices.h, , [use_quartz="no (requires ApplicationServices framework)"])
  if test "x$use_quartz" != "xyes" ; then
    dnl check for CoreGraphics as a separate framework
    AC_CHECK_HEADER(CoreGraphics/CoreGraphics.h, , [use_quartz="no (requires CoreGraphics framework)"])
    quartz_LIBS="-Xlinker -framework -Xlinker CoreGraphics"
  else
    quartz_LIBS="-Xlinker -framework -Xlinker ApplicationServices"
  fi
])

CAIRO_ENABLE_FONT_BACKEND(quartz_font, Quartz, auto, [
  use_quartz_font=$use_quartz
])

CAIRO_ENABLE_SURFACE_BACKEND(quartz_image, Quartz Image, no, [
  use_quartz_image=$use_quartz
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(win32, Microsoft Windows, auto, [
  if test "x$have_windows" != xyes; then
    use_win32="no (requires a Win32 platform)"
  fi
  win32_LIBS="-lgdi32 -lmsimg32"
])

CAIRO_ENABLE_FONT_BACKEND(win32_font, Microsoft Windows, auto, [
  use_win32_font=$use_win32
])

test_win32_printing=no
if test "x$use_win32" = "xyes"; then
  AC_CHECK_PROG(GS, gs, gs)
  if test "$GS"; then
    AC_DEFINE([CAIRO_CAN_TEST_WIN32_PRINTING_SURFACE], 1, [Define to 1 if the Win32 Printing backend can be tested (needs ghostscript)])
    test_win32_printing="yes"
  else
    AC_MSG_WARN([Win32 Printing backend will not be tested since ghostscript is not available])
    test_win32_printing="no (requires ghostscript)"
  fi
fi

AM_CONDITIONAL(CAIRO_CAN_TEST_WIN32_PRINTING_SURFACE, test "x$test_win32_printing" = "xyes")

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(skia, Skia, no, [
  AC_ARG_WITH([skia],
	      [AS_HELP_STRING([--with-skia=/path/to/skia],
			      [directory to find compiled skia sources])],
	      [skia_DIR="$withval"],
	      [skia_DIR="`pwd`/../mesa"])
  skia_NONPKGCONFIG_CFLAGS="-I$skia_DIR/include/config -I$skia_DIR/include/core -I$skia_DIR/include/effects"
  skia_NONPKGCONFIG_LIBS="$skia_DIR/out/libskia.a"
  AC_SUBST(skia_DIR)
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(os2, OS/2, no, [
  case "$host" in
    *-*-os2*)
      :
      ;;
    *)
      use_os2="no (requires an OS/2 platform)"
      ;;
  esac
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(beos, BeOS/Zeta, no, [
  case "$host" in
    *-*-beos)
      beos_LIBS=""
      dnl Add libbe and libzeta if available
      AC_CHECK_LIB(be,main,beos_LIBS="$beos_LIBS -lbe")
      AC_CHECK_LIB(zeta,main,beos_LIBS="$beos_LIBS -lzeta")
      ;;
    *)
      use_beos="no (requires a BeOS platform)"
      ;;
  esac
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(drm, DRM, no, [
  drm_REQUIRES="libudev >= 136"
  PKG_CHECK_MODULES(drm, $drm_REQUIRES, , [AC_MSG_RESULT(no)
  use_drm="no (requires $drm_REQUIRES, udev is available from git://git.kernel.org/pub/scm/linux/hotplug/udev.git)"])
])

CAIRO_ENABLE_FUNCTIONS(drm_xr, DRM Xr (DDX), no, [
  if test "x$use_drm" = "xyes"; then
      drm_xr_REQUIRES="xorg-server >= 1.6 xproto xextproto >= 7.0.99.1 renderproto x11"
      PKG_CHECK_MODULES(drm_xr, $drm_xr_REQUIRES, ,
			[AC_MSG_RESULT(no)
			use_drm_xr="no (requires $drm_xr)"])
      drm_xr_CFLAGS=`echo "$drm_xr_CFLAGS" | $SED -e 's/-fvisibility=hidden//g'`
  else
    use_drm_xr="no (requires --enable-drm)"
  fi
])
AM_CONDITIONAL(BUILD_DRM_XR, test "x$use_drm_xr" = "xyes")

CAIRO_ENABLE_SURFACE_BACKEND(gallium, Gallium3D, no, [
  if test "x$use_drm" = "xyes"; then
      AC_ARG_WITH([gallium],
		  [AS_HELP_STRING([--with-gallium=/path/to/mesa],
				  [directory to find gallium enabled mesa])],
		  [mesa_DIR="$withval"],
		  [mesa_DIR="`pwd`/../mesa"])
      gallium_DIR="$mesa_DIR/src/gallium"
      gallium_NONPKGCONFIG_CFLAGS="-I$mesa_DIR/include -I$mesa_DIR/src/mesa -I$gallium_DIR/include -I$gallium_DIR/auxiliary"
      gallium_NONPKGCONFIG_LIBS="-lGL"
      AC_SUBST(mesa_DIR)
      AC_SUBST(gallium_DIR)
  else
    use_gallium="no (requires --enable-drm)"
  fi
])

CAIRO_ENABLE_FUNCTIONS(xcb_drm, XCB/DRM, no, [
  if test "x$use_xcb" = "xyes" -a "x$use_drm" = "xyes"; then
      xcb_drm_REQUIRES="xcb-dri2"
      PKG_CHECK_MODULES(xcb_drm, $xcb_drm_REQUIRES, ,
			[AC_MSG_RESULT(no)
			use_xcb_drm="no (requires $xcb_drm_REQUIRES http://xcb.freedesktop.org)"])
  else
    use_xcb_drm="no (requires both --enable-xcb and --enable-drm)"
  fi
])

dnl ===========================================================================

CAIRO_ENABLE_FUNCTIONS(png, PNG, yes, [
  use_png=no
  AC_ARG_VAR([png_REQUIRES], [module name for libpng to search for using pkg-config])
  if test "x$png_REQUIRES" = x; then
    # libpng13 is GnuWin32's libpng-1.2.8 :-(
    for l in libpng libpng14 libpng12 libpng13 libpng10; do
      if $PKG_CONFIG --exists $l ; then
        png_REQUIRES=$l
        use_png=yes
        break
      fi
    done
  else
    use_png=yes
  fi

  if test "x$use_png" = "xyes" ; then 
    PKG_CHECK_MODULES(png, $png_REQUIRES, , AC_MSG_RESULT(no))
  else
    AC_MSG_WARN([Could not find libpng in the pkg-config search path])
  fi    
])

dnl ===========================================================================
CAIRO_ENABLE_SURFACE_BACKEND(gl, OpenGL, no, [
  gl_REQUIRES="gl"
  PKG_CHECK_MODULES(gl, $gl_REQUIRES,, [
	  dnl Fallback to searching for headers
	  AC_CHECK_HEADER(GL/gl.h,, [use_gl="no (gl.pc nor OpenGL headers not found)"])
	  if test "x$use_gl" = "xyes"; then
	      gl_NONPKGCONFIG_CFLAGS=
	      gl_NONPKGCONFIG_LIBS="-lGL"
	  fi])

  need_glx_functions=yes
  need_wgl_functions=yes
  need_egl_functions=yes
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(directfb, directfb, no, [
  directfb_REQUIRES=directfb
  PKG_CHECK_MODULES(directfb, $directfb_REQUIRES, , AC_MSG_RESULT(no)
		    [use_directfb="no (requires $directfb_REQUIRES http://www.directfb.org)"])
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(vg, OpenVG, no, [
  dnl There is no pkgconfig for OpenVG; lets do a header check
  AC_CHECK_HEADER(VG/openvg.h,, [use_vg="no (OpenVG headers not found)"])
  if test "x$use_vg" = "xyes"; then
      vg_NONPKGCONFIG_CFLAGS=
      vg_NONPKGCONFIG_LIBS="-lOpenVG"
      need_egl_functions=yes
      need_glx_functions=yes
  fi
])

CAIRO_ENABLE_FUNCTIONS(egl, EGL, auto, [
  if test "x$need_egl_functions" = "xyes"; then
      egl_REQUIRES="egl"
      PKG_CHECK_MODULES(egl, $egl_REQUIRES, ,
		    [egl_REQUIRES=""
		     AC_CHECK_HEADER(EGL/egl.h,, [use_egl="no (EGL headers not found)"])
		     if test "x$use_egl" = "xyes"; then
			 egl_NONPKGCONFIG_CFLAGS=
			 egl_NONPKGCONFIG_LIBS=
			 save_LIBS="$LIBS"
			 other_egl_LIBS=""
			 # Temporary workaround for missing link from egl13
			 AC_CHECK_LIB(csi, csi_stream_attachresource, other_egl_LIBS="-lcsi")
			 LIBS="$other_egl_LIBS $LIBS"
			 for egl_lib in EGL egl13 egl12 egl11; do
			     if test -z "$egl_NONPKGCONFIG_LIBS"; then
				 AC_CHECK_LIB($egl_lib, eglGetError, egl_NONPKGCONFIG_LIBS="-l$egl_lib")
			     fi
			 done
			 if test -z "$egl_NONPKGCONFIG_LIBS"; then
			     use_egl="no (EGL library not found)"
			 else
			     egl_NONPKGCONFIG_LIBS="$egl_NONPKGCONFIG_LIBS $other_egl_LIBS"
			 fi
			 LIBS="$save_LIBS"
		     fi
  	])
  else
      use_egl="no (not required by any backend)"
  fi
])

CAIRO_ENABLE_FUNCTIONS(glx, GLX, auto, [
  if test "x$need_glx_functions" = "xyes"; then
    save_CFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS $gl_CFLAGS $gl_NONPKGCONFIG_CFLAGS"
    AC_CHECK_HEADER(GL/glx.h,, [use_glx="no (GLX headers not found)"])
    glx_NONPKGCONFIG_CFLAGS=
    glx_NONPKGCONFIG_LIBS="-lGL"
    CFLAGS="$save_CFLAGS"
  else
      use_glx="no (not required by any backend)"
  fi
])

CAIRO_ENABLE_FUNCTIONS(wgl, WGL, auto, [
  if test "x$need_wgl_functions" = "xyes"; then
    AC_CHECK_HEADER(windows.h,, [use_wgl="no (WGL headers not found)"])
  else
      use_wgl="no (not required by any backend)"
  fi
])

dnl ===========================================================================

any2ppm_cs=no
CAIRO_ENABLE_SURFACE_BACKEND(script, script, no, [
  any2ppm_cs=yes
])

dnl ===========================================================================

# We use pkg-config to look for freetype2, but fall back to
# freetype-config if it fails.  We prefer pkg-config, since we can
# then just put freetype2 >= $FREETYPE_MIN_VERSION in
# Requires.private, but at least up to 2003-06-07, there was no
# freetype2.pc in the release.
#
# FreeType versions come in three forms:
#   release (such as 2.1.9)
#   libtool (such as 9.7.3) (returned by freetype-config and pkg-config)
#   platform-specific/soname (such as 6.3.4)
# and they recommend you never use the platform-specific version
# (see docs/VERSION.DLL in freetype2 sources)
#
# Set these as appropriate:

# release number - for information only
FREETYPE_MIN_RELEASE=2.1.9
# libtool-specific version - this is what is checked
FREETYPE_MIN_VERSION=9.7.3

CAIRO_ENABLE_FONT_BACKEND(ft, FreeType, auto, [

    PKG_CHECK_MODULES(FREETYPE, freetype2 >= $FREETYPE_MIN_VERSION,
                      [freetype_pkgconfig=yes],
		      [AC_MSG_RESULT(no)
		       freetype_pkgconfig=no])
  
    if test "x$freetype_pkgconfig" = "xyes"; then
      ft_REQUIRES="freetype2 >= $FREETYPE_MIN_VERSION $ft_REQUIRES"
    else
  
      if test -z "$FREETYPE_CONFIG"; then
        AC_PATH_PROG(FREETYPE_CONFIG, freetype-config, no)
      fi
      if test "x$FREETYPE_CONFIG" = "xno" ; then
        use_ft='no (freetype-config not found in path or $FREETYPE_CONFIG)'
      else
        AC_MSG_CHECKING(freetype2 libtool version)

        FREETYPE_VERSION=`$FREETYPE_CONFIG --version`
	AX_COMPARE_VERSION([$FREETYPE_VERSION], [gt], [$FREETYPE_MIN_VERSION],
			   [AC_MSG_RESULT($FREETYPE_VERSION - OK)
			   ft_NONPKGCONFIG_CFLAGS=`$FREETYPE_CONFIG --cflags`
			   ft_NONPKGCONFIG_LIBS=`$FREETYPE_CONFIG --libs`],
			   [AC_MSG_RESULT($FREETYPE_VERSION - Too old)
			   use_ft="no ($FREETYPE_VERSION found; version $FREETYPE_MIN_VERSION from release $FREETYPE_MIN_RELEASE required)"])
      fi
    fi

  ft_CFLAGS="$FREETYPE_CFLAGS"
  ft_LIBS="$FREETYPE_LIBS"
])

FONTCONFIG_MIN_VERSION=2.2.95
CAIRO_ENABLE_FONT_BACKEND(fc, Fontconfig, auto, [
  use_fc=$use_ft
  if test "x$use_fc" = "xyes"; then
    fc_REQUIRES="fontconfig >= $FONTCONFIG_MIN_VERSION"
    PKG_CHECK_MODULES(FONTCONFIG, $fc_REQUIRES,,
		      [AC_MSG_RESULT(no); use_fc="no (requires $fc_REQUIRES)"])
  fi
  fc_CFLAGS="$FONTCONFIG_CFLAGS"
  fc_LIBS="$FONTCONFIG_LIBS"
])

if test "x$use_ft" = "xyes"; then
  _save_libs="$LIBS"
  _save_cflags="$CFLAGS"
  LIBS="$LIBS $ft_LIBS"
  CFLAGS="$CFLAGS $ft_CFLAGS"
  AC_CHECK_MEMBER(FT_Bitmap_Size.y_ppem,
                  HAVE_FT_BITMAP_SIZE_Y_PPEM=1,
                  HAVE_FT_BITMAP_SIZE_Y_PPEM=0,
                  [#include <ft2build.h>
                   #include FT_FREETYPE_H])
  AC_DEFINE_UNQUOTED(HAVE_FT_BITMAP_SIZE_Y_PPEM,$HAVE_FT_BITMAP_SIZE_Y_PPEM,
                     [FT_Bitmap_Size structure includes y_ppem field])

  AC_CHECK_FUNCS(FT_GlyphSlot_Embolden FT_Load_Sfnt_Table FT_Library_SetLcdFilter)

  LIBS="$_save_libs"
  CFLAGS="$_save_cflags"
fi

if test "x$use_fc" = "xyes"; then
  CAIRO_CHECK_FUNCS_WITH_FLAGS(FcInit FcFini, [$FONTCONFIG_CFLAGS], [$FONTCONFIG_LIBS])
fi

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(ps, PostScript, yes, [
    # The ps backend requires zlib.
    use_ps=$have_libz
    ps_NONPKGCONFIG_LIBS=-lz
])

dnl ===========================================================================

SPECTRE_VERSION_REQUIRED=0.2.0
test_ps=no
any2ppm_ps=no
if test "x$use_ps" = "xyes"; then
  AC_CHECK_PROG(GS, gs, gs)
  if test "$GS"; then
    AC_DEFINE([CAIRO_CAN_TEST_PS_SURFACE], 1, [Define to 1 if the PS backend can be tested (needs ghostscript)])
    test_ps="yes"
  else
    AC_MSG_WARN([PS backend will not be tested since ghostscript is not available])
    test_ps="no (requires ghostscript)"
  fi

  libspectre_DEPENDENCY="libspectre >= $SPECTRE_VERSION_REQUIRED"
  PKG_CHECK_MODULES(LIBSPECTRE, $libspectre_DEPENDENCY,
		    [any2ppm_ps=yes],
		    [test_ps="no (requires libspectre)"])
fi

AM_CONDITIONAL(CAIRO_CAN_TEST_PS_SURFACE, test "x$test_ps" = "xyes")
AM_CONDITIONAL(CAIRO_HAS_SPECTRE, test "x$any2ppm_ps" = "xyes")
if test "x$any2ppm_ps" = "xyes"; then
    AC_DEFINE([CAIRO_HAS_SPECTRE], 1, [Define to 1 if libspectre is available])
fi
AC_SUBST(LIBSPECTRE_CFLAGS)
AC_SUBST(LIBSPECTRE_LIBS)

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(pdf, PDF, yes, [
    # The pdf backend requires zlib.
    use_pdf=$have_libz
    pdf_NONPKGCONFIG_LIBS=-lz
])

dnl ===========================================================================

# poppler-0.9.2 has an important bug fixes for user-font and an
# enhancement not to gobble nearly 1GiB of memory during test/large-font.
POPPLER_VERSION_REQUIRED=0.13.3
test_pdf=no
any2ppm_pdf=no
if test "x$use_pdf" = "xyes"; then
  poppler_DEPENDENCY="poppler-glib >= $POPPLER_VERSION_REQUIRED"
  PKG_CHECK_MODULES(POPPLER, $poppler_DEPENDENCY,
		    [CAIRO_CHECK_FUNCS_WITH_FLAGS(poppler_page_render, [$POPPLER_CFLAGS], [$POPPLER_LIBS],
                    [test_pdf=yes; any2ppm_pdf=yes],
		    [test_pdf="no (requires $poppler_DEPENDENCY)"])],
		    [test_pdf="no (requires $poppler_DEPENDENCY)"])
  if test "x$test_pdf" = "xyes"; then
    AC_DEFINE([CAIRO_CAN_TEST_PDF_SURFACE], 1, [Define to 1 if the PDF backend can be tested (need poppler and other dependencies for pdf2png)])
  else
    AC_MSG_WARN([PDF backend will not be tested since poppler >= $POPPLER_VERSION_REQUIRED is not available])
  fi
fi

AM_CONDITIONAL(CAIRO_CAN_TEST_PDF_SURFACE, test "x$test_pdf" = "xyes")
AC_SUBST(POPPLER_CFLAGS)
AC_SUBST(POPPLER_LIBS)

AM_CONDITIONAL(CAIRO_HAS_MULTI_PAGE_SURFACES, test "x$use_ps" = "xyes" -o "x$use_pdf" = "xyes")

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(svg, SVG, yes, [
  if test "x$use_png" != "xyes"; then
    use_svg="no (requires --enable-png)"
  fi
])

LIBRSVG_VERSION_REQUIRED=2.15.0
test_svg=no
any2ppm_svg=no
if test "x$use_svg" = "xyes"; then
  librsvg_DEPENDENCY="librsvg-2.0 >= $LIBRSVG_VERSION_REQUIRED"
  PKG_CHECK_MODULES(LIBRSVG, $librsvg_DEPENDENCY gdk-2.0,
		    [CAIRO_CHECK_FUNCS_WITH_FLAGS(rsvg_pixbuf_from_file, [$LIBRSVG_CFLAGS], [$LIBRSVG_LIBS],
                    [test_svg=yes; any2ppm_svg=yes],
		    [test_svg="no (requires $librsvg_DEPENDENCY)"])],
		    [test_svg="no (requires $librsvg_DEPENDENCY)"])
  if test "x$test_svg" = "xyes"; then
    AC_DEFINE([CAIRO_CAN_TEST_SVG_SURFACE], 1, [Define to 1 if the SVG backend can be tested])
  else
    AC_MSG_WARN([SVG backend will not be tested since librsvg >= $LIBRSVG_VERSION_REQUIRED is not available])
  fi
fi

AM_CONDITIONAL(CAIRO_CAN_TEST_SVG_SURFACE, test "x$test_svg" = "xyes")
AC_SUBST(LIBRSVG_CFLAGS)
AC_SUBST(LIBRSVG_LIBS)

dnl ===========================================================================

dnl XXX make this a private feature?
CAIRO_ENABLE(test_surfaces, test surfaces, no)

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(image, image, always, [
  pixman_REQUIRES="pixman-1 >= 0.20.2"
  PKG_CHECK_MODULES(pixman, $pixman_REQUIRES, , [AC_MSG_RESULT(no)
  use_image="no (requires $pixman_REQUIRES http://cairographics.org/releases/)"])
  image_REQUIRES=$pixman_REQUIRES
  image_CFLAGS=$pixman_CFLAGS
  image_LIBS=$pixman_LIBS
])

dnl ===========================================================================

CAIRO_ENABLE_SURFACE_BACKEND(recording, recording, always)
CAIRO_ENABLE_SURFACE_BACKEND(tee, tee, no)
CAIRO_ENABLE_SURFACE_BACKEND(xml, xml, no, [
    use_xml=$have_libz
    xml_NONPKGCONFIG_LIBS=-lz
])

dnl ===========================================================================

CAIRO_ENABLE_FONT_BACKEND(user, user, always)

dnl ===========================================================================
dnl
dnl This needs to be last on our list of features so that the pthread libs and flags
dnl gets prefixed in front of everything else in CAIRO_{CFLAGS,LIBS}.
dnl
have_real_pthread=no
have_pthread=no
CAIRO_ENABLE(pthread, pthread, auto, [CAIRO_CONFIGURE_PTHREAD])
AM_CONDITIONAL(HAVE_REAL_PTHREAD, test "x$use_pthread" = "xyes" -a "x$have_real_pthread" = "xyes")
AM_CONDITIONAL(HAVE_PTHREAD, test "x$use_pthread" = "xyes")
AC_SUBST(pthread_CFLAGS)
AC_SUBST(pthread_LIBS)
AC_SUBST(real_pthread_CFLAGS)
AC_SUBST(real_pthread_LIBS)


dnl ===========================================================================
dnl Build gobject integration library

CAIRO_ENABLE_FUNCTIONS(gobject, gobject, auto, [
  gobject_REQUIRES="gobject-2.0 glib-2.0"
  PKG_CHECK_MODULES(GOBJECT, $gobject_REQUIRES, , [AC_MSG_RESULT(no)
  use_gobject="no (requires $gobject_REQUIRES http://download.gnome.org/pub/GNOME/sources/glib/)"])
  gobject_NONPKGCONFIG_EXTRA_LIBS="-L\${libdir} -lcairo-gobject"
])
dnl I'm too lazy to fix the caching properly
if test "x$use_gobject" = "xyes"; then
  PKG_CHECK_MODULES(GOBJECT, $gobject_REQUIRES)
fi

dnl ===========================================================================
dnl Default to quick testing during development, but force a full test before
dnl release

AC_ARG_ENABLE(full-testing,
  AS_HELP_STRING([--enable-full-testing],
                 [Sets the test suite to perform full testing by default, which
		  will dramatically slow down make check, but is a
		  *requirement* before release.]), [
if test "x$enableval" = "xyes"; then
    CAIRO_TEST_MODE=full
    AC_SUBST(CAIRO_TEST_MODE)
fi
])

dnl ===========================================================================
dnl Build the external converter if we have any of the test backends
AM_CONDITIONAL(BUILD_ANY2PPM,
	       test "x$any2ppm_svg" = "xyes" \
	         -o "x$any2ppm_pdf" = "xyes" \
		 -o "x$any2ppm_ps"  = "xyes" \
		 -o "x$any2ppm_cs"  = "xyes")

dnl ===========================================================================
dnl Some utilities need to dlopen the shared libraries, so they need to
dnl know how libtools will name them

case $host in
*-*-darwin*)
	SHLIB_EXT="dylib"
	;;
*)
	SHLIB_EXT="so"
	;;
esac
AC_DEFINE_UNQUOTED(SHARED_LIB_EXT, "${SHLIB_EXT}", [Shared library file extension])
AC_SUBST(SHLIB_EXT)

dnl ===========================================================================
dnl The tracing utility requires LD_PRELOAD, so only build it for systems
dnl that are known to work.

case $host in
*-linux*|*-*bsd*|*-solaris*|*-*-darwin*|*-dragonfly*)
	have_ld_preload="yes"
	;;
*)
	have_ld_preload="no"
	;;
esac

CAIRO_ENABLE(trace, cairo-trace, auto, [
	if test "x$have_ld_preload" != "xyes" -o \
		"x$have_libz" != "xyes" -o \
		"x$have_real_pthread" != "xyes" -o \
		"x$have_dlsym" != "xyes"; then
		use_trace="no (requires dynamic linker and zlib and real pthreads)"
	fi
])

CAIRO_ENABLE(interpreter, cairo-script-interpreter, yes, [
	if test "x$have_libz" != "xyes"; then
		use_interpreter="no (requires zlib)"
	fi
])

AC_CHECK_LIB(bfd, bfd_openr,
	 [AC_CHECK_HEADER(bfd.h, [have_bfd=yes],
	 [have_bfd=no])], [have_bfd=no])
AC_CHECK_HEADER(libiberty.h,, [have_bfd=no])
if test "x$have_bfd" = "xyes"; then
    AC_DEFINE([HAVE_BFD], [1], [Define to 1 if you have the binutils development files installed])
    BFD_LIBS=-lbfd
    AC_SUBST(BFD_LIBS)
fi

CAIRO_ENABLE(symbol_lookup, symbol-lookup, auto, [
	if test "x$have_bfd" != "xyes"; then
		use_symbol_lookup="no (requires bfd)"
	fi
])

PKG_CHECK_MODULES(glib, glib-2.0, have_glib=yes, have_glib=no)
AC_SUBST(glib_CFLAGS)
AC_SUBST(glib_LIBS)
AM_CONDITIONAL(BUILD_SPHINX, test "x$have_glib" = "xyes")

save_LIBS="$LIBS"
AC_CHECK_LIB(rt, shm_open, shm_LIBS="-lrt")
AC_SUBST(shm_LIBS)
LIBS="$save_LIBS"

dnl ===========================================================================

AC_ARG_ENABLE(some-floating-point,
  AS_HELP_STRING([--disable-some-floating-point],
                 [Disable certain code paths that rely heavily on double precision
                  floating-point calculation. This option can improve
                  performance on systems without a double precision floating-point
                  unit, but might degrade performance on those that do.]), [
if test "x$enableval" = "xno"; then
  # A value of 'no' for $enableval means that they want to disable, which
  # means 'yes' for $disable_some_floating_point.
  disable_some_floating_point=yes
fi
], [disable_some_floating_point=no])

AM_CONDITIONAL(DISABLE_SOME_FLOATING_POINT,
               test "x$disable_some_floating_point" = "xyes")
if test "x$disable_some_floating_point" = "xyes"; then
  AC_DEFINE(DISABLE_SOME_FLOATING_POINT, 1,
            [Define to 1 to disable certain code paths that rely heavily on
             double precision floating-point calculation])
fi

dnl ===========================================================================

dnl Extra stuff we need to do when building C++ code
need_cxx="no"
AS_IF([test "x$use_skia" = "xyes"], [need_cxx="yes"])
AS_IF([test "x$use_qt" = "xyes"], [need_cxx="yes"])
AS_IF([test "x$use_beos" = "xyes"], [need_cxx="yes"])

AM_CONDITIONAL(BUILD_CXX, test "x$need_cxx" = "xyes")

dnl ===========================================================================

# We use GTK+ for some utility/debugging tools
PKG_CHECK_MODULES(gtk, "gtk+-2.0",have_gtk=yes, have_gtk=no)
AM_CONDITIONAL(HAVE_GTK, test "x$have_gtk" = "xyes")

AC_CONFIG_FILES([
Makefile
boilerplate/Makefile
src/Makefile
test/Makefile
test/pdiff/Makefile
perf/Makefile
util/Makefile
util/cairo-fdr/Makefile
util/cairo-gobject/Makefile
util/cairo-script/Makefile
util/cairo-script/examples/Makefile
util/cairo-sphinx/Makefile
util/cairo-trace/Makefile
util/cairo-trace/cairo-trace
doc/Makefile
doc/public/Makefile
])

AC_OUTPUT
CAIRO_REPORT
