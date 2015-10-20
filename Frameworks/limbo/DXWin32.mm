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

#if defined(WIN32) || defined(QNX)
#include <process.h>
#endif

#include <math.h>
#include <malloc.h>
#include <assert.h>

#include <vector>
#include <algorithm>

#include "Platform\EbrDirectX.h"
#include <d3d11.h>
#include <d3d11_2.h>

#undef interface
#include "Starboard.h"
#include "UIInterface.h"
#include "CACompositorClient.h"
#include "DXCompositor.h"

#pragma comment(lib, "d3d11.lib")

struct ApplicationProperties {
public:
    float appWidth, appHeight, appScale;
    const char* appName;
    bool isTablet;
    bool bLandscape;
};

ApplicationProperties applicationProperties;

// For XAML interop.
ID3D11Device2* existingDevice = NULL;
ID3D11DeviceContext2* existingContext = NULL;
IDXGISwapChain* existingChain = NULL;
ID3D11RenderTargetView* existingRtv = NULL;
static HANDLE _hNewFrameAvailable;

DXCompositorInterface* _dxCompositor;

#define EVENT_DOWN 0x64
#define EVENT_MOVE 0x65
#define EVENT_UP 0x66

float windowWidth, windowHeight;

DWORD windowStyle = (WS_OVERLAPPEDWINDOW);

static LRESULT CALLBACK CompositorWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_DESTROY:
            PostQuitMessage(0);
            UIShutdown();
            break;

        case WM_SIZE: {
            RECT rc;

            GetClientRect(hWnd, &rc);
            unsigned newWidth = rc.right - rc.left;
            unsigned newHeight = rc.bottom - rc.top;

            windowWidth = newWidth;
            windowHeight = newHeight;

            if (_dxCompositor) {
                _dxCompositor->SetRenderSize(newWidth, newHeight);

                if (existingRtv && existingChain && existingDevice && existingContext) {
                    existingRtv->Release();
                    existingRtv = NULL;

                    HRESULT hr = S_OK;
                    hr = existingChain->ResizeBuffers(0, newWidth, newHeight, DXGI_FORMAT_UNKNOWN, 0);
                    assert(hr == S_OK);

                    ID3D11Texture2D* pBackBuffer;
                    hr = existingChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
                    assert(hr == S_OK);

                    hr = existingDevice->CreateRenderTargetView(pBackBuffer, NULL, &existingRtv);
                    assert(hr == S_OK);

                    pBackBuffer->Release();
                    existingContext->OMSetRenderTargets(1, &existingRtv, NULL);
                }
                SetEvent(_hNewFrameAvailable);
            }
        } break;

        case WM_CHAR:
            UIQueueKeyInput(wParam);
            break;

        case WM_POINTERDOWN:
        case WM_POINTERUPDATE:
        case WM_POINTERUP:
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_MOUSEMOVE: {
            float x = (float)(signed short)LOWORD(lParam);
            float y = (float)(signed short)HIWORD(lParam);
            uint64_t timestamp;

            int touchID = 0;
            if (message == WM_LBUTTONDOWN || message == WM_LBUTTONUP || message == WM_MOUSEMOVE) {
                touchID = 0x7FFFFFFF;
                timestamp = GetTickCount64() * 1000000LL;
            } else {
                POINT pt;

                pt.x = x;
                pt.y = y;
                ScreenToClient(hWnd, &pt);
                x = pt.x;
                y = pt.y;

                touchID = GET_POINTERID_WPARAM(wParam);

                POINTER_INFO pi;
                GetPointerInfo(touchID, &pi);

                timestamp = pi.dwTime * 1000000LL;
            }

            if (touchID == -1)
                break;

            switch (message) {
                case WM_LBUTTONDOWN:
                case WM_LBUTTONDBLCLK:
                case WM_POINTERDOWN:
                    SetFocus(hWnd);
                    SetCapture(hWnd);
                    UIQueueTouchInput(x, y, touchID, EVENT_DOWN, windowWidth, windowHeight, timestamp, applicationProperties.bLandscape);
                    break;

                case WM_LBUTTONUP:
                case WM_POINTERUP:
                    ReleaseCapture();
                    UIQueueTouchInput(x, y, touchID, EVENT_UP, windowWidth, windowHeight, timestamp, applicationProperties.bLandscape);
                    break;

                case WM_MOUSEMOVE:
                case WM_POINTERUPDATE:
                    UIQueueTouchInput(x, y, touchID, EVENT_MOVE, windowWidth, windowHeight, timestamp, applicationProperties.bLandscape);
                    break;
            }
        }
            return 0;
            break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

