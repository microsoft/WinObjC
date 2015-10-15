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

#include <algorithm>
#include "HashFn.h"
#include "Str.h"

#include <algorithm>

template <typename T>
struct HashSet1 {
    size_t operator()(const T& key) const {
        return murmurHash3(&key, sizeof(key), 0x9747b28c);
    }
};

template <>
struct HashSet1<Str> {
    size_t operator()(const Str& key) const {
        return murmurHash3(key.cstr(), key.len(), 0x9747b28c);
    }
};

template <typename T>
struct HashSet2 {
    size_t operator()(const T& key) const {
        return murmurHash3(&key, sizeof(key), 0x460d5f6d);
    }
};

template <>
struct HashSet2<Str> {
    size_t operator()(const Str& key) const {
        return murmurHash3(key.cstr(), key.len(), 0x460d5f6d);
    }
};

template <typename KeyType, typename ValueType, size_t maxHop = 30, typename Hash1 = HashSet1<KeyType>, typename Hash2 = HashSet2<KeyType>>
class HashMap {
    struct Bucket {
        Bucket() : used(false) {
        }

        KeyType key;
        ValueType val;

        bool used;
    } * _buckets;
    size_t _size;

    Hash1 _hash1;
    Hash2 _hash2;

    static const size_t kResizeMult = 2, kResizeOffset = 7;
    void rehash() {
        Bucket* orig = _buckets;
        size_t origSize = _size;

        _size = _size * kResizeMult + kResizeOffset;
        _buckets = new Bucket[_size];

        for (size_t i = 0; i < origSize; ++i) {
            if (orig[i].used) {
                insert(orig[i].key, orig[i].val);
            }
        }

        delete[] orig;
    }

public:
    HashMap(size_t startSize = 0) : _buckets(0), _size(0) {
    }

    ~HashMap() {
        delete[] _buckets;
    }

    bool exists(const KeyType& key) const {
        if (_size == 0)
            return false;

        size_t h1 = _hash1(key) % _size;
        size_t h2 = _hash2(key) % _size;

        return (_buckets[h1].used && _buckets[h1].key == key) || (_buckets[h2].used && _buckets[h2].key == key);
    }

    ValueType* insert(KeyType key, ValueType val) {
        if (_size == 0)
            rehash();

        size_t h1 = _hash1(key) % _size;
        if (_buckets[h1].used && _buckets[h1].key == key) {
            _buckets[h1].val = val;
            return &_buckets[h1].val;
        }
        size_t h2 = _hash2(key) % _size;
        if (_buckets[h2].used && _buckets[h2].key == key) {
            _buckets[h2].val = val;
            return &_buckets[h2].val;
        }

        size_t curr = _hash1(key) % _size;

        // We need to keep track of this because we may kick something out and recursively try
        // to add it again - the caller is only interested in the thing it tried to add though.
        Bucket* retBucket = &_buckets[curr];
        KeyType insertKey = key;

        for (size_t i = 0; i < maxHop; ++i) {
            if (key == insertKey) {
                retBucket = &_buckets[curr];
            }

            if (!_buckets[curr].used) {
                _buckets[curr].used = true;
                _buckets[curr].key = key;
                _buckets[curr].val = val;
                return &retBucket->val;
            }

            std::swap(key, _buckets[curr].key);
            std::swap(val, _buckets[curr].val);

            if (curr == _hash1(key) % _size)
                curr = _hash2(key) % _size;
            else
                curr = _hash1(key) % _size;
        }

        rehash();
        insert(key, val);
        return get(insertKey);
    }

    bool get(const KeyType& key, ValueType*& val) {
        if (_size == 0)
            return false;

        size_t h1 = _hash1(key) % _size;
        if (_buckets[h1].used && _buckets[h1].key == key) {
            val = &_buckets[h1].val;
            return true;
        }

        size_t h2 = _hash2(key) % _size;
        if (_buckets[h2].used && _buckets[h2].key == key) {
            val = &_buckets[h2].val;
            return true;
        }

        return false;
    }

    ValueType* get(const KeyType& key) {
        ValueType* val = NULL;
        get(key, val);
        return val;
    }

    ValueType* operator[](const KeyType& key) {
        ValueType* val = NULL;
        get(key, val);
        return val;
    }

    void remove(KeyType key) {
        if (_size != 0) {
            size_t h1 = _hash1(key) % _size;
            if (_buckets[h1].used && _buckets[h1].key == key) {
                _buckets[h1].used = false;
                return;
            }
            size_t h2 = _hash2(key) % _size;
            if (_buckets[h2].used && _buckets[h2].key == key) {
                _buckets[h2].used = false;
            }
        }
    }

    void clear() {
        delete[] _buckets;
        _buckets = 0;
        _size = 0;
    }

    bool nextHandle(size_t& ret, size_t handle = -1) {
        ret = handle + 1;
        while (ret < _size && !_buckets[ret].used)
            ++ret;
        return ret != _size;
    }

    ValueType& valueAtHandle(size_t handle) {
        return _buckets[handle].val;
    }
    KeyType keyAtHandle(size_t handle) {
        return _buckets[handle].key;
    }
};

template <typename KeyType>
class HashSet {
    struct None {};

    HashMap<KeyType, None> _map;

public:
    bool exists(const KeyType& key) {
        return _map.exists(key);
    }
    void insert(const KeyType& key) {
        _map.insert(key, None());
    }
    void remove(const KeyType& key) {
        _map.remove(key);
    }
    void clear() {
        _map.clear();
    }
};
