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
@class WUXMXamlBinaryWriter, WUXMXamlReader, WUXMXamlBindingHelper;
@class WUXMXamlBinaryWriterErrorInformation, WUXMXmlnsDefinition;
@protocol WUXMIComponentConnector
, WUXMIComponentConnector2, WUXMIXamlMember, WUXMIXamlType, WUXMIXamlMetadataProvider, WUXMIXamlBinaryWriter, WUXMIXamlBinaryWriterStatics,
    WUXMIXamlReader, WUXMIXamlReaderStatics, WUXMIDataTemplateComponent, WUXMIXamlBindingHelper, WUXMIXamlBindingHelperStatics;

#include "WindowsUIXamlInterop.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUIXaml.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Markup.XamlBinaryWriterErrorInformation
WINRT_EXPORT
@interface WUXMXamlBinaryWriterErrorInformation : NSObject
+ (instancetype) new;
@property unsigned int inputStreamIndex;
@property unsigned int lineNumber;
@property unsigned int linePosition;
@end

// [struct] Windows.UI.Xaml.Markup.XmlnsDefinition
WINRT_EXPORT
@interface WUXMXmlnsDefinition : NSObject
+ (instancetype) new;
@property (copy) NSString* xmlNamespace;
@property (copy) NSString* Namespace;
@end

// Windows.UI.Xaml.Markup.IComponentConnector
#ifndef __WUXMIComponentConnector_DEFINED__
#define __WUXMIComponentConnector_DEFINED__

@protocol WUXMIComponentConnector
- (void)connect:(int)connectionId target:(RTObject*)target;
@end

#endif // __WUXMIComponentConnector_DEFINED__

// Windows.UI.Xaml.Markup.IComponentConnector2
#ifndef __WUXMIComponentConnector2_DEFINED__
#define __WUXMIComponentConnector2_DEFINED__

@protocol WUXMIComponentConnector2
- (RTObject<WUXMIComponentConnector>*)getBindingConnector:(int)connectionId target:(RTObject*)target;
@end

#endif // __WUXMIComponentConnector2_DEFINED__

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

// Windows.UI.Xaml.Markup.IXamlMetadataProvider
#ifndef __WUXMIXamlMetadataProvider_DEFINED__
#define __WUXMIXamlMetadataProvider_DEFINED__

@protocol WUXMIXamlMetadataProvider
- (RTObject<WUXMIXamlType>*)getXamlType:(WUXITypeName*)type;
- (RTObject<WUXMIXamlType>*)getXamlTypeByFullName:(NSString*)fullName;
- (NSArray*)getXmlnsDefinitions;
@end

#endif // __WUXMIXamlMetadataProvider_DEFINED__

// Windows.UI.Xaml.Markup.IDataTemplateComponent
#ifndef __WUXMIDataTemplateComponent_DEFINED__
#define __WUXMIDataTemplateComponent_DEFINED__

@protocol WUXMIDataTemplateComponent
- (void)recycle;
- (void)processBindings:(RTObject*)item itemIndex:(int)itemIndex phase:(int)phase nextPhase:(int*)nextPhase;
@end

#endif // __WUXMIDataTemplateComponent_DEFINED__

// Windows.UI.Xaml.Markup.XamlBinaryWriter
#ifndef __WUXMXamlBinaryWriter_DEFINED__
#define __WUXMXamlBinaryWriter_DEFINED__

WINRT_EXPORT
@interface WUXMXamlBinaryWriter : RTObject
+ (WUXMXamlBinaryWriterErrorInformation*)write:(id<NSFastEnumeration> /* RTObject<WSSIRandomAccessStream>* */)inputStreams
                                 outputStreams:(id<NSFastEnumeration> /* RTObject<WSSIRandomAccessStream>* */)outputStreams
                          xamlMetadataProvider:(RTObject<WUXMIXamlMetadataProvider>*)xamlMetadataProvider;
@end

#endif // __WUXMXamlBinaryWriter_DEFINED__

// Windows.UI.Xaml.Markup.XamlReader
#ifndef __WUXMXamlReader_DEFINED__
#define __WUXMXamlReader_DEFINED__

WINRT_EXPORT
@interface WUXMXamlReader : RTObject
+ (RTObject*)load:(NSString*)xaml;
+ (RTObject*)loadWithInitialTemplateValidation:(NSString*)xaml;
@end

#endif // __WUXMXamlReader_DEFINED__

// Windows.UI.Xaml.Markup.XamlBindingHelper
#ifndef __WUXMXamlBindingHelper_DEFINED__
#define __WUXMXamlBindingHelper_DEFINED__

WINRT_EXPORT
@interface WUXMXamlBindingHelper : RTObject
+ (RTObject<WUXMIDataTemplateComponent>*)getDataTemplateComponent:(WXDependencyObject*)element;
+ (void)setDataTemplateComponent:(WXDependencyObject*)element value:(RTObject<WUXMIDataTemplateComponent>*)value;
+ (void)suspendRendering:(WXUIElement*)target;
+ (void)resumeRendering:(WXUIElement*)target;
+ (RTObject*)convertValue:(WUXITypeName*)type value:(RTObject*)value;
+ (void)setPropertyFromString:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(NSString*)value;
+ (void)setPropertyFromBoolean:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(BOOL)value;
+ (void)setPropertyFromChar16:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WCHAR)value;
+ (void)setPropertyFromDateTime:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFDateTime*)value;
+ (void)setPropertyFromDouble:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(double)value;
+ (void)setPropertyFromInt32:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(int)value;
+ (void)setPropertyFromUInt32:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(unsigned int)value;
+ (void)setPropertyFromInt64:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(int64_t)value;
+ (void)setPropertyFromUInt64:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(uint64_t)value;
+ (void)setPropertyFromSingle:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(float)value;
+ (void)setPropertyFromPoint:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFPoint*)value;
+ (void)setPropertyFromRect:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFRect*)value;
+ (void)setPropertyFromSize:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFSize*)value;
+ (void)setPropertyFromTimeSpan:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFTimeSpan*)value;
+ (void)setPropertyFromByte:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(uint8_t)value;
+ (void)setPropertyFromUri:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFUri*)value;
+ (void)setPropertyFromObject:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(RTObject*)value;
+ (WXDependencyProperty*)dataTemplateComponentProperty;
@end

#endif // __WUXMXamlBindingHelper_DEFINED__
