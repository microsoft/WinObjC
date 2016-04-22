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

#import <StubReturn.h>
#import <Starboard.h>
#import <Foundation/NSData.h>
#import <Foundation/NSString.h>
#include "LoggingNative.h"
#import <CoreGraphics/CGDataProvider.h>
#import "CGDataProviderInternal.h"

static const wchar_t* TAG = L"CGDataProvider";

// TODO: Task 7188763-Reimplement CGDataProvider which does not inherit from NSData but rather uses it within itself.
@implementation CGDataProvider : NSData
- (void)dealloc {
    if (releaseFunc != 0) {
        releaseFunc(info, data, size);
    }
    filename = nil;
    [super dealloc];
}

- (NSString*)_fileName {
    return filename;
}

- (instancetype)init {
    return [self initWithBytes:"" length:0];
}

- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    if (self = [super init]) {
        _data.attach([[NSData alloc] initWithBytesNoCopy:bytes length:length freeWhenDone:freeWhenDone]);
    }
    return self;
}

- (const void*)bytes {
    return [_data bytes];
}

- (NSUInteger)length {
    return [_data length];
}

@end

/**
 @Status Caveat
 @Notes Only supports file:/// URLs
*/
CGDataProviderRef CGDataProviderCreateWithURL(CFURLRef url) {
    NSString* path = [static_cast<NSURL*>(url) path];
    CGDataProvider* ret = [[CGDataProvider alloc] initWithContentsOfFile:path];
    ret->filename = path;

    return ret;
}

/**
 @Status Interoperable
*/
CFDataRef CGDataProviderCopyData(CGDataProviderRef provider) {
    void* data = (void*)[(NSData*)provider bytes];
    DWORD size = [(NSData*)provider length];
    id ret = [[CGDataProvider alloc] initWithBytes:data length:size];

    return (CFDataRef)ret;
}

/**
 @Status Caveat
 @Notes Only calls getBytePointer
*/
CGDataProviderRef CGDataProviderCreateDirect(void* info, __int64 size, CGDataProviderDirectCallbacks* callBacks) {
    TraceWarning(TAG, L"Warning: CGDataProviderCreateDirect is hacky");
    char* pBytes = (char*)callBacks->getBytePointer(info);

    id ret = [[CGDataProvider alloc] initWithBytesNoCopy:pBytes length:(DWORD)size freeWhenDone:FALSE];

    return ret;
}

/**
 @Status Caveat
 @Notes Hacky
*/
CGDataProviderRef CGDataProviderCreateSequential(void* info, CGDataProviderSequentialCallbacks* callBacks) {
    TraceWarning(TAG, L"Warning: CGDataProviderCreateSequential is hacky");
    char* pBytes = (char*)IwMalloc(1024 * 1024);

    int amt = callBacks->getBytes(info, pBytes, 1024 * 1024);

    id ret = [[CGDataProvider alloc] initWithBytes:pBytes length:amt];
    IwFree(pBytes);

    return ret;
}

/**
 @Status Interoperable
*/
CGDataProviderRef CGDataProviderCreateWithCFData(CFDataRef data) {
    return (CGDataProviderRef)CFRetain(data);
}

/**
 @Status Interoperable
*/
CGDataProviderRef CGDataProviderCreateWithData(void* info, const void* data, size_t size, CGDataProviderReleaseDataCallback releaseData) {
    CGDataProvider* ret = [[CGDataProvider alloc] initWithBytesNoCopy:(void*)data length:size freeWhenDone:FALSE];
    ret->releaseFunc = releaseData;
    ret->info = info;
    ret->data = data;
    ret->size = size;

    return ret;
}

/**
 @Status Interoperable
*/
CGDataProviderRef CGDataProviderCreateWithFilename(const char* filename) {
    CGDataProvider* ret = [[CGDataProvider alloc] initWithContentsOfFile:[NSString stringWithCString:filename]];
    if (!ret) {
        return 0;
    }
    ret->filename = [NSString stringWithCString:filename];

    return ret;
}

/**
 @Status Interoperable
*/
void CGDataProviderRelease(CGDataProviderRef data) {
    CFRelease(data);
}

/**
 @Status Interoperable
 @Notes
*/
CGDataProviderRef CGDataProviderRetain(CGDataProviderRef provider) {
    CFRetain((id)provider);

    return provider;
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGDataProviderGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}