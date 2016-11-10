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

#import "UICTFont.h"
#import <CFFoundationInternal.h>
#import <BridgeHelpers.h>

// Only exists to support the WinObjC-only [UIFont initWithCoder:]
#pragma region UIFontPrototype
@implementation UIFontPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(UICTFont)

// WinObjC-only extension for UINibUnarchiver
- (instancetype)initWithCoder:(NSCoder*)coder {
    NSString* name = [coder decodeObjectForKey:@"UIFontName"];
    if ([name length] == 0) {
        // fallback to default if could not find a font name
        name = (__bridge NSString*)kCTFontDefaultFontName;
    }

    CGFloat size = [coder decodeFloatForKey:@"UIFontPointSize"];

    return reinterpret_cast<UIFontPrototype*>(static_cast<UIFont*>(CTFontCreateWithName((__bridge CFStringRef)name, size, nullptr)));
}

@end
#pragma endregion

#pragma region UICTFont
@implementation UICTFont

BRIDGED_CLASS_REQUIRED_IMPLS(CTFontRef, CTFontGetTypeID, UIFont, UICTFont)

+ (UIFont*)fontWithName:(NSString*)name size:(float)size {
    return [(__bridge UIFont*)CTFontCreateWithName((__bridge CFStringRef)name, size, nullptr) autorelease];
}

+ (UIFont*)fontWithDescriptor:(UIFontDescriptor*)descriptor size:(CGFloat)fontSize {
    return [(__bridge UIFont*)CTFontCreateWithFontDescriptor((__bridge CTFontDescriptorRef)descriptor, fontSize, nullptr) autorelease];
}

- (NSString*)fontName {
    return [(__bridge NSString*)CTFontCopyFullName((CTFontRef)self) autorelease];
}

- (NSString*)familyName {
    return [(__bridge NSString*)CTFontCopyFamilyName((CTFontRef)self) autorelease];
}

- (CGFloat)descender {
    return CTFontGetDescent((CTFontRef)self);
}

- (CGFloat)ascender {
    return CTFontGetAscent((CTFontRef)self);
}

- (CGFloat)capHeight {
    return CTFontGetCapHeight((CTFontRef)self);
}

- (CGFloat)xHeight {
    return CTFontGetXHeight((CTFontRef)self);
}

- (CGFloat)pointSize {
    return CTFontGetSize((CTFontRef)self);
}

- (CGFloat)leading {
    return CTFontGetLeading((CTFontRef)self);
}

- (UIFontDescriptor*)fontDescriptor {
    return [(__bridge UIFontDescriptor*)CTFontCopyFontDescriptor((CTFontRef)self) autorelease];
}

- (NSUInteger)hash {
    return CFHash((CTFontRef)self);
}

- (NSString*)description {
    return [(__bridge NSString*)CFCopyDescription((CTFontRef)self) autorelease];
}

- (BOOL)isEqual:(UIFont*)other {
    if (![other isKindOfClass:[UICTFont class]]) {
        return [super isEqual:other];
    }

    return CFEqual((CTFontRef)self, (CTFontRef)other);
}

@end
#pragma endregion