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

// WindowsApplicationModelResourcesCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Resources.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelResourcesCore.h"
#include "WindowsApplicationModelResourcesCore_priv.h"

@implementation WARCResourceMap {
    RTMapViewObj<HSTRING,
                 HSTRING,
                 ABI::Windows::ApplicationModel::Resources::Core::NamedResource*,
                 ABI::Windows::ApplicationModel::Resources::Core::INamedResource*,
                 NSString,
                 WARCNamedResource,
                 IMapView<HSTRING, ABI::Windows::ApplicationModel::Resources::Core::NamedResource*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAPVIEW(self.comObj,
                     RTProxiedNSDictionary_NSString_WARCNamedResource,
                     HSTRING,
                     HSTRING,
                     ABI::Windows::ApplicationModel::Resources::Core::INamedResource*,
                     ABI::Windows::ApplicationModel::Resources::Core::NamedResource*,
                     NSString,
                     WARCNamedResource)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceMap> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceMap>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WARCResourceCandidate*)getValue:(NSString*)resource {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceMap>(self);
    THROW_NS_IF_FAILED(_comInst->GetValue(nsStrToHstr(resource).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceCandidate>(unmarshalledReturn.Get());
}

- (WARCResourceCandidate*)getValueForContext:(NSString*)resource context:(WARCResourceContext*)context {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceMap>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetValueForContext(nsStrToHstr(resource).Get(),
                                     _getRtInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(context).Get(),
                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceCandidate>(unmarshalledReturn.Get());
}

- (WARCResourceMap*)getSubtree:(NSString*)reference {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceMap>(self);
    THROW_NS_IF_FAILED(_comInst->GetSubtree(nsStrToHstr(reference).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceMap>(unmarshalledReturn.Get());
}

@end

@implementation WARCResourceContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Resources.Core.ResourceContext").Get(),
                                              &out));
    return [_createRtProxy<WARCResourceContext>(out.Get()) retain];
}

ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics3> WARCIResourceContextStatics3_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Resources.Core.ResourceContext").Get(), &inst));
    return inst;
}

+ (void)setGlobalQualifierValueWithPersistence:(NSString*)key
                                         value:(NSString*)value
                                   persistence:(WARCResourceQualifierPersistence)persistence {
    auto _comInst = WARCIResourceContextStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetGlobalQualifierValueWithPersistence(nsStrToHstr(key).Get(),
                                                         nsStrToHstr(value).Get(),
                                                         (ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifierPersistence)
                                                             persistence));
}

ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics> WARCIResourceContextStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Resources.Core.ResourceContext").Get(), &inst));
    return inst;
}

+ (WARCResourceContext*)createMatchingContext:(id<NSFastEnumeration> /* WARCResourceQualifier* */)result {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext> unmarshalledReturn;
    auto _comInst = WARCIResourceContextStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMatchingContext(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*,
            ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier*>>::type>*>(
            ConvertToIterable<
                WARCResourceQualifier,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*,
                                                                  ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier*>>(
                result)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceContext>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics2> WARCIResourceContextStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContextStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Resources.Core.ResourceContext").Get(), &inst));
    return inst;
}

+ (WARCResourceContext*)getForCurrentView {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext> unmarshalledReturn;
    auto _comInst = WARCIResourceContextStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceContext>(unmarshalledReturn.Get());
}

+ (void)setGlobalQualifierValue:(NSString*)key value:(NSString*)value {
    auto _comInst = WARCIResourceContextStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->SetGlobalQualifierValue(nsStrToHstr(key).Get(), nsStrToHstr(value).Get()));
}

+ (void)resetGlobalQualifierValues {
    auto _comInst = WARCIResourceContextStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->ResetGlobalQualifierValues());
}

+ (void)resetGlobalQualifierValuesForSpecifiedQualifiers:(id<NSFastEnumeration> /* NSString * */)qualifierNames {
    auto _comInst = WARCIResourceContextStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->ResetGlobalQualifierValuesForSpecifiedQualifiers(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(qualifierNames).Get())));
}

