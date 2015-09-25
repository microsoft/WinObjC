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

#import <QuartzCore/QuartzCore.h>

#define REGISTER_STRING(name) CA_EXPORT NSString* const name = @ #name;

REGISTER_STRING(kCAGravityCenter)
REGISTER_STRING(kCAGravityTop)
REGISTER_STRING(kCAGravityBottom)
REGISTER_STRING(kCAGravityLeft)
REGISTER_STRING(kCAGravityRight)
REGISTER_STRING(kCAGravityTopLeft)
REGISTER_STRING(kCAGravityTopRight)
REGISTER_STRING(kCAGravityBottomLeft)
REGISTER_STRING(kCAGravityBottomRight)
REGISTER_STRING(kCAGravityResize)
REGISTER_STRING(kCAGravityResizeAspect)
REGISTER_STRING(kCAGravityResizeAspectFill)
REGISTER_STRING(kCAMediaTimingFunctionLinear)
REGISTER_STRING(kCAMediaTimingFunctionEaseInEaseOut)
REGISTER_STRING(kCATransactionAnimationDuration)
