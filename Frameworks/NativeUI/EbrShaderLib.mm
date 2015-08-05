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

#include <stdio.h>
#include <stdlib.h>

#include "Starboard.h"

#include "EbrShaderLib.h"
#include "ShadersList.h"


#if NATIVEUI_3D
    #include "Shaders/vs_passthroughsolid.h"
    #include "Shaders/vs_passthroughtex.h"
    #include "Shaders/vs_passthroughtexcolor.h"
#else 
    #include "Shaders/vs_passthroughsolid_2d.h"
    #include "Shaders/vs_passthroughtex_2d.h"
    #include "Shaders/vs_passthroughtexcolor_2d.h"
#endif 

#include "Shaders/ps_passthroughsolid.h"
#include "Shaders/ps_passthroughtex.h"
#include "Shaders/ps_passthroughtexcolor.h"
#include "Shaders/ps_passthroughfont.h"
#include "Shaders/ps_passthroughsdffont.h"

#define MAX_SHADERS 15

static Shader *ebrShaders[MAX_SHADERS] = { 0 };
static int numEbrShaders;
static Shader *activeShader = NULL;

static bool shadersInitialized;

bool EbrShaderInit(ID3D11Device *device)
{
    if ( shadersInitialized ) {
        return true;
    }
    shadersInitialized = true;
    numEbrShaders = 0;


    {
        D3D11_INPUT_ELEMENT_DESC layout[] =
        {
#if NATIVEUI_3D
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#else
            { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#endif             
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        ebrShaders[numEbrShaders] = new Shader();
        ebrShaders[numEbrShaders]->loadFrom(device, layout, 3, sizeof(PositionTexColorVertex), 1024,
            g_VS_PassthroughSolid, sizeof(g_VS_PassthroughSolid),
            g_PS_PassthroughSolid, sizeof(g_PS_PassthroughSolid));
        numEbrShaders ++;
    }

    {
        D3D11_INPUT_ELEMENT_DESC layout[] =
        {
#if NATIVEUI_3D
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#else
            { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#endif             
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        ebrShaders[numEbrShaders] = new Shader();
        ebrShaders[numEbrShaders]->loadFrom(device, layout, 3, sizeof(PositionTexColorVertex), 1024, 
            g_VS_PassthroughTex, sizeof(g_VS_PassthroughTex),
            g_PS_PassthroughTex, sizeof(g_PS_PassthroughTex));
        numEbrShaders ++;
    }

    {
        D3D11_INPUT_ELEMENT_DESC layout[] =
        {
#if NATIVEUI_3D
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#else
            { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#endif             
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        ebrShaders[numEbrShaders] = new Shader();
        ebrShaders[numEbrShaders]->loadFrom(device, layout, 3, sizeof(PositionTexColorVertex), 1024,
            g_VS_PassthroughTexColor, sizeof(g_VS_PassthroughTexColor),
            g_PS_PassthroughTexColor, sizeof(g_PS_PassthroughTexColor));
        numEbrShaders ++;
    }

    // Font shader.
    {
        D3D11_INPUT_ELEMENT_DESC layout[] =
        {
#if NATIVEUI_3D
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#else
            { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#endif             
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        ebrShaders[numEbrShaders] = new Shader();
        ebrShaders[numEbrShaders]->loadFrom(device, layout, 3, sizeof(PositionTexColorVertex), 2048,
            g_VS_PassthroughTexColor, sizeof(g_VS_PassthroughTexColor),
            g_PS_PassthroughFont, sizeof(g_PS_PassthroughFont));
        numEbrShaders ++;
    }

    // SDF Font shader.
    {
        D3D11_INPUT_ELEMENT_DESC layout[] =
      {
#if NATIVEUI_3D
          { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#else
          { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
#endif             
          { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
          { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
      };

      ebrShaders[numEbrShaders] = new Shader();
      ebrShaders[numEbrShaders]->loadFrom(device, layout, 3, sizeof(PositionTexColorVertex), 2048,
          g_VS_PassthroughTexColor, sizeof(g_VS_PassthroughTexColor),
          g_PS_PassthroughSDFFont, sizeof(g_PS_PassthroughSDFFont));
        numEbrShaders ++;
    }


    return true;
}

bool EbrShaderDestroy()
{
    if ( !shadersInitialized ) {
        return false;
    }
    shadersInitialized = false;
    for ( int i = 0; i < numEbrShaders; i ++ ) {
        delete ebrShaders[i];
        ebrShaders[i] = NULL;
    }
    numEbrShaders = 0;
    return true;
}

void EbrShaderNewFrame()
{
    for(int i = 0; i < numEbrShaders; i++) {
        ebrShaders[i]->newFrame();
    }
}

Shader *EbrShaderGet(EbrShader shader)
{
    Shader *s = ebrShaders[shader];
    return s;
}
