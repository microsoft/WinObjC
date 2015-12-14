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

#include "NSData.h"

@interface NSMutableData : NSData {
@public
    DWORD _capacity;
}
- (instancetype)initWithLength:(unsigned)length;
- (instancetype)initWithCapacity:(unsigned)length;
- (void)appendBytes:(const char*)bytes length:(unsigned)length;
- (void)appendData:(NSData*)data;
- (void)setData:(NSData*)data;
- (void)setLength:(unsigned)length;
- (void)increaseLengthBy:(unsigned)length;
- (void)replaceBytesInRange:(NSRange)range withBytes:(void*)bytes;
- (void)replaceBytesInRange:(NSRange)aRange withBytes:(void*)bytes length:(unsigned)length;
- (uint8_t*)mutableBytes;
- (id)copyWithZone:(id)zone;
+ (instancetype)data;
+ (instancetype)dataWithLength:(unsigned)length;
+ (instancetype)dataWithCapacity:(unsigned)capacity;
@end
