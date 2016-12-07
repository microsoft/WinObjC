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

#include <COMIncludes.h>
#import <wrl/implements.h>
#import <D2d1.h>
#include <COMIncludes_End.h>

#import <LoggingNative.h>

#import "DWriteWrapper_CoreText.h"

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteWrapper_CGPath";

/**
 * Custom IDWriteGeometrySink class, built on top of a CGMutablePath,
 * that translates callbacks from IDWriteFontFace::GetGlyphRunOutline to CGPath elements.
 *
 * Notes:
 *
 * DWrite provides negative values for y-coordinates, whereas CGPath expects positive ones
 * As such, functions in this class will invert y-coordinates when passing points from DWrite to CG
 *
 * IDWriteFontFace::GetGlyphRunOutline uses this class in a single-threaded manner (dumping the draw instructions from the font linearly)
 * As such, this class is deliberately left thread-unsafe.
 */
class __CGPathGeometrySink : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteGeometrySink> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite.__CGPathGeometrySink", TrustLevel::BaseTrust);

public:
    __CGPathGeometrySink(const CGAffineTransform* transform) {
        m_cgPath.reset(CGPathCreateMutable());
        if (transform) {
            m_transform = std::make_unique<CGAffineTransform>(*transform);
        }
    }

    void STDMETHODCALLTYPE AddBeziers(_In_ const D2D1_BEZIER_SEGMENT* beziers, unsigned int beziersCount) {
        // Some background on Bezier curves:
        // A quadratic Bezier curve is specified by 3 points:     a start point, a control point, and an end point
        // A cubic Bezier curve is instead specified by 4 points: a start point, TWO control points, and an end point
        // As a generalization, most "older" fonts specify quadratic curves, and "newer" ones can use cubic curves
        // Eg: Times New Roman's curves are all quadratic

        // CGPath has support for both orders of Bezier curve, (AddCurveToPoint for cubic, AddQuadCurveToPointFor quadratic)
        // but DWrite's GeometrySink only supports cubic Bezier curves (AddBeziers),
        // and approximates any quadratic curves in terms of a cubic curve
        // Eg: Reference platform quadratic curve:  (previous endpoint),              (512, 632),              (480, 632)
        //     DWrite approximate cubic curve:      (previous endpoint), (529, 632.666626), (501.333313, 632), (480, 632)

        // Attempting to do an approximation from cubic back to quadratic would be clumsy and introduce further approximation error,
        // So just pass all cubic Beziers through directly, including approximated ones
        for (unsigned int i = 0; i < beziersCount; ++i) {
            CGPathAddCurveToPoint(m_cgPath.get(),
                                  m_transform.get(),
                                  beziers[i].point1.x,
                                  -beziers[i].point1.y,
                                  beziers[i].point2.x,
                                  -beziers[i].point2.y,
                                  beziers[i].point3.x,
                                  -beziers[i].point3.y);
        }
    }

    void STDMETHODCALLTYPE AddLines(_In_ const D2D1_POINT_2F* points, unsigned int pointsCount) {
        // Use individual CGPathAddLineToPoint() calls here, rather than CGPathAddLines
        // CGPathAddLines does a CGPathMoveToPoint to the first point,
        // which doesn't match what DWrite expects (draw a line from the previous point)
        for (unsigned int i = 0; i < pointsCount; ++i) {
            CGPathAddLineToPoint(m_cgPath.get(), m_transform.get(), points[i].x, -points[i].y);
        }
    }

    void STDMETHODCALLTYPE BeginFigure(D2D1_POINT_2F startPoint, D2D1_FIGURE_BEGIN figureBegin) {
        if (m_figureInProgress) {
            TraceError(TAG,
                       L"IDWriteGeometrySink::BeginFigure called while a figure was currently in progress. Placing object in error state - "
                       L"future function calls will fail.");
            m_invalidState = true;
        }

        if (!m_invalidState) {
            // figureBegin is ignored for CGPath purposes -
            // filled vs hollow maps to CGPathDrawingMode, and is specified to CGContextDrawPath directly
            m_figureInProgress = true;
            CGPathMoveToPoint(m_cgPath.get(), m_transform.get(), startPoint.x, -startPoint.y);
        }
    }

    HRESULT STDMETHODCALLTYPE Close() {
        if (m_figureInProgress) {
            TraceError(TAG,
                       L"IDWriteGeometrySink::Close called while a figure was currently in progress. Placing object in error state - "
                       L"future function calls will fail.");
            m_invalidState = true;
        }

        return m_invalidState ? E_UNEXPECTED : S_OK;
    }

    void STDMETHODCALLTYPE EndFigure(D2D1_FIGURE_END figureEnd) {
        if (!m_figureInProgress) {
            TraceError(TAG,
                       L"IDWriteGeometrySink::EndFigure called while no figure was currently in progress. Placing object in error state - "
                       L"future function calls will fail.");
            m_invalidState = true;
        }

        if (!m_invalidState) {
            // figureBegin is ignored for CGPath purposes -
            // filled vs hollow maps to CGPathDrawingMode, and is specified to CGContextDrawPath directly
            m_figureInProgress = false;

            if (figureEnd) {
                // D2D1_FIGURE_END_CLOSED  = 1, close the subpath
                CGPathCloseSubpath(m_cgPath.get());
            }
            // D2D1_FIGURE_END_OPEN = 0, subpath is left open (no-op in terms of CGPath)
        }
    }

    void STDMETHODCALLTYPE SetFillMode(D2D1_FILL_MODE fillMode) {
        // No-op for CGPath purposes - CGPathDrawingMode is specified to CGContextDrawPath directly
    }

    void STDMETHODCALLTYPE SetSegmentFlags(D2D1_PATH_SEGMENT vertexFlags) {
        // No-op for CGPath purposes - CGLineJoin is specified to CGContextStrokePath directly
    }

    // Releases the class's ownership of its path when all operations are finished, returning a +1 reference (from the path's Create)
    CGPathRef ReleasePath() {
        return m_cgPath.release();
    }

private:
    woc::unique_cf<CGMutablePathRef> m_cgPath;
    std::unique_ptr<CGAffineTransform> m_transform;
    bool m_figureInProgress = false; // Keeps track of whether this class is currently between a BeginFigure and EndFigure call
    bool m_invalidState = false; // If BeginFigure and EndFigure calls are imbalanced, invalidate all future operations
};

/**
 * Returns a CGPathRef representing the specified glyph, using the specified font face, point size, and transformation matrix.
 */
CGPathRef _DWriteFontCreatePathForGlyph(const ComPtr<IDWriteFontFace>& fontFace,
                                        CGFloat pointSize,
                                        CGGlyph glyph,
                                        const CGAffineTransform* transform) {
    // Create an instance of a custom IDWriteGeometrySink backed by a CGMutablePathRef
    ComPtr<__CGPathGeometrySink> geometrySink = Make<__CGPathGeometrySink>(transform);

    // Call GetGlyphRunOutline using glyph as a C-style array of size 1
    RETURN_NULL_IF_FAILED(fontFace->GetGlyphRunOutline(pointSize, &glyph, nullptr, nullptr, 1, false, false, geometrySink.Get()));

    // Get the underlying CGMutablePathRef from the sink
    return geometrySink->ReleasePath();
}