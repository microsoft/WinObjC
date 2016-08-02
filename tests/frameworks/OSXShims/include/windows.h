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

#pragma once

#import <stdint.h>
#import <limits.h>

#import <cstddef>

#ifndef _MAX_PATH
#define _MAX_PATH PATH_MAX
#endif

#ifndef _MAX_FNAME
#define _MAX_FNAME NAME_MAX
#endif

#ifndef DWORD
#define DWORD uint32_t
#endif

long InterlockedExchange(long volatile* Target, long Value);
long _InterlockedExchange(long volatile* Target, long Value);

long InterlockedIncrement(long volatile* Addend);
long InterlockedDecrement(long volatile* Addend);

void Sleep(DWORD dwMilliseconds);

// Currently all usages of GetModuleFileName + variants use NULL for hModule, so its type doesn't matter
// May need more complex shim if actual handle is used at any point
DWORD GetModuleFileNameA(void* hModule, char* lpFilename, DWORD nSize);
DWORD GetModuleFileNameW(void* hModule, wchar_t* lpFilename, DWORD nSize);

bool SetCurrentDirectoryW(wchar_t* lpPathName);
DWORD GetCurrentDirectoryW(DWORD nBufferLength, wchar_t* lpBuffer);

DWORD GetCurrentProcessId(void);

char* _getcwd(char* buf, size_t size);
char* _strdup(const char* s);