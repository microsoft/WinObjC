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

#include "Starboard.h"
#include "Foundation/NSData.h"
#include "Foundation/NSString.h"
#include "CoreGraphics/CGDataProvider.h"

@interface CGDataProvider : NSData {
@public
    CGDataProviderReleaseDataCallback releaseFunc;
    void* info;
    size_t size;
    const void* data;
    idretain filename;
}
@end

@implementation CGDataProvider : NSData
- (void)dealloc {
    if (releaseFunc != 0) {
        EbrCall(releaseFunc, "ddd", info, data, size);
    }
    filename = nil;
    [super dealloc];
}

- (NSString*)_fileName {
    return filename;
}

@end

CGDataProviderRef CGDataProviderCreateWithURL(CFURLRef url) {
    CGDataProvider* ret = [[CGDataProvider alloc] initWithContentsOfFile:[url path]];
    ret->filename = [url path];

    return ret;
}

CFDataRef CGDataProviderCopyData(CGDataProviderRef provider) {
    void* data = (void*)[provider bytes];
    DWORD size = [provider length];
    id ret = [[CGDataProvider alloc] initWithBytes:data length:size];

    return (CFDataRef)ret;
}

CGDataProviderRef CGDataProviderCreateDirect(DWORD info, __int64 size, CGDataProviderDirectCallbacks* callBacks) {
    EbrDebugLog("Warning: CGDataProviderCreateDirect is hacky\n");
    char* pBytes = (char*)EbrCall(callBacks->getBytePointer, "d", info);

    id ret = [[CGDataProvider alloc] initWithBytesNoCopy:pBytes length:(DWORD)size freeWhenDone:FALSE];

    return ret;
}

CGDataProviderRef CGDataProviderCreateSequential(DWORD info, CGDataProviderSequentialCallbacks* callBacks) {
    EbrDebugLog("Warning: CGDataProviderCreateSequential is hacky\n");
    char* pBytes = (char*)EbrMalloc(1024 * 1024);

    int amt = (int)EbrCall(callBacks->getBytes, "ddd", info, pBytes, 1024 * 1024);

    id ret = [[CGDataProvider alloc] initWithBytes:pBytes length:amt];
    EbrFree(pBytes);

    return ret;
}

CGDataProviderRef CGDataProviderCreateWithCFData(CFDataRef data) {
    return [data retain];
}

CGDataProviderRef
CGDataProviderCreateWithData(void* info, const void* data, size_t size, CGDataProviderReleaseDataCallback releaseData) {
    CGDataProvider* ret = [[CGDataProvider alloc] initWithBytesNoCopy:(void*)data length:size freeWhenDone:FALSE];
    ret->releaseFunc = releaseData;
    ret->info = info;
    ret->data = data;
    ret->size = size;

    return ret;
}

CGDataProviderRef CGDataProviderCreateWithFilename(const char* filename) {
    CGDataProvider* ret = [[CGDataProvider alloc] initWithContentsOfFile:[NSString stringWithCString:filename]];
    if (!ret)
        return 0;
    ret->filename = [NSString stringWithCString:filename];

    return ret;
}

void CGDataProviderRelease(CGDataProviderRef data) {
    CFRelease(data);
}
