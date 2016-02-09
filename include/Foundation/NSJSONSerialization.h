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

@class NSData;
@class NSError;
@class NSInputStream;
@class NSOutputStream;

typedef NSUInteger NSJSONReadingOptions;
typedef NSUInteger NSJSONWritingOptions;
enum { NSJSONReadingMutableContainers = (1UL << 0), NSJSONReadingMutableLeaves = (1UL << 1), NSJSONReadingAllowFragments = (1UL << 2) };
enum { NSJSONWritingPrettyPrinted = (1UL << 0) };

FOUNDATION_EXPORT_CLASS
@interface NSJSONSerialization : NSObject
+ (id)JSONObjectWithData:(NSData*)data options:(NSJSONReadingOptions)opt error:(NSError* _Nullable*)error;
+ (id)JSONObjectWithStream:(NSInputStream*)stream options:(NSJSONReadingOptions)opt error:(NSError* _Nullable*)error STUB_METHOD;
+ (NSData*)dataWithJSONObject:(id)obj options:(NSJSONWritingOptions)opt error:(NSError* _Nullable*)error;
+ (NSInteger)writeJSONObject:(id)obj
                    toStream:(NSOutputStream*)stream
                     options:(NSJSONWritingOptions)opt
                       error:(NSError* _Nullable*)error STUB_METHOD;
+ (BOOL)isValidJSONObject:(id)obj;
@end
