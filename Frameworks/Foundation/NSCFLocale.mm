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
#import "StubReturn.h"

#import <Foundation/Foundation.h>
#import "BridgeHelpers.h"
#import <Foundation/NSLocale.h>
#import "CFHelpers.h"
#import "CFFoundationInternal.h"
#import "Starboard.h"
#import "StubReturn.h"
#import "NSCFLocale.h"
#import <CoreFoundation/CFLocale.h>

#pragma region NSLocalePrototype

@implementation NSLocalePrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS

- (instancetype)init {
    return [self initWithLocaleIdentifier:@""];
}

- (instancetype)initWithLocaleIdentifier:(NSString*)string {
    return reinterpret_cast<NSLocalePrototype*>(
        static_cast<NSLocale*>(CFLocaleCreate(kCFAllocatorDefault, static_cast<CFStringRef>(string))));
}

@end

#pragma endregion

#pragma region NSCFCharacterSet

@implementation NSCFLocale

BRIDGED_CLASS_REQUIRED_IMPLS(CFLocaleRef, CFLocaleGetTypeID, NSLocale, NSCFLocale)

- (NSString*)displayNameForKey:(id)key value:(id)value {
    return [(static_cast<NSString*>(CFLocaleCopyDisplayNameForPropertyValue(static_cast<CFLocaleRef>(self),
                                                                            static_cast<CFStringRef>(key),
                                                                            static_cast<CFStringRef>(value))))autorelease];
}

- (id)objectForKey:(id)key {
    return static_cast<id>(CFLocaleGetValue(static_cast<CFLocaleRef>(self), static_cast<CFStringRef>(key)));
}

- (NSString*)localeIdentifier {
    return static_cast<NSString*>(CFLocaleGetIdentifier(static_cast<CFLocaleRef>(self)));
}

@end

#pragma endregion
