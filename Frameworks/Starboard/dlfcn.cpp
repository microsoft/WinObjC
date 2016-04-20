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

#include <dlfcn.h>
#include <windows.h>
#include <memory>
#include <string>
#include <string.h>

/**
@Status Caveat
@Notes This function can only find libraries in the root of the current
       package. The mode parameter is ignored. In addition, error information
       is not available on failure.
*/
void* dlopen(const char* path, int mode) {
    try {
        // We can only load libraries from within our own package or any dependent
        // packages, so absolute paths are not much use to us. From whatever path
        // we're given, just strip off everything but the leaf file name and try
        // to load that. This isn't always correct, but it is sometimes correct.

        std::wstring widePath(path, path + strlen(path));

        DWORD pathLength = GetFullPathNameW(widePath.c_str(), 0, nullptr, nullptr);
        auto fullPath = std::make_unique<WCHAR[]>(pathLength);
        LPWSTR fileName = nullptr;

        GetFullPathNameW(widePath.c_str(), pathLength, fullPath.get(), &fileName);

        return LoadPackagedLibrary(fileName, 0);
    } catch (...) {
    }

    return NULL;
}

/**
@Status Caveat
@Notes Error information is not available on failure
*/

void* dlsym(void* handle, const char* symbol) {
    HMODULE module = static_cast<HMODULE>(handle);

    return GetProcAddress(module, symbol);
}

/**
@Status Caveat
@Notes Error information is not available on failure
*/
int dlclose(void* handle) {
    HMODULE module = static_cast<HMODULE>(handle);

    return !FreeLibrary(module);
}
