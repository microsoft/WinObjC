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

#ifndef _STARBOARDEXPORT_H_
#define _STARBOARDEXPORT_H_

#include <sys/cdefs.h>

#ifdef __cplusplus
#define SB_EXPORT extern "C"
#else
#define SB_EXPORT extern
#endif

#define SB_INLINE static __inline

#if defined(__GNUC__)
#define SB_ALWAYS_INLINE static __inline __always_inline
#else
#define SB_ALWAYS_INLINE static __inline
#endif

#define UIKIT_EXTERN SB_EXPORT

#endif /* _STARBOARDEXPORT_H_ */
