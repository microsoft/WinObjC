#include <stdio.h>
#include "utils.h"
#include <sys/types.h>

#if 0
#define fence_malloc malloc
#define fence_free free
#define make_random_bytes malloc
#endif

static const pixman_format_code_t image_formats[] =
{
    PIXMAN_a8r8g8b8,
    PIXMAN_x8r8g8b8,
    PIXMAN_r5g6b5,
    PIXMAN_r3g3b2,
    PIXMAN_a8,
    PIXMAN_a8b8g8r8,
    PIXMAN_x8b8g8r8,
    PIXMAN_b8g8r8a8,
    PIXMAN_b8g8r8x8,
    PIXMAN_r8g8b8a8,
    PIXMAN_r8g8b8x8,
    PIXMAN_x14r6g6b6,
    PIXMAN_r8g8b8,
    PIXMAN_b8g8r8,
    PIXMAN_r5g6b5,
    PIXMAN_b5g6r5,
    PIXMAN_x2r10g10b10,
    PIXMAN_a2r10g10b10,
    PIXMAN_x2b10g10r10,
    PIXMAN_a2b10g10r10,
    PIXMAN_a1r5g5b5,
    PIXMAN_x1r5g5b5,
    PIXMAN_a1b5g5r5,
    PIXMAN_x1b5g5r5,
    PIXMAN_a4r4g4b4,
    PIXMAN_x4r4g4b4,
    PIXMAN_a4b4g4r4,
    PIXMAN_x4b4g4r4,
    PIXMAN_a8,
    PIXMAN_r3g3b2,
    PIXMAN_b2g3r3,
    PIXMAN_a2r2g2b2,
    PIXMAN_a2b2g2r2,
    PIXMAN_c8,
    PIXMAN_g8,
    PIXMAN_x4c4,
    PIXMAN_x4g4,
    PIXMAN_c4,
    PIXMAN_g4,
    PIXMAN_g1,
    PIXMAN_x4a4,
    PIXMAN_a4,
    PIXMAN_r1g2b1,
    PIXMAN_b1g2r1,
    PIXMAN_a1r1g1b1,
    PIXMAN_a1b1g1r1,
    PIXMAN_a1
};

static pixman_filter_t filters[] =
{
    PIXMAN_FILTER_NEAREST,
    PIXMAN_FILTER_BILINEAR,
    PIXMAN_FILTER_FAST,
    PIXMAN_FILTER_GOOD,
    PIXMAN_FILTER_BEST,
    PIXMAN_FILTER_CONVOLUTION
};

static int
get_size (void)
{
    switch (lcg_rand_n (28))
    {
    case 0:
	return 1;

    case 1:
	return 2;

    default:
    case 2:
	return lcg_rand_n (200);

    case 4:
	return lcg_rand_n (2000) + 1000;

    case 5:
	return 65535;

    case 6:
	return 65536;

    case 7:
	return lcg_rand_N (64000) + 63000;
    }
}

static void
destroy (pixman_image_t *image, void *data)
{
    if (image->type == BITS && image->bits.free_me != image->bits.bits)
    {
	uint32_t *bits;

	if (image->bits.bits != (void *)0x01)
	{
	    bits = image->bits.bits;

	    if (image->bits.rowstride < 0)
		bits -= (- image->bits.rowstride * (image->bits.height - 1));

	    fence_free (bits);
	}
    }

    free (data);
}

static uint32_t
real_reader (const void *src, int size)
{
    switch (size)
    {
    case 1:
	return *(uint8_t *)src;
    case 2:
	return *(uint16_t *)src;
    case 4:
	return *(uint32_t *)src;
    default:
	assert (0);
	return 0; /* silence MSVC */
    }
}

static void
real_writer (void *src, uint32_t value, int size)
{
    switch (size)
    {
    case 1:
	*(uint8_t *)src = value;
	break;

    case 2:
	*(uint16_t *)src = value;
	break;

    case 4:
	*(uint32_t *)src = value;
	break;

    default:
	assert (0);
	break;
    }
}

