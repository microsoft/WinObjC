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

#import <Security/SecBase.h>
#import <CoreFoundation/CoreFoundation.h>
#import <CoreFoundation/CFDictionary.h>

SECURITY_EXPORT const CFStringRef kSecClass;
SECURITY_EXPORT const CFStringRef kSecClassGenericPassword;
SECURITY_EXPORT const CFStringRef kSecClassInternetPassword;
SECURITY_EXPORT const CFStringRef kSecClassCertificate;
SECURITY_EXPORT const CFStringRef kSecClassKey;
SECURITY_EXPORT const CFStringRef kSecClassIdentity;

SECURITY_EXPORT const CFStringRef kSecAttrAccessible;
SECURITY_EXPORT const CFStringRef kSecAttrAccessibleAfterFirstUnlock;
SECURITY_EXPORT const CFStringRef kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly;
SECURITY_EXPORT const CFStringRef kSecAttrAccessibleAlways;
SECURITY_EXPORT const CFStringRef kSecAttrAccessibleAlwaysThisDeviceOnly;
SECURITY_EXPORT const CFStringRef kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly;
SECURITY_EXPORT const CFStringRef kSecAttrAccessibleWhenUnlocked;
SECURITY_EXPORT const CFStringRef kSecAttrAccessibleWhenUnlockedThisDeviceOnly;

SECURITY_EXPORT const CFStringRef kSecAttrAccessGroup;
SECURITY_EXPORT const CFStringRef kSecAttrCreationDate;
SECURITY_EXPORT const CFStringRef kSecAttrModificationDate;
SECURITY_EXPORT const CFStringRef kSecAttrDescription;
SECURITY_EXPORT const CFStringRef kSecAttrComment;
SECURITY_EXPORT const CFStringRef kSecAttrCreator;
SECURITY_EXPORT const CFStringRef kSecAttrType;
SECURITY_EXPORT const CFStringRef kSecAttrLabel;
SECURITY_EXPORT const CFStringRef kSecAttrIsInvisible;
SECURITY_EXPORT const CFStringRef kSecAttrIsNegative;
SECURITY_EXPORT const CFStringRef kSecAttrAccount;
SECURITY_EXPORT const CFStringRef kSecAttrService;
SECURITY_EXPORT const CFStringRef kSecAttrGeneric;

SECURITY_EXPORT const CFStringRef kSecValueData;
SECURITY_EXPORT const CFStringRef kSecValueRef;
SECURITY_EXPORT const CFStringRef kSecValuePersistentRef;

SECURITY_EXPORT const CFStringRef kSecReturnData;
SECURITY_EXPORT const CFStringRef kSecReturnAttributes;
SECURITY_EXPORT const CFStringRef kSecReturnRef;
SECURITY_EXPORT const CFStringRef kSecReturnPersistentRef;

SECURITY_EXPORT const CFStringRef kSecUseItemList;

SECURITY_EXPORT const CFStringRef kSecMatchPolicy;
SECURITY_EXPORT const CFStringRef kSecMatchItemList;
SECURITY_EXPORT const CFStringRef kSecMatchSearchList;
SECURITY_EXPORT const CFStringRef kSecMatchIssuers;
SECURITY_EXPORT const CFStringRef kSecMatchEmailAddressIfPresent;
SECURITY_EXPORT const CFStringRef kSecMatchSubjectContains;
SECURITY_EXPORT const CFStringRef kSecMatchCaseInsensitive;
SECURITY_EXPORT const CFStringRef kSecMatchTrustedOnly;
SECURITY_EXPORT const CFStringRef kSecMatchValidOnDate;
SECURITY_EXPORT const CFStringRef kSecMatchLimit;
SECURITY_EXPORT const CFStringRef kSecMatchLimitOne;
SECURITY_EXPORT const CFStringRef kSecMatchLimitAll;

SECURITY_EXPORT OSStatus SecItemUpdate(CFDictionaryRef query, CFDictionaryRef attributesToUpdate);

SECURITY_EXPORT OSStatus SecItemAdd(CFDictionaryRef attributes, CFTypeRef* result);

SECURITY_EXPORT OSStatus SecItemDelete(CFDictionaryRef query);

SECURITY_EXPORT OSStatus SecItemCopyMatching(CFDictionaryRef query, CFTypeRef* result);