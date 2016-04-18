#include "pthread.h"

#include <SDKDDKVer.h>
#include <Windows.h>

#ifdef _MSC_VER

#if defined DEBUG || defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_CLIENTBLOCK new(_CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

#endif

#include <errno.h>

#pragma warning(disable : 4200) // warning C4200: nonstandard extension used : zero-sized array in struct/union

long slots_allocated;
typedef void (*slot_destructor)(void*);
slot_destructor* destructors; // slot_destructor[slots_allocated]
CRITICAL_SECTION destructor_lock;

struct _pthread_items
{
	long count;
	pthread_t current_thread;
	void* items[];
};

typedef struct _pthread_items pthread_items;
typedef pthread_items* pthread_items_t;
__declspec(thread) pthread_items_t pthread_items_tlv;

struct _pthread
{
	BOOL privately_owned;
	HANDLE thread;
	void* result;
};

typedef struct _pthread pthread;

typedef pthread* pthread_t;

void* _pthread_get_native_handle(pthread_t pt)
{
	return pt->thread;
}

static void _pthread_destructors(void)
{
	pthread_items_t items;
	slot_destructor* local_destructors;
	long slot_count, i;
	int more_calls_needed;

	EnterCriticalSection(&destructor_lock);
	items = pthread_items_tlv;
	slot_count = slots_allocated;
	local_destructors = calloc(slot_count, sizeof(slot_destructor));
	memcpy(local_destructors, destructors, slot_count * sizeof(slot_destructor));
	LeaveCriticalSection(&destructor_lock);
	do
	{
		for(i = 0; i < slot_count; ++i)
		{
			if(items->items[i] && local_destructors[i])
			{
				void* value = items->items[i];
				items->items[i] = NULL;
				local_destructors[i](value);
			}
		}
		more_calls_needed = 0;
		for(i = 0; i < slot_count; ++i)
		{
			if(items->items[i] && local_destructors[i])
			{
				more_calls_needed = 1;
			}
		}
	}
	while(more_calls_needed);
	free(local_destructors);
}

#include <stdio.h>

void _pthread_tls_attach_thread()
{
	pthread_items_t items = pthread_items_tlv;
	if(!items)
	{
		HANDLE thread_handle = INVALID_HANDLE_VALUE;
		items = calloc(1, sizeof(pthread_items) + slots_allocated * sizeof(void*));
		items->count = slots_allocated;
		items->current_thread = calloc(1, sizeof(pthread));
		items->current_thread->privately_owned = TRUE;
		DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &thread_handle, 0, TRUE, DUPLICATE_SAME_ACCESS);
		items->current_thread->thread = thread_handle;
		pthread_items_tlv = items;
	}
}

void _pthread_tls_detach_thread()
{
	pthread_items_t items = pthread_items_tlv;
	if(items)
	{
		_pthread_destructors();
		if(items->current_thread->privately_owned)
		{
			CloseHandle(items->current_thread->thread);
			free(items->current_thread);
		}
		free(items);
		pthread_items_tlv = NULL;
	}
}

void NTAPI pthread_tls_init(void* dll, DWORD reason, void* reserved)
{
	UNREFERENCED_PARAMETER(dll);
	UNREFERENCED_PARAMETER(reserved);

	switch(reason)
	{
	case DLL_PROCESS_ATTACH:
		slots_allocated = 0;
		destructors = NULL;
		InitializeCriticalSectionEx(&destructor_lock, 0, 0);
		// fall through
	case DLL_THREAD_ATTACH:
		// For WINOBJC - TLS initialization can be defered until a caller is actually trying to set/get from the TLS. Initializing
		// TLS for all threads does not really give us any benefit, rather can theoritically slow things down as we initialize it
		// for every thread the application creates that won't be using the TLS.
#ifndef WINOBJC
		_pthread_tls_attach_thread();
#endif
		break;
	case DLL_THREAD_DETACH:
		_pthread_tls_detach_thread();
		break;
	case DLL_PROCESS_DETACH:
		/* For WINOBJC - Don't detach the last thread, as it is likely executing from within a block and will complain about the 
		   queue not being empty */
#ifndef WINOBJC
		_pthread_tls_detach_thread();
#endif
		free(destructors);
		DeleteCriticalSection(&destructor_lock);
		break;
	}
}

#if defined(_LIB)

