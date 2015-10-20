//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

/*
 * WIN32 Events for POSIX
 * Author: Mahmoud Al-Qudsi <mqudsi@neosmart.net>
 * Copyright (C) 2011 - 2012 by NeoSmart Technologies
 * This code is released under the terms of the MIT License
 */

#pragma once

#include <pthread.h>
#include <stdint.h>

#define WFMO

namespace neosmart {
// Type declarations
struct neosmart_event_t_;
typedef neosmart_event_t_* neosmart_event_t;

// WIN32-style functions
neosmart_event_t NeoCreateEvent(bool manualReset = false, bool initialState = false);
int DestroyEvent(neosmart_event_t event);
int WaitForEvent(neosmart_event_t event, uint64_t milliseconds = -1);
int SetEvent(neosmart_event_t event);
int ResetEvent(neosmart_event_t event);
#ifdef WFMO
int WaitForMultipleEvents(neosmart_event_t* events, int count, bool waitAll, uint64_t milliseconds);
int WaitForMultipleEvents(neosmart_event_t* events, int count, bool waitAll, uint64_t milliseconds, int& index, SocketWait* sockets);
#endif

// POSIX-style functions
// TBD
}
