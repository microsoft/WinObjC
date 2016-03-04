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

#import "Foundation/NSString.h"

//
// Helper macros for NSLog
//
// DLog displays output only when with DEBUG setting.
#if (defined(DEBUG) || defined(_DEBUG))
#define DLog(tag, fmt, ...) NSTraceInfo(tag, (@"%s [Line \"%d\"] : " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define DLog(...)
#endif
// VLog always displays output regardless of the DEBUG setting.
#define VLog(tag, fmt, ...) NSTraceInfo(tag, (@"%s : " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__)

//
// Trace a verbose message.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
void NSTraceVerbose(const wchar_t* tag, NSString* format, ...);

//
// Trace an info message.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
void NSTraceInfo(const wchar_t* tag, NSString* format, ...);

//
// Trace a warning message.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
void NSTraceWarning(const wchar_t* tag, NSString* format, ...);

//
// Trace an error message.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
void NSTraceError(const wchar_t* tag, NSString* format, ...);

//
// Trace a critical message.
//
// tag - a tag to be given to this message.
// format - a "printf" style format string
// ... - var args for printf.
//
void NSTraceCritical(const wchar_t* tag, NSString* format, ...);