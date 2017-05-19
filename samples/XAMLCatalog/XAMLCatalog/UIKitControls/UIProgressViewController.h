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

@interface UIProgressViewController : UIViewController

@property (nonatomic) UIProgressView* progressView;
@property (nonatomic) NSProgress* progress;

@property (nonatomic) UIButton* pauseButton;
@property (nonatomic) UIButton* startButton;

@property (nonatomic) UITextField* progressValue;
@property (nonatomic) UIButton* setProgressButton;

@property (nonatomic) UIButton* fillSelectButton;
@property (nonatomic) UIButton* trackSelectButton;

@property (nonatomic) UIButton* styleSelectButton;

@property (nonatomic) UITextField* redFillComponent;
@property (nonatomic) UITextField* greenFillComponent;
@property (nonatomic) UITextField* blueFillComponent;
@property (nonatomic) UITextField* alphaFillComponent;
@property (nonatomic) UIButton* setFillTintButton;

@property (nonatomic) UITextField* redTrackComponent;
@property (nonatomic) UITextField* greenTrackComponent;
@property (nonatomic) UITextField* blueTrackComponent;
@property (nonatomic) UITextField* alphaTrackComponent;
@property (nonatomic) UIButton* setTrackTintButton;

@end
