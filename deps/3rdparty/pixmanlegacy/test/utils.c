#define _GNU_SOURCE

#include "utils.h"
#include <signal.h>

#ifdef HAVE_GETTIMEOFDAY
#include <sys/time.h>
#else
#include <time.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif

#ifdef HAVE_FENV_H
#include <fenv.h>
#endif

/* Random number seed
 */

uint32_t lcg_seed;

/*----------------------------------------------------------------------------*\
 *  CRC-32 version 2.0.0 by Craig Bruce, 2006-04-29.
 *
 *  This program generates the CRC-32 values for the files named in the
 *  command-line arguments.  These are the same CRC-32 values used by GZIP,
 *  PKZIP, and ZMODEM.  The Crc32_ComputeBuf () can also be detached and
 *  used independently.
 *
 *  THIS PROGRAM IS PUBLIC-DOMAIN SOFTWARE.
 *
 *  Based on the byte-oriented implementation "File Verification Using CRC"
 *  by Mark R. Nelson in Dr. Dobb's Journal, May 1992, pp. 64-67.
 *
 *  v1.0.0: original release.
 *  v1.0.1: fixed printf formats.
 *  v1.0.2: fixed something else.
 *  v1.0.3: replaced CRC constant table by generator function.
 *  v1.0.4: reformatted code, made ANSI C.  1994-12-05.
 *  v2.0.0: rewrote to use memory buffer & static table, 2006-04-29.
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
 *  NAME:
 *     Crc32_ComputeBuf () - computes the CRC-32 value of a memory buffer
 *  DESCRIPTION:
 *     Computes or accumulates the CRC-32 value for a memory buffer.
 *     The 'inCrc32' gives a previously accumulated CRC-32 value to allow
 *     a CRC to be generated for multiple sequential buffer-fuls of data.
 *     The 'inCrc32' for the first buffer must be zero.
 *  ARGUMENTS:
 *     inCrc32 - accumulated CRC-32 value, must be 0 on first call
 *     buf     - buffer to compute CRC-32 value for
 *     bufLen  - number of bytes in buffer
 *  RETURNS:
 *     crc32 - computed CRC-32 value
 *  ERRORS:
 *     (no errors are possible)
\*----------------------------------------------------------------------------*/

uint32_t
compute_crc32 (uint32_t    in_crc32,
	       const void *buf,
	       size_t      buf_len)
{
    static const uint32_t crc_table[256] = {
	0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA, 0x076DC419, 0x706AF48F,
	0xE963A535, 0x9E6495A3, 0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
	0x09B64C2B, 0x7EB17CBD,	0xE7B82D07, 0x90BF1D91, 0x1DB71064, 0x6AB020F2,
	0xF3B97148, 0x84BE41DE, 0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
	0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,	0x14015C4F, 0x63066CD9,
	0xFA0F3D63, 0x8D080DF5, 0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
	0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B, 0x35B5A8FA, 0x42B2986C,
	0xDBBBC9D6, 0xACBCF940, 0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
	0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423,
	0xCFBA9599, 0xB8BDA50F, 0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
	0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D, 0x76DC4190, 0x01DB7106,
	0x98D220BC, 0xEFD5102A, 0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
	0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818, 0x7F6A0DBB, 0x086D3D2D,
	0x91646C97, 0xE6635C01, 0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
	0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457, 0x65B0D9C6, 0x12B7E950,
	0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
	0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2, 0x4ADFA541, 0x3DD895D7,
	0xA4D1C46D, 0xD3D6F4FB, 0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
	0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9, 0x5005713C, 0x270241AA,
	0xBE0B1010, 0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
	0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17, 0x2EB40D81,
	0xB7BD5C3B, 0xC0BA6CAD, 0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
	0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683, 0xE3630B12, 0x94643B84,
	0x0D6D6A3E, 0x7A6A5AA8, 0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
	0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB,
	0x196C3671, 0x6E6B06E7, 0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
	0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5, 0xD6D6A3E8, 0xA1D1937E,
	0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
	0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55,
	0x316E8EEF, 0x4669BE79, 0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
	0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F, 0xC5BA3BBE, 0xB2BD0B28,
	0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
	0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A, 0x9C0906A9, 0xEB0E363F,
	0x72076785, 0x05005713, 0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
	0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21, 0x86D3D2D4, 0xF1D4E242,
	0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
	0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C, 0x8F659EFF, 0xF862AE69,
	0x616BFFD3, 0x166CCF45, 0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
	0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB, 0xAED16A4A, 0xD9D65ADC,
	0x40DF0B66, 0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
	0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605, 0xCDD70693,
	0x54DE5729, 0x23D967BF, 0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
	0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
    };

    uint32_t              crc32;
    unsigned char *       byte_buf;
    size_t                i;

    /* accumulate crc32 for buffer */
    crc32 = in_crc32 ^ 0xFFFFFFFF;
    byte_buf = (unsigned char*) buf;

    for (i = 0; i < buf_len; i++)
	crc32 = (crc32 >> 8) ^ crc_table[(crc32 ^ byte_buf[i]) & 0xFF];

    return (crc32 ^ 0xFFFFFFFF);
}

