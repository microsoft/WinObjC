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
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKEffect.h>
#import <GLKit/GLKShader.h>

// See GLKVertexAttrib enum in GLKEffect.h for layout locations.
//
static const char* vertShader =
 "attribute vec4 " GLKSH_POS_NAME  ";\n"
 "attribute vec4 " GLKSH_COLOR_NAME ";\n"
 
 "varying vec4 _outcolor;\n"
 
 "uniform mat4 " GLKSH_MVP_NAME ";\n"
 
 "void main()\n"
 "{\n"
 "    _outcolor = _color;\n"
 "    gl_Position = _mvp * _position;\n"
 "}";

static const char* fragShader =
 "varying lowp vec4 _outcolor;\n"
 
 "void main()\n"
 "{\n"
 "    gl_FragColor = _outcolor;\n"
 "}";

@implementation GLKShaderCache {
    NSMutableDictionary* _shaders;
}

static GLKShaderCache* imp = nil;

+(instancetype) get {
    if (imp == nil) {
        imp = [[GLKShaderCache alloc] init];
    }
    return imp;
}

-(void)preloadShaders {
    GLKShaderSource* ss = [[GLKShaderSource alloc] initWithVS: vertShader PS: fragShader];
    if(ss) {
        [_shaders setObject: ss forKey: GLKSH_STANDARD_SHADER];
    }
}

-(GLKShader*)shaderForName: (NSString*)baseName effect: (GLKShaderEffect*)effect {
    GLKShaderSource* s = [_shaders objectForKey: baseName];
    if (s == nil) return nil;

    return [s shaderForEffect: effect];
}

-(id)init {
    _shaders = [[NSMutableDictionary alloc] init];
    [self preloadShaders];
    return self;
}

@end

@implementation GLKShaderSource {
    GLKShader* _shader;
}

-(id)initWithVS: (const char*)baseVSource PS: (const char*)basePSource {
    _vsh = glCreateShader(GL_VERTEX_SHADER);
    _psh = glCreateShader(GL_FRAGMENT_SHADER);

    GLint compileStatus = 0;
    
    const char* vsrces[] = { baseVSource };
    const int vlens[] = { strlen(baseVSource) };
    glShaderSource(_vsh, 1, vsrces, vlens);
    glCompileShader(_vsh);
    glGetShaderiv(_vsh, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_FALSE) {
        NSLog(@"WARNING: vertex shader compilation failed!");
    }

    const char* psrces[] = { basePSource };
    const int plens[] = { strlen(basePSource) };
    glShaderSource(_psh, 1, psrces, plens);
    glCompileShader(_psh);
    glGetShaderiv(_psh, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_FALSE) {
        NSLog(@"WARNING: pixel shader compilation failed!");
    }

    _program = glCreateProgram();
    glAttachShader(_program, _vsh);
    glAttachShader(_program, _psh);

    // Enforce common vertex format standard via attribute naming.
    glBindAttribLocation(_program, GLKVertexAttribPosition,  GLKSH_POS_NAME);
    glBindAttribLocation(_program, GLKVertexAttribNormal,    GLKSH_NORMAL_NAME);
    glBindAttribLocation(_program, GLKVertexAttribColor,     GLKSH_COLOR_NAME);
    glBindAttribLocation(_program, GLKVertexAttribTexCoord0, GLKSH_UV0_NAME);
    glBindAttribLocation(_program, GLKVertexAttribTexCoord1, GLKSH_UV1_NAME);

    glLinkProgram(_program);

    _shader = [[GLKShader alloc] initWith: self];
    return self;
}

-(GLKShader*)shaderForEffect: (GLKShaderEffect*)effect {
    return _shader;
}
@end

@implementation GLKShader {
    GLKShaderSource* _src;
}

-(id)initWith: (GLKShaderSource*)src {
    _src = src;

    GLuint p = self.program;
    
    GLint numAttrs = 0, numUniforms = 0;
    glGetProgramiv(p, GL_ACTIVE_ATTRIBUTES, &numAttrs);
    glGetProgramiv(p, GL_ACTIVE_UNIFORMS, &numUniforms);

    GLsizei len = 0;
    char buf[1024];
    GLint size;
    GLenum type;
    for(int i = 0; i < numAttrs; i ++) {
        glGetActiveAttrib(p, i, sizeof(buf), &len, &size, &type, buf);
        GLint loc = glGetAttribLocation(p, buf);
        NSLog(@"Shader attr: %d name: %s type: %d size: %d loc: %d", i, buf, type, size, loc);
    }
    for(int i = 0; i < numUniforms; i ++) {
        glGetActiveUniform(p, i, sizeof(buf), &len, &size, &type, buf);
        GLint loc = glGetUniformLocation(p, buf);
        if (strcmp(buf, GLKSH_MVP_NAME) == 0) {
            _mvploc = loc;
        } else {
            // TODO: BK: build uniform dictionary here.
            NSLog(@"Shader uniform: %d name: %s type: %d size: %d loc: %d", i, buf, type, size, loc); 
        }
    }
    
    return self;
}

-(GLuint)program    { return _src.program; }
-(GLuint)vsh        { return _src.vsh; }
-(GLuint)psh        { return _src.psh; }

@end

