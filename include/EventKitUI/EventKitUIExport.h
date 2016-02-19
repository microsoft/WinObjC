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

#ifndef EVENTKITUI_IMPEXP
#define EVENTKITUI_IMPEXP __declspec(dllimport)
#endif

#ifndef EVENTKITUI_EXPORT
#ifdef __cplusplus
#define EVENTKITUI_EXPORT EVENTKITUI_IMPEXP extern "C"
#define EVENTKITUI_EXPORT_CLASS EVENTKITUI_IMPEXP
#else
#define EVENTKITUI_EXPORT EVENTKITUI_IMPEXP extern
#define EVENTKITUI_EXPORT_CLASS EVENTKITUI_IMPEXP
#endif
#endif

#ifndef EVENTKITUI_EXTERNC_BEGIN
#if defined(__cplusplus)
#define EVENTKITUI_EXTERNC_BEGIN extern "C" {
#define EVENTKITUI_EXTERNC_END }
#else
#define EVENTKITUI_EXTERNC_BEGIN
#define EVENTKITUI_EXTERNC_END
#endif
#endif
