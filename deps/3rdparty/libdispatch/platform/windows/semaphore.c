#include "semaphore.h"
#include "time.h"

#include <SDKDDKVer.h>
#include <Windows.h>

#include <errno.h>

typedef HANDLE sem_t;

int sem_init(sem_t* sem, int pshared, unsigned int value)
{
	if(!sem)
	{
		return EINVAL;
	}
	UNREFERENCED_PARAMETER(pshared);

	*sem = CreateSemaphoreExW(NULL, value, LONG_MAX, NULL, 0, SEMAPHORE_ALL_ACCESS);
	return 0;
}

sem_t* sem_open(const char* name, int oflag, ...);
int sem_unlink(const char* name);
int sem_close(sem_t* sem);

int sem_destroy(sem_t* sem)
{
	if(!sem)
	{
		return EINVAL;
	}

	CloseHandle(*sem);
	*sem = 0;
	return 0;
}

int sem_wait(sem_t* sem)
{
	if(!sem)
	{
		return EINVAL;
	}

	WaitForSingleObjectEx(*sem, INFINITE, FALSE);
	return 0;
}

int sem_trywait(sem_t* sem)
{
	if(!sem)
	{
		return EINVAL;
	}

	switch(WaitForSingleObjectEx(*sem, 0, FALSE))
	{
	case WAIT_TIMEOUT:
		return EAGAIN;
	case WAIT_OBJECT_0:
		return 0;
	default:
		return -1;
	}
}

int sem_timedwait(sem_t* sem, const struct timespec* abs_timeout)
{
	struct timespec now = {0};
	__int64 delta = 0;

	if(!sem)
	{
		return EINVAL;
	}

	clock_gettime(CLOCK_REALTIME, &now);
	delta = ((abs_timeout->tv_sec * INTERVALS_PER_SEC) + (abs_timeout->tv_nsec / NSEC_PER_INTERVAL))
	      - ((now.tv_sec          * INTERVALS_PER_SEC) + (now.tv_nsec          / NSEC_PER_INTERVAL));
	delta = delta / (INTERVALS_PER_SEC / 1000);
	if(delta < 0)
	{
		delta = 0;
	}
	switch(WaitForSingleObjectEx(*sem, (DWORD)delta, FALSE))
	{
	case WAIT_TIMEOUT:
		return ETIMEDOUT;
	case WAIT_OBJECT_0:
		return 0;
	default:
		return -1;
	}
}

int sem_post(sem_t* sem)
{
	if(!sem)
	{
		return EINVAL;
	}

	ReleaseSemaphore(*sem, 1, NULL);
	return 0;
}

int sem_getvalue(sem_t* sem, int* sval);
