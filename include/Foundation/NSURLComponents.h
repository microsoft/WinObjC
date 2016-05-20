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
@class NSURL;
@class NSNumber;
@class NSArray<ObjectType>;
@class NSURLQueryItem;

FOUNDATION_EXPORT_CLASS
@interface NSURLComponents : NSObject <NSCopying>
+ (instancetype)componentsWithString:(NSString*)URLString;
+ (instancetype)componentsWithURL:(NSURL*)url resolvingAgainstBaseURL:(BOOL)resolve;
- (instancetype)init;
- (instancetype)initWithString:(NSString*)URLString;
- (instancetype)initWithURL:(NSURL*)url resolvingAgainstBaseURL:(BOOL)resolve;
@property (readonly, copy) NSString* string;
@property (readonly, copy) NSURL* URL;
- (NSURL*)URLRelativeToURL:(NSURL*)baseURL;
@property (copy) NSString* fragment;
@property (copy) NSString* host;
@property (copy) NSString* password;
@property (copy) NSString* path;
@property (copy) NSNumber* port;
@property (copy) NSString* query;
@property (copy) NSArray<NSURLQueryItem*>* queryItems;
@property (copy) NSString* scheme;
@property (copy) NSString* user;
@property (copy) NSString* percentEncodedFragment;
@property (copy) NSString* percentEncodedHost;
@property (copy) NSString* percentEncodedPassword;
@property (copy) NSString* percentEncodedPath;
@property (copy) NSString* percentEncodedQuery;
@property (copy) NSString* percentEncodedUser;
@end
