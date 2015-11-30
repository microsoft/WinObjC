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
#include <Foundation\Foundation.h>

void assertArrayContents(NSArray* array, NSObject* first, ...) {
    va_list args;
    va_start(args, first);

    id curVal = first;

    size_t i = 0;
    while (curVal != nil) {
        ASSERT_OBJCEQ(curVal, [array objectAtIndex:i++]);
        curVal = va_arg(args, id);
    }

    va_end(args);

    ASSERT_EQ(i, [array count]);
}

TEST(Foundation, NSArray_ArrayWithObjects) {
    // Empty list
    assertArrayContents([NSArray arrayWithObjects:nil], nil);

    // Single element
    assertArrayContents([NSArray arrayWithObjects:@1, nil], @1, nil);

    // Multiple elements
    assertArrayContents([NSArray arrayWithObjects:@1, @2, @3, nil], @1, @2, @3, nil);
}

TEST(Foundation, NSArray_InitWithObjects) {
    // Empty list
    assertArrayContents([[NSArray alloc] initWithObjects:nil], nil);

    // Single element
    assertArrayContents([[NSArray alloc] initWithObjects:@1, nil], @1, nil);

    // Multiple elements
    assertArrayContents([[NSArray alloc] initWithObjects:@1, @2, @3, nil], @1, @2, @3, nil);
}