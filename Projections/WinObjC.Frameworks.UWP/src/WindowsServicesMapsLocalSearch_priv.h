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

// WindowsServicesMapsLocalSearch_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsServicesMaps_priv.h"
#include "WindowsGlobalization_priv.h"
#include "WindowsDevicesGeolocation_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderStatics> WSMLILocalLocationFinderStatics_inst();
ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalCategoriesStatics> WSMLILocalCategoriesStatics_inst();

id RTProxiedNSArray_WSMLLocalLocation_create(IInspectable* val);
id RTProxiedNSArray_WSMLLocalLocationHoursOfOperationItem_create(IInspectable* val);

@class Nullable_Double, Nullable_Int32, RTProxiedNSArray_WSMLLocalLocation, RTProxiedNSArray_WSMLLocalLocationHoursOfOperationItem;
