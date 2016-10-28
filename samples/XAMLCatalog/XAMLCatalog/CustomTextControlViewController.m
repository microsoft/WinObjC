//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "CustomTextControlViewController.h"

#import <UIKit/UIKit.h>

// WinRT Projections imports
#ifdef WINOBJC

#endif // WINOBJC

@interface SpiralTextEdit : UIView

@end

#ifdef WINOBJC

#else // WINOBJC
@implementation SpiralTextEdit

- (void)_commonInit {
    UILabel* infoLabel = [[UILabel alloc] initWithFrame:self.bounds];
    
    infoLabel.text = @"Build this sample using the Islandwood SDK";
    infoLabel.numberOfLines = 0;
    infoLabel.textAlignment = NSTextAlignmentCenter;
    
    [self addSubview:infoLabel];
    
    self.backgroundColor = [UIColor grayColor];
}

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _commonInit];
    }
    
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    if (self = [super initWithCoder:aDecoder]) {
        [self _commonInit];
    }
    
    return self;
}

@end
#endif // WINOBJC

@implementation CustomTextControlViewController {
    BOOL _fromCoder;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    if (self = [super initWithCoder:aDecoder]) {
        _fromCoder = YES;
    }
    
    return self;
}

- (void)viewDidLoad {
    self.view.backgroundColor = [UIColor whiteColor];
    
    if (!_fromCoder) {
        CGRect centeredEditRect = CGRectMake(self.view.bounds.size.width / 2 - 200 / 2, 200, 200, 200);
        CGRect centeredInfoRect = CGRectMake(self.view.bounds.size.width / 2 - 300 / 2, 100, 300, 100);
        
        SpiralTextEdit* textEdit = [[SpiralTextEdit alloc] initWithFrame:centeredEditRect];
        UILabel* infoLabel = [[UILabel alloc] initWithFrame:centeredInfoRect];
        
        textEdit.autoresizingMask = infoLabel.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin;
        
        infoLabel.text = @"Click the control to gain focus. Use the keyboard to type and caret nagivate. Hold shift to update the selection. Right click or Ctrl+C or V to copy and paste.";
        infoLabel.numberOfLines = 0;
        infoLabel.textAlignment = NSTextAlignmentCenter;
        
        UIButton* focusButton = [UIButton buttonWithType:UIButtonTypeSystem];
        
        focusButton.frame = CGRectMake(self.view.bounds.size.width / 2 - 100 / 2, 450, 100, 50);
        [focusButton setTitle:@"Tab To Focus" forState:UIControlStateNormal];
        
        [self.view addSubview:focusButton];
        [self.view addSubview:textEdit];
        [self.view addSubview:infoLabel];
    }
}

@end