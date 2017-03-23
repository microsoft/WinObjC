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

#include <unknwn.h>
#include "Social.Xaml.Export.h"

struct IInspectable;

class __declspec(novtable) __declspec(uuid("5CF22688-7892-4CE0-ACA4-3EA01A0EDDDB")) ShareSheetControl : public IUnknown {
public:
    virtual ~ShareSheetControl() = default;

    virtual void addLink(const wchar_t* url) = 0;
    virtual void addImage(IInspectable* image) = 0;
    virtual void show() = 0;
};

SOCIAL_XAML_EXPORT ShareSheetControl* XamlCreateShareSheet(const wchar_t* token);
