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

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#import <Starboard.h>
#import <GLKit/GLKShader.h>

static const char vertexShader[] =
 "attribute vec4 _position;\n"
 "attribute vec4 _color;\n"
 "varying vec4 _outcolor;\n"
 "uniform mat4 _mvp;\n"
 "void main()\n"
 "{\n"
 "    _outcolor = _color;\n"
 "    gl_Position = _mvp * _position;\n"
 "}";

static const char fragShader[] =
 "varying lowp vec4 _outcolor;\n"
 "void main()\n"
 "{\n"
 "    gl_FragColor = _outcolor;\n"
 "}";

static NSString* standardShaderSrc = @"";

@implementation GLKShaderCache {
    NSMutableDictionary* _shaders;
}

static GLKShaderCache* imp = nil;

+(instancetype) get {
    if (imp == nil) {
        imp = [NSAllocateObject([GLKShaderCache class], 0, 0) init];
    }
    return imp;
}

+(instancetype) alloc {
    assert(!"Shader cache objects should not be allocated, but accessed through get instead.");
    return nil;
}

-(void)preloadShaders {
}

-(GLKShader*)shaderForName: (NSString*)baseName effect: (GLKShaderEffect*)effect {
    GLKShaderSource* s = [_shaders objectForKey: baseName];
    if (s == nil) return nil;


    return nil;    
}

-(id)init {
    _shaders = [[NSMutableDictionary alloc] init];
    [self preloadShaders];
    return self;
}

@end

@implementation GLKShaderSource {
    NSString* _vertSrc;
    NSString* _fragSrc;
}

-(id)initWithVS: (NSString*)baseVSource PS: (NSString*)basePSource {
    _vertSrc = baseVSource;
    _fragSrc = basePSource;

    return self;
}

@end

@implementation GLKShader {
}

-(id)init {
    _program = 0;
    return self;
}

@end