static uint32_t
fake_reader (const void *src, int size)
{
    uint32_t r = lcg_rand_u32 ();

    assert (size == 1 || size == 2 || size == 4);
    return r & ((1 << (size * 8)) - 1);
}

static void
fake_writer (void *src, uint32_t value, int size)
{
    assert (size == 1 || size == 2 || size == 4);
}

static int32_t
log_rand (void)
{
    uint32_t mask;

    mask = (1 << lcg_rand_n (31)) - 1;

    return (lcg_rand () & mask) - (mask >> 1);
}

static pixman_image_t *
create_random_bits_image (void)
{
    pixman_format_code_t format;
    pixman_indexed_t *indexed;
    pixman_image_t *image;
    int width, height, stride;
    uint32_t *bits;
    pixman_read_memory_func_t read_func = NULL;
    pixman_write_memory_func_t write_func = NULL;
    pixman_filter_t filter;
    pixman_fixed_t *coefficients = NULL;
    int n_coefficients = 0;

    /* format */
    format = image_formats[lcg_rand_n (ARRAY_LENGTH (image_formats))];

    indexed = NULL;
    if (PIXMAN_FORMAT_TYPE (format) == PIXMAN_TYPE_COLOR)
    {
	indexed = malloc (sizeof (pixman_indexed_t));

	initialize_palette (indexed, PIXMAN_FORMAT_BPP (format), TRUE);
    }
    else if (PIXMAN_FORMAT_TYPE (format) == PIXMAN_TYPE_GRAY)
    {
	indexed = malloc (sizeof (pixman_indexed_t));

	initialize_palette (indexed, PIXMAN_FORMAT_BPP (format), FALSE);
    }
    else
    {
	indexed = NULL;
    }

    /* size */
    width = get_size ();
    height = get_size ();

    if ((uint64_t)width * height > 200000)
    {
	if (lcg_rand_n(2) == 0)
	    height = 200000 / width;
	else
	    width = 200000 / height;
    }

    if (height == 0)
	height = 1;
    if (width == 0)
	width = 1;

    /* bits */
    switch (lcg_rand_n (7))
    {
    default:
    case 0:
	stride = width * PIXMAN_FORMAT_BPP (format) + lcg_rand_n (17);
	stride = (stride + 3) & (~3);
	bits = (uint32_t *)make_random_bytes (height * stride);
	break;

    case 1:
	stride = 0;
	bits = NULL;
	break;

    case 2: /* Zero-filled */
	stride = width * PIXMAN_FORMAT_BPP (format) + lcg_rand_n (17);
	stride = (stride + 3) & (~3);
	bits = fence_malloc (height * stride);
	if (!bits)
	    return NULL;
	memset (bits, 0, height * stride);
	break;

    case 3: /* Filled with 0xFF */
	stride = width * PIXMAN_FORMAT_BPP (format) + lcg_rand_n (17);
	stride = (stride + 3) & (~3);
	bits = fence_malloc (height * stride);
	if (!bits)
	    return NULL;
	memset (bits, 0xff, height * stride);
	break;

    case 4: /* bits is a bad pointer, has read/write functions */
	stride = 232;
	bits = (void *)0x01;
	read_func = fake_reader;
	write_func = fake_writer;
	break;

    case 5: /* bits is a real pointer, has read/write functions */
	stride = width * PIXMAN_FORMAT_BPP (format) + lcg_rand_n (17);
	stride = (stride + 3) & (~3);
	bits = fence_malloc (height * stride);
	if (!bits)
	    return NULL;
	memset (bits, 0xff, height * stride);
	read_func = real_reader;
	write_func = real_writer;
	break;

    case 6: /* bits is a real pointer, stride is negative */
	stride = (width * PIXMAN_FORMAT_BPP (format) + lcg_rand_n (17));
	stride = (stride + 3) & (~3);
	bits = (uint32_t *)make_random_bytes (height * stride);
	if (!bits)
	    return NULL;
	bits += ((height - 1) * stride) / 4;
	stride = - stride;
	break;
    }

    /* Filter */
    filter = filters[lcg_rand_n (ARRAY_LENGTH (filters))];
    if (filter == PIXMAN_FILTER_CONVOLUTION)
    {
	int width = lcg_rand_n (17);
	int height = lcg_rand_n (19);

	n_coefficients = width * height + 2;
	coefficients = malloc (n_coefficients * sizeof (pixman_fixed_t));

	if (coefficients)
	{
	    int i;

	    for (i = 0; i < width * height; ++i)
		coefficients[i + 2] = lcg_rand_u32();

	    coefficients[0] = width << 16;
	    coefficients[1] = height << 16;
	}
	else
	{
	    filter = PIXMAN_FILTER_BEST;
	}
    }

    /* Finally create the image */
    image = pixman_image_create_bits (format, width, height, bits, stride);
    if (!image)
	return NULL;

    pixman_image_set_indexed (image, indexed);
    pixman_image_set_destroy_function (image, destroy, indexed);
    pixman_image_set_accessors (image, read_func, write_func);
    pixman_image_set_filter (image, filter, coefficients, n_coefficients);

    return image;
}

