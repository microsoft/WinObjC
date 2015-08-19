#include "strings.h"

#if defined( _MSC_VER )

#include <intrin.h>

#pragma intrinsic(_BitScanForward)
#ifdef _M_X64
#pragma intrinsic(_BitScanForward64)
#elif defined( WINOBJC )
/* ===-------- Intrin.h ---------------------------------------------------===
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */

static inline unsigned char
_BitScanForward(unsigned long *_Index, unsigned long _Mask) {
  if (!_Mask)
    return 0;
  *_Index = __builtin_ctzl(_Mask);
  return 1;
}

static inline unsigned char
_BitScanReverse(unsigned long *_Index, unsigned long _Mask) {
  if (!_Mask)
    return 0;
  *_Index = 31 - __builtin_clzl(_Mask);
  return 1;
}
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
