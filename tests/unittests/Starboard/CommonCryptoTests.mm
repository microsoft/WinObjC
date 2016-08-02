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
#include <windows.h>
#include <CommonCrypto/CommonCrypto.h>
#include <string>
#include <vector>
#include "ByteUtils.h"

static const char singleLine[] = "Hello Project Islandwood,  a.k.a. Windows Bridge for iOS!";
static const char multiLine1[] = "Hello ";
static const char multiLine2[] = "Project Islandwood,  ";
static const char multiLine3[] = "a.k.a. Windows Bridge for iOS!";

static const char secret[] = "secret!";
static const char secret2[] = "secret2!secret2!";
static const char longKey[] =
    "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678";

/* CommonDigest Tests */

void _sanity(int (*init)(CC_Digest_State**),
             int (*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
             int (*final)(unsigned char* digest, CC_Digest_State** ctx),
             unsigned digestLength) {
    CC_Digest_State* ctx;
    std::vector<unsigned char> digest(digestLength);

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest.data(), &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest.data(), digestLength);
}

void _sameDataYieldsSameDigest(int (*init)(CC_Digest_State**),
                               int (*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
                               int (*final)(unsigned char* digest, CC_Digest_State** ctx),
                               unsigned digestLength) {
    CC_Digest_State* ctx;
    std::vector<unsigned char> digest1(digestLength);
    std::vector<unsigned char> digest2(digestLength);

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest1.data(), &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest1.data(), digestLength);

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest2.data(), &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest2.data(), digestLength);

    ASSERT_TRUE_MSG(equalsBytes(digest1.data(), digest2.data(), digestLength), "FAILED: same data should yield same result");
}

void _multipleUpdatesYieldsSameDigest(int (*init)(CC_Digest_State**),
                                      int (*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
                                      int (*final)(unsigned char* digest, CC_Digest_State** ctx),
                                      unsigned digestLength) {
    CC_Digest_State* ctx;
    std::vector<unsigned char> digest1(digestLength);
    std::vector<unsigned char> digest2(digestLength);

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest1.data(), &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest1.data(), digestLength);

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, multiLine1, _countof(multiLine1) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, multiLine2, _countof(multiLine2) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, multiLine3, _countof(multiLine3) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest2.data(), &ctx), 1, "FAILED: final returned incorrect value");
    logBytes("(Multiline digest)", digest2.data(), digestLength);

    ASSERT_TRUE_MSG(equalsBytes(digest1.data(), digest2.data(), digestLength),
                    "FAILED: multiple updates using same data should yield same result");
}

class DigestTest : public ::testing::TestWithParam<::testing::tuple<int (*)(CC_Digest_State**),
                                                                    int (*)(CC_Digest_State** ctx, const void* data, CC_LONG len),
                                                                    int (*)(unsigned char* digest, CC_Digest_State** ctx),
                                                                    unsigned>> {};

TEST_P(DigestTest, Sanity) {
    _sanity(::testing::get<0>(GetParam()), ::testing::get<1>(GetParam()), ::testing::get<2>(GetParam()), ::testing::get<3>(GetParam()));
}

TEST_P(DigestTest, SameDataYieldsSameDigest) {
    _sameDataYieldsSameDigest(::testing::get<0>(GetParam()),
                              ::testing::get<1>(GetParam()),
                              ::testing::get<2>(GetParam()),
                              ::testing::get<3>(GetParam()));
}

TEST_P(DigestTest, MultipleUpdatesYieldsSameDigest) {
    _sameDataYieldsSameDigest(::testing::get<0>(GetParam()),
                              ::testing::get<1>(GetParam()),
                              ::testing::get<2>(GetParam()),
                              ::testing::get<3>(GetParam()));
}

INSTANTIATE_TEST_CASE_P(
    CommonDigest,
    DigestTest,
    ::testing::Values(::testing::make_tuple(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512_DIGEST_LENGTH)));

