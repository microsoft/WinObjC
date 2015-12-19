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
#import <CoreFoundation/CoreFoundation.h>
#import <Security/SecItem.h>
#import "Frameworks/Security/GenericPasswordItemHandler.h"

@interface MockVault : NSObject

+ (instancetype)create ACTIVATOR;
- (void)add:(WSCPasswordCredential*)credential;
- (void)remove:(WSCPasswordCredential*)credential;
- (WSCPasswordCredential*)retrieve:(NSString*)resource userName:(NSString*)userName;
- (NSArray*)findAllByResource:(NSString*)resource;
- (NSArray*)findAllByUserName:(NSString*)userName;
- (NSArray*)retrieveAll;
- (instancetype)init;

@end

@implementation MockVault {
    NSMutableArray* credentialList;
}

+ (instancetype)create {
    return nil;
}

- (void)add:(WSCPasswordCredential*)credential {
    [credentialList addObject:credential];
}

- (void)remove:(WSCPasswordCredential*)credential {
    [credentialList removeObject:credential];
}

- (WSCPasswordCredential*)retrieve:(NSString*)resource userName:(NSString*)userName {
    return nil;
}

- (NSArray*)findAllByResource:(NSString*)resource {
    return nil;
}

- (NSArray*)findAllByUserName:(NSString*)userName {
    return nil;
}

- (NSArray*)retrieveAll {
    return credentialList;
}

- (void)dealloc {
    [credentialList release];
    credentialList = nil;

    [super dealloc];
}

- (instancetype)init {
    if (self = [super init]) {
        credentialList = [NSMutableArray new];
    }
    return self;
}

@end

