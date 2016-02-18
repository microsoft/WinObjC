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

#import <UIKit/UIDocumentInteractionController.h>
#import <StubReturn.h>

@implementation UIDocumentInteractionController
/**
 @Status Stub
 @Notes
*/
+ (UIDocumentInteractionController*)interactionControllerWithURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)presentPreviewAnimated:(BOOL)animated {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)dismissPreviewAnimated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)presentOptionsMenuFromRect:(CGRect)rect inView:(UIView*)view animated:(BOOL)animated {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)presentOptionsMenuFromBarButtonItem:(UIBarButtonItem*)item animated:(BOOL)animated {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)presentOpenInMenuFromRect:(CGRect)rect inView:(UIView*)view animated:(BOOL)animated {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)presentOpenInMenuFromBarButtonItem:(UIBarButtonItem*)item animated:(BOOL)animated {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)dismissMenuAnimated:(BOOL)animated {
    UNIMPLEMENTED();
}

@end
