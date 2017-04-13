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

#import <Starboard.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKView.h>
#import <GLKit/GLKViewController.h>
#import <chrono>

#import "CALayerInternal.h"
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.Foundation.h>
#import <winrt/Windows.Globalization.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::Globalization;
namespace WF = winrt::Windows::Foundation;

static NSTimeInterval timeSpanToInterval(const WF::TimeSpan& timeSpan) {
    // NSTimeInterval is in seconds
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(timeSpan);
    return millis.count() / 1000.0;
}

@protocol _GLKViewControllerInformal <NSObject>
- (BOOL)_renderFrame;
@end

@implementation GLKViewController {
    CADisplayLink* _link;
    WF::DateTime _firstStart;
    WF::DateTime _lastStart;
    WF::DateTime _lastFrame;
    TrivialDefaultConstructor<Calendar> _calendar;
    BOOL _isGlkView;
}

/**
 @Status Interoperable
 @Public No
*/
- (void)viewDidLoad {
    [super viewDidLoad];
    if ([self.view isKindOfClass:[GLKView class]]) {
        _isGlkView = YES;
        GLKView* kv = (GLKView*)self.view;
        kv.enableSetNeedsDisplay = FALSE;
    }

    _link = [CADisplayLink displayLinkWithTarget:self selector:@selector(_renderFrame)];
    [_link retain];

    _calendar = Calendar();
    _calendar.SetToNow();
    _firstStart = _lastFrame = _calendar.GetDateTime();
}

- (void)dealloc {
    [_link release];
    [super dealloc];
}

/**
 @Status Interoperable
 @Public No
*/
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self.delegate glkViewController:self willPause:FALSE];

    [_link addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];

    _calendar.SetToNow();
    _lastStart = _calendar.GetDateTime();
}

/**
 @Status Interoperable
 @Public No
*/
- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [self.delegate glkViewController:self willPause:TRUE];

    [_link removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}

- (BOOL)_renderFrame {
    _calendar.SetToNow();
    WF::DateTime frameTime = _calendar.GetDateTime();

    _timeSinceFirstResume = timeSpanToInterval(frameTime - _firstStart);
    _timeSinceLastResume = timeSpanToInterval(frameTime - _lastStart);
    _timeSinceLastUpdate = timeSpanToInterval(frameTime - _lastFrame);
    _timeSinceLastDraw = _timeSinceLastUpdate;

    _lastFrame = frameTime;

    id dest = self;
    if (self.delegate != nil) {
        dest = self.delegate;
    }

    // TODO: The view/view controller logic here is probably quite wrong.

    if ([dest respondsToSelector:@selector(glkViewControllerUpdate:)]) {
        [dest glkViewControllerUpdate:self];
    } else if ([dest respondsToSelector:@selector(update)]) {
        [dest update];
    }

    bool tryDirectRender = true;
    if ([self.view respondsToSelector:@selector(_renderFrame)]) {
        if ([(id<_GLKViewControllerInformal>)self.view _renderFrame]) {
            tryDirectRender = false;
        }
    }

    if (tryDirectRender) {
        if (_isGlkView && [dest respondsToSelector:@selector(glkView:drawInRect:)]) {
            GLKView* view = static_cast<GLKView*>(self.view);
            CAEAGLLayer* layer = static_cast<CAEAGLLayer*>(view.layer);
            [dest glkView:view drawInRect:CGRectMake(0, 0, [layer _pixelWidth], [layer _pixelHeight])];
        }
    }

    _framesDisplayed++;

    return TRUE;
}

// TODO: implement me!

/**
 @Status Stub
*/
- (NSInteger)framesPerSecond {
    UNIMPLEMENTED();
    return 30;
}

/**
 @Status Stub
 @Notes
*/
- (void)glkView:(GLKView*)view drawInRect:(CGRect)rect {
    UNIMPLEMENTED();
}

@end