void _oneShotYieldsSameDigestAsUpdate(int (*init)(CC_Digest_State**),
                                      int (*update)(CC_Digest_State** ctx, const void* data, CC_LONG len),
                                      int (*final)(unsigned char* digest, CC_Digest_State** ctx),
                                      unsigned char* (*oneShot)(const void* data, CC_LONG len, unsigned char* md),
                                      unsigned digestLength) {
    CC_Digest_State* ctx;
    std::vector<unsigned char> digest1(digestLength);
    std::vector<unsigned char> digest2(digestLength);

    ASSERT_EQ_MSG(init(&ctx), 1, "FAILED: init returned incorrect value");
    ASSERT_EQ_MSG(update(&ctx, singleLine, _countof(singleLine) - 1), 1, "FAILURE: update returned incorrect value");
    ASSERT_EQ_MSG(final(digest1.data(), &ctx), 1, "FAILED: final returned incorrect value");
    logBytes(singleLine, digest1.data(), digestLength);

    ASSERT_EQ_MSG(oneShot(singleLine, _countof(singleLine) - 1, digest2.data()), digest2.data(), "FAILED: oneShot incorrect value");
    logBytes(singleLine, digest2.data(), digestLength);

    ASSERT_TRUE_MSG(equalsBytes(digest1.data(), digest2.data(), digestLength), "FAILED: one shot should yield same result");
}

class DigestTest2 : public ::testing::TestWithParam<::testing::tuple<int (*)(CC_Digest_State**),
                                                                     int (*)(CC_Digest_State** ctx, const void* data, CC_LONG len),
                                                                     int (*)(unsigned char* digest, CC_Digest_State** ctx),
                                                                     unsigned char* (*)(const void*, CC_LONG, unsigned char*),
                                                                     unsigned>> {};

TEST_P(DigestTest2, OneShotYieldsSameDigestAsUpdate) {
    _oneShotYieldsSameDigestAsUpdate(::testing::get<0>(GetParam()),
                                     ::testing::get<1>(GetParam()),
                                     ::testing::get<2>(GetParam()),
                                     ::testing::get<3>(GetParam()),
                                     ::testing::get<4>(GetParam()));
}

INSTANTIATE_TEST_CASE_P(
    CommonDigest,
    DigestTest2,
    ::testing::Values(::testing::make_tuple(CC_MD2_Init, CC_MD2_Update, CC_MD2_Final, CC_MD2, CC_MD2_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_MD4_Init, CC_MD4_Update, CC_MD4_Final, CC_MD4, CC_MD4_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_MD5_Init, CC_MD5_Update, CC_MD5_Final, CC_MD5, CC_MD5_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_SHA1_Init, CC_SHA1_Update, CC_SHA1_Final, CC_SHA1, CC_SHA1_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_SHA256_Init, CC_SHA256_Update, CC_SHA256_Final, CC_SHA256, CC_SHA256_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_SHA384_Init, CC_SHA384_Update, CC_SHA384_Final, CC_SHA384, CC_SHA384_DIGEST_LENGTH),
                      ::testing::make_tuple(CC_SHA512_Init, CC_SHA512_Update, CC_SHA512_Final, CC_SHA512, CC_SHA512_DIGEST_LENGTH)));

/* CommonHMAC tests */

class HmacTest : public ::testing::TestWithParam<::testing::tuple<CCHmacAlgorithm, unsigned>> {};

void _sameDataYieldsSameHash(CCHmacAlgorithm algorithm, unsigned outputLength) {
    CC_Hmac_State* ctx;

    std::vector<unsigned char> hash1(outputLength);
    std::vector<unsigned char> hash2(outputLength);

    CCHmacInit(&ctx, algorithm, secret, _countof(secret) - 1);
    CCHmacUpdate(&ctx, singleLine, _countof(singleLine) - 1);
    CCHmacFinal(&ctx, hash1.data());
    logBytes(singleLine, hash1.data(), outputLength);

    CCHmacInit(&ctx, algorithm, secret, _countof(secret) - 1);
    CCHmacUpdate(&ctx, singleLine, _countof(singleLine) - 1);
    CCHmacFinal(&ctx, hash2.data());
    logBytes(singleLine, hash2.data(), outputLength);

    ASSERT_TRUE_MSG(equalsBytes(hash1.data(), hash2.data(), outputLength), "FAILED: same data should yield same result");
}

void _multipleUpdatesYieldsSameHash(CCHmacAlgorithm algorithm, unsigned outputLength) {
    CC_Hmac_State* ctx;

    std::vector<unsigned char> hash1(outputLength);
    std::vector<unsigned char> hash2(outputLength);

    CCHmacInit(&ctx, algorithm, secret, _countof(secret) - 1);
    CCHmacUpdate(&ctx, singleLine, _countof(singleLine) - 1);
    CCHmacFinal(&ctx, hash1.data());
    logBytes(singleLine, hash1.data(), outputLength);

    CCHmacInit(&ctx, algorithm, secret, _countof(secret) - 1);
    CCHmacUpdate(&ctx, multiLine1, _countof(multiLine1) - 1);
    CCHmacUpdate(&ctx, multiLine2, _countof(multiLine2) - 1);
    CCHmacUpdate(&ctx, multiLine3, _countof(multiLine3) - 1);
    CCHmacFinal(&ctx, hash2.data());
    logBytes(singleLine, hash2.data(), outputLength);

    ASSERT_TRUE_MSG(equalsBytes(hash1.data(), hash2.data(), outputLength),
                    "FAILED: multiple updates using same data should yield same result");
}

