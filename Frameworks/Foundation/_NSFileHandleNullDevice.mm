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
#import <_NSFileHandleNullDevice.h>
#import <Foundation/NSData.h>

@implementation _NSFileHandleNullDevice

/**
 @Status Interoperable
*/
- (NSData*)availableData {
    return [NSData data];
}

/**
 @Status Interoperable
*/
- (void)seekToFileOffset:(unsigned long long)offset {
    // no-op
}

/**
 @Status Interoperable
*/
- (void)truncateFileAtOffset:(unsigned long long)size {
    // no-op
}

/**
 @Status Interoperable
*/
- (unsigned long long)offsetInFile {
    return 0;
}

/**
 @Status Interoperable
*/
- (unsigned long long)seekToEndOfFile {
    return 0;
}

/**
 @Status Interoperable
*/
- (int)fileDescriptor {
    return -1;
}

/**
 @Status Interoperable
*/
- (void)synchronizeFile {
    // no-op
}

/**
 @Status Interoperable
*/
- (NSData*)readDataOfLength:(NSUInteger)len {
    return [NSData data];
}

/**
 @Status Interoperable
*/
- (NSData*)readDataToEndOfFile {
    return [NSData data];
}

/**
 @Status Interoperable
*/
- (void)writeData:(NSData*)data {
    // no-op
}

/**
 @Status Interoperable
*/
- (void)closeFile {
    // no-op
}
@end