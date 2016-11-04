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
//*****************************************************************************/
#pragma once

#import <CoreGraphics/CoreGraphics.h>

#ifdef __cplusplus

#pragma region CFRange
bool operator==(const CFRange& lhs, const CFRange& rhs) {
    return lhs.location == rhs.location && rhs.length == rhs.length;
}

#pragma endregion

#pragma region CGPoint
bool operator==(const CGPoint& lhs, const CGPoint& rhs) {
    return lhs.x == rhs.x && rhs.y == rhs.y;
}

#pragma endregion

#pragma region CGSize
bool operator==(const CGSize& lhs, const CGSize& rhs) {
    return lhs.width == rhs.width && rhs.height == rhs.height;
}

#pragma endregion

#pragma region CGRect
bool operator==(const CGRect& lhs, const CGRect& rhs) {
    return lhs.origin == rhs.origin && rhs.size == rhs.size;
}

#pragma endregion

#endif