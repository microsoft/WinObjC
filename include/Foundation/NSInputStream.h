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

#import <Foundation/NSStream.h>

@class NSData;
@class NSString;
@class NSURL;

FOUNDATION_EXPORT_CLASS
@interface NSInputStream : NSStream

+ (instancetype)inputStreamWithData:(NSData*)data;
+ (instancetype)inputStreamWithFileAtPath:(NSString*)path;
+ (instancetype)inputStreamWithURL:(NSURL*)url;
- (instancetype)initWithData:(NSData*)data;
- (instancetype)initWithFileAtPath:(NSString*)path;
- (instancetype)initWithURL:(NSURL*)url;
- (NSInteger)read:(uint8_t*)buffer maxLength:(NSUInteger)len;
- (BOOL)getBuffer:(uint8_t* _Nullable*)buffer length:(NSUInteger*)len;
@property (readonly) BOOL hasBytesAvailable;
@end
