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
#include "byteutils.h"

static const char singleLine[] = "Hello Project Islandwood,  a.k.a. Windows Bridge for iOS!";
static const char multiLine1[] = "Hello ";
static const char multiLine2[] = "Project Islandwood,  ";
static const char multiLine3[] = "a.k.a. Windows Bridge for iOS!";

TEST(CommonCrypto, Sanity) {
    CC_MD5_CTX ctx;
    BYTE digest[CC_MD5_DIGEST_LENGTH];

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    logBytes(singleLine, digest, sizeof(digest));
}

TEST(CommonCrypto, SameDataYieldsSameResult) {
    CC_MD5_CTX ctx;
    BYTE digest1[CC_MD5_DIGEST_LENGTH];
    BYTE digest2[CC_MD5_DIGEST_LENGTH];

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest1, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    logBytes(singleLine, digest1, sizeof(digest1));

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest2, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    logBytes(singleLine, digest2, sizeof(digest2));

    ASSERT_TRUE_MSG(equalsBytes(digest1, digest2, sizeof(digest1)), "FAILED: same data should yield same result");
}

TEST(CommonCrypto, MultipleUpdatesYieldsSameResult) {
    CC_MD5_CTX ctx;
    BYTE digest1[CC_MD5_DIGEST_LENGTH];
    BYTE digest2[CC_MD5_DIGEST_LENGTH];

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest1, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    logBytes(singleLine, digest1, sizeof(digest1));

    ASSERT_EQ_MSG(CC_MD5_Init(&ctx), 1, "FAILED: CC_MD5_Init returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, multiLine1, _countof(multiLine1) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, multiLine2, _countof(multiLine2) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Update(&ctx, multiLine3, _countof(multiLine3) - 1), 1, "FAILURE: CC_MD5_Update returned incorrect value");
    ASSERT_EQ_MSG(CC_MD5_Final(digest2, &ctx), 1, "FAILED: CC_MD5_Final returned incorrect value");
    logBytes("(Multiline digest)", digest2, sizeof(digest2));

    ASSERT_TRUE_MSG(equalsBytes(digest1, digest2, sizeof(digest1)), "FAILED: multiple updates using same data should yield same result");
}

TEST(CommonCrypto, TestCC_MD5) {
    BYTE digest[CC_MD5_DIGEST_LENGTH];

    ASSERT_EQ_MSG(CC_MD5(singleLine, _countof(singleLine) - 1, digest), digest, "FAILED: CC_MD5 incorrect value");
    logBytes(singleLine, digest, sizeof(digest));
}
