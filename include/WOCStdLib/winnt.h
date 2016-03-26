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

#ifdef _ARM_

// winnt.h includes some ARM intrinsics that aren't supported in
// clang and cause front end compilation breaks. Because of this,
// def a flag for /clr:pure which removes a lot of MS specific
// compiler intrinsic usage.
#ifndef _M_CEE_PURE
#define __SHOULD_UNDEF_M_CEE_PURE
#define _M_CEE_PURE
#endif

#include_next <winnt.h>

#ifdef __SHOULD_UNDEF_M_CEE_PURE
#undef __SHOULD_UNDEF_M_CEE_PURE
#undef _M_CEE_PURE
#endif

#else

#include_next <winnt.h>

#endif