TEST_P(HmacTest, SameDataYieldsSameHash) {
    _sameDataYieldsSameHash(::testing::get<0>(GetParam()), ::testing::get<1>(GetParam()));
}

TEST_P(HmacTest, MultipleUpdatesYieldsSameHash) {
    _multipleUpdatesYieldsSameHash(::testing::get<0>(GetParam()), ::testing::get<1>(GetParam()));
}

INSTANTIATE_TEST_CASE_P(CommonHmac,
                        HmacTest,
                        ::testing::Values(::testing::make_tuple(kCCHmacAlgSHA1, CC_SHA1_DIGEST_LENGTH),
                                          ::testing::make_tuple(kCCHmacAlgMD5, CC_MD5_DIGEST_LENGTH),
                                          ::testing::make_tuple(kCCHmacAlgSHA256, CC_SHA256_DIGEST_LENGTH),
                                          ::testing::make_tuple(kCCHmacAlgSHA384, CC_SHA384_DIGEST_LENGTH),
                                          ::testing::make_tuple(kCCHmacAlgSHA512, CC_SHA512_DIGEST_LENGTH)));

TEST(CommonHmac, OneShotSanity) {
    unsigned hashLength = CC_SHA256_DIGEST_LENGTH;
    CC_Hmac_State* ctx;
    std::vector<unsigned char> hash1(hashLength);

    CCHmac(kCCHmacAlgSHA256, secret, _countof(secret) - 1, singleLine, _countof(singleLine) - 1, hash1.data());
    logBytes(singleLine, hash1.data(), hashLength);
}

/* CommonCryptor tests */
void _oneShotYieldsSameCrypto(CCAlgorithm algorithm,
                              CCOperation operation,
                              CCOptions options,
                              size_t keyLength,
                              size_t update1Size,
                              size_t update2Size,
                              size_t outputSize,
                              const char* iv) {
    CCCryptorRef ctx;

    CCCryptorStatus status;
    status = CCCryptorCreate(operation, algorithm, options, longKey, keyLength, iv, &ctx);
    ASSERT_EQ(kCCSuccess, status);

    size_t outputLength = CCCryptorGetOutputLength(ctx, update1Size + update2Size, true);
    ASSERT_EQ(outputSize, outputLength);

    std::vector<unsigned char> output1(outputLength);
    std::vector<unsigned char> output2(outputLength);

    size_t oneShotBytesMoved;
    status = CCCrypt(operation,
                     algorithm,
                     options,
                     longKey,
                     keyLength,
                     iv,
                     singleLine,
                     update1Size + update2Size,
                     output1.data(),
                     outputSize,
                     &oneShotBytesMoved);
    ASSERT_EQ(kCCSuccess, status);
    ASSERT_EQ(outputLength, oneShotBytesMoved);
    logBytes(singleLine, output1.data(), outputLength);

    size_t updateBytesMoved1;
    size_t updateBytesMoved2;
    size_t finalBytesMoved;
    status = CCCryptorUpdate(ctx, singleLine, update1Size, output2.data(), outputLength, &updateBytesMoved1);
    ASSERT_EQ(kCCSuccess, status);
    status = CCCryptorUpdate(ctx,
                             singleLine + update1Size,
                             update2Size,
                             output2.data() + updateBytesMoved1,
                             outputLength - updateBytesMoved1,
                             &updateBytesMoved2);
    ASSERT_EQ(kCCSuccess, status);
    status = CCCryptorFinal(ctx,
                            output2.data() + updateBytesMoved1 + updateBytesMoved2,
                            outputLength - updateBytesMoved1 - updateBytesMoved2,
                            &finalBytesMoved);
    ASSERT_EQ(kCCSuccess, status);
    ASSERT_EQ(outputLength, updateBytesMoved1 + updateBytesMoved2 + finalBytesMoved);
    logBytes(singleLine, output2.data(), outputLength);

    ASSERT_TRUE_MSG(equalsBytes(output1.data(), output2.data(), outputLength), "FAILED: one shot using same data should yield same result");
    ASSERT_EQ(kCCSuccess, CCCryptorRelease(ctx));
}

