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

#include "Starboard.h"

#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSBundle.h"
#include "Foundation/NSNotificationCenter.h"
#include "Foundation/NSNib.h"
#include "Foundation/NSValue.h"
#include "UIKit/UIView.h"
#include "UIKit/UIViewController.h"
#include "UIKit/UIApplication.h"
#include "UIKit/UIDevice.h"
#include "UIKit/UIScreen.h"
#include "CoreGraphics/CGContext.h"
#include "CoreGraphics/CGAffineTransform.h"
#include "UIKit/UIEmptyController.h"
#include "UIViewInternal.h"
#include "UIViewControllerInternal.h"
#include "AutoLayout.h"
#include "UIViewControllerInternal.h"

@interface _TransitionNotifier : NSObject
@end

@implementation _TransitionNotifier {
    idretain _animDelegate;
    SEL _selector;
}

+ (instancetype)_transitionTrampoline:(id)delegate withSelector:(SEL)selector {
    _TransitionNotifier* ret = [self alloc];
    ret->_animDelegate = delegate;
    ret->_selector = selector;
    return [ret autorelease];
}

- (void)animationDidStop:(CAAnimation*)animation finished:(BOOL)finished {
    void (*imp)(id, SEL, CAAnimation*, BOOL) = (void (*)(id, SEL, CAAnimation*, BOOL))[_animDelegate methodForSelector:_selector];
    imp(_animDelegate, _selector, animation, finished);
    _animDelegate = nil;
}
@end

#import <UIKit/UIStoryboardPushSegueTemplate.h>

#include "..\include\CACompositor.h"

#include "Etc.h"

extern "C" bool doLog;
extern bool g_doLog;
extern BOOL g_presentingAnimated;

void EbrDumpStack();

// UIView -> UIViewController mapping:
#include <unordered_map>
namespace {
std::unordered_map<UIView*, UIViewController*> viewMap;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void addViewMapping(UIView* view, UIViewController* controller) {
    pthread_mutex_lock(&mutex);
    assert(viewMap.find(view) == viewMap.end());
    viewMap[view] = controller;
    pthread_mutex_unlock(&mutex);
}

void removeViewMapping(UIView* view) {
    pthread_mutex_lock(&mutex);
    auto it = viewMap.find(view);
    assert(it != viewMap.end());
    viewMap.erase(it);
    pthread_mutex_unlock(&mutex);
}

UIViewController* lookupViewController(UIView* view) {
    pthread_mutex_lock(&mutex);
    auto it = viewMap.find(view);

    UIViewController* ret = nil;
    if (it != viewMap.end())
        ret = it->second;
    pthread_mutex_unlock(&mutex);

    return ret;
}
};

bool isSupportedControllerOrientation(UIViewController* controller, UIInterfaceOrientation orientation) {
    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];
    NSArray* orientations = 0;

    if (GetCACompositor()->isTablet()) {
        orientations = [infoDict objectForKey:@"UISupportedInterfaceOrientations~ipad"];
    }
    if (!orientations) {
        orientations = [infoDict objectForKey:@"UISupportedInterfaceOrientations"];
    }

    if (orientations != nil) {
        if (![controller shouldAutorotate])
            return false;

        int supportedOrientations = 0;

        for (NSString* curstr in orientations) {
            if ([curstr isEqualToString:@"UIInterfaceOrientationPortrait"])
                supportedOrientations |= UIInterfaceOrientationMaskPortrait;
            if ([curstr isEqualToString:@"UIInterfaceOrientationPortraitUpsideDown"])
                supportedOrientations |= UIInterfaceOrientationMaskPortraitUpsideDown;
            if ([curstr isEqualToString:@"UIInterfaceOrientationLandscapeLeft"])
                supportedOrientations |= UIInterfaceOrientationMaskLandscapeLeft;
            if ([curstr isEqualToString:@"UIInterfaceOrientationLandscapeRight"])
                supportedOrientations |= UIInterfaceOrientationMaskLandscapeRight;
        }

        int windowSupported = [controller supportedInterfaceOrientations];
        supportedOrientations &= windowSupported;

        if (supportedOrientations & (1 << orientation)) {
            return true;
        } else {
            return false;
        }
    } else {
        return [controller shouldAutorotateToInterfaceOrientation:orientation] != FALSE;
    }
}

UIInterfaceOrientation supportedOrientationForOrientation(UIViewController* controller, UIInterfaceOrientation orientation) {
    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];
    NSArray* orientations = 0;
    if (GetCACompositor()->isTablet()) {
        orientations = [infoDict objectForKey:@"UISupportedInterfaceOrientations~ipad"];
    }
    if (!orientations) {
        orientations = [infoDict objectForKey:@"UISupportedInterfaceOrientations"];
    }

    if (orientations != nil) {
        int supportedOrientations = 0;

        if (![controller shouldAutorotate])
            return UIInterfaceOrientationUnknown;

        for (NSString* curstr in orientations) {
            if ([curstr isEqualToString:@"UIInterfaceOrientationPortrait"])
                supportedOrientations |= UIInterfaceOrientationMaskPortrait;
            if ([curstr isEqualToString:@"UIInterfaceOrientationPortraitUpsideDown"])
                supportedOrientations |= UIInterfaceOrientationMaskPortraitUpsideDown;
            if ([curstr isEqualToString:@"UIInterfaceOrientationLandscapeLeft"])
                supportedOrientations |= UIInterfaceOrientationMaskLandscapeLeft;
            if ([curstr isEqualToString:@"UIInterfaceOrientationLandscapeRight"])
                supportedOrientations |= UIInterfaceOrientationMaskLandscapeRight;
        }

        int windowSupported = [controller supportedInterfaceOrientations];
        supportedOrientations &= windowSupported;

        if (supportedOrientations & (1 << orientation)) {
            return orientation;
        } else {
            //  Go with any valid orientation
            if (supportedOrientations & UIInterfaceOrientationMaskPortrait) {
                return UIInterfaceOrientationPortrait;
            }
            if (supportedOrientations & UIInterfaceOrientationMaskPortraitUpsideDown) {
                return UIInterfaceOrientationPortraitUpsideDown;
            }
            if (supportedOrientations & UIInterfaceOrientationMaskLandscapeRight) {
                return UIInterfaceOrientationLandscapeRight;
            }
            if (supportedOrientations & UIInterfaceOrientationMaskLandscapeLeft) {
                return UIInterfaceOrientationLandscapeLeft;
            }
            return UIInterfaceOrientationUnknown;
        }
    } else {
        if ([controller shouldAutorotateToInterfaceOrientation:orientation]) {
            return orientation;
        } else {
            //  Try to find any valid orientation
            static const UIInterfaceOrientation orientations[] = { UIInterfaceOrientationPortrait,
                                                                   UIInterfaceOrientationPortraitUpsideDown,
                                                                   UIInterfaceOrientationLandscapeRight,
                                                                   UIInterfaceOrientationLandscapeLeft };

            int i;

            for (i = 0; i < 4; i++) {
                orientation = orientations[i];

                if ([controller shouldAutorotateToInterfaceOrientation:orientation]) {
                    return orientation;
                }
            }
        }

        return UIInterfaceOrientationUnknown;
    }
}

@interface _UILayoutSupportConstraint : NSLayoutConstraint
@end

// Not convinced this is here for anything but a rename.
@implementation _UILayoutSupportConstraint
@end

@implementation _UILayoutGuide {
@public
    CGFloat _length;
    NSString* _identifier;
}

- (instancetype)init {
    self.translatesAutoresizingMaskIntoConstraints = NO;
    return self;
}

