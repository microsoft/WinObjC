//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include "Starboard.h"
#include "StubReturn.h"

#import <Foundation/NSByteOrder.h>

/**
 @Status Stub
 @Notes
*/
NSSwappedDouble NSConvertHostDoubleToSwapped(double x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSSwappedFloat NSConvertHostFloatToSwapped(float x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
double NSConvertSwappedDoubleToHost(NSSwappedDouble x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
float NSConvertSwappedFloatToHost(NSSwappedFloat x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSByteOrder NSHostByteOrder() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
double NSSwapBigDoubleToHost(NSSwappedDouble x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
float NSSwapBigFloatToHost(NSSwappedFloat x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned int NSSwapBigIntToHost(unsigned int x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long long NSSwapBigLongLongToHost(unsigned long long x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long NSSwapBigLongToHost(unsigned long x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned short NSSwapBigShortToHost(unsigned short x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSSwappedDouble NSSwapDouble(NSSwappedDouble x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSSwappedFloat NSSwapFloat(NSSwappedFloat x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSSwappedDouble NSSwapHostDoubleToLittle(double x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSSwappedFloat NSSwapHostFloatToLittle(float x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
unsigned int NSSwapHostIntToBig(unsigned int val) {
    return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val & 0xFF0000) >> 8) | (val >> 24);
}

/**
 @Status Stub
 @Notes
*/
unsigned int NSSwapHostIntToLittle(unsigned int x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long long NSSwapHostLongLongToLittle(unsigned long long x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long NSSwapHostLongToBig(unsigned long x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long NSSwapHostLongToLittle(unsigned long x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned short NSSwapHostShortToLittle(unsigned short x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned int NSSwapInt(unsigned int inv) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
double NSSwapLittleDoubleToHost(NSSwappedDouble x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
float NSSwapLittleFloatToHost(NSSwappedFloat x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned int NSSwapLittleIntToHost(unsigned int x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long long NSSwapLittleLongLongToHost(unsigned long long x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long NSSwapLittleLongToHost(unsigned long x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned short NSSwapLittleShortToHost(unsigned short x) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long NSSwapLong(unsigned long inv) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned long long NSSwapLongLong(unsigned long long inv) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
unsigned short NSSwapShort(unsigned short inv) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
NSSwappedFloat NSSwapHostFloatToBig(float val) {
    DWORD ret = NSSwapHostIntToBig(*((DWORD*)&val));

    return *((NSSwappedFloat*)&ret);
}

/**
 @Status Interoperable
*/
NSSwappedDouble NSSwapHostDoubleToBig(double val) {
    unsigned __int64 ret = NSSwapHostLongLongToBig(*((unsigned __int64*)&val));

    return *((NSSwappedDouble*)&ret);
}

/**
 @Status Interoperable
*/
unsigned short NSSwapHostShortToBig(unsigned short val) {
    return ((val & 0xFF) << 8) | (val >> 8);
}

/**
 @Status Interoperable
*/
unsigned __int64 NSSwapHostLongLongToBig(unsigned __int64 val) {
    union {
        unsigned long long word;
        uint8_t bytes[8];
    } value, result;

    value.word = val;

    result.bytes[0] = value.bytes[7];
    result.bytes[1] = value.bytes[6];
    result.bytes[2] = value.bytes[5];
    result.bytes[3] = value.bytes[4];
    result.bytes[4] = value.bytes[3];
    result.bytes[5] = value.bytes[2];
    result.bytes[6] = value.bytes[1];
    result.bytes[7] = value.bytes[0];

    return result.word;
}