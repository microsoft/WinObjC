//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

@interface CGDrawOptions : NSObject
- (id)initWithLineWidth:(CGFloat)lineWidth
              lineColor:(CGColorRef)lineColor
              fillColor:(CGColorRef)fillColor
        lineDashPattern:(CGFloat*)dashPattern
              linePhase:(CGFloat)linePhase
              dashCount:(size_t)dashCount;

@property (readonly) CGFloat lineWidth;
@property (readonly) CGColorRef lineColor;
@property (readonly) CGColorRef fillColor;
@property (readonly) CGFloat* lineDashPattern;
@property (readonly) CGFloat linePhase;
@property (readonly) size_t lineDashCount;
@end
