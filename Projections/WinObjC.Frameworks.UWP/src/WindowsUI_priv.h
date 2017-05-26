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

// WindowsUI_priv.h
// Forward decls for private object generation
#pragma once

ComPtr<ABI::Windows::UI::IColorHelperStatics> WUIColorHelperStatics_inst();
ComPtr<ABI::Windows::UI::IColorsStatics> WUIColorsStatics_inst();
@interface WUColor (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Color)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Color*)internalStruct;
@end
inline WUColor* WUColor_create(ABI::Windows::UI::Color val) {
    return [WUColor createWith:val];
}
