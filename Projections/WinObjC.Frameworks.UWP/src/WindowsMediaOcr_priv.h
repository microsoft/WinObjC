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

// WindowsMediaOcr_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsImaging_priv.h"
#include "WindowsGlobalization_priv.h"
ComPtr<ABI::Windows::Media::Ocr::IOcrEngineStatics> WMOIOcrEngineStatics_inst();

id RTProxiedNSArray_WGLanguage_create(IInspectable* val);
id RTProxiedNSArray_WMOOcrLine_create(IInspectable* val);
id RTProxiedNSArray_WMOOcrWord_create(IInspectable* val);

@class Nullable_Double, RTProxiedNSArray_WGLanguage, RTProxiedNSArray_WMOOcrLine, RTProxiedNSArray_WMOOcrWord;
