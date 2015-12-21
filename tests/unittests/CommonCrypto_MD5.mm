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

#include "gtest-api.h"
#include <windows.h>
#include <CommonCrypto\CommonDigest.h>
#include <string>

static const char singleLine[] = "Hello Project Islandwood,  a.k.a. Windows Bridge for iOS!";
static const char multiLine1[] = "Hello ";
static const char multiLine2[] = "Project Islandwood,  ";
static const char multiLine3[] = "a.k.a. Windows Bridge for iOS!";

const BYTE lookup[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

std::string stringFromMD5Digest(BYTE* digest) {
    std::string ret;
    ret.reserve(2 * CC_MD5_DIGEST_LENGTH + 1);

    for (int i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
        ret.push_back(lookup[digest[i] & 0xf]);
        ret.push_back(lookup[digest[i] >> 4]);
    }

    return ret;
}

bool equalsDigest(BYTE* digest1, BYTE* digest2) {
    return memcmp(digest1, digest2, CC_MD5_DIGEST_LENGTH) == 0;
}

void LogDigest(const char* str, BYTE* digest) {
    std::string strDigest = stringFromMD5Digest(digest);
    LOG_INFO("Digest value for %s is %s", str, strDigest.c_str());
}

TEST(CommonCrypto, Sanity) {
    CC_MD5_CTX ctx;
    BYTE digest[CC_MD5_DIGEST_LENGTH];

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    LogDigest(singleLine, digest);
}

TEST(CommonCrypto, SameDataYieldsSameResult) {
    CC_MD5_CTX ctx;
    BYTE digest1[CC_MD5_DIGEST_LENGTH];
    BYTE digest2[CC_MD5_DIGEST_LENGTH];

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest1, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    LogDigest(singleLine, digest1);

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest2, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    LogDigest(singleLine, digest2);

    ASSERT_TRUE_MSG(equalsDigest(digest1, digest2), "FAILED: same data should yield same result");
}

TEST(CommonCrypto, MultipleUpdatesYieldsSameResult) {
    CC_MD5_CTX ctx;
    BYTE digest1[CC_MD5_DIGEST_LENGTH];
    BYTE digest2[CC_MD5_DIGEST_LENGTH];

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest1, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    LogDigest(singleLine, digest1);

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, multiLine1, _countof(multiLine1) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, multiLine2, _countof(multiLine2) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, multiLine3, _countof(multiLine3) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest2, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    LogDigest("(Multiline digest)", digest2);

    ASSERT_TRUE_MSG(equalsDigest(digest1, digest2), "FAILED: multiple updates using same data should yield same result");
}

TEST(CommonCrypto, TestCC_MD5) {
    BYTE digest[CC_MD5_DIGEST_LENGTH];

    ASSERT_EQ_MSG(CC_MD5(singleLine, _countof(singleLine) - 1, digest), digest, "FAILED: CC_MD5 incorrect value");
    LogDigest(singleLine, digest);
}
