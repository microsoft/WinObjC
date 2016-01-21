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

#include <Starboard.h>
#include <CoreFoundation/CoreFoundation.h>

const void* CFNSCopy(CFAllocatorRef allocator, const void* obj);

const void* CFNSRetain(CFAllocatorRef allocator, const void* obj);

void CFNSRelease(CFAllocatorRef allocator, const void* obj);

Boolean CFNSEqual(const void* obj1, const void* obj2);

CFHashCode CFNSHash(const void* obj1);

int CFNSComparer(id obj1, id obj2, void* context);

int CFNSDescriptorCompare(id obj1, id obj2, void* descriptors);

int CFNSBlockCompare(id obj1, id obj2, void* block);