TEST(Security, GenericPasswordHandler_Add) {
    MockVault* mockVault = [MockVault new];
    GenericPasswordItemHandler* handler = [[GenericPasswordItemHandler alloc] initWithVault:reinterpret_cast<WSCPasswordVault*>(mockVault)];

    // First try to add the credential.
    NSString* mockPassword = @"fak3Passw0rd";

    NSDictionary* dictionary = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"fakeAccount@fakeEmail.com",
        (__bridge id)(kSecAttrService) : @"www.fakeWebService.com",
        (__bridge id)(kSecValueData) : [mockPassword dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    id idOutDictionary;
    [handler add:dictionary withResult:&idOutDictionary];

    NSDictionary* outDictionary = static_cast<NSDictionary*>(idOutDictionary);

    // Make sure that the returned attributes match what is set. NOTE: normally
    // extra read only attributes like creation time would have been added. This
    // is not possible with the current WinRT apis.
    ASSERT_OBJCEQ((__bridge id)(kSecClassGenericPassword), [outDictionary objectForKey:(__bridge id)(kSecClass)]);
    ASSERT_OBJCEQ(@"fakeAccount@fakeEmail.com", [outDictionary objectForKey:(__bridge id)(kSecAttrAccount)]);
    ASSERT_OBJCEQ(@"www.fakeWebService.com", [outDictionary objectForKey:(__bridge id)(kSecAttrService)]);

    [outDictionary release];
    [dictionary release];
    [mockVault release];
    [handler release];
}

TEST(Security, GenericPasswordHandler_AddEmpty) {
    MockVault* mockVault = [MockVault new];
    GenericPasswordItemHandler* handler = [[GenericPasswordItemHandler alloc] initWithVault:reinterpret_cast<WSCPasswordVault*>(mockVault)];

    // First try to add the credential.
    NSString* mockPassword = @"fak3Passw0rd";

    // Go Crazy and have empty username and service.
    NSDictionary* dictionary = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrService) : @"",
        (__bridge id)(kSecValueData) : [mockPassword dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    id idOutDictionary;
    [handler add:dictionary withResult:&idOutDictionary];

    NSDictionary* outDictionary = static_cast<NSDictionary*>(idOutDictionary);

    // Make sure that the returned attributes match what is set. NOTE: normally
    // extra read only attributes like creation time would have been added. This
    // is not possible with the current WinRT apis.
    // Note that its a little weird that @"" doesn't come back but there is no way for us to tell.
    ASSERT_EQ(1, [outDictionary count]);
    ASSERT_OBJCEQ((__bridge id)(kSecClassGenericPassword), [outDictionary objectForKey:(__bridge id)(kSecClass)]);

    [outDictionary release];
    [dictionary release];
    [mockVault release];
    [handler release];
}

TEST(Security, GenericPasswordHandler_Query) {
    MockVault* mockVault = [MockVault new];
    GenericPasswordItemHandler* handler = [[GenericPasswordItemHandler alloc] initWithVault:reinterpret_cast<WSCPasswordVault*>(mockVault)];

    // First try to add the credentials.
    NSString* mockPassword1 = @"fak3Passw0rd1";
    NSString* mockPassword2 = @"fak3Passw0rd2";
    NSString* mockPassword3 = @"fak3Passw0rd3";

    NSDictionary* credential1 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"fakeAccount@fakeEmail.com",
        (__bridge id)(kSecAttrService) : @"www.fakeWebService.com",
        (__bridge id)(kSecValueData) : [mockPassword1 dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    NSDictionary* credential2 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"fakeAccount@fakeEmail.com",
        (__bridge id)(kSecAttrService) : @"www.ADifferentFakeWebService.com",
        (__bridge id)(kSecValueData) : [mockPassword2 dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    NSDictionary* credential3 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"ADifferentFakeAccount@fakeEmail.com",
        (__bridge id)(kSecAttrService) : @"www.fakeWebService.com",
        (__bridge id)(kSecValueData) : [mockPassword3 dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    [handler add:credential1 withResult:nil];
    [handler add:credential2 withResult:nil];
    [handler add:credential3 withResult:nil];

    // Now that its added go ahead and query. Start with a basic query for the info set.
    NSDictionary* attrQuery1 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrService) : @"www.fakeWebService.com",
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
        (__bridge id)(kSecMatchLimit) : (__bridge id)kSecMatchLimitOne,
    };

    // lmiit one specified so just go directly to dictionary.
    NSDictionary* attributes;
    [handler query:attrQuery1 withResult:&attributes];

    // Make sure that the returned attributes match what is set.
    // Note that this assumes return order is the same as add order which isn't necessarily true
    // but will be for the mock.
    ASSERT_OBJCEQ((__bridge id)(kSecClassGenericPassword), [attributes objectForKey:(__bridge id)(kSecClass)]);
    ASSERT_OBJCEQ(@"fakeAccount@fakeEmail.com", [attributes objectForKey:(__bridge id)(kSecAttrAccount)]);
    ASSERT_OBJCEQ(@"www.fakeWebService.com", [attributes objectForKey:(__bridge id)(kSecAttrService)]);

    [attributes release];
    [attrQuery1 release];

    // Now query for password data and match multiple
    NSDictionary* dataQuery1 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"fakeAccount@fakeEmail.com",
        (__bridge id)(kSecReturnData) : (__bridge id)kCFBooleanTrue,
        (__bridge id)(kSecMatchLimit) : (__bridge id)kSecMatchLimitAll,
    };

    NSArray* outArray;
    [handler query:dataQuery1 withResult:&outArray];
    ASSERT_EQ(2, [outArray count]);

    // Note that this assumes return order is the same as add order which isn't necessarily true
    // but will be for the mock.
    ASSERT_OBJCEQ([[mockPassword1 dataUsingEncoding:NSUTF8StringEncoding] autorelease], [outArray objectAtIndex:0]);
    ASSERT_OBJCEQ([[mockPassword2 dataUsingEncoding:NSUTF8StringEncoding] autorelease], [outArray objectAtIndex:1]);

    [outArray release];
    [dataQuery1 release];

    outArray = nil;

    // Query for something not there.
    NSDictionary* attrQuery2 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrService) : @"www.aNonExistentWebService.com",
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
        (__bridge id)(kSecMatchLimit) : (__bridge id)kSecMatchLimitOne,
    };

    OSStatus result = [handler query:attrQuery2 withResult:&outArray];
    ASSERT_EQ(result, errSecItemNotFound);
    ASSERT_EQ(nil, outArray);

    [attrQuery2 release];

    [credential1 release];
    [credential2 release];
    [credential3 release];
    [mockVault release];
    [handler release];
}

