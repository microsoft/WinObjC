/*
Test were run with the following script
target can be directfb_bitmap or directfb

export CAIRO_TEST_TARGET=directfb_bitmap
export DFBARGS=quiet,no-banner,no-debug,log-file=dfblog,system=x11
cd cairo/test
make check

*/

#include "cairo-boilerplate-private.h"

#include <cairo-directfb.h>

#include <stdio.h>
#include <stdlib.h>

#include <direct/debug.h>

D_DEBUG_DOMAIN (CairoDFB_Boiler, "CairoDFB/Boiler", "Cairo DirectFB Boilerplate");

/* macro for a safe call to DirectFB functions */
#define DFBCHECK(x...)	do{					\
    err = x;							\
    if (err != DFB_OK) {					\
	fprintf (stderr, "%s <%d>:\n\t", __FILE__, __LINE__); \
	goto ERROR; \
    }								\
} while (0)

typedef struct _DFBInfo {
    IDirectFB		   *dfb;
    IDirectFBDisplayLayer  *layer;
    IDirectFBWindow	   *window;
    IDirectFBSurface	   *surface;
} DFBInfo;

static void
_cairo_boilerplate_directfb_cleanup (void *closure)
{
    DFBInfo *info = (DFBInfo *) closure;

    if (info->surface)
	info->surface->Release (info->surface);

    if (info->window)
	info->window->Release (info->window);

    if (info->layer)
	info->layer->Release (info->layer);

    if (info->dfb)
	info->dfb->Release (info->dfb);

    free (info);
}

static DFBInfo *
init (void)
{
    DFBDisplayLayerConfig	 layer_config;
    DFBGraphicsDeviceDescription desc;
    int err;
    DFBInfo *info;

    info = xcalloc (1, sizeof (DFBInfo));
    if (info == NULL)
	return NULL;

    DFBCHECK (DirectFBInit (NULL, NULL));
    DFBCHECK (DirectFBCreate (&info->dfb));
    info->dfb->GetDeviceDescription (info->dfb, &desc);

    DFBCHECK (info->dfb->GetDisplayLayer (info->dfb,
					  DLID_PRIMARY, &info->layer));
    info->layer->SetCooperativeLevel (info->layer, DLSCL_ADMINISTRATIVE);

    if ((desc.blitting_flags & (DSBLIT_BLEND_ALPHACHANNEL |
				DSBLIT_BLEND_COLORALPHA)) !=
	(DSBLIT_BLEND_ALPHACHANNEL | DSBLIT_BLEND_COLORALPHA))
    {
	layer_config.flags = DLCONF_BUFFERMODE;
	layer_config.buffermode = DLBM_BACKSYSTEM;
	info->layer->SetConfiguration (info->layer, &layer_config);
    }

    return info;

ERROR:
    if (info != NULL)
	_cairo_boilerplate_directfb_cleanup (info);
    return NULL;
}

static cairo_surface_t *
_cairo_boilerplate_directfb_window_create_surface (DFBInfo	   *info,
						   cairo_content_t  content,
						   int		    width,
						   int		    height)
{
    DFBWindowDescription desc;
    int err;

    D_DEBUG_AT (CairoDFB_Boiler, "%s (%p, %s, %dx%d)\n", __FUNCTION__, info,
		content == CAIRO_CONTENT_ALPHA	     ? "ALPHA" :
		content == CAIRO_CONTENT_COLOR	     ? "RGB"   :
		content == CAIRO_CONTENT_COLOR_ALPHA ? "ARGB"  : "unknown content!",
		width, height);

    desc.flags	= DWDESC_POSX | DWDESC_POSY |
		  DWDESC_WIDTH | DWDESC_HEIGHT;
    desc.caps	= DSCAPS_NONE;
    desc.posx	= 0;
    desc.posy	= 0;
    desc.width	= width;
    desc.height = height;
    if (content == CAIRO_CONTENT_COLOR_ALPHA) {
	desc.flags |= DWDESC_CAPS | DSDESC_PIXELFORMAT;
	desc.caps  |= DWCAPS_DOUBLEBUFFER | DWCAPS_ALPHACHANNEL;
	desc.pixelformat = DSPF_ARGB;
    }

    DFBCHECK (info->layer->CreateWindow (info->layer, &desc, &info->window));
    info->window->SetOpacity (info->window, 0xFF);
    info->window->GetSurface (info->window, &info->surface);
    info->surface->SetColor (info->surface, 0xFF, 0xFF, 0xFF, 0xFF);
    info->surface->FillRectangle (info->surface,0, 0, desc.width, desc.height);
    info->surface->Flip (info->surface, NULL, 0);

    return cairo_directfb_surface_create (info->dfb, info->surface);

ERROR:
    _cairo_boilerplate_directfb_cleanup (info);
    return NULL;
}

