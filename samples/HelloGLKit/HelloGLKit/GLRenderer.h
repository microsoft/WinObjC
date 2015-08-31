#pragma once

#import <GLKit/GLKit.h>

@interface GLRenderer : NSObject<GLKViewDelegate, GLKViewControllerDelegate>

-(void)glkViewController: (GLKViewController*)controller willPause:(BOOL)paused;
-(void)glkViewControllerUpdate: (GLKViewController*)controller;
-(void)glkView:(GLKView*)view drawInRect:(CGRect)rect;

@end

