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

#include_next <stdio.h>

#undef min
#undef max

#include <strings.h>

#ifndef vsnprintf
#include <stdarg.h>

__if_not_exists(vsnprintf) {
    __forceinline int vsnprintf(char *buf, size_t count, const char *fmt, va_list list)
    {
        return _vsnprintf(buf, count, fmt, list);
    }
}
#endif

#ifndef snprintf
#include <stdarg.h>

__if_not_exists(snprintf) {
    __forceinline int snprintf(char *buf, size_t count, const char *fmt, ...)
    {
        int rc;
        va_list list;
        va_start(list, fmt);
        rc = vsnprintf(buf, count, fmt, list);
        va_end(list);
        
        return rc;
    }
}
#endif
