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
#include <stdint.h>

enum {
    kCCHmacAlgSHA1,
    kCCHmacAlgMD5,
    kCCHmacAlgSHA256,
    kCCHmacAlgSHA384,
    kCCHmacAlgSHA512,
    kCCHmacAlgSHA224
};

struct CC_Hmac_State;
typedef struct CC_Hmac_State* CCHmacContext;
typedef int32_t CCHmacAlgorithm;

SB_EXTERNC_BEGIN

void CCHmacInit(CCHmacContext* ctx, CCHmacAlgorithm algorithm, const void* key, size_t keyLength);
void CCHmacUpdate(CCHmacContext* ctx, const void* data, size_t dataLength);
void CCHmacFinal(CCHmacContext* ctx, void* macOut);
void CCHmac(CCHmacAlgorithm algorithm, const void* key, size_t keyLength, const void* data, size_t dataLength, void* macOut);

SB_EXTERNC_END