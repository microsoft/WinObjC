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
#import <Foundation/NSURLCredential.h>

TEST(Foundation, NSURLCredential_credentialWithUser) {
    NSString* user = @"user";
    NSString* pass = @"pass";
    NSURLCredential* credential = [NSURLCredential credentialWithUser:user password:pass persistence:NSURLCredentialPersistenceForSession];
    ASSERT_TRUE_MSG(credential != NULL, "FAILED: credential should be non-null!");

    ASSERT_OBJCEQ_MSG(user, [credential user], "FAILED: User name is not valid");
    ASSERT_OBJCEQ_MSG(pass, [credential password], "FAILED: password is not valid");
    ASSERT_EQ_MSG(NSURLCredentialPersistenceForSession, [credential persistence], "FAILED: persistence is not valid");
    ASSERT_EQ_MSG(YES, [credential hasPassword], "FAILED: hasPassword is not the expected value");
    ASSERT_EQ_MSG(nil, [credential identity], "FAILED: identity not null");
    ASSERT_EQ_MSG(nil, [credential certificates], "FAILED: certificates not null");
}

TEST(Foundation, NSURLCredential_credentialWithIdentity) {
    NSArray* certs = [NSMutableArray array];
    NSURLCredential* credential =
        [NSURLCredential credentialWithIdentity:nullptr certificates:(NSArray*)certs persistence:NSURLCredentialPersistencePermanent];

    ASSERT_TRUE_MSG(credential != NULL, "FAILED: credential should be non-null!");
    ASSERT_EQ_MSG(nil, [credential user], "FAILED: User name is not null");
    ASSERT_EQ_MSG(nil, [credential password], "FAILED: password is not null");
    ASSERT_EQ_MSG(NSURLCredentialPersistencePermanent, [credential persistence], "FAILED: persistence is not valid");
    ASSERT_EQ_MSG(NO, [credential hasPassword], "FAILED: hasPassword is not the expected value");
    ASSERT_EQ_MSG(nil, [credential identity], "FAILED: identity not null");
    ASSERT_TRUE_MSG(([credential certificates] != nil), "FAILED: certificates should be non null");
}

TEST(Foundation, NSURLCredential_credentialForTrust) {
    NSURLCredential* credential = [NSURLCredential credentialForTrust:nullptr];

    ASSERT_TRUE_MSG(credential != NULL, "FAILED: credential should be non-null!");
    ASSERT_EQ_MSG(nil, [credential user], "FAILED: User name is not null");
    ASSERT_EQ_MSG(nil, [credential password], "FAILED: password is not null");
    ASSERT_EQ_MSG(NSURLCredentialPersistenceNone, [credential persistence], "FAILED: persistence is not valid");
    ASSERT_EQ_MSG(NO, [credential hasPassword], "FAILED: hasPassword is not the expected value");
    ASSERT_EQ_MSG(nil, [credential identity], "FAILED: identity not null");
    ASSERT_EQ_MSG(nil, [credential trust], "FAILED: trust not null");
}