+ (WARCResourceContext*)getForViewIndependentUse {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext> unmarshalledReturn;
    auto _comInst = WARCIResourceContextStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForViewIndependentUse(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceContext>(unmarshalledReturn.Get());
}

- (NSMutableDictionary<RTObservableCollection>* /* NSString *, NSString * */)qualifierValues {
    ComPtr<IObservableMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_QualifierValues(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)resetQualifierValues:(id<NSFastEnumeration> /* NSString * */)qualifierNames {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->ResetQualifierValues(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(qualifierNames).Get())));
}

- (void)overrideToMatch:(id<NSFastEnumeration> /* WARCResourceQualifier* */)result {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(self);
    THROW_NS_IF_FAILED(_comInst->OverrideToMatch(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*,
            ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier*>>::type>*>(
            ConvertToIterable<
                WARCResourceQualifier,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*,
                                                                  ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier*>>(
                result)
                .Get())));
}

- (WARCResourceContext*)clone {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceContext>(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (void)setLanguages:(NSArray* /* NSString * */)languages {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Languages(static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToVectorView<NSString, HSTRING>(languages).Get())));
}

@end

@implementation WARCNamedResource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::INamedResource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::INamedResource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSArray* /* WARCResourceCandidate* */)candidates {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::INamedResource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Candidates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WARCResourceCandidate_create(unmarshalledReturn.Get());
}