- (instancetype)initWithIdentifier:(NSString*)identifier {
    _identifier = identifier;
    self.translatesAutoresizingMaskIntoConstraints = NO;
    return self;
}

- (NSString*)description {
    NSString* ret = [super description];
    return [NSString stringWithFormat:@"%@:%@", ret, _identifier];
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    _UILayoutGuide* ret = [super initWithCoder:coder];
    _identifier = [coder decodeObjectForKey:@"_UILayoutGuideIdentifier"];
    self.translatesAutoresizingMaskIntoConstraints = NO;
    assert(_identifier);
    return ret;
}

- (CGFloat)length {
    // TODO: Search up the hierarchy for the controller, look for nav/tab bars, return height + status bar
    return _length;
}
@end

@implementation UIViewController : UIResponder

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
    return TRUE;
}
- (void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
                                                    duration:(NSTimeInterval)duration {
}
- (void)encodeRestorableStateWithCoder:(NSCoder*)coder {
}
- (void)decodeRestorableStateWithCoder:(NSCoder*)coder {
}
- (BOOL)isBeingDismissed {
    return TRUE;
}
+ (instancetype)allocWithZone:(NSZone*)zone {
    UIViewController* ret = [super allocWithZone:zone];

    ret->priv = (UIViewControllerPriv*)EbrCalloc(1, sizeof(UIViewControllerPriv));
    ret->priv->_curOrientation = UIInterfaceOrientationPortrait;
    ret->priv->_edgesForExtendedLayout = 0xF;
    ret->priv->_contentSizeForViewInPopover.width = 320.0f;
    ret->priv->_contentSizeForViewInPopover.height = 1100.0f;

    [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];

    return ret;
}

- (CGRect)_orientationRect:(UIInterfaceOrientation)orientation {
    CGRect appFrame;

    appFrame = [[UIScreen mainScreen] applicationFrame];

    if (priv->_presentationStyle == UIModalPresentationFormSheet) {
        CGRect screenFrame;
        screenFrame = [[UIScreen mainScreen] applicationFrame];

        appFrame.size.width = 540;
        appFrame.size.height = 575;

        appFrame.origin.x = screenFrame.origin.x + screenFrame.size.width / 2.0f - appFrame.size.width / 2.0f;
        appFrame.origin.y = screenFrame.origin.y + screenFrame.size.height / 2.0f - appFrame.size.height / 2.0f;
    }

    CGRect rect;

    switch (orientation) {
        case UIInterfaceOrientationPortrait: {
            rect.origin.x = appFrame.origin.x;
            rect.origin.y = appFrame.origin.y;
            rect.size.width = appFrame.size.width;
            rect.size.height = appFrame.size.height;
        } break;

        case UIInterfaceOrientationLandscapeRight: {
            rect.origin.x = appFrame.origin.y;
            rect.origin.y = appFrame.origin.x;
            rect.size.width = appFrame.size.height;
            rect.size.height = appFrame.size.width;
        } break;

        case UIInterfaceOrientationLandscapeLeft: {
            rect.origin.x = appFrame.origin.y;
            rect.origin.y = appFrame.origin.x;
            rect.size.width = appFrame.size.height;
            rect.size.height = appFrame.size.width;
        } break;

        default:
            assert(0);
            break;
    }

    return rect;
}

- (void)setResizeToScreen:(BOOL)resize {
    priv->_resizeToScreen = TRUE;
}

- (void)setOrientationInternal:(UIInterfaceOrientation)orientation animated:(BOOL)animated {
    CGRect appFrame;

#ifndef USE_HOST_ROTATION
    if (animated) {
        [UIView beginAnimations:@"Rotation" context:nil];
        [UIView setAnimationDuration:0.25f];
    }
#endif

    [[UIApplication sharedApplication] setStatusBarOrientation:orientation animated:FALSE];

    if (priv->_wantsFullScreenLayout) {
        appFrame = [[UIScreen mainScreen] bounds];
    } else {
        appFrame = [[UIScreen mainScreen] applicationFrame];
    }
    if (priv->_presentationStyle == UIModalPresentationFormSheet) {
        CGRect screenFrame;
        screenFrame = [[UIScreen mainScreen] applicationFrame];

        appFrame.size.width = GetCACompositor()->screenWidth();
        appFrame.size.height = GetCACompositor()->screenHeight();

        appFrame.origin.x = screenFrame.origin.x + screenFrame.size.width / 2.0f - appFrame.size.width / 2.0f;
        appFrame.origin.y = screenFrame.origin.y + screenFrame.size.height / 2.0f - appFrame.size.height / 2.0f;
    }

    switch (orientation) {
        case UIInterfaceOrientationPortrait: {
            CGRect rect;

            rect.origin.x = appFrame.origin.x;
            rect.origin.y = appFrame.origin.y;
            rect.size.width = appFrame.size.width;
            rect.size.height = appFrame.size.height;

            [priv->view
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            rect.origin.x = 0.0f;
            rect.origin.y = 0.0f;
            [priv->view setBounds:rect];

            CGAffineTransform trans;

            trans = CGAffineTransformMakeTranslation(0.0f, 0.0f);
            [priv->view setTransform:trans];
        } break;

        case UIInterfaceOrientationPortraitUpsideDown: {
            CGRect rect;

            rect.origin.x = appFrame.origin.x;
            rect.origin.y = appFrame.origin.y;
            rect.size.width = appFrame.size.width;
            rect.size.height = appFrame.size.height;

            [priv->view
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            rect.origin.x = 0.0f;
            rect.origin.y = 0.0f;
            [priv->view setBounds:rect];

            CGAffineTransform trans;

            trans = CGAffineTransformMakeRotation(kPi);
            [priv->view setTransform:trans];
        } break;

        case UIInterfaceOrientationLandscapeRight: {
            CGRect rect;

            rect.origin.x = appFrame.origin.y;
            rect.origin.y = appFrame.origin.x;
            rect.size.width = appFrame.size.height;
            rect.size.height = appFrame.size.width;

            [priv->view
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            rect.origin.x = 0.0f;
            rect.origin.y = 0.0f;
            [priv->view setBounds:rect];

            CGAffineTransform trans;

            trans = CGAffineTransformMakeRotation(kPi / 2);
            [priv->view setTransform:trans];
        } break;

        case UIInterfaceOrientationLandscapeLeft: {
            CGRect rect;

            rect.origin.x = appFrame.origin.y;
            rect.origin.y = appFrame.origin.x;
            rect.size.width = appFrame.size.height;
            rect.size.height = appFrame.size.width;

            [priv->view
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            rect.origin.x = 0.0f;
            rect.origin.y = 0.0f;
            [priv->view setBounds:rect];

            CGAffineTransform trans;

            trans = CGAffineTransformMakeRotation(270.0f / 180.0f * kPi);
            [priv->view setTransform:trans];
        } break;

            break;

        default:
            assert(0);
            break;
    }

    [priv->view setNeedsLayout];

    if (animated) {
        [priv->view layoutIfNeeded];
#ifndef USE_HOST_ROTATION
        [self willAnimateRotationToInterfaceOrientation:orientation duration:0.25f];
        [UIView commitAnimations];
#else
        [self willAnimateRotationToInterfaceOrientation:orientation duration:0.0];
#endif
    } else {
        [self willAnimateRotationToInterfaceOrientation:orientation duration:0.0f];
    }
}

- (void)setRotation:(UIInterfaceOrientation)orientation animated:(BOOL)animated {
    if (([priv->view superview] == nil || [priv->view window] != [priv->view superview]) && !priv->_isRootView) {
        return;
    }

    if (orientation != UIInterfaceOrientationPortrait && orientation != UIInterfaceOrientationPortraitUpsideDown &&
        orientation != UIInterfaceOrientationLandscapeLeft && orientation != UIInterfaceOrientationLandscapeRight) {
        return;
    }

    UIInterfaceOrientation curOrientation = (UIInterfaceOrientation)[self interfaceOrientation];
    orientation = supportedOrientationForOrientation(self, orientation);

    if (orientation != -1) {
        if ((orientation != priv->_curOrientation) || !priv->_didSetRotation ||
            orientation != [[UIApplication sharedApplication] statusBarOrientation]) {
            bool sendEvent = orientation != priv->_curOrientation;
            if (sendEvent)
                [self willRotateToInterfaceOrientation:orientation duration:0.25];

            int oldOrientation = priv->_curOrientation;
            priv->_curOrientation = orientation;
            priv->_didSetRotation = true;
            [self setOrientationInternal:orientation animated:animated];

            if (sendEvent)
                [self didRotateFromInterfaceOrientation:oldOrientation];
        }
    }
}

- (id)initWithCoder:(NSCoder*)coder {
    UIView* view = [coder decodeObjectForKey:@"UIView"];
    [self setView:view];

    priv->navigationItem = [coder decodeObjectForKey:@"UINavigationItem"];
    if (priv->navigationItem != nil) {
        EbrDebugLog("UIVIewController navigationItem is %s\n", object_getClassName(priv->navigationItem));
    }

    priv->nibName = [coder decodeObjectForKey:@"UINibName"];
    priv->tabBarItem = [coder decodeObjectForKey:@"UITabBarItem"];

    priv->toolbarItems = [coder decodeObjectForKey:@"UIToolbarItems"];

    if ([coder containsValueForKey:@"UIAutoresizesArchivedViewToFullSize"]) {
        priv->_autoresize = [coder decodeIntForKey:@"UIAutoresizesArchivedViewToFullSize"] != FALSE;
    } else
        priv->_autoresize = true;
    if ([coder containsValueForKey:@"UIWantsFullScreenLayout"]) {
        priv->_wantsFullScreenLayout = [coder decodeIntForKey:@"UIWantsFullScreenLayout"] != FALSE;
    };

    priv->_modalTemplates = [coder decodeObjectForKey:@"UIStoryboardSegueTemplates"];
    NSDictionary* objs = [coder decodeObjectForKey:@"UIExternalObjectsTableForViewLoading"];
    if (objs != nil) {
        priv->_externalObjects = objs;
    }

    priv->_childViewControllers = [coder decodeObjectForKey:@"UIChildViewControllers"];
    // assert(nibName != nil);
    priv->_edgesForExtendedLayout = [coder decodeIntForKey:@"UIKeyEdgesForExtendedLayout"];

    return self;
}

- (void)awakeFromNib {
    if (priv->view != nil && priv->hasLoaded == FALSE) {
        priv->hasLoaded = TRUE;
        [self viewDidLoad];
    }
}

- (NSString*)nibName {
    if (priv->nibName == nil) {
        NSString* ret = nil;
        NSString* nibPath;

        char* ourClass = _strdup(object_getClassName(self));
        char tryClass[255];

        assert(strlen(ourClass) < 255);

        if (strlen(ourClass) > strlen("Controller")) {
            if (strcmp(&ourClass[strlen(ourClass) - strlen("Controller")], "Controller") == 0) {
                //  Try to find the name of just the controller
                strcpy(tryClass, ourClass);
                tryClass[strlen(tryClass) - strlen("Controller")] = 0;
                nibPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithCString:tryClass] ofType:@"nib"];
                if (nibPath != nil) {
                    ret = [NSString stringWithCString:tryClass];
                }
            }
        }

        if (nibPath == nil) {
            nibPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithCString:ourClass] ofType:@"nib"];
            if (nibPath != nil) {
                ret = [NSString stringWithCString:ourClass];
            }
        }

        free(ourClass);

        return ret;
    }

    return (NSString*)(priv->nibName);
}

- (NSBundle*)nibBundle {
    return priv->nibBundle;
}

- (instancetype)initWithNibName:(NSString*)strNib bundle:(NSBundle*)bundle {
    if (!priv) {
        priv = (UIViewControllerPriv*)EbrCalloc(1, sizeof(UIViewControllerPriv));
        priv->_curOrientation = UIInterfaceOrientationPortrait;
        priv->_contentSizeForViewInPopover.width = 320.0f;
        priv->_contentSizeForViewInPopover.height = 1100.0f;
    }

    if (bundle == nil) {
        priv->nibBundle = [NSBundle mainBundle];
    } else {
        priv->nibBundle = bundle;
    }

    if (strNib) {
        const char* name = (const char*)[strNib UTF8String];
        char openname[255];

        sprintf(openname, "%s", name);

        priv->nibName = [strNib copy];
    } else {
        priv->nibName = nil;
    }

    return self;
}

- (instancetype)init {
    [super init];

    return [self initWithNibName:nil bundle:nil];
}

- (void)loadView {
    if (priv->view != nil) {
        return;
    }

    NSString* nibPath = nil;

    if (priv->nibName != nil) {
        if (priv->nibBundle != nil) {
            nibPath = [priv->nibBundle pathForResource:priv->nibName ofType:@"nib"];
        }

        if (nibPath == nil)
            nibPath = [[NSBundle mainBundle] pathForResource:priv->nibName ofType:@"nib"];
        if (nibPath == nil) {
            NSString* storyboardPath = [priv->_storyboard _path];

            if (storyboardPath != nil) {
                NSString* runtimePath = [storyboardPath stringByAppendingPathComponent:priv->nibName];
                runtimePath = [runtimePath stringByAppendingString:@".nib"];

                EbrDebugLog("Searching = %s\n", (char*)[runtimePath UTF8String]);
                nibPath = [[NSBundle mainBundle] pathForResource:@"runtime" ofType:@"nib" inDirectory:runtimePath];

                if (nibPath == nil) {
                    nibPath = [[NSBundle mainBundle] pathForResource:priv->nibName ofType:@"nib" inDirectory:storyboardPath];
                }
            }
        }

        if (nibPath == nil) {
            EbrDebugLog("Couldn't find %s\n", [priv->nibName UTF8String]);
            assert(0);
        }
    } else {
        char* ourClass = _strdup(object_getClassName(self));
        char tryClass[255];

        assert(strlen(ourClass) < 255);

        if (strlen(ourClass) > strlen("Controller")) {
            if (strcmp(&ourClass[strlen(ourClass) - strlen("Controller")], "Controller") == 0) {
                //  Try to find the name of just the controller
                strcpy(tryClass, ourClass);
                tryClass[strlen(tryClass) - strlen("Controller")] = 0;
                nibPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithCString:tryClass] ofType:@"nib"];
            }
        }

        if (nibPath == nil) {
            nibPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithCString:ourClass] ofType:@"nib"];
        }

        free(ourClass);
        // if ( nibPath == nil ) assert(0);
    }

    if (nibPath != nil) {
        char* openname = (char*)[nibPath UTF8String];
        if (EbrAccess(openname, 0) == -1) {
            nibPath = [nibPath stringByAppendingPathComponent:@"/runtime.nib"];
            openname = (char*)[nibPath UTF8String];
        }

        const char* name = (const char*)[nibPath UTF8String];

        EbrDebugLog("Loading view %s with owner=%s\n", name ? name : "nil", object_getClassName(self));

        if (EbrAccess(openname, 0) != -1) {
            UIStoryboard* proxyObjects[1];
            NSString* proxyNames[1];

            proxyObjects[0] = [self storyboard];
            proxyNames[0] = @"UIStoryboardPlaceholder";

            NSMutableDictionary* proxyObjectsDict = [NSMutableDictionary dictionaryWithObjects:proxyObjects forKeys:proxyNames count:1];
            [proxyObjectsDict addEntriesFromDictionary:priv->_externalObjects];

            NSNib* nib = [NSNib alloc];
            [nib loadNib:[NSString stringWithCString:openname] withOwner:self proxies:proxyObjectsDict];
            [nib release];
            priv->_externalObjects = nil;
        } else {
            assert(0);
        }
    }

    if (priv->view == nil) {
        CGRect frame = { 0.0f, 0.0f, GetCACompositor()->screenWidth(), GetCACompositor()->screenHeight() };

        frame = [[UIScreen mainScreen] applicationFrame]; /** This is correct **/
        if (priv->_presentationStyle == UIModalPresentationFormSheet) {
            CGRect screenFrame;
            screenFrame = [[UIScreen mainScreen] applicationFrame];

            frame.size.width = 540;
            frame.size.height = 575;

            frame.origin.x = screenFrame.origin.x + screenFrame.size.width / 2.0f - frame.size.width / 2.0f;
            frame.origin.y = screenFrame.origin.y + screenFrame.size.height / 2.0f - frame.size.height / 2.0f;
        }

        UIView* view = [[[UIEmptyController alloc] initWithFrame:frame] autorelease];
        [view setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
        [self setView:view];
    }

    [self _doResizeToScreen];
    priv->_externalObjects = nil;
}

