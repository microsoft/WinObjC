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

// WindowsWebAtomPub_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsWebSyndication_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsSecurityCredentials_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsDataXmlDom_priv.h"
static ComPtr<ABI::Windows::Web::AtomPub::IAtomPubClientFactory> WWAIAtomPubClientFactory_inst();

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WWAResourceCollection_create(IInspectable* val);
id RTProxiedNSArray_WWAWorkspace_create(IInspectable* val);
id RTProxiedNSArray_WWSSyndicationCategory_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_WWSISyndicationNode_create(IInspectable* val);
id RTProxiedNSMutableArray_WWSSyndicationAttribute_create(IInspectable* val);

@class RTProxiedNSArray_NSString, RTProxiedNSArray_WWAResourceCollection, RTProxiedNSArray_WWAWorkspace,
    RTProxiedNSArray_WWSSyndicationCategory;
@class RTProxiedNSMutableArray_RTObject_WWSISyndicationNode, RTProxiedNSMutableArray_WWSSyndicationAttribute;
