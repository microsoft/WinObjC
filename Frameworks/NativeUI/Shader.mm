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

#include <malloc.h>

#include "Starboard.h"

#include "ShadersList.h"

#if NATIVEUI_3D

struct CommonShaderConstBuf {
    float mvpMatrix[16];
};

ID3D11Buffer* _shaderConstBuf = NULL;

#endif

Shader::Shader()
{
}

Shader::~Shader()
{
    mQuadVB = nullptr;
    mPassThroughSampler = nullptr;
    mPassThroughIL = nullptr;
    mPassThroughVS = nullptr;
    mPassThroughPS = nullptr;
}

void Shader::setMatrix(ID3D11DeviceContext *ctx, float *matrix)
{
#if NATIVEUI_3D
    D3D11_MAPPED_SUBRESOURCE res = { 0 };
    ctx->Map(_shaderConstBuf, 0, D3D11_MAP_WRITE_DISCARD, 0, &res);
    memcpy(res.pData, matrix, 16 * sizeof(float));
    ctx->Unmap(_shaderConstBuf, 0);
#endif 
}

void Shader::initShaders(ID3D11Device* device)
{
#if NATIVEUI_3D
    D3D11_BUFFER_DESC desc;
    desc.ByteWidth = sizeof(CommonShaderConstBuf);
    desc.Usage = D3D11_USAGE_DYNAMIC;
    desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    desc.MiscFlags = 0;
    desc.StructureByteStride = 0;

    // Fill in the subresource data.
    CommonShaderConstBuf shaderConsts = { 0 };

    D3D11_SUBRESOURCE_DATA initData;
    initData.pSysMem = &shaderConsts;
    initData.SysMemPitch = 0;
    initData.SysMemSlicePitch = 0;

    // Create the buffer.
    HRESULT hr = device->CreateBuffer(&desc, &initData, &_shaderConstBuf);
    if(FAILED(hr)) {
        EbrDebugLog("ERROR: could not create shader constant buffer.\n");
    }
#endif 
}

void Shader::destroyShaders()
{
#if NATIVEUI_3D
    if ( _shaderConstBuf ) {
        _shaderConstBuf->Release();
        _shaderConstBuf = NULL;
    }
#endif 
}

void Shader::newFrame()
{
}

bool Shader::loadFrom(ID3D11Device *device, D3D11_INPUT_ELEMENT_DESC *desc, int descCount,
                      int vertexSize, int maxVertexElements, const BYTE *vertexBin,
                      int vertexLen, const BYTE *pixelBin, int pixelLen)
{
    // Make sure our resources are all not allocated, when we create
    D3D11_BUFFER_DESC vbDesc;
    vbDesc.ByteWidth = vertexSize * maxVertexElements;
    vbDesc.Usage = D3D11_USAGE_DYNAMIC;
    vbDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vbDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    vbDesc.MiscFlags = 0;
    vbDesc.StructureByteStride = 0;

    mVertexSize = vertexSize;
    mVertexCount = maxVertexElements;

    HRESULT result = device->CreateBuffer(&vbDesc, NULL, mQuadVB.ReleaseAndGetAddressOf());
    assert(SUCCEEDED(result));

    D3D11_SAMPLER_DESC samplerDesc;
    samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
    samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
    samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    samplerDesc.MipLODBias = 0.0f;
    samplerDesc.MaxAnisotropy = 0;
    samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    samplerDesc.BorderColor[0] = 0.0f;
    samplerDesc.BorderColor[1] = 0.0f;
    samplerDesc.BorderColor[2] = 0.0f;
    samplerDesc.BorderColor[3] = 0.0f;
    samplerDesc.MinLOD = 0;
    if (device->GetFeatureLevel() <= D3D_FEATURE_LEVEL_9_3)
        samplerDesc.MaxLOD = FLT_MAX; //breaks Surface RT if 0.0f
    else
        samplerDesc.MaxLOD = 0.0f;

    result = device->CreateSamplerState(&samplerDesc, mPassThroughSampler.ReleaseAndGetAddressOf());
    assert(SUCCEEDED(result));

    result = device->CreateInputLayout(desc, descCount, vertexBin, vertexLen, mPassThroughIL.ReleaseAndGetAddressOf());
    assert(SUCCEEDED(result));

    result = device->CreateVertexShader(vertexBin, vertexLen, NULL, mPassThroughVS.ReleaseAndGetAddressOf());
    assert(SUCCEEDED(result));

    result = device->CreatePixelShader(pixelBin, pixelLen, NULL, mPassThroughPS.ReleaseAndGetAddressOf());
    assert(SUCCEEDED(result));

    return true;
}

void Shader::draw(ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget,
                  ID3D11DepthStencilView *depthTarget, ID3D11ShaderResourceView *texture,
                  const void *buffer, int numVertices)
{
    HRESULT result = S_OK;

    D3D11_MAP mapType;

    // Do we wrap the ring buffer or not?
    // TODO: this can be reset every frame.
    if (mStartIdx + numVertices > mVertexCount) {
        mStartIdx = 0;
        mapType = D3D11_MAP_WRITE_DISCARD;
    } else {
        mapType = D3D11_MAP_WRITE_NO_OVERWRITE;
    }
    
    // Set vertices
    D3D11_MAPPED_SUBRESOURCE mappedResource;
    result = context->Map(mQuadVB.Get(), 0, mapType, 0, &mappedResource);
    if (FAILED(result))
    {
        EbrDebugLog("ERROR: failed map of vertex buffer resource!\n");
        return;
    }

    char* dest = ((char *)mappedResource.pData) + (mStartIdx * mVertexSize);
    memcpy(dest, buffer, numVertices * mVertexSize);
    context->Unmap(mQuadVB.Get(), 0);

    // TODO: might not need to do this every frame.
    UINT startOffset = 0;
    context->IASetVertexBuffers(0, 1, mQuadVB.GetAddressOf(), &mVertexSize, &startOffset);

    // Apply shaders
    context->IASetInputLayout(mPassThroughIL.Get());
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    context->VSSetShader(mPassThroughVS.Get(), NULL, 0);
    context->PSSetShader(mPassThroughPS.Get(), NULL, 0);

    // Apply render targets
    context->OMSetRenderTargets(1, &renderTarget, depthTarget);

    // Apply textures
    context->PSSetShaderResources(0, 1, &texture);
    context->PSSetSamplers(0, 1, mPassThroughSampler.GetAddressOf());

    // Set shader constants.
#if NATIVEUI_3D    
    context->VSSetConstantBuffers(0, 1, &_shaderConstBuf);
#endif 
    
    context->Draw(numVertices, mStartIdx);
    mStartIdx += numVertices;

    // Unbind
    static ID3D11ShaderResourceView *const nullSRV = NULL;
    context->PSSetShaderResources(0, 1, &nullSRV);
}

