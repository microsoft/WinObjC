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

#import <QuartzCore/CARenderer.h>
#import "StubReturn.h"

@implementation CARenderer
/**
 @Status Stub
*/
+ (CARenderer*)rendererWithCGLContext:(void*)cglContext options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)beginFrameAtTime:(CFTimeInterval)currentTime timeStamp:(CVTimeStamp*)timeStamp {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (CGRect)updateBounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)addUpdateRect:(CGRect)aRect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)render {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (CFTimeInterval)nextFrameTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)endFrame {
    UNIMPLEMENTED();
}

@end