static pixman_repeat_t repeats[] =
{
    PIXMAN_REPEAT_NONE,
    PIXMAN_REPEAT_NORMAL,
    PIXMAN_REPEAT_REFLECT,
    PIXMAN_REPEAT_PAD
};

static uint32_t
absolute (int32_t i)
{
    return i < 0? -i : i;
}

static void
set_general_properties (pixman_image_t *image, pixman_bool_t allow_alpha_map)
{
    pixman_repeat_t repeat;

    /* Set properties that are generic to all images */

    /* Repeat */
    repeat = repeats[lcg_rand_n (ARRAY_LENGTH (repeats))];
    pixman_image_set_repeat (image, repeat);

    /* Alpha map */
    if (allow_alpha_map && lcg_rand_n (3) == 0)
    {
	pixman_image_t *alpha_map;
	int16_t x, y;

	alpha_map = create_random_bits_image ();

	if (alpha_map)
	{
	    set_general_properties (alpha_map, FALSE);

	    x = lcg_rand_N (100000) - 65536;
	    y = lcg_rand_N (100000) - 65536;

	    pixman_image_set_alpha_map (image, alpha_map, x, y);

	    pixman_image_unref (alpha_map);
	}
    }

    /* Component alpha */
    pixman_image_set_component_alpha (image, lcg_rand_n (3) == 0);

    /* Clip region */
    if (lcg_rand_n (8) != 0)
    {
	pixman_region32_t region;
	int i, n_rects;

	pixman_region32_init (&region);

	switch (lcg_rand_n (10))
	{
	case 0:
	    n_rects = 0;
	    break;

	case 1: case 2: case 3:
	    n_rects = 1;
	    break;

	case 4: case 5:
	    n_rects = 2;
	    break;

	case 6: case 7:
	    n_rects = 3;

	default:
	    n_rects = lcg_rand_n (100);
	    break;
	}

	for (i = 0; i < n_rects; ++i)
	{
	    uint32_t width, height;
	    int x, y;

	    x = log_rand();
	    y = log_rand();
	    width = absolute (log_rand ()) + 1;
	    height = absolute (log_rand ()) + 1;

	    pixman_region32_union_rect (
		&region, &region, x, y, width, height);
	}

	pixman_image_set_clip_region32 (image, &region);

	pixman_region32_fini (&region);
    }

    /* Whether source clipping is enabled */
    pixman_image_set_source_clipping (image, !!lcg_rand_n (2));

    /* Client clip */
    pixman_image_set_has_client_clip (image, !!lcg_rand_n (2));

    /* Transform */
    if (lcg_rand_n (5) < 2)
    {
	pixman_transform_t xform;
	int i, j, k;
	uint32_t tx, ty, sx, sy;
	uint32_t c, s;

	memset (&xform, 0, sizeof xform);
	xform.matrix[0][0] = pixman_fixed_1;
	xform.matrix[1][1] = pixman_fixed_1;
	xform.matrix[2][2] = pixman_fixed_1;

	for (k = 0; k < 3; ++k)
	{
	    switch (lcg_rand_n (4))
	    {
	    case 0:
		/* rotation */
		c = lcg_rand_N (2 * 65536) - 65536;
		s = lcg_rand_N (2 * 65536) - 65536;
		pixman_transform_rotate (&xform, NULL, c, s);
		break;

	    case 1:
		/* translation */
		tx = lcg_rand_u32();
		ty = lcg_rand_u32();
		pixman_transform_translate (&xform, NULL, tx, ty);
		break;

	    case 2:
		/* scale */
		sx = lcg_rand_u32();
		sy = lcg_rand_u32();
		pixman_transform_scale (&xform, NULL, sx, sy);
		break;

	    case 3:
		if (lcg_rand_n (16) == 0)
		{
		    /* random */
		    for (i = 0; i < 3; ++i)
			for (j = 0; j < 3; ++j)
			    xform.matrix[i][j] = lcg_rand_u32();
		    break;
		}
		else if (lcg_rand_n (16) == 0)
		{
		    /* zero */
		    memset (&xform, 0, sizeof xform);
		}
		break;
	    }
	}

	pixman_image_set_transform (image, &xform);
    }
}

