#include <stdlib.h>
#include <config.h>
#include <assert.h>
#include "pixman-private.h" /* For 'inline' definition */

#define ARRAY_LENGTH(A) ((int) (sizeof (A) / sizeof ((A) [0])))

/* A primitive pseudorandom number generator,
 * taken from POSIX.1-2001 example
 */

extern uint32_t lcg_seed;
#ifdef USE_OPENMP
#pragma omp threadprivate(lcg_seed)
#endif

static inline uint32_t
lcg_rand (void)
{
    lcg_seed = lcg_seed * 1103515245 + 12345;
    return ((uint32_t)(lcg_seed / 65536) % 32768);
}

static inline void
lcg_srand (uint32_t seed)
{
    lcg_seed = seed;
}

static inline uint32_t
lcg_rand_n (int max)
{
    return lcg_rand () % max;
}

static inline uint32_t
lcg_rand_N (int max)
{
    uint32_t lo = lcg_rand ();
    uint32_t hi = lcg_rand () << 15;
    return (lo | hi) % max;
}

static inline uint32_t
lcg_rand_u32 (void)
{
    uint32_t lo = lcg_rand();
    uint32_t hi = lcg_rand();

    return (hi << 16) | lo;
}

/* CRC 32 computation
 */
uint32_t
compute_crc32 (uint32_t    in_crc32,
	       const void *buf,
	       size_t      buf_len);

/* perform endian conversion of pixel data
 */
void
image_endian_swap (pixman_image_t *img);

/* Allocate memory that is bounded by protected pages,
 * so that out-of-bounds access will cause segfaults
 */
void *
fence_malloc (int64_t len);

void
fence_free (void *data);

/* Generate n_bytes random bytes in fence_malloced memory */
uint8_t *
make_random_bytes (int n_bytes);

/* Return current time in seconds */
double
gettime (void);

uint32_t
get_random_seed (void);

/* main body of the fuzzer test */
int
fuzzer_test_main (const char *test_name,
		  int         default_number_of_iterations,
		  uint32_t    expected_checksum,
		  uint32_t    (*test_function)(int testnum, int verbose),
		  int         argc,
		  const char *argv[]);

void
fail_after (int seconds, const char *msg);

/* If possible, enable traps for floating point exceptions */
void enable_fp_exceptions(void);

/* A pair of macros which can help to detect corruption of
 * floating point registers after a function call. This may
 * happen if _mm_empty() call is forgotten in MMX/SSE2 fast
 * path code, or ARM NEON assembly optimized function forgets
 * to save/restore d8-d15 registers before use.
 */

#define FLOAT_REGS_CORRUPTION_DETECTOR_START()                 \
    static volatile double frcd_volatile_constant1 = 123451;   \
    static volatile double frcd_volatile_constant2 = 123452;   \
    static volatile double frcd_volatile_constant3 = 123453;   \
    static volatile double frcd_volatile_constant4 = 123454;   \
    static volatile double frcd_volatile_constant5 = 123455;   \
    static volatile double frcd_volatile_constant6 = 123456;   \
    static volatile double frcd_volatile_constant7 = 123457;   \
    static volatile double frcd_volatile_constant8 = 123458;   \
    double frcd_canary_variable1 = frcd_volatile_constant1;    \
    double frcd_canary_variable2 = frcd_volatile_constant2;    \
    double frcd_canary_variable3 = frcd_volatile_constant3;    \
    double frcd_canary_variable4 = frcd_volatile_constant4;    \
    double frcd_canary_variable5 = frcd_volatile_constant5;    \
    double frcd_canary_variable6 = frcd_volatile_constant6;    \
    double frcd_canary_variable7 = frcd_volatile_constant7;    \
    double frcd_canary_variable8 = frcd_volatile_constant8;

#define FLOAT_REGS_CORRUPTION_DETECTOR_FINISH()                \
    assert (frcd_canary_variable1 == frcd_volatile_constant1); \
    assert (frcd_canary_variable2 == frcd_volatile_constant2); \
    assert (frcd_canary_variable3 == frcd_volatile_constant3); \
    assert (frcd_canary_variable4 == frcd_volatile_constant4); \
    assert (frcd_canary_variable5 == frcd_volatile_constant5); \
    assert (frcd_canary_variable6 == frcd_volatile_constant6); \
    assert (frcd_canary_variable7 == frcd_volatile_constant7); \
    assert (frcd_canary_variable8 == frcd_volatile_constant8);

/* Try to get an aligned memory chunk */
void *
aligned_malloc (size_t align, size_t size);

void
initialize_palette (pixman_indexed_t *palette, uint32_t depth, int is_rgb);