/* perform endian conversion of pixel data
 */
void
image_endian_swap (pixman_image_t *img)
{
    int stride = pixman_image_get_stride (img);
    uint32_t *data = pixman_image_get_data (img);
    int height = pixman_image_get_height (img);
    int bpp = PIXMAN_FORMAT_BPP (pixman_image_get_format (img));
    int i, j;

    /* swap bytes only on big endian systems */
    volatile uint16_t endian_check_var = 0x1234;
    if (*(volatile uint8_t *)&endian_check_var != 0x12)
	return;

    if (bpp == 8)
	return;

    for (i = 0; i < height; i++)
    {
	uint8_t *line_data = (uint8_t *)data + stride * i;
	
	switch (bpp)
	{
	case 1:
	    for (j = 0; j < stride; j++)
	    {
		line_data[j] =
		    ((line_data[j] & 0x80) >> 7) |
		    ((line_data[j] & 0x40) >> 5) |
		    ((line_data[j] & 0x20) >> 3) |
		    ((line_data[j] & 0x10) >> 1) |
		    ((line_data[j] & 0x08) << 1) |
		    ((line_data[j] & 0x04) << 3) |
		    ((line_data[j] & 0x02) << 5) |
		    ((line_data[j] & 0x01) << 7);
	    }
	    break;
	case 4:
	    for (j = 0; j < stride; j++)
	    {
		line_data[j] = (line_data[j] >> 4) | (line_data[j] << 4);
	    }
	    break;
	case 16:
	    for (j = 0; j + 2 <= stride; j += 2)
	    {
		char t1 = line_data[j + 0];
		char t2 = line_data[j + 1];

		line_data[j + 1] = t1;
		line_data[j + 0] = t2;
	    }
	    break;
	case 24:
	    for (j = 0; j + 3 <= stride; j += 3)
	    {
		char t1 = line_data[j + 0];
		char t2 = line_data[j + 1];
		char t3 = line_data[j + 2];

		line_data[j + 2] = t1;
		line_data[j + 1] = t2;
		line_data[j + 0] = t3;
	    }
	    break;
	case 32:
	    for (j = 0; j + 4 <= stride; j += 4)
	    {
		char t1 = line_data[j + 0];
		char t2 = line_data[j + 1];
		char t3 = line_data[j + 2];
		char t4 = line_data[j + 3];

		line_data[j + 3] = t1;
		line_data[j + 2] = t2;
		line_data[j + 1] = t3;
		line_data[j + 0] = t4;
	    }
	    break;
	default:
	    assert (FALSE);
	    break;
	}
    }
}

#define N_LEADING_PROTECTED	10
#define N_TRAILING_PROTECTED	10

typedef struct
{
    void *addr;
    uint32_t len;
    uint8_t *trailing;
    int n_bytes;
} info_t;

#if defined(HAVE_MPROTECT) && defined(HAVE_GETPAGESIZE) && defined(HAVE_SYS_MMAN_H) && defined(HAVE_MMAP)

/* This is apparently necessary on at least OS X */
#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS MAP_ANON
#endif

