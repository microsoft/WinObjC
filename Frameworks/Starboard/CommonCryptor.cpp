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

#include <CommonCrypto\CommonCryptor.h>
#include <StubReturn.h>

/**
@Status Stub
*/
int32_t CCCrypt(uint32_t op, /* kCCEncrypt, etc. */
    uint32_t alg, /* kCCAlgorithmAES128, etc. */
    uint32_t options, /* kCCOptionPKCS7Padding, etc. */
    const void* key,
    size_t keyLength,
    const void* iv, /* optional initialization vector */
    const void* dataIn, /* optional per op and alg */
    size_t dataInLength,
    void* dataOut, /* data RETURNED here */
    size_t dataOutAvailable,
    size_t* dataOutMoved) {
    UNIMPLEMENTED();
    return StubReturn();
}