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

#import <UIKit/UILayoutGuide.h>
#import <UIKit/NSLayoutAnchor.h>
#import <UIKit/NSLayoutConstraint.h>
#import <StubReturn.h>

#import <Starboard.h>

#import "UILayoutGuide+AutoLayout.h"
#import "NSLayoutAnchorInternal.h"

@implementation UILayoutGuide {
    StrongId<NSLayoutYAxisAnchor> _bottomAnchor;
    StrongId<NSLayoutXAxisAnchor> _centerXAnchor;
    StrongId<NSLayoutYAxisAnchor> _centerYAnchor;
    StrongId<NSLayoutDimension> _heightAnchor;
    StrongId<NSLayoutXAxisAnchor> _leadingAnchor;
    StrongId<NSLayoutXAxisAnchor> _leftAnchor;
    StrongId<NSLayoutXAxisAnchor> _rightAnchor;
    StrongId<NSLayoutYAxisAnchor> _topAnchor;
    StrongId<NSLayoutXAxisAnchor> _trailingAnchor;
    StrongId<NSLayoutDimension> _widthAnchor;
}

+ (instancetype)allocWithZone:(NSZone*)zone {
    id ret = [super allocWithZone:zone];

    [ret autoLayoutAlloc];

    return ret;
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/*@property (copy, nonatomic) NSString* identifier STUB_PROPERTY;
*/

- (CGRect)layoutFrame {
    return [self autoLayoutGetRect];
}

// TODO: Should we except when owningView isn't set?

- (NSLayoutDimension*) heightAnchor {
    if (_heightAnchor == nil) {
        _heightAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeHeight owner:self];
    }
    return _heightAnchor;
}

- (NSLayoutDimension*) widthAnchor {
    if (_widthAnchor == nil) {
        _widthAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeWidth owner:self];
    }
    return _widthAnchor;
}

- (NSLayoutXAxisAnchor*) centerXAnchor {
    if (_centerXAnchor == nil) {
        _centerXAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeCenterX owner:self];
    }
    return _centerXAnchor;
}

- (NSLayoutXAxisAnchor*) leadingAnchor {
    if (_leadingAnchor == nil) {
        _leadingAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeLeading owner:self];
    }
    return _leadingAnchor;
}

- (NSLayoutXAxisAnchor*) leftAnchor {
    if (_leftAnchor == nil) {
        _leftAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeLeft owner:self];
    }
    return _leftAnchor;
}

- (NSLayoutXAxisAnchor*) rightAnchor {
    if (_rightAnchor == nil) {
        _rightAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeRight owner:self];
    }
    return _rightAnchor;
}

- (NSLayoutXAxisAnchor*) trailingAnchor {
    if (_trailingAnchor == nil) {
        _trailingAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeTrailing owner:self];
    }
    return _trailingAnchor;
}

- (NSLayoutYAxisAnchor*) bottomAnchor {
    if (_bottomAnchor == nil) {
        _bottomAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeBottom owner:self];
    }
    return _bottomAnchor;
}

- (NSLayoutYAxisAnchor*) centerYAnchor {
    if (_centerYAnchor == nil) {
        _centerYAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeCenterY owner:self];
    }
    return _centerYAnchor;
}

- (NSLayoutYAxisAnchor*) topAnchor {
    if (_topAnchor == nil) {
        _topAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeTop owner:self];
    }
    return _topAnchor;
}

@end
