//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#if defined(__OBJC__)
#include <COMIncludes.h>
#endif

#include <wrl/client.h>

#if defined(__OBJC__)
#include <COMIncludes_end.h>
#endif

// Proxy for CG-rendered content
struct IDisplayTexture {
public:
    virtual ~IDisplayTexture(){};

    virtual Microsoft::WRL::ComPtr<IInspectable> GetContent() = 0;
    // Returns a pointer to the start of the backing buffer
    virtual void* Lock(int* stride) = 0;
    virtual void Unlock() = 0;
};
