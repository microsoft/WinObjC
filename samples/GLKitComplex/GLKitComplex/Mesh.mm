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

#include "Mesh.h"

#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>

#define POS_EPSILON 0.001f
#define UV_EPSILON 0.01f

bool operator==(const MeshVertex& a, const MeshVertex& b)
{
    float dist = 0.f;
    dist += fabsf(a.pos[0] - b.pos[0]);
    dist += fabsf(a.pos[1] - b.pos[1]);
    dist += fabsf(a.pos[2] - b.pos[2]);

    if (dist < POS_EPSILON) {
        return true;
    }
    return false;
}

bool MeshVertex::uvsMatch(const MeshVertex& other) const 
{
    float dist = 0.f;

    dist += fabsf(uv[0] - other.uv[0]);
    dist += fabsf(uv[1] - other.uv[1]);

    return dist < UV_EPSILON;
}

namespace {
    void splitString(const std::string& s, std::vector<std::string>& words, const std::string& separators)
    {
        words.resize(0);

        size_t idx = s.find_first_not_of(separators);
        while(idx != std::string::npos) {
            size_t idx2 = s.find_first_of(separators, idx);
            std::string word = s.substr(idx, (idx2 != std::string::npos) ? (idx2 - idx) : std::string::npos);
            words.push_back(word);
            idx = s.find_first_not_of(separators, idx2);
        }
    }

    float toFloat(const std::string& s) { return atof(s.c_str()); }
    int toInt(const std::string& s)     { return atoi(s.c_str()); }

    void toFloat2(float* f, std::vector<std::string>::iterator it)
    {
        f[0] = toFloat(*it++);
        f[1] = toFloat(*it++);
    }

    void toFloat3(float* f, std::vector<std::string>::iterator it)
    {
        f[0] = toFloat(*it++);
        f[1] = toFloat(*it++);
        f[2] = toFloat(*it++);
    }

    void toInt3(short int* i, std::vector<std::string>::iterator it)
    {
        i[0] = toInt(*it++);
        i[1] = toInt(*it++);
        i[2] = toInt(*it++);
    }
}

Mesh::Mesh() :
    vb(0), ib(0)
{    
}

Mesh::~Mesh()
{   
    if (vb) {
        glDeleteBuffers(1, &vb);        
        vb = 0;
    }
    if (ib) {
        glDeleteBuffers(1, &ib);
        ib = 0;
    }
}

short int Mesh::add(const MeshVertex& v)
{
    auto it = std::find(verts.begin(), verts.end(), v);
    bool orig = true;
    if (it != verts.end()) {

        // Add normal.
        it->norm[0] += v.norm[0];
        it->norm[1] += v.norm[1];
        it->norm[2] += v.norm[2];

        // Check UV coords, add a separate new vert if needed.
        int idx = it - verts.begin();
        int lastIdx = idx;
        while(idx >= 0) {
            if(v.uvsMatch(verts[idx])) return idx;
            lastIdx = idx;
            idx = vertInfos[idx].nextVertInList;
        }
        
        // No UV match.  Add it to pos match list.
        vertInfos[lastIdx].nextVertInList = verts.size();
        orig = false;
    }

    verts.push_back(v);
    vertInfos.push_back(MeshVertexBuildInfo(orig));
    return verts.size() - 1;
}

short int Mesh::buildVert(const std::string& s, const V3Array& verts, const V3Array& norms, const V2Array& uvs)
{
    std::vector<std::string> words;
    splitString(s, words, "/");
    
    short int indices[3];
    toInt3(indices, words.begin());

    MeshVertex v = { 0 };
    
    v.pos[0] = verts[indices[0] - 1].v[0];
    v.pos[1] = verts[indices[0] - 1].v[1];
    v.pos[2] = verts[indices[0] - 1].v[2];
    v.norm[0] = norms[indices[2] - 1].v[0];
    v.norm[1] = norms[indices[2] - 1].v[1];
    v.norm[2] = norms[indices[2] - 1].v[2];
    v.uv[0] = uvs[indices[1] - 1].v[0];
    v.uv[1] = uvs[indices[1] - 1].v[1];

    return add(v);
}

void Mesh::parseFace(std::vector<std::string>::iterator fc,
                     std::vector<std::string>::iterator end,
                     const V3Array& verts, const V3Array& norms, const V2Array& uvs)
{
    short int indices[3];

    Face f = { 0 };
    short int istart, ilast;

    istart = buildVert(*fc++, verts, norms, uvs);
    ilast = buildVert(*fc++, verts, norms, uvs);
    for(; fc != end; fc ++) {
        auto cur = buildVert(*fc, verts, norms, uvs);

        f.indices[0] = istart;
        f.indices[1] = ilast;
        f.indices[2] = cur;
        faces.push_back(f);

        ilast = cur;
    }
}

