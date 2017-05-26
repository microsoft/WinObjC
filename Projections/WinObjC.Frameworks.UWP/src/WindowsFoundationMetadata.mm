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

// WindowsFoundationMetadata.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Foundation.Metadata.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsFoundationMetadata.h"
#include "WindowsFoundationMetadata_priv.h"

@implementation WFMApiInformation

ComPtr<ABI::Windows::Foundation::Metadata::IApiInformationStatics> WFMIApiInformationStatics_inst() {
    ComPtr<ABI::Windows::Foundation::Metadata::IApiInformationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Metadata.ApiInformation").Get(), &inst));
    return inst;
}

+ (BOOL)isTypePresent:(NSString*)typeName {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsTypePresent(nsStrToHstr(typeName).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isMethodPresent:(NSString*)typeName methodName:(NSString*)methodName {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsMethodPresent(nsStrToHstr(typeName).Get(), nsStrToHstr(methodName).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isMethodPresentWithArity:(NSString*)typeName
                      methodName:(NSString*)methodName
             inputParameterCount:(unsigned int)inputParameterCount {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsMethodPresentWithArity(nsStrToHstr(typeName).Get(),
                                                          nsStrToHstr(methodName).Get(),
                                                          inputParameterCount,
                                                          &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isEventPresent:(NSString*)typeName eventName:(NSString*)eventName {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsEventPresent(nsStrToHstr(typeName).Get(), nsStrToHstr(eventName).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isPropertyPresent:(NSString*)typeName propertyName:(NSString*)propertyName {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsPropertyPresent(nsStrToHstr(typeName).Get(), nsStrToHstr(propertyName).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isReadOnlyPropertyPresent:(NSString*)typeName propertyName:(NSString*)propertyName {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->IsReadOnlyPropertyPresent(nsStrToHstr(typeName).Get(), nsStrToHstr(propertyName).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isWriteablePropertyPresent:(NSString*)typeName propertyName:(NSString*)propertyName {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->IsWriteablePropertyPresent(nsStrToHstr(typeName).Get(), nsStrToHstr(propertyName).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isEnumNamedValuePresent:(NSString*)enumTypeName valueName:(NSString*)valueName {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->IsEnumNamedValuePresent(nsStrToHstr(enumTypeName).Get(), nsStrToHstr(valueName).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isApiContractPresentByMajor:(NSString*)contractName majorVersion:(unsigned short)majorVersion {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsApiContractPresentByMajor(nsStrToHstr(contractName).Get(), majorVersion, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isApiContractPresentByMajorAndMinor:(NSString*)contractName
                               majorVersion:(unsigned short)majorVersion
                               minorVersion:(unsigned short)minorVersion {
    boolean unmarshalledReturn;
    auto _comInst = WFMIApiInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->IsApiContractPresentByMajorAndMinor(nsStrToHstr(contractName).Get(), majorVersion, minorVersion, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end
