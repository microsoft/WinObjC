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
#import <Foundation/NSNetService.h>
#import <Foundation/NSObject.h>

@protocol NSNetServiceBrowserDelegate;
@class NSString;
@class NSRunLoop;

FOUNDATION_EXPORT_CLASS
@interface NSNetServiceBrowser : NSObject
- (instancetype)init STUB_METHOD;
@property (assign) id<NSNetServiceBrowserDelegate> delegate STUB_PROPERTY;
- (void)searchForBrowsableDomains STUB_METHOD;
- (void)searchForRegistrationDomains STUB_METHOD;
- (void)searchForServicesOfType:(NSString*)serviceType inDomain:(NSString*)domainName STUB_METHOD;
- (void)stop STUB_METHOD;
- (void)scheduleInRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)runLoopMode STUB_METHOD;
- (void)removeFromRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)runLoopMode STUB_METHOD;
@end

@protocol NSNetServiceBrowserDelegate <NSObject>
@optional
- (void)netServiceBrowser:(NSNetServiceBrowser*)netServiceBrowser didFindDomain:(NSString*)domainName moreComing:(BOOL)moreDomainsComing;
- (void)netServiceBrowser:(NSNetServiceBrowser*)netServiceBrowser didRemoveDomain:(NSString*)domainName moreComing:(BOOL)moreDomainsComing;
- (void)netServiceBrowser:(NSNetServiceBrowser*)netServiceBrowser
           didFindService:(NSNetService*)netService
               moreComing:(BOOL)moreServicesComing;
- (void)netServiceBrowser:(NSNetServiceBrowser*)netServiceBrowser
         didRemoveService:(NSNetService*)netService
               moreComing:(BOOL)moreServicesComing;
- (void)netServiceBrowserWillSearch:(NSNetServiceBrowser*)netServiceBrowser;
- (void)netServiceBrowser:(NSNetServiceBrowser*)netServiceBrowser didNotSearch:(NSDictionary*)errorInfo;
- (void)netServiceBrowserDidStopSearch:(NSNetServiceBrowser*)netServiceBrowser;
@end
