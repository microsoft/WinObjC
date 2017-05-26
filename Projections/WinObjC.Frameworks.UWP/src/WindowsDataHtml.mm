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

// WindowsDataHtml.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Data.Html.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDataHtml.h"
#include "WindowsDataHtml_priv.h"

@implementation WDHHtmlUtilities

ComPtr<ABI::Windows::Data::Html::IHtmlUtilities> WDHIHtmlUtilities_inst() {
    ComPtr<ABI::Windows::Data::Html::IHtmlUtilities> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Html.HtmlUtilities").Get(), &inst));
    return inst;
}

+ (NSString*)convertToText:(NSString*)html {
    HSTRING unmarshalledReturn;
    auto _comInst = WDHIHtmlUtilities_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertToText(nsStrToHstr(html).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end
