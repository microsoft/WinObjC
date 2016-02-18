//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSURLCredential;
@class NSURLProtectionSpace;
@class NSDictionary;

FOUNDATION_EXPORT NSString* const NSURLCredentialStorageRemoveSynchronizableCredentials;
FOUNDATION_EXPORT NSString* const NSURLCredentialStorageChangedNotification;

FOUNDATION_EXPORT_CLASS
@interface NSURLCredentialStorage : NSObject
+ (NSURLCredentialStorage*)sharedCredentialStorage;
- (NSURLCredential*)defaultCredentialForProtectionSpace:(NSURLProtectionSpace*)protectionSpace;
- (void)setDefaultCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace;
- (void)removeCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace;
- (void)removeCredential:(NSURLCredential*)credential
      forProtectionSpace:(NSURLProtectionSpace*)protectionSpace
                 options:(NSDictionary*)options STUB_METHOD;
- (void)setCredential:(NSURLCredential*)credential forProtectionSpace:(NSURLProtectionSpace*)protectionSpace;
@property (readonly, copy) NSDictionary* allCredentials;
- (NSDictionary*)credentialsForProtectionSpace:(NSURLProtectionSpace*)protectionSpace;
@end
