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

#include "Starboard.h"
#include <array>
#include <utility>
#import <Foundation/NSDictionary.h>
#import <Security/SecItem.h>
#import <Starboard.h>

#import "SecItemHandlerProtocol.h"
#import "GenericPasswordItemHandler.h"

const CFStringRef kSecImportExportPassphrase = static_cast<CFStringRef>(@"kSecImportExportPassphrase");
const CFTypeRef kSecClass = static_cast<CFStringRef>(@"kSecClass");
const CFTypeRef kSecClassGenericPassword = static_cast<CFStringRef>(@"kSecClassGenericPassword");
const CFTypeRef kSecClassInternetPassword = static_cast<CFStringRef>(@"kSecClassInternetPassword");
const CFTypeRef kSecClassCertificate = static_cast<CFStringRef>(@"kSecClassCertificate");
const CFTypeRef kSecClassKey = static_cast<CFStringRef>(@"kSecClassKey");
const CFTypeRef kSecClassIdentity = static_cast<CFStringRef>(@"kSecClassIdentity");
const CFTypeRef kSecAttrAccessible = static_cast<CFStringRef>(@"kSecAttrAccessible");
const CFTypeRef kSecAttrCreationDate = static_cast<CFStringRef>(@"kSecAttrCreationDate");
const CFTypeRef kSecAttrModificationDate = static_cast<CFStringRef>(@"kSecAttrModificationDate");
const CFTypeRef kSecAttrDescription = static_cast<CFStringRef>(@"kSecAttrDescription");
const CFTypeRef kSecAttrComment = static_cast<CFStringRef>(@"kSecAttrComment");
const CFTypeRef kSecAttrCreator = static_cast<CFStringRef>(@"kSecAttrCreator");
const CFTypeRef kSecAttrType = static_cast<CFStringRef>(@"kSecAttrType");
const CFTypeRef kSecAttrLabel = static_cast<CFStringRef>(@"kSecAttrLabel");
const CFTypeRef kSecAttrIsInvisible = static_cast<CFStringRef>(@"kSecAttrIsInvisible");
const CFTypeRef kSecAttrIsNegative = static_cast<CFStringRef>(@"kSecAttrIsNegative");
const CFTypeRef kSecAttrAccount = static_cast<CFStringRef>(@"kSecAttrAccount");
const CFTypeRef kSecAttrService = static_cast<CFStringRef>(@"kSecAttrService");
const CFTypeRef kSecAttrGeneric = static_cast<CFStringRef>(@"kSecAttrGeneric");
const CFTypeRef kSecAttrSecurityDomain = static_cast<CFStringRef>(@"kSecAttrSecurityDomain");
const CFTypeRef kSecAttrServer = static_cast<CFStringRef>(@"kSecAttrServer");
const CFTypeRef kSecAttrProtocol = static_cast<CFStringRef>(@"kSecAttrProtocol");
const CFTypeRef kSecAttrAuthenticationType = static_cast<CFStringRef>(@"kSecAttrAuthenticationType");
const CFTypeRef kSecAttrPort = static_cast<CFStringRef>(@"kSecAttrPort");
const CFTypeRef kSecAttrPath = static_cast<CFStringRef>(@"kSecAttrPath");
const CFTypeRef kSecAttrSubject = static_cast<CFStringRef>(@"kSecAttrSubject");
const CFTypeRef kSecAttrIssuer = static_cast<CFStringRef>(@"kSecAttrIssuer");
const CFTypeRef kSecAttrSerialNumber = static_cast<CFStringRef>(@"kSecAttrSerialNumber");
const CFTypeRef kSecAttrSubjectKeyID = static_cast<CFStringRef>(@"kSecAttrSubjectKeyID");
const CFTypeRef kSecAttrPublicKeyHash = static_cast<CFStringRef>(@"kSecAttrPublicKeyHash");
const CFTypeRef kSecAttrCertificateType = static_cast<CFStringRef>(@"kSecAttrCertificateType");
const CFTypeRef kSecAttrCertificateEncoding = static_cast<CFStringRef>(@"kSecAttrCertificateEncoding");
const CFTypeRef kSecAttrKeyClass = static_cast<CFStringRef>(@"kSecAttrKeyClass");
const CFTypeRef kSecAttrApplicationLabel = static_cast<CFStringRef>(@"kSecAttrApplicationLabel");
const CFTypeRef kSecAttrIsPermanent = static_cast<CFStringRef>(@"kSecAttrIsPermanent");
const CFTypeRef kSecAttrApplicationTag = static_cast<CFStringRef>(@"kSecAttrApplicationTag");
const CFTypeRef kSecAttrKeyType = static_cast<CFStringRef>(@"kSecAttrKeyType");
const CFTypeRef kSecAttrKeySizeInBits = static_cast<CFStringRef>(@"kSecAttrKeySizeInBits");
const CFTypeRef kSecAttrEffectiveKeySize = static_cast<CFStringRef>(@"kSecAttrEffectiveKeySize");
const CFTypeRef kSecAttrCanEncrypt = static_cast<CFStringRef>(@"kSecAttrCanEncrypt");
const CFTypeRef kSecAttrCanDecrypt = static_cast<CFStringRef>(@"kSecAttrCanDecrypt");
const CFTypeRef kSecAttrCanDerive = static_cast<CFStringRef>(@"kSecAttrCanDerive");
const CFTypeRef kSecAttrCanSign = static_cast<CFStringRef>(@"kSecAttrCanSign");
const CFTypeRef kSecAttrCanVerify = static_cast<CFStringRef>(@"kSecAttrCanVerify");
const CFTypeRef kSecAttrCanWrap = static_cast<CFStringRef>(@"kSecAttrCanWrap");
const CFTypeRef kSecAttrCanUnwrap = static_cast<CFStringRef>(@"kSecAttrCanUnwrap");
const CFTypeRef kSecAttrAccessGroup = static_cast<CFStringRef>(@"kSecAttrAccessGroup");
const CFTypeRef kSecAttrProtocolFTP = static_cast<CFStringRef>(@"kSecAttrProtocolFTP");
const CFTypeRef kSecAttrProtocolFTPAccount = static_cast<CFStringRef>(@"kSecAttrProtocolFTPAccount");
const CFTypeRef kSecAttrProtocolHTTP = static_cast<CFStringRef>(@"kSecAttrProtocolHTTP");
const CFTypeRef kSecAttrProtocolIRC = static_cast<CFStringRef>(@"kSecAttrProtocolIRC");
const CFTypeRef kSecAttrProtocolNNTP = static_cast<CFStringRef>(@"kSecAttrProtocolNNTP");
const CFTypeRef kSecAttrProtocolPOP3 = static_cast<CFStringRef>(@"kSecAttrProtocolPOP3");
const CFTypeRef kSecAttrProtocolSMTP = static_cast<CFStringRef>(@"kSecAttrProtocolSMTP");
const CFTypeRef kSecAttrProtocolSOCKS = static_cast<CFStringRef>(@"kSecAttrProtocolSOCKS");
const CFTypeRef kSecAttrProtocolIMAP = static_cast<CFStringRef>(@"kSecAttrProtocolIMAP");
const CFTypeRef kSecAttrProtocolLDAP = static_cast<CFStringRef>(@"kSecAttrProtocolLDAP");
const CFTypeRef kSecAttrProtocolAppleTalk = static_cast<CFStringRef>(@"kSecAttrProtocolAppleTalk");
const CFTypeRef kSecAttrProtocolAFP = static_cast<CFStringRef>(@"kSecAttrProtocolAFP");
const CFTypeRef kSecAttrProtocolTelnet = static_cast<CFStringRef>(@"kSecAttrProtocolTelnet");
const CFTypeRef kSecAttrProtocolSSH = static_cast<CFStringRef>(@"kSecAttrProtocolSSH");
const CFTypeRef kSecAttrProtocolFTPS = static_cast<CFStringRef>(@"kSecAttrProtocolFTPS");
const CFTypeRef kSecAttrProtocolHTTPS = static_cast<CFStringRef>(@"kSecAttrProtocolHTTPS");
const CFTypeRef kSecAttrProtocolHTTPProxy = static_cast<CFStringRef>(@"kSecAttrProtocolHTTPProxy");
const CFTypeRef kSecAttrProtocolHTTPSProxy = static_cast<CFStringRef>(@"kSecAttrProtocolHTTPSProxy");
const CFTypeRef kSecAttrProtocolFTPProxy = static_cast<CFStringRef>(@"kSecAttrProtocolFTPProxy");
const CFTypeRef kSecAttrProtocolSMB = static_cast<CFStringRef>(@"kSecAttrProtocolSMB");
const CFTypeRef kSecAttrProtocolRTSP = static_cast<CFStringRef>(@"kSecAttrProtocolRTSP");
const CFTypeRef kSecAttrProtocolRTSPProxy = static_cast<CFStringRef>(@"kSecAttrProtocolRTSPProxy");
const CFTypeRef kSecAttrProtocolDAAP = static_cast<CFStringRef>(@"kSecAttrProtocolDAAP");
const CFTypeRef kSecAttrProtocolEPPC = static_cast<CFStringRef>(@"kSecAttrProtocolEPPC");
const CFTypeRef kSecAttrProtocolIPP = static_cast<CFStringRef>(@"kSecAttrProtocolIPP");
const CFTypeRef kSecAttrProtocolNNTPS = static_cast<CFStringRef>(@"kSecAttrProtocolNNTPS");
const CFTypeRef kSecAttrProtocolLDAPS = static_cast<CFStringRef>(@"kSecAttrProtocolLDAPS");
const CFTypeRef kSecAttrProtocolTelnetS = static_cast<CFStringRef>(@"kSecAttrProtocolTelnetS");
const CFTypeRef kSecAttrProtocolIMAPS = static_cast<CFStringRef>(@"kSecAttrProtocolIMAPS");
const CFTypeRef kSecAttrProtocolIRCS = static_cast<CFStringRef>(@"kSecAttrProtocolIRCS");
const CFTypeRef kSecAttrProtocolPOP3S = static_cast<CFStringRef>(@"kSecAttrProtocolPOP3S");
const CFTypeRef kSecAttrAuthenticationTypeNTLM = static_cast<CFStringRef>(@"kSecAttrAuthenticationTypeNTLM");
const CFTypeRef kSecAttrAuthenticationTypeMSN = static_cast<CFStringRef>(@"kSecAttrAuthenticationTypeMSN");
const CFTypeRef kSecAttrAuthenticationTypeDPA = static_cast<CFStringRef>(@"kSecAttrAuthenticationTypeDPA");
const CFTypeRef kSecAttrAuthenticationTypeRPA = static_cast<CFStringRef>(@"kSecAttrAuthenticationTypeRPA");
const CFTypeRef kSecAttrAuthenticationTypeHTTPBasic = static_cast<CFStringRef>(@"kSecAttrAuthenticationTypeHTTPBasic");
const CFTypeRef kSecAttrAuthenticationTypeHTTPDigest = static_cast<CFStringRef>(@"kSecAttrAuthenticationTypeHTTPDigest");
const CFTypeRef kSecAttrAuthenticationTypeHTMLForm = static_cast<CFStringRef>(@"kSecAttrAuthenticationTypeHTMLForm");
const CFTypeRef kSecAttrAuthenticationTypeDefault = static_cast<CFStringRef>(@"kSecAttrAuthenticationTypeDefault");
const CFTypeRef kSecAttrKeyClassPublic = static_cast<CFStringRef>(@"kSecAttrKeyClassPublic");
const CFTypeRef kSecAttrKeyClassPrivate = static_cast<CFStringRef>(@"kSecAttrKeyClassPrivate");
const CFTypeRef kSecAttrKeyClassSymmetric = static_cast<CFStringRef>(@"kSecAttrKeyClassSymmetric");
const CFTypeRef kSecAttrKeyTypeRSA = static_cast<CFStringRef>(@"kSecAttrKeyTypeRSA");
const CFTypeRef kSecAttrAccessibleWhenUnlocked = static_cast<CFStringRef>(@"kSecAttrAccessibleWhenUnlocked");
const CFTypeRef kSecAttrAccessibleAfterFirstUnlock = static_cast<CFStringRef>(@"kSecAttrAccessibleAfterFirstUnlock");
const CFTypeRef kSecAttrAccessibleAlways = static_cast<CFStringRef>(@"kSecAttrAccessibleAlways");
const CFTypeRef kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly =
    static_cast<CFStringRef>(@"kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly");
