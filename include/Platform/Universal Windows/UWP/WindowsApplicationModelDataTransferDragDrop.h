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

// WindowsApplicationModelDataTransferDragDrop.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_APPLICATIONMODEL_DATATRANSFER_DRAGDROP_EXPORT
#define OBJCUWP_WINDOWS_APPLICATIONMODEL_DATATRANSFER_DRAGDROP_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_ApplicationModel_DataTransfer_DragDrop.lib")
#endif
#endif
#include <UWP/interopBase.h>

// Windows.ApplicationModel.DataTransfer.DragDrop.DragDropModifiers
enum _WADDDragDropModifiers {
    WADDDragDropModifiersNone = 0,
    WADDDragDropModifiersShift = 1,
    WADDDragDropModifiersControl = 2,
    WADDDragDropModifiersAlt = 4,
    WADDDragDropModifiersLeftButton = 8,
    WADDDragDropModifiersMiddleButton = 16,
    WADDDragDropModifiersRightButton = 32,
};
typedef unsigned WADDDragDropModifiers;

#import <Foundation/Foundation.h>
