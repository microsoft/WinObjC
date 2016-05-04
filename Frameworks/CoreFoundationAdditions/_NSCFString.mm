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

#include <CoreFoundation/CFBase.h>
#include "CFFoundationInternal.h"
#include "CFInternal.h"
#include "_NSCFString.h"
#include <CoreFoundation/CFString.h>

// ignore bridge cast warnings here. _NSCFString will be a subclass of NSString. It just
// doesn't realize it yet.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbridge-cast"
@implementation _NSCFString

- (instancetype)retain {
    CFRetain(static_cast<CFStringRef>(self));
    return self;
}

- (oneway void)release {
    CFRelease(static_cast<CFStringRef>(self));
}

- (id)autorelease {
    return (id)(CFAutorelease(static_cast<CFStringRef>(self)));
}

- (NSUInteger)retainCount {
    return CFGetRetainCount(static_cast<CFStringRef>(self));
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
- (void)dealloc {
    /* No-op for bridged classes. This is because the CF system is responsible for the allocation and dealloc of the backing memory. */
    /* This is all handled via the CFRelease calls. */
    /* When its CF ref count drops to 0 the CF version of dealloc is invoked */
    /* so by the time the NSObject dealloc is called, there is nothing left to do. */
}

+ (instancetype)allocWithZone:(NSZone*)zone {
    return nil;
}
#pragma clang diagnostic pop

// NSString overrides
- (NSUInteger)length {
    return CFStringGetLength(static_cast<CFStringRef>(self));
}

- (unichar)characterAtIndex:(NSUInteger)index {
    return CFStringGetCharacterAtIndex(static_cast<CFStringRef>(self), index);
}

- (void)getCharacters:(unichar*)buffer range:(NSRange)range {
    return CFStringGetCharacters(static_cast<CFStringRef>(self), CFRange{ range.location, range.length }, buffer);
}

- (void)replaceCharactersInRange:(NSRange)range withString:(NSString*)replacement {
    CFStringReplace(static_cast<CFMutableStringRef>(self), CFRange{ range.location, range.length }, static_cast<CFStringRef>(replacement));
}

- (instancetype)copyWithZone:(NSZone*)zone {
    return static_cast<_NSCFString*>(CFStringCreateCopy(nullptr, static_cast<CFStringRef>(self)));
}

@end
#pragma clang diagnostic pop