void Mesh::testMesh()
{
    static Vertices cubeVertices{
        { {0.0f, 2.0f, 0.0f}, {0.f, 1.f, 0.f}, {0.0f,  1.0f,  0.0f,  1.0f}, {0.f, 0.f} },
      
        { {-1.0f, -1.0f, -1.0f}, {0.f, 1.f, 0.f}, {0.0f,  1.0f,  1.0f,  1.0f}, {0.f, 0.f} },
        { {-1.0f, -1.0f, 1.0f}, {0.f, 1.f, 0.f}, {0.0f,  0.0f,  1.0f,  1.0f}, {0.f, 1.f} },
        { { 1.0f, -1.0f, 1.0f}, {0.f, 1.f, 0.f},  {0.1f,  0.0f,  1.0f,  1.0f}, {1.f, 1.f} },
        { { 1.0f, -1.0f, -1.0f}, {0.f, 1.f, 0.f},  {1.0f,  1.0f,  1.0f,  1.0f}, {1.f, 0.f} },
    };

    static Faces cubeFaces{
        {1, 2, 3},
        {1, 3, 4},
    };

    verts = cubeVertices;
    faces = cubeFaces;

    calcBounding();
}

void Mesh::calcNormals()
{
    if (!vertInfos.size()) {
        NSLog(@"Not performing final build step, no auxiliary vertex information.");
        return;
    }

    // Normalize vertex normals, and propagate to all the other vert normals in the same position.
    auto inf = vertInfos.begin();
    for(auto& v : verts) {
        if (inf->isOrigVert) {
            float magn = sqrtf(v.norm[0] * v.norm[0] + v.norm[1] * v.norm[1] +v.norm[2] * v.norm[2]);
            if (magn) {
                magn = 1.f / magn;
                v.norm[0] *= magn;
                v.norm[1] *= magn;
                v.norm[2] *= magn;
            }
            int idx = inf->nextVertInList;
            while(idx > 0) {
                verts[idx].norm[0] = v.norm[0];
                verts[idx].norm[1] = v.norm[1];
                verts[idx].norm[2] = v.norm[2];
                
                idx = vertInfos[idx].nextVertInList;
            }
        }

        inf ++;
    }

    vertInfos.clear();
}

void Mesh::calcBounding()
{
    // This won't be a tight bound due to duplicated vertex positions within the array, but it's "good enough"
    center = GLKVector3Make(0, 0, 0);
    for(const auto& v : verts) {
        center = GLKVector3Add(center, GLKVector3Make(v.pos[0], v.pos[1], v.pos[2]));
    }
    center = GLKVector3DivideScalar(center, static_cast<float>(verts.size()));

    radius = 0.f;
    for(const auto& v : verts) {
        float dist = GLKVector3Distance(center, GLKVector3Make(v.pos[0], v.pos[1], v.pos[2]));
        radius = std::max<float>(radius, dist);
    }    
}

void Mesh::parse(const char* str, size_t len)
{
    char buf[1024];
    std::istringstream in(std::string(str, len));
    std::vector<std::string> words;

    V3Array pos, norm;
    V2Array uv;
    v3 v;
    v2 u;
    
    while(!in.getline(buf, sizeof(buf)).eof()) {
        char* c = strchr(buf, '#');
        if (c) *c = 0;
        splitString(std::string(buf), words, " \t");
        if(words.size() < 1) continue;

        auto next = words.begin() + 1;
        if(words[0] == "v") {
            toFloat3(v.v, next);
            pos.push_back(v);
        } else if(words[0] == "vt") {
            toFloat2(u.v, next);
            uv.push_back(u);
        } else if(words[0] == "vn") {
            toFloat3(v.v, next);
            norm.push_back(v);
        } else if(words[0] == "f") {
            parseFace(next, words.end(), pos, norm, uv);
        }
    }

    calcNormals();
    calcBounding();
}

bool Mesh::createOGLBuffers()
{
    glGenBuffers(1, &vb);
    glGenBuffers(1, &ib);

    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(MeshVertex) * verts.size(), &verts[0], GL_STATIC_DRAW);
    

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Face) * faces.size(), &faces[0], GL_STATIC_DRAW);


    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    GLint i = glGetError();
    if (i) {
        NSLog(@"GL Error 0x%x creating mesh.", i);
        return false;
    }

    return true;
}

void Mesh::bindVertexData()
{
    glBindBuffer(GL_ARRAY_BUFFER, vb);

    glEnableVertexAttribArray(GLKVertexAttribPosition);
    glVertexAttribPointer(GLKVertexAttribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (const GLvoid*)offsetof(MeshVertex, pos));
    glEnableVertexAttribArray(GLKVertexAttribNormal);
    glVertexAttribPointer(GLKVertexAttribNormal, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (const GLvoid*)offsetof(MeshVertex, norm));
    glEnableVertexAttribArray(GLKVertexAttribColor);
    glVertexAttribPointer(GLKVertexAttribColor, 4, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (const GLvoid*)offsetof(MeshVertex, color));
    glEnableVertexAttribArray(GLKVertexAttribTexCoord0);
    glVertexAttribPointer(GLKVertexAttribTexCoord0, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (const GLvoid*)offsetof(MeshVertex, uv));
    glEnableVertexAttribArray(GLKVertexAttribTexCoord1);
    glVertexAttribPointer(GLKVertexAttribTexCoord1, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (const GLvoid*)offsetof(MeshVertex, uv));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
}

// not to be used in production code.
void Mesh::calcColours()
{
    for(auto& v : verts) {
        v.color[0] = v.norm[0] * 0.25f + 0.75f;
        v.color[1] = v.norm[1] * 0.25f + 0.75f;
        v.color[2] = v.norm[2] * 0.25f + 0.75f;
        v.color[3] = 1.f;
    }
}

