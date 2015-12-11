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

#include <TestFramework.h>
#import <Foundation/Foundation.h>
#import <Security/SecItem.h>

TEST(Security, SecItem_Constants) {
    ASSERT_TRUE([static_cast<NSString*>(kSecClass) isEqualToString:@"class"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassGenericPassword) isEqualToString:@"genp"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassInternetPassword) isEqualToString:@"inet"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassCertificate) isEqualToString:@"cert"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassKey) isEqualToString:@"keys"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassIdentity) isEqualToString:@"idnt"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessible) isEqualToString:@"pdmn"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleAfterFirstUnlock) isEqualToString:@"ck"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly) isEqualToString:@"cku"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleAlways) isEqualToString:@"dk"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleAlwaysThisDeviceOnly) isEqualToString:@"dku"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly) isEqualToString:@"akpu"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleWhenUnlocked) isEqualToString:@"ak"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleWhenUnlockedThisDeviceOnly) isEqualToString:@"aku"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessGroup) isEqualToString:@"agrp"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCreationDate) isEqualToString:@"cdat"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrModificationDate) isEqualToString:@"mdat"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrDescription) isEqualToString:@"desc"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrComment) isEqualToString:@"icmt"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCreator) isEqualToString:@"crtr"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrType) isEqualToString:@"type"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrLabel) isEqualToString:@"labl"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrIsInvisible) isEqualToString:@"invi"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrIsNegative) isEqualToString:@"nega"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccount) isEqualToString:@"acct"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrService) isEqualToString:@"svce"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrGeneric) isEqualToString:@"gena"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecValueData) isEqualToString:@"v_Data"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecValueRef) isEqualToString:@"v_Ref"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecValuePersistentRef) isEqualToString:@"v_PersistentRef"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecReturnData) isEqualToString:@"r_Data"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecReturnAttributes) isEqualToString:@"r_Attributes"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecReturnRef) isEqualToString:@"r_Ref"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecReturnPersistentRef) isEqualToString:@"r_PersistentRef"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecUseItemList) isEqualToString:@"u_ItemList"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchPolicy) isEqualToString:@"m_Policy"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchItemList) isEqualToString:@"m_ItemList"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchSearchList) isEqualToString:@"m_SearchList"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchIssuers) isEqualToString:@"m_Issuers"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchEmailAddressIfPresent) isEqualToString:@"m_EmailAddressIfPresent"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchSubjectContains) isEqualToString:@"m_SubjectContains"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchCaseInsensitive) isEqualToString:@"m_CaseInsensitive"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchTrustedOnly) isEqualToString:@"m_TrustedOnly"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchValidOnDate) isEqualToString:@"m_ValidOnDate"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchLimit) isEqualToString:@"m_Limit"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchLimitOne) isEqualToString:@"m_LimitOne"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchLimitAll) isEqualToString:@"m_LimitAll"]);
}