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

#import <Foundation/NSURLCredentialStorage.h>
#import <Starboard.h>
#import <Windows.h>

@implementation NSURLCredentialStorage

- (instancetype)init {
    self = [super init];
    return self;
}

+ (NSURLCredentialStorage*)sharedCredentialStorage {
    return [[[NSURLCredentialStorage alloc] init] autorelease];
}

- (NSDictionary*)allCredentials {
    UNIMPLEMENTED();
    return nil;
}

- (NSDictionary*)credentialsForProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    UNIMPLEMENTED();
    return nil;
}

- (NSURLCredential*)defaultCredentialForProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    UNIMPLEMENTED();
    return nil;
}

- (void)setCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    UNIMPLEMENTED();
}

- (void)setDefaultCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    UNIMPLEMENTED();
}

- (void)removeCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace {
    UNIMPLEMENTED();
}

@end