void _multipleUpdatesYieldsSameCrypto(CCAlgorithm algorithm,
                                      CCOperation operation,
                                      CCOptions options,
                                      size_t keyLength,
                                      size_t update1Size,
                                      size_t update2Size,
                                      size_t outputSize,
                                      const char* iv) {
    CCCryptorRef ctx;

    CCCryptorStatus status;
    status = CCCryptorCreate(operation, algorithm, options, longKey, keyLength, nullptr, &ctx);
    ASSERT_EQ(kCCSuccess, status);

    size_t outputLength = CCCryptorGetOutputLength(ctx, update1Size + update2Size, true);

    std::vector<unsigned char> output1(outputLength);
    std::vector<unsigned char> output2(outputLength);

    size_t updateBytesMoved1;
    status = CCCryptorUpdate(ctx, singleLine, update1Size + update2Size, output1.data(), outputLength, &updateBytesMoved1);
    ASSERT_EQ(kCCSuccess, status);
    size_t finalBytesMoved;
    status = CCCryptorFinal(ctx, output1.data() + updateBytesMoved1, outputLength - updateBytesMoved1, &finalBytesMoved);
    ASSERT_EQ(kCCSuccess, status);
    ASSERT_EQ(outputLength, updateBytesMoved1 + finalBytesMoved);
    logBytes(singleLine, output1.data(), outputLength);

    status = CCCryptorReset(ctx, nullptr);
    ASSERT_EQ(kCCSuccess, status);

    size_t updateBytesMoved2;
    status = CCCryptorUpdate(ctx, singleLine, update1Size, output2.data(), outputLength, &updateBytesMoved1);
    ASSERT_EQ(kCCSuccess, status);
    status = CCCryptorUpdate(ctx,
                             singleLine + update1Size,
                             update2Size,
                             output2.data() + updateBytesMoved1,
                             outputLength - updateBytesMoved1,
                             &updateBytesMoved2);
    ASSERT_EQ(kCCSuccess, status);
    status = CCCryptorFinal(ctx,
                            output2.data() + updateBytesMoved1 + updateBytesMoved2,
                            outputLength - updateBytesMoved1 - updateBytesMoved2,
                            &finalBytesMoved);
    ASSERT_EQ(kCCSuccess, status);
    ASSERT_EQ(outputLength, updateBytesMoved1 + updateBytesMoved2 + finalBytesMoved);
    logBytes(singleLine, output2.data(), outputLength);

    ASSERT_TRUE_MSG(equalsBytes(output1.data(), output2.data(), outputLength),
                    "FAILED: multiple updates using same data should yield same result");
    ASSERT_EQ(kCCSuccess, CCCryptorRelease(ctx));
}

void _encryptDecryptSameAsOriginal(
    CCAlgorithm algorithm, CCOptions options, size_t keyLength, size_t update1Size, size_t update2Size, size_t outputSize, const char* iv) {
    CCCryptorRef ctx;

    CCCryptorStatus status;
    status = CCCryptorCreate(kCCEncrypt, algorithm, options, longKey, keyLength, iv, &ctx);
    ASSERT_EQ(kCCSuccess, status);

    size_t outputLength = CCCryptorGetOutputLength(ctx, update1Size + update2Size, true);
    ASSERT_EQ(outputSize, outputLength);

    std::vector<unsigned char> output1(outputLength);
    std::vector<unsigned char> output2(outputLength);
    ASSERT_EQ(kCCSuccess, CCCryptorRelease(ctx));

    size_t oneShotBytesEncrypted;
    status = CCCrypt(kCCEncrypt,
                     algorithm,
                     options,
                     longKey,
                     keyLength,
                     iv,
                     singleLine,
                     update1Size + update2Size,
                     output1.data(),
                     outputSize,
                     &oneShotBytesEncrypted);
    ASSERT_EQ(kCCSuccess, status);
    ASSERT_EQ(outputLength, oneShotBytesEncrypted);
    logBytes(singleLine, output1.data(), outputLength);

    size_t oneShotBytesDecrypted;
    status = CCCrypt(kCCDecrypt,
                     algorithm,
                     options,
                     longKey,
                     keyLength,
                     iv,
                     output1.data(),
                     outputSize,
                     output2.data(),
                     outputSize,
                     &oneShotBytesDecrypted);
    ASSERT_EQ(kCCSuccess, status);
    ASSERT_EQ(outputLength, oneShotBytesDecrypted);
    logBytes(singleLine, output2.data(), update1Size + update2Size);

    ASSERT_TRUE_MSG(equalsBytes((BYTE*)singleLine, output2.data(), update1Size + update2Size),
                    "FAILED: Encrypt followed by Decrypt should equal original");
}