- (void)_doResizeToScreen {
    if ((priv->_resizeToScreen && priv->view && priv->_autoresize) || priv->_wantsFullScreenLayout) {
        CGRect frame = { 0.0f, 0.0f, GetCACompositor()->screenHeight(), GetCACompositor()->screenWidth() };

        if (priv->_wantsFullScreenLayout) {
            frame = [[UIScreen mainScreen] bounds];
        } else {
            frame = [[UIScreen mainScreen] applicationFrame];
        }

        if (priv->_presentationStyle == UIModalPresentationFormSheet) {
            CGRect screenFrame;
            screenFrame = [[UIScreen mainScreen] applicationFrame];

            frame.size.width = 540;
            frame.size.height = 575;

            frame.origin.x = screenFrame.origin.x + screenFrame.size.width / 2.0f - frame.size.width / 2.0f;
            frame.origin.y = screenFrame.origin.y + screenFrame.size.height / 2.0f - frame.size.height / 2.0f;
        }
        UIInterfaceOrientation curOrientation = (UIInterfaceOrientation)[[UIApplication sharedApplication] statusBarOrientation];

        /*
        switch ( curOrientation ) {
        case UIInterfaceOrientationLandscapeLeft:
        case UIInterfaceOrientationLandscapeRight: {
        float temp = frame.size.width;
        frame.size.width = frame.size.height;
        frame.size.height = temp;
        }
        break;
        }
        */
        [priv->view setFrame:frame];
    }
}