const CFTypeRef kSecAttrAccessibleWhenUnlockedThisDeviceOnly = static_cast<CFStringRef>(@"kSecAttrAccessibleWhenUnlockedThisDeviceOnly");
const CFTypeRef kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly =
    static_cast<CFStringRef>(@"kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly");
const CFTypeRef kSecAttrAccessibleAlwaysThisDeviceOnly = static_cast<CFStringRef>(@"kSecAttrAccessibleAlwaysThisDeviceOnly");
const CFTypeRef kSecMatchPolicy = static_cast<CFStringRef>(@"kSecMatchPolicy");
const CFTypeRef kSecMatchItemList = static_cast<CFStringRef>(@"kSecMatchItemList");
const CFTypeRef kSecMatchSearchList = static_cast<CFStringRef>(@"kSecMatchSearchList");
const CFTypeRef kSecMatchIssuers = static_cast<CFStringRef>(@"kSecMatchIssuers");
const CFTypeRef kSecMatchEmailAddressIfPresent = static_cast<CFStringRef>(@"kSecMatchEmailAddressIfPresent");
const CFTypeRef kSecMatchSubjectContains = static_cast<CFStringRef>(@"kSecMatchSubjectContains");
const CFTypeRef kSecMatchCaseInsensitive = static_cast<CFStringRef>(@"kSecMatchCaseInsensitive");
const CFTypeRef kSecMatchTrustedOnly = static_cast<CFStringRef>(@"kSecMatchTrustedOnly");
const CFTypeRef kSecMatchValidOnDate = static_cast<CFStringRef>(@"kSecMatchValidOnDate");
const CFTypeRef kSecMatchLimit = static_cast<CFStringRef>(@"kSecMatchLimit");
const CFTypeRef kSecMatchLimitOne = static_cast<CFStringRef>(@"kSecMatchLimitOne");
const CFTypeRef kSecMatchLimitAll = static_cast<CFStringRef>(@"kSecMatchLimitAll");
const CFTypeRef kSecUseItemList = static_cast<CFStringRef>(@"kSecUseItemList");
const CFTypeRef kSecReturnData = static_cast<CFStringRef>(@"kSecReturnData");
const CFTypeRef kSecReturnAttributes = static_cast<CFStringRef>(@"kSecReturnAttributes");
const CFTypeRef kSecReturnRef = static_cast<CFStringRef>(@"kSecReturnRef");
const CFTypeRef kSecReturnPersistentRef = static_cast<CFStringRef>(@"kSecReturnPersistentRef");
const CFTypeRef kSecValueData = static_cast<CFStringRef>(@"kSecValueData");
const CFTypeRef kSecValueRef = static_cast<CFStringRef>(@"kSecValueRef");
const CFTypeRef kSecValuePersistentRef = static_cast<CFStringRef>(@"kSecValuePersistentRef");

