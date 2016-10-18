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

#include <COMIncludes.h>
#import <wrl/client.h>
#import <D2d1.h>
#include <COMIncludes_End.h>

#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGBase.h>

Microsoft::WRL::ComPtr<ID2D1Factory> _GetD2DFactoryInstance();

static inline D2D_POINT_2F _CGPointToD2D_F(CGPoint point) {
    return { point.x, point.y };
}

static inline CGRect _D2DRectToCGRect(D2D1_RECT_F rect) {
    CGFloat x = rect.left;
    CGFloat y = rect.top;
    CGFloat width = rect.right - x;
    CGFloat height = rect.bottom - y;

    return CGRectMake(x, y, width, height);
}