- (UIView*)view {
    if (priv->view == nil) {
        priv->isLoading = TRUE;
        [self loadView];
        priv->isLoading = FALSE;

        if (priv->view == nil) {
            EbrDebugLog("Class name=%s\n", object_getClassName(self));
            CGRect frame = { 0.0f, 0.0f, GetCACompositor()->screenHeight(), GetCACompositor()->screenWidth() };

            frame = [[UIScreen mainScreen] applicationFrame];
            if (priv->_presentationStyle == UIModalPresentationFormSheet) {
                CGRect screenFrame;
                screenFrame = [[UIScreen mainScreen] applicationFrame];

                frame.size.width = 540;
                frame.size.height = 575;

                frame.origin.x = screenFrame.origin.x + screenFrame.size.width / 2.0f - frame.size.width / 2.0f;
                frame.origin.y = screenFrame.origin.y + screenFrame.size.height / 2.0f - frame.size.height / 2.0f;
            }

            UIView* view = [[[UIEmptyController alloc] initWithFrame:frame] autorelease];
            [self setView:view];
        }
    }

    if (!priv->hasLoaded && priv->isLoading == FALSE) {
        priv->hasLoaded = TRUE;
        [self viewDidLoad];
    }

    return priv->view;
}

- (UINavigationItem*)navigationItem {
    if (priv->navigationItem == nil) {
        priv->navigationItem.attach([[UINavigationItem alloc] initWithTitle:nil]);
    }

    return priv->navigationItem;
}

- (UINavigationController*)navigationController {
    UIViewController* curController = [self parentViewController];
    while (curController != nil) {
        if ([curController isKindOfClass:[UINavigationController class]]) {
            return (UINavigationController*)curController;
        }
        curController = [curController parentViewController];
    }
    return nil;
}

- (UISearchDisplayController*)searchDisplayController {
    return priv->_searchDisplayController;
}

- (void)setSearchDisplayController:(UISearchDisplayController*)newController {
    priv->_searchDisplayController = newController;
}

- (UIViewController*)modalViewController {
    return priv->_modalViewController;
}

- (void)setView:(UIView*)newView {
    if (newView == priv->view)
        return;

    UIView* oldSuper = nil;
    UIView* oldView = nil;
    if (priv->view != nil) {
        oldView = priv->view;
        oldSuper = [oldView superview];
        removeViewMapping(priv->view);
    }

    priv->view = newView;

    if (priv->view != nil) {
        CGRect curRect = [priv->view bounds];
        CGRect appFrame = [[UIScreen mainScreen] applicationFrame];

        if ((curRect.size.width == 0.0f && curRect.size.height == 0.0f) || curRect.size.width > appFrame.size.width ||
            curRect.size.height > appFrame.size.height) {
            appFrame.origin.x = 0.0f;
            appFrame.origin.y = 0.0f;
            [priv->view setFrame:appFrame];
        }

        /*
        if ( curSize.size.width == 320.0f &&
        (curSize.size.height == 460.0f || curSize.size.height == 480.0f) ) {
        CGRect frame;

        frame = [[UIScreen mainScreen] bounds];
        frame.size.height -= 480.0f - curSize.size.height;
        frame.origin.y += 480.0f - curSize.size.height;

        [priv->view setFrame:frame];
        }
        */

        addViewMapping(priv->view, self);
        if (oldSuper != nil && oldSuper != priv->view) {
            [oldSuper insertSubview:priv->view aboveSubview:oldView];
            [priv->view setHidden:FALSE];
            [oldView removeFromSuperview];
            [oldSuper setNeedsLayout];
        }
    }
}

- (void)setNavigationItem:(UINavigationItem*)newItem {
    priv->navigationItem = newItem;
}

- (UITabBarItem*)tabBarItem {
    if (priv->tabBarItem == nil) {
        priv->tabBarItem.attach([[UITabBarItem alloc] initWithTitle:priv->_title image:nil tag:nil]);
        EbrDebugLog("New tab: %s\n", object_getClassName(self));
    }

    return priv->tabBarItem;
}

- (UITabBarItem*)_tabBarItem {
    return priv->tabBarItem;
}

- (UIBarButtonItem*)editButtonItem {
    if (priv->editButtonItem == nil) {
        priv->editButtonItem.attach([[UIBarButtonItem alloc] initWithTitle:priv->_isEditing ? @"Done" : @"Edit"
                                                                     style:UIBarButtonItemStylePlain
                                                                    target:self
                                                                    action:@selector(_editPressed:)]);
    }

    return priv->editButtonItem;
}

- (void)_editPressed:(id)item {
    if (priv->_isEditing) {
        [self setEditing:FALSE animated:TRUE];
    } else {
        [self setEditing:TRUE animated:TRUE];
    }
}

- (void)setTabBarItem:(UITabBarItem*)newItem {
    priv->tabBarItem = newItem;
}

