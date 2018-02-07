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

// WindowsApplicationModelDataTransferDragDrop.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELDATATRANSFERDRAGDROPEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELDATATRANSFERDRAGDROPEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelDataTransferDragDrop.lib")
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

