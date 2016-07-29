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

#ifndef __IWMALLOC_H
#define __IWMALLOC_H

#include <string.h>
#include <WinObjCRTExport.h>

// These allocation functions are intended to match the malloc/free used by
// client code in the application. Framework code must use these allocators
// when freeing buffers allocated by the client or allocating buffers to be
// freed by the client.

WINOBJCRT_EXPORT void* IwMalloc(size_t size);
WINOBJCRT_EXPORT void* IwRealloc(void* ptr, size_t size);
WINOBJCRT_EXPORT void IwFree(void* ptr);
WINOBJCRT_EXPORT void* IwCalloc(size_t num, size_t size);

inline char* IwStrDup(const char* str) {
    size_t len = strlen(str);
    char* buffer = (char*)IwMalloc(len + 1);

    if (buffer != NULL) {
// strcpy_s is a MSVC extension,
// strncpy is not usable in our current WinObjC build
#ifdef _WIN32
        strcpy_s(buffer, len + 1, str);
#else
        strncpy(buffer, str, len + 1);
#endif
    }

    return buffer;
}

#endif // __IWMALLOC_H
