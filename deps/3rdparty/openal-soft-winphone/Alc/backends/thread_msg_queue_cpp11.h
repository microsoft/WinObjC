#ifndef THREAD_MSG_QUEUE_WINRT_H
#define THREAD_MSG_QUEUE_WINRT_H

#include <mutex>
#include <list>
#include <condition_variable>
#include <stdint.h>

#ifndef TM_QUIT
#define TM_QUIT                         0x0012
#endif

struct QueueMsg_t {
	uint32_t message;
	void* wParam;
	void* lParam;
};

//MsgQueueThread_t
class MsgQueue_t {
public:
	MsgQueue_t();
	~MsgQueue_t();

	int PostMsg(uint32_t MsgType, void* wParam, void* lParam);//return non zero on succeeded. 
	int GetMsg(QueueMsg_t* msgOut);//return non zero on succeeded. return 0 when receive TM_QUIT message
private:
	std::list<QueueMsg_t> MsgQueue;

	std::mutex MsgQueueLock;
	std::condition_variable MsgNotEmptyCond;
};

#endif