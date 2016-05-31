//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include <Foundation/Foundation.h>
#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc-arc.h>

const void* _NSCFCallbackCopy(CFAllocatorRef allocator, const void* value) {
    return (void*)[(id)value copy];
}

const void* _NSCFCallbackRetain(CFAllocatorRef allocator, const void* value) {
    return objc_retain((id)value);
}

void _NSCFCallbackRelease(CFAllocatorRef allocator, const void* value) {
    objc_release((id)value);
}

CFStringRef _NSCFCallbackCopyDescription(const void* value) {
    return (__bridge CFStringRef)[[(id)value description] copy];
}

Boolean _NSCFCallbackEquals(const void* value1, const void* value2) {
    return [(id)value1 isEqual:(id)value2];
}

CFHashCode _NSCFCallbackHash(const void* value) {
    return (CFHashCode)[(id)value hash];
}