static cairo_surface_t *
_cairo_boilerplate_directfb_bitmap_create_surface (DFBInfo	   *info,
						   cairo_content_t  content,
						   int		    width,
						   int		    height)
{
    int  err;
    DFBSurfaceDescription  desc;

    D_DEBUG_AT (CairoDFB_Boiler, "%s (%p, %s, %dx%d)\n", __FUNCTION__, info,
		content == CAIRO_CONTENT_ALPHA	     ? "ALPHA" :
		content == CAIRO_CONTENT_COLOR	     ? "RGB"   :
		content == CAIRO_CONTENT_COLOR_ALPHA ? "ARGB"  : "unknown content!",
		width, height);

    desc.flags = DSDESC_WIDTH | DSDESC_HEIGHT;
    desc.caps = DSCAPS_NONE;
    desc.width	= width;
    desc.height = height;
    if (content == CAIRO_CONTENT_COLOR_ALPHA) {
	desc.flags |= DSDESC_PIXELFORMAT;
	desc.pixelformat = DSPF_ARGB;
    }
    DFBCHECK (info->dfb->CreateSurface (info->dfb, &desc, &info->surface));

    return cairo_directfb_surface_create (info->dfb, info->surface);

ERROR:
    _cairo_boilerplate_directfb_cleanup (info);
    return NULL;
}

static cairo_surface_t *
_cairo_boilerplate_directfb_create_surface (const char		      *name,
					    cairo_content_t	       content,
					    double		       width,
					    double		       height,
					    double		       max_width,
					    double		       max_height,
					    cairo_boilerplate_mode_t   mode,
					    int 		       id,
					    void		     **closure)
{

    DFBInfo *info;

    info = init ();
    if (info == NULL)
	return NULL;

    *closure = info;

    D_DEBUG_AT (CairoDFB_Boiler, "%s ('%s', %s, %dx%d, %s)\n",
		__FUNCTION__, name,
		content == CAIRO_CONTENT_ALPHA	     ? "ALPHA" :
		content == CAIRO_CONTENT_COLOR	     ? "RGB"   :
		content == CAIRO_CONTENT_COLOR_ALPHA ? "ARGB"  : "unknown content!",
		width, height,
		mode == CAIRO_BOILERPLATE_MODE_TEST ? "TEST" :
		mode == CAIRO_BOILERPLATE_MODE_PERF ? "PERF" : "unknown mode!");

    if (width == 0)
	width = 1;
    if (height == 0)
	height = 1;

    if (mode == CAIRO_BOILERPLATE_MODE_TEST)
	return _cairo_boilerplate_directfb_bitmap_create_surface (info, content, width, height);
    else /* mode == CAIRO_BOILERPLATE_MODE_PERF */
	return _cairo_boilerplate_directfb_window_create_surface (info, content, width, height);
}

static const cairo_boilerplate_target_t targets[] = {
    {
	"directfb", "directfb", NULL, NULL,
	CAIRO_SURFACE_TYPE_DIRECTFB, CAIRO_CONTENT_COLOR, 0,
	"cairo_directfb_surface_create",
	_cairo_boilerplate_directfb_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_directfb_cleanup,
	NULL, NULL, TRUE, FALSE, FALSE
    },
    {
	"directfb-bitmap", "directfb", NULL, NULL,
	CAIRO_SURFACE_TYPE_DIRECTFB, CAIRO_CONTENT_COLOR_ALPHA, 0,
	"cairo_directfb_surface_create",
	_cairo_boilerplate_directfb_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_directfb_cleanup,
	NULL, NULL, FALSE, FALSE, FALSE
    },
};
CAIRO_BOILERPLATE (directfb, targets);
