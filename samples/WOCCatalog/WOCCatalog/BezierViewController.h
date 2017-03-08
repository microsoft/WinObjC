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

@class WOCBezierPathView;

@interface BezierViewController : UIViewController
@property (strong, nonatomic) IBOutlet WOCBezierPathView* bezierPath1;
@property (strong, nonatomic) IBOutlet WOCBezierPathView* bezierPath2;
@property (strong, nonatomic) IBOutlet WOCBezierPathView* bezierPath3;
@property (strong, nonatomic) IBOutletCollection(WOCBezierPathView) NSArray<WOCBezierPathView*>* endCapViews;
@property (strong, nonatomic) IBOutletCollection(WOCBezierPathView) NSArray<WOCBezierPathView*>* fillModeViews;
@end
