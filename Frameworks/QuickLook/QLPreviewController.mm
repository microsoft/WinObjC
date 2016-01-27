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

#import <StubReturn.h>
#import <QuickLook/QuickLook.h>

@implementation QLPreviewController
/**
 @Status Stub
 @Notes
*/
+ (BOOL)canPreviewItem:(id<QLPreviewItem>)item {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)refreshCurrentPreviewItem {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)reloadData {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes Conform to UIContentContainer.h
*/
- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes Conform to UIContentContainer.h
*/
- (void)willTransitionToTraitCollection:(UITraitCollection*)newCollection
              withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes Conform to UIContentContainer.h
*/
- (CGSize)sizeForChildContentContainer:(id<UIContentContainer>)container withParentContainerSize:(CGSize)parentSize {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes Conform to UIContentContainer.h
*/
- (void)preferredContentSizeDidChangeForChildContentContainer:(id<UIContentContainer>)container {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes Conform to UIContentContainer.h
*/
- (void)systemLayoutFittingSizeDidChangeForChildContentContainer:(id<UIContentContainer>)container {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes Conform to UIFocusEnvironment.h
*/
- (void)setNeedsFocusUpdate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes Conform to UIFocusEnvironment.h
*/
- (void)updateFocusIfNeeded {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes Conform to UIFocusEnvironment.h
*/
- (BOOL)shouldUpdateFocusInContext:(UIFocusUpdateContext*)context {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes Conform to UIFocusEnvironment.h
*/
- (void)didUpdateFocusInContext:(UIFocusUpdateContext*)context withAnimationCoordinator:(UIFocusAnimationCoordinator*)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes Conform to UITraitEnvironment.h
*/
- (void)traitCollectionDidChange:(UITraitCollection*)previousTraitCollection {
    UNIMPLEMENTED();
}

@end
