//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

static constexpr size_t sc_indentSpaces = 4;

#include <Foundation/NSEnumerator.h>

@class NSArray;
@class NSString;

typedef void (*initIteratorFunc)(id obj, void* enumeratorHolder);
typedef int (*nextValueFunc)(id obj, void* enumeratorHolder, id* ret, int count);

@interface NSEnumerator (Internal) {
}

+ (NSEnumerator*)enumeratorWithArray:(NSArray*)array;
+ (NSEnumerator*)enumeratorWithArrayReverse:(NSArray*)array;
+ (NSEnumerator*)enumeratorWithIterator:(initIteratorFunc)initIterator forObject:(id)obj nextFunction:(nextValueFunc)nextValueFunction;

@end

// Helper function for foundation collections which returns the description for value
NSString* _descriptionForCollectionElement(id value, id locale, NSUInteger indent);

__inline void _enumerateWithBlock(id<NSFastEnumeration> enumerator, NSEnumerationOptions options, void (^block)(id, BOOL*)) {
    dispatch_queue_t queue;
    dispatch_group_t group;

    // Initialize dispatch queue for concurrent enumeration
    if (options & NSEnumerationConcurrent) {
        queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
        group = dispatch_group_create();
    }

    __block BOOL stop = FALSE;
    for (id key in enumerator) {
        if (options & NSEnumerationConcurrent) {
            dispatch_group_async(group, queue, ^() {
                block(key, &stop);
            });
        } else {
            block(key, &stop);
        }

        if (stop) {
            break;
        }
    }

    if (options & NSEnumerationConcurrent) {
        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    }
}