static pixman_color_t
random_color (void)
{
    pixman_color_t color =
    {
	lcg_rand() & 0xffff,
	lcg_rand() & 0xffff,
	lcg_rand() & 0xffff,
	lcg_rand() & 0xffff,
    };

    return color;
}


static pixman_image_t *
create_random_solid_image (void)
{
    pixman_color_t color = random_color();
    pixman_image_t *image = pixman_image_create_solid_fill (&color);

    return image;
}

static pixman_gradient_stop_t *
create_random_stops (int *n_stops)
{
    pixman_fixed_t step;
    pixman_fixed_t s;
    int i;
    pixman_gradient_stop_t *stops;

    *n_stops = lcg_rand_n (50) + 1;

    step = pixman_fixed_1 / *n_stops;

    stops = malloc (*n_stops * sizeof (pixman_gradient_stop_t));

    s = 0;
    for (i = 0; i < (*n_stops) - 1; ++i)
    {
	stops[i].x = s;
	stops[i].color = random_color();

	s += step;
    }

    stops[*n_stops - 1].x = pixman_fixed_1;
    stops[*n_stops - 1].color = random_color();

    return stops;
}

static pixman_point_fixed_t
create_random_point (void)
{
    pixman_point_fixed_t p;

    p.x = log_rand ();
    p.y = log_rand ();

    return p;
}

static pixman_image_t *
create_random_linear_image (void)
{
    int n_stops;
    pixman_gradient_stop_t *stops;
    pixman_point_fixed_t p1, p2;
    pixman_image_t *result;

    stops = create_random_stops (&n_stops);
    if (!stops)
	return NULL;

    p1 = create_random_point ();
    p2 = create_random_point ();

    result = pixman_image_create_linear_gradient (&p1, &p2, stops, n_stops);

    free (stops);

    return result;
}

static pixman_image_t *
create_random_radial_image (void)
{
    int n_stops;
    pixman_gradient_stop_t *stops;
    pixman_point_fixed_t inner_c, outer_c;
    pixman_fixed_t inner_r, outer_r;
    pixman_image_t *result;

    inner_c = create_random_point();
    outer_c = create_random_point();
    inner_r = lcg_rand();
    outer_r = lcg_rand();

    stops = create_random_stops (&n_stops);

    if (!stops)
	return NULL;

    result = pixman_image_create_radial_gradient (
	&inner_c, &outer_c, inner_r, outer_r, stops, n_stops);

    free (stops);

    return result;
}

