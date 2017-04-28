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

#include <CoreGraphics/CGColor.h>

struct __CGColorQuad {
    CGFloat r;
    CGFloat g;
    CGFloat b;
    CGFloat a;

    bool operator==(const __CGColorQuad& other) const {
        return (r == other.r) && (g == other.g) && (b == other.b) && (a == other.a);
    }

    void Clear() {
        r = g = b = a = 0.0f;
    }

    void SetColorComponents(CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha) {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }
};
