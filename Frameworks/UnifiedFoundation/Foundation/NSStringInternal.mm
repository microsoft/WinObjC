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
#include "NSStringInternal.h"
#include "LoggingNative.h"

static const wchar_t* TAG = L"NSStringInternal";

@implementation NSString (Internal)
- (int)_versionStringCompare:(NSString*)compStrAddr {
    TraceWarning(TAG, L"Warning: versionStringCompare not implemented");
    char* str = (char*)[self UTF8String];

    if (compStrAddr == nil) {
        TraceVerbose(TAG, L"Compare to nil?");
        return strcmp(str, "");
    }

    const char* compStr = (const char*)[compStrAddr UTF8String];

    int result = strcmp(str, compStr);
    if (result < 0) {
        result = -1;
    }
    if (result > 0) {
        result = 1;
    }

    return result;
}

- (NSString*)_reverseString {
    NSUInteger length = [self length];
    if (length < 2) {
        return self;
    }

    char* characters = (char*)malloc(sizeof(char) * (length + 1));
    [self getCString:characters maxLength:length];
    for (int i = 0; i < length / 2; ++i) {
        char character = characters[length - i - 1];
        characters[length - i - 1] = characters[i];
        characters[i] = character;
    }
    characters[length] = '\0';

    NSString* ret = [[[NSString alloc] initWithCString:characters] autorelease];

    free(characters);
    characters = nullptr;

    return ret;
}

@end

__attribute__((constructor)) static void _ForceTUInclusion() {
}