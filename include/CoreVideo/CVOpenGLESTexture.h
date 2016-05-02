//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <CoreVideo/CoreVideoExport.h>

#import <CoreFoundation/CFBase.h>
#import <CoreVideo/CVImageBuffer.h>

// TODO::
// todo-nithishm-01282016 - Temp typedef for stubbed methods. Need to use ANGLE headers when these methods are implemented.
typedef unsigned int GLenum;
typedef unsigned int GLuint;
typedef signed int GLint;
typedef char GLchar;
typedef float GLfloat;
typedef int GLsizei;

typedef CVImageBufferRef CVOpenGLESTextureRef;

COREVIDEO_EXPORT CFTypeID CVOpenGLESTextureGetTypeID() STUB_METHOD;
COREVIDEO_EXPORT GLenum CVOpenGLESTextureGetTarget(CVOpenGLESTextureRef image) STUB_METHOD;
COREVIDEO_EXPORT GLuint CVOpenGLESTextureGetName(CVOpenGLESTextureRef image) STUB_METHOD;
COREVIDEO_EXPORT Boolean CVOpenGLESTextureIsFlipped(CVOpenGLESTextureRef image) STUB_METHOD;
COREVIDEO_EXPORT void CVOpenGLESTextureGetCleanTexCoords(
    CVOpenGLESTextureRef image, GLfloat lowerLeft[2], GLfloat lowerRight[2], GLfloat upperRight[2], GLfloat upperLeft[2]) STUB_METHOD;
