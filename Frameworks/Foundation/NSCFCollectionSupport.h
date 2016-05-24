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

#pragma once

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFString.h>
#include <Foundation/NSObjCRuntime.h>

const void* _NSCFCallbackCopy(CFAllocatorRef allocator, const void* value);
const void* _NSCFCallbackRetain(CFAllocatorRef allocator, const void* value);
void _NSCFCallbackRelease(CFAllocatorRef allocator, const void* value);
CFStringRef _NSCFCallbackCopyDescription(const void* value);
Boolean _NSCFCallbackEquals(const void* value1, const void* value2);
CFHashCode _NSCFCallbackHash(const void* value);