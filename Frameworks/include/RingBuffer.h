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

template <typename Type, int sz>
class RingBuffer {
    enum { arraySize = sz + 1 };

    Type data[arraySize];
    size_t low, high;

public:
    RingBuffer() : low(0), high(0) {
    }

    void add(const Type& val) {
        data[high] = val;
        high = (high + 1) % arraySize;

        // Even when full we keep a single element empty to differentiate between an empty
        // buffer and a full buffer.
        if (high == low) {
            low = (low + 1) % arraySize;
        }
    }

    size_t size() const {
        if (high < low)
            return arraySize - (low - high);
        return high - low;
    }

    Type at(size_t index) const {
        assert(index < size());
        index = (index + low) % arraySize;
        return data[index];
    }

    Type fromEnd(size_t index) const {
        assert(size() > index);
        return at(size() - index - 1);
    }

    Type operator[](size_t index) const {
        return at(index);
    }

    void reset() {
        low = high = 0;
    }
};
