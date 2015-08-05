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

// This header file is not yet implemented

#ifndef _OSATOMIC_H_
#define _OSATOMIC_H_

typedef int         __int32_t;

__BEGIN_DECLS

__int32_t OSAtomicAdd32(__int32_t val, volatile __int32_t *p);
__int32_t OSAtomicAdd32Barrier(__int32_t val, volatile __int32_t *p);

static __inline __int32_t
OSAtomicDecrement32(__int32_t *x)
{
    return OSAtomicAdd32(-1, x);
}

static __inline __int32_t
OSAtomicIncrement32(__int32_t *x)
{
    return OSAtomicAdd32(1, x);
}


void OSMemoryBarrier();

static __inline __int32_t OSAtomicIncrement32Barrier(volatile __int32_t *val)
{
    return OSAtomicAdd32Barrier(1, val);
}
static __inline __int32_t OSAtomicDecrement32Barrier(volatile __int32_t *val)
{
    return OSAtomicAdd32Barrier(-1, val);
}

__END_DECLS

#endif