class CryptorTest
    : public ::testing::TestWithParam<::testing::tuple<CCAlgorithm, CCOperation, CCOptions, size_t, size_t, size_t, size_t, const char*>> {
};

TEST_P(CryptorTest, OneShotYieldsSameCrypto) {
    _oneShotYieldsSameCrypto(::testing::get<0>(GetParam()),
                             ::testing::get<1>(GetParam()),
                             ::testing::get<2>(GetParam()),
                             ::testing::get<3>(GetParam()),
                             ::testing::get<4>(GetParam()),
                             ::testing::get<5>(GetParam()),
                             ::testing::get<6>(GetParam()),
                             ::testing::get<7>(GetParam()));
}

TEST_P(CryptorTest, MultipleUpdatesYieldsSameCrypto) {
    _multipleUpdatesYieldsSameCrypto(::testing::get<0>(GetParam()),
                                     ::testing::get<1>(GetParam()),
                                     ::testing::get<2>(GetParam()),
                                     ::testing::get<3>(GetParam()),
                                     ::testing::get<4>(GetParam()),
                                     ::testing::get<5>(GetParam()),
                                     ::testing::get<6>(GetParam()),
                                     ::testing::get<7>(GetParam()));
}

TEST_P(CryptorTest, EncryptDecryptSameAsOriginal) {
    _encryptDecryptSameAsOriginal(::testing::get<0>(GetParam()),
                                  ::testing::get<2>(GetParam()),
                                  ::testing::get<3>(GetParam()),
                                  ::testing::get<4>(GetParam()),
                                  ::testing::get<5>(GetParam()),
                                  ::testing::get<6>(GetParam()),
                                  ::testing::get<7>(GetParam()));
}

