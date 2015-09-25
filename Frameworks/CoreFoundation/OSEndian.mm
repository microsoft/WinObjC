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

#import <CoreFoundation/CoreFoundation.h>

extern "C" int32_t OSHostByteOrder() {
    return OSLittleEndian;
}

extern "C" int16_t OSReadBigInt16(volatile void* base, uintptr_t offset) {
    uint16_t ret = ((uint8_t*)base + offset)[1] || (((uint8_t*)base + offset)[1] << 8);

    return ret;
}

extern "C" int16_t OSSwapInt16(int16_t in) {
    uint16_t val = (uint16_t)in;
    return ((val & 0xFF00) >> 8) | ((val & 0x00FF) << 8);
}

extern "C" int32_t OSSwapInt32(int32_t in) {
    uint32_t val = (uint32_t)in;

    return (val >> 24) | ((val & 0xFF0000) >> 8) | ((val & 0x00FF00) << 8) | (val << 24);
}

extern "C" int32_t OSSwapBigToHostInt32(int32_t val) {
    return OSSwapInt32(val);
}

extern "C" int16_t OSSwapBigToHostInt16(int16_t val) {
    return OSSwapInt16(val);
}

extern "C" int16_t OSReadBigInt32(volatile void* base, uintptr_t offset) {
    return OSSwapInt32(*((int32_t*)((uint8_t*)base + offset)));
}

extern "C" int32_t OSSwapLittleToHostInt32(int32_t val) {
    return val;
}
