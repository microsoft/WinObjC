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
#import <Foundation/NSCopying.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSURL;
@class NSNumber;
@class NSArray;

FOUNDATION_EXPORT_CLASS
@interface NSURLComponents : NSObject <NSCopying>
+ (instancetype)componentsWithString:(NSString*)URLString STUB_METHOD;
+ (instancetype)componentsWithURL:(NSURL*)url resolvingAgainstBaseURL:(BOOL)resolve STUB_METHOD;
- (instancetype)init STUB_METHOD;
- (instancetype)initWithString:(NSString*)URLString STUB_METHOD;
- (instancetype)initWithURL:(NSURL*)url resolvingAgainstBaseURL:(BOOL)resolve STUB_METHOD;
@property (readonly, copy) NSString* string STUB_PROPERTY;
@property (readonly, copy) NSURL* URL STUB_PROPERTY;
- (NSURL*)URLRelativeToURL:(NSURL*)baseURL STUB_METHOD;
@property (copy) NSString* fragment STUB_PROPERTY;
@property (copy) NSString* host STUB_PROPERTY;
@property (copy) NSString* password STUB_PROPERTY;
@property (copy) NSString* path STUB_PROPERTY;
@property (copy) NSNumber* port STUB_PROPERTY;
@property (copy) NSString* query STUB_PROPERTY;
@property (copy) NSArray* queryItems STUB_PROPERTY;
@property (copy) NSString* scheme STUB_PROPERTY;
@property (copy) NSString* user STUB_PROPERTY;
@property (copy) NSString* percentEncodedFragment STUB_PROPERTY;
@property (copy) NSString* percentEncodedHost STUB_PROPERTY;
@property (copy) NSString* percentEncodedPassword STUB_PROPERTY;
@property (copy) NSString* percentEncodedPath STUB_PROPERTY;
@property (copy) NSString* percentEncodedQuery STUB_PROPERTY;
@property (copy) NSString* percentEncodedUser STUB_PROPERTY;
@end
