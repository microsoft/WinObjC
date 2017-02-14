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

#include "DrawingTest.h"

DRAW_TEST_F(CGContext, Shadow, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);
    CGContextSetLineWidth(context, 5);

    CGContextSetShadow(context, CGSize{ 10.f, 10.f }, 1.0);

    CGPoint center = _CGRectGetCenter(bounds);
    CGRect rect = _CGRectCenteredOnPoint({ 150, 150 }, center);

    CGContextStrokeRect(context, rect);
}

DRAW_TEST_F(CGContext, ShadowWithRotatedCTM, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);
    CGContextSetLineWidth(context, 5);

    CGContextSetShadow(context, CGSize{ 10.f, 10.f }, 1.0);

    CGPoint center = _CGRectGetCenter(bounds);
    CGRect rect = _CGRectCenteredOnPoint({ 150, 150 }, center);
    CGPoint rectCenter = _CGRectGetCenter(rect);

    CGContextTranslateCTM(context, rectCenter.x, rectCenter.y);
    CGContextRotateCTM(context, 15.f * M_PI / 180.f);
    CGContextTranslateCTM(context, -rectCenter.x, -rectCenter.y);

    CGContextStrokeRect(context, rect);
}

DRAW_TEST_F(CGContext, ShadowOverlap, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);
    CGContextSetLineWidth(context, 5);

    CGContextSetShadow(context, CGSize{ 10.f, 10.f }, 1.0);

    CGPoint center = _CGRectGetCenter(bounds);
    CGRect rect = _CGRectCenteredOnPoint({ 150, 150 }, center);
    CGRect rect2 = _CGRectCenteredOnPoint({ 150, 150 }, rect.origin);

    CGContextStrokeRect(context, rect);
    CGContextStrokeRect(context, rect2);
}

DRAW_TEST_F(CGContext, ShadowEnabledInMiddle, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);
    CGContextSetLineWidth(context, 5);

    CGPoint center = _CGRectGetCenter(bounds);
    CGRect rect = _CGRectCenteredOnPoint({ 150, 150 }, center);
    CGRect rect2 = _CGRectCenteredOnPoint({ 150, 150 }, rect.origin);

    CGContextStrokeRect(context, rect);
    CGContextSetShadow(context, CGSize{ 10.f, 10.f }, 1.0);
    CGContextStrokeRect(context, rect2);
}

DRAW_TEST_F(CGContext, ShadowDisabledInMiddle, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);
    CGContextSetLineWidth(context, 5);

    CGPoint center = _CGRectGetCenter(bounds);
    CGRect rect = _CGRectCenteredOnPoint({ 150, 150 }, center);
    CGRect rect2 = _CGRectCenteredOnPoint({ 150, 150 }, rect.origin);

    CGContextSetShadow(context, CGSize{ 10.f, 10.f }, 1.0);
    CGContextStrokeRect(context, rect);
    CGContextSetShadow(context, CGSize{ 0, 0 }, 0.0);
    CGContextStrokeRect(context, rect2);
}
