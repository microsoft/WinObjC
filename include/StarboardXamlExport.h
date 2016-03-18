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

#ifndef SBXAML_IMPEXP
#define SBXAML_IMPEXP __declspec(dllimport)
#endif

#ifndef SBXAML_EXPORT
#ifdef __cplusplus
#define SBXAML_EXPORT extern "C" SBXAML_IMPEXP
#define SBXAML_EXPORT_CLASS SBXAML_IMPEXP
#else
#define SBXAML_EXPORT extern SBXAML_IMPEXP
#define SBXAML_EXPORT_CLASS SBXAML_IMPEXP
#endif
#endif

#ifndef SBXAML_EXTERNC_BEGIN
#if defined(__cplusplus)
#define SBXAML_EXTERNC_BEGIN extern "C" {
#define SBXAML_EXTERNC_END }
#else
#define SBXAML_EXTERNC_BEGIN
#define SBXAML_EXTERNC_END
#endif
#endif

#define SBXAML_INLINE static __inline

#if defined(__GNUC__)
#define SBXAML_ALWAYS_INLINE static __inline __always_inline
#else
#define SBXAML_ALWAYS_INLINE static __inline
#endif