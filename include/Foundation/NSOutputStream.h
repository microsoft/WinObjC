//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <Foundation/NSStream.h>

@interface NSOutputStream : NSStream

@property (readonly) BOOL hasSpaceAvailable;

- (instancetype)initToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity;
- (instancetype)initToFileAtPath:(NSString*)path append:(BOOL)append;
- (instancetype)initToMemory;
- (instancetype)initWithURL:(NSURL*)url append:(BOOL)shouldAppend;

+ (instancetype)outputStreamToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity;
+ (instancetype)outputStreamToFileAtPath:(NSString*)path append:(BOOL)append;
+ (instancetype)outputStreamToMemory;
+ (instancetype)outputStreamWithURL:(NSURL*)url append:(BOOL)shouldAppend;

- (NSInteger)write:(const uint8_t*)buffer maxLength:(NSUInteger)length;

@end
