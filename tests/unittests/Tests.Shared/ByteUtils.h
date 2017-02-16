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

#include <windows.h>
#include <string>
#include <TestFramework.h>

static inline std::string stringFromBytes(BYTE* buf, size_t len) {
    static const BYTE lookup[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    std::string ret;
    ret.reserve(2 * (len + 1) + len / 2);

    for (int i = 0, count = 0; i < len; i++, count++) {
        ret.push_back(lookup[buf[i] >> 4]);
        ret.push_back(lookup[buf[i] & 0xf]);
        if (count == 1) {
            count = -1;
            ret.push_back(' ');
        }
    }

    return ret;
}

inline bool equalsBytes(BYTE* buf1, BYTE* buf2, size_t len) {
    return memcmp(buf1, buf2, len) == 0;
}

inline void logBytes(const char* str, BYTE* buf, size_t len) {
    std::string strBuf = stringFromBytes(buf, len);
    LOG_INFO("Bytes value for %s is\n%s", str, strBuf.c_str());
}