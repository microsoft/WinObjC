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

#import "BezierViewController.h"

@interface WOCBezierPathView : UIView
@end

@implementation WOCBezierPathView
+(Class) layerClass {
    return [CAShapeLayer class];
}

-(CAShapeLayer *) shape {
    return (CAShapeLayer *) self.layer;
}
@end

@implementation BezierViewController
-(void) viewWillLayoutSubviews
{
    CGRect bounds = _bezierPath1.bounds;

    _bezierPath1.shape.path = [UIBezierPath bezierPathWithRoundedRect: CGRectInset(bounds, 10, 10) cornerRadius:10.0f].CGPath;
    _bezierPath1.shape.lineWidth = 10.0f;
    _bezierPath1.shape.fillColor = [UIColor blueColor].CGColor;
    _bezierPath1.shape.strokeColor = [UIColor grayColor].CGColor;
    
    CGPoint center = CGPointMake(bounds.size.width / 2, bounds.size.height / 2);
    CGFloat minDimension = center.x < center.y ? center.x : center.y;
    minDimension -= 5.0;
    _bezierPath2.shape.path = [UIBezierPath bezierPathWithArcCenter: center radius: minDimension startAngle: 0 endAngle: M_PI clockwise: NO].CGPath;
    _bezierPath2.shape.lineWidth = 5.0f;
    _bezierPath2.shape.fillColor = [UIColor blueColor].CGColor;
    _bezierPath2.shape.strokeColor = [UIColor grayColor].CGColor;
    
    _bezierPath3.shape.path = [UIBezierPath bezierPathWithOvalInRect: CGRectInset(bounds, 10, 10)].CGPath;
    _bezierPath3.shape.lineWidth = 10.0f;
    _bezierPath3.shape.fillColor = [UIColor blueColor].CGColor;
    _bezierPath3.shape.strokeColor = [UIColor grayColor].CGColor;
}
@end
