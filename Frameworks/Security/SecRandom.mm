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

#include <windows.h>
#include <BCrypt.h>
#import <Starboard.h>
#import <Security/SecRandom.h>
#include <errno.h>

const SecRandomRef kSecRandomDefault = nullptr; // we just need a sentinel value for this constant

static int _getErrorNumber(DWORD status) {
    switch (status) {
        case STATUS_SUCCESS:
            return 0;
        case STATUS_INVALID_PARAMETER:
        case STATUS_INVALID_HANDLE:
            return EINVAL;
        case STATUS_NO_MEMORY:
        case STATUS_ACCESS_VIOLATION:
            return ENOMEM;
        default:
            break;
    }
    return EFAULT;
}

/**
 @Status Caveat
 @Notes only kSecRandomDefault is supported
*/
int SecRandomCopyBytes(SecRandomRef rnd, size_t count, uint8_t* bytes) {
    NTSTATUS ret = STATUS_INVALID_HANDLE;

    if (rnd != kSecRandomDefault) {
        LOG_NTSTATUS_MSG(ret, "Invalid SecRandomRef value passed to SecRandomCopyBytes");
    } else {
        ret = BCryptGenRandom(NULL, reinterpret_cast<BYTE*>(bytes), count, BCRYPT_USE_SYSTEM_PREFERRED_RNG);
        LOG_IF_NTSTATUS_FAILED_MSG(ret, "BCryptGenRandom failed\n");
    }

    _set_errno(_getErrorNumber(ret));
    return ret == STATUS_SUCCESS ? 0 : -1;
}
