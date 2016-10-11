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
#pragma once

#import <QuartzCore/CoreAnimationExport.h>
#import <ApplicationServices/ApplicationServices.h>
#import <Foundation/NSObject.h>

@class CALayer;

@interface CARenderer : NSObject {
    void* _cglContext;
    CGRect _bounds;
    CALayer* _rootLayer;
}

@property (retain) CALayer* layer STUB_PROPERTY;
@property (assign) CGRect bounds STUB_PROPERTY;

+ (CARenderer*)rendererWithCGLContext:(void*)cglContext options:(NSDictionary*)options STUB_METHOD;

- (void)beginFrameAtTime:(CFTimeInterval)currentTime timeStamp:(struct CVTimeStamp*)timeStamp STUB_METHOD;
- (CGRect)updateBounds STUB_METHOD;
- (void)addUpdateRect:(CGRect)aRect STUB_METHOD;
- (void)render STUB_METHOD;
- (CFTimeInterval)nextFrameTime STUB_METHOD;
- (void)endFrame STUB_METHOD;
@end
