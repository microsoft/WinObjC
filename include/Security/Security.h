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

// This header file is not yet implemented

#import <CoreFoundation/CFDictionary.h>

typedef struct __SecIdentity *SecIdentityRef;

typedef struct __SecTrust *SecTrustRef;

typedef const struct __SecRandom * SecRandomRef;

extern CFTypeRef kSecClassGenericPassword;

extern CFTypeRef kSecReturnData;

extern CFTypeRef kSecMatchLimitOne;

extern CFTypeRef kSecAttrService;

extern CFTypeRef kSecAttrGeneric;

extern CFTypeRef kSecAttrAccount;

extern CFTypeRef kSecAttrAccessGroup;

OSStatus SecItemCopyMatching(CFDictionaryRef query, CFTypeRef *result);

enum
{
    errSecSuccess                = 0,       /* No error. */
    errSecItemNotFound           = -25300,      /* The specified item could not be found in the keychain. */
};

extern CFTypeRef kSecValueData;

OSStatus SecItemUpdate(CFDictionaryRef query,CFDictionaryRef attributesToUpdate);

extern CFTypeRef kSecClass;

extern CFTypeRef kSecMatchLimit;

extern CFTypeRef kSecAttrAccessibleAfterFirstUnlock;

OSStatus SecItemAdd(CFDictionaryRef attributes, CFTypeRef *result);

OSStatus SecItemDelete(CFDictionaryRef query);

extern CFTypeRef kSecReturnAttributes;

extern CFTypeRef kSecMatchLimitAll;

extern CFTypeRef kSecMatchLimit;

extern CFTypeRef kSecAttrAccessible;