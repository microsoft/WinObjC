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
#import <StubReturn.h>

#import "NSLayoutAnchorInternal.h"

@implementation NSLayoutDimension
/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:m
                                         constant:0.0f];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m constant:(CGFloat)c {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:m
                                         constant:c];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintEqualToConstant:(CGFloat)c {
    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationEqual
                                           toItem:nil
                                        attribute:NSLayoutAttributeNotAnAttribute
                                       multiplier:1.0f
                                         constant:c];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintGreaterThanOrEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationGreaterThanOrEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:m
                                         constant:0.0f];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintGreaterThanOrEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m constant:(CGFloat)c {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationGreaterThanOrEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:m
                                         constant:c];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintGreaterThanOrEqualToConstant:(CGFloat)c {
    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationGreaterThanOrEqual
                                           toItem:nil
                                        attribute:NSLayoutAttributeNotAnAttribute
                                       multiplier:1.0f
                                         constant:c];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintLessThanOrEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationLessThanOrEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:m
                                         constant:0.0f];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintLessThanOrEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m constant:(CGFloat)c {
    [self _validateMayConstrainToAnchor:anchor];

    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationLessThanOrEqual
                                           toItem:anchor->_owner
                                        attribute:anchor->_attr
                                       multiplier:m
                                         constant:c];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSLayoutConstraint*)constraintLessThanOrEqualToConstant:(CGFloat)c {
    return [NSLayoutConstraint constraintWithItem:self->_owner 
                                        attribute:self->_attr 
                                        relatedBy:NSLayoutRelationLessThanOrEqual
                                           toItem:nil
                                        attribute:NSLayoutAttributeNotAnAttribute
                                       multiplier:1.0f
                                         constant:c];
}

@end
