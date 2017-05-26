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

// WindowsFoundationCollections.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Foundation.Collections.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundationCollections_priv.h"

@implementation WFCIVectorChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Collections::IVectorChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFCCollectionChange)collectionChange {
    ABI::Windows::Foundation::Collections::CollectionChange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Collections::IVectorChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CollectionChange(&unmarshalledReturn));
    return (WFCCollectionChange)unmarshalledReturn;
}

- (unsigned int)index {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Collections::IVectorChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Index(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WFCIPropertySet

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WFCPropertySet {
    RTObservableMapObjFull<HSTRING,
                           HSTRING,
                           IInspectable*,
                           IInspectable*,
                           NSString,
                           RTObject,
                           IMap<HSTRING, IInspectable*>,
                           dummyObjCCreator,
                           dummyObjCCreator,
                           dummyWRLCreator,
                           dummyWRLCreator>
        _map;
}
INTEROP_IMPL_OBSMAP_FULL(self.comObj,
                         RTProxiedObservableNSMutableDictionary_NSString_RTObject,
                         HSTRING,
                         HSTRING,
                         IInspectable*,
                         IInspectable*,
                         NSString,
                         RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Foundation.Collections.PropertySet").Get(), &out));
    return [_createRtProxy<WFCPropertySet>(out.Get()) retain];
}

@end

@implementation WFCValueSet {
    RTObservableMapObjFull<HSTRING,
                           HSTRING,
                           IInspectable*,
                           IInspectable*,
                           NSString,
                           RTObject,
                           IMap<HSTRING, IInspectable*>,
                           dummyObjCCreator,
                           dummyObjCCreator,
                           dummyWRLCreator,
                           dummyWRLCreator>
        _map;
}
INTEROP_IMPL_OBSMAP_FULL(self.comObj,
                         RTProxiedObservableNSMutableDictionary_NSString_RTObject,
                         HSTRING,
                         HSTRING,
                         IInspectable*,
                         IInspectable*,
                         NSString,
                         RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Foundation.Collections.ValueSet").Get(), &out));
    return [_createRtProxy<WFCValueSet>(out.Get()) retain];
}

@end

@implementation WFCStringMap {
    RTMapObj<HSTRING,
             HSTRING,
             HSTRING,
             HSTRING,
             NSString,
             NSString,
             IMap<HSTRING, HSTRING>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj, RTProxiedNSMutableDictionary_NSString_NSString, HSTRING, HSTRING, HSTRING, HSTRING, NSString, NSString)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IMap<HSTRING, HSTRING>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Foundation.Collections.StringMap").Get(), &out));
    return [_createRtProxy<WFCStringMap>(out.Get()) retain];
}

@end
