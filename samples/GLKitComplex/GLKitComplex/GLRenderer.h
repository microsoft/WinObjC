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

#import <GLKit/GLKit.h>

enum _DisplayMode {
    DM_LitSolidColor,
    DM_PixSolidColor,
    DM_ReflSpecular,
    DM_LitTextured,
    DM_PixelLitTextured,
    DM_VertexColor,
    DM_SolidColor,
    DM_TexturedVertexColor,
    DM_TexturedSolidColor,
    DM_Last = DM_TexturedSolidColor
};
typedef unsigned int DisplayMode;

@interface GLRenderer : NSObject<GLKViewDelegate, GLKViewControllerDelegate>

@property(readonly) DisplayMode mode;

-(void)initGLData;
-(void)cleanupGLData;

-(void)nextDisplayMode;

-(void)glkViewController: (GLKViewController*)controller willPause:(BOOL)paused;
-(void)glkViewControllerUpdate: (GLKViewController*)controller;
-(void)glkView:(GLKView*)view drawInRect:(CGRect)rect;

@end

