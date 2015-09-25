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

#include "UIKit/UIView.h"
#include "UIKit/UIDevice.h"
#include "UIKit/UIApplication.h"
#include "Foundation/NSArray.h"
#include "UIKit/UIScreen.h"

extern float statusBarHeight;

@implementation UIScreenMode : NSObject
- (CGSize)size {
    CGSize ret;
    ret.width = GetCACompositor()->screenWidth() * GetCACompositor()->screenScale();
    ret.height = GetCACompositor()->screenHeight() * GetCACompositor()->screenScale();

    return ret;
}

@end

static UIScreen* mainScreen;
static UIScreenMode* curMode;

@implementation UIScreen : NSObject
+ (void)initialize {
    mainScreen = [self alloc];
    curMode = [UIScreenMode alloc];
}

+ (UIScreen*)mainScreen {
    return mainScreen;
}

- (UIScreenMode*)currentMode {
    return curMode;
}

+ (NSArray*)screens {
    return [NSArray arrayWithObject:mainScreen];
}

- (float)scale {
    return GetCACompositor()->screenScale();
}

- (float)brightness {
    return 1.0;
}

- (CGRect)bounds {
    CGRect ret;
    ret.origin.x = 0.0f;
    ret.origin.y = 0.0f;
    ret.size.width = GetCACompositor()->screenWidth();
    ret.size.height = GetCACompositor()->screenHeight();

    return ret;
}

- (CGRect)applicationFrame {
    BOOL isHidden = [[UIApplication sharedApplication] isStatusBarHidden];
    UIInterfaceOrientation statusBarOrientation =
        (UIInterfaceOrientation)[[UIApplication sharedApplication] statusBarOrientation];
    CGRect ret;
    ret.origin.x = 0.0f;
    ret.origin.y = 0.0f;
    ret.size.width = GetCACompositor()->screenWidth();
    ret.size.height = GetCACompositor()->screenHeight();

    if (!isHidden) {
        switch (statusBarOrientation) {
            case UIInterfaceOrientationLandscapeLeft:
                ret.origin.x += statusBarHeight;
                ret.size.width -= statusBarHeight;
                break;

            case UIInterfaceOrientationLandscapeRight:
                ret.size.width -= statusBarHeight;
                break;

            case UIInterfaceOrientationPortrait:
                ret.origin.y += statusBarHeight;
                ret.size.height -= statusBarHeight;
                break;

            case UIInterfaceOrientationPortraitUpsideDown:
                ret.size.height -= statusBarHeight;
                break;

            case 0:
                ret.origin.y += statusBarHeight;
                ret.size.height -= statusBarHeight;
                break;

            default:
                assert(0);
                break;
        }
    }

    return ret;
}

- (CADisplayLink*)displayLinkWithTarget:(NSObject*)target selector:(SEL)selector {
    id ret = [CADisplayLink displayLinkWithTarget:target selector:selector];

    return ret;
}

@end