- (WARCResourceCandidate*)resolve {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::INamedResource>(self);
    THROW_NS_IF_FAILED(_comInst->Resolve(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceCandidate>(unmarshalledReturn.Get());
}

- (WARCResourceCandidate*)resolveForContext:(WARCResourceContext*)resourceContext {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::INamedResource>(self);
    THROW_NS_IF_FAILED(_comInst->ResolveForContext(
        _getRtInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(resourceContext).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceCandidate>(unmarshalledReturn.Get());
}

- (NSArray* /* WARCResourceCandidate* */)resolveAll {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::INamedResource>(self);
    THROW_NS_IF_FAILED(_comInst->ResolveAll(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WARCResourceCandidate_create(unmarshalledReturn.Get());
}

- (NSArray* /* WARCResourceCandidate* */)resolveAllForContext:(WARCResourceContext*)resourceContext {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::INamedResource>(self);
    THROW_NS_IF_FAILED(_comInst->ResolveAllForContext(
        _getRtInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext>(resourceContext).Get(),
        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WARCResourceCandidate_create(unmarshalledReturn.Get());
}

@end

@implementation WARCResourceManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceManagerStatics> WARCIResourceManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Resources.Core.ResourceManager").Get(), &inst));
    return inst;
}

+ (WARCResourceManager*)current {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager> unmarshalledReturn;
    auto _comInst = WARCIResourceManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceManager>(unmarshalledReturn.Get());
}

+ (BOOL)isResourceReference:(NSString*)resourceReference {
    boolean unmarshalledReturn;
    auto _comInst = WARCIResourceManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsResourceReference(nsStrToHstr(resourceReference).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WARCResourceMap*)mainResourceMap {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceMap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_MainResourceMap(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceMap>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, WARCResourceMap* */)allResourceMaps {
    ComPtr<IMapView<HSTRING, ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllResourceMaps(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WARCResourceMap_create(unmarshalledReturn.Get());
}

- (WARCResourceContext*)defaultContext {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceContext> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultContext(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARCResourceContext>(unmarshalledReturn.Get());
}

- (void)loadPriFiles:(id<NSFastEnumeration> /* RTObject<WSIStorageFile>* */)files {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->LoadPriFiles(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                   ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::IStorageFile*,
                                                                                     ABI::Windows::Storage::IStorageFile*>>::type>*>(
            ConvertToIterable<RTObject<WSIStorageFile>,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::IStorageFile*,
                                                                                ABI::Windows::Storage::IStorageFile*>>(files)
                .Get())));
}

- (void)unloadPriFiles:(id<NSFastEnumeration> /* RTObject<WSIStorageFile>* */)files {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->UnloadPriFiles(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                     ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::IStorageFile*,
                                                                                       ABI::Windows::Storage::IStorageFile*>>::type>*>(
            ConvertToIterable<RTObject<WSIStorageFile>,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::IStorageFile*,
                                                                                ABI::Windows::Storage::IStorageFile*>>(files)
                .Get())));
}

- (NSArray* /* WARCNamedResource* */)getAllNamedResourcesForPackage:(NSString*)packageName
                                                 resourceLayoutInfo:(WARCResourceLayoutInfo*)resourceLayoutInfo {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::NamedResource*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAllNamedResourcesForPackage(nsStrToHstr(packageName).Get(),
                                                                *[resourceLayoutInfo internalStruct],
                                                                unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WARCNamedResource_create(unmarshalledReturn.Get());
}

- (NSArray* /* WARCResourceMap* */)getAllSubtreesForPackage:(NSString*)packageName
                                         resourceLayoutInfo:(WARCResourceLayoutInfo*)resourceLayoutInfo {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceManager2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAllSubtreesForPackage(nsStrToHstr(packageName).Get(),
                                                          *[resourceLayoutInfo internalStruct],
                                                          unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WARCResourceMap_create(unmarshalledReturn.Get());
}

@end

@implementation WARCResourceQualifier

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)qualifierName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_QualifierName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)qualifierValue {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_QualifierValue(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isDefault {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDefault(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isMatch {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMatch(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)score {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier>(self);
    THROW_NS_IF_FAILED(_comInst->get_Score(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WARCResourceCandidate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WARCResourceQualifier* */)qualifiers {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Qualifiers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WARCResourceQualifier_create(unmarshalledReturn.Get());
}

- (BOOL)isMatch {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMatch(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isMatchAsDefault {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMatchAsDefault(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDefault {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDefault(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)valueAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValueAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)getValueAsFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->GetValueAsFileAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSString*)getQualifierValue:(NSString*)qualifierName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate>(self);
    THROW_NS_IF_FAILED(_comInst->GetQualifierValue(nsStrToHstr(qualifierName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)getValueAsStreamAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate2>(self);
    THROW_NS_IF_FAILED(_comInst->GetValueAsStreamAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WARCResourceMapIterator

// Failed to get type for default interface: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.NamedResource>>
// Could not find base class
// Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.NamedResource>>
// type information
@end

@implementation WARCResourceMapMapView {
    RTMapViewObj<HSTRING,
                 HSTRING,
                 ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*,
                 ABI::Windows::ApplicationModel::Resources::Core::IResourceMap*,
                 NSString,
                 WARCResourceMap,
                 IMapView<HSTRING, ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAPVIEW(self.comObj,
                     RTProxiedNSDictionary_NSString_WARCResourceMap,
                     HSTRING,
                     HSTRING,
                     ABI::Windows::ApplicationModel::Resources::Core::IResourceMap*,
                     ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*,
                     NSString,
                     WARCResourceMap)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IMapView<HSTRING, ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WARCResourceMapMapViewIterator

// Failed to get type for default interface: Can't marshal
// Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.ResourceMap>>
// Could not find base class
// Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.ResourceMap>>
// type information
@end

@implementation WARCResourceQualifierObservableMap {
    RTObservableMapObjFull<HSTRING,
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
INTEROP_IMPL_OBSMAP_FULL(
    self.comObj, RTProxiedObservableNSMutableDictionary_NSString_NSString, HSTRING, HSTRING, HSTRING, HSTRING, NSString, NSString)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IObservableMap<HSTRING, HSTRING>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WARCResourceQualifierMapView {
    RTMapViewObj<HSTRING,
                 HSTRING,
                 HSTRING,
                 HSTRING,
                 NSString,
                 NSString,
                 IMapView<HSTRING, HSTRING>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAPVIEW(self.comObj, RTProxiedNSDictionary_NSString_NSString, HSTRING, HSTRING, HSTRING, HSTRING, NSString, NSString)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IMapView<HSTRING, HSTRING>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WARCResourceQualifierVectorView {
    RTArrayObj<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier*,
               IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*>,
               WARCResourceQualifier,
               ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             WARCResourceQualifier,
                             ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier*,
                             ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WARCResourceCandidateVectorView {
    RTArrayObj<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate*,
               IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*>,
               WARCResourceCandidate,
               ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             WARCResourceCandidate,
                             ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate*,
                             ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WARCResourceContextLanguagesVectorView {
    RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator> _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj, NSString, HSTRING, HSTRING)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<HSTRING>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WARCResourceLayoutInfo {
    ABI::Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo)s {
    WARCResourceLayoutInfo* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo*)internalStruct {
    return &structVal;
}
- (unsigned int)majorVersion {
    return structVal.MajorVersion;
}
- (void)setMajorVersion:(unsigned int)val {
    structVal.MajorVersion = val;
}
- (unsigned int)minorVersion {
    return structVal.MinorVersion;
}
- (void)setMinorVersion:(unsigned int)val {
    structVal.MinorVersion = val;
}
- (unsigned int)resourceSubtreeCount {
    return structVal.ResourceSubtreeCount;
}
- (void)setResourceSubtreeCount:(unsigned int)val {
    structVal.ResourceSubtreeCount = val;
}
- (unsigned int)namedResourceCount {
    return structVal.NamedResourceCount;
}
- (void)setNamedResourceCount:(unsigned int)val {
    structVal.NamedResourceCount = val;
}
- (int)checksum {
    return structVal.Checksum;
}
- (void)setChecksum:(int)val {
    structVal.Checksum = val;
}
@end
id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_RTObject_WSIStorageFile_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Storage::IStorageFile*>,
                                                 RTIterableObj<ABI::Windows::Storage::IStorageFile*,
                                                               IIterable<ABI::Windows::Storage::IStorageFile*>,
                                                               RTObject<WSIStorageFile>,
                                                               ABI::Windows::Storage::IStorageFile*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WARCResourceQualifier_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*>,
                                RTIterableObj<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier*,
                                              IIterable<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*>,
                                              WARCResourceQualifier,
                                              ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedKeyValuePair_NSString_WARCNamedResource_create(IInspectable* val) {
    std::unique_ptr<KeyValuePairAdapter> adapter =
        std::make_unique<KeyValuePairAdapterObj<RTKeyValuePairObj<HSTRING,
                                                                  HSTRING,
                                                                  ABI::Windows::ApplicationModel::Resources::Core::INamedResource*,
                                                                  ABI::Windows::ApplicationModel::Resources::Core::NamedResource*,
                                                                  NSString,
                                                                  WARCNamedResource,
                                                                  dummyObjCCreator,
                                                                  dummyObjCCreator>>>();
    return _createRtProxyWithAdapter<RTProxiedKeyValuePair, KeyValuePairAdapter>(val, std::move(adapter));
    ;
}

id RTProxiedKeyValuePair_NSString_WARCResourceMap_create(IInspectable* val) {
    std::unique_ptr<KeyValuePairAdapter> adapter =
        std::make_unique<KeyValuePairAdapterObj<RTKeyValuePairObj<HSTRING,
                                                                  HSTRING,
                                                                  ABI::Windows::ApplicationModel::Resources::Core::IResourceMap*,
                                                                  ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*,
                                                                  NSString,
                                                                  WARCResourceMap,
                                                                  dummyObjCCreator,
                                                                  dummyObjCCreator>>>();
    return _createRtProxyWithAdapter<RTProxiedKeyValuePair, KeyValuePairAdapter>(val, std::move(adapter));
    ;
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WARCNamedResource_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::NamedResource*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Resources::Core::INamedResource*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Resources::Core::NamedResource*>,
                                                    WARCNamedResource,
                                                    ABI::Windows::ApplicationModel::Resources::Core::NamedResource*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WARCResourceCandidate_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Resources::Core::IResourceCandidate*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*>,
                                                    WARCResourceCandidate,
                                                    ABI::Windows::ApplicationModel::Resources::Core::ResourceCandidate*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WARCResourceMap_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Resources::Core::IResourceMap*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>,
                                                    WARCResourceMap,
                                                    ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WARCResourceQualifier_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Resources::Core::IResourceQualifier*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*>,
                                                    WARCResourceQualifier,
                                                    ABI::Windows::ApplicationModel::Resources::Core::ResourceQualifier*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WARCResourceMap_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*,
                     ABI::Windows::ApplicationModel::Resources::Core::IResourceMap*,
                     NSString,
                     WARCResourceMap,
                     IMapView<HSTRING, ABI::Windows::ApplicationModel::Resources::Core::ResourceMap*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedObservableNSMutableDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<ObservableDictionaryAdapter> adapter = std::make_unique<
        ObservableDictionaryAdapterObj<IObservableMap<HSTRING, HSTRING>,
                                       DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                                       RTObservableMapObj<HSTRING,
                                                          HSTRING,
                                                          HSTRING,
                                                          HSTRING,
                                                          NSString,
                                                          NSString,
                                                          IMap<HSTRING, HSTRING>,
                                                          dummyObjCCreator,
                                                          dummyObjCCreator,
                                                          dummyWRLCreator,
                                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedObservableNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
