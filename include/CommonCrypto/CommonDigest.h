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

#pragma once

#include <StarboardExport.h>
#include <StubIncludes.h>

struct CC_Digest_State;
typedef struct CC_Digest_State* CC_MD2_CTX;
typedef struct CC_Digest_State* CC_MD4_CTX;
typedef struct CC_Digest_State* CC_MD5_CTX;
typedef struct CC_Digest_State* CC_SHA1_CTX;
typedef struct CC_Digest_State* CC_SHA224_CTX;
typedef struct CC_Digest_State* CC_SHA256_CTX;
typedef struct CC_Digest_State* CC_SHA384_CTX;
typedef struct CC_Digest_State* CC_SHA512_CTX;

typedef unsigned long CC_LONG;

#define CC_MD2_DIGEST_LENGTH 16
#define CC_MD4_DIGEST_LENGTH 16
#define CC_MD5_DIGEST_LENGTH 16
#define CC_SHA1_DIGEST_LENGTH 20
#define CC_SHA224_DIGEST_LENGTH 28
#define CC_SHA256_DIGEST_LENGTH 32
#define CC_SHA384_DIGEST_LENGTH 48
#define CC_SHA512_DIGEST_LENGTH 64

SB_EXTERNC_BEGIN

int CC_MD2_Init(CC_MD2_CTX* c);
int CC_MD2_Update(CC_MD2_CTX* c, const void* data, CC_LONG len);
int CC_MD2_Final(unsigned char* md, CC_MD2_CTX* c);
unsigned char* CC_MD2(const void* data, CC_LONG len, unsigned char* md);

int CC_MD4_Init(CC_MD4_CTX* c);
int CC_MD4_Update(CC_MD4_CTX* c, const void* data, CC_LONG len);
int CC_MD4_Final(unsigned char* md, CC_MD4_CTX* c);
unsigned char* CC_MD4(const void* data, CC_LONG len, unsigned char* md);

int CC_MD5_Init(CC_MD5_CTX* ctx);
int CC_MD5_Update(CC_MD5_CTX* ctx, const void* data, CC_LONG len);
int CC_MD5_Final(unsigned char* digest, CC_MD5_CTX* ctx);
unsigned char* CC_MD5(const void* data, CC_LONG len, unsigned char* md);

int CC_SHA1_Init(CC_SHA1_CTX* ctx);
int CC_SHA1_Update(CC_SHA1_CTX* ctx, const void* data, CC_LONG len);
int CC_SHA1_Final(unsigned char* digest, CC_SHA1_CTX* ctx);
unsigned char* CC_SHA1(const void* data, CC_LONG len, unsigned char* md);

int CC_SHA224_Init(CC_SHA224_CTX* ctx) STUB_METHOD;
int CC_SHA224_Update(CC_SHA224_CTX* ctx, const void* data, CC_LONG len) STUB_METHOD;
int CC_SHA224_Final(unsigned char* digest, CC_SHA224_CTX* ctx) STUB_METHOD;
unsigned char* CC_SHA224(const void* data, CC_LONG len, unsigned char* md) STUB_METHOD;

int CC_SHA256_Init(CC_SHA256_CTX* ctx);
int CC_SHA256_Update(CC_SHA256_CTX* ctx, const void* data, CC_LONG len);
int CC_SHA256_Final(unsigned char* digest, CC_SHA256_CTX* ctx);
unsigned char* CC_SHA256(const void* data, CC_LONG len, unsigned char* md);

int CC_SHA384_Init(CC_SHA384_CTX* ctx);
int CC_SHA384_Update(CC_SHA384_CTX* ctx, const void* data, CC_LONG len);
int CC_SHA384_Final(unsigned char* digest, CC_SHA384_CTX* ctx);
unsigned char* CC_SHA384(const void* data, CC_LONG len, unsigned char* md);

int CC_SHA512_Init(CC_SHA512_CTX* ctx);
int CC_SHA512_Update(CC_SHA512_CTX* ctx, const void* data, CC_LONG len);
int CC_SHA512_Final(unsigned char* digest, CC_SHA512_CTX* ctx);
unsigned char* CC_SHA512(const void* data, CC_LONG len, unsigned char* md);

SB_EXTERNC_END