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

#import "GLKitExampleController.h"
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#include <vector>
#include <algorithm>

static GLKVector4 FOG_COLOR = GLKVector4Make(0.f, 0.25f, 0.55f, 1.f);

static unsigned char heights[] = {
    145, 147, 142, 139, 177, 180, 184, 195, 134, 92, 100, 120, 135, 156, 145, 139, 125, 83, 91, 87, 65, 62, 62, 84, 121, 174, 190, 169, 157, 123, 134, 160,
    189, 194, 176, 150, 180, 200, 208, 212, 159, 135, 157, 147, 150, 173, 141, 128, 133, 79, 62, 69, 59, 54, 38, 60, 122, 166, 184, 179, 146, 114, 131, 137,
    224, 225, 186, 139, 161, 193, 194, 211, 195, 153, 139, 118, 139, 173, 138, 106, 107, 82, 80, 88, 85, 108, 89, 66, 120, 150, 160, 172, 128, 79, 75, 60,
    216, 228, 187, 166, 194, 198, 185, 190, 178, 125, 88, 85, 105, 147, 138, 88, 82, 102, 115, 112, 115, 154, 137, 100, 148, 176, 178, 167, 140, 112, 75, 43,
    188, 220, 199, 188, 199, 189, 175, 160, 145, 107, 86, 84, 78, 108, 101, 66, 92, 104, 84, 95, 124, 160, 145, 114, 159, 176, 165, 146, 141, 145, 96, 80,
    142, 166, 204, 216, 198, 191, 164, 129, 108, 65, 58, 42, 29, 79, 90, 69, 97, 102, 65, 83, 123, 150, 136, 123, 163, 192, 183, 172, 176, 162, 108, 99,
    133, 128, 188, 239, 215, 199, 154, 106, 82, 35, 41, 32, 36, 64, 64, 50, 64, 98, 93, 107, 133, 146, 133, 134, 169, 200, 189, 179, 175, 167, 134, 90,
    116, 149, 194, 196, 176, 173, 149, 122, 108, 83, 56, 50, 68, 69, 56, 56, 68, 107, 144, 158, 153, 135, 122, 140, 155, 174, 168, 153, 154, 155, 143, 91,
    121, 161, 162, 146, 159, 157, 148, 134, 119, 128, 82, 56, 68, 99, 119, 123, 134, 137, 161, 177, 161, 112, 94, 126, 120, 138, 141, 115, 124, 128, 131, 119,
    126, 140, 122, 124, 152, 139, 116, 149, 153, 152, 135, 90, 72, 126, 180, 176, 181, 179, 174, 171, 157, 108, 79, 96, 99, 105, 88, 87, 91, 84, 101, 136,
    116, 122, 104, 87, 96, 126, 133, 161, 147, 126, 126, 113, 116, 139, 170, 170, 179, 184, 161, 144, 148, 128, 114, 113, 118, 118, 93, 91, 61, 65, 114, 126,
    94, 109, 97, 85, 100, 145, 148, 131, 119, 100, 95, 106, 124, 123, 130, 145, 155, 150, 116, 122, 142, 139, 155, 152, 141, 119, 84, 71, 62, 77, 108, 103,
    90, 97, 76, 88, 115, 144, 113, 75, 86, 76, 79, 75, 66, 94, 136, 158, 157, 160, 142, 163, 180, 154, 159, 136, 101, 93, 84, 62, 73, 97, 108, 120,
    86, 55, 46, 89, 112, 117, 95, 73, 67, 63, 73, 34, 14, 67, 139, 174, 167, 167, 155, 164, 190, 200, 188, 123, 68, 77, 80, 53, 49, 76, 119, 130,
    65, 39, 71, 117, 118, 105, 108, 103, 71, 63, 70, 33, 36, 49, 86, 127, 115, 124, 128, 148, 209, 233, 195, 142, 105, 94, 63, 47, 60, 57, 93, 98,
    101, 99, 115, 124, 128, 133, 134, 114, 98, 85, 75, 54, 51, 46, 67, 114, 96, 97, 103, 133, 210, 236, 197, 149, 127, 109, 53, 51, 77, 74, 104, 91,
    114, 120, 113, 112, 136, 157, 144, 109, 119, 126, 123, 92, 64, 61, 91, 150, 127, 118, 122, 129, 190, 239, 214, 151, 135, 121, 60, 56, 67, 75, 114, 116,
    104, 109, 116, 118, 130, 156, 136, 102, 114, 146, 149, 104, 64, 52, 106, 161, 131, 123, 144, 138, 168, 202, 188, 159, 127, 114, 84, 60, 71, 99, 123, 146,
    126, 106, 119, 141, 145, 170, 156, 147, 169, 186, 150, 97, 56, 15, 66, 140, 139, 117, 132, 134, 156, 170, 158, 153, 104, 93, 88, 56, 78, 117, 126, 137,
    100, 57, 80, 120, 124, 145, 159, 183, 202, 210, 177, 123, 91, 36, 23, 75, 114, 108, 115, 136, 151, 152, 150, 123, 93, 119, 126, 96, 89, 102, 120, 138,
    83, 37, 80, 121, 117, 115, 114, 149, 159, 176, 174, 121, 89, 64, 33, 44, 97, 111, 125, 148, 134, 111, 114, 92, 98, 135, 137, 122, 102, 96, 116, 149,
    84, 63, 93, 116, 134, 124, 107, 115, 122, 158, 171, 128, 94, 59, 23, 50, 86, 103, 141, 161, 148, 127, 113, 107, 142, 162, 130, 119, 105, 109, 140, 152,
    101, 87, 79, 77, 118, 124, 120, 118, 125, 148, 142, 118, 103, 68, 37, 69, 75, 84, 137, 152, 129, 113, 98, 92, 132, 183, 155, 140, 141, 139, 164, 174,
    108, 94, 76, 76, 104, 102, 103, 128, 145, 145, 119, 108, 113, 74, 50, 75, 100, 133, 169, 147, 91, 73, 55, 76, 124, 167, 167, 158, 177, 166, 153, 158,
    103, 79, 47, 53, 65, 87, 122, 138, 134, 139, 123, 114, 120, 87, 81, 88, 120, 171, 180, 159, 123, 99, 61, 77, 112, 126, 145, 153, 179, 201, 194, 162,
    119, 81, 16, 22, 37, 72, 134, 134, 101, 99, 121, 119, 113, 116, 108, 127, 167, 196, 191, 173, 144, 114, 90, 98, 115, 117, 138, 168, 220, 250, 211, 159,
    128, 120, 55, 42, 50, 56, 87, 111, 109, 99, 146, 150, 137, 144, 109, 133, 169, 203, 217, 198, 172, 133, 123, 138, 146, 154, 188, 204, 249, 255, 229, 162,
    129, 119, 71, 57, 75, 65, 52, 86, 129, 143, 162, 161, 147, 138, 129, 143, 165, 181, 192, 191, 176, 146, 133, 137, 151, 182, 223, 215, 214, 255, 255, 191,
    125, 100, 65, 50, 62, 78, 79, 82, 109, 163, 180, 174, 154, 118, 115, 133, 162, 170, 185, 179, 154, 152, 156, 152, 180, 188, 187, 210, 213, 225, 221, 170,
    117, 89, 58, 46, 64, 84, 106, 98, 113, 175, 203, 212, 195, 149, 141, 159, 163, 167, 185, 146, 113, 125, 132, 143, 164, 159, 161, 202, 215, 199, 170, 165,
    107, 85, 69, 58, 79, 69, 71, 72, 100, 153, 171, 197, 191, 162, 175, 194, 167, 135, 127, 86, 73, 99, 116, 142, 153, 147, 177, 203, 179, 177, 162, 159,
    104, 99, 78, 55, 57, 66, 63, 45, 68, 123, 150, 170, 183, 183, 190, 176, 154, 132, 106, 74, 79, 101, 132, 165, 149, 141, 193, 201, 144, 141, 144, 133
};

