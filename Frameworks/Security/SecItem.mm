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
#import <Security/SecItem.h>

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

/**
 @Status Stub
*/
OSStatus SecItemUpdate(CFDictionaryRef query, CFDictionaryRef attributesToUpdate) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
OSStatus SecItemAdd(CFDictionaryRef attributes, CFTypeRef* result) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
OSStatus SecItemDelete(CFDictionaryRef query) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
OSStatus SecItemCopyMatching(CFDictionaryRef query, CFTypeRef* result) {
    UNIMPLEMENTED();
    return 0;
}