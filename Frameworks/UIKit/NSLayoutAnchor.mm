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

#import <UIKit/UIKit.h>
#import <UIKit/NSLayoutAnchor.h>
#import <UIKit/NSLayoutXAxisAnchor.h>
#import <UIKit/NSLayoutXAxisAnchor.h>
#import <UIKit/NSLayoutDimension.h>
#import <StubReturn.h>

#import "NSLayoutAnchorInternal.h"

@implementation NSLayoutAnchor

+ (instancetype)_anchorWithAttribute:(NSLayoutAttribute)attribute owner:(id)owner {
    NSLayoutAnchor* ret = nil;

    switch (attribute) {
        case NSLayoutAttributeLeft:
        case NSLayoutAttributeRight:
        case NSLayoutAttributeLeading:
        case NSLayoutAttributeTrailing:
        case NSLayoutAttributeLeftMargin:
        case NSLayoutAttributeRightMargin:
        case NSLayoutAttributeLeadingMargin:
        case NSLayoutAttributeTrailingMargin:
            ret = [NSLayoutXAxisAnchor new];
            ret->_attr = attribute;
            ret->_owner = owner;
            return [ret autorelease];

        case NSLayoutAttributeTop:
        case NSLayoutAttributeBottom:
        case NSLayoutAttributeLastBaseline:
        case NSLayoutAttributeFirstBaseline:
        case NSLayoutAttributeTopMargin:
        case NSLayoutAttributeBottomMargin:
            ret = [NSLayoutYAxisAnchor new];
            ret->_attr = attribute;
            ret->_owner = owner;
            return [ret autorelease];

        case NSLayoutAttributeWidth:
        case NSLayoutAttributeCenterX:
        case NSLayoutAttributeHeight:
        case NSLayoutAttributeCenterY:
        case NSLayoutAttributeCenterYWithinMargins:
        case NSLayoutAttributeCenterXWithinMargins:
            ret = [NSLayoutDimension new];
            ret->_attr = attribute;
            ret->_owner = owner;
            return [ret autorelease];

        case NSLayoutAttributeNotAnAttribute:
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Argument 'attribute' not an attribute!" userInfo:nil];
    }
}

- (void)_validateMayConstrainToAnchor:(NSLayoutAnchor*)anchor {
    if ([self isKindOfClass:[NSLayoutXAxisAnchor class]]) {
        if (![anchor isKindOfClass:[NSLayoutXAxisAnchor class]]) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Layout anchor of class NSLayoutXAxisAnchor must be constrained to the same type" userInfo:nil];
        }
    } else if ([self isKindOfClass:[NSLayoutYAxisAnchor class]]) {
        if (![anchor isKindOfClass:[NSLayoutYAxisAnchor class]]) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Layout anchor of class NSLayoutYAxisAnchor must be constrained to the same type" userInfo:nil];
        }
    } else if ([self isKindOfClass:[NSLayoutDimension class]]) {
        if (![anchor isKindOfClass:[NSLayoutDimension class]]) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Layout anchor of class NSLayoutDimension must be constrained to the same type" userInfo:nil];
        }
    } else {
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Unknown NSLayoutAnchor subclass" userInfo:nil];
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutAnchor*)anchor {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:1.0f
                                         constant:0.0f];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutAnchor*)anchor constant:(CGFloat)c {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:1.0f
                                         constant:c];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor*)anchor {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationGreaterThanOrEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:1.0f
                                         constant:0.0f];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor*)anchor constant:(CGFloat)c {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationGreaterThanOrEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:1.0f
                                         constant:c];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintLessThanOrEqualToAnchor:(NSLayoutAnchor*)anchor {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationLessThanOrEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:1.0f
                                         constant:0.0f];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintLessThanOrEqualToAnchor:(NSLayoutAnchor*)anchor constant:(CGFloat)c {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationLessThanOrEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:1.0f
                                         constant:c];
}

@end
