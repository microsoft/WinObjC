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

SECURITY_EXPORT const CFStringRef kSecImportExportPassphrase;
SECURITY_EXPORT const CFTypeRef kSecClass;
SECURITY_EXPORT const CFTypeRef kSecClassGenericPassword;
SECURITY_EXPORT const CFTypeRef kSecClassInternetPassword;
SECURITY_EXPORT const CFTypeRef kSecClassCertificate;
SECURITY_EXPORT const CFTypeRef kSecClassKey;
SECURITY_EXPORT const CFTypeRef kSecClassIdentity;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessible;
SECURITY_EXPORT const CFTypeRef kSecAttrCreationDate;
SECURITY_EXPORT const CFTypeRef kSecAttrModificationDate;
SECURITY_EXPORT const CFTypeRef kSecAttrDescription;
SECURITY_EXPORT const CFTypeRef kSecAttrComment;
SECURITY_EXPORT const CFTypeRef kSecAttrCreator;
SECURITY_EXPORT const CFTypeRef kSecAttrType;
SECURITY_EXPORT const CFTypeRef kSecAttrLabel;
SECURITY_EXPORT const CFTypeRef kSecAttrIsInvisible;
SECURITY_EXPORT const CFTypeRef kSecAttrIsNegative;
SECURITY_EXPORT const CFTypeRef kSecAttrAccount;
SECURITY_EXPORT const CFTypeRef kSecAttrService;
SECURITY_EXPORT const CFTypeRef kSecAttrGeneric;
SECURITY_EXPORT const CFTypeRef kSecAttrSecurityDomain;
SECURITY_EXPORT const CFTypeRef kSecAttrServer;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocol;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationType;
SECURITY_EXPORT const CFTypeRef kSecAttrPort;
SECURITY_EXPORT const CFTypeRef kSecAttrPath;
SECURITY_EXPORT const CFTypeRef kSecAttrSubject;
SECURITY_EXPORT const CFTypeRef kSecAttrIssuer;
SECURITY_EXPORT const CFTypeRef kSecAttrSerialNumber;
SECURITY_EXPORT const CFTypeRef kSecAttrSubjectKeyID;
SECURITY_EXPORT const CFTypeRef kSecAttrPublicKeyHash;
SECURITY_EXPORT const CFTypeRef kSecAttrCertificateType;
SECURITY_EXPORT const CFTypeRef kSecAttrCertificateEncoding;
SECURITY_EXPORT const CFTypeRef kSecAttrKeyClass;
SECURITY_EXPORT const CFTypeRef kSecAttrApplicationLabel;
SECURITY_EXPORT const CFTypeRef kSecAttrIsPermanent;
SECURITY_EXPORT const CFTypeRef kSecAttrApplicationTag;
SECURITY_EXPORT const CFTypeRef kSecAttrKeyType;
SECURITY_EXPORT const CFTypeRef kSecAttrKeySizeInBits;
SECURITY_EXPORT const CFTypeRef kSecAttrEffectiveKeySize;
SECURITY_EXPORT const CFTypeRef kSecAttrCanEncrypt;
SECURITY_EXPORT const CFTypeRef kSecAttrCanDecrypt;
SECURITY_EXPORT const CFTypeRef kSecAttrCanDerive;
SECURITY_EXPORT const CFTypeRef kSecAttrCanSign;
SECURITY_EXPORT const CFTypeRef kSecAttrCanVerify;
SECURITY_EXPORT const CFTypeRef kSecAttrCanWrap;
SECURITY_EXPORT const CFTypeRef kSecAttrCanUnwrap;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessGroup;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolFTP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolFTPAccount;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolHTTP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolIRC;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolNNTP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolPOP3;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolSMTP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolSOCKS;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolIMAP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolLDAP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolAppleTalk;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolAFP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolTelnet;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolSSH;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolFTPS;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolHTTPS;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolHTTPProxy;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolHTTPSProxy;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolFTPProxy;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolSMB;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolRTSP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolRTSPProxy;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolDAAP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolEPPC;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolIPP;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolNNTPS;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolLDAPS;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolTelnetS;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolIMAPS;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolIRCS;
SECURITY_EXPORT const CFTypeRef kSecAttrProtocolPOP3S;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationTypeNTLM;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationTypeMSN;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationTypeDPA;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationTypeRPA;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationTypeHTTPBasic;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationTypeHTTPDigest;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationTypeHTMLForm;
SECURITY_EXPORT const CFTypeRef kSecAttrAuthenticationTypeDefault;
SECURITY_EXPORT const CFTypeRef kSecAttrKeyClassPublic;
SECURITY_EXPORT const CFTypeRef kSecAttrKeyClassPrivate;
SECURITY_EXPORT const CFTypeRef kSecAttrKeyClassSymmetric;
SECURITY_EXPORT const CFTypeRef kSecAttrKeyTypeRSA;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessibleWhenUnlocked;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessibleAfterFirstUnlock;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessibleAlways;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessibleWhenUnlockedThisDeviceOnly;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly;
SECURITY_EXPORT const CFTypeRef kSecAttrAccessibleAlwaysThisDeviceOnly;
SECURITY_EXPORT const CFTypeRef kSecMatchPolicy;
SECURITY_EXPORT const CFTypeRef kSecMatchItemList;
SECURITY_EXPORT const CFTypeRef kSecMatchSearchList;
SECURITY_EXPORT const CFTypeRef kSecMatchIssuers;
SECURITY_EXPORT const CFTypeRef kSecMatchEmailAddressIfPresent;
SECURITY_EXPORT const CFTypeRef kSecMatchSubjectContains;
SECURITY_EXPORT const CFTypeRef kSecMatchCaseInsensitive;
SECURITY_EXPORT const CFTypeRef kSecMatchTrustedOnly;
SECURITY_EXPORT const CFTypeRef kSecMatchValidOnDate;
SECURITY_EXPORT const CFTypeRef kSecMatchLimit;
SECURITY_EXPORT const CFTypeRef kSecMatchLimitOne;
SECURITY_EXPORT const CFTypeRef kSecMatchLimitAll;
SECURITY_EXPORT const CFTypeRef kSecUseItemList;
SECURITY_EXPORT const CFTypeRef kSecReturnData;
SECURITY_EXPORT const CFTypeRef kSecReturnAttributes;
SECURITY_EXPORT const CFTypeRef kSecReturnRef;
SECURITY_EXPORT const CFTypeRef kSecReturnPersistentRef;
SECURITY_EXPORT const CFTypeRef kSecValueData;
SECURITY_EXPORT const CFTypeRef kSecValueRef;
SECURITY_EXPORT const CFTypeRef kSecValuePersistentRef;

SECURITY_EXPORT const CFStringRef kSecImportItemLabel;
SECURITY_EXPORT const CFStringRef kSecImportItemKeyID;
SECURITY_EXPORT const CFStringRef kSecImportItemTrust;
SECURITY_EXPORT const CFStringRef kSecImportItemCertChain;
SECURITY_EXPORT const CFStringRef kSecImportItemIdentity;

SECURITY_EXPORT const CFTypeRef kSecPropertyTypeTitle;
SECURITY_EXPORT const CFTypeRef kSecPropertyTypeError;

SECURITY_EXPORT OSStatus SecItemUpdate(CFDictionaryRef query, CFDictionaryRef attributesToUpdate);
SECURITY_EXPORT OSStatus SecItemAdd(CFDictionaryRef attributes, CFTypeRef* result);
SECURITY_EXPORT OSStatus SecItemDelete(CFDictionaryRef query);
SECURITY_EXPORT OSStatus SecItemCopyMatching(CFDictionaryRef query, CFTypeRef* result);