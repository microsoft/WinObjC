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

template <typename T>
class Triplet {
    T _x, _y, _z;

public:
    inline Triplet() {
    }
    inline Triplet(T x, T y, T z) : _x(x), _y(y), _z(z) {
    }
    explicit inline Triplet(T val) : _x(val), _y(val), _z(val) {
    }
    inline ~Triplet() {
    }

    const T& x() const {
        return _x;
    }
    const T& y() const {
        return _y;
    }
    const T& z() const {
        return _z;
    }

    T& x() {
        return _x;
    }
    T& y() {
        return _y;
    }
    T& z() {
        return _z;
    }
};
