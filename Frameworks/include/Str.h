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

#include <string.h>
#include "Types.h"

class Str {
    char* _contents;
    size_t _len;

    void copy(const char* str) {
        size_t len = 1;
        const char* lenPos = str;
        while (*lenPos) {
            ++lenPos;
            ++len;
        }

        _contents = new char[len];
        for (size_t i = 0; i < len; ++i) {
            _contents[i] = str[i];
        }

        // don't include null term:
        _len = len - 1;
    }

public:
    Str() : _contents(0), _len(0) {
    }
    Str(const char* other) {
        copy(other);
    }
    Str(const Str& other) {
        copy(other._contents);
    }
    Str(const char* other, size_t len) {
        _len = len;
        _contents = new char[len + 1];
        memcpy(_contents, other, len);
        _contents[len] = '\0';
    }

    ~Str() {
        delete[] _contents;
    }

    Str& operator=(const Str& other) {
        delete[] _contents;
        copy(other._contents);
        return *this;
    }

    bool operator==(const Str& other) const {
        if (_len != other._len)
            return false;
        for (size_t i = 0; i < _len; ++i) {
            if (_contents[i] != other._contents[i])
                return false;
        }
        return true;
    }

    const char* cstr() const {
        return _contents;
    }

    size_t len() const {
        return _len;
    }
};