const CFStringRef kSecImportItemLabel = static_cast<CFStringRef>(@"kSecImportItemLabel");
const CFStringRef kSecImportItemKeyID = static_cast<CFStringRef>(@"kSecImportItemKeyID");
const CFStringRef kSecImportItemTrust = static_cast<CFStringRef>(@"kSecImportItemTrust");
const CFStringRef kSecImportItemCertChain = static_cast<CFStringRef>(@"kSecImportItemCertChain");
const CFStringRef kSecImportItemIdentity = static_cast<CFStringRef>(@"kSecImportItemIdentity");

const CFTypeRef kSecPropertyTypeTitle = static_cast<CFStringRef>(@"kSecPropertyTypeTitle");
const CFTypeRef kSecPropertyTypeError = static_cast<CFStringRef>(@"kSecPropertyTypeError");

std::array<std::pair<NSString*, idretainp<id<SecItemHandler>>>, 1>& GetItemHandlers() {
    // using a array here instead of a dictionary because there will only ever be a handful of
    // handlers so iterating to find the right one should be fast enough and have less overhead than a dictionary.
    static std::array<std::pair<NSString*, idretainp<id<SecItemHandler>>>, 1> s_itemHandlers{ {
        { static_cast<NSString*>(kSecClassGenericPassword), [[GenericPasswordItemHandler new] autorelease] },
    } };

    return s_itemHandlers;
}

