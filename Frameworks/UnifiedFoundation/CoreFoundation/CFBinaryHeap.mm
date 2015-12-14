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

#import <Starboard.h>
#import <Foundation/CFBinaryHeap.h>
#import <CFBridgeBase.h>
#include <algorithm>
#include <vector>
#include <functional>

const void* CFNSRetain(CFAllocatorRef allocator, const void* obj);
void CFNSRelease(CFAllocatorRef allocator, const void* obj);
Boolean CFNSEqual(const void* obj1, const void* obj2);

CFComparisonResult defaultCompare(const void* value, const void* other, void* context) {
    if (value == other) {
        return kCFCompareEqualTo;
    } else if (value > other) {
        return kCFCompareGreaterThan;
    }

    return kCFCompareLessThan;
};

const CFBinaryHeapCallBacks kCFStringBinaryHeapCallBacks = {
    0, CFNSRetain, CFNSRelease, CFCopyDescription, defaultCompare,
};

struct __CFBinaryHeap : public CFBridgeBase<__CFBinaryHeap> {
    CFIndex _capacity;
    CFAllocatorRef _allocator;
    CFBinaryHeapCallBacks _callbacks;
    CFBinaryHeapCompareContext _compareContext;
    std::vector<const void*> _container;

    std::function<bool(const void*, const void*)> _compare = [this](const void* value, const void* other) {
        if (_callbacks.compare) {
            return (kCFCompareGreaterThan == _callbacks.compare(value, other, _compareContext.info));
        }
        return (value > other);
    };

    __CFBinaryHeap(CFAllocatorRef allocatorRef, CFIndex cap, const CFBinaryHeapCallBacks* callbcks, const CFBinaryHeapCompareContext* ctx)
        : _capacity(cap), _allocator(allocatorRef) {
        if (callbcks) {
            _callbacks = *callbcks;
        }
        if (ctx) {
            _compareContext = *ctx;
        }
        std::make_heap(_container.begin(), _container.end(), _compare);
    }

    __CFBinaryHeap(CFAllocatorRef allocator, CFIndex capacity, const __CFBinaryHeap& other) : _allocator(allocator), _capacity(capacity) {
        this->_callbacks = other._callbacks;
        this->_compareContext = other._compareContext;

        // copy insert the values from the initial heap into this one.
        for (auto value : other._container) {
            this->CFBinaryHeapAddValue(value);
        }
    }

    void CFBinaryHeapAddValue(const void* value) {
        if ((_capacity != 0) && (_container.size() == _capacity)) {
            return;
        }

        if (_callbacks.retain) {
            _callbacks.retain(_allocator, value);
        }

        _container.push_back(value);
        std::push_heap(_container.begin(), _container.end(), _compare);
    }

    void CFBinaryHeapApplyFunction(CFBinaryHeapApplierFunction function, void* context) {
        std::for_each(_container.begin(), _container.end(), [function, context](const void* value) { function(value, context); });
    }

    Boolean CFBinaryHeapContainsValue(const void* value) {
        auto result = std::find_if(_container.begin(),
                                   _container.end(),
                                   [this, value](const void* other) {
                                       if (_callbacks.compare) {
                                           return (kCFCompareEqualTo == _callbacks.compare(value, other, _compareContext.info));
                                       }
                                       return (value == other);
                                   });
        return (result != _container.end());
    }

    CFIndex CFBinaryHeapGetCountOfValue(const void* value) {
        return (CFIndex)std::count_if(_container.begin(),
                                      _container.end(),
                                      [this, value](const void* other) {
                                          if (_callbacks.compare) {
                                              return (kCFCompareEqualTo == _callbacks.compare(value, other, _compareContext.info));
                                          }
                                          return (value == other);
                                      });
    }

    CFIndex CFBinaryHeapGetCount() {
        return (CFIndex)_container.size();
    }

    const void* CFBinaryHeapGetMinimum() {
        return _container.empty() ? NULL : _container.front();
    }

    Boolean CFBinaryHeapGetMinimumIfPresent(const void** value) {
        if ((_container.empty()) || (value == nullptr)) {
            return false;
        }

        *value = _container.front();
        return true;
    }

