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

@interface NSData : NSObject {
@public
    uint8_t* _bytes;
    size_t _length;
    BOOL _freeWhenDone;
}
- (instancetype)init;
- (instancetype)initWithData:(NSData*)data;
- (instancetype)initWithBytes:(const uint8_t*)bytes length:(unsigned)length;
- (void)encodeWithCoder:(NSCoder*)coder;
- (instancetype)initWithCoder:(NSCoder*)coder;
- (instancetype)initWithBytesNoCopy:(const uint8_t*)bytes length:(unsigned)length freeWhenDone:(BOOL)freeWhenDone;
- (instancetype)initWithBytesNoCopy:(const uint8_t*)bytes length:(unsigned)length;
- (void)getBytes:(void*)dest;
- (void)getBytes:(void*)dest length:(unsigned)length;
- (void)getBytes:(void*)dest range:(NSRange)range;
- (instancetype)initWithContentsOfMappedFile:(NSString*)filename;
- (instancetype)initWithContentsOfFile:(NSString*)filename;
- (BOOL)writeToFile:(NSString*)filename atomically:(BOOL)atomically;
- (BOOL)writeToURL:(NSURL*)url atomically:(BOOL)atomically;
- (BOOL)writeToFile:(NSString*)filename options:(unsigned)options error:(NSError**)error;
- (instancetype)initWithContentsOfFile:(NSString*)filename options:(unsigned)options error:(NSError**)error;
- (instancetype)initWithContentsOfURL:(NSURL*)url;
- (instancetype)initWithContentsOfURL:(NSURL*)url options:(unsigned)options error:(id*)error;
- (instancetype)subdataWithRange:(NSRange)range;
- (id)copyWithZone:(NSZone*)zone;
- (NSMutableData*)mutableCopyWithZone:(id)zone;
- (BOOL)isEqualToData:(NSData*)data;
- (BOOL)isEqual:(id)objAddr;
- (NSString*)description;
- (uint8_t*)bytes;
- (unsigned)length;
- (void)dealloc;
+ (instancetype)dataWithData:(NSData*)data;
+ (instancetype)data;
+ (instancetype)dataWithBytes:(const uint8_t*)bytes length:(unsigned)length;
+ (instancetype)dataWithBytesNoCopy:(const uint8_t*)bytes length:(unsigned)length;
+ (instancetype)dataWithBytesNoCopy:(const uint8_t*)bytes length:(unsigned)length freeWhenDone:(BOOL)free;
+ (instancetype)dataWithContentsOfFile:(NSString*)filename;
+ (instancetype)dataWithContentsOfMappedFile:(NSString*)filename;
+ (instancetype)dataWithContentsOfFile:(NSString*)filename options:(unsigned)options error:(id*)error;
+ (instancetype)dataWithContentsOfURL:(NSURL*)url options:(unsigned)options error:(id*)error;
+ (instancetype)dataWithContentsOfURL:(NSURL*)url;
@end
