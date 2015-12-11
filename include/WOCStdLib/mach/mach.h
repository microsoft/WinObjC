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

#include "machine.h"
#include "message.h"
#include "mach_defs.h"
#include "vm_statistics.h"
#include "sys/_types.h"
#include "mach_task.h"

#define HOST_VM_INFO 1

typedef void* host_info_t;

#ifdef __cplusplus
extern "C" {
#endif
extern int vm_page_size;

// Always returns 0.
mach_port_t mach_host_self(void);

// Parameter port will be ignored
kern_return_t host_page_size(host_t host, vm_size_t* pageSize);

int host_statistics(mach_port_t port, int type, host_info_t dataOut, mach_msg_type_number_t* dataOutSize);
#ifdef __cplusplus
}
#endif
