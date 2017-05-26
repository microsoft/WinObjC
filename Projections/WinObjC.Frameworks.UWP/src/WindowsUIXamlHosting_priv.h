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

// WindowsUIXamlHosting_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXamlControlsPrimitives_priv.h"
#include "WindowsUIComposition_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsUIXamlControls_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> WUXHIElementCompositionPreviewStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics> WUXHIXamlUIPresenterStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics2> WUXHIXamlUIPresenterStatics2_inst();
