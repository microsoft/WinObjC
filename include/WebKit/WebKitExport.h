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

#ifndef WEBKIT_IMPEXP
#define WEBKIT_IMPEXP __declspec(dllimport)
#endif

#ifndef WEBKIT_EXPORT
#ifdef __cplusplus
#define WEBKIT_EXPORT WEBKIT_IMPEXP extern "C"
#define WEBKIT_EXPORT_CLASS WEBKIT_IMPEXP
#else
#define WEBKIT_EXPORT WEBKIT_IMPEXP extern
#define WEBKIT_EXPORT_CLASS WEBKIT_IMPEXP
#endif
#endif

#ifndef WEBKIT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define WEBKIT_EXTERNC_BEGIN extern "C" {
#define WEBKIT_EXTERNC_END }
#else
#define WEBKIT_EXTERNC_BEGIN
#define WEBKIT_EXTERNC_END
#endif
#endif
