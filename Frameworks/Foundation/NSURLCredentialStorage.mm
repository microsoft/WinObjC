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

#import <Starboard.h>
#import <Windows.h>
#import <Foundation/NSURLCredentialStorage.h>

@interface NSURLCredentialStorage ()
@property (readwrite, copy) NSDictionary* allCredentials;
@end

NSString* const NSURLCredentialStorageChangedNotification = @"NSURLCredentialStorageChangedNotification";

@implementation NSURLCredentialStorage

NSString* const DEFAULT_CREDENTIALS = @"defaultCredentials";

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _allCredentials = [[NSMutableDictionary alloc] init];
    }
    return self;
}

/**
 @Status Interoperable
*/
+ (NSURLCredentialStorage*)sharedCredentialStorage {
    static NSURLCredentialStorage* sharedInstance = [[NSURLCredentialStorage alloc] init];
    return sharedInstance;
}

/**
 @Status Interoperable
*/
- (NSDictionary*)credentialsForProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    return [[_allCredentials objectForKey:protectionSpace] retain];
}

/**
 @Status Interoperable
*/
- (NSURLCredential*)defaultCredentialForProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    return [[[_allCredentials objectForKey:protectionSpace] objectForKey:DEFAULT_CREDENTIALS] retain];
}

/**
 @Status Interoperable
*/
- (NSDictionary*)_obtainValidCredentialForProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    NSDictionary* protectionSpaceValue = [_allCredentials objectForKey:protectionSpace];

    if (protectionSpaceValue == nil) {
        protectionSpaceValue = [NSMutableDictionary new];
        [_allCredentials setObject:protectionSpaceValue forKey:protectionSpace];
        [protectionSpaceValue release];
    }

    return [_allCredentials objectForKey:protectionSpace];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)anObject {
    if (self == anObject) {
        return YES;
    }
    if ((!anObject) || (![anObject isKindOfClass:[self class]])) {
        return NO;
    }
	
	NSURLCredentialStorage* object = (NSURLCredentialStorage*)anObject;
	return [_allCredentials isEqual:object.allCredentials];
}

- (NSUInteger)hash {
	return [_allCredentials hash];
}

/**
 @Status Interoperable
*/
- (void)setCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    NSDictionary* protectionSpaceValue = [self _obtainValidCredentialForProtectionSpace:protectionSpace];
    [protectionSpaceValue setObject:credential forKey:[credential user]];
}

/**
 @Status Interoperable
*/
- (void)setDefaultCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    NSDictionary* protectionSpaceValue = [self _obtainValidCredentialForProtectionSpace:protectionSpace];
    [protectionSpaceValue setObject:credential forKey:DEFAULT_CREDENTIALS];
}

/**
 @Status Interoperable
*/
- (void)removeCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    [[_allCredentials objectForKey:protectionSpace] removeObjectForKey:[credential user]];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_allCredentials release];
    [super dealloc];
}

@end