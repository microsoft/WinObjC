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

const CFStringRef kSecClass = static_cast<CFStringRef>(@"class");
const CFStringRef kSecClassGenericPassword = static_cast<CFStringRef>(@"genp");
const CFStringRef kSecClassInternetPassword = static_cast<CFStringRef>(@"inet");
const CFStringRef kSecClassCertificate = static_cast<CFStringRef>(@"cert");
const CFStringRef kSecClassKey = static_cast<CFStringRef>(@"keys");
const CFStringRef kSecClassIdentity = static_cast<CFStringRef>(@"idnt");
const CFStringRef kSecAttrAccessible = static_cast<CFStringRef>(@"pdmn");
const CFStringRef kSecAttrAccessGroup = static_cast<CFStringRef>(@"agrp");
const CFStringRef kSecAttrCreationDate = static_cast<CFStringRef>(@"cdat");
const CFStringRef kSecAttrModificationDate = static_cast<CFStringRef>(@"mdat");
const CFStringRef kSecAttrDescription = static_cast<CFStringRef>(@"desc");
const CFStringRef kSecAttrComment = static_cast<CFStringRef>(@"icmt");
const CFStringRef kSecAttrCreator = static_cast<CFStringRef>(@"crtr");
const CFStringRef kSecAttrType = static_cast<CFStringRef>(@"type");
const CFStringRef kSecAttrLabel = static_cast<CFStringRef>(@"labl");
const CFStringRef kSecAttrIsInvisible = static_cast<CFStringRef>(@"invi");
const CFStringRef kSecAttrIsNegative = static_cast<CFStringRef>(@"nega");
const CFStringRef kSecAttrAccount = static_cast<CFStringRef>(@"acct");
const CFStringRef kSecAttrService = static_cast<CFStringRef>(@"svce");
const CFStringRef kSecAttrGeneric = static_cast<CFStringRef>(@"gena");
const CFStringRef kSecValueData = static_cast<CFStringRef>(@"v_Data");
const CFStringRef kSecValueRef = static_cast<CFStringRef>(@"v_Ref");
const CFStringRef kSecValuePersistentRef = static_cast<CFStringRef>(@"v_PersistentRef");
const CFStringRef kSecReturnData = static_cast<CFStringRef>(@"r_Data");
const CFStringRef kSecReturnAttributes = static_cast<CFStringRef>(@"r_Attributes");
const CFStringRef kSecReturnRef = static_cast<CFStringRef>(@"r_Ref");
const CFStringRef kSecReturnPersistentRef = static_cast<CFStringRef>(@"r_PersistentRef");
const CFStringRef kSecUseItemList = static_cast<CFStringRef>(@"u_ItemList");
const CFStringRef kSecMatchPolicy = static_cast<CFStringRef>(@"m_Policy");
const CFStringRef kSecMatchItemList = static_cast<CFStringRef>(@"m_ItemList");
const CFStringRef kSecMatchSearchList = static_cast<CFStringRef>(@"m_SearchList");
const CFStringRef kSecMatchIssuers = static_cast<CFStringRef>(@"m_Issuers");
const CFStringRef kSecMatchEmailAddressIfPresent = static_cast<CFStringRef>(@"m_EmailAddressIfPresent");
const CFStringRef kSecMatchSubjectContains = static_cast<CFStringRef>(@"m_SubjectContains");
const CFStringRef kSecMatchCaseInsensitive = static_cast<CFStringRef>(@"m_CaseInsensitive");
const CFStringRef kSecMatchTrustedOnly = static_cast<CFStringRef>(@"m_TrustedOnly");
const CFStringRef kSecMatchValidOnDate = static_cast<CFStringRef>(@"m_ValidOnDate");
const CFStringRef kSecMatchLimit = static_cast<CFStringRef>(@"m_Limit");
const CFStringRef kSecMatchLimitOne = static_cast<CFStringRef>(@"m_LimitOne");
const CFStringRef kSecMatchLimitAll = static_cast<CFStringRef>(@"m_LimitAll");
const CFStringRef kSecAttrAccessibleAfterFirstUnlock = static_cast<CFStringRef>(@"ck");
const CFStringRef kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly = static_cast<CFStringRef>(@"cku");
const CFStringRef kSecAttrAccessibleAlways = static_cast<CFStringRef>(@"dk");
const CFStringRef kSecAttrAccessibleAlwaysThisDeviceOnly = static_cast<CFStringRef>(@"dku");
const CFStringRef kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly = static_cast<CFStringRef>(@"akpu");
const CFStringRef kSecAttrAccessibleWhenUnlocked = static_cast<CFStringRef>(@"ak");
const CFStringRef kSecAttrAccessibleWhenUnlockedThisDeviceOnly = static_cast<CFStringRef>(@"aku");

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
    // Each handler could have some matching items so go ahead and
    // forward along to all of them. This means that error handling
    // will get a little tricky though. Fail on the first error and
    // make no attempt to rollback or whatever. Whatever happens, happens.
    for (const auto& handlerPair : GetItemHandlers()) {
        OSStatus status =
            [handlerPair.second update:static_cast<NSDictionary*>(query) withAttributes:static_cast<NSDictionary*>(attributesToUpdate)];
        if (status != errSecSuccess) {
            return status;
        }
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