struct Vertex {
    GLKVector3 pos;
    GLKVector3 norm;
};

static void buildGeometry(std::vector<Vertex>& verts, std::vector<unsigned short>& indices, float width, float length, float height,
                   unsigned char* heights, size_t mapWidth, size_t mapHeight)
{
    unsigned char minHeight = heights[0];
    unsigned char maxHeight = heights[0];
    for (int i = 1; i < mapWidth * mapHeight; i ++) {
        minHeight = std::min(minHeight, heights[i]);
        maxHeight = std::max(maxHeight, heights[i]);
    }

    float xSub = width / 2.f;
    float ySub = length / 2.f;
    float xMult = width / static_cast<float>(mapWidth - 1);
    float yMult = length / static_cast<float>(mapHeight - 1);

    float heightMult = height / static_cast<float>(maxHeight - minHeight);

    // 1 - set up position.
    for (int y = 0; y < mapHeight; y ++) {
        for (int x = 0; x < mapWidth; x ++) {
            Vertex v;
            v.pos.x = static_cast<float>(x) * xMult - xSub;
            v.pos.y = static_cast<float>(heights[y * mapWidth + x] - minHeight) * heightMult;
            v.pos.z = static_cast<float>(y) * yMult - ySub;
            v.norm = GLKVector3Make(0.f, 0.f, 0.f);
            
            verts.push_back(v);
        }        
    }

    // 2 - calculate normals.
    size_t prevIdx = 0;
    for (int y = 0; y < mapHeight; y ++) {
        for (int x = 0; x < mapWidth; x ++) {
            Vertex& v = verts[y * mapWidth + x];
            float curY = v.pos.y;

            float dx = 0.f;
            if (x > 0) {
                dx += (verts[y * mapWidth + (x - 1)].pos.y - curY);
            }
            if (x < mapWidth - 1) {
                dx += (curY - verts[y * mapWidth + (x + 1)].pos.y);
            }

            float dy = 0.f;
            if (y > 0) {
                dy += (verts[(y - 1) * mapWidth + x].pos.y - curY);
            }
            if (y < mapHeight - 1) {
                dy += (curY - verts[(y + 1) * mapWidth + x].pos.y);
            }

            v.norm = GLKVector3Normalize(GLKVector3Make(dx, 2.f, dy));
        }
    }
    
    // 3 - add faces.
    for (int y = 1; y < mapHeight; y ++) {
        for (int x = 1; x < mapWidth; x ++) {

            // Four corner indices.
            int a = ((y - 1) * mapWidth + (x - 1));
            int b = a + 1;
            int c = (y * mapWidth + (x - 1));
            int d = c + 1;

            // Add two faces.
            indices.push_back(d);
            indices.push_back(b);
            indices.push_back(a);
            indices.push_back(a);
            indices.push_back(c);
            indices.push_back(d);
        }
    }
}

