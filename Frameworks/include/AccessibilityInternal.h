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

@protocol UIAccessibility;

typedef uint64_t IWAccessibilityFlags;

const uint64_t ACC_FLAG_BUTTON = (1 << 1);
const uint64_t ACC_FLAG_LINK = (1 << 2);
const uint64_t ACC_FLAG_SELECTED = (1 << 3);
const uint64_t ACC_FLAG_STATIC_TEXT = (1 << 4);

const uint64_t ACC_FLAG_UNUSED = 0;

// TODO: BK: additional accessibility info here.

struct IWAccessibilityInfo {
    IWAccessibilityFlags flags;
};

void IWUpdateAccessibility(id receiver, NSObject<UIAccessibility>* accessibilityObj);

