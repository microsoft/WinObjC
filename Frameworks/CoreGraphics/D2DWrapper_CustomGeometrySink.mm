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

#import <CoreGraphics/D2DWrapper.h>
#import <Starboard.h>

#import "CoreGraphics/D2DWrapper_CustomGeometrySink.h"

#include <COMIncludes.h>
#import <WRLHelpers.h>
#include <COMIncludes_End.h>

// The CGPathApplySink is an implementation of the Id2D1SimplifiedGeometrySink. We use this sink to create a custom callback for each
// figure type of the path. This will let us call the CGPathApplierFunction provided to us automatically through the use of D2D APIs.
// This should only be used with CGPathApply as it is very specialized for this case only.
class _CGPathApplySink
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                          ID2D1SimplifiedGeometrySink> {
protected:
    InspectableClass(L"Windows.Bridge.Direct2D._CGPathApplySink", TrustLevel::BaseTrust);

public:
    _CGPathApplySink(_In_ void* info, _In_ CGPathApplierFunction function) : m_info(info), m_pathApplierFunction(function) {
    }

    STDMETHOD_(void, AddBeziers)(const D2D1_BEZIER_SEGMENT* beziers, UINT bezierCount) {
        FAIL_FAST_IF_NULL(beziers);
        for (UINT i = 0; i < bezierCount; ++i) {
            CGPoint cgPoints[3] = { _D2DPointToCGPoint(beziers[i].point1),
                                    _D2DPointToCGPoint(beziers[i].point2),
                                    _D2DPointToCGPoint(beziers[i].point3) };
            CGPathElement element = { kCGPathElementAddCurveToPoint, cgPoints };
            m_pathApplierFunction(m_info, &element);
        }
    }

    STDMETHOD_(void, AddLines)(const D2D1_POINT_2F* points, UINT pointsCount) {
        FAIL_FAST_IF_NULL(points);
        for (UINT i = 0; i < pointsCount; ++i) {
            CGPoint cgPoints[1] = { _D2DPointToCGPoint(points[i]) };

            CGPathElement element = { kCGPathElementAddLineToPoint, cgPoints };
            m_pathApplierFunction(m_info, &element);
        }
    }

    STDMETHOD_(void, BeginFigure)(D2D1_POINT_2F startPoint, D2D1_FIGURE_BEGIN figureBegin) {
        CGPoint cgPoints[1] = { _D2DPointToCGPoint(startPoint) };

        CGPathElement element = { kCGPathElementMoveToPoint, cgPoints };
        m_pathApplierFunction(m_info, &element);
    }

    // End Figure is empty as there is no expected callback for a figure ending, there is a callback strictly for a sub path being closed.
    STDMETHOD_(void, EndFigure)(D2D1_FIGURE_END figureEnd) {
    }

    // This custom class is striclty for callbacks on figures.
    STDMETHOD_(void, SetFillMode)(D2D1_FILL_MODE fillMode) {
    }

    // This custom class is striclty for callbacks on figures.
    STDMETHOD_(void, SetSegmentFlags)(D2D1_PATH_SEGMENT vertexFlags) {
    }

    STDMETHOD(Close)() {
        return S_OK;
    }

private:
    void* m_info;
    CGPathApplierFunction m_pathApplierFunction;
};

using namespace Microsoft::WRL;

HRESULT _CGPathApplyInternal(ComPtr<ID2D1PathGeometry> pathGeometry, void* info, CGPathApplierFunction function) {
    ComPtr<_CGPathApplySink> sink = Microsoft::WRL::Make<_CGPathApplySink>(info, function);
    RETURN_IF_FAILED(pathGeometry->Simplify(D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES, D2D1::IdentityMatrix(), sink.Get()));
    return S_OK;
}