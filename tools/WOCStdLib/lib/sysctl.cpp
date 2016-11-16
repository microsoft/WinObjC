//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include <WOCStdLib/sys/sysctl.h>
#include <windows.h>
#include <StubReturn.h>

/**
@Status Caveat
@Notes Only HW_AVAILCPU is supported
*/
extern "C" int sysctl(const int* name, u_int namelen, void* oldp, size_t* oldlenp, const void* newp, size_t newlen) {
    if (namelen < 2 || name == nullptr) {
        errno = EINVAL;
        return -1;
    }

    if (namelen != 2 ||
        name[0] != CTL_HW ||
        name[1] != HW_AVAILCPU) {

        UNIMPLEMENTED_WITH_MSG("sysctl only supports querying HW_AVAILCPU");
        errno = EOPNOTSUPP;
        return -1;
    }

    if (*oldlenp < sizeof(int)) {
        *oldlenp = sizeof(int);
        errno = ENOMEM;
        return -1;
    }

    SYSTEM_INFO systemInfo;
    GetNativeSystemInfo(&systemInfo);

    *static_cast<int*>(oldp) = systemInfo.dwNumberOfProcessors;
    *oldlenp = sizeof(int);

    return 0;
}
