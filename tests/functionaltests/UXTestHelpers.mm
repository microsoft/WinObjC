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

#import "UXTestHelpers.h"
#import "StringHelpers.h"

////////////////////////////////////////////////////////////////
// UX Helpers
////////////////////////////////////////////////////////////////
UIWindow* GetCurrentWindow() {
    return [[UIApplication sharedApplication] keyWindow];
}

NSString* NSStringFromPropertyValue(RTObject* rtPropertyValue) {
    // BUGBUG:8791977 - WFIPropertyValue is not publicly exposed via projections so we used a workaround
    Microsoft::WRL::ComPtr<IInspectable> inspPropVal = [rtPropertyValue comObj];
    return NSStringFromPropertyValue(inspPropVal);
}

NSString* NSStringFromPropertyValue(const Microsoft::WRL::ComPtr<IInspectable>& inspPropertyValue) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IPropertyValue> propVal;
    HRESULT hr = inspPropertyValue.As(&propVal);
    if (SUCCEEDED(hr)) {
        HSTRING str;
        auto freeHSTRING = wil::ScopeExit([&]() { WindowsDeleteString(str); });

        hr = propVal->GetString(&str);
        if (SUCCEEDED(hr)) {
            return Strings::WideToNSString<HSTRING>(str);
        }
    }

    return nil;
}