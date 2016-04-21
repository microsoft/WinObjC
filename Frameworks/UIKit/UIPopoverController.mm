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

#import <Starboard.h>
#import <UIKit/UIPopoverController.h>
#import <StubReturn.h>

@implementation UIPopoverController {
    StrongId<UIColor> _backgroundColor;
}
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithContentViewController:(UIViewController*)viewController {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)presentPopoverFromRect:(CGRect)rect
                        inView:(UIView*)view
      permittedArrowDirections:(UIPopoverArrowDirection)arrowDirections
                      animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)presentPopoverFromBarButtonItem:(UIBarButtonItem*)item
               permittedArrowDirections:(UIPopoverArrowDirection)arrowDirections
                               animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)dismissPopoverAnimated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setContentViewController:(UIViewController*)viewController animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setPopoverContentSize:(CGSize)size animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UIColor*)backgroundColor {
    UNIMPLEMENTED();
    return [[_backgroundColor copy] autorelease];
}

/**
 @Status Stub
*/
- (void)setBackgroundColor:(UIColor*)color {
    UNIMPLEMENTED();
    _backgroundColor.attach([color copy]);
}

@end
