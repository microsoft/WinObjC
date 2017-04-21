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

@interface UIActivityIndicatorViewController : UIViewController <UIPickerViewDelegate, UIPickerViewDataSource>
@property (nonatomic) UIActivityIndicatorView* indicator;

@property (nonatomic) UIButton* animateIndicatorButton;

@property (nonatomic) UILabel* hideIndicatorLabel;
@property (nonatomic) UISwitch* hideStoppedIndicatorSwitch;

@property (nonatomic) UILabel* redLabel;
@property (nonatomic) UILabel* redValueLabel;
@property (nonatomic) UISlider* redSlider;

@property (nonatomic) UILabel* greenLabel;
@property (nonatomic) UILabel* greenValueLabel;
@property (nonatomic) UISlider* greenSlider;

@property (nonatomic) UILabel* blueLabel;
@property (nonatomic) UILabel* blueValueLabel;
@property (nonatomic) UISlider* blueSlider;

@property (nonatomic) UILabel* alphaLabel;
@property (nonatomic) UILabel* alphaValueLabel;
@property (nonatomic) UISlider* alphaSlider;

@property (nonatomic) UIPickerView* indicatorStylePicker;
@end
