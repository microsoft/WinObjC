//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>

@class NSURL;
@class NSDictionary;
@class NSError;
@class NSString;

UIKIT_EXPORT_CLASS
@interface NSFileProviderExtension : NSObject
+ (NSURL*)placeholderURLForURL:(NSURL*)url STUB_METHOD;
+ (BOOL)writePlaceholderAtURL:(NSURL*)placeholderURL withMetadata:(NSDictionary*)metadata error:(NSError* _Nullable*)error STUB_METHOD;
- (NSURL*)documentStorageURL STUB_METHOD;
- (NSString*)providerIdentifier STUB_METHOD;
- (NSString*)persistentIdentifierForItemAtURL:(NSURL*)url STUB_METHOD;
- (NSURL*)URLForItemWithPersistentIdentifier:(NSString*)identifier STUB_METHOD;
- (void)itemChangedAtURL:(NSURL*)url STUB_METHOD;
- (void)providePlaceholderAtURL:(NSURL*)url completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)startProvidingItemAtURL:(NSURL*)url completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)stopProvidingItemAtURL:(NSURL*)url STUB_METHOD;
@end
