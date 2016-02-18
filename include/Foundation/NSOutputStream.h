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
#import <Foundation/NSStream.h>

@class NSString;
@class NSURL;

FOUNDATION_EXPORT_CLASS
@interface NSOutputStream : NSStream
+ (instancetype)outputStreamToMemory;
+ (instancetype)outputStreamToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity;
+ (instancetype)outputStreamToFileAtPath:(NSString*)path append:(BOOL)shouldAppend;
+ (instancetype)outputStreamWithURL:(NSURL*)url append:(BOOL)shouldAppend;
- (instancetype)initToMemory;
- (instancetype)initToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity;
- (instancetype)initToFileAtPath:(NSString*)path append:(BOOL)shouldAppend;
- (instancetype)initWithURL:(NSURL*)url append:(BOOL)shouldAppend;
@property (readonly) BOOL hasSpaceAvailable;
- (NSInteger)write:(const uint8_t*)buffer maxLength:(NSUInteger)length;
@end
