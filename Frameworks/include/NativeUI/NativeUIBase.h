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

enum DisplayTextureType {
    displayTextureNormal,
    displayTextureOpenGL,
    displayTextureKHRTexture,
    displayTextureKHRRenderbuffer,
    displayTextureFontAtlas
};

enum AlphaDrawMode {
    ADM_NO_ALPHA,
    ADM_ALPHA_BLEND,
    ADM_FONT_BLEND,

    ADM_ALPHA_WRITE,
    ADM_ALPHA_DEST_BLEND
};

enum StencilDrawMode {
    SDM_NONE,
    SDM_WRITE,
    SDM_TEST
};

class DrawingObserver
{
public:
    virtual void operationWasClipped() = 0;
    virtual void operationDidDraw() = 0;
    virtual void drawingBegan() = 0;
    virtual void drawingEnded() = 0;
};

