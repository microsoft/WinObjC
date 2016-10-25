//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "UICTFontDescriptor.h"

#import <CoreText/CTFontDescriptor.h>
#import <CFFoundationInternal.h>
#import <BridgeHelpers.h>

@interface UICTFontDescriptor : UIFontDescriptor
@end

#pragma region UIFontDescriptorPrototype
@implementation UIFontDescriptorPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(UICTFontDescriptor)

- (instancetype)initWithFontAttributes:(NSDictionary*)attributes {
    return reinterpret_cast<UIFontDescriptorPrototype*>(
        static_cast<UIFontDescriptor*>(CTFontDescriptorCreateWithAttributes((__bridge CFDictionaryRef)attributes)));
}

@end
#pragma endregion

#pragma region UICTFontDescriptor
@implementation UICTFontDescriptor

BRIDGED_CLASS_REQUIRED_IMPLS(CTFontDescriptorRef, CTFontDescriptorGetTypeID, UIFontDescriptor, UICTFontDescriptor)

- (NSDictionary<NSString*, id>*)fontAttributes {
    return [(__bridge NSDictionary<NSString*, id>*)CTFontDescriptorCopyAttributes(static_cast<CTFontDescriptorRef>(self)) autorelease];
}

- (id)objectForKey:(NSString*)anAttribute {
    return [static_cast<id>(CTFontDescriptorCopyAttribute(static_cast<CTFontDescriptorRef>(self), (__bridge CFStringRef)anAttribute))
        autorelease];
}

- (NSUInteger)hash {
    return CFHash((CTFontRef)self);
}

- (NSString*)description {
    return [(__bridge NSString*)CFCopyDescription((CTFontDescriptorRef)self) autorelease];
}

- (BOOL)isEqual:(UIFont*)other {
    if (![other isKindOfClass:[UICTFontDescriptor class]]) {
        return [super isEqual:other];
    }

    return CFEqual((CTFontDescriptorRef)self, (CTFontDescriptorRef)other);
}

@end
#pragma endregion