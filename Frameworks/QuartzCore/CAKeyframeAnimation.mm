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

#include "Starboard.h"
#include "QuartzCore/CAKeyframeAnimation.h"

NSString* const kCAAnimationLinear = @"kCAAnimationLinear";
NSString* const kCAAnimationDiscrete = @"kCAAnimationDiscrete";
NSString* const kCAAnimationPaced = @"kCAAnimationPaced";
NSString* const kCAAnimationCubic = @"kCAAnimationCubic";
NSString* const kCAAnimationCubicPaced = @"kCAAnimationCubicPaced";
NSString* const kCAAnimationRotateAuto = @"kCAAnimationRotateAuto";
NSString* const kCAAnimationRotateAutoReverse = @"kCAAnimationRotateAutoReverse";

@implementation CAKeyframeAnimation
/**
 @Status Caveat
 @Notes Only position, bounds, and transform properties supported
*/
+ (instancetype)animationWithKeyPath:(NSString*)path {
    return [super animationWithKeyPath:path];
}
@end
