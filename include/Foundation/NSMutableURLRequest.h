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
#import <Foundation/NSURLRequest.h>

@class NSURL;
@class NSString;
@class NSDictionary;
@class NSData;
@class NSInputStream;

FOUNDATION_EXPORT_CLASS
@interface NSMutableURLRequest : NSURLRequest <NSCopying, NSMutableCopying, NSSecureCoding>
@property NSURLRequestCachePolicy cachePolicy;
@property (copy) NSURL* mainDocumentURL;
@property NSURLRequestNetworkServiceType networkServiceType;
@property NSTimeInterval timeoutInterval;
@property (copy) NSURL* URL;
@property BOOL allowsCellularAccess;
- (void)addValue:(NSString*)value forHTTPHeaderField:(NSString*)field;
@property (copy) NSDictionary* allHTTPHeaderFields;
@property (copy) NSData* HTTPBody;
@property (retain) NSInputStream* HTTPBodyStream;
@property (copy) NSString* HTTPMethod;
@property BOOL HTTPShouldHandleCookies;
@property BOOL HTTPShouldUsePipelining;
- (void)setValue:(NSString*)value forHTTPHeaderField:(NSString*)field;
@end
