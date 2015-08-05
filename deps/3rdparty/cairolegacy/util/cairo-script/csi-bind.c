#include <cairo.h>
#include <cairo-script-interpreter.h>

#include <stdio.h>
#include <stdlib.h>

static cairo_status_t
write_func (void *closure,
	    const unsigned char *data,
	    unsigned int length)
{
    if (fwrite (data, length, 1, closure) != 1)
	return CAIRO_STATUS_WRITE_ERROR;

    return CAIRO_STATUS_SUCCESS;
}

int
main (int argc, char **argv)
{
    FILE *in = stdin, *out = stdout;
    cairo_status_t status;
    int i;

    if (argc >= 3) {
	if (strcmp (argv[argc-1], "-")) {
	    out = fopen (argv[argc-1], "w");
	    if (out == NULL) {
		fprintf (stderr, "Failed to open output '%s'\n", argv[argc-1]);
		return 1;
	    }
	}
    }

    if (argc > 2) {
	for (i = 1; i < argc - 1; i++) {
	    in = fopen (argv[i], "r");
	    if (in == NULL) {
		fprintf (stderr, "Failed to open input '%s'\n", argv[i]);
		return 1;
	    }

	    status = cairo_script_interpreter_translate_stream (in, write_func, out);
	    fclose (in);

	    if (status)
		break;
	}
    } else {
	if (argc > 1) {
	    if (strcmp (argv[1], "-")) {
		in = fopen (argv[1], "r");
		if (in == NULL) {
		    fprintf (stderr, "Failed to open input '%s'\n", argv[1]);
		    return 1;
		}
	    }
	}

	status = cairo_script_interpreter_translate_stream (in, write_func, out);

	if (in != stdin)
	    fclose (in);
    }

    if (out != stdout)
	fclose (out);

    if (status) {
	fprintf (stderr, "Translation failed: %s\n",
		cairo_status_to_string (status));
	return status;
    }

    return status;
}
