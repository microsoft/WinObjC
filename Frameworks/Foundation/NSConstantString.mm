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
#import "Starboard.h"
#import "ForFoundationOnly.h"
#import "NSConstantString.h"
#import "BridgeHelpers.h"
#import <CoreFoundation/CFString.h>

// Despite what one would imagine when designing a compiler + runtime to interop with NSString,
// the compiler filled in ivars are in UTF-8 not UTF-16 (which is what NSString's primitive methods operate in).
// Moreover, NSString has the "interesting" quirk that length is the size of the unichar buffer, not a logical
// count of characters, meaning that a traversal + codepoint conversion to UTF16 will fail to correctly account for
// UTF16 surrogate pairs which logically count as 1 character index but 2 unichar indices. In order to "most painlessly"
// account for these shenanigans, defer everything to CF's constant string mechanism. This unfortunately means a duplicate
// CFConstantString will exist and access to it is gated on the CFConstantString dictionary lock. It possible that extra space
// on this object could be used to cache the CFStringRef but because it is a compiler generated object, adding ivars is a big no-no.
@implementation NSConstantString
- (instancetype)retain {
    return self;
}

- (void)release {
}

- (instancetype)autorelease {
    return self;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
- (void)dealloc {
}
#pragma pop

- INNER_BRIDGE_CALL(static_cast<NSString*>(__CFStringMakeConstantString(c_string)), NSUInteger, length);
- INNER_BRIDGE_CALL(static_cast<NSString*>(__CFStringMakeConstantString(c_string)), unichar, characterAtIndex:(NSUInteger)index);
- INNER_BRIDGE_CALL(static_cast<NSString*>(__CFStringMakeConstantString(c_string)), void,
                    getCharacters:(unichar*)buffer
                    range:(NSRange)range);

- (const char*)_fastCStringContents:(CFStringEncoding)encoding {
    return CFStringGetCStringPtr(__CFStringMakeConstantString(c_string), encoding);
}

- (const UniChar*)_fastCharacterContents {
    return CFStringGetCharactersPtr(__CFStringMakeConstantString(c_string));
}

- (Boolean)_encodingCantBeStoredInEightBitCFString {
    return (nullptr == CFStringGetCStringPtr(__CFStringMakeConstantString(c_string), __CFStringGetEightBitStringEncoding()));
}

@end