TEST(Security, GenericPasswordHandler_Update) {
    MockVault* mockVault = [MockVault new];
    GenericPasswordItemHandler* handler = [[GenericPasswordItemHandler alloc] initWithVault:reinterpret_cast<WSCPasswordVault*>(mockVault)];

    // First try to add the credential.
    NSString* mockPassword = @"fak3Passw0rd";

    NSDictionary* dictionary = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"fakeAccount@fakeEmail.com",
        (__bridge id)(kSecAttrService) : @"www.fakeWebService.com",
        (__bridge id)(kSecValueData) : [mockPassword dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    [handler add:dictionary withResult:nil];

    NSDictionary* updateDictionary = @{
        (__bridge id)(kSecAttrService) : @"www.anUpdatedFakeWebService.com",
    };

    NSDictionary* updateQuery = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrService) : @"www.fakeWebService.com",
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
        (__bridge id)(kSecMatchLimit) : (__bridge id)kSecMatchLimitOne,
    };

    [handler update:updateQuery withAttributes:updateDictionary];

    // Query for results.
    NSDictionary* queryDictionary = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrService) : @"www.anUpdatedFakeWebService.com",
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
        (__bridge id)(kSecMatchLimit) : (__bridge id)kSecMatchLimitOne,
    };

    NSDictionary* attributes;
    [handler query:queryDictionary withResult:&attributes];

    ASSERT_OBJCEQ((__bridge id)(kSecClassGenericPassword), [attributes objectForKey:(__bridge id)(kSecClass)]);
    ASSERT_OBJCEQ(@"fakeAccount@fakeEmail.com", [attributes objectForKey:(__bridge id)(kSecAttrAccount)]);
    ASSERT_OBJCEQ(@"www.anUpdatedFakeWebService.com", [attributes objectForKey:(__bridge id)(kSecAttrService)]);

    [attributes release];
    [queryDictionary release];
    [updateQuery release];
    [updateDictionary release];
    [dictionary release];
    [mockVault release];
    [handler release];
}

TEST(Security, GenericPasswordHandler_Remove) {
    MockVault* mockVault = [MockVault new];
    GenericPasswordItemHandler* handler = [[GenericPasswordItemHandler alloc] initWithVault:reinterpret_cast<WSCPasswordVault*>(mockVault)];

    NSString* mockPassword1 = @"fak3Passw0rd1";
    NSString* mockPassword2 = @"fak3Passw0rd2";
    NSString* mockPassword3 = @"fak3Passw0rd3";

    NSDictionary* credential1 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"fakeAccount@fakeEmail.com",
        (__bridge id)(kSecAttrService) : @"www.fakeWebService.com",
        (__bridge id)(kSecValueData) : [mockPassword1 dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    NSDictionary* credential2 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"fakeAccount@fakeEmail.com",
        (__bridge id)(kSecAttrService) : @"www.ADifferentFakeWebService.com",
        (__bridge id)(kSecValueData) : [mockPassword2 dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    NSDictionary* credential3 = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecAttrAccount) : @"ADifferentFakeAccount@fakeEmail.com",
        (__bridge id)(kSecAttrService) : @"www.fakeWebService.com",
        (__bridge id)(kSecValueData) : [mockPassword3 dataUsingEncoding:NSUTF8StringEncoding],
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
    };

    [handler add:credential1 withResult:nil];
    [handler add:credential2 withResult:nil];
    [handler add:credential3 withResult:nil];

    NSDictionary* removeQuery = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
    };

    [handler remove:removeQuery];

    // Query for results.
    NSDictionary* queryDictionary = @{
        (__bridge id)(kSecClass) : (__bridge id)(kSecClassGenericPassword),
        (__bridge id)(kSecReturnAttributes) : (__bridge id)kCFBooleanTrue,
        (__bridge id)(kSecMatchLimit) : (__bridge id)kSecMatchLimitAll,
    };

    NSArray* outArray = nil;
    OSStatus result = [handler query:queryDictionary withResult:&outArray];
    ASSERT_EQ(result, errSecItemNotFound);
    ASSERT_EQ(nil, outArray);

    [removeQuery release];
    [queryDictionary release];
    [credential1 release];
    [credential2 release];
    [credential3 release];
    [mockVault release];
    [handler release];
}