@implementation GLKitExampleController {
    EAGLContext* _ctx;
    GLKView*_outputView;
    GLuint _vb, _ib;
    std::vector<Vertex> _verts;
    std::vector<unsigned short> _indices;
    GLKBaseEffect* _effect;
    float _rotation;
}

-(void)createGLData
{
    _verts.resize(0);
    _indices.resize(0);
    buildGeometry(_verts, _indices, 25.f, 25.f, 1.5f, heights, 32, 32);

    glGenBuffers(1, &_vb);
    glGenBuffers(1, &_ib);

    glBindBuffer(GL_ARRAY_BUFFER, _vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * _verts.size(), &_verts[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ib);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short) * _indices.size(), &_indices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    int err = glGetError();
    if (err) {
        NSLog(@"Error 0x%x creating mesh data!\n", err);
    }
    
    _effect = [[GLKBaseEffect alloc] init];
    _effect.lightingType = GLKLightingTypePerPixel;
    _effect.lightModelAmbientColor = GLKVector4Make(0.1f, 0.1f, 0.1f, 1.f);

    _effect.material.diffuseColor = GLKVector4Make(0.4f, 1.f, 0.7f, 1.f);
    _effect.material.specularColor = GLKVector4Make(0.25f, 0.25f, 0.075f, 1.f);
    _effect.material.shininess = 2.f;

    _effect.fog.enabled = TRUE;
    _effect.fog.mode = GLKFogModeLinear;
    _effect.fog.start = 1.f;
    _effect.fog.end = 17.f;
    _effect.fog.color = FOG_COLOR;
}

