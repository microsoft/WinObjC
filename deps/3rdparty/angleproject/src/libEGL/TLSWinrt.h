//
// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// TLSWinrt.h: Thread local storage implementation for WinRT and WP8.

#ifndef TLS_WINRT_H_
#define TLS_WINRT_H_
#include "libEGL/main.h"

#if defined(WINAPI_FAMILY)
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define TLS_OUT_OF_INDEXES -1

void* AngleTlsGetValue(DWORD index);
DWORD AngleTlsAlloc();
void AngleTlsSetValue(DWORD currentTLS, egl::Current* current);
void AngleTlsFree(DWORD index);

void * LocalAlloc(UINT uFlags, size_t size);
void LocalFree(HLOCAL index);
#endif
#endif

#endif // TLS_WINRT_H_
