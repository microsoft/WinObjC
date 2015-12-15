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

#include "gtest-api.h"
#import <Foundation/Foundation.h>
#include <Foundation/CFBinaryHeap.h>
#include <string.h>

TEST(Foundation, CFBinaryHeap_BasicCreation) {
    const CFIndex heapSize = 5;
    CFBinaryHeapRef heap = CFBinaryHeapCreate(NULL, heapSize, NULL, NULL);
    ASSERT_TRUE_MSG(heap != NULL, "FAILED: [CFBinaryHeapCreate] heap should be non-null!");
    ASSERT_EQ_MSG(CFBinaryHeapGetCount(heap), 0, "FAILED: [CFBinaryHeapGetCount] should be 0!");
    int heapArray[heapSize] = { 3, 5, 8, 10, 3 };

    // add values to the heap.
    for (int i = 0; i < heapSize; ++i) {
        CFBinaryHeapAddValue(heap, (const void*)heapArray[i]);
    }

    ASSERT_EQ_MSG(heapSize, CFBinaryHeapGetCount(heap), "FAILED: [CFBinaryHeapGetCount] should be %d.", heapSize);

    ASSERT_TRUE_MSG(CFBinaryHeapContainsValue(heap, (const void*)heapArray[0]),
                    "FAILED: [CFBinaryHeapContainsValue] should contain the value %d.",
                    heapArray[0]);

    ASSERT_EQ_MSG(2, CFBinaryHeapGetCountOfValue(heap, (const void*)heapArray[0]), "FAILED: [CFBinaryHeapGetCountOfValue] should be 2");

    ASSERT_EQ_MSG(3, (int)CFBinaryHeapGetMinimum(heap), "FAILED: [CFBinaryHeapGetMinimum] should be 3");

    CFBinaryHeapRemoveMinimumValue(heap);

    ASSERT_EQ_MSG(3, (int)CFBinaryHeapGetMinimum(heap), "FAILED: [CFBinaryHeapGetMinimum] should be 3");

    CFBinaryHeapRemoveMinimumValue(heap);
    ASSERT_EQ_MSG(5, (int)CFBinaryHeapGetMinimum(heap), "FAILED: [CFBinaryHeapGetMinimum] should be 5");

    ASSERT_EQ_MSG((heapSize - 2), CFBinaryHeapGetCount(heap), "FAILED: [CFBinaryHeapGetCount] should be %d.", (heapSize - 2));

    CFBinaryHeapRemoveAllValues(heap);
    ASSERT_EQ_MSG(0, CFBinaryHeapGetCount(heap), "FAILED: [CFBinaryHeapGetCount] should be 0.");

    CFRelease(heap);
}

CFComparisonResult compare(const void* value, const void* other, void* context) {
    if ((int)value == (int)other) {
        return kCFCompareEqualTo;
    } else if ((int)value < (int)other) {
        return kCFCompareLessThan;
    }

    return kCFCompareGreaterThan;
};

CFBinaryHeapCallBacks defaultCallbacks = { 0, NULL, NULL, NULL, compare };

TEST(Foundation, CFBinaryHeap_CreationWithCustomFunctions) {
    const CFIndex heapSize = 10;
    int heapArray[10] = { 3, 5, 8, 10, 3, -4, 13, 44, 1, -3 };

    CFBinaryHeapRef heap = CFBinaryHeapCreate(kCFAllocatorDefault, 0 /*ever growing heap*/, &defaultCallbacks, NULL);
    ASSERT_TRUE_MSG(heap != NULL, "FAILED: [CFBinaryHeapCreate] heap should be non-null!");
    ASSERT_EQ_MSG(0, CFBinaryHeapGetCount(heap), "FAILED: [CFBinaryHeapGetCount] should be 0!");

    for (int i = 0; i < heapSize; ++i) {
        CFBinaryHeapAddValue(heap, (const void*)heapArray[i]);
    }

    ASSERT_EQ_MSG(heapSize, CFBinaryHeapGetCount(heap), "FAILED: [CFBinaryHeapGetCount] should be %d.", heapSize);

    ASSERT_TRUE_MSG(CFBinaryHeapContainsValue(heap, (const void*)heapArray[0]),
                    "FAILED: [CFBinaryHeapContainsValue] should contain the value %d.",
                    heapArray[0]);

    ASSERT_EQ_MSG(2, CFBinaryHeapGetCountOfValue(heap, (const void*)heapArray[0]), "FAILED: [CFBinaryHeapGetCountOfValue] should be 2");

    ASSERT_EQ_MSG(-4, (int)CFBinaryHeapGetMinimum(heap), "FAILED: [CFBinaryHeapGetMinimum] should be -4");

    CFBinaryHeapRemoveMinimumValue(heap);

    ASSERT_EQ_MSG(-3, (int)CFBinaryHeapGetMinimum(heap), "FAILED: [CFBinaryHeapGetMinimum] should be -3");

    CFBinaryHeapRemoveMinimumValue(heap);
    ASSERT_EQ_MSG(1, (int)CFBinaryHeapGetMinimum(heap), "FAILED: [CFBinaryHeapGetMinimum] should be 1");

    ASSERT_EQ_MSG((heapSize - 2), CFBinaryHeapGetCount(heap), "FAILED: [CFBinaryHeapGetCount] should be %d.", (heapSize - 2));

    CFBinaryHeapRemoveAllValues(heap);
    ASSERT_EQ_MSG(0, CFBinaryHeapGetCount(heap), "FAILED: [CFBinaryHeapGetCount] should be 0.");

    CFRelease(heap);
}