/**
 @Status Caveat
 @Notes Only GenericPassword items can be updated
*/
OSStatus SecItemUpdate(CFDictionaryRef query, CFDictionaryRef attributesToUpdate) {
    NSUInteger numberUpdated = 0;

    // Each handler could have some matching items so go ahead and
    // forward along to all of them. This means that error handling
    // will get a little tricky though. Fail on the first error and
    // make no attempt to rollback or whatever. Whatever happens, happens.
    for (const auto& handlerPair : GetItemHandlers()) {
        NSUInteger currentUpdated = 0;

        OSStatus status = [handlerPair.second update:static_cast<NSDictionary*>(query)
                                      withAttributes:static_cast<NSDictionary*>(attributesToUpdate)
                                   attributesUpdated:&currentUpdated];

        if (status != errSecSuccess) {
            return status;
        }

        numberUpdated += currentUpdated;
    }

    if (numberUpdated < CFDictionaryGetCount(attributesToUpdate)) {
        return errSecItemNotFound;
    }

    return errSecSuccess;
}

/**
 @Status Caveat
 @Notes Only GenericPassword items can be added
*/
OSStatus SecItemAdd(CFDictionaryRef attributes, CFTypeRef* result) {
    NSDictionary* nsAttributes = static_cast<NSDictionary*>(attributes);
    if (nsAttributes == nil) {
        return errSecParam;
    }

    id classType = [nsAttributes objectForKey:static_cast<NSString*>(kSecClass)];
    if (classType == nil) {
        return errSecParam;
    }

    for (const auto& handlerPair : GetItemHandlers()) {
        if ([classType isEqualToString:handlerPair.first]) {
            return [handlerPair.second add:static_cast<NSDictionary*>(attributes) withResult:(id*)(result)];
        }
    }

    return errSecParam;
}

