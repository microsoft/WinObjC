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

#include <Starboard.h>
#include <Starboard/String.h>

#include <cstdarg>
#include <string>

std::string woc::string::format[[gnu::format(printf, 1, 2)]](const char* format, ...) {
    va_list arguments, arguments2;
    va_start(arguments, format);
    // Compiler Issue: va_copy is emitted as __vacopy, and is an undefined external.
    // stdarg.h specifies va_copy as ((dest)=(src)). As such, we inline it here.
    // va_copy(arguments2, arguments);
    arguments2 = arguments;
    size_t size = _vscprintf(format, arguments);
    va_end(arguments);
    std::string ret(size + 1, '\0');
    _vsnprintf(&ret[0], size, format, arguments2);
    va_end(arguments2);
    return ret;
}