void *
fence_malloc (int64_t len)
{
    unsigned long page_size = getpagesize();
    unsigned long page_mask = page_size - 1;
    uint32_t n_payload_bytes = (len + page_mask) & ~page_mask;
    uint32_t n_bytes =
	(page_size * (N_LEADING_PROTECTED + N_TRAILING_PROTECTED + 2) +
	 n_payload_bytes) & ~page_mask;
    uint8_t *initial_page;
    uint8_t *leading_protected;
    uint8_t *trailing_protected;
    uint8_t *payload;
    uint8_t *addr;

    if (len < 0)
	abort();
    
    addr = mmap (NULL, n_bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
		 -1, 0);

    if (addr == MAP_FAILED)
    {
	printf ("mmap failed on %lld %u\n", (long long int)len, n_bytes);
	return NULL;
    }

    initial_page = (uint8_t *)(((unsigned long)addr + page_mask) & ~page_mask);
    leading_protected = initial_page + page_size;
    payload = leading_protected + N_LEADING_PROTECTED * page_size;
    trailing_protected = payload + n_payload_bytes;

    ((info_t *)initial_page)->addr = addr;
    ((info_t *)initial_page)->len = len;
    ((info_t *)initial_page)->trailing = trailing_protected;
    ((info_t *)initial_page)->n_bytes = n_bytes;

    if ((mprotect (leading_protected, N_LEADING_PROTECTED * page_size,
		  PROT_NONE) == -1) ||
	(mprotect (trailing_protected, N_TRAILING_PROTECTED * page_size,
		  PROT_NONE) == -1))
    {
	munmap (addr, n_bytes);
	return NULL;
    }

    return payload;
}

void
fence_free (void *data)
{
    uint32_t page_size = getpagesize();
    uint8_t *payload = data;
    uint8_t *leading_protected = payload - N_LEADING_PROTECTED * page_size;
    uint8_t *initial_page = leading_protected - page_size;
    info_t *info = (info_t *)initial_page;

    munmap (info->addr, info->n_bytes);
}

#else

void *
fence_malloc (int64_t len)
{
    return malloc (len);
}

void
fence_free (void *data)
{
    free (data);
}

#endif

uint8_t *
make_random_bytes (int n_bytes)
{
    uint8_t *bytes = fence_malloc (n_bytes);
    int i;

    if (!bytes)
	return NULL;

    for (i = 0; i < n_bytes; ++i)
	bytes[i] = lcg_rand () & 0xff;

    return bytes;
}

/*
 * A function, which can be used as a core part of the test programs,
 * intended to detect various problems with the help of fuzzing input
 * to pixman API (according to some templates, aka "smart" fuzzing).
 * Some general information about such testing can be found here:
 * http://en.wikipedia.org/wiki/Fuzz_testing
 *
 * It may help detecting:
 *  - crashes on bad handling of valid or reasonably invalid input to
 *    pixman API.
 *  - deviations from the behavior of older pixman releases.
 *  - deviations from the behavior of the same pixman release, but
 *    configured in a different way (for example with SIMD optimizations
 *    disabled), or running on a different OS or hardware.
 *
 * The test is performed by calling a callback function a huge number
 * of times. The callback function is expected to run some snippet of
 * pixman code with pseudorandom variations to the data feeded to
 * pixman API. A result of running each callback function should be
 * some deterministic value which depends on test number (test number
 * can be used as a seed for PRNG). When 'verbose' argument is nonzero,
 * callback function is expected to print to stdout some information
 * about what it does.
 *
 * Return values from many small tests are accumulated together and
 * used as final checksum, which can be compared to some expected
 * value. Running the tests not individually, but in a batch helps
 * to reduce process start overhead and also allows to parallelize
 * testing and utilize multiple CPU cores.
 *
 * The resulting executable can be run without any arguments. In
 * this case it runs a batch of tests starting from 1 and up to
 * 'default_number_of_iterations'. The resulting checksum is
 * compared with 'expected_checksum' and FAIL or PASS verdict
 * depends on the result of this comparison.
 *
 * If the executable is run with 2 numbers provided as command line
 * arguments, they specify the starting and ending numbers for a test
 * batch.
 *
 * If the executable is run with only one number provided as a command
 * line argument, then this number is used to call the callback function
 * once, and also with verbose flag set.
 */
int
fuzzer_test_main (const char *test_name,
		  int         default_number_of_iterations,
		  uint32_t    expected_checksum,
		  uint32_t    (*test_function)(int testnum, int verbose),
		  int         argc,
		  const char *argv[])
{
    int i, n1 = 1, n2 = 0;
    uint32_t checksum = 0;
    int verbose = getenv ("VERBOSE") != NULL;

    if (argc >= 3)
    {
	n1 = atoi (argv[1]);
	n2 = atoi (argv[2]);
	if (n2 < n1)
	{
	    printf ("invalid test range\n");
	    return 1;
	}
    }
    else if (argc >= 2)
    {
	n2 = atoi (argv[1]);
	checksum = test_function (n2, 1);
	printf ("%d: checksum=%08X\n", n2, checksum);
	return 0;
    }
    else
    {
	n1 = 1;
	n2 = default_number_of_iterations;
    }

#ifdef USE_OPENMP
    #pragma omp parallel for reduction(+:checksum) default(none) \
					shared(n1, n2, test_function, verbose)
#endif
    for (i = n1; i <= n2; i++)
    {
	uint32_t crc = test_function (i, 0);
	if (verbose)
	    printf ("%d: %08X\n", i, crc);
	checksum += crc;
    }

    if (n1 == 1 && n2 == default_number_of_iterations)
    {
	if (checksum == expected_checksum)
	{
	    printf ("%s test passed (checksum=%08X)\n",
		    test_name, checksum);
	}
	else
	{
	    printf ("%s test failed! (checksum=%08X, expected %08X)\n",
		    test_name, checksum, expected_checksum);
	    return 1;
	}
    }
    else
    {
	printf ("%d-%d: checksum=%08X\n", n1, n2, checksum);
    }

    return 0;
}

