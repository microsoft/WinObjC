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

#include "OpenGLES20Implementation.h"
#include "EbrOpenglIncludes.h"
#include <stdlib.h>
#include "../OpenGLESMath.h"
#include <algorithm>

#undef min
#undef max
using namespace OpenGLES::OpenGLES2;

OpenGLES20Implementation::OpenGLES20Implementation() : OpenGLESImplementation()
{
    
}

OpenGLES20Implementation::~OpenGLES20Implementation()
{
    
}

void OpenGLES20Implementation::init() 
{   
    ANGLE_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_FORMAT, &colorReadFormat);
    ANGLE_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_TYPE, &colorReadType);
    ANGLE_glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxCombinedTextureImageUnits);
    maxCombinedTextureImageUnits = std::min(3, maxCombinedTextureImageUnits); // TODO: currently shaders support 3 textures
    ANGLE_glGetIntegerv(GL_MAX_CUBE_MAP_TEXTURE_SIZE, &maxCubeMapTextureSize);
    ANGLE_glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_VECTORS, &maxFragmentUniformVectors);
    
    ANGLE_glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &maxRenderBufferSize);
    ANGLE_glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
    ANGLE_glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureImageUnits);
    maxTextureImageUnits = std::min(3, maxTextureImageUnits); // TODO: currently shaders support 3 textures
    ANGLE_glGetIntegerv(GL_MAX_VARYING_VECTORS, &maxVaryingVectors);
    ANGLE_glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttribs);
    ANGLE_glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &maxVertexTextureImageUnits);
    ANGLE_glGetIntegerv(GL_MAX_VERTEX_UNIFORM_VECTORS, &maxVertexUniformVectors);
    
    ANGLE_glGetIntegerv(GL_MAX_VIEWPORT_DIMS, maxViewportDims);
    ANGLE_glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &numCompressedTextureFormats);
    ANGLE_glGetIntegerv(GL_NUM_SHADER_BINARY_FORMATS, &numShaderBinaryFormats);
    shaderBinaryFormats = (int *)malloc(sizeof(int) * numShaderBinaryFormats);
    ANGLE_glGetIntegerv(GL_SHADER_BINARY_FORMATS, shaderBinaryFormats);
    
    unsigned char tmp;
    ANGLE_glGetBooleanv(GL_SHADER_COMPILER, &tmp);
    shaderCompilerSupported = tmp == 0;
    
    ANGLE_glGetIntegerv(GL_DEPTH_BITS, &depthBits);
    ANGLE_glGetIntegerv(GL_STENCIL_BITS, &stencilBits);
    
    print();
}
