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

#include <TestFramework.h>
#import <Security/SecRandom.h>
#include <errno.h>
#include <windows.h>
#include "ByteUtils.h"

TEST(Security, SecRandom_Failure) {
    ASSERT_EQ_MSG(SecRandomCopyBytes((SecRandomRef)1, 0, nullptr), -1, "SecRandomCopyBytes did not fail for invalid SecRandomRef value");
    ASSERT_EQ_MSG(errno, EINVAL, "SecRandomCopyBytes did not set correct errno for invalid SecRandomRef value");
    ASSERT_EQ_MSG(SecRandomCopyBytes(kSecRandomDefault, 0, nullptr), -1, "SecRandomCopyBytes did not fail for invalid parameters value");
    ASSERT_EQ_MSG(errno, EINVAL, "SecRandomCopyBytes did not set correct errno for invalid SecRandomRef value");
}

TEST(Security, SecRandom_Sanity) {
    BYTE buf1[128];
    BYTE buf2[128];

    memset(buf1, 0, sizeof(buf1));
    memset(buf2, 0, sizeof(buf2));

    ASSERT_EQ_MSG(SecRandomCopyBytes(kSecRandomDefault, _countof(buf1), buf1), 0, "SecRandomCopyBytes failed");
    ASSERT_EQ_MSG(errno, 0, "SecRandomCopyBytes did not set correct errno on success");
    logBytes("buf1", buf1, sizeof(buf1));

    ASSERT_EQ_MSG(SecRandomCopyBytes(kSecRandomDefault, _countof(buf2), buf2), 0, "SecRandomCopyBytes failed");
    ASSERT_EQ_MSG(errno, 0, "SecRandomCopyBytes did not set correct errno on success");
    logBytes("buf2", buf2, sizeof(buf2));

    ASSERT_FALSE_MSG(equalsBytes(buf1, buf2, sizeof(buf1)), "buf1 and buf2 cannot be equal");

    DWORD rand = 0;
    ASSERT_EQ_MSG(SecRandomCopyBytes(kSecRandomDefault, sizeof(rand), reinterpret_cast<BYTE*>(&rand)),
                  0,
                  "SecRandomCopyBytes failed for DWORD");
    ASSERT_EQ_MSG(errno, 0, "SecRandomCopyBytes did not set correct errno on success");
    logBytes("rand", reinterpret_cast<BYTE*>(&rand), sizeof(rand));
}
