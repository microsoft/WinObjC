#include <cairo.h>
#include <cairo-script-interpreter.h>

#include <stdio.h>
#include <stdlib.h>

static cairo_surface_t *
_surface_create (void *closure,
		 cairo_content_t content,
		 double width, double height,
		 long uid)
{
    return cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);
}

int
main (int argc, char **argv)
{
    const cairo_script_interpreter_hooks_t hooks = {
	.surface_create = _surface_create
    };
    cairo_script_interpreter_t *csi;
	int status;
    int i;

    csi = cairo_script_interpreter_create ();
    cairo_script_interpreter_install_hooks (csi, &hooks);
    for (i = 1; i < argc; i++)
	cairo_script_interpreter_run (csi, argv[i]);
    return cairo_script_interpreter_destroy (csi);
}
