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

// WindowsUIXamlInterop.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Interop.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlInterop.h"
#include "WindowsUIXamlInterop_priv.h"

@implementation WUXIIBindableIterable

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableIterable> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXIIBindableIterator>*)first {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableIterator> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableIterable>(self);
    THROW_NS_IF_FAILED(_comInst->First(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIIBindableIterator>(unmarshalledReturn.Get());
}

@end

@implementation WUXIIBindableVector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableVector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)getAt:(unsigned int)index {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->GetAt(index, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (unsigned int)size {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WUXIIBindableVectorView>*)getView {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableVectorView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->GetView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIIBindableVectorView>(unmarshalledReturn.Get());
}

- (BOOL)indexOf:(RTObject*)value index:(unsigned int*)index {
    unsigned int indexOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->IndexOf([value comObj].Get(), &indexOutUnmarshaled, &unmarshalledReturn));
    *index = indexOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)setAt:(unsigned int)index value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->SetAt(index, [value comObj].Get()));
}

- (void)insertAt:(unsigned int)index value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->InsertAt(index, [value comObj].Get()));
}

- (void)removeAt:(unsigned int)index {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAt(index));
}

- (void)append:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->Append([value comObj].Get()));
}

- (void)removeAtEnd {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAtEnd());
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (RTObject<WUXIIBindableIterator>*)first {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableIterator> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableIterable>(self);
    THROW_NS_IF_FAILED(_comInst->First(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIIBindableIterator>(unmarshalledReturn.Get());
}

@end

@implementation WUXIIBindableObservableVector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableObservableVector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addVectorChangedEvent:(WUXIBindableVectorChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableObservableVector>(self);
    THROW_NS_IF_FAILED(_comInst->add_VectorChanged(Make<WUXIBindableVectorChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVectorChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableObservableVector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VectorChanged(token));
}

- (RTObject*)getAt:(unsigned int)index {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->GetAt(index, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (unsigned int)size {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WUXIIBindableVectorView>*)getView {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableVectorView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->GetView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIIBindableVectorView>(unmarshalledReturn.Get());
}

- (BOOL)indexOf:(RTObject*)value index:(unsigned int*)index {
    unsigned int indexOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->IndexOf([value comObj].Get(), &indexOutUnmarshaled, &unmarshalledReturn));
    *index = indexOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)setAt:(unsigned int)index value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->SetAt(index, [value comObj].Get()));
}

- (void)insertAt:(unsigned int)index value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->InsertAt(index, [value comObj].Get()));
}

- (void)removeAt:(unsigned int)index {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAt(index));
}

- (void)append:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->Append([value comObj].Get()));
}

- (void)removeAtEnd {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAtEnd());
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (RTObject<WUXIIBindableIterator>*)first {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableIterator> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableIterable>(self);
    THROW_NS_IF_FAILED(_comInst->First(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIIBindableIterator>(unmarshalledReturn.Get());
}

@end

@implementation WUXIIBindableVectorView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableVectorView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)getAt:(unsigned int)index {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVectorView>(self);
    THROW_NS_IF_FAILED(_comInst->GetAt(index, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (unsigned int)size {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVectorView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)indexOf:(RTObject*)value index:(unsigned int*)index {
    unsigned int indexOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableVectorView>(self);
    THROW_NS_IF_FAILED(_comInst->IndexOf([value comObj].Get(), &indexOutUnmarshaled, &unmarshalledReturn));
    *index = indexOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WUXIIBindableIterator>*)first {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableIterator> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableIterable>(self);
    THROW_NS_IF_FAILED(_comInst->First(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIIBindableIterator>(unmarshalledReturn.Get());
}

@end

@implementation WUXIIBindableIterator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableIterator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)current {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableIterator>(self);
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)hasCurrent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableIterator>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasCurrent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)moveNext {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::IBindableIterator>(self);
    THROW_NS_IF_FAILED(_comInst->MoveNext(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXIINotifyCollectionChanged

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChanged> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addCollectionChangedEvent:(WUXINotifyCollectionChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChanged>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_CollectionChanged(Make<WUXINotifyCollectionChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCollectionChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChanged>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CollectionChanged(token));
}

@end

@implementation WUXINotifyCollectionChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXINotifyCollectionChangedEventArgs*)makeInstanceWithAllParameters:(WUXINotifyCollectionChangedAction)action
                                                              newItems:(RTObject<WUXIIBindableVector>*)newItems
                                                              oldItems:(RTObject<WUXIIBindableVector>*)oldItems
                                                              newIndex:(int)newIndex
                                                              oldIndex:(int)oldIndex {
    ComPtr<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgsFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Interop.NotifyCollectionChangedEventArgs").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithAllParameters((ABI::Windows::UI::Xaml::Interop::NotifyCollectionChangedAction)action,
                                                 _getRtInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(newItems).Get(),
                                                 _getRtInterface<ABI::Windows::UI::Xaml::Interop::IBindableVector>(oldItems).Get(),
                                                 newIndex,
                                                 oldIndex,
                                                 outer.Get(),
                                                 &inner,
                                                 &instance));
    WUXINotifyCollectionChangedEventArgs* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (WUXINotifyCollectionChangedAction)action {
    ABI::Windows::UI::Xaml::Interop::NotifyCollectionChangedAction unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Action(&unmarshalledReturn));
    return (WUXINotifyCollectionChangedAction)unmarshalledReturn;
}

- (RTObject<WUXIIBindableVector>*)newItems __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableVector> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewItems(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIIBindableVector>(unmarshalledReturn.Get());
}

- (RTObject<WUXIIBindableVector>*)oldItems {
    ComPtr<ABI::Windows::UI::Xaml::Interop::IBindableVector> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldItems(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIIBindableVector>(unmarshalledReturn.Get());
}

- (int)newStartingIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewStartingIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)oldStartingIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldStartingIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXITypeName {
    ABI::Windows::UI::Xaml::Interop::TypeName structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Interop::TypeName)s {
    WUXITypeName* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Interop::TypeName*)internalStruct {
    return &structVal;
}
- (NSString*)name {
    return hstrToNSStr(structVal.Name);
}
- (void)setName:(NSString*)val {
    structVal.Name = nsStrToHstr(val).Detach();
}
- (WUXITypeKind)kind {
    return (WUXITypeKind)structVal.Kind;
}
- (void)setKind:(WUXITypeKind)val {
    structVal.Kind = (ABI::Windows::UI::Xaml::Interop::TypeKind)val;
}
@end
