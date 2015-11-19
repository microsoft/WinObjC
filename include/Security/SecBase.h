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

#ifndef SECURITY_IMPEXP
#define SECURITY_IMPEXP __declspec(dllimport)
#endif

#ifndef SECURITY_EXPORT
#ifdef __cplusplus
#define SECURITY_EXPORT extern "C" SECURITY_IMPEXP
#define SECURITY_EXPORT_CLASS SECURITY_IMPEXP
#else
#define SECURITY_EXPORT extern SECURITY_IMPEXP
#define SECURITY_EXPORT_CLASS SECURITY_IMPEXP
#endif
#endif
enum {
    errSecSuccess = 0, /* No error. */
    errSecUnimplemented = -4,
    errSecParam = -50,
    errSecAllocate = -108,
    errSecNotAvailable = -25291,
    errSecAuthFailed = -25293,
    errSecDuplicateItem = -25299,
    errSecItemNotFound = -25300, /* The specified item could not be found in the keychain. */
    errSecInteractionNotAllowed = -25308,
    errSecDecode = -26274,
};
