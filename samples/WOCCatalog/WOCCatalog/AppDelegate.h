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

#import <UIKit/UIKit.h>
#import "WindowLevelControlViewController.h"
#import "BlankWindowViewController.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow* window;
@property (strong, nonatomic) UIWindow* levelControlWindow;
@property (strong, nonatomic) UIWindow* redColorWindow;
@property (strong, nonatomic) UIWindow* yellowColorWindow;
@property (strong, nonatomic) UIWindow* blueColorWindow;

@property (strong, nonatomic) UIViewController* viewController;
@property (strong, nonatomic) WindowLevelControlViewController* levelControlVC;
@property (strong, nonatomic) BlankWindowViewController* redVC;
@property (strong, nonatomic) BlankWindowViewController* yellowVC;
@property (strong, nonatomic) BlankWindowViewController* blueVC;

@end