static HANDLE compositorReady;

class DXWin32CompositorClient : public CACompositorClientInterface {
public:
    DXWin32CompositorClient() {
        _hNewFrameAvailable = CreateEvent(NULL, FALSE, FALSE, NULL);
    }

    void RequestRedraw() {
        SetEvent(_hNewFrameAvailable);
    }

    void RequestTransactionProcessing() {
        UIRequestTransactionProcessing();
    }

    void SetLandscape(bool isLandscape) {
        applicationProperties.bLandscape = isLandscape;
        if (_dxCompositor)
            _dxCompositor->SetLandscape(isLandscape);
    }
};

DXWin32CompositorClient* _client;

static DWORD WINAPI CompositorThread(LPVOID thread) {
    // the handle for the window, filled by a function
    HWND hWnd = NULL;

    assert(existingDevice == NULL && existingContext == NULL && existingChain == NULL);

    // this struct holds information for the window class
    WNDCLASSEX wc;

    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    // fill in the struct with the needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = CompositorWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = "DX Compositor";

    // register the window class
    RegisterClassEx(&wc);

    int windowWidth = applicationProperties.appWidth;
    int windowHeight = applicationProperties.appHeight;

    if (applicationProperties.bLandscape) {
        int tmp = windowWidth;
        windowWidth = windowHeight;
        windowHeight = tmp;
    }

    // create the window and use the result as the handle
    hWnd = CreateWindowEx(NULL,
                          "DX Compositor", // name of the window class
                          applicationProperties.appName, // title of the window
                          windowStyle, // window style
                          100, // x-position of the window
                          100, // y-position of the window
                          windowWidth, // width of the window
                          windowHeight, // height of the window
                          NULL, // we have no parent window, NULL
                          NULL, // we aren't using menus, NULL
                          GetModuleHandle(NULL), // application handle
                          NULL); // used with multiple windows, NULL

    RegisterTouchWindow(hWnd, 0);

    // Make sure the client rect is the size we want:

    RECT clientRect, wr;
    GetClientRect(hWnd, &clientRect);
    GetWindowRect(hWnd, &wr);

    float widthDiff = wr.right - wr.left - clientRect.right;
    float heightDiff = wr.bottom - wr.top - clientRect.bottom;
    MoveWindow(hWnd, wr.left, wr.top, windowWidth + widthDiff, windowHeight + heightDiff, TRUE);

    // display the window on the screen
    ShowWindow(hWnd, SW_SHOW);

    // create a struct to hold information about the swap chain
    DXGI_SWAP_CHAIN_DESC scd;

    // clear out the struct for use
    ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

    // fill the swap chain description struct
    scd.BufferCount = 1; // one back buffer
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // use 32-bit color
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // how swap chain is to be used
    scd.OutputWindow = hWnd; // the window to be used
    scd.SampleDesc.Count = 1; // how many multisamples
    scd.Windowed = TRUE; // windowed/full-screen mode

    // create a device, device context and swap chain using the information in the scd struct
    HRESULT rc = D3D11CreateDeviceAndSwapChain(NULL,
                                               D3D_DRIVER_TYPE_HARDWARE,
                                               NULL,
                                               NULL,
                                               NULL,
                                               NULL,
                                               D3D11_SDK_VERSION,
                                               &scd,
                                               &existingChain,
                                               (ID3D11Device**)&existingDevice,
                                               NULL,
                                               (ID3D11DeviceContext**)&existingContext);
    if (FAILED(rc)) {
        char buf[512];
        sprintf(buf, "HRESULT IS 0x%x\n", rc);
        OutputDebugStringA(buf);
    }

    existingChain->ResizeBuffers(0, windowWidth, windowHeight, DXGI_FORMAT_UNKNOWN, 0);

    ID3D11Texture2D* pBackBuffer;
    existingChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    existingDevice->CreateRenderTargetView(pBackBuffer, NULL, &existingRtv);
    pBackBuffer->Release();
    existingContext->OMSetRenderTargets(1, &existingRtv, NULL);
    MSG msg;

    _dxCompositor->ConnectDevice((ID3D11Device1*)existingDevice);
    _dxCompositor->SetRenderSize(windowWidth, windowHeight);
    _dxCompositor->SetLandscape(applicationProperties.bLandscape);
    SetEvent(compositorReady);

    for (;;) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            DWORD result = MsgWaitForMultipleObjectsEx(1, &_hNewFrameAvailable, INFINITE, QS_ALLEVENTS, MWMO_ALERTABLE);
            if (result == WAIT_OBJECT_0) {
                _dxCompositor->RenderFrame(existingContext, existingRtv);
                existingChain->Present(1, 0);
            }
        }
    }

    return 0;
}