static pixman_image_t *
create_random_conical_image (void)
{
    pixman_gradient_stop_t *stops;
    int n_stops;
    pixman_point_fixed_t c;
    pixman_fixed_t angle;
    pixman_image_t *result;

    c = create_random_point();
    angle = lcg_rand();

    stops = create_random_stops (&n_stops);

    if (!stops)
	return NULL;

    result = pixman_image_create_conical_gradient (&c, angle, stops, n_stops);

    free (stops);

    return result;
}

static pixman_image_t *
create_random_image (void)
{
    pixman_image_t *result;

    switch (lcg_rand_n (5))
    {
    default:
    case 0:
	result = create_random_bits_image ();
	break;

    case 1:
	result = create_random_solid_image ();
	break;

    case 2:
	result = create_random_linear_image ();
	break;

    case 3:
	result = create_random_radial_image ();
	break;

    case 4:
	result = create_random_conical_image ();
	break;
    }

    if (result)
	set_general_properties (result, TRUE);

    return result;
}

static const pixman_op_t op_list[] =
{
    PIXMAN_OP_SRC,
    PIXMAN_OP_OVER,
    PIXMAN_OP_ADD,
    PIXMAN_OP_CLEAR,
    PIXMAN_OP_SRC,
    PIXMAN_OP_DST,
    PIXMAN_OP_OVER,
    PIXMAN_OP_OVER_REVERSE,
    PIXMAN_OP_IN,
    PIXMAN_OP_IN_REVERSE,
    PIXMAN_OP_OUT,
    PIXMAN_OP_OUT_REVERSE,
    PIXMAN_OP_ATOP,
    PIXMAN_OP_ATOP_REVERSE,
    PIXMAN_OP_XOR,
    PIXMAN_OP_ADD,
    PIXMAN_OP_SATURATE,
    PIXMAN_OP_DISJOINT_CLEAR,
    PIXMAN_OP_DISJOINT_SRC,
    PIXMAN_OP_DISJOINT_DST,
    PIXMAN_OP_DISJOINT_OVER,
    PIXMAN_OP_DISJOINT_OVER_REVERSE,
    PIXMAN_OP_DISJOINT_IN,
    PIXMAN_OP_DISJOINT_IN_REVERSE,
    PIXMAN_OP_DISJOINT_OUT,
    PIXMAN_OP_DISJOINT_OUT_REVERSE,
    PIXMAN_OP_DISJOINT_ATOP,
    PIXMAN_OP_DISJOINT_ATOP_REVERSE,
    PIXMAN_OP_DISJOINT_XOR,
    PIXMAN_OP_CONJOINT_CLEAR,
    PIXMAN_OP_CONJOINT_SRC,
    PIXMAN_OP_CONJOINT_DST,
    PIXMAN_OP_CONJOINT_OVER,
    PIXMAN_OP_CONJOINT_OVER_REVERSE,
    PIXMAN_OP_CONJOINT_IN,
    PIXMAN_OP_CONJOINT_IN_REVERSE,
    PIXMAN_OP_CONJOINT_OUT,
    PIXMAN_OP_CONJOINT_OUT_REVERSE,
    PIXMAN_OP_CONJOINT_ATOP,
    PIXMAN_OP_CONJOINT_ATOP_REVERSE,
    PIXMAN_OP_CONJOINT_XOR,
    PIXMAN_OP_MULTIPLY,
    PIXMAN_OP_SCREEN,
    PIXMAN_OP_OVERLAY,
    PIXMAN_OP_DARKEN,
    PIXMAN_OP_LIGHTEN,
    PIXMAN_OP_COLOR_DODGE,
    PIXMAN_OP_COLOR_BURN,
    PIXMAN_OP_HARD_LIGHT,
    PIXMAN_OP_DIFFERENCE,
    PIXMAN_OP_EXCLUSION,
    PIXMAN_OP_SOFT_LIGHT,
    PIXMAN_OP_HSL_HUE,
    PIXMAN_OP_HSL_SATURATION,
    PIXMAN_OP_HSL_COLOR,
    PIXMAN_OP_HSL_LUMINOSITY,
};

