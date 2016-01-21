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
#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFBinaryHeap.h>
#include <string.h>

TEST(CFBinaryHeap, BasicCreation) {
    const CFIndex heapSize = 5;
    CFBinaryHeapRef heap = CFBinaryHeapCreate(NULL, heapSize, NULL, NULL);
    ASSERT_TRUE(heap != NULL);
    ASSERT_EQ(CFBinaryHeapGetCount(heap), 0);
    int heapArray[heapSize] = { 3, 5, 8, 10, 3 };

    // add values to the heap.
    for (int i = 0; i < heapSize; ++i) {
        CFBinaryHeapAddValue(heap, (const void*)heapArray[i]);
    }

    ASSERT_EQ(heapSize, CFBinaryHeapGetCount(heap));

    ASSERT_TRUE(CFBinaryHeapContainsValue(heap, (const void*)heapArray[0]));

    ASSERT_EQ(2, CFBinaryHeapGetCountOfValue(heap, (const void*)heapArray[0]));

    ASSERT_EQ(3, (int)CFBinaryHeapGetMinimum(heap));

    CFBinaryHeapRemoveMinimumValue(heap);

    ASSERT_EQ(3, (int)CFBinaryHeapGetMinimum(heap));

    CFBinaryHeapRemoveMinimumValue(heap);
    ASSERT_EQ(5, (int)CFBinaryHeapGetMinimum(heap));

    ASSERT_EQ((heapSize - 2), CFBinaryHeapGetCount(heap));

    CFBinaryHeapRemoveAllValues(heap);
    ASSERT_EQ(0, CFBinaryHeapGetCount(heap));

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

TEST(CFBinaryHeap, CreationWithCustomFunctions) {
    const CFIndex heapSize = 10;
    int heapArray[10] = { 3, 5, 8, 10, 3, -4, 13, 44, 1, -3 };

    CFBinaryHeapRef heap = CFBinaryHeapCreate(kCFAllocatorDefault, 0 /*ever growing heap*/, &defaultCallbacks, NULL);
    ASSERT_TRUE(heap != NULL);
    ASSERT_EQ(0, CFBinaryHeapGetCount(heap));

    for (int i = 0; i < heapSize; ++i) {
        CFBinaryHeapAddValue(heap, (const void*)heapArray[i]);
    }

    ASSERT_EQ(heapSize, CFBinaryHeapGetCount(heap));

    ASSERT_TRUE(CFBinaryHeapContainsValue(heap, (const void*)heapArray[0]));

    ASSERT_EQ(2, CFBinaryHeapGetCountOfValue(heap, (const void*)heapArray[0]));

    ASSERT_EQ(-4, (int)CFBinaryHeapGetMinimum(heap));

    CFBinaryHeapRemoveMinimumValue(heap);

    ASSERT_EQ(-3, (int)CFBinaryHeapGetMinimum(heap));

    CFBinaryHeapRemoveMinimumValue(heap);
    ASSERT_EQ(1, (int)CFBinaryHeapGetMinimum(heap));

    ASSERT_EQ((heapSize - 2), CFBinaryHeapGetCount(heap));

    CFBinaryHeapRemoveAllValues(heap);
    ASSERT_EQ(0, CFBinaryHeapGetCount(heap));

    CFRelease(heap);
}
