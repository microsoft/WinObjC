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

#include "Shader.h"
#include "../OpenGLESUtil.h"
#include "../OpenGLESConfig.h"
#include "ShaderSource.h"
#include "ShaderFile.h"

using namespace OpenGLES::OpenGLES2;

Shader::Shader(GLenum type, std::vector<ShaderSource*>& sources) : type(type), sources(sources) {
}

Shader::~Shader() {
}

GLuint Shader::compile() {
    id = glCreateShader(type);

    const char* typeString = type == GL_FRAGMENT_SHADER ? "Fragment shader" : "Vertex shader";

    if (id == 0) {
        EbrDebugLog("Error creating shader\n");
        LOG_MESSAGE(__FILE__, __LINE__, OpenGLESString("ERROR: Could not create ") + typeString);
        return 0;
    }

    if (!readShaderSource()) {
        EbrDebugLog("Error reading shader source\n");
        LOG_MESSAGE(__FILE__, __LINE__, OpenGLESString("ERROR: Could not read ") + typeString + OpenGLESString(" source."));
        return 0;
    }

    EbrDebugLog("Compiling\n");
#ifndef WINPHONE
    glCompileShader(id);

    GLint compiled;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);

    if (!compiled || OpenGLESConfig::DEBUG) {
        GLint infoLength;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLength);

        EbrDebugLog("Compile failed %d\n", infoLength);
        if (1) // infoLength > 1)
        {
            char* infoLog = (char*)calloc(sizeof(char) * 4096, 1);
            GLsizei len;
            glGetShaderInfoLog(id, 4096, &len, infoLog);
            EbrDebugLog("Error compiling %d %s\n", len, infoLog);

            if (compiled) {
                LOG_MESSAGE(__FILE__, __LINE__, OpenGLESString("WARNING: Compiled ") + typeString + " with warnings:\n" + infoLog);
            } else {
                LOG_MESSAGE(__FILE__, __LINE__, OpenGLESString("ERROR: Compiling ") + typeString + " failed:\n" + infoLog);
            }
            free(infoLog);
        }

        if (compiled != 0) {
            LOG_MESSAGE(OpenGLESString("Compiled ") + typeString + " successfully.");
        } else {
            glDeleteShader(id);
            return 0;
        }
    }
#endif

    return id;
}

char* convertStringToChar(const std::string& str) {
    size_t retPtrSize = str.length() + 1;
    char* retPtr = (char*)malloc(retPtrSize);

    strcpy_s(retPtr, retPtrSize, str.c_str());

    return retPtr;
}

bool Shader::readShaderSource() {
    char** shaderSources = (char**)malloc(sizeof(char*) * sources.size());

    EbrDebugLog("shader count=%d\n", sources.size());
    if (shaderSources == NULL) {
        EbrDebugLog("Can't allocate memory\n");
        LOG_MESSAGE(__FILE__, __LINE__, "ERROR: Cannot allocate memory.");
        return false;
    }

    for (size_t i = 0; i < sources.size(); i++) {
        shaderSources[i] = convertStringToChar(sources[i]->getSource());
    }

    glShaderSource(id, sources.size(), (const char**)shaderSources, NULL);

    /*
    int curLine = 0;
    FILE *fpOut = fopen("c:\\temp\\shader.txt", "wb");

    for (size_t i = 0; i < sources.size(); i++)
    {
    char *curPtr = shaderSources[i];
    fwrite(curPtr, 1, strlen(curPtr), fpOut);
    free(shaderSources[i]);
    }
    fclose(fpOut);
    */
    for (size_t i = 0; i < sources.size(); i++) {
        free(shaderSources[i]);
    }

    free(shaderSources);

    return true;
}