// clang-format off
INSTANTIATE_TEST_CASE_P(CommonCryptor,
                        CryptorTest,
                        ::testing::Values(
                            ::testing::make_tuple(kCCAlgorithmDES, kCCEncrypt, 0, kCCKeySizeDES, kCCBlockSizeDES, kCCBlockSizeDES, kCCBlockSizeDES * 2, secret2),
                            ::testing::make_tuple(kCCAlgorithmDES, kCCEncrypt, 0, kCCKeySizeDES, kCCBlockSizeDES - 1, kCCBlockSizeDES + 1, kCCBlockSizeDES * 2, nullptr),
                            ::testing::make_tuple(kCCAlgorithmDES, kCCEncrypt, kCCOptionECBMode, kCCKeySizeDES, kCCBlockSizeDES, kCCBlockSizeDES, kCCBlockSizeDES * 2, nullptr),
                            ::testing::make_tuple(kCCAlgorithmDES, kCCEncrypt, kCCOptionPKCS7Padding, kCCKeySizeDES, kCCBlockSizeDES - 1, kCCBlockSizeDES, kCCBlockSizeDES * 2, secret2),
                            ::testing::make_tuple(kCCAlgorithmDES, kCCEncrypt, kCCOptionECBMode | kCCOptionPKCS7Padding, kCCKeySizeDES, kCCBlockSizeDES, kCCBlockSizeDES + 1, kCCBlockSizeDES * 3, nullptr),
                            ::testing::make_tuple(kCCAlgorithm3DES, kCCEncrypt, 0, kCCKeySize3DES, kCCBlockSize3DES, kCCBlockSize3DES, kCCBlockSize3DES * 2, nullptr),
                            ::testing::make_tuple(kCCAlgorithm3DES, kCCEncrypt, 0, kCCKeySize3DES, kCCBlockSize3DES - 1, kCCBlockSize3DES + 1, kCCBlockSize3DES * 2, secret2),
                            ::testing::make_tuple(kCCAlgorithm3DES, kCCEncrypt, kCCOptionECBMode, kCCKeySize3DES, kCCBlockSize3DES, kCCBlockSize3DES, kCCBlockSize3DES * 2, nullptr),
                            ::testing::make_tuple(kCCAlgorithm3DES, kCCEncrypt, kCCOptionPKCS7Padding, kCCKeySize3DES, kCCBlockSize3DES - 1, kCCBlockSize3DES, kCCBlockSize3DES * 2, secret2),
                            ::testing::make_tuple(kCCAlgorithm3DES, kCCEncrypt, kCCOptionECBMode | kCCOptionPKCS7Padding, kCCKeySize3DES, kCCBlockSize3DES, kCCBlockSize3DES + 1, kCCBlockSize3DES * 3, nullptr),
                            ::testing::make_tuple(kCCAlgorithmAES128, kCCEncrypt, 0, kCCKeySizeAES128, kCCBlockSizeAES128, kCCBlockSizeAES128, kCCBlockSizeAES128 * 2, secret2),
                            ::testing::make_tuple(kCCAlgorithmAES128, kCCEncrypt, 0, kCCKeySizeAES128, kCCBlockSizeAES128 - 1, kCCBlockSizeAES128 + 1, kCCBlockSizeAES128 * 2, nullptr),
                            ::testing::make_tuple(kCCAlgorithmAES128, kCCEncrypt, kCCOptionECBMode, kCCKeySizeAES128, kCCBlockSizeAES128, kCCBlockSizeAES128, kCCBlockSizeAES128 * 2, nullptr),
                            ::testing::make_tuple(kCCAlgorithmAES128, kCCEncrypt, kCCOptionPKCS7Padding, kCCKeySizeAES128, kCCBlockSizeAES128 - 1, kCCBlockSizeAES128, kCCBlockSizeAES128 * 2, secret2),
                            ::testing::make_tuple(kCCAlgorithmAES128, kCCEncrypt, kCCOptionECBMode | kCCOptionPKCS7Padding, kCCKeySizeAES128, kCCBlockSizeAES128, kCCBlockSizeAES128 + 1, kCCBlockSizeAES128 * 3, nullptr),
                            ::testing::make_tuple(kCCAlgorithmRC2, kCCEncrypt, 0, kCCKeySizeMinRC2, kCCBlockSizeRC2, kCCBlockSizeRC2, kCCBlockSizeRC2 * 2, secret2),
                            ::testing::make_tuple(kCCAlgorithmRC2, kCCEncrypt, 0, kCCKeySizeMaxRC2, kCCBlockSizeRC2 - 1, kCCBlockSizeRC2 + 1, kCCBlockSizeRC2 * 2, secret2),
                            ::testing::make_tuple(kCCAlgorithmRC2, kCCEncrypt, kCCOptionECBMode, kCCKeySizeMinRC2, kCCBlockSizeRC2, kCCBlockSizeRC2, kCCBlockSizeRC2 * 2, nullptr),
                            ::testing::make_tuple(kCCAlgorithmRC2, kCCEncrypt, kCCOptionPKCS7Padding, kCCKeySizeMaxRC2, kCCBlockSizeRC2 - 1, kCCBlockSizeRC2, kCCBlockSizeRC2 * 2, nullptr),
                            ::testing::make_tuple(kCCAlgorithmRC2, kCCEncrypt, kCCOptionECBMode | kCCOptionPKCS7Padding, kCCKeySizeMinRC2, kCCBlockSizeRC2, kCCBlockSizeRC2 + 1, kCCBlockSizeRC2 * 3, nullptr),
                            ::testing::make_tuple(kCCAlgorithmRC4, kCCEncrypt, 0, kCCKeySizeMinRC4, 2, 5, 7, nullptr),
                            ::testing::make_tuple(kCCAlgorithmRC4, kCCEncrypt, 0, kCCKeySizeMaxRC4, 0, 14, 14, nullptr)));
// clang-format on

TEST(CommonCryptor, Sanity) {
    unsigned aesBlockLength = 16;
    CCCryptorRef ctx;
    std::vector<unsigned char> key(kCCKeySizeAES128);
    memcpy_s(key.data(), kCCKeySizeAES128, (unsigned char*)"abcdefghijklmnop", kCCKeySizeAES128);
    CCCryptorCreate(kCCEncrypt, kCCAlgorithmAES, 0, key.data(), kCCKeySizeAES128, nullptr, &ctx);
    std::vector<unsigned char> output(aesBlockLength);
    size_t datamoved;
    CCCryptorUpdate(ctx, multiLine2, aesBlockLength, output.data(), aesBlockLength, &datamoved);
    logBytes(multiLine2, output.data(), aesBlockLength);
    ASSERT_EQ(16, datamoved);
    CCCryptorRelease(ctx);
}