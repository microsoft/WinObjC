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

@implementation UICTFont

BRIDGED_CLASS_REQUIRED_IMPLS(CTFontRef, CTFontGetTypeID, UIFont, UICTFont)

+ (UIFont*)fontWithName:(NSString*)name size:(float)size {
    return [(__bridge UIFont*)CTFontCreateWithName((__bridge CFStringRef)name, size, nullptr) autorelease];
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