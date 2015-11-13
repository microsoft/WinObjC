//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsUIXamlMarkup.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXMXamlReader, WUXMXamlBinaryWriter;
@class WUXMXmlnsDefinition, WUXMXamlBinaryWriterErrorInformation;
@protocol WUXMIXamlReader
, WUXMIXamlReaderStatics, WUXMIComponentConnector, WUXMIXamlType, WUXMIXamlMember, WUXMIXamlMetadataProvider, WUXMIXamlBinaryWriter,
    WUXMIXamlBinaryWriterStatics;

#include "WindowsUIXamlInterop.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Markup.XmlnsDefinition
WINRT_EXPORT
@interface WUXMXmlnsDefinition : NSObject
+ (instancetype) new;
@property (copy) NSString* xmlNamespace;
@property (copy) NSString* Namespace;
@end

// [struct] Windows.UI.Xaml.Markup.XamlBinaryWriterErrorInformation
WINRT_EXPORT
@interface WUXMXamlBinaryWriterErrorInformation : NSObject
+ (instancetype) new;
@property unsigned inputStreamIndex;
@property unsigned lineNumber;
@property unsigned linePosition;
@end

// Windows.UI.Xaml.Markup.IComponentConnector
#ifndef __WUXMIComponentConnector_DEFINED__
#define __WUXMIComponentConnector_DEFINED__

@protocol WUXMIComponentConnector
- (void)connect:(int)connectionId target:(RTObject*)target;
@end

#endif // __WUXMIComponentConnector_DEFINED__

// Windows.UI.Xaml.Markup.IXamlType
#ifndef __WUXMIXamlType_DEFINED__
#define __WUXMIXamlType_DEFINED__

@protocol WUXMIXamlType
@property (readonly) RTObject<WUXMIXamlType>* baseType;
@property (readonly) RTObject<WUXMIXamlMember>* contentProperty;
@property (readonly) NSString* fullName;
@property (readonly) BOOL isArray;
@property (readonly) BOOL isBindable;
@property (readonly) BOOL isCollection;
@property (readonly) BOOL isConstructible;
@property (readonly) BOOL isDictionary;
@property (readonly) BOOL isMarkupExtension;
@property (readonly) RTObject<WUXMIXamlType>* itemType;
@property (readonly) RTObject<WUXMIXamlType>* keyType;
@property (readonly) WUXITypeName* underlyingType;
- (RTObject*)activateInstance;
- (RTObject*)createFromString:(NSString*)value;
- (RTObject<WUXMIXamlMember>*)getMember:(NSString*)name;
- (void)addToVector:(RTObject*)instance value:(RTObject*)value;
- (void)addToMap:(RTObject*)instance key:(RTObject*)key value:(RTObject*)value;
- (void)runInitializer;
@end

#endif // __WUXMIXamlType_DEFINED__

// Windows.UI.Xaml.Markup.IXamlMember
#ifndef __WUXMIXamlMember_DEFINED__
#define __WUXMIXamlMember_DEFINED__

@protocol WUXMIXamlMember
@property (readonly) BOOL isAttachable;
@property (readonly) BOOL isDependencyProperty;
@property (readonly) BOOL isReadOnly;
@property (readonly) NSString* name;
@property (readonly) RTObject<WUXMIXamlType>* targetType;
@property (readonly) RTObject<WUXMIXamlType>* type;
- (RTObject*)getValue:(RTObject*)instance;
- (void)setValue:(RTObject*)instance value:(RTObject*)value;
@end

#endif // __WUXMIXamlMember_DEFINED__

// Windows.UI.Xaml.Markup.IXamlMetadataProvider
#ifndef __WUXMIXamlMetadataProvider_DEFINED__
#define __WUXMIXamlMetadataProvider_DEFINED__

@protocol WUXMIXamlMetadataProvider
- (RTObject<WUXMIXamlType>*)getXamlType:(WUXITypeName*)type;
- (RTObject<WUXMIXamlType>*)getXamlTypeByFullName:(NSString*)fullName;
- (id<NSFastEnumeration> /*WUXMXmlnsDefinition*/)getXmlnsDefinitions;
@end

#endif // __WUXMIXamlMetadataProvider_DEFINED__

// Windows.UI.Xaml.Markup.XamlReader
#ifndef __WUXMXamlReader_DEFINED__
#define __WUXMXamlReader_DEFINED__

WINRT_EXPORT
@interface WUXMXamlReader : RTObject
+ (RTObject*)load:(NSString*)xaml;
+ (RTObject*)loadWithInitialTemplateValidation:(NSString*)xaml;
@end

#endif // __WUXMXamlReader_DEFINED__

// Windows.UI.Xaml.Markup.XamlBinaryWriter
#ifndef __WUXMXamlBinaryWriter_DEFINED__
#define __WUXMXamlBinaryWriter_DEFINED__

WINRT_EXPORT
@interface WUXMXamlBinaryWriter : RTObject
+ (WUXMXamlBinaryWriterErrorInformation*)write:(id<NSFastEnumeration> /*WSSIRandomAccessStream*/)inputStreams
                                 outputStreams:(id<NSFastEnumeration> /*WSSIRandomAccessStream*/)outputStreams
                          xamlMetadataProvider:(RTObject<WUXMIXamlMetadataProvider>*)xamlMetadataProvider;
@end

#endif // __WUXMXamlBinaryWriter_DEFINED__
