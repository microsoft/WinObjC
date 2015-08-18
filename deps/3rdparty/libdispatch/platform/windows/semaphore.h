#ifndef PLATFORM_WINDOWS_SEMAPHORE__H
#define PLATFORM_WINDOWS_SEMAPHORE__H

#include "time.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef void* sem_t;

int sem_init(sem_t* sem, int pshared, unsigned int value);
sem_t* sem_open(const char* name, int oflag, ...);
int sem_unlink(const char* name);
int sem_close(sem_t* sem);
int sem_destroy(sem_t* sem);

int sem_wait(sem_t* sem);
int sem_trywait(sem_t* sem);
int sem_timedwait(sem_t* sem, const struct timespec* abs_timeout);
int sem_post(sem_t* sem);
int sem_getvalue(sem_t* sem, int* sval);

#ifdef __cplusplus
}
#endif

#endif
