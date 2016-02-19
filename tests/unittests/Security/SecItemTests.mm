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
    ASSERT_TRUE([static_cast<NSString*>(kSecClass) isEqualToString:@"kSecClass"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassGenericPassword) isEqualToString:@"kSecClassGenericPassword"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassInternetPassword) isEqualToString:@"kSecClassInternetPassword"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassCertificate) isEqualToString:@"kSecClassCertificate"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassKey) isEqualToString:@"kSecClassKey"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecClassIdentity) isEqualToString:@"kSecClassIdentity"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessible) isEqualToString:@"kSecAttrAccessible"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleAfterFirstUnlock) isEqualToString:@"kSecAttrAccessibleAfterFirstUnlock"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly)
        isEqualToString:@"kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleAlways) isEqualToString:@"kSecAttrAccessibleAlways"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleAlwaysThisDeviceOnly) isEqualToString:@"kSecAttrAccessibleAlwaysThisDeviceOnly"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly)
        isEqualToString:@"kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleWhenUnlocked) isEqualToString:@"kSecAttrAccessibleWhenUnlocked"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessibleWhenUnlockedThisDeviceOnly)
        isEqualToString:@"kSecAttrAccessibleWhenUnlockedThisDeviceOnly"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccessGroup) isEqualToString:@"kSecAttrAccessGroup"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAccount) isEqualToString:@"kSecAttrAccount"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrApplicationLabel) isEqualToString:@"kSecAttrApplicationLabel"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrApplicationTag) isEqualToString:@"kSecAttrApplicationTag"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationType) isEqualToString:@"kSecAttrAuthenticationType"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationTypeDPA) isEqualToString:@"kSecAttrAuthenticationTypeDPA"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationTypeDefault) isEqualToString:@"kSecAttrAuthenticationTypeDefault"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationTypeHTMLForm) isEqualToString:@"kSecAttrAuthenticationTypeHTMLForm"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationTypeHTTPBasic) isEqualToString:@"kSecAttrAuthenticationTypeHTTPBasic"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationTypeHTTPDigest) isEqualToString:@"kSecAttrAuthenticationTypeHTTPDigest"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationTypeMSN) isEqualToString:@"kSecAttrAuthenticationTypeMSN"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationTypeNTLM) isEqualToString:@"kSecAttrAuthenticationTypeNTLM"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrAuthenticationTypeRPA) isEqualToString:@"kSecAttrAuthenticationTypeRPA"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCreationDate) isEqualToString:@"kSecAttrCreationDate"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrModificationDate) isEqualToString:@"kSecAttrModificationDate"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrDescription) isEqualToString:@"kSecAttrDescription"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCanDecrypt) isEqualToString:@"kSecAttrCanDecrypt"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCanDerive) isEqualToString:@"kSecAttrCanDerive"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCanEncrypt) isEqualToString:@"kSecAttrCanEncrypt"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCanSign) isEqualToString:@"kSecAttrCanSign"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCanUnwrap) isEqualToString:@"kSecAttrCanUnwrap"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCanVerify) isEqualToString:@"kSecAttrCanVerify"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCanWrap) isEqualToString:@"kSecAttrCanWrap"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCertificateEncoding) isEqualToString:@"kSecAttrCertificateEncoding"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCertificateType) isEqualToString:@"kSecAttrCertificateType"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrEffectiveKeySize) isEqualToString:@"kSecAttrEffectiveKeySize"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrComment) isEqualToString:@"kSecAttrComment"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrCreator) isEqualToString:@"kSecAttrCreator"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrType) isEqualToString:@"kSecAttrType"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrLabel) isEqualToString:@"kSecAttrLabel"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrIsInvisible) isEqualToString:@"kSecAttrIsInvisible"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrIsNegative) isEqualToString:@"kSecAttrIsNegative"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrIsPermanent) isEqualToString:@"kSecAttrIsPermanent"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrIssuer) isEqualToString:@"kSecAttrIssuer"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrService) isEqualToString:@"kSecAttrService"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecAttrGeneric) isEqualToString:@"kSecAttrGeneric"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecValueData) isEqualToString:@"kSecValueData"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecValueRef) isEqualToString:@"kSecValueRef"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecValuePersistentRef) isEqualToString:@"kSecValuePersistentRef"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecReturnData) isEqualToString:@"kSecReturnData"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecReturnAttributes) isEqualToString:@"kSecReturnAttributes"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecReturnRef) isEqualToString:@"kSecReturnRef"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecReturnPersistentRef) isEqualToString:@"kSecReturnPersistentRef"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecUseItemList) isEqualToString:@"kSecUseItemList"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchPolicy) isEqualToString:@"kSecMatchPolicy"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchItemList) isEqualToString:@"kSecMatchItemList"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchSearchList) isEqualToString:@"kSecMatchSearchList"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchIssuers) isEqualToString:@"kSecMatchIssuers"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchEmailAddressIfPresent) isEqualToString:@"kSecMatchEmailAddressIfPresent"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchSubjectContains) isEqualToString:@"kSecMatchSubjectContains"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchCaseInsensitive) isEqualToString:@"kSecMatchCaseInsensitive"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchTrustedOnly) isEqualToString:@"kSecMatchTrustedOnly"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchValidOnDate) isEqualToString:@"kSecMatchValidOnDate"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchLimit) isEqualToString:@"kSecMatchLimit"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchLimitOne) isEqualToString:@"kSecMatchLimitOne"]);
    ASSERT_TRUE([static_cast<NSString*>(kSecMatchLimitAll) isEqualToString:@"kSecMatchLimitAll"]);
}