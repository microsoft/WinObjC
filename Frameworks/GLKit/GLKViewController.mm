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
#import <GLKit/GLKViewController.h>

// TODO: BK: when to call glkViewControllerUpdate on delegate?

@implementation GLKViewController {
    CADisplayLink *_displayLink;
}

-(void) viewWillLayoutSubviews
{
    NSLog(@"GLKViewController got viewWillLayoutSubviews.");
}

-(void) viewDidLoad
{
    [super viewDidLoad];
    NSLog(@"GLKViewController got viewDidLoad.");
    
    _displayLink = [CADisplayLink displayLinkWithTarget: self selector: @selector(render)];
}

-(void)viewWillAppear:(BOOL)animated
{
    NSLog(@"GLKViewController got viewWillAppear.");
    
    [super viewWillAppear: animated];
    [self.delegate glkViewController: self willPause: FALSE];
}

-(void)viewWillDisappear:(BOOL)animated
{
    NSLog(@"GLKViewController got viewWillDisappear.");
    
    [super viewWillDisappear: animated];
    [self.delegate glkViewController: self willPause: TRUE];
}

-(void)render
{
    NSLog(@"GLKViewController got render.");
    [self.view setNeedsDisplay];
}

@end

