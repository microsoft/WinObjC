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
#import <GLKit/GLKShaderDefs.h>

#include "ShaderGen.h"
#include "ShaderProg.h"

#define COLOR_WHITE "vec4(1, 1, 1, 1)"
#define COLOR_BLACK "vec4(0, 0, 0, 1)"

ShaderDef standardVsh{
    {"gl_Position", new ShaderPosRef() },
    {"_outColor", new ShaderFallbackRef(GLKSH_CONSTCOLOR_NAME, GLKSH_COLOR_NAME, COLOR_WHITE) }
};

ShaderDef standardPsh{
    {"gl_FragColor", new ShaderVarRef("_outColor")}
};
