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

#include <Windows.h>

#ifndef _M_ARM
#ifndef _STDCALL
#define _STDCALL __stdcall
#endif
#endif

#ifndef _STDCALL
#define _STDCALL
#endif

#ifdef __cplusplus
extern "C" {
#endif

long _STDCALL _NSWindowsUnhandledExceptionFilter(struct _EXCEPTION_POINTERS* ExceptionInfo);
void _NSExceptionCallUnhandledExceptionHandler(void* /* treated as NSException* */);

#ifdef __cplusplus
}
#endif