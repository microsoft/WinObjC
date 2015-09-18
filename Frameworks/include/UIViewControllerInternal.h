#pragma once

struct UIViewControllerPriv
{
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
    __unsafe_unretained id _dismissCompletionBlock;
    idretaintype(UIViewController) _dismissController;
    CGSize _contentSizeForViewInPopover;
    unsigned _edgesForExtendedLayout;
    BOOL  _modalInPopover;
    CGSize _preferredContentSize;

    idretaintype(NSArray) _modalTemplates;
    idretaintype(UIView) view;
    idretaintype(NSMutableArray) _childViewControllers;
};

@interface UIViewController () {
@public
    struct UIViewControllerPriv* priv;
}
@end
