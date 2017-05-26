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

// WindowsUIText_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUI_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::UI::Text::ITextConstantsStatics> WUTITextConstantsStatics_inst();
ComPtr<ABI::Windows::UI::Text::IFontWeightsStatics> WUTIFontWeightsStatics_inst();
@interface WUTFontWeight (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Text::FontWeight)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Text::FontWeight*)internalStruct;
@end
inline WUTFontWeight* WUTFontWeight_create(ABI::Windows::UI::Text::FontWeight val) {
    return [WUTFontWeight createWith:val];
}
