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
#pragma once

#ifndef WINOBJCRT_IMPEXP
#define WINOBJCRT_IMPEXP __declspec(dllimport)
#endif

#ifndef WINOBJCRT_EXPORT
#ifdef __cplusplus
#define WINOBJCRT_EXPORT extern "C" WINOBJCRT_IMPEXP
#define WINOBJCRT_EXPORT_CLASS WINOBJCRT_IMPEXP
#else
#define WINOBJCRT_EXPORT extern WINOBJCRT_IMPEXP
#define WINOBJCRT_EXPORT_CLASS WINOBJCRT_IMPEXP
#endif
#endif

#ifndef WINOBJCRT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define WINOBJCRT_EXTERNC_BEGIN extern "C" {
#define WINOBJCRT_EXTERNC_END }
#else
#define WINOBJCRT_EXTERNC_BEGIN
#define WINOBJCRT_EXTERNC_END
#endif
#endif
