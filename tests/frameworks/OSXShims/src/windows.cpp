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

#import <windows.h>

#import <libkern/OSAtomic.h>
#import <mach-o/dyld.h>

#import <cstdlib>
#import <string.h>
#import <unistd.h>

long InterlockedExchange(long volatile* Target, long Value) {
    bool success = false;
    long oldValue;

    while (!success) {
        oldValue = *Target;
        success = OSAtomicCompareAndSwap32(static_cast<int32_t>(oldValue),
                                           static_cast<int32_t>(Value),
                                           reinterpret_cast<int32_t volatile*>(Target));
    }

    return oldValue;
}

long _InterlockedExchange(long volatile* Target, long Value) {
    return InterlockedExchange(Target, Value);
}

long InterlockedIncrement(long volatile* Addend) {
    return OSAtomicIncrement32(reinterpret_cast<int32_t volatile*>(Addend));
}

long InterlockedDecrement(long volatile* Addend) {
    return OSAtomicDecrement32(reinterpret_cast<int32_t volatile*>(Addend));
}

void Sleep(DWORD dwMilliseconds) {
    sleep(dwMilliseconds);
}

DWORD GetModuleFileNameA(void* hModule, char* lpFilename, DWORD nSize) {
    return _NSGetExecutablePath(lpFilename, &nSize);
}

DWORD GetModuleFileNameW(void* hModule, wchar_t* lpFilename, DWORD nSize) {
    char tempBuffer[nSize];
    _NSGetExecutablePath(tempBuffer, &nSize);
    return mbstowcs(lpFilename, tempBuffer, nSize);
}

bool SetCurrentDirectoryW(wchar_t* lpPathName) {
    char tempBuffer[_MAX_PATH];
    wcstombs(tempBuffer, lpPathName, _MAX_PATH);

    // return true on success (0)
    return chdir(tempBuffer) ? false : true;
}

DWORD GetCurrentDirectoryW(DWORD nBufferLength, wchar_t* lpBuffer) {
    char tempBuffer[nBufferLength];

    if (getcwd(tempBuffer, nBufferLength)) {
        return mbstowcs(lpBuffer, tempBuffer, nBufferLength);
    } else {
        return 0;
    }
}

DWORD GetCurrentProcessId(void) {
    return static_cast<DWORD>(getpid());
}

char* _getcwd(char* buf, size_t size) {
    return getcwd(buf, size);
}

char* _strdup(const char* s) {
    return strdup(s);
}