/* Copyright (c) 2008-2009 Christopher J. W. Lloyd

Permission is hereby granted,free of charge,to any person obtaining a copy of this software and associated documentation files (the "Software"),to deal in the Software without restriction,including without limitation the rights to use,copy,modify,merge,publish,distribute,sublicense,and/or sell copies of the Software,and to permit persons to whom the Software is furnished to do so,subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS",WITHOUT WARRANTY OF ANY KIND,EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,DAMAGES OR OTHER LIABILITY,WHETHER IN AN ACTION OF CONTRACT,TORT OR OTHERWISE,ARISING FROM,OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
#ifndef _CFBYTEORDER_H_
#define _CFBYTEORDER_H_

#import <libkern/OSByteOrder.h>
#import <CoreFoundation/CFBase.h>
#import <stdlib.h>
#import <StarboardExport.h>


COREFOUNDATION_EXTERNC_BEGIN

typedef enum {
    CFByteOrderUnknown,
    CFByteOrderLittleEndian,
    CFByteOrderBigEndian
} CFByteOrder;

typedef struct {
    uint32_t v;
} CFSwappedFloat32;

typedef struct {
    uint64_t v;
} CFSwappedFloat64;

SB_INLINE CFByteOrder CFByteOrderGetCurrent(void) {
    int32_t order = OSHostByteOrder();
    switch (order) {
    case OSLittleEndian:
        return CFByteOrderLittleEndian;
    case OSBigEndian:
        return CFByteOrderBigEndian;
    default:
        return CFByteOrderUnknown;
    }
}

SB_INLINE CFSwappedFloat64 CFConvertDoubleHostToSwapped(double value) {
    union {
        CFSwappedFloat64 w;
        double f;
    } swap;

    swap.f = value;
#ifdef __LITTLE_ENDIAN__
    swap.w.v = OSSwapInt64(swap.w.v);
#endif
    return swap.w;
}
SB_INLINE double CFConvertDoubleSwappedToHost(CFSwappedFloat64 value) {
    union {
        CFSwappedFloat64 w;
        double f;
    } swap;

    swap.w = value;
#ifdef __LITTLE_ENDIAN__
    swap.w.v = OSSwapInt64(swap.w.v);
#endif
    return swap.f;
}

SB_INLINE CFSwappedFloat32 CFConvertFloat32HostToSwapped(Float32 value) {
    union {
        CFSwappedFloat32 w;
        Float32 f;
    } swap;

    swap.f = value;
#ifdef __LITTLE_ENDIAN__
    swap.w.v = OSSwapInt32(swap.w.v);
#endif
    return swap.w;
}

SB_INLINE Float32 CFConvertFloat32SwappedToHost(CFSwappedFloat32 value) {
    union {
        CFSwappedFloat32 w;
        Float32 f;
    } swap;

    swap.w = value;
#ifdef __LITTLE_ENDIAN__
    swap.w.v = OSSwapInt32(swap.w.v);
#endif
    return swap.f;
}

SB_INLINE CFSwappedFloat64 CFConvertFloat64HostToSwapped(Float64 value) {
    union {
        CFSwappedFloat64 w;
        Float64 f;
    } swap;

    swap.f = value;
#ifdef __LITTLE_ENDIAN__
    swap.w.v = OSSwapInt64(swap.w.v);
#endif
    return swap.w;
}

SB_INLINE Float64 CFConvertFloat64SwappedToHost(CFSwappedFloat64 value) {
    union {
        CFSwappedFloat64 w;
        Float64 f;
    } swap;

    swap.w = value;
#ifdef __LITTLE_ENDIAN__
    swap.w.v = OSSwapInt64(swap.w.v);
#endif
    return swap.f;
}

SB_INLINE CFSwappedFloat32 CFConvertFloatHostToSwapped(float value) {
    union {
        CFSwappedFloat32 w;
        float f;
    } swap;

    swap.f = value;
#ifdef __LITTLE_ENDIAN__
    swap.w.v = OSSwapInt32(swap.w.v);
#endif
    return swap.w;
}

SB_INLINE float CFConvertFloatSwappedToHost(CFSwappedFloat32 value) {
    union {
        CFSwappedFloat32 w;
        float f;
    } swap;

    swap.w = value;
#ifdef __LITTLE_ENDIAN__
    swap.w.v = OSSwapInt32(swap.w.v);
#endif
    return swap.f;
}

SB_INLINE uint16_t CFSwapInt16(uint16_t value) {
    return OSSwapInt16(value);
}
SB_INLINE uint16_t CFSwapInt16BigToHost(uint16_t value) {
    return OSSwapBigToHostInt16(value);
}

SB_INLINE uint16_t CFSwapInt16HostToBig(uint16_t value) {
    return OSSwapHostToBigInt16(value);
}

SB_INLINE uint16_t CFSwapInt16HostToLittle(uint16_t value) {
    return OSSwapHostToLittleInt16(value);
}

SB_INLINE uint16_t CFSwapInt16LittleToHost(uint16_t value) {
    return OSSwapLittleToHostInt16(value);
}

SB_INLINE uint32_t CFSwapInt32(uint32_t value) {
    return OSSwapInt32(value);
}

SB_INLINE uint32_t CFSwapInt32BigToHost(uint32_t value) {
    return OSSwapBigToHostInt32(value);
}

SB_INLINE uint32_t CFSwapInt32HostToBig(uint32_t value) {
    return OSSwapHostToBigInt32(value);
}

SB_INLINE uint32_t CFSwapInt32HostToLittle(uint32_t value) {
    return OSSwapHostToLittleInt32(value);
}

SB_INLINE uint32_t CFSwapInt32LittleToHost(uint32_t value) {
    return OSSwapLittleToHostInt32(value);
}

SB_INLINE uint64_t CFSwapInt64(uint64_t value) {
    return OSSwapInt64(value);
}

SB_INLINE uint64_t CFSwapInt64BigToHost(uint64_t value) {
    return OSSwapBigToHostInt64(value);
}

SB_INLINE uint64_t CFSwapInt64HostToBig(uint64_t value) {
    return OSSwapHostToBigInt64(value);
}

SB_INLINE uint64_t CFSwapInt64HostToLittle(uint64_t value) {
    return OSSwapHostToLittleInt64(value);
}

SB_INLINE uint64_t CFSwapInt64LittleToHost(uint64_t value) {
    return OSSwapLittleToHostInt64(value);
}

COREFOUNDATION_EXTERNC_END

#endif // _CFBYTEORDER_H_