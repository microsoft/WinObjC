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

// TODO: Task 7188763-Reimplement CGDataProvider which does not inherit from NSData but rather uses it within itself.
@interface CGDataProvider : NSData {
@public
    CGDataProviderReleaseDataCallback releaseFunc;
    void* info;
    size_t size;
    const void* data;
    StrongId<NSString> filename;
    StrongId<NSData> _data;
}
- (NSString*)_fileName;

- (instancetype)init;
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
- (const void*)bytes;
- (NSUInteger)length;

@end
