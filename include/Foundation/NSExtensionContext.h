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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSError;
@class NSArray;
@class NSURL;

FOUNDATION_EXPORT NSString* const NSExtensionItemsAndErrorsKey;
// Missing declaration of //apple_ref/c/data/NSExtensionHostDidBecomeActiveNotification
// Missing declaration of //apple_ref/c/data/NSExtensionHostWillResignActiveNotification
// Missing declaration of //apple_ref/c/data/NSExtensionHostDidEnterBackgroundNotification
// Missing declaration of //apple_ref/c/data/NSExtensionHostWillEnterForegroundNotification

FOUNDATION_EXPORT_CLASS
@interface NSExtensionContext : NSObject
- (void)cancelRequestWithError:(NSError*)error STUB_METHOD;
- (void)completeRequestReturningItems:(NSArray*)items completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (void)openURL:(NSURL*)URL completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* inputItems STUB_PROPERTY;
@end
