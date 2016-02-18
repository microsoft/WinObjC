//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#ifndef MESSAGEUI_IMPEXP
#define MESSAGEUI_IMPEXP __declspec(dllimport)
#endif

#ifndef MESSAGEUI_EXPORT
#ifdef __cplusplus
#define MESSAGEUI_EXPORT MESSAGEUI_IMPEXP extern "C"
#define MESSAGEUI_EXPORT_CLASS MESSAGEUI_IMPEXP
#else
#define MESSAGEUI_EXPORT MESSAGEUI_IMPEXP extern
#define MESSAGEUI_EXPORT_CLASS MESSAGEUI_IMPEXP
#endif
#endif

#ifndef MESSAGEUI_EXTERNC_BEGIN
#if defined(__cplusplus)
#define MESSAGEUI_EXTERNC_BEGIN extern "C" {
#define MESSAGEUI_EXTERNC_END }
#else
#define MESSAGEUI_EXTERNC_BEGIN
#define MESSAGEUI_EXTERNC_END
#endif
#endif