    void CFBinaryHeapRemoveAllValues() {
        std::for_each(_container.begin(),
                      _container.end(),
                      [this](const void* value) {
                          if (_callbacks.release) {
                              _callbacks.release(_allocator, value);
                          }
                      });
        _container.clear();
    }

    void CFBinaryHeapRemoveMinimumValue() {
        if (_container.empty()) {
            return;
        }

        const void* ref = _container.front();
        if (_callbacks.release) {
            _callbacks.release(_allocator, ref);
        }

        std::pop_heap(_container.begin(), _container.end(), _compare);
        _container.pop_back();
    }
    ~__CFBinaryHeap() {
        std::for_each(_container.begin(),
                      _container.end(),
                      [this](const void* value) {
                          if (_callbacks.release) {
                              _callbacks.release(_allocator, value);
                          }
                      });
    }
};

void CFBinaryHeapAddValue(CFBinaryHeapRef heap, const void* value) {
    if (heap == nullptr) {
        return;
    }
    heap->CFBinaryHeapAddValue(value);
}

void CFBinaryHeapApplyFunction(CFBinaryHeapRef heap, CFBinaryHeapApplierFunction function, void* context) {
    if (heap == nullptr) {
        return;
    }
    heap->CFBinaryHeapApplyFunction(function, context);
}

Boolean CFBinaryHeapContainsValue(CFBinaryHeapRef heap, const void* value) {
    if (heap == nullptr) {
        return false;
    }
    return heap->CFBinaryHeapContainsValue(value);
}

CFBinaryHeapRef CFBinaryHeapCreate(CFAllocatorRef allocator,
                                   CFIndex capacity,
                                   const CFBinaryHeapCallBacks* callbacks,
                                   const CFBinaryHeapCompareContext* context) {
    if (capacity < 0) {
        return nullptr;
    }

    CFBinaryHeapRef heapRef = CFBridgeBase<__CFBinaryHeap>::alloc(nil, allocator, capacity, callbacks, context);
    return heapRef;
}

CFBinaryHeapRef CFBinaryHeapCreateCopy(CFAllocatorRef allocator, CFIndex capacity, CFBinaryHeapRef heap) {
    if (((capacity > 0) && (capacity < heap->CFBinaryHeapGetCount())) || (capacity < 0)) {
        return nullptr;
    }

    CFBinaryHeapRef heapRef = CFBridgeBase<__CFBinaryHeap>::alloc(nil, allocator, capacity, *heap);
    return heapRef;
}

CFIndex CFBinaryHeapGetCount(CFBinaryHeapRef heap) {
    if (heap == nullptr) {
        return 0;
    }
    return heap->CFBinaryHeapGetCount();
}

CFIndex CFBinaryHeapGetCountOfValue(CFBinaryHeapRef heap, const void* value) {
    if (heap == nullptr) {
        return 0;
    }
    return heap->CFBinaryHeapGetCountOfValue(value);
}

const void* CFBinaryHeapGetMinimum(CFBinaryHeapRef heap) {
    if (heap == nullptr) {
        return nullptr;
    }
    return heap->CFBinaryHeapGetMinimum();
}

Boolean CFBinaryHeapGetMinimumIfPresent(CFBinaryHeapRef heap, const void** value) {
    if (heap == nullptr) {
        return false;
    }
    return heap->CFBinaryHeapGetMinimumIfPresent(value);
}

void CFBinaryHeapGetValues(CFBinaryHeapRef heap, const void** values) {
    if ((heap == nullptr) || (values == nullptr)) {
        return;
    }

    CFBinaryHeapRef copyHeap = CFBinaryHeapCreateCopy(nullptr, 0, heap);
    if (copyHeap != nullptr) {
        for (int i = 0; i < copyHeap->CFBinaryHeapGetCount(); ++i) {
            values[i] = copyHeap->CFBinaryHeapGetMinimum();
            copyHeap->CFBinaryHeapRemoveMinimumValue();
        }
    }

    CFRelease(copyHeap);
}

void CFBinaryHeapRemoveAllValues(CFBinaryHeapRef heap) {
    if (heap == nullptr) {
        return;
    }
    heap->CFBinaryHeapRemoveAllValues();
}

void CFBinaryHeapRemoveMinimumValue(CFBinaryHeapRef heap) {
    if (heap == nullptr) {
        return;
    }
    heap->CFBinaryHeapRemoveMinimumValue();
}