- (void)setToolbarItems:(NSArray*)newItems animated:(BOOL)animated {
    priv->toolbarItems = newItems;
}

- (NSArray*)toolbarItems {
    return priv->toolbarItems;
}

- (void)setToolbarItems:(NSArray*)newItems {
    [self setToolbarItems:newItems animated:FALSE];
}

- (void)presentModalViewController:(UIViewController*)controller animated:(BOOL)animated {
    [self presentViewController:controller animated:animated completion:nil];
}

- (void)presentViewController:(UIViewController*)controller animated:(BOOL)animated completion:(void (^)(void))completion {
    bool shouldShow = false;
    UIViewController* curController = self;
    while (curController != nil) {
        if (curController->priv->_visibility != controllerNotVisible) {
            shouldShow = true;
        }
        curController = curController->priv->_parentViewController;
    }
    if (!shouldShow) {
        EbrDebugLog("Controller is not visible!\n");
        return;
    }

    UIViewController* oldViewController = self;
    if (priv->_modalViewController != nil) {
        oldViewController = priv->_modalViewController;
        EbrDebugLog("Can't present view controller %08x (%s) - view controller %08x (%s) already has a presented controller!\n",
                    controller,
                    object_getClassName(controller),
                    self,
                    object_getClassName(self));
        return;
    }

    if (controller != nil) {
        [[UIApplication sharedApplication] beginIgnoringInteractionEvents];
    }

    [self notifyViewWillDisappear:animated];

    priv->_modalViewController = controller;
    priv->_presentedViewController = controller;
    if (controller != nil) {
        [controller view];
        controller->priv->_parentViewController = self;
        controller->priv->_presentingViewController = self;
        [controller performSelector:@selector(_addToTop:) withObject:[NSNumber numberWithInt:animated] afterDelay:0.0];
    }

    /*
    else {
    //[self notifyViewWillDisappear:FALSE];

    priv->_modalViewController = controller;
    controller->priv->_parentViewController = self;

    id view = [controller view];

    id parentView = [self view];
    parentView = [parentView window];

    if ( parentView != nil ) {
    [parentView addSubview:view];
    } else {
    [[[[UIApplication sharedApplication] windows] objectAtIndex:1] addSubview:view];
    }

    //[self notifyViewDidDisappear:FALSE];

    int toOrientation = [[UIDevice currentDevice] orientation];
    if ( controller->priv->_parentViewController != nil ) {
    int parentOrientation = [controller->priv->_parentViewController interfaceOrientation];
    if ( parentOrientation != 0 ) {
    toOrientation = parentOrientation;
    }
    }
    [controller setRotation:toOrientation animated:0];
    }
    */

    if (completion) {
        completion();
    }
}

- (void)dismissModalViewControllerAnimated:(BOOL)animated {
    [self dismissViewControllerAnimated:animated completion:nil];
    /*
    if ( priv->_modalViewController == nil ) {
    if ( priv->_parentViewController ) {
    return [priv->_parentViewController dismissModalViewControllerAnimated:animated];
    }
    EbrDebugLog("dismissModalViewController invalid!\n");
    //assert(0);
    return nil;
    }

    UIViewController* curController = priv->_modalViewController;

    [curController retain];
    [curController autorelease];

    [self notifyViewWillAppear:animated];

    priv->_modalViewController = nil;
    curController->priv->_parentViewController = nil;
    curController->priv->_presentingViewController = nil;

    id curView = [curController view];
    [curView removeFromSuperview];

    id myView = [self view];
    [myView setHidden:FALSE];

    if ( [[self view] superview] == nil ) {
    EbrDebugLog("View is not part of the heirarchy!\n");
    *((char *) 0) = 0;
    } else {
    [[[self view] superview] bringSubviewToFront:[self view]];
    }
    [self notifyViewDidAppear:animated];

    return self;
    */
}

- (void)_notifyDidDisappearAnimated:(UIView*)view {
    LLTREE_FOREACH(subview, view->priv) {
        [self _notifyDidDisappearAnimated:subview->self];
    }

    UIViewController* controller = [UIViewController controllerForView:view];

    if (controller != nil) {
        [controller notifyViewDidDisappear:TRUE];
    }
}

- (void)_dismissTransitionStopped:(id)anim finished:(BOOL)finished {
    UIView* view = [priv->_dismissController view];
    [[view layer] removeAnimationForKey:@"ModalDismiss"];

    [self _notifyDidDisappearAnimated:view];
    [self notifyViewDidAppear:TRUE];

    if (priv->_dismissCompletionBlock != nil) {
        priv->_dismissCompletionBlock();
        [priv->_dismissCompletionBlock release];
        priv->_dismissCompletionBlock = nil;
    }

    [view removeFromSuperview];
    priv->_dismissController = nil;
    [[UIApplication sharedApplication] endIgnoringInteractionEvents];
}

- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion {
    if (priv->_modalViewController == nil) {
        if (priv->_parentViewController) {
            return;
        }
        EbrDebugLog("dismissModalViewController invalid!\n");
        // assert(0);
        return;
    }

    UIViewController* curController = priv->_modalViewController;

    [curController retain];
    [curController autorelease];

    if (curController->priv->_modalViewController) {
        [curController dismissViewControllerAnimated:animated completion:completion];
    }

    [self notifyViewWillAppear:animated];

    priv->_modalViewController = nil;
    priv->_presentedViewController = nil;
    curController->priv->_parentViewController = nil;
    curController->priv->_presentingViewController = nil;

    UIView* curView = [curController view];

    UIView* myView = [self view];
    [myView setHidden:FALSE];

    if (animated) {
        CGPoint curPos;
        id layer = [curView layer];

        curPos = [layer position];

        CABasicAnimation* animation = [CABasicAnimation animationWithKeyPath:@"position"];
        [animation setFromValue:[NSValue valueWithCGPoint:curPos]];

        int orientation = findOrientation(self);
        if (orientation == UIInterfaceOrientationPortrait) {
            curPos.y += GetCACompositor()->screenHeight();
        } else if (orientation == UIInterfaceOrientationPortraitUpsideDown) {
            curPos.y -= GetCACompositor()->screenHeight();
        } else if (orientation == UIInterfaceOrientationLandscapeLeft) {
            curPos.x += GetCACompositor()->screenWidth();
        } else {
            curPos.x -= GetCACompositor()->screenWidth();
        }
        // curPos.y += GetCACompositor()->screenHeight();

        [[UIApplication sharedApplication] beginIgnoringInteractionEvents];
        [animation setToValue:[NSValue valueWithCGPoint:curPos]];
        [animation setDuration:0.2f];
        [animation setTimingFunction:[CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseInEaseOut"]];
        [animation
            setDelegate:[_TransitionNotifier _transitionTrampoline:self withSelector:@selector(_dismissTransitionStopped:finished:)]];
        [animation setRemovedOnCompletion:FALSE];
        [layer addAnimation:animation forKey:@"ModalDismiss"];

        priv->_dismissCompletionBlock = [[completion copy] autorelease];
        priv->_dismissController = curController;
        [curController notifyViewWillDisappear:TRUE];
    } else {
        [curController notifyViewWillDisappear:animated];
        [curView removeFromSuperview];

        if ([[self view] superview] == nil) {
            // EbrDebugLog("View is not part of the heirarchy!\n");
            //*((char *) 0) = 0;
        } else {
            [[[self view] superview] bringSubviewToFront:[self view]];
        }

        [curController notifyViewDidDisappear:FALSE];
        [self notifyViewDidAppear:animated];
        EbrDebugLog("Preparing completion\n");
        if (completion != nil)
            completion();
        EbrDebugLog("Done completion\n");
    }
}

- (void)_notifyDidAppearAnimated:(UIView*)view {
    LLTREE_FOREACH(subview, view->priv) {
        [self _notifyDidAppearAnimated:subview->self];
    }

    UIViewController* controller = [UIViewController controllerForView:view];
    if (controller != nil) {
        [controller notifyViewDidAppear:TRUE];
    }
}

- (void)_transitionStopped:(id)context {
    UIView* view = [self view];

    [[priv->_parentViewController view] setHidden:TRUE];
    [self _notifyDidAppearAnimated:view];
    [[UIApplication sharedApplication] endIgnoringInteractionEvents];
}

- (void)_addToTop:(NSNumber*)animatedValue {
    BOOL animated = [animatedValue intValue];

    priv->_isRootView = true;

    if (priv->_parentViewController != nil) {
        float endY = 0;

        UIView* view = [self view];
        UIWindow* parentWindow = [[priv->_parentViewController view] window];

        if (animated) {
            g_presentingAnimated = TRUE;
            [[UIApplication sharedApplication] beginIgnoringInteractionEvents];
            [self notifyViewWillAppear:TRUE];
        } else {
            [[priv->_parentViewController view] setHidden:TRUE];
        }

        if (parentWindow != nil) {
            [parentWindow addSubview:view];
        } else {
            [[[[UIApplication sharedApplication] windows] objectAtIndex:1] addSubview:view];
        }

        if (animated) {
            CGPoint curPos;
            CALayer* layer = [view layer];

            curPos = [layer position];

            int orientation = findOrientation(self);
            if (orientation == UIInterfaceOrientationPortrait) {
                curPos.y += GetCACompositor()->screenHeight();
            } else if (orientation == UIInterfaceOrientationPortraitUpsideDown) {
                curPos.y -= GetCACompositor()->screenHeight();
            } else if (orientation == UIInterfaceOrientationLandscapeLeft) {
                curPos.x += GetCACompositor()->screenWidth();
            } else {
                curPos.x -= GetCACompositor()->screenWidth();
            }

            CABasicAnimation* animation = [CABasicAnimation animationWithKeyPath:@"position"];
            [animation setFromValue:[NSValue valueWithCGPoint:curPos]];

            if (orientation == UIInterfaceOrientationPortrait) {
                curPos.y -= GetCACompositor()->screenHeight();
            } else if (orientation == UIInterfaceOrientationPortraitUpsideDown) {
                curPos.y += GetCACompositor()->screenHeight();
            } else if (orientation == UIInterfaceOrientationLandscapeLeft) {
                curPos.x -= GetCACompositor()->screenWidth();
            } else {
                curPos.x += GetCACompositor()->screenWidth();
            }

            [animation setToValue:[NSValue valueWithCGPoint:curPos]];
            [animation setDuration:0.2f];
            [animation setTimingFunction:[CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseInEaseOut"]];
            [animation setDelegate:[_TransitionNotifier _transitionTrampoline:self withSelector:@selector(_transitionStopped:)]];
            [layer addAnimation:animation forKey:@"ModalPresent"];
            g_presentingAnimated = FALSE;
        }

        [priv->_parentViewController notifyViewDidDisappear:animated];
    } else {
        EbrDebugLog("Modal controller doesn't have a parent!\n");
    }

    [[UIApplication sharedApplication] endIgnoringInteractionEvents];
}

- (void)setNavigationController:(id)controller {
    priv->navigationController = controller;
}

- (BOOL)_rotationLocked:(UIInterfaceOrientation)curOrientation {
    // By default our rotation is not locked:
    return FALSE;
}

- (BOOL)shouldAutorotate {
    return TRUE;
}

- (void)setModalInPopover:(BOOL)isModal {
    priv->_modalInPopover = isModal;
}

- (BOOL)isModalInPopover {
    return priv->_modalInPopover;
}

static UIInterfaceOrientation findOrientation(UIViewController* self) {
    UIInterfaceOrientation orientation = (UIInterfaceOrientation)[[UIDevice currentDevice] orientation];
    if (self->priv->_parentViewController != nil && [self->priv->_parentViewController _rotationLocked:orientation]) {
        UIInterfaceOrientation parentOrientation = (UIInterfaceOrientation)[self->priv->_parentViewController interfaceOrientation];
        if (parentOrientation != 0) {
            orientation = parentOrientation;
        }
    }
    return orientation;
}

- (void)notifyViewWillAppear:(BOOL)isAnimated {
    switch (priv->_visibility) {
        case controllerNotVisible: {
            UIViewController* parent = self;
            UIViewController* nextParent = [parent parentViewController];
            while (nextParent != nil) {
                parent = nextParent;
                nextParent = [parent parentViewController];
            }

            UIInterfaceOrientation toOrientation = findOrientation(self);

            [self setRotation:toOrientation animated:FALSE];
            [parent setRotation:toOrientation animated:FALSE];

            if (isAnimated) {
                priv->_visibility = controllerWillAppearAnimated;
            } else {
                priv->_visibility = controllerWillAppear;
            }
            if (priv->_searchDisplayController) {
                [priv->_searchDisplayController notifyViewWillAppear:isAnimated];
            }
            [self viewWillAppear:isAnimated];
        } break;

        case controllerWillAppear:
        case controllerWillAppearAnimated:
            break;

        case controllerVisible:
            break;

        case controllerWillDisappearAnimated:
        case controllerWillDisappear:
            break;

        default:
            assert(0);
            break;
    }

    if (priv->_didSetRotation && [self interfaceOrientation] != [[UIApplication sharedApplication] statusBarOrientation]) {
        int ourOrientation = [self interfaceOrientation];
        [[UIApplication sharedApplication] setStatusBarOrientation:ourOrientation];
    }
}

- (void)notifyViewDidAppear:(BOOL)isAnimated {
    switch (priv->_visibility) {
        case controllerWillAppear:
            if (isAnimated == FALSE) {
                priv->_visibility = controllerVisible;
                if (priv->_searchDisplayController) {
                    [priv->_searchDisplayController notifyViewDidAppear:isAnimated];
                }
                [self viewDidAppear:isAnimated];
            } else {
                assert(0);
            }
            break;

        case controllerWillAppearAnimated:
            if (isAnimated) {
                priv->_visibility = controllerVisible;
                if (priv->_searchDisplayController) {
                    [priv->_searchDisplayController notifyViewDidAppear:isAnimated];
                }
                [self viewDidAppear:isAnimated];
            }
            break;

        case controllerWillDisappearAnimated:
        case controllerWillDisappear:
            EbrDebugLog("Warning: Can't notify controller appeared when disappearing\n");
            break;

        case controllerNotVisible:
            EbrDebugLog("Warning: Controller not visible\n");
            break;

        case controllerVisible:
            break;

        default:
            assert(0);
            break;
    }
}

- (void)notifyViewWillDisappear:(BOOL)isAnimated {
    switch (priv->_visibility) {
        case controllerNotVisible:
            break;

        case controllerVisible:
            [UIResponder _resignCurResponder];

            if (isAnimated == FALSE) {
                priv->_visibility = controllerWillDisappear;
                if (priv->_searchDisplayController) {
                    [priv->_searchDisplayController notifyViewWillDisappear:isAnimated];
                }
                [self viewWillDisappear:isAnimated];
            } else {
                priv->_visibility = controllerWillDisappearAnimated;
                if (priv->_searchDisplayController) {
                    [priv->_searchDisplayController notifyViewWillDisappear:isAnimated];
                }
                [self viewWillDisappear:isAnimated];
            }
            break;

        case controllerWillAppear:
        case controllerWillAppearAnimated:
        case controllerWillDisappear:
        case controllerWillDisappearAnimated:
            break;

        default:
            assert(0);
            break;
    }
}

- (void)notifyViewDidDisappear:(BOOL)isAnimated {
    switch (priv->_visibility) {
        case controllerNotVisible:
            break;

        case controllerWillDisappear:
            if (isAnimated == FALSE) {
                priv->_visibility = controllerNotVisible;
                if (priv->_searchDisplayController) {
                    [priv->_searchDisplayController notifyViewDidDisappear:isAnimated];
                }
                [self viewDidDisappear:isAnimated];
            } else {
                // assert(0);
            }
            break;

        case controllerWillDisappearAnimated:
            if (isAnimated) {
                priv->_visibility = controllerNotVisible;
                if (priv->_searchDisplayController) {
                    [priv->_searchDisplayController notifyViewDidDisappear:isAnimated];
                }
                [self viewDidDisappear:isAnimated];
            }
            break;

        case controllerVisible:
            EbrDebugLog("Warning: Didn't notify view will disappear\n");
            priv->_visibility = controllerNotVisible;
            if (priv->_searchDisplayController) {
                [priv->_searchDisplayController notifyViewDidDisappear:isAnimated];
            }
            [self viewDidDisappear:isAnimated];
            break;

        case controllerWillAppearAnimated:
        case controllerWillAppear:
            break;

        default:
            assert(0);
            break;
    }
}

- (void)beginAppearanceTransition:(BOOL)appearing animated:(BOOL)isAnimated {
    if (appearing) {
        [self notifyViewWillAppear:isAnimated];
    } else {
        [self notifyViewWillDisappear:isAnimated];
    }
}

- (void)endAppearanceTransition {
    switch (priv->_visibility) {
        case controllerWillAppear:
            [self notifyViewDidAppear:FALSE];
            break;

        case controllerWillAppearAnimated:
            [self notifyViewDidAppear:TRUE];
            break;

        case controllerWillDisappear:
            [self notifyViewDidDisappear:FALSE];
            break;

        case controllerWillDisappearAnimated:
            [self notifyViewDidDisappear:TRUE];
            break;
    }
}

- (void)viewWillAppear:(BOOL)isAnimated {
}

- (void)viewDidAppear:(BOOL)isAnimated {
}

- (void)viewWillDisappear:(BOOL)isAnimated {
}

- (void)viewDidDisappear:(BOOL)isAnimated {
}

- (void)setTitle:(NSString*)title {
    priv->_title = title;
    [[self navigationItem] setTitle:priv->_title];
    [[self tabBarItem] setTitle:priv->_title];
}

- (NSString*)title {
    return priv->_title;
}

- (void)setEditing:(BOOL)editing {
    [self setEditing:editing animated:FALSE];
}

- (void)setEditing:(BOOL)editing animated:(BOOL)animated {
    priv->_isEditing = editing;

    if (priv->editButtonItem != nil) {
        [priv->editButtonItem setTitle:priv->_isEditing ? @"Done" : @"Edit"];
    }
}

- (BOOL)isEditing {
    return priv->_isEditing;
}

- (void)viewDidLoad {
}

- (void)viewDidUnload {
}

- (void)viewWillUnload {
}

- (void)viewDidLayoutSubviews {
}

- (BOOL)isViewLoaded {
    return priv->view != nil;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskAllButUpsideDown;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)orientation {
    return orientation == UIInterfaceOrientationPortrait;
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)orientation duration:(double)duration {
}

- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)orientation duration:(double)duration {
}

- (int)_edgesForExtendedLayout {
    return priv->_edgesForExtendedLayout;
}

- (UIInterfaceOrientation)interfaceOrientation {
    if (!priv->_didSetRotation) {
        return (UIInterfaceOrientation)[[UIApplication sharedApplication] statusBarOrientation];
    }

    return priv->_curOrientation;
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)orientation {
}

- (void)willMoveToParentViewController:(UIViewController*)parent {
}

- (void)didMoveToParentViewController:(UIViewController*)parent {
}

+ (UIViewController*)controllerForView:(UIView*)view {
    return lookupViewController(view);
}

- (UIResponder*)nextResponder {
    if (priv->view != nil) {
        return [priv->view superview];
    }

    return nil;
}

- (UITabBarController*)tabBarController {
    UIViewController* cur = self;

    while (cur != nil) {
        EbrDebugLog("Class is %s\n", object_getClassName(cur));
        if ([cur isKindOfClass:[UITabBarController class]]) {
            return cur;
        }

        cur = [cur parentViewController];
    }

    return nil;
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    id nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesBegan:touches withEvent:event];
    }
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    UIResponder* nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesMoved:touches withEvent:event];
    }
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    UIResponder* nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesEnded:touches withEvent:event];
    }
}

- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
    UIResponder* nextResponder = [self nextResponder];

    if (nextResponder != nil) {
        [nextResponder touchesCancelled:touches withEvent:event];
    }
}

- (void)setHidesBottomBarWhenPushed:(BOOL)hide {
    priv->_hidesBottomBar = hide != FALSE;
}

- (BOOL)hidesBottomBarWhenPushed {
    return priv->_hidesBottomBar;
}

- (void)setModalTransitionStyle:(UIModalTransitionStyle)style {
    priv->_modalTransitionStyle = style;
}

- (UIModalTransitionStyle)modalTransitionStyle {
    return priv->_modalTransitionStyle;
}

- (void)setWantsFullScreenLayout:(BOOL)wantsFullScreen {
    priv->_wantsFullScreenLayout = wantsFullScreen != FALSE;
}

- (void)setContentSizeForViewInPopover:(CGSize)size {
    priv->_contentSizeForViewInPopover = size;
}

- (CGSize)contentSizeForViewInPopover {
    return priv->_contentSizeForViewInPopover;
}

- (void)setPreferredContentSize:(CGSize)size {
    priv->_preferredContentSize = size;
}

- (CGSize)preferredContentSize {
    return priv->_preferredContentSize;
}

- (void)setModalPresentationStyle:(UIModalPresentationStyle)style {
    priv->_presentationStyle = style;
}

- (UIModalPresentationStyle)modalPresentationStyle {
    return priv->_presentationStyle;
}

- (void)performSegueWithIdentifier:(NSString*)identifier sender:(id)sender {
    EbrDebugLog("perform segue for %s\n", [identifier UTF8String]);

    NSString* controllerName = nil;
    UIStoryboardSegueTemplate* segueTemplate = nil;

    for (UIStoryboardSegueTemplate* cur in (NSArray*)priv->_modalTemplates) {
        if ([[cur identifier] isEqualToString:identifier]) {
            controllerName = [cur destination];
            segueTemplate = cur;
            break;
        }
    }

    UIViewController* controller = [[self storyboard] instantiateViewControllerWithIdentifier:controllerName];
    UIStoryboardSegue* segue = [[UIStoryboardSegue alloc] initWithIdentifier:identifier source:self destination:controller];
    [self prepareForSegue:segue sender:sender];
    [controller setResizeToScreen:TRUE];

    if ([segueTemplate isKindOfClass:[UIStoryboardPushSegueTemplate class]]) {
        [[self navigationController] pushViewController:controller animated:TRUE];
    } else {
        [self presentModalViewController:controller animated:TRUE];
    }

    [segue release];
}