/* Try to obtain current time in seconds */
double
gettime (void)
{
#ifdef HAVE_GETTIMEOFDAY
    struct timeval tv;

    gettimeofday (&tv, NULL);
    return (double)((int64_t)tv.tv_sec * 1000000 + tv.tv_usec) / 1000000.;
#else
    return (double)clock() / (double)CLOCKS_PER_SEC;
#endif
}

uint32_t
get_random_seed (void)
{
    double d = gettime();

    lcg_srand (*(uint32_t *)&d);

    return lcg_rand_u32 ();
}

static const char *global_msg;

static void
on_alarm (int signo)
{
    printf ("%s\n", global_msg);
    exit (1);
}

void
fail_after (int seconds, const char *msg)
{
#ifdef HAVE_SIGACTION
#ifdef HAVE_ALARM
    struct sigaction action;

    global_msg = msg;

    memset (&action, 0, sizeof (action));
    action.sa_handler = on_alarm;

    alarm (seconds);

    sigaction (SIGALRM, &action, NULL);
#endif
#endif
}

void
enable_fp_exceptions (void)
{
#ifdef HAVE_FENV_H
#ifdef HAVE_FEENABLEEXCEPT
    /* Note: we don't enable the FE_INEXACT trap because
     * that happens quite commonly. It is possible that
     * over- and underflow should similarly be considered
     * okay, but for now the test suite passes with them
     * enabled, and it's useful to know if they start
     * occuring.
     */
    feenableexcept (FE_DIVBYZERO	|
		    FE_INVALID		|
		    FE_OVERFLOW		|
		    FE_UNDERFLOW);
#endif
#endif
}

void *
aligned_malloc (size_t align, size_t size)
{
    void *result;

#ifdef HAVE_POSIX_MEMALIGN
    if (posix_memalign (&result, align, size) != 0)
      result = NULL;
#else
    result = malloc (size);
#endif

    return result;
}

#define CONVERT_15(c, is_rgb)						\
    (is_rgb?								\
     ((((c) >> 3) & 0x001f) |						\
      (((c) >> 6) & 0x03e0) |						\
      (((c) >> 9) & 0x7c00)) :						\
     (((((c) >> 16) & 0xff) * 153 +					\
       (((c) >>  8) & 0xff) * 301 +					\
       (((c)      ) & 0xff) * 58) >> 2))

void
initialize_palette (pixman_indexed_t *palette, uint32_t depth, int is_rgb)
{
    int i;
    uint32_t mask = (1 << depth) - 1;

    for (i = 0; i < 32768; ++i)
	palette->ent[i] = lcg_rand() & mask;

    memset (palette->rgba, 0, sizeof (palette->rgba));

    for (i = 0; i < mask + 1; ++i)
    {
	uint32_t rgba24;
 	pixman_bool_t retry;
	uint32_t i15;

	/* We filled the rgb->index map with random numbers, but we
	 * do need the ability to round trip, that is if some indexed
	 * color expands to an argb24, then the 15 bit version of that
	 * color must map back to the index. Anything else, we don't
	 * care about too much.
	 */
	do
	{
	    uint32_t old_idx;

	    rgba24 = lcg_rand();
	    i15 = CONVERT_15 (rgba24, is_rgb);

	    old_idx = palette->ent[i15];
	    if (CONVERT_15 (palette->rgba[old_idx], is_rgb) == i15)
		retry = 1;
	    else
		retry = 0;
	} while (retry);

	palette->rgba[i] = rgba24;
	palette->ent[i15] = i;
    }

    for (i = 0; i < mask + 1; ++i)
    {
	assert (palette->ent[CONVERT_15 (palette->rgba[i], is_rgb)] == i);
    }
}
