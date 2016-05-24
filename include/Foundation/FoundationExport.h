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

#ifndef FOUNDATION_IMPEXP
#define FOUNDATION_IMPEXP __declspec(dllimport)
#endif

#ifndef FOUNDATION_EXPORT
#ifdef __cplusplus
#define FOUNDATION_EXPORT FOUNDATION_IMPEXP extern "C"
#define FOUNDATION_EXPORT_CLASS FOUNDATION_IMPEXP
#else
#define FOUNDATION_EXPORT FOUNDATION_IMPEXP extern
#define FOUNDATION_EXPORT_CLASS FOUNDATION_IMPEXP
#endif
#endif

#ifndef FOUNDATION_EXTERNC_BEGIN
#if defined(__cplusplus)
#define FOUNDATION_EXTERNC_BEGIN extern "C" {
#define FOUNDATION_EXTERNC_END }
#else
#define FOUNDATION_EXTERNC_BEGIN
#define FOUNDATION_EXTERNC_END
#endif
#endif

#if !defined(FOUNDATION_INLINE)
#if defined(__GNUC__) && (__GNUC__ == 4) && !defined(DEBUG)
#define FOUNDATION_INLINE static __inline__ __attribute__((always_inline))
#elif defined(__GNUC__)
#define FOUNDATION_INLINE static __inline__
#elif defined(__cplusplus)
#define FOUNDATION_INLINE static inline
#elif defined(_MSC_VER)
#define FOUNDATION_INLINE static __inline
#elif TARGET_OS_WIN32
#define FOUNDATION_INLINE static __inline__
#endif
#endif