const char* GetAppNameFromPList() {
    NSString* appName = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"];
    if (appName != nil) {
        return [appName UTF8String];
    }

    return "Starboard";
}

void NoExclude();

int UIApplicationMain(int argc, char* argv[], NSString* principalClassName, NSString* delegateClassName) {
    NoExclude();

    _client = new DXWin32CompositorClient();
    _dxCompositor = CreateDXCompositor(_client);

    float defaultWidth = GetCACompositor()->screenWidth();
    float defaultHeight = GetCACompositor()->screenHeight();
    float defaultScale = GetCACompositor()->screenScale();
    bool defaultTablet = false;
    bool bLandscape = false;

    [NSBundle setMainBundlePath:@"."];

    if ([UIApplication respondsToSelector:@selector(initialOperationMode)]) {
        UIOperationMode mode = [UIApplication initialOperationMode];
        if (mode == UIOperationModeTablet) {
            defaultTablet = true;
            defaultWidth = 768.0f;
            defaultHeight = 1024.0f;
            defaultScale = 1.0f;
        }
    }
    if ([UIApplication respondsToSelector:@selector(renderWidth)]) {
        defaultWidth = [UIApplication renderWidth];
    }
    if ([UIApplication respondsToSelector:@selector(renderHeight)]) {
        defaultHeight = [UIApplication renderHeight];
    }
    if ([UIApplication respondsToSelector:@selector(renderScale)]) {
        defaultScale = [UIApplication renderScale];
    }

    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];

    //  Figure out what our initial default orientation should be from Info.plist
    int defaultOrientation = UIInterfaceOrientationUnknown;
    if (infoDict != nil) {
        defaultOrientation = EbrGetWantedOrientation();

        NSObject* orientation;
        orientation = [infoDict objectForKey:@"UISupportedInterfaceOrientations"];
        if (orientation == nil)
            orientation = [infoDict objectForKey:@"UIInterfaceOrientation"];

        if ([orientation isKindOfClass:[NSString class]]) {
            defaultOrientation = UIOrientationFromString(defaultOrientation, orientation);
        } else if ([orientation isKindOfClass:[NSArray class]]) {
            bool found = false;

            for (NSString* curstr in (NSArray*)orientation) {
                int newOrientation = UIOrientationFromString(defaultOrientation, curstr);
                if (newOrientation == defaultOrientation) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                if ([orientation count] > 0) {
                    defaultOrientation = UIOrientationFromString(defaultOrientation, [orientation objectAtIndex:0]);
                } else {
                    defaultOrientation = UIInterfaceOrientationPortrait;
                }
            }
        } else {
            defaultOrientation = UIInterfaceOrientationPortrait;
        }
    }

    if (defaultOrientation == UIInterfaceOrientationLandscapeLeft || defaultOrientation == UIInterfaceOrientationLandscapeRight) {
        bLandscape = true;
    }

    applicationProperties.appWidth = defaultWidth;
    applicationProperties.appHeight = defaultHeight;
    applicationProperties.appScale = defaultScale;
    applicationProperties.appName = strdup(GetAppNameFromPList());
    applicationProperties.isTablet = defaultTablet;
    applicationProperties.bLandscape = bLandscape;

    GetCACompositor()->setScreenSize(applicationProperties.appWidth, applicationProperties.appHeight, applicationProperties.appScale);
    GetCACompositor()->setDeviceSize(applicationProperties.appWidth * applicationProperties.appScale,
                                     applicationProperties.appHeight * applicationProperties.appScale);
    GetCACompositor()->setTablet(applicationProperties.isTablet);

    DWORD tid;
    compositorReady = CreateEvent(NULL, FALSE, FALSE, NULL);
    CreateThread(NULL, 65536, CompositorThread, NULL, 0, &tid);
    WaitForSingleObject(compositorReady, INFINITE);

    UIApplicationMainInit(argc, argv, principalClassName, delegateClassName, defaultOrientation);
    return UIApplicationMainLoop();
}
