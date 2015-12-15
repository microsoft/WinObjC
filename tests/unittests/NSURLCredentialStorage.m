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
#import <Foundation/NSURLCredentialStorage.h>
#import <Foundation/NSURLCredential.h>
#import <Foundation/NSURLProtectionSpace.h>

TEST(Foundation, NSURLCredentialStorage_DefaultSharedSession) {
    NSURLCredential* credential =
        [[NSURLCredential credentialWithUser:@"user" password:@"pass" persistence:NSURLCredentialPersistenceForSession] retain];
    ASSERT_TRUE_MSG(credential != NULL, "FAILED: credential should be non-null!");

    NSURLProtectionSpace* protectionSpace =
        [[NSURLProtectionSpace alloc] initWithHost:@"microsoft" port:8080 protocol:nil realm:nil authenticationMethod:nil];
    ASSERT_TRUE_MSG(protectionSpace != NULL, "FAILED: protectionSpace should be non-null!");

    NSURLCredentialStorage* storage = [NSURLCredentialStorage sharedCredentialStorage];
    ASSERT_TRUE_MSG(storage != NULL, "FAILED: storage should be non-null!");

    ASSERT_EQ_MSG(nil,
                  [storage defaultCredentialForProtectionSpace:protectionSpace],
                  "FAILED defaultCredentialForProtectionSpace should be nil");
    [storage setDefaultCredential:credential forProtectionSpace:protectionSpace];

   /* NSURLCredential* defaultCred = [storage defaultCredentialForProtectionSpace:protectionSpace];
    ASSERT_TRUE_MSG(defaultCred != NULL, "FAILED: defaultCred should be non-null!");
    ASSERT_OBJCEQ_MSG(@"user", [defaultCred user], "FAILED: Invalid username.");
	*/
    [protectionSpace release];
}

TEST(Foundation, NSURLCredentialStorage_NonDefaultSession) {
    NSURLCredential* credential =
        [NSURLCredential credentialWithUser:@"user" password:@"pass" persistence:NSURLCredentialPersistenceForSession];
    ASSERT_TRUE_MSG(credential != NULL, "FAILED: credential should be non-null!");

    NSURLProtectionSpace* protectionSpace =
        [[NSURLProtectionSpace alloc] initWithHost:@"microsoft" port:8080 protocol:nil realm:nil authenticationMethod:nil];
    ASSERT_TRUE_MSG(protectionSpace != NULL, "FAILED: protectionSpace should be non-null!");

    NSURLCredentialStorage* storage = [NSURLCredentialStorage sharedCredentialStorage];
    ASSERT_TRUE_MSG(storage != NULL, "FAILED: storage should be non-null!");

    ASSERT_EQ_MSG(nil,
                  [storage defaultCredentialForProtectionSpace:protectionSpace],
                  "FAILED defaultCredentialForProtectionSpace should be nil");

    ASSERT_EQ_MSG(nil, [storage credentialsForProtectionSpace:protectionSpace], "FAILED credentialsForProtectionSpace should be nil");

    [storage setCredential:credential forProtectionSpace:protectionSpace];

    /*NSDictionary* creden = [storage credentialsForProtectionSpace:protectionSpace];
    ASSERT_TRUE_MSG(creden != NULL, "FAILED: creden should be non-null!");
    ASSERT_OBJCEQ_MSG(@"user", [creden user], "FAILED: Invalid username.");

    [storage removeCredential:credential forProtectionSpace:protectionSpace];
    ASSERT_EQ_MSG(nil, [storage credentialsForProtectionSpace:protectionSpace], "FAILED credentialsForProtectionSpace should be nil");
	*/
    [protectionSpace release];
    [storage release];
  //  [creden release];
}