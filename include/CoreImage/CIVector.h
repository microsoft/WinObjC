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

#import <Foundation/NSObject.h>
#import <CoreGraphics/CoreGraphics.h>

@interface CIVector : NSObject {
    size_t _count;
    CGFloat* _values;
}

+ (CIVector*)vectorWithValues:(const CGFloat*)values count:(size_t)count;

+ (CIVector*)vectorWithX:(CGFloat)x;
+ (CIVector*)vectorWithX:(CGFloat)x Y:(CGFloat)y;
+ (CIVector*)vectorWithX:(CGFloat)x Y:(CGFloat)y Z:(CGFloat)z;
+ (CIVector*)vectorWithX:(CGFloat)x Y:(CGFloat)y Z:(CGFloat)z W:(CGFloat)w;

- initWithValues:(const CGFloat*)values count:(size_t)count;
- initWithX:(CGFloat)x;
- initWithX:(CGFloat)x Y:(CGFloat)y;
- initWithX:(CGFloat)x Y:(CGFloat)y Z:(CGFloat)z;
- initWithX:(CGFloat)x Y:(CGFloat)y Z:(CGFloat)z W:(CGFloat)w;

- (size_t)count;
- (CGFloat)valueAtIndex:(size_t)index;

- (CGFloat)X;
- (CGFloat)Y;
- (CGFloat)Z;
- (CGFloat)W;

@end
