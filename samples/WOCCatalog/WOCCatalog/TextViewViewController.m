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

#import "TextViewViewController.h"

@implementation TextViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.textView = [[UITextView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    self.textView.textColor = [UIColor blackColor];
    UIFontDescriptor* des = [UIFontDescriptor fontDescriptorWithName:@"Calibri" size:18.0];
    des = [des fontDescriptorWithSymbolicTraits:(UIFontDescriptorTraitBold | UIFontDescriptorTraitItalic)];
    self.textView.font = [UIFont fontWithDescriptor:des size:20.0];
    self.textView.backgroundColor = [UIColor whiteColor];

    self.textView.text = @"Lorem ipsum dolor sit amet lorem a ut massa quam tempus maecenas. Eu consequat ipsum magnis quisque. Etiam "
                         @"luctus dictum natoque ullamcorper dolor quam quisque metus. Dui imperdiet eget ante tellus. Nullam sem aenean. "
                         @"Pede donec lorem ultricies eleifend imperdiet integer phasellus blandit dictum nulla eget. Nulla fringilla sit "
                         @"pulvinar eu vel semper orci. Vel lorem ante ut. Eleifend vulputate rhoncus. Ultricies dolor venenatis amet sit "
                         @"aenean ante magnis imperdiet rhoncus tellus elementum. Etiam amet ante enim. Tellus adipiscing consequat. "
                         @"Dolor justo adipiscing nisi amet. Adipiscing aliquam eleifend lorem ante fringilla integer elementum quis "
                         @"felis libero pretium justo. Veni tellus id. Etiam quam vitae leo aenean et vivamus rhoncus nec. Nulla "
                         @"adipiscing parturient sit porttitor et nec quam ultricies integer nullam. Lorem dui eu vitae ultricies tellus "
                         @"eget quis felis dolor tincidunt aenean semper. Vitae quis dolor natoque eleifend justo phasellus mollis "
                         @"pulvinar venenatis ac pede sem pellentesque. Eget commodo nam quam sem ipsum vici ligula ante.";

    self.textView.returnKeyType = UIReturnKeyDefault;
    self.textView.keyboardType = UIKeyboardTypeDefault;
    self.textView.scrollEnabled = YES;
    self.textView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    [self.view addSubview:self.textView];
}

@end
