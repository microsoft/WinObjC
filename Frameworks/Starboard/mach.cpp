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

#include <Windows.h>
#include <mach/mach.h>
#include <StubReturn.h>
#include <mach/mach_defs.h>
#include <mach/mach_time.h>

extern "C" {
/**
@Status Caveat
@Notes Parameter port will be ignored.
*/
kern_return_t host_page_size(host_t host, vm_size_t* pageSize) {
    SYSTEM_INFO systemInfo = {};
    ::GetNativeSystemInfo(&systemInfo);
    *pageSize = static_cast<vm_size_t>(systemInfo.dwPageSize);
    return KERN_SUCCESS;
}

/**
@Status Stub
*/
mach_port_t mach_host_self(void) {
    UNIMPLEMENTED();
    return 0;
}

int vm_page_size = 65536;

/**
@Status Stub
*/
int host_statistics(mach_port_t port, int type, host_info_t dataOut, mach_msg_type_number_t* dataOutSize) {
    if (type == HOST_VM_INFO && *dataOutSize >= sizeof(vm_statistics)) {
        *dataOutSize = sizeof(vm_statistics);

        vm_statistics* ret = (vm_statistics*)dataOut;
        memset(ret, 0, sizeof(vm_statistics));

        ret->free_count = 512 * 1024 * 1024 / 65536;
    } else {
        UNIMPLEMENTED();
    }

    return 0;
}

static int64_t _mach_get_timebase() {
    LARGE_INTEGER performanceFrequency;
    FAIL_FAST_IF(0 == QueryPerformanceFrequency(&performanceFrequency));
    return performanceFrequency.QuadPart;
}

static int64_t _mach_frequency = _mach_get_timebase();

kern_return_t mach_timebase_info(mach_timebase_info_t tinfo) {
    //  mach_absolute_time uses QueryPerformanceCounter which returns
    //  the absolute number of cycles since boot in microseconds.
    //
    // Return a timebase representing the conversion between QPC counts and nanoseconds:
    // 1,000,000,000 nanoseconds per every n counts.
    *tinfo = { 1000000000, _mach_frequency };

    return 0;
}

uint64_t mach_absolute_time() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    // mach_absolute_time is unsigned, but this function returns a signed value.
    return (uint64_t)count.QuadPart;
}

}
