#include <cairo-script.h>
#include <cairo-script-interpreter.h>

#include <stdio.h>
#include <string.h>
#include <libgen.h>

static cairo_surface_t *
_script_surface_create (void *closure,
			 cairo_content_t content,
			 double width, double height,
			 long uid)
{
    return cairo_script_surface_create (closure, content, width, height);
}

int
main (int argc, char **argv)
{
    cairo_script_interpreter_t *csi;
    cairo_script_interpreter_hooks_t hooks = {
	.surface_create = _script_surface_create,
    };
    int i;

    csi = cairo_script_interpreter_create ();

    for (i = 1; i < argc; i++) {
	char buf[4096];

	snprintf (buf, sizeof (buf), "%s.trace", basename (argv[i]));
	cairo_device_destroy (hooks.closure);
	hooks.closure = cairo_script_create (buf);
	cairo_script_interpreter_install_hooks (csi, &hooks);
	cairo_script_interpreter_run (csi, argv[i]);
    }
    cairo_device_destroy (hooks.closure);

    return cairo_script_interpreter_destroy (csi);
}
