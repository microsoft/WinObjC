//
// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// angleutils.h: Common ANGLE utilities.

#ifndef COMMON_WINRT_THREADUTILS_H_
#define COMMON_WINRT_THREADUTILS_H_

#include <windows.h>


namespace ThreadUtilsWinRT
{

inline DWORD TlsAlloc(){
	return FlsAlloc(nullptr);
}

inline void LocalFree(HLOCAL index)
{
    free((void*) index);
}

inline void* LocalAlloc(UINT uFlags, size_t size)
{
    return malloc(size);
}

#define TlsFree FlsFree


#define TLS_OUT_OF_INDEXES FLS_OUT_OF_INDEXES
#define TlsSetValue FlsSetValue
#define TlsGetValue FlsGetValue

}


#endif // COMMON_WINRT_THREADUTILS_H_
