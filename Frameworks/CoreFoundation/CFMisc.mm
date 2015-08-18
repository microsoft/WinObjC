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

#import <CoreFoundation/CoreFoundation.h>
#include <Windows.h>

#ifndef __ISLANDWOOD_COMPAT
#include <sys/types.h>
#endif
#include <unistd.h>

extern "C" void *_OBJC_CLASS_CFConstantString = NULL;

COREFOUNDATION_EXPORT extern "C" uint32_t arc4random()
{
    return (rand() | (rand() << 16) ^ (rand() << 1) ^ (rand() << 17));
}

COREFOUNDATION_EXPORT extern "C" int usleep(useconds_t secs)
{
    Sleep(secs * 1000);
    return 0;
}

COREFOUNDATION_EXPORT extern "C" unsigned int sleep(useconds_t secs)
{
    Sleep(secs * 1000);
    return 0;
}

COREFOUNDATION_EXPORT extern "C" int sysctlbyname(const char *name, void *out, size_t *outSize, const void *, size_t)
{
    if ( strcmp(name, "hw.machine") == 0 ) {
        const int required = 8;
        if ( outSize ) {
            // If there's no buffer, we have to return the nr. of bytes required for this response.
            *outSize = !out ? required : min(*outSize, required);
        } else {
            return -1;
        }

        if ( out ) strncpy((char *) out, "winobjc", *outSize); // outsize is <= required here
        return *outSize < required ? ENOMEM : 0;
    }
    return -1;
}

CFStringRef CFCopyDescription(CFTypeRef ref)
{
    return (CFStringRef) @"Desc";
}

