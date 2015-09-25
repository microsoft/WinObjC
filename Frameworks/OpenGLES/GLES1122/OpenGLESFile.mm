/*
Copyright 2009 Johannes Vuorinen

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "OpenGLESFile.h"
//#include "Util.h"
#include <stdio.h>
#include <assert.h>

using namespace OpenGLES;

#include "gles11shaders\alphaTest.frag.h"
#include "gles11shaders\clipPlane.frag.h"
#include "gles11shaders\clipPlane.vert.h"
#include "gles11shaders\fog.glsl.h"
#include "gles11shaders\lighting.frag.h"
#include "gles11shaders\lighting.vert.h"
#include "gles11shaders\lightingPerFragment.frag.h"
#include "gles11shaders\lightingPerFragment.vert.h"
#include "gles11shaders\lightingPerVertex.vert.h"
#include "gles11shaders\main.frag.h"
#include "gles11shaders\main.vert.h"
#include "gles11shaders\postprocess.frag.h"
#include "gles11shaders\postprocess.vert.h"
#include "gles11shaders\texture.frag.h"
#include "gles11shaders\texture.vert.h"
#include "gles11shaders\texture0.frag.h"
#include "gles11shaders\texture0.vert.h"
#include "gles11shaders\texture1.frag.h"
#include "gles11shaders\texture1.vert.h"
#include "gles11shaders\texture2.frag.h"
#include "gles11shaders\texture2.vert.h"

struct ShaderFile {
    const char* _filename;
    const unsigned char* _buf;
    int _len;
};

#define NAMESIZE(x) x, sizeof(x)
#define NUMFILES sizeof(files) / sizeof(files[0])

static ShaderFile files[] = { "alphaTest.frag",
                              NAMESIZE(alphaTest_frag),
                              "clipPlane.frag",
                              NAMESIZE(clipPlane_frag),
                              "clipPlane.vert",
                              NAMESIZE(clipPlane_vert),
                              "fog.glsl",
                              NAMESIZE(fog_glsl),
                              "lighting.frag",
                              NAMESIZE(lighting_frag),
                              "lighting.vert",
                              NAMESIZE(lighting_vert),
                              "lightingPerFragment.frag",
                              NAMESIZE(lightingPerFragment_frag),
                              "lightingPerFragment.vert",
                              NAMESIZE(lightingPerFragment_vert),
                              "lightingPerVertex.vert",
                              NAMESIZE(lightingPerVertex_vert),
                              "main.frag",
                              NAMESIZE(main_frag),
                              "main.vert",
                              NAMESIZE(main_vert),
                              "postprocess.frag",
                              NAMESIZE(postprocess_frag),
                              "postprocess.vert",
                              NAMESIZE(postprocess_vert),
                              "texture.frag",
                              NAMESIZE(texture_frag),
                              "texture.vert",
                              NAMESIZE(texture_vert),
                              "texture0.frag",
                              NAMESIZE(texture0_frag),
                              "texture0.vert",
                              NAMESIZE(texture0_vert),
                              "texture1.frag",
                              NAMESIZE(texture1_frag),
                              "texture1.vert",
                              NAMESIZE(texture1_vert),
                              "texture2.frag",
                              NAMESIZE(texture2_frag),
                              "texture2.vert",
                              NAMESIZE(texture2_vert) };

OpenGLESFile::OpenGLESFile(std::string n) : name() {
    name = n.c_str();
    buf_pos = 0;
}

bool OpenGLESFile::open() {
    for (int i = 0; i < NUMFILES; i++) {
        if (strcmp(files[i]._filename, name.c_str()) == 0) {
            buf = (const char*)files[i]._buf;
            buf_len = files[i]._len;
            buf_pos = 0;
            return true;
        }
    }
    return false;
}

int OpenGLESFile::seek(long int offset, int origin) {
    switch (origin) {
        case SEEK_SET:
            buf_pos = offset;
            break;

        case SEEK_END:
            buf_pos = buf_len;
            break;

        case SEEK_CUR:
            buf_pos += offset;
            break;
    }

    if (buf_pos > buf_len)
        buf_pos = buf_len;
    if (buf_pos < 0)
        buf_pos = 0;
    return buf_pos;
}

long int OpenGLESFile::tell() {
    return buf_pos;
}

size_t OpenGLESFile::read(void* ptr, size_t size, size_t count) {
    int bytesToRead = size * count;
    int left = buf_len - buf_pos;
    if (left < bytesToRead)
        bytesToRead = left;

    memcpy(ptr, &buf[buf_pos], bytesToRead);
    buf_pos += bytesToRead;

    return bytesToRead / size;
}

void OpenGLESFile::close() {
}

std::string OpenGLESFile::getName() {
    return name;
}
