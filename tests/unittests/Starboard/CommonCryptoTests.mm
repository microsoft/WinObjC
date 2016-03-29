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
#include <CommonCrypto\CommonCrypto.h>
#include <string>
#include "ByteUtils.h"

static const char singleLine[] = "Hello Project Islandwood,  a.k.a. Windows Bridge for iOS!";
static const char multiLine1[] = "Hello ";
static const char multiLine2[] = "Project Islandwood,  ";
static const char multiLine3[] = "a.k.a. Windows Bridge for iOS!";

static const char secret[] = "secret!";

/* CommonDigest test helpers */

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

void _sameDataYieldsSameDigest(int (*init)(CC_Digest_State**),
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

void _multipleUpdatesYieldsSameDigest(int (*init)(CC_Digest_State**),
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

void _oneShotYieldsSameDigestAsUpdate(int (*init)(CC_Digest_State**),
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

/* CommonDigest tests */

TEST(CommonDigest, Sanity) {
    _sanity(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2_DIGEST_LENGTH);
    _sanity(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4_DIGEST_LENGTH);
    _sanity(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5_DIGEST_LENGTH);
    _sanity(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1_DIGEST_LENGTH);
    _sanity(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256_DIGEST_LENGTH);
    _sanity(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384_DIGEST_LENGTH);
    _sanity(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512_DIGEST_LENGTH);
}

TEST(CommonDigest, SameDataYieldsSameResult) {
    _sameDataYieldsSameDigest(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2_DIGEST_LENGTH);
    _sameDataYieldsSameDigest(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4_DIGEST_LENGTH);
    _sameDataYieldsSameDigest(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5_DIGEST_LENGTH);
    _sameDataYieldsSameDigest(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1_DIGEST_LENGTH);
    _sameDataYieldsSameDigest(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256_DIGEST_LENGTH);
    _sameDataYieldsSameDigest(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384_DIGEST_LENGTH);
    _sameDataYieldsSameDigest(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512_DIGEST_LENGTH);
}

TEST(CommonDigest, MultipleUpdatesYieldsSameResult) {
    _multipleUpdatesYieldsSameDigest(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512_DIGEST_LENGTH);
}

TEST(CommonDigest, OneShotDigest) {
    _oneShotYieldsSameDigestAsUpdate(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2, CC_MD2_DIGEST_LENGTH);
    _oneShotYieldsSameDigestAsUpdate(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4, CC_MD4_DIGEST_LENGTH);
    _oneShotYieldsSameDigestAsUpdate(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5, CC_MD5_DIGEST_LENGTH);
    _oneShotYieldsSameDigestAsUpdate(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1, CC_SHA1_DIGEST_LENGTH);
    _oneShotYieldsSameDigestAsUpdate(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256, CC_SHA256_DIGEST_LENGTH);
    _oneShotYieldsSameDigestAsUpdate(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384, CC_SHA384_DIGEST_LENGTH);
    _oneShotYieldsSameDigestAsUpdate(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512, CC_SHA512_DIGEST_LENGTH);
}

/* CommonHMAC helpers */

void _sameDataYieldsSameHash(CCHmacAlgorithm algorithm, unsigned outputLength) {
    CC_Hmac_State* ctx;
    BYTE* hash1 = new BYTE[outputLength];
    BYTE* hash2 = new BYTE[outputLength];

    CCHmacInit(&ctx, algorithm, secret, _countof(secret) - 1);
    CCHmacUpdate(&ctx, singleLine, _countof(singleLine) - 1);
    CCHmacFinal(&ctx, hash1);
    logBytes(singleLine, hash1, outputLength);

    CCHmacInit(&ctx, algorithm, secret, _countof(secret) - 1);
    CCHmacUpdate(&ctx, singleLine, _countof(singleLine) - 1);
    CCHmacFinal(&ctx, hash2);
    logBytes(singleLine, hash2, outputLength);

    ASSERT_TRUE_MSG(equalsBytes(hash1, hash2, outputLength), "FAILED: same data should yield same result");
    delete [] hash1;
    delete [] hash2;
}

void _multipleUpdatesYieldsSameDigest(CCHmacAlgorithm algorithm, unsigned digestLength) {
    CC_Hmac_State* ctx;
    BYTE* hash1 = new BYTE[digestLength];
    BYTE* hash2 = new BYTE[digestLength];

    CCHmacInit(&ctx, algorithm, secret, _countof(secret) - 1);
    CCHmacUpdate(&ctx, singleLine, _countof(singleLine) - 1);
    CCHmacFinal(&ctx, hash1);
    logBytes(singleLine, hash1, digestLength);

    CCHmacInit(&ctx, algorithm, secret, _countof(secret) - 1);
    CCHmacUpdate(&ctx, multiLine1, _countof(multiLine1) - 1);
    CCHmacUpdate(&ctx, multiLine2, _countof(multiLine2) - 1);
    CCHmacUpdate(&ctx, multiLine3, _countof(multiLine3) - 1);
    CCHmacFinal(&ctx, hash2);
    logBytes(singleLine, hash2, digestLength);

    ASSERT_TRUE_MSG(equalsBytes(hash1, hash2, digestLength), "FAILED: multiple updates using same data should yield same result");
    delete [] hash1;
    delete [] hash2;
}

/* CommonHMAC tests */

TEST(CommonHMAC, OneShotSanity) {
    unsigned hashLength = CC_SHA256_DIGEST_LENGTH;
    CC_Hmac_State* ctx;
    BYTE* digest1 = new BYTE[hashLength];
    CCHmac(kCCHmacAlgSHA256, secret, _countof(secret) - 1, singleLine, _countof(singleLine) - 1, digest1);
    logBytes(singleLine, digest1, hashLength);

    delete [] digest1;
}

TEST(CommonHMAC, SameDataYieldsSameResult) {
    _sameDataYieldsSameHash(kCCHmacAlgSHA1, CC_SHA1_DIGEST_LENGTH);
    _sameDataYieldsSameHash(kCCHmacAlgMD5, CC_MD5_DIGEST_LENGTH);
    _sameDataYieldsSameHash(kCCHmacAlgSHA256, CC_SHA256_DIGEST_LENGTH);
    _sameDataYieldsSameHash(kCCHmacAlgSHA384, CC_SHA384_DIGEST_LENGTH);
    _sameDataYieldsSameHash(kCCHmacAlgSHA512, CC_SHA512_DIGEST_LENGTH);
}

TEST(CommonHMAC, MultipleUpdatesYieldsSameResult) {
    _multipleUpdatesYieldsSameDigest(kCCHmacAlgSHA1, CC_SHA1_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(kCCHmacAlgMD5, CC_MD5_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(kCCHmacAlgSHA256, CC_SHA256_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(kCCHmacAlgSHA384, CC_SHA384_DIGEST_LENGTH);
    _multipleUpdatesYieldsSameDigest(kCCHmacAlgSHA512, CC_SHA512_DIGEST_LENGTH);
}