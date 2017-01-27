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

#import "MenuTableViewController.h"
#import "TestEnabledUITextField.h"

@interface UIButtonWithControlsViewController : UIViewController

@property (nonatomic, readonly) UIButton* button;

@property (nonatomic, readonly) UISlider* sliderTitleColorNormal;

@property (nonatomic, readonly) UISwitch* switchEnabled;

@property (nonatomic, readonly) TestEnabledUITextField* textTitleNormal;
@property (nonatomic, readonly) TestEnabledUITextField* textTitleHighlighted;
@property (nonatomic, readonly) TestEnabledUITextField* textTitleDisabled;

@property (nonatomic, readonly) UIColor* titleColorNormal;
@property (nonatomic, readonly) UIColor* titleColorHighlighted;
@property (nonatomic, readonly) UIColor* titleColorDisabled;

@end