- (void)performSegueWithDestination:(NSString*)destination sender:(id)sender {
    EbrDebugLog("perform destination segue for %s\n", [destination UTF8String]);

    NSString* controllerName = nil;
    UIStoryboardSegueTemplate* segueTemplate = nil;

    for (UIStoryboardSegueTemplate* cur in (NSArray*)priv->_modalTemplates) {
        if ([[cur destination] isEqualToString:destination]) {
            controllerName = [cur destination];
            segueTemplate = cur;
            break;
        }
    }

    UIViewController* controller = [[self storyboard] instantiateViewControllerWithIdentifier:controllerName];
    UIStoryboardSegue* segue = [[UIStoryboardSegue alloc] initWithIdentifier:nil source:self destination:controller];
    [self prepareForSegue:segue sender:sender];
    [controller setResizeToScreen:TRUE];

    if ([segueTemplate isKindOfClass:[UIStoryboardPushSegueTemplate class]]) {
        [[self navigationController] pushViewController:controller animated:TRUE];
    } else {
        [self presentModalViewController:controller animated:TRUE];
    }
    [segue release];
}

- (void)prepareForSegue:(UIStoryboardSegue*)segue sender:(id)sender {
}

- (void)transitionFromViewController:(UIViewController*)fromController
                    toViewController:(UIViewController*)toController
                            duration:(double)duration
                             options:(unsigned)options
                          animations:(id)animations // TODO(DH): animations
                          completion:(void (^)(BOOL finished))completion {
    UIView* fromView = [fromController view];
    [fromView removeFromSuperview];
    UIView* toView = [toController view];

    CGRect bounds;
    bounds = [[self view] bounds];
    [toView setFrame:bounds];
    [[self view] addSubview:toView];
    completion(YES); // TODO(DH) "finished"?
}

- (void)setStoryboard:(id)storyboard {
    priv->_storyboard = storyboard;
}

- (UIStoryboard*)storyboard {
    return priv->_storyboard;
}

- (BOOL)wantsFullScreenLayout {
    return priv->_wantsFullScreenLayout;
}

- (UIViewController*)parentViewController {
    return priv->_parentViewController;
}

- (UIViewController*)presentingViewController {
    if (priv->_presentingViewController == nil) {
        return [priv->_parentViewController presentingViewController];
    }

    return priv->_presentingViewController;
}

- (UIViewController*)presentedViewController {
    if (priv->_presentedViewController == nil) {
        return [priv->_parentViewController presentingViewController];
    }

    return priv->_presentingViewController;
}

- (void)dealloc {
    EbrDebugLog("View controller dealloc: %s\n", object_getClassName(self));
    if (priv->view != nil) {
        removeViewMapping(priv->view);
    }

    //  Don't remove our view from the heirarchy on dealloc
    //  since there could be animations being performed
    //  [Will this cause memory leaks?]
    //[priv->view removeFromSuperview];

    priv->view = nil;
    priv->navigationItem = nil;
    priv->tabBarItem = nil;
    priv->toolbarItems = nil;
    priv->editButtonItem = nil;
    priv->navigationController = nil;
    if (priv->_modalViewController) {
        ((UIViewController*)priv->_modalViewController)->priv->_parentViewController = nil;
    }
    priv->_modalViewController = nil;
    priv->_parentViewController = nil;
    priv->nibName = nil;
    priv->nibBundle = nil;
    priv->_title = nil;
    priv->_externalObjects = nil;

    //  Remove us from being the parent of our child view controller.
    //  Should we call controller->removeFromParentViewController instead?
    for (UIViewController* curController in (NSArray*)priv->_childViewControllers) {
        curController->priv->_parentViewController = nil;
    }

    priv->_childViewControllers = nil;
    priv->_searchDisplayController = nil;
    priv->_storyboard = nil;
    priv->_modalTemplates = nil;
    priv->_dismissController = nil;
    EbrFree(priv);

    //  For safety since most people seem to forget
    [[NSNotificationCenter defaultCenter] removeObserver:self];

    [super dealloc];
}

- (id)undoManager {
    //  This should come from UIResponder, which we do not actually inherit from
    EbrDebugLog("Undo manager not supported\n");

    return nil;
}

- (void)didReceiveMemoryWarning {
}

- (void)setNeedsStatusBarAppearanceUpdate {
    EbrDebugLog("ignoring setNeedsStatusBarAppearanceUpdate!\n");
}

- (NSArray*)childViewControllers {
    if (priv->_childViewControllers == nil) {
        priv->_childViewControllers.attach([NSMutableArray new]);
    }
    return priv->_childViewControllers;
}

- (void)addChildViewController:(UIViewController*)controller {
    if (priv->_childViewControllers == nil) {
        priv->_childViewControllers.attach([NSMutableArray new]);
    }

    UIViewController* child = controller;
    if (child->priv->_parentViewController) {
        [controller removeFromParentViewController];
    }

    [priv->_childViewControllers addObject:controller];
    child->priv->_parentViewController = self;
}

- (void)removeFromParentViewController {
    UIViewController* parent = priv->_parentViewController;

    if (parent != nil)
        [parent->priv->_childViewControllers removeObject:self];
}

- (id<UILayoutSupport>)topLayoutGuide {
    UIView* view = priv->view;

    if (!view) {
        return nil;
    }

    for (int i = 0; i < [view.subviews count]; i++) {
        UIView* child = (UIView*)[view.subviews objectAtIndex:i];
        if ([child isKindOfClass:[_UILayoutGuide class]]) {
            _UILayoutGuide* guide = (_UILayoutGuide*)child;
            if ([guide->_identifier isEqual:@"_UIViewControllerTop"]) {
                return guide;
            }
        }
    }

    _UILayoutGuide* tlg = [[_UILayoutGuide alloc] initWithIdentifier:@"_UIViewControllerTop"];
    [view addSubview:tlg];
    [view addConstraint:[NSLayoutConstraint constraintWithItem:view
                                                     attribute:NSLayoutAttributeTop
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:tlg
                                                     attribute:NSLayoutAttributeTop
                                                    multiplier:1.0f
                                                      constant:0]];
    [view addConstraint:[_UILayoutSupportConstraint constraintWithItem:tlg
                                                             attribute:NSLayoutAttributeHeight
                                                             relatedBy:NSLayoutRelationEqual
                                                                toItem:nil
                                                             attribute:NSLayoutAttributeNotAnAttribute
                                                            multiplier:1.0f
                                                              constant:0]];

    return tlg;
}

- (id<UILayoutSupport>)bottomLayoutGuide {
    UIView* view = priv->view;

    if (!view) {
        return nil;
    }

    for (int i = 0; i < [view.subviews count]; i++) {
        UIView* child = (UIView*)[view.subviews objectAtIndex:i];
        if ([child isKindOfClass:[_UILayoutGuide class]]) {
            _UILayoutGuide* guide = (_UILayoutGuide*)child;
            if ([guide->_identifier isEqual:@"_UIViewControllerBottom"]) {
                return guide;
            }
        }
    }

    _UILayoutGuide* blg = [[_UILayoutGuide alloc] initWithIdentifier:@"_UIViewControllerBottom"];
    [view addSubview:blg];
    [view addConstraint:[NSLayoutConstraint constraintWithItem:view
                                                     attribute:NSLayoutAttributeBottom
                                                     relatedBy:NSLayoutRelationEqual
                                                        toItem:blg
                                                     attribute:NSLayoutAttributeBottom
                                                    multiplier:1.0f
                                                      constant:0]];
    [view addConstraint:[_UILayoutSupportConstraint constraintWithItem:blg
                                                             attribute:NSLayoutAttributeHeight
                                                             relatedBy:NSLayoutRelationEqual
                                                                toItem:nil
                                                             attribute:NSLayoutAttributeNotAnAttribute
                                                            multiplier:1.0f
                                                              constant:0]];

    return blg;
}

- (void)viewWillLayoutSubviews {
}

- (void)updateViewConstraints {
    [((UIView*)(priv->view))_applyConstraints];
}
@end
