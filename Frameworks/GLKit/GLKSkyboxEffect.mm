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

#import <Starboard.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKEffect.h>
#import <GLKit/GLKShader.h>
#import <GLKit/GLKTexture.h>
#import <GLKit/GLKSkyboxEffect.h>
#import "ShaderInfo.h"

#define NM 0.5773502691896258f // 1 / sqrtf(3)

struct SkyboxVert {
    GLKVector3 pos;
    GLKVector3 norm;
};

const std::string skyboxTexName = "_tex0";

const char* vsSrc =
    "uniform mat4 _mvp;\n"
    "attribute vec4 _position;\n"
    "attribute vec3 _normal;\n"
    "varying vec3 _lookup;\n"
    "\n"
    "void main() {\n"
    "    gl_Position = _mvp * _position;\n"
    "    _lookup = _normal;\n"
    "}\n\n";

const char* psSrc =
    "uniform samplerCube _tex0;\n"
    "varying mediump vec3 _lookup;\n"
    "\n"
    "void main() {\n"
    "    gl_FragColor = textureCube(_tex0, _lookup);\n"
    "}\n\n";

@implementation GLKSkyboxEffect {
    BOOL _inited;
    BOOL _shaderInited;
    GLuint _vb, _ib;
}

- (id)init {
    [super init];
    _textureCubeMap = [[GLKEffectPropertyTexture alloc] initWith:self];
    _inited = FALSE;
    _shaderInited = FALSE;
    self.shaderName = @"StandardSkybox";
    return self;
}

- (void)dealloc {
    if (_inited) {
        glDeleteBuffers(1, &_vb);
        glDeleteBuffers(1, &_ib);
    }
    [super dealloc];
}

- (BOOL)updateShaderMaterialParams {
    [super updateShaderMaterialParams];

    ShaderMaterial* mat = (ShaderMaterial*)self.shaderMat;
    mat->addTexCube(skyboxTexName, _textureCubeMap.name);

    return TRUE;
}

- (void)prepareToDraw {
    if (!_inited) {
        _inited = TRUE;

        glGenBuffers(1, &_vb);
        glGenBuffers(1, &_ib);

        static SkyboxVert skyboxVerts[] = {
            { { -1.0f, -1.0f, -1.0f }, { -NM, -NM, -NM } }, { { 1.0f, -1.0f, -1.0f }, { NM, -NM, -NM } },
            { { 1.0f, 1.0f, -1.0f }, { NM, NM, -NM } },     { { -1.0f, 1.0f, -1.0f }, { -NM, NM, -NM } },
            { { -1.0f, -1.0f, 1.0f }, { -NM, -NM, NM } },   { { 1.0f, -1.0f, 1.0f }, { NM, -NM, NM } },
            { { 1.0f, 1.0f, 1.0f }, { NM, NM, NM } },       { { -1.0f, 1.0f, 1.0f }, { -NM, NM, NM } }
        };

        static short int faces[] = { 5, 4, 0, 1, 5, 0, 6, 5, 1, 2, 6, 1, 7, 6, 2, 3, 7, 2,
                                     4, 7, 3, 0, 4, 3, 6, 7, 4, 5, 6, 4, 1, 0, 3, 2, 1, 3 };

        glBindBuffer(GL_ARRAY_BUFFER, _vb);
        glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVerts), skyboxVerts, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ib);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faces), faces, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        GLKShaderPair* src = [[GLKShaderPair alloc] init];
        src.vertexShader = [NSString stringWithCString:vsSrc];
        src.pixelShader = [NSString stringWithCString:psSrc];

        [[GLKShaderCache get] addShaderNamed:self.shaderName source:src];
    }

    [super prepareToDraw]; // will call updateShaderMaterialParams.
}

- (void)draw {
    bool depthTest = glIsEnabled(GL_DEPTH_TEST);
    if (depthTest) {
        glDisable(GL_DEPTH_TEST);
    }

    glBindBuffer(GL_ARRAY_BUFFER, _vb);
    glEnableVertexAttribArray(GLKVertexAttribPosition);
    glVertexAttribPointer(GLKVertexAttribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(SkyboxVert), 0);
    glEnableVertexAttribArray(GLKVertexAttribNormal);
    glVertexAttribPointer(
        GLKVertexAttribNormal, 3, GL_FLOAT, GL_FALSE, sizeof(SkyboxVert), (const GLvoid*)(3 * sizeof(float)));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ib);

    glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_SHORT, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    if (depthTest) {
        glEnable(GL_DEPTH_TEST);
    }
}

@end
