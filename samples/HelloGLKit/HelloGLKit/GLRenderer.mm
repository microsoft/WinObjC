#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#import "GLRenderer.h"

@implementation GLRenderer

-(void)glkViewController: (GLKViewController*)controller willPause:(BOOL)paused {
    if(paused) {
        NSLog(@"GLRenderer got pause event from controller.");
    } else {
        NSLog(@"GLRenderer got unpause event from controller.");
    }
}

-(void)glkViewControllerUpdate: (GLKViewController*)controller {
    NSLog(@"GLRenderer got update event from controller.");
}

-(void)glkView:(GLKView*)view drawInRect:(CGRect)rect {
    NSLog(@"GLRenderer got render framer request.");

    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

@end