-(void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"GLKit";

    _ctx = [[EAGLContext alloc] initWithAPI: kEAGLRenderingAPIOpenGLES2];
    [EAGLContext setCurrentContext: _ctx];
    
    CGRect frame = CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height);
    _outputView = [[GLKView alloc] initWithFrame: frame];
    _outputView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    _outputView.context = _ctx;
    _outputView.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    _outputView.delegate = self;
    self.view = _outputView;

    [self createGLData];

    _rotation = 0.f;
}

-(void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear: animated];

    glClearColor(FOG_COLOR.x, FOG_COLOR.y, FOG_COLOR.z, FOG_COLOR.w);
    glClearDepthf(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

-(void)update 
{
}

-(void)glkView:(GLKView*)src drawInRect:(CGRect)rect
{
    glClearColor(FOG_COLOR.x, FOG_COLOR.y, FOG_COLOR.z, FOG_COLOR.w);
    glClearDepthf(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    float aspect = rect.size.width / rect.size.height;
    GLKMatrix4 proj = GLKMatrix4MakePerspective(M_PI / 3, aspect, 0.5f, 25.f);
    _effect.transform.projectionMatrix = proj;

    GLKMatrix4 lookAt = GLKMatrix4MakeLookAt(0.f, 5.f, -6.f, 0, 0, 0, 0, 1.f, 0);
    _effect.transform.modelviewMatrix = lookAt;
        
    _effect.light0.enabled = TRUE;
    _effect.light0.position = GLKVector4Make(3.f, 1.5f, -5.f, 1.f);
    _effect.light0.diffuseColor = GLKVector4Make(1.f, 0.8f, 0.35f, 1.f);
    _effect.light0.spotDirection = GLKVector3Make(0, 0, 1.f);
    _effect.light0.spotExponent = 10.f;
    _effect.light0.spotCutoff = 45.f;
    
    _effect.light1.enabled = TRUE;
    _effect.light1.position = GLKVector4Make(-3.f, 1.5f, -5.f, 1.f);
    _effect.light1.diffuseColor = GLKVector4Make(2.f, 0.3f, 0.1f, 1.f);
    _effect.light1.spotDirection = GLKVector3Make(0, 0, 1.f);
    _effect.light1.spotExponent = 10.f;
    _effect.light1.spotCutoff = 45.f;

    _effect.transform.modelviewMatrix = GLKMatrix4RotateY(lookAt, _rotation);;

    [_effect prepareToDraw];

    glBindBuffer(GL_ARRAY_BUFFER, _vb);

    glEnableVertexAttribArray(GLKVertexAttribPosition);
    glVertexAttribPointer(GLKVertexAttribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)offsetof(Vertex, pos));
    glEnableVertexAttribArray(GLKVertexAttribNormal);
    glVertexAttribPointer(GLKVertexAttribNormal, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)offsetof(Vertex, norm));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ib);

    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_SHORT, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);    

    _rotation += (1.f / 360.f) * M_PI;
}

@end
 
