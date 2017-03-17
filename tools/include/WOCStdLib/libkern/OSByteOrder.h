//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#ifndef _OSBYTEORDER_H_
#define _OSBYTEORDER_H_

#ifdef WOCSTDLIB
#include <sys/_types.h>
#endif
#include <assert.h>
#include <inttypes.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

enum { OSUnknownByteOrder, OSLittleEndian, OSBigEndian };

int32_t OSHostByteOrder();
int64_t OSSwapInt64(int64_t x);
int32_t OSSwapInt32(int32_t x);
int16_t OSSwapInt16(int16_t x);
int16_t OSSwapBigToHostInt16(int16_t x);
int16_t OSSwapHostToLittleInt16(int16_t x);
int32_t OSSwapBigToHostInt32(int32_t x);
int16_t OSSwapHostToBigInt16(int16_t x);
int16_t OSSwapLittleToHostInt16(int16_t x);
int32_t OSSwapHostToBigInt32(int32_t x);
int32_t OSSwapHostToLittleInt32(int32_t x);
int32_t OSSwapLittleToHostInt32(int32_t x);
int64_t OSSwapBigToHostInt64(int64_t x);
int64_t OSSwapHostToBigInt64(int64_t x);
int64_t OSSwapHostToLittleInt64(int64_t x);
int64_t OSSwapLittleToHostInt64(int64_t x);

__END_DECLS

#endif
