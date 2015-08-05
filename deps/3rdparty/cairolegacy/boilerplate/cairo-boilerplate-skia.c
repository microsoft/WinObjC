
#include "cairo-boilerplate-private.h"

#include <cairo-skia.h>

static cairo_surface_t *
_cairo_boilerplate_skia_create_surface (const char		  *name,
					cairo_content_t 	   content,
					double			   width,
					double			   height,
					double			   max_width,
					double			   max_height,
					cairo_boilerplate_mode_t   mode,
					int			   id,
					void			 **closure)
{
    cairo_format_t format;

    *closure = NULL;

    if (content == CAIRO_CONTENT_COLOR_ALPHA) {
	format = CAIRO_FORMAT_ARGB32;
    } else if (content == CAIRO_CONTENT_COLOR) {
	format = CAIRO_FORMAT_RGB24;
    } else {
	return NULL;
    }

    return cairo_skia_surface_create (format, width, height);
}

static const cairo_boilerplate_target_t targets[] = {
    {
	"skia", "skia", NULL, NULL,
	CAIRO_SURFACE_TYPE_SKIA, CAIRO_CONTENT_COLOR_ALPHA, 0,
	"cairo_skia_surface_create",
	_cairo_boilerplate_skia_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	NULL, NULL, NULL, TRUE, FALSE, FALSE
    },
    {
	"skia", "skia", NULL, NULL,
	CAIRO_SURFACE_TYPE_SKIA, CAIRO_CONTENT_COLOR, 0,
	"cairo_skia_surface_create",
	_cairo_boilerplate_skia_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	NULL, NULL, NULL, FALSE, FALSE, FALSE
    },
};
CAIRO_BOILERPLATE (skia, targets)
