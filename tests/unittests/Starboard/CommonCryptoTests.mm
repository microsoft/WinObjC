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
#include "ByteUtils.h"

static const char singleLine[] = "Hello Project Islandwood,  a.k.a. Windows Bridge for iOS!";
static const char multiLine1[] = "Hello ";
static const char multiLine2[] = "Project Islandwood,  ";
static const char multiLine3[] = "a.k.a. Windows Bridge for iOS!";

void _sanity(int (*init)(CC_Digest_State**),
            int (*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
            int (*final)(unsigned char* digest, CC_Digest_State** ctx),
            unsigned digestLength) {
    CC_Digest_State* ctx;
    BYTE* digest = new BYTE[digestLength];

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest, &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest, digestLength);
    delete [] digest;
}

void _sameDataYieldsSameResult(int (*init)(CC_Digest_State**),
            int (*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
            int (*final)(unsigned char* digest, CC_Digest_State** ctx),
            unsigned digestLength) {
    CC_Digest_State* ctx;
    BYTE* digest1 = new BYTE[digestLength];
    BYTE* digest2 = new BYTE[digestLength];

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest1, &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest1, digestLength);

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest2, &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest2, digestLength);

    ASSERT_TRUE_MSG(equalsBytes(digest1, digest2, digestLength), "FAILED: same data should yield same result");
    delete [] digest1;
    delete [] digest2;
}

void _multipleUpdatesYieldsSameResult(int (*init)(CC_Digest_State**),
            int (*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
            int (*final)(unsigned char* digest, CC_Digest_State** ctx),
            unsigned digestLength) {
    CC_Digest_State* ctx;
    BYTE* digest1 = new BYTE[digestLength];
    BYTE* digest2 = new BYTE[digestLength];

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest1, &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest1, digestLength);

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, multiLine1, _countof(multiLine1) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, multiLine2, _countof(multiLine2) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, multiLine3, _countof(multiLine3) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest2, &ctx), 1, "FAILED: final returned incorrect value");
    logBytes("(Multiline digest)", digest2, digestLength);

    ASSERT_TRUE_MSG(equalsBytes(digest1, digest2, digestLength), "FAILED: multiple updates using same data should yield same result");
    delete [] digest1;
    delete [] digest2;
}

void _oneShotYieldsSameResultAsUpdate(int (*init)(CC_Digest_State**),
            int (*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
            int (*final)(unsigned char* digest, CC_Digest_State** ctx),
            unsigned char* (*oneShot)(const void* data, CC_LONG len, unsigned char* md),
            unsigned digestLength) {
    CC_Digest_State* ctx;
    BYTE* digest1 = new BYTE[digestLength];
    BYTE* digest2 = new BYTE[digestLength];

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest1, &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest1, digestLength);

    ASSERT_EQ_MSG(oneShot(singleLine, _countof(singleLine) - 1, digest2), digest2, "FAILED: oneShot incorrect value");
    logBytes(singleLine, digest2, digestLength);

    ASSERT_TRUE_MSG(equalsBytes(digest1, digest2, digestLength), "FAILED: one shot should yield same result");
    delete [] digest1;
    delete [] digest2;
}

TEST(CommonCrypto, Sanity) {
    _sanity(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2_DIGEST_LENGTH);
    _sanity(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4_DIGEST_LENGTH);
    _sanity(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5_DIGEST_LENGTH);
    _sanity(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1_DIGEST_LENGTH);
    _sanity(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256_DIGEST_LENGTH);
    _sanity(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384_DIGEST_LENGTH);
    _sanity(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512_DIGEST_LENGTH);
}

TEST(CommonCrypto, SameDataYieldsSameResult) {
    _sameDataYieldsSameResult(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2_DIGEST_LENGTH);
    _sameDataYieldsSameResult(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4_DIGEST_LENGTH);
    _sameDataYieldsSameResult(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5_DIGEST_LENGTH);
    _sameDataYieldsSameResult(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1_DIGEST_LENGTH);
    _sameDataYieldsSameResult(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256_DIGEST_LENGTH);
    _sameDataYieldsSameResult(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384_DIGEST_LENGTH);
    _sameDataYieldsSameResult(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512_DIGEST_LENGTH);
}

TEST(CommonCrypto, MultipleUpdatesYieldsSameResult) {
    _multipleUpdatesYieldsSameResult(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameResult(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameResult(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameResult(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameResult(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameResult(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameResult(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512_DIGEST_LENGTH);
}

TEST(CommonCrypto, OneShotDigest) {
    _oneShotYieldsSameResultAsUpdate(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2, CC_MD2_DIGEST_LENGTH);
    _oneShotYieldsSameResultAsUpdate(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4, CC_MD4_DIGEST_LENGTH);
    _oneShotYieldsSameResultAsUpdate(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5, CC_MD5_DIGEST_LENGTH);
    _oneShotYieldsSameResultAsUpdate(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1, CC_SHA1_DIGEST_LENGTH);
    _oneShotYieldsSameResultAsUpdate(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256, CC_SHA256_DIGEST_LENGTH);
    _oneShotYieldsSameResultAsUpdate(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384, CC_SHA384_DIGEST_LENGTH);
    _oneShotYieldsSameResultAsUpdate(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512, CC_SHA512_DIGEST_LENGTH);
}