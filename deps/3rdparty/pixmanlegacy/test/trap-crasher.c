#include <stdlib.h>
#include <pixman.h>

int
main()
{
    pixman_image_t *dst;
    pixman_trapezoid_t traps[1] = {
	{
	    2147483646,
	    2147483647,
	    {
		{ 0, 0 },
		{ 0, 2147483647 }
	    },
	    {
		{ 65536, 0 },
		{ 0, 2147483647 }
	    }
	},
    };

    dst = pixman_image_create_bits (PIXMAN_a8, 1, 1, NULL, -1);

    pixman_add_trapezoids (dst, 0, 0, sizeof (traps)/sizeof (traps[0]), traps);
    return (0);
}
