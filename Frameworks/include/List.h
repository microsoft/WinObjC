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

template <typename Type>
class List {
    Type* _data;
    size_t _capacity, _count;

    void resize(size_t capacity) {
        Type* prevData = _data;
        _data = new Type[capacity];

        // assert(capacity >= _count);
        for (size_t i = 0; i < _count; ++i) {
            _data[i] = prevData[i];
        }

        _capacity = capacity;
        delete prevData;
    }

public:
    List() : _data(0), _capacity(0), _count(0) {
    }

    ~List() {
        delete[] _data;
    }

    void add(const Type& val) {
        if (_count + 1 >= _capacity) {
            resize(2 * _capacity + 7);
        }
        _data[_count++] = val;
    }

    Type& operator[](size_t pos) {
        return _data[pos];
    }
    const Type& operator[](size_t pos) const {
        return _data[pos];
    }

    void removeEnd() {
        --_count;
    }

    size_t len() const {
        return _count;
    }
};
