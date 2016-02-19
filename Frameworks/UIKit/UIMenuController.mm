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

#import <UIKit/UIMenuController.h>
#import <StubReturn.h>

NSString* const UIMenuControllerWillShowMenuNotification = @"UIMenuControllerWillShowMenuNotification";
NSString* const UIMenuControllerDidShowMenuNotification = @"UIMenuControllerDidShowMenuNotification";
NSString* const UIMenuControllerWillHideMenuNotification = @"UIMenuControllerWillHideMenuNotification";
NSString* const UIMenuControllerDidHideMenuNotification = @"UIMenuControllerDidHideMenuNotification";
NSString* const UIMenuControllerMenuFrameDidChangeNotification = @"UIMenuControllerMenuFrameDidChangeNotification";

@implementation UIMenuController
/**
 @Status Stub
 @Notes
*/
+ (UIMenuController*)sharedMenuController {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setMenuVisible:(BOOL)menuVisible animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setTargetRect:(CGRect)targetRect inView:(UIView*)targetView {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)update {
    UNIMPLEMENTED();
}

@end
