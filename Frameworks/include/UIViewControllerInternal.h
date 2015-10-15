//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _UIVIEWCONTROLLERPRIVATE_H_
#define _UIVIEWCONTROLLERPRIVATE_H_

enum ControllerVisibiltyState {
    controllerNotVisible,
    controllerWillAppear,
    controllerWillAppearAnimated,
    controllerVisible,
    controllerWillDisappear,
    controllerWillDisappearAnimated
};

struct UIViewControllerPriv {
    idretaintype(UINavigationItem) navigationItem;
    idretaintype(UITabBarItem) tabBarItem;
    idretaintype(NSArray) toolbarItems;
    idretaintype(UIBarButtonItem) editButtonItem;
    idretaintype(UINavigationController) navigationController;
    idretaintype(UIViewController) _modalViewController;
    idretaintype(UISearchDisplayController) _searchDisplayController;
    __unsafe_unretained id _presentingViewController, _presentedViewController;
    idretaintype(NSDictionary) _externalObjects;
    __unsafe_unretained id _parentViewController;
    idretaintype(NSString) nibName;
    idretaintype(NSBundle) nibBundle;
    idretaintype(NSString) _title;
    UIStoryboard* _storyboard;
    BOOL hasLoaded, isLoading;
    BOOL _isEditing;
    UIInterfaceOrientation _curOrientation;
    BOOL _didSetRotation;
    BOOL _resizeToScreen;
    enum ControllerVisibiltyState _visibility;
    BOOL _wantsFullScreenLayout;
    BOOL _autoresize;
    UIModalPresentationStyle _presentationStyle;
    BOOL _hidesBottomBar;
    UIModalTransitionStyle _modalTransitionStyle;
    BOOL _isRootView;
    idretainp<void (^)(void)> _dismissCompletionBlock;
    idretaintype(UIViewController) _dismissController;
    CGSize _contentSizeForViewInPopover;
    unsigned _edgesForExtendedLayout;
    BOOL _modalInPopover;
    CGSize _preferredContentSize;

    idretaintype(NSArray) _modalTemplates;
    idretaintype(UIView) view;
    idretaintype(NSMutableArray) _childViewControllers;
};

@interface UIViewController () {
@public
    struct UIViewControllerPriv* priv;
}

- (void)notifyViewWillAppear:(BOOL)isAnimated;
- (void)notifyViewDidAppear:(BOOL)isAnimated;
- (void)notifyViewWillDisappear:(BOOL)isAnimated;
- (void)notifyViewDidDisappear:(BOOL)isAnimated;
@end

#endif
