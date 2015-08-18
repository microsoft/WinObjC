#ifndef PLATFORM_WINDOWS_PTHREAD__H
#define PLATFORM_WINDOWS_PTHREAD__H

#ifdef __cplusplus
extern "C"
{
#endif

struct _pthread;
typedef struct _pthread pthread;
typedef pthread* pthread_t;
struct _pthread_attr;
typedef struct _pthread_attr pthread_attr;
typedef pthread_attr* pthread_attr_t;

typedef long pthread_key_t;

int pthread_key_create(pthread_key_t* key, void (*destr_function)(void*));
int pthread_key_delete(pthread_key_t key);
int pthread_setspecific(pthread_key_t key, const void* pointer);
void* pthread_getspecific(pthread_key_t key);

int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg);
int pthread_detach(pthread_t thread);
int pthread_join(pthread_t thread, void** thread_return);
__declspec(noreturn) void pthread_exit(void *status);
pthread_t pthread_self();

void* _pthread_get_native_handle(pthread_t);

// Threadpool threads are getting torn down without calling TLS destructors. This is infuriating.
// In response, we don't rely on the automatic systems.
void _pthread_tls_attach_thread(void);
void _pthread_tls_detach_thread(void);

#ifdef __cplusplus
}
#endif

#endif
