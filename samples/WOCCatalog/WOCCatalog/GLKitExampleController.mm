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

struct Vertex {
    Vertex() {}
    Vertex(GLKVector3 pos, GLKVector3 norm) : pos(pos), norm(norm) {}
    
    GLKVector3 pos;
    GLKVector3 norm;
};

namespace {

GLKVector4 FOG_COLOR = GLKVector4Make(0.f, 0.25f, 0.55f, 1.f);

// Input heights for the heightfield mesh.  Generated via a noise function.
unsigned char heights[] = {
    145, 147, 142, 139, 177, 180, 184, 195, 134, 92, 100, 120, 135, 156, 145, 139,
    189, 194, 176, 150, 180, 200, 208, 212, 159, 135, 157, 147, 150, 173, 141, 128,
    224, 225, 186, 139, 161, 193, 194, 211, 195, 153, 139, 118, 139, 173, 138, 106,
    216, 228, 187, 166, 194, 198, 185, 190, 178, 125, 88, 85, 105, 147, 138, 88,
    188, 220, 199, 188, 199, 189, 175, 160, 145, 107, 86, 84, 78, 108, 101, 66,
    142, 166, 204, 216, 198, 191, 164, 129, 108, 65, 58, 42, 29, 79, 90, 69,
    133, 128, 188, 239, 215, 199, 154, 106, 82, 35, 41, 32, 36, 64, 64, 50,
    116, 149, 194, 196, 176, 173, 149, 122, 108, 83, 56, 50, 68, 69, 56, 56,
    121, 161, 162, 146, 159, 157, 148, 134, 119, 128, 82, 56, 68, 99, 119, 123,
    126, 140, 122, 124, 152, 139, 116, 149, 153, 152, 135, 90, 72, 126, 180, 176,
    116, 122, 104, 87, 96, 126, 133, 161, 147, 126, 126, 113, 116, 139, 170, 170,
    94, 109, 97, 85, 100, 145, 148, 131, 119, 100, 95, 106, 124, 123, 130, 145,
    90, 97, 76, 88, 115, 144, 113, 75, 86, 76, 79, 75, 66, 94, 136, 158,
    86, 55, 46, 89, 112, 117, 95, 73, 67, 63, 73, 34, 14, 67, 139, 174,
    65, 39, 71, 117, 118, 105, 108, 103, 71, 63, 70, 33, 36, 49, 86, 127,
    101, 99, 115, 124, 128, 133, 134, 114, 98, 85, 75, 54, 51, 46, 67, 114
};

// Create a single, round arch with the specified dimensions.
void buildArch(std::vector<Vertex>& verts, std::vector<unsigned short>& indices,
               const GLKVector3& center, const GLKVector3& fwd, const GLKVector3& left,
               float length, float thickness, float width, size_t numFacets)
{
    GLKVector3 widthSub = GLKVector3MultiplyScalar(left, 0.5f * width);
    GLKVector3 widthAdd = GLKVector3MultiplyScalar(left, -0.5f * width);
    GLKVector3 invLeft = GLKVector3Negate(left);
    
    size_t lastFacetIdx = verts.size();
    for (size_t i = 0; i < numFacets; i ++) {
        size_t curFacetIdx = verts.size();

        // Calculate some common factors.
        const float mult = M_PI / (numFacets - 1);
        const float start = -0.5f * M_PI;
        
        const float ang = start + static_cast<float>(i) * mult;
        const float ybase = cosf(ang);
        const float zbase = sinf(ang);

        GLKVector3 norm = GLKVector3Add(GLKVector3MultiplyScalar(fwd, zbase), GLKVector3Make(0, ybase, 0));
        GLKVector3 invNorm = GLKVector3Negate(norm);

        const float hl = 0.5f * length;        
        GLKVector3 far = GLKVector3MultiplyScalar(norm, hl);
        GLKVector3 near = GLKVector3MultiplyScalar(norm, hl - thickness);

        // Calculate some needed positions.
        GLKVector3 centerLeft = GLKVector3Add(center, widthSub);
        GLKVector3 centerRight = GLKVector3Add(center, widthAdd);

        GLKVector3 farLeft = GLKVector3Add(centerLeft, far);
        GLKVector3 nearLeft = GLKVector3Add(centerLeft, near);
        GLKVector3 farRight = GLKVector3Add(centerRight, far);
        GLKVector3 nearRight = GLKVector3Add(centerRight, near);

        // Add the vertices for this position.
        verts.push_back(Vertex(farLeft, norm));
        verts.push_back(Vertex(farRight, norm));
        verts.push_back(Vertex(farRight, invLeft));
        verts.push_back(Vertex(nearRight, invLeft));
        verts.push_back(Vertex(nearRight, invNorm));
        verts.push_back(Vertex(nearLeft, invNorm));
        verts.push_back(Vertex(nearLeft, left));
        verts.push_back(Vertex(farLeft, left));
        
        // Add faces.
        if (curFacetIdx > lastFacetIdx) {

            const size_t VERTS_PER_FACET = 8;
            for (size_t f = 0; f < VERTS_PER_FACET; f += 2) {
                
                size_t lb = lastFacetIdx + f;
                size_t nb = curFacetIdx + f;
                
                indices.push_back(lb);
                indices.push_back(lb + 1);
                indices.push_back(nb + 1);

                indices.push_back(lb);
                indices.push_back(nb + 1);
                indices.push_back(nb);
            }
        }
        
        lastFacetIdx = curFacetIdx;
    }
}

// Build two crossing arches with the specified dimensions along 45 degree diagonals on the XZ plane.
void buildDualArch(std::vector<Vertex>& verts, std::vector<unsigned short>& indices, const GLKVector3& center,
                   float size, float thickness, float width, size_t facets)
{
    GLKVector3 f1 = GLKVector3Normalize(GLKVector3Make(1.f, 0.f, 1.f));
    GLKVector3 f2 = GLKVector3Normalize(GLKVector3Make(1.f, 0.f, -1.f));
    GLKVector3 f3 = GLKVector3Normalize(GLKVector3Make(-1.f, 0.f, -1.f));
    
    buildArch(verts, indices, center, f1, f2, size, thickness, width, facets);
    buildArch(verts, indices, center, f2, f3, size, thickness, width, facets);
}

// Build a multilayer arch with the given number of layers.  The top layer will have a single arch, the second
// 2x2 aches, the third 3x3, and so on.  Arrange arches such that the bottoms connect to the top of the next layer down.
void buildMultiArch(std::vector<Vertex>& verts, std::vector<unsigned short>& indices,
                    const GLKVector3& center, size_t numLayers, float archLength, float archThickness,
                    float archWidth, size_t archFacets)
{
    if (numLayers == 1) {
        buildDualArch(verts, indices, center, archLength, archThickness, archWidth, archFacets);
    } else if (numLayers > 1) {
        float archXZLength = sqrtf(0.5f * archLength * archLength);
        
        const size_t numArches = numLayers;
        float innerLength = (numArches - 1) * archXZLength;
        
        buildMultiArch(verts, indices, GLKVector3Add(center, GLKVector3Make(0.f, 0.5f * archLength, 0.f)),
                       numLayers - 1, archLength, archThickness, archWidth, archFacets);

        float firstX = center.x - 0.5f * innerLength;
        float firstZ = center.z - 0.5f * innerLength;
        
        for (size_t i = 0; i < numArches; i ++) {
            for (size_t j = 0; j < numArches; j ++) {
                GLKVector3 curCenter = GLKVector3Make(firstX + i * archXZLength, center.y, firstZ + j * archXZLength);
                buildDualArch(verts, indices, curCenter, archLength, archThickness, archWidth, archFacets);
            }
        }
    }
}

// Create a heightfield vertex buffer given a list of input heights.  Scales, calculates normals, etc.
void buildGeometry(std::vector<Vertex>& verts, std::vector<unsigned short>& indices, float width, float length, float height,
                   unsigned char* heights, size_t mapWidth, size_t mapHeight)
{
    if (mapWidth < 2 || mapHeight < 2) {
        NSLog(@"Invalid height field parameters!");
        return;
    }
    
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

            v.norm = GLKVector3Normalize(GLKVector3Make(dx, 1.f, dy)); // normally y is 2.f, it's reduced here to exaggerate lighting.
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

}

@implementation GLKitExampleController {
    EAGLContext* _ctx;
    GLKView*_outputView;
    GLuint _vb, _ib;
    std::vector<Vertex> _verts;
    std::vector<unsigned short> _indices;
    size_t _archStart;
    GLKBaseEffect* _effect;
    float _rotation;
}

-(void)createGLData
{
    _verts.resize(0);
    _indices.resize(0);
    buildGeometry(_verts, _indices, 17.f, 17.f, 1.f, heights, 16, 16);
    _archStart = _indices.size();
    buildMultiArch(_verts, _indices, GLKVector3Make(0.f, 0.f, 0.f), 4, 4.f, 0.25f, 0.25f, 8);

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

    _effect.fog.enabled = TRUE;
    _effect.fog.mode = GLKFogModeLinear;
    _effect.fog.start = 1.f;
    _effect.fog.end = 25.f;
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

    GLKMatrix4 lookAt = GLKMatrix4MakeLookAt(0.f, 7.f, -11.f, 0, 0, 0, 0, 1.f, 0);
    _effect.transform.modelviewMatrix = lookAt;
        
    _effect.light0.enabled = TRUE;
    _effect.light0.position = GLKVector4Make(-4.5f, 9.5f, -7.f, 1.f);
    _effect.light0.diffuseColor = GLKVector4Make(0.9f, 0.9f, 1.f, 1.f);
    
    _effect.transform.modelviewMatrix = GLKMatrix4RotateY(lookAt, _rotation);;

    _effect.material.diffuseColor = GLKVector4Make(0.15f, 0.55f, 0.25f, 1.f);
    
    [_effect prepareToDraw];

    // Draw ground.
    glBindBuffer(GL_ARRAY_BUFFER, _vb);

    glEnableVertexAttribArray(GLKVertexAttribPosition);
    glVertexAttribPointer(GLKVertexAttribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)offsetof(Vertex, pos));
    glEnableVertexAttribArray(GLKVertexAttribNormal);
    glVertexAttribPointer(GLKVertexAttribNormal, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)offsetof(Vertex, norm));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ib);
   
    glDrawElements(GL_TRIANGLES, _archStart, GL_UNSIGNED_SHORT, 0);

    // Draw arches.
    _effect.material.diffuseColor = GLKVector4Make(1.f, 1.f, 1.f, 1.f);    
    [_effect prepareToDraw];
    glDrawElements(GL_TRIANGLES, _indices.size() - _archStart, GL_UNSIGNED_SHORT, (GLvoid*)(_archStart * sizeof(unsigned short)));
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);    

    _rotation += (72.f / 360.f) * (float)self.timeSinceLastDraw;
}

@end
 
