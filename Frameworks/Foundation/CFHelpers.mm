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

#include "CFHelpers.h"

const void* CFNSCopy(CFAllocatorRef allocator, const void* obj) {
    return [static_cast<id>(obj) copy];
}

const void* CFNSRetain(CFAllocatorRef allocator, const void* obj) {
    return [static_cast<id>(obj) retain];
}

void CFNSRelease(CFAllocatorRef allocator, const void* obj) {
    [static_cast<id>(obj) release];
}

Boolean CFNSEqual(const void* obj1, const void* obj2) {
    return [static_cast<id>(obj1) isEqual:static_cast<id>(obj2)];
}

CFHashCode CFNSHash(const void* obj1) {
    return [static_cast<id>(obj1) hash];
}

int CFNSComparer(id obj1, id obj2, void* context) {
    return [obj1 compare:obj2];
}

int CFNSDescriptorCompare(id obj1, id obj2, void* descriptors) {
    id idDescriptors = static_cast<id>(descriptors);
    int count = [idDescriptors count];

    for (int i = 0; i < count; i++) {
        id curDesc = [idDescriptors objectAtIndex:i];

        int result = [curDesc compareObject:obj1 toObject:obj2];
        if (result != 0) {
            return result;
        }
    }

    return 0;
}

int CFNSBlockCompare(id obj1, id obj2, void* block) {
    int (^blockFunc)(id, id) = (int (^)(id, id))block;
    int ret = (int)blockFunc(obj1, obj2);

    return ret;
}