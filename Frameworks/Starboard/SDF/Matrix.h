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

#include <assert.h>

template <typename T>
class Matrix {
    T* data;
    size_t sizeX, sizeY;

public:
    explicit inline Matrix(T* data) : data(data), sizeX(0), sizeY(0) {
    }
    inline Matrix(T* data, size_t sizeX, size_t sizeY) : data(data), sizeX(sizeX), sizeY(sizeY) {
    }

    inline ~Matrix() {
    }

    static const size_t typeSize = sizeof(T);

    inline void reinit(T* newData, size_t x, size_t y) {
        data = newData;
        sizeX = x;
        sizeY = y;
    }

    inline void resize(size_t x, size_t y) {
        sizeX = x;
        sizeY = y;
    }

    inline void clear() {
        if (data)
            memset(data, 0, sizeof(T) * sizeX * sizeY);
    }

    inline size_t width() const {
        return sizeX;
    }
    inline size_t height() const {
        return sizeY;
    }

    const T& operator()(size_t x, size_t y) const {
        assert((x < sizeX) && (y < sizeY));
        return data[y * sizeX + x];
    }

    T& operator()(size_t x, size_t y) {
        assert((x < sizeX) && (y < sizeY));
        return data[y * sizeX + x];
    }

    const T* row(size_t r) const {
        return data + r * sizeX;
    }
    T* mem() {
        return data;
    }
    const T* mem() const {
        return data;
    }
};
