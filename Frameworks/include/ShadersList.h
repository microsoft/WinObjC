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

#include "Platform\EbrDirectX.h"
#include "Starboard.h"

class Shader {
    EbrComPtr<ID3D11Buffer> mQuadVB;
    EbrComPtr<ID3D11SamplerState> mPassThroughSampler;
    EbrComPtr<ID3D11InputLayout> mPassThroughIL;
    EbrComPtr<ID3D11VertexShader> mPassThroughVS;
    EbrComPtr<ID3D11PixelShader> mPassThroughPS;

    UINT mVertexSize;
    UINT mVertexCount;
    UINT mStartIdx;
    
public:
    Shader();
    ~Shader();

    static void setMatrix(ID3D11DeviceContext *ctx, float *matrix);
    static void initShaders(ID3D11Device* device);
    static void destroyShaders();

    void newFrame();
    
    bool loadFrom(ID3D11Device *device, D3D11_INPUT_ELEMENT_DESC *desc, int descCount, int vertexSize, int maxVertexElements, const BYTE *vertexBin, int vertexLen, const BYTE *pixelBin, int pixelLen);
    void draw(ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget, ID3D11DepthStencilView *depthTarget, ID3D11ShaderResourceView *texture, const void *buffer, int bufferLen);
};
