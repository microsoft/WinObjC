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

#include <math.h>
#include <malloc.h>
#include <assert.h>

#include <vector>
#include <algorithm>

#include <d3d11.h>
#include <d3d11_2.h>

#undef interface
#include "Starboard.h"
#include "UIInterface.h"
#include "CACompositorClient.h"
#include "DXCompositor.h"
#include "winobjc\winobjc.h"

DXCompositorInterface *_dxCompositor;

static bool bLandscape;

class DXWin32CompositorClient : public CACompositorClientInterface
{
public:
    HANDLE _hNewFrameAvailable;

    DXWin32CompositorClient()
    {
        _hNewFrameAvailable = CreateEventEx(NULL, NULL, 0, 0);
    }

    void RequestRedraw() 
    { 
        SetEvent(_hNewFrameAvailable);
    }

    void RequestTransactionProcessing() 
    {
        UIRequestTransactionProcessing();
    }

    void SetLandscape(bool isLandscape) 
    {
        bLandscape = isLandscape;
        if ( _dxCompositor ) _dxCompositor->SetLandscape(isLandscape);
    }
};

DXWin32CompositorClient *_client;
void SetCACompositorClient(CACompositorClientInterface *client);

HANDLE IWConnectCompositor(ID3D11Device1 *device)
{
    _client = new DXWin32CompositorClient();
    SetCACompositorClient(_client);
    _dxCompositor = CreateDXCompositor(_client);
    _dxCompositor->ConnectDevice((ID3D11Device1*)device);

    return _client->_hNewFrameAvailable;
}

__declspec(dllexport)
CACompositorClientInterface *CreateCompositorClient()
{
    _client = new DXWin32CompositorClient();
    return _client;
}

void IWRenderFrame(ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget, float width, float height)
{
    if ( _dxCompositor ) {
        _dxCompositor->SetRenderSize(width, height);
        _dxCompositor->RenderFrame(context, renderTarget);
    }
}

void IWHandleInput(float x, float y, float width, float height, int fingerID, int eventType, int64_t eventTime)
{
    UIQueueTouchInput(x, y, fingerID, eventType, width, height, eventTime, bLandscape);
}

