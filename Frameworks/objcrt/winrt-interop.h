#pragma once

#ifdef __cplusplus
extern "C" {
#endif

unsigned int __stdcall _winrt_inspect_QueryInterface(void* thisptr, void* riid, void** ppvObject);
unsigned int __stdcall _winrt_inspect_AddRef(void* thisptr);
unsigned int __stdcall _winrt_inspect_Release(void* thisptr);
unsigned int __stdcall _winrt_inspect_GetIids(void* thisptr, unsigned long* iidCount, void** iids);
unsigned int __stdcall _winrt_inspect_GetRuntimeClassName(void* thisptr, void** name);
unsigned int __stdcall _winrt_inspect_GetTrustLevel(void* thisptr, int* TrustLevel);
unsigned int __stdcall _winrt_iwmsgsend_MsgSend(void* thisptr, const char* selName, ...);
BOOL object_isWinRT(id obj);
IMP object_getWinRTImp(id obj, const char* selName);
#ifdef __cplusplus
};
#endif
