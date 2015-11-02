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
#import <QuartzCore/CABase.h>

CA_EXPORT NSString* const kCAMediaTimingFunctionLinear;
CA_EXPORT NSString* const kCAMediaTimingFunctionEaseIn;
CA_EXPORT NSString* const kCAMediaTimingFunctionEaseOut;
CA_EXPORT NSString* const kCAMediaTimingFunctionEaseInEaseOut;
CA_EXPORT NSString* const kCAMediaTimingFunctionDefault;

CA_EXPORT_CLASS
@interface CAMediaTimingFunction : NSObject {
@public
    float _c1x;
    float _c1y;
    float _c2x;
    float _c2y;
}

- initWithControlPoints:(float)c1x _:(float)c1y _:(float)c2x _:(float)c2y;

+ functionWithControlPoints:(float)c1x _:(float)c1y _:(float)c2x _:(float)c2y;
+ functionWithControlPoints:(float)c1x:(float)c1y:(float)c2x:(float)c2y;

+ functionWithName:(NSString*)name;

- (void)getControlPointAtIndex:(size_t)index values:(float[2])ptr;

@end
