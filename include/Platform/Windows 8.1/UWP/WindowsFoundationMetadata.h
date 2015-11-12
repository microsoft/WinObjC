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

// WindowsFoundationMetadata.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
// Windows.Foundation.Metadata.GCPressureAmount
enum _WFMGCPressureAmount {
    WFMGCPressureAmountLow = 0,
    WFMGCPressureAmountMedium = 1,
    WFMGCPressureAmountHigh = 2,
};
typedef unsigned WFMGCPressureAmount;

// Windows.Foundation.Metadata.Platform
enum _WFMPlatform {
    WFMPlatformWindows = 0,
    WFMPlatformWindowsPhone = 1,
};
typedef unsigned WFMPlatform;

// Windows.Foundation.Metadata.AttributeTargets
enum _WFMAttributeTargets {
    WFMAttributeTargetsAll = -1,
    WFMAttributeTargetsDelegate = 1,
    WFMAttributeTargetsEnum = 2,
    WFMAttributeTargetsEvent = 4,
    WFMAttributeTargetsField = 8,
    WFMAttributeTargetsInterface = 16,
    WFMAttributeTargetsMethod = 64,
    WFMAttributeTargetsParameter = 128,
    WFMAttributeTargetsProperty = 256,
    WFMAttributeTargetsRuntimeClass = 512,
    WFMAttributeTargetsStruct = 1024,
    WFMAttributeTargetsInterfaceImpl = 2048,
};
typedef unsigned WFMAttributeTargets;

// Windows.Foundation.Metadata.CompositionType
enum _WFMCompositionType {
    WFMCompositionTypeProtected = 1,
    WFMCompositionTypePublic = 2,
};
typedef unsigned WFMCompositionType;

// Windows.Foundation.Metadata.ThreadingModel
enum _WFMThreadingModel {
    WFMThreadingModelSTA = 1,
    WFMThreadingModelMTA = 2,
    WFMThreadingModelBoth = 3,
    WFMThreadingModelInvalidThreading = 0,
};
typedef unsigned WFMThreadingModel;

// Windows.Foundation.Metadata.MarshalingType
enum _WFMMarshalingType {
    WFMMarshalingTypeNone = 1,
    WFMMarshalingTypeAgile = 2,
    WFMMarshalingTypeStandard = 3,
    WFMMarshalingTypeInvalidMarshaling = 0,
};
typedef unsigned WFMMarshalingType;

// Windows.Foundation.Metadata.DeprecationType
enum _WFMDeprecationType {
    WFMDeprecationTypeDeprecate = 0,
    WFMDeprecationTypeRemove = 1,
};
typedef unsigned WFMDeprecationType;