static void
run_test (uint32_t seed, pixman_bool_t verbose, uint32_t mod)
{
    pixman_image_t *source, *mask, *dest;
    pixman_op_t op;

    if (verbose)
    {
	if (mod == 0 || (seed % mod) == 0)
	    printf ("Seed 0x%08x\n", seed);
    }
	    
    lcg_srand (seed);

    source = create_random_image ();
    mask   = create_random_image ();
    dest   = create_random_bits_image ();

    if (source && mask && dest)
    {
	set_general_properties (dest, TRUE);

	op = op_list [lcg_rand_n (ARRAY_LENGTH (op_list))];

	pixman_image_composite32 (op,
				  source, mask, dest,
				  log_rand(), log_rand(),
				  log_rand(), log_rand(),
				  log_rand(), log_rand(),
				  absolute (log_rand()),
				  absolute (log_rand()));
    }
    if (source)
	pixman_image_unref (source);
    if (mask)
	pixman_image_unref (mask);
    if (dest)
	pixman_image_unref (dest);
}

static pixman_bool_t
get_int (char *s, uint32_t *i)
{
    char *end;
    int p;

    p = strtol (s, &end, 0);

    if (end != s && *end == 0)
    {
	*i = p;
	return TRUE;
    }

    return FALSE;
}

int
main (int argc, char **argv)
{
    int verbose = FALSE;
    uint32_t seed = 1;
    uint32_t n_tests = 0xffffffff;
    uint32_t mod = 0;
    pixman_bool_t use_threads = TRUE;
    uint32_t i;

    pixman_disable_out_of_bounds_workaround ();

    enable_fp_exceptions();

    if (getenv ("VERBOSE") != NULL)
	verbose = TRUE;

    for (i = 1; i < argc; ++i)
    {
	if (strcmp (argv[i], "-v") == 0)
	{
	    verbose = TRUE;

	    if (i + 1 < argc)
	    {
		get_int (argv[i + 1], &mod);
		i++;
	    }
	}
	else if (strcmp (argv[i], "-s") == 0 && i + 1 < argc)
	{
	    get_int (argv[i + 1], &seed);
	    use_threads = FALSE;
	    i++;
	}
	else if (strcmp (argv[i], "-n") == 0 && i + 1 < argc)
	{
	    get_int (argv[i + 1], &n_tests);
	    i++;
	}
	else
	{
	    if (strcmp (argv[i], "-h") != 0)
		printf ("Unknown option '%s'\n\n", argv[i]);

	    printf ("Options:\n\n"
		    "-n <number>        Number of tests to run\n"
		    "-s <seed> 	        Seed of first test (ignored if PIXMAN_RANDOMIZE_TESTS is set)\n"
		    "-v                 Print out seeds\n"
		    "-v <n>             Print out every n'th seed\n\n");

	    exit (-1);
	}
    }

    if (n_tests == 0xffffffff)
	n_tests = 8000;

    if (getenv ("PIXMAN_RANDOMIZE_TESTS"))
    {
	seed = get_random_seed();
	printf ("First seed: 0x%08x\n", seed);
    }

    if (use_threads)
    {
#ifdef USE_OPENMP
#   pragma omp parallel for default(none) shared(verbose, n_tests, mod, seed)
#endif
	for (i = seed; i < seed + n_tests; ++i)
	    run_test (i, verbose, mod);
    }
    else
    {
	for (i = seed; i < seed + n_tests; ++i)
	    run_test (i, verbose, mod);
    }

    return 0;
}
