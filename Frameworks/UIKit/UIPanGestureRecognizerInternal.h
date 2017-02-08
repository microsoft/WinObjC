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

#pragma once
#import <vector>

// So we can allocate explicitly because otherwise constructors aren't called:
struct TouchInfo {
    UITouch* touch;
    CGPoint startPos, lastPos;
    double startTime;
};

struct Private {
    std::vector<TouchInfo> touches;
    CGPoint currentVelocity;
    CGPoint lastCenter;
    CGPoint currentTranslation;
};

@interface UIPanGestureRecognizer ()
- (const std::vector<TouchInfo>&)_getTouches;
- (UIView*)_touchedView;
- (void)_setDragSlack:(float)slack;
- (float)_getDragSlack;
@end
