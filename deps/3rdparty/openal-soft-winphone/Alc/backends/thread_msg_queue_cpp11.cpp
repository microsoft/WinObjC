/**
* OpenAL cross platform audio library
* Copyright (C) 2014 by Le Hoang Quyen
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

#include "thread_msg_queue_cpp11.h"


MsgQueue_t::MsgQueue_t()
{
	
}

MsgQueue_t::~MsgQueue_t()
{
}

int MsgQueue_t::PostMsg(uint32_t MsgType, void* wParam, void* lParam)
{
	int re = 1;
	QueueMsg_t newMsg;
	newMsg.message = MsgType;
	newMsg.wParam = wParam;
	newMsg.lParam = lParam;

	//push to queue
	MsgQueueLock.lock();

	try {
		MsgQueue.push_back(newMsg);
	}
	catch (...) {
		re = 0;
	}
	//notify that the queue is not empty
	MsgNotEmptyCond.notify_one();

	MsgQueueLock.unlock();

	return re;
}


int MsgQueue_t::GetMsg(QueueMsg_t* msgOut)
{
	std::unique_lock<std::mutex> lock(MsgQueueLock);

	//wait for the queue to have at least one message
	if (MsgQueue.size() == 0)
		MsgNotEmptyCond.wait(lock);


	//retrieve the oldest message
	*msgOut = MsgQueue.front();
	MsgQueue.pop_front();

	if (msgOut->message == TM_QUIT)
		return 0;

	return 1;
}
