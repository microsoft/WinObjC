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

@class NSURLRequest;
@class NSCachedURLResponse;
@protocol NSURLProtocolClient;
@class NSString;
@class NSMutableURLRequest;

FOUNDATION_EXPORT_CLASS
@interface NSURLProtocol : NSObject
- (instancetype)initWithRequest:(NSURLRequest*)request
                 cachedResponse:(NSCachedURLResponse*)cachedResponse
                         client:(id<NSURLProtocolClient>)client;
+ (BOOL)registerClass:(Class)protocolClass STUB_METHOD;
+ (void)unregisterClass:(Class)protocolClass STUB_METHOD;
+ (BOOL)canInitWithRequest:(NSURLRequest*)request STUB_METHOD;
+ (id)propertyForKey:(NSString*)key inRequest:(NSURLRequest*)request STUB_METHOD;
+ (void)setProperty:(id)value forKey:(NSString*)key inRequest:(NSMutableURLRequest*)request STUB_METHOD;
+ (void)removePropertyForKey:(NSString*)key inRequest:(NSMutableURLRequest*)request STUB_METHOD;
+ (NSURLRequest*)canonicalRequestForRequest:(NSURLRequest*)request STUB_METHOD;
+ (BOOL)requestIsCacheEquivalent:(NSURLRequest*)aRequest toRequest:(NSURLRequest*)bRequest STUB_METHOD;
- (void)startLoading STUB_METHOD;
- (void)stopLoading STUB_METHOD;
@property (readonly, copy) NSCachedURLResponse* cachedResponse;
@property (readonly, retain) id<NSURLProtocolClient> client;
@property (readonly, copy) NSURLRequest* request;
@end
