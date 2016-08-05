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

#ifndef LOGGING_IMPEXP
#define LOGGING_IMPEXP __declspec(dllimport)
#endif

#ifndef LOGGING_EXPORT
#ifdef __cplusplus
#define LOGGING_EXPORT extern "C" LOGGING_IMPEXP
#else
#define LOGGING_EXPORT extern LOGGING_IMPEXP
#endif
#endif

//
// Trace a verbose message.
// Verbose messages log the behavior of "normal" or succesful operations.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
LOGGING_EXPORT void TraceVerbose(const wchar_t* tag, const wchar_t* format, ...);

//
// Trace an info message.
// Info messages log valid, but interesting or unusual events.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
LOGGING_EXPORT void TraceInfo(const wchar_t* tag, const wchar_t* format, ...);

//
// Trace a warning message.
// Warning messages log invalid conditions that do not necessarily lead to app failure or data loss.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
LOGGING_EXPORT void TraceWarning(const wchar_t* tag, const wchar_t* format, ...);

//
// Trace an error message.
// Error messages log invalid conditions that most likely lead to app failure or malfunction.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
LOGGING_EXPORT void TraceError(const wchar_t* tag, const wchar_t* format, ...);

//
// Trace a critical message.
// Critical messages log fail fast or similar severity conditions.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
LOGGING_EXPORT void TraceCritical(const wchar_t* tag, const wchar_t* format, ...);

//
// Ensures the the trace logging provider is registered.
//
LOGGING_EXPORT void TraceRegister();

//
// Ensures the trace logging provider is unregistered.
//
LOGGING_EXPORT void TraceUnregister();
