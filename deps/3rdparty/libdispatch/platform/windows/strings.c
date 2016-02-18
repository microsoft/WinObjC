#include "strings.h"

#if defined( _MSC_VER )

#include <intrin.h>

#pragma intrinsic(_BitScanForward)
#ifdef _M_X64
#pragma intrinsic(_BitScanForward64)
#endif

int ffs(int value)
{
	unsigned long index = 0;
	unsigned char isNonZero;

	isNonZero = _BitScanForward(&index, value);
	return isNonZero ? index + 1 : 0;
}

int ffsl(long value)
{
	unsigned long index = 0;
	unsigned char isNonZero;

	isNonZero = _BitScanForward(&index, value);
	return isNonZero ? index + 1 : 0;
}

#ifdef _M_X64
int ffsll(long long value)
{
	unsigned long index = 0;
	unsigned char isNonZero;

	isNonZero = _BitScanForward64(&index, value);
	return isNonZero ? index + 1 : 0;
}
#endif

int fls(int value)
{
	unsigned long index = 0;
	unsigned char isNonZero;

	isNonZero = _BitScanReverse(&index, value);
	return isNonZero ? index + 1 : 0;
}

int flsl(long value)
{
	unsigned long index = 0;
	unsigned char isNonZero;

	isNonZero = _BitScanReverse(&index, value);
	return isNonZero ? index + 1 : 0;
}

#ifdef _M_X64
int flsll(long long value)
{
	unsigned long index = 0;
	unsigned char isNonZero;

	isNonZero = _BitScanReverse64(&index, value);
	return isNonZero ? index + 1 : 0;
}
#endif

#endif
