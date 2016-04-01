/**
 * OpenAL cross platform audio library
 * Copyright (C) 2014 by Le Hoang Quyen.
 * This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the
 *  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA  02111-1307, USA.
 * Or go to http://www.gnu.org/copyleft/lgpl.html
 */

#include "config.h"

#include <stdlib.h>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <mutex>
#include <new>

#include "alMain.h"
#include "alThunk.h"


struct ThreadInfo{
	ThreadInfo() : thread(nullptr) {}
	~ThreadInfo() { delete thread; }

	ALuint(*func)(ALvoid*);
	ALvoid *ptr;
	ALuint ret;
	std::thread* thread;
} ;

#ifdef _MSC_VER
//there are some bugs in std::mutex implementation of MSVC
#define NO_STD_MUTEX
#endif

#ifdef NO_STD_MUTEX
class _MutexType {
public:
	_MutexType()
		: pCritSec(NULL){
		pCritSec = new CRITICAL_SECTION();
		if (!InitializeCriticalSectionEx(pCritSec, 0, 0))
		{
			delete pCritSec;
			pCritSec = nullptr;

			throw std::bad_alloc();
		}
	}

	~_MutexType() {
		if (pCritSec)
		{
			DeleteCriticalSection(pCritSec);
			delete pCritSec;
		}
	}
	void lock() { EnterCriticalSection(pCritSec); }
	void unlock() { LeaveCriticalSection(pCritSec); }
private:
	CRITICAL_SECTION *pCritSec;
};
#else//#ifdef NO_STD_MUTEX
typedef std::mutex _MutexType;
#endif//#ifdef NO_STD_MUTEX

/*--------thread local storage---------*/
class _ThreadLocalData: public std::unordered_map<ULONG, void*> {
public :
	typedef std::unordered_map<ULONG, void*> ParentType;
	_ThreadLocalData();
	~_ThreadLocalData();
};
static __declspec( thread )  _ThreadLocalData* currentThreadLocalData = nullptr;

static _MutexType& GetTlsAllocLock(){
	static _MutexType _tlsLock;
	return _tlsLock;
}

static std::unordered_set<_ThreadLocalData*>& GetAllThreadData()
{
	static std::unordered_set<_ThreadLocalData*> _allThreadData;
	return _allThreadData;
}

static std::set<DWORD>& GetReusableAllocIds() {
	static std::set<DWORD> _reuseAllocID;
	return _reuseAllocID;
}

static DWORD& GetTlsAllocSeed(){
	static DWORD _seed = 0;
	return _seed;
}

#define TLS_ALLOC_SEED GetTlsAllocSeed()
#define ALL_THREAD_DATA GetAllThreadData()
#define TLS_ALLOC_LOCK GetTlsAllocLock()
#define REUSABLE_ALLOC_IDS GetReusableAllocIds()

_ThreadLocalData::_ThreadLocalData()
{
	ALL_THREAD_DATA.insert(this);//push to list of all thread's data
}

_ThreadLocalData::~_ThreadLocalData()
{
	ALL_THREAD_DATA.erase(this);//erase from list of all thread's data
}


//public "C" interfaces
extern "C"{
DWORD cpp11_TlsAlloc()
{
	DWORD id;
	auto & _tlsAllocLock = TLS_ALLOC_LOCK;
	auto & _reuseAllocID = REUSABLE_ALLOC_IDS;
	auto& _tlsAllocSeed = TLS_ALLOC_SEED;

	_tlsAllocLock.lock();

	//use reuseable ID if available
	if (_reuseAllocID.size() > 0)
	{
		auto ite = _reuseAllocID.begin();
		id = *ite;
		_reuseAllocID.erase(ite);
	}
	//increase id seed counter
	id = _tlsAllocSeed++;
	_tlsAllocLock.unlock();

	return id;
}

BOOL cpp11_TlsFree(DWORD id)
{
	BOOL re = TRUE;
	auto & _tlsAllocLock = TLS_ALLOC_LOCK;
	auto & _reuseAllocID = REUSABLE_ALLOC_IDS;
	auto & _tlsAllocSeed = TLS_ALLOC_SEED;
	auto & _allThreadData = ALL_THREAD_DATA;

	_tlsAllocLock.lock();
	if (id < _tlsAllocSeed)
	{
		_reuseAllocID.insert(id);

		//release every thread's data associated with this key
		for (auto & threadData : _allThreadData)
		{
			auto ite = threadData->find(id);
			if (ite != threadData->end())
				threadData->erase(ite);
		}
	}
	else 
		re = FALSE;
	_tlsAllocLock.unlock();
	return re;
}

void* cpp11_TlsGetValue(DWORD id)
{
	void* re = NULL;

	if (currentThreadLocalData != nullptr)
	{
		auto ite = currentThreadLocalData->find(id);
		if (ite != currentThreadLocalData->end())
			re = ite->second;
	}

	return re;
}

BOOL cpp11_TlsSetValue(DWORD id, void* value)
{
	BOOL re = FALSE;
	auto & _reuseAllocID = REUSABLE_ALLOC_IDS;
	auto & _tlsAllocSeed = TLS_ALLOC_SEED;

	if (id < _tlsAllocSeed && _reuseAllocID.find(id) == _reuseAllocID.end())//valid key
	{
		//create thread local data container if unavailable
		if (currentThreadLocalData == nullptr)
			currentThreadLocalData = new (std::nothrow)_ThreadLocalData();
	
		if (currentThreadLocalData != nullptr)
		{
			(*currentThreadLocalData)[id] = value;

			re = TRUE;
		}
	}

	return re;
}

/*----------------------*/
void cpp11_Sleep(ALuint ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


int sched_yield(void)
{
	std::this_thread::yield();
	return 0;
}



static void StarterFunc(void *ptr)
{
    ThreadInfo *inf = (ThreadInfo*)ptr;
    
	inf->ret = inf->func(inf->ptr);

	//release thread local data
	if (currentThreadLocalData != nullptr)
	{
		delete currentThreadLocalData;
		currentThreadLocalData = nullptr;
	}
}

ALvoid *StartThread(ALuint (*func)(ALvoid*), ALvoid *ptr)
{
	ThreadInfo *inf = new(std::nothrow) ThreadInfo ();
    if(!inf) return 0;

    inf->func = func;
    inf->ptr = ptr;

	inf->thread = new(std::nothrow) std::thread(StarterFunc, inf);
    if(!inf->thread)
    {
        delete (inf);
        return NULL;
    }

    return inf;
}

ALuint StopThread(ALvoid *thread)
{
	ThreadInfo *inf = (ThreadInfo *)thread;
    ALuint ret = 0;

	if (inf->thread->joinable())
		inf->thread->join();

	ret = inf->ret;

    delete (inf);

    return ret;
}

}//extern "C"
