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
#include <vector>

struct v2 {
    float v[2];
};

struct v3 {
    float v[3];
};
typedef std::vector<v2> V2Array;
typedef std::vector<v3> V3Array;

struct MeshVertex {
    float pos[3];
    float norm[3];
    float color[4];
    float uv[2];

    bool uvsMatch(const MeshVertex& other) const;
};

struct MeshVertexBuildInfo {
    explicit inline MeshVertexBuildInfo(bool orig) : isOrigVert(orig) {}
    bool isOrigVert = true;
    int nextVertInList = -1;
};

bool operator==(const MeshVertex& v, const MeshVertex& b);

struct Face {
    short int indices[3];
};

typedef std::vector<MeshVertex> Vertices;
typedef std::vector<MeshVertexBuildInfo> BuildInfos;
typedef std::vector<Face> Faces;

class Mesh {
    Vertices    verts;
    BuildInfos  vertInfos;
    Faces       faces;

    GLuint vb, ib;

    short int add(const MeshVertex& v);
    short int buildVert(const std::string& s, const V3Array& verts, const V3Array& norms, const V2Array& uvs);
    void parseFace(std::vector<std::string>::iterator start,
                   std::vector<std::string>::iterator end,
                   const V3Array& verts, const V3Array& norms, const V2Array& uvs);

    void calcNormals();
    void calcBounding();

    GLKVector3 center;
    float radius;
    
public:
    Mesh();
    ~Mesh();

    void parse(const char* str, size_t len);
    void testMesh();
    bool createOGLBuffers();
    void calcColours();

    void bindVertexData();
    
    inline size_t faceCount() const                 { return faces.size(); }
    inline const GLKVector3& getCenter() const      { return center; }
    inline float getRadius()                        { return radius; }
};
