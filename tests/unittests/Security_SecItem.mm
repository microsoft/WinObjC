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

#include "gtest-api.h"
#import <Foundation/Foundation.h>
#import <Security/SecItem.h>

TEST(Security, SecItem_Constants) {
    ASSERT_TRUE([kSecClass isEqualToString:@"class"]);
    ASSERT_TRUE([kSecClassGenericPassword isEqualToString:@"genp"]);
    ASSERT_TRUE([kSecClassInternetPassword isEqualToString:@"inet"]);
    ASSERT_TRUE([kSecClassCertificate isEqualToString:@"cert"]);
    ASSERT_TRUE([kSecClassKey isEqualToString:@"keys"]);
    ASSERT_TRUE([kSecClassIdentity isEqualToString:@"idnt"]);
    ASSERT_TRUE([kSecAttrAccessible isEqualToString:@"pdmn"]);
    ASSERT_TRUE([kSecAttrAccessibleAfterFirstUnlock isEqualToString:@"ck"]);
    ASSERT_TRUE([kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly isEqualToString:@"cku"]);
    ASSERT_TRUE([kSecAttrAccessibleAlways isEqualToString:@"dk"]);
    ASSERT_TRUE([kSecAttrAccessibleAlwaysThisDeviceOnly isEqualToString:@"dku"]);
    ASSERT_TRUE([kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly isEqualToString:@"akpu"]);
    ASSERT_TRUE([kSecAttrAccessibleWhenUnlocked isEqualToString:@"ak"]);
    ASSERT_TRUE([kSecAttrAccessibleWhenUnlockedThisDeviceOnly isEqualToString:@"aku"]);
    ASSERT_TRUE([kSecAttrAccessGroup isEqualToString:@"agrp"]);
    ASSERT_TRUE([kSecAttrCreationDate isEqualToString:@"cdat"]);
    ASSERT_TRUE([kSecAttrModificationDate isEqualToString:@"mdat"]);
    ASSERT_TRUE([kSecAttrDescription isEqualToString:@"desc"]);
    ASSERT_TRUE([kSecAttrComment isEqualToString:@"icmt"]);
    ASSERT_TRUE([kSecAttrCreator isEqualToString:@"crtr"]);
    ASSERT_TRUE([kSecAttrType isEqualToString:@"type"]);
    ASSERT_TRUE([kSecAttrLabel isEqualToString:@"labl"]);
    ASSERT_TRUE([kSecAttrIsInvisible isEqualToString:@"invi"]);
    ASSERT_TRUE([kSecAttrIsNegative isEqualToString:@"nega"]);
    ASSERT_TRUE([kSecAttrAccount isEqualToString:@"acct"]);
    ASSERT_TRUE([kSecAttrService isEqualToString:@"svce"]);
    ASSERT_TRUE([kSecAttrGeneric isEqualToString:@"gena"]);
    ASSERT_TRUE([kSecValueData isEqualToString:@"v_Data"]);
    ASSERT_TRUE([kSecValueRef isEqualToString:@"v_Ref"]);
    ASSERT_TRUE([kSecValuePersistentRef isEqualToString:@"v_PersistentRef"]);
    ASSERT_TRUE([kSecReturnData isEqualToString:@"r_Data"]);
    ASSERT_TRUE([kSecReturnAttributes isEqualToString:@"r_Attributes"]);
    ASSERT_TRUE([kSecReturnRef isEqualToString:@"r_Ref"]);
    ASSERT_TRUE([kSecReturnPersistentRef isEqualToString:@"r_PersistentRef"]);
    ASSERT_TRUE([kSecUseItemList isEqualToString:@"u_ItemList"]);
    ASSERT_TRUE([kSecMatchPolicy isEqualToString:@"m_Policy"]);
    ASSERT_TRUE([kSecMatchItemList isEqualToString:@"m_ItemList"]);
    ASSERT_TRUE([kSecMatchSearchList isEqualToString:@"m_SearchList"]);
    ASSERT_TRUE([kSecMatchIssuers isEqualToString:@"m_Issuers"]);
    ASSERT_TRUE([kSecMatchEmailAddressIfPresent isEqualToString:@"m_EmailAddressIfPresent"]);
    ASSERT_TRUE([kSecMatchSubjectContains isEqualToString:@"m_SubjectContains"]);
    ASSERT_TRUE([kSecMatchCaseInsensitive isEqualToString:@"m_CaseInsensitive"]);
    ASSERT_TRUE([kSecMatchTrustedOnly isEqualToString:@"m_TrustedOnly"]);
    ASSERT_TRUE([kSecMatchValidOnDate isEqualToString:@"m_ValidOnDate"]);
    ASSERT_TRUE([kSecMatchLimit isEqualToString:@"m_Limit"]);
    ASSERT_TRUE([kSecMatchLimitOne isEqualToString:@"m_LimitOne"]);
    ASSERT_TRUE([kSecMatchLimitAll isEqualToString:@"m_LimitAll"]);
}