/**
 @Status Caveat
 @Notes Only GenericPassword items can be deleted
*/
OSStatus SecItemDelete(CFDictionaryRef query) {
    // Each handler could have some matching items so go ahead and
    // forward along to all of them. This means that error handling
    // will get a little tricky though. Fail on the first error and
    // make no attempt to rollback or whatever. Whatever happens, happens.
    for (const auto& handlerPair : GetItemHandlers()) {
        OSStatus status = [handlerPair.second remove:static_cast<NSDictionary*>(query)];
        if (status != errSecSuccess) {
            return status;
        }
    }

    return errSecSuccess;
}

/**
 @Status Caveat
 @Notes Only GenericPassword items can be queried
*/
OSStatus SecItemCopyMatching(CFDictionaryRef query, CFTypeRef* result) {
    // Each handler could have some matching items so go ahead and
    // forward along to all of them. This means that error handling
    // will get a little tricky though. Fail on the first error and
    // make no attempt to rollback or whatever. Whatever happens, happens.
    for (const auto& handlerPair : GetItemHandlers()) {
        OSStatus status = [handlerPair.second query:static_cast<NSDictionary*>(query) withResult:(id*)(result)];
        if (status != errSecSuccess) {
            return status;
        }
    }

    // TODO: all results need combined into one (assuming not nil result). As written only the last result
    // gets applied which is fine until more than handler exists.

    return errSecSuccess;
}
