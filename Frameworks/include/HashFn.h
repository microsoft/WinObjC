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

#pragma once

#include "Types.h"

inline uint32 rotl32(uint32 x, int8 r)
{
    return (x << r) | (x >> (32 - r));
}

inline uint32 fmix(uint32 h)
{
      h ^= h >> 16;
      h *= 0x85ebca6b;
      h ^= h >> 13;
      h *= 0xc2b2ae35;
      h ^= h >> 16;
      return h;
}

inline size_t murmurHash3(const void* key, int len, unsigned int seed)
{
    const uint8 * data = (const uint8*) key;
    const int nblocks = len / 4;

    uint32 h1 = seed;

    const uint32 c1 = 0xcc9e2d51;
    const uint32 c2 = 0x1b873593;

    //----------
    // body

    const uint32 * blocks = (const uint32 *)(data + nblocks*4);

    for(int i = -nblocks; i; i++)
    {
        uint32 k1 = blocks[i];

        k1 *= c1;
        k1 = rotl32(k1,15);
        k1 *= c2;
    
        h1 ^= k1;
        h1 = rotl32(h1,13); 
        h1 = h1*5+0xe6546b64;
    }

    //----------
    // tail

    const uint8 * tail = (const uint8*)(data + nblocks*4);

    uint32 k1 = 0;

    switch(len & 3)
    {
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
                k1 *= c1; k1 = rotl32(k1,15); k1 *= c2; h1 ^= k1;
    };

    //----------
    // finalization

    h1 ^= len;
    h1 = fmix(h1);
    return h1;
} 