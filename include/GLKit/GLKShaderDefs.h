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

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#define GLKSH_STANDARD_SHADER   "Standard"

// ------------------------------
// Vertex attrs

#define GLKSH_POS_NAME          "_position"
#define GLKSH_NORMAL_NAME       "_normal"
#define GLKSH_COLOR_NAME        "_color"
#define GLKSH_UV0_NAME          "_uv0"
#define GLKSH_UV1_NAME          "_uv1"

// ------------------------------
// Constant names

#define GLKSH_MVP_NAME          "_mvp"

#define GLKSH_TEX0_NAME         "_tex0"
#define GLKSH_TEX1_NAME         "_tex1"

#define GLKSH_CAMERA            "_camera"

#define GLKSH_CONSTCOLOR_NAME   "_constColor"
#define GLKSH_AMBIENT           "_ambient"

#define GLKSH_LIGHT0_COLOR      "_lightcolor0"
#define GLKSH_LIGHT0_POS        "_lightpos0"
#define GLKSH_LIGHT0_ATTEN      "_lightatten0"
#define GLKSH_LIGHT0_SPECULAR   "_lightspec0"

#define GLKSH_LIGHT1_COLOR      "_lightcolor1"
#define GLKSH_LIGHT1_POS        "_lightpos1"
#define GLKSH_LIGHT1_ATTEN      "_lightatten1"
#define GLKSH_LIGHT1_SPECULAR   "_lightspec1"

#define GLKSH_LIGHT2_COLOR      "_lightcolor2"
#define GLKSH_LIGHT2_POS        "_lightpos2"
#define GLKSH_LIGHT2_ATTEN      "_lightatten2"
#define GLKSH_LIGHT2_SPECULAR   "_lightspec2"
