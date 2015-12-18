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

#ifndef __COMMON_DIGEST_H
#define __COMMON_DIGEST_H

// This header file is not yet implemented
typedef struct CC_MD5_State* CC_MD5_CTX;

#ifdef __cplusplus
extern "C" {
#endif

#define CC_MD5_DIGEST_LENGTH 16
typedef unsigned long CC_LONG;

unsigned char* CC_MD5(const void*, CC_LONG length, unsigned char*);

int CC_MD5_Init(CC_MD5_CTX* ctx);
int CC_MD5_Update(CC_MD5_CTX* ctx, const void* data, unsigned int len);
int CC_MD5_Final(unsigned char* out, CC_MD5_CTX* ctx);

#ifdef __cplusplus
}
#endif
#endif