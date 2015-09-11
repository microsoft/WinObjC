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

@implementation GLKViewController {
    CADisplayLink *_link;
}

-(void) viewWillLayoutSubviews
{
    NSLog(@"GLKViewController got viewWillLayoutSubviews.");
}

-(void) viewDidLoad
{
    [super viewDidLoad];
    if ([self.view isKindOfClass: [GLKView class]]) {
        GLKView* kv = (GLKView*)self.view;
        kv.enableSetNeedsDisplay = FALSE;
    }
    NSLog(@"GLKViewController got viewDidLoad.");
    
    _link = [CADisplayLink displayLinkWithTarget: self selector: @selector(_renderFrame)];
}

-(void)viewWillAppear:(BOOL)animated
{
    NSLog(@"GLKViewController got viewWillAppear.");

    [super viewWillAppear: animated];
    [self.delegate glkViewController: self willPause: FALSE];

    [_link addToRunLoop: [NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];    
}

-(void)viewWillDisappear:(BOOL)animated
{
    NSLog(@"GLKViewController got viewWillDisappear.");

    [super viewWillDisappear: animated];
    [self.delegate glkViewController: self willPause: TRUE];

    [_link removeFromRunLoop: [NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}

-(BOOL)_renderFrame {
    id dest = self;
    if (self.delegate != nil) dest = self.delegate;

    if ([dest respondsToSelector: @selector(glkViewControllerUpdate:)]) {
        [dest glkViewControllerUpdate: self];
    } else if ([dest respondsToSelector: @selector(update)]) {
        [dest update];
    }

    bool tryDirectRender = true;
    if([self.view respondsToSelector: @selector(_renderFrame)]) {
        if ([self.view _renderFrame]) tryDirectRender = false;
    }

    if (tryDirectRender) {
        if ([dest respondsToSelector: @selector(glkView:drawInRect:)]) {
            [dest glkView: self.view drawInRect: self.view.frame];
        }
    }

    return TRUE;
}

@end