#ifdef _M_IX86
#pragma comment (linker, "/INCLUDE:__tls_used")
#pragma comment (linker, "/INCLUDE:_pthread_tls_callback")
#else
#pragma comment (linker, "/INCLUDE:_tls_used")
#pragma comment (linker, "/INCLUDE:pthread_tls_callback")
#endif

#ifdef _M_X64
#pragma const_seg(".CRT$XLF")
EXTERN_C const
#elif defined( WINOBJC ) && !defined( _M_IX86 )
#pragma const_seg(".CRT$XLF")
EXTERN_C const
#else
#pragma data_seg(".CRT$XLF")
EXTERN_C
#endif

PIMAGE_TLS_CALLBACK pthread_tls_callback = pthread_tls_init;

#ifdef _M_X64
#pragma const_seg()
#elif defined( WINOBJC ) && !defined( _M_IX86 )
#pragma const_seg()
#else
#pragma data_seg()
#endif

#elif defined(_WINDLL)

// put dllmain here

#endif

int pthread_key_create(pthread_key_t* key, void (*destr_function)(void*))
{
	if(!key)
	{
		return EFAULT;
	}

	EnterCriticalSection(&destructor_lock);
	{
		long new_key = slots_allocated++;
		destructors = realloc(destructors, sizeof(slot_destructor) * slots_allocated);
		destructors[new_key] = destr_function;
		*key = new_key;
	}
	LeaveCriticalSection(&destructor_lock);

	return 0;
}

int pthread_key_delete(pthread_key_t key)
{
	if(key >= slots_allocated)
	{
		return EINVAL;
	}
	return 0;
}

static pthread_items_t _get_items()
{
	pthread_items_t items = pthread_items_tlv;
#ifdef WINOBJC
	if (items == NULL)
	{
		// TLS is being accessed for the first time for this thread. Initialize TLS area.
		_pthread_tls_attach_thread();
		items = pthread_items_tlv;
	}
#endif

	if(items->count < slots_allocated)
	{
		long i = 0;
		items = realloc(items, sizeof(pthread_items) + slots_allocated * sizeof(void*));
		for(i = items->count; i < slots_allocated; ++i)
		{
			items->items[i] = NULL;
		}
		items->count = slots_allocated;
		pthread_items_tlv = items;
	}
	return items;
}

int pthread_setspecific(pthread_key_t key, const void* pointer)
{
	pthread_items_t items = _get_items();
	items->items[key] = (void*)pointer;
	return 0;
}

void* pthread_getspecific(pthread_key_t key)
{
	pthread_items_t items = _get_items();
	return items->items[key];
}

struct _fn
{
	void* (*fun)(void*);
	void* context;
	pthread_t* pth;
	HANDLE evt;
};

typedef struct _fn fn;

static DWORD WINAPI thread_proc(void* parameter)
{
	fn* f = parameter;

	*f->pth = pthread_self();
	pthread_self()->privately_owned = FALSE;
	SetEvent(f->evt);
	pthread_self()->result = f->fun(f->context);

	free(f);
	return 0;
}

int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg)
{
	fn* f;
	HANDLE evt = CreateEventEx(NULL, NULL, CREATE_EVENT_MANUAL_RESET, EVENT_ALL_ACCESS);

	if(!thread || !start_routine)
	{
		return EFAULT;
	}
	if(attr)
	{
		return EINVAL;
	}

	f = calloc(1, sizeof(fn));
	if(!f)
	{
		return ENOMEM;
	}

	f->fun = start_routine;
	f->context = arg;
	f->pth = thread;
	f->evt = evt;
	CloseHandle(CreateThread(NULL, 0, thread_proc, f, 0, NULL));
	WaitForSingleObjectEx(evt, INFINITE, FALSE);
	CloseHandle(evt);
	return 0;
}

int pthread_detach(pthread_t thread)
{
	thread->privately_owned = TRUE;
	return 0;
}

int pthread_join(pthread_t thread, void** thread_return)
{
	WaitForSingleObjectEx(thread->thread, INFINITE, FALSE);
	if(thread_return)
	{
		*thread_return = thread->result;
	}
	CloseHandle(thread->thread);
	free(thread);
	return 0;
}

void pthread_exit(void* status)
{
	pthread_self()->result = status;
	// HACKHACK Windows is not at all happy at making API calls during thread teardown.
	// with many APIs claiming "0xC000000D: An invalid parameter was passed to a service or function."
	// so I have to call these early.
	_pthread_destructors();
	ExitThread(0);
}

pthread_t pthread_self()
{
	pthread_items_t items = _get_items();
	return items->current_thread;
}
