//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#include <libkern/OSAtomic.h>
#include "windows.h"
#ifdef _MSC_VER
#include <intrin.h>
#endif

extern "C" void OSSpinLockLock(volatile OSSpinLock* lock) {
    while (_InterlockedCompareExchange((volatile long*)lock, ~0, 0) != 0) {
        Sleep(0);
    }
}

extern "C" void OSSpinLockUnlock(volatile OSSpinLock* lock) {
    _InterlockedExchange((volatile long*)lock, 0);
}

extern "C" bool OSSpinLockTry(volatile OSSpinLock* lock) {
    return (_InterlockedCompareExchange((volatile long*)lock, ~0, 0) == 0);
}