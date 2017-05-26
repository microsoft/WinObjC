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

// WindowsApplicationModelResourcesCore_priv.h
// Forward decls for private object generation
#pragma once

// Can't create proxy instantiator for type: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.NamedResource>>

// Can't create proxy instantiator for type: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.ResourceMap>>

#include "WindowsStorage_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics3> WARCIResourceContextStatics3_inst();
ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics> WARCIResourceContextStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics2> WARCIResourceContextStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceManagerStatics> WARCIResourceManagerStatics_inst();
@interface WARCResourceLayoutInfo (Internal)
+ (instancetype)createWith:(ABI::Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo*)internalStruct;
@end
inline WARCResourceLayoutInfo* WARCResourceLayoutInfo_create(ABI::Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo val) {
    return [WARCResourceLayoutInfo createWith:val];
}

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_RTObject_WSIStorageFile_create(IInspectable* val);
id RTProxiedIterableNSArray_WARCResourceQualifier_create(IInspectable* val);
id RTProxiedKeyValuePair_NSString_WARCNamedResource_create(IInspectable* val);
id RTProxiedKeyValuePair_NSString_WARCResourceMap_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WARCNamedResource_create(IInspectable* val);
id RTProxiedNSArray_WARCResourceCandidate_create(IInspectable* val);
id RTProxiedNSArray_WARCResourceMap_create(IInspectable* val);
id RTProxiedNSArray_WARCResourceQualifier_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WARCResourceMap_create(IInspectable* val);
id RTProxiedObservableNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_RTObject_WSIStorageFile, RTProxiedIterableNSArray_WARCResourceQualifier;
@class RTProxiedKeyValuePair_NSString_WARCNamedResource, RTProxiedKeyValuePair_NSString_WARCResourceMap, RTProxiedNSArray_NSString,
    RTProxiedNSArray_WARCNamedResource;
@class RTProxiedNSArray_WARCResourceCandidate, RTProxiedNSArray_WARCResourceMap, RTProxiedNSArray_WARCResourceQualifier,
    RTProxiedNSDictionary_NSString_WARCResourceMap;
@class RTProxiedObservableNSMutableDictionary_NSString_NSString;
