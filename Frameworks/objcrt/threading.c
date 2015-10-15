//******************************************************************************
//
// Copyright (c) 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015
//   Jonathan Schleifer <js@webkeks.org>. All rights reserved.
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

#include <stdio.h>
#include <stdlib.h>

#include "runtime.h"
#include "runtime-private.h"

#include <windows.h>

static CRITICAL_SECTION global_mutex;
static BOOL global_mutex_init = NO;

static void objc_global_mutex_new(void) {
    if (!InitializeCriticalSectionEx(&global_mutex, 0, 0))
        OBJC_ERROR("Failed to create global mutex!");

    global_mutex_init = YES;
}

void objc_global_mutex_lock(void) {
    if (!global_mutex_init)
        objc_global_mutex_new();

    EnterCriticalSection(&global_mutex);
}

void objc_global_mutex_unlock(void) {
    LeaveCriticalSection(